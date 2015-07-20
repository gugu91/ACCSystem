#include "mbed.h"
#include "rtos.h"

extern "C" {
#include "ACC_Controller.h"
#include "rtwtypes.h"
}

Ticker tick;
Timeout flipper;
Timer           t;
Timer alive_t;
uint8_T flippedFlag;
DigitalOut led_red(LED_RED);
DigitalOut led_green(LED_GREEN);
DigitalOut led_blue(LED_BLUE);
InterruptIn enableSwitch(SW2);
InterruptIn pedalFlag(SW3);
Serial      pc(USBTX, USBRX); // tx, rx
DigitalOut      trigger(D2);
InterruptIn     echo(D4);
volatile char    ready;
volatile float   distance;
volatile int distance_age;

static RT_MODEL_ACC_Controller_T ACC_Controller_M_;
static RT_MODEL_ACC_Controller_T *const ACC_Controller_M = &ACC_Controller_M_;/* Real-time model */
static P_ACC_Controller_T ACC_Controller_P = {
    0.0,                                 /* Expression: 0
                                          * Referenced by: '<S6>/Delay'
                                          */
    0.0,                                 /* Expression: 0
                                          * Referenced by: '<S6>/Delay1'
                                          */
    0.0,                                 /* Expression: 0
                                          * Referenced by: '<S6>/Delay2'
                                          */
    0.0,                                 /* Expression: 0
                                          * Referenced by: '<S6>/Delay3'
                                          */
    5.0,                                 /* Expression: 5
                                          * Referenced by: '<S6>/Constant'
                                          */
    10.0,                                /* Expression: 10
                                          * Referenced by: '<S3>/Constant'
                                          */
    0.0,                                 /* Expression: 0
                                          * Referenced by: '<S4>/Delay'
                                          */
    0.0,                                 /* Expression: 0
                                          * Referenced by: '<S4>/Delay1'
                                          */
    0.0,                                 /* Expression: 0
                                          * Referenced by: '<S4>/Delay2'
                                          */
    0.0,                                 /* Expression: 0
                                          * Referenced by: '<S4>/Delay3'
                                          */
    5.0,                                 /* Expression: 5
                                          * Referenced by: '<S4>/Constant'
                                          */
    160.0,                               /* Expression: 160
                                          * Referenced by: '<S5>/Constant1'
                                          */
    0.0,                                 /* Expression: 0
                                          * Referenced by: '<S5>/Constant'
                                          */
    400.0,                               /* Expression: 400
                                          * Referenced by: '<S5>/Constant3'
                                          */
    2.0,                                 /* Expression: 2
                                          * Referenced by: '<S5>/Constant2'
                                          */
    1U,                                  /* Computed Parameter: Delay_DelayLength
                                          * Referenced by: '<S6>/Delay'
                                          */
    1U,                                  /* Computed Parameter: Delay1_DelayLength
                                          * Referenced by: '<S6>/Delay1'
                                          */
    1U,                                  /* Computed Parameter: Delay2_DelayLength
                                          * Referenced by: '<S6>/Delay2'
                                          */
    1U,                                  /* Computed Parameter: Delay3_DelayLength
                                          * Referenced by: '<S6>/Delay3'
                                          */
    1U,                                  /* Computed Parameter: Delay_DelayLength_i
                                          * Referenced by: '<S4>/Delay'
                                          */
    1U,                                  /* Computed Parameter: Delay1_DelayLength_p
                                          * Referenced by: '<S4>/Delay1'
                                          */
    1U,                                  /* Computed Parameter: Delay2_DelayLength_b
                                          * Referenced by: '<S4>/Delay2'
                                          */
    1U,                                  /* Computed Parameter: Delay3_DelayLength_h
                                          * Referenced by: '<S4>/Delay3'
                                          */
    1U,                                  /* Computed Parameter: Constant5_Value
                                          * Referenced by: '<S8>/Constant5'
                                          */
    0U,                                  /* Computed Parameter: Constant4_Value
                                          * Referenced by: '<S8>/Constant4'
                                          */
    1U,                                  /* Computed Parameter: Constant5_Value_p
                                          * Referenced by: '<S9>/Constant5'
                                          */
    0U,                                  /* Computed Parameter: Constant4_Value_d
                                          * Referenced by: '<S9>/Constant4'
                                          */
    1U,                                  /* Computed Parameter: Constant5_Value_m
                                          * Referenced by: '<S10>/Constant5'
                                          */
    0U                                   /* Computed Parameter: Constant4_Value_b
                                          * Referenced by: '<S10>/Constant4'
                                          */
};                                     /* Modifiable parameters */

static DW_ACC_Controller_T ACC_Controller_DW;/* Observable states */

/* '<Root>/EnableSwitch' */
static uint8_T ACC_Controller_U_EnableSwitch;

/* '<Root>/PedalFlag' */
static uint8_T ACC_Controller_U_PedalFlag;

/* '<Root>/ResetSwitch' */
static uint8_T ACC_Controller_U_ResetSwitch;

