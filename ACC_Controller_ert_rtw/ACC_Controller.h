/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ACC_Controller.h
 *
 * Code generated for Simulink model 'ACC_Controller'.
 *
 * Model version                  : 1.33
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * C/C++ source code generated on : Mon Jul 20 22:30:36 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_ACC_Controller_h_
#define RTW_HEADER_ACC_Controller_h_
#include "rtwtypes.h"
#include <string.h>
#ifndef ACC_Controller_COMMON_INCLUDES_
# define ACC_Controller_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* ACC_Controller_COMMON_INCLUDES_ */

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM_ACC_Controller_T RT_MODEL_ACC_Controller_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T Delay_DSTATE;                 /* '<S6>/Delay' */
  real_T Delay1_DSTATE;                /* '<S6>/Delay1' */
  real_T Delay2_DSTATE;                /* '<S6>/Delay2' */
  real_T Delay3_DSTATE;                /* '<S6>/Delay3' */
  real_T Delay_DSTATE_f;               /* '<S4>/Delay' */
  real_T Delay1_DSTATE_f;              /* '<S4>/Delay1' */
  real_T Delay2_DSTATE_h;              /* '<S4>/Delay2' */
  real_T Delay3_DSTATE_j;              /* '<S4>/Delay3' */
  real_T setSpeed;                     /* '<S1>/controller' */
  uint8_T is_active_c3_ACC_Controller; /* '<S1>/controller' */
  uint8_T is_c3_ACC_Controller;        /* '<S1>/controller' */
  uint8_T is_ON_STATE;                 /* '<S1>/controller' */
  uint8_T is_WORKING_STATE;            /* '<S1>/controller' */
  uint8_T temporalCounter_i1;          /* '<S1>/controller' */
} DW_ACC_Controller_T;

/* Parameters (auto storage) */
struct P_ACC_Controller_T_ {
  real_T Delay_InitialCondition;       /* Expression: 0
                                        * Referenced by: '<S6>/Delay'
                                        */
  real_T Delay1_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<S6>/Delay1'
                                        */
  real_T Delay2_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<S6>/Delay2'
                                        */
  real_T Delay3_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<S6>/Delay3'
                                        */
  real_T Constant_Value;               /* Expression: 5
                                        * Referenced by: '<S6>/Constant'
                                        */
  real_T Constant_Value_k;             /* Expression: 10
                                        * Referenced by: '<S3>/Constant'
                                        */
  real_T Delay_InitialCondition_i;     /* Expression: 0
                                        * Referenced by: '<S4>/Delay'
                                        */
  real_T Delay1_InitialCondition_o;    /* Expression: 0
                                        * Referenced by: '<S4>/Delay1'
                                        */
  real_T Delay2_InitialCondition_h;    /* Expression: 0
                                        * Referenced by: '<S4>/Delay2'
                                        */
  real_T Delay3_InitialCondition_a;    /* Expression: 0
                                        * Referenced by: '<S4>/Delay3'
                                        */
  real_T Constant_Value_m;             /* Expression: 5
                                        * Referenced by: '<S4>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 160
                                        * Referenced by: '<S5>/Constant1'
                                        */
  real_T Constant_Value_g;             /* Expression: 0
                                        * Referenced by: '<S5>/Constant'
                                        */
  real_T Constant3_Value;              /* Expression: 400
                                        * Referenced by: '<S5>/Constant3'
                                        */
  real_T Constant2_Value;              /* Expression: 2
                                        * Referenced by: '<S5>/Constant2'
                                        */
  uint32_T Delay_DelayLength;          /* Computed Parameter: Delay_DelayLength
                                        * Referenced by: '<S6>/Delay'
                                        */
  uint32_T Delay1_DelayLength;         /* Computed Parameter: Delay1_DelayLength
                                        * Referenced by: '<S6>/Delay1'
                                        */
  uint32_T Delay2_DelayLength;         /* Computed Parameter: Delay2_DelayLength
                                        * Referenced by: '<S6>/Delay2'
                                        */
  uint32_T Delay3_DelayLength;         /* Computed Parameter: Delay3_DelayLength
                                        * Referenced by: '<S6>/Delay3'
                                        */
  uint32_T Delay_DelayLength_i;        /* Computed Parameter: Delay_DelayLength_i
                                        * Referenced by: '<S4>/Delay'
                                        */
  uint32_T Delay1_DelayLength_p;       /* Computed Parameter: Delay1_DelayLength_p
                                        * Referenced by: '<S4>/Delay1'
                                        */
  uint32_T Delay2_DelayLength_b;       /* Computed Parameter: Delay2_DelayLength_b
                                        * Referenced by: '<S4>/Delay2'
                                        */
  uint32_T Delay3_DelayLength_h;       /* Computed Parameter: Delay3_DelayLength_h
                                        * Referenced by: '<S4>/Delay3'
                                        */
  uint8_T Constant5_Value;             /* Computed Parameter: Constant5_Value
                                        * Referenced by: '<S8>/Constant5'
                                        */
  uint8_T Constant4_Value;             /* Computed Parameter: Constant4_Value
                                        * Referenced by: '<S8>/Constant4'
                                        */
  uint8_T Constant5_Value_p;           /* Computed Parameter: Constant5_Value_p
                                        * Referenced by: '<S9>/Constant5'
                                        */
  uint8_T Constant4_Value_d;           /* Computed Parameter: Constant4_Value_d
                                        * Referenced by: '<S9>/Constant4'
                                        */
  uint8_T Constant5_Value_m;           /* Computed Parameter: Constant5_Value_m
                                        * Referenced by: '<S10>/Constant5'
                                        */
  uint8_T Constant4_Value_b;           /* Computed Parameter: Constant4_Value_b
                                        * Referenced by: '<S10>/Constant4'
                                        */
};

