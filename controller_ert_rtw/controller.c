/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: controller.c
 *
 * Code generated for Simulink model 'controller'.
 *
 * Model version                  : 1.6
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * C/C++ source code generated on : Fri May 29 11:49:41 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "controller.h"

/* Named constants for Chart: '<Root>/controller' */
#define controller_IN_NO_ACTIVE_CHILD  ((uint8_T)0U)
#define controller_IN_OFF_STATE        ((uint8_T)1U)
#define controller_IN_ON_STATE         ((uint8_T)2U)
#define controller_IN_OVERRIDDEN_STATE ((uint8_T)3U)

/*===========*
 * Constants *
 *===========*/
#define RT_PI                          3.14159265358979323846
#define RT_PIF                         3.1415927F
#define RT_LN_10                       2.30258509299404568402
#define RT_LN_10F                      2.3025851F
#define RT_LOG10E                      0.43429448190325182765
#define RT_LOG10EF                     0.43429449F
#define RT_E                           2.7182818284590452354
#define RT_EF                          2.7182817F

/*
 * UNUSED_PARAMETER(x)
 *   Used to specify that a function parameter (argument) is required but not
 *   accessed by the function body.
 */
#ifndef UNUSED_PARAMETER
# if defined(__LCC__)
#   define UNUSED_PARAMETER(x)                                   /* do nothing */
# else

/*
 * This is the semi-ANSI standard way of indicating that an
 * unused function parameter is required.
 */
#   define UNUSED_PARAMETER(x)         (void) (x)
# endif
#endif

/* Model step function */
void controller_step(RT_MODEL_controller_T *const controller_M, uint8_T
                     controller_U_enableSwitch, uint8_T controller_U_pedalFlag,
                     uint8_T controller_U_resetSwitch, uint8_T
                     *controller_Y_led1)
{
  DW_controller_T *controller_DW = ((DW_controller_T *)
    controller_M->ModelData.dwork);

  /* Chart: '<Root>/controller' incorporates:
   *  Inport: '<Root>/enableSwitch'
   *  Inport: '<Root>/pedalFlag'
   *  Inport: '<Root>/resetSwitch'
   */
  /* Gateway: controller */
  /* During: controller */
  if (controller_DW->is_active_c3_controller == 0U) {
    /* Entry: controller */
    controller_DW->is_active_c3_controller = 1U;

    /* Entry Internal: controller */
    /* Transition: '<S1>:2' */
    controller_DW->is_c3_controller = controller_IN_OFF_STATE;

    /* Outport: '<Root>/led1' */
    /* Entry 'OFF_STATE': '<S1>:1' */
    *controller_Y_led1 = 0U;
  } else {
    switch (controller_DW->is_c3_controller) {
     case controller_IN_OFF_STATE:
      /* During 'OFF_STATE': '<S1>:1' */
      if ((controller_U_pedalFlag == 0) && (controller_U_enableSwitch == 1)) {
        /* Transition: '<S1>:6' */
        controller_DW->is_c3_controller = controller_IN_ON_STATE;

        /* Outport: '<Root>/led1' */
        /* Entry 'ON_STATE': '<S1>:3' */
        *controller_Y_led1 = 1U;
      }
      break;

     case controller_IN_ON_STATE:
      /* During 'ON_STATE': '<S1>:3' */
      if (controller_U_enableSwitch == 0) {
        /* Transition: '<S1>:7' */
        controller_DW->is_c3_controller = controller_IN_OFF_STATE;

        /* Outport: '<Root>/led1' */
        /* Entry 'OFF_STATE': '<S1>:1' */
        *controller_Y_led1 = 0U;
      } else {
        if (controller_U_pedalFlag == 1) {
          /* Transition: '<S1>:13' */
          controller_DW->is_c3_controller = controller_IN_OVERRIDDEN_STATE;

          /* Outport: '<Root>/led1' */
          /* Entry 'OVERRIDDEN_STATE': '<S1>:11' */
          *controller_Y_led1 = 2U;
        }
      }
      break;

     default:
      /* During 'OVERRIDDEN_STATE': '<S1>:11' */
      if (controller_U_enableSwitch == 0) {
        /* Transition: '<S1>:12' */
        controller_DW->is_c3_controller = controller_IN_OFF_STATE;

        /* Outport: '<Root>/led1' */
        /* Entry 'OFF_STATE': '<S1>:1' */
        *controller_Y_led1 = 0U;
      } else {
        if (controller_U_resetSwitch == 1) {
          /* Transition: '<S1>:15' */
          controller_DW->is_c3_controller = controller_IN_ON_STATE;

          /* Outport: '<Root>/led1' */
          /* Entry 'ON_STATE': '<S1>:3' */
          *controller_Y_led1 = 1U;
        }
      }
      break;
    }
  }

  /* End of Chart: '<Root>/controller' */
}

/* Model initialize function */
void controller_initialize(RT_MODEL_controller_T *const controller_M, uint8_T
  *controller_U_enableSwitch, uint8_T *controller_U_pedalFlag, uint8_T
  *controller_U_resetSwitch, uint8_T *controller_Y_led1)
{
  DW_controller_T *controller_DW = ((DW_controller_T *)
    controller_M->ModelData.dwork);

  /* Registration code */

  /* states (dwork) */
  (void) memset((void *)controller_DW, 0,
                sizeof(DW_controller_T));

  /* external inputs */
  (*controller_U_enableSwitch) = 0U;
  (*controller_U_pedalFlag) = 0U;
  (*controller_U_resetSwitch) = 0U;

  /* external outputs */
  (*controller_Y_led1) = 0U;

  /* InitializeConditions for Chart: '<Root>/controller' */
  controller_DW->is_active_c3_controller = 0U;
  controller_DW->is_c3_controller = controller_IN_NO_ACTIVE_CHILD;
}

/* Model terminate function */
void controller_terminate(RT_MODEL_controller_T *const controller_M)
{
  /* (no terminate code required) */
  UNUSED_PARAMETER(controller_M);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
