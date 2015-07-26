/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ACC_Controller.c
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
#define ACC_Controller_IN_WAIT         ((uint8_T)3U)
#define ACC_Controller_IN_WORKING_STATE ((uint8_T)4U)

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
  real_T ACC_Controller_U_Distance, real_T ACC_Controller_U_Speed, uint8_T
  ACC_Controller_U_CANAlive, uint8_T ACC_Controller_U_DistanceAlive, uint8_T
  *ACC_Controller_Y_Go, uint8_T *ACC_Controller_Y_Stop, uint8_T
  *ACC_Controller_Y_Led1)
{
  P_ACC_Controller_T *ACC_Controller_P = ((P_ACC_Controller_T *)
    ACC_Controller_M->ModelData.defaultParam);
  DW_ACC_Controller_T *ACC_Controller_DW = ((DW_ACC_Controller_T *)
    ACC_Controller_M->ModelData.dwork);
  real_T rtb_Delay;
  real_T rtb_Delay1;
  real_T rtb_Delay2;
  real_T rtb_Divide;
  real_T rtb_Add;
  real_T rtb_Delay_m;
  real_T rtb_Delay1_b;
  real_T rtb_Delay2_o;
  boolean_T rtb_LogicalOperator_e;

  /* Delay: '<S5>/Delay' */
  rtb_Delay = ACC_Controller_DW->Delay_DSTATE;

  /* Delay: '<S5>/Delay1' */
  rtb_Delay1 = ACC_Controller_DW->Delay1_DSTATE;

  /* Delay: '<S5>/Delay2' */
  rtb_Delay2 = ACC_Controller_DW->Delay2_DSTATE;

  /* Product: '<S5>/Divide' incorporates:
   *  Constant: '<S5>/Constant'
   *  Delay: '<S5>/Delay'
   *  Delay: '<S5>/Delay1'
   *  Delay: '<S5>/Delay2'
   *  Delay: '<S5>/Delay3'
   *  Inport: '<Root>/Speed'
   *  Sum: '<S5>/Sum'
   *  Sum: '<S5>/Sum1'
   *  Sum: '<S5>/Sum2'
   *  Sum: '<S5>/Sum3'
   */
  rtb_Divide = ((((ACC_Controller_U_Speed + ACC_Controller_DW->Delay_DSTATE) +
                  ACC_Controller_DW->Delay1_DSTATE) +
                 ACC_Controller_DW->Delay2_DSTATE) +
                ACC_Controller_DW->Delay3_DSTATE) /
    ACC_Controller_P->Constant_Value;

  /* Product: '<S2>/Divide1' incorporates:
   *  Constant: '<S2>/Constant'
   */
  rtb_Add = rtb_Divide / ACC_Controller_P->Constant_Value_k;

  /* Product: '<S2>/Y^2' */
  rtb_Add *= rtb_Add;

  /* Switch: '<S2>/Switch' incorporates:
   *  Constant: '<S2>/Constant1'
   *  RelationalOperator: '<S2>/Relational Operator'
   */
  if (!(rtb_Add > ACC_Controller_P->Constant1_Value)) {
    rtb_Add = ACC_Controller_P->Constant1_Value;
  }

  /* End of Switch: '<S2>/Switch' */

  /* Delay: '<S3>/Delay' */
  rtb_Delay_m = ACC_Controller_DW->Delay_DSTATE_f;

  /* Delay: '<S3>/Delay1' */
  rtb_Delay1_b = ACC_Controller_DW->Delay1_DSTATE_f;

  /* Delay: '<S3>/Delay2' */
  rtb_Delay2_o = ACC_Controller_DW->Delay2_DSTATE_h;

  /* Sum: '<S2>/Add' incorporates:
   *  Constant: '<S3>/Constant'
   *  Delay: '<S3>/Delay'
   *  Delay: '<S3>/Delay1'
   *  Delay: '<S3>/Delay2'
   *  Delay: '<S3>/Delay3'
   *  Inport: '<Root>/Distance'
   *  Product: '<S3>/Divide'
   *  Sum: '<S3>/Sum'
   *  Sum: '<S3>/Sum1'
   *  Sum: '<S3>/Sum2'
   *  Sum: '<S3>/Sum3'
   */
  rtb_Add = ((((ACC_Controller_U_Distance + ACC_Controller_DW->Delay_DSTATE_f) +
               ACC_Controller_DW->Delay1_DSTATE_f) +
              ACC_Controller_DW->Delay2_DSTATE_h) +
             ACC_Controller_DW->Delay3_DSTATE_j) /
    ACC_Controller_P->Constant_Value_m - rtb_Add;

  /* Signum: '<S2>/Sign' */
  if (rtb_Add < 0.0) {
    rtb_Add = -1.0;
  } else if (rtb_Add > 0.0) {
    rtb_Add = 1.0;
  } else {
    if (rtb_Add == 0.0) {
      rtb_Add = 0.0;
    }
  }

  /* End of Signum: '<S2>/Sign' */

  /* Logic: '<S4>/Logical Operator' incorporates:
   *  Constant: '<S10>/Constant1'
   *  Constant: '<S10>/Constant4'
   *  Constant: '<S10>/Constant5'
   *  Constant: '<S8>/Constant'
   *  Constant: '<S8>/Constant1'
   *  Constant: '<S8>/Constant2'
   *  Constant: '<S8>/Constant3'
   *  Constant: '<S9>/Constant4'
   *  Constant: '<S9>/Constant5'
   *  Inport: '<Root>/CAN Alive'
   *  Inport: '<Root>/Distance'
   *  Inport: '<Root>/Distance Alive'
   *  Inport: '<Root>/EnableSwitch'
   *  Inport: '<Root>/PedalFlag'
   *  Inport: '<Root>/Speed'
   *  Logic: '<S10>/Logical Operator'
   *  Logic: '<S7>/Logical Operator'
   *  Logic: '<S8>/Logical Operator'
   *  Logic: '<S9>/Logical Operator'
   *  RelationalOperator: '<S10>/Relational Operator1'
   *  RelationalOperator: '<S10>/Relational Operator4'
   *  RelationalOperator: '<S10>/Relational Operator5'
   *  RelationalOperator: '<S8>/Relational Operator'
   *  RelationalOperator: '<S8>/Relational Operator1'
   *  RelationalOperator: '<S8>/Relational Operator2'
   *  RelationalOperator: '<S8>/Relational Operator3'
   *  RelationalOperator: '<S9>/Relational Operator4'
   *  RelationalOperator: '<S9>/Relational Operator5'
   */
  rtb_LogicalOperator_e = ((ACC_Controller_U_Speed >
    ACC_Controller_P->Constant1_Value_e) || (ACC_Controller_U_Speed <
    ACC_Controller_P->Constant_Value_g) || (ACC_Controller_U_Distance >
    ACC_Controller_P->Constant3_Value) || (ACC_Controller_U_Distance <
    ACC_Controller_P->Constant2_Value) || (!((ACC_Controller_U_EnableSwitch ==
    ACC_Controller_P->Constant5_Value) || (ACC_Controller_U_EnableSwitch ==
    ACC_Controller_P->Constant4_Value) || (ACC_Controller_U_EnableSwitch ==
    ACC_Controller_P->Constant1_Value_p))) || (!((ACC_Controller_U_PedalFlag ==
    ACC_Controller_P->Constant5_Value_p) || (ACC_Controller_U_PedalFlag ==
    ACC_Controller_P->Constant4_Value_d))) || (!((ACC_Controller_U_DistanceAlive
    != 0) && (ACC_Controller_U_CANAlive != 0))));

  /* Chart: '<S1>/controller' incorporates:
   *  Inport: '<Root>/EnableSwitch'
   *  Inport: '<Root>/PedalFlag'
   */
  /* Gateway: ACC_Controller/controller */
  if (ACC_Controller_DW->temporalCounter_i1 < 7U) {
    ACC_Controller_DW->temporalCounter_i1++;
  }

  /* During: ACC_Controller/controller */
  if (ACC_Controller_DW->is_active_c3_ACC_Controller == 0U) {
    /* Entry: ACC_Controller/controller */
    ACC_Controller_DW->is_active_c3_ACC_Controller = 1U;

    /* Entry Internal: ACC_Controller/controller */
    /* Transition: '<S6>:2' */
    ACC_Controller_DW->is_c3_ACC_Controller = ACC_Controller_IN_OFF_STATE;

    /* Outport: '<Root>/Led1' */
    /* Entry 'OFF_STATE': '<S6>:1' */
    *ACC_Controller_Y_Led1 = 0U;
  } else {
    switch (ACC_Controller_DW->is_c3_ACC_Controller) {
     case ACC_Controller_IN_OFF_STATE:
      /* During 'OFF_STATE': '<S6>:1' */
      if ((ACC_Controller_U_PedalFlag == 0) && (ACC_Controller_U_EnableSwitch ==
           1)) {
        /* Transition: '<S6>:6' */
        ACC_Controller_DW->is_c3_ACC_Controller = ACC_Controller_IN_ON_STATE;

        /* Entry Internal 'ON_STATE': '<S6>:3' */
        /* Transition: '<S6>:43' */
        ACC_Controller_DW->is_ON_STATE = ACC_Controller_IN_WAIT;
        ACC_Controller_DW->temporalCounter_i1 = 0U;
      }
      break;

     case ACC_Controller_IN_ON_STATE:
      /* During 'ON_STATE': '<S6>:3' */
      if (ACC_Controller_U_EnableSwitch == 0) {
        /* Transition: '<S6>:7' */
        /* Exit Internal 'ON_STATE': '<S6>:3' */
        ACC_Controller_DW->is_ON_STATE = ACC_Controll_IN_NO_ACTIVE_CHILD;

        /* Exit Internal 'WORKING_STATE': '<S6>:39' */
        ACC_Controller_DW->is_WORKING_STATE = ACC_Controll_IN_NO_ACTIVE_CHILD;

        /* Outport: '<Root>/Stop' */
        /* Exit 'ON_STATE': '<S6>:3' */
        *ACC_Controller_Y_Stop = 0U;

        /* Outport: '<Root>/Go' */
        *ACC_Controller_Y_Go = 0U;
        ACC_Controller_DW->is_c3_ACC_Controller = ACC_Controller_IN_OFF_STATE;

        /* Outport: '<Root>/Led1' */
        /* Entry 'OFF_STATE': '<S6>:1' */
        *ACC_Controller_Y_Led1 = 0U;
      } else if ((ACC_Controller_U_PedalFlag == 1) || rtb_LogicalOperator_e) {
        /* Transition: '<S6>:13' */
        /* Exit Internal 'ON_STATE': '<S6>:3' */
        ACC_Controller_DW->is_ON_STATE = ACC_Controll_IN_NO_ACTIVE_CHILD;

        /* Exit Internal 'WORKING_STATE': '<S6>:39' */
        ACC_Controller_DW->is_WORKING_STATE = ACC_Controll_IN_NO_ACTIVE_CHILD;

        /* Outport: '<Root>/Stop' */
        /* Exit 'ON_STATE': '<S6>:3' */
        *ACC_Controller_Y_Stop = 0U;

        /* Outport: '<Root>/Go' */
        *ACC_Controller_Y_Go = 0U;
        ACC_Controller_DW->is_c3_ACC_Controller =
          ACC_Control_IN_OVERRIDDEN_STATE;

        /* Outport: '<Root>/Led1' */
        /* Entry 'OVERRIDDEN_STATE': '<S6>:11' */
        *ACC_Controller_Y_Led1 = 2U;
      } else {
        switch (ACC_Controller_DW->is_ON_STATE) {
         case ACC_Controller_IN_IDLE_STATE:
          /* During 'IDLE_STATE': '<S6>:17' */
          if (rtb_Divide == 0.0) {
            /* Transition: '<S6>:33' */
            ACC_Controller_DW->is_ON_STATE = ACC_Controller_IN_IDLE_STATE;

            /* Outport: '<Root>/Go' */
            /* Entry 'IDLE_STATE': '<S6>:17' */
            *ACC_Controller_Y_Go = 0U;

            /* Outport: '<Root>/Stop' */
            *ACC_Controller_Y_Stop = 0U;
          } else if ((rtb_Add < 0.0) || (rtb_Divide >
                      ACC_Controller_DW->setSpeed)) {
            /* Transition: '<S6>:24' */
            ACC_Controller_DW->is_ON_STATE = ACC_Controller_IN_WORKING_STATE;
            ACC_Controller_DW->is_WORKING_STATE = ACC_Controller_IN_STOP_STATE;

            /* Outport: '<Root>/Go' */
            /* Entry 'STOP_STATE': '<S6>:20' */
            *ACC_Controller_Y_Go = 0U;

            /* Outport: '<Root>/Stop' */
            *ACC_Controller_Y_Stop = 1U;
          } else {
            if ((rtb_Add > 0.0) && (rtb_Divide < ACC_Controller_DW->setSpeed)) {
              /* Transition: '<S6>:45' */
              ACC_Controller_DW->is_ON_STATE = ACC_Controller_IN_WORKING_STATE;
              ACC_Controller_DW->is_WORKING_STATE = ACC_Controller_IN_GO_STATE;

              /* Outport: '<Root>/Go' */
              /* Entry 'GO_STATE': '<S6>:19' */
              *ACC_Controller_Y_Go = 1U;

              /* Outport: '<Root>/Stop' */
              *ACC_Controller_Y_Stop = 0U;
            }
          }
          break;

         case ACC_Controller_IN_INIT_ON:
          /* During 'INIT_ON': '<S6>:47' */
          /* Transition: '<S6>:65' */
          ACC_Controller_DW->is_ON_STATE = ACC_Controller_IN_IDLE_STATE;

          /* Outport: '<Root>/Go' */
          /* Entry 'IDLE_STATE': '<S6>:17' */
          *ACC_Controller_Y_Go = 0U;

          /* Outport: '<Root>/Stop' */
          *ACC_Controller_Y_Stop = 0U;
          break;

         case ACC_Controller_IN_WAIT:
          /* During 'WAIT': '<S6>:41' */
          if (ACC_Controller_DW->temporalCounter_i1 >= 4) {
            /* Transition: '<S6>:42' */
            ACC_Controller_DW->is_ON_STATE = ACC_Controller_IN_INIT_ON;

            /* Outport: '<Root>/Led1' */
            /* Entry 'INIT_ON': '<S6>:47' */
            *ACC_Controller_Y_Led1 = 1U;
            ACC_Controller_DW->setSpeed = rtb_Divide;
          }
          break;

         default:
          /* During 'WORKING_STATE': '<S6>:39' */
          if ((rtb_Divide == 0.0) || ((rtb_Add == 0.0) && (rtb_Divide <=
                ACC_Controller_DW->setSpeed)) || ((rtb_Add >= 0.0) &&
               (rtb_Divide == ACC_Controller_DW->setSpeed))) {
            /* Transition: '<S6>:40' */
            /* Exit Internal 'WORKING_STATE': '<S6>:39' */
            ACC_Controller_DW->is_WORKING_STATE =
              ACC_Controll_IN_NO_ACTIVE_CHILD;
            ACC_Controller_DW->is_ON_STATE = ACC_Controller_IN_IDLE_STATE;

            /* Outport: '<Root>/Go' */
            /* Entry 'IDLE_STATE': '<S6>:17' */
            *ACC_Controller_Y_Go = 0U;

            /* Outport: '<Root>/Stop' */
            *ACC_Controller_Y_Stop = 0U;
          } else if (ACC_Controller_DW->is_WORKING_STATE ==
                     ACC_Controller_IN_GO_STATE) {
            /* During 'GO_STATE': '<S6>:19' */
            if ((rtb_Add < 0.0) || (rtb_Divide > ACC_Controller_DW->setSpeed)) {
              /* Transition: '<S6>:31' */
              ACC_Controller_DW->is_WORKING_STATE = ACC_Controller_IN_STOP_STATE;

              /* Outport: '<Root>/Go' */
              /* Entry 'STOP_STATE': '<S6>:20' */
              *ACC_Controller_Y_Go = 0U;

              /* Outport: '<Root>/Stop' */
              *ACC_Controller_Y_Stop = 1U;
            }
          } else {
            /* During 'STOP_STATE': '<S6>:20' */
            if ((rtb_Add > 0.0) && (rtb_Divide < ACC_Controller_DW->setSpeed)) {
              /* Transition: '<S6>:32' */
              ACC_Controller_DW->is_WORKING_STATE = ACC_Controller_IN_GO_STATE;

              /* Outport: '<Root>/Go' */
              /* Entry 'GO_STATE': '<S6>:19' */
              *ACC_Controller_Y_Go = 1U;

              /* Outport: '<Root>/Stop' */
              *ACC_Controller_Y_Stop = 0U;
            }
          }
          break;
        }
      }
      break;

     default:
      /* During 'OVERRIDDEN_STATE': '<S6>:11' */
      if (ACC_Controller_U_EnableSwitch == 0) {
        /* Transition: '<S6>:12' */
        ACC_Controller_DW->is_c3_ACC_Controller = ACC_Controller_IN_OFF_STATE;

        /* Outport: '<Root>/Led1' */
        /* Entry 'OFF_STATE': '<S6>:1' */
        *ACC_Controller_Y_Led1 = 0U;
      } else if ((ACC_Controller_U_PedalFlag == 1) || rtb_LogicalOperator_e) {
        /* Transition: '<S6>:58' */
        ACC_Controller_DW->is_c3_ACC_Controller =
          ACC_Control_IN_OVERRIDDEN_STATE;

        /* Outport: '<Root>/Led1' */
        /* Entry 'OVERRIDDEN_STATE': '<S6>:11' */
        *ACC_Controller_Y_Led1 = 2U;
      } else {
        if (ACC_Controller_U_EnableSwitch == 2) {
          /* Transition: '<S6>:15' */
          ACC_Controller_DW->is_c3_ACC_Controller = ACC_Controller_IN_ON_STATE;

          /* Entry Internal 'ON_STATE': '<S6>:3' */
          /* Transition: '<S6>:43' */
          ACC_Controller_DW->is_ON_STATE = ACC_Controller_IN_WAIT;
          ACC_Controller_DW->temporalCounter_i1 = 0U;
        }
      }
      break;
    }
  }

  /* End of Chart: '<S1>/controller' */

  /* Update for Delay: '<S5>/Delay' incorporates:
   *  Update for Inport: '<Root>/Speed'
   */
  ACC_Controller_DW->Delay_DSTATE = ACC_Controller_U_Speed;

  /* Update for Delay: '<S5>/Delay1' */
  ACC_Controller_DW->Delay1_DSTATE = rtb_Delay;

  /* Update for Delay: '<S5>/Delay2' */
  ACC_Controller_DW->Delay2_DSTATE = rtb_Delay1;

  /* Update for Delay: '<S5>/Delay3' */
  ACC_Controller_DW->Delay3_DSTATE = rtb_Delay2;

  /* Update for Delay: '<S3>/Delay' incorporates:
   *  Update for Inport: '<Root>/Distance'
   */
  ACC_Controller_DW->Delay_DSTATE_f = ACC_Controller_U_Distance;

  /* Update for Delay: '<S3>/Delay1' */
  ACC_Controller_DW->Delay1_DSTATE_f = rtb_Delay_m;

  /* Update for Delay: '<S3>/Delay2' */
  ACC_Controller_DW->Delay2_DSTATE_h = rtb_Delay1_b;

  /* Update for Delay: '<S3>/Delay3' */
  ACC_Controller_DW->Delay3_DSTATE_j = rtb_Delay2_o;
}

