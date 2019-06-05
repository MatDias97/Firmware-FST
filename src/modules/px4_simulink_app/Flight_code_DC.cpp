//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Flight_code_DC.cpp
//
// Code generated for Simulink model 'Flight_code_DC'.
//
// Model version                  : 1.227
// Simulink Coder version         : 9.0 (R2018b) 24-May-2018
// C/C++ source code generated on : Tue Jun  4 18:27:06 2019
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "Flight_code_DC.h"
#include "Flight_code_DC_private.h"

// Block signals (default storage)
B_Flight_code_DC_T Flight_code_DC_B;

// Block states (default storage)
DW_Flight_code_DC_T Flight_code_DC_DW;

// Real-time model
RT_MODEL_Flight_code_DC_T Flight_code_DC_M_;
RT_MODEL_Flight_code_DC_T *const Flight_code_DC_M = &Flight_code_DC_M_;

// Forward declaration for local functions
static void Flight_cod_SystemCore_release_i(const
  px4_internal_block_Subscriber_T *obj);
static void Flight_code_SystemCore_delete_i(const
  px4_internal_block_Subscriber_T *obj);
static void matlabCodegenHandle_matlabCod_i(px4_internal_block_Subscriber_T *obj);
static void Flight_code__SystemCore_release(px4_internal_block_PWM_Flight_T *obj);
static void Flight_code_D_SystemCore_delete(px4_internal_block_PWM_Flight_T *obj);
static void matlabCodegenHandle_matlabCodeg(px4_internal_block_PWM_Flight_T *obj);
static void Fl_SystemCore_release_iri5mq4el(const
  px4_internal_block_Publisher__T *obj);
static void Fli_SystemCore_delete_iri5mq4el(const
  px4_internal_block_Publisher__T *obj);
static void matlabCodegenHandle_m_iri5mq4el(px4_internal_block_Publisher__T *obj);
static void Flight_code_DC_SystemCore_setup(px4_internal_block_PWM_Flight_T *obj,
  boolean_T varargin_1, boolean_T varargin_2);
static void rate_scheduler(void);
real_T look1_binlxpw(real_T u0, const real_T bp0[], const real_T table[],
                     uint32_T maxIndex)
{
  real_T frac;
  uint32_T iRght;
  uint32_T iLeft;
  uint32_T bpIdx;

  // Column-major Lookup 1-D
  // Search method: 'binary'
  // Use previous index: 'off'
  // Interpolation method: 'Linear point-slope'
  // Extrapolation method: 'Linear'
  // Use last breakpoint for index at or above upper limit: 'off'
  // Remove protection against out-of-range input in generated code: 'off'

  // Prelookup - Index and Fraction
  // Index Search method: 'binary'
  // Extrapolation method: 'Linear'
  // Use previous index: 'off'
  // Use last breakpoint for index at or above upper limit: 'off'
  // Remove protection against out-of-range input in generated code: 'off'

  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = (u0 - bp0[0U]) / (bp0[1U] - bp0[0U]);
  } else if (u0 < bp0[maxIndex]) {
    // Binary Search
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex - 1U;
    frac = (u0 - bp0[maxIndex - 1U]) / (bp0[maxIndex] - bp0[maxIndex - 1U]);
  }

  // Column-major Interpolation 1-D
  // Interpolation method: 'Linear point-slope'
  // Use last breakpoint for index at or above upper limit: 'off'
  // Overflow mode: 'portable wrapping'

  return (table[iLeft + 1U] - table[iLeft]) * frac + table[iLeft];
}

//
//   This function updates active task flag for each subrate.
// The function is called at model base rate, hence the
// generated code self-manages all its subrates.
//
static void rate_scheduler(void)
{
  // Compute which subrates run during the next base time step.  Subrates
  //  are an integer multiple of the base rate counter.  Therefore, the subtask
  //  counter is reset when it reaches its limit (zero means run).

  (Flight_code_DC_M->Timing.TaskCounters.TID[1])++;
  if ((Flight_code_DC_M->Timing.TaskCounters.TID[1]) > 4) {// Sample time: [0.05s, 0.0s] 
    Flight_code_DC_M->Timing.TaskCounters.TID[1] = 0;
  }
}

//
// Output and update for atomic system:
//    '<S24>/MATLAB Function'
//    '<S25>/MATLAB Function'
//
void Flight_code_DC_MATLABFunction(real_T rtu_Throttle, real_T rtu_Delta, real_T
  *rty_Throttle_out, real_T *rty_Dif_L, real_T *rty_Dif_R)
{
  real_T Dif_L;
  real_T Delta2;
  real_T excess;
  Delta2 = rtu_Delta / 2.0;
  Dif_L = rtu_Throttle + Delta2;
  Delta2 = rtu_Throttle - Delta2;
  if (Dif_L < 0.0) {
    excess = Dif_L;
    Dif_L = 0.0;
    Delta2 -= excess;
  }

  if (Delta2 < 0.0) {
    excess = Delta2;
    Delta2 = 0.0;
    Dif_L -= excess;
  }

  if (Dif_L > 1.0) {
    excess = Dif_L;
    Dif_L = 1.0;
    Delta2 -= excess;
  }

  if (Delta2 > 1.0) {
    excess = Delta2;
    Delta2 = 1.0;
    Dif_L -= excess;
  }

  excess = 2.0 * rtu_Throttle - (Dif_L + Delta2) / 2.0;
  if (Dif_L < 0.0) {
    Dif_L = 0.0;
  }

  if (Delta2 < 0.0) {
    Delta2 = 0.0;
  }

  if (excess < 0.0) {
    excess = 0.0;
  }

  if (excess > 1.0) {
    excess = 1.0;
  }

  *rty_Throttle_out = excess;
  *rty_Dif_L = Dif_L;
  *rty_Dif_R = Delta2;
}

real32_T rt_atan2f_snf(real32_T u0, real32_T u1)
{
  real32_T y;
  int32_T u0_0;
  int32_T u1_0;
  if (rtIsNaNF(u0) || rtIsNaNF(u1)) {
    y = (rtNaNF);
  } else if (rtIsInfF(u0) && rtIsInfF(u1)) {
    if (u0 > 0.0F) {
      u0_0 = 1;
    } else {
      u0_0 = -1;
    }

    if (u1 > 0.0F) {
      u1_0 = 1;
    } else {
      u1_0 = -1;
    }

    y = (real32_T)atan2((real_T)(real32_T)u0_0, (real_T)(real32_T)u1_0);
  } else if (u1 == 0.0F) {
    if (u0 > 0.0F) {
      y = RT_PIF / 2.0F;
    } else if (u0 < 0.0F) {
      y = -(RT_PIF / 2.0F);
    } else {
      y = 0.0F;
    }
  } else {
    y = (real32_T)atan2((real_T)u0, (real_T)u1);
  }

  return y;
}

static void Flight_cod_SystemCore_release_i(const
  px4_internal_block_Subscriber_T *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    uORB_read_terminate(&obj->eventStructObj);
  }
}

static void Flight_code_SystemCore_delete_i(const
  px4_internal_block_Subscriber_T *obj)
{
  Flight_cod_SystemCore_release_i(obj);
}

static void matlabCodegenHandle_matlabCod_i(px4_internal_block_Subscriber_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    Flight_code_SystemCore_delete_i(obj);
  }
}

static void Flight_code__SystemCore_release(px4_internal_block_PWM_Flight_T *obj)
{
  uint16_T status;
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    status = pwm_disarm(&obj->pwmDevHandler);
    obj->errorStatus |= status;
    status = pwm_resetServo(&obj->pwmDevHandler, obj->servoCount,
      obj->channelMask, obj->isMain);
    obj->errorStatus |= status;
    status = pwm_close(&obj->pwmDevHandler);
    obj->errorStatus |= status;
  }
}

static void Flight_code_D_SystemCore_delete(px4_internal_block_PWM_Flight_T *obj)
{
  Flight_code__SystemCore_release(obj);
}

static void matlabCodegenHandle_matlabCodeg(px4_internal_block_PWM_Flight_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    Flight_code_D_SystemCore_delete(obj);
  }
}

static void Fl_SystemCore_release_iri5mq4el(const
  px4_internal_block_Publisher__T *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    uORB_write_terminate(&obj->orbAdvertiseObj);
  }
}

static void Fli_SystemCore_delete_iri5mq4el(const
  px4_internal_block_Publisher__T *obj)
{
  Fl_SystemCore_release_iri5mq4el(obj);
}

static void matlabCodegenHandle_m_iri5mq4el(px4_internal_block_Publisher__T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    Fli_SystemCore_delete_iri5mq4el(obj);
  }
}

static void Flight_code_DC_SystemCore_setup(px4_internal_block_PWM_Flight_T *obj,
  boolean_T varargin_1, boolean_T varargin_2)
{
  uint16_T status;
  uint16_T varargin_1_0;
  obj->isSetupComplete = false;
  obj->isInitialized = 1;
  obj->isMain = true;
  obj->pwmDevObj = MW_PWM_OUTPUT_MAIN_DEVICE_PATH;
  status = pwm_open(&obj->pwmDevHandler, obj->pwmDevObj);
  varargin_1_0 = obj->errorStatus;
  obj->errorStatus = (uint16_T)(varargin_1_0 | status);
  obj->servoCount = 0;
  status = pwm_getServoCount(&obj->pwmDevHandler, &obj->servoCount);
  varargin_1_0 = obj->errorStatus;
  obj->errorStatus = (uint16_T)(varargin_1_0 | status);
  if (varargin_1) {
    status = pwm_arm(&obj->pwmDevHandler);
  } else {
    status = pwm_disarm(&obj->pwmDevHandler);
  }

  varargin_1_0 = obj->errorStatus;
  obj->errorStatus = (uint16_T)(varargin_1_0 | status);
  status = pwm_setPWMRate(&obj->pwmDevHandler, obj->isMain);
  varargin_1_0 = obj->errorStatus;
  obj->errorStatus = (uint16_T)(varargin_1_0 | status);
  obj->channelMask = 255;
  status = pwm_setChannelMask(&obj->pwmDevHandler, obj->channelMask);
  varargin_1_0 = obj->errorStatus;
  obj->errorStatus = (uint16_T)(varargin_1_0 | status);
  status = pwm_setFailsafePWM(&obj->pwmDevHandler, obj->servoCount,
    obj->channelMask, obj->isMain);
  varargin_1_0 = obj->errorStatus;
  obj->errorStatus = (uint16_T)(varargin_1_0 | status);
  status = pwm_setDisarmedPWM(&obj->pwmDevHandler, obj->servoCount,
    obj->channelMask, obj->isMain);
  varargin_1_0 = obj->errorStatus;
  obj->errorStatus = (uint16_T)(varargin_1_0 | status);
  if (obj->isMain) {
    status = pwm_forceFailsafe(&obj->pwmDevHandler, varargin_2);
    varargin_1_0 = obj->errorStatus;
    obj->errorStatus = (uint16_T)(varargin_1_0 | status);
    status = pwm_forceTerminateFailsafe(&obj->pwmDevHandler, false);
    varargin_1_0 = obj->errorStatus;
    obj->errorStatus = (uint16_T)(varargin_1_0 | status);
  }

  obj->isSetupComplete = true;
}

