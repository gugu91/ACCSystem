/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ACCSystem.c
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
#define ACCSystem_IN_WORKING_STATE     ((uint8_T)3U)
#include "solver_zc.h"
#include "zero_crossing_types.h"
#ifndef slZcHadEvent
#define slZcHadEvent(ev, zcsDir)       (((ev) & (zcsDir)) != 0x00 )
#endif

#ifndef slZcUnAliasEvents
#define slZcUnAliasEvents(evL, evR)    ((((slZcHadEvent((evL), (SL_ZCS_EVENT_N2Z)) && slZcHadEvent((evR), (SL_ZCS_EVENT_Z2P))) || (slZcHadEvent((evL), (SL_ZCS_EVENT_P2Z)) && slZcHadEvent((evR), (SL_ZCS_EVENT_Z2N)))) ? (SL_ZCS_EVENT_NUL) : (evR)))
#endif

#define NumBitsPerChar                 8U

extern real_T rt_urand_Upu32_Yd_f_pw_snf(uint32_T *u);
extern real_T rt_nrand_Upu32_Yd_f_pw_snf(uint32_T *u);
extern ZCEventType rt_ZCFcn(ZCDirection zcDir, ZCSigState *prevZc, real_T
  currValue);
extern real_T rtInf;
extern real_T rtMinusInf;
extern real_T rtNaN;
extern real32_T rtInfF;
extern real32_T rtMinusInfF;
extern real32_T rtNaNF;
extern void rt_InitInfAndNaN(size_t realSize);
extern boolean_T rtIsInf(real_T value);
extern boolean_T rtIsInfF(real32_T value);
extern boolean_T rtIsNaN(real_T value);
extern boolean_T rtIsNaNF(real32_T value);
typedef struct {
  struct {
    uint32_T wordH;
    uint32_T wordL;
  } words;
} BigEndianIEEEDouble;

typedef struct {
  struct {
    uint32_T wordL;
    uint32_T wordH;
  } words;
} LittleEndianIEEEDouble;

typedef struct {
  union {
    real32_T wordLreal;
    uint32_T wordLuint;
  } wordL;
} IEEESingle;

real_T rtInf;
real_T rtMinusInf;
real_T rtNaN;
real32_T rtInfF;
real32_T rtMinusInfF;
real32_T rtNaNF;
extern real_T rtGetInf(void);
extern real32_T rtGetInfF(void);
extern real_T rtGetMinusInf(void);
extern real32_T rtGetMinusInfF(void);
extern real_T rtGetNaN(void);
extern real32_T rtGetNaNF(void);

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

