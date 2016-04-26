#include "__cf_HEV.h"
#include <math.h>
#include "HEV_acc.h"
#include "HEV_acc_private.h"
#include <stdio.h>
#include "simstruc.h"
#include "fixedpoint.h"
#define CodeFormat S-Function
#define AccDefine1 Accelerator_S-Function
void HEV_acc_BINARYSEARCH_real_T ( uint32_T * piLeft , uint32_T * piRght ,
real_T u , const real_T * pData , uint32_T iHi ) { * piLeft = 0U ; * piRght =
iHi ; if ( u <= pData [ 0 ] ) { * piRght = 0U ; } else if ( u >= pData [ iHi
] ) { * piLeft = iHi ; } else { uint32_T i ; while ( ( * piRght - * piLeft )
> 1U ) { i = ( * piLeft + * piRght ) >> 1 ; if ( u < pData [ i ] ) { * piRght
= i ; } else { * piLeft = i ; } } } } void HEV_acc_LookUp_real_T_real_T (
real_T * pY , const real_T * pYData , real_T u , const real_T * pUData ,
uint32_T iHi ) { uint32_T iLeft ; uint32_T iRght ;
HEV_acc_BINARYSEARCH_real_T ( & ( iLeft ) , & ( iRght ) , u , pUData , iHi )
; { real_T lambda ; if ( pUData [ iRght ] > pUData [ iLeft ] ) { real_T num ;
real_T den ; den = pUData [ iRght ] ; den -= pUData [ iLeft ] ; num = u ; num
-= pUData [ iLeft ] ; lambda = num / den ; } else { lambda = 0.0 ; } { real_T
yLeftCast ; real_T yRghtCast ; yLeftCast = pYData [ iLeft ] ; yRghtCast =
pYData [ iRght ] ; yLeftCast += lambda * ( yRghtCast - yLeftCast ) ; ( * pY )
= yLeftCast ; } } } void HEV_acc_Look2D_real_T_real_T_real_T ( real_T * pY ,
const real_T * pYData , real_T u0 , const real_T * pU0Data , uint32_T iHiU0 ,
real_T u1 , const real_T * pU1Data , uint32_T iHiU1 ) { uint32_T iLeftU0 ,
iRghtU0 , iLeftU1 , iRghtU1 ; HEV_acc_BINARYSEARCH_real_T ( & ( iLeftU0 ) , &
( iRghtU0 ) , u0 , pU0Data , iHiU0 ) ; HEV_acc_BINARYSEARCH_real_T ( & (
iLeftU1 ) , & ( iRghtU1 ) , u1 , pU1Data , iHiU1 ) ; { real_T u0Left =
pU0Data [ iLeftU0 ] ; real_T u0Rght = pU0Data [ iRghtU0 ] ; real_T u1Left =
pU1Data [ iLeftU1 ] ; real_T u1Rght = pU1Data [ iRghtU1 ] ; real_T yTemp ;
real_T yLeftLeft ; real_T yLeftRght ; real_T yRghtLeft ; real_T yRghtRght ;
real_T u1Lambda ; real_T u0Lambda ; if ( u1Rght > u1Left ) { real_T num ;
real_T den ; den = u1Rght ; den -= u1Left ; num = u1 ; num -= u1Left ;
u1Lambda = num / den ; } else { u1Lambda = 0.0 ; } if ( u0Rght > u0Left ) {
real_T num ; real_T den ; den = u0Rght ; den -= u0Left ; num = u0 ; num -=
u0Left ; u0Lambda = num / den ; } else { u0Lambda = 0.0 ; } iHiU0 ++ ;
iLeftU1 *= iHiU0 ; iRghtU1 *= iHiU0 ; yRghtLeft = pYData [ ( iRghtU0 +
iLeftU1 ) ] ; yRghtRght = pYData [ ( iRghtU0 + iRghtU1 ) ] ; yLeftLeft =
pYData [ ( iLeftU0 + iLeftU1 ) ] ; yLeftRght = pYData [ ( iLeftU0 + iRghtU1 )
] ; { real_T yLeftCast ; real_T yRghtCast ; yLeftCast = yLeftLeft ; yRghtCast
= yLeftRght ; yLeftCast += u1Lambda * ( yRghtCast - yLeftCast ) ; ( * pY ) =
yLeftCast ; } { real_T yLeftCast ; real_T yRghtCast ; yLeftCast = yRghtLeft ;
yRghtCast = yRghtRght ; yLeftCast += u1Lambda * ( yRghtCast - yLeftCast ) ;
yTemp = yLeftCast ; } { real_T yLeftCast ; real_T yRghtCast ; yLeftCast = ( *
pY ) ; yRghtCast = yTemp ; yLeftCast += u0Lambda * ( yRghtCast - yLeftCast )
; ( * pY ) = yLeftCast ; } } } void keyxmz53xi ( SimStruct * const S ,
boolean_T mfqvbclekq , boolean_T gbeq152nyt , h1kbqu5vwm * localB ,
his5kfh0i3 * localDW ) { if ( mfqvbclekq ) { localB -> nxi25prvux =
gbeq152nyt ; if ( ssIsMajorTimeStep ( S ) ) { srUpdateBC ( localDW ->
hx1jtpaojx ) ; } } } void nxnb4xfekz ( SimStruct * const S ) { } void
pxb4ekgt40 ( p4fr4skvru * localDW ) { localDW -> mm1hqt2fmu = false ; } void
h5wlu0jr4o ( SimStruct * const S , boolean_T arbplnr3kg , boolean_T
c0s1in3hpq , colzs110oe * localB , p4fr4skvru * localDW ) { if (
ssIsSampleHit ( S , 3 , 0 ) && ssIsMajorTimeStep ( S ) ) { if ( arbplnr3kg )
{ if ( ! localDW -> mm1hqt2fmu ) { if ( ssGetTaskTime ( S , 3 ) !=
ssGetTStart ( S ) ) { ssSetSolverNeedsReset ( S ) ; } localDW -> mm1hqt2fmu =
true ; } } else { if ( localDW -> mm1hqt2fmu ) { ssSetSolverNeedsReset ( S )
; pxb4ekgt40 ( localDW ) ; } } } if ( localDW -> mm1hqt2fmu ) { if (
ssIsSampleHit ( S , 1 , 0 ) ) { localB -> oyhdmurzjh = c0s1in3hpq ; } if (
ssIsMajorTimeStep ( S ) ) { srUpdateBC ( localDW -> aynvqfqzr3 ) ; } } } void
nclrm4pyvg ( SimStruct * const S ) { } static void mdlOutputs ( SimStruct * S
, int_T tid ) { real_T lwbz0wcdrq ; real_T jubgb1nd5z ; real_T lx4pbfxtbc ;
real_T poymnughfl ; real_T crne3byzmy ; real_T bs2qhimvya ; real_T fqbhv02h3b
; real_T nuxercq3rg ; real_T ouvslzwll4 ; boolean_T o3uvutavac ; boolean_T
plykbgk15o ; real_T * lastU ; uint8_T fg2z5apswc ; real_T olptcjth3h ; real_T
eskeehll14 ; real_T nzkt5g3ckg ; boolean_T f5v0rstk5i ; real_T g0desguayz ;
real_T ehtkh2wauy ; real_T mkcfwi2fsi ; real_T ojp40wkotz ; real_T jlph3w5wgc
; real_T fv0yihlfgb ; real_T jv1f4t0umc ; real_T neooptatmt ; real_T
ex0subwfrn ; real_T i24gmhmn24 ; real_T byehzqrbel ; boolean_T d32xki5ce2 ;
real_T plqe5rftf1 ; real_T mvo1vu4fxh ; real_T jcpcoishnw ; real_T j0jhyqa1p3
; real_T iu0uolp1g0 ; real_T liz4gmuw0i ; real_T dztyrqu4xa ; real_T
payjt4hwej ; real_T hvqfirrur0 ; real_T oqvhvuyyrz ; real_T m2kgveajrn ;
real_T avdc0fgs2h ; real_T l1mscynyvk ; real_T pogyapcinw ; real_T eq33yxixok
; real_T nv5qtm3k1a [ 2 ] ; real_T db4h41wmsv ; real_T bntecz3apr ; int32_T i
; real_T epi0kh5ytt_idx_0 ; real_T epi0kh5ytt_idx_1 ; real_T epi0kh5ytt_idx_2
; ZCEventType zcEvent_idx_0 ; ZCEventType zcEvent_idx_1 ; ZCEventType
zcEvent_idx_2 ; fdj1laa40s * _rtB ; baqezl5ja5 * _rtP ; hgl3elxkcb * _rtX ;
bu2ncqpcar * _rtZCE ; h04hj5x5sk * _rtDW ; _rtDW = ( ( h04hj5x5sk * )
ssGetRootDWork ( S ) ) ; _rtZCE = ( ( bu2ncqpcar * ) _ssGetPrevZCSigState ( S
) ) ; _rtX = ( ( hgl3elxkcb * ) ssGetContStates ( S ) ) ; _rtP = ( (
baqezl5ja5 * ) ssGetDefaultParam ( S ) ) ; _rtB = ( ( fdj1laa40s * )
_ssGetBlockIO ( S ) ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB ->
m451lzcan3 = _rtP -> P_16 ; _rtB -> h3e1tbau1t = _rtP -> P_17 ; _rtB ->
kyw4fgkopx = _rtP -> P_18 ; _rtB -> nyjq4bb1cw = _rtP -> P_19 ; _rtB ->
mzzpuobwb1 = _rtP -> P_20 ; _rtB -> lb1t355soj = _rtP -> P_21 ; _rtB ->
g5dp2f4wfx = _rtP -> P_22 ; _rtB -> ekd4iw5rvv = _rtP -> P_23 ; _rtB ->
gkamp0a1fl = _rtP -> P_24 ; _rtB -> fpafrklqo3 = _rtP -> P_25 ; _rtB ->
jejnuvla0d = _rtP -> P_26 ; _rtB -> drxxifyu23 = _rtP -> P_27 ; _rtB ->
hhlcz2ptxp = _rtP -> P_28 ; _rtB -> d03bjcjq0j = _rtP -> P_29 ; _rtB ->
oiqrmrqsyy = _rtP -> P_30 ; _rtB -> hh41rktg2c = _rtP -> P_31 ; _rtB ->
mplk52reue = _rtP -> P_32 ; } _rtB -> h5wegthhav [ 0 ] = _rtB -> m451lzcan3 ;
_rtB -> h5wegthhav [ 1 ] = _rtB -> h3e1tbau1t ; _rtB -> h5wegthhav [ 2 ] =
_rtB -> kyw4fgkopx ; _rtB -> h5wegthhav [ 3 ] = _rtB -> nyjq4bb1cw ; _rtB ->
h5wegthhav [ 4 ] = _rtB -> mzzpuobwb1 ; _rtB -> h5wegthhav [ 5 ] = _rtB ->
lb1t355soj ; _rtB -> h5wegthhav [ 6 ] = _rtB -> g5dp2f4wfx ; _rtB ->
h5wegthhav [ 7 ] = _rtB -> ekd4iw5rvv ; _rtB -> h5wegthhav [ 8 ] = _rtB ->
gkamp0a1fl ; _rtB -> h5wegthhav [ 9 ] = _rtB -> fpafrklqo3 ; _rtB ->
h5wegthhav [ 10 ] = _rtB -> jejnuvla0d ; _rtB -> h5wegthhav [ 11 ] = _rtB ->
drxxifyu23 ; _rtB -> h5wegthhav [ 12 ] = _rtB -> hhlcz2ptxp ; _rtB ->
h5wegthhav [ 13 ] = _rtB -> d03bjcjq0j ; _rtB -> h5wegthhav [ 14 ] = _rtB ->
oiqrmrqsyy ; _rtB -> h5wegthhav [ 15 ] = _rtB -> hh41rktg2c ; _rtB ->
h5wegthhav [ 16 ] = _rtB -> mplk52reue ; ssCallAccelRunBlock ( S , 20 , 18 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 20 , 19 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> om5h3x44fj = _rtP -> P_33 * _rtB ->
kfh0ffdqcp [ 5 ] ; _rtB -> chy0gpxouj = muDoubleScalarAbs ( _rtB ->
om5h3x44fj ) ; HEV_acc_LookUp_real_T_real_T ( & ( _rtB -> mwqhxdl5bq ) , _rtP
-> P_35 , _rtB -> chy0gpxouj , _rtP -> P_34 , 6U ) ; if ( ssIsSampleHit ( S ,
1 , 0 ) ) { _rtB -> n5litymrxg = _rtP -> P_36 ; } ssCallAccelRunBlock ( S ,
20 , 24 , SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 20 , 25 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 20 , 26 ,
SS_CALL_MDL_OUTPUTS ) ; switch ( ( int32_T ) _rtB -> n5litymrxg ) { case 1 :
_rtB -> czdycx5yqx = _rtB -> ondnbzt21p ; break ; case 2 : _rtB -> czdycx5yqx
= _rtB -> bq130gi0hp ; break ; default : _rtB -> czdycx5yqx = _rtB ->
lr0prrgtqd ; break ; } _rtB -> er5osgue5m = 0.0 ; _rtB -> er5osgue5m += _rtP
-> P_38 * _rtX -> ix50zu3rlz ; _rtB -> amdszsp34w = _rtB -> czdycx5yqx - _rtB
-> er5osgue5m ; _rtB -> eg2qq01c0z = _rtP -> P_39 * _rtB -> amdszsp34w ; if (
( ( hgl3elxkcb * ) ssGetContStates ( S ) ) -> f0udlm3lxk >= _rtP -> P_41 ) {
if ( ( ( hgl3elxkcb * ) ssGetContStates ( S ) ) -> f0udlm3lxk != _rtP -> P_41
) { ( ( hgl3elxkcb * ) ssGetContStates ( S ) ) -> f0udlm3lxk = _rtP -> P_41 ;
ssSetSolverNeedsReset ( S ) ; } } else if ( ( ( hgl3elxkcb * )
ssGetContStates ( S ) ) -> f0udlm3lxk <= _rtP -> P_42 ) { if ( ( ( hgl3elxkcb
* ) ssGetContStates ( S ) ) -> f0udlm3lxk != _rtP -> P_42 ) { ( ( hgl3elxkcb
* ) ssGetContStates ( S ) ) -> f0udlm3lxk = _rtP -> P_42 ;
ssSetSolverNeedsReset ( S ) ; } } _rtB -> mwzhnpi34h = ( ( hgl3elxkcb * )
ssGetContStates ( S ) ) -> f0udlm3lxk ; _rtB -> cbzu0vv1vn = _rtB ->
eg2qq01c0z + _rtB -> mwzhnpi34h ; if ( _rtB -> cbzu0vv1vn > _rtP -> P_43 ) {
_rtB -> mzy2nkp4sl = _rtP -> P_43 ; } else if ( _rtB -> cbzu0vv1vn < _rtP ->
P_44 ) { _rtB -> mzy2nkp4sl = _rtP -> P_44 ; } else { _rtB -> mzy2nkp4sl =
_rtB -> cbzu0vv1vn ; } if ( ( _rtDW -> cwivfg5ijd >= ssGetTaskTime ( S , 0 )
) && ( _rtDW -> m1iuzueluk >= ssGetTaskTime ( S , 0 ) ) ) { _rtB ->
mpvsgfisp4 = _rtB -> mzy2nkp4sl ; } else { if ( ( ( _rtDW -> cwivfg5ijd <
_rtDW -> m1iuzueluk ) && ( _rtDW -> m1iuzueluk < ssGetTaskTime ( S , 0 ) ) )
|| ( ( _rtDW -> cwivfg5ijd >= _rtDW -> m1iuzueluk ) && ( _rtDW -> cwivfg5ijd
>= ssGetTaskTime ( S , 0 ) ) ) ) { j0jhyqa1p3 = ssGetTaskTime ( S , 0 ) -
_rtDW -> m1iuzueluk ; liz4gmuw0i = _rtDW -> bvl1znuobh ; } else { j0jhyqa1p3
= ssGetTaskTime ( S , 0 ) - _rtDW -> cwivfg5ijd ; liz4gmuw0i = _rtDW ->
kguctqvwvn ; } iu0uolp1g0 = j0jhyqa1p3 * _rtP -> P_45 ; avdc0fgs2h = _rtB ->
mzy2nkp4sl - liz4gmuw0i ; if ( avdc0fgs2h > iu0uolp1g0 ) { _rtB -> mpvsgfisp4
= liz4gmuw0i + iu0uolp1g0 ; } else { j0jhyqa1p3 *= _rtP -> P_46 ; if (
avdc0fgs2h < j0jhyqa1p3 ) { _rtB -> mpvsgfisp4 = liz4gmuw0i + j0jhyqa1p3 ; }
else { _rtB -> mpvsgfisp4 = _rtB -> mzy2nkp4sl ; } } } _rtB -> hqts1k1nze =
_rtP -> P_47 * _rtB -> mpvsgfisp4 ; if ( _rtB -> hqts1k1nze > _rtB ->
mwqhxdl5bq ) { _rtB -> jrc4ehhgfu = _rtB -> mwqhxdl5bq ; } else { _rtB ->
gybawppu3r = _rtP -> P_15 * _rtB -> mwqhxdl5bq ; if ( _rtB -> hqts1k1nze <
_rtB -> gybawppu3r ) { _rtB -> ke1i0dpoai = _rtB -> gybawppu3r ; } else {
_rtB -> ke1i0dpoai = _rtB -> hqts1k1nze ; } _rtB -> jrc4ehhgfu = _rtB ->
ke1i0dpoai ; } nuxercq3rg = ssGetT ( S ) ; if ( ssIsSampleHit ( S , 1 , 0 ) )
{ _rtB -> d4jchbu5m2 = _rtP -> P_48 ; } _rtB -> chfkvxnrn5 = ( real_T ) (
nuxercq3rg > _rtB -> d4jchbu5m2 ) * _rtB -> jrc4ehhgfu ; if ( ssIsSampleHit (
S , 2 , 0 ) ) { _rtB -> eh1wctryes = _rtP -> P_49 * _rtDW -> f2z5i2ds5e ;
_rtB -> ghuadkwg3z = ( _rtB -> eh1wctryes > ld5zvvrfqt ( S ) -> gs2tltvmzo )
; } if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> k02nbbbnuh = _rtDW ->
b50c0wk1dc ; } if ( ssIsSampleHit ( S , 2 , 0 ) ) { if ( _rtDW -> o05rwe50bo
!= 0 ) { _rtDW -> pk42w2cjcz = _rtB -> k02nbbbnuh ; if ( _rtDW -> pk42w2cjcz
>= _rtP -> P_55 ) { _rtDW -> pk42w2cjcz = _rtP -> P_55 ; } else { if ( _rtDW
-> pk42w2cjcz <= _rtP -> P_56 ) { _rtDW -> pk42w2cjcz = _rtP -> P_56 ; } } }
if ( ( _rtB -> ghuadkwg3z > 0.0 ) && ( _rtDW -> f0fxu4veqt <= 0 ) ) { _rtDW
-> pk42w2cjcz = _rtB -> k02nbbbnuh ; if ( _rtDW -> pk42w2cjcz >= _rtP -> P_55
) { _rtDW -> pk42w2cjcz = _rtP -> P_55 ; } else { if ( _rtDW -> pk42w2cjcz <=
_rtP -> P_56 ) { _rtDW -> pk42w2cjcz = _rtP -> P_56 ; } } } if ( _rtDW ->
pk42w2cjcz >= _rtP -> P_55 ) { _rtDW -> pk42w2cjcz = _rtP -> P_55 ; } else {
if ( _rtDW -> pk42w2cjcz <= _rtP -> P_56 ) { _rtDW -> pk42w2cjcz = _rtP ->
P_56 ; } } olptcjth3h = _rtP -> P_57 * _rtDW -> pk42w2cjcz ; if ( olptcjth3h
> _rtP -> P_58 ) { eskeehll14 = _rtP -> P_58 ; } else if ( olptcjth3h < _rtP
-> P_59 ) { eskeehll14 = _rtP -> P_59 ; } else { eskeehll14 = olptcjth3h ; }
_rtB -> a5nxuv3afw = ( 1.0 - eskeehll14 / 7.0 ) * 100.0 ; } _rtB ->
bkged3dh2n = _rtX -> bjc4xqhn0t ; ssCallAccelRunBlock ( S , 18 , 0 ,
SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB ->
kj1sd1cu5q = _rtP -> P_61 ; } _rtB -> m0mtkc2u2o = _rtB -> opxobf1blg * _rtB
-> kj1sd1cu5q ; if ( _rtB -> m0mtkc2u2o > _rtP -> P_62 ) { _rtB -> pflxbg1zd1
= _rtP -> P_62 ; } else if ( _rtB -> m0mtkc2u2o < _rtP -> P_63 ) { _rtB ->
pflxbg1zd1 = _rtP -> P_63 ; } else { _rtB -> pflxbg1zd1 = _rtB -> m0mtkc2u2o
; } ssCallAccelRunBlock ( S , 20 , 57 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
b5bpyg4l3b = _rtP -> P_64 * _rtB -> kfh0ffdqcp [ 11 ] ; ssCallAccelRunBlock (
S , 20 , 59 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> cyzlewftog = _rtP -> P_65 *
_rtB -> b5bpyg4l3b ; _rtB -> k0djrssudk = _rtX -> mh2wvbi24o ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> gdxhqcof03 = _rtP -> P_67 ; } _rtB ->
aep2dr5e3d = _rtB -> k0djrssudk - _rtB -> gdxhqcof03 ; _rtB -> cqe3zaxej5 =
_rtP -> P_68 * _rtB -> aep2dr5e3d ; if ( ssIsSampleHit ( S , 1 , 0 ) ) {
nzkt5g3ckg = _rtP -> P_69 ; _rtB -> in4gjcldnd = ( _rtP -> P_69 != ld5zvvrfqt
( S ) -> l1b2o4yxab ) ; } _rtB -> b3othyhuus = _rtB -> aep2dr5e3d * ( real_T
) _rtB -> in4gjcldnd ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB ->
guj4fbsjmz = _rtP -> P_71 ; } f5v0rstk5i = ( _rtB -> b3othyhuus >= _rtB ->
guj4fbsjmz ) ; _rtB -> gok2qdf42v = _rtB -> cqe3zaxej5 * ( real_T )
f5v0rstk5i ; _rtB -> kdaezrlg4z = _rtP -> P_72 * _rtB -> kfh0ffdqcp [ 12 ] ;
_rtB -> ej5p3l5vcl = _rtP -> P_73 * _rtB -> kfh0ffdqcp [ 0 ] ; _rtB ->
ptbhbc00fq = _rtB -> kdaezrlg4z - _rtB -> ej5p3l5vcl ; _rtB -> p2wegwufdb =
_rtP -> P_74 * _rtB -> ptbhbc00fq ; _rtB -> lgxfuxedpe = ( real_T )
f5v0rstk5i * _rtB -> p2wegwufdb ; _rtB -> n55wlsx0zi = ( 0.0 - _rtB ->
gok2qdf42v ) - _rtB -> lgxfuxedpe ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB
-> a2nsairehx = _rtP -> P_75 ; } _rtB -> kbpegvoi41 = _rtB -> k0djrssudk +
_rtB -> a2nsairehx ; _rtB -> b4dsoaqrwv = _rtP -> P_76 * _rtB -> kbpegvoi41 ;
if ( ssIsSampleHit ( S , 1 , 0 ) ) { nzkt5g3ckg = _rtP -> P_77 ; _rtB ->
l1cxct3fmj = ( _rtP -> P_77 != ld5zvvrfqt ( S ) -> pn0afgnpnl ) ; } _rtB ->
omphqtd0ga = _rtB -> kbpegvoi41 * ( real_T ) _rtB -> l1cxct3fmj ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> fczhjdbokb = _rtP -> P_79 ; }
f5v0rstk5i = ( _rtB -> omphqtd0ga <= _rtB -> fczhjdbokb ) ; _rtB ->
jvee2nzrcw = _rtB -> b4dsoaqrwv * ( real_T ) f5v0rstk5i ; _rtB -> kix5ia34db
= _rtP -> P_80 * _rtB -> ptbhbc00fq ; _rtB -> ah4hh3cdwr = ( real_T )
f5v0rstk5i * _rtB -> kix5ia34db ; _rtB -> pgd05pok0r = ( 0.0 - _rtB ->
jvee2nzrcw ) - _rtB -> ah4hh3cdwr ; if ( ssIsSampleHit ( S , 1 , 0 ) ) {
nzkt5g3ckg = _rtP -> P_81 ; _rtB -> ofu1votyki = ( _rtP -> P_81 != ld5zvvrfqt
( S ) -> esztrntvpt ) ; } _rtB -> pmkak1zu0k = _rtB -> pgd05pok0r * ( real_T
) _rtB -> ofu1votyki ; _rtB -> byq1k4fdgz = ( 0.0 - _rtB -> n55wlsx0zi ) -
_rtB -> pmkak1zu0k ; _rtB -> chyrit1evg = _rtX -> dqmv0fuubx ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> b3ipf5im4j = _rtP -> P_84 ; } _rtB ->
emyd5cgoh5 = _rtB -> chyrit1evg - _rtB -> b3ipf5im4j ; _rtB -> cobazmuhfh =
_rtP -> P_85 * _rtB -> emyd5cgoh5 ; if ( ssIsSampleHit ( S , 1 , 0 ) ) {
nzkt5g3ckg = _rtP -> P_86 ; _rtB -> czrjyd0by3 = ( _rtP -> P_86 != ld5zvvrfqt
( S ) -> cblubmpllc ) ; } _rtB -> puy1pyy0gt = _rtB -> emyd5cgoh5 * ( real_T
) _rtB -> czrjyd0by3 ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB ->
dmopjyrf0f = _rtP -> P_88 ; } f5v0rstk5i = ( _rtB -> puy1pyy0gt >= _rtB ->
dmopjyrf0f ) ; _rtB -> mkmoajljbc = _rtB -> cobazmuhfh * ( real_T )
f5v0rstk5i ; _rtB -> o4qv0qs1qh = _rtP -> P_89 * _rtB -> kfh0ffdqcp [ 1 ] ;
_rtB -> ivkw11z5hw = _rtP -> P_90 * _rtB -> kfh0ffdqcp [ 4 ] ; _rtB ->
ceuutekqj2 = _rtB -> o4qv0qs1qh - _rtB -> ivkw11z5hw ; _rtB -> bifn5ofnxm =
_rtP -> P_91 * _rtB -> ceuutekqj2 ; _rtB -> e2lrmjhnft = ( real_T )
f5v0rstk5i * _rtB -> bifn5ofnxm ; _rtB -> lzl040onia = ( 0.0 - _rtB ->
mkmoajljbc ) - _rtB -> e2lrmjhnft ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB
-> ixaatfxyhb = _rtP -> P_92 ; } _rtB -> dqc3vm4exd = _rtB -> chyrit1evg +
_rtB -> ixaatfxyhb ; _rtB -> k2dqakhioc = _rtP -> P_93 * _rtB -> dqc3vm4exd ;
if ( ssIsSampleHit ( S , 1 , 0 ) ) { nzkt5g3ckg = _rtP -> P_94 ; _rtB ->
ihzzkzkoed = ( _rtP -> P_94 != ld5zvvrfqt ( S ) -> nebdjc5roh ) ; } _rtB ->
hj0lheumph = _rtB -> dqc3vm4exd * ( real_T ) _rtB -> ihzzkzkoed ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> jpei25pre4 = _rtP -> P_96 ; }
f5v0rstk5i = ( _rtB -> hj0lheumph <= _rtB -> jpei25pre4 ) ; _rtB ->
dptadm54l5 = _rtB -> k2dqakhioc * ( real_T ) f5v0rstk5i ; _rtB -> dugpnns2hu
= _rtP -> P_97 * _rtB -> ceuutekqj2 ; _rtB -> mofb0qacwe = ( real_T )
f5v0rstk5i * _rtB -> dugpnns2hu ; _rtB -> mudzuwir3p = ( 0.0 - _rtB ->
dptadm54l5 ) - _rtB -> mofb0qacwe ; if ( ssIsSampleHit ( S , 1 , 0 ) ) {
nzkt5g3ckg = _rtP -> P_98 ; _rtB -> brllkrvwfq = ( _rtP -> P_98 != ld5zvvrfqt
( S ) -> f553soggdo ) ; } _rtB -> eou1qwz5sa = _rtB -> mudzuwir3p * ( real_T
) _rtB -> brllkrvwfq ; _rtB -> aqmlzq43fp = ( 0.0 - _rtB -> lzl040onia ) -
_rtB -> eou1qwz5sa ; _rtB -> oexzgywxvl = _rtP -> P_100 * _rtB -> aqmlzq43fp
; _rtB -> aycrmboosh = _rtX -> mme20c3etf ; if ( ssIsSampleHit ( S , 1 , 0 )
) { _rtB -> pipzk5hlxt = _rtP -> P_102 ; } _rtB -> lhox1aa1pw = _rtX ->
eofb3a23j0 ; _rtB -> ckuxmgocfd = muDoubleScalarAbs ( _rtB -> lhox1aa1pw ) ;
_rtB -> hof4253xgu = ( _rtB -> pipzk5hlxt > _rtB -> ckuxmgocfd ) ; _rtB ->
dhdu3qg3ei = _rtP -> P_104 * _rtB -> ckuxmgocfd ; _rtB -> mgockhzxmt = _rtP
-> P_105 * _rtB -> dhdu3qg3ei ; _rtB -> fubytwnind = ( muDoubleScalarCos (
_rtB -> mgockhzxmt ) + 1.0 ) * _rtP -> P_106 ; _rtB -> launmuc51h = _rtP ->
P_107 * _rtB -> fubytwnind ; _rtB -> gtipdynmdv = _rtP -> P_108 * _rtB ->
launmuc51h ; _rtB -> drnugvgjqy = _rtP -> P_109 * _rtB -> kfh0ffdqcp [ 2 ] ;
_rtB -> coicicwgin = _rtP -> P_110 * _rtB -> drnugvgjqy ; _rtB -> jylgp33lex
= _rtB -> lhox1aa1pw - _rtB -> coicicwgin ; _rtB -> mynogjqhee = _rtB ->
hof4253xgu * _rtB -> gtipdynmdv * _rtB -> jylgp33lex ; _rtB -> m3mnwoaieu =
_rtB -> aycrmboosh - _rtB -> mynogjqhee ; _rtB -> hcpwnzxwgw =
muDoubleScalarSign ( _rtB -> m3mnwoaieu ) ; _rtB -> gwpcgzouim =
muDoubleScalarAbs ( _rtB -> m3mnwoaieu ) ; _rtB -> c22jb2rfw4 = _rtP -> P_111
* _rtB -> gwpcgzouim ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { nzkt5g3ckg = _rtP
-> P_112 ; _rtB -> dbtgrppw14 = _rtP -> P_113 * muDoubleScalarSin ( _rtP ->
P_112 ) ; } _rtB -> ljxgpa44h5 = 0.0 ; _rtB -> ljxgpa44h5 += _rtP -> P_115 [
0 ] * _rtX -> boqgv4aeow [ 0 ] ; _rtB -> ljxgpa44h5 += _rtP -> P_115 [ 1 ] *
_rtX -> boqgv4aeow [ 1 ] ; _rtB -> aqvuwzilbr = muDoubleScalarSign ( _rtB ->
lhox1aa1pw ) ; _rtB -> ik5ho3arpb = _rtB -> lhox1aa1pw * _rtB -> lhox1aa1pw *
_rtB -> aqvuwzilbr ; _rtB -> loz5qlyy5f = _rtP -> P_116 * _rtB -> ik5ho3arpb
; _rtB -> pupntjpli1 = _rtP -> P_117 * _rtB -> loz5qlyy5f ; _rtB ->
gpltpcaetm = _rtP -> P_118 * _rtB -> pupntjpli1 ; _rtB -> kk0busyovy = _rtP
-> P_119 * _rtB -> gpltpcaetm ; _rtB -> kcw1d2b5q0 = ( ( 0.0 - _rtB ->
dbtgrppw14 ) - _rtB -> ljxgpa44h5 ) - _rtB -> kk0busyovy ; _rtB -> jmtf5gh20s
= _rtP -> P_120 * _rtB -> kcw1d2b5q0 ; if ( ssIsSampleHit ( S , 1 , 0 ) ) {
nzkt5g3ckg = _rtP -> P_121 * muDoubleScalarCos ( nzkt5g3ckg ) ; _rtB ->
odfvh14sgd = _rtP -> P_122 * nzkt5g3ckg ; _rtB -> juftsmavo1 = _rtP -> P_123
; } _rtB -> mqqmabvqad = ( _rtB -> odfvh14sgd - _rtB -> jmtf5gh20s ) + _rtB
-> juftsmavo1 ; if ( _rtB -> mqqmabvqad > _rtP -> P_124 ) { _rtB ->
ii1lramsm4 = _rtP -> P_124 ; } else if ( _rtB -> mqqmabvqad < _rtP -> P_125 )
{ _rtB -> ii1lramsm4 = _rtP -> P_125 ; } else { _rtB -> ii1lramsm4 = _rtB ->
mqqmabvqad ; } _rtB -> fa0qrdkmhb = _rtP -> P_126 * _rtB -> ii1lramsm4 ;
HEV_acc_Look2D_real_T_real_T_real_T ( & ( lwbz0wcdrq ) , _rtP -> P_129 , _rtB
-> c22jb2rfw4 , _rtP -> P_127 , 108U , _rtB -> fa0qrdkmhb , _rtP -> P_128 ,
100U ) ; _rtB -> mcbawwy2ze = _rtP -> P_130 * lwbz0wcdrq ; _rtB -> pdkpc2zqh1
= _rtB -> hcpwnzxwgw * _rtB -> mcbawwy2ze ; _rtB -> dxmyoc32um = _rtP ->
P_131 * _rtB -> pdkpc2zqh1 ; _rtB -> a5afdxklz1 = _rtP -> P_132 * _rtB ->
dxmyoc32um ; _rtB -> iw5w5obtgj = _rtX -> dkmu1cdscm ; if ( ssIsSampleHit ( S
, 1 , 0 ) ) { _rtB -> ati42lzgpb = _rtP -> P_134 ; } _rtB -> hl1ra0otqp =
muDoubleScalarAbs ( _rtB -> lhox1aa1pw ) ; _rtB -> fjwd5bwcfb = ( _rtB ->
ati42lzgpb > _rtB -> hl1ra0otqp ) ; _rtB -> ptw0pr35v0 = _rtP -> P_135 * _rtB
-> hl1ra0otqp ; _rtB -> ekpet41dr5 = _rtP -> P_136 * _rtB -> ptw0pr35v0 ;
_rtB -> f4ttx0aeny = ( muDoubleScalarCos ( _rtB -> ekpet41dr5 ) + 1.0 ) *
_rtP -> P_137 ; _rtB -> j23m5se5mc = _rtP -> P_138 * _rtB -> f4ttx0aeny ;
_rtB -> byngs34gie = _rtP -> P_139 * _rtB -> j23m5se5mc ; _rtB -> jzl0dnnxil
= _rtP -> P_140 * _rtB -> kfh0ffdqcp [ 3 ] ; _rtB -> lycfoqk13m = _rtP ->
P_141 * _rtB -> jzl0dnnxil ; _rtB -> hojpq2hcaj = _rtB -> lhox1aa1pw - _rtB
-> lycfoqk13m ; _rtB -> o432sm1sgr = _rtB -> fjwd5bwcfb * _rtB -> byngs34gie
* _rtB -> hojpq2hcaj ; _rtB -> ju1n5rycpj = _rtB -> iw5w5obtgj - _rtB ->
o432sm1sgr ; _rtB -> bktma30l4e = muDoubleScalarSign ( _rtB -> ju1n5rycpj ) ;
_rtB -> oyjhnz0lm3 = muDoubleScalarAbs ( _rtB -> ju1n5rycpj ) ; _rtB ->
ovdgmvdbva = _rtP -> P_142 * _rtB -> oyjhnz0lm3 ; if ( ssIsSampleHit ( S , 1
, 0 ) ) { _rtB -> pb0tvtn3l3 = _rtP -> P_143 * nzkt5g3ckg ; _rtB ->
aaddxqsmmf = _rtP -> P_144 ; } _rtB -> mhkbvsadrm = ( _rtB -> jmtf5gh20s +
_rtB -> pb0tvtn3l3 ) + _rtB -> aaddxqsmmf ; if ( _rtB -> mhkbvsadrm > _rtP ->
P_145 ) { _rtB -> mkpsln2gv2 = _rtP -> P_145 ; } else if ( _rtB -> mhkbvsadrm
< _rtP -> P_146 ) { _rtB -> mkpsln2gv2 = _rtP -> P_146 ; } else { _rtB ->
mkpsln2gv2 = _rtB -> mhkbvsadrm ; } _rtB -> k10iwvvizc = _rtP -> P_147 * _rtB
-> mkpsln2gv2 ; HEV_acc_Look2D_real_T_real_T_real_T ( & ( jubgb1nd5z ) , _rtP
-> P_150 , _rtB -> ovdgmvdbva , _rtP -> P_148 , 108U , _rtB -> k10iwvvizc ,
_rtP -> P_149 , 100U ) ; _rtB -> djcbbymtfg = _rtP -> P_151 * jubgb1nd5z ;
_rtB -> oiwqfkdud2 = _rtB -> bktma30l4e * _rtB -> djcbbymtfg ; _rtB ->
ntvvvumvc5 = _rtP -> P_152 * _rtB -> oiwqfkdud2 ; _rtB -> haotx14ptz = _rtP
-> P_153 * _rtB -> ntvvvumvc5 ; if ( ssIsSampleHit ( S , 2 , 0 ) ) { _rtB ->
er2owrz1gy = _rtDW -> aagwoi0uhr ; _rtB -> llripu04eo = _rtDW -> giv5xrlbh0 ;
_rtB -> banzpsts4l = ( - 0.00045907990073600015 * _rtB -> er2owrz1gy * _rtB
-> llripu04eo + 0.175666143629361 * _rtB -> er2owrz1gy ) * 6.0 ; _rtB ->
pkc13jitsl = _rtDW -> aekc0mbj0y ; _rtB -> axxu2c2pmu = _rtDW -> oi2n4lur1q ;
_rtB -> ncba5bfobt = ( 0.0 * _rtB -> pkc13jitsl * _rtB -> axxu2c2pmu + 0.192
* _rtB -> pkc13jitsl ) * 1.5 ; } if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB ->
j5ugide4pb = _rtP -> P_162 ; } _rtB -> g4tdviggql = _rtP -> P_163 * _rtB ->
kfh0ffdqcp [ 10 ] ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> dmg4bh440v =
_rtP -> P_164 ; } fg2z5apswc = ( uint8_T ) ( _rtB -> g4tdviggql > _rtB ->
dmg4bh440v ) ; if ( fg2z5apswc >= _rtP -> P_474 ) { _rtB -> dt4ztgj5du = _rtB
-> j5ugide4pb ; } else { if ( _rtB -> pflxbg1zd1 > _rtP -> P_7 ) { _rtB ->
ar1kv5pkqg = _rtP -> P_7 ; } else if ( _rtB -> pflxbg1zd1 < _rtP -> P_8 ) {
_rtB -> ar1kv5pkqg = _rtP -> P_8 ; } else { _rtB -> ar1kv5pkqg = _rtB ->
pflxbg1zd1 ; } _rtB -> nqthmrnfqk = _rtP -> P_9 * _rtB -> g4tdviggql ; _rtB
-> hv2em112b5 = rt_Lookup ( _rtP -> P_10 , 101 , _rtB -> nqthmrnfqk , _rtP ->
P_11 ) * _rtB -> ar1kv5pkqg ; _rtB -> dt4ztgj5du = _rtB -> hv2em112b5 ; }
_rtB -> p34s1yzahb = _rtP -> P_165 * _rtB -> byq1k4fdgz ; _rtB -> gmb1gqt5kv
[ 0 ] = _rtB -> byq1k4fdgz ; _rtB -> gmb1gqt5kv [ 1 ] = _rtB -> oexzgywxvl ;
_rtB -> gmb1gqt5kv [ 2 ] = _rtB -> a5afdxklz1 ; _rtB -> gmb1gqt5kv [ 3 ] =
_rtB -> haotx14ptz ; _rtB -> gmb1gqt5kv [ 4 ] = _rtB -> aqmlzq43fp ; _rtB ->
gmb1gqt5kv [ 5 ] = _rtB -> banzpsts4l ; _rtB -> gmb1gqt5kv [ 6 ] = _rtB ->
ncba5bfobt ; _rtB -> gmb1gqt5kv [ 7 ] = _rtB -> dt4ztgj5du ; _rtB ->
gmb1gqt5kv [ 8 ] = _rtB -> p34s1yzahb ; ssCallAccelRunBlock ( S , 20 , 222 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> h1nvplcdrn = _rtP -> P_166 * _rtB ->
fumqusjt44 [ 1 ] ; _rtB -> fdmu3ib3vx = _rtB -> b5bpyg4l3b * _rtB ->
h1nvplcdrn ; ssCallAccelRunBlock ( S , 20 , 225 , SS_CALL_MDL_OUTPUTS ) ;
_rtB -> amhkuby45s = _rtX -> pi4mr5hhgl ; nuxercq3rg = 1.0 / _rtB ->
amhkuby45s * _rtB -> bkged3dh2n ; _rtB -> fdmu3ib3vx = _rtP -> P_168 *
nuxercq3rg ; _rtB -> buoxgxrmie = rt_Lookup2D_Normal ( _rtP -> P_169 , 10 ,
_rtP -> P_170 , 10 , _rtP -> P_171 , _rtB -> cyzlewftog , _rtB -> h1nvplcdrn
) ; _rtB -> pjcfg2e3fk = rt_Lookup2D_Normal ( _rtP -> P_172 , 10 , _rtP ->
P_173 , 10 , _rtP -> P_174 , _rtB -> cyzlewftog , _rtB -> h1nvplcdrn ) ; _rtB
-> kn5iczv3qt = rt_Lookup2D_Normal ( _rtP -> P_175 , 10 , _rtP -> P_176 , 10
, _rtP -> P_177 , _rtB -> cyzlewftog , _rtB -> h1nvplcdrn ) ;
ssCallAccelRunBlock ( S , 20 , 232 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
en44hplr1q = ! ( fg2z5apswc != 0 ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) {
ssCallAccelRunBlock ( S , 20 , 234 , SS_CALL_MDL_OUTPUTS ) ; }
ssCallAccelRunBlock ( S , 20 , 240 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 20 , 241 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 20 , 242 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 20 , 243 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
kn5iczv3qt = 1.0 / nuxercq3rg ; ssCallAccelRunBlock ( S , 20 , 245 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 20 , 246 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 20 , 247 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> gtfccq4heb = _rtP -> P_181 *
rt_Lookup2D_Normal ( _rtP -> P_178 , 10 , _rtP -> P_179 , 10 , _rtP -> P_180
, _rtB -> cyzlewftog , _rtB -> h1nvplcdrn ) ; if ( ssIsSampleHit ( S , 1 , 0
) ) { _rtB -> ckztek5l5d = _rtP -> P_182 ; } _rtB -> lvdthqoiv1 = _rtB ->
gtfccq4heb / _rtB -> ckztek5l5d ; _rtB -> n4v1iaymn1 = _rtP -> P_183 * _rtB
-> lhox1aa1pw ; _rtB -> gawdygiuvt = _rtP -> P_184 * _rtB -> n4v1iaymn1 ;
_rtB -> gujw14k2fh = _rtP -> P_185 * _rtB -> lvdthqoiv1 ; ssCallAccelRunBlock
( S , 20 , 261 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> iij1uewirv = 0 ;
ssCallAccelRunBlock ( S , 20 , 282 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 20 , 283 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 20 , 284 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 20 , 285 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 20 , 286 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
i0cl4hjbel = _rtP -> P_186 * _rtB -> amdszsp34w ; if ( ssIsSampleHit ( S , 2
, 0 ) ) { memcpy ( & _rtB -> f3gligikgk [ 0 ] , & _rtP -> P_187 [ 0 ] , 12U *
sizeof ( real_T ) ) ; g0desguayz = _rtDW -> eaosag5owj ; ehtkh2wauy =
muDoubleScalarSin ( _rtDW -> eaosag5owj ) ; mkcfwi2fsi = muDoubleScalarCos (
_rtDW -> eaosag5owj ) ; _rtB -> ayk3rubdue = _rtB -> pkc13jitsl * mkcfwi2fsi
+ _rtB -> axxu2c2pmu * ehtkh2wauy ; _rtB -> imetovib1x = ( ( - _rtB ->
pkc13jitsl - 1.7320508075688772 * _rtB -> axxu2c2pmu ) * mkcfwi2fsi + (
1.7320508075688772 * _rtB -> pkc13jitsl - _rtB -> axxu2c2pmu ) * ehtkh2wauy )
* 0.5 ; ojp40wkotz = _rtDW -> pa0tuks1qd ; jlph3w5wgc = muDoubleScalarSin (
_rtDW -> pa0tuks1qd ) ; fv0yihlfgb = muDoubleScalarCos ( _rtDW -> pa0tuks1qd
) ; _rtB -> ixfzlplrc3 = _rtB -> er2owrz1gy * fv0yihlfgb + _rtB -> llripu04eo
* jlph3w5wgc ; _rtB -> ce2juvddnf = ( ( - _rtB -> er2owrz1gy -
1.7320508075688772 * _rtB -> llripu04eo ) * fv0yihlfgb + ( 1.7320508075688772
* _rtB -> er2owrz1gy - _rtB -> llripu04eo ) * jlph3w5wgc ) * 0.5 ; } if (
ssIsSampleHit ( S , 1 , 0 ) ) { nzkt5g3ckg = _rtP -> P_192 ; jv1f4t0umc =
_rtP -> P_193 ; neooptatmt = _rtP -> P_194 ; } if ( ssIsSampleHit ( S , 2 , 0
) ) { _rtB -> i5d2g2h5mw = _rtDW -> jly33pdwub ; _rtB -> iifodbbars =
muDoubleScalarExp ( - 2.3076923076923075 * eskeehll14 ) * 18.82114106089411 ;
} if ( ssIsSampleHit ( S , 1 , 0 ) ) { switch ( ( int32_T ) neooptatmt ) {
case 1 : ex0subwfrn = _rtB -> i5d2g2h5mw ; break ; case 2 : ex0subwfrn = _rtB
-> iifodbbars ; break ; case 3 : ex0subwfrn = _rtB -> i5d2g2h5mw ; break ;
default : ex0subwfrn = _rtB -> i5d2g2h5mw ; break ; } } if ( ssIsSampleHit (
S , 2 , 0 ) ) { _rtB -> drf0oksk0l = 7.0 / ( 7.0 - eskeehll14 ) * -
0.23801451555567835 * eskeehll14 ; _rtB -> nythd4s4mn = - _rtB -> ghuadkwg3z
* 0.23801451555567835 * _rtB -> eh1wctryes * ( 7.0 / ( 7.0 - eskeehll14 ) ) ;
} if ( ssIsSampleHit ( S , 1 , 0 ) ) { i24gmhmn24 = _rtP -> P_197 ; } if (
ssIsSampleHit ( S , 2 , 0 ) ) { if ( olptcjth3h > _rtP -> P_198 ) { _rtB ->
l0pzkbqgnv = _rtP -> P_198 ; } else if ( olptcjth3h < _rtP -> P_199 ) { _rtB
-> l0pzkbqgnv = _rtP -> P_199 ; } else { _rtB -> l0pzkbqgnv = olptcjth3h ; }
_rtB -> g3iv42dld3 = ( _rtB -> eh1wctryes < ld5zvvrfqt ( S ) -> jvdmgvjxnb )
; } if ( ssIsSampleHit ( S , 1 , 0 ) ) { switch ( ( int32_T ) i24gmhmn24 ) {
case 1 : neooptatmt = - ( _rtP -> P_3 * _rtB -> g3iv42dld3 ) *
0.23801451555567835 * ( _rtP -> P_3 * _rtB -> eh1wctryes ) * ( 7.0 / ( _rtP
-> P_3 * _rtB -> l0pzkbqgnv + 0.70000000000000007 ) ) ; break ; case 2 :
neooptatmt = - ( _rtP -> P_2 * _rtB -> g3iv42dld3 ) * 0.23801451555567835 * (
_rtP -> P_2 * _rtB -> eh1wctryes ) * ( 7.0 / ( _rtP -> P_2 * _rtB ->
l0pzkbqgnv + 0.70000000000000007 ) ) ; break ; case 3 : neooptatmt = - ( _rtP
-> P_1 * _rtB -> g3iv42dld3 ) * 0.23801451555567835 * ( _rtP -> P_1 * _rtB ->
eh1wctryes ) * ( 7.0 / ( muDoubleScalarAbs ( _rtP -> P_1 * _rtB -> l0pzkbqgnv
) + 0.70000000000000007 ) ) ; break ; default : neooptatmt = - ( _rtP -> P_0
* _rtB -> g3iv42dld3 ) * 0.23801451555567835 * ( _rtP -> P_0 * _rtB ->
eh1wctryes ) * ( 7.0 / ( muDoubleScalarAbs ( _rtP -> P_0 * _rtB -> l0pzkbqgnv
) + 0.70000000000000007 ) ) ; break ; } byehzqrbel = ( ( ( jv1f4t0umc +
ex0subwfrn ) + _rtB -> drf0oksk0l ) + _rtB -> nythd4s4mn ) + neooptatmt ;
d32xki5ce2 = ( byehzqrbel > nzkt5g3ckg ) ; } if ( ssIsSampleHit ( S , 2 , 0 )
) { _rtB -> h5k4wv1g2q = _rtP -> P_201 * _rtB -> eh1wctryes ; } if (
ssIsSampleHit ( S , 1 , 0 ) ) { if ( d32xki5ce2 ) { _rtB -> ablhlgfu2w =
nzkt5g3ckg ; } else if ( byehzqrbel < _rtB -> h5k4wv1g2q ) { _rtB ->
ablhlgfu2w = _rtB -> h5k4wv1g2q ; } else { _rtB -> ablhlgfu2w = byehzqrbel ;
} } if ( ssIsSampleHit ( S , 2 , 0 ) ) { _rtB -> llaqeksi04 = _rtDW ->
fezg0yhyh2 ; epi0kh5ytt_idx_0 = _rtDW -> hdqerfit1p [ 0 ] ; epi0kh5ytt_idx_1
= _rtDW -> hdqerfit1p [ 1 ] ; epi0kh5ytt_idx_2 = _rtDW -> hdqerfit1p [ 2 ] ;
olptcjth3h = _rtP -> P_204 * g0desguayz ; plqe5rftf1 = muDoubleScalarCos (
olptcjth3h ) ; olptcjth3h = muDoubleScalarSin ( olptcjth3h ) ; mvo1vu4fxh =
_rtP -> P_205 ; jcpcoishnw = _rtP -> P_206 ; } _rtB -> kn5iczv3qt = _rtP ->
P_207 * _rtB -> kfh0ffdqcp [ 7 ] ; if ( _rtB -> kn5iczv3qt > _rtP -> P_208 )
{ nuxercq3rg = _rtP -> P_208 ; } else if ( _rtB -> kn5iczv3qt < _rtP -> P_209
) { nuxercq3rg = _rtP -> P_209 ; } else { nuxercq3rg = _rtB -> kn5iczv3qt ; }
nuxercq3rg = 1.0 / nuxercq3rg ; nuxercq3rg *= _rtP -> P_210 ; neooptatmt =
muDoubleScalarAbs ( nuxercq3rg ) ; if ( ssIsMajorTimeStep ( S ) ) { if ( _rtB
-> kn5iczv3qt >= _rtP -> P_211 ) { _rtDW -> ch52ed4whv = true ; } else { if (
_rtB -> kn5iczv3qt <= _rtP -> P_212 ) { _rtDW -> ch52ed4whv = false ; } } }
if ( _rtDW -> ch52ed4whv ) { _rtB -> dn5hp2o2lu = _rtP -> P_213 ; } else {
_rtB -> dn5hp2o2lu = _rtP -> P_214 ; } if ( ( _rtDW -> mg242c3vwq >=
ssGetTaskTime ( S , 0 ) ) && ( _rtDW -> k1wt3kvmem >= ssGetTaskTime ( S , 0 )
) ) { _rtB -> flcpkzs4x3 = _rtB -> dn5hp2o2lu ; } else { if ( ( ( _rtDW ->
mg242c3vwq < _rtDW -> k1wt3kvmem ) && ( _rtDW -> k1wt3kvmem < ssGetTaskTime (
S , 0 ) ) ) || ( ( _rtDW -> mg242c3vwq >= _rtDW -> k1wt3kvmem ) && ( _rtDW ->
mg242c3vwq >= ssGetTaskTime ( S , 0 ) ) ) ) { j0jhyqa1p3 = ssGetTaskTime ( S
, 0 ) - _rtDW -> k1wt3kvmem ; liz4gmuw0i = _rtDW -> lzjsh0qxsz ; } else {
j0jhyqa1p3 = ssGetTaskTime ( S , 0 ) - _rtDW -> mg242c3vwq ; liz4gmuw0i =
_rtDW -> oiqwpboxgd ; } iu0uolp1g0 = j0jhyqa1p3 * _rtP -> P_215 ; avdc0fgs2h
= _rtB -> dn5hp2o2lu - liz4gmuw0i ; if ( avdc0fgs2h > iu0uolp1g0 ) { _rtB ->
flcpkzs4x3 = liz4gmuw0i + iu0uolp1g0 ; } else { j0jhyqa1p3 *= _rtP -> P_216 ;
if ( avdc0fgs2h < j0jhyqa1p3 ) { _rtB -> flcpkzs4x3 = liz4gmuw0i + j0jhyqa1p3
; } else { _rtB -> flcpkzs4x3 = _rtB -> dn5hp2o2lu ; } } } nuxercq3rg = _rtB
-> chfkvxnrn5 * _rtB -> om5h3x44fj ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { i =
( int32_T ) ( ( ( ( ( uint32_T ) ( _rtB -> a5nxuv3afw < _rtP -> P_217 ) << 1
) + ( _rtB -> a5nxuv3afw > _rtP -> P_218 ) ) << 1 ) + _rtDW -> bvad1zjfik ) ;
_rtB -> jjneelk2gr [ 0U ] = _rtP -> P_476 [ ( uint32_T ) i ] ; _rtB ->
jjneelk2gr [ 1U ] = _rtP -> P_476 [ i + 8U ] ; } ouvslzwll4 = _rtB ->
jjneelk2gr [ 0 ] ; _rtB -> ka4y32teig = _rtP -> P_219 * ouvslzwll4 ; if ( (
_rtDW -> hfvh40s0je >= ssGetTaskTime ( S , 0 ) ) && ( _rtDW -> f41a3yqptq >=
ssGetTaskTime ( S , 0 ) ) ) { _rtB -> pwgh3s5ueh = _rtB -> ka4y32teig ; }
else { if ( ( ( _rtDW -> hfvh40s0je < _rtDW -> f41a3yqptq ) && ( _rtDW ->
f41a3yqptq < ssGetTaskTime ( S , 0 ) ) ) || ( ( _rtDW -> hfvh40s0je >= _rtDW
-> f41a3yqptq ) && ( _rtDW -> hfvh40s0je >= ssGetTaskTime ( S , 0 ) ) ) ) {
j0jhyqa1p3 = ssGetTaskTime ( S , 0 ) - _rtDW -> f41a3yqptq ; liz4gmuw0i =
_rtDW -> aq3qjo4ji4 ; } else { j0jhyqa1p3 = ssGetTaskTime ( S , 0 ) - _rtDW
-> hfvh40s0je ; liz4gmuw0i = _rtDW -> lidlmlim32 ; } iu0uolp1g0 = j0jhyqa1p3
* _rtP -> P_220 ; avdc0fgs2h = _rtB -> ka4y32teig - liz4gmuw0i ; if (
avdc0fgs2h > iu0uolp1g0 ) { _rtB -> pwgh3s5ueh = liz4gmuw0i + iu0uolp1g0 ; }
else { j0jhyqa1p3 *= _rtP -> P_221 ; if ( avdc0fgs2h < j0jhyqa1p3 ) { _rtB ->
pwgh3s5ueh = liz4gmuw0i + j0jhyqa1p3 ; } else { _rtB -> pwgh3s5ueh = _rtB ->
ka4y32teig ; } } } j0jhyqa1p3 = nuxercq3rg - _rtB -> pwgh3s5ueh ; ouvslzwll4
= muDoubleScalarAbs ( j0jhyqa1p3 ) ; ouvslzwll4 = _rtP -> P_224 * rt_Lookup (
_rtP -> P_222 , 84 , ouvslzwll4 , _rtP -> P_223 ) ; if ( ouvslzwll4 > _rtP ->
P_225 ) { liz4gmuw0i = _rtP -> P_225 ; } else if ( ouvslzwll4 < _rtP -> P_226
) { liz4gmuw0i = _rtP -> P_226 ; } else { liz4gmuw0i = ouvslzwll4 ; }
iu0uolp1g0 = _rtP -> P_227 * liz4gmuw0i ; if ( ssIsMajorTimeStep ( S ) ) { if
( nuxercq3rg >= _rtP -> P_228 ) { _rtDW -> guq5pq4c5s = true ; } else { if (
nuxercq3rg <= _rtP -> P_229 ) { _rtDW -> guq5pq4c5s = false ; } } } if (
ssIsSampleHit ( S , 1 , 0 ) ) { if ( _rtDW -> guq5pq4c5s ) { _rtB ->
f34ibfp31c = ! ( _rtP -> P_230 != 0.0 ) ; } else { _rtB -> f34ibfp31c = ! (
_rtP -> P_231 != 0.0 ) ; } _rtB -> mf2my5aghd = ( _rtDW -> aln04uuynj !=
ld5zvvrfqt ( S ) -> b4f4uenpnn ) ; _rtB -> oyjweedlls = _rtDW -> nlh5qppt4m ;
} if ( _rtB -> f34ibfp31c || ( ( nuxercq3rg > ld5zvvrfqt ( S ) -> elq1semnqj
) && _rtB -> mf2my5aghd ) ) { if ( j0jhyqa1p3 > _rtP -> P_13 ) { j0jhyqa1p3 =
_rtP -> P_13 ; } else { if ( j0jhyqa1p3 < _rtP -> P_14 ) { j0jhyqa1p3 = _rtP
-> P_14 ; } } _rtB -> g0w54d32ej = 1.0 / iu0uolp1g0 * j0jhyqa1p3 * _rtB ->
flcpkzs4x3 ; } else { _rtB -> g0w54d32ej = _rtB -> oyjweedlls ; } ouvslzwll4
= 1.0 / iu0uolp1g0 * _rtB -> b5bpyg4l3b ; if ( ouvslzwll4 > _rtP -> P_236 ) {
liz4gmuw0i = _rtP -> P_236 ; } else if ( ouvslzwll4 < _rtP -> P_237 ) {
liz4gmuw0i = _rtP -> P_237 ; } else { liz4gmuw0i = ouvslzwll4 ; } liz4gmuw0i
= _rtB -> flcpkzs4x3 * _rtB -> g0w54d32ej * liz4gmuw0i * _rtP -> P_238 ; if (
liz4gmuw0i > neooptatmt ) { _rtB -> pjcfg2e3fk = neooptatmt ; } else {
neooptatmt *= _rtP -> P_12 ; if ( liz4gmuw0i < neooptatmt ) { _rtB ->
pjcfg2e3fk = neooptatmt ; } else { _rtB -> pjcfg2e3fk = liz4gmuw0i ; } } if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> gckftarsru = _rtP -> P_240 ; }
ouvslzwll4 = _rtP -> P_239 * _rtB -> pjcfg2e3fk * _rtB -> gckftarsru ; if ( (
_rtDW -> mtptmi2003 == ( rtMinusInf ) ) || ( _rtDW -> mtptmi2003 ==
ssGetTaskTime ( S , 0 ) ) ) { _rtDW -> mtptmi2003 = ssGetTaskTime ( S , 0 ) ;
_rtB -> c4u32gdnaq = _rtP -> P_241 ; } else { _rtB -> c4u32gdnaq = ouvslzwll4
; } if ( ( _rtDW -> efkpcjgjek >= ssGetTaskTime ( S , 0 ) ) && ( _rtDW ->
hnoimzxxep >= ssGetTaskTime ( S , 0 ) ) ) { _rtB -> h25hr2ldko = _rtB ->
c4u32gdnaq ; } else { if ( ( ( _rtDW -> efkpcjgjek < _rtDW -> hnoimzxxep ) &&
( _rtDW -> hnoimzxxep < ssGetTaskTime ( S , 0 ) ) ) || ( ( _rtDW ->
efkpcjgjek >= _rtDW -> hnoimzxxep ) && ( _rtDW -> efkpcjgjek >= ssGetTaskTime
( S , 0 ) ) ) ) { j0jhyqa1p3 = ssGetTaskTime ( S , 0 ) - _rtDW -> hnoimzxxep
; liz4gmuw0i = _rtDW -> b5egd0vrtp ; } else { j0jhyqa1p3 = ssGetTaskTime ( S
, 0 ) - _rtDW -> efkpcjgjek ; liz4gmuw0i = _rtDW -> oyyqrjxbur ; } iu0uolp1g0
= j0jhyqa1p3 * _rtP -> P_242 ; avdc0fgs2h = _rtB -> c4u32gdnaq - liz4gmuw0i ;
if ( avdc0fgs2h > iu0uolp1g0 ) { _rtB -> h25hr2ldko = liz4gmuw0i + iu0uolp1g0
; } else { j0jhyqa1p3 *= _rtP -> P_243 ; if ( avdc0fgs2h < j0jhyqa1p3 ) {
_rtB -> h25hr2ldko = liz4gmuw0i + j0jhyqa1p3 ; } else { _rtB -> h25hr2ldko =
_rtB -> c4u32gdnaq ; } } } if ( ssIsSampleHit ( S , 2 , 0 ) ) { dztyrqu4xa =
_rtP -> P_244 * _rtDW -> lmxxx3r01a ; payjt4hwej = _rtB -> h25hr2ldko -
dztyrqu4xa ; } if ( ssIsSampleHit ( S , 1 , 0 ) && ssIsSampleHit ( S , 2 , 0
) ) { _rtB -> nfni5wm2s2 = _rtB -> gckftarsru ; } if ( ssIsSampleHit ( S , 2
, 0 ) ) { neooptatmt = payjt4hwej * _rtB -> nfni5wm2s2 ; _rtB -> gryl5xpbjt =
_rtP -> P_247 * neooptatmt ; if ( _rtDW -> ptsgdhh2pm != 0 ) { _rtB ->
jmel44rsxo = _rtDW -> epthsan5zc ; } else { _rtB -> jmel44rsxo = _rtP ->
P_248 * _rtB -> gryl5xpbjt + _rtDW -> epthsan5zc ; } if ( _rtB -> jmel44rsxo
>= _rtP -> P_250 ) { _rtB -> jmel44rsxo = _rtP -> P_250 ; } else { if ( _rtB
-> jmel44rsxo <= _rtP -> P_251 ) { _rtB -> jmel44rsxo = _rtP -> P_251 ; } }
if ( ( int32_T ) jcpcoishnw == 1 ) { dztyrqu4xa = _rtP -> P_4 * neooptatmt +
_rtB -> jmel44rsxo ; } else { dztyrqu4xa = _rtB -> c4u32gdnaq ; } if (
dztyrqu4xa > _rtP -> P_252 ) { dztyrqu4xa = _rtP -> P_252 ; } else { if (
dztyrqu4xa < _rtP -> P_253 ) { dztyrqu4xa = _rtP -> P_253 ; } } neooptatmt =
_rtP -> P_254 * dztyrqu4xa ; hvqfirrur0 = - mvo1vu4fxh * olptcjth3h +
neooptatmt * plqe5rftf1 ; oqvhvuyyrz = _rtP -> P_255 * hvqfirrur0 ;
avdc0fgs2h = oqvhvuyyrz - epi0kh5ytt_idx_0 ; if ( avdc0fgs2h >= _rtP -> P_256
) { _rtDW -> mdrfaaqhlc = true ; } else { if ( avdc0fgs2h <= _rtP -> P_257 )
{ _rtDW -> mdrfaaqhlc = false ; } } plqe5rftf1 = ( 1.7320508 * olptcjth3h + -
plqe5rftf1 ) * neooptatmt * 0.5 + ( 1.7320508 * plqe5rftf1 + olptcjth3h ) *
mvo1vu4fxh * 0.5 ; m2kgveajrn = _rtP -> P_260 * plqe5rftf1 ; neooptatmt =
m2kgveajrn - epi0kh5ytt_idx_1 ; if ( neooptatmt >= _rtP -> P_261 ) { _rtDW ->
hi5e5wjvfn = true ; } else { if ( neooptatmt <= _rtP -> P_262 ) { _rtDW ->
hi5e5wjvfn = false ; } } if ( _rtDW -> hi5e5wjvfn ) { neooptatmt = _rtP ->
P_263 ; } else { neooptatmt = _rtP -> P_264 ; } if ( _rtDW -> mdrfaaqhlc ) {
liz4gmuw0i = _rtP -> P_258 ; } else { liz4gmuw0i = _rtP -> P_259 ; }
avdc0fgs2h = liz4gmuw0i - neooptatmt ; l1mscynyvk = ( ( 0.0 - plqe5rftf1 ) -
hvqfirrur0 ) * _rtP -> P_265 ; hvqfirrur0 = l1mscynyvk - epi0kh5ytt_idx_2 ;
if ( hvqfirrur0 >= _rtP -> P_266 ) { _rtDW -> ltj2mwt3by = true ; } else { if
( hvqfirrur0 <= _rtP -> P_267 ) { _rtDW -> ltj2mwt3by = false ; } } if (
_rtDW -> ltj2mwt3by ) { liz4gmuw0i = _rtP -> P_268 ; } else { liz4gmuw0i =
_rtP -> P_269 ; } neooptatmt -= liz4gmuw0i ; hvqfirrur0 = _rtB -> gckftarsru
; _rtB -> ejjtlyhwm0 [ 0 ] = avdc0fgs2h * _rtB -> gckftarsru * _rtB ->
llaqeksi04 ; _rtB -> ejjtlyhwm0 [ 1 ] = neooptatmt * _rtB -> gckftarsru *
_rtB -> llaqeksi04 ; _rtB -> imsqyxysdt = _rtDW -> m4x03oyk3f ; _rtB ->
hazljvwcqv [ 0 ] = _rtDW -> baieefy5w1 [ 0 ] ; _rtB -> hazljvwcqv [ 1 ] =
_rtDW -> baieefy5w1 [ 1 ] ; _rtB -> hazljvwcqv [ 2 ] = _rtDW -> baieefy5w1 [
2 ] ; if ( ssIsSampleHit ( S , 3 , 0 ) ) { _rtB -> mpr0ootgj0 [ 0 ] = _rtB ->
hazljvwcqv [ 0 ] ; _rtB -> mpr0ootgj0 [ 1 ] = _rtB -> hazljvwcqv [ 1 ] ; _rtB
-> mpr0ootgj0 [ 2 ] = _rtB -> hazljvwcqv [ 2 ] ; } _rtB -> hdnbxtnlcj =
ojp40wkotz / 4.0 ; if ( ssIsSampleHit ( S , 3 , 0 ) ) { _rtB -> igu0y1ftzm =
_rtB -> hdnbxtnlcj ; } } if ( ssIsSampleHit ( S , 3 , 0 ) ) { pogyapcinw =
_rtP -> P_272 * _rtB -> igu0y1ftzm ; eq33yxixok = muDoubleScalarCos (
pogyapcinw ) ; pogyapcinw = muDoubleScalarSin ( pogyapcinw ) ; if (
ssIsSampleHit ( S , 4 , 0 ) ) { _rtB -> l1v3xllygg = _rtDW -> afj2f0hafp ; }
_rtB -> bzysyf03ne = _rtP -> P_274 * _rtB -> l1v3xllygg ; } if ( ( _rtDW ->
kzeshw3sd4 >= ssGetTaskTime ( S , 0 ) ) && ( _rtDW -> kzvthvykyq >=
ssGetTaskTime ( S , 0 ) ) ) { _rtB -> nv35kgxb2v = _rtB -> bzysyf03ne ; }
else { if ( ( ( _rtDW -> kzeshw3sd4 < _rtDW -> kzvthvykyq ) && ( _rtDW ->
kzvthvykyq < ssGetTaskTime ( S , 0 ) ) ) || ( ( _rtDW -> kzeshw3sd4 >= _rtDW
-> kzvthvykyq ) && ( _rtDW -> kzeshw3sd4 >= ssGetTaskTime ( S , 0 ) ) ) ) {
j0jhyqa1p3 = ssGetTaskTime ( S , 0 ) - _rtDW -> kzvthvykyq ; liz4gmuw0i =
_rtDW -> fstidsd2mk ; } else { j0jhyqa1p3 = ssGetTaskTime ( S , 0 ) - _rtDW
-> kzeshw3sd4 ; liz4gmuw0i = _rtDW -> ag11bw3z1w ; } iu0uolp1g0 = j0jhyqa1p3
* _rtP -> P_275 ; avdc0fgs2h = _rtB -> bzysyf03ne - liz4gmuw0i ; if (
avdc0fgs2h > iu0uolp1g0 ) { _rtB -> nv35kgxb2v = liz4gmuw0i + iu0uolp1g0 ; }
else { j0jhyqa1p3 *= _rtP -> P_276 ; if ( avdc0fgs2h < j0jhyqa1p3 ) { _rtB ->
nv35kgxb2v = liz4gmuw0i + j0jhyqa1p3 ; } else { _rtB -> nv35kgxb2v = _rtB ->
bzysyf03ne ; } } } ouvslzwll4 = muDoubleScalarAbs ( _rtB -> nv35kgxb2v ) ;
_rtB -> jzbao1mbfm = rt_Lookup ( _rtP -> P_277 , 301 , ouvslzwll4 , _rtP ->
P_278 ) ; if ( ssIsSampleHit ( S , 3 , 0 ) ) { _rtB -> oefbfiqfen = _rtB ->
om5h3x44fj ; _rtB -> otzgbcwgfg = _rtP -> P_279 ; for ( i = 0 ; i < 5 ; i ++
) { _rtB -> bwxtdjc24k [ i ] = _rtP -> P_280 [ i ] ; } ssCallAccelRunBlock (
S , 11 , 0 , SS_CALL_MDL_OUTPUTS ) ; avdc0fgs2h = _rtB -> kb4ftsx3te - _rtDW
-> ifkyn0mekk ; if ( avdc0fgs2h > _rtP -> P_281 ) { liz4gmuw0i = _rtDW ->
ifkyn0mekk + _rtP -> P_281 ; } else if ( avdc0fgs2h < _rtP -> P_282 ) {
liz4gmuw0i = _rtDW -> ifkyn0mekk + _rtP -> P_282 ; } else { liz4gmuw0i = _rtB
-> kb4ftsx3te ; } _rtDW -> ifkyn0mekk = liz4gmuw0i ; liz4gmuw0i *= _rtP ->
P_284 ; avdc0fgs2h = _rtB -> am0qa2dpy1 - _rtDW -> k0zfnbgfkp ; if (
avdc0fgs2h > _rtP -> P_285 ) { neooptatmt = _rtDW -> k0zfnbgfkp + _rtP ->
P_285 ; } else if ( avdc0fgs2h < _rtP -> P_286 ) { neooptatmt = _rtDW ->
k0zfnbgfkp + _rtP -> P_286 ; } else { neooptatmt = _rtB -> am0qa2dpy1 ; }
_rtDW -> k0zfnbgfkp = neooptatmt ; neooptatmt *= _rtP -> P_288 ; j0jhyqa1p3 =
- liz4gmuw0i * pogyapcinw + neooptatmt * eq33yxixok ; _rtB -> limqng3g05 =
_rtP -> P_289 * j0jhyqa1p3 ; iu0uolp1g0 = _rtB -> limqng3g05 - _rtB ->
mpr0ootgj0 [ 0 ] ; if ( iu0uolp1g0 >= _rtP -> P_290 ) { _rtDW -> hm144hfxex =
true ; } else { if ( iu0uolp1g0 <= _rtP -> P_291 ) { _rtDW -> hm144hfxex =
false ; } } eq33yxixok = ( 1.7320508 * pogyapcinw + - eq33yxixok ) *
neooptatmt * 0.5 + ( 1.7320508 * eq33yxixok + pogyapcinw ) * liz4gmuw0i * 0.5
; _rtB -> fyzmfyzgzs = _rtP -> P_294 * eq33yxixok ; neooptatmt = _rtB ->
fyzmfyzgzs - _rtB -> mpr0ootgj0 [ 1 ] ; if ( neooptatmt >= _rtP -> P_295 ) {
_rtDW -> fm0ymeevnp = true ; } else { if ( neooptatmt <= _rtP -> P_296 ) {
_rtDW -> fm0ymeevnp = false ; } } if ( _rtDW -> fm0ymeevnp ) { neooptatmt =
_rtP -> P_297 ; } else { neooptatmt = _rtP -> P_298 ; } if ( _rtDW ->
hm144hfxex ) { liz4gmuw0i = _rtP -> P_292 ; } else { liz4gmuw0i = _rtP ->
P_293 ; } _rtB -> okn5jpaa4w = liz4gmuw0i - neooptatmt ; _rtB -> lguemj2h2f =
( ( 0.0 - eq33yxixok ) - j0jhyqa1p3 ) * _rtP -> P_299 ; iu0uolp1g0 = _rtB ->
lguemj2h2f - _rtB -> mpr0ootgj0 [ 2 ] ; if ( iu0uolp1g0 >= _rtP -> P_300 ) {
_rtDW -> pms13femcc = true ; } else { if ( iu0uolp1g0 <= _rtP -> P_301 ) {
_rtDW -> pms13femcc = false ; } } if ( _rtDW -> pms13femcc ) { liz4gmuw0i =
_rtP -> P_302 ; } else { liz4gmuw0i = _rtP -> P_303 ; } _rtB -> je4wud3xqu =
neooptatmt - liz4gmuw0i ; } if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB ->
dacdqmjrfy = _rtP -> P_304 ; nv5qtm3k1a [ 0 ] = _rtB -> okn5jpaa4w * _rtB ->
dacdqmjrfy ; nv5qtm3k1a [ 1 ] = _rtB -> je4wud3xqu * _rtB -> dacdqmjrfy ; if
( ssIsSampleHit ( S , 2 , 0 ) ) { _rtB -> pk4gx3y1dh [ 0 ] = nv5qtm3k1a [ 0 ]
; _rtB -> pk4gx3y1dh [ 1 ] = nv5qtm3k1a [ 1 ] ; } } if ( ssIsSampleHit ( S ,
2 , 0 ) ) { _rtB -> crwk5ua5ah [ 0 ] = _rtB -> imsqyxysdt * _rtB ->
pk4gx3y1dh [ 0 ] ; _rtB -> crwk5ua5ah [ 1 ] = _rtB -> imsqyxysdt * _rtB ->
pk4gx3y1dh [ 1 ] ; _rtB -> hkzkvvck2b = _rtDW -> pot2tvweea ; plykbgk15o = (
hvqfirrur0 != 0.0 ) ; zcEvent_idx_0 = rt_ZCFcn ( ANY_ZERO_CROSSING , & _rtZCE
-> gn3hyklx0i [ 0 ] , ( oqvhvuyyrz - _rtP -> P_306 ) ) ; zcEvent_idx_1 =
rt_ZCFcn ( ANY_ZERO_CROSSING , & _rtZCE -> gn3hyklx0i [ 1 ] , ( m2kgveajrn -
_rtP -> P_306 ) ) ; zcEvent_idx_2 = rt_ZCFcn ( ANY_ZERO_CROSSING , & _rtZCE
-> gn3hyklx0i [ 2 ] , ( l1mscynyvk - _rtP -> P_306 ) ) ; if ( _rtDW ->
p5ivrte15o [ 0 ] == 0 ) { if ( zcEvent_idx_0 != NO_ZCEVENT ) { _rtB ->
mitpoaehu1 [ 0 ] = ! _rtB -> mitpoaehu1 [ 0 ] ; _rtDW -> p5ivrte15o [ 0 ] = 1
; } else if ( _rtB -> mitpoaehu1 [ 0 ] ) { if ( oqvhvuyyrz != _rtP -> P_306 )
{ _rtB -> mitpoaehu1 [ 0 ] = false ; } } else { if ( oqvhvuyyrz == _rtP ->
P_306 ) { _rtB -> mitpoaehu1 [ 0 ] = true ; } } } else { if ( oqvhvuyyrz !=
_rtP -> P_306 ) { _rtB -> mitpoaehu1 [ 0 ] = false ; } _rtDW -> p5ivrte15o [
0 ] = 0 ; } if ( _rtDW -> p5ivrte15o [ 1 ] == 0 ) { if ( zcEvent_idx_1 !=
NO_ZCEVENT ) { _rtB -> mitpoaehu1 [ 1 ] = ! _rtB -> mitpoaehu1 [ 1 ] ; _rtDW
-> p5ivrte15o [ 1 ] = 1 ; } else if ( _rtB -> mitpoaehu1 [ 1 ] ) { if (
m2kgveajrn != _rtP -> P_306 ) { _rtB -> mitpoaehu1 [ 1 ] = false ; } } else {
if ( m2kgveajrn == _rtP -> P_306 ) { _rtB -> mitpoaehu1 [ 1 ] = true ; } } }
else { if ( m2kgveajrn != _rtP -> P_306 ) { _rtB -> mitpoaehu1 [ 1 ] = false
; } _rtDW -> p5ivrte15o [ 1 ] = 0 ; } if ( _rtDW -> p5ivrte15o [ 2 ] == 0 ) {
if ( zcEvent_idx_2 != NO_ZCEVENT ) { _rtB -> mitpoaehu1 [ 2 ] = ! _rtB ->
mitpoaehu1 [ 2 ] ; _rtDW -> p5ivrte15o [ 2 ] = 1 ; } else if ( _rtB ->
mitpoaehu1 [ 2 ] ) { if ( l1mscynyvk != _rtP -> P_306 ) { _rtB -> mitpoaehu1
[ 2 ] = false ; } } else { if ( l1mscynyvk == _rtP -> P_306 ) { _rtB ->
mitpoaehu1 [ 2 ] = true ; } } } else { if ( l1mscynyvk != _rtP -> P_306 ) {
_rtB -> mitpoaehu1 [ 2 ] = false ; } _rtDW -> p5ivrte15o [ 2 ] = 0 ; }
keyxmz53xi ( S , _rtB -> mitpoaehu1 [ 0 ] , plykbgk15o , & _rtB ->
keyxmz53xiy , & _rtDW -> keyxmz53xiy ) ; keyxmz53xi ( S , _rtB -> mitpoaehu1
[ 1 ] , plykbgk15o , & _rtB -> d5h5wn4011 , & _rtDW -> d5h5wn4011 ) ;
keyxmz53xi ( S , _rtB -> mitpoaehu1 [ 2 ] , plykbgk15o , & _rtB -> hlr1ddtilb
, & _rtDW -> hlr1ddtilb ) ; avdc0fgs2h = _rtP -> P_307 * _rtDW -> nonllthbl2
; hvqfirrur0 = _rtP -> P_310 * _rtDW -> kol45dq53x ; g0desguayz *= _rtP ->
P_314 ; mvo1vu4fxh = muDoubleScalarSin ( g0desguayz ) ; g0desguayz =
muDoubleScalarCos ( g0desguayz ) ; olptcjth3h = ( 0.0 - mvo1vu4fxh * _rtP ->
P_315 ) - g0desguayz * _rtP -> P_316 ; plqe5rftf1 = mvo1vu4fxh * _rtP ->
P_316 - g0desguayz * _rtP -> P_315 ; liz4gmuw0i = ( avdc0fgs2h * mvo1vu4fxh +
hvqfirrur0 * g0desguayz ) + _rtP -> P_313 ; iu0uolp1g0 = ( avdc0fgs2h *
olptcjth3h + hvqfirrur0 * plqe5rftf1 ) + _rtP -> P_313 ; avdc0fgs2h = ( ( (
0.0 - olptcjth3h ) - mvo1vu4fxh ) * avdc0fgs2h + ( ( 0.0 - plqe5rftf1 ) -
g0desguayz ) * hvqfirrur0 ) + _rtP -> P_313 ; _rtB -> aevhkqzjvc [ 0 ] = (
real_T ) _rtB -> keyxmz53xiy . nxi25prvux * oqvhvuyyrz + _rtP -> P_317 *
liz4gmuw0i ; _rtB -> aevhkqzjvc [ 1 ] = ( real_T ) _rtB -> d5h5wn4011 .
nxi25prvux * m2kgveajrn + _rtP -> P_317 * iu0uolp1g0 ; _rtB -> aevhkqzjvc [ 2
] = ( real_T ) _rtB -> hlr1ddtilb . nxi25prvux * l1mscynyvk + _rtP -> P_317 *
avdc0fgs2h ; if ( _rtDW -> ehaijafsot > _rtP -> P_320 ) { liz4gmuw0i = _rtP
-> P_320 ; } else if ( _rtDW -> ehaijafsot < _rtP -> P_321 ) { liz4gmuw0i =
_rtP -> P_321 ; } else { liz4gmuw0i = _rtDW -> ehaijafsot ; } _rtB ->
pdtpz4ahix = _rtDW -> fw2k5vojpd / liz4gmuw0i ; } if ( ssIsSampleHit ( S , 1
, 0 ) ) { o3uvutavac = ( _rtB -> dacdqmjrfy != 0.0 ) ; } if ( ssIsSampleHit (
S , 3 , 0 ) ) { zcEvent_idx_0 = rt_ZCFcn ( ANY_ZERO_CROSSING , & _rtZCE ->
iawgonhhkk [ 0 ] , ( _rtB -> limqng3g05 - _rtP -> P_322 ) ) ; zcEvent_idx_1 =
rt_ZCFcn ( ANY_ZERO_CROSSING , & _rtZCE -> iawgonhhkk [ 1 ] , ( _rtB ->
fyzmfyzgzs - _rtP -> P_322 ) ) ; zcEvent_idx_2 = rt_ZCFcn ( ANY_ZERO_CROSSING
, & _rtZCE -> iawgonhhkk [ 2 ] , ( _rtB -> lguemj2h2f - _rtP -> P_322 ) ) ;
if ( _rtDW -> lothx5dmyz [ 0 ] == 0 ) { if ( zcEvent_idx_0 != NO_ZCEVENT ) {
_rtB -> dbasalpnmf [ 0 ] = ! _rtB -> dbasalpnmf [ 0 ] ; _rtDW -> lothx5dmyz [
0 ] = 1 ; } else if ( _rtB -> dbasalpnmf [ 0 ] ) { if ( _rtB -> limqng3g05 !=
_rtP -> P_322 ) { _rtB -> dbasalpnmf [ 0 ] = false ; } } else { if ( _rtB ->
limqng3g05 == _rtP -> P_322 ) { _rtB -> dbasalpnmf [ 0 ] = true ; } } } else
{ if ( _rtB -> limqng3g05 != _rtP -> P_322 ) { _rtB -> dbasalpnmf [ 0 ] =
false ; } _rtDW -> lothx5dmyz [ 0 ] = 0 ; } if ( _rtDW -> lothx5dmyz [ 1 ] ==
0 ) { if ( zcEvent_idx_1 != NO_ZCEVENT ) { _rtB -> dbasalpnmf [ 1 ] = ! _rtB
-> dbasalpnmf [ 1 ] ; _rtDW -> lothx5dmyz [ 1 ] = 1 ; } else if ( _rtB ->
dbasalpnmf [ 1 ] ) { if ( _rtB -> fyzmfyzgzs != _rtP -> P_322 ) { _rtB ->
dbasalpnmf [ 1 ] = false ; } } else { if ( _rtB -> fyzmfyzgzs == _rtP ->
P_322 ) { _rtB -> dbasalpnmf [ 1 ] = true ; } } } else { if ( _rtB ->
fyzmfyzgzs != _rtP -> P_322 ) { _rtB -> dbasalpnmf [ 1 ] = false ; } _rtDW ->
lothx5dmyz [ 1 ] = 0 ; } if ( _rtDW -> lothx5dmyz [ 2 ] == 0 ) { if (
zcEvent_idx_2 != NO_ZCEVENT ) { _rtB -> dbasalpnmf [ 2 ] = ! _rtB ->
dbasalpnmf [ 2 ] ; _rtDW -> lothx5dmyz [ 2 ] = 1 ; } else if ( _rtB ->
dbasalpnmf [ 2 ] ) { if ( _rtB -> lguemj2h2f != _rtP -> P_322 ) { _rtB ->
dbasalpnmf [ 2 ] = false ; } } else { if ( _rtB -> lguemj2h2f == _rtP ->
P_322 ) { _rtB -> dbasalpnmf [ 2 ] = true ; } } } else { if ( _rtB ->
lguemj2h2f != _rtP -> P_322 ) { _rtB -> dbasalpnmf [ 2 ] = false ; } _rtDW ->
lothx5dmyz [ 2 ] = 0 ; } } h5wlu0jr4o ( S , _rtB -> dbasalpnmf [ 0 ] ,
o3uvutavac , & _rtB -> h5wlu0jr4oh , & _rtDW -> h5wlu0jr4oh ) ; h5wlu0jr4o (
S , _rtB -> dbasalpnmf [ 1 ] , o3uvutavac , & _rtB -> i4yjdoht2q , & _rtDW ->
i4yjdoht2q ) ; h5wlu0jr4o ( S , _rtB -> dbasalpnmf [ 2 ] , o3uvutavac , &
_rtB -> kbxxrvtle0 , & _rtDW -> kbxxrvtle0 ) ; if ( ssIsSampleHit ( S , 1 , 0
) && ssIsSampleHit ( S , 2 , 0 ) ) { _rtB -> n0xgmiihio [ 0 ] = ( real_T )
_rtB -> h5wlu0jr4oh . oyhdmurzjh * _rtB -> limqng3g05 ; _rtB -> n0xgmiihio [
1 ] = ( real_T ) _rtB -> i4yjdoht2q . oyhdmurzjh * _rtB -> fyzmfyzgzs ; _rtB
-> n0xgmiihio [ 2 ] = ( real_T ) _rtB -> kbxxrvtle0 . oyhdmurzjh * _rtB ->
lguemj2h2f ; } if ( ssIsSampleHit ( S , 2 , 0 ) ) { iu0uolp1g0 = _rtP ->
P_323 * _rtDW -> ifokpl3ags ; liz4gmuw0i = _rtP -> P_326 * _rtDW ->
bn3tyk4y03 ; avdc0fgs2h = _rtP -> P_330 * _rtB -> hdnbxtnlcj ; hvqfirrur0 =
muDoubleScalarSin ( avdc0fgs2h ) ; avdc0fgs2h = muDoubleScalarCos (
avdc0fgs2h ) ; plqe5rftf1 = ( 0.0 - hvqfirrur0 * _rtP -> P_331 ) - avdc0fgs2h
* _rtP -> P_332 ; neooptatmt = hvqfirrur0 * _rtP -> P_332 - avdc0fgs2h * _rtP
-> P_331 ; g0desguayz = ( iu0uolp1g0 * hvqfirrur0 + liz4gmuw0i * avdc0fgs2h )
+ _rtP -> P_329 ; olptcjth3h = ( iu0uolp1g0 * plqe5rftf1 + liz4gmuw0i *
neooptatmt ) + _rtP -> P_329 ; iu0uolp1g0 = ( ( ( 0.0 - plqe5rftf1 ) -
hvqfirrur0 ) * iu0uolp1g0 + ( ( 0.0 - neooptatmt ) - avdc0fgs2h ) *
liz4gmuw0i ) + _rtP -> P_329 ; _rtB -> hslx2kbnt5 [ 0 ] = _rtP -> P_333 *
g0desguayz + _rtB -> n0xgmiihio [ 0 ] ; _rtB -> hslx2kbnt5 [ 1 ] = _rtP ->
P_333 * olptcjth3h + _rtB -> n0xgmiihio [ 1 ] ; _rtB -> hslx2kbnt5 [ 2 ] =
_rtP -> P_333 * iu0uolp1g0 + _rtB -> n0xgmiihio [ 2 ] ; if ( _rtDW ->
macroyt1rc > _rtP -> P_336 ) { liz4gmuw0i = _rtP -> P_336 ; } else if ( _rtDW
-> macroyt1rc < _rtP -> P_337 ) { liz4gmuw0i = _rtP -> P_337 ; } else {
liz4gmuw0i = _rtDW -> macroyt1rc ; } _rtB -> nvg4y4skzd = _rtDW -> bjzaihqzlo
/ liz4gmuw0i ; _rtB -> k2ap2yn0fz = _rtDW -> jxow0tsi5b ; ssCallAccelRunBlock
( S , 20 , 512 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> atqoytqquv = _rtP -> P_339 *
_rtB -> g0fqnhdbap [ 29 ] ; _rtB -> coypa0wwsx = _rtP -> P_340 * _rtB ->
g0fqnhdbap [ 25 ] ; _rtB -> ak4z542xwc = _rtP -> P_341 * _rtB -> g0fqnhdbap [
33 ] ; _rtB -> illbukciz5 = _rtP -> P_342 * _rtB -> g0fqnhdbap [ 20 ] ; _rtB
-> kdhmigl2tf = _rtP -> P_343 * _rtB -> ak4z542xwc ; } if ( ssIsSampleHit ( S
, 1 , 0 ) ) { _rtB -> anbzkyt4t2 = _rtB -> ablhlgfu2w - _rtB -> kdhmigl2tf ;
ssCallAccelRunBlock ( S , 20 , 519 , SS_CALL_MDL_OUTPUTS ) ; } if (
ssIsSampleHit ( S , 2 , 0 ) ) { _rtB -> mpcurlrkqj = ( ( real_T ) ( _rtB ->
ak4z542xwc < ld5zvvrfqt ( S ) -> dow4g3bkrf ) * _rtP -> P_345 - _rtB ->
i5d2g2h5mw ) * muDoubleScalarAbs ( _rtB -> ak4z542xwc ) * _rtP -> P_346 ;
_rtB -> mizxc54qe4 = _rtP -> P_347 * eskeehll14 ; } ssCallAccelRunBlock ( S ,
20 , 550 , SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSampleHit ( S , 2 , 0 ) ) {
ssCallAccelRunBlock ( S , 20 , 551 , SS_CALL_MDL_OUTPUTS ) ; }
ssCallAccelRunBlock ( S , 20 , 552 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
buoxgxrmie = _rtP -> P_348 * _rtB -> om5h3x44fj ; if ( ssIsSampleHit ( S , 2
, 0 ) && ssIsSampleHit ( S , 4 , 0 ) ) { _rtB -> pi5fgk4fhv = _rtDW ->
gwbk0uviaf ; } _rtB -> fdmu3ib3vx = _rtB -> banzpsts4l * _rtB -> om5h3x44fj ;
ssCallAccelRunBlock ( S , 20 , 556 , SS_CALL_MDL_OUTPUTS ) ; if (
ssIsSampleHit ( S , 2 , 0 ) ) { ssCallAccelRunBlock ( S , 20 , 559 ,
SS_CALL_MDL_OUTPUTS ) ; iu0uolp1g0 = _rtP -> P_350 * _rtDW -> d3ojd0ilqw ;
liz4gmuw0i = _rtP -> P_353 * _rtDW -> p0opx5r1kj ; i = ( int32_T ) ( ( ( ( (
uint32_T ) ( iu0uolp1g0 > liz4gmuw0i ) << 1 ) + ( iu0uolp1g0 < _rtP -> P_356
* liz4gmuw0i ) ) << 1 ) + _rtDW -> jasnynsjlw ) ; _rtB -> kkh5yr3jb3 [ 0U ] =
_rtP -> P_478 [ ( uint32_T ) i ] ; _rtB -> kkh5yr3jb3 [ 1U ] = _rtP -> P_478
[ i + 8U ] ; fg2z5apswc = ( uint8_T ) ( _rtB -> kkh5yr3jb3 [ 0 ] ? ( int32_T
) _rtP -> P_481 : 0 ) ; _rtB -> a5eeritldw = ( real_T ) fg2z5apswc *
0.0078125 ; _rtB -> fk0tb50ghr = ( real_T ) fg2z5apswc * 0.0078125 ; _rtB ->
b4o5khndg3 = ( real_T ) fg2z5apswc * 0.0078125 ; f5v0rstk5i = ! ( fg2z5apswc
!= 0 ) ; _rtB -> ian4zddpuy = f5v0rstk5i ; _rtB -> o5ol0qf0yd = f5v0rstk5i ;
_rtB -> cs2jbhptzr = f5v0rstk5i ; iu0uolp1g0 = _rtP -> P_357 * _rtB ->
g0fqnhdbap [ 30 ] ; liz4gmuw0i = _rtP -> P_358 * _rtB -> g0fqnhdbap [ 31 ] ;
j0jhyqa1p3 = _rtP -> P_359 * _rtB -> g0fqnhdbap [ 32 ] ; _rtB -> cu3ee2hbin =
( ( iu0uolp1g0 * iu0uolp1g0 + liz4gmuw0i * liz4gmuw0i ) + j0jhyqa1p3 *
j0jhyqa1p3 ) * _rtP -> P_360 + ( _rtP -> P_361 * _rtB -> g0fqnhdbap [ 21 ] *
iu0uolp1g0 + _rtP -> P_362 * _rtB -> g0fqnhdbap [ 22 ] * liz4gmuw0i ) ; }
neooptatmt = muDoubleScalarPower ( ( 0.006391889398924 * _rtB -> om5h3x44fj *
_rtB -> llripu04eo + 0.0065 * _rtB -> er2owrz1gy ) + 0.702664574517444 * _rtB
-> om5h3x44fj , 2.0 ) + muDoubleScalarPower ( 0.0065 * _rtB -> llripu04eo -
0.008228209001868 * _rtB -> om5h3x44fj * _rtB -> er2owrz1gy , 2.0 ) ; if (
neooptatmt < 0.0 ) { neooptatmt = - muDoubleScalarSqrt ( - neooptatmt ) ; }
else { neooptatmt = muDoubleScalarSqrt ( neooptatmt ) ; } _rtB -> grtvvntr5n
= 1.5707963267948966 * neooptatmt ; if ( ssIsSampleHit ( S , 2 , 0 ) ) { _rtB
-> iixjexpwun = _rtP -> P_363 * _rtB -> g0fqnhdbap [ 23 ] ; _rtB ->
ce45zmtf1b = ( ( 2.0 * _rtB -> g0fqnhdbap [ 14 ] + _rtB -> g0fqnhdbap [ 15 ]
) * fv0yihlfgb + 1.7320508075688772 * _rtB -> g0fqnhdbap [ 15 ] * jlph3w5wgc
) * 0.33333333333333331 ; _rtB -> ilefg2fmot = ( ( 2.0 * _rtB -> g0fqnhdbap [
14 ] + _rtB -> g0fqnhdbap [ 15 ] ) * jlph3w5wgc + - 1.7320508075688772 * _rtB
-> g0fqnhdbap [ 15 ] * fv0yihlfgb ) * 0.33333333333333331 ; _rtB ->
ovjwigulwl = _rtP -> P_364 * _rtB -> ilefg2fmot ; } _rtB -> f1afn02nl1 = _rtP
-> P_365 * _rtB -> om5h3x44fj ; if ( ssIsSampleHit ( S , 2 , 0 ) ) { _rtB ->
prydf5fhn3 = _rtP -> P_367 * _rtB -> llripu04eo ; } _rtB -> kroja0nrao = _rtB
-> f1afn02nl1 * _rtB -> er2owrz1gy * _rtP -> P_366 + ( _rtB -> ovjwigulwl -
_rtB -> prydf5fhn3 ) ; if ( ssIsSampleHit ( S , 2 , 0 ) ) { _rtB ->
d2rq0msf4u = _rtP -> P_368 * _rtB -> ce45zmtf1b ; _rtB -> adclde2olc = _rtP
-> P_370 * _rtB -> er2owrz1gy ; } _rtB -> hxwzukm1sf = ( ( _rtB -> d2rq0msf4u
- _rtB -> adclde2olc ) - _rtB -> llripu04eo * _rtB -> f1afn02nl1 * _rtP ->
P_369 ) - _rtP -> P_371 * _rtB -> f1afn02nl1 ; if ( ssIsSampleHit ( S , 2 , 0
) ) { _rtB -> nzuqkjyb2c = _rtP -> P_372 * _rtB -> g0fqnhdbap [ 38 ] ; _rtB
-> ps4zrh023s = _rtP -> P_373 * _rtB -> g0fqnhdbap [ 39 ] ; _rtB ->
gfsxylt2pa = _rtP -> P_374 * _rtB -> g0fqnhdbap [ 40 ] ; } if ( ssIsSampleHit
( S , 4 , 0 ) ) { db4h41wmsv = _rtP -> P_375 ; } ouvslzwll4 =
muDoubleScalarAbs ( _rtB -> om5h3x44fj ) ; HEV_acc_LookUp_real_T_real_T ( & (
lx4pbfxtbc ) , _rtP -> P_377 , ouvslzwll4 , _rtP -> P_376 , 6U ) ; if ( _rtB
-> adbh334xzj > lx4pbfxtbc ) { ouvslzwll4 = lx4pbfxtbc ; } else { neooptatmt
= _rtP -> P_6 * lx4pbfxtbc ; if ( _rtB -> adbh334xzj < neooptatmt ) {
ouvslzwll4 = neooptatmt ; } else { ouvslzwll4 = _rtB -> adbh334xzj ; } }
ouvslzwll4 *= _rtB -> dacdqmjrfy ; if ( ( _rtDW -> lxzpaf0d00 == ( rtMinusInf
) ) || ( _rtDW -> lxzpaf0d00 == ssGetTaskTime ( S , 0 ) ) ) { _rtDW ->
lxzpaf0d00 = ssGetTaskTime ( S , 0 ) ; _rtB -> nuaccwsurs = _rtP -> P_378 ; }
else { _rtB -> nuaccwsurs = ouvslzwll4 ; } if ( ( _rtDW -> ohitnp3v2k >=
ssGetTaskTime ( S , 0 ) ) && ( _rtDW -> bmafymwoxg >= ssGetTaskTime ( S , 0 )
) ) { _rtB -> k5ixb4di45 = _rtB -> nuaccwsurs ; } else { if ( ( ( _rtDW ->
ohitnp3v2k < _rtDW -> bmafymwoxg ) && ( _rtDW -> bmafymwoxg < ssGetTaskTime (
S , 0 ) ) ) || ( ( _rtDW -> ohitnp3v2k >= _rtDW -> bmafymwoxg ) && ( _rtDW ->
ohitnp3v2k >= ssGetTaskTime ( S , 0 ) ) ) ) { j0jhyqa1p3 = ssGetTaskTime ( S
, 0 ) - _rtDW -> bmafymwoxg ; liz4gmuw0i = _rtDW -> phwxap45zp ; } else {
j0jhyqa1p3 = ssGetTaskTime ( S , 0 ) - _rtDW -> ohitnp3v2k ; liz4gmuw0i =
_rtDW -> dateb3z15w ; } iu0uolp1g0 = j0jhyqa1p3 * _rtP -> P_379 ; avdc0fgs2h
= _rtB -> nuaccwsurs - liz4gmuw0i ; if ( avdc0fgs2h > iu0uolp1g0 ) { _rtB ->
k5ixb4di45 = liz4gmuw0i + iu0uolp1g0 ; } else { j0jhyqa1p3 *= _rtP -> P_380 ;
if ( avdc0fgs2h < j0jhyqa1p3 ) { _rtB -> k5ixb4di45 = liz4gmuw0i + j0jhyqa1p3
; } else { _rtB -> k5ixb4di45 = _rtB -> nuaccwsurs ; } } } if ( ssIsSampleHit
( S , 4 , 0 ) ) { _rtB -> ppkn0j50uc = _rtB -> k5ixb4di45 ; bntecz3apr = _rtB
-> ppkn0j50uc - _rtP -> P_381 * _rtDW -> cok2lfoe2t ; } if ( ssIsSampleHit (
S , 1 , 0 ) && ssIsSampleHit ( S , 4 , 0 ) ) { _rtB -> oblrfxmr1w = _rtB ->
dacdqmjrfy ; } if ( ssIsSampleHit ( S , 4 , 0 ) ) { neooptatmt = bntecz3apr *
_rtB -> oblrfxmr1w ; _rtB -> ix2dwttwi3 = _rtP -> P_384 * neooptatmt ; if (
_rtDW -> gsqmr1likf != 0 ) { _rtB -> elqltztscy = _rtDW -> li02312w4a ; }
else { _rtB -> elqltztscy = _rtP -> P_385 * _rtB -> ix2dwttwi3 + _rtDW ->
li02312w4a ; } if ( _rtB -> elqltztscy >= _rtP -> P_387 ) { _rtB ->
elqltztscy = _rtP -> P_387 ; } else { if ( _rtB -> elqltztscy <= _rtP ->
P_388 ) { _rtB -> elqltztscy = _rtP -> P_388 ; } } _rtB -> pdmbilnwfz = _rtB
-> nuaccwsurs ; if ( ( int32_T ) db4h41wmsv == 1 ) { bntecz3apr = _rtP -> P_5
* neooptatmt + _rtB -> elqltztscy ; } else { bntecz3apr = _rtB -> pdmbilnwfz
; } if ( bntecz3apr > _rtP -> P_389 ) { _rtB -> dk5wpb3wiw = _rtP -> P_389 ;
} else if ( bntecz3apr < _rtP -> P_390 ) { _rtB -> dk5wpb3wiw = _rtP -> P_390
; } else { _rtB -> dk5wpb3wiw = bntecz3apr ; } } _rtB -> d5hta5akos = _rtB ->
om5h3x44fj * _rtB -> dacdqmjrfy * _rtP -> P_391 ; if ( ssIsSampleHit ( S , 4
, 0 ) ) { _rtB -> g3rjxatquz = _rtB -> d5hta5akos ; _rtB -> fjybkm2pos = _rtB
-> dk5wpb3wiw * _rtB -> oblrfxmr1w ; } if ( ssIsSampleHit ( S , 2 , 0 ) ) {
ssCallAccelRunBlock ( S , 20 , 722 , SS_CALL_MDL_OUTPUTS ) ; }
ssCallAccelRunBlock ( S , 20 , 723 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
buoxgxrmie = _rtP -> P_392 * _rtB -> kn5iczv3qt ; if ( ssIsSampleHit ( S , 2
, 0 ) ) { _rtB -> jmumasjwoo = dztyrqu4xa * _rtB -> nfni5wm2s2 ; } _rtB ->
fdmu3ib3vx = _rtB -> ncba5bfobt * _rtB -> kn5iczv3qt ; ssCallAccelRunBlock (
S , 20 , 727 , SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSampleHit ( S , 2 , 0 ) ) {
iu0uolp1g0 = _rtP -> P_393 * _rtDW -> dy4ppyw4mo ; liz4gmuw0i = _rtP -> P_396
* _rtDW -> hmybg5b1mi ; i = ( int32_T ) ( ( ( ( ( uint32_T ) ( iu0uolp1g0 >
liz4gmuw0i ) << 1 ) + ( iu0uolp1g0 < _rtP -> P_399 * liz4gmuw0i ) ) << 1 ) +
_rtDW -> gkq12xkctn ) ; _rtB -> kqyvrrud5e [ 0U ] = _rtP -> P_480 [ (
uint32_T ) i ] ; _rtB -> kqyvrrud5e [ 1U ] = _rtP -> P_480 [ i + 8U ] ;
fg2z5apswc = ( uint8_T ) ( _rtB -> kqyvrrud5e [ 0 ] ? ( int32_T ) _rtP ->
P_482 : 0 ) ; _rtB -> d4zn525trt = ( real_T ) fg2z5apswc * 0.0078125 ; _rtB
-> h2ovzc1qc5 = ( real_T ) fg2z5apswc * 0.0078125 ; _rtB -> bx2fj52lsp = (
real_T ) fg2z5apswc * 0.0078125 ; f5v0rstk5i = ! ( fg2z5apswc != 0 ) ; _rtB
-> ggjsutryci = f5v0rstk5i ; _rtB -> ihlvhz5ld2 = f5v0rstk5i ; _rtB ->
jshj010rml = f5v0rstk5i ; iu0uolp1g0 = _rtP -> P_400 * _rtB -> g0fqnhdbap [
26 ] ; liz4gmuw0i = _rtP -> P_401 * _rtB -> g0fqnhdbap [ 27 ] ; j0jhyqa1p3 =
_rtP -> P_402 * _rtB -> g0fqnhdbap [ 28 ] ; _rtB -> fq41tauxr3 = ( (
iu0uolp1g0 * iu0uolp1g0 + liz4gmuw0i * liz4gmuw0i ) + j0jhyqa1p3 * j0jhyqa1p3
) * _rtP -> P_403 + ( _rtP -> P_404 * _rtB -> g0fqnhdbap [ 17 ] * iu0uolp1g0
+ _rtP -> P_405 * _rtB -> g0fqnhdbap [ 18 ] * liz4gmuw0i ) ; } neooptatmt =
muDoubleScalarPower ( ( 0.000635 * _rtB -> kn5iczv3qt * _rtB -> axxu2c2pmu +
0.05 * _rtB -> pkc13jitsl ) + 0.192 * _rtB -> kn5iczv3qt , 2.0 ) +
muDoubleScalarPower ( 0.05 * _rtB -> axxu2c2pmu - 0.000635 * _rtB ->
kn5iczv3qt * _rtB -> pkc13jitsl , 2.0 ) ; if ( neooptatmt < 0.0 ) {
neooptatmt = - muDoubleScalarSqrt ( - neooptatmt ) ; } else { neooptatmt =
muDoubleScalarSqrt ( neooptatmt ) ; } _rtB -> a5dmhfwwiy = 1.5707963267948966
* neooptatmt ; if ( ssIsSampleHit ( S , 2 , 0 ) ) { _rtB -> f1fhleshzz = _rtP
-> P_406 * _rtB -> g0fqnhdbap [ 19 ] ; _rtB -> mxnkobt05b = _rtP -> P_407 *
_rtB -> g0fqnhdbap [ 35 ] ; _rtB -> gutl50bysc = _rtP -> P_408 * _rtB ->
g0fqnhdbap [ 36 ] ; _rtB -> krhsfzevx2 = _rtP -> P_409 * _rtB -> g0fqnhdbap [
37 ] ; _rtB -> ocd0msjtdk = ( ( 2.0 * _rtB -> g0fqnhdbap [ 12 ] + _rtB ->
g0fqnhdbap [ 13 ] ) * mkcfwi2fsi + 1.7320508075688772 * _rtB -> g0fqnhdbap [
13 ] * ehtkh2wauy ) * 0.33333333333333331 ; _rtB -> auf0j5mrv2 = ( ( 2.0 *
_rtB -> g0fqnhdbap [ 12 ] + _rtB -> g0fqnhdbap [ 13 ] ) * ehtkh2wauy + -
1.7320508075688772 * _rtB -> g0fqnhdbap [ 13 ] * mkcfwi2fsi ) *
0.33333333333333331 ; _rtB -> aqri2uygh1 = _rtP -> P_410 * _rtB -> auf0j5mrv2
; } _rtB -> bn4et2idix = _rtP -> P_411 * _rtB -> kn5iczv3qt ; if (
ssIsSampleHit ( S , 2 , 0 ) ) { _rtB -> lziniaj3qy = _rtP -> P_413 * _rtB ->
axxu2c2pmu ; } _rtB -> bhqfjhd35i = _rtB -> bn4et2idix * _rtB -> pkc13jitsl *
_rtP -> P_412 + ( _rtB -> aqri2uygh1 - _rtB -> lziniaj3qy ) ; if (
ssIsSampleHit ( S , 2 , 0 ) ) { _rtB -> k1jw2yhjty = _rtP -> P_414 * _rtB ->
ocd0msjtdk ; _rtB -> mm20c5juwn = _rtP -> P_416 * _rtB -> pkc13jitsl ; } _rtB
-> het12fgs0x = ( ( _rtB -> k1jw2yhjty - _rtB -> mm20c5juwn ) - _rtB ->
axxu2c2pmu * _rtB -> bn4et2idix * _rtP -> P_415 ) - _rtP -> P_417 * _rtB ->
bn4et2idix ; _rtB -> lo5vdkxxcf = _rtB -> kn5iczv3qt * _rtB -> gckftarsru *
_rtP -> P_418 ; if ( ssIsSampleHit ( S , 2 , 0 ) ) { _rtB -> phmx5ph1e0 =
_rtB -> lo5vdkxxcf ; } ouvslzwll4 = ssGetT ( S ) ; if ( ssIsSampleHit ( S , 1
, 0 ) ) { _rtB -> lhcreccaiy = _rtP -> P_419 ; } fg2z5apswc = ( uint8_T ) (
ouvslzwll4 > _rtB -> lhcreccaiy ) ; _rtB -> o1d3acsooj = 0.0 ; _rtB ->
o1d3acsooj += _rtP -> P_421 * _rtX -> jevixzbezd ; if ( ssIsSampleHit ( S , 1
, 0 ) ) { _rtB -> oac5iadqib = _rtP -> P_422 ; } ouvslzwll4 = _rtB ->
o1d3acsooj - _rtB -> oac5iadqib ; nuxercq3rg = ouvslzwll4 * ( real_T )
fg2z5apswc ; _rtB -> bs2keii2w3 = _rtP -> P_424 * nuxercq3rg ; if (
ssIsSampleHit ( S , 2 , 0 ) ) { if ( _rtDW -> kx3vg4xtiw != 0 ) { _rtB ->
nex55iphrg = _rtDW -> oyhpvg4ubg ; } else { _rtB -> nex55iphrg = _rtP ->
P_425 * _rtB -> bs2keii2w3 + _rtDW -> oyhpvg4ubg ; } if ( _rtB -> nex55iphrg
>= _rtP -> P_427 ) { _rtB -> nex55iphrg = _rtP -> P_427 ; } else { if ( _rtB
-> nex55iphrg <= _rtP -> P_428 ) { _rtB -> nex55iphrg = _rtP -> P_428 ; } } }
ouvslzwll4 = _rtP -> P_423 * nuxercq3rg + _rtB -> nex55iphrg ; if (
ouvslzwll4 > _rtP -> P_429 ) { liz4gmuw0i = _rtP -> P_429 ; } else if (
ouvslzwll4 < _rtP -> P_430 ) { liz4gmuw0i = _rtP -> P_430 ; } else {
liz4gmuw0i = ouvslzwll4 ; } _rtB -> p1vvzotek4 = ( liz4gmuw0i + 1.0 ) * 0.5 ;
if ( ssIsSampleHit ( S , 2 , 0 ) ) { _rtB -> aneznbcibh = _rtP -> P_432 *
_rtB -> g0fqnhdbap [ 16 ] ; _rtB -> py4j2jpqpv = _rtP -> P_433 * _rtB ->
g0fqnhdbap [ 24 ] * _rtDW -> dwrzgh5jph ; _rtB -> oqoozlooh0 = _rtP -> P_434
* _rtB -> g0fqnhdbap [ 34 ] * _rtDW -> dwrzgh5jph ; } ssCallAccelRunBlock ( S
, 20 , 922 , SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 20 , 923 ,
SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSampleHit ( S , 2 , 0 ) ) {
ssCallAccelRunBlock ( S , 20 , 924 , SS_CALL_MDL_OUTPUTS ) ; }
ssCallAccelRunBlock ( S , 20 , 925 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 20 , 926 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 20 , 927 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 20 , 928 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 20 , 929 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 20 , 930 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 20 , 931 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
e4cfdkzr0b = muDoubleScalarAbs ( _rtB -> lhox1aa1pw ) ; if ( ( _rtDW ->
ahaacov03d >= ssGetT ( S ) ) && ( _rtDW -> jomnbzdhyn >= ssGetT ( S ) ) ) {
_rtB -> gb4ja2yabm = 0.0 ; } else { neooptatmt = _rtDW -> ahaacov03d ; lastU
= & _rtDW -> irq44heqot ; if ( _rtDW -> ahaacov03d < _rtDW -> jomnbzdhyn ) {
if ( _rtDW -> jomnbzdhyn < ssGetT ( S ) ) { neooptatmt = _rtDW -> jomnbzdhyn
; lastU = & _rtDW -> e50qeafqax ; } } else { if ( _rtDW -> ahaacov03d >=
ssGetT ( S ) ) { neooptatmt = _rtDW -> jomnbzdhyn ; lastU = & _rtDW ->
e50qeafqax ; } } _rtB -> gb4ja2yabm = ( _rtB -> mkpsln2gv2 - * lastU ) / (
ssGetT ( S ) - neooptatmt ) ; } _rtB -> movbjbjfm2 = _rtP -> P_435 * _rtB ->
gb4ja2yabm ; _rtB -> jtb0rfqqle = muDoubleScalarAbs ( _rtB -> iw5w5obtgj ) ;
_rtB -> jag5nbgcn1 = _rtP -> P_436 * _rtB -> jtb0rfqqle ; _rtB -> m5lqndi3uj
= _rtP -> P_437 * _rtB -> mkpsln2gv2 ; HEV_acc_Look2D_real_T_real_T_real_T (
& ( poymnughfl ) , _rtP -> P_440 , _rtB -> jag5nbgcn1 , _rtP -> P_438 , 108U
, _rtB -> m5lqndi3uj , _rtP -> P_439 , 100U ) ; _rtB -> knqsq1fpga = _rtP ->
P_441 * poymnughfl ; _rtB -> nzznfaxgmo = _rtP -> P_442 * _rtB -> knqsq1fpga
; _rtB -> gzk1vnqca0 = muDoubleScalarSign ( _rtB -> iw5w5obtgj ) ; _rtB ->
okyingmywn = muDoubleScalarAbs ( _rtB -> iw5w5obtgj ) ; _rtB -> ljz4vpvb5a =
_rtP -> P_443 * _rtB -> okyingmywn ; _rtB -> oxhlmurelr = _rtP -> P_444 *
_rtB -> mkpsln2gv2 ; HEV_acc_Look2D_real_T_real_T_real_T ( & ( crne3byzmy ) ,
_rtP -> P_447 , _rtB -> ljz4vpvb5a , _rtP -> P_445 , 108U , _rtB ->
oxhlmurelr , _rtP -> P_446 , 100U ) ; _rtB -> ins1sjmx3s = _rtP -> P_448 *
crne3byzmy ; _rtB -> doh4whb52u = _rtB -> gzk1vnqca0 * _rtB -> ins1sjmx3s ;
_rtB -> azbh2lgmd2 = _rtB -> doh4whb52u * _rtB -> movbjbjfm2 ; _rtB ->
a0ylhrywpm = _rtP -> P_449 * _rtB -> azbh2lgmd2 ; _rtB -> mp5mq5jc04 = _rtB
-> e4cfdkzr0b * _rtB -> iw5w5obtgj ; if ( _rtB -> nzznfaxgmo > _rtP -> P_450
) { _rtB -> cxpfzexzea = _rtP -> P_450 ; } else if ( _rtB -> nzznfaxgmo <
_rtP -> P_451 ) { _rtB -> cxpfzexzea = _rtP -> P_451 ; } else { _rtB ->
cxpfzexzea = _rtB -> nzznfaxgmo ; } _rtB -> ivusk2oexn = ( ( 0.0 - _rtB ->
a0ylhrywpm ) - _rtB -> hojpq2hcaj ) - _rtB -> mp5mq5jc04 ; _rtB -> oknlud03nk
= 1.0 / _rtB -> cxpfzexzea * _rtB -> ivusk2oexn ; _rtB -> h32efl2e22 = _rtB
-> oiwqfkdud2 + _rtB -> pdkpc2zqh1 ; _rtB -> k3cbfnpmeh = ( _rtB ->
h32efl2e22 - _rtB -> kk0busyovy ) - _rtB -> dbtgrppw14 ; _rtB -> e400jxxsie =
_rtP -> P_452 * _rtB -> k3cbfnpmeh ; _rtB -> ldtacuhtlk = muDoubleScalarAbs (
_rtB -> lhox1aa1pw ) ; if ( ( _rtDW -> oad342sj3x >= ssGetT ( S ) ) && (
_rtDW -> mf0gkni0c4 >= ssGetT ( S ) ) ) { _rtB -> i4dqbbd1hx = 0.0 ; } else {
neooptatmt = _rtDW -> oad342sj3x ; lastU = & _rtDW -> bm1fsqdtc2 ; if ( _rtDW
-> oad342sj3x < _rtDW -> mf0gkni0c4 ) { if ( _rtDW -> mf0gkni0c4 < ssGetT ( S
) ) { neooptatmt = _rtDW -> mf0gkni0c4 ; lastU = & _rtDW -> mz5uyj4kq2 ; } }
else { if ( _rtDW -> oad342sj3x >= ssGetT ( S ) ) { neooptatmt = _rtDW ->
mf0gkni0c4 ; lastU = & _rtDW -> mz5uyj4kq2 ; } } _rtB -> i4dqbbd1hx = ( _rtB
-> ii1lramsm4 - * lastU ) / ( ssGetT ( S ) - neooptatmt ) ; } _rtB ->
kvln1aypaz = _rtP -> P_453 * _rtB -> i4dqbbd1hx ; _rtB -> omdjsizscz =
muDoubleScalarAbs ( _rtB -> aycrmboosh ) ; _rtB -> fdviokbcp2 = _rtP -> P_454
* _rtB -> omdjsizscz ; _rtB -> cculz2qagq = _rtP -> P_455 * _rtB ->
ii1lramsm4 ; HEV_acc_Look2D_real_T_real_T_real_T ( & ( bs2qhimvya ) , _rtP ->
P_458 , _rtB -> fdviokbcp2 , _rtP -> P_456 , 108U , _rtB -> cculz2qagq , _rtP
-> P_457 , 100U ) ; _rtB -> beecubw4l4 = _rtP -> P_459 * bs2qhimvya ; _rtB ->
agddjge4z4 = _rtP -> P_460 * _rtB -> beecubw4l4 ; _rtB -> dgi1rh2u1j =
muDoubleScalarSign ( _rtB -> aycrmboosh ) ; _rtB -> irxsngrf1p =
muDoubleScalarAbs ( _rtB -> aycrmboosh ) ; _rtB -> czyi1hfcl3 = _rtP -> P_461
* _rtB -> irxsngrf1p ; _rtB -> a5xgwdj2fy = _rtP -> P_462 * _rtB ->
ii1lramsm4 ; HEV_acc_Look2D_real_T_real_T_real_T ( & ( fqbhv02h3b ) , _rtP ->
P_465 , _rtB -> czyi1hfcl3 , _rtP -> P_463 , 108U , _rtB -> a5xgwdj2fy , _rtP
-> P_464 , 100U ) ; _rtB -> mhe4hj3z52 = _rtP -> P_466 * fqbhv02h3b ; _rtB ->
ns1zph5txg = _rtB -> dgi1rh2u1j * _rtB -> mhe4hj3z52 ; _rtB -> n2lu3al323 =
_rtB -> ns1zph5txg * _rtB -> kvln1aypaz ; _rtB -> olmwhebj0m = _rtP -> P_467
* _rtB -> n2lu3al323 ; _rtB -> asm2pnvwo4 = _rtB -> ldtacuhtlk * _rtB ->
aycrmboosh ; if ( _rtB -> agddjge4z4 > _rtP -> P_468 ) { _rtB -> daydu2ikkh =
_rtP -> P_468 ; } else if ( _rtB -> agddjge4z4 < _rtP -> P_469 ) { _rtB ->
daydu2ikkh = _rtP -> P_469 ; } else { _rtB -> daydu2ikkh = _rtB -> agddjge4z4
; } _rtB -> ioeux1rje5 = ( ( 0.0 - _rtB -> olmwhebj0m ) - _rtB -> jylgp33lex
) - _rtB -> asm2pnvwo4 ; _rtB -> mdyuxd3owi = 1.0 / _rtB -> daydu2ikkh * _rtB
-> ioeux1rje5 ; _rtB -> kn5iczv3qt = _rtP -> P_470 * _rtB -> fumqusjt44 [ 4 ]
; ssCallAccelRunBlock ( S , 20 , 992 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
kn5iczv3qt = _rtP -> P_471 * _rtB -> kfh0ffdqcp [ 6 ] ; _rtB -> pjcfg2e3fk =
_rtP -> P_472 * _rtB -> kfh0ffdqcp [ 8 ] ; _rtB -> buoxgxrmie = _rtP -> P_473
* _rtB -> kfh0ffdqcp [ 9 ] ; ssCallAccelRunBlock ( S , 20 , 1039 ,
SS_CALL_MDL_OUTPUTS ) ; UNUSED_PARAMETER ( tid ) ; }
#define MDL_UPDATE
static void mdlUpdate ( SimStruct * S , int_T tid ) { real_T * lastU ;
fdj1laa40s * _rtB ; baqezl5ja5 * _rtP ; h04hj5x5sk * _rtDW ; _rtDW = ( (
h04hj5x5sk * ) ssGetRootDWork ( S ) ) ; _rtP = ( ( baqezl5ja5 * )
ssGetDefaultParam ( S ) ) ; _rtB = ( ( fdj1laa40s * ) _ssGetBlockIO ( S ) ) ;
if ( _rtDW -> cwivfg5ijd == ( rtInf ) ) { _rtDW -> cwivfg5ijd = ssGetTaskTime
( S , 0 ) ; _rtDW -> kguctqvwvn = _rtB -> mpvsgfisp4 ; } else if ( _rtDW ->
m1iuzueluk == ( rtInf ) ) { _rtDW -> m1iuzueluk = ssGetTaskTime ( S , 0 ) ;
_rtDW -> bvl1znuobh = _rtB -> mpvsgfisp4 ; } else if ( _rtDW -> cwivfg5ijd <
_rtDW -> m1iuzueluk ) { _rtDW -> cwivfg5ijd = ssGetTaskTime ( S , 0 ) ; _rtDW
-> kguctqvwvn = _rtB -> mpvsgfisp4 ; } else { _rtDW -> m1iuzueluk =
ssGetTaskTime ( S , 0 ) ; _rtDW -> bvl1znuobh = _rtB -> mpvsgfisp4 ; } if (
ssIsSampleHit ( S , 2 , 0 ) ) { _rtDW -> f2z5i2ds5e = ( _rtB -> ak4z542xwc -
_rtP -> P_50 [ 1 ] * _rtDW -> f2z5i2ds5e ) / _rtP -> P_50 [ 0 ] ; } if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtDW -> b50c0wk1dc = _rtB -> mizxc54qe4 ; }
if ( ssIsSampleHit ( S , 2 , 0 ) ) { _rtDW -> o05rwe50bo = 0U ; _rtDW ->
pk42w2cjcz += _rtP -> P_54 * _rtB -> ak4z542xwc ; if ( _rtDW -> pk42w2cjcz >=
_rtP -> P_55 ) { _rtDW -> pk42w2cjcz = _rtP -> P_55 ; } else { if ( _rtDW ->
pk42w2cjcz <= _rtP -> P_56 ) { _rtDW -> pk42w2cjcz = _rtP -> P_56 ; } } if (
_rtB -> ghuadkwg3z > 0.0 ) { _rtDW -> f0fxu4veqt = 1 ; } else if ( _rtB ->
ghuadkwg3z < 0.0 ) { _rtDW -> f0fxu4veqt = - 1 ; } else if ( _rtB ->
ghuadkwg3z == 0.0 ) { _rtDW -> f0fxu4veqt = 0 ; } else { _rtDW -> f0fxu4veqt
= 2 ; } _rtDW -> aagwoi0uhr += _rtP -> P_154 * _rtB -> hxwzukm1sf ; _rtDW ->
giv5xrlbh0 += _rtP -> P_156 * _rtB -> kroja0nrao ; _rtDW -> aekc0mbj0y +=
_rtP -> P_158 * _rtB -> het12fgs0x ; _rtDW -> oi2n4lur1q += _rtP -> P_160 *
_rtB -> bhqfjhd35i ; _rtDW -> eaosag5owj += _rtP -> P_188 * _rtB ->
bn4et2idix ; _rtDW -> pa0tuks1qd += _rtP -> P_190 * _rtB -> f1afn02nl1 ;
_rtDW -> jly33pdwub += _rtP -> P_195 * _rtB -> mpcurlrkqj ; _rtDW ->
fezg0yhyh2 = _rtB -> f1fhleshzz ; _rtDW -> hdqerfit1p [ 0 ] = _rtB ->
mxnkobt05b ; _rtDW -> hdqerfit1p [ 1 ] = _rtB -> gutl50bysc ; _rtDW ->
hdqerfit1p [ 2 ] = _rtB -> krhsfzevx2 ; } if ( _rtDW -> mg242c3vwq == ( rtInf
) ) { _rtDW -> mg242c3vwq = ssGetTaskTime ( S , 0 ) ; _rtDW -> oiqwpboxgd =
_rtB -> flcpkzs4x3 ; } else if ( _rtDW -> k1wt3kvmem == ( rtInf ) ) { _rtDW
-> k1wt3kvmem = ssGetTaskTime ( S , 0 ) ; _rtDW -> lzjsh0qxsz = _rtB ->
flcpkzs4x3 ; } else if ( _rtDW -> mg242c3vwq < _rtDW -> k1wt3kvmem ) { _rtDW
-> mg242c3vwq = ssGetTaskTime ( S , 0 ) ; _rtDW -> oiqwpboxgd = _rtB ->
flcpkzs4x3 ; } else { _rtDW -> k1wt3kvmem = ssGetTaskTime ( S , 0 ) ; _rtDW
-> lzjsh0qxsz = _rtB -> flcpkzs4x3 ; } if ( ssIsSampleHit ( S , 1 , 0 ) ) {
_rtDW -> bvad1zjfik = _rtB -> jjneelk2gr [ 0 ] ; } if ( _rtDW -> hfvh40s0je
== ( rtInf ) ) { _rtDW -> hfvh40s0je = ssGetTaskTime ( S , 0 ) ; _rtDW ->
lidlmlim32 = _rtB -> pwgh3s5ueh ; } else if ( _rtDW -> f41a3yqptq == ( rtInf
) ) { _rtDW -> f41a3yqptq = ssGetTaskTime ( S , 0 ) ; _rtDW -> aq3qjo4ji4 =
_rtB -> pwgh3s5ueh ; } else if ( _rtDW -> hfvh40s0je < _rtDW -> f41a3yqptq )
{ _rtDW -> hfvh40s0je = ssGetTaskTime ( S , 0 ) ; _rtDW -> lidlmlim32 = _rtB
-> pwgh3s5ueh ; } else { _rtDW -> f41a3yqptq = ssGetTaskTime ( S , 0 ) ;
_rtDW -> aq3qjo4ji4 = _rtB -> pwgh3s5ueh ; } if ( ssIsSampleHit ( S , 1 , 0 )
) { _rtDW -> aln04uuynj = _rtB -> pwgh3s5ueh ; _rtDW -> nlh5qppt4m = _rtB ->
g0w54d32ej ; } if ( _rtDW -> efkpcjgjek == ( rtInf ) ) { _rtDW -> efkpcjgjek
= ssGetTaskTime ( S , 0 ) ; _rtDW -> oyyqrjxbur = _rtB -> h25hr2ldko ; } else
if ( _rtDW -> hnoimzxxep == ( rtInf ) ) { _rtDW -> hnoimzxxep = ssGetTaskTime
( S , 0 ) ; _rtDW -> b5egd0vrtp = _rtB -> h25hr2ldko ; } else if ( _rtDW ->
efkpcjgjek < _rtDW -> hnoimzxxep ) { _rtDW -> efkpcjgjek = ssGetTaskTime ( S
, 0 ) ; _rtDW -> oyyqrjxbur = _rtB -> h25hr2ldko ; } else { _rtDW ->
hnoimzxxep = ssGetTaskTime ( S , 0 ) ; _rtDW -> b5egd0vrtp = _rtB ->
h25hr2ldko ; } if ( ssIsSampleHit ( S , 2 , 0 ) ) { _rtDW -> lmxxx3r01a = (
_rtB -> phmx5ph1e0 - _rtP -> P_245 [ 1 ] * _rtDW -> lmxxx3r01a ) / _rtP ->
P_245 [ 0 ] ; _rtDW -> ptsgdhh2pm = 0U ; _rtDW -> epthsan5zc = _rtP -> P_248
* _rtB -> gryl5xpbjt + _rtB -> jmel44rsxo ; if ( _rtDW -> epthsan5zc >= _rtP
-> P_250 ) { _rtDW -> epthsan5zc = _rtP -> P_250 ; } else { if ( _rtDW ->
epthsan5zc <= _rtP -> P_251 ) { _rtDW -> epthsan5zc = _rtP -> P_251 ; } }
_rtDW -> m4x03oyk3f = _rtB -> iixjexpwun ; _rtDW -> baieefy5w1 [ 0 ] = _rtB
-> nzuqkjyb2c ; _rtDW -> baieefy5w1 [ 1 ] = _rtB -> ps4zrh023s ; _rtDW ->
baieefy5w1 [ 2 ] = _rtB -> gfsxylt2pa ; } if ( ssIsSampleHit ( S , 4 , 0 ) )
{ _rtDW -> afj2f0hafp = _rtB -> dk5wpb3wiw ; } if ( _rtDW -> kzeshw3sd4 == (
rtInf ) ) { _rtDW -> kzeshw3sd4 = ssGetTaskTime ( S , 0 ) ; _rtDW ->
ag11bw3z1w = _rtB -> nv35kgxb2v ; } else if ( _rtDW -> kzvthvykyq == ( rtInf
) ) { _rtDW -> kzvthvykyq = ssGetTaskTime ( S , 0 ) ; _rtDW -> fstidsd2mk =
_rtB -> nv35kgxb2v ; } else if ( _rtDW -> kzeshw3sd4 < _rtDW -> kzvthvykyq )
{ _rtDW -> kzeshw3sd4 = ssGetTaskTime ( S , 0 ) ; _rtDW -> ag11bw3z1w = _rtB
-> nv35kgxb2v ; } else { _rtDW -> kzvthvykyq = ssGetTaskTime ( S , 0 ) ;
_rtDW -> fstidsd2mk = _rtB -> nv35kgxb2v ; } if ( ssIsSampleHit ( S , 2 , 0 )
) { _rtDW -> pot2tvweea = _rtB -> py4j2jpqpv ; _rtDW -> nonllthbl2 = ( _rtB
-> auf0j5mrv2 - _rtP -> P_308 [ 1 ] * _rtDW -> nonllthbl2 ) / _rtP -> P_308 [
0 ] ; _rtDW -> kol45dq53x = ( _rtB -> ocd0msjtdk - _rtP -> P_311 [ 1 ] *
_rtDW -> kol45dq53x ) / _rtP -> P_311 [ 0 ] ; _rtDW -> fw2k5vojpd = _rtB ->
fq41tauxr3 ; _rtDW -> ehaijafsot = _rtB -> f1fhleshzz ; _rtDW -> ifokpl3ags =
( _rtB -> ilefg2fmot - _rtP -> P_324 [ 1 ] * _rtDW -> ifokpl3ags ) / _rtP ->
P_324 [ 0 ] ; _rtDW -> bn3tyk4y03 = ( _rtB -> ce45zmtf1b - _rtP -> P_327 [ 1
] * _rtDW -> bn3tyk4y03 ) / _rtP -> P_327 [ 0 ] ; _rtDW -> bjzaihqzlo = _rtB
-> cu3ee2hbin ; _rtDW -> macroyt1rc = _rtB -> iixjexpwun ; _rtDW ->
jxow0tsi5b = _rtB -> oqoozlooh0 ; ssCallAccelRunBlock ( S , 20 , 512 ,
SS_CALL_MDL_UPDATE ) ; } if ( ssIsSampleHit ( S , 4 , 0 ) ) { _rtDW ->
gwbk0uviaf = _rtB -> fjybkm2pos ; } if ( ssIsSampleHit ( S , 2 , 0 ) ) {
_rtDW -> d3ojd0ilqw = ( _rtB -> grtvvntr5n - _rtP -> P_351 [ 1 ] * _rtDW ->
d3ojd0ilqw ) / _rtP -> P_351 [ 0 ] ; _rtDW -> p0opx5r1kj = ( _rtB ->
imsqyxysdt - _rtP -> P_354 [ 1 ] * _rtDW -> p0opx5r1kj ) / _rtP -> P_354 [ 0
] ; _rtDW -> jasnynsjlw = _rtB -> kkh5yr3jb3 [ 0 ] ; } if ( _rtDW ->
ohitnp3v2k == ( rtInf ) ) { _rtDW -> ohitnp3v2k = ssGetTaskTime ( S , 0 ) ;
_rtDW -> dateb3z15w = _rtB -> k5ixb4di45 ; } else if ( _rtDW -> bmafymwoxg ==
( rtInf ) ) { _rtDW -> bmafymwoxg = ssGetTaskTime ( S , 0 ) ; _rtDW ->
phwxap45zp = _rtB -> k5ixb4di45 ; } else if ( _rtDW -> ohitnp3v2k < _rtDW ->
bmafymwoxg ) { _rtDW -> ohitnp3v2k = ssGetTaskTime ( S , 0 ) ; _rtDW ->
dateb3z15w = _rtB -> k5ixb4di45 ; } else { _rtDW -> bmafymwoxg =
ssGetTaskTime ( S , 0 ) ; _rtDW -> phwxap45zp = _rtB -> k5ixb4di45 ; } if (
ssIsSampleHit ( S , 4 , 0 ) ) { _rtDW -> cok2lfoe2t = ( _rtB -> g3rjxatquz -
_rtP -> P_382 [ 1 ] * _rtDW -> cok2lfoe2t ) / _rtP -> P_382 [ 0 ] ; _rtDW ->
gsqmr1likf = 0U ; _rtDW -> li02312w4a = _rtP -> P_385 * _rtB -> ix2dwttwi3 +
_rtB -> elqltztscy ; if ( _rtDW -> li02312w4a >= _rtP -> P_387 ) { _rtDW ->
li02312w4a = _rtP -> P_387 ; } else { if ( _rtDW -> li02312w4a <= _rtP ->
P_388 ) { _rtDW -> li02312w4a = _rtP -> P_388 ; } } } if ( ssIsSampleHit ( S
, 2 , 0 ) ) { _rtDW -> dy4ppyw4mo = ( _rtB -> a5dmhfwwiy - _rtP -> P_394 [ 1
] * _rtDW -> dy4ppyw4mo ) / _rtP -> P_394 [ 0 ] ; _rtDW -> hmybg5b1mi = (
_rtB -> llaqeksi04 - _rtP -> P_397 [ 1 ] * _rtDW -> hmybg5b1mi ) / _rtP ->
P_397 [ 0 ] ; _rtDW -> gkq12xkctn = _rtB -> kqyvrrud5e [ 0 ] ; } if (
ssIsSampleHit ( S , 2 , 0 ) ) { _rtDW -> kx3vg4xtiw = 0U ; _rtDW ->
oyhpvg4ubg = _rtP -> P_425 * _rtB -> bs2keii2w3 + _rtB -> nex55iphrg ; if (
_rtDW -> oyhpvg4ubg >= _rtP -> P_427 ) { _rtDW -> oyhpvg4ubg = _rtP -> P_427
; } else { if ( _rtDW -> oyhpvg4ubg <= _rtP -> P_428 ) { _rtDW -> oyhpvg4ubg
= _rtP -> P_428 ; } } _rtDW -> dwrzgh5jph = _rtB -> p1vvzotek4 ; } if ( _rtDW
-> ahaacov03d == ( rtInf ) ) { _rtDW -> ahaacov03d = ssGetT ( S ) ; lastU = &
_rtDW -> irq44heqot ; } else if ( _rtDW -> jomnbzdhyn == ( rtInf ) ) { _rtDW
-> jomnbzdhyn = ssGetT ( S ) ; lastU = & _rtDW -> e50qeafqax ; } else if (
_rtDW -> ahaacov03d < _rtDW -> jomnbzdhyn ) { _rtDW -> ahaacov03d = ssGetT (
S ) ; lastU = & _rtDW -> irq44heqot ; } else { _rtDW -> jomnbzdhyn = ssGetT (
S ) ; lastU = & _rtDW -> e50qeafqax ; } * lastU = _rtB -> mkpsln2gv2 ; if (
_rtDW -> oad342sj3x == ( rtInf ) ) { _rtDW -> oad342sj3x = ssGetT ( S ) ;
lastU = & _rtDW -> bm1fsqdtc2 ; } else if ( _rtDW -> mf0gkni0c4 == ( rtInf )
) { _rtDW -> mf0gkni0c4 = ssGetT ( S ) ; lastU = & _rtDW -> mz5uyj4kq2 ; }
else if ( _rtDW -> oad342sj3x < _rtDW -> mf0gkni0c4 ) { _rtDW -> oad342sj3x =
ssGetT ( S ) ; lastU = & _rtDW -> bm1fsqdtc2 ; } else { _rtDW -> mf0gkni0c4 =
ssGetT ( S ) ; lastU = & _rtDW -> mz5uyj4kq2 ; } * lastU = _rtB -> ii1lramsm4
; UNUSED_PARAMETER ( tid ) ; }
#define MDL_DERIVATIVES
static void mdlDerivatives ( SimStruct * S ) { fdj1laa40s * _rtB ; baqezl5ja5
* _rtP ; hgl3elxkcb * _rtX ; aab5tqo4s5 * _rtXdot ; h04hj5x5sk * _rtDW ;
_rtDW = ( ( h04hj5x5sk * ) ssGetRootDWork ( S ) ) ; _rtXdot = ( ( aab5tqo4s5
* ) ssGetdX ( S ) ) ; _rtX = ( ( hgl3elxkcb * ) ssGetContStates ( S ) ) ;
_rtP = ( ( baqezl5ja5 * ) ssGetDefaultParam ( S ) ) ; _rtB = ( ( fdj1laa40s *
) _ssGetBlockIO ( S ) ) ; ssCallAccelRunBlock ( S , 20 , 19 ,
SS_CALL_MDL_DERIVATIVES ) ; _rtXdot -> ix50zu3rlz = 0.0 ; _rtXdot ->
ix50zu3rlz += _rtP -> P_37 * _rtX -> ix50zu3rlz ; _rtXdot -> ix50zu3rlz +=
_rtB -> n4v1iaymn1 ; { boolean_T lsat ; boolean_T usat ; lsat = ( ( (
hgl3elxkcb * ) ssGetContStates ( S ) ) -> f0udlm3lxk <= _rtP -> P_42 ) ; usat
= ( ( ( hgl3elxkcb * ) ssGetContStates ( S ) ) -> f0udlm3lxk >= _rtP -> P_41
) ; if ( ( ! lsat && ! usat ) || ( lsat && ( _rtB -> i0cl4hjbel > 0 ) ) || (
usat && ( _rtB -> i0cl4hjbel < 0 ) ) ) { ( ( aab5tqo4s5 * ) ssGetdX ( S ) )
-> f0udlm3lxk = _rtB -> i0cl4hjbel ; } else { ( ( aab5tqo4s5 * ) ssGetdX ( S
) ) -> f0udlm3lxk = 0.0 ; } } _rtXdot -> bjc4xqhn0t = _rtB -> gujw14k2fh ;
_rtXdot -> mh2wvbi24o = _rtB -> ptbhbc00fq ; _rtXdot -> dqmv0fuubx = _rtB ->
ceuutekqj2 ; _rtXdot -> mme20c3etf = _rtB -> mdyuxd3owi ; _rtXdot ->
eofb3a23j0 = _rtB -> e400jxxsie ; _rtXdot -> boqgv4aeow [ 0 ] = 0.0 ; _rtXdot
-> boqgv4aeow [ 1 ] = 0.0 ; _rtXdot -> boqgv4aeow [ 0 ] += _rtP -> P_114 [ 0
] * _rtX -> boqgv4aeow [ 0 ] ; _rtXdot -> boqgv4aeow [ 0 ] += _rtP -> P_114 [
1 ] * _rtX -> boqgv4aeow [ 1 ] ; _rtXdot -> boqgv4aeow [ 1 ] += _rtX ->
boqgv4aeow [ 0 ] ; _rtXdot -> boqgv4aeow [ 0 ] += _rtB -> k3cbfnpmeh ;
_rtXdot -> dkmu1cdscm = _rtB -> oknlud03nk ; _rtXdot -> pi4mr5hhgl = _rtB ->
gawdygiuvt ; _rtXdot -> jevixzbezd = 0.0 ; _rtXdot -> jevixzbezd += _rtP ->
P_420 * _rtX -> jevixzbezd ; _rtXdot -> jevixzbezd += _rtB -> aneznbcibh ; }
#define MDL_PROJECTION
static void mdlProjection ( SimStruct * S ) { fdj1laa40s * _rtB ; h04hj5x5sk
* _rtDW ; _rtDW = ( ( h04hj5x5sk * ) ssGetRootDWork ( S ) ) ; _rtB = ( (
fdj1laa40s * ) _ssGetBlockIO ( S ) ) ; ssCallAccelRunBlock ( S , 20 , 19 ,
SS_CALL_MDL_PROJECTION ) ; } static void mdlInitializeSizes ( SimStruct * S )
{ ssSetChecksumVal ( S , 0 , 3661469254U ) ; ssSetChecksumVal ( S , 1 ,
3666102351U ) ; ssSetChecksumVal ( S , 2 , 2709761304U ) ; ssSetChecksumVal (
S , 3 , 723727943U ) ; { mxArray * slVerStructMat = NULL ; mxArray * slStrMat
= mxCreateString ( "simulink" ) ; char slVerChar [ 10 ] ; int status =
mexCallMATLAB ( 1 , & slVerStructMat , 1 , & slStrMat , "ver" ) ; if ( status
== 0 ) { mxArray * slVerMat = mxGetField ( slVerStructMat , 0 , "Version" ) ;
if ( slVerMat == NULL ) { status = 1 ; } else { status = mxGetString (
slVerMat , slVerChar , 10 ) ; } } mxDestroyArray ( slStrMat ) ;
mxDestroyArray ( slVerStructMat ) ; if ( ( status == 1 ) || ( strcmp (
slVerChar , "8.5" ) != 0 ) ) { return ; } } ssSetOptions ( S ,
SS_OPTION_EXCEPTION_FREE_CODE ) ; if ( ssGetSizeofDWork ( S ) != sizeof (
h04hj5x5sk ) ) { ssSetErrorStatus ( S ,
"Unexpected error: Internal DWork sizes do "
"not match for accelerator mex file." ) ; } if ( ssGetSizeofGlobalBlockIO ( S
) != sizeof ( fdj1laa40s ) ) { ssSetErrorStatus ( S ,
"Unexpected error: Internal BlockIO sizes do "
"not match for accelerator mex file." ) ; } { int ssSizeofParams ;
ssGetSizeofParams ( S , & ssSizeofParams ) ; if ( ssSizeofParams != sizeof (
baqezl5ja5 ) ) { static char msg [ 256 ] ; sprintf ( msg ,
"Unexpected error: Internal Parameters sizes do "
"not match for accelerator mex file." ) ; } } _ssSetDefaultParam ( S , (
real_T * ) & apa05pzygw ) ; _ssSetConstBlockIO ( S , & j5jvyqjhah ) ;
rt_InitInfAndNaN ( sizeof ( real_T ) ) ; ( ( baqezl5ja5 * ) ssGetDefaultParam
( S ) ) -> P_17 = rtNaN ; ( ( baqezl5ja5 * ) ssGetDefaultParam ( S ) ) ->
P_22 = rtNaN ; ( ( baqezl5ja5 * ) ssGetDefaultParam ( S ) ) -> P_29 = rtNaN ;
( ( baqezl5ja5 * ) ssGetDefaultParam ( S ) ) -> P_32 = rtNaN ; ( ( baqezl5ja5
* ) ssGetDefaultParam ( S ) ) -> P_56 = rtMinusInf ; ( ( baqezl5ja5 * )
ssGetDefaultParam ( S ) ) -> P_124 = rtInf ; ( ( baqezl5ja5 * )
ssGetDefaultParam ( S ) ) -> P_145 = rtInf ; ( ( baqezl5ja5 * )
ssGetDefaultParam ( S ) ) -> P_199 = rtMinusInf ; ( ( baqezl5ja5 * )
ssGetDefaultParam ( S ) ) -> P_208 = rtInf ; ( ( baqezl5ja5 * )
ssGetDefaultParam ( S ) ) -> P_320 = rtInf ; ( ( baqezl5ja5 * )
ssGetDefaultParam ( S ) ) -> P_336 = rtInf ; ( ( baqezl5ja5 * )
ssGetDefaultParam ( S ) ) -> P_450 = rtInf ; ( ( baqezl5ja5 * )
ssGetDefaultParam ( S ) ) -> P_468 = rtInf ; } static void
mdlInitializeSampleTimes ( SimStruct * S ) { { SimStruct * childS ;
SysOutputFcn * callSysFcns ; childS = ssGetSFunction ( S , 0 ) ; callSysFcns
= ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 1 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; } } static void mdlTerminate ( SimStruct * S ) { }
#include "simulink.c"
