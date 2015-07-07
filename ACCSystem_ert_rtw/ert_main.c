/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ert_main.c
 *
 * Code generated for Simulink model 'ACCSystem'.
 *
 * Model version                  : 1.16
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * C/C++ source code generated on : Tue Jul  7 19:19:18 2015
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
#include "zero_crossing_types.h"

static RT_MODEL_ACCSystem_T ACCSystem_M_;
static RT_MODEL_ACCSystem_T *const ACCSystem_M = &ACCSystem_M_;/* Real-time model */
static P_ACCSystem_T ACCSystem_P = {
  70.0,                                /* Expression: initCond
                                        * Referenced by: '<S4>/ '
                                        */
  81.0,                                /* Expression: 81
                                        * Referenced by: '<S2>/Random Number'
                                        */
  3.1622776601683795,                  /* Computed Parameter: RandomNumber_StdDev
                                        * Referenced by: '<S2>/Random Number'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Random Number'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S2>/Pulse Generator1'
                                        */
  100.0,                               /* Computed Parameter: PulseGenerator1_Period
                                        * Referenced by: '<S2>/Pulse Generator1'
                                        */
  50.0,                                /* Computed Parameter: PulseGenerator1_Duty
                                        * Referenced by: '<S2>/Pulse Generator1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Pulse Generator1'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S5>/Gain1'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S5>/Gain2'
                                        */
  90.0,                                /* Expression: 90
                                        * Referenced by: '<S5>/Data Store Memory'
                                        */
  0U,                                  /* Computed Parameter: ResetSwitchOff_Value
                                        * Referenced by: '<S2>/Reset Switch Off'
                                        */
  0U,                                  /* Computed Parameter: ResetSwitchOn_Value
                                        * Referenced by: '<S2>/Reset Switch On'
                                        */
  0U,                                  /* Computed Parameter: PedalFlagOff_Value
                                        * Referenced by: '<S2>/Pedal Flag Off'
                                        */
  0U,                                  /* Computed Parameter: PedalFlagOn_Value
                                        * Referenced by: '<S2>/Pedal Flag On'
                                        */
  1U,                                  /* Computed Parameter: EnableSwitchOff_Value
                                        * Referenced by: '<S2>/Enable Switch Off'
                                        */
  1U,                                  /* Computed Parameter: EnableSwitchOn_Value
                                        * Referenced by: '<S2>/Enable Switch On'
                                        */
  1U,                                  /* Computed Parameter: EnableSwitchSelector_CurrentSet
                                        * Referenced by: '<S2>/EnableSwitch Selector'
                                        */
  1U,                                  /* Computed Parameter: PedalFlagSelector_CurrentSettin
                                        * Referenced by: '<S2>/Pedal Flag Selector'
                                        */
  1U                                   /* Computed Parameter: ResetSwitchSelector_CurrentSett
                                        * Referenced by: '<S2>/Reset Switch Selector'
                                        */
};                                     /* Modifiable parameters */

static B_ACCSystem_T ACCSystem_B;      /* Observable signals */
static DW_ACCSystem_T ACCSystem_DW;    /* Observable states */
static PrevZCX_ACCSystem_T ACCSystem_PrevZCX;/* Triggered events */

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
  ACCSystem_M->ModelData.blockIO = &ACCSystem_B;
  ACCSystem_M->ModelData.dwork = &ACCSystem_DW;
  ACCSystem_M->ModelData.prevZCSigState = &ACCSystem_PrevZCX;

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