/* Detect zero crossings events. */
ZCEventType rt_ZCFcn(ZCDirection zcDir, ZCSigState* prevZc, real_T currValue)
{
  slZcEventType zcsDir;
  slZcEventType tempEv;
  ZCEventType zcEvent = NO_ZCEVENT;    /* assume */

  /* zcEvent matrix */
  static const slZcEventType eventMatrix[4][4] = {
    /*          ZER              POS              NEG              UNK */
    { SL_ZCS_EVENT_NUL, SL_ZCS_EVENT_Z2P, SL_ZCS_EVENT_Z2N, SL_ZCS_EVENT_NUL },/* ZER */

    { SL_ZCS_EVENT_P2Z, SL_ZCS_EVENT_NUL, SL_ZCS_EVENT_P2N, SL_ZCS_EVENT_NUL },/* POS */

    { SL_ZCS_EVENT_N2Z, SL_ZCS_EVENT_N2P, SL_ZCS_EVENT_NUL, SL_ZCS_EVENT_NUL },/* NEG */

    { SL_ZCS_EVENT_NUL, SL_ZCS_EVENT_NUL, SL_ZCS_EVENT_NUL, SL_ZCS_EVENT_NUL }/* UNK */
  };

  /* get prevZcEvent and prevZcSign from prevZc */
  slZcEventType prevEv = (slZcEventType)(((uint8_T)(*prevZc)) >> 2);
  slZcSignalSignType prevSign = (slZcSignalSignType)(((uint8_T)(*prevZc)) &
    (uint8_T)0x03);

  /* get current zcSignal sign from current zcSignal value */
  slZcSignalSignType currSign = (slZcSignalSignType)((currValue) > 0.0 ?
    SL_ZCS_SIGN_POS :
    ((currValue) < 0.0 ? SL_ZCS_SIGN_NEG : SL_ZCS_SIGN_ZERO));

  /* get current zcEvent based on prev and current zcSignal value */
  slZcEventType currEv = eventMatrix[prevSign][currSign];

  /* get slZcEventType from ZCDirection */
  switch (zcDir) {
   case ANY_ZERO_CROSSING:
    zcsDir = SL_ZCS_EVENT_ALL;
    break;

   case FALLING_ZERO_CROSSING:
    zcsDir = SL_ZCS_EVENT_ALL_DN;
    break;

   case RISING_ZERO_CROSSING:
    zcsDir = SL_ZCS_EVENT_ALL_UP;
    break;

   default:
    zcsDir = SL_ZCS_EVENT_NUL;
    break;
  }

  /*had event, check if double zc happend remove double detection. */
  if (slZcHadEvent(currEv, zcsDir)) {
    currEv = (slZcEventType)(slZcUnAliasEvents(prevEv, currEv));
  } else {
    currEv = SL_ZCS_EVENT_NUL;
  }

  /* Update prevZc */
  tempEv = (slZcEventType)(currEv << 2);/* shift left by 2 bits */
  *prevZc = (ZCSigState)((currSign) | (tempEv));
  if ((currEv & SL_ZCS_EVENT_ALL_DN) != 0) {
    zcEvent = FALLING_ZCEVENT;
  } else if ((currEv & SL_ZCS_EVENT_ALL_UP) != 0) {
    zcEvent = RISING_ZCEVENT;
  } else {
    zcEvent = NO_ZCEVENT;
  }

  return zcEvent;
}                                      /* rt_ZCFcn */

/*
 * Initialize the rtInf, rtMinusInf, and rtNaN needed by the
 * generated code. NaN is initialized as non-signaling. Assumes IEEE.
 */
void rt_InitInfAndNaN(size_t realSize)
{
  (void) (realSize);
  rtNaN = rtGetNaN();
  rtNaNF = rtGetNaNF();
  rtInf = rtGetInf();
  rtInfF = rtGetInfF();
  rtMinusInf = rtGetMinusInf();
  rtMinusInfF = rtGetMinusInfF();
}

/* Test if value is infinite */
boolean_T rtIsInf(real_T value)
{
  return (boolean_T)((value==rtInf || value==rtMinusInf) ? 1U : 0U);
}

/* Test if single-precision value is infinite */
boolean_T rtIsInfF(real32_T value)
{
  return (boolean_T)(((value)==rtInfF || (value)==rtMinusInfF) ? 1U : 0U);
}

/* Test if value is not a number */
boolean_T rtIsNaN(real_T value)
{
  return (boolean_T)((value!=value) ? 1U : 0U);
}

/* Test if single-precision value is not a number */
boolean_T rtIsNaNF(real32_T value)
{
  return (boolean_T)(((value!=value) ? 1U : 0U));
}

/*
 * Initialize rtInf needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
real_T rtGetInf(void)
{
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  real_T inf = 0.0;
  if (bitsPerReal == 32U) {
    inf = rtGetInfF();
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.bitVal.words.wordH = 0x7FF00000U;
    tmpVal.bitVal.words.wordL = 0x00000000U;
    inf = tmpVal.fltVal;
  }

  return inf;
}

/*
 * Initialize rtInfF needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
real32_T rtGetInfF(void)
{
  IEEESingle infF;
  infF.wordL.wordLuint = 0x7F800000U;
  return infF.wordL.wordLreal;
}

/*
 * Initialize rtMinusInf needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
real_T rtGetMinusInf(void)
{
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  real_T minf = 0.0;
  if (bitsPerReal == 32U) {
    minf = rtGetMinusInfF();
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.bitVal.words.wordH = 0xFFF00000U;
    tmpVal.bitVal.words.wordL = 0x00000000U;
    minf = tmpVal.fltVal;
  }

  return minf;
}

/*
 * Initialize rtMinusInfF needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
real32_T rtGetMinusInfF(void)
{
  IEEESingle minfF;
  minfF.wordL.wordLuint = 0xFF800000U;
  return minfF.wordL.wordLreal;
}

/*
 * Initialize rtNaN needed by the generated code.
 * NaN is initialized as non-signaling. Assumes IEEE.
 */