// Model step function
void Flight_code_DC_step(void)
{
  static const char_T b[18] = { 'A', 'i', 'r', 's', 'p', 'e', 'e', 'd', ':', ' ',
    '%', '8', '.', '4', 'f', ' ', '\x0a', '\x00' };

  static const char_T c[25] = { 'S', 'i', 'd', 'e', 's', 'l', 'i', 'p', ' ', 'C',
    'o', 'n', 'r', 'a', 'd', ':', ' ', '%', '8', '.', '4', 'f', ' ', '\x0a',
    '\x00' };

  static const char_T d[28] = { 'S', 'i', 'd', 'e', 's', 'l', 'i', 'p', ' ', 's',
    'i', 'n', 't', 'h', 'e', 't', 'i', 'c', ':', ' ', '%', '8', '.', '4', 'f',
    ' ', '\x0a', '\x00' };

  uint16_T status;
  uint16_T rtb_DataTypeConversion5;
  uint16_T rtb_DataTypeConversion3;
  real32_T rtb_Gain4_f;
  int32_T rtb_Mode;
  boolean_T rtb_Mode_change_e;
  boolean_T rtb_Mode_change;
  boolean_T rtb_Switch1;
  int32_T i;
  boolean_T tmp;
  boolean_T tmp_0;
  boolean_T tmp_1;
  boolean_T tmp_2;
  boolean_T tmp_3;
  boolean_T tmp_4;
  boolean_T tmp_5;

  // MATLABSystem: '<S69>/SourceBlock' incorporates:
  //   Inport: '<S70>/In1'

  rtb_Switch1 = uORB_read_step(Flight_code_DC_DW.obj_d.orbMetadataObj,
    &Flight_code_DC_DW.obj_d.eventStructObj, &Flight_code_DC_B.b_varargout_2_cx,
    false, 5000.0);

  // Outputs for Enabled SubSystem: '<S69>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S70>/Enable'

  if (rtb_Switch1) {
    Flight_code_DC_B.In1_c = Flight_code_DC_B.b_varargout_2_cx;
  }

  // End of MATLABSystem: '<S69>/SourceBlock'
  // End of Outputs for SubSystem: '<S69>/Enabled Subsystem'

  // MATLAB Function: '<S9>/MATLAB Function' incorporates:
  //   DataTypeConversion: '<S23>/Data Type Conversion'
  //   DataTypeConversion: '<S23>/Data Type Conversion1'
  //   DataTypeConversion: '<S9>/Data Type Conversion4'
  //   DataTypeConversion: '<S9>/Data Type Conversion5'
  //   Gain: '<S23>/Gain'
  //   Gain: '<S23>/Gain1'
  //   S-Function (sfix_bitop): '<S23>/Bitwise Operator'

  if (((int32_T)(((uint32_T)Flight_code_DC_P.Gain_Gain_m *
                  Flight_code_DC_B.In1_c.rc_failsafe) >> 6) | (int32_T)
       (((uint32_T)Flight_code_DC_P.Gain1_Gain * Flight_code_DC_B.In1_c.rc_lost)
        >> 5)) != 0) {
    rtb_Mode = 1;
  } else if (Flight_code_DC_B.In1_c.values[4] < 1600) {
    rtb_Mode = 3;
  } else {
    rtb_Mode = 4;
  }

  // End of MATLAB Function: '<S9>/MATLAB Function'

  // Fcn: '<S9>/Fcn1' incorporates:
  //   DataTypeConversion: '<S9>/Data Type Conversion1'

  Flight_code_DC_B.Dif_R_p = ((real_T)Flight_code_DC_B.In1_c.values[3] - 1000.0)
    / 1000.0;

  // Saturate: '<S9>/Saturation1'
  if (Flight_code_DC_B.Dif_R_p > Flight_code_DC_P.Saturation1_UpperSat) {
    Flight_code_DC_B.Dif_R_p = Flight_code_DC_P.Saturation1_UpperSat;
  } else {
    if (Flight_code_DC_B.Dif_R_p < Flight_code_DC_P.Saturation1_LowerSat) {
      Flight_code_DC_B.Dif_R_p = Flight_code_DC_P.Saturation1_LowerSat;
    }
  }

  // End of Saturate: '<S9>/Saturation1'

  // Gain: '<S9>/Gain'
  Flight_code_DC_B.Gain = Flight_code_DC_P.Gain_Gain * Flight_code_DC_B.Dif_R_p;

  // MATLABSystem: '<S163>/SourceBlock' incorporates:
  //   Inport: '<S164>/In1'

  rtb_Switch1 = uORB_read_step(Flight_code_DC_DW.obj.orbMetadataObj,
    &Flight_code_DC_DW.obj.eventStructObj, &Flight_code_DC_B.b_varargout_2_g,
    false, 1.0);

  // Outputs for Enabled SubSystem: '<S163>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S164>/Enable'

  if (rtb_Switch1) {
    Flight_code_DC_B.In1_h = Flight_code_DC_B.b_varargout_2_g;
  }

  // End of MATLABSystem: '<S163>/SourceBlock'
  // End of Outputs for SubSystem: '<S163>/Enabled Subsystem'

  // MATLABSystem: '<S34>/SourceBlock' incorporates:
  //   Inport: '<S37>/In1'

  rtb_Switch1 = uORB_read_step(Flight_code_DC_DW.obj_n.orbMetadataObj,
    &Flight_code_DC_DW.obj_n.eventStructObj, &Flight_code_DC_B.b_varargout_2_f,
    false, 1.0);

  // Outputs for Enabled SubSystem: '<S34>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S37>/Enable'

  if (rtb_Switch1) {
    Flight_code_DC_B.In1_m = Flight_code_DC_B.b_varargout_2_f;
  }

  // End of MATLABSystem: '<S34>/SourceBlock'
  // End of Outputs for SubSystem: '<S34>/Enabled Subsystem'

  // Gain: '<S32>/Gain' incorporates:
  //   Math: '<S32>/Math Function'
  //   Product: '<S32>/Product'
  //
  //  About '<S32>/Math Function':
  //   Operator: magnitude^2

  rtb_Gain4_f = Flight_code_DC_B.In1_m.indicated_airspeed_m_s *
    Flight_code_DC_B.In1_m.indicated_airspeed_m_s * Flight_code_DC_B.In1_h.rho *
    Flight_code_DC_P.Gain_Gain_h5;

  // Fcn: '<S9>/Fcn3' incorporates:
  //   DataTypeConversion: '<S9>/Data Type Conversion2'

  Flight_code_DC_B.Dif_R_p = ((real_T)Flight_code_DC_B.In1_c.values[0] - 1500.0)
    / 500.0;

  // Saturate: '<S9>/Saturation2'
  if (Flight_code_DC_B.Dif_R_p > Flight_code_DC_P.Saturation2_UpperSat) {
    Flight_code_DC_B.Dif_R_p = Flight_code_DC_P.Saturation2_UpperSat;
  } else {
    if (Flight_code_DC_B.Dif_R_p < Flight_code_DC_P.Saturation2_LowerSat) {
      Flight_code_DC_B.Dif_R_p = Flight_code_DC_P.Saturation2_LowerSat;
    }
  }

  // End of Saturate: '<S9>/Saturation2'

  // Gain: '<S9>/Gain2'
  Flight_code_DC_B.Gain2 = Flight_code_DC_P.RUDDER_LIMITS *
    Flight_code_DC_B.Dif_R_p;

  // MATLAB Function: '<S47>/MATLAB Function' incorporates:
  //   Constant: '<S46>/Constant'
  //   Gain: '<S46>/Gain'
  //   Product: '<S46>/Product'
  //   Sum: '<S46>/Sum'

  Flight_code_DC_B.Delta2 = (Flight_code_DC_P.Gain_Gain_p * rtb_Gain4_f -
    Flight_code_DC_P.K_RUDDER_AILERON) * Flight_code_DC_B.Gain2 / 2.0;
  Flight_code_DC_B.Gain1 = Flight_code_DC_B.Gain + Flight_code_DC_B.Delta2;
  if (Flight_code_DC_B.Gain1 > 1.0) {
    // SignalConversion: '<S11>/TmpSignal ConversionAt SFunction Inport2' incorporates:
    //   MATLAB Function: '<Root>/MATLAB_Function'

    Flight_code_DC_B.TmpSignalConversionAtSFunct[2] = 1.0;
    Flight_code_DC_B.TmpSignalConversionAtSFunct[1] = (Flight_code_DC_B.Gain -
      Flight_code_DC_B.Delta2) - (Flight_code_DC_B.Gain1 - 1.0);
    Flight_code_DC_B.TmpSignalConversionAtSFunct[0] = (Flight_code_DC_B.Gain1 -
      1.0) / 2.0 + Flight_code_DC_B.Gain;
  } else {
    Flight_code_DC_B.Dif_R_p = Flight_code_DC_B.Gain - Flight_code_DC_B.Delta2;
    if (Flight_code_DC_B.Dif_R_p > 1.0) {
      // SignalConversion: '<S11>/TmpSignal ConversionAt SFunction Inport2' incorporates:
      //   MATLAB Function: '<Root>/MATLAB_Function'

      Flight_code_DC_B.TmpSignalConversionAtSFunct[1] = 1.0;
      Flight_code_DC_B.TmpSignalConversionAtSFunct[2] = Flight_code_DC_B.Gain1 -
        (Flight_code_DC_B.Dif_R_p - 1.0);
      Flight_code_DC_B.TmpSignalConversionAtSFunct[0] =
        (Flight_code_DC_B.Dif_R_p - 1.0) / 2.0 + Flight_code_DC_B.Gain;
    } else if (Flight_code_DC_B.Dif_R_p < 0.0) {
      Flight_code_DC_B.Excess = Flight_code_DC_B.Delta2 - Flight_code_DC_B.Gain;

      // SignalConversion: '<S11>/TmpSignal ConversionAt SFunction Inport2' incorporates:
      //   MATLAB Function: '<Root>/MATLAB_Function'

      Flight_code_DC_B.TmpSignalConversionAtSFunct[1] = 0.0;
      Flight_code_DC_B.TmpSignalConversionAtSFunct[2] = Flight_code_DC_B.Gain1 +
        Flight_code_DC_B.Excess;
      Flight_code_DC_B.TmpSignalConversionAtSFunct[0] = Flight_code_DC_B.Gain -
        Flight_code_DC_B.Excess / 2.0;
    } else if (Flight_code_DC_B.Gain1 < 0.0) {
      // SignalConversion: '<S11>/TmpSignal ConversionAt SFunction Inport2' incorporates:
      //   MATLAB Function: '<Root>/MATLAB_Function'

      Flight_code_DC_B.TmpSignalConversionAtSFunct[2] = 0.0;
      Flight_code_DC_B.TmpSignalConversionAtSFunct[1] = Flight_code_DC_B.Dif_R_p
        + -Flight_code_DC_B.Gain1;
      Flight_code_DC_B.TmpSignalConversionAtSFunct[0] = Flight_code_DC_B.Gain -
        -Flight_code_DC_B.Gain1 / 2.0;
    } else {
      // SignalConversion: '<S11>/TmpSignal ConversionAt SFunction Inport2' incorporates:
      //   MATLAB Function: '<Root>/MATLAB_Function'

      Flight_code_DC_B.TmpSignalConversionAtSFunct[1] = Flight_code_DC_B.Dif_R_p;
      Flight_code_DC_B.TmpSignalConversionAtSFunct[2] = Flight_code_DC_B.Gain1;
      Flight_code_DC_B.TmpSignalConversionAtSFunct[0] = Flight_code_DC_B.Gain;
    }
  }

  // End of MATLAB Function: '<S47>/MATLAB Function'

  // Fcn: '<S9>/Fcn2' incorporates:
  //   DataTypeConversion: '<S9>/Data Type Conversion'

  Flight_code_DC_B.Dif_R_p = ((real_T)Flight_code_DC_B.In1_c.values[2] - 1500.0)
    / 500.0;

  // Saturate: '<S9>/Saturation9'
  if (Flight_code_DC_B.Dif_R_p > Flight_code_DC_P.Saturation9_UpperSat) {
    Flight_code_DC_B.Dif_R_p = Flight_code_DC_P.Saturation9_UpperSat;
  } else {
    if (Flight_code_DC_B.Dif_R_p < Flight_code_DC_P.Saturation9_LowerSat) {
      Flight_code_DC_B.Dif_R_p = Flight_code_DC_P.Saturation9_LowerSat;
    }
  }

  // End of Saturate: '<S9>/Saturation9'

  // Gain: '<S9>/Gain1'
  Flight_code_DC_B.Gain1 = Flight_code_DC_P.AILERON_LIMITS *
    Flight_code_DC_B.Dif_R_p;

  // Fcn: '<S9>/Fcn4' incorporates:
  //   DataTypeConversion: '<S9>/Data Type Conversion3'

  Flight_code_DC_B.Dif_R_p = ((real_T)Flight_code_DC_B.In1_c.values[1] - 1500.0)
    / 500.0;

  // Saturate: '<S9>/Saturation3'
  if (Flight_code_DC_B.Dif_R_p > Flight_code_DC_P.Saturation3_UpperSat) {
    Flight_code_DC_B.Dif_R_p = Flight_code_DC_P.Saturation3_UpperSat;
  } else {
    if (Flight_code_DC_B.Dif_R_p < Flight_code_DC_P.Saturation3_LowerSat) {
      Flight_code_DC_B.Dif_R_p = Flight_code_DC_P.Saturation3_LowerSat;
    }
  }

  // End of Saturate: '<S9>/Saturation3'

  // Gain: '<S9>/Gain4'
  Flight_code_DC_B.Delta2 = Flight_code_DC_P.ELEVATOR_LIMITS *
    Flight_code_DC_B.Dif_R_p;

  // Lookup_n-D: '<S71>/K32' incorporates:
  //   DataTypeConversion: '<S24>/Data Type Conversion5'

  Flight_code_DC_B.DataTypeConversion = look1_binlxpw((real_T)
    Flight_code_DC_B.In1_m.indicated_airspeed_m_s, Flight_code_DC_P.V_K_SAS,
    Flight_code_DC_P.K32, 18U);

  // Concatenate: '<S71>/Matrix Concatenate' incorporates:
  //   Constant: '<S71>/Constant1'
  //   Constant: '<S71>/Constant16'
  //   Constant: '<S71>/Constant2'
  //   Constant: '<S71>/Constant3'
  //   Constant: '<S71>/Constant4'
  //   Constant: '<S71>/Constant5'
  //   Constant: '<S71>/Constant6'
  //   Constant: '<S71>/Constant7'
  //   Constant: '<S71>/Constant8'
  //   Constant: '<S71>/Constant9'
  //   DataTypeConversion: '<S24>/Data Type Conversion5'
  //   Lookup_n-D: '<S71>/K11'
  //   Lookup_n-D: '<S71>/K12'
  //   Lookup_n-D: '<S71>/K13'
  //   Lookup_n-D: '<S71>/K31'
  //   Lookup_n-D: '<S71>/K33'

  Flight_code_DC_B.MatrixConcatenate[0] = look1_binlxpw((real_T)
    Flight_code_DC_B.In1_m.indicated_airspeed_m_s, Flight_code_DC_P.V_K_SAS,
    Flight_code_DC_P.K11, 18U);
  Flight_code_DC_B.MatrixConcatenate[4] = look1_binlxpw((real_T)
    Flight_code_DC_B.In1_m.indicated_airspeed_m_s, Flight_code_DC_P.V_K_SAS,
    Flight_code_DC_P.K12, 18U);
  Flight_code_DC_B.MatrixConcatenate[8] = look1_binlxpw((real_T)
    Flight_code_DC_B.In1_m.indicated_airspeed_m_s, Flight_code_DC_P.V_K_SAS,
    Flight_code_DC_P.K13, 18U);
  Flight_code_DC_B.MatrixConcatenate[12] = Flight_code_DC_P.Constant7_Value;
  Flight_code_DC_B.MatrixConcatenate[1] = Flight_code_DC_P.Constant1_Value;
  Flight_code_DC_B.MatrixConcatenate[5] = Flight_code_DC_P.Constant2_Value;
  Flight_code_DC_B.MatrixConcatenate[9] = Flight_code_DC_P.Constant3_Value;
  Flight_code_DC_B.MatrixConcatenate[13] = Flight_code_DC_P.Constant4_Value;
  Flight_code_DC_B.MatrixConcatenate[2] = look1_binlxpw((real_T)
    Flight_code_DC_B.In1_m.indicated_airspeed_m_s, Flight_code_DC_P.V_K_SAS,
    Flight_code_DC_P.K31, 18U);
  Flight_code_DC_B.MatrixConcatenate[6] = Flight_code_DC_B.DataTypeConversion;
  Flight_code_DC_B.MatrixConcatenate[10] = look1_binlxpw((real_T)
    Flight_code_DC_B.In1_m.indicated_airspeed_m_s, Flight_code_DC_P.V_K_SAS,
    Flight_code_DC_P.K33, 18U);
  Flight_code_DC_B.MatrixConcatenate[14] = Flight_code_DC_P.Constant5_Value;
  Flight_code_DC_B.MatrixConcatenate[3] = Flight_code_DC_P.Constant6_Value;
  Flight_code_DC_B.MatrixConcatenate[7] = Flight_code_DC_P.Constant8_Value;
  Flight_code_DC_B.MatrixConcatenate[11] = Flight_code_DC_P.Constant9_Value;
  Flight_code_DC_B.MatrixConcatenate[15] = Flight_code_DC_P.Constant16_Value;

  // MATLABSystem: '<S35>/SourceBlock' incorporates:
  //   Inport: '<S38>/In1'

  rtb_Switch1 = uORB_read_step(Flight_code_DC_DW.obj_k.orbMetadataObj,
    &Flight_code_DC_DW.obj_k.eventStructObj, &Flight_code_DC_B.b_varargout_2_p,
    false, 1.0);

  // Outputs for Enabled SubSystem: '<S35>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S38>/Enable'

  if (rtb_Switch1) {
    Flight_code_DC_B.In1_o = Flight_code_DC_B.b_varargout_2_p;
  }

  // End of MATLABSystem: '<S35>/SourceBlock'
  // End of Outputs for SubSystem: '<S35>/Enabled Subsystem'

  // Product: '<S32>/Divide'
  rtb_Gain4_f = 1.0F / rtb_Gain4_f *
    Flight_code_DC_B.In1_o.differential_pressure_raw_pa;

  // DataTypeConversion: '<S2>/Data Type Conversion' incorporates:
  //   Bias: '<S32>/Bias'
  //   Gain: '<S32>/Gain1'

  Flight_code_DC_B.DataTypeConversion = (rtb_Gain4_f +
    Flight_code_DC_P.BIAS_CONRAD) * Flight_code_DC_P.SCALE_CONRAD;

  // MATLABSystem: '<S43>/SourceBlock' incorporates:
  //   Inport: '<S44>/In1'

  rtb_Switch1 = uORB_read_step(Flight_code_DC_DW.obj_i.orbMetadataObj,
    &Flight_code_DC_DW.obj_i.eventStructObj, &Flight_code_DC_B.b_varargout_2_b,
    false, 1.0);

  // Outputs for Enabled SubSystem: '<S43>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S44>/Enable'

  if (rtb_Switch1) {
    Flight_code_DC_B.In1_l = Flight_code_DC_B.b_varargout_2_b;
  }

  // End of MATLABSystem: '<S43>/SourceBlock'
  // End of Outputs for SubSystem: '<S43>/Enabled Subsystem'

  // MATLAB Function: '<S40>/Quat2eul'
  rtb_Gain4_f = rt_atan2f_snf((Flight_code_DC_B.In1_l.q[0] *
    Flight_code_DC_B.In1_l.q[1] + Flight_code_DC_B.In1_l.q[2] *
    Flight_code_DC_B.In1_l.q[3]) * 2.0F, 1.0F - (Flight_code_DC_B.In1_l.q[0] *
    Flight_code_DC_B.In1_l.q[0] + Flight_code_DC_B.In1_l.q[1] *
    Flight_code_DC_B.In1_l.q[1]) * 2.0F);

  // SignalConversion: '<S24>/TmpSignal ConversionAtProduct1Inport2' incorporates:
  //   Product: '<S24>/Product'

  Flight_code_DC_B.Dif_R_p = Flight_code_DC_B.In1_m.indicated_airspeed_m_s *
    Flight_code_DC_B.DataTypeConversion;

  // Product: '<S24>/Product1' incorporates:
  //   DataTypeConversion: '<S24>/Data Type Conversion'
  //   DataTypeConversion: '<S24>/Data Type Conversion1'
  //   DataTypeConversion: '<S24>/Data Type Conversion2'

  for (i = 0; i < 4; i++) {
    Flight_code_DC_B.Throttle_out = Flight_code_DC_B.MatrixConcatenate[i + 12] *
      rtb_Gain4_f + (Flight_code_DC_B.MatrixConcatenate[i + 8] *
                     Flight_code_DC_B.In1_l.yawspeed +
                     (Flight_code_DC_B.MatrixConcatenate[i + 4] *
                      Flight_code_DC_B.In1_l.rollspeed +
                      Flight_code_DC_B.MatrixConcatenate[i] *
                      Flight_code_DC_B.Dif_R_p));
    Flight_code_DC_B.Product1[i] = Flight_code_DC_B.Throttle_out;
  }

  // End of Product: '<S24>/Product1'

  // MATLAB Function: '<S24>/MATLAB Function' incorporates:
  //   Constant: '<S73>/Constant'
  //   Gain: '<S73>/Gain'
  //   Math: '<S73>/Math Function'
  //   Product: '<S73>/Product'
  //   Sum: '<S24>/Sum7'
  //   Sum: '<S73>/Sum'
  //
  //  About '<S73>/Math Function':
  //   Operator: magnitude^2

  Flight_code_DC_MATLABFunction(Flight_code_DC_B.Gain,
    Flight_code_DC_B.Product1[2] + (Flight_code_DC_P.Gain_Gain_f *
    (Flight_code_DC_B.In1_m.indicated_airspeed_m_s *
     Flight_code_DC_B.In1_m.indicated_airspeed_m_s) -
    Flight_code_DC_P.K_RUDDER_AILERON) * Flight_code_DC_B.Gain2,
    &Flight_code_DC_B.Throttle_out, &Flight_code_DC_B.Dif_L,
    &Flight_code_DC_B.Dif_R);

  // MATLABSystem: '<S50>/SourceBlock' incorporates:
  //   Inport: '<S53>/In1'

  rtb_Switch1 = uORB_read_step(Flight_code_DC_DW.obj_o.orbMetadataObj,
    &Flight_code_DC_DW.obj_o.eventStructObj, &Flight_code_DC_B.b_varargout_2_m,
    false, 1.0);

  // Outputs for Enabled SubSystem: '<S50>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S53>/Enable'

  if (rtb_Switch1) {
    Flight_code_DC_B.In1_k = Flight_code_DC_B.b_varargout_2_m;
  }

  // End of MATLABSystem: '<S50>/SourceBlock'
  // End of Outputs for SubSystem: '<S50>/Enabled Subsystem'

  // SignalConversion: '<S80>/TmpSignal ConversionAtDot Product2Inport1' incorporates:
  //   MATLAB Function: '<S40>/Quat2eul'
  //   SignalConversion: '<S123>/TmpSignal ConversionAtDot Product2Inport1'

  Flight_code_DC_B.Product1[3] = (real32_T)asin((real_T)
    ((Flight_code_DC_B.In1_l.q[0] * Flight_code_DC_B.In1_l.q[2] +
      Flight_code_DC_B.In1_l.q[3] * Flight_code_DC_B.In1_l.q[1]) * 2.0F));

  // Sum: '<S79>/Sum' incorporates:
  //   Memory: '<S79>/Memory'

  Flight_code_DC_B.Sum_l = (real_T)rtb_Mode -
    Flight_code_DC_DW.Memory_PreviousInput;

  // DataTypeConversion: '<S79>/Data Type Conversion'
  rtb_Mode_change = (Flight_code_DC_B.Sum_l != 0.0);

  // DiscreteIntegrator: '<S93>/Discrete-Time Integrator' incorporates:
  //   Constant: '<S80>/Constant'
  //   DataTypeConversion: '<S79>/Data Type Conversion'
  //   Sum: '<S79>/Sum'

  if (((Flight_code_DC_B.Sum_l != 0.0) &&
       (Flight_code_DC_DW.DiscreteTimeIntegrator_PrevRese <= 0)) ||
      ((!(Flight_code_DC_B.Sum_l != 0.0)) &&
       (Flight_code_DC_DW.DiscreteTimeIntegrator_PrevRese == 1))) {
    Flight_code_DC_DW.DiscreteTimeIntegrator_DSTATE =
      Flight_code_DC_P.Constant_Value_g;
  }

  // DiscreteIntegrator: '<S94>/Discrete-Time Integrator' incorporates:
  //   Constant: '<S80>/Constant1'

  if ((rtb_Mode_change && (Flight_code_DC_DW.DiscreteTimeIntegrator_PrevRe_p <=
        0)) || ((!rtb_Mode_change) &&
                (Flight_code_DC_DW.DiscreteTimeIntegrator_PrevRe_p == 1))) {
    Flight_code_DC_DW.DiscreteTimeIntegrator_DSTATE_a =
      Flight_code_DC_P.Constant1_Value_h;
  }

  // Sum: '<S80>/Sum' incorporates:
  //   DataTypeConversion: '<S80>/boolean2double1'
  //   DataTypeConversion: '<S80>/boolean2double2'
  //   DataTypeConversion: '<S80>/boolean2double3'
  //   DataTypeConversion: '<S80>/boolean2double5'
  //   DiscreteIntegrator: '<S93>/Discrete-Time Integrator'
  //   DiscreteIntegrator: '<S94>/Discrete-Time Integrator'
  //   DotProduct: '<S80>/Dot Product'
  //   DotProduct: '<S80>/Dot Product1'
  //   DotProduct: '<S80>/Dot Product2'
  //   DotProduct: '<S80>/Dot Product3'
  //   Lookup_n-D: '<S80>/F11'
  //   Lookup_n-D: '<S80>/F12'
  //   Lookup_n-D: '<S80>/F13'
  //   Lookup_n-D: '<S80>/F14'
  //   Lookup_n-D: '<S80>/F21'
  //   Lookup_n-D: '<S80>/F22'
  //   Lookup_n-D: '<S80>/F23'
  //   Lookup_n-D: '<S80>/F24'
  //   Lookup_n-D: '<S80>/FI11'
  //   Lookup_n-D: '<S80>/FI12'
  //   Lookup_n-D: '<S80>/FI21'
  //   Lookup_n-D: '<S80>/FI22'
  //   SignalConversion: '<S80>/TmpSignal ConversionAtDot Product2Inport1'

  Flight_code_DC_B.Throttle_out = (((Flight_code_DC_B.In1_k.vx * look1_binlxpw
    ((real_T)Flight_code_DC_B.In1_m.indicated_airspeed_m_s, Flight_code_DC_P.V0,
     Flight_code_DC_P.F11, 29U) + Flight_code_DC_B.In1_k.vz * look1_binlxpw
    ((real_T)Flight_code_DC_B.In1_m.indicated_airspeed_m_s, Flight_code_DC_P.V0,
     Flight_code_DC_P.F12, 29U)) + Flight_code_DC_B.In1_l.pitchspeed *
    look1_binlxpw((real_T)Flight_code_DC_B.In1_m.indicated_airspeed_m_s,
                  Flight_code_DC_P.V0, Flight_code_DC_P.F13, 29U)) +
    Flight_code_DC_B.Product1[3] * look1_binlxpw((real_T)
    Flight_code_DC_B.In1_m.indicated_airspeed_m_s, Flight_code_DC_P.V0,
    Flight_code_DC_P.F14, 29U)) +
    (Flight_code_DC_DW.DiscreteTimeIntegrator_DSTATE * look1_binlxpw((real_T)
      Flight_code_DC_B.In1_m.indicated_airspeed_m_s, Flight_code_DC_P.V0,
      Flight_code_DC_P.FI11, 29U) +
     Flight_code_DC_DW.DiscreteTimeIntegrator_DSTATE_a * look1_binlxpw((real_T)
      Flight_code_DC_B.In1_m.indicated_airspeed_m_s, Flight_code_DC_P.V0,
      Flight_code_DC_P.FI12, 29U));
  Flight_code_DC_B.Dif_L = (((Flight_code_DC_B.In1_k.vx * look1_binlxpw((real_T)
    Flight_code_DC_B.In1_m.indicated_airspeed_m_s, Flight_code_DC_P.V0,
    Flight_code_DC_P.F21, 29U) + Flight_code_DC_B.In1_k.vz * look1_binlxpw
    ((real_T)Flight_code_DC_B.In1_m.indicated_airspeed_m_s, Flight_code_DC_P.V0,
     Flight_code_DC_P.F22, 29U)) + Flight_code_DC_B.In1_l.pitchspeed *
    look1_binlxpw((real_T)Flight_code_DC_B.In1_m.indicated_airspeed_m_s,
                  Flight_code_DC_P.V0, Flight_code_DC_P.F23, 29U)) +
    Flight_code_DC_B.Product1[3] * look1_binlxpw((real_T)
    Flight_code_DC_B.In1_m.indicated_airspeed_m_s, Flight_code_DC_P.V0,
    Flight_code_DC_P.F24, 29U)) +
    (Flight_code_DC_DW.DiscreteTimeIntegrator_DSTATE * look1_binlxpw((real_T)
      Flight_code_DC_B.In1_m.indicated_airspeed_m_s, Flight_code_DC_P.V0,
      Flight_code_DC_P.FI21, 29U) +
     Flight_code_DC_DW.DiscreteTimeIntegrator_DSTATE_a * look1_binlxpw((real_T)
      Flight_code_DC_B.In1_m.indicated_airspeed_m_s, Flight_code_DC_P.V0,
      Flight_code_DC_P.FI22, 29U));

  // Sum: '<S83>/Sum' incorporates:
  //   Gain: '<S78>/Gain'
  //   Gain: '<S79>/Gain1'
  //   Gain: '<S79>/Gain6'
  //   Sum: '<S126>/Sum'
  //   Sum: '<S78>/Sum'

  Flight_code_DC_B.Sum_l = (1.0 / Flight_code_DC_P.AILERON_LIMITS *
    Flight_code_DC_B.Gain1 * Flight_code_DC_P.BANK_LIMITS - rtb_Gain4_f) *
    Flight_code_DC_P.K_phi - Flight_code_DC_B.In1_l.rollspeed;

  // Product: '<S104>/Divide' incorporates:
  //   Constant: '<S104>/Constant'

  Flight_code_DC_B.Dif_R = Flight_code_DC_B.In1_m.indicated_airspeed_m_s /
    Flight_code_DC_P.REF_SPEED;

  // Product: '<S104>/Divide1' incorporates:
  //   Gain: '<S104>/Gain'
  //   Sum: '<S83>/Sum'

  Flight_code_DC_B.Divide1_l = Flight_code_DC_P.Kp_p * Flight_code_DC_B.Sum_l *
    Flight_code_DC_B.Dif_R * Flight_code_DC_B.Dif_R;

  // DiscreteIntegrator: '<S103>/Discrete-Time Integrator' incorporates:
  //   Sum: '<S83>/Sum'

  if (Flight_code_DC_DW.DiscreteTimeIntegrator_IC_LOADI != 0) {
    Flight_code_DC_DW.DiscreteTimeIntegrator_DSTATE_f = Flight_code_DC_B.Sum_l;
  }

  if ((rtb_Mode_change && (Flight_code_DC_DW.DiscreteTimeIntegrator_PrevR_p5 <=
        0)) || ((!rtb_Mode_change) &&
                (Flight_code_DC_DW.DiscreteTimeIntegrator_PrevR_p5 == 1))) {
    Flight_code_DC_DW.DiscreteTimeIntegrator_DSTATE_f = Flight_code_DC_B.Sum_l;
  }

  // Sum: '<S83>/Sum1' incorporates:
  //   DiscreteIntegrator: '<S103>/Discrete-Time Integrator'

  Flight_code_DC_B.Sum1 = Flight_code_DC_B.Divide1_l +
    Flight_code_DC_DW.DiscreteTimeIntegrator_DSTATE_f;

  // Sum: '<S77>/Sum' incorporates:
  //   Gain: '<S79>/Gain2'
  //   Gain: '<S79>/Gain3'
  //   Sum: '<S120>/Sum'

  Flight_code_DC_B.Sum_o = 1.0 / Flight_code_DC_P.RUDDER_LIMITS *
    Flight_code_DC_B.Gain2 * Flight_code_DC_P.BETA_LIMITS -
    Flight_code_DC_B.DataTypeConversion;

  // Gain: '<S77>/Gain' incorporates:
  //   Sum: '<S77>/Sum'

  Flight_code_DC_B.Gain_jg = Flight_code_DC_P.Kp_Beta * Flight_code_DC_B.Sum_o;

  // DiscreteIntegrator: '<S88>/Discrete-Time Integrator' incorporates:
  //   Sum: '<S77>/Sum'

  if (Flight_code_DC_DW.DiscreteTimeIntegrator_IC_LOA_e != 0) {
    Flight_code_DC_DW.DiscreteTimeIntegrator_DSTATE_l = Flight_code_DC_B.Sum_o;
  }

  if ((rtb_Mode_change && (Flight_code_DC_DW.DiscreteTimeIntegrator_PrevRe_c <=
        0)) || ((!rtb_Mode_change) &&
                (Flight_code_DC_DW.DiscreteTimeIntegrator_PrevRe_c == 1))) {
    Flight_code_DC_DW.DiscreteTimeIntegrator_DSTATE_l = Flight_code_DC_B.Sum_o;
  }

  // DiscreteIntegrator: '<S114>/Discrete-Time Integrator' incorporates:
  //   Memory: '<S86>/Memory'

  if (Flight_code_DC_DW.DiscreteTimeIntegrator_IC_LOA_k != 0) {
    Flight_code_DC_DW.DiscreteTimeIntegrator_DSTATE_n =
      Flight_code_DC_DW.Memory_PreviousInput_l;
  }

  if ((rtb_Mode_change && (Flight_code_DC_DW.DiscreteTimeIntegrator_PrevRe_o <=
        0)) || ((!rtb_Mode_change) &&
                (Flight_code_DC_DW.DiscreteTimeIntegrator_PrevRe_o == 1))) {
    Flight_code_DC_DW.DiscreteTimeIntegrator_DSTATE_n =
      Flight_code_DC_DW.Memory_PreviousInput_l;
  }

  // Product: '<S86>/Divide1' incorporates:
  //   Gain: '<S86>/Gain3'
  //   Product: '<S129>/Divide1'

  Flight_code_DC_B.Dif_R_p = Flight_code_DC_P.Kp_r *
    Flight_code_DC_B.In1_l.yawspeed;

  // Product: '<S86>/Divide' incorporates:
  //   Constant: '<S86>/Constant'
  //   Product: '<S77>/Divide'

  Flight_code_DC_B.rtb_Sum2_tmp = Flight_code_DC_P.REF_SPEED /
    Flight_code_DC_B.In1_m.indicated_airspeed_m_s;

  // Sum: '<S26>/Sum2' incorporates:
  //   DiscreteIntegrator: '<S114>/Discrete-Time Integrator'
  //   DiscreteIntegrator: '<S88>/Discrete-Time Integrator'
  //   Product: '<S86>/Divide'
  //   Product: '<S86>/Divide1'
  //   Sum: '<S77>/Sum1'
  //   Sum: '<S86>/Sum1'

  Flight_code_DC_B.Sum2 = (Flight_code_DC_B.Gain_jg +
    Flight_code_DC_DW.DiscreteTimeIntegrator_DSTATE_l) -
    (Flight_code_DC_B.rtb_Sum2_tmp * Flight_code_DC_B.Dif_R_p +
     Flight_code_DC_DW.DiscreteTimeIntegrator_DSTATE_n);

  // Sum: '<S122>/Sum' incorporates:
  //   Memory: '<S122>/Memory'

  Flight_code_DC_B.Excess = (real_T)rtb_Mode -
    Flight_code_DC_DW.Memory_PreviousInput_o;

  // DataTypeConversion: '<S122>/Data Type Conversion'
  rtb_Mode_change_e = (Flight_code_DC_B.Excess != 0.0);

  // DiscreteIntegrator: '<S136>/Discrete-Time Integrator' incorporates:
  //   Constant: '<S123>/Constant'
  //   DataTypeConversion: '<S122>/Data Type Conversion'
  //   Sum: '<S122>/Sum'

  if (((Flight_code_DC_B.Excess != 0.0) &&
       (Flight_code_DC_DW.DiscreteTimeIntegrator_PrevRe_d <= 0)) ||
      ((!(Flight_code_DC_B.Excess != 0.0)) &&
       (Flight_code_DC_DW.DiscreteTimeIntegrator_PrevRe_d == 1))) {
    Flight_code_DC_DW.DiscreteTimeIntegrator_DSTATE_j =
      Flight_code_DC_P.Constant_Value_lq;
  }

  // DiscreteIntegrator: '<S137>/Discrete-Time Integrator' incorporates:
  //   Constant: '<S123>/Constant1'

  if ((rtb_Mode_change_e && (Flight_code_DC_DW.DiscreteTimeIntegrator_PrevRe_h <=
        0)) || ((!rtb_Mode_change_e) &&
                (Flight_code_DC_DW.DiscreteTimeIntegrator_PrevRe_h == 1))) {
    Flight_code_DC_DW.DiscreteTimeIntegrator_DSTATE_k =
      Flight_code_DC_P.Constant1_Value_g;
  }

  // Sum: '<S123>/Sum' incorporates:
  //   Constant: '<S27>/Airspeed2'
  //   DataTypeConversion: '<S80>/boolean2double2'
  //   DataTypeConversion: '<S80>/boolean2double3'
  //   DataTypeConversion: '<S80>/boolean2double5'
  //   DiscreteIntegrator: '<S136>/Discrete-Time Integrator'
  //   DiscreteIntegrator: '<S137>/Discrete-Time Integrator'
  //   DotProduct: '<S123>/Dot Product'
  //   DotProduct: '<S123>/Dot Product1'
  //   DotProduct: '<S123>/Dot Product2'
  //   DotProduct: '<S123>/Dot Product3'
  //   Lookup_n-D: '<S123>/F11'
  //   Lookup_n-D: '<S123>/F12'
  //   Lookup_n-D: '<S123>/F13'
  //   Lookup_n-D: '<S123>/F14'
  //   Lookup_n-D: '<S123>/F21'
  //   Lookup_n-D: '<S123>/F22'
  //   Lookup_n-D: '<S123>/F23'
  //   Lookup_n-D: '<S123>/F24'
  //   Lookup_n-D: '<S123>/FI11'
  //   Lookup_n-D: '<S123>/FI12'
  //   Lookup_n-D: '<S123>/FI21'
  //   Lookup_n-D: '<S123>/FI22'
  //   SignalConversion: '<S123>/TmpSignal ConversionAtDot Product2Inport1'

  Flight_code_DC_B.rtb_Sum_i_idx_0 = (((Flight_code_DC_B.In1_k.vx *
    look1_binlxpw(Flight_code_DC_P.Airspeed2_Value, Flight_code_DC_P.V0,
                  Flight_code_DC_P.F11, 29U) + Flight_code_DC_B.In1_k.vz *
    look1_binlxpw(Flight_code_DC_P.Airspeed2_Value, Flight_code_DC_P.V0,
                  Flight_code_DC_P.F12, 29U)) +
    Flight_code_DC_B.In1_l.pitchspeed * look1_binlxpw
    (Flight_code_DC_P.Airspeed2_Value, Flight_code_DC_P.V0, Flight_code_DC_P.F13,
     29U)) + Flight_code_DC_B.Product1[3] * look1_binlxpw
    (Flight_code_DC_P.Airspeed2_Value, Flight_code_DC_P.V0, Flight_code_DC_P.F14,
     29U)) + (Flight_code_DC_DW.DiscreteTimeIntegrator_DSTATE_j * look1_binlxpw
              (Flight_code_DC_P.Airspeed2_Value, Flight_code_DC_P.V0,
               Flight_code_DC_P.FI11, 29U) +
              Flight_code_DC_DW.DiscreteTimeIntegrator_DSTATE_k * look1_binlxpw
              (Flight_code_DC_P.Airspeed2_Value, Flight_code_DC_P.V0,
               Flight_code_DC_P.FI12, 29U));
  Flight_code_DC_B.rtb_Sum_i_idx_1 = (((Flight_code_DC_B.In1_k.vx *
    look1_binlxpw(Flight_code_DC_P.Airspeed2_Value, Flight_code_DC_P.V0,
                  Flight_code_DC_P.F21, 29U) + Flight_code_DC_B.In1_k.vz *
    look1_binlxpw(Flight_code_DC_P.Airspeed2_Value, Flight_code_DC_P.V0,
                  Flight_code_DC_P.F22, 29U)) +
    Flight_code_DC_B.In1_l.pitchspeed * look1_binlxpw
    (Flight_code_DC_P.Airspeed2_Value, Flight_code_DC_P.V0, Flight_code_DC_P.F23,
     29U)) + Flight_code_DC_B.Product1[3] * look1_binlxpw
    (Flight_code_DC_P.Airspeed2_Value, Flight_code_DC_P.V0, Flight_code_DC_P.F24,
     29U)) + (Flight_code_DC_DW.DiscreteTimeIntegrator_DSTATE_j * look1_binlxpw
              (Flight_code_DC_P.Airspeed2_Value, Flight_code_DC_P.V0,
               Flight_code_DC_P.FI21, 29U) +
              Flight_code_DC_DW.DiscreteTimeIntegrator_DSTATE_k * look1_binlxpw
              (Flight_code_DC_P.Airspeed2_Value, Flight_code_DC_P.V0,
               Flight_code_DC_P.FI22, 29U));

  // Product: '<S147>/Divide' incorporates:
  //   Constant: '<S147>/Constant'
  //   Constant: '<S27>/Airspeed'

  Flight_code_DC_B.Excess = Flight_code_DC_P.Airspeed_Value /
    Flight_code_DC_P.REF_SPEED;

  // Product: '<S147>/Divide1' incorporates:
  //   Gain: '<S147>/Gain'

  Flight_code_DC_B.Divide1_a = Flight_code_DC_P.Kp_p * Flight_code_DC_B.Sum_l *
    Flight_code_DC_B.Excess * Flight_code_DC_B.Excess;

  // DiscreteIntegrator: '<S146>/Discrete-Time Integrator'
  if (Flight_code_DC_DW.DiscreteTimeIntegrator_IC_LO_e2 != 0) {
    Flight_code_DC_DW.DiscreteTimeIntegrator_DSTAT_fn = Flight_code_DC_B.Sum_l;
  }

  if ((rtb_Mode_change_e && (Flight_code_DC_DW.DiscreteTimeIntegrator_PrevR_d5 <=
        0)) || ((!rtb_Mode_change_e) &&
                (Flight_code_DC_DW.DiscreteTimeIntegrator_PrevR_d5 == 1))) {
    Flight_code_DC_DW.DiscreteTimeIntegrator_DSTAT_fn = Flight_code_DC_B.Sum_l;
  }

  // Sum: '<S126>/Sum1' incorporates:
  //   DiscreteIntegrator: '<S146>/Discrete-Time Integrator'

  Flight_code_DC_B.Sum_l = Flight_code_DC_B.Divide1_a +
    Flight_code_DC_DW.DiscreteTimeIntegrator_DSTAT_fn;

  // Gain: '<S120>/Gain'
  Flight_code_DC_B.Gain_j = Flight_code_DC_P.Kp_Beta * Flight_code_DC_B.Sum_o;

  // DiscreteIntegrator: '<S131>/Discrete-Time Integrator'
  if (Flight_code_DC_DW.DiscreteTimeIntegrator_IC_LOA_c != 0) {
    Flight_code_DC_DW.DiscreteTimeIntegrator_DSTATE_e = Flight_code_DC_B.Sum_o;
  }

  if ((rtb_Mode_change_e && (Flight_code_DC_DW.DiscreteTimeIntegrator_PrevR_d4 <=
        0)) || ((!rtb_Mode_change_e) &&
                (Flight_code_DC_DW.DiscreteTimeIntegrator_PrevR_d4 == 1))) {
    Flight_code_DC_DW.DiscreteTimeIntegrator_DSTATE_e = Flight_code_DC_B.Sum_o;
  }

  // DiscreteIntegrator: '<S157>/Discrete-Time Integrator' incorporates:
  //   Memory: '<S129>/Memory'

  if (Flight_code_DC_DW.DiscreteTimeIntegrator_IC_LOA_h != 0) {
    Flight_code_DC_DW.DiscreteTimeIntegrator_DSTAT_kf =
      Flight_code_DC_DW.Memory_PreviousInput_l2;
  }

  if ((rtb_Mode_change_e && (Flight_code_DC_DW.DiscreteTimeIntegrator_PrevRe_f <=
        0)) || ((!rtb_Mode_change_e) &&
                (Flight_code_DC_DW.DiscreteTimeIntegrator_PrevRe_f == 1))) {
    Flight_code_DC_DW.DiscreteTimeIntegrator_DSTAT_kf =
      Flight_code_DC_DW.Memory_PreviousInput_l2;
  }

  // Sum: '<S27>/Sum2' incorporates:
  //   Constant: '<S129>/Constant'
  //   Constant: '<S27>/Airspeed1'
  //   DiscreteIntegrator: '<S131>/Discrete-Time Integrator'
  //   DiscreteIntegrator: '<S157>/Discrete-Time Integrator'
  //   Product: '<S129>/Divide'
  //   Product: '<S129>/Divide1'
  //   Sum: '<S120>/Sum1'
  //   Sum: '<S129>/Sum1'

  Flight_code_DC_B.Sum_o = (Flight_code_DC_B.Gain_j +
    Flight_code_DC_DW.DiscreteTimeIntegrator_DSTATE_e) - (1.0 /
    Flight_code_DC_P.Airspeed1_Value * Flight_code_DC_P.REF_SPEED *
    Flight_code_DC_B.Dif_R_p + Flight_code_DC_DW.DiscreteTimeIntegrator_DSTAT_kf);

  // Lookup_n-D: '<S74>/K13' incorporates:
  //   Constant: '<S25>/Constant'

  Flight_code_DC_B.Dif_R_p = look1_binlxpw(Flight_code_DC_P.Constant_Value_c,
    Flight_code_DC_P.V_K_SAS, Flight_code_DC_P.K13, 18U);

  // DataTypeConversion: '<S25>/Data Type Conversion1'
  Flight_code_DC_B.Throttle_out_a = Flight_code_DC_B.In1_l.yawspeed;

  // DataTypeConversion: '<S25>/Data Type Conversion2'
  Flight_code_DC_B.Dif_L_i = rtb_Gain4_f;

  // Concatenate: '<S74>/Matrix Concatenate' incorporates:
  //   Constant: '<S25>/Constant'
  //   Constant: '<S74>/Constant1'
  //   Constant: '<S74>/Constant16'
  //   Constant: '<S74>/Constant2'
  //   Constant: '<S74>/Constant3'
  //   Constant: '<S74>/Constant4'
  //   Constant: '<S74>/Constant5'
  //   Constant: '<S74>/Constant6'
  //   Constant: '<S74>/Constant7'
  //   Constant: '<S74>/Constant8'
  //   Constant: '<S74>/Constant9'
  //   Lookup_n-D: '<S74>/K11'
  //   Lookup_n-D: '<S74>/K12'
  //   Lookup_n-D: '<S74>/K31'
  //   Lookup_n-D: '<S74>/K32'
  //   Lookup_n-D: '<S74>/K33'

  Flight_code_DC_B.MatrixConcatenate[0] = look1_binlxpw
    (Flight_code_DC_P.Constant_Value_c, Flight_code_DC_P.V_K_SAS,
     Flight_code_DC_P.K11, 18U);
  Flight_code_DC_B.MatrixConcatenate[4] = look1_binlxpw
    (Flight_code_DC_P.Constant_Value_c, Flight_code_DC_P.V_K_SAS,
     Flight_code_DC_P.K12, 18U);
  Flight_code_DC_B.MatrixConcatenate[8] = Flight_code_DC_B.Dif_R_p;
  Flight_code_DC_B.MatrixConcatenate[12] = Flight_code_DC_P.Constant7_Value_f;
  Flight_code_DC_B.MatrixConcatenate[1] = Flight_code_DC_P.Constant1_Value_m;
  Flight_code_DC_B.MatrixConcatenate[5] = Flight_code_DC_P.Constant2_Value_b;
  Flight_code_DC_B.MatrixConcatenate[9] = Flight_code_DC_P.Constant3_Value_n;
  Flight_code_DC_B.MatrixConcatenate[13] = Flight_code_DC_P.Constant4_Value_i;
  Flight_code_DC_B.MatrixConcatenate[2] = look1_binlxpw
    (Flight_code_DC_P.Constant_Value_c, Flight_code_DC_P.V_K_SAS,
     Flight_code_DC_P.K31, 18U);
  Flight_code_DC_B.MatrixConcatenate[6] = look1_binlxpw
    (Flight_code_DC_P.Constant_Value_c, Flight_code_DC_P.V_K_SAS,
     Flight_code_DC_P.K32, 18U);
  Flight_code_DC_B.MatrixConcatenate[10] = look1_binlxpw
    (Flight_code_DC_P.Constant_Value_c, Flight_code_DC_P.V_K_SAS,
     Flight_code_DC_P.K33, 18U);
  Flight_code_DC_B.MatrixConcatenate[14] = Flight_code_DC_P.Constant5_Value_p;
  Flight_code_DC_B.MatrixConcatenate[3] = Flight_code_DC_P.Constant6_Value_i;
  Flight_code_DC_B.MatrixConcatenate[7] = Flight_code_DC_P.Constant8_Value_p;
  Flight_code_DC_B.MatrixConcatenate[11] = Flight_code_DC_P.Constant9_Value_o;
  Flight_code_DC_B.MatrixConcatenate[15] = Flight_code_DC_P.Constant16_Value_d;

  // SignalConversion: '<S25>/TmpSignal ConversionAtProduct1Inport2' incorporates:
  //   Constant: '<S25>/Constant1'
  //   Product: '<S25>/Product'

  Flight_code_DC_B.Dif_R_p = Flight_code_DC_P.Constant1_Value_m3 *
    Flight_code_DC_B.DataTypeConversion;

  // Product: '<S25>/Product1' incorporates:
  //   DataTypeConversion: '<S25>/Data Type Conversion'
  //   DataTypeConversion: '<S25>/Data Type Conversion1'
  //   DataTypeConversion: '<S25>/Data Type Conversion2'

  for (i = 0; i < 4; i++) {
    Flight_code_DC_B.Throttle_out_a = Flight_code_DC_B.MatrixConcatenate[i + 12]
      * rtb_Gain4_f + (Flight_code_DC_B.MatrixConcatenate[i + 8] *
                       Flight_code_DC_B.In1_l.yawspeed +
                       (Flight_code_DC_B.MatrixConcatenate[i + 4] *
                        Flight_code_DC_B.In1_l.rollspeed +
                        Flight_code_DC_B.MatrixConcatenate[i] *
                        Flight_code_DC_B.Dif_R_p));
    Flight_code_DC_B.Product1[i] = Flight_code_DC_B.Throttle_out_a;
  }

  // End of Product: '<S25>/Product1'

  // MATLAB Function: '<S25>/MATLAB Function' incorporates:
  //   Constant: '<S25>/Constant2'
  //   Constant: '<S76>/Constant'
  //   Gain: '<S76>/Gain'
  //   Math: '<S76>/Math Function'
  //   Product: '<S76>/Product'
  //   Sum: '<S25>/Sum7'
  //   Sum: '<S76>/Sum'
  //
  //  About '<S76>/Math Function':
  //   Operator: magnitude^2

  Flight_code_DC_MATLABFunction(Flight_code_DC_B.Gain,
    Flight_code_DC_B.Product1[2] + (Flight_code_DC_P.Gain_Gain_h *
    (Flight_code_DC_P.Constant2_Value_k * Flight_code_DC_P.Constant2_Value_k) -
    Flight_code_DC_P.K_RUDDER_AILERON) * Flight_code_DC_B.Gain2,
    &Flight_code_DC_B.Throttle_out_a, &Flight_code_DC_B.Dif_L_i,
    &Flight_code_DC_B.Dif_R_p);

  // SignalConversion: '<S11>/TmpSignal ConversionAt SFunction Inport2' incorporates:
  //   Constant: '<S7>/Constant'
  //   Gain: '<S45>/K_RUDDER_AILERON'
  //   MATLAB Function: '<Root>/MATLAB_Function'
  //   Sum: '<S45>/Sum'

  Flight_code_DC_B.TmpSignalConversionAtSFunct[3] =
    Flight_code_DC_P.K_RUDDER_AILERON * Flight_code_DC_B.Gain2 +
    Flight_code_DC_B.Gain1;
  Flight_code_DC_B.TmpSignalConversionAtSFunct[4] =
    Flight_code_DC_P.Constant_Value_l;
  Flight_code_DC_B.TmpSignalConversionAtSFunct[5] = Flight_code_DC_B.Delta2;

  // MATLAB Function: '<Root>/MATLAB_Function' incorporates:
  //   SignalConversion: '<S11>/TmpSignal ConversionAt SFunction Inport3'

  for (i = 0; i < 6; i++) {
    Flight_code_DC_B.y[i] = Flight_code_DC_B.TmpSignalConversionAtSFunct[i] *
      0.0;
  }

  if (rtb_Mode != 1) {
    if (rtb_Mode == 3) {
      Flight_code_DC_B.y[0] = Flight_code_DC_B.Gain;
      Flight_code_DC_B.y[1] = Flight_code_DC_B.Gain;
      Flight_code_DC_B.y[2] = Flight_code_DC_B.Gain;
      Flight_code_DC_B.y[3] = Flight_code_DC_B.Gain1;
      Flight_code_DC_B.y[4] = Flight_code_DC_B.Gain2;
      Flight_code_DC_B.y[5] = Flight_code_DC_B.Delta2;
    } else {
      if (rtb_Mode == 4) {
        for (i = 0; i < 6; i++) {
          Flight_code_DC_B.y[i] = Flight_code_DC_B.TmpSignalConversionAtSFunct[i];
        }
      }
    }
  }

  // Fcn: '<S12>/Fcn4' incorporates:
  //   Gain: '<S12>/Gain'

  Flight_code_DC_B.Dif_R_p = (-(1.0 / Flight_code_DC_P.AILERON_LIMITS *
    Flight_code_DC_B.y[3]) + 3.0) * 500.0;

  // Saturate: '<S12>/Output_Limits4'
  if (Flight_code_DC_B.Dif_R_p > Flight_code_DC_P.Output_Limits4_UpperSat) {
    Flight_code_DC_B.Dif_R_p = Flight_code_DC_P.Output_Limits4_UpperSat;
  } else {
    if (Flight_code_DC_B.Dif_R_p < Flight_code_DC_P.Output_Limits4_LowerSat) {
      Flight_code_DC_B.Dif_R_p = Flight_code_DC_P.Output_Limits4_LowerSat;
    }
  }

  // End of Saturate: '<S12>/Output_Limits4'

  // DataTypeConversion: '<S12>/Data Type Conversion3'
  Flight_code_DC_B.Gain1 = floor(Flight_code_DC_B.Dif_R_p);
  if (rtIsNaN(Flight_code_DC_B.Gain1) || rtIsInf(Flight_code_DC_B.Gain1)) {
    Flight_code_DC_B.Gain1 = 0.0;
  } else {
    Flight_code_DC_B.Gain1 = fmod(Flight_code_DC_B.Gain1, 65536.0);
  }

  rtb_DataTypeConversion3 = (uint16_T)(Flight_code_DC_B.Gain1 < 0.0 ? (int32_T)
    (uint16_T)-(int16_T)(uint16_T)-Flight_code_DC_B.Gain1 : (int32_T)(uint16_T)
    Flight_code_DC_B.Gain1);

  // End of DataTypeConversion: '<S12>/Data Type Conversion3'

  // Fcn: '<S12>/Fcn3'
  Flight_code_DC_B.Gain2 = (Flight_code_DC_B.y[2] + 1.0) * 1000.0;

  // Switch: '<S59>/Switch' incorporates:
  //   Constant: '<S59>/Constant'

  if (!(Flight_code_DC_B.Gain2 > Flight_code_DC_P.Switch_Threshold)) {
    Flight_code_DC_B.Gain2 = Flight_code_DC_P.Constant_Value_d;
  }

  // End of Switch: '<S59>/Switch'

  // Saturate: '<S12>/Output_Limits3'
  if (Flight_code_DC_B.Gain2 > Flight_code_DC_P.Output_Limits3_UpperSat) {
    Flight_code_DC_B.Gain2 = Flight_code_DC_P.Output_Limits3_UpperSat;
  } else {
    if (Flight_code_DC_B.Gain2 < Flight_code_DC_P.Output_Limits3_LowerSat) {
      Flight_code_DC_B.Gain2 = Flight_code_DC_P.Output_Limits3_LowerSat;
    }
  }

  // End of Saturate: '<S12>/Output_Limits3'

  // DataTypeConversion: '<S12>/Data Type Conversion2'
  Flight_code_DC_B.Gain1 = floor(Flight_code_DC_B.Gain2);
  if (rtIsNaN(Flight_code_DC_B.Gain1) || rtIsInf(Flight_code_DC_B.Gain1)) {
    Flight_code_DC_B.Gain1 = 0.0;
  } else {
    Flight_code_DC_B.Gain1 = fmod(Flight_code_DC_B.Gain1, 65536.0);
  }

  // Fcn: '<S12>/Fcn1'
  Flight_code_DC_B.Gain2 = (Flight_code_DC_B.y[0] + 1.0) * 1000.0;

  // Switch: '<S57>/Switch' incorporates:
  //   Constant: '<S57>/Constant'

  if (!(Flight_code_DC_B.Gain2 > Flight_code_DC_P.Switch_Threshold_m)) {
    Flight_code_DC_B.Gain2 = Flight_code_DC_P.Constant_Value_fj;
  }

  // End of Switch: '<S57>/Switch'

  // Saturate: '<S12>/Output_Limits1'
  if (Flight_code_DC_B.Gain2 > Flight_code_DC_P.Output_Limits1_UpperSat) {
    Flight_code_DC_B.Gain2 = Flight_code_DC_P.Output_Limits1_UpperSat;
  } else {
    if (Flight_code_DC_B.Gain2 < Flight_code_DC_P.Output_Limits1_LowerSat) {
      Flight_code_DC_B.Gain2 = Flight_code_DC_P.Output_Limits1_LowerSat;
    }
  }

  // End of Saturate: '<S12>/Output_Limits1'

  // DataTypeConversion: '<S12>/Data Type Conversion5'
  Flight_code_DC_B.Dif_R_p = floor(Flight_code_DC_B.Gain2);
  if (rtIsNaN(Flight_code_DC_B.Dif_R_p) || rtIsInf(Flight_code_DC_B.Dif_R_p)) {
    Flight_code_DC_B.Dif_R_p = 0.0;
  } else {
    Flight_code_DC_B.Dif_R_p = fmod(Flight_code_DC_B.Dif_R_p, 65536.0);
  }

  rtb_DataTypeConversion5 = (uint16_T)(Flight_code_DC_B.Dif_R_p < 0.0 ? (int32_T)
    (uint16_T)-(int16_T)(uint16_T)-Flight_code_DC_B.Dif_R_p : (int32_T)(uint16_T)
    Flight_code_DC_B.Dif_R_p);

  // End of DataTypeConversion: '<S12>/Data Type Conversion5'

  // Fcn: '<S12>/Fcn2'
  Flight_code_DC_B.Gain2 = (Flight_code_DC_B.y[1] + 1.0) * 1000.0;

  // Switch: '<S58>/Switch' incorporates:
  //   Constant: '<S58>/Constant'

  if (!(Flight_code_DC_B.Gain2 > Flight_code_DC_P.Switch_Threshold_d)) {
    Flight_code_DC_B.Gain2 = Flight_code_DC_P.Constant_Value_i;
  }

  // End of Switch: '<S58>/Switch'

  // Saturate: '<S12>/Output_Limits2'
  if (Flight_code_DC_B.Gain2 > Flight_code_DC_P.Output_Limits2_UpperSat) {
    Flight_code_DC_B.Gain2 = Flight_code_DC_P.Output_Limits2_UpperSat;
  } else {
    if (Flight_code_DC_B.Gain2 < Flight_code_DC_P.Output_Limits2_LowerSat) {
      Flight_code_DC_B.Gain2 = Flight_code_DC_P.Output_Limits2_LowerSat;
    }
  }

  // End of Saturate: '<S12>/Output_Limits2'

  // MATLABSystem: '<Root>/PX4 PWM Output' incorporates:
  //   Constant: '<Root>/Constant'
  //   Constant: '<Root>/Constant5'
  //   DataTypeConversion: '<S12>/Data Type Conversion1'
  //   DataTypeConversion: '<S12>/Data Type Conversion2'
  //   DataTypeConversion: '<S12>/Data Type Conversion6'
  //   DataTypeConversion: '<S12>/Data Type Conversion7'

  if (Flight_code_DC_P.Constant_Value_ig) {
    status = pwm_arm(&Flight_code_DC_DW.obj_kz.pwmDevHandler);
    Flight_code_DC_DW.obj_kz.errorStatus |= status;
    Flight_code_DC_B.pwmValue[0] = rtb_DataTypeConversion3;

    // Fcn: '<S12>/Fcn7' incorporates:
    //   Gain: '<S12>/Gain2'

    Flight_code_DC_B.Dif_R_p = (-(1.0 / Flight_code_DC_P.ELEVATOR_LIMITS *
      Flight_code_DC_B.y[5]) + 3.0) * 500.0;

    // Saturate: '<S12>/Output_Limits7'
    if (Flight_code_DC_B.Dif_R_p > Flight_code_DC_P.Output_Limits7_UpperSat) {
      Flight_code_DC_B.Dif_R_p = Flight_code_DC_P.Output_Limits7_UpperSat;
    } else {
      if (Flight_code_DC_B.Dif_R_p < Flight_code_DC_P.Output_Limits7_LowerSat) {
        Flight_code_DC_B.Dif_R_p = Flight_code_DC_P.Output_Limits7_LowerSat;
      }
    }

    // End of Saturate: '<S12>/Output_Limits7'

    // DataTypeConversion: '<S12>/Data Type Conversion7'
    Flight_code_DC_B.Dif_R_p = floor(Flight_code_DC_B.Dif_R_p);
    if (rtIsNaN(Flight_code_DC_B.Dif_R_p) || rtIsInf(Flight_code_DC_B.Dif_R_p))
    {
      Flight_code_DC_B.Dif_R_p = 0.0;
    } else {
      Flight_code_DC_B.Dif_R_p = fmod(Flight_code_DC_B.Dif_R_p, 65536.0);
    }

    Flight_code_DC_B.pwmValue[1] = (uint16_T)(Flight_code_DC_B.Dif_R_p < 0.0 ?
      (int32_T)(uint16_T)-(int16_T)(uint16_T)-Flight_code_DC_B.Dif_R_p :
      (int32_T)(uint16_T)Flight_code_DC_B.Dif_R_p);
    Flight_code_DC_B.pwmValue[2] = rtb_DataTypeConversion3;

    // Fcn: '<S12>/Fcn6' incorporates:
    //   DataTypeConversion: '<S12>/Data Type Conversion7'
    //   Gain: '<S12>/Gain1'

    Flight_code_DC_B.Dif_R_p = (1.0 / Flight_code_DC_P.RUDDER_LIMITS *
      Flight_code_DC_B.y[4] + 3.0) * 500.0;

    // Saturate: '<S12>/Output_Limits6'
    if (Flight_code_DC_B.Dif_R_p > Flight_code_DC_P.Output_Limits6_UpperSat) {
      Flight_code_DC_B.Dif_R_p = Flight_code_DC_P.Output_Limits6_UpperSat;
    } else {
      if (Flight_code_DC_B.Dif_R_p < Flight_code_DC_P.Output_Limits6_LowerSat) {
        Flight_code_DC_B.Dif_R_p = Flight_code_DC_P.Output_Limits6_LowerSat;
      }
    }

    // End of Saturate: '<S12>/Output_Limits6'

    // DataTypeConversion: '<S12>/Data Type Conversion6'
    Flight_code_DC_B.Dif_R_p = floor(Flight_code_DC_B.Dif_R_p);
    if (rtIsNaN(Flight_code_DC_B.Dif_R_p) || rtIsInf(Flight_code_DC_B.Dif_R_p))
    {
      Flight_code_DC_B.Dif_R_p = 0.0;
    } else {
      Flight_code_DC_B.Dif_R_p = fmod(Flight_code_DC_B.Dif_R_p, 65536.0);
    }

    Flight_code_DC_B.pwmValue[3] = (uint16_T)(Flight_code_DC_B.Dif_R_p < 0.0 ?
      (int32_T)(uint16_T)-(int16_T)(uint16_T)-Flight_code_DC_B.Dif_R_p :
      (int32_T)(uint16_T)Flight_code_DC_B.Dif_R_p);
    Flight_code_DC_B.pwmValue[4] = (uint16_T)(Flight_code_DC_B.Gain1 < 0.0 ?
      (int32_T)(uint16_T)-(int16_T)(uint16_T)-Flight_code_DC_B.Gain1 : (int32_T)
      (uint16_T)Flight_code_DC_B.Gain1);
    Flight_code_DC_B.pwmValue[5] = rtb_DataTypeConversion5;
    Flight_code_DC_B.pwmValue[6] = rtb_DataTypeConversion5;

    // DataTypeConversion: '<S12>/Data Type Conversion1' incorporates:
    //   DataTypeConversion: '<S12>/Data Type Conversion2'
    //   DataTypeConversion: '<S12>/Data Type Conversion6'

    Flight_code_DC_B.Gain1 = floor(Flight_code_DC_B.Gain2);
    if (rtIsNaN(Flight_code_DC_B.Gain1) || rtIsInf(Flight_code_DC_B.Gain1)) {
      Flight_code_DC_B.Gain1 = 0.0;
    } else {
      Flight_code_DC_B.Gain1 = fmod(Flight_code_DC_B.Gain1, 65536.0);
    }

    Flight_code_DC_B.pwmValue[7] = (uint16_T)(Flight_code_DC_B.Gain1 < 0.0 ?
      (int32_T)(uint16_T)-(int16_T)(uint16_T)-Flight_code_DC_B.Gain1 : (int32_T)
      (uint16_T)Flight_code_DC_B.Gain1);
    status = pwm_setServo(&Flight_code_DC_DW.obj_kz.pwmDevHandler,
                          Flight_code_DC_DW.obj_kz.servoCount,
                          Flight_code_DC_DW.obj_kz.channelMask,
                          Flight_code_DC_B.pwmValue);
    Flight_code_DC_DW.obj_kz.errorStatus |= status;
  } else {
    status = pwm_disarm(&Flight_code_DC_DW.obj_kz.pwmDevHandler);
    Flight_code_DC_DW.obj_kz.errorStatus |= status;
    status = pwm_resetServo(&Flight_code_DC_DW.obj_kz.pwmDevHandler,
      Flight_code_DC_DW.obj_kz.servoCount, Flight_code_DC_DW.obj_kz.channelMask,
      Flight_code_DC_DW.obj_kz.isMain);
    Flight_code_DC_DW.obj_kz.errorStatus |= status;
  }

  if (Flight_code_DC_DW.obj_kz.isMain) {
    status = pwm_forceFailsafe(&Flight_code_DC_DW.obj_kz.pwmDevHandler,
      Flight_code_DC_P.Constant5_Value_c);
    Flight_code_DC_DW.obj_kz.errorStatus |= status;
  }

  // End of MATLABSystem: '<Root>/PX4 PWM Output'

  // BusAssignment: '<Root>/Bus Assignment' incorporates:
  //   Constant: '<Root>/Constant3'
  //   Constant: '<Root>/Constant4'
  //   Constant: '<S13>/Constant'
  //   DataTypeConversion: '<Root>/Data Type Conversion5'

  Flight_code_DC_B.BusAssignment = Flight_code_DC_P.Constant_Value_pi;
  Flight_code_DC_B.BusAssignment.color = (uint8_T)(int32_T)fmod((real_T)rtb_Mode,
    256.0);
  Flight_code_DC_B.BusAssignment.mode = Flight_code_DC_P.Constant3_Value_f;
  Flight_code_DC_B.BusAssignment.led_mask = Flight_code_DC_P.Constant4_Value_d;

  // MATLABSystem: '<S19>/SinkBlock'
  uORB_write_step(Flight_code_DC_DW.obj_oe.orbMetadataObj,
                  &Flight_code_DC_DW.obj_oe.orbAdvertiseObj,
                  &Flight_code_DC_B.BusAssignment);

  // RateTransition: '<S22>/Rate Transition2'
  if (Flight_code_DC_M->Timing.TaskCounters.TID[1] == 0) {
    Flight_code_DC_B.RateTransition2 =
      Flight_code_DC_B.In1_m.indicated_airspeed_m_s;

    // RateTransition: '<S22>/Rate Transition1'
    Flight_code_DC_B.RateTransition1 = Flight_code_DC_B.DataTypeConversion;
  }

  // End of RateTransition: '<S22>/Rate Transition2'

  // MATLABSystem: '<S31>/SourceBlock' incorporates:
  //   Inport: '<S33>/In1'

  rtb_Switch1 = uORB_read_step(Flight_code_DC_DW.obj_g.orbMetadataObj,
    &Flight_code_DC_DW.obj_g.eventStructObj, &Flight_code_DC_B.b_varargout_2,
    false, 1.0);

  // Outputs for Enabled SubSystem: '<S31>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S33>/Enable'

  if (rtb_Switch1) {
    Flight_code_DC_B.In1 = Flight_code_DC_B.b_varargout_2;
  }

  // End of MATLABSystem: '<S31>/SourceBlock'
  // End of Outputs for SubSystem: '<S31>/Enabled Subsystem'

  // RateTransition: '<S22>/Rate Transition'
  if (Flight_code_DC_M->Timing.TaskCounters.TID[1] == 0) {
    // MATLAB Function: '<S67>/Print'
    for (i = 0; i < 18; i++) {
      Flight_code_DC_B.b[i] = b[i];
    }

    printf(Flight_code_DC_B.b, Flight_code_DC_B.RateTransition2);
    for (i = 0; i < 25; i++) {
      Flight_code_DC_B.c[i] = c[i];
    }

    printf(Flight_code_DC_B.c, Flight_code_DC_B.RateTransition1);
    for (i = 0; i < 28; i++) {
      Flight_code_DC_B.d[i] = d[i];
    }

    printf(Flight_code_DC_B.d, Flight_code_DC_B.In1.beta_innov);

    // End of MATLAB Function: '<S67>/Print'
  }

  // End of RateTransition: '<S22>/Rate Transition'

  // MATLABSystem: '<S29>/SourceBlock'
  uORB_read_step(Flight_code_DC_DW.obj_p.orbMetadataObj,
                 &Flight_code_DC_DW.obj_p.eventStructObj,
                 &Flight_code_DC_B.b_varargout_2_k, false, 1.0);

  // MATLABSystem: '<S36>/SourceBlock'
  uORB_read_step(Flight_code_DC_DW.obj_h.orbMetadataObj,
                 &Flight_code_DC_DW.obj_h.eventStructObj,
                 &Flight_code_DC_B.b_varargout_2_cv, false, 1.0);

  // MATLABSystem: '<S51>/SourceBlock'
  uORB_read_step(Flight_code_DC_DW.obj_e.orbMetadataObj,
                 &Flight_code_DC_DW.obj_e.eventStructObj,
                 &Flight_code_DC_B.b_varargout_2_c, false, 1.0);

  // Product: '<S77>/Divide1' incorporates:
  //   Gain: '<S77>/Gain2'

  Flight_code_DC_B.Gain2 = Flight_code_DC_B.rtb_Sum2_tmp *
    (Flight_code_DC_P.Ki_Beta * Flight_code_DC_B.Gain_jg);

  // Switch: '<S88>/Switch4' incorporates:
  //   Constant: '<S88>/max deflection limit'
  //   Constant: '<S88>/max deflection limit '
  //   Constant: '<S88>/min deflection limit1'
  //   Constant: '<S89>/Constant'
  //   Constant: '<S91>/Constant'
  //   Logic: '<S88>/Logical Operator'
  //   Logic: '<S88>/Logical Operator4'
  //   RelationalOperator: '<S88>/Relational Operator'
  //   RelationalOperator: '<S88>/Relational Operator2'
  //   RelationalOperator: '<S89>/Compare'
  //   RelationalOperator: '<S91>/Compare'

  if (Flight_code_DC_P.mindeflectionlimit1_Value != 0.0) {
    rtb_Switch1 = ((Flight_code_DC_B.Sum2 >= Flight_code_DC_P.RUDDER_LIMITS) &&
                   (Flight_code_DC_B.Gain2 > Flight_code_DC_P.Constant_Value_e));
  } else {
    rtb_Switch1 = ((Flight_code_DC_B.Sum2 >= Flight_code_DC_P.RUDDER_LIMITS) &&
                   (Flight_code_DC_B.Gain2 < Flight_code_DC_P.Constant_Value_n));
  }

  // End of Switch: '<S88>/Switch4'

  // Switch: '<S88>/Switch1' incorporates:
  //   Constant: '<S88>/min deflection limit'
  //   Constant: '<S88>/min deflection limit '
  //   Constant: '<S88>/min deflection limit2'
  //   Constant: '<S90>/Constant'
  //   Constant: '<S92>/Constant'
  //   Logic: '<S88>/Logical Operator2'
  //   Logic: '<S88>/Logical Operator5'
  //   RelationalOperator: '<S88>/Relational Operator1'
  //   RelationalOperator: '<S88>/Relational Operator3'
  //   RelationalOperator: '<S90>/Compare'
  //   RelationalOperator: '<S92>/Compare'

  if (Flight_code_DC_P.mindeflectionlimit2_Value != 0.0) {
    tmp = ((Flight_code_DC_B.Sum2 <= -Flight_code_DC_P.RUDDER_LIMITS) &&
           (Flight_code_DC_B.Gain2 < Flight_code_DC_P.Constant_Value_ds));
  } else {
    tmp = ((Flight_code_DC_B.Sum2 <= -Flight_code_DC_P.RUDDER_LIMITS) &&
           (Flight_code_DC_B.Gain2 > Flight_code_DC_P.Constant_Value_d2));
  }

  // End of Switch: '<S88>/Switch1'

  // Product: '<S88>/Product' incorporates:
  //   Constant: '<S88>/max limit'
  //   Constant: '<S88>/min limit'
  //   DataTypeConversion: '<S88>/boolean2double'
  //   Logic: '<S88>/Logical Operator1'
  //   Logic: '<S88>/Logical Operator3'
  //   RelationalOperator: '<S88>/Relational Operator4'
  //   RelationalOperator: '<S88>/Relational Operator5'

  Flight_code_DC_B.Gain2 *= (real_T)(((Flight_code_DC_B.Sum2 <=
    Flight_code_DC_P.RUDDER_LIMITS) && (Flight_code_DC_B.Sum2 >=
    -Flight_code_DC_P.RUDDER_LIMITS)) || rtb_Switch1 || tmp);

  // Sum: '<S80>/Sum1' incorporates:
  //   DataTypeConversion: '<S80>/boolean2double5'
  //   Gain: '<S79>/Gain7'
  //   Sum: '<S123>/Sum1'

  Flight_code_DC_B.Gain = Flight_code_DC_P.VELOCITY_LIMITS *
    Flight_code_DC_B.Gain - Flight_code_DC_B.In1_k.vx;

  // Switch: '<S93>/Switch4' incorporates:
  //   Constant: '<S93>/max deflection limit'
  //   Constant: '<S93>/max deflection limit '
  //   Constant: '<S93>/min deflection limit1'
  //   Constant: '<S95>/Constant'
  //   Constant: '<S97>/Constant'
  //   Logic: '<S93>/Logical Operator'
  //   Logic: '<S93>/Logical Operator4'
  //   RelationalOperator: '<S93>/Relational Operator'
  //   RelationalOperator: '<S93>/Relational Operator2'
  //   RelationalOperator: '<S95>/Compare'
  //   RelationalOperator: '<S97>/Compare'
  //   Sum: '<S80>/Sum1'

  if (Flight_code_DC_P.mindeflectionlimit1_Value_i != 0.0) {
    rtb_Switch1 = ((Flight_code_DC_B.Throttle_out >=
                    Flight_code_DC_P.maxdeflectionlimit_Value_a) &&
                   (Flight_code_DC_B.Gain > Flight_code_DC_P.Constant_Value_op));
  } else {
    rtb_Switch1 = ((Flight_code_DC_B.Throttle_out >=
                    Flight_code_DC_P.maxdeflectionlimit_Value) &&
                   (Flight_code_DC_B.Gain < Flight_code_DC_P.Constant_Value_k));
  }

  // End of Switch: '<S93>/Switch4'

  // Switch: '<S93>/Switch1' incorporates:
  //   Constant: '<S93>/min deflection limit'
  //   Constant: '<S93>/min deflection limit '
  //   Constant: '<S93>/min deflection limit2'
  //   Constant: '<S96>/Constant'
  //   Constant: '<S98>/Constant'
  //   Logic: '<S93>/Logical Operator2'
  //   Logic: '<S93>/Logical Operator5'
  //   RelationalOperator: '<S93>/Relational Operator1'
  //   RelationalOperator: '<S93>/Relational Operator3'
  //   RelationalOperator: '<S96>/Compare'
  //   RelationalOperator: '<S98>/Compare'
  //   Sum: '<S80>/Sum1'

  if (Flight_code_DC_P.mindeflectionlimit2_Value_j != 0.0) {
    tmp = ((Flight_code_DC_B.Throttle_out <=
            Flight_code_DC_P.mindeflectionlimit_Value) && (Flight_code_DC_B.Gain
            < Flight_code_DC_P.Constant_Value_k3));
  } else {
    tmp = ((Flight_code_DC_B.Throttle_out <= -Flight_code_DC_P.ELEVATOR_LIMITS) &&
           (Flight_code_DC_B.Gain > Flight_code_DC_P.Constant_Value_fr));
  }

  // End of Switch: '<S93>/Switch1'

  // Sum: '<S80>/Sum2' incorporates:
  //   DataTypeConversion: '<S80>/boolean2double2'
  //   Gain: '<S79>/Gain4'
  //   Gain: '<S79>/Gain5'
  //   Sum: '<S123>/Sum2'

  Flight_code_DC_B.Delta2 = 1.0 / Flight_code_DC_P.ELEVATOR_LIMITS *
    Flight_code_DC_B.Delta2 * Flight_code_DC_P.W_LIMITS -
    Flight_code_DC_B.In1_k.vz;

  // Switch: '<S94>/Switch4' incorporates:
  //   Constant: '<S101>/Constant'
  //   Constant: '<S94>/max deflection limit'
  //   Constant: '<S94>/max deflection limit '
  //   Constant: '<S94>/min deflection limit1'
  //   Constant: '<S99>/Constant'
  //   Logic: '<S94>/Logical Operator'
  //   Logic: '<S94>/Logical Operator4'
  //   RelationalOperator: '<S101>/Compare'
  //   RelationalOperator: '<S94>/Relational Operator'
  //   RelationalOperator: '<S94>/Relational Operator2'
  //   RelationalOperator: '<S99>/Compare'
  //   Sum: '<S80>/Sum2'

  if (Flight_code_DC_P.mindeflectionlimit1_Value_j != 0.0) {
    tmp_0 = ((Flight_code_DC_B.Dif_L >= Flight_code_DC_P.ELEVATOR_LIMITS) &&
             (Flight_code_DC_B.Delta2 > Flight_code_DC_P.Constant_Value_jc));
  } else {
    tmp_0 = ((Flight_code_DC_B.Dif_L >= Flight_code_DC_P.ELEVATOR_LIMITS) &&
             (Flight_code_DC_B.Delta2 < Flight_code_DC_P.Constant_Value_pb));
  }

  // End of Switch: '<S94>/Switch4'

  // Switch: '<S94>/Switch1' incorporates:
  //   Constant: '<S100>/Constant'
  //   Constant: '<S102>/Constant'
  //   Constant: '<S94>/min deflection limit'
  //   Constant: '<S94>/min deflection limit '
  //   Constant: '<S94>/min deflection limit2'
  //   Logic: '<S94>/Logical Operator2'
  //   Logic: '<S94>/Logical Operator5'
  //   RelationalOperator: '<S100>/Compare'
  //   RelationalOperator: '<S102>/Compare'
  //   RelationalOperator: '<S94>/Relational Operator1'
  //   RelationalOperator: '<S94>/Relational Operator3'
  //   Sum: '<S80>/Sum2'

  if (Flight_code_DC_P.mindeflectionlimit2_Value_d != 0.0) {
    tmp_1 = ((Flight_code_DC_B.Dif_L <= -Flight_code_DC_P.ELEVATOR_LIMITS) &&
             (Flight_code_DC_B.Delta2 < Flight_code_DC_P.Constant_Value_ny));
  } else {
    tmp_1 = ((Flight_code_DC_B.Dif_L <= -Flight_code_DC_P.ELEVATOR_LIMITS) &&
             (Flight_code_DC_B.Delta2 > Flight_code_DC_P.Constant_Value_ir));
  }

  // End of Switch: '<S94>/Switch1'

  // Product: '<S104>/Divide2' incorporates:
  //   Gain: '<S104>/Gain2'

  Flight_code_DC_B.Dif_R *= Flight_code_DC_P.Ki_p * Flight_code_DC_B.Divide1_l;

  // Switch: '<S103>/Switch4' incorporates:
  //   Constant: '<S103>/max deflection limit'
  //   Constant: '<S103>/max deflection limit '
  //   Constant: '<S103>/min deflection limit1'
  //   Constant: '<S105>/Constant'
  //   Constant: '<S107>/Constant'
  //   Logic: '<S103>/Logical Operator'
  //   Logic: '<S103>/Logical Operator4'
  //   RelationalOperator: '<S103>/Relational Operator'
  //   RelationalOperator: '<S103>/Relational Operator2'
  //   RelationalOperator: '<S105>/Compare'
  //   RelationalOperator: '<S107>/Compare'

  if (Flight_code_DC_P.mindeflectionlimit1_Value_h != 0.0) {
    tmp_2 = ((Flight_code_DC_B.Sum1 >= Flight_code_DC_P.AILERON_LIMITS) &&
             (Flight_code_DC_B.Dif_R > Flight_code_DC_P.Constant_Value_mh));
  } else {
    tmp_2 = ((Flight_code_DC_B.Sum1 >= Flight_code_DC_P.AILERON_LIMITS) &&
             (Flight_code_DC_B.Dif_R < Flight_code_DC_P.Constant_Value_e1));
  }

  // End of Switch: '<S103>/Switch4'

  // Switch: '<S103>/Switch1' incorporates:
  //   Constant: '<S103>/min deflection limit'
  //   Constant: '<S103>/min deflection limit '
  //   Constant: '<S103>/min deflection limit2'
  //   Constant: '<S106>/Constant'
  //   Constant: '<S108>/Constant'
  //   Logic: '<S103>/Logical Operator2'
  //   Logic: '<S103>/Logical Operator5'
  //   RelationalOperator: '<S103>/Relational Operator1'
  //   RelationalOperator: '<S103>/Relational Operator3'
  //   RelationalOperator: '<S106>/Compare'
  //   RelationalOperator: '<S108>/Compare'

  if (Flight_code_DC_P.mindeflectionlimit2_Value_n != 0.0) {
    tmp_3 = ((Flight_code_DC_B.Sum1 <= -Flight_code_DC_P.AILERON_LIMITS) &&
             (Flight_code_DC_B.Dif_R < Flight_code_DC_P.Constant_Value_a));
  } else {
    tmp_3 = ((Flight_code_DC_B.Sum1 <= -Flight_code_DC_P.AILERON_LIMITS) &&
             (Flight_code_DC_B.Dif_R > Flight_code_DC_P.Constant_Value_kj));
  }

  // End of Switch: '<S103>/Switch1'

  // Product: '<S103>/Product' incorporates:
  //   Constant: '<S103>/max limit'
  //   Constant: '<S103>/min limit'
  //   DataTypeConversion: '<S103>/boolean2double'
  //   Logic: '<S103>/Logical Operator1'
  //   Logic: '<S103>/Logical Operator3'
  //   RelationalOperator: '<S103>/Relational Operator4'
  //   RelationalOperator: '<S103>/Relational Operator5'

  Flight_code_DC_B.Dif_R *= (real_T)(((Flight_code_DC_B.Sum1 <=
    Flight_code_DC_P.AILERON_LIMITS) && (Flight_code_DC_B.Sum1 >=
    -Flight_code_DC_P.AILERON_LIMITS)) || tmp_2 || tmp_3);

  // Product: '<S120>/Divide1' incorporates:
  //   Constant: '<S120>/Constant'
  //   Constant: '<S27>/Airspeed3'
  //   Gain: '<S120>/Gain2'
  //   Product: '<S120>/Divide'

  Flight_code_DC_B.Divide1_l = 1.0 / Flight_code_DC_P.Airspeed3_Value *
    Flight_code_DC_P.REF_SPEED * (Flight_code_DC_P.Ki_Beta *
    Flight_code_DC_B.Gain_j);

  // Switch: '<S131>/Switch4' incorporates:
  //   Constant: '<S131>/max deflection limit'
  //   Constant: '<S131>/max deflection limit '
  //   Constant: '<S131>/min deflection limit1'
  //   Constant: '<S132>/Constant'
  //   Constant: '<S134>/Constant'
  //   Logic: '<S131>/Logical Operator'
  //   Logic: '<S131>/Logical Operator4'
  //   RelationalOperator: '<S131>/Relational Operator'
  //   RelationalOperator: '<S131>/Relational Operator2'
  //   RelationalOperator: '<S132>/Compare'
  //   RelationalOperator: '<S134>/Compare'

  if (Flight_code_DC_P.mindeflectionlimit1_Value_a != 0.0) {
    tmp_2 = ((Flight_code_DC_B.Sum_o >= Flight_code_DC_P.RUDDER_LIMITS) &&
             (Flight_code_DC_B.Divide1_l > Flight_code_DC_P.Constant_Value_cs));
  } else {
    tmp_2 = ((Flight_code_DC_B.Sum_o >= Flight_code_DC_P.RUDDER_LIMITS) &&
             (Flight_code_DC_B.Divide1_l < Flight_code_DC_P.Constant_Value_mn));
  }

  // End of Switch: '<S131>/Switch4'

  // Switch: '<S131>/Switch1' incorporates:
  //   Constant: '<S131>/min deflection limit'
  //   Constant: '<S131>/min deflection limit '
  //   Constant: '<S131>/min deflection limit2'
  //   Constant: '<S133>/Constant'
  //   Constant: '<S135>/Constant'
  //   Logic: '<S131>/Logical Operator2'
  //   Logic: '<S131>/Logical Operator5'
  //   RelationalOperator: '<S131>/Relational Operator1'
  //   RelationalOperator: '<S131>/Relational Operator3'
  //   RelationalOperator: '<S133>/Compare'
  //   RelationalOperator: '<S135>/Compare'

  if (Flight_code_DC_P.mindeflectionlimit2_Value_l != 0.0) {
    tmp_3 = ((Flight_code_DC_B.Sum_o <= -Flight_code_DC_P.RUDDER_LIMITS) &&
             (Flight_code_DC_B.Divide1_l < Flight_code_DC_P.Constant_Value_ab));
  } else {
    tmp_3 = ((Flight_code_DC_B.Sum_o <= -Flight_code_DC_P.RUDDER_LIMITS) &&
             (Flight_code_DC_B.Divide1_l > Flight_code_DC_P.Constant_Value_ct));
  }

  // End of Switch: '<S131>/Switch1'

  // Product: '<S131>/Product' incorporates:
  //   Constant: '<S131>/max limit'
  //   Constant: '<S131>/min limit'
  //   DataTypeConversion: '<S131>/boolean2double'
  //   Logic: '<S131>/Logical Operator1'
  //   Logic: '<S131>/Logical Operator3'
  //   RelationalOperator: '<S131>/Relational Operator4'
  //   RelationalOperator: '<S131>/Relational Operator5'

  Flight_code_DC_B.Divide1_l *= (real_T)(((Flight_code_DC_B.Sum_o <=
    Flight_code_DC_P.RUDDER_LIMITS) && (Flight_code_DC_B.Sum_o >=
    -Flight_code_DC_P.RUDDER_LIMITS)) || tmp_2 || tmp_3);

  // Switch: '<S136>/Switch4' incorporates:
  //   Constant: '<S136>/max deflection limit'
  //   Constant: '<S136>/max deflection limit '
  //   Constant: '<S136>/min deflection limit1'
  //   Constant: '<S138>/Constant'
  //   Constant: '<S140>/Constant'
  //   Logic: '<S136>/Logical Operator'
  //   Logic: '<S136>/Logical Operator4'
  //   RelationalOperator: '<S136>/Relational Operator'
  //   RelationalOperator: '<S136>/Relational Operator2'
  //   RelationalOperator: '<S138>/Compare'
  //   RelationalOperator: '<S140>/Compare'

  if (Flight_code_DC_P.mindeflectionlimit1_Value_ae != 0.0) {
    tmp_2 = ((Flight_code_DC_B.rtb_Sum_i_idx_0 >=
              Flight_code_DC_P.maxdeflectionlimit_Value_f) &&
             (Flight_code_DC_B.Gain > Flight_code_DC_P.Constant_Value_jm));
  } else {
    tmp_2 = ((Flight_code_DC_B.rtb_Sum_i_idx_0 >=
              Flight_code_DC_P.maxdeflectionlimit_Value_n) &&
             (Flight_code_DC_B.Gain < Flight_code_DC_P.Constant_Value_cs0));
  }

  // End of Switch: '<S136>/Switch4'

  // Switch: '<S136>/Switch1' incorporates:
  //   Constant: '<S136>/min deflection limit'
  //   Constant: '<S136>/min deflection limit '
  //   Constant: '<S136>/min deflection limit2'
  //   Constant: '<S139>/Constant'
  //   Constant: '<S141>/Constant'
  //   Logic: '<S136>/Logical Operator2'
  //   Logic: '<S136>/Logical Operator5'
  //   RelationalOperator: '<S136>/Relational Operator1'
  //   RelationalOperator: '<S136>/Relational Operator3'
  //   RelationalOperator: '<S139>/Compare'
  //   RelationalOperator: '<S141>/Compare'

  if (Flight_code_DC_P.mindeflectionlimit2_Value_lp != 0.0) {
    tmp_3 = ((Flight_code_DC_B.rtb_Sum_i_idx_0 <=
              Flight_code_DC_P.mindeflectionlimit_Value_f) &&
             (Flight_code_DC_B.Gain < Flight_code_DC_P.Constant_Value_of));
  } else {
    tmp_3 = ((Flight_code_DC_B.rtb_Sum_i_idx_0 <=
              -Flight_code_DC_P.ELEVATOR_LIMITS) && (Flight_code_DC_B.Gain >
              Flight_code_DC_P.Constant_Value_nx));
  }

  // End of Switch: '<S136>/Switch1'

  // Switch: '<S137>/Switch4' incorporates:
  //   Constant: '<S137>/max deflection limit'
  //   Constant: '<S137>/max deflection limit '
  //   Constant: '<S137>/min deflection limit1'
  //   Constant: '<S142>/Constant'
  //   Constant: '<S144>/Constant'
  //   Logic: '<S137>/Logical Operator'
  //   Logic: '<S137>/Logical Operator4'
  //   RelationalOperator: '<S137>/Relational Operator'
  //   RelationalOperator: '<S137>/Relational Operator2'
  //   RelationalOperator: '<S142>/Compare'
  //   RelationalOperator: '<S144>/Compare'

  if (Flight_code_DC_P.mindeflectionlimit1_Value_o != 0.0) {
    tmp_4 = ((Flight_code_DC_B.rtb_Sum_i_idx_1 >=
              Flight_code_DC_P.ELEVATOR_LIMITS) && (Flight_code_DC_B.Delta2 >
              Flight_code_DC_P.Constant_Value_ac));
  } else {
    tmp_4 = ((Flight_code_DC_B.rtb_Sum_i_idx_1 >=
              Flight_code_DC_P.ELEVATOR_LIMITS) && (Flight_code_DC_B.Delta2 <
              Flight_code_DC_P.Constant_Value_om));
  }

  // End of Switch: '<S137>/Switch4'

  // Switch: '<S137>/Switch1' incorporates:
  //   Constant: '<S137>/min deflection limit'
  //   Constant: '<S137>/min deflection limit '
  //   Constant: '<S137>/min deflection limit2'
  //   Constant: '<S143>/Constant'
  //   Constant: '<S145>/Constant'
  //   Logic: '<S137>/Logical Operator2'
  //   Logic: '<S137>/Logical Operator5'
  //   RelationalOperator: '<S137>/Relational Operator1'
  //   RelationalOperator: '<S137>/Relational Operator3'
  //   RelationalOperator: '<S143>/Compare'
  //   RelationalOperator: '<S145>/Compare'

  if (Flight_code_DC_P.mindeflectionlimit2_Value_g != 0.0) {
    tmp_5 = ((Flight_code_DC_B.rtb_Sum_i_idx_1 <=
              -Flight_code_DC_P.ELEVATOR_LIMITS) && (Flight_code_DC_B.Delta2 <
              Flight_code_DC_P.Constant_Value_af));
  } else {
    tmp_5 = ((Flight_code_DC_B.rtb_Sum_i_idx_1 <=
              -Flight_code_DC_P.ELEVATOR_LIMITS) && (Flight_code_DC_B.Delta2 >
              Flight_code_DC_P.Constant_Value_fo));
  }

  // End of Switch: '<S137>/Switch1'

  // Product: '<S147>/Divide2' incorporates:
  //   Gain: '<S147>/Gain2'

  Flight_code_DC_B.Excess *= Flight_code_DC_P.Ki_p * Flight_code_DC_B.Divide1_a;

  // Update for Memory: '<S79>/Memory'
  Flight_code_DC_DW.Memory_PreviousInput = rtb_Mode;

  // Update for DiscreteIntegrator: '<S93>/Discrete-Time Integrator' incorporates:
  //   Constant: '<S93>/max limit'
  //   Constant: '<S93>/min limit'
  //   DataTypeConversion: '<S93>/boolean2double'
  //   Logic: '<S93>/Logical Operator1'
  //   Logic: '<S93>/Logical Operator3'
  //   Product: '<S93>/Product'
  //   RelationalOperator: '<S93>/Relational Operator4'
  //   RelationalOperator: '<S93>/Relational Operator5'
  //   Sum: '<S80>/Sum1'

  Flight_code_DC_DW.DiscreteTimeIntegrator_DSTATE +=
    Flight_code_DC_P.DiscreteTimeIntegrator_gainval * ((real_T)
    (((Flight_code_DC_B.Throttle_out <= Flight_code_DC_P.maxlimit_Value) &&
      (Flight_code_DC_B.Throttle_out >= Flight_code_DC_P.minlimit_Value)) ||
     rtb_Switch1 || tmp) * Flight_code_DC_B.Gain);
  Flight_code_DC_DW.DiscreteTimeIntegrator_PrevRese = (int8_T)rtb_Mode_change;

  // Update for DiscreteIntegrator: '<S94>/Discrete-Time Integrator' incorporates:
  //   Constant: '<S94>/max limit'
  //   Constant: '<S94>/min limit'
  //   DataTypeConversion: '<S94>/boolean2double'
  //   Logic: '<S94>/Logical Operator1'
  //   Logic: '<S94>/Logical Operator3'
  //   Product: '<S94>/Product'
  //   RelationalOperator: '<S94>/Relational Operator4'
  //   RelationalOperator: '<S94>/Relational Operator5'
  //   Sum: '<S80>/Sum2'

  Flight_code_DC_DW.DiscreteTimeIntegrator_DSTATE_a +=
    Flight_code_DC_P.DiscreteTimeIntegrator_gainva_n * ((real_T)
    (((Flight_code_DC_B.Dif_L <= Flight_code_DC_P.ELEVATOR_LIMITS) &&
      (Flight_code_DC_B.Dif_L >= -Flight_code_DC_P.ELEVATOR_LIMITS)) || tmp_0 ||
     tmp_1) * Flight_code_DC_B.Delta2);
  Flight_code_DC_DW.DiscreteTimeIntegrator_PrevRe_p = (int8_T)rtb_Mode_change;

  // Update for DiscreteIntegrator: '<S103>/Discrete-Time Integrator'
  Flight_code_DC_DW.DiscreteTimeIntegrator_IC_LOADI = 0U;
  Flight_code_DC_DW.DiscreteTimeIntegrator_DSTATE_f +=
    Flight_code_DC_P.DiscreteTimeIntegrator_gainva_o * Flight_code_DC_B.Dif_R;
  Flight_code_DC_DW.DiscreteTimeIntegrator_PrevR_p5 = (int8_T)rtb_Mode_change;

  // Update for DiscreteIntegrator: '<S88>/Discrete-Time Integrator'
  Flight_code_DC_DW.DiscreteTimeIntegrator_IC_LOA_e = 0U;
  Flight_code_DC_DW.DiscreteTimeIntegrator_DSTATE_l +=
    Flight_code_DC_P.DiscreteTimeIntegrator_gainva_k * Flight_code_DC_B.Gain2;
  Flight_code_DC_DW.DiscreteTimeIntegrator_PrevRe_c = (int8_T)rtb_Mode_change;

  // Update for Memory: '<S86>/Memory' incorporates:
  //   DiscreteIntegrator: '<S114>/Discrete-Time Integrator'

  Flight_code_DC_DW.Memory_PreviousInput_l =
    Flight_code_DC_DW.DiscreteTimeIntegrator_DSTATE_n;

  // Update for DiscreteIntegrator: '<S114>/Discrete-Time Integrator'
  Flight_code_DC_DW.DiscreteTimeIntegrator_IC_LOA_k = 0U;

  // Gain: '<S114>/Gain4' incorporates:
  //   Gain: '<S157>/Gain4'

  rtb_Gain4_f = Flight_code_DC_P.K_d_b * Flight_code_DC_B.In1_l.yawspeed;

  // Update for DiscreteIntegrator: '<S114>/Discrete-Time Integrator' incorporates:
  //   Gain: '<S114>/Gain4'
  //   Gain: '<S114>/Gain5'
  //   Sum: '<S114>/Sum2'

  Flight_code_DC_DW.DiscreteTimeIntegrator_DSTATE_n += ((0.0F -
    Flight_code_DC_P.K_d_b * Flight_code_DC_DW.DiscreteTimeIntegrator_DSTATE_n)
    - rtb_Gain4_f) * Flight_code_DC_P.DiscreteTimeIntegrator_gainva_f;
  Flight_code_DC_DW.DiscreteTimeIntegrator_PrevRe_o = (int8_T)rtb_Mode_change;

  // Update for Memory: '<S122>/Memory'
  Flight_code_DC_DW.Memory_PreviousInput_o = rtb_Mode;

  // Update for DiscreteIntegrator: '<S136>/Discrete-Time Integrator' incorporates:
  //   Constant: '<S136>/max limit'
  //   Constant: '<S136>/min limit'
  //   DataTypeConversion: '<S136>/boolean2double'
  //   Logic: '<S136>/Logical Operator1'
  //   Logic: '<S136>/Logical Operator3'
  //   Product: '<S136>/Product'
  //   RelationalOperator: '<S136>/Relational Operator4'
  //   RelationalOperator: '<S136>/Relational Operator5'

  Flight_code_DC_DW.DiscreteTimeIntegrator_DSTATE_j +=
    Flight_code_DC_P.DiscreteTimeIntegrator_gainva_b * ((real_T)
    (((Flight_code_DC_B.rtb_Sum_i_idx_0 <= Flight_code_DC_P.maxlimit_Value_m) &&
      (Flight_code_DC_B.rtb_Sum_i_idx_0 >= Flight_code_DC_P.minlimit_Value_d)) ||
     tmp_2 || tmp_3) * Flight_code_DC_B.Gain);
  Flight_code_DC_DW.DiscreteTimeIntegrator_PrevRe_d = (int8_T)rtb_Mode_change_e;

  // Update for DiscreteIntegrator: '<S137>/Discrete-Time Integrator' incorporates:
  //   Constant: '<S137>/max limit'
  //   Constant: '<S137>/min limit'
  //   DataTypeConversion: '<S137>/boolean2double'
  //   Logic: '<S137>/Logical Operator1'
  //   Logic: '<S137>/Logical Operator3'
  //   Product: '<S137>/Product'
  //   RelationalOperator: '<S137>/Relational Operator4'
  //   RelationalOperator: '<S137>/Relational Operator5'

  Flight_code_DC_DW.DiscreteTimeIntegrator_DSTATE_k +=
    Flight_code_DC_P.DiscreteTimeIntegrator_gainva_m * ((real_T)
    (((Flight_code_DC_B.rtb_Sum_i_idx_1 <= Flight_code_DC_P.ELEVATOR_LIMITS) &&
      (Flight_code_DC_B.rtb_Sum_i_idx_1 >= -Flight_code_DC_P.ELEVATOR_LIMITS)) ||
     tmp_4 || tmp_5) * Flight_code_DC_B.Delta2);
  Flight_code_DC_DW.DiscreteTimeIntegrator_PrevRe_h = (int8_T)rtb_Mode_change_e;

  // Update for DiscreteIntegrator: '<S146>/Discrete-Time Integrator'
  Flight_code_DC_DW.DiscreteTimeIntegrator_IC_LO_e2 = 0U;

  // Switch: '<S146>/Switch4' incorporates:
  //   Constant: '<S146>/max deflection limit'
  //   Constant: '<S146>/max deflection limit '
  //   Constant: '<S146>/min deflection limit1'
  //   Constant: '<S148>/Constant'
  //   Constant: '<S150>/Constant'
  //   Logic: '<S146>/Logical Operator'
  //   Logic: '<S146>/Logical Operator4'
  //   RelationalOperator: '<S146>/Relational Operator'
  //   RelationalOperator: '<S146>/Relational Operator2'
  //   RelationalOperator: '<S148>/Compare'
  //   RelationalOperator: '<S150>/Compare'

  if (Flight_code_DC_P.mindeflectionlimit1_Value_hb != 0.0) {
    rtb_Switch1 = ((Flight_code_DC_B.Sum_l >= Flight_code_DC_P.AILERON_LIMITS) &&
                   (Flight_code_DC_B.Excess > Flight_code_DC_P.Constant_Value_jl));
  } else {
    rtb_Switch1 = ((Flight_code_DC_B.Sum_l >= Flight_code_DC_P.AILERON_LIMITS) &&
                   (Flight_code_DC_B.Excess < Flight_code_DC_P.Constant_Value_gw));
  }

  // End of Switch: '<S146>/Switch4'

  // Switch: '<S146>/Switch1' incorporates:
  //   Constant: '<S146>/min deflection limit'
  //   Constant: '<S146>/min deflection limit '
  //   Constant: '<S146>/min deflection limit2'
  //   Constant: '<S149>/Constant'
  //   Constant: '<S151>/Constant'
  //   Logic: '<S146>/Logical Operator2'
  //   Logic: '<S146>/Logical Operator5'
  //   RelationalOperator: '<S146>/Relational Operator1'
  //   RelationalOperator: '<S146>/Relational Operator3'
  //   RelationalOperator: '<S149>/Compare'
  //   RelationalOperator: '<S151>/Compare'

  if (Flight_code_DC_P.mindeflectionlimit2_Value_c != 0.0) {
    tmp = ((Flight_code_DC_B.Sum_l <= -Flight_code_DC_P.AILERON_LIMITS) &&
           (Flight_code_DC_B.Excess < Flight_code_DC_P.Constant_Value_jj));
  } else {
    tmp = ((Flight_code_DC_B.Sum_l <= -Flight_code_DC_P.AILERON_LIMITS) &&
           (Flight_code_DC_B.Excess > Flight_code_DC_P.Constant_Value_h));
  }

  // End of Switch: '<S146>/Switch1'

  // Update for DiscreteIntegrator: '<S146>/Discrete-Time Integrator' incorporates:
  //   Constant: '<S146>/max limit'
  //   Constant: '<S146>/min limit'
  //   DataTypeConversion: '<S146>/boolean2double'
  //   Logic: '<S146>/Logical Operator1'
  //   Logic: '<S146>/Logical Operator3'
  //   Product: '<S146>/Product'
  //   RelationalOperator: '<S146>/Relational Operator4'
  //   RelationalOperator: '<S146>/Relational Operator5'

  Flight_code_DC_DW.DiscreteTimeIntegrator_DSTAT_fn += (real_T)
    (((Flight_code_DC_B.Sum_l <= Flight_code_DC_P.AILERON_LIMITS) &&
      (Flight_code_DC_B.Sum_l >= -Flight_code_DC_P.AILERON_LIMITS)) ||
     rtb_Switch1 || tmp) * Flight_code_DC_B.Excess *
    Flight_code_DC_P.DiscreteTimeIntegrator_gainv_kd;
  Flight_code_DC_DW.DiscreteTimeIntegrator_PrevR_d5 = (int8_T)rtb_Mode_change_e;

  // Update for DiscreteIntegrator: '<S131>/Discrete-Time Integrator'
  Flight_code_DC_DW.DiscreteTimeIntegrator_IC_LOA_c = 0U;
  Flight_code_DC_DW.DiscreteTimeIntegrator_DSTATE_e +=
    Flight_code_DC_P.DiscreteTimeIntegrator_gainv_nl *
    Flight_code_DC_B.Divide1_l;
  Flight_code_DC_DW.DiscreteTimeIntegrator_PrevR_d4 = (int8_T)rtb_Mode_change_e;

  // Update for Memory: '<S129>/Memory' incorporates:
  //   DiscreteIntegrator: '<S157>/Discrete-Time Integrator'

  Flight_code_DC_DW.Memory_PreviousInput_l2 =
    Flight_code_DC_DW.DiscreteTimeIntegrator_DSTAT_kf;

  // Update for DiscreteIntegrator: '<S157>/Discrete-Time Integrator' incorporates:
  //   Gain: '<S157>/Gain5'
  //   Sum: '<S157>/Sum2'

  Flight_code_DC_DW.DiscreteTimeIntegrator_IC_LOA_h = 0U;
  Flight_code_DC_DW.DiscreteTimeIntegrator_DSTAT_kf += ((0.0F -
    Flight_code_DC_P.K_d_b * Flight_code_DC_DW.DiscreteTimeIntegrator_DSTAT_kf)
    - rtb_Gain4_f) * Flight_code_DC_P.DiscreteTimeIntegrator_gainva_i;
  Flight_code_DC_DW.DiscreteTimeIntegrator_PrevRe_f = (int8_T)rtb_Mode_change_e;
  rate_scheduler();
}

