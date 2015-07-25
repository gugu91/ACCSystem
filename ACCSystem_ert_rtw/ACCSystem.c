/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ACCSystem.c
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

#include "ACCSystem.h"

/* Named constants for Chart: '<S1>/controller' */
#define ACCSystem_IN_GO_STATE          ((uint8_T)1U)
#define ACCSystem_IN_IDLE_STATE        ((uint8_T)1U)
#define ACCSystem_IN_INIT_ON           ((uint8_T)2U)
#define ACCSystem_IN_NO_ACTIVE_CHILD   ((uint8_T)0U)
#define ACCSystem_IN_OFF_STATE         ((uint8_T)1U)
#define ACCSystem_IN_ON_STATE          ((uint8_T)2U)
#define ACCSystem_IN_OVERRIDDEN_STATE  ((uint8_T)3U)
#define ACCSystem_IN_STOP_STATE        ((uint8_T)2U)
#define ACCSystem_IN_WAIT              ((uint8_T)3U)
#define ACCSystem_IN_WORKING_STATE     ((uint8_T)4U)

/* Used by FromWorkspace Block: '<S2>/From Workspace1' */
#ifndef rtInterpolate
# define rtInterpolate(v1,v2,f1,f2)    (((v1)==(v2))?((double)(v1)): (((f1)*((double)(v1)))+((f2)*((double)(v2)))))
#endif

