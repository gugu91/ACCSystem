/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ert_main.c
 *
 * Code generated for Simulink model 'ACCSystem'.
 *
 * Model version                  : 1.33
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * C/C++ source code generated on : Mon Jul 20 22:30:16 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include <stddef.h>
#include <stdio.h>                     /* This ert_main.c example uses printf/fflush */
#include "ACCSystem.h"                 /* Model's header file */
#include "rtwtypes.h"

static RT_MODEL_ACCSystem_T ACCSystem_M_;
static RT_MODEL_ACCSystem_T *const ACCSystem_M = &ACCSystem_M_;/* Real-time model */
static P_ACCSystem_T ACCSystem_P = {
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S7>/Delay'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S7>/Delay1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S7>/Delay2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S7>/Delay3'
                                        */
  5.0,                                 /* Expression: 5
                                        * Referenced by: '<S7>/Constant'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<S4>/Constant'
                                        */
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
  160.0,                               /* Expression: 160
                                        * Referenced by: '<S6>/Constant1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/Constant'
                                        */
  400.0,                               /* Expression: 400
                                        * Referenced by: '<S6>/Constant3'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S6>/Constant2'
                                        */
  1U,                                  /* Computed Parameter: Delay_DelayLength
                                        * Referenced by: '<S7>/Delay'
                                        */
  1U,                                  /* Computed Parameter: Delay1_DelayLength
                                        * Referenced by: '<S7>/Delay1'
                                        */
  1U,                                  /* Computed Parameter: Delay2_DelayLength
                                        * Referenced by: '<S7>/Delay2'
                                        */
  1U,                                  /* Computed Parameter: Delay3_DelayLength
                                        * Referenced by: '<S7>/Delay3'
                                        */
  1U,                                  /* Computed Parameter: Delay_DelayLength_i
                                        * Referenced by: '<S5>/Delay'
                                        */
  1U,                                  /* Computed Parameter: Delay1_DelayLength_p
                                        * Referenced by: '<S5>/Delay1'
                                        */
  1U,                                  /* Computed Parameter: Delay2_DelayLength_b
                                        * Referenced by: '<S5>/Delay2'
                                        */
  1U,                                  /* Computed Parameter: Delay3_DelayLength_h
                                        * Referenced by: '<S5>/Delay3'
                                        */
  1U,                                  /* Computed Parameter: DistanceOn_Value
                                        * Referenced by: '<S2>/Distance On'
                                        */
  1U,                                  /* Computed Parameter: CANOn_Value
                                        * Referenced by: '<S2>/CAN On'
                                        */
  1U,                                  /* Computed Parameter: EnableSwitchOn_Value
                                        * Referenced by: '<S2>/Enable Switch On'
                                        */
  1U,                                  /* Computed Parameter: Constant5_Value
                                        * Referenced by: '<S9>/Constant5'
                                        */
  0U,                                  /* Computed Parameter: Constant4_Value
                                        * Referenced by: '<S9>/Constant4'
                                        */
  0U,                                  /* Computed Parameter: PedalFlagOn_Value
                                        * Referenced by: '<S2>/Pedal Flag On'
                                        */
  1U,                                  /* Computed Parameter: Constant5_Value_p
                                        * Referenced by: '<S10>/Constant5'
                                        */
  0U,                                  /* Computed Parameter: Constant4_Value_d
                                        * Referenced by: '<S10>/Constant4'
                                        */
  1U,                                  /* Computed Parameter: ResetSwitchOn_Value
                                        * Referenced by: '<S2>/Reset Switch On'
                                        */
  1U,                                  /* Computed Parameter: Constant5_Value_m
                                        * Referenced by: '<S11>/Constant5'
                                        */
  0U                                   /* Computed Parameter: Constant4_Value_b
                                        * Referenced by: '<S11>/Constant4'
                                        */
};                                     /* Modifiable parameters */

static DW_ACCSystem_T ACCSystem_DW;    /* Observable states */

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
void rt_OneStep(RT_MODEL_ACCSystem_T *const ACCSystem_M);
void rt_OneStep(RT_MODEL_ACCSystem_T *const ACCSystem_M)
{
  static boolean_T OverrunFlag = false;

  /* Disable interrupts here */

  /* Check for overrun */
  if (OverrunFlag) {
    rtmSetErrorStatus(ACCSystem_M, "Overrun");
    return;
  }

  OverrunFlag = true;

  /* Save FPU context here (if necessary) */
  /* Re-enable timer or interrupt here */
  /* Set model inputs here */

  /* Step the model */
  ACCSystem_step(ACCSystem_M);

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
  ACCSystem_M->ModelData.defaultParam = &ACCSystem_P;
  ACCSystem_M->ModelData.dwork = &ACCSystem_DW;

  /* Initialize model */
  ACCSystem_initialize(ACCSystem_M);

  /* Attach rt_OneStep to a timer or interrupt service routine with
   * period 0.1 seconds (the model's base sample time) here.  The
   * call syntax for rt_OneStep is
   *
   *  rt_OneStep(ACCSystem_M);
   */
  printf("Warning: The simulation will run forever. "
         "Generated ERT main won't simulate model step behavior. "
         "To change this behavior select the 'MAT-file logging' option.\n");
  fflush((NULL));
  while (rtmGetErrorStatus(ACCSystem_M) == (NULL)) {
    /*  Perform other application tasks here */
  }

  /* Disable rt_OneStep() here */

  /* Terminate model */
  ACCSystem_terminate(ACCSystem_M);
  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
