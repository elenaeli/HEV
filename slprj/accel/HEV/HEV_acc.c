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
= i ; } else { * piLeft = i ; } } } } void
HEV_acc_Look2D_real_T_real_T_real_T ( real_T * pY , const real_T * pYData ,
real_T u0 , const real_T * pU0Data , uint32_T iHiU0 , real_T u1 , const
real_T * pU1Data , uint32_T iHiU1 ) { uint32_T iLeftU0 , iRghtU0 , iLeftU1 ,
iRghtU1 ; HEV_acc_BINARYSEARCH_real_T ( & ( iLeftU0 ) , & ( iRghtU0 ) , u0 ,
pU0Data , iHiU0 ) ; HEV_acc_BINARYSEARCH_real_T ( & ( iLeftU1 ) , & ( iRghtU1
) , u1 , pU1Data , iHiU1 ) ; { real_T u0Left = pU0Data [ iLeftU0 ] ; real_T
u0Rght = pU0Data [ iRghtU0 ] ; real_T u1Left = pU1Data [ iLeftU1 ] ; real_T
u1Rght = pU1Data [ iRghtU1 ] ; real_T yTemp ; real_T yLeftLeft ; real_T
yLeftRght ; real_T yRghtLeft ; real_T yRghtRght ; real_T u1Lambda ; real_T
u0Lambda ; if ( u1Rght > u1Left ) { real_T num ; real_T den ; den = u1Rght ;
den -= u1Left ; num = u1 ; num -= u1Left ; u1Lambda = num / den ; } else {
u1Lambda = 0.0 ; } if ( u0Rght > u0Left ) { real_T num ; real_T den ; den =
u0Rght ; den -= u0Left ; num = u0 ; num -= u0Left ; u0Lambda = num / den ; }
else { u0Lambda = 0.0 ; } iHiU0 ++ ; iLeftU1 *= iHiU0 ; iRghtU1 *= iHiU0 ;
yRghtLeft = pYData [ ( iRghtU0 + iLeftU1 ) ] ; yRghtRght = pYData [ ( iRghtU0
+ iRghtU1 ) ] ; yLeftLeft = pYData [ ( iLeftU0 + iLeftU1 ) ] ; yLeftRght =
pYData [ ( iLeftU0 + iRghtU1 ) ] ; { real_T yLeftCast ; real_T yRghtCast ;
yLeftCast = yLeftLeft ; yRghtCast = yLeftRght ; yLeftCast += u1Lambda * (
yRghtCast - yLeftCast ) ; ( * pY ) = yLeftCast ; } { real_T yLeftCast ;
real_T yRghtCast ; yLeftCast = yRghtLeft ; yRghtCast = yRghtRght ; yLeftCast
+= u1Lambda * ( yRghtCast - yLeftCast ) ; yTemp = yLeftCast ; } { real_T
yLeftCast ; real_T yRghtCast ; yLeftCast = ( * pY ) ; yRghtCast = yTemp ;
yLeftCast += u0Lambda * ( yRghtCast - yLeftCast ) ; ( * pY ) = yLeftCast ; }
} } void HEV_acc_LookUp_real_T_real_T ( real_T * pY , const real_T * pYData ,
real_T u , const real_T * pUData , uint32_T iHi ) { uint32_T iLeft ; uint32_T
iRght ; HEV_acc_BINARYSEARCH_real_T ( & ( iLeft ) , & ( iRght ) , u , pUData
, iHi ) ; { real_T lambda ; if ( pUData [ iRght ] > pUData [ iLeft ] ) {
real_T num ; real_T den ; den = pUData [ iRght ] ; den -= pUData [ iLeft ] ;
num = u ; num -= pUData [ iLeft ] ; lambda = num / den ; } else { lambda =
0.0 ; } { real_T yLeftCast ; real_T yRghtCast ; yLeftCast = pYData [ iLeft ]
; yRghtCast = pYData [ iRght ] ; yLeftCast += lambda * ( yRghtCast -
yLeftCast ) ; ( * pY ) = yLeftCast ; } } } void keyxmz53xi ( SimStruct *
const S , boolean_T mfqvbclekq , boolean_T gbeq152nyt , h1kbqu5vwm * localB ,
his5kfh0i3 * localDW ) { if ( mfqvbclekq ) { localB -> forbrjhq11 =
gbeq152nyt ; if ( ssIsMajorTimeStep ( S ) ) { srUpdateBC ( localDW ->
hx1jtpaojx ) ; } } } void nxnb4xfekz ( SimStruct * const S ) { } static void
mdlOutputs ( SimStruct * S , int_T tid ) { real_T fepbibcdbq ; real_T
nzpvluxqo1 ; real_T gj0z5teswu ; real_T dks5t0rchn ; real_T iiwpljhiwm ;
real_T achaqmub1c ; real_T g4ujj0rjwg ; real_T is3sm2p0on ; real_T llfprdkco5
; real_T ei5vcc44pf ; boolean_T cq224qj4y1 ; int32_T rowIdx ; real_T * lastU
; boolean_T o3khhk3fbg ; uint8_T h100jbae3x ; real_T iiis24gb3o ; real_T
jwhz1ujp3w ; real_T ehtkh2wauy ; real_T mkcfwi2fsi ; real_T ehcygfucdl ;
real_T po0ockmy2b ; real_T mizlp41tvx ; real_T f4ufgq33gz ; real_T i5nu34w4uj
; real_T dztyrqu4xa ; real_T eskeehll14 ; real_T ckrl0nmlwt ; real_T
lduwq00gqj ; real_T byehzqrbel ; boolean_T fviymzl3aa ; real_T j0jhyqa1p3 ;
real_T aqlslovppe ; real_T dyfxp2slod ; real_T dk4tk42hhp ; real_T ctpq3axefx
; real_T f1b5simhxh ; real_T lstej3qx0u ; real_T h0cg4jnrg5 ; real_T
lfv3m5pb5c ; real_T f2e3v5ccex ; real_T lebvfutt11 ; real_T lc4cnav21a_idx_0
; real_T lc4cnav21a_idx_1 ; real_T lc4cnav21a_idx_2 ; ZCEventType
zcEvent_idx_0 ; ZCEventType zcEvent_idx_1 ; ZCEventType zcEvent_idx_2 ;
fdj1laa40s * _rtB ; baqezl5ja5 * _rtP ; hgl3elxkcb * _rtX ; bu2ncqpcar *
_rtZCE ; h04hj5x5sk * _rtDW ; _rtDW = ( ( h04hj5x5sk * ) ssGetRootDWork ( S )
) ; _rtZCE = ( ( bu2ncqpcar * ) _ssGetPrevZCSigState ( S ) ) ; _rtX = ( (
hgl3elxkcb * ) ssGetContStates ( S ) ) ; _rtP = ( ( baqezl5ja5 * )
ssGetDefaultParam ( S ) ) ; _rtB = ( ( fdj1laa40s * ) _ssGetBlockIO ( S ) ) ;
_rtB -> jro10jnzw4 = _rtX -> mh2wvbi24o ; _rtB -> hjqvqi2kxb = _rtB ->
jro10jnzw4 - ld5zvvrfqt ( S ) -> ojxhzlzf31 ; _rtB -> ggsfrqg40g = 0.0 * _rtB
-> hjqvqi2kxb ; _rtB -> gp0a54hauc = _rtB -> hjqvqi2kxb * ( real_T )
ld5zvvrfqt ( S ) -> jtyffi3ygy ; o3khhk3fbg = ( _rtB -> gp0a54hauc >=
ld5zvvrfqt ( S ) -> cx4i3mezhn ) ; _rtB -> d5ztt4c3k3 = _rtB -> ggsfrqg40g *
( real_T ) o3khhk3fbg ; _rtB -> pp30n5d3zg [ 0 ] = ld5zvvrfqt ( S ) ->
dkaeg0vhlj ; _rtB -> pp30n5d3zg [ 1 ] = ld5zvvrfqt ( S ) -> kfppdkqbu1 ; _rtB
-> pp30n5d3zg [ 2 ] = ld5zvvrfqt ( S ) -> d1n4jwbtvx ; _rtB -> pp30n5d3zg [ 3
] = ld5zvvrfqt ( S ) -> b5eiakdlax ; _rtB -> pp30n5d3zg [ 4 ] = ld5zvvrfqt (
S ) -> kukfi0ry5r ; _rtB -> pp30n5d3zg [ 5 ] = ld5zvvrfqt ( S ) -> oc0zgyho3y
; _rtB -> pp30n5d3zg [ 6 ] = ld5zvvrfqt ( S ) -> ayw1ok1jnp ; _rtB ->
pp30n5d3zg [ 7 ] = ld5zvvrfqt ( S ) -> phnxyum15u ; _rtB -> pp30n5d3zg [ 8 ]
= ld5zvvrfqt ( S ) -> me33hi2v5f ; _rtB -> pp30n5d3zg [ 9 ] = ld5zvvrfqt ( S
) -> gyw2dkfkrn ; _rtB -> pp30n5d3zg [ 10 ] = ld5zvvrfqt ( S ) -> gqzirnozm5
; _rtB -> pp30n5d3zg [ 11 ] = ld5zvvrfqt ( S ) -> hilkli0kdi ; _rtB ->
pp30n5d3zg [ 12 ] = ld5zvvrfqt ( S ) -> cvrmedndto ; _rtB -> pp30n5d3zg [ 13
] = ld5zvvrfqt ( S ) -> pziqszrs1g ; _rtB -> pp30n5d3zg [ 14 ] = ld5zvvrfqt (
S ) -> i24vrpdhda ; _rtB -> pp30n5d3zg [ 15 ] = ld5zvvrfqt ( S ) ->
oxzw12pd2m ; _rtB -> pp30n5d3zg [ 16 ] = ld5zvvrfqt ( S ) -> kdo0hok5es ;
ssCallAccelRunBlock ( S , 16 , 29 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 16 , 30 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
b2zz22c1x4 = _rtB -> m2y1khvsri [ 12 ] - _rtB -> m2y1khvsri [ 0 ] ; _rtB ->
hwdyjyrauc = 0.2079 * _rtB -> b2zz22c1x4 ; _rtB -> m13shqita4 = ( real_T )
o3khhk3fbg * _rtB -> hwdyjyrauc ; _rtB -> p4rnt4xsr1 = ( 0.0 - _rtB ->
d5ztt4c3k3 ) - _rtB -> m13shqita4 ; _rtB -> eu34sjejj2 = _rtB -> jro10jnzw4 +
ld5zvvrfqt ( S ) -> dn0w40jfhz ; _rtB -> op2xcjgze4 = 0.0 * _rtB ->
eu34sjejj2 ; _rtB -> gyqurnomb2 = _rtB -> eu34sjejj2 * ( real_T ) ld5zvvrfqt
( S ) -> ljew4sq5tw ; o3khhk3fbg = ( _rtB -> gyqurnomb2 <= ld5zvvrfqt ( S )
-> hu0a1xefmp ) ; _rtB -> nctmi5hz4i = _rtB -> op2xcjgze4 * ( real_T )
o3khhk3fbg ; _rtB -> bly0yc3fc5 = 0.2079 * _rtB -> b2zz22c1x4 ; _rtB ->
dfrbnsp2rt = ( real_T ) o3khhk3fbg * _rtB -> bly0yc3fc5 ; _rtB -> blqwgjrez3
= ( 0.0 - _rtB -> nctmi5hz4i ) - _rtB -> dfrbnsp2rt ; _rtB -> kfey3avqy4 =
_rtB -> blqwgjrez3 * ( real_T ) ld5zvvrfqt ( S ) -> dbjnhecnzo ; _rtB ->
f42rmc3fdw = ( 0.0 - _rtB -> p4rnt4xsr1 ) - _rtB -> kfey3avqy4 ; _rtB ->
fcs4dxccao = _rtX -> nlkba1lokv ; _rtB -> daqpye2lqg = _rtB -> fcs4dxccao -
ld5zvvrfqt ( S ) -> clg5asxy1d ; _rtB -> ckf3ivyvzk = 0.0 * _rtB ->
daqpye2lqg ; _rtB -> m1m4aaztxc = _rtB -> daqpye2lqg * ( real_T ) ld5zvvrfqt
( S ) -> oer5j0t1vn ; o3khhk3fbg = ( _rtB -> m1m4aaztxc >= ld5zvvrfqt ( S )
-> lttmtg3g41 ) ; _rtB -> bei2ufp1v5 = _rtB -> ckf3ivyvzk * ( real_T )
o3khhk3fbg ; _rtB -> jvnivwhexw = _rtB -> m2y1khvsri [ 1 ] - _rtB ->
m2y1khvsri [ 4 ] ; _rtB -> oea3xuc0s5 = 0.1 * _rtB -> jvnivwhexw ; _rtB ->
njipmcv1xh = ( real_T ) o3khhk3fbg * _rtB -> oea3xuc0s5 ; _rtB -> glt4zp4gtb
= ( 0.0 - _rtB -> bei2ufp1v5 ) - _rtB -> njipmcv1xh ; _rtB -> gbki3niqjp =
_rtB -> fcs4dxccao + ld5zvvrfqt ( S ) -> njbwxgzzyn ; _rtB -> msozgakcih =
0.0 * _rtB -> gbki3niqjp ; _rtB -> mgb12ztsmk = _rtB -> gbki3niqjp * ( real_T
) ld5zvvrfqt ( S ) -> ndnosjhyxk ; o3khhk3fbg = ( _rtB -> mgb12ztsmk <=
ld5zvvrfqt ( S ) -> e3mojtnxia ) ; _rtB -> h3nkktynbq = _rtB -> msozgakcih *
( real_T ) o3khhk3fbg ; _rtB -> mbipro2nlb = 0.1 * _rtB -> jvnivwhexw ; _rtB
-> dtngj23avy = ( real_T ) o3khhk3fbg * _rtB -> mbipro2nlb ; _rtB ->
ktjjtgcnj5 = ( 0.0 - _rtB -> h3nkktynbq ) - _rtB -> dtngj23avy ; _rtB ->
pk2yjbujbv = _rtB -> ktjjtgcnj5 * ( real_T ) ld5zvvrfqt ( S ) -> o5spiwykiu ;
_rtB -> hea4gjqawa = ( 0.0 - _rtB -> glt4zp4gtb ) - _rtB -> pk2yjbujbv ; _rtB
-> lt41u3p0z3 = - _rtB -> hea4gjqawa ; _rtB -> iyq5z5g4dk = _rtX ->
eackaa2e5o ; _rtB -> chkwevbcym = _rtX -> a3p154yttn ; _rtB -> a3wpzz45yv =
muDoubleScalarAbs ( _rtB -> chkwevbcym ) ; o3khhk3fbg = ( ld5zvvrfqt ( S ) ->
ar0ry5uhpg > _rtB -> a3wpzz45yv ) ; _rtB -> f31yc1wsbi = o3khhk3fbg ; _rtB ->
p4glylxbqw = 0.4 * _rtB -> a3wpzz45yv ; _rtB -> eyijkrzari =
3.1415926535897931 * _rtB -> p4glylxbqw ; _rtB -> d153oi01u4 = (
muDoubleScalarCos ( _rtB -> eyijkrzari ) + 1.0 ) * 770.0 ; _rtB -> hvvtwpg5px
= 0.5 * _rtB -> d153oi01u4 ; _rtB -> av43cv4xhp = 9.6688232009214591E-6 *
_rtB -> hvvtwpg5px ; _rtB -> obtvggk4n2 = 0.3 * _rtB -> m2y1khvsri [ 2 ] ;
_rtB -> pv0hkzonpw = _rtB -> chkwevbcym - _rtB -> obtvggk4n2 ; _rtB ->
k0z0bqxgkf = _rtB -> f31yc1wsbi * _rtB -> av43cv4xhp * _rtB -> pv0hkzonpw ;
_rtB -> jdhkzfg42s = _rtB -> iyq5z5g4dk - _rtB -> k0z0bqxgkf ; _rtB ->
j2ipbqjbeh = muDoubleScalarSign ( _rtB -> jdhkzfg42s ) ; _rtB -> aohsyhrwdm =
muDoubleScalarAbs ( _rtB -> jdhkzfg42s ) ; _rtB -> g013xtkmbh = 1.093 * _rtB
-> aohsyhrwdm ; _rtB -> g5igjkknn4 = 0.0 ; _rtB -> g5igjkknn4 += 0.0 * _rtX
-> lvhb24m1u3 [ 0 ] ; _rtB -> g5igjkknn4 += 157.91367041742973 * _rtX ->
lvhb24m1u3 [ 1 ] ; _rtB -> a0ljv2tapn = muDoubleScalarSign ( _rtB ->
chkwevbcym ) ; _rtB -> adxyvyijsd = _rtB -> chkwevbcym * _rtB -> chkwevbcym *
_rtB -> a0ljv2tapn ; _rtB -> iw2wfvlz4u = 0.5 * _rtB -> adxyvyijsd ; _rtB ->
dktfsz2xal = 1.2 * _rtB -> iw2wfvlz4u ; _rtB -> nddnuu201y = 0.26 * _rtB ->
dktfsz2xal ; _rtB -> jdx1oh4myt = 2.57 * _rtB -> nddnuu201y ; _rtB ->
e1ypjzt0yh = ( ( 0.0 - ld5zvvrfqt ( S ) -> oapjufkr55 ) - _rtB -> g5igjkknn4
) - _rtB -> jdx1oh4myt ; _rtB -> movta12pwv = 0.18518518518518517 * _rtB ->
e1ypjzt0yh ; _rtB -> p2vbkoxqk0 = ( ld5zvvrfqt ( S ) -> oj4yafkqbd - _rtB ->
movta12pwv ) + ld5zvvrfqt ( S ) -> bdwujnn4a2 ; if ( _rtB -> p2vbkoxqk0 <=
0.0 ) { _rtB -> eqtatbfsoc = 0.0 ; } else { _rtB -> eqtatbfsoc = _rtB ->
p2vbkoxqk0 ; } _rtB -> p3144ypepf = 1.0464 * _rtB -> eqtatbfsoc ; { uint32_T
iLeftU0 , iRghtU0 , iLeftU1 , iRghtU1 ; HEV_acc_BINARYSEARCH_real_T ( & (
iLeftU0 ) , & ( iRghtU0 ) , _rtB -> g013xtkmbh , ni220kbneq . bvhb4ijxid ,
108U ) ; if ( _rtB -> p3144ypepf <= 0.0 ) { iLeftU1 = 0U ; iRghtU1 = 0U ; }
else if ( _rtB -> p3144ypepf >= 6000.0 ) { iLeftU1 = 100U ; iRghtU1 = 100U ;
} else { iLeftU1 = ( uint32_T ) ( ( _rtB -> p3144ypepf ) / 60.0 ) ; iRghtU1 =
iLeftU1 + 1 ; } { real_T yTemp ; real_T u1Lambda ; real_T u0Lambda ; if (
iLeftU1 != iRghtU1 ) { { real_T num = ( real_T ) ( _rtB -> p3144ypepf ) - (
iLeftU1 * 60.0 ) ; u1Lambda = num / 60.0 ; } } else { u1Lambda = 0.0 ; } if (
( ni220kbneq . bvhb4ijxid [ iRghtU0 ] ) > ( ni220kbneq . bvhb4ijxid [ iLeftU0
] ) ) { real_T num ; real_T den ; den = ( ni220kbneq . bvhb4ijxid [ iRghtU0 ]
) ; den -= ( ni220kbneq . bvhb4ijxid [ iLeftU0 ] ) ; num = _rtB -> g013xtkmbh
; num -= ( ni220kbneq . bvhb4ijxid [ iLeftU0 ] ) ; u0Lambda = num / den ; }
else { u0Lambda = 0.0 ; } { real_T yLeftCast ; real_T yRghtCast ; yLeftCast =
( ni220kbneq . fgjvocl3ug [ ( iLeftU0 + 109U * iLeftU1 ) ] ) ; yRghtCast = (
ni220kbneq . fgjvocl3ug [ ( iLeftU0 + 109U * iRghtU1 ) ] ) ; yLeftCast +=
u1Lambda * ( yRghtCast - yLeftCast ) ; fepbibcdbq = yLeftCast ; } { real_T
yLeftCast ; real_T yRghtCast ; yLeftCast = ( ni220kbneq . fgjvocl3ug [ (
iRghtU0 + 109U * iLeftU1 ) ] ) ; yRghtCast = ( ni220kbneq . fgjvocl3ug [ (
iRghtU0 + 109U * iRghtU1 ) ] ) ; yLeftCast += u1Lambda * ( yRghtCast -
yLeftCast ) ; yTemp = yLeftCast ; } { real_T yLeftCast ; real_T yRghtCast ;
yLeftCast = fepbibcdbq ; yRghtCast = yTemp ; yLeftCast += u0Lambda * (
yRghtCast - yLeftCast ) ; fepbibcdbq = yLeftCast ; } } } _rtB -> fxnvpwosph =
1.0351048413332149 * fepbibcdbq ; _rtB -> cwuinypz5p = _rtB -> j2ipbqjbeh *
_rtB -> fxnvpwosph ; _rtB -> nefuuqg1e4 = 0.3 * _rtB -> cwuinypz5p ; _rtB ->
oac35s35vw = - _rtB -> nefuuqg1e4 ; _rtB -> ib5hrgd3aj = _rtX -> oiuvfykmtf ;
_rtB -> owvkgodw45 = muDoubleScalarAbs ( _rtB -> chkwevbcym ) ; o3khhk3fbg =
( ld5zvvrfqt ( S ) -> l451usvceu > _rtB -> owvkgodw45 ) ; _rtB -> hiqs0fy3to
= o3khhk3fbg ; _rtB -> libhc1olfz = 0.4 * _rtB -> owvkgodw45 ; _rtB ->
cau55owpvd = 3.1415926535897931 * _rtB -> libhc1olfz ; _rtB -> l2en2jcur2 = (
muDoubleScalarCos ( _rtB -> cau55owpvd ) + 1.0 ) * 770.0 ; _rtB -> j3zklhhskk
= 0.5 * _rtB -> l2en2jcur2 ; _rtB -> jdcnfxh1mh = 9.6688232009214591E-6 *
_rtB -> j3zklhhskk ; _rtB -> pbh31ya5q3 = 0.3 * _rtB -> m2y1khvsri [ 3 ] ;
_rtB -> mcmpwax5wu = _rtB -> chkwevbcym - _rtB -> pbh31ya5q3 ; _rtB ->
nsp2nutm2k = _rtB -> hiqs0fy3to * _rtB -> jdcnfxh1mh * _rtB -> mcmpwax5wu ;
_rtB -> jlystfaabk = _rtB -> ib5hrgd3aj - _rtB -> nsp2nutm2k ; _rtB ->
n0ur5azag0 = muDoubleScalarSign ( _rtB -> jlystfaabk ) ; _rtB -> bsan0jns50 =
muDoubleScalarAbs ( _rtB -> jlystfaabk ) ; _rtB -> jla0sqmgz1 = 1.093 * _rtB
-> bsan0jns50 ; _rtB -> dkjznecoxt = ( _rtB -> movta12pwv + ld5zvvrfqt ( S )
-> fhk0ge1q0c ) + ld5zvvrfqt ( S ) -> k5egx2dlnq ; if ( _rtB -> dkjznecoxt <=
0.0 ) { _rtB -> g123hlbqqb = 0.0 ; } else { _rtB -> g123hlbqqb = _rtB ->
dkjznecoxt ; } _rtB -> gy3qknpzse = 1.0464 * _rtB -> g123hlbqqb ; { uint32_T
iLeftU0 , iRghtU0 , iLeftU1 , iRghtU1 ; HEV_acc_BINARYSEARCH_real_T ( & (
iLeftU0 ) , & ( iRghtU0 ) , _rtB -> jla0sqmgz1 , ni220kbneq . bvhb4ijxid ,
108U ) ; if ( _rtB -> gy3qknpzse <= 0.0 ) { iLeftU1 = 0U ; iRghtU1 = 0U ; }
else if ( _rtB -> gy3qknpzse >= 6000.0 ) { iLeftU1 = 100U ; iRghtU1 = 100U ;
} else { iLeftU1 = ( uint32_T ) ( ( _rtB -> gy3qknpzse ) / 60.0 ) ; iRghtU1 =
iLeftU1 + 1 ; } { real_T yTemp ; real_T u1Lambda ; real_T u0Lambda ; if (
iLeftU1 != iRghtU1 ) { { real_T num = ( real_T ) ( _rtB -> gy3qknpzse ) - (
iLeftU1 * 60.0 ) ; u1Lambda = num / 60.0 ; } } else { u1Lambda = 0.0 ; } if (
( ni220kbneq . bvhb4ijxid [ iRghtU0 ] ) > ( ni220kbneq . bvhb4ijxid [ iLeftU0
] ) ) { real_T num ; real_T den ; den = ( ni220kbneq . bvhb4ijxid [ iRghtU0 ]
) ; den -= ( ni220kbneq . bvhb4ijxid [ iLeftU0 ] ) ; num = _rtB -> jla0sqmgz1
; num -= ( ni220kbneq . bvhb4ijxid [ iLeftU0 ] ) ; u0Lambda = num / den ; }
else { u0Lambda = 0.0 ; } { real_T yLeftCast ; real_T yRghtCast ; yLeftCast =
( ni220kbneq . fgjvocl3ug [ ( iLeftU0 + 109U * iLeftU1 ) ] ) ; yRghtCast = (
ni220kbneq . fgjvocl3ug [ ( iLeftU0 + 109U * iRghtU1 ) ] ) ; yLeftCast +=
u1Lambda * ( yRghtCast - yLeftCast ) ; nzpvluxqo1 = yLeftCast ; } { real_T
yLeftCast ; real_T yRghtCast ; yLeftCast = ( ni220kbneq . fgjvocl3ug [ (
iRghtU0 + 109U * iLeftU1 ) ] ) ; yRghtCast = ( ni220kbneq . fgjvocl3ug [ (
iRghtU0 + 109U * iRghtU1 ) ] ) ; yLeftCast += u1Lambda * ( yRghtCast -
yLeftCast ) ; yTemp = yLeftCast ; } { real_T yLeftCast ; real_T yRghtCast ;
yLeftCast = nzpvluxqo1 ; yRghtCast = yTemp ; yLeftCast += u0Lambda * (
yRghtCast - yLeftCast ) ; nzpvluxqo1 = yLeftCast ; } } } _rtB -> ammfsxv3hv =
1.0351048413332149 * nzpvluxqo1 ; _rtB -> mv0scjuozy = _rtB -> n0ur5azag0 *
_rtB -> ammfsxv3hv ; _rtB -> h15whm4yjc = 0.3 * _rtB -> mv0scjuozy ; _rtB ->
jv1hez3310 = - _rtB -> h15whm4yjc ; if ( ssIsSampleHit ( S , 2 , 0 ) ) { _rtB
-> deue3miwlt = _rtDW -> epw20ibixm ; _rtB -> aorbsvsy2v = _rtDW ->
emjtqjwqij ; _rtB -> kgfazmviyv = ( - 0.00045907990073600015 * _rtB ->
deue3miwlt * _rtB -> aorbsvsy2v + 0.175666143629361 * _rtB -> deue3miwlt ) *
6.0 ; if ( _rtB -> kgfazmviyv > 400.0 ) { _rtB -> cbttxcrlpy = 400.0 ; } else
if ( _rtB -> kgfazmviyv < - 400.0 ) { _rtB -> cbttxcrlpy = - 400.0 ; } else {
_rtB -> cbttxcrlpy = _rtB -> kgfazmviyv ; } _rtB -> bw2nhi51td = _rtDW ->
aekc0mbj0y ; _rtB -> gthgcz50sq = _rtDW -> oi2n4lur1q ; _rtB -> netq4xlqvp =
( 0.0 * _rtB -> bw2nhi51td * _rtB -> gthgcz50sq + 0.192 * _rtB -> bw2nhi51td
) * 1.5 ; if ( _rtB -> netq4xlqvp > 400.0 ) { _rtB -> c1dd1abfch = 400.0 ; }
else if ( _rtB -> netq4xlqvp < - 400.0 ) { _rtB -> c1dd1abfch = - 400.0 ; }
else { _rtB -> c1dd1abfch = _rtB -> netq4xlqvp ; } } if ( _rtB -> m2y1khvsri
[ 10 ] > 628.31853071795865 ) { _rtB -> jkneh55zyo = 628.31853071795865 ; }
else if ( _rtB -> m2y1khvsri [ 10 ] < 0.0 ) { _rtB -> jkneh55zyo = 0.0 ; }
else { _rtB -> jkneh55zyo = _rtB -> m2y1khvsri [ 10 ] ; } h100jbae3x = (
uint8_T ) ( _rtB -> jkneh55zyo > ld5zvvrfqt ( S ) -> kridhzpqfr ) ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { if ( ssIsSampleHit ( S , 2 , 0 ) ) { _rtB ->
l2uxbs2atq = _rtDW -> jnhtlxaxxk ; } if ( _rtB -> l2uxbs2atq > 1.0 ) { _rtB
-> e0ucbx352x = 1.0 ; } else if ( _rtB -> l2uxbs2atq < 0.0 ) { _rtB ->
e0ucbx352x = 0.0 ; } else { _rtB -> e0ucbx352x = _rtB -> l2uxbs2atq ; } } if
( h100jbae3x >= 1 ) { _rtB -> bmpu5p2kzq = ld5zvvrfqt ( S ) -> jpwtxo3hpd ; }
else { _rtB -> evneamc1h2 = 9.5492965855137211 * _rtB -> jkneh55zyo ; _rtB ->
l5ps3h45bs = rt_Lookup ( ni220kbneq . jqglboln4v , 101 , _rtB -> evneamc1h2 ,
ni220kbneq . i2vn1liwwa ) * _rtB -> e0ucbx352x ; if ( _rtB -> l5ps3h45bs >
136.0757 ) { _rtB -> pvpxscgwqr = 136.0757 ; } else if ( _rtB -> l5ps3h45bs <
0.0 ) { _rtB -> pvpxscgwqr = 0.0 ; } else { _rtB -> pvpxscgwqr = _rtB ->
l5ps3h45bs ; } _rtB -> bmpu5p2kzq = _rtB -> pvpxscgwqr ; } _rtB -> dau0oam2ht
= - _rtB -> f42rmc3fdw ; _rtB -> kkyt3uefy4 [ 0 ] = _rtB -> f42rmc3fdw ; _rtB
-> kkyt3uefy4 [ 1 ] = _rtB -> lt41u3p0z3 ; _rtB -> kkyt3uefy4 [ 2 ] = _rtB ->
oac35s35vw ; _rtB -> kkyt3uefy4 [ 3 ] = _rtB -> jv1hez3310 ; _rtB ->
kkyt3uefy4 [ 4 ] = _rtB -> hea4gjqawa ; _rtB -> kkyt3uefy4 [ 5 ] = _rtB ->
cbttxcrlpy ; _rtB -> kkyt3uefy4 [ 6 ] = _rtB -> c1dd1abfch ; _rtB ->
kkyt3uefy4 [ 7 ] = _rtB -> bmpu5p2kzq ; _rtB -> kkyt3uefy4 [ 8 ] = _rtB ->
dau0oam2ht ; ssCallAccelRunBlock ( S , 16 , 179 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 16 , 180 , SS_CALL_MDL_OUTPUTS ) ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { ssCallAccelRunBlock ( S , 16 , 181 ,
SS_CALL_MDL_OUTPUTS ) ; } ssCallAccelRunBlock ( S , 16 , 182 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> bwlmtykro0 = 9.5492965854826952 * _rtB ->
m2y1khvsri [ 11 ] ; _rtB -> ikiy2z4zm3 = _rtB -> m2y1khvsri [ 11 ] * _rtB ->
htjriwobeu [ 1 ] ; ssCallAccelRunBlock ( S , 16 , 185 , SS_CALL_MDL_OUTPUTS )
; _rtB -> ffcve0ou4e = _rtX -> pi4mr5hhgl ; _rtB -> cbqjtrbh5m = _rtX ->
bjc4xqhn0t ; llfprdkco5 = 1.0 / _rtB -> ffcve0ou4e * _rtB -> cbqjtrbh5m *
100.0 ; if ( llfprdkco5 > 15.0 ) { _rtB -> ikiy2z4zm3 = 15.0 ; } else if (
llfprdkco5 < 0.0 ) { _rtB -> ikiy2z4zm3 = 0.0 ; } else { _rtB -> ikiy2z4zm3 =
llfprdkco5 ; } HEV_acc_Look2D_real_T_real_T_real_T ( & ( _rtB -> lutyrcb0gb )
, ( ( baqezl5ja5 * ) ssGetDefaultParam ( S ) ) -> FuelConsTable .
lookupTableFuel , _rtB -> bwlmtykro0 , ( ( baqezl5ja5 * ) ssGetDefaultParam (
S ) ) -> FuelConsTable . speed , 9U , _rtB -> htjriwobeu [ 1 ] , ( (
baqezl5ja5 * ) ssGetDefaultParam ( S ) ) -> FuelConsTable . torque , 9U ) ;
HEV_acc_Look2D_real_T_real_T_real_T ( & ( _rtB -> c5lofc00ur ) , ( (
baqezl5ja5 * ) ssGetDefaultParam ( S ) ) -> GasEmisTable . lookupTableCO ,
_rtB -> bwlmtykro0 , ( ( baqezl5ja5 * ) ssGetDefaultParam ( S ) ) ->
GasEmisTable . speed , 9U , _rtB -> htjriwobeu [ 1 ] , ( ( baqezl5ja5 * )
ssGetDefaultParam ( S ) ) -> GasEmisTable . torque , 9U ) ;
HEV_acc_Look2D_real_T_real_T_real_T ( & ( _rtB -> lmb25sruhs ) , ( (
baqezl5ja5 * ) ssGetDefaultParam ( S ) ) -> GasEmisTable . lookupTableHC ,
_rtB -> bwlmtykro0 , ( ( baqezl5ja5 * ) ssGetDefaultParam ( S ) ) ->
GasEmisTable . speed , 9U , _rtB -> htjriwobeu [ 1 ] , ( ( baqezl5ja5 * )
ssGetDefaultParam ( S ) ) -> GasEmisTable . torque , 9U ) ;
HEV_acc_Look2D_real_T_real_T_real_T ( & ( _rtB -> bxmms3bqxa ) , ( (
baqezl5ja5 * ) ssGetDefaultParam ( S ) ) -> GasEmisTable . lookupTableNOX ,
_rtB -> bwlmtykro0 , ( ( baqezl5ja5 * ) ssGetDefaultParam ( S ) ) ->
GasEmisTable . speed , 9U , _rtB -> htjriwobeu [ 1 ] , ( ( baqezl5ja5 * )
ssGetDefaultParam ( S ) ) -> GasEmisTable . torque , 9U ) ;
ssCallAccelRunBlock ( S , 16 , 195 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
pflt530iff = ! ( h100jbae3x != 0 ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) {
ssCallAccelRunBlock ( S , 16 , 197 , SS_CALL_MDL_OUTPUTS ) ; } _rtB ->
pdsnyrwzxm = _rtX -> oy1vxpvao1 ; llfprdkco5 = ssGetT ( S ) ; _rtB ->
bxp415etnk = _rtB -> pdsnyrwzxm / llfprdkco5 ; ssCallAccelRunBlock ( S , 16 ,
206 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> oompwwasmy = _rtX -> iglmayn3zq ; _rtB
-> kf3t5b41va = llfprdkco5 * ld5zvvrfqt ( S ) -> a35rxrg3n1 ; _rtB ->
bxp415etnk *= _rtB -> kf3t5b41va ; llfprdkco5 = _rtB -> oompwwasmy / _rtB ->
bxp415etnk ; if ( llfprdkco5 <= 0.0 ) { _rtB -> mcetl23ukz = 0.0 ; } else {
_rtB -> mcetl23ukz = llfprdkco5 ; } ssCallAccelRunBlock ( S , 16 , 213 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 16 , 214 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> pkn3qaidb3 = _rtX -> p24x5vnk3x ; llfprdkco5
= _rtB -> pkn3qaidb3 / _rtB -> bxp415etnk ; if ( llfprdkco5 <= 0.0 ) { _rtB
-> mcetl23ukz = 0.0 ; } else { _rtB -> mcetl23ukz = llfprdkco5 ; }
ssCallAccelRunBlock ( S , 16 , 218 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
dju111pk51 = _rtX -> jntxheunx4 ; llfprdkco5 = _rtB -> dju111pk51 / _rtB ->
bxp415etnk ; if ( llfprdkco5 <= 0.0 ) { _rtB -> mcetl23ukz = 0.0 ; } else {
_rtB -> mcetl23ukz = llfprdkco5 ; } ssCallAccelRunBlock ( S , 16 , 222 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 16 , 223 ,
SS_CALL_MDL_OUTPUTS ) ; if ( _rtB -> cbqjtrbh5m <= 0.0 ) { h0cg4jnrg5 = 0.0 ;
} else { h0cg4jnrg5 = _rtB -> cbqjtrbh5m ; } _rtB -> djljkzmo5i = h0cg4jnrg5
+ ld5zvvrfqt ( S ) -> ezb5c05hsw ; ssCallAccelRunBlock ( S , 16 , 227 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 16 , 228 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> ipal3laumf = 0.001 * _rtB -> lutyrcb0gb ;
_rtB -> d4o5dz1qo3 = _rtB -> ipal3laumf / ld5zvvrfqt ( S ) -> jfrlruuvnr ;
_rtB -> oq3dprofto = 3.6 * _rtB -> chkwevbcym ; if ( _rtB -> oq3dprofto >
200.0 ) { _rtB -> pv0g2dpf4q = 200.0 ; } else if ( _rtB -> oq3dprofto < 0.0 )
{ _rtB -> pv0g2dpf4q = 0.0 ; } else { _rtB -> pv0g2dpf4q = _rtB -> oq3dprofto
; } _rtB -> gq3amsk45r = 0.0002777777777778 * _rtB -> pv0g2dpf4q ; _rtB ->
jumk2kvvg3 = 1000.0 * _rtB -> d4o5dz1qo3 ; ssCallAccelRunBlock ( S , 16 , 242
, SS_CALL_MDL_OUTPUTS ) ; _rtB -> mwlcz45ota = 0 ; ssCallAccelRunBlock ( S ,
16 , 263 , SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 16 , 264 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 16 , 265 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 16 , 266 ,
SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSampleHit ( S , 4 , 0 ) ) {
ssCallAccelRunBlock ( S , 16 , 267 , SS_CALL_MDL_OUTPUTS ) ; } _rtB ->
ozl5w3wauj = 0.0 ; _rtB -> ozl5w3wauj += 125.66370614359172 * _rtX ->
ix50zu3rlz ; ssCallAccelRunBlock ( S , 16 , 269 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 16 , 270 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
i1yji2rzyc = _rtB -> mcetl23ukz - _rtB -> ozl5w3wauj ; iiis24gb3o = 0.02 *
_rtB -> i1yji2rzyc ; if ( ( ( hgl3elxkcb * ) ssGetContStates ( S ) ) ->
f0udlm3lxk >= 5.0 ) { if ( ( ( hgl3elxkcb * ) ssGetContStates ( S ) ) ->
f0udlm3lxk != 5.0 ) { ( ( hgl3elxkcb * ) ssGetContStates ( S ) ) ->
f0udlm3lxk = 5.0 ; ssSetSolverNeedsReset ( S ) ; } } else if ( ( ( hgl3elxkcb
* ) ssGetContStates ( S ) ) -> f0udlm3lxk <= ( - 5.0 ) ) { if ( ( (
hgl3elxkcb * ) ssGetContStates ( S ) ) -> f0udlm3lxk != ( - 5.0 ) ) { ( (
hgl3elxkcb * ) ssGetContStates ( S ) ) -> f0udlm3lxk = ( - 5.0 ) ;
ssSetSolverNeedsReset ( S ) ; } } _rtB -> cyaefnwupo = ( ( hgl3elxkcb * )
ssGetContStates ( S ) ) -> f0udlm3lxk ; llfprdkco5 = iiis24gb3o + _rtB ->
cyaefnwupo ; if ( llfprdkco5 > 1.0 ) { _rtB -> e4rep5rom3 = 1.0 ; } else if (
llfprdkco5 < - 1.0 ) { _rtB -> e4rep5rom3 = - 1.0 ; } else { _rtB ->
e4rep5rom3 = llfprdkco5 ; } ssCallAccelRunBlock ( S , 16 , 276 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 16 , 277 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> khvkfx53q0 = 0.04 * _rtB -> i1yji2rzyc ; if (
ssIsSampleHit ( S , 2 , 0 ) ) { jwhz1ujp3w = _rtDW -> eaosag5owj ; ehtkh2wauy
= muDoubleScalarSin ( _rtDW -> eaosag5owj ) ; mkcfwi2fsi = muDoubleScalarCos
( _rtDW -> eaosag5owj ) ; _rtB -> jrmxpxekhm = _rtB -> bw2nhi51td *
mkcfwi2fsi + _rtB -> gthgcz50sq * ehtkh2wauy ; _rtB -> owtu4im5h2 = ( ( -
_rtB -> bw2nhi51td - 1.7320508075688772 * _rtB -> gthgcz50sq ) * mkcfwi2fsi +
( 1.7320508075688772 * _rtB -> bw2nhi51td - _rtB -> gthgcz50sq ) * ehtkh2wauy
) * 0.5 ; ehcygfucdl = _rtDW -> jcugjk0yp0 ; po0ockmy2b = muDoubleScalarSin (
_rtDW -> jcugjk0yp0 ) ; mizlp41tvx = muDoubleScalarCos ( _rtDW -> jcugjk0yp0
) ; _rtB -> b5ttljiovc = _rtB -> deue3miwlt * mizlp41tvx + _rtB -> aorbsvsy2v
* po0ockmy2b ; _rtB -> piqzs2jgjq = ( ( - _rtB -> deue3miwlt -
1.7320508075688772 * _rtB -> aorbsvsy2v ) * mizlp41tvx + ( 1.7320508075688772
* _rtB -> deue3miwlt - _rtB -> aorbsvsy2v ) * po0ockmy2b ) * 0.5 ; f4ufgq33gz
= _rtDW -> jly33pdwub ; i5nu34w4uj = 5.9999820000156134E-6 * _rtDW ->
f2z5i2ds5e ; _rtB -> inzo0k02k1 = ( i5nu34w4uj > ld5zvvrfqt ( S ) ->
bkybk24pxk ) ; } if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> lbrdx4mpgo =
_rtDW -> b50c0wk1dc ; } if ( ssIsSampleHit ( S , 2 , 0 ) ) { if ( _rtDW ->
o05rwe50bo != 0 ) { _rtDW -> pk42w2cjcz = _rtB -> lbrdx4mpgo ; if ( _rtDW ->
pk42w2cjcz >= 25200.0 ) { _rtDW -> pk42w2cjcz = 25200.0 ; } else { if ( _rtDW
-> pk42w2cjcz <= rtMinusInf ) { _rtDW -> pk42w2cjcz = rtMinusInf ; } } } if (
( _rtB -> inzo0k02k1 > 0.0 ) && ( _rtDW -> f0fxu4veqt <= 0 ) ) { _rtDW ->
pk42w2cjcz = _rtB -> lbrdx4mpgo ; if ( _rtDW -> pk42w2cjcz >= 25200.0 ) {
_rtDW -> pk42w2cjcz = 25200.0 ; } else { if ( _rtDW -> pk42w2cjcz <=
rtMinusInf ) { _rtDW -> pk42w2cjcz = rtMinusInf ; } } } if ( _rtDW ->
pk42w2cjcz >= 25200.0 ) { _rtDW -> pk42w2cjcz = 25200.0 ; } else { if ( _rtDW
-> pk42w2cjcz <= rtMinusInf ) { _rtDW -> pk42w2cjcz = rtMinusInf ; } }
dztyrqu4xa = 0.00027777777777777778 * _rtDW -> pk42w2cjcz ; if ( dztyrqu4xa >
6.9993 ) { eskeehll14 = 6.9993 ; } else if ( dztyrqu4xa < 0.0 ) { eskeehll14
= 0.0 ; } else { eskeehll14 = dztyrqu4xa ; } if ( dztyrqu4xa >= 6.9993 ) {
dztyrqu4xa = 6.9993 ; } byehzqrbel = ( ( 7.0 / ( 7.0 - eskeehll14 ) * -
0.23801451555567835 * eskeehll14 + ( ld5zvvrfqt ( S ) -> fhcl2rwzr3 +
f4ufgq33gz ) ) + - _rtB -> inzo0k02k1 * 0.23801451555567835 * i5nu34w4uj * (
7.0 / ( 7.0 - eskeehll14 ) ) ) + - ( ( real_T ) ( i5nu34w4uj < ld5zvvrfqt ( S
) -> lhidkeezkl ) * ld5zvvrfqt ( S ) -> jsena5gvgp ) * 0.23801451555567835 *
( ld5zvvrfqt ( S ) -> jsena5gvgp * i5nu34w4uj ) * ( 7.0 / ( muDoubleScalarAbs
( ld5zvvrfqt ( S ) -> jsena5gvgp * dztyrqu4xa ) + 0.70000000000000007 ) ) ;
if ( byehzqrbel > ld5zvvrfqt ( S ) -> pcncjv5doi ) { _rtB -> afmxkvqw45 =
ld5zvvrfqt ( S ) -> pcncjv5doi ; } else { iiis24gb3o = 0.30769230769230771 *
i5nu34w4uj ; if ( byehzqrbel < iiis24gb3o ) { _rtB -> afmxkvqw45 = iiis24gb3o
; } else { _rtB -> afmxkvqw45 = byehzqrbel ; } } _rtB -> gz2goujg2r = _rtDW
-> fezg0yhyh2 ; lc4cnav21a_idx_0 = _rtDW -> hdqerfit1p [ 0 ] ;
lc4cnav21a_idx_1 = _rtDW -> hdqerfit1p [ 1 ] ; lc4cnav21a_idx_2 = _rtDW ->
hdqerfit1p [ 2 ] ; lduwq00gqj = muDoubleScalarCos ( jwhz1ujp3w ) ; ckrl0nmlwt
= muDoubleScalarSin ( jwhz1ujp3w ) ; } if ( _rtB -> m2y1khvsri [ 7 ] <= 1.0 )
{ llfprdkco5 = 1.0 ; } else { llfprdkco5 = _rtB -> m2y1khvsri [ 7 ] ; }
llfprdkco5 = 1.0 / llfprdkco5 ; llfprdkco5 *= 30000.0 ; i5nu34w4uj =
muDoubleScalarAbs ( llfprdkco5 ) ; if ( ssIsMajorTimeStep ( S ) ) { if ( _rtB
-> m2y1khvsri [ 7 ] >= 300.0 ) { _rtDW -> ch52ed4whv = true ; } else { if (
_rtB -> m2y1khvsri [ 7 ] <= 200.0 ) { _rtDW -> ch52ed4whv = false ; } } }
_rtB -> mkply5jhqs = _rtDW -> ch52ed4whv ; if ( ( _rtDW -> mg242c3vwq >=
ssGetTaskTime ( S , 0 ) ) && ( _rtDW -> k1wt3kvmem >= ssGetTaskTime ( S , 0 )
) ) { _rtB -> opx3gyttsw = _rtB -> mkply5jhqs ; } else { if ( ( ( _rtDW ->
mg242c3vwq < _rtDW -> k1wt3kvmem ) && ( _rtDW -> k1wt3kvmem < ssGetTaskTime (
S , 0 ) ) ) || ( ( _rtDW -> mg242c3vwq >= _rtDW -> k1wt3kvmem ) && ( _rtDW ->
mg242c3vwq >= ssGetTaskTime ( S , 0 ) ) ) ) { iiis24gb3o = ssGetTaskTime ( S
, 0 ) - _rtDW -> k1wt3kvmem ; lebvfutt11 = _rtDW -> lzjsh0qxsz ; } else {
iiis24gb3o = ssGetTaskTime ( S , 0 ) - _rtDW -> mg242c3vwq ; lebvfutt11 =
_rtDW -> oiqwpboxgd ; } lstej3qx0u = iiis24gb3o * 10.0 ; f2e3v5ccex = _rtB ->
mkply5jhqs - lebvfutt11 ; if ( f2e3v5ccex > lstej3qx0u ) { _rtB -> opx3gyttsw
= lebvfutt11 + lstej3qx0u ; } else { iiis24gb3o *= - 10.0 ; if ( f2e3v5ccex <
iiis24gb3o ) { _rtB -> opx3gyttsw = lebvfutt11 + iiis24gb3o ; } else { _rtB
-> opx3gyttsw = _rtB -> mkply5jhqs ; } } } if ( _rtB -> m2y1khvsri [ 5 ] >
628.31853071795865 ) { _rtB -> kkpq2kwxuh = 628.31853071795865 ; } else if (
_rtB -> m2y1khvsri [ 5 ] < 0.0 ) { _rtB -> kkpq2kwxuh = 0.0 ; } else { _rtB
-> kkpq2kwxuh = _rtB -> m2y1khvsri [ 5 ] ; } llfprdkco5 = muDoubleScalarAbs (
_rtB -> kkpq2kwxuh ) ; HEV_acc_LookUp_real_T_real_T ( & ( gj0z5teswu ) ,
ni220kbneq . pormlyvumi , llfprdkco5 , ni220kbneq . johzj1udqh , 6U ) ; if (
( _rtDW -> cwivfg5ijd >= ssGetTaskTime ( S , 0 ) ) && ( _rtDW -> m1iuzueluk
>= ssGetTaskTime ( S , 0 ) ) ) { _rtB -> jn4gk5uedm = _rtB -> e4rep5rom3 ; }
else { if ( ( ( _rtDW -> cwivfg5ijd < _rtDW -> m1iuzueluk ) && ( _rtDW ->
m1iuzueluk < ssGetTaskTime ( S , 0 ) ) ) || ( ( _rtDW -> cwivfg5ijd >= _rtDW
-> m1iuzueluk ) && ( _rtDW -> cwivfg5ijd >= ssGetTaskTime ( S , 0 ) ) ) ) {
iiis24gb3o = ssGetTaskTime ( S , 0 ) - _rtDW -> m1iuzueluk ; lebvfutt11 =
_rtDW -> bvl1znuobh ; } else { iiis24gb3o = ssGetTaskTime ( S , 0 ) - _rtDW
-> cwivfg5ijd ; lebvfutt11 = _rtDW -> kguctqvwvn ; } f2e3v5ccex = _rtB ->
e4rep5rom3 - lebvfutt11 ; if ( f2e3v5ccex > iiis24gb3o ) { _rtB -> jn4gk5uedm
= lebvfutt11 + iiis24gb3o ; } else { iiis24gb3o = - iiis24gb3o ; if (
f2e3v5ccex < iiis24gb3o ) { _rtB -> jn4gk5uedm = lebvfutt11 + iiis24gb3o ; }
else { _rtB -> jn4gk5uedm = _rtB -> e4rep5rom3 ; } } } byehzqrbel = 400.0 *
_rtB -> jn4gk5uedm ; if ( byehzqrbel > gj0z5teswu ) { llfprdkco5 = gj0z5teswu
; } else if ( byehzqrbel < - gj0z5teswu ) { llfprdkco5 = - gj0z5teswu ; }
else { llfprdkco5 = byehzqrbel ; } ei5vcc44pf = ssGetT ( S ) ; _rtB ->
kgzzaktogw = ( real_T ) ( ei5vcc44pf > ld5zvvrfqt ( S ) -> ezi3fip04t ) *
llfprdkco5 ; ei5vcc44pf = _rtB -> kgzzaktogw * _rtB -> kkpq2kwxuh ; if (
ssIsSampleHit ( S , 2 , 0 ) ) { _rtB -> mjzq04sefh = ( 1.0 - eskeehll14 / 7.0
) * 100.0 ; rowIdx = ( int32_T ) ( ( ( ( ( uint32_T ) ( _rtB -> mjzq04sefh <
ld5zvvrfqt ( S ) -> ebblk4v00z ) << 1 ) + ( _rtB -> mjzq04sefh > ld5zvvrfqt (
S ) -> e4z11owcfn ) ) << 1 ) + _rtDW -> bvad1zjfik ) ; _rtB -> cwawvyhhog [
0U ] = ni220kbneq . nzwc2c2eqf [ ( uint32_T ) rowIdx ] ; _rtB -> cwawvyhhog [
1U ] = ni220kbneq . nzwc2c2eqf [ rowIdx + 8U ] ; } llfprdkco5 = _rtB ->
cwawvyhhog [ 0 ] ; _rtB -> a51a0luisi = - 21000.0 * llfprdkco5 ; if ( ( _rtDW
-> hfvh40s0je >= ssGetTaskTime ( S , 0 ) ) && ( _rtDW -> f41a3yqptq >=
ssGetTaskTime ( S , 0 ) ) ) { _rtB -> hijbmmvub5 = _rtB -> a51a0luisi ; }
else { if ( ( ( _rtDW -> hfvh40s0je < _rtDW -> f41a3yqptq ) && ( _rtDW ->
f41a3yqptq < ssGetTaskTime ( S , 0 ) ) ) || ( ( _rtDW -> hfvh40s0je >= _rtDW
-> f41a3yqptq ) && ( _rtDW -> hfvh40s0je >= ssGetTaskTime ( S , 0 ) ) ) ) {
iiis24gb3o = ssGetTaskTime ( S , 0 ) - _rtDW -> f41a3yqptq ; lebvfutt11 =
_rtDW -> aq3qjo4ji4 ; } else { iiis24gb3o = ssGetTaskTime ( S , 0 ) - _rtDW
-> hfvh40s0je ; lebvfutt11 = _rtDW -> lidlmlim32 ; } lstej3qx0u = iiis24gb3o
* 42000.0 ; f2e3v5ccex = _rtB -> a51a0luisi - lebvfutt11 ; if ( f2e3v5ccex >
lstej3qx0u ) { _rtB -> hijbmmvub5 = lebvfutt11 + lstej3qx0u ; } else {
iiis24gb3o *= - 42000.0 ; if ( f2e3v5ccex < iiis24gb3o ) { _rtB -> hijbmmvub5
= lebvfutt11 + iiis24gb3o ; } else { _rtB -> hijbmmvub5 = _rtB -> a51a0luisi
; } } } j0jhyqa1p3 = ei5vcc44pf - _rtB -> hijbmmvub5 ; llfprdkco5 =
muDoubleScalarAbs ( j0jhyqa1p3 ) ; llfprdkco5 = 1.1 * rt_Lookup ( _rtP ->
EngineSpeedPower . power , 84 , llfprdkco5 , _rtP -> EngineSpeedPower . speed
) ; if ( llfprdkco5 > 5000.0 ) { _rtB -> mcetl23ukz = 5000.0 ; } else if (
llfprdkco5 < 750.0 ) { _rtB -> mcetl23ukz = 750.0 ; } else { _rtB ->
mcetl23ukz = llfprdkco5 ; } byehzqrbel = 0.10471975511965977 * _rtB ->
mcetl23ukz ; if ( ssIsMajorTimeStep ( S ) ) { if ( ei5vcc44pf >= 12000.0 ) {
_rtDW -> guq5pq4c5s = true ; } else { if ( ei5vcc44pf <= 11000.0 ) { _rtDW ->
guq5pq4c5s = false ; } } } if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB ->
c3cdumk5ue = ! ! _rtDW -> guq5pq4c5s ; _rtB -> bbi1a4woy5 = ( _rtDW ->
aln04uuynj != ld5zvvrfqt ( S ) -> i3yyx2vgzd ) ; } o3khhk3fbg = ( _rtB ->
c3cdumk5ue || ( ( ei5vcc44pf > ld5zvvrfqt ( S ) -> fvqe355sya ) && _rtB ->
bbi1a4woy5 ) ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> ffx4mzj1i4 =
_rtDW -> nlh5qppt4m ; } if ( o3khhk3fbg ) { if ( j0jhyqa1p3 > 57000.0 ) {
h0cg4jnrg5 = 57000.0 ; } else if ( j0jhyqa1p3 < - 57000.0 ) { h0cg4jnrg5 = -
57000.0 ; } else { h0cg4jnrg5 = j0jhyqa1p3 ; } _rtB -> cj0c4eiztx = 1.0 /
byehzqrbel * h0cg4jnrg5 * _rtB -> opx3gyttsw ; } else { _rtB -> cj0c4eiztx =
_rtB -> ffx4mzj1i4 ; } ei5vcc44pf = 1.0 / byehzqrbel * _rtB -> m2y1khvsri [
11 ] ; if ( ei5vcc44pf > 1.0 ) { h0cg4jnrg5 = 1.0 ; } else if ( ei5vcc44pf <
0.0 ) { h0cg4jnrg5 = 0.0 ; } else { h0cg4jnrg5 = ei5vcc44pf ; } iiis24gb3o =
_rtB -> opx3gyttsw * _rtB -> cj0c4eiztx * h0cg4jnrg5 * 0.27777777777777779 ;
if ( iiis24gb3o > i5nu34w4uj ) { _rtB -> pqvfeo32cg = i5nu34w4uj ; } else if
( iiis24gb3o < - i5nu34w4uj ) { _rtB -> pqvfeo32cg = - i5nu34w4uj ; } else {
_rtB -> pqvfeo32cg = iiis24gb3o ; } ei5vcc44pf = - _rtB -> pqvfeo32cg *
ld5zvvrfqt ( S ) -> aos5ylbxlz ; if ( ( _rtDW -> mtptmi2003 == ( rtMinusInf )
) || ( _rtDW -> mtptmi2003 == ssGetTaskTime ( S , 0 ) ) ) { _rtDW ->
mtptmi2003 = ssGetTaskTime ( S , 0 ) ; _rtB -> e2knxf1dm4 = 0.0 ; } else {
_rtB -> e2knxf1dm4 = ei5vcc44pf ; } if ( ssIsSampleHit ( S , 2 , 0 ) ) { if (
_rtB -> e2knxf1dm4 > 45.0 ) { dztyrqu4xa = 45.0 ; } else if ( _rtB ->
e2knxf1dm4 < - 45.0 ) { dztyrqu4xa = - 45.0 ; } else { dztyrqu4xa = _rtB ->
e2knxf1dm4 ; } aqlslovppe = 3.4722222222222219 * dztyrqu4xa ; dyfxp2slod = -
ld5zvvrfqt ( S ) -> a3ycysbtcc * ckrl0nmlwt + aqlslovppe * lduwq00gqj ;
ctpq3axefx = dyfxp2slod - lc4cnav21a_idx_0 ; if ( ctpq3axefx >= 0.0 ) { _rtDW
-> mdrfaaqhlc = true ; } else { if ( ctpq3axefx <= 0.0 ) { _rtDW ->
mdrfaaqhlc = false ; } } dk4tk42hhp = ( 1.7320508 * ckrl0nmlwt + - lduwq00gqj
) * aqlslovppe * 0.5 + ( 1.7320508 * lduwq00gqj + ckrl0nmlwt ) * ld5zvvrfqt (
S ) -> a3ycysbtcc * 0.5 ; aqlslovppe = dk4tk42hhp - lc4cnav21a_idx_1 ; if (
aqlslovppe >= 0.0 ) { _rtDW -> hi5e5wjvfn = true ; } else { if ( aqlslovppe
<= 0.0 ) { _rtDW -> hi5e5wjvfn = false ; } } f1b5simhxh = ( 0.0 - dk4tk42hhp
) - dyfxp2slod ; lduwq00gqj = f1b5simhxh - lc4cnav21a_idx_2 ; if ( lduwq00gqj
>= 0.0 ) { _rtDW -> ltj2mwt3by = true ; } else { if ( lduwq00gqj <= 0.0 ) {
_rtDW -> ltj2mwt3by = false ; } } _rtB -> mqt0rycbvc [ 0 ] = ( ( real_T )
_rtDW -> mdrfaaqhlc - ( real_T ) _rtDW -> hi5e5wjvfn ) * ld5zvvrfqt ( S ) ->
aos5ylbxlz * _rtB -> gz2goujg2r ; _rtB -> mqt0rycbvc [ 1 ] = ( ( real_T )
_rtDW -> hi5e5wjvfn - ( real_T ) _rtDW -> ltj2mwt3by ) * ld5zvvrfqt ( S ) ->
aos5ylbxlz * _rtB -> gz2goujg2r ; _rtB -> lew1su5u2u = _rtDW -> bro0cn1wmi ;
lc4cnav21a_idx_0 = _rtDW -> j31s1kcymk [ 0 ] ; lc4cnav21a_idx_1 = _rtDW ->
j31s1kcymk [ 1 ] ; lc4cnav21a_idx_2 = _rtDW -> j31s1kcymk [ 2 ] ; ehcygfucdl
/= 4.0 ; ctpq3axefx = 4.0 * ehcygfucdl ; aqlslovppe = muDoubleScalarCos (
ctpq3axefx ) ; ctpq3axefx = muDoubleScalarSin ( ctpq3axefx ) ; if (
ssIsSampleHit ( S , 3 , 0 ) ) { _rtB -> czxyvc02ym = _rtDW -> gsr0ogd2xb ; }
_rtB -> f0jzjbnjfv = 0.002479481623358034 * _rtB -> czxyvc02ym ; } if ( (
_rtDW -> joiszbfghn >= ssGetTaskTime ( S , 0 ) ) && ( _rtDW -> jlnwqqs23l >=
ssGetTaskTime ( S , 0 ) ) ) { _rtB -> dil4xbueyo = _rtB -> f0jzjbnjfv ; }
else { if ( ( ( _rtDW -> joiszbfghn < _rtDW -> jlnwqqs23l ) && ( _rtDW ->
jlnwqqs23l < ssGetTaskTime ( S , 0 ) ) ) || ( ( _rtDW -> joiszbfghn >= _rtDW
-> jlnwqqs23l ) && ( _rtDW -> joiszbfghn >= ssGetTaskTime ( S , 0 ) ) ) ) {
iiis24gb3o = ssGetTaskTime ( S , 0 ) - _rtDW -> jlnwqqs23l ; lebvfutt11 =
_rtDW -> miwjijsda1 ; } else { iiis24gb3o = ssGetTaskTime ( S , 0 ) - _rtDW
-> joiszbfghn ; lebvfutt11 = _rtDW -> narm2z4h4g ; } lstej3qx0u = iiis24gb3o
* 10.0 ; f2e3v5ccex = _rtB -> f0jzjbnjfv - lebvfutt11 ; if ( f2e3v5ccex >
lstej3qx0u ) { _rtB -> dil4xbueyo = lebvfutt11 + lstej3qx0u ; } else {
iiis24gb3o *= - 10.0 ; if ( f2e3v5ccex < iiis24gb3o ) { _rtB -> dil4xbueyo =
lebvfutt11 + iiis24gb3o ; } else { _rtB -> dil4xbueyo = _rtB -> f0jzjbnjfv ;
} } } ei5vcc44pf = muDoubleScalarAbs ( _rtB -> dil4xbueyo ) ; _rtB ->
c2ivurwyme = rt_Lookup ( ni220kbneq . hvtx2huqpc , 301 , ei5vcc44pf ,
ni220kbneq . fjibtn4wrs ) ; if ( ssIsSampleHit ( S , 2 , 0 ) ) { _rtB ->
gtpd5mskaz = _rtB -> kkpq2kwxuh ; ssCallAccelRunBlock ( S , 5 , 0 ,
SS_CALL_MDL_OUTPUTS ) ; f2e3v5ccex = _rtB -> kqnrloov3e - _rtDW -> edm2y2p3wp
; if ( f2e3v5ccex > 0.006 ) { lduwq00gqj = _rtDW -> edm2y2p3wp + 0.006 ; }
else if ( f2e3v5ccex < - 0.006 ) { lduwq00gqj = _rtDW -> edm2y2p3wp + - 0.006
; } else { lduwq00gqj = _rtB -> kqnrloov3e ; } _rtDW -> edm2y2p3wp =
lduwq00gqj ; lduwq00gqj *= - 382.64830010578072 ; f2e3v5ccex = _rtB ->
h0veg11mi0 - _rtDW -> asqvifamq0 ; if ( f2e3v5ccex > 0.006 ) { ckrl0nmlwt =
_rtDW -> asqvifamq0 + 0.006 ; } else if ( f2e3v5ccex < - 0.006 ) { ckrl0nmlwt
= _rtDW -> asqvifamq0 + - 0.006 ; } else { ckrl0nmlwt = _rtB -> h0veg11mi0 ;
} _rtDW -> asqvifamq0 = ckrl0nmlwt ; ckrl0nmlwt *= 382.64830010578072 ;
byehzqrbel = - lduwq00gqj * ctpq3axefx + ckrl0nmlwt * aqlslovppe ; iiis24gb3o
= byehzqrbel - lc4cnav21a_idx_0 ; if ( iiis24gb3o >= 0.0 ) { _rtDW ->
bmg0h5hxwy = true ; } else { if ( iiis24gb3o <= 0.0 ) { _rtDW -> bmg0h5hxwy =
false ; } } i5nu34w4uj = ( 1.7320508 * ctpq3axefx + - aqlslovppe ) *
ckrl0nmlwt * 0.5 + ( 1.7320508 * aqlslovppe + ctpq3axefx ) * lduwq00gqj * 0.5
; ctpq3axefx = i5nu34w4uj - lc4cnav21a_idx_1 ; if ( ctpq3axefx >= 0.0 ) {
_rtDW -> kakc11drsq = true ; } else { if ( ctpq3axefx <= 0.0 ) { _rtDW ->
kakc11drsq = false ; } } lstej3qx0u = ( 0.0 - i5nu34w4uj ) - byehzqrbel ;
aqlslovppe = lstej3qx0u - lc4cnav21a_idx_2 ; if ( aqlslovppe >= 0.0 ) { _rtDW
-> d1uemo0w03 = true ; } else { if ( aqlslovppe <= 0.0 ) { _rtDW ->
d1uemo0w03 = false ; } } _rtB -> pw1plqxdzr [ 0 ] = ( ( real_T ) _rtDW ->
bmg0h5hxwy - ( real_T ) _rtDW -> kakc11drsq ) * ld5zvvrfqt ( S ) ->
avxn4yfarf * _rtB -> lew1su5u2u ; _rtB -> pw1plqxdzr [ 1 ] = ( ( real_T )
_rtDW -> kakc11drsq - ( real_T ) _rtDW -> d1uemo0w03 ) * ld5zvvrfqt ( S ) ->
avxn4yfarf * _rtB -> lew1su5u2u ; _rtB -> l0yvdn5li4 = _rtDW -> kzrq2xyp0f ;
cq224qj4y1 = ( ld5zvvrfqt ( S ) -> aos5ylbxlz != 0.0 ) ; zcEvent_idx_0 =
rt_ZCFcn ( ANY_ZERO_CROSSING , & _rtZCE -> gn3hyklx0i [ 0 ] , ( dyfxp2slod )
) ; zcEvent_idx_1 = rt_ZCFcn ( ANY_ZERO_CROSSING , & _rtZCE -> gn3hyklx0i [ 1
] , ( dk4tk42hhp ) ) ; zcEvent_idx_2 = rt_ZCFcn ( ANY_ZERO_CROSSING , &
_rtZCE -> gn3hyklx0i [ 2 ] , ( f1b5simhxh ) ) ; if ( _rtDW -> p5ivrte15o [ 0
] == 0 ) { if ( zcEvent_idx_0 != NO_ZCEVENT ) { _rtB -> k1ubefzcfo [ 0 ] = !
_rtB -> k1ubefzcfo [ 0 ] ; _rtDW -> p5ivrte15o [ 0 ] = 1 ; } else if ( _rtB
-> k1ubefzcfo [ 0 ] ) { if ( dyfxp2slod != 0.0 ) { _rtB -> k1ubefzcfo [ 0 ] =
false ; } } else { if ( dyfxp2slod == 0.0 ) { _rtB -> k1ubefzcfo [ 0 ] = true
; } } } else { if ( dyfxp2slod != 0.0 ) { _rtB -> k1ubefzcfo [ 0 ] = false ;
} _rtDW -> p5ivrte15o [ 0 ] = 0 ; } if ( _rtDW -> p5ivrte15o [ 1 ] == 0 ) {
if ( zcEvent_idx_1 != NO_ZCEVENT ) { _rtB -> k1ubefzcfo [ 1 ] = ! _rtB ->
k1ubefzcfo [ 1 ] ; _rtDW -> p5ivrte15o [ 1 ] = 1 ; } else if ( _rtB ->
k1ubefzcfo [ 1 ] ) { if ( dk4tk42hhp != 0.0 ) { _rtB -> k1ubefzcfo [ 1 ] =
false ; } } else { if ( dk4tk42hhp == 0.0 ) { _rtB -> k1ubefzcfo [ 1 ] = true
; } } } else { if ( dk4tk42hhp != 0.0 ) { _rtB -> k1ubefzcfo [ 1 ] = false ;
} _rtDW -> p5ivrte15o [ 1 ] = 0 ; } if ( _rtDW -> p5ivrte15o [ 2 ] == 0 ) {
if ( zcEvent_idx_2 != NO_ZCEVENT ) { _rtB -> k1ubefzcfo [ 2 ] = ! _rtB ->
k1ubefzcfo [ 2 ] ; _rtDW -> p5ivrte15o [ 2 ] = 1 ; } else if ( _rtB ->
k1ubefzcfo [ 2 ] ) { if ( f1b5simhxh != 0.0 ) { _rtB -> k1ubefzcfo [ 2 ] =
false ; } } else { if ( f1b5simhxh == 0.0 ) { _rtB -> k1ubefzcfo [ 2 ] = true
; } } } else { if ( f1b5simhxh != 0.0 ) { _rtB -> k1ubefzcfo [ 2 ] = false ;
} _rtDW -> p5ivrte15o [ 2 ] = 0 ; } keyxmz53xi ( S , _rtB -> k1ubefzcfo [ 0 ]
, cq224qj4y1 , & _rtB -> keyxmz53xiy , & _rtDW -> keyxmz53xiy ) ; keyxmz53xi
( S , _rtB -> k1ubefzcfo [ 1 ] , cq224qj4y1 , & _rtB -> d5h5wn4011 , & _rtDW
-> d5h5wn4011 ) ; keyxmz53xi ( S , _rtB -> k1ubefzcfo [ 2 ] , cq224qj4y1 , &
_rtB -> hlr1ddtilb , & _rtDW -> hlr1ddtilb ) ; iiis24gb3o =
0.05823546641575128 * _rtDW -> nonllthbl2 ; ctpq3axefx = 0.05823546641575128
* _rtDW -> kol45dq53x ; aqlslovppe = muDoubleScalarSin ( jwhz1ujp3w ) ;
jwhz1ujp3w = muDoubleScalarCos ( jwhz1ujp3w ) ; lduwq00gqj = ( 0.0 -
aqlslovppe * ld5zvvrfqt ( S ) -> l2lrkhjror ) - jwhz1ujp3w * ld5zvvrfqt ( S )
-> pehlo1d22e ; ckrl0nmlwt = aqlslovppe * ld5zvvrfqt ( S ) -> pehlo1d22e -
jwhz1ujp3w * ld5zvvrfqt ( S ) -> l2lrkhjror ; h0cg4jnrg5 = ( iiis24gb3o *
aqlslovppe + ctpq3axefx * jwhz1ujp3w ) + ld5zvvrfqt ( S ) -> pe0ortttt2 ;
lfv3m5pb5c = ( iiis24gb3o * lduwq00gqj + ctpq3axefx * ckrl0nmlwt ) +
ld5zvvrfqt ( S ) -> pe0ortttt2 ; iiis24gb3o = ( ( ( 0.0 - lduwq00gqj ) -
aqlslovppe ) * iiis24gb3o + ( ( 0.0 - ckrl0nmlwt ) - jwhz1ujp3w ) *
ctpq3axefx ) + ld5zvvrfqt ( S ) -> pe0ortttt2 ; _rtB -> bdfn1dqo1s [ 0 ] = (
real_T ) _rtB -> keyxmz53xiy . forbrjhq11 * dyfxp2slod + 0.2 * h0cg4jnrg5 ;
_rtB -> bdfn1dqo1s [ 1 ] = ( real_T ) _rtB -> d5h5wn4011 . forbrjhq11 *
dk4tk42hhp + 0.2 * lfv3m5pb5c ; _rtB -> bdfn1dqo1s [ 2 ] = ( real_T ) _rtB ->
hlr1ddtilb . forbrjhq11 * f1b5simhxh + 0.2 * iiis24gb3o ; if ( _rtDW ->
ehaijafsot <= 1.0 ) { h0cg4jnrg5 = 1.0 ; } else { h0cg4jnrg5 = _rtDW ->
ehaijafsot ; } _rtB -> ecux00rxvh = _rtDW -> fw2k5vojpd / h0cg4jnrg5 ;
zcEvent_idx_0 = rt_ZCFcn ( ANY_ZERO_CROSSING , & _rtZCE -> iw5dmb04jk [ 0 ] ,
( byehzqrbel ) ) ; zcEvent_idx_1 = rt_ZCFcn ( ANY_ZERO_CROSSING , & _rtZCE ->
iw5dmb04jk [ 1 ] , ( i5nu34w4uj ) ) ; zcEvent_idx_2 = rt_ZCFcn (
ANY_ZERO_CROSSING , & _rtZCE -> iw5dmb04jk [ 2 ] , ( lstej3qx0u ) ) ; if (
_rtDW -> l43ws31i1a [ 0 ] == 0 ) { if ( zcEvent_idx_0 != NO_ZCEVENT ) { _rtB
-> e5ld3mnvtg [ 0 ] = ! _rtB -> e5ld3mnvtg [ 0 ] ; _rtDW -> l43ws31i1a [ 0 ]
= 1 ; } else if ( _rtB -> e5ld3mnvtg [ 0 ] ) { if ( byehzqrbel != 0.0 ) {
_rtB -> e5ld3mnvtg [ 0 ] = false ; } } else { if ( byehzqrbel == 0.0 ) { _rtB
-> e5ld3mnvtg [ 0 ] = true ; } } } else { if ( byehzqrbel != 0.0 ) { _rtB ->
e5ld3mnvtg [ 0 ] = false ; } _rtDW -> l43ws31i1a [ 0 ] = 0 ; } if ( _rtDW ->
l43ws31i1a [ 1 ] == 0 ) { if ( zcEvent_idx_1 != NO_ZCEVENT ) { _rtB ->
e5ld3mnvtg [ 1 ] = ! _rtB -> e5ld3mnvtg [ 1 ] ; _rtDW -> l43ws31i1a [ 1 ] = 1
; } else if ( _rtB -> e5ld3mnvtg [ 1 ] ) { if ( i5nu34w4uj != 0.0 ) { _rtB ->
e5ld3mnvtg [ 1 ] = false ; } } else { if ( i5nu34w4uj == 0.0 ) { _rtB ->
e5ld3mnvtg [ 1 ] = true ; } } } else { if ( i5nu34w4uj != 0.0 ) { _rtB ->
e5ld3mnvtg [ 1 ] = false ; } _rtDW -> l43ws31i1a [ 1 ] = 0 ; } if ( _rtDW ->
l43ws31i1a [ 2 ] == 0 ) { if ( zcEvent_idx_2 != NO_ZCEVENT ) { _rtB ->
e5ld3mnvtg [ 2 ] = ! _rtB -> e5ld3mnvtg [ 2 ] ; _rtDW -> l43ws31i1a [ 2 ] = 1
; } else if ( _rtB -> e5ld3mnvtg [ 2 ] ) { if ( lstej3qx0u != 0.0 ) { _rtB ->
e5ld3mnvtg [ 2 ] = false ; } } else { if ( lstej3qx0u == 0.0 ) { _rtB ->
e5ld3mnvtg [ 2 ] = true ; } } } else { if ( lstej3qx0u != 0.0 ) { _rtB ->
e5ld3mnvtg [ 2 ] = false ; } _rtDW -> l43ws31i1a [ 2 ] = 0 ; } keyxmz53xi ( S
, _rtB -> e5ld3mnvtg [ 0 ] , ld5zvvrfqt ( S ) -> n43m1vlqhy , & _rtB ->
ovboqennya , & _rtDW -> ovboqennya ) ; keyxmz53xi ( S , _rtB -> e5ld3mnvtg [
1 ] , ld5zvvrfqt ( S ) -> n43m1vlqhy , & _rtB -> ifhlf2te5a , & _rtDW ->
ifhlf2te5a ) ; keyxmz53xi ( S , _rtB -> e5ld3mnvtg [ 2 ] , ld5zvvrfqt ( S )
-> n43m1vlqhy , & _rtB -> dtnq4yt00p , & _rtDW -> dtnq4yt00p ) ; lfv3m5pb5c =
0.05823546641575128 * _rtDW -> lvw3lta2fy ; h0cg4jnrg5 = 0.05823546641575128
* _rtDW -> c20b4oc1jp ; ehcygfucdl *= 4.0 ; f2e3v5ccex = muDoubleScalarSin (
ehcygfucdl ) ; ehcygfucdl = muDoubleScalarCos ( ehcygfucdl ) ; lebvfutt11 = (
0.0 - f2e3v5ccex * ld5zvvrfqt ( S ) -> hbcx2vyfta ) - ehcygfucdl * ld5zvvrfqt
( S ) -> obbel2jaso ; iiis24gb3o = f2e3v5ccex * ld5zvvrfqt ( S ) ->
obbel2jaso - ehcygfucdl * ld5zvvrfqt ( S ) -> hbcx2vyfta ; lduwq00gqj = (
lfv3m5pb5c * f2e3v5ccex + h0cg4jnrg5 * ehcygfucdl ) + ld5zvvrfqt ( S ) ->
m45bvzbwxd ; ckrl0nmlwt = ( lfv3m5pb5c * lebvfutt11 + h0cg4jnrg5 * iiis24gb3o
) + ld5zvvrfqt ( S ) -> m45bvzbwxd ; lfv3m5pb5c = ( ( ( 0.0 - lebvfutt11 ) -
f2e3v5ccex ) * lfv3m5pb5c + ( ( 0.0 - iiis24gb3o ) - ehcygfucdl ) *
h0cg4jnrg5 ) + ld5zvvrfqt ( S ) -> m45bvzbwxd ; _rtB -> oafxzfdjhv [ 0 ] = (
real_T ) _rtB -> ovboqennya . forbrjhq11 * byehzqrbel + 1.5384615384615383 *
lduwq00gqj ; _rtB -> oafxzfdjhv [ 1 ] = ( real_T ) _rtB -> ifhlf2te5a .
forbrjhq11 * i5nu34w4uj + 1.5384615384615383 * ckrl0nmlwt ; _rtB ->
oafxzfdjhv [ 2 ] = ( real_T ) _rtB -> dtnq4yt00p . forbrjhq11 * lstej3qx0u +
1.5384615384615383 * lfv3m5pb5c ; if ( _rtDW -> kopxzfb0sb <= 1.0 ) {
h0cg4jnrg5 = 1.0 ; } else { h0cg4jnrg5 = _rtDW -> kopxzfb0sb ; } _rtB ->
a0hhmnezbe = _rtDW -> lp13v2ihui / h0cg4jnrg5 ; _rtB -> bj0jd4ffsv = _rtDW ->
ebwur5qeqq ; ssCallAccelRunBlock ( S , 16 , 492 , SS_CALL_MDL_OUTPUTS ) ;
_rtB -> kvbxxzddjn = _rtB -> afmxkvqw45 - 0.30769230769230771 * _rtB ->
jqbq23fhxi [ 33 ] ; ssCallAccelRunBlock ( S , 16 , 495 , SS_CALL_MDL_OUTPUTS
) ; lfv3m5pb5c = muDoubleScalarAbs ( _rtB -> jqbq23fhxi [ 33 ] ) ; _rtB ->
l5bk4ytw0f = ( ( real_T ) ( _rtB -> jqbq23fhxi [ 33 ] < ld5zvvrfqt ( S ) ->
chucomdobg ) * 18.82114106089411 - f4ufgq33gz ) * lfv3m5pb5c *
0.00064102564102564092 ; _rtB -> nbmku2aq4p = 3600.0 * eskeehll14 ; }
ssCallAccelRunBlock ( S , 14 , 0 , SS_CALL_MDL_OUTPUTS ) ; if ( _rtB ->
kkpq2kwxuh <= 1.0 ) { i5nu34w4uj = 1.0 ; } else { i5nu34w4uj = _rtB ->
kkpq2kwxuh ; } if ( ssIsMajorTimeStep ( S ) ) { if ( i5nu34w4uj >=
20.943951023931955 ) { _rtDW -> bmy4qihc4v = true ; } else { if ( i5nu34w4uj
<= 10.471975511965978 ) { _rtDW -> bmy4qihc4v = false ; } } } _rtB ->
opj41s5zot = ! _rtDW -> bmy4qihc4v ; if ( ssIsSampleHit ( S , 2 , 0 ) ) {
_rtB -> oxn35udia2 = ld5zvvrfqt ( S ) -> oeb4fnixti - ( ld5zvvrfqt ( S ) ->
drqvxpnrgk - _rtB -> kvbxxzddjn ) * 200.0 ; } ei5vcc44pf = _rtB -> oxn35udia2
; if ( ei5vcc44pf > 21000.0 ) { _rtB -> dybzfcfnxv = 21000.0 ; } else if (
ei5vcc44pf < 0.0 ) { _rtB -> dybzfcfnxv = 0.0 ; } else { _rtB -> dybzfcfnxv =
ei5vcc44pf ; } if ( ( _rtDW -> n33aen2wbt >= ssGetTaskTime ( S , 0 ) ) && (
_rtDW -> fjojh4ewqs >= ssGetTaskTime ( S , 0 ) ) ) { _rtB -> lsycnpudut =
_rtB -> dybzfcfnxv ; } else { if ( ( ( _rtDW -> n33aen2wbt < _rtDW ->
fjojh4ewqs ) && ( _rtDW -> fjojh4ewqs < ssGetTaskTime ( S , 0 ) ) ) || ( (
_rtDW -> n33aen2wbt >= _rtDW -> fjojh4ewqs ) && ( _rtDW -> n33aen2wbt >=
ssGetTaskTime ( S , 0 ) ) ) ) { iiis24gb3o = ssGetTaskTime ( S , 0 ) - _rtDW
-> fjojh4ewqs ; lebvfutt11 = _rtDW -> d21ysphefx ; } else { iiis24gb3o =
ssGetTaskTime ( S , 0 ) - _rtDW -> n33aen2wbt ; lebvfutt11 = _rtDW ->
evmu5j4txb ; } lstej3qx0u = iiis24gb3o * 210000.0 ; f2e3v5ccex = _rtB ->
dybzfcfnxv - lebvfutt11 ; if ( f2e3v5ccex > lstej3qx0u ) { _rtB -> lsycnpudut
= lebvfutt11 + lstej3qx0u ; } else { iiis24gb3o *= - 210000.0 ; if (
f2e3v5ccex < iiis24gb3o ) { _rtB -> lsycnpudut = lebvfutt11 + iiis24gb3o ; }
else { _rtB -> lsycnpudut = _rtB -> dybzfcfnxv ; } } } fviymzl3aa = ( _rtB ->
hijbmmvub5 != ld5zvvrfqt ( S ) -> dyykireftb ) ; byehzqrbel = j0jhyqa1p3 -
_rtB -> htjriwobeu [ 1 ] * _rtB -> m2y1khvsri [ 11 ] ; if ( fviymzl3aa ) {
_rtB -> mnzn4koylg = _rtB -> hijbmmvub5 ; } else { _rtB -> mnzn4koylg =
byehzqrbel ; } if ( ( _rtDW -> nolj4flzwb >= ssGetTaskTime ( S , 0 ) ) && (
_rtDW -> bluedlz4ee >= ssGetTaskTime ( S , 0 ) ) ) { _rtB -> h4hofwicsz =
_rtB -> mnzn4koylg ; } else { if ( ( ( _rtDW -> nolj4flzwb < _rtDW ->
bluedlz4ee ) && ( _rtDW -> bluedlz4ee < ssGetTaskTime ( S , 0 ) ) ) || ( (
_rtDW -> nolj4flzwb >= _rtDW -> bluedlz4ee ) && ( _rtDW -> nolj4flzwb >=
ssGetTaskTime ( S , 0 ) ) ) ) { iiis24gb3o = ssGetTaskTime ( S , 0 ) - _rtDW
-> bluedlz4ee ; lebvfutt11 = _rtDW -> awi4nxie0m ; } else { iiis24gb3o =
ssGetTaskTime ( S , 0 ) - _rtDW -> nolj4flzwb ; lebvfutt11 = _rtDW ->
ppmw3hzciy ; } lstej3qx0u = iiis24gb3o * 21000.0 ; f2e3v5ccex = _rtB ->
mnzn4koylg - lebvfutt11 ; if ( f2e3v5ccex > lstej3qx0u ) { _rtB -> h4hofwicsz
= lebvfutt11 + lstej3qx0u ; } else { iiis24gb3o *= - 21000.0 ; if (
f2e3v5ccex < iiis24gb3o ) { _rtB -> h4hofwicsz = lebvfutt11 + iiis24gb3o ; }
else { _rtB -> h4hofwicsz = _rtB -> mnzn4koylg ; } } } if ( _rtB ->
opj41s5zot != 0.0 ) { _rtB -> eyavresob4 = _rtB -> bwqretfuxy ; } else { if (
fviymzl3aa ) { byehzqrbel = _rtB -> h4hofwicsz ; } if ( byehzqrbel > _rtB ->
lsycnpudut ) { byehzqrbel = _rtB -> lsycnpudut ; } else { if ( byehzqrbel < -
_rtB -> lsycnpudut ) { byehzqrbel = - _rtB -> lsycnpudut ; } } _rtB ->
eyavresob4 = ( _rtB -> m2y1khvsri [ 7 ] * _rtB -> pqvfeo32cg + byehzqrbel ) /
i5nu34w4uj ; } ssCallAccelRunBlock ( S , 16 , 545 , SS_CALL_MDL_OUTPUTS ) ;
if ( ssIsSampleHit ( S , 2 , 0 ) ) { ssCallAccelRunBlock ( S , 16 , 546 ,
SS_CALL_MDL_OUTPUTS ) ; } ssCallAccelRunBlock ( S , 16 , 547 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> kf3t5b41va = 9.5492965855137211 * _rtB ->
kkpq2kwxuh ; if ( ssIsSampleHit ( S , 2 , 0 ) && ssIsSampleHit ( S , 3 , 0 )
) { _rtB -> jybu53irkl = _rtDW -> bv5gvrfela ; } _rtB -> bxp415etnk = _rtB ->
kgfazmviyv * _rtB -> kkpq2kwxuh ; ssCallAccelRunBlock ( S , 16 , 551 ,
SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSampleHit ( S , 2 , 0 ) ) {
ssCallAccelRunBlock ( S , 16 , 554 , SS_CALL_MDL_OUTPUTS ) ; }
ssCallAccelRunBlock ( S , 16 , 555 , SS_CALL_MDL_OUTPUTS ) ; if (
ssIsSampleHit ( S , 2 , 0 ) ) { lfv3m5pb5c = 0.013480000230266853 * _rtDW ->
pe31gvq3pv ; h0cg4jnrg5 = 0.013480000230266853 * _rtDW -> bw5cwo255x ; rowIdx
= ( int32_T ) ( ( ( ( ( uint32_T ) ( lfv3m5pb5c > h0cg4jnrg5 ) << 1 ) + (
lfv3m5pb5c < 0.9 * h0cg4jnrg5 ) ) << 1 ) + _rtDW -> l2t4rgxmml ) ; _rtB ->
eodsxjmoej [ 0U ] = ni220kbneq . nzwc2c2eqf [ ( uint32_T ) rowIdx ] ; _rtB ->
eodsxjmoej [ 1U ] = ni220kbneq . nzwc2c2eqf [ rowIdx + 8U ] ; h100jbae3x = (
uint8_T ) ( _rtB -> eodsxjmoej [ 0 ] << 7 ) ; _rtB -> mu3wxyiasc = ( real_T )
h100jbae3x * 0.0078125 ; _rtB -> p33zoq5jnj = ( real_T ) h100jbae3x *
0.0078125 ; _rtB -> corkyfkthr = ( real_T ) h100jbae3x * 0.0078125 ;
fviymzl3aa = ! ( h100jbae3x != 0 ) ; _rtB -> gyfx4c1wz4 = fviymzl3aa ; _rtB
-> eqyqdfw5zw = fviymzl3aa ; _rtB -> j41et2hkmg = fviymzl3aa ; _rtB ->
etirgqau3o = ( ( _rtB -> jqbq23fhxi [ 30 ] * _rtB -> jqbq23fhxi [ 30 ] + _rtB
-> jqbq23fhxi [ 31 ] * _rtB -> jqbq23fhxi [ 31 ] ) + _rtB -> jqbq23fhxi [ 32
] * _rtB -> jqbq23fhxi [ 32 ] ) * 0.001 + ( _rtB -> jqbq23fhxi [ 21 ] * _rtB
-> jqbq23fhxi [ 30 ] + _rtB -> jqbq23fhxi [ 22 ] * _rtB -> jqbq23fhxi [ 31 ]
) ; } byehzqrbel = muDoubleScalarPower ( ( 0.006391889398924 * _rtB ->
kkpq2kwxuh * _rtB -> aorbsvsy2v + 0.0065 * _rtB -> deue3miwlt ) +
0.702664574517444 * _rtB -> kkpq2kwxuh , 2.0 ) + muDoubleScalarPower ( 0.0065
* _rtB -> aorbsvsy2v - 0.008228209001868 * _rtB -> kkpq2kwxuh * _rtB ->
deue3miwlt , 2.0 ) ; if ( byehzqrbel < 0.0 ) { byehzqrbel = -
muDoubleScalarSqrt ( - byehzqrbel ) ; } else { byehzqrbel =
muDoubleScalarSqrt ( byehzqrbel ) ; } _rtB -> hkhe1qfrqk = 1.5707963267948966
* byehzqrbel ; if ( ssIsSampleHit ( S , 2 , 0 ) ) { _rtB -> dzrmwbehc5 = ( (
2.0 * _rtB -> jqbq23fhxi [ 14 ] + _rtB -> jqbq23fhxi [ 15 ] ) * mizlp41tvx +
1.7320508075688772 * _rtB -> jqbq23fhxi [ 15 ] * po0ockmy2b ) *
0.33333333333333331 ; _rtB -> lyzuxjnzrt = ( ( 2.0 * _rtB -> jqbq23fhxi [ 14
] + _rtB -> jqbq23fhxi [ 15 ] ) * po0ockmy2b + - 1.7320508075688772 * _rtB ->
jqbq23fhxi [ 15 ] * mizlp41tvx ) * 0.33333333333333331 ; _rtB -> fk5onszcs3 =
625.79305591134812 * _rtB -> lyzuxjnzrt ; } _rtB -> d4jqz2ve5w = 4.0 * _rtB
-> kkpq2kwxuh ; if ( ssIsSampleHit ( S , 2 , 0 ) ) { _rtB -> dpg2pi1nvq =
4.0676548634237628 * _rtB -> aorbsvsy2v ; } _rtB -> cj4r3orqto = _rtB ->
d4jqz2ve5w * _rtB -> deue3miwlt * 1.2872890139890598 + ( _rtB -> fk5onszcs3 -
_rtB -> dpg2pi1nvq ) ; if ( ssIsSampleHit ( S , 2 , 0 ) ) { _rtB ->
csozflsux3 = 486.13252277523628 * _rtB -> dzrmwbehc5 ; _rtB -> abn51ebowi =
3.1598613980390358 * _rtB -> deue3miwlt ; } _rtB -> ebdm2xapr0 = ( ( _rtB ->
csozflsux3 - _rtB -> abn51ebowi ) - _rtB -> aorbsvsy2v * _rtB -> d4jqz2ve5w *
0.77682632969980325 ) - 85.397025568738272 * _rtB -> d4jqz2ve5w ; ei5vcc44pf
= muDoubleScalarAbs ( _rtB -> kkpq2kwxuh ) ; HEV_acc_LookUp_real_T_real_T ( &
( dks5t0rchn ) , ni220kbneq . pormlyvumi , ei5vcc44pf , ni220kbneq .
johzj1udqh , 6U ) ; if ( _rtB -> eyavresob4 > dks5t0rchn ) { ei5vcc44pf =
dks5t0rchn ; } else if ( _rtB -> eyavresob4 < - dks5t0rchn ) { ei5vcc44pf = -
dks5t0rchn ; } else { ei5vcc44pf = _rtB -> eyavresob4 ; } ei5vcc44pf *=
ld5zvvrfqt ( S ) -> avxn4yfarf ; if ( ( _rtDW -> dlegz3mcx5 == ( rtMinusInf )
) || ( _rtDW -> dlegz3mcx5 == ssGetTaskTime ( S , 0 ) ) ) { _rtDW ->
dlegz3mcx5 = ssGetTaskTime ( S , 0 ) ; _rtB -> hcgjikrwsl = 0.0 ; } else {
_rtB -> hcgjikrwsl = ei5vcc44pf ; } if ( ssIsSampleHit ( S , 3 , 0 ) ) { _rtB
-> bzue2s3eub = _rtB -> hcgjikrwsl ; if ( _rtB -> bzue2s3eub > 400.0 ) { _rtB
-> oomejsu5n4 = 400.0 ; } else if ( _rtB -> bzue2s3eub < - 400.0 ) { _rtB ->
oomejsu5n4 = - 400.0 ; } else { _rtB -> oomejsu5n4 = _rtB -> bzue2s3eub ; } }
if ( ssIsSampleHit ( S , 1 , 0 ) && ssIsSampleHit ( S , 3 , 0 ) ) { _rtB ->
etf4l0im20 = ld5zvvrfqt ( S ) -> avxn4yfarf ; } if ( ssIsSampleHit ( S , 3 ,
0 ) ) { _rtB -> pj1s4bwo5p = _rtB -> oomejsu5n4 * _rtB -> etf4l0im20 ; } if (
ssIsSampleHit ( S , 2 , 0 ) ) { ssCallAccelRunBlock ( S , 16 , 696 ,
SS_CALL_MDL_OUTPUTS ) ; } ssCallAccelRunBlock ( S , 16 , 697 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> kf3t5b41va = 9.5492965855137211 * _rtB ->
m2y1khvsri [ 7 ] ; if ( ssIsSampleHit ( S , 1 , 0 ) && ssIsSampleHit ( S , 2
, 0 ) ) { _rtB -> psae1mjui2 = ld5zvvrfqt ( S ) -> aos5ylbxlz ; } if (
ssIsSampleHit ( S , 2 , 0 ) ) { _rtB -> htkosoanli = dztyrqu4xa * _rtB ->
psae1mjui2 ; } _rtB -> bxp415etnk = _rtB -> netq4xlqvp * _rtB -> m2y1khvsri [
7 ] ; ssCallAccelRunBlock ( S , 16 , 702 , SS_CALL_MDL_OUTPUTS ) ; if (
ssIsSampleHit ( S , 2 , 0 ) ) { lfv3m5pb5c = 0.013480000230266853 * _rtDW ->
dy4ppyw4mo ; h0cg4jnrg5 = 0.013480000230266853 * _rtDW -> hmybg5b1mi ; rowIdx
= ( int32_T ) ( ( ( ( ( uint32_T ) ( lfv3m5pb5c > h0cg4jnrg5 ) << 1 ) + (
lfv3m5pb5c < 0.9 * h0cg4jnrg5 ) ) << 1 ) + _rtDW -> gkq12xkctn ) ; _rtB ->
e0swysjneh [ 0U ] = ni220kbneq . nzwc2c2eqf [ ( uint32_T ) rowIdx ] ; _rtB ->
e0swysjneh [ 1U ] = ni220kbneq . nzwc2c2eqf [ rowIdx + 8U ] ; h100jbae3x = (
uint8_T ) ( _rtB -> e0swysjneh [ 0 ] << 7 ) ; _rtB -> jqhlnwwwe5 = ( real_T )
h100jbae3x * 0.0078125 ; _rtB -> mcoyjrns5b = ( real_T ) h100jbae3x *
0.0078125 ; _rtB -> grpqmw1rb2 = ( real_T ) h100jbae3x * 0.0078125 ;
fviymzl3aa = ! ( h100jbae3x != 0 ) ; _rtB -> kdx02nknrv = fviymzl3aa ; _rtB
-> nqrqg5qjte = fviymzl3aa ; _rtB -> pqzkg0lv54 = fviymzl3aa ; _rtB ->
avcb2vosfu = ( ( _rtB -> jqbq23fhxi [ 26 ] * _rtB -> jqbq23fhxi [ 26 ] + _rtB
-> jqbq23fhxi [ 27 ] * _rtB -> jqbq23fhxi [ 27 ] ) + _rtB -> jqbq23fhxi [ 28
] * _rtB -> jqbq23fhxi [ 28 ] ) * 0.001 + ( _rtB -> jqbq23fhxi [ 17 ] * _rtB
-> jqbq23fhxi [ 26 ] + _rtB -> jqbq23fhxi [ 18 ] * _rtB -> jqbq23fhxi [ 27 ]
) ; } byehzqrbel = muDoubleScalarPower ( ( 0.000635 * _rtB -> m2y1khvsri [ 7
] * _rtB -> gthgcz50sq + 0.05 * _rtB -> bw2nhi51td ) + 0.192 * _rtB ->
m2y1khvsri [ 7 ] , 2.0 ) + muDoubleScalarPower ( 0.05 * _rtB -> gthgcz50sq -
0.000635 * _rtB -> m2y1khvsri [ 7 ] * _rtB -> bw2nhi51td , 2.0 ) ; if (
byehzqrbel < 0.0 ) { byehzqrbel = - muDoubleScalarSqrt ( - byehzqrbel ) ; }
else { byehzqrbel = muDoubleScalarSqrt ( byehzqrbel ) ; } _rtB -> hfvjerekxn
= 1.5707963267948966 * byehzqrbel ; if ( ssIsSampleHit ( S , 2 , 0 ) ) { _rtB
-> indjzxedww = ( ( 2.0 * _rtB -> jqbq23fhxi [ 12 ] + _rtB -> jqbq23fhxi [ 13
] ) * mkcfwi2fsi + 1.7320508075688772 * _rtB -> jqbq23fhxi [ 13 ] *
ehtkh2wauy ) * 0.33333333333333331 ; _rtB -> f0nqistfq2 = ( ( 2.0 * _rtB ->
jqbq23fhxi [ 12 ] + _rtB -> jqbq23fhxi [ 13 ] ) * ehtkh2wauy + -
1.7320508075688772 * _rtB -> jqbq23fhxi [ 13 ] * mkcfwi2fsi ) *
0.33333333333333331 ; _rtB -> mv4ljavuas = 1574.803149606299 * _rtB ->
f0nqistfq2 ; _rtB -> igeizk0kgg = 78.740157480314963 * _rtB -> gthgcz50sq ; }
_rtB -> h4hdvz1ojz = ( _rtB -> mv4ljavuas - _rtB -> igeizk0kgg ) + _rtB ->
m2y1khvsri [ 7 ] * _rtB -> bw2nhi51td ; if ( ssIsSampleHit ( S , 2 , 0 ) ) {
_rtB -> hqriu5elkp = 1574.803149606299 * _rtB -> indjzxedww ; _rtB ->
hg5oxo0fos = 78.740157480314963 * _rtB -> bw2nhi51td ; } _rtB -> azrh5zhoj1 =
( ( _rtB -> hqriu5elkp - _rtB -> hg5oxo0fos ) - _rtB -> gthgcz50sq * _rtB ->
m2y1khvsri [ 7 ] ) - 302.36220472440942 * _rtB -> m2y1khvsri [ 7 ] ; if (
ssIsSampleHit ( S , 2 , 0 ) ) { ssCallAccelRunBlock ( S , 16 , 831 ,
SS_CALL_MDL_OUTPUTS ) ; } ei5vcc44pf = ssGetT ( S ) ; if ( ssIsSampleHit ( S
, 2 , 0 ) ) { _rtB -> ddjw5mvvyn = _rtB -> jqbq23fhxi [ 16 ] - ld5zvvrfqt ( S
) -> f4itz54uxy ; } _rtB -> irchshx0ry = ( real_T ) ( ei5vcc44pf > ld5zvvrfqt
( S ) -> ovb4o0pkxe ) * _rtB -> ddjw5mvvyn ; if ( ssIsSampleHit ( S , 2 , 0 )
) { if ( _rtDW -> llu3sg1ihp != 0 ) { _rtB -> krg1d2xh0a = _rtDW ->
fj2gixcnhk ; } else { _rtB -> krg1d2xh0a = 3.0E-5 * _rtB -> irchshx0ry +
_rtDW -> fj2gixcnhk ; } if ( _rtB -> krg1d2xh0a >= 1.0 ) { _rtB -> krg1d2xh0a
= 1.0 ; } else { if ( _rtB -> krg1d2xh0a <= - 1.0 ) { _rtB -> krg1d2xh0a = -
1.0 ; } } } ei5vcc44pf = 0.001 * _rtB -> irchshx0ry + _rtB -> krg1d2xh0a ; if
( ei5vcc44pf > 0.95 ) { h0cg4jnrg5 = 0.95 ; } else if ( ei5vcc44pf < - 0.95 )
{ h0cg4jnrg5 = - 0.95 ; } else { h0cg4jnrg5 = ei5vcc44pf ; } _rtB ->
bnjekjvigq = ( h0cg4jnrg5 + 1.0 ) * 0.5 ; if ( ssIsSampleHit ( S , 2 , 0 ) )
{ lfv3m5pb5c = _rtDW -> dco4afubi3 ; _rtB -> dcr5pclngn = _rtDW -> dco4afubi3
* _rtB -> jqbq23fhxi [ 24 ] ; _rtB -> lebkafl2xg = _rtDW -> dco4afubi3 * _rtB
-> jqbq23fhxi [ 34 ] ; } ssCallAccelRunBlock ( S , 16 , 878 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 16 , 879 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 16 , 880 ,
SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSampleHit ( S , 2 , 0 ) ) {
ssCallAccelRunBlock ( S , 16 , 881 , SS_CALL_MDL_OUTPUTS ) ; } if (
ssIsSampleHit ( S , 4 , 0 ) ) { ssCallAccelRunBlock ( S , 16 , 882 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 16 , 883 ,
SS_CALL_MDL_OUTPUTS ) ; } if ( _rtB -> pymde5nzv1 > 136.0 ) { h0cg4jnrg5 =
136.0 ; } else if ( _rtB -> pymde5nzv1 < 0.0 ) { h0cg4jnrg5 = 0.0 ; } else {
h0cg4jnrg5 = _rtB -> pymde5nzv1 ; } ei5vcc44pf = h0cg4jnrg5 * ld5zvvrfqt ( S
) -> nzabkt43tm ; if ( ei5vcc44pf > 1.0 ) { _rtB -> kf3t5b41va = 1.0 ; } else
if ( ei5vcc44pf < 0.0 ) { _rtB -> kf3t5b41va = 0.0 ; } else { _rtB ->
kf3t5b41va = ei5vcc44pf ; } ssCallAccelRunBlock ( S , 16 , 888 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 16 , 889 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 16 , 890 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 16 , 891 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 16 , 892 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 16 , 893 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 16 , 894 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 16 , 895 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 16 , 896 ,
SS_CALL_MDL_OUTPUTS ) ; ei5vcc44pf = _rtB -> mcetl23ukz * ( real_T )
o3khhk3fbg ; if ( ( _rtDW -> nn1a5wvgr5 == ( rtMinusInf ) ) || ( _rtDW ->
nn1a5wvgr5 == ssGetTaskTime ( S , 0 ) ) ) { _rtDW -> nn1a5wvgr5 =
ssGetTaskTime ( S , 0 ) ; _rtB -> ftrqot2dom = 0.0 ; } else { _rtB ->
ftrqot2dom = ei5vcc44pf ; } if ( ( _rtDW -> ewhcynzuun >= ssGetTaskTime ( S ,
0 ) ) && ( _rtDW -> ciu3b0lpet >= ssGetTaskTime ( S , 0 ) ) ) { _rtB ->
onkav0tkia = _rtB -> ftrqot2dom ; } else { if ( ( ( _rtDW -> ewhcynzuun <
_rtDW -> ciu3b0lpet ) && ( _rtDW -> ciu3b0lpet < ssGetTaskTime ( S , 0 ) ) )
|| ( ( _rtDW -> ewhcynzuun >= _rtDW -> ciu3b0lpet ) && ( _rtDW -> ewhcynzuun
>= ssGetTaskTime ( S , 0 ) ) ) ) { iiis24gb3o = ssGetTaskTime ( S , 0 ) -
_rtDW -> ciu3b0lpet ; lebvfutt11 = _rtDW -> mmlyeyihwy ; } else { iiis24gb3o
= ssGetTaskTime ( S , 0 ) - _rtDW -> ewhcynzuun ; lebvfutt11 = _rtDW ->
h4ipbzntlo ; } lstej3qx0u = iiis24gb3o * 50000.0 ; f2e3v5ccex = _rtB ->
ftrqot2dom - lebvfutt11 ; if ( f2e3v5ccex > lstej3qx0u ) { _rtB -> onkav0tkia
= lebvfutt11 + lstej3qx0u ; } else { iiis24gb3o *= - 50000.0 ; if (
f2e3v5ccex < iiis24gb3o ) { _rtB -> onkav0tkia = lebvfutt11 + iiis24gb3o ; }
else { _rtB -> onkav0tkia = _rtB -> ftrqot2dom ; } } } if ( ssIsSampleHit ( S
, 2 , 0 ) ) { _rtB -> etcuzcgrf5 = o3khhk3fbg ; h0cg4jnrg5 = ( _rtB ->
onkav0tkia - 0.036997346603025116 * _rtDW -> jctbfc4f1e ) * ( real_T ) _rtB
-> etcuzcgrf5 ; _rtB -> kdqwoukw3f = 0.1 * h0cg4jnrg5 ; if ( _rtDW ->
h4pa1qmmy5 != 0 ) { _rtB -> lteqbz0ryo = _rtDW -> olv3cnxtoy ; } else { _rtB
-> lteqbz0ryo = 3.0E-5 * _rtB -> kdqwoukw3f + _rtDW -> olv3cnxtoy ; } if (
_rtB -> lteqbz0ryo >= 1.0 ) { _rtB -> lteqbz0ryo = 1.0 ; } else { if ( _rtB
-> lteqbz0ryo <= 0.0 ) { _rtB -> lteqbz0ryo = 0.0 ; } } lfv3m5pb5c = 0.01 *
h0cg4jnrg5 + _rtB -> lteqbz0ryo ; if ( lfv3m5pb5c > 1.0 ) { lfv3m5pb5c = 1.0
; } else { if ( lfv3m5pb5c < 0.0 ) { lfv3m5pb5c = 0.0 ; } } } ei5vcc44pf =
_rtB -> m2y1khvsri [ 11 ] * ( real_T ) o3khhk3fbg ; _rtB -> imyvmhrmra =
9.5492965855137211 * ei5vcc44pf ; if ( ssIsSampleHit ( S , 2 , 0 ) ) { _rtB
-> ea0hte4exs = _rtB -> imyvmhrmra ; _rtB -> lz5cv3wcwq = lfv3m5pb5c * (
real_T ) _rtB -> etcuzcgrf5 ; } _rtB -> pjan2pzjoc = muDoubleScalarAbs ( _rtB
-> chkwevbcym ) ; if ( ( _rtDW -> en15lu4hm1 >= ssGetT ( S ) ) && ( _rtDW ->
km4yirabra >= ssGetT ( S ) ) ) { _rtB -> falwl051fx = 0.0 ; } else {
byehzqrbel = _rtDW -> en15lu4hm1 ; lastU = & _rtDW -> aa3vndu55f ; if ( _rtDW
-> en15lu4hm1 < _rtDW -> km4yirabra ) { if ( _rtDW -> km4yirabra < ssGetT ( S
) ) { byehzqrbel = _rtDW -> km4yirabra ; lastU = & _rtDW -> ke4dqjfdz3 ; } }
else { if ( _rtDW -> en15lu4hm1 >= ssGetT ( S ) ) { byehzqrbel = _rtDW ->
km4yirabra ; lastU = & _rtDW -> ke4dqjfdz3 ; } } _rtB -> falwl051fx = ( _rtB
-> g123hlbqqb - * lastU ) / ( ssGetT ( S ) - byehzqrbel ) ; } _rtB ->
ahfhbgxda5 = muDoubleScalarAbs ( _rtB -> ib5hrgd3aj ) ; _rtB -> bgk1vgojv4 =
1.093 * _rtB -> ahfhbgxda5 ; _rtB -> l1cs30ukud = 1.0464 * _rtB -> g123hlbqqb
; { uint32_T iLeftU0 , iRghtU0 , iLeftU1 , iRghtU1 ;
HEV_acc_BINARYSEARCH_real_T ( & ( iLeftU0 ) , & ( iRghtU0 ) , _rtB ->
bgk1vgojv4 , ni220kbneq . bvhb4ijxid , 108U ) ; if ( _rtB -> l1cs30ukud <=
0.0 ) { iLeftU1 = 0U ; iRghtU1 = 0U ; } else if ( _rtB -> l1cs30ukud >=
6000.0 ) { iLeftU1 = 100U ; iRghtU1 = 100U ; } else { iLeftU1 = ( uint32_T )
( ( _rtB -> l1cs30ukud ) / 60.0 ) ; iRghtU1 = iLeftU1 + 1 ; } { real_T yTemp
; real_T u1Lambda ; real_T u0Lambda ; if ( iLeftU1 != iRghtU1 ) { { real_T
num = ( real_T ) ( _rtB -> l1cs30ukud ) - ( iLeftU1 * 60.0 ) ; u1Lambda = num
/ 60.0 ; } } else { u1Lambda = 0.0 ; } if ( ( ni220kbneq . bvhb4ijxid [
iRghtU0 ] ) > ( ni220kbneq . bvhb4ijxid [ iLeftU0 ] ) ) { real_T num ; real_T
den ; den = ( ni220kbneq . bvhb4ijxid [ iRghtU0 ] ) ; den -= ( ni220kbneq .
bvhb4ijxid [ iLeftU0 ] ) ; num = _rtB -> bgk1vgojv4 ; num -= ( ni220kbneq .
bvhb4ijxid [ iLeftU0 ] ) ; u0Lambda = num / den ; } else { u0Lambda = 0.0 ; }
{ real_T yLeftCast ; real_T yRghtCast ; yLeftCast = ( ni220kbneq . aeijn3z5nk
[ ( iLeftU0 + 109U * iLeftU1 ) ] ) ; yRghtCast = ( ni220kbneq . aeijn3z5nk [
( iLeftU0 + 109U * iRghtU1 ) ] ) ; yLeftCast += u1Lambda * ( yRghtCast -
yLeftCast ) ; iiwpljhiwm = yLeftCast ; } { real_T yLeftCast ; real_T
yRghtCast ; yLeftCast = ( ni220kbneq . aeijn3z5nk [ ( iRghtU0 + 109U *
iLeftU1 ) ] ) ; yRghtCast = ( ni220kbneq . aeijn3z5nk [ ( iRghtU0 + 109U *
iRghtU1 ) ] ) ; yLeftCast += u1Lambda * ( yRghtCast - yLeftCast ) ; yTemp =
yLeftCast ; } { real_T yLeftCast ; real_T yRghtCast ; yLeftCast = iiwpljhiwm
; yRghtCast = yTemp ; yLeftCast += u0Lambda * ( yRghtCast - yLeftCast ) ;
iiwpljhiwm = yLeftCast ; } } } _rtB -> kp4w2bddel = 1.0351048413332149 *
iiwpljhiwm ; _rtB -> dlzezfoyb3 = 1.933764640184292E-6 * _rtB -> kp4w2bddel ;
_rtB -> hovggos5y0 = muDoubleScalarSign ( _rtB -> ib5hrgd3aj ) ; _rtB ->
hmeu1uri5n = muDoubleScalarAbs ( _rtB -> ib5hrgd3aj ) ; _rtB -> playujyhwt =
1.093 * _rtB -> hmeu1uri5n ; _rtB -> j5gxzbowrb = 1.0464 * _rtB -> g123hlbqqb
; { uint32_T iLeftU0 , iRghtU0 , iLeftU1 , iRghtU1 ;
HEV_acc_BINARYSEARCH_real_T ( & ( iLeftU0 ) , & ( iRghtU0 ) , _rtB ->
playujyhwt , ni220kbneq . bvhb4ijxid , 108U ) ; if ( _rtB -> j5gxzbowrb <=
0.0 ) { iLeftU1 = 0U ; iRghtU1 = 0U ; } else if ( _rtB -> j5gxzbowrb >=
6000.0 ) { iLeftU1 = 100U ; iRghtU1 = 100U ; } else { iLeftU1 = ( uint32_T )
( ( _rtB -> j5gxzbowrb ) / 60.0 ) ; iRghtU1 = iLeftU1 + 1 ; } { real_T yTemp
; real_T u1Lambda ; real_T u0Lambda ; if ( iLeftU1 != iRghtU1 ) { { real_T
num = ( real_T ) ( _rtB -> j5gxzbowrb ) - ( iLeftU1 * 60.0 ) ; u1Lambda = num
/ 60.0 ; } } else { u1Lambda = 0.0 ; } if ( ( ni220kbneq . bvhb4ijxid [
iRghtU0 ] ) > ( ni220kbneq . bvhb4ijxid [ iLeftU0 ] ) ) { real_T num ; real_T
den ; den = ( ni220kbneq . bvhb4ijxid [ iRghtU0 ] ) ; den -= ( ni220kbneq .
bvhb4ijxid [ iLeftU0 ] ) ; num = _rtB -> playujyhwt ; num -= ( ni220kbneq .
bvhb4ijxid [ iLeftU0 ] ) ; u0Lambda = num / den ; } else { u0Lambda = 0.0 ; }
{ real_T yLeftCast ; real_T yRghtCast ; yLeftCast = ( ni220kbneq . osuhnhw40g
[ ( iLeftU0 + 109U * iLeftU1 ) ] ) ; yRghtCast = ( ni220kbneq . osuhnhw40g [
( iLeftU0 + 109U * iRghtU1 ) ] ) ; yLeftCast += u1Lambda * ( yRghtCast -
yLeftCast ) ; achaqmub1c = yLeftCast ; } { real_T yLeftCast ; real_T
yRghtCast ; yLeftCast = ( ni220kbneq . osuhnhw40g [ ( iRghtU0 + 109U *
iLeftU1 ) ] ) ; yRghtCast = ( ni220kbneq . osuhnhw40g [ ( iRghtU0 + 109U *
iRghtU1 ) ] ) ; yLeftCast += u1Lambda * ( yRghtCast - yLeftCast ) ; yTemp =
yLeftCast ; } { real_T yLeftCast ; real_T yRghtCast ; yLeftCast = achaqmub1c
; yRghtCast = yTemp ; yLeftCast += u0Lambda * ( yRghtCast - yLeftCast ) ;
achaqmub1c = yLeftCast ; } } } _rtB -> f2cbecm00b = 1.0351048413332149 *
achaqmub1c ; _rtB -> fnbty0jpov = _rtB -> hovggos5y0 * _rtB -> f2cbecm00b ;
_rtB -> jnmszj4rxf = _rtB -> fnbty0jpov * _rtB -> falwl051fx ; _rtB ->
be3ik2tg4h = 1.933764640184292E-6 * _rtB -> jnmszj4rxf ; _rtB -> ogjl2s0i0b =
_rtB -> pjan2pzjoc * _rtB -> ib5hrgd3aj ; if ( _rtB -> dlzezfoyb3 <= 0.02 ) {
_rtB -> natwmlp4lc = 0.02 ; } else { _rtB -> natwmlp4lc = _rtB -> dlzezfoyb3
; } _rtB -> ou31fz5yri = ( ( 0.0 - _rtB -> be3ik2tg4h ) - _rtB -> mcmpwax5wu
) - _rtB -> ogjl2s0i0b ; _rtB -> kasim24bnz = 1.0 / _rtB -> natwmlp4lc * _rtB
-> ou31fz5yri ; _rtB -> k0t5t04nkj = _rtB -> mv0scjuozy + _rtB -> cwuinypz5p
; _rtB -> iocsb2frxj = ( _rtB -> k0t5t04nkj - _rtB -> jdx1oh4myt ) -
ld5zvvrfqt ( S ) -> oapjufkr55 ; _rtB -> dbfqfu1h3z = 0.00075471698113207543
* _rtB -> iocsb2frxj ; _rtB -> bmmyrr0up3 = muDoubleScalarAbs ( _rtB ->
chkwevbcym ) ; if ( ( _rtDW -> cgi523usaj >= ssGetT ( S ) ) && ( _rtDW ->
irt5havirw >= ssGetT ( S ) ) ) { _rtB -> irv2xtzte1 = 0.0 ; } else {
byehzqrbel = _rtDW -> cgi523usaj ; lastU = & _rtDW -> edrzze2flm ; if ( _rtDW
-> cgi523usaj < _rtDW -> irt5havirw ) { if ( _rtDW -> irt5havirw < ssGetT ( S
) ) { byehzqrbel = _rtDW -> irt5havirw ; lastU = & _rtDW -> gljjadsfzv ; } }
else { if ( _rtDW -> cgi523usaj >= ssGetT ( S ) ) { byehzqrbel = _rtDW ->
irt5havirw ; lastU = & _rtDW -> gljjadsfzv ; } } _rtB -> irv2xtzte1 = ( _rtB
-> eqtatbfsoc - * lastU ) / ( ssGetT ( S ) - byehzqrbel ) ; } _rtB ->
hmz2gdoyj0 = muDoubleScalarAbs ( _rtB -> iyq5z5g4dk ) ; _rtB -> gf0exbgqfy =
1.093 * _rtB -> hmz2gdoyj0 ; _rtB -> f13wljmkdg = 1.0464 * _rtB -> eqtatbfsoc
; { uint32_T iLeftU0 , iRghtU0 , iLeftU1 , iRghtU1 ;
HEV_acc_BINARYSEARCH_real_T ( & ( iLeftU0 ) , & ( iRghtU0 ) , _rtB ->
gf0exbgqfy , ni220kbneq . bvhb4ijxid , 108U ) ; if ( _rtB -> f13wljmkdg <=
0.0 ) { iLeftU1 = 0U ; iRghtU1 = 0U ; } else if ( _rtB -> f13wljmkdg >=
6000.0 ) { iLeftU1 = 100U ; iRghtU1 = 100U ; } else { iLeftU1 = ( uint32_T )
( ( _rtB -> f13wljmkdg ) / 60.0 ) ; iRghtU1 = iLeftU1 + 1 ; } { real_T yTemp
; real_T u1Lambda ; real_T u0Lambda ; if ( iLeftU1 != iRghtU1 ) { { real_T
num = ( real_T ) ( _rtB -> f13wljmkdg ) - ( iLeftU1 * 60.0 ) ; u1Lambda = num
/ 60.0 ; } } else { u1Lambda = 0.0 ; } if ( ( ni220kbneq . bvhb4ijxid [
iRghtU0 ] ) > ( ni220kbneq . bvhb4ijxid [ iLeftU0 ] ) ) { real_T num ; real_T
den ; den = ( ni220kbneq . bvhb4ijxid [ iRghtU0 ] ) ; den -= ( ni220kbneq .
bvhb4ijxid [ iLeftU0 ] ) ; num = _rtB -> gf0exbgqfy ; num -= ( ni220kbneq .
bvhb4ijxid [ iLeftU0 ] ) ; u0Lambda = num / den ; } else { u0Lambda = 0.0 ; }
{ real_T yLeftCast ; real_T yRghtCast ; yLeftCast = ( ni220kbneq . aeijn3z5nk
[ ( iLeftU0 + 109U * iLeftU1 ) ] ) ; yRghtCast = ( ni220kbneq . aeijn3z5nk [
( iLeftU0 + 109U * iRghtU1 ) ] ) ; yLeftCast += u1Lambda * ( yRghtCast -
yLeftCast ) ; g4ujj0rjwg = yLeftCast ; } { real_T yLeftCast ; real_T
yRghtCast ; yLeftCast = ( ni220kbneq . aeijn3z5nk [ ( iRghtU0 + 109U *
iLeftU1 ) ] ) ; yRghtCast = ( ni220kbneq . aeijn3z5nk [ ( iRghtU0 + 109U *
iRghtU1 ) ] ) ; yLeftCast += u1Lambda * ( yRghtCast - yLeftCast ) ; yTemp =
yLeftCast ; } { real_T yLeftCast ; real_T yRghtCast ; yLeftCast = g4ujj0rjwg
; yRghtCast = yTemp ; yLeftCast += u0Lambda * ( yRghtCast - yLeftCast ) ;
g4ujj0rjwg = yLeftCast ; } } } _rtB -> dw1mgwn4gn = 1.0351048413332149 *
g4ujj0rjwg ; _rtB -> e0ybe5x0cz = 1.933764640184292E-6 * _rtB -> dw1mgwn4gn ;
_rtB -> dkh20ye5nw = muDoubleScalarSign ( _rtB -> iyq5z5g4dk ) ; _rtB ->
a0jdaxqapy = muDoubleScalarAbs ( _rtB -> iyq5z5g4dk ) ; _rtB -> aktvrkragv =
1.093 * _rtB -> a0jdaxqapy ; _rtB -> mlrauxxqq2 = 1.0464 * _rtB -> eqtatbfsoc
; { uint32_T iLeftU0 , iRghtU0 , iLeftU1 , iRghtU1 ;
HEV_acc_BINARYSEARCH_real_T ( & ( iLeftU0 ) , & ( iRghtU0 ) , _rtB ->
aktvrkragv , ni220kbneq . bvhb4ijxid , 108U ) ; if ( _rtB -> mlrauxxqq2 <=
0.0 ) { iLeftU1 = 0U ; iRghtU1 = 0U ; } else if ( _rtB -> mlrauxxqq2 >=
6000.0 ) { iLeftU1 = 100U ; iRghtU1 = 100U ; } else { iLeftU1 = ( uint32_T )
( ( _rtB -> mlrauxxqq2 ) / 60.0 ) ; iRghtU1 = iLeftU1 + 1 ; } { real_T yTemp
; real_T u1Lambda ; real_T u0Lambda ; if ( iLeftU1 != iRghtU1 ) { { real_T
num = ( real_T ) ( _rtB -> mlrauxxqq2 ) - ( iLeftU1 * 60.0 ) ; u1Lambda = num
/ 60.0 ; } } else { u1Lambda = 0.0 ; } if ( ( ni220kbneq . bvhb4ijxid [
iRghtU0 ] ) > ( ni220kbneq . bvhb4ijxid [ iLeftU0 ] ) ) { real_T num ; real_T
den ; den = ( ni220kbneq . bvhb4ijxid [ iRghtU0 ] ) ; den -= ( ni220kbneq .
bvhb4ijxid [ iLeftU0 ] ) ; num = _rtB -> aktvrkragv ; num -= ( ni220kbneq .
bvhb4ijxid [ iLeftU0 ] ) ; u0Lambda = num / den ; } else { u0Lambda = 0.0 ; }
{ real_T yLeftCast ; real_T yRghtCast ; yLeftCast = ( ni220kbneq . osuhnhw40g
[ ( iLeftU0 + 109U * iLeftU1 ) ] ) ; yRghtCast = ( ni220kbneq . osuhnhw40g [
( iLeftU0 + 109U * iRghtU1 ) ] ) ; yLeftCast += u1Lambda * ( yRghtCast -
yLeftCast ) ; is3sm2p0on = yLeftCast ; } { real_T yLeftCast ; real_T
yRghtCast ; yLeftCast = ( ni220kbneq . osuhnhw40g [ ( iRghtU0 + 109U *
iLeftU1 ) ] ) ; yRghtCast = ( ni220kbneq . osuhnhw40g [ ( iRghtU0 + 109U *
iRghtU1 ) ] ) ; yLeftCast += u1Lambda * ( yRghtCast - yLeftCast ) ; yTemp =
yLeftCast ; } { real_T yLeftCast ; real_T yRghtCast ; yLeftCast = is3sm2p0on
; yRghtCast = yTemp ; yLeftCast += u0Lambda * ( yRghtCast - yLeftCast ) ;
is3sm2p0on = yLeftCast ; } } } _rtB -> gvmv4fxdrf = 1.0351048413332149 *
is3sm2p0on ; _rtB -> k04xe5o0l1 = _rtB -> dkh20ye5nw * _rtB -> gvmv4fxdrf ;
_rtB -> g0e14wdp4c = _rtB -> k04xe5o0l1 * _rtB -> irv2xtzte1 ; _rtB ->
ph2bh23ckg = 1.933764640184292E-6 * _rtB -> g0e14wdp4c ; _rtB -> b1wtd3cmen =
_rtB -> bmmyrr0up3 * _rtB -> iyq5z5g4dk ; if ( _rtB -> e0ybe5x0cz <= 0.02 ) {
_rtB -> bgr5t1bqgt = 0.02 ; } else { _rtB -> bgr5t1bqgt = _rtB -> e0ybe5x0cz
; } _rtB -> irxdwtyet1 = ( ( 0.0 - _rtB -> ph2bh23ckg ) - _rtB -> pv0hkzonpw
) - _rtB -> b1wtd3cmen ; _rtB -> gzgl2sptex = 1.0 / _rtB -> bgr5t1bqgt * _rtB
-> irxdwtyet1 ; ssCallAccelRunBlock ( S , 16 , 971 , SS_CALL_MDL_OUTPUTS ) ;
_rtB -> mcetl23ukz = _rtB -> m2y1khvsri [ 9 ] * _rtB -> htjriwobeu [ 2 ] ;
_rtB -> kf3t5b41va = _rtB -> htjriwobeu [ 3 ] * _rtB -> m2y1khvsri [ 6 ] ;
_rtB -> bxp415etnk = _rtB -> m2y1khvsri [ 8 ] * _rtB -> htjriwobeu [ 11 ] ;
_rtB -> lutyrcb0gb = _rtB -> kf3t5b41va + _rtB -> bxp415etnk ;
ssCallAccelRunBlock ( S , 16 , 1019 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 16 , 1020 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 16 , 1021 , SS_CALL_MDL_OUTPUTS ) ;
UNUSED_PARAMETER ( tid ) ; }
#define MDL_UPDATE
static void mdlUpdate ( SimStruct * S , int_T tid ) { real_T * lastU ;
fdj1laa40s * _rtB ; h04hj5x5sk * _rtDW ; _rtDW = ( ( h04hj5x5sk * )
ssGetRootDWork ( S ) ) ; _rtB = ( ( fdj1laa40s * ) _ssGetBlockIO ( S ) ) ; if
( ssIsSampleHit ( S , 2 , 0 ) ) { _rtDW -> epw20ibixm += 6.0E-5 * _rtB ->
ebdm2xapr0 ; _rtDW -> emjtqjwqij += 6.0E-5 * _rtB -> cj4r3orqto ; _rtDW ->
aekc0mbj0y += 6.0E-5 * _rtB -> azrh5zhoj1 ; _rtDW -> oi2n4lur1q += 6.0E-5 *
_rtB -> h4hdvz1ojz ; _rtDW -> jnhtlxaxxk = _rtB -> lz5cv3wcwq ; } if (
ssIsSampleHit ( S , 2 , 0 ) ) { _rtDW -> eaosag5owj += 6.0E-5 * _rtB ->
m2y1khvsri [ 7 ] ; _rtDW -> jcugjk0yp0 += 6.0E-5 * _rtB -> d4jqz2ve5w ; _rtDW
-> jly33pdwub += 6.0E-5 * _rtB -> l5bk4ytw0f ; _rtDW -> f2z5i2ds5e = _rtB ->
jqbq23fhxi [ 33 ] - - 0.999994000018 * _rtDW -> f2z5i2ds5e ; } if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtDW -> b50c0wk1dc = _rtB -> nbmku2aq4p ; }
if ( ssIsSampleHit ( S , 2 , 0 ) ) { _rtDW -> o05rwe50bo = 0U ; _rtDW ->
pk42w2cjcz += 6.0E-5 * _rtB -> jqbq23fhxi [ 33 ] ; if ( _rtDW -> pk42w2cjcz
>= 25200.0 ) { _rtDW -> pk42w2cjcz = 25200.0 ; } else { if ( _rtDW ->
pk42w2cjcz <= rtMinusInf ) { _rtDW -> pk42w2cjcz = rtMinusInf ; } } if ( _rtB
-> inzo0k02k1 > 0.0 ) { _rtDW -> f0fxu4veqt = 1 ; } else if ( _rtB ->
inzo0k02k1 < 0.0 ) { _rtDW -> f0fxu4veqt = - 1 ; } else if ( _rtB ->
inzo0k02k1 == 0.0 ) { _rtDW -> f0fxu4veqt = 0 ; } else { _rtDW -> f0fxu4veqt
= 2 ; } _rtDW -> fezg0yhyh2 = _rtB -> jqbq23fhxi [ 19 ] ; _rtDW -> hdqerfit1p
[ 0 ] = _rtB -> jqbq23fhxi [ 35 ] ; _rtDW -> hdqerfit1p [ 1 ] = _rtB ->
jqbq23fhxi [ 36 ] ; _rtDW -> hdqerfit1p [ 2 ] = _rtB -> jqbq23fhxi [ 37 ] ; }
if ( _rtDW -> mg242c3vwq == ( rtInf ) ) { _rtDW -> mg242c3vwq = ssGetTaskTime
( S , 0 ) ; _rtDW -> oiqwpboxgd = _rtB -> opx3gyttsw ; } else if ( _rtDW ->
k1wt3kvmem == ( rtInf ) ) { _rtDW -> k1wt3kvmem = ssGetTaskTime ( S , 0 ) ;
_rtDW -> lzjsh0qxsz = _rtB -> opx3gyttsw ; } else if ( _rtDW -> mg242c3vwq <
_rtDW -> k1wt3kvmem ) { _rtDW -> mg242c3vwq = ssGetTaskTime ( S , 0 ) ; _rtDW
-> oiqwpboxgd = _rtB -> opx3gyttsw ; } else { _rtDW -> k1wt3kvmem =
ssGetTaskTime ( S , 0 ) ; _rtDW -> lzjsh0qxsz = _rtB -> opx3gyttsw ; } if (
_rtDW -> cwivfg5ijd == ( rtInf ) ) { _rtDW -> cwivfg5ijd = ssGetTaskTime ( S
, 0 ) ; _rtDW -> kguctqvwvn = _rtB -> jn4gk5uedm ; } else if ( _rtDW ->
m1iuzueluk == ( rtInf ) ) { _rtDW -> m1iuzueluk = ssGetTaskTime ( S , 0 ) ;
_rtDW -> bvl1znuobh = _rtB -> jn4gk5uedm ; } else if ( _rtDW -> cwivfg5ijd <
_rtDW -> m1iuzueluk ) { _rtDW -> cwivfg5ijd = ssGetTaskTime ( S , 0 ) ; _rtDW
-> kguctqvwvn = _rtB -> jn4gk5uedm ; } else { _rtDW -> m1iuzueluk =
ssGetTaskTime ( S , 0 ) ; _rtDW -> bvl1znuobh = _rtB -> jn4gk5uedm ; } if (
ssIsSampleHit ( S , 2 , 0 ) ) { _rtDW -> bvad1zjfik = _rtB -> cwawvyhhog [ 0
] ; } if ( _rtDW -> hfvh40s0je == ( rtInf ) ) { _rtDW -> hfvh40s0je =
ssGetTaskTime ( S , 0 ) ; _rtDW -> lidlmlim32 = _rtB -> hijbmmvub5 ; } else
if ( _rtDW -> f41a3yqptq == ( rtInf ) ) { _rtDW -> f41a3yqptq = ssGetTaskTime
( S , 0 ) ; _rtDW -> aq3qjo4ji4 = _rtB -> hijbmmvub5 ; } else if ( _rtDW ->
hfvh40s0je < _rtDW -> f41a3yqptq ) { _rtDW -> hfvh40s0je = ssGetTaskTime ( S
, 0 ) ; _rtDW -> lidlmlim32 = _rtB -> hijbmmvub5 ; } else { _rtDW ->
f41a3yqptq = ssGetTaskTime ( S , 0 ) ; _rtDW -> aq3qjo4ji4 = _rtB ->
hijbmmvub5 ; } if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtDW -> aln04uuynj =
_rtB -> hijbmmvub5 ; _rtDW -> nlh5qppt4m = _rtB -> cj0c4eiztx ; } if (
ssIsSampleHit ( S , 2 , 0 ) ) { _rtDW -> bro0cn1wmi = _rtB -> jqbq23fhxi [ 23
] ; _rtDW -> j31s1kcymk [ 0 ] = _rtB -> jqbq23fhxi [ 38 ] ; _rtDW ->
j31s1kcymk [ 1 ] = _rtB -> jqbq23fhxi [ 39 ] ; _rtDW -> j31s1kcymk [ 2 ] =
_rtB -> jqbq23fhxi [ 40 ] ; } if ( ssIsSampleHit ( S , 3 , 0 ) ) { _rtDW ->
gsr0ogd2xb = _rtB -> oomejsu5n4 ; } if ( _rtDW -> joiszbfghn == ( rtInf ) ) {
_rtDW -> joiszbfghn = ssGetTaskTime ( S , 0 ) ; _rtDW -> narm2z4h4g = _rtB ->
dil4xbueyo ; } else if ( _rtDW -> jlnwqqs23l == ( rtInf ) ) { _rtDW ->
jlnwqqs23l = ssGetTaskTime ( S , 0 ) ; _rtDW -> miwjijsda1 = _rtB ->
dil4xbueyo ; } else if ( _rtDW -> joiszbfghn < _rtDW -> jlnwqqs23l ) { _rtDW
-> joiszbfghn = ssGetTaskTime ( S , 0 ) ; _rtDW -> narm2z4h4g = _rtB ->
dil4xbueyo ; } else { _rtDW -> jlnwqqs23l = ssGetTaskTime ( S , 0 ) ; _rtDW
-> miwjijsda1 = _rtB -> dil4xbueyo ; } if ( ssIsSampleHit ( S , 2 , 0 ) ) {
_rtDW -> kzrq2xyp0f = _rtB -> dcr5pclngn ; _rtDW -> nonllthbl2 = _rtB ->
f0nqistfq2 - - 0.94176453358424872 * _rtDW -> nonllthbl2 ; _rtDW ->
kol45dq53x = _rtB -> indjzxedww - - 0.94176453358424872 * _rtDW -> kol45dq53x
; _rtDW -> fw2k5vojpd = _rtB -> avcb2vosfu ; _rtDW -> ehaijafsot = _rtB ->
jqbq23fhxi [ 19 ] ; _rtDW -> lvw3lta2fy = _rtB -> lyzuxjnzrt - -
0.94176453358424872 * _rtDW -> lvw3lta2fy ; _rtDW -> c20b4oc1jp = _rtB ->
dzrmwbehc5 - - 0.94176453358424872 * _rtDW -> c20b4oc1jp ; _rtDW ->
lp13v2ihui = _rtB -> etirgqau3o ; _rtDW -> kopxzfb0sb = _rtB -> jqbq23fhxi [
23 ] ; _rtDW -> ebwur5qeqq = _rtB -> lebkafl2xg ; ssCallAccelRunBlock ( S ,
16 , 492 , SS_CALL_MDL_UPDATE ) ; } if ( _rtDW -> n33aen2wbt == ( rtInf ) ) {
_rtDW -> n33aen2wbt = ssGetTaskTime ( S , 0 ) ; _rtDW -> evmu5j4txb = _rtB ->
lsycnpudut ; } else if ( _rtDW -> fjojh4ewqs == ( rtInf ) ) { _rtDW ->
fjojh4ewqs = ssGetTaskTime ( S , 0 ) ; _rtDW -> d21ysphefx = _rtB ->
lsycnpudut ; } else if ( _rtDW -> n33aen2wbt < _rtDW -> fjojh4ewqs ) { _rtDW
-> n33aen2wbt = ssGetTaskTime ( S , 0 ) ; _rtDW -> evmu5j4txb = _rtB ->
lsycnpudut ; } else { _rtDW -> fjojh4ewqs = ssGetTaskTime ( S , 0 ) ; _rtDW
-> d21ysphefx = _rtB -> lsycnpudut ; } if ( _rtDW -> nolj4flzwb == ( rtInf )
) { _rtDW -> nolj4flzwb = ssGetTaskTime ( S , 0 ) ; _rtDW -> ppmw3hzciy =
_rtB -> h4hofwicsz ; } else if ( _rtDW -> bluedlz4ee == ( rtInf ) ) { _rtDW
-> bluedlz4ee = ssGetTaskTime ( S , 0 ) ; _rtDW -> awi4nxie0m = _rtB ->
h4hofwicsz ; } else if ( _rtDW -> nolj4flzwb < _rtDW -> bluedlz4ee ) { _rtDW
-> nolj4flzwb = ssGetTaskTime ( S , 0 ) ; _rtDW -> ppmw3hzciy = _rtB ->
h4hofwicsz ; } else { _rtDW -> bluedlz4ee = ssGetTaskTime ( S , 0 ) ; _rtDW
-> awi4nxie0m = _rtB -> h4hofwicsz ; } if ( ssIsSampleHit ( S , 3 , 0 ) ) {
_rtDW -> bv5gvrfela = _rtB -> pj1s4bwo5p ; } if ( ssIsSampleHit ( S , 2 , 0 )
) { _rtDW -> pe31gvq3pv = _rtB -> hkhe1qfrqk - - 0.98651999976973315 * _rtDW
-> pe31gvq3pv ; _rtDW -> bw5cwo255x = _rtB -> lew1su5u2u - -
0.98651999976973315 * _rtDW -> bw5cwo255x ; _rtDW -> l2t4rgxmml = _rtB ->
eodsxjmoej [ 0 ] ; } if ( ssIsSampleHit ( S , 2 , 0 ) ) { _rtDW -> dy4ppyw4mo
= _rtB -> hfvjerekxn - - 0.98651999976973315 * _rtDW -> dy4ppyw4mo ; _rtDW ->
hmybg5b1mi = _rtB -> gz2goujg2r - - 0.98651999976973315 * _rtDW -> hmybg5b1mi
; _rtDW -> gkq12xkctn = _rtB -> e0swysjneh [ 0 ] ; _rtDW -> llu3sg1ihp = 0U ;
_rtDW -> fj2gixcnhk = 3.0E-5 * _rtB -> irchshx0ry + _rtB -> krg1d2xh0a ; if (
_rtDW -> fj2gixcnhk >= 1.0 ) { _rtDW -> fj2gixcnhk = 1.0 ; } else { if (
_rtDW -> fj2gixcnhk <= - 1.0 ) { _rtDW -> fj2gixcnhk = - 1.0 ; } } _rtDW ->
dco4afubi3 = _rtB -> bnjekjvigq ; } if ( _rtDW -> ewhcynzuun == ( rtInf ) ) {
_rtDW -> ewhcynzuun = ssGetTaskTime ( S , 0 ) ; _rtDW -> h4ipbzntlo = _rtB ->
onkav0tkia ; } else if ( _rtDW -> ciu3b0lpet == ( rtInf ) ) { _rtDW ->
ciu3b0lpet = ssGetTaskTime ( S , 0 ) ; _rtDW -> mmlyeyihwy = _rtB ->
onkav0tkia ; } else if ( _rtDW -> ewhcynzuun < _rtDW -> ciu3b0lpet ) { _rtDW
-> ewhcynzuun = ssGetTaskTime ( S , 0 ) ; _rtDW -> h4ipbzntlo = _rtB ->
onkav0tkia ; } else { _rtDW -> ciu3b0lpet = ssGetTaskTime ( S , 0 ) ; _rtDW
-> mmlyeyihwy = _rtB -> onkav0tkia ; } if ( ssIsSampleHit ( S , 2 , 0 ) ) {
_rtDW -> jctbfc4f1e = _rtB -> ea0hte4exs - - 0.96300265339697488 * _rtDW ->
jctbfc4f1e ; _rtDW -> h4pa1qmmy5 = 0U ; _rtDW -> olv3cnxtoy = 3.0E-5 * _rtB
-> kdqwoukw3f + _rtB -> lteqbz0ryo ; if ( _rtDW -> olv3cnxtoy >= 1.0 ) {
_rtDW -> olv3cnxtoy = 1.0 ; } else { if ( _rtDW -> olv3cnxtoy <= 0.0 ) {
_rtDW -> olv3cnxtoy = 0.0 ; } } } if ( _rtDW -> en15lu4hm1 == ( rtInf ) ) {
_rtDW -> en15lu4hm1 = ssGetT ( S ) ; lastU = & _rtDW -> aa3vndu55f ; } else
if ( _rtDW -> km4yirabra == ( rtInf ) ) { _rtDW -> km4yirabra = ssGetT ( S )
; lastU = & _rtDW -> ke4dqjfdz3 ; } else if ( _rtDW -> en15lu4hm1 < _rtDW ->
km4yirabra ) { _rtDW -> en15lu4hm1 = ssGetT ( S ) ; lastU = & _rtDW ->
aa3vndu55f ; } else { _rtDW -> km4yirabra = ssGetT ( S ) ; lastU = & _rtDW ->
ke4dqjfdz3 ; } * lastU = _rtB -> g123hlbqqb ; if ( _rtDW -> cgi523usaj == (
rtInf ) ) { _rtDW -> cgi523usaj = ssGetT ( S ) ; lastU = & _rtDW ->
edrzze2flm ; } else if ( _rtDW -> irt5havirw == ( rtInf ) ) { _rtDW ->
irt5havirw = ssGetT ( S ) ; lastU = & _rtDW -> gljjadsfzv ; } else if ( _rtDW
-> cgi523usaj < _rtDW -> irt5havirw ) { _rtDW -> cgi523usaj = ssGetT ( S ) ;
lastU = & _rtDW -> edrzze2flm ; } else { _rtDW -> irt5havirw = ssGetT ( S ) ;
lastU = & _rtDW -> gljjadsfzv ; } * lastU = _rtB -> eqtatbfsoc ;
UNUSED_PARAMETER ( tid ) ; }
#define MDL_DERIVATIVES
static void mdlDerivatives ( SimStruct * S ) { fdj1laa40s * _rtB ; hgl3elxkcb
* _rtX ; aab5tqo4s5 * _rtXdot ; h04hj5x5sk * _rtDW ; _rtDW = ( ( h04hj5x5sk *
) ssGetRootDWork ( S ) ) ; _rtXdot = ( ( aab5tqo4s5 * ) ssGetdX ( S ) ) ;
_rtX = ( ( hgl3elxkcb * ) ssGetContStates ( S ) ) ; _rtB = ( ( fdj1laa40s * )
_ssGetBlockIO ( S ) ) ; _rtXdot -> mh2wvbi24o = _rtB -> b2zz22c1x4 ;
ssCallAccelRunBlock ( S , 16 , 30 , SS_CALL_MDL_DERIVATIVES ) ; _rtXdot ->
nlkba1lokv = _rtB -> jvnivwhexw ; _rtXdot -> eackaa2e5o = _rtB -> gzgl2sptex
; _rtXdot -> a3p154yttn = _rtB -> dbfqfu1h3z ; _rtXdot -> lvhb24m1u3 [ 0 ] =
0.0 ; _rtXdot -> lvhb24m1u3 [ 1 ] = 0.0 ; _rtXdot -> lvhb24m1u3 [ 0 ] += -
20.106192982974676 * _rtX -> lvhb24m1u3 [ 0 ] ; _rtXdot -> lvhb24m1u3 [ 0 ]
+= - 157.91367041742973 * _rtX -> lvhb24m1u3 [ 1 ] ; _rtXdot -> lvhb24m1u3 [
1 ] += _rtX -> lvhb24m1u3 [ 0 ] ; _rtXdot -> lvhb24m1u3 [ 0 ] += _rtB ->
iocsb2frxj ; _rtXdot -> oiuvfykmtf = _rtB -> kasim24bnz ; _rtXdot ->
pi4mr5hhgl = _rtB -> gq3amsk45r ; _rtXdot -> bjc4xqhn0t = _rtB -> jumk2kvvg3
; _rtXdot -> oy1vxpvao1 = _rtB -> pv0g2dpf4q ; _rtXdot -> iglmayn3zq = _rtB
-> c5lofc00ur ; _rtXdot -> p24x5vnk3x = _rtB -> lmb25sruhs ; _rtXdot ->
jntxheunx4 = _rtB -> bxmms3bqxa ; _rtXdot -> ix50zu3rlz = 0.0 ; _rtXdot ->
ix50zu3rlz += - 125.66370614359172 * _rtX -> ix50zu3rlz ; _rtXdot ->
ix50zu3rlz += _rtB -> pv0g2dpf4q ; { boolean_T lsat ; boolean_T usat ; lsat =
( ( ( hgl3elxkcb * ) ssGetContStates ( S ) ) -> f0udlm3lxk <= ( - 5.0 ) ) ;
usat = ( ( ( hgl3elxkcb * ) ssGetContStates ( S ) ) -> f0udlm3lxk >= 5.0 ) ;
if ( ( ! lsat && ! usat ) || ( lsat && ( _rtB -> khvkfx53q0 > 0 ) ) || ( usat
&& ( _rtB -> khvkfx53q0 < 0 ) ) ) { ( ( aab5tqo4s5 * ) ssGetdX ( S ) ) ->
f0udlm3lxk = _rtB -> khvkfx53q0 ; } else { ( ( aab5tqo4s5 * ) ssGetdX ( S ) )
-> f0udlm3lxk = 0.0 ; } } }
#define MDL_PROJECTION
static void mdlProjection ( SimStruct * S ) { fdj1laa40s * _rtB ; h04hj5x5sk
* _rtDW ; _rtDW = ( ( h04hj5x5sk * ) ssGetRootDWork ( S ) ) ; _rtB = ( (
fdj1laa40s * ) _ssGetBlockIO ( S ) ) ; ssCallAccelRunBlock ( S , 16 , 30 ,
SS_CALL_MDL_PROJECTION ) ; } static void mdlInitializeSizes ( SimStruct * S )
{ ssSetChecksumVal ( S , 0 , 546598756U ) ; ssSetChecksumVal ( S , 1 ,
2851626782U ) ; ssSetChecksumVal ( S , 2 , 638921059U ) ; ssSetChecksumVal (
S , 3 , 2348820173U ) ; { mxArray * slVerStructMat = NULL ; mxArray *
slStrMat = mxCreateString ( "simulink" ) ; char slVerChar [ 10 ] ; int status
= mexCallMATLAB ( 1 , & slVerStructMat , 1 , & slStrMat , "ver" ) ; if (
status == 0 ) { mxArray * slVerMat = mxGetField ( slVerStructMat , 0 ,
"Version" ) ; if ( slVerMat == NULL ) { status = 1 ; } else { status =
mxGetString ( slVerMat , slVerChar , 10 ) ; } } mxDestroyArray ( slStrMat ) ;
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
rt_InitInfAndNaN ( sizeof ( real_T ) ) ; cleaxjsuvr . hwzhoadajw = rtNaN ;
cleaxjsuvr . al3rzxug3z = rtInf ; cleaxjsuvr . bmggooyndx = rtMinusInf ;
ld5zvvrfqt ( S ) -> kfppdkqbu1 = rtNaN ; ld5zvvrfqt ( S ) -> ayw1ok1jnp =
rtNaN ; ld5zvvrfqt ( S ) -> pziqszrs1g = rtNaN ; ld5zvvrfqt ( S ) ->
kdo0hok5es = rtNaN ; } static void mdlInitializeSampleTimes ( SimStruct * S )
{ { SimStruct * childS ; SysOutputFcn * callSysFcns ; childS = ssGetSFunction
( S , 0 ) ; callSysFcns = ssGetCallSystemOutputFcnList ( childS ) ;
callSysFcns [ 3 + 0 ] = ( SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction (
S , 1 ) ; callSysFcns = ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns
[ 3 + 0 ] = ( SysOutputFcn ) ( NULL ) ; } } static void mdlTerminate (
SimStruct * S ) { }
#include "simulink.c"