real_T rtGetNaN(void)
{
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  real_T nan = 0.0;
  if (bitsPerReal == 32U) {
    nan = rtGetNaNF();
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.bitVal.words.wordH = 0xFFF80000U;
    tmpVal.bitVal.words.wordL = 0x00000000U;
    nan = tmpVal.fltVal;
  }

  return nan;
}

/*
 * Initialize rtNaNF needed by the generated code.
 * NaN is initialized as non-signaling. Assumes IEEE.
 */
real32_T rtGetNaNF(void)
{
  IEEESingle nanF = { { 0 } };

  nanF.wordL.wordLuint = 0xFFC00000U;
  return nanF.wordL.wordLreal;
}

real_T rt_urand_Upu32_Yd_f_pw_snf(uint32_T *u)
{
  uint32_T lo;
  uint32_T hi;

  /* Uniform random number generator (random number between 0 and 1)

     #define IA      16807                      magic multiplier = 7^5
     #define IM      2147483647                 modulus = 2^31-1
     #define IQ      127773                     IM div IA
     #define IR      2836                       IM modulo IA
     #define S       4.656612875245797e-10      reciprocal of 2^31-1
     test = IA * (seed % IQ) - IR * (seed/IQ)
     seed = test < 0 ? (test + IM) : test
     return (seed*S)
   */
  lo = *u % 127773U * 16807U;
  hi = *u / 127773U * 2836U;
  if (lo < hi) {
    *u = 2147483647U - (hi - lo);
  } else {
    *u = lo - hi;
  }

  return (real_T)*u * 4.6566128752457969E-10;
}

real_T rt_nrand_Upu32_Yd_f_pw_snf(uint32_T *u)
{
  real_T y;
  real_T sr;
  real_T si;

  /* Normal (Gaussian) random number generator */
  do {
    sr = 2.0 * rt_urand_Upu32_Yd_f_pw_snf(u) - 1.0;
    si = 2.0 * rt_urand_Upu32_Yd_f_pw_snf(u) - 1.0;
    si = sr * sr + si * si;
  } while (si > 1.0);

  y = sqrt(-2.0 * log(si) / si) * sr;
  return y;
}

