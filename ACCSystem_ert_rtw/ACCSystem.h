/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ACCSystem.h
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

#ifndef RTW_HEADER_ACCSystem_h_
#define RTW_HEADER_ACCSystem_h_
#include "rtwtypes.h"
#include <math.h>
#include <string.h>
#ifndef ACCSystem_COMMON_INCLUDES_
# define ACCSystem_COMMON_INCLUDES_
#include "rtwtypes.h"
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

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T Delay_DSTATE;                 /* '<S7>/Delay' */
  real_T Delay1_DSTATE;                /* '<S7>/Delay1' */
  real_T Delay2_DSTATE;                /* '<S7>/Delay2' */
  real_T Delay3_DSTATE;                /* '<S7>/Delay3' */
  real_T Delay_DSTATE_f;               /* '<S5>/Delay' */
  real_T Delay1_DSTATE_f;              /* '<S5>/Delay1' */
  real_T Delay2_DSTATE_h;              /* '<S5>/Delay2' */
  real_T Delay3_DSTATE_j;              /* '<S5>/Delay3' */
  real_T setSpeed;                     /* '<S1>/controller' */
  struct {
    void *TimePtr;
    void *DataPtr;
    void *RSimInfoPtr;
  } FromWorkspace1_PWORK;              /* '<S2>/From Workspace1' */

  struct {
    void *TimePtr;
    void *DataPtr;
    void *RSimInfoPtr;
  } FromWorkspace_PWORK;               /* '<S2>/From Workspace' */

  struct {
    int_T PrevIndex;
  } FromWorkspace1_IWORK;              /* '<S2>/From Workspace1' */

  struct {
    int_T PrevIndex;
  } FromWorkspace_IWORK;               /* '<S2>/From Workspace' */

  uint8_T is_active_c3_ACCSystem;      /* '<S1>/controller' */
  uint8_T is_c3_ACCSystem;             /* '<S1>/controller' */
  uint8_T is_ON_STATE;                 /* '<S1>/controller' */
  uint8_T is_WORKING_STATE;            /* '<S1>/controller' */
  uint8_T temporalCounter_i1;          /* '<S1>/controller' */
} DW_ACCSystem_T;