// Model initialize function
void Flight_code_DC_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  // initialize real-time model
  (void) memset((void *)Flight_code_DC_M, 0,
                sizeof(RT_MODEL_Flight_code_DC_T));

  // block I/O
  (void) memset(((void *) &Flight_code_DC_B), 0,
                sizeof(B_Flight_code_DC_T));

  // states (dwork)
  (void) memset((void *)&Flight_code_DC_DW, 0,
                sizeof(DW_Flight_code_DC_T));

  {
    px4_Bus_led_control rtb_BusAssignment;
    real_T Constant1_k;
    real_T Constant_c;
    real_T Constant1;
    real_T Constant;

    // Start for MATLABSystem: '<S69>/SourceBlock'
    Flight_code_DC_DW.obj_d.matlabCodegenIsDeleted = true;
    Flight_code_DC_DW.obj_d.isInitialized = 0;
    Flight_code_DC_DW.obj_d.ticksUntilNextHit = 0.0;
    Flight_code_DC_DW.obj_d.matlabCodegenIsDeleted = false;
    Flight_code_DC_DW.obj_d.isSetupComplete = false;
    Flight_code_DC_DW.obj_d.isInitialized = 1;
    Flight_code_DC_DW.obj_d.orbMetadataObj = ORB_ID(input_rc);
    uORB_read_initialize(Flight_code_DC_DW.obj_d.orbMetadataObj,
                         &Flight_code_DC_DW.obj_d.eventStructObj, 10.0);
    Flight_code_DC_DW.obj_d.isSetupComplete = true;

    // Start for MATLABSystem: '<S163>/SourceBlock'
    Flight_code_DC_DW.obj.matlabCodegenIsDeleted = true;
    Flight_code_DC_DW.obj.isInitialized = 0;
    Flight_code_DC_DW.obj.ticksUntilNextHit = 0.0;
    Flight_code_DC_DW.obj.matlabCodegenIsDeleted = false;
    Flight_code_DC_DW.obj.isSetupComplete = false;
    Flight_code_DC_DW.obj.isInitialized = 1;
    Flight_code_DC_DW.obj.orbMetadataObj = ORB_ID(vehicle_air_data);
    uORB_read_initialize(Flight_code_DC_DW.obj.orbMetadataObj,
                         &Flight_code_DC_DW.obj.eventStructObj, 10.0);
    Flight_code_DC_DW.obj.isSetupComplete = true;

    // Start for MATLABSystem: '<S34>/SourceBlock'
    Flight_code_DC_DW.obj_n.matlabCodegenIsDeleted = true;
    Flight_code_DC_DW.obj_n.isInitialized = 0;
    Flight_code_DC_DW.obj_n.ticksUntilNextHit = 0.0;
    Flight_code_DC_DW.obj_n.matlabCodegenIsDeleted = false;
    Flight_code_DC_DW.obj_n.isSetupComplete = false;
    Flight_code_DC_DW.obj_n.isInitialized = 1;
    Flight_code_DC_DW.obj_n.orbMetadataObj = ORB_ID(airspeed);
    uORB_read_initialize(Flight_code_DC_DW.obj_n.orbMetadataObj,
                         &Flight_code_DC_DW.obj_n.eventStructObj, 10.0);
    Flight_code_DC_DW.obj_n.isSetupComplete = true;

    // Start for MATLABSystem: '<S35>/SourceBlock'
    Flight_code_DC_DW.obj_k.matlabCodegenIsDeleted = true;
    Flight_code_DC_DW.obj_k.isInitialized = 0;
    Flight_code_DC_DW.obj_k.ticksUntilNextHit = 0.0;
    Flight_code_DC_DW.obj_k.matlabCodegenIsDeleted = false;
    Flight_code_DC_DW.obj_k.isSetupComplete = false;
    Flight_code_DC_DW.obj_k.isInitialized = 1;
    Flight_code_DC_DW.obj_k.orbMetadataObj = ORB_ID(differential_pressure_ms);
    uORB_read_initialize(Flight_code_DC_DW.obj_k.orbMetadataObj,
                         &Flight_code_DC_DW.obj_k.eventStructObj, 10.0);
    Flight_code_DC_DW.obj_k.isSetupComplete = true;

    // Start for MATLABSystem: '<S43>/SourceBlock'
    Flight_code_DC_DW.obj_i.matlabCodegenIsDeleted = true;
    Flight_code_DC_DW.obj_i.isInitialized = 0;
    Flight_code_DC_DW.obj_i.ticksUntilNextHit = 0.0;
    Flight_code_DC_DW.obj_i.matlabCodegenIsDeleted = false;
    Flight_code_DC_DW.obj_i.isSetupComplete = false;
    Flight_code_DC_DW.obj_i.isInitialized = 1;
    Flight_code_DC_DW.obj_i.orbMetadataObj = ORB_ID(vehicle_attitude);
    uORB_read_initialize(Flight_code_DC_DW.obj_i.orbMetadataObj,
                         &Flight_code_DC_DW.obj_i.eventStructObj, 10.0);
    Flight_code_DC_DW.obj_i.isSetupComplete = true;

    // Start for MATLABSystem: '<S50>/SourceBlock'
    Flight_code_DC_DW.obj_o.matlabCodegenIsDeleted = true;
    Flight_code_DC_DW.obj_o.isInitialized = 0;
    Flight_code_DC_DW.obj_o.ticksUntilNextHit = 0.0;
    Flight_code_DC_DW.obj_o.matlabCodegenIsDeleted = false;
    Flight_code_DC_DW.obj_o.isSetupComplete = false;
    Flight_code_DC_DW.obj_o.isInitialized = 1;
    Flight_code_DC_DW.obj_o.orbMetadataObj = ORB_ID(vehicle_local_position);
    uORB_read_initialize(Flight_code_DC_DW.obj_o.orbMetadataObj,
                         &Flight_code_DC_DW.obj_o.eventStructObj, 10.0);
    Flight_code_DC_DW.obj_o.isSetupComplete = true;

    // Start for Constant: '<S80>/Constant'
    Constant = Flight_code_DC_P.Constant_Value_g;

    // Start for Constant: '<S80>/Constant1'
    Constant1 = Flight_code_DC_P.Constant1_Value_h;

    // Start for Constant: '<S123>/Constant'
    Constant_c = Flight_code_DC_P.Constant_Value_lq;

    // Start for Constant: '<S123>/Constant1'
    Constant1_k = Flight_code_DC_P.Constant1_Value_g;

    // Start for MATLABSystem: '<Root>/PX4 PWM Output' incorporates:
    //   Constant: '<Root>/Constant'
    //   Constant: '<Root>/Constant5'

    Flight_code_DC_DW.obj_kz.matlabCodegenIsDeleted = true;
    Flight_code_DC_DW.obj_kz.errorStatus = 0U;
    Flight_code_DC_DW.obj_kz.isInitialized = 0;
    Flight_code_DC_DW.obj_kz.matlabCodegenIsDeleted = false;
    Flight_code_DC_SystemCore_setup(&Flight_code_DC_DW.obj_kz,
      Flight_code_DC_P.Constant_Value_ig, Flight_code_DC_P.Constant5_Value_c);

    // Start for MATLABSystem: '<S19>/SinkBlock'
    Flight_code_DC_DW.obj_oe.matlabCodegenIsDeleted = true;
    Flight_code_DC_DW.obj_oe.isInitialized = 0;
    Flight_code_DC_DW.obj_oe.matlabCodegenIsDeleted = false;
    Flight_code_DC_DW.obj_oe.isSetupComplete = false;
    Flight_code_DC_DW.obj_oe.isInitialized = 1;
    Flight_code_DC_DW.obj_oe.orbMetadataObj = ORB_ID(led_control);
    uORB_write_initialize(Flight_code_DC_DW.obj_oe.orbMetadataObj,
                          &Flight_code_DC_DW.obj_oe.orbAdvertiseObj,
                          &rtb_BusAssignment, 1);
    Flight_code_DC_DW.obj_oe.isSetupComplete = true;

    // Start for MATLABSystem: '<S31>/SourceBlock'
    Flight_code_DC_DW.obj_g.matlabCodegenIsDeleted = true;
    Flight_code_DC_DW.obj_g.isInitialized = 0;
    Flight_code_DC_DW.obj_g.ticksUntilNextHit = 0.0;
    Flight_code_DC_DW.obj_g.matlabCodegenIsDeleted = false;
    Flight_code_DC_DW.obj_g.isSetupComplete = false;
    Flight_code_DC_DW.obj_g.isInitialized = 1;
    Flight_code_DC_DW.obj_g.orbMetadataObj = ORB_ID(ekf2_innovations);
    uORB_read_initialize(Flight_code_DC_DW.obj_g.orbMetadataObj,
                         &Flight_code_DC_DW.obj_g.eventStructObj, 10.0);
    Flight_code_DC_DW.obj_g.isSetupComplete = true;

    // Start for MATLABSystem: '<S29>/SourceBlock'
    Flight_code_DC_DW.obj_p.matlabCodegenIsDeleted = true;
    Flight_code_DC_DW.obj_p.isInitialized = 0;
    Flight_code_DC_DW.obj_p.ticksUntilNextHit = 0.0;
    Flight_code_DC_DW.obj_p.matlabCodegenIsDeleted = false;
    Flight_code_DC_DW.obj_p.isSetupComplete = false;
    Flight_code_DC_DW.obj_p.isInitialized = 1;
    Flight_code_DC_DW.obj_p.orbMetadataObj = ORB_ID(sensor_accel);
    uORB_read_initialize(Flight_code_DC_DW.obj_p.orbMetadataObj,
                         &Flight_code_DC_DW.obj_p.eventStructObj, 10.0);
    Flight_code_DC_DW.obj_p.isSetupComplete = true;

    // Start for MATLABSystem: '<S36>/SourceBlock'
    Flight_code_DC_DW.obj_h.matlabCodegenIsDeleted = true;
    Flight_code_DC_DW.obj_h.isInitialized = 0;
    Flight_code_DC_DW.obj_h.ticksUntilNextHit = 0.0;
    Flight_code_DC_DW.obj_h.matlabCodegenIsDeleted = false;
    Flight_code_DC_DW.obj_h.isSetupComplete = false;
    Flight_code_DC_DW.obj_h.isInitialized = 1;
    Flight_code_DC_DW.obj_h.orbMetadataObj = ORB_ID(differential_pressure);
    uORB_read_initialize(Flight_code_DC_DW.obj_h.orbMetadataObj,
                         &Flight_code_DC_DW.obj_h.eventStructObj, 10.0);
    Flight_code_DC_DW.obj_h.isSetupComplete = true;

    // Start for MATLABSystem: '<S51>/SourceBlock'
    Flight_code_DC_DW.obj_e.matlabCodegenIsDeleted = true;
    Flight_code_DC_DW.obj_e.isInitialized = 0;
    Flight_code_DC_DW.obj_e.ticksUntilNextHit = 0.0;
    Flight_code_DC_DW.obj_e.matlabCodegenIsDeleted = false;
    Flight_code_DC_DW.obj_e.isSetupComplete = false;
    Flight_code_DC_DW.obj_e.isInitialized = 1;
    Flight_code_DC_DW.obj_e.orbMetadataObj = ORB_ID(vehicle_gps_position);
    uORB_read_initialize(Flight_code_DC_DW.obj_e.orbMetadataObj,
                         &Flight_code_DC_DW.obj_e.eventStructObj, 10.0);
    Flight_code_DC_DW.obj_e.isSetupComplete = true;

    // InitializeConditions for Memory: '<S79>/Memory'
    Flight_code_DC_DW.Memory_PreviousInput =
      Flight_code_DC_P.Memory_InitialCondition;

    // InitializeConditions for DiscreteIntegrator: '<S93>/Discrete-Time Integrator' 
    Flight_code_DC_DW.DiscreteTimeIntegrator_DSTATE = Constant;
    Flight_code_DC_DW.DiscreteTimeIntegrator_PrevRese = 2;

    // InitializeConditions for DiscreteIntegrator: '<S94>/Discrete-Time Integrator' 
    Flight_code_DC_DW.DiscreteTimeIntegrator_DSTATE_a = Constant1;
    Flight_code_DC_DW.DiscreteTimeIntegrator_PrevRe_p = 2;

    // InitializeConditions for DiscreteIntegrator: '<S103>/Discrete-Time Integrator' 
    Flight_code_DC_DW.DiscreteTimeIntegrator_IC_LOADI = 1U;
    Flight_code_DC_DW.DiscreteTimeIntegrator_PrevR_p5 = 2;

    // InitializeConditions for DiscreteIntegrator: '<S88>/Discrete-Time Integrator' 
    Flight_code_DC_DW.DiscreteTimeIntegrator_IC_LOA_e = 1U;
    Flight_code_DC_DW.DiscreteTimeIntegrator_PrevRe_c = 2;

    // InitializeConditions for Memory: '<S86>/Memory'
    Flight_code_DC_DW.Memory_PreviousInput_l =
      Flight_code_DC_P.Memory_InitialCondition_b;

    // InitializeConditions for DiscreteIntegrator: '<S114>/Discrete-Time Integrator' 
    Flight_code_DC_DW.DiscreteTimeIntegrator_IC_LOA_k = 1U;
    Flight_code_DC_DW.DiscreteTimeIntegrator_PrevRe_o = 2;

    // InitializeConditions for Memory: '<S122>/Memory'
    Flight_code_DC_DW.Memory_PreviousInput_o =
      Flight_code_DC_P.Memory_InitialCondition_h;

    // InitializeConditions for DiscreteIntegrator: '<S136>/Discrete-Time Integrator' 
    Flight_code_DC_DW.DiscreteTimeIntegrator_DSTATE_j = Constant_c;
    Flight_code_DC_DW.DiscreteTimeIntegrator_PrevRe_d = 2;

    // InitializeConditions for DiscreteIntegrator: '<S137>/Discrete-Time Integrator' 
    Flight_code_DC_DW.DiscreteTimeIntegrator_DSTATE_k = Constant1_k;
    Flight_code_DC_DW.DiscreteTimeIntegrator_PrevRe_h = 2;

    // InitializeConditions for DiscreteIntegrator: '<S146>/Discrete-Time Integrator' 
    Flight_code_DC_DW.DiscreteTimeIntegrator_IC_LO_e2 = 1U;
    Flight_code_DC_DW.DiscreteTimeIntegrator_PrevR_d5 = 2;

    // InitializeConditions for DiscreteIntegrator: '<S131>/Discrete-Time Integrator' 
    Flight_code_DC_DW.DiscreteTimeIntegrator_IC_LOA_c = 1U;
    Flight_code_DC_DW.DiscreteTimeIntegrator_PrevR_d4 = 2;

    // InitializeConditions for Memory: '<S129>/Memory'
    Flight_code_DC_DW.Memory_PreviousInput_l2 =
      Flight_code_DC_P.Memory_InitialCondition_g;

    // InitializeConditions for DiscreteIntegrator: '<S157>/Discrete-Time Integrator' 
    Flight_code_DC_DW.DiscreteTimeIntegrator_IC_LOA_h = 1U;
    Flight_code_DC_DW.DiscreteTimeIntegrator_PrevRe_f = 2;

    // SystemInitialize for Enabled SubSystem: '<S69>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S70>/Out1'
    Flight_code_DC_B.In1_c = Flight_code_DC_P.Out1_Y0_g;

    // End of SystemInitialize for SubSystem: '<S69>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S163>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S164>/Out1'
    Flight_code_DC_B.In1_h = Flight_code_DC_P.Out1_Y0_p3;

    // End of SystemInitialize for SubSystem: '<S163>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S34>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S37>/Out1'
    Flight_code_DC_B.In1_m = Flight_code_DC_P.Out1_Y0_m;

    // End of SystemInitialize for SubSystem: '<S34>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S35>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S38>/Out1'
    Flight_code_DC_B.In1_o = Flight_code_DC_P.Out1_Y0_n5;

    // End of SystemInitialize for SubSystem: '<S35>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S43>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S44>/Out1'
    Flight_code_DC_B.In1_l = Flight_code_DC_P.Out1_Y0_d;

    // End of SystemInitialize for SubSystem: '<S43>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S50>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S53>/Out1'
    Flight_code_DC_B.In1_k = Flight_code_DC_P.Out1_Y0_h;

    // End of SystemInitialize for SubSystem: '<S50>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S31>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S33>/Out1'
    Flight_code_DC_B.In1 = Flight_code_DC_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S31>/Enabled Subsystem'
  }
}

