/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ACC_Controller.c
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

#include "ACC_Controller.h"

/* Named constants for Chart: '<S1>/controller' */
#define ACC_Control_IN_OVERRIDDEN_STATE ((uint8_T)3U)
#define ACC_Controll_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define ACC_Controller_IN_GO_STATE     ((uint8_T)1U)
#define ACC_Controller_IN_IDLE_STATE   ((uint8_T)1U)
#define ACC_Controller_IN_INIT_ON      ((uint8_T)2U)
#define ACC_Controller_IN_OFF_STATE    ((uint8_T)1U)
#define ACC_Controller_IN_ON_STATE     ((uint8_T)2U)
#define ACC_Controller_IN_STOP_STATE   ((uint8_T)2U)
#define ACC_Controller_IN_WORKING_STATE ((uint8_T)3U)

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
void ACC_Controller_step(RT_MODEL_ACC_Controller_T *const ACC_Controller_M,
  uint8_T ACC_Controller_U_EnableSwitch, uint8_T ACC_Controller_U_PedalFlag,
  uint8_T ACC_Controller_U_ResetSwitch, real_T ACC_Controller_U_Speed, real_T
  ACC_Controller_U_Distance, uint8_T *ACC_Controller_Y_Led1, uint8_T
  *ACC_Controller_Y_Go, uint8_T *ACC_Controller_Y_Stop)
{
  DW_ACC_Controller_T *ACC_Controller_DW = ((DW_ACC_Controller_T *)
    ACC_Controller_M->ModelData.dwork);
  real_T y;

  /* Chart: '<S1>/controller' incorporates:
   *  Inport: '<Root>/Distance'
   *  Inport: '<Root>/EnableSwitch'
   *  Inport: '<Root>/PedalFlag'
   *  Inport: '<Root>/ResetSwitch'
   *  Inport: '<Root>/Speed'
   */
  /* Gateway: ACC_Controller/controller */
  /* During: ACC_Controller/controller */
  if (ACC_Controller_DW->is_active_c3_ACC_Controller == 0U) {
    /* Entry: ACC_Controller/controller */
    ACC_Controller_DW->is_active_c3_ACC_Controller = 1U;

    /* Entry Internal: ACC_Controller/controller */
    /* Transition: '<S2>:2' */
    ACC_Controller_DW->is_c3_ACC_Controller = ACC_Controller_IN_OFF_STATE;

    /* Outport: '<Root>/Led1' */
    /* Entry 'OFF_STATE': '<S2>:1' */
    *ACC_Controller_Y_Led1 = 0U;
  } else {
    switch (ACC_Controller_DW->is_c3_ACC_Controller) {
     case ACC_Controller_IN_OFF_STATE:
      /* During 'OFF_STATE': '<S2>:1' */
      if ((ACC_Controller_U_PedalFlag == 0) && (ACC_Controller_U_EnableSwitch ==
           1)) {
        /* Transition: '<S2>:6' */
        ACC_Controller_DW->is_c3_ACC_Controller = ACC_Controller_IN_ON_STATE;

        /* Entry Internal 'ON_STATE': '<S2>:3' */
        /* Transition: '<S2>:43' */
        ACC_Controller_DW->is_ON_STATE = ACC_Controller_IN_INIT_ON;

        /* Outport: '<Root>/Led1' */
        /* Entry 'INIT_ON': '<S2>:41' */
        *ACC_Controller_Y_Led1 = 1U;
        ACC_Controller_DW->setSpeed = ACC_Controller_U_Speed;
        y = ACC_Controller_U_Speed / 10.0;
        ACC_Controller_DW->safety = y * y;
      }
      break;

     case ACC_Controller_IN_ON_STATE:
      /* During 'ON_STATE': '<S2>:3' */
      if (ACC_Controller_U_EnableSwitch == 0) {
        /* Transition: '<S2>:7' */
        /* Exit Internal 'ON_STATE': '<S2>:3' */
        ACC_Controller_DW->is_ON_STATE = ACC_Controll_IN_NO_ACTIVE_CHILD;

        /* Exit Internal 'WORKING_STATE': '<S2>:39' */
        ACC_Controller_DW->is_WORKING_STATE = ACC_Controll_IN_NO_ACTIVE_CHILD;
        ACC_Controller_DW->is_c3_ACC_Controller = ACC_Controller_IN_OFF_STATE;

        /* Outport: '<Root>/Led1' */
        /* Entry 'OFF_STATE': '<S2>:1' */
        *ACC_Controller_Y_Led1 = 0U;
      } else if (ACC_Controller_U_PedalFlag == 1) {
        /* Transition: '<S2>:13' */
        /* Exit Internal 'ON_STATE': '<S2>:3' */
        ACC_Controller_DW->is_ON_STATE = ACC_Controll_IN_NO_ACTIVE_CHILD;

        /* Exit Internal 'WORKING_STATE': '<S2>:39' */
        ACC_Controller_DW->is_WORKING_STATE = ACC_Controll_IN_NO_ACTIVE_CHILD;
        ACC_Controller_DW->is_c3_ACC_Controller =
          ACC_Control_IN_OVERRIDDEN_STATE;

        /* Outport: '<Root>/Led1' */
        /* Entry 'OVERRIDDEN_STATE': '<S2>:11' */
        *ACC_Controller_Y_Led1 = 2U;
      } else {
        switch (ACC_Controller_DW->is_ON_STATE) {
         case ACC_Controller_IN_IDLE_STATE:
          /* During 'IDLE_STATE': '<S2>:17' */
          if ((ACC_Controller_U_Speed <= 0.0) || (ACC_Controller_U_Distance ==
               ACC_Controller_DW->safety)) {
            /* Transition: '<S2>:33' */
            ACC_Controller_DW->is_ON_STATE = ACC_Controller_IN_IDLE_STATE;

            /* Outport: '<Root>/Go' */
            /* Entry 'IDLE_STATE': '<S2>:17' */
            *ACC_Controller_Y_Go = 0U;

            /* Outport: '<Root>/Stop' */
            *ACC_Controller_Y_Stop = 0U;
            y = ACC_Controller_U_Speed / 10.0;
            ACC_Controller_DW->safety = y * y;
          } else if (ACC_Controller_U_Distance < ACC_Controller_DW->safety) {
            /* Transition: '<S2>:24' */
            ACC_Controller_DW->is_ON_STATE = ACC_Controller_IN_WORKING_STATE;
            ACC_Controller_DW->is_WORKING_STATE = ACC_Controller_IN_STOP_STATE;

            /* Outport: '<Root>/Go' */
            /* Entry 'STOP_STATE': '<S2>:20' */
            *ACC_Controller_Y_Go = 0U;

            /* Outport: '<Root>/Stop' */
            *ACC_Controller_Y_Stop = 1U;
            y = ACC_Controller_U_Speed / 10.0;
            ACC_Controller_DW->safety = y * y;
          } else if ((ACC_Controller_U_Distance > ACC_Controller_DW->safety) &&
                     (ACC_Controller_U_Speed < ACC_Controller_DW->setSpeed)) {
            /* Transition: '<S2>:45' */
            ACC_Controller_DW->is_ON_STATE = ACC_Controller_IN_WORKING_STATE;
            ACC_Controller_DW->is_WORKING_STATE = ACC_Controller_IN_GO_STATE;

            /* Outport: '<Root>/Go' */
            /* Entry 'GO_STATE': '<S2>:19' */
            *ACC_Controller_Y_Go = 1U;

            /* Outport: '<Root>/Stop' */
            *ACC_Controller_Y_Stop = 0U;
            y = ACC_Controller_U_Speed / 10.0;
            ACC_Controller_DW->safety = y * y;
          } else {
            y = ACC_Controller_U_Speed / 10.0;
            ACC_Controller_DW->safety = y * y;
          }
          break;

         case ACC_Controller_IN_INIT_ON:
          /* During 'INIT_ON': '<S2>:41' */
          /* Transition: '<S2>:42' */
          ACC_Controller_DW->is_ON_STATE = ACC_Controller_IN_IDLE_STATE;

          /* Outport: '<Root>/Go' */
          /* Entry 'IDLE_STATE': '<S2>:17' */
          *ACC_Controller_Y_Go = 0U;

          /* Outport: '<Root>/Stop' */
          *ACC_Controller_Y_Stop = 0U;
          y = ACC_Controller_U_Speed / 10.0;
          ACC_Controller_DW->safety = y * y;
          break;

         default:
          /* During 'WORKING_STATE': '<S2>:39' */
          if ((ACC_Controller_U_Speed <= 0.0) || (ACC_Controller_U_Distance ==
               ACC_Controller_DW->safety) || (ACC_Controller_U_Distance <
               ACC_Controller_DW->safety) || (ACC_Controller_U_Speed ==
               ACC_Controller_DW->setSpeed)) {
            /* Transition: '<S2>:40' */
            /* Exit Internal 'WORKING_STATE': '<S2>:39' */
            ACC_Controller_DW->is_WORKING_STATE =
              ACC_Controll_IN_NO_ACTIVE_CHILD;
            ACC_Controller_DW->is_ON_STATE = ACC_Controller_IN_IDLE_STATE;

            /* Outport: '<Root>/Go' */
            /* Entry 'IDLE_STATE': '<S2>:17' */
            *ACC_Controller_Y_Go = 0U;

            /* Outport: '<Root>/Stop' */
            *ACC_Controller_Y_Stop = 0U;
            y = ACC_Controller_U_Speed / 10.0;
            ACC_Controller_DW->safety = y * y;
          } else if (ACC_Controller_DW->is_WORKING_STATE ==
                     ACC_Controller_IN_GO_STATE) {
            /* During 'GO_STATE': '<S2>:19' */
            if ((ACC_Controller_U_Distance < ACC_Controller_DW->safety) ||
                (ACC_Controller_U_Speed > ACC_Controller_DW->setSpeed)) {
              /* Transition: '<S2>:31' */
              ACC_Controller_DW->is_WORKING_STATE = ACC_Controller_IN_STOP_STATE;

              /* Outport: '<Root>/Go' */
              /* Entry 'STOP_STATE': '<S2>:20' */
              *ACC_Controller_Y_Go = 0U;

              /* Outport: '<Root>/Stop' */
              *ACC_Controller_Y_Stop = 1U;
              y = ACC_Controller_U_Speed / 10.0;
              ACC_Controller_DW->safety = y * y;
            } else {
              y = ACC_Controller_U_Speed / 10.0;
              ACC_Controller_DW->safety = y * y;
            }
          } else {
            /* During 'STOP_STATE': '<S2>:20' */
            if ((ACC_Controller_U_Distance > ACC_Controller_DW->safety) &&
                (ACC_Controller_U_Speed < ACC_Controller_DW->setSpeed)) {
              /* Transition: '<S2>:32' */
              ACC_Controller_DW->is_WORKING_STATE = ACC_Controller_IN_GO_STATE;

              /* Outport: '<Root>/Go' */
              /* Entry 'GO_STATE': '<S2>:19' */
              *ACC_Controller_Y_Go = 1U;

              /* Outport: '<Root>/Stop' */
              *ACC_Controller_Y_Stop = 0U;
              y = ACC_Controller_U_Speed / 10.0;
              ACC_Controller_DW->safety = y * y;
            } else {
              y = ACC_Controller_U_Speed / 10.0;
              ACC_Controller_DW->safety = y * y;
            }
          }
          break;
        }
      }
      break;

     default:
      /* During 'OVERRIDDEN_STATE': '<S2>:11' */
      if (ACC_Controller_U_EnableSwitch == 0) {
        /* Transition: '<S2>:12' */
        ACC_Controller_DW->is_c3_ACC_Controller = ACC_Controller_IN_OFF_STATE;

        /* Outport: '<Root>/Led1' */
        /* Entry 'OFF_STATE': '<S2>:1' */
        *ACC_Controller_Y_Led1 = 0U;
      } else {
        if (ACC_Controller_U_ResetSwitch == 1) {
          /* Transition: '<S2>:15' */
          ACC_Controller_DW->is_c3_ACC_Controller = ACC_Controller_IN_ON_STATE;

          /* Entry Internal 'ON_STATE': '<S2>:3' */
          /* Transition: '<S2>:43' */
          ACC_Controller_DW->is_ON_STATE = ACC_Controller_IN_INIT_ON;

          /* Outport: '<Root>/Led1' */
          /* Entry 'INIT_ON': '<S2>:41' */
          *ACC_Controller_Y_Led1 = 1U;
          ACC_Controller_DW->setSpeed = ACC_Controller_U_Speed;
          y = ACC_Controller_U_Speed / 10.0;
          ACC_Controller_DW->safety = y * y;
        }
      }
      break;
    }
  }

  /* End of Chart: '<S1>/controller' */
}