/* Parameters (auto storage) */
struct P_ACCSystem_T_ {
  real_T Delay_InitialCondition;       /* Expression: 0
                                        * Referenced by: '<S7>/Delay'
                                        */
  real_T Delay1_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<S7>/Delay1'
                                        */
  real_T Delay2_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<S7>/Delay2'
                                        */
  real_T Delay3_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<S7>/Delay3'
                                        */
  real_T Constant_Value;               /* Expression: 5
                                        * Referenced by: '<S7>/Constant'
                                        */
  real_T Constant_Value_k;             /* Expression: 10
                                        * Referenced by: '<S4>/Constant'
                                        */
  real_T Delay_InitialCondition_i;     /* Expression: 0
                                        * Referenced by: '<S5>/Delay'
                                        */
  real_T Delay1_InitialCondition_o;    /* Expression: 0
                                        * Referenced by: '<S5>/Delay1'
                                        */
  real_T Delay2_InitialCondition_h;    /* Expression: 0
                                        * Referenced by: '<S5>/Delay2'
                                        */
  real_T Delay3_InitialCondition_a;    /* Expression: 0
                                        * Referenced by: '<S5>/Delay3'
                                        */
  real_T Constant_Value_m;             /* Expression: 5
                                        * Referenced by: '<S5>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 160
                                        * Referenced by: '<S6>/Constant1'
                                        */
  real_T Constant_Value_g;             /* Expression: 0
                                        * Referenced by: '<S6>/Constant'
                                        */
  real_T Constant3_Value;              /* Expression: 400
                                        * Referenced by: '<S6>/Constant3'
                                        */
  real_T Constant2_Value;              /* Expression: 2
                                        * Referenced by: '<S6>/Constant2'
                                        */
  uint32_T Delay_DelayLength;          /* Computed Parameter: Delay_DelayLength
                                        * Referenced by: '<S7>/Delay'
                                        */
  uint32_T Delay1_DelayLength;         /* Computed Parameter: Delay1_DelayLength
                                        * Referenced by: '<S7>/Delay1'
                                        */
  uint32_T Delay2_DelayLength;         /* Computed Parameter: Delay2_DelayLength
                                        * Referenced by: '<S7>/Delay2'
                                        */
  uint32_T Delay3_DelayLength;         /* Computed Parameter: Delay3_DelayLength
                                        * Referenced by: '<S7>/Delay3'
                                        */
  uint32_T Delay_DelayLength_i;        /* Computed Parameter: Delay_DelayLength_i
                                        * Referenced by: '<S5>/Delay'
                                        */
  uint32_T Delay1_DelayLength_p;       /* Computed Parameter: Delay1_DelayLength_p
                                        * Referenced by: '<S5>/Delay1'
                                        */
  uint32_T Delay2_DelayLength_b;       /* Computed Parameter: Delay2_DelayLength_b
                                        * Referenced by: '<S5>/Delay2'
                                        */
  uint32_T Delay3_DelayLength_h;       /* Computed Parameter: Delay3_DelayLength_h
                                        * Referenced by: '<S5>/Delay3'
                                        */
  uint8_T DistanceOn_Value;            /* Computed Parameter: DistanceOn_Value
                                        * Referenced by: '<S2>/Distance On'
                                        */
  uint8_T CANOn_Value;                 /* Computed Parameter: CANOn_Value
                                        * Referenced by: '<S2>/CAN On'
                                        */
  uint8_T EnableSwitchOn_Value;        /* Computed Parameter: EnableSwitchOn_Value
                                        * Referenced by: '<S2>/Enable Switch On'
                                        */
  uint8_T Constant5_Value;             /* Computed Parameter: Constant5_Value
                                        * Referenced by: '<S9>/Constant5'
                                        */
  uint8_T Constant4_Value;             /* Computed Parameter: Constant4_Value
                                        * Referenced by: '<S9>/Constant4'
                                        */
  uint8_T PedalFlagOn_Value;           /* Computed Parameter: PedalFlagOn_Value
                                        * Referenced by: '<S2>/Pedal Flag On'
                                        */
  uint8_T Constant5_Value_p;           /* Computed Parameter: Constant5_Value_p
                                        * Referenced by: '<S10>/Constant5'
                                        */
  uint8_T Constant4_Value_d;           /* Computed Parameter: Constant4_Value_d
                                        * Referenced by: '<S10>/Constant4'
                                        */
  uint8_T ResetSwitchOn_Value;         /* Computed Parameter: ResetSwitchOn_Value
                                        * Referenced by: '<S2>/Reset Switch On'
                                        */
  uint8_T Constant5_Value_m;           /* Computed Parameter: Constant5_Value_m
                                        * Referenced by: '<S11>/Constant5'
                                        */
  uint8_T Constant4_Value_b;           /* Computed Parameter: Constant4_Value_b
                                        * Referenced by: '<S11>/Constant4'
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
    P_ACCSystem_T *defaultParam;
    DW_ACCSystem_T *dwork;
  } ModelData;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
  } Timing;
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
 * '<S3>'   : 'ACCSystem/ACC_Controller/Age Checks'
 * '<S4>'   : 'ACCSystem/ACC_Controller/Compute Safety Speed'
 * '<S5>'   : 'ACCSystem/ACC_Controller/Distance Average'
 * '<S6>'   : 'ACCSystem/ACC_Controller/Range Checks'
 * '<S7>'   : 'ACCSystem/ACC_Controller/Speed Average'
 * '<S8>'   : 'ACCSystem/ACC_Controller/controller'
 * '<S9>'   : 'ACCSystem/ACC_Controller/Range Checks/Check Flag'
 * '<S10>'  : 'ACCSystem/ACC_Controller/Range Checks/Check Flag1'
 * '<S11>'  : 'ACCSystem/ACC_Controller/Range Checks/Check Flag2'
 */
#endif                                 /* RTW_HEADER_ACCSystem_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