#ifndef rtRound
# define rtRound(v)                    ( ((v) >= 0) ? floor((v) + 0.5) : ceil((v) - 0.5) )
#endif

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
void ACCSystem_step(RT_MODEL_ACCSystem_T *const ACCSystem_M)
{
  P_ACCSystem_T *ACCSystem_P = ((P_ACCSystem_T *)
    ACCSystem_M->ModelData.defaultParam);
  DW_ACCSystem_T *ACCSystem_DW = ((DW_ACCSystem_T *)
    ACCSystem_M->ModelData.dwork);

  /* local block i/o variables */
  real_T rtb_FromWorkspace1;
  real_T rtb_FromWorkspace;
  real_T rtb_Delay;
  real_T rtb_Delay1;
  real_T rtb_Delay2;
  real_T rtb_Divide;
  real_T rtb_Add;
  real_T rtb_Delay_m;
  real_T rtb_Delay1_b;
  real_T rtb_Delay2_o;
  boolean_T rtb_LogicalOperator_e;

  /* FromWorkspace: '<S2>/From Workspace1' */
  {
    real_T *pDataValues = (real_T *) ACCSystem_DW->FromWorkspace1_PWORK.DataPtr;
    real_T *pTimeValues = (real_T *) ACCSystem_DW->FromWorkspace1_PWORK.TimePtr;
    int_T currTimeIndex = ACCSystem_DW->FromWorkspace1_IWORK.PrevIndex;
    real_T t = ((ACCSystem_M->Timing.clockTick0) * 0.1);

    /* Get index */
    if (t <= pTimeValues[0]) {
      currTimeIndex = 0;
    } else if (t >= pTimeValues[79]) {
      currTimeIndex = 78;
    } else {
      if (t < pTimeValues[currTimeIndex]) {
        while (t < pTimeValues[currTimeIndex]) {
          currTimeIndex--;
        }
      } else {
        while (t >= pTimeValues[currTimeIndex + 1]) {
          currTimeIndex++;
        }
      }
    }

    ACCSystem_DW->FromWorkspace1_IWORK.PrevIndex = currTimeIndex;

    /* Post output */
    {
      real_T t1 = pTimeValues[currTimeIndex];
      real_T t2 = pTimeValues[currTimeIndex + 1];
      if (t1 == t2) {
        if (t < t1) {
          rtb_FromWorkspace1 = pDataValues[currTimeIndex];
        } else {
          rtb_FromWorkspace1 = pDataValues[currTimeIndex + 1];
        }
      } else {
        real_T f1 = (t2 - t) / (t2 - t1);
        real_T f2 = 1.0 - f1;
        real_T d1;
        real_T d2;
        int_T TimeIndex= currTimeIndex;
        d1 = pDataValues[TimeIndex];
        d2 = pDataValues[TimeIndex + 1];
        rtb_FromWorkspace1 = (real_T) rtInterpolate(d1, d2, f1, f2);
        pDataValues += 80;
      }
    }
  }

  /* Delay: '<S7>/Delay' */
  rtb_Delay = ACCSystem_DW->Delay_DSTATE;

  /* Delay: '<S7>/Delay1' */
  rtb_Delay1 = ACCSystem_DW->Delay1_DSTATE;

  /* Delay: '<S7>/Delay2' */
  rtb_Delay2 = ACCSystem_DW->Delay2_DSTATE;

  /* Product: '<S7>/Divide' incorporates:
   *  Constant: '<S7>/Constant'
   *  Delay: '<S7>/Delay'
   *  Delay: '<S7>/Delay1'
   *  Delay: '<S7>/Delay2'
   *  Delay: '<S7>/Delay3'
   *  Sum: '<S7>/Sum'
   *  Sum: '<S7>/Sum1'
   *  Sum: '<S7>/Sum2'
   *  Sum: '<S7>/Sum3'
   */
  rtb_Divide = ((((rtb_FromWorkspace1 + ACCSystem_DW->Delay_DSTATE) +
                  ACCSystem_DW->Delay1_DSTATE) + ACCSystem_DW->Delay2_DSTATE) +
                ACCSystem_DW->Delay3_DSTATE) / ACCSystem_P->Constant_Value;

  /* Product: '<S4>/Divide1' incorporates:
   *  Constant: '<S4>/Constant'
   */
  rtb_Add = rtb_Divide / ACCSystem_P->Constant_Value_k;

  /* FromWorkspace: '<S2>/From Workspace' */
  {
    real_T *pDataValues = (real_T *) ACCSystem_DW->FromWorkspace_PWORK.DataPtr;
    real_T *pTimeValues = (real_T *) ACCSystem_DW->FromWorkspace_PWORK.TimePtr;
    int_T currTimeIndex = ACCSystem_DW->FromWorkspace_IWORK.PrevIndex;
    real_T t = ((ACCSystem_M->Timing.clockTick0) * 0.1);

    /* Get index */
    if (t <= pTimeValues[0]) {
      currTimeIndex = 0;
    } else if (t >= pTimeValues[79]) {
      currTimeIndex = 78;
    } else {
      if (t < pTimeValues[currTimeIndex]) {
        while (t < pTimeValues[currTimeIndex]) {
          currTimeIndex--;
        }
      } else {
        while (t >= pTimeValues[currTimeIndex + 1]) {
          currTimeIndex++;
        }
      }
    }

    ACCSystem_DW->FromWorkspace_IWORK.PrevIndex = currTimeIndex;

    /* Post output */
    {
      real_T t1 = pTimeValues[currTimeIndex];
      real_T t2 = pTimeValues[currTimeIndex + 1];
      if (t1 == t2) {
        if (t < t1) {
          rtb_FromWorkspace = pDataValues[currTimeIndex];
        } else {
          rtb_FromWorkspace = pDataValues[currTimeIndex + 1];
        }
      } else {
        real_T f1 = (t2 - t) / (t2 - t1);
        real_T f2 = 1.0 - f1;
        real_T d1;
        real_T d2;
        int_T TimeIndex= currTimeIndex;
        d1 = pDataValues[TimeIndex];
        d2 = pDataValues[TimeIndex + 1];
        rtb_FromWorkspace = (real_T) rtInterpolate(d1, d2, f1, f2);
        pDataValues += 80;
      }
    }
  }

  /* Delay: '<S5>/Delay' */
  rtb_Delay_m = ACCSystem_DW->Delay_DSTATE_f;

  /* Delay: '<S5>/Delay1' */
  rtb_Delay1_b = ACCSystem_DW->Delay1_DSTATE_f;

  /* Delay: '<S5>/Delay2' */
  rtb_Delay2_o = ACCSystem_DW->Delay2_DSTATE_h;

  /* Sum: '<S4>/Add' incorporates:
   *  Constant: '<S5>/Constant'
   *  Delay: '<S5>/Delay'
   *  Delay: '<S5>/Delay1'
   *  Delay: '<S5>/Delay2'
   *  Delay: '<S5>/Delay3'
   *  Product: '<S4>/Y^2'
   *  Product: '<S5>/Divide'
   *  Sum: '<S5>/Sum'
   *  Sum: '<S5>/Sum1'
   *  Sum: '<S5>/Sum2'
   *  Sum: '<S5>/Sum3'
   */
  rtb_Add = ((((rtb_FromWorkspace + ACCSystem_DW->Delay_DSTATE_f) +
               ACCSystem_DW->Delay1_DSTATE_f) + ACCSystem_DW->Delay2_DSTATE_h) +
             ACCSystem_DW->Delay3_DSTATE_j) / ACCSystem_P->Constant_Value_m -
    rtb_Add * rtb_Add;

  /* Signum: '<S4>/Sign' */
  if (rtb_Add < 0.0) {
    rtb_Add = -1.0;
  } else if (rtb_Add > 0.0) {
    rtb_Add = 1.0;
  } else {
    if (rtb_Add == 0.0) {
      rtb_Add = 0.0;
    }
  }

  /* End of Signum: '<S4>/Sign' */

  /* Logic: '<S1>/Logical Operator' incorporates:
   *  Constant: '<S10>/Constant4'
   *  Constant: '<S10>/Constant5'
   *  Constant: '<S11>/Constant4'
   *  Constant: '<S11>/Constant5'
   *  Constant: '<S2>/CAN On'
   *  Constant: '<S2>/Distance On'
   *  Constant: '<S2>/Enable Switch On'
   *  Constant: '<S2>/Pedal Flag On'
   *  Constant: '<S2>/Reset Switch On'
   *  Constant: '<S6>/Constant'
   *  Constant: '<S6>/Constant1'
   *  Constant: '<S6>/Constant2'
   *  Constant: '<S6>/Constant3'
   *  Constant: '<S9>/Constant4'
   *  Constant: '<S9>/Constant5'
   *  Logic: '<S10>/Logical Operator'
   *  Logic: '<S11>/Logical Operator'
   *  Logic: '<S3>/Logical Operator'
   *  Logic: '<S6>/Logical Operator'
   *  Logic: '<S9>/Logical Operator'
   *  RelationalOperator: '<S10>/Relational Operator4'
   *  RelationalOperator: '<S10>/Relational Operator5'
   *  RelationalOperator: '<S11>/Relational Operator4'
   *  RelationalOperator: '<S11>/Relational Operator5'
   *  RelationalOperator: '<S6>/Relational Operator'
   *  RelationalOperator: '<S6>/Relational Operator1'
   *  RelationalOperator: '<S6>/Relational Operator2'
   *  RelationalOperator: '<S6>/Relational Operator3'
   *  RelationalOperator: '<S9>/Relational Operator4'
   *  RelationalOperator: '<S9>/Relational Operator5'
   */
  rtb_LogicalOperator_e = ((rtb_FromWorkspace1 > ACCSystem_P->Constant1_Value) ||
    (rtb_FromWorkspace1 < ACCSystem_P->Constant_Value_g) || (rtb_FromWorkspace >
    ACCSystem_P->Constant3_Value) || (rtb_FromWorkspace <
    ACCSystem_P->Constant2_Value) || (!((ACCSystem_P->EnableSwitchOn_Value ==
    ACCSystem_P->Constant5_Value) || (ACCSystem_P->EnableSwitchOn_Value ==
    ACCSystem_P->Constant4_Value))) || (!((ACCSystem_P->PedalFlagOn_Value ==
    ACCSystem_P->Constant5_Value_p) || (ACCSystem_P->PedalFlagOn_Value ==
    ACCSystem_P->Constant4_Value_d))) || (!((ACCSystem_P->ResetSwitchOn_Value ==
    ACCSystem_P->Constant5_Value_m) || (ACCSystem_P->ResetSwitchOn_Value ==
    ACCSystem_P->Constant4_Value_b))) || (!((ACCSystem_P->DistanceOn_Value != 0)
    && (ACCSystem_P->CANOn_Value != 0))));

  /* Chart: '<S1>/controller' incorporates:
   *  Constant: '<S2>/Enable Switch On'
   *  Constant: '<S2>/Pedal Flag On'
   *  Constant: '<S2>/Reset Switch On'
   */
  /* Gateway: ACC_Controller/controller */
  if (ACCSystem_DW->temporalCounter_i1 < 7U) {
    ACCSystem_DW->temporalCounter_i1++;
  }

  /* During: ACC_Controller/controller */
  if (ACCSystem_DW->is_active_c3_ACCSystem == 0U) {
    /* Entry: ACC_Controller/controller */
    ACCSystem_DW->is_active_c3_ACCSystem = 1U;

    /* Entry Internal: ACC_Controller/controller */
    /* Transition: '<S8>:2' */
    ACCSystem_DW->is_c3_ACCSystem = ACCSystem_IN_OFF_STATE;

    /* Entry 'OFF_STATE': '<S8>:1' */
  } else {
    switch (ACCSystem_DW->is_c3_ACCSystem) {
     case ACCSystem_IN_OFF_STATE:
      /* During 'OFF_STATE': '<S8>:1' */
      if ((ACCSystem_P->PedalFlagOn_Value == 0) &&
          (ACCSystem_P->EnableSwitchOn_Value == 1)) {
        /* Transition: '<S8>:6' */
        ACCSystem_DW->is_c3_ACCSystem = ACCSystem_IN_ON_STATE;

        /* Entry Internal 'ON_STATE': '<S8>:3' */
        /* Transition: '<S8>:43' */
        ACCSystem_DW->is_ON_STATE = ACCSystem_IN_WAIT;
        ACCSystem_DW->temporalCounter_i1 = 0U;
      }
      break;

     case ACCSystem_IN_ON_STATE:
      /* During 'ON_STATE': '<S8>:3' */
      if (ACCSystem_P->EnableSwitchOn_Value == 0) {
        /* Transition: '<S8>:7' */
        /* Exit Internal 'ON_STATE': '<S8>:3' */
        ACCSystem_DW->is_ON_STATE = ACCSystem_IN_NO_ACTIVE_CHILD;

        /* Exit Internal 'WORKING_STATE': '<S8>:39' */
        ACCSystem_DW->is_WORKING_STATE = ACCSystem_IN_NO_ACTIVE_CHILD;

        /* Exit 'ON_STATE': '<S8>:3' */
        ACCSystem_DW->is_c3_ACCSystem = ACCSystem_IN_OFF_STATE;

        /* Entry 'OFF_STATE': '<S8>:1' */
      } else if ((ACCSystem_P->PedalFlagOn_Value == 1) || rtb_LogicalOperator_e)
      {
        /* Transition: '<S8>:13' */
        /* Exit Internal 'ON_STATE': '<S8>:3' */
        ACCSystem_DW->is_ON_STATE = ACCSystem_IN_NO_ACTIVE_CHILD;

        /* Exit Internal 'WORKING_STATE': '<S8>:39' */
        ACCSystem_DW->is_WORKING_STATE = ACCSystem_IN_NO_ACTIVE_CHILD;

        /* Exit 'ON_STATE': '<S8>:3' */
        ACCSystem_DW->is_c3_ACCSystem = ACCSystem_IN_OVERRIDDEN_STATE;

        /* Entry 'OVERRIDDEN_STATE': '<S8>:11' */
      } else {
        switch (ACCSystem_DW->is_ON_STATE) {
         case ACCSystem_IN_IDLE_STATE:
          /* During 'IDLE_STATE': '<S8>:17' */
          if (rtb_Divide == 0.0) {
            /* Transition: '<S8>:33' */
            ACCSystem_DW->is_ON_STATE = ACCSystem_IN_IDLE_STATE;

            /* Entry 'IDLE_STATE': '<S8>:17' */
          } else if ((rtb_Add < 0.0) || (rtb_Divide > ACCSystem_DW->setSpeed)) {
            /* Transition: '<S8>:24' */
            ACCSystem_DW->is_ON_STATE = ACCSystem_IN_WORKING_STATE;
            ACCSystem_DW->is_WORKING_STATE = ACCSystem_IN_STOP_STATE;

            /* Entry 'STOP_STATE': '<S8>:20' */
          } else {
            if ((rtb_Add > 0.0) && (rtb_Divide < ACCSystem_DW->setSpeed)) {
              /* Transition: '<S8>:45' */
              ACCSystem_DW->is_ON_STATE = ACCSystem_IN_WORKING_STATE;
              ACCSystem_DW->is_WORKING_STATE = ACCSystem_IN_GO_STATE;

              /* Entry 'GO_STATE': '<S8>:19' */
            }
          }
          break;

         case ACCSystem_IN_INIT_ON:
          /* During 'INIT_ON': '<S8>:47' */
          /* Transition: '<S8>:48' */
          ACCSystem_DW->is_ON_STATE = ACCSystem_IN_IDLE_STATE;

          /* Entry 'IDLE_STATE': '<S8>:17' */
          break;

         case ACCSystem_IN_WAIT:
          /* During 'WAIT': '<S8>:41' */
          if (ACCSystem_DW->temporalCounter_i1 >= 4) {
            /* Transition: '<S8>:42' */
            ACCSystem_DW->is_ON_STATE = ACCSystem_IN_INIT_ON;

            /* Entry 'INIT_ON': '<S8>:47' */
            ACCSystem_DW->setSpeed = rtb_Divide;
          }
          break;

         default:
          /* During 'WORKING_STATE': '<S8>:39' */
          if ((rtb_Divide == 0.0) || ((rtb_Add == 0.0) && (rtb_Divide <=
                ACCSystem_DW->setSpeed)) || ((rtb_Add >= 0.0) && (rtb_Divide ==
                ACCSystem_DW->setSpeed))) {
            /* Transition: '<S8>:40' */
            /* Exit Internal 'WORKING_STATE': '<S8>:39' */
            ACCSystem_DW->is_WORKING_STATE = ACCSystem_IN_NO_ACTIVE_CHILD;
            ACCSystem_DW->is_ON_STATE = ACCSystem_IN_IDLE_STATE;

            /* Entry 'IDLE_STATE': '<S8>:17' */
          } else if (ACCSystem_DW->is_WORKING_STATE == ACCSystem_IN_GO_STATE) {
            /* During 'GO_STATE': '<S8>:19' */
            if ((rtb_Add < 0.0) || (rtb_Divide > ACCSystem_DW->setSpeed)) {
              /* Transition: '<S8>:31' */
              ACCSystem_DW->is_WORKING_STATE = ACCSystem_IN_STOP_STATE;

              /* Entry 'STOP_STATE': '<S8>:20' */
            }
          } else {
            /* During 'STOP_STATE': '<S8>:20' */
            if ((rtb_Add > 0.0) && (rtb_Divide < ACCSystem_DW->setSpeed)) {
              /* Transition: '<S8>:32' */
              ACCSystem_DW->is_WORKING_STATE = ACCSystem_IN_GO_STATE;

              /* Entry 'GO_STATE': '<S8>:19' */
            }
          }
          break;
        }
      }
      break;

     default:
      /* During 'OVERRIDDEN_STATE': '<S8>:11' */
      if (ACCSystem_P->EnableSwitchOn_Value == 0) {
        /* Transition: '<S8>:12' */
        ACCSystem_DW->is_c3_ACCSystem = ACCSystem_IN_OFF_STATE;

        /* Entry 'OFF_STATE': '<S8>:1' */
      } else if ((ACCSystem_P->PedalFlagOn_Value == 1) || rtb_LogicalOperator_e)
      {
        /* Transition: '<S8>:58' */
        ACCSystem_DW->is_c3_ACCSystem = ACCSystem_IN_OVERRIDDEN_STATE;

        /* Entry 'OVERRIDDEN_STATE': '<S8>:11' */
      } else {
        if (ACCSystem_P->ResetSwitchOn_Value == 1) {
          /* Transition: '<S8>:15' */
          ACCSystem_DW->is_c3_ACCSystem = ACCSystem_IN_ON_STATE;

          /* Entry Internal 'ON_STATE': '<S8>:3' */
          /* Transition: '<S8>:43' */
          ACCSystem_DW->is_ON_STATE = ACCSystem_IN_WAIT;
          ACCSystem_DW->temporalCounter_i1 = 0U;
        }
      }
      break;
    }
  }

  /* End of Chart: '<S1>/controller' */

  /* Update for Delay: '<S7>/Delay' */
  ACCSystem_DW->Delay_DSTATE = rtb_FromWorkspace1;

  /* Update for Delay: '<S7>/Delay1' */
  ACCSystem_DW->Delay1_DSTATE = rtb_Delay;

  /* Update for Delay: '<S7>/Delay2' */
  ACCSystem_DW->Delay2_DSTATE = rtb_Delay1;

  /* Update for Delay: '<S7>/Delay3' */
  ACCSystem_DW->Delay3_DSTATE = rtb_Delay2;

  /* Update for Delay: '<S5>/Delay' */
  ACCSystem_DW->Delay_DSTATE_f = rtb_FromWorkspace;

  /* Update for Delay: '<S5>/Delay1' */
  ACCSystem_DW->Delay1_DSTATE_f = rtb_Delay_m;

  /* Update for Delay: '<S5>/Delay2' */
  ACCSystem_DW->Delay2_DSTATE_h = rtb_Delay1_b;

  /* Update for Delay: '<S5>/Delay3' */
  ACCSystem_DW->Delay3_DSTATE_j = rtb_Delay2_o;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.1, which is the step size
   * of the task. Size of "clockTick0" ensures timer will not overflow during the
   * application lifespan selected.
   */
  ACCSystem_M->Timing.clockTick0++;
}

