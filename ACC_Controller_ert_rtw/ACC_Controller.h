/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ACC_Controller.h
 *
 * Code generated for Simulink model 'ACC_Controller'.
 *
 * Model version                  : 1.16
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * C/C++ source code generated on : Tue Jul  7 19:24:08 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_ACC_Controller_h_
#define RTW_HEADER_ACC_Controller_h_
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
  real_T setSpeed;                     /* '<S1>/controller' */
  real_T safety;                       /* '<S1>/controller' */
  uint8_T is_active_c3_ACC_Controller; /* '<S1>/controller' */
  uint8_T is_c3_ACC_Controller;        /* '<S1>/controller' */
  uint8_T is_ON_STATE;                 /* '<S1>/controller' */
  uint8_T is_WORKING_STATE;            /* '<S1>/controller' */
} DW_ACC_Controller_T;

/* Real-time Model Data Structure */
struct tag_RTM_ACC_Controller_T {
  const char_T * volatile errorStatus;

  /*
   * ModelData:
   * The following substructure contains information regarding
   * the data used in the model.
   */
  struct {
    DW_ACC_Controller_T *dwork;
  } ModelData;
};

/* Model entry point functions */
extern void ACC_Controller_initialize(RT_MODEL_ACC_Controller_T *const
  ACC_Controller_M, uint8_T *ACC_Controller_U_EnableSwitch, uint8_T
  *ACC_Controller_U_PedalFlag, uint8_T *ACC_Controller_U_ResetSwitch, real_T
  *ACC_Controller_U_Speed, real_T *ACC_Controller_U_Distance, uint8_T
  *ACC_Controller_Y_Led1, uint8_T *ACC_Controller_Y_Go, uint8_T
  *ACC_Controller_Y_Stop);
extern void ACC_Controller_step(RT_MODEL_ACC_Controller_T *const
  ACC_Controller_M, uint8_T ACC_Controller_U_EnableSwitch, uint8_T
  ACC_Controller_U_PedalFlag, uint8_T ACC_Controller_U_ResetSwitch, real_T
  ACC_Controller_U_Speed, real_T ACC_Controller_U_Distance, uint8_T
  *ACC_Controller_Y_Led1, uint8_T *ACC_Controller_Y_Go, uint8_T
  *ACC_Controller_Y_Stop);
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
 * '<S2>'   : 'ACCSystem/ACC_Controller/controller'
 */
#endif                                 /* RTW_HEADER_ACC_Controller_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