/* Model step function */
void ACCSystem_step(RT_MODEL_ACCSystem_T *const ACCSystem_M)
{
  P_ACCSystem_T *ACCSystem_P = ((P_ACCSystem_T *)
    ACCSystem_M->ModelData.defaultParam);
  B_ACCSystem_T *ACCSystem_B = ((B_ACCSystem_T *) ACCSystem_M->ModelData.blockIO);
  DW_ACCSystem_T *ACCSystem_DW = ((DW_ACCSystem_T *)
    ACCSystem_M->ModelData.dwork);
  PrevZCX_ACCSystem_T *ACCSystem_PrevZCX = ((PrevZCX_ACCSystem_T *)
    ACCSystem_M->ModelData.prevZCSigState);
  real_T rtb_PulseGenerator1;
  ZCEventType zcEvent;
  uint8_T rtb_EnableSwitchSelector;
  uint8_T rtb_PedalFlagSelector;

  /* ManualSwitch: '<S2>/EnableSwitch Selector' incorporates:
   *  Constant: '<S2>/Enable Switch Off'
   *  Constant: '<S2>/Enable Switch On'
   */
  if (ACCSystem_P->EnableSwitchSelector_CurrentSet == 1) {
    rtb_EnableSwitchSelector = ACCSystem_P->EnableSwitchOn_Value;
  } else {
    rtb_EnableSwitchSelector = ACCSystem_P->EnableSwitchOff_Value;
  }

  /* End of ManualSwitch: '<S2>/EnableSwitch Selector' */

  /* ManualSwitch: '<S2>/Pedal Flag Selector' incorporates:
   *  Constant: '<S2>/Pedal Flag Off'
   *  Constant: '<S2>/Pedal Flag On'
   */
  if (ACCSystem_P->PedalFlagSelector_CurrentSettin == 1) {
    rtb_PedalFlagSelector = ACCSystem_P->PedalFlagOn_Value;
  } else {
    rtb_PedalFlagSelector = ACCSystem_P->PedalFlagOff_Value;
  }

  /* End of ManualSwitch: '<S2>/Pedal Flag Selector' */

  /* DiscretePulseGenerator: '<S2>/Pulse Generator1' */
  rtb_PulseGenerator1 = (ACCSystem_DW->clockTickCounter <
    ACCSystem_P->PulseGenerator1_Duty) && (ACCSystem_DW->clockTickCounter >= 0) ?
    ACCSystem_P->PulseGenerator1_Amp : 0.0;
  if (ACCSystem_DW->clockTickCounter >= ACCSystem_P->PulseGenerator1_Period -
      1.0) {
    ACCSystem_DW->clockTickCounter = 0;
  } else {
    ACCSystem_DW->clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<S2>/Pulse Generator1' */

  /* Outputs for Triggered SubSystem: '<S2>/Sample and Hold1' incorporates:
   *  TriggerPort: '<S4>/Trigger'
   */
  zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                     &ACCSystem_PrevZCX->SampleandHold1_Trig_ZCE,
                     (rtb_PulseGenerator1));
  if (zcEvent != NO_ZCEVENT) {
    /* Inport: '<S4>/In' incorporates:
     *  RandomNumber: '<S2>/Random Number'
     */
    ACCSystem_B->In = ACCSystem_DW->NextOutput;
  }

  /* End of Outputs for SubSystem: '<S2>/Sample and Hold1' */

  /* Chart: '<S1>/controller' incorporates:
   *  DataStoreRead: '<S5>/Data Store Read'
   *  ManualSwitch: '<S2>/Reset Switch Selector'
   */
  /* Gateway: ACC_Controller/controller */
  /* During: ACC_Controller/controller */
  if (ACCSystem_DW->is_active_c3_ACCSystem == 0U) {
    /* Entry: ACC_Controller/controller */
    ACCSystem_DW->is_active_c3_ACCSystem = 1U;

    /* Entry Internal: ACC_Controller/controller */
    /* Transition: '<S3>:2' */
    ACCSystem_DW->is_c3_ACCSystem = ACCSystem_IN_OFF_STATE;

    /* Entry 'OFF_STATE': '<S3>:1' */
  } else {
    switch (ACCSystem_DW->is_c3_ACCSystem) {
     case ACCSystem_IN_OFF_STATE:
      /* During 'OFF_STATE': '<S3>:1' */
      if ((rtb_PedalFlagSelector == 0) && (rtb_EnableSwitchSelector == 1)) {
        /* Transition: '<S3>:6' */
        ACCSystem_DW->is_c3_ACCSystem = ACCSystem_IN_ON_STATE;

        /* Entry Internal 'ON_STATE': '<S3>:3' */
        /* Transition: '<S3>:43' */
        ACCSystem_DW->is_ON_STATE = ACCSystem_IN_INIT_ON;

        /* Entry 'INIT_ON': '<S3>:41' */
        ACCSystem_DW->setSpeed = ACCSystem_DW->Speed;
        rtb_PulseGenerator1 = ACCSystem_DW->Speed / 10.0;
        ACCSystem_DW->safety = rtb_PulseGenerator1 * rtb_PulseGenerator1;
      }
      break;

     case ACCSystem_IN_ON_STATE:
      /* During 'ON_STATE': '<S3>:3' */
      if (rtb_EnableSwitchSelector == 0) {
        /* Transition: '<S3>:7' */
        /* Exit Internal 'ON_STATE': '<S3>:3' */
        ACCSystem_DW->is_ON_STATE = ACCSystem_IN_NO_ACTIVE_CHILD;

        /* Exit Internal 'WORKING_STATE': '<S3>:39' */
        ACCSystem_DW->is_WORKING_STATE = ACCSystem_IN_NO_ACTIVE_CHILD;
        ACCSystem_DW->is_c3_ACCSystem = ACCSystem_IN_OFF_STATE;

        /* Entry 'OFF_STATE': '<S3>:1' */
      } else if (rtb_PedalFlagSelector == 1) {
        /* Transition: '<S3>:13' */
        /* Exit Internal 'ON_STATE': '<S3>:3' */
        ACCSystem_DW->is_ON_STATE = ACCSystem_IN_NO_ACTIVE_CHILD;

        /* Exit Internal 'WORKING_STATE': '<S3>:39' */
        ACCSystem_DW->is_WORKING_STATE = ACCSystem_IN_NO_ACTIVE_CHILD;
        ACCSystem_DW->is_c3_ACCSystem = ACCSystem_IN_OVERRIDDEN_STATE;

        /* Entry 'OVERRIDDEN_STATE': '<S3>:11' */
      } else {
        switch (ACCSystem_DW->is_ON_STATE) {
         case ACCSystem_IN_IDLE_STATE:
          /* During 'IDLE_STATE': '<S3>:17' */
          if ((ACCSystem_DW->Speed <= 0.0) || (ACCSystem_B->In ==
               ACCSystem_DW->safety)) {
            /* Transition: '<S3>:33' */
            ACCSystem_DW->is_ON_STATE = ACCSystem_IN_IDLE_STATE;

            /* Entry 'IDLE_STATE': '<S3>:17' */
            ACCSystem_B->go = 0U;
            ACCSystem_B->stop = 0U;
            rtb_PulseGenerator1 = ACCSystem_DW->Speed / 10.0;
            ACCSystem_DW->safety = rtb_PulseGenerator1 * rtb_PulseGenerator1;
          } else if (ACCSystem_B->In < ACCSystem_DW->safety) {
            /* Transition: '<S3>:24' */
            ACCSystem_DW->is_ON_STATE = ACCSystem_IN_WORKING_STATE;
            ACCSystem_DW->is_WORKING_STATE = ACCSystem_IN_STOP_STATE;

            /* Entry 'STOP_STATE': '<S3>:20' */
            ACCSystem_B->go = 0U;
            ACCSystem_B->stop = 1U;
            rtb_PulseGenerator1 = ACCSystem_DW->Speed / 10.0;
            ACCSystem_DW->safety = rtb_PulseGenerator1 * rtb_PulseGenerator1;
          } else if ((ACCSystem_B->In > ACCSystem_DW->safety) &&
                     (ACCSystem_DW->Speed < ACCSystem_DW->setSpeed)) {
            /* Transition: '<S3>:45' */
            ACCSystem_DW->is_ON_STATE = ACCSystem_IN_WORKING_STATE;
            ACCSystem_DW->is_WORKING_STATE = ACCSystem_IN_GO_STATE;

            /* Entry 'GO_STATE': '<S3>:19' */
            ACCSystem_B->go = 1U;
            ACCSystem_B->stop = 0U;
            rtb_PulseGenerator1 = ACCSystem_DW->Speed / 10.0;
            ACCSystem_DW->safety = rtb_PulseGenerator1 * rtb_PulseGenerator1;
          } else {
            rtb_PulseGenerator1 = ACCSystem_DW->Speed / 10.0;
            ACCSystem_DW->safety = rtb_PulseGenerator1 * rtb_PulseGenerator1;
          }
          break;

         case ACCSystem_IN_INIT_ON:
          /* During 'INIT_ON': '<S3>:41' */
          /* Transition: '<S3>:42' */
          ACCSystem_DW->is_ON_STATE = ACCSystem_IN_IDLE_STATE;

          /* Entry 'IDLE_STATE': '<S3>:17' */
          ACCSystem_B->go = 0U;
          ACCSystem_B->stop = 0U;
          rtb_PulseGenerator1 = ACCSystem_DW->Speed / 10.0;
          ACCSystem_DW->safety = rtb_PulseGenerator1 * rtb_PulseGenerator1;
          break;

         default:
          /* During 'WORKING_STATE': '<S3>:39' */
          if ((ACCSystem_DW->Speed <= 0.0) || (ACCSystem_B->In ==
               ACCSystem_DW->safety) || (ACCSystem_B->In < ACCSystem_DW->safety)
              || (ACCSystem_DW->Speed == ACCSystem_DW->setSpeed)) {
            /* Transition: '<S3>:40' */
            /* Exit Internal 'WORKING_STATE': '<S3>:39' */
            ACCSystem_DW->is_WORKING_STATE = ACCSystem_IN_NO_ACTIVE_CHILD;
            ACCSystem_DW->is_ON_STATE = ACCSystem_IN_IDLE_STATE;

            /* Entry 'IDLE_STATE': '<S3>:17' */
            ACCSystem_B->go = 0U;
            ACCSystem_B->stop = 0U;
            rtb_PulseGenerator1 = ACCSystem_DW->Speed / 10.0;
            ACCSystem_DW->safety = rtb_PulseGenerator1 * rtb_PulseGenerator1;
          } else if (ACCSystem_DW->is_WORKING_STATE == ACCSystem_IN_GO_STATE) {
            /* During 'GO_STATE': '<S3>:19' */
            if ((ACCSystem_B->In < ACCSystem_DW->safety) || (ACCSystem_DW->Speed
                 > ACCSystem_DW->setSpeed)) {
              /* Transition: '<S3>:31' */
              ACCSystem_DW->is_WORKING_STATE = ACCSystem_IN_STOP_STATE;

              /* Entry 'STOP_STATE': '<S3>:20' */
              ACCSystem_B->go = 0U;
              ACCSystem_B->stop = 1U;
              rtb_PulseGenerator1 = ACCSystem_DW->Speed / 10.0;
              ACCSystem_DW->safety = rtb_PulseGenerator1 * rtb_PulseGenerator1;
            } else {
              rtb_PulseGenerator1 = ACCSystem_DW->Speed / 10.0;
              ACCSystem_DW->safety = rtb_PulseGenerator1 * rtb_PulseGenerator1;
            }
          } else {
            /* During 'STOP_STATE': '<S3>:20' */
            if ((ACCSystem_B->In > ACCSystem_DW->safety) && (ACCSystem_DW->Speed
                 < ACCSystem_DW->setSpeed)) {
              /* Transition: '<S3>:32' */
              ACCSystem_DW->is_WORKING_STATE = ACCSystem_IN_GO_STATE;

              /* Entry 'GO_STATE': '<S3>:19' */
              ACCSystem_B->go = 1U;
              ACCSystem_B->stop = 0U;
              rtb_PulseGenerator1 = ACCSystem_DW->Speed / 10.0;
              ACCSystem_DW->safety = rtb_PulseGenerator1 * rtb_PulseGenerator1;
            } else {
              rtb_PulseGenerator1 = ACCSystem_DW->Speed / 10.0;
              ACCSystem_DW->safety = rtb_PulseGenerator1 * rtb_PulseGenerator1;
            }
          }
          break;
        }
      }
      break;

     default:
      /* During 'OVERRIDDEN_STATE': '<S3>:11' */
      if (rtb_EnableSwitchSelector == 0) {
        /* Transition: '<S3>:12' */
        ACCSystem_DW->is_c3_ACCSystem = ACCSystem_IN_OFF_STATE;

        /* Entry 'OFF_STATE': '<S3>:1' */
      } else {
        if (ACCSystem_P->ResetSwitchSelector_CurrentSett == 1) {
          /* ManualSwitch: '<S2>/Reset Switch Selector' incorporates:
           *  Constant: '<S2>/Reset Switch On'
           */
          rtb_EnableSwitchSelector = ACCSystem_P->ResetSwitchOn_Value;
        } else {
          /* ManualSwitch: '<S2>/Reset Switch Selector' incorporates:
           *  Constant: '<S2>/Reset Switch Off'
           */
          rtb_EnableSwitchSelector = ACCSystem_P->ResetSwitchOff_Value;
        }

        if (rtb_EnableSwitchSelector == 1) {
          /* Transition: '<S3>:15' */
          ACCSystem_DW->is_c3_ACCSystem = ACCSystem_IN_ON_STATE;

          /* Entry Internal 'ON_STATE': '<S3>:3' */
          /* Transition: '<S3>:43' */
          ACCSystem_DW->is_ON_STATE = ACCSystem_IN_INIT_ON;

          /* Entry 'INIT_ON': '<S3>:41' */
          ACCSystem_DW->setSpeed = ACCSystem_DW->Speed;
          rtb_PulseGenerator1 = ACCSystem_DW->Speed / 10.0;
          ACCSystem_DW->safety = rtb_PulseGenerator1 * rtb_PulseGenerator1;
        }
      }
      break;
    }
  }

  /* End of Chart: '<S1>/controller' */

  /* DataStoreWrite: '<S5>/Data Store Write' incorporates:
   *  DataStoreRead: '<S5>/Data Store Read1'
   *  DataTypeConversion: '<S5>/Data Type Conversion'
   *  DataTypeConversion: '<S5>/Data Type Conversion1'
   *  Gain: '<S5>/Gain1'
   *  Gain: '<S5>/Gain2'
   *  Sum: '<S5>/Sum'
   */
  ACCSystem_DW->Speed += ACCSystem_P->Gain1_Gain * (real_T)ACCSystem_B->go -
    ACCSystem_P->Gain2_Gain * (real_T)ACCSystem_B->stop;

  /* Update for RandomNumber: '<S2>/Random Number' */
  ACCSystem_DW->NextOutput = rt_nrand_Upu32_Yd_f_pw_snf(&ACCSystem_DW->RandSeed)
    * ACCSystem_P->RandomNumber_StdDev + ACCSystem_P->RandomNumber_Mean;
}