/* Model initialize function */
void ACCSystem_initialize(RT_MODEL_ACCSystem_T *const ACCSystem_M)
{
  P_ACCSystem_T *ACCSystem_P = ((P_ACCSystem_T *)
    ACCSystem_M->ModelData.defaultParam);
  DW_ACCSystem_T *ACCSystem_DW = ((DW_ACCSystem_T *)
    ACCSystem_M->ModelData.dwork);

  /* Registration code */

  /* states (dwork) */
  (void) memset((void *)ACCSystem_DW, 0,
                sizeof(DW_ACCSystem_T));

  /* Start for FromWorkspace: '<S2>/From Workspace1' */
  {
    static real_T pTimeValues0[] = { 0.0, 0.1, 0.2, 0.30000000000000004, 0.4,
      0.5, 0.60000000000000009, 0.70000000000000007, 0.8, 0.9, 1.0, 1.1,
      1.2000000000000002, 1.3, 1.4000000000000001, 1.5, 1.6, 1.7000000000000002,
      1.8, 1.9000000000000001, 2.0, 2.1, 2.2, 2.3000000000000003,
      2.4000000000000004, 2.5, 2.6, 2.7, 2.8000000000000003, 2.9000000000000004,
      3.0, 3.1, 3.2, 3.3000000000000003, 3.4000000000000004, 3.5, 3.6, 3.7,
      3.8000000000000003, 3.9000000000000004, 4.0, 4.1, 4.2, 4.3000000000000007,
      4.4, 4.5, 4.6, 4.7, 4.8000000000000007, 4.9, 5.0, 5.1, 5.2,
      5.3000000000000007, 5.4, 5.5, 5.6, 5.7, 5.8000000000000007, 5.9, 6.0,
      6.1000000000000005, 6.2, 6.3000000000000007, 6.4, 6.5, 6.6000000000000005,
      6.7, 6.8000000000000007, 6.9, 7.0, 7.1000000000000005, 7.2,
      7.3000000000000007, 7.4, 7.5, 7.6000000000000005, 7.7, 7.8000000000000007,
      7.9 } ;

    static real_T pDataValues0[] = { 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0,
      50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0,
      50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0,
      50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 49.0, 49.0, 49.0,
      49.0, 49.0, 49.0, 49.0, 49.0, 49.0, 49.0, 51.0, 51.0, 51.0, 51.0, 51.0,
      51.0, 51.0, 51.0, 51.0, 51.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0,
      50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0,
      50.0 } ;

    ACCSystem_DW->FromWorkspace1_PWORK.TimePtr = (void *) pTimeValues0;
    ACCSystem_DW->FromWorkspace1_PWORK.DataPtr = (void *) pDataValues0;
    ACCSystem_DW->FromWorkspace1_IWORK.PrevIndex = 0;
  }

  /* Start for FromWorkspace: '<S2>/From Workspace' */
  {
    static real_T pTimeValues0[] = { 0.0, 0.1, 0.2, 0.30000000000000004, 0.4,
      0.5, 0.60000000000000009, 0.70000000000000007, 0.8, 0.9, 1.0, 1.1,
      1.2000000000000002, 1.3, 1.4000000000000001, 1.5, 1.6, 1.7000000000000002,
      1.8, 1.9000000000000001, 2.0, 2.1, 2.2, 2.3000000000000003,
      2.4000000000000004, 2.5, 2.6, 2.7, 2.8000000000000003, 2.9000000000000004,
      3.0, 3.1, 3.2, 3.3000000000000003, 3.4000000000000004, 3.5, 3.6, 3.7,
      3.8000000000000003, 3.9000000000000004, 4.0, 4.1, 4.2, 4.3000000000000007,
      4.4, 4.5, 4.6, 4.7, 4.8000000000000007, 4.9, 5.0, 5.1, 5.2,
      5.3000000000000007, 5.4, 5.5, 5.6, 5.7, 5.8000000000000007, 5.9, 6.0,
      6.1000000000000005, 6.2, 6.3000000000000007, 6.4, 6.5, 6.6000000000000005,
      6.7, 6.8000000000000007, 6.9, 7.0, 7.1000000000000005, 7.2,
      7.3000000000000007, 7.4, 7.5, 7.6000000000000005, 7.7, 7.8000000000000007,
      7.9 } ;

    static real_T pDataValues0[] = { 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0,
      2.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 24.6, 24.6, 24.6,
      24.6, 24.6, 24.6, 24.6, 24.6, 24.6, 24.6, 25.0, 25.0, 25.0, 25.0, 25.0,
      25.0, 25.0, 25.0, 25.0, 25.0, 25.0, 25.0, 25.0, 25.0, 25.0, 25.0, 25.0,
      25.0, 25.0, 25.0, 25.0, 25.0, 25.0, 25.0, 25.0, 25.0, 25.0, 25.0, 25.0,
      25.0, 25.4, 25.4, 25.4, 25.4, 25.4, 25.4, 25.4, 25.4, 25.4, 25.4, 20.0,
      20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0 } ;

    ACCSystem_DW->FromWorkspace_PWORK.TimePtr = (void *) pTimeValues0;
    ACCSystem_DW->FromWorkspace_PWORK.DataPtr = (void *) pDataValues0;
    ACCSystem_DW->FromWorkspace_IWORK.PrevIndex = 0;
  }

  /* InitializeConditions for Delay: '<S7>/Delay' */
  ACCSystem_DW->Delay_DSTATE = ACCSystem_P->Delay_InitialCondition;

  /* InitializeConditions for Delay: '<S7>/Delay1' */
  ACCSystem_DW->Delay1_DSTATE = ACCSystem_P->Delay1_InitialCondition;

  /* InitializeConditions for Delay: '<S7>/Delay2' */
  ACCSystem_DW->Delay2_DSTATE = ACCSystem_P->Delay2_InitialCondition;

  /* InitializeConditions for Delay: '<S7>/Delay3' */
  ACCSystem_DW->Delay3_DSTATE = ACCSystem_P->Delay3_InitialCondition;

  /* InitializeConditions for Delay: '<S5>/Delay' */
  ACCSystem_DW->Delay_DSTATE_f = ACCSystem_P->Delay_InitialCondition_i;

  /* InitializeConditions for Delay: '<S5>/Delay1' */
  ACCSystem_DW->Delay1_DSTATE_f = ACCSystem_P->Delay1_InitialCondition_o;

  /* InitializeConditions for Delay: '<S5>/Delay2' */
  ACCSystem_DW->Delay2_DSTATE_h = ACCSystem_P->Delay2_InitialCondition_h;

  /* InitializeConditions for Delay: '<S5>/Delay3' */
  ACCSystem_DW->Delay3_DSTATE_j = ACCSystem_P->Delay3_InitialCondition_a;

  /* InitializeConditions for Chart: '<S1>/controller' */
  ACCSystem_DW->is_ON_STATE = ACCSystem_IN_NO_ACTIVE_CHILD;
  ACCSystem_DW->temporalCounter_i1 = 0U;
  ACCSystem_DW->is_WORKING_STATE = ACCSystem_IN_NO_ACTIVE_CHILD;
  ACCSystem_DW->is_active_c3_ACCSystem = 0U;
  ACCSystem_DW->is_c3_ACCSystem = ACCSystem_IN_NO_ACTIVE_CHILD;
}

/* Model terminate function */
void ACCSystem_terminate(RT_MODEL_ACCSystem_T *const ACCSystem_M)
{
  /* (no terminate code required) */
  UNUSED_PARAMETER(ACCSystem_M);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