/* '<Root>/Distance' */
static real_T ACC_Controller_U_Distance;

/* '<Root>/Speed' */
static real_T ACC_Controller_U_Speed;

/* '<Root>/CAN Alive' */
static uint8_T ACC_Controller_U_CANAlive;

/* '<Root>/Distance Alive' */
static uint8_T ACC_Controller_U_DistanceAlive;

/* '<Root>/Go' */
static uint8_T ACC_Controller_Y_Go;

/* '<Root>/Stop' */
static uint8_T ACC_Controller_Y_Stop;

/* '<Root>/d' */
static real_T ACC_Controller_Y_d;

/* '<Root>/Led1' */
static uint8_T ACC_Controller_Y_Led1;

void flipEnSw(){
    if(flippedFlag == 0) {
        flippedFlag = 1;
        ACC_Controller_U_EnableSwitch = !ACC_Controller_U_EnableSwitch;
    }
}

void downEnSw(){
    ACC_Controller_U_ResetSwitch = 0;
    flippedFlag=0;
    flipper.attach(&flipEnSw, 1);
}

void upEnSw(){
    if(flippedFlag == 0) {
        flippedFlag = 1;
        ACC_Controller_U_ResetSwitch = 1;
    }
}

void downPedal(){
    ACC_Controller_U_PedalFlag = 1;
}

void upPedal(){
    ACC_Controller_U_PedalFlag = 0;
}

void start( void )
{
    ready = 0;
    t.start();
}

void stop( void )
{
    t.stop();
    distance = t.read_us()/58.26;
    ready = 1;
    alive_t.reset();
    alive_t.start();
    t.reset();
}

void do_step()
{
    ACC_Controller_U_Distance = distance;
    ACC_Controller_U_DistanceAlive = 1;
    distance_age = alive_t.read_ms();
    
    if(distance_age > 180)
        ACC_Controller_U_DistanceAlive = 0;
    
    ACC_Controller_step(ACC_Controller_M, ACC_Controller_U_EnableSwitch,
                        ACC_Controller_U_PedalFlag, ACC_Controller_U_ResetSwitch,
                        ACC_Controller_U_Distance, ACC_Controller_U_Speed,
                        ACC_Controller_U_CANAlive, ACC_Controller_U_DistanceAlive,
                        &ACC_Controller_Y_Go, &ACC_Controller_Y_Stop,
                        &ACC_Controller_Y_d, &ACC_Controller_Y_Led1);
    ACC_Controller_U_ResetSwitch = 0;
    led_red=1;
    led_green=1;
    led_blue = 1;
    if(ACC_Controller_Y_Led1 == 1) {
        led_green = 0; //led pins are active low
        if(ACC_Controller_Y_Stop == 1) led_red = 0;
        if(ACC_Controller_Y_Go == 1) led_blue = 0;
    }
    if(ACC_Controller_Y_Led1 == 2) led_red = 0;
}

void read_distance_thread(void const *args)
{
    trigger = 0;
    distance = 0;
    ready = 0;
    t.reset();
    alive_t.reset();
    
    echo.rise( &start );
    echo.fall( &stop );
    
    while (true) {
        trigger = 1;
        wait_us( 10 );
        trigger = 0;
        while( !ready );
        ready = 0;
        Thread::wait(60);
    }
}

int main()
{
    /* Pack model data into RTM */
    /* Pack model data into RTM */
    ACC_Controller_M->ModelData.defaultParam = &ACC_Controller_P;
    ACC_Controller_M->ModelData.dwork = &ACC_Controller_DW;
    
    /* Initialize model */
    ACC_Controller_initialize(ACC_Controller_M, &ACC_Controller_U_EnableSwitch,
                              &ACC_Controller_U_PedalFlag, &ACC_Controller_U_ResetSwitch,
                              &ACC_Controller_U_Distance, &ACC_Controller_U_Speed,
                              &ACC_Controller_U_CANAlive, &ACC_Controller_U_DistanceAlive,
                              &ACC_Controller_Y_Go, &ACC_Controller_Y_Stop, &ACC_Controller_Y_d,
                              &ACC_Controller_Y_Led1);
    
    ACC_Controller_U_PedalFlag = 0;
    ACC_Controller_U_Distance = 0;
    
    ACC_Controller_U_Speed = 50;
    ACC_Controller_U_CANAlive = 1;
    ACC_Controller_U_DistanceAlive = 1;
    
    enableSwitch.fall(&downEnSw);
    enableSwitch.rise(&upEnSw);
    pedalFlag.fall(&downPedal);
    pedalFlag.rise(&upPedal);
    
    Thread thread(read_distance_thread);
    
    tick.attach(&do_step, 0.1); // setup ticker to call flip every 0.1 seconds
    
    
    while (true) {
        pc.printf( "\n\rDistance: %.3f Go: %d Stop: %d age: %d\n\r", ACC_Controller_U_Distance, ACC_Controller_Y_Go, ACC_Controller_Y_Stop, distance_age);
        
        Thread::wait(1000);
    }
    
    ACC_Controller_terminate(ACC_Controller_M);
}
