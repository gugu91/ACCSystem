/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ert_main.c
 *
 * Code generated for Simulink model 'ACC_Controller'.
 *
 * Model version                  : 1.37
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * C/C++ source code generated on : Sun Jul 26 16:20:54 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include <stddef.h>
#include <stdio.h>                     /* This ert_main.c example uses printf/fflush */
#include "ACC_Controller.h"            /* Model's header file */
#include "rtwtypes.h"

static RT_MODEL_ACC_Controller_T ACC_Controller_M_;
static RT_MODEL_ACC_Controller_T *const ACC_Controller_M = &ACC_Controller_M_;/* Real-time model */
static P_ACC_Controller_T ACC_Controller_P = {
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S5>/Delay'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S5>/Delay1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S5>/Delay2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S5>/Delay3'
                                        */
  5.0,                                 /* Expression: 5
                                        * Referenced by: '<S5>/Constant'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<S2>/Constant'
                                        */
  4.0,                                 /* Expression: 4
                                        * Referenced by: '<S2>/Constant1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Delay'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Delay1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Delay2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Delay3'
                                        */
  5.0,                                 /* Expression: 5
                                        * Referenced by: '<S3>/Constant'
                                        */
  195.0,                               /* Expression: 195
                                        * Referenced by: '<S8>/Constant1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S8>/Constant'
                                        */
  400.0,                               /* Expression: 400
                                        * Referenced by: '<S8>/Constant3'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S8>/Constant2'
                                        */
  1U,                                  /* Computed Parameter: Delay_DelayLength
                                        * Referenced by: '<S5>/Delay'
                                        */
  1U,                                  /* Computed Parameter: Delay1_DelayLength
                                        * Referenced by: '<S5>/Delay1'
                                        */
  1U,                                  /* Computed Parameter: Delay2_DelayLength
                                        * Referenced by: '<S5>/Delay2'
                                        */
  1U,                                  /* Computed Parameter: Delay3_DelayLength
                                        * Referenced by: '<S5>/Delay3'
                                        */
  1U,                                  /* Computed Parameter: Delay_DelayLength_i
                                        * Referenced by: '<S3>/Delay'
                                        */
  1U,                                  /* Computed Parameter: Delay1_DelayLength_p
                                        * Referenced by: '<S3>/Delay1'
                                        */
  1U,                                  /* Computed Parameter: Delay2_DelayLength_b
                                        * Referenced by: '<S3>/Delay2'
                                        */
  1U,                                  /* Computed Parameter: Delay3_DelayLength_h
                                        * Referenced by: '<S3>/Delay3'
                                        */
  1U,                                  /* Computed Parameter: Constant5_Value
                                        * Referenced by: '<S10>/Constant5'
                                        */
  0U,                                  /* Computed Parameter: Constant4_Value
                                        * Referenced by: '<S10>/Constant4'
                                        */
  2U,                                  /* Computed Parameter: Constant1_Value_p
                                        * Referenced by: '<S10>/Constant1'
                                        */
  1U,                                  /* Computed Parameter: Constant5_Value_p
                                        * Referenced by: '<S9>/Constant5'
                                        */
  0U                                   /* Computed Parameter: Constant4_Value_d
                                        * Referenced by: '<S9>/Constant4'
                                        */
};                                     /* Modifiable parameters */

static DW_ACC_Controller_T ACC_Controller_DW;/* Observable states */

/* '<Root>/EnableSwitch' */
static uint8_T ACC_Controller_U_EnableSwitch;

/* '<Root>/PedalFlag' */
static uint8_T ACC_Controller_U_PedalFlag;

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

/* '<Root>/Led1' */
static uint8_T ACC_Controller_Y_Led1;

/*
 * Associating rt_OneStep with a real-time clock or interrupt service routine
 * is what makes the generated code "real-time".  The function rt_OneStep is
 * always associated with the base rate of the model.  Subrates are managed
 * by the base rate from inside the generated code.  Enabling/disabling
 * interrupts and floating point context switches are target specific.  This
 * example code indicates where these should take place relative to executing
 * the generated code step function.  Overrun behavior should be tailored to
 * your application needs.  This example simply sets an error status in the
 * real-time model and returns from rt_OneStep.
 */
void rt_OneStep(RT_MODEL_ACC_Controller_T *const ACC_Controller_M);
void rt_OneStep(RT_MODEL_ACC_Controller_T *const ACC_Controller_M)
{
  static boolean_T OverrunFlag = false;

  /* Disable interrupts here */

  /* Check for overrun */
  if (OverrunFlag) {
    rtmSetErrorStatus(ACC_Controller_M, "Overrun");
    return;
  }

  OverrunFlag = true;

  /* Save FPU context here (if necessary) */
  /* Re-enable timer or interrupt here */
  /* Set model inputs here */

  /* Step the model */
  ACC_Controller_step(ACC_Controller_M, ACC_Controller_U_EnableSwitch,
                      ACC_Controller_U_PedalFlag, ACC_Controller_U_Distance,
                      ACC_Controller_U_Speed, ACC_Controller_U_CANAlive,
                      ACC_Controller_U_DistanceAlive, &ACC_Controller_Y_Go,
                      &ACC_Controller_Y_Stop, &ACC_Controller_Y_Led1);

  /* Get model outputs here */

  /* Indicate task complete */
  OverrunFlag = false;

  /* Disable interrupts here */
  /* Restore FPU context here (if necessary) */
  /* Enable interrupts here */
}

/*
 * The example "main" function illustrates what is required by your
 * application code to initialize, execute, and terminate the generated code.
 * Attaching rt_OneStep to a real-time clock is target specific.  This example
 * illustates how you do this relative to initializing the model.
 */
int_T main(int_T argc, const char *argv[])
{
  /* Unused arguments */
  (void)(argc);
  (void)(argv);

  /* Pack model data into RTM */
  ACC_Controller_M->ModelData.defaultParam = &ACC_Controller_P;
  ACC_Controller_M->ModelData.dwork = &ACC_Controller_DW;

  /* Initialize model */
  ACC_Controller_initialize(ACC_Controller_M, &ACC_Controller_U_EnableSwitch,
    &ACC_Controller_U_PedalFlag, &ACC_Controller_U_Distance,
    &ACC_Controller_U_Speed, &ACC_Controller_U_CANAlive,
    &ACC_Controller_U_DistanceAlive, &ACC_Controller_Y_Go,
    &ACC_Controller_Y_Stop, &ACC_Controller_Y_Led1);

  /* Attach rt_OneStep to a timer or interrupt service routine with
   * period 0.1 seconds (the model's base sample time) here.  The
   * call syntax for rt_OneStep is
   *
   *  rt_OneStep(ACC_Controller_M);
   */
  printf("Warning: The simulation will run forever. "
         "Generated ERT main won't simulate model step behavior. "
         "To change this behavior select the 'MAT-file logging' option.\n");
  fflush((NULL));
  while (rtmGetErrorStatus(ACC_Controller_M) == (NULL)) {
    /*  Perform other application tasks here */
  }

  /* Disable rt_OneStep() here */

  /* Terminate model */
  ACC_Controller_terminate(ACC_Controller_M);
  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