/* Model initialize function */
void ACC_Controller_initialize(RT_MODEL_ACC_Controller_T *const ACC_Controller_M,
  uint8_T *ACC_Controller_U_EnableSwitch, uint8_T *ACC_Controller_U_PedalFlag,
  uint8_T *ACC_Controller_U_ResetSwitch, real_T *ACC_Controller_U_Speed, real_T *
  ACC_Controller_U_Distance, uint8_T *ACC_Controller_Y_Led1, uint8_T
  *ACC_Controller_Y_Go, uint8_T *ACC_Controller_Y_Stop)
{
  DW_ACC_Controller_T *ACC_Controller_DW = ((DW_ACC_Controller_T *)
    ACC_Controller_M->ModelData.dwork);

  /* Registration code */

  /* states (dwork) */
  (void) memset((void *)ACC_Controller_DW, 0,
                sizeof(DW_ACC_Controller_T));

  /* external inputs */
  (*ACC_Controller_U_EnableSwitch) = 0U;
  (*ACC_Controller_U_PedalFlag) = 0U;
  (*ACC_Controller_U_ResetSwitch) = 0U;
  (*ACC_Controller_U_Speed) = 0.0;
  (*ACC_Controller_U_Distance) = 0.0;

  /* external outputs */
  (*ACC_Controller_Y_Led1) = 0U;
  (*ACC_Controller_Y_Go) = 0U;
  (*ACC_Controller_Y_Stop) = 0U;

  /* InitializeConditions for Chart: '<S1>/controller' */
  ACC_Controller_DW->is_ON_STATE = ACC_Controll_IN_NO_ACTIVE_CHILD;
  ACC_Controller_DW->is_WORKING_STATE = ACC_Controll_IN_NO_ACTIVE_CHILD;
  ACC_Controller_DW->is_active_c3_ACC_Controller = 0U;
  ACC_Controller_DW->is_c3_ACC_Controller = ACC_Controll_IN_NO_ACTIVE_CHILD;
}

/* Model terminate function */
void ACC_Controller_terminate(RT_MODEL_ACC_Controller_T *const ACC_Controller_M)
{
  /* (no terminate code required) */
  UNUSED_PARAMETER(ACC_Controller_M);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
