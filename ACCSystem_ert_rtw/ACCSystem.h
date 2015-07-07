/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ACCSystem.h
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

#ifndef RTW_HEADER_ACCSystem_h_
#define RTW_HEADER_ACCSystem_h_
#include <stddef.h>
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include <math.h>
#include <string.h>
#ifndef ACCSystem_COMMON_INCLUDES_
# define ACCSystem_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#endif                                 /* ACCSystem_COMMON_INCLUDES_ */

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM_ACCSystem_T RT_MODEL_ACCSystem_T;

/* Block signals (auto storage) */
typedef struct {
  real_T In;                           /* '<S4>/In' */
  uint8_T go;                          /* '<S1>/controller' */
  uint8_T stop;                        /* '<S1>/controller' */
} B_ACCSystem_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T NextOutput;                   /* '<S2>/Random Number' */
  real_T Speed;                        /* '<S5>/Data Store Memory' */
  real_T setSpeed;                     /* '<S1>/controller' */
  real_T safety;                       /* '<S1>/controller' */
  int32_T clockTickCounter;            /* '<S2>/Pulse Generator1' */
  uint32_T RandSeed;                   /* '<S2>/Random Number' */
  uint8_T is_active_c3_ACCSystem;      /* '<S1>/controller' */
  uint8_T is_c3_ACCSystem;             /* '<S1>/controller' */
  uint8_T is_ON_STATE;                 /* '<S1>/controller' */
  uint8_T is_WORKING_STATE;            /* '<S1>/controller' */
} DW_ACCSystem_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState SampleandHold1_Trig_ZCE;  /* '<S2>/Sample and Hold1' */
} PrevZCX_ACCSystem_T;

/* Parameters (auto storage) */
struct P_ACCSystem_T_ {
  real_T _Y0;                          /* Expression: initCond
                                        * Referenced by: '<S4>/ '
                                        */
  real_T RandomNumber_Mean;            /* Expression: 81
                                        * Referenced by: '<S2>/Random Number'
                                        */
  real_T RandomNumber_StdDev;          /* Computed Parameter: RandomNumber_StdDev
                                        * Referenced by: '<S2>/Random Number'
                                        */
  real_T RandomNumber_Seed;            /* Expression: 0
                                        * Referenced by: '<S2>/Random Number'
                                        */
  real_T PulseGenerator1_Amp;          /* Expression: 1
                                        * Referenced by: '<S2>/Pulse Generator1'
                                        */
  real_T PulseGenerator1_Period;       /* Computed Parameter: PulseGenerator1_Period
                                        * Referenced by: '<S2>/Pulse Generator1'
                                        */
  real_T PulseGenerator1_Duty;         /* Computed Parameter: PulseGenerator1_Duty
                                        * Referenced by: '<S2>/Pulse Generator1'
                                        */
  real_T PulseGenerator1_PhaseDelay;   /* Expression: 0
                                        * Referenced by: '<S2>/Pulse Generator1'
                                        */
  real_T Gain1_Gain;                   /* Expression: 0.5
                                        * Referenced by: '<S5>/Gain1'
                                        */
  real_T Gain2_Gain;                   /* Expression: 0.5
                                        * Referenced by: '<S5>/Gain2'
                                        */
  real_T DataStoreMemory_InitialValue; /* Expression: 90
                                        * Referenced by: '<S5>/Data Store Memory'
                                        */
  uint8_T ResetSwitchOff_Value;        /* Computed Parameter: ResetSwitchOff_Value
                                        * Referenced by: '<S2>/Reset Switch Off'
                                        */
  uint8_T ResetSwitchOn_Value;         /* Computed Parameter: ResetSwitchOn_Value
                                        * Referenced by: '<S2>/Reset Switch On'
                                        */
  uint8_T PedalFlagOff_Value;          /* Computed Parameter: PedalFlagOff_Value
                                        * Referenced by: '<S2>/Pedal Flag Off'
                                        */
  uint8_T PedalFlagOn_Value;           /* Computed Parameter: PedalFlagOn_Value
                                        * Referenced by: '<S2>/Pedal Flag On'
                                        */
  uint8_T EnableSwitchOff_Value;       /* Computed Parameter: EnableSwitchOff_Value
                                        * Referenced by: '<S2>/Enable Switch Off'
                                        */
  uint8_T EnableSwitchOn_Value;        /* Computed Parameter: EnableSwitchOn_Value
                                        * Referenced by: '<S2>/Enable Switch On'
                                        */
  uint8_T EnableSwitchSelector_CurrentSet;/* Computed Parameter: EnableSwitchSelector_CurrentSet
                                           * Referenced by: '<S2>/EnableSwitch Selector'
                                           */
  uint8_T PedalFlagSelector_CurrentSettin;/* Computed Parameter: PedalFlagSelector_CurrentSettin
                                           * Referenced by: '<S2>/Pedal Flag Selector'
                                           */
  uint8_T ResetSwitchSelector_CurrentSett;/* Computed Parameter: ResetSwitchSelector_CurrentSett
                                           * Referenced by: '<S2>/Reset Switch Selector'
                                           */
};

/* Parameters (auto storage) */
typedef struct P_ACCSystem_T_ P_ACCSystem_T;

/* Real-time Model Data Structure */
struct tag_RTM_ACCSystem_T {
  const char_T * volatile errorStatus;

  /*
   * ModelData:
   * The following substructure contains information regarding
   * the data used in the model.
   */
  struct {
    B_ACCSystem_T *blockIO;
    P_ACCSystem_T *defaultParam;
    PrevZCX_ACCSystem_T *prevZCSigState;
    DW_ACCSystem_T *dwork;
  } ModelData;
};

/* Model entry point functions */
extern void ACCSystem_initialize(RT_MODEL_ACCSystem_T *const ACCSystem_M);
extern void ACCSystem_step(RT_MODEL_ACCSystem_T *const ACCSystem_M);
extern void ACCSystem_terminate(RT_MODEL_ACCSystem_T *const ACCSystem_M);

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'ACCSystem'
 * '<S1>'   : 'ACCSystem/ACC_Controller'
 * '<S2>'   : 'ACCSystem/Testbench'
 * '<S3>'   : 'ACCSystem/ACC_Controller/controller'
 * '<S4>'   : 'ACCSystem/Testbench/Sample and Hold1'
 * '<S5>'   : 'ACCSystem/Testbench/Speed Simulator'
 */
#endif                                 /* RTW_HEADER_ACCSystem_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