/* Model initialize function */
void ACCSystem_initialize(RT_MODEL_ACCSystem_T *const ACCSystem_M)
{
  P_ACCSystem_T *ACCSystem_P = ((P_ACCSystem_T *)
    ACCSystem_M->ModelData.defaultParam);
  B_ACCSystem_T *ACCSystem_B = ((B_ACCSystem_T *) ACCSystem_M->ModelData.blockIO);
  DW_ACCSystem_T *ACCSystem_DW = ((DW_ACCSystem_T *)
    ACCSystem_M->ModelData.dwork);
  PrevZCX_ACCSystem_T *ACCSystem_PrevZCX = ((PrevZCX_ACCSystem_T *)
    ACCSystem_M->ModelData.prevZCSigState);

  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* block I/O */
  (void) memset(((void *) ACCSystem_B), 0,
                sizeof(B_ACCSystem_T));

  /* states (dwork) */
  (void) memset((void *)ACCSystem_DW, 0,
                sizeof(DW_ACCSystem_T));

  {
    uint32_T tseed;
    int32_T r;
    int32_T t;
    real_T tmp;

    /* Start for DiscretePulseGenerator: '<S2>/Pulse Generator1' */
    ACCSystem_DW->clockTickCounter = 0;

    /* Start for Triggered SubSystem: '<S2>/Sample and Hold1' */
    /* VirtualOutportStart for Outport: '<S4>/ ' */
    ACCSystem_B->In = ACCSystem_P->_Y0;

    /* End of Start for SubSystem: '<S2>/Sample and Hold1' */

    /* Start for DataStoreMemory: '<S5>/Data Store Memory' */
    ACCSystem_DW->Speed = ACCSystem_P->DataStoreMemory_InitialValue;
    ACCSystem_PrevZCX->SampleandHold1_Trig_ZCE = UNINITIALIZED_ZCSIG;

    /* InitializeConditions for RandomNumber: '<S2>/Random Number' */
    tmp = floor(ACCSystem_P->RandomNumber_Seed);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp;
    r = (int32_T)(tseed >> 16U);
    t = (int32_T)(tseed & 32768U);
    tseed = ((((tseed - ((uint32_T)r << 16U)) + t) << 16U) + t) + r;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    ACCSystem_DW->RandSeed = tseed;
    ACCSystem_DW->NextOutput = rt_nrand_Upu32_Yd_f_pw_snf
      (&ACCSystem_DW->RandSeed) * ACCSystem_P->RandomNumber_StdDev +
      ACCSystem_P->RandomNumber_Mean;

    /* End of InitializeConditions for RandomNumber: '<S2>/Random Number' */

    /* InitializeConditions for Chart: '<S1>/controller' */
    ACCSystem_DW->is_ON_STATE = ACCSystem_IN_NO_ACTIVE_CHILD;
    ACCSystem_DW->is_WORKING_STATE = ACCSystem_IN_NO_ACTIVE_CHILD;
    ACCSystem_DW->is_active_c3_ACCSystem = 0U;
    ACCSystem_DW->is_c3_ACCSystem = ACCSystem_IN_NO_ACTIVE_CHILD;
  }
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