/* Model initialize function */
void ACC_Controller_initialize(RT_MODEL_ACC_Controller_T *const ACC_Controller_M,
  uint8_T *ACC_Controller_U_EnableSwitch, uint8_T *ACC_Controller_U_PedalFlag,
  real_T *ACC_Controller_U_Distance, real_T *ACC_Controller_U_Speed, uint8_T
  *ACC_Controller_U_CANAlive, uint8_T *ACC_Controller_U_DistanceAlive, uint8_T
  *ACC_Controller_Y_Go, uint8_T *ACC_Controller_Y_Stop, uint8_T
  *ACC_Controller_Y_Led1)
{
  P_ACC_Controller_T *ACC_Controller_P = ((P_ACC_Controller_T *)
    ACC_Controller_M->ModelData.defaultParam);
  DW_ACC_Controller_T *ACC_Controller_DW = ((DW_ACC_Controller_T *)
    ACC_Controller_M->ModelData.dwork);

  /* Registration code */

  /* states (dwork) */
  (void) memset((void *)ACC_Controller_DW, 0,
                sizeof(DW_ACC_Controller_T));

  /* external inputs */
  (*ACC_Controller_U_EnableSwitch) = 0U;
  (*ACC_Controller_U_PedalFlag) = 0U;
  (*ACC_Controller_U_Distance) = 0.0;
  (*ACC_Controller_U_Speed) = 0.0;
  (*ACC_Controller_U_CANAlive) = 0U;
  (*ACC_Controller_U_DistanceAlive) = 0U;

  /* external outputs */
  (*ACC_Controller_Y_Go) = 0U;
  (*ACC_Controller_Y_Stop) = 0U;
  (*ACC_Controller_Y_Led1) = 0U;

  /* InitializeConditions for Delay: '<S5>/Delay' */
  ACC_Controller_DW->Delay_DSTATE = ACC_Controller_P->Delay_InitialCondition;

  /* InitializeConditions for Delay: '<S5>/Delay1' */
  ACC_Controller_DW->Delay1_DSTATE = ACC_Controller_P->Delay1_InitialCondition;

  /* InitializeConditions for Delay: '<S5>/Delay2' */
  ACC_Controller_DW->Delay2_DSTATE = ACC_Controller_P->Delay2_InitialCondition;

  /* InitializeConditions for Delay: '<S5>/Delay3' */
  ACC_Controller_DW->Delay3_DSTATE = ACC_Controller_P->Delay3_InitialCondition;

  /* InitializeConditions for Delay: '<S3>/Delay' */
  ACC_Controller_DW->Delay_DSTATE_f = ACC_Controller_P->Delay_InitialCondition_i;

  /* InitializeConditions for Delay: '<S3>/Delay1' */
  ACC_Controller_DW->Delay1_DSTATE_f =
    ACC_Controller_P->Delay1_InitialCondition_o;

  /* InitializeConditions for Delay: '<S3>/Delay2' */
  ACC_Controller_DW->Delay2_DSTATE_h =
    ACC_Controller_P->Delay2_InitialCondition_h;

  /* InitializeConditions for Delay: '<S3>/Delay3' */
  ACC_Controller_DW->Delay3_DSTATE_j =
    ACC_Controller_P->Delay3_InitialCondition_a;

  /* InitializeConditions for Chart: '<S1>/controller' */
  ACC_Controller_DW->is_ON_STATE = ACC_Controll_IN_NO_ACTIVE_CHILD;
  ACC_Controller_DW->temporalCounter_i1 = 0U;
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