/* Parameters (auto storage) */
typedef struct P_ACC_Controller_T_ P_ACC_Controller_T;

/* Real-time Model Data Structure */
struct tag_RTM_ACC_Controller_T {
  const char_T * volatile errorStatus;

  /*
   * ModelData:
   * The following substructure contains information regarding
   * the data used in the model.
   */
  struct {
    P_ACC_Controller_T *defaultParam;
    DW_ACC_Controller_T *dwork;
  } ModelData;
};

/* Model entry point functions */
extern void ACC_Controller_initialize(RT_MODEL_ACC_Controller_T *const
  ACC_Controller_M, uint8_T *ACC_Controller_U_EnableSwitch, uint8_T
  *ACC_Controller_U_PedalFlag, uint8_T *ACC_Controller_U_ResetSwitch, real_T
  *ACC_Controller_U_Distance, real_T *ACC_Controller_U_Speed, uint8_T
  *ACC_Controller_U_CANAlive, uint8_T *ACC_Controller_U_DistanceAlive, uint8_T
  *ACC_Controller_Y_Go, uint8_T *ACC_Controller_Y_Stop, real_T
  *ACC_Controller_Y_d, uint8_T *ACC_Controller_Y_Led1);
extern void ACC_Controller_step(RT_MODEL_ACC_Controller_T *const
  ACC_Controller_M, uint8_T ACC_Controller_U_EnableSwitch, uint8_T
  ACC_Controller_U_PedalFlag, uint8_T ACC_Controller_U_ResetSwitch, real_T
  ACC_Controller_U_Distance, real_T ACC_Controller_U_Speed, uint8_T
  ACC_Controller_U_CANAlive, uint8_T ACC_Controller_U_DistanceAlive, uint8_T
  *ACC_Controller_Y_Go, uint8_T *ACC_Controller_Y_Stop, real_T
  *ACC_Controller_Y_d, uint8_T *ACC_Controller_Y_Led1);
extern void ACC_Controller_terminate(RT_MODEL_ACC_Controller_T *const
  ACC_Controller_M);

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('ACCSystem/ACC_Controller')    - opens subsystem ACCSystem/ACC_Controller
 * hilite_system('ACCSystem/ACC_Controller/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'ACCSystem'
 * '<S1>'   : 'ACCSystem/ACC_Controller'
 * '<S2>'   : 'ACCSystem/ACC_Controller/Age Checks'
 * '<S3>'   : 'ACCSystem/ACC_Controller/Compute Safety Speed'
 * '<S4>'   : 'ACCSystem/ACC_Controller/Distance Average'
 * '<S5>'   : 'ACCSystem/ACC_Controller/Range Checks'
 * '<S6>'   : 'ACCSystem/ACC_Controller/Speed Average'
 * '<S7>'   : 'ACCSystem/ACC_Controller/controller'
 * '<S8>'   : 'ACCSystem/ACC_Controller/Range Checks/Check Flag'
 * '<S9>'   : 'ACCSystem/ACC_Controller/Range Checks/Check Flag1'
 * '<S10>'  : 'ACCSystem/ACC_Controller/Range Checks/Check Flag2'
 */
#endif                                 /* RTW_HEADER_ACC_Controller_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
