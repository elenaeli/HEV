/*
 * MATLAB_types.h
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

#ifndef RTW_HEADER_MATLAB_types_h_
#define RTW_HEADER_MATLAB_types_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#ifndef _DEFINED_TYPEDEF_FOR_struct_YlEyT9qojLzO8y7BfHmLTF_
#define _DEFINED_TYPEDEF_FOR_struct_YlEyT9qojLzO8y7BfHmLTF_

typedef struct {
  real_T speed[10];
  real_T torque[10];
  real_T fuel[10];
  real_T power[10];
  real_T lookupTableFuel[100];
  real_T lookupTablePower[100];
} struct_YlEyT9qojLzO8y7BfHmLTF;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_struct_AhOCq8wSv57sPisAx0oKfH_
#define _DEFINED_TYPEDEF_FOR_struct_AhOCq8wSv57sPisAx0oKfH_

typedef struct {
  real_T speed[10];
  real_T torque[10];
  real_T hc[10];
  real_T nox[10];
  real_T co[10];
  real_T lookupTableHC[100];
  real_T lookupTableCO[100];
  real_T lookupTableNOX[100];
} struct_AhOCq8wSv57sPisAx0oKfH;

#endif

/* Custom Type definition for MATLAB Function: '<Root>/MATLAB Function' */
#ifndef struct_sgTV7FO0lYpchQmr81YXzw
#define struct_sgTV7FO0lYpchQmr81YXzw

struct sgTV7FO0lYpchQmr81YXzw
{
  real_T speed[10];
  real_T torque[10];
  real_T fuel[10];
  real_T power[10];
  real_T lookupTableFuel[100];
  real_T lookupTablePower[100];
};

#endif                                 /*struct_sgTV7FO0lYpchQmr81YXzw*/

#ifndef typedef_sgTV7FO0lYpchQmr81YXzw_MATLAB_T
#define typedef_sgTV7FO0lYpchQmr81YXzw_MATLAB_T

typedef struct sgTV7FO0lYpchQmr81YXzw sgTV7FO0lYpchQmr81YXzw_MATLAB_T;

#endif                                 /*typedef_sgTV7FO0lYpchQmr81YXzw_MATLAB_T*/

#ifndef struct_sCQbhvoVmv3dcJduNPb76oB
#define struct_sCQbhvoVmv3dcJduNPb76oB

struct sCQbhvoVmv3dcJduNPb76oB
{
  real_T speed[10];
  real_T torque[10];
  real_T hc[10];
  real_T nox[10];
  real_T co[10];
  real_T lookupTableHC[100];
  real_T lookupTableCO[100];
  real_T lookupTableNOX[100];
};

#endif                                 /*struct_sCQbhvoVmv3dcJduNPb76oB*/

#ifndef typedef_sCQbhvoVmv3dcJduNPb76oB_MATLA_T
#define typedef_sCQbhvoVmv3dcJduNPb76oB_MATLA_T

typedef struct sCQbhvoVmv3dcJduNPb76oB sCQbhvoVmv3dcJduNPb76oB_MATLA_T;

#endif                                 /*typedef_sCQbhvoVmv3dcJduNPb76oB_MATLA_T*/

/* Forward declaration for rtModel */
typedef struct tag_RTM_MATLAB_T RT_MODEL_MATLAB_T;

#endif                                 /* RTW_HEADER_MATLAB_types_h_ */
