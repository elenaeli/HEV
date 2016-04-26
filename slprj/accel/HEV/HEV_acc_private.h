#include "__cf_HEV.h"
#ifndef RTW_HEADER_HEV_acc_private_h_
#define RTW_HEADER_HEV_acc_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#if !defined(ss_VALIDATE_MEMORY)
#define ss_VALIDATE_MEMORY(S, ptr)   if(!(ptr)) {\
  ssSetErrorStatus(S, RT_MEMORY_ALLOCATION_ERROR);\
  }
#endif
#if !defined(rt_FREE)
#if !defined(_WIN32)
#define rt_FREE(ptr)   if((ptr) != (NULL)) {\
  free((ptr));\
  (ptr) = (NULL);\
  }
#else
#define rt_FREE(ptr)   if((ptr) != (NULL)) {\
  free((void *)(ptr));\
  (ptr) = (NULL);\
  }
#endif
#endif
#ifndef UCHAR_MAX
#include <limits.h>
#endif
#if ( UCHAR_MAX != (0xFFU) ) || ( SCHAR_MAX != (0x7F) )
#error Code was generated for compiler with different sized uchar/char. \Consider adjusting Test hardware word size settings on the \Hardware Implementation pane to match your compiler word sizes as \defined in limits.h of the compiler. Alternatively, you can \select the Test hardware is the same as production hardware option and \select the Enable portable word sizes option on the Code Generation > \Verification pane for ERT based targets, which will disable the \preprocessor word size checks.
#endif
#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized ushort/short. \Consider adjusting Test hardware word size settings on the \Hardware Implementation pane to match your compiler word sizes as \defined in limits.h of the compiler. Alternatively, you can \select the Test hardware is the same as production hardware option and \select the Enable portable word sizes option on the Code Generation > \Verification pane for ERT based targets, which will disable the \preprocessor word size checks.
#endif
#if ( UINT_MAX != (0xFFFFFFFFU) ) || ( INT_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized uint/int. \Consider adjusting Test hardware word size settings on the \Hardware Implementation pane to match your compiler word sizes as \defined in limits.h of the compiler. Alternatively, you can \select the Test hardware is the same as production hardware option and \select the Enable portable word sizes option on the Code Generation > \Verification pane for ERT based targets, which will disable the \preprocessor word size checks.
#endif
#if ( ULONG_MAX != (0xFFFFFFFFU) ) || ( LONG_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized ulong/long. \Consider adjusting Test hardware word size settings on the \Hardware Implementation pane to match your compiler word sizes as \defined in limits.h of the compiler. Alternatively, you can \select the Test hardware is the same as production hardware option and \select the Enable portable word sizes option on the Code Generation > \Verification pane for ERT based targets, which will disable the \preprocessor word size checks.
#endif
#ifndef rtInterpolate
#define rtInterpolate(v1,v2,f1,f2)   (((v1)==(v2))?((double)(v1)):  (((f1)*((double)(v1)))+((f2)*((double)(v2)))))
#endif
#ifndef rtRound
#define rtRound(v) ( ((v) >= 0) ?   muDoubleScalarFloor((v) + 0.5) :   muDoubleScalarCeil((v) - 0.5) )
#endif
void HEV_acc_BINARYSEARCH_real_T ( uint32_T * piLeft , uint32_T * piRght ,
real_T u , const real_T * pData , uint32_T iHi ) ; void
HEV_acc_LookUp_real_T_real_T ( real_T * pY , const real_T * pYData , real_T u
, const real_T * pUData , uint32_T iHi ) ; void
HEV_acc_Look2D_real_T_real_T_real_T ( real_T * pY , const real_T * pYData ,
real_T u0 , const real_T * pU0Data , uint32_T iHiU0 , real_T u1 , const
real_T * pU1Data , uint32_T iHiU1 ) ; void keyxmz53xi ( SimStruct * const S ,
boolean_T mfqvbclekq , boolean_T gbeq152nyt , h1kbqu5vwm * localB ,
his5kfh0i3 * localDW ) ; void pxb4ekgt40 ( p4fr4skvru * localDW ) ; void
h5wlu0jr4o ( SimStruct * const S , boolean_T arbplnr3kg , boolean_T
c0s1in3hpq , colzs110oe * localB , p4fr4skvru * localDW ) ;
#endif
