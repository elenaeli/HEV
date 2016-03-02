/*
 * MATLAB.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "MATLAB".
 *
 * Model version              : 1.108
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Wed Mar 02 10:42:27 2016
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_MATLAB_h_
#define RTW_HEADER_MATLAB_h_
#include <math.h>
#include <string.h>
#include <float.h>
#include <stddef.h>
#ifndef MATLAB_COMMON_INCLUDES_
# define MATLAB_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#endif                                 /* MATLAB_COMMON_INCLUDES_ */

#include "MATLAB_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T payoffBoth[7442];
  real_T x[7442];
  real_T M[7442];
  real_T E[7442];
  real_T payoffMotor[3721];
  real_T payoffEngine[3721];
  real_T tmpTorque[3721];
  real_T totalTorque[3721];
} B_MATLAB_T;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T RequiredtorqueNm;             /* '<Root>/requiredTorque' */
} ExtU_MATLAB_T;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T engineTorque;                 /* '<Root>/engineTorque' */
  real_T motorTorque;                  /* '<Root>/motorTorque' */
} ExtY_MATLAB_T;

/* Real-time Model Data Structure */
struct tag_RTM_MATLAB_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block signals (auto storage) */
extern B_MATLAB_T MATLAB_B;

/* External inputs (root inport signals with auto storage) */
extern ExtU_MATLAB_T MATLAB_U;

/* External outputs (root outports fed by signals with auto storage) */
extern ExtY_MATLAB_T MATLAB_Y;

/* Model entry point functions */
extern void MATLAB_initialize(void);
extern void MATLAB_step(void);
extern void MATLAB_terminate(void);

/* Real-time Model object */
extern RT_MODEL_MATLAB_T *const MATLAB_M;

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
 * hilite_system('HEV/Power Controller/Game Theory Controller/MATLAB Function')    - opens subsystem HEV/Power Controller/Game Theory Controller/MATLAB Function
 * hilite_system('HEV/Power Controller/Game Theory Controller/MATLAB Function/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'HEV/Power Controller/Game Theory Controller'
 * '<S1>'   : 'HEV/Power Controller/Game Theory Controller/MATLAB Function'
 */
#endif                                 /* RTW_HEADER_MATLAB_h_ */