// Model terminate function
void Flight_code_DC_terminate(void)
{
  // Terminate for MATLABSystem: '<S69>/SourceBlock'
  matlabCodegenHandle_matlabCod_i(&Flight_code_DC_DW.obj_d);

  // Terminate for MATLABSystem: '<S163>/SourceBlock'
  matlabCodegenHandle_matlabCod_i(&Flight_code_DC_DW.obj);

  // Terminate for MATLABSystem: '<S34>/SourceBlock'
  matlabCodegenHandle_matlabCod_i(&Flight_code_DC_DW.obj_n);

  // Terminate for MATLABSystem: '<S35>/SourceBlock'
  matlabCodegenHandle_matlabCod_i(&Flight_code_DC_DW.obj_k);

  // Terminate for MATLABSystem: '<S43>/SourceBlock'
  matlabCodegenHandle_matlabCod_i(&Flight_code_DC_DW.obj_i);

  // Terminate for MATLABSystem: '<S50>/SourceBlock'
  matlabCodegenHandle_matlabCod_i(&Flight_code_DC_DW.obj_o);

  // Terminate for MATLABSystem: '<Root>/PX4 PWM Output'
  matlabCodegenHandle_matlabCodeg(&Flight_code_DC_DW.obj_kz);

  // Terminate for MATLABSystem: '<S19>/SinkBlock'
  matlabCodegenHandle_m_iri5mq4el(&Flight_code_DC_DW.obj_oe);

  // Terminate for MATLABSystem: '<S31>/SourceBlock'
  matlabCodegenHandle_matlabCod_i(&Flight_code_DC_DW.obj_g);

  // Terminate for MATLABSystem: '<S29>/SourceBlock'
  matlabCodegenHandle_matlabCod_i(&Flight_code_DC_DW.obj_p);

  // Terminate for MATLABSystem: '<S36>/SourceBlock'
  matlabCodegenHandle_matlabCod_i(&Flight_code_DC_DW.obj_h);

  // Terminate for MATLABSystem: '<S51>/SourceBlock'
  matlabCodegenHandle_matlabCod_i(&Flight_code_DC_DW.obj_e);
}

//
// File trailer for generated code.
//
// [EOF]
//
