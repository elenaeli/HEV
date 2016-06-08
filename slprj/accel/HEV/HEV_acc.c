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
nzpvluxqo1 ; real_T fxzudfooqr ; real_T bqmdh4lvh2 ; real_T boxfyroykz ;
real_T gfnebsmhwv ; real_T ludevrgvrx ; real_T htsyt1c0no ; real_T hmll0wvmpw
; real_T puuqlcshxw ; boolean_T pz4rdgpjxp ; int32_T rowIdx ; real_T * lastU
; boolean_T o3khhk3fbg ; uint8_T h100jbae3x ; real_T iiis24gb3o ; real_T
jwhz1ujp3w ; real_T ehtkh2wauy ; real_T mkcfwi2fsi ; real_T ehcygfucdl ;
real_T po0ockmy2b ; real_T mizlp41tvx ; real_T f4ufgq33gz ; real_T i5nu34w4uj
; real_T dztyrqu4xa ; real_T eskeehll14 ; real_T ckrl0nmlwt ; real_T
lduwq00gqj ; real_T byehzqrbel ; boolean_T fviymzl3aa ; real_T j0jhyqa1p3 ;
real_T aqlslovppe ; real_T dyfxp2slod ; real_T dk4tk42hhp ; real_T ctpq3axefx
; real_T f1b5simhxh ; real_T lstej3qx0u ; real_T h0cg4jnrg5 ; real_T
lfv3m5pb5c ; real_T f2e3v5ccex ; real_T lebvfutt11 ; real_T ogs5kt2fyi_idx_0
; real_T ogs5kt2fyi_idx_1 ; real_T ogs5kt2fyi_idx_2 ; ZCEventType
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
iLeftU0 ) , & ( iRghtU0 ) , _rtB -> g013xtkmbh , ni220kbneq . c4qvyaa1p5 ,
108U ) ; if ( _rtB -> p3144ypepf <= 0.0 ) { iLeftU1 = 0U ; iRghtU1 = 0U ; }
else if ( _rtB -> p3144ypepf >= 6000.0 ) { iLeftU1 = 100U ; iRghtU1 = 100U ;
} else { iLeftU1 = ( uint32_T ) ( ( _rtB -> p3144ypepf ) / 60.0 ) ; iRghtU1 =
iLeftU1 + 1 ; } { real_T yTemp ; real_T u1Lambda ; real_T u0Lambda ; if (
iLeftU1 != iRghtU1 ) { { real_T num = ( real_T ) ( _rtB -> p3144ypepf ) - (
iLeftU1 * 60.0 ) ; u1Lambda = num / 60.0 ; } } else { u1Lambda = 0.0 ; } if (
( ni220kbneq . c4qvyaa1p5 [ iRghtU0 ] ) > ( ni220kbneq . c4qvyaa1p5 [ iLeftU0
] ) ) { real_T num ; real_T den ; den = ( ni220kbneq . c4qvyaa1p5 [ iRghtU0 ]
) ; den -= ( ni220kbneq . c4qvyaa1p5 [ iLeftU0 ] ) ; num = _rtB -> g013xtkmbh
; num -= ( ni220kbneq . c4qvyaa1p5 [ iLeftU0 ] ) ; u0Lambda = num / den ; }
else { u0Lambda = 0.0 ; } { real_T yLeftCast ; real_T yRghtCast ; yLeftCast =
( ni220kbneq . mstlffh4xe [ ( iLeftU0 + 109U * iLeftU1 ) ] ) ; yRghtCast = (
ni220kbneq . mstlffh4xe [ ( iLeftU0 + 109U * iRghtU1 ) ] ) ; yLeftCast +=
u1Lambda * ( yRghtCast - yLeftCast ) ; fepbibcdbq = yLeftCast ; } { real_T
yLeftCast ; real_T yRghtCast ; yLeftCast = ( ni220kbneq . mstlffh4xe [ (
iRghtU0 + 109U * iLeftU1 ) ] ) ; yRghtCast = ( ni220kbneq . mstlffh4xe [ (
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
iLeftU0 ) , & ( iRghtU0 ) , _rtB -> jla0sqmgz1 , ni220kbneq . c4qvyaa1p5 ,
108U ) ; if ( _rtB -> gy3qknpzse <= 0.0 ) { iLeftU1 = 0U ; iRghtU1 = 0U ; }
else if ( _rtB -> gy3qknpzse >= 6000.0 ) { iLeftU1 = 100U ; iRghtU1 = 100U ;
} else { iLeftU1 = ( uint32_T ) ( ( _rtB -> gy3qknpzse ) / 60.0 ) ; iRghtU1 =
iLeftU1 + 1 ; } { real_T yTemp ; real_T u1Lambda ; real_T u0Lambda ; if (
iLeftU1 != iRghtU1 ) { { real_T num = ( real_T ) ( _rtB -> gy3qknpzse ) - (
iLeftU1 * 60.0 ) ; u1Lambda = num / 60.0 ; } } else { u1Lambda = 0.0 ; } if (
( ni220kbneq . c4qvyaa1p5 [ iRghtU0 ] ) > ( ni220kbneq . c4qvyaa1p5 [ iLeftU0
] ) ) { real_T num ; real_T den ; den = ( ni220kbneq . c4qvyaa1p5 [ iRghtU0 ]
) ; den -= ( ni220kbneq . c4qvyaa1p5 [ iLeftU0 ] ) ; num = _rtB -> jla0sqmgz1
; num -= ( ni220kbneq . c4qvyaa1p5 [ iLeftU0 ] ) ; u0Lambda = num / den ; }
else { u0Lambda = 0.0 ; } { real_T yLeftCast ; real_T yRghtCast ; yLeftCast =
( ni220kbneq . mstlffh4xe [ ( iLeftU0 + 109U * iLeftU1 ) ] ) ; yRghtCast = (
ni220kbneq . mstlffh4xe [ ( iLeftU0 + 109U * iRghtU1 ) ] ) ; yLeftCast +=
u1Lambda * ( yRghtCast - yLeftCast ) ; nzpvluxqo1 = yLeftCast ; } { real_T
yLeftCast ; real_T yRghtCast ; yLeftCast = ( ni220kbneq . mstlffh4xe [ (
iRghtU0 + 109U * iLeftU1 ) ] ) ; yRghtCast = ( ni220kbneq . mstlffh4xe [ (
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
l5ps3h45bs ; } _rtB -> bmpu5p2kzq = _rtB -> pvpxscgwqr ; } if ( _rtB ->
bmpu5p2kzq > 136.0757 ) { _rtB -> ocumwohfv1 = 136.0757 ; } else if ( _rtB ->
bmpu5p2kzq < 0.0 ) { _rtB -> ocumwohfv1 = 0.0 ; } else { _rtB -> ocumwohfv1 =
_rtB -> bmpu5p2kzq ; } _rtB -> gy5wzn2hz0 = - _rtB -> f42rmc3fdw ; _rtB ->
n0wmhn050p [ 0 ] = _rtB -> f42rmc3fdw ; _rtB -> n0wmhn050p [ 1 ] = _rtB ->
lt41u3p0z3 ; _rtB -> n0wmhn050p [ 2 ] = _rtB -> oac35s35vw ; _rtB ->
n0wmhn050p [ 3 ] = _rtB -> jv1hez3310 ; _rtB -> n0wmhn050p [ 4 ] = _rtB ->
hea4gjqawa ; _rtB -> n0wmhn050p [ 5 ] = _rtB -> cbttxcrlpy ; _rtB ->
n0wmhn050p [ 6 ] = _rtB -> c1dd1abfch ; _rtB -> n0wmhn050p [ 7 ] = _rtB ->
ocumwohfv1 ; _rtB -> n0wmhn050p [ 8 ] = _rtB -> gy5wzn2hz0 ;
ssCallAccelRunBlock ( S , 16 , 180 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 16 , 181 , SS_CALL_MDL_OUTPUTS ) ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { ssCallAccelRunBlock ( S , 16 , 182 ,
SS_CALL_MDL_OUTPUTS ) ; } ssCallAccelRunBlock ( S , 16 , 183 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> fig2vfwpyr = 9.5492965854826952 * _rtB ->
m2y1khvsri [ 11 ] ; _rtB -> knja43t4jr = _rtB -> m2y1khvsri [ 11 ] * _rtB ->
il4mgadolv [ 1 ] ; ssCallAccelRunBlock ( S , 16 , 186 , SS_CALL_MDL_OUTPUTS )
; _rtB -> mcopmn2tir = _rtX -> pi4mr5hhgl ; _rtB -> klwtb045nk = _rtX ->
bjc4xqhn0t ; hmll0wvmpw = 1.0 / _rtB -> mcopmn2tir * _rtB -> klwtb045nk *
100.0 ; if ( hmll0wvmpw > 15.0 ) { _rtB -> knja43t4jr = 15.0 ; } else if (
hmll0wvmpw < 0.0 ) { _rtB -> knja43t4jr = 0.0 ; } else { _rtB -> knja43t4jr =
hmll0wvmpw ; } HEV_acc_Look2D_real_T_real_T_real_T ( & ( _rtB -> lvjrio3qws )
, ( ( baqezl5ja5 * ) ssGetDefaultParam ( S ) ) -> FuelConsTable .
lookupTableFuel , _rtB -> fig2vfwpyr , ( ( baqezl5ja5 * ) ssGetDefaultParam (
S ) ) -> FuelConsTable . speed , 9U , _rtB -> il4mgadolv [ 1 ] , ( (
baqezl5ja5 * ) ssGetDefaultParam ( S ) ) -> FuelConsTable . torque , 9U ) ;
HEV_acc_Look2D_real_T_real_T_real_T ( & ( _rtB -> gwhokqj4dv ) , ( (
baqezl5ja5 * ) ssGetDefaultParam ( S ) ) -> GasEmisTable . lookupTableCO ,
_rtB -> fig2vfwpyr , ( ( baqezl5ja5 * ) ssGetDefaultParam ( S ) ) ->
GasEmisTable . speed , 9U , _rtB -> il4mgadolv [ 1 ] , ( ( baqezl5ja5 * )
ssGetDefaultParam ( S ) ) -> GasEmisTable . torque , 9U ) ;
HEV_acc_Look2D_real_T_real_T_real_T ( & ( _rtB -> lasykkrzbv ) , ( (
baqezl5ja5 * ) ssGetDefaultParam ( S ) ) -> GasEmisTable . lookupTableHC ,
_rtB -> fig2vfwpyr , ( ( baqezl5ja5 * ) ssGetDefaultParam ( S ) ) ->
GasEmisTable . speed , 9U , _rtB -> il4mgadolv [ 1 ] , ( ( baqezl5ja5 * )
ssGetDefaultParam ( S ) ) -> GasEmisTable . torque , 9U ) ;
HEV_acc_Look2D_real_T_real_T_real_T ( & ( _rtB -> fc1o4q5r0w ) , ( (
baqezl5ja5 * ) ssGetDefaultParam ( S ) ) -> GasEmisTable . lookupTableNOX ,
_rtB -> fig2vfwpyr , ( ( baqezl5ja5 * ) ssGetDefaultParam ( S ) ) ->
GasEmisTable . speed , 9U , _rtB -> il4mgadolv [ 1 ] , ( ( baqezl5ja5 * )
ssGetDefaultParam ( S ) ) -> GasEmisTable . torque , 9U ) ;
ssCallAccelRunBlock ( S , 16 , 196 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
i5nm0bzs1m = ! ( h100jbae3x != 0 ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) {
ssCallAccelRunBlock ( S , 16 , 198 , SS_CALL_MDL_OUTPUTS ) ; } _rtB ->
pkjpt5qvgm = _rtX -> oy1vxpvao1 ; hmll0wvmpw = ssGetT ( S ) ; _rtB ->
fez00ly5gv = _rtB -> pkjpt5qvgm / hmll0wvmpw ; ssCallAccelRunBlock ( S , 16 ,
207 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> otjtsoshxw = _rtX -> iglmayn3zq ; _rtB
-> boctzwx3r2 = hmll0wvmpw * ld5zvvrfqt ( S ) -> cip5x3puis ; _rtB ->
fez00ly5gv *= _rtB -> boctzwx3r2 ; hmll0wvmpw = _rtB -> otjtsoshxw / _rtB ->
fez00ly5gv ; if ( hmll0wvmpw <= 0.0 ) { _rtB -> npqw2hqsht = 0.0 ; } else {
_rtB -> npqw2hqsht = hmll0wvmpw ; } ssCallAccelRunBlock ( S , 16 , 214 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 16 , 215 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> eoaixrtvfq = _rtX -> p24x5vnk3x ; hmll0wvmpw
= _rtB -> eoaixrtvfq / _rtB -> fez00ly5gv ; if ( hmll0wvmpw <= 0.0 ) { _rtB
-> npqw2hqsht = 0.0 ; } else { _rtB -> npqw2hqsht = hmll0wvmpw ; }
ssCallAccelRunBlock ( S , 16 , 219 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
hugpqfftkj = _rtX -> jntxheunx4 ; hmll0wvmpw = _rtB -> hugpqfftkj / _rtB ->
fez00ly5gv ; if ( hmll0wvmpw <= 0.0 ) { _rtB -> npqw2hqsht = 0.0 ; } else {
_rtB -> npqw2hqsht = hmll0wvmpw ; } ssCallAccelRunBlock ( S , 16 , 223 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 16 , 224 ,
SS_CALL_MDL_OUTPUTS ) ; if ( _rtB -> klwtb045nk <= 0.0 ) { h0cg4jnrg5 = 0.0 ;
} else { h0cg4jnrg5 = _rtB -> klwtb045nk ; } _rtB -> mstphh4ee3 = h0cg4jnrg5
+ ld5zvvrfqt ( S ) -> pgalrzmagk ; ssCallAccelRunBlock ( S , 16 , 228 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 16 , 229 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> fsawlu5edv = 0.001 * _rtB -> lvjrio3qws ;
_rtB -> l2qh4rqqir = _rtB -> fsawlu5edv / ld5zvvrfqt ( S ) -> d1tspyxwbf ;
_rtB -> ce1id0pwp5 = 3.6 * _rtB -> chkwevbcym ; if ( _rtB -> ce1id0pwp5 >
200.0 ) { _rtB -> otp4c53e0a = 200.0 ; } else if ( _rtB -> ce1id0pwp5 < 0.0 )
{ _rtB -> otp4c53e0a = 0.0 ; } else { _rtB -> otp4c53e0a = _rtB -> ce1id0pwp5
; } _rtB -> ik1quccdcq = 0.0002777777777778 * _rtB -> otp4c53e0a ; _rtB ->
jiuie0tfic = 1000.0 * _rtB -> l2qh4rqqir ; ssCallAccelRunBlock ( S , 16 , 243
, SS_CALL_MDL_OUTPUTS ) ; _rtB -> benvjxhrdn = 0 ; ssCallAccelRunBlock ( S ,
16 , 264 , SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 16 , 265 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 16 , 266 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 16 , 267 ,
SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSampleHit ( S , 4 , 0 ) ) {
ssCallAccelRunBlock ( S , 16 , 268 , SS_CALL_MDL_OUTPUTS ) ; } _rtB ->
fzn0yhcu5j = 0.0 ; _rtB -> fzn0yhcu5j += 125.66370614359172 * _rtX ->
ix50zu3rlz ; ssCallAccelRunBlock ( S , 16 , 270 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 16 , 271 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
fkll1ai55g = _rtB -> npqw2hqsht - _rtB -> fzn0yhcu5j ; iiis24gb3o = 0.02 *
_rtB -> fkll1ai55g ; if ( ( ( hgl3elxkcb * ) ssGetContStates ( S ) ) ->
f0udlm3lxk >= 5.0 ) { if ( ( ( hgl3elxkcb * ) ssGetContStates ( S ) ) ->
f0udlm3lxk != 5.0 ) { ( ( hgl3elxkcb * ) ssGetContStates ( S ) ) ->
f0udlm3lxk = 5.0 ; ssSetSolverNeedsReset ( S ) ; } } else if ( ( ( hgl3elxkcb
* ) ssGetContStates ( S ) ) -> f0udlm3lxk <= ( - 5.0 ) ) { if ( ( (
hgl3elxkcb * ) ssGetContStates ( S ) ) -> f0udlm3lxk != ( - 5.0 ) ) { ( (
hgl3elxkcb * ) ssGetContStates ( S ) ) -> f0udlm3lxk = ( - 5.0 ) ;
ssSetSolverNeedsReset ( S ) ; } } _rtB -> ae5unni1dd = ( ( hgl3elxkcb * )
ssGetContStates ( S ) ) -> f0udlm3lxk ; hmll0wvmpw = iiis24gb3o + _rtB ->
ae5unni1dd ; if ( hmll0wvmpw > 1.0 ) { _rtB -> a3iikuicnm = 1.0 ; } else if (
hmll0wvmpw < - 1.0 ) { _rtB -> a3iikuicnm = - 1.0 ; } else { _rtB ->
a3iikuicnm = hmll0wvmpw ; } ssCallAccelRunBlock ( S , 16 , 277 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 16 , 278 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> nktcz1jlg1 = 0.04 * _rtB -> fkll1ai55g ; if (
ssIsSampleHit ( S , 2 , 0 ) ) { jwhz1ujp3w = _rtDW -> eaosag5owj ; ehtkh2wauy
= muDoubleScalarSin ( _rtDW -> eaosag5owj ) ; mkcfwi2fsi = muDoubleScalarCos
( _rtDW -> eaosag5owj ) ; _rtB -> oiarkgbwt2 = _rtB -> bw2nhi51td *
mkcfwi2fsi + _rtB -> gthgcz50sq * ehtkh2wauy ; _rtB -> d4q33he30r = ( ( -
_rtB -> bw2nhi51td - 1.7320508075688772 * _rtB -> gthgcz50sq ) * mkcfwi2fsi +
( 1.7320508075688772 * _rtB -> bw2nhi51td - _rtB -> gthgcz50sq ) * ehtkh2wauy
) * 0.5 ; ehcygfucdl = _rtDW -> jcugjk0yp0 ; po0ockmy2b = muDoubleScalarSin (
_rtDW -> jcugjk0yp0 ) ; mizlp41tvx = muDoubleScalarCos ( _rtDW -> jcugjk0yp0
) ; _rtB -> aaqqwmy3bf = _rtB -> deue3miwlt * mizlp41tvx + _rtB -> aorbsvsy2v
* po0ockmy2b ; _rtB -> no4yjpc1xv = ( ( - _rtB -> deue3miwlt -
1.7320508075688772 * _rtB -> aorbsvsy2v ) * mizlp41tvx + ( 1.7320508075688772
* _rtB -> deue3miwlt - _rtB -> aorbsvsy2v ) * po0ockmy2b ) * 0.5 ; f4ufgq33gz
= _rtDW -> jly33pdwub ; i5nu34w4uj = 5.9999820000156134E-6 * _rtDW ->
f2z5i2ds5e ; _rtB -> nzg45ejzyh = ( i5nu34w4uj > ld5zvvrfqt ( S ) ->
on3ih02zfn ) ; } if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> enixcp11c2 =
_rtDW -> b50c0wk1dc ; } if ( ssIsSampleHit ( S , 2 , 0 ) ) { if ( _rtDW ->
o05rwe50bo != 0 ) { _rtDW -> pk42w2cjcz = _rtB -> enixcp11c2 ; if ( _rtDW ->
pk42w2cjcz >= 25200.0 ) { _rtDW -> pk42w2cjcz = 25200.0 ; } else { if ( _rtDW
-> pk42w2cjcz <= rtMinusInf ) { _rtDW -> pk42w2cjcz = rtMinusInf ; } } } if (
( _rtB -> nzg45ejzyh > 0.0 ) && ( _rtDW -> f0fxu4veqt <= 0 ) ) { _rtDW ->
pk42w2cjcz = _rtB -> enixcp11c2 ; if ( _rtDW -> pk42w2cjcz >= 25200.0 ) {
_rtDW -> pk42w2cjcz = 25200.0 ; } else { if ( _rtDW -> pk42w2cjcz <=
rtMinusInf ) { _rtDW -> pk42w2cjcz = rtMinusInf ; } } } if ( _rtDW ->
pk42w2cjcz >= 25200.0 ) { _rtDW -> pk42w2cjcz = 25200.0 ; } else { if ( _rtDW
-> pk42w2cjcz <= rtMinusInf ) { _rtDW -> pk42w2cjcz = rtMinusInf ; } }
dztyrqu4xa = 0.00027777777777777778 * _rtDW -> pk42w2cjcz ; if ( dztyrqu4xa >
6.9993 ) { eskeehll14 = 6.9993 ; } else if ( dztyrqu4xa < 0.0 ) { eskeehll14
= 0.0 ; } else { eskeehll14 = dztyrqu4xa ; } if ( dztyrqu4xa >= 6.9993 ) {
dztyrqu4xa = 6.9993 ; } byehzqrbel = ( ( 7.0 / ( 7.0 - eskeehll14 ) * -
0.23801451555567835 * eskeehll14 + ( ld5zvvrfqt ( S ) -> dg5000srfh +
f4ufgq33gz ) ) + - _rtB -> nzg45ejzyh * 0.23801451555567835 * i5nu34w4uj * (
7.0 / ( 7.0 - eskeehll14 ) ) ) + - ( ( real_T ) ( i5nu34w4uj < ld5zvvrfqt ( S
) -> gsblhxj455 ) * ld5zvvrfqt ( S ) -> kykab1g0ft ) * 0.23801451555567835 *
( ld5zvvrfqt ( S ) -> kykab1g0ft * i5nu34w4uj ) * ( 7.0 / ( muDoubleScalarAbs
( ld5zvvrfqt ( S ) -> kykab1g0ft * dztyrqu4xa ) + 0.70000000000000007 ) ) ;
if ( byehzqrbel > ld5zvvrfqt ( S ) -> dfqbatzsjb ) { _rtB -> k1fwhzg1af =
ld5zvvrfqt ( S ) -> dfqbatzsjb ; } else { iiis24gb3o = 0.30769230769230771 *
i5nu34w4uj ; if ( byehzqrbel < iiis24gb3o ) { _rtB -> k1fwhzg1af = iiis24gb3o
; } else { _rtB -> k1fwhzg1af = byehzqrbel ; } } _rtB -> jxjfrhnnrc = _rtDW
-> fezg0yhyh2 ; ogs5kt2fyi_idx_0 = _rtDW -> hdqerfit1p [ 0 ] ;
ogs5kt2fyi_idx_1 = _rtDW -> hdqerfit1p [ 1 ] ; ogs5kt2fyi_idx_2 = _rtDW ->
hdqerfit1p [ 2 ] ; lduwq00gqj = muDoubleScalarCos ( jwhz1ujp3w ) ; ckrl0nmlwt
= muDoubleScalarSin ( jwhz1ujp3w ) ; } if ( _rtB -> m2y1khvsri [ 7 ] <= 1.0 )
{ hmll0wvmpw = 1.0 ; } else { hmll0wvmpw = _rtB -> m2y1khvsri [ 7 ] ; }
hmll0wvmpw = 1.0 / hmll0wvmpw ; hmll0wvmpw *= 30000.0 ; i5nu34w4uj =
muDoubleScalarAbs ( hmll0wvmpw ) ; if ( ssIsMajorTimeStep ( S ) ) { if ( _rtB
-> m2y1khvsri [ 7 ] >= 300.0 ) { _rtDW -> ch52ed4whv = true ; } else { if (
_rtB -> m2y1khvsri [ 7 ] <= 200.0 ) { _rtDW -> ch52ed4whv = false ; } } }
_rtB -> pa4skybrma = _rtDW -> ch52ed4whv ; if ( ( _rtDW -> mg242c3vwq >=
ssGetTaskTime ( S , 0 ) ) && ( _rtDW -> k1wt3kvmem >= ssGetTaskTime ( S , 0 )
) ) { _rtB -> ffl5hinbtg = _rtB -> pa4skybrma ; } else { if ( ( ( _rtDW ->
mg242c3vwq < _rtDW -> k1wt3kvmem ) && ( _rtDW -> k1wt3kvmem < ssGetTaskTime (
S , 0 ) ) ) || ( ( _rtDW -> mg242c3vwq >= _rtDW -> k1wt3kvmem ) && ( _rtDW ->
mg242c3vwq >= ssGetTaskTime ( S , 0 ) ) ) ) { iiis24gb3o = ssGetTaskTime ( S
, 0 ) - _rtDW -> k1wt3kvmem ; lebvfutt11 = _rtDW -> lzjsh0qxsz ; } else {
iiis24gb3o = ssGetTaskTime ( S , 0 ) - _rtDW -> mg242c3vwq ; lebvfutt11 =
_rtDW -> oiqwpboxgd ; } lstej3qx0u = iiis24gb3o * 10.0 ; f2e3v5ccex = _rtB ->
pa4skybrma - lebvfutt11 ; if ( f2e3v5ccex > lstej3qx0u ) { _rtB -> ffl5hinbtg
= lebvfutt11 + lstej3qx0u ; } else { iiis24gb3o *= - 10.0 ; if ( f2e3v5ccex <
iiis24gb3o ) { _rtB -> ffl5hinbtg = lebvfutt11 + iiis24gb3o ; } else { _rtB
-> ffl5hinbtg = _rtB -> pa4skybrma ; } } } if ( _rtB -> m2y1khvsri [ 5 ] >
628.31853071795865 ) { _rtB -> j1z103ne1b = 628.31853071795865 ; } else if (
_rtB -> m2y1khvsri [ 5 ] < 0.0 ) { _rtB -> j1z103ne1b = 0.0 ; } else { _rtB
-> j1z103ne1b = _rtB -> m2y1khvsri [ 5 ] ; } hmll0wvmpw = muDoubleScalarAbs (
_rtB -> j1z103ne1b ) ; HEV_acc_LookUp_real_T_real_T ( & ( fxzudfooqr ) ,
ni220kbneq . jmw3cjssuc , hmll0wvmpw , ni220kbneq . imwrxglx2u , 6U ) ; if (
( _rtDW -> cwivfg5ijd >= ssGetTaskTime ( S , 0 ) ) && ( _rtDW -> m1iuzueluk
>= ssGetTaskTime ( S , 0 ) ) ) { _rtB -> p1oacvuoap = _rtB -> a3iikuicnm ; }
else { if ( ( ( _rtDW -> cwivfg5ijd < _rtDW -> m1iuzueluk ) && ( _rtDW ->
m1iuzueluk < ssGetTaskTime ( S , 0 ) ) ) || ( ( _rtDW -> cwivfg5ijd >= _rtDW
-> m1iuzueluk ) && ( _rtDW -> cwivfg5ijd >= ssGetTaskTime ( S , 0 ) ) ) ) {
iiis24gb3o = ssGetTaskTime ( S , 0 ) - _rtDW -> m1iuzueluk ; lebvfutt11 =
_rtDW -> bvl1znuobh ; } else { iiis24gb3o = ssGetTaskTime ( S , 0 ) - _rtDW
-> cwivfg5ijd ; lebvfutt11 = _rtDW -> kguctqvwvn ; } f2e3v5ccex = _rtB ->
a3iikuicnm - lebvfutt11 ; if ( f2e3v5ccex > iiis24gb3o ) { _rtB -> p1oacvuoap
= lebvfutt11 + iiis24gb3o ; } else { iiis24gb3o = - iiis24gb3o ; if (
f2e3v5ccex < iiis24gb3o ) { _rtB -> p1oacvuoap = lebvfutt11 + iiis24gb3o ; }
else { _rtB -> p1oacvuoap = _rtB -> a3iikuicnm ; } } } byehzqrbel = 400.0 *
_rtB -> p1oacvuoap ; if ( byehzqrbel > fxzudfooqr ) { hmll0wvmpw = fxzudfooqr
; } else if ( byehzqrbel < - fxzudfooqr ) { hmll0wvmpw = - fxzudfooqr ; }
else { hmll0wvmpw = byehzqrbel ; } puuqlcshxw = ssGetT ( S ) ; _rtB ->
j4um5pxivg = ( real_T ) ( puuqlcshxw > ld5zvvrfqt ( S ) -> odsrzm4fae ) *
hmll0wvmpw ; puuqlcshxw = _rtB -> j4um5pxivg * _rtB -> j1z103ne1b ; if (
ssIsSampleHit ( S , 2 , 0 ) ) { _rtB -> o1nttgnvao = ( 1.0 - eskeehll14 / 7.0
) * 100.0 ; rowIdx = ( int32_T ) ( ( ( ( ( uint32_T ) ( _rtB -> o1nttgnvao <
ld5zvvrfqt ( S ) -> niqcsxyjmd ) << 1 ) + ( _rtB -> o1nttgnvao > ld5zvvrfqt (
S ) -> lcy5oepvmj ) ) << 1 ) + _rtDW -> bvad1zjfik ) ; _rtB -> igiwwchpml [
0U ] = ni220kbneq . h0dkarmdmw [ ( uint32_T ) rowIdx ] ; _rtB -> igiwwchpml [
1U ] = ni220kbneq . h0dkarmdmw [ rowIdx + 8U ] ; } hmll0wvmpw = _rtB ->
igiwwchpml [ 0 ] ; _rtB -> mhfdul4ssh = - 21000.0 * hmll0wvmpw ; if ( ( _rtDW
-> hfvh40s0je >= ssGetTaskTime ( S , 0 ) ) && ( _rtDW -> f41a3yqptq >=
ssGetTaskTime ( S , 0 ) ) ) { _rtB -> hnfw3iptxu = _rtB -> mhfdul4ssh ; }
else { if ( ( ( _rtDW -> hfvh40s0je < _rtDW -> f41a3yqptq ) && ( _rtDW ->
f41a3yqptq < ssGetTaskTime ( S , 0 ) ) ) || ( ( _rtDW -> hfvh40s0je >= _rtDW
-> f41a3yqptq ) && ( _rtDW -> hfvh40s0je >= ssGetTaskTime ( S , 0 ) ) ) ) {
iiis24gb3o = ssGetTaskTime ( S , 0 ) - _rtDW -> f41a3yqptq ; lebvfutt11 =
_rtDW -> aq3qjo4ji4 ; } else { iiis24gb3o = ssGetTaskTime ( S , 0 ) - _rtDW
-> hfvh40s0je ; lebvfutt11 = _rtDW -> lidlmlim32 ; } lstej3qx0u = iiis24gb3o
* 42000.0 ; f2e3v5ccex = _rtB -> mhfdul4ssh - lebvfutt11 ; if ( f2e3v5ccex >
lstej3qx0u ) { _rtB -> hnfw3iptxu = lebvfutt11 + lstej3qx0u ; } else {
iiis24gb3o *= - 42000.0 ; if ( f2e3v5ccex < iiis24gb3o ) { _rtB -> hnfw3iptxu
= lebvfutt11 + iiis24gb3o ; } else { _rtB -> hnfw3iptxu = _rtB -> mhfdul4ssh
; } } } j0jhyqa1p3 = puuqlcshxw - _rtB -> hnfw3iptxu ; hmll0wvmpw =
muDoubleScalarAbs ( j0jhyqa1p3 ) ; hmll0wvmpw = 1.1 * rt_Lookup ( _rtP ->
EngineSpeedPower . power , 84 , hmll0wvmpw , _rtP -> EngineSpeedPower . speed
) ; if ( hmll0wvmpw > 5000.0 ) { _rtB -> npqw2hqsht = 5000.0 ; } else if (
hmll0wvmpw < 750.0 ) { _rtB -> npqw2hqsht = 750.0 ; } else { _rtB ->
npqw2hqsht = hmll0wvmpw ; } byehzqrbel = 0.10471975511965977 * _rtB ->
npqw2hqsht ; if ( ssIsMajorTimeStep ( S ) ) { if ( puuqlcshxw >= 12000.0 ) {
_rtDW -> guq5pq4c5s = true ; } else { if ( puuqlcshxw <= 11000.0 ) { _rtDW ->
guq5pq4c5s = false ; } } } if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB ->
ntt0jkcwqv = ! ! _rtDW -> guq5pq4c5s ; _rtB -> mcuwt02j0z = ( _rtDW ->
aln04uuynj != ld5zvvrfqt ( S ) -> eybicv4ce3 ) ; } o3khhk3fbg = ( _rtB ->
ntt0jkcwqv || ( ( puuqlcshxw > ld5zvvrfqt ( S ) -> io4u3lf1h3 ) && _rtB ->
mcuwt02j0z ) ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> efvkk5qpog =
_rtDW -> nlh5qppt4m ; } if ( o3khhk3fbg ) { if ( j0jhyqa1p3 > 57000.0 ) {
h0cg4jnrg5 = 57000.0 ; } else if ( j0jhyqa1p3 < - 57000.0 ) { h0cg4jnrg5 = -
57000.0 ; } else { h0cg4jnrg5 = j0jhyqa1p3 ; } _rtB -> fiujcjo4ly = 1.0 /
byehzqrbel * h0cg4jnrg5 * _rtB -> ffl5hinbtg ; } else { _rtB -> fiujcjo4ly =
_rtB -> efvkk5qpog ; } puuqlcshxw = 1.0 / byehzqrbel * _rtB -> m2y1khvsri [
11 ] ; if ( puuqlcshxw > 1.0 ) { h0cg4jnrg5 = 1.0 ; } else if ( puuqlcshxw <
0.0 ) { h0cg4jnrg5 = 0.0 ; } else { h0cg4jnrg5 = puuqlcshxw ; } iiis24gb3o =
_rtB -> ffl5hinbtg * _rtB -> fiujcjo4ly * h0cg4jnrg5 * 0.27777777777777779 ;
if ( iiis24gb3o > i5nu34w4uj ) { _rtB -> ceod1aisyk = i5nu34w4uj ; } else if
( iiis24gb3o < - i5nu34w4uj ) { _rtB -> ceod1aisyk = - i5nu34w4uj ; } else {
_rtB -> ceod1aisyk = iiis24gb3o ; } puuqlcshxw = - _rtB -> ceod1aisyk *
ld5zvvrfqt ( S ) -> dlqmatuaok ; if ( ( _rtDW -> mtptmi2003 == ( rtMinusInf )
) || ( _rtDW -> mtptmi2003 == ssGetTaskTime ( S , 0 ) ) ) { _rtDW ->
mtptmi2003 = ssGetTaskTime ( S , 0 ) ; _rtB -> otok31ofhz = 0.0 ; } else {
_rtB -> otok31ofhz = puuqlcshxw ; } if ( ssIsSampleHit ( S , 2 , 0 ) ) { if (
_rtB -> otok31ofhz > 45.0 ) { dztyrqu4xa = 45.0 ; } else if ( _rtB ->
otok31ofhz < - 45.0 ) { dztyrqu4xa = - 45.0 ; } else { dztyrqu4xa = _rtB ->
otok31ofhz ; } aqlslovppe = 3.4722222222222219 * dztyrqu4xa ; dyfxp2slod = -
ld5zvvrfqt ( S ) -> kcqvuc0kxv * ckrl0nmlwt + aqlslovppe * lduwq00gqj ;
ctpq3axefx = dyfxp2slod - ogs5kt2fyi_idx_0 ; if ( ctpq3axefx >= 0.0 ) { _rtDW
-> mdrfaaqhlc = true ; } else { if ( ctpq3axefx <= 0.0 ) { _rtDW ->
mdrfaaqhlc = false ; } } dk4tk42hhp = ( 1.7320508 * ckrl0nmlwt + - lduwq00gqj
) * aqlslovppe * 0.5 + ( 1.7320508 * lduwq00gqj + ckrl0nmlwt ) * ld5zvvrfqt (
S ) -> kcqvuc0kxv * 0.5 ; aqlslovppe = dk4tk42hhp - ogs5kt2fyi_idx_1 ; if (
aqlslovppe >= 0.0 ) { _rtDW -> hi5e5wjvfn = true ; } else { if ( aqlslovppe
<= 0.0 ) { _rtDW -> hi5e5wjvfn = false ; } } f1b5simhxh = ( 0.0 - dk4tk42hhp
) - dyfxp2slod ; lduwq00gqj = f1b5simhxh - ogs5kt2fyi_idx_2 ; if ( lduwq00gqj
>= 0.0 ) { _rtDW -> ltj2mwt3by = true ; } else { if ( lduwq00gqj <= 0.0 ) {
_rtDW -> ltj2mwt3by = false ; } } _rtB -> fomw34zafl [ 0 ] = ( ( real_T )
_rtDW -> mdrfaaqhlc - ( real_T ) _rtDW -> hi5e5wjvfn ) * ld5zvvrfqt ( S ) ->
dlqmatuaok * _rtB -> jxjfrhnnrc ; _rtB -> fomw34zafl [ 1 ] = ( ( real_T )
_rtDW -> hi5e5wjvfn - ( real_T ) _rtDW -> ltj2mwt3by ) * ld5zvvrfqt ( S ) ->
dlqmatuaok * _rtB -> jxjfrhnnrc ; _rtB -> kktx4eqlpq = _rtDW -> bro0cn1wmi ;
ogs5kt2fyi_idx_0 = _rtDW -> j31s1kcymk [ 0 ] ; ogs5kt2fyi_idx_1 = _rtDW ->
j31s1kcymk [ 1 ] ; ogs5kt2fyi_idx_2 = _rtDW -> j31s1kcymk [ 2 ] ; ehcygfucdl
/= 4.0 ; ctpq3axefx = 4.0 * ehcygfucdl ; aqlslovppe = muDoubleScalarCos (
ctpq3axefx ) ; ctpq3axefx = muDoubleScalarSin ( ctpq3axefx ) ; if (
ssIsSampleHit ( S , 3 , 0 ) ) { _rtB -> puyxp41pqr = _rtDW -> gsr0ogd2xb ; }
_rtB -> pw1g04d5ea = 0.002479481623358034 * _rtB -> puyxp41pqr ; } if ( (
_rtDW -> joiszbfghn >= ssGetTaskTime ( S , 0 ) ) && ( _rtDW -> jlnwqqs23l >=
ssGetTaskTime ( S , 0 ) ) ) { _rtB -> bwi32ct0dr = _rtB -> pw1g04d5ea ; }
else { if ( ( ( _rtDW -> joiszbfghn < _rtDW -> jlnwqqs23l ) && ( _rtDW ->
jlnwqqs23l < ssGetTaskTime ( S , 0 ) ) ) || ( ( _rtDW -> joiszbfghn >= _rtDW
-> jlnwqqs23l ) && ( _rtDW -> joiszbfghn >= ssGetTaskTime ( S , 0 ) ) ) ) {
iiis24gb3o = ssGetTaskTime ( S , 0 ) - _rtDW -> jlnwqqs23l ; lebvfutt11 =
_rtDW -> miwjijsda1 ; } else { iiis24gb3o = ssGetTaskTime ( S , 0 ) - _rtDW
-> joiszbfghn ; lebvfutt11 = _rtDW -> narm2z4h4g ; } lstej3qx0u = iiis24gb3o
* 10.0 ; f2e3v5ccex = _rtB -> pw1g04d5ea - lebvfutt11 ; if ( f2e3v5ccex >
lstej3qx0u ) { _rtB -> bwi32ct0dr = lebvfutt11 + lstej3qx0u ; } else {
iiis24gb3o *= - 10.0 ; if ( f2e3v5ccex < iiis24gb3o ) { _rtB -> bwi32ct0dr =
lebvfutt11 + iiis24gb3o ; } else { _rtB -> bwi32ct0dr = _rtB -> pw1g04d5ea ;
} } } puuqlcshxw = muDoubleScalarAbs ( _rtB -> bwi32ct0dr ) ; _rtB ->
ana4c51koz = rt_Lookup ( ni220kbneq . hvtx2huqpc , 301 , puuqlcshxw ,
ni220kbneq . fjibtn4wrs ) ; if ( ssIsSampleHit ( S , 2 , 0 ) ) { _rtB ->
oukm0r2olj = _rtB -> j1z103ne1b ; ssCallAccelRunBlock ( S , 5 , 0 ,
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
= byehzqrbel - ogs5kt2fyi_idx_0 ; if ( iiis24gb3o >= 0.0 ) { _rtDW ->
bmg0h5hxwy = true ; } else { if ( iiis24gb3o <= 0.0 ) { _rtDW -> bmg0h5hxwy =
false ; } } i5nu34w4uj = ( 1.7320508 * ctpq3axefx + - aqlslovppe ) *
ckrl0nmlwt * 0.5 + ( 1.7320508 * aqlslovppe + ctpq3axefx ) * lduwq00gqj * 0.5
; ctpq3axefx = i5nu34w4uj - ogs5kt2fyi_idx_1 ; if ( ctpq3axefx >= 0.0 ) {
_rtDW -> kakc11drsq = true ; } else { if ( ctpq3axefx <= 0.0 ) { _rtDW ->
kakc11drsq = false ; } } lstej3qx0u = ( 0.0 - i5nu34w4uj ) - byehzqrbel ;
aqlslovppe = lstej3qx0u - ogs5kt2fyi_idx_2 ; if ( aqlslovppe >= 0.0 ) { _rtDW
-> d1uemo0w03 = true ; } else { if ( aqlslovppe <= 0.0 ) { _rtDW ->
d1uemo0w03 = false ; } } _rtB -> nsmzwpbqwm [ 0 ] = ( ( real_T ) _rtDW ->
bmg0h5hxwy - ( real_T ) _rtDW -> kakc11drsq ) * ld5zvvrfqt ( S ) ->
bacmzqco3u * _rtB -> kktx4eqlpq ; _rtB -> nsmzwpbqwm [ 1 ] = ( ( real_T )
_rtDW -> kakc11drsq - ( real_T ) _rtDW -> d1uemo0w03 ) * ld5zvvrfqt ( S ) ->
bacmzqco3u * _rtB -> kktx4eqlpq ; _rtB -> czrolx2b1o = _rtDW -> kzrq2xyp0f ;
pz4rdgpjxp = ( ld5zvvrfqt ( S ) -> dlqmatuaok != 0.0 ) ; zcEvent_idx_0 =
rt_ZCFcn ( ANY_ZERO_CROSSING , & _rtZCE -> gn3hyklx0i [ 0 ] , ( dyfxp2slod )
) ; zcEvent_idx_1 = rt_ZCFcn ( ANY_ZERO_CROSSING , & _rtZCE -> gn3hyklx0i [ 1
] , ( dk4tk42hhp ) ) ; zcEvent_idx_2 = rt_ZCFcn ( ANY_ZERO_CROSSING , &
_rtZCE -> gn3hyklx0i [ 2 ] , ( f1b5simhxh ) ) ; if ( _rtDW -> p5ivrte15o [ 0
] == 0 ) { if ( zcEvent_idx_0 != NO_ZCEVENT ) { _rtB -> m00u4uvrv4 [ 0 ] = !
_rtB -> m00u4uvrv4 [ 0 ] ; _rtDW -> p5ivrte15o [ 0 ] = 1 ; } else if ( _rtB
-> m00u4uvrv4 [ 0 ] ) { if ( dyfxp2slod != 0.0 ) { _rtB -> m00u4uvrv4 [ 0 ] =
false ; } } else { if ( dyfxp2slod == 0.0 ) { _rtB -> m00u4uvrv4 [ 0 ] = true
; } } } else { if ( dyfxp2slod != 0.0 ) { _rtB -> m00u4uvrv4 [ 0 ] = false ;
} _rtDW -> p5ivrte15o [ 0 ] = 0 ; } if ( _rtDW -> p5ivrte15o [ 1 ] == 0 ) {
if ( zcEvent_idx_1 != NO_ZCEVENT ) { _rtB -> m00u4uvrv4 [ 1 ] = ! _rtB ->
m00u4uvrv4 [ 1 ] ; _rtDW -> p5ivrte15o [ 1 ] = 1 ; } else if ( _rtB ->
m00u4uvrv4 [ 1 ] ) { if ( dk4tk42hhp != 0.0 ) { _rtB -> m00u4uvrv4 [ 1 ] =
false ; } } else { if ( dk4tk42hhp == 0.0 ) { _rtB -> m00u4uvrv4 [ 1 ] = true
; } } } else { if ( dk4tk42hhp != 0.0 ) { _rtB -> m00u4uvrv4 [ 1 ] = false ;
} _rtDW -> p5ivrte15o [ 1 ] = 0 ; } if ( _rtDW -> p5ivrte15o [ 2 ] == 0 ) {
if ( zcEvent_idx_2 != NO_ZCEVENT ) { _rtB -> m00u4uvrv4 [ 2 ] = ! _rtB ->
m00u4uvrv4 [ 2 ] ; _rtDW -> p5ivrte15o [ 2 ] = 1 ; } else if ( _rtB ->
m00u4uvrv4 [ 2 ] ) { if ( f1b5simhxh != 0.0 ) { _rtB -> m00u4uvrv4 [ 2 ] =
false ; } } else { if ( f1b5simhxh == 0.0 ) { _rtB -> m00u4uvrv4 [ 2 ] = true
; } } } else { if ( f1b5simhxh != 0.0 ) { _rtB -> m00u4uvrv4 [ 2 ] = false ;
} _rtDW -> p5ivrte15o [ 2 ] = 0 ; } keyxmz53xi ( S , _rtB -> m00u4uvrv4 [ 0 ]
, pz4rdgpjxp , & _rtB -> keyxmz53xiy , & _rtDW -> keyxmz53xiy ) ; keyxmz53xi
( S , _rtB -> m00u4uvrv4 [ 1 ] , pz4rdgpjxp , & _rtB -> d5h5wn4011 , & _rtDW
-> d5h5wn4011 ) ; keyxmz53xi ( S , _rtB -> m00u4uvrv4 [ 2 ] , pz4rdgpjxp , &
_rtB -> hlr1ddtilb , & _rtDW -> hlr1ddtilb ) ; iiis24gb3o =
0.05823546641575128 * _rtDW -> nonllthbl2 ; ctpq3axefx = 0.05823546641575128
* _rtDW -> kol45dq53x ; aqlslovppe = muDoubleScalarSin ( jwhz1ujp3w ) ;
jwhz1ujp3w = muDoubleScalarCos ( jwhz1ujp3w ) ; lduwq00gqj = ( 0.0 -
aqlslovppe * ld5zvvrfqt ( S ) -> an0plcvumq ) - jwhz1ujp3w * ld5zvvrfqt ( S )
-> pz5wrr1e1a ; ckrl0nmlwt = aqlslovppe * ld5zvvrfqt ( S ) -> pz5wrr1e1a -
jwhz1ujp3w * ld5zvvrfqt ( S ) -> an0plcvumq ; h0cg4jnrg5 = ( iiis24gb3o *
aqlslovppe + ctpq3axefx * jwhz1ujp3w ) + ld5zvvrfqt ( S ) -> kiccmlkren ;
lfv3m5pb5c = ( iiis24gb3o * lduwq00gqj + ctpq3axefx * ckrl0nmlwt ) +
ld5zvvrfqt ( S ) -> kiccmlkren ; iiis24gb3o = ( ( ( 0.0 - lduwq00gqj ) -
aqlslovppe ) * iiis24gb3o + ( ( 0.0 - ckrl0nmlwt ) - jwhz1ujp3w ) *
ctpq3axefx ) + ld5zvvrfqt ( S ) -> kiccmlkren ; _rtB -> cguxcadgoh [ 0 ] = (
real_T ) _rtB -> keyxmz53xiy . forbrjhq11 * dyfxp2slod + 0.2 * h0cg4jnrg5 ;
_rtB -> cguxcadgoh [ 1 ] = ( real_T ) _rtB -> d5h5wn4011 . forbrjhq11 *
dk4tk42hhp + 0.2 * lfv3m5pb5c ; _rtB -> cguxcadgoh [ 2 ] = ( real_T ) _rtB ->
hlr1ddtilb . forbrjhq11 * f1b5simhxh + 0.2 * iiis24gb3o ; if ( _rtDW ->
ehaijafsot <= 1.0 ) { h0cg4jnrg5 = 1.0 ; } else { h0cg4jnrg5 = _rtDW ->
ehaijafsot ; } _rtB -> bq4evcynkt = _rtDW -> fw2k5vojpd / h0cg4jnrg5 ;
zcEvent_idx_0 = rt_ZCFcn ( ANY_ZERO_CROSSING , & _rtZCE -> iw5dmb04jk [ 0 ] ,
( byehzqrbel ) ) ; zcEvent_idx_1 = rt_ZCFcn ( ANY_ZERO_CROSSING , & _rtZCE ->
iw5dmb04jk [ 1 ] , ( i5nu34w4uj ) ) ; zcEvent_idx_2 = rt_ZCFcn (
ANY_ZERO_CROSSING , & _rtZCE -> iw5dmb04jk [ 2 ] , ( lstej3qx0u ) ) ; if (
_rtDW -> l43ws31i1a [ 0 ] == 0 ) { if ( zcEvent_idx_0 != NO_ZCEVENT ) { _rtB
-> nz0qj5c0uy [ 0 ] = ! _rtB -> nz0qj5c0uy [ 0 ] ; _rtDW -> l43ws31i1a [ 0 ]
= 1 ; } else if ( _rtB -> nz0qj5c0uy [ 0 ] ) { if ( byehzqrbel != 0.0 ) {
_rtB -> nz0qj5c0uy [ 0 ] = false ; } } else { if ( byehzqrbel == 0.0 ) { _rtB
-> nz0qj5c0uy [ 0 ] = true ; } } } else { if ( byehzqrbel != 0.0 ) { _rtB ->
nz0qj5c0uy [ 0 ] = false ; } _rtDW -> l43ws31i1a [ 0 ] = 0 ; } if ( _rtDW ->
l43ws31i1a [ 1 ] == 0 ) { if ( zcEvent_idx_1 != NO_ZCEVENT ) { _rtB ->
nz0qj5c0uy [ 1 ] = ! _rtB -> nz0qj5c0uy [ 1 ] ; _rtDW -> l43ws31i1a [ 1 ] = 1
; } else if ( _rtB -> nz0qj5c0uy [ 1 ] ) { if ( i5nu34w4uj != 0.0 ) { _rtB ->
nz0qj5c0uy [ 1 ] = false ; } } else { if ( i5nu34w4uj == 0.0 ) { _rtB ->
nz0qj5c0uy [ 1 ] = true ; } } } else { if ( i5nu34w4uj != 0.0 ) { _rtB ->
nz0qj5c0uy [ 1 ] = false ; } _rtDW -> l43ws31i1a [ 1 ] = 0 ; } if ( _rtDW ->
l43ws31i1a [ 2 ] == 0 ) { if ( zcEvent_idx_2 != NO_ZCEVENT ) { _rtB ->
nz0qj5c0uy [ 2 ] = ! _rtB -> nz0qj5c0uy [ 2 ] ; _rtDW -> l43ws31i1a [ 2 ] = 1
; } else if ( _rtB -> nz0qj5c0uy [ 2 ] ) { if ( lstej3qx0u != 0.0 ) { _rtB ->
nz0qj5c0uy [ 2 ] = false ; } } else { if ( lstej3qx0u == 0.0 ) { _rtB ->
nz0qj5c0uy [ 2 ] = true ; } } } else { if ( lstej3qx0u != 0.0 ) { _rtB ->
nz0qj5c0uy [ 2 ] = false ; } _rtDW -> l43ws31i1a [ 2 ] = 0 ; } keyxmz53xi ( S
, _rtB -> nz0qj5c0uy [ 0 ] , ld5zvvrfqt ( S ) -> gl3rqm05j5 , & _rtB ->
ovboqennya , & _rtDW -> ovboqennya ) ; keyxmz53xi ( S , _rtB -> nz0qj5c0uy [
1 ] , ld5zvvrfqt ( S ) -> gl3rqm05j5 , & _rtB -> ifhlf2te5a , & _rtDW ->
ifhlf2te5a ) ; keyxmz53xi ( S , _rtB -> nz0qj5c0uy [ 2 ] , ld5zvvrfqt ( S )
-> gl3rqm05j5 , & _rtB -> dtnq4yt00p , & _rtDW -> dtnq4yt00p ) ; lfv3m5pb5c =
0.05823546641575128 * _rtDW -> lvw3lta2fy ; h0cg4jnrg5 = 0.05823546641575128
* _rtDW -> c20b4oc1jp ; ehcygfucdl *= 4.0 ; f2e3v5ccex = muDoubleScalarSin (
ehcygfucdl ) ; ehcygfucdl = muDoubleScalarCos ( ehcygfucdl ) ; lebvfutt11 = (
0.0 - f2e3v5ccex * ld5zvvrfqt ( S ) -> bgihs32tkq ) - ehcygfucdl * ld5zvvrfqt
( S ) -> beimhrqap4 ; iiis24gb3o = f2e3v5ccex * ld5zvvrfqt ( S ) ->
beimhrqap4 - ehcygfucdl * ld5zvvrfqt ( S ) -> bgihs32tkq ; lduwq00gqj = (
lfv3m5pb5c * f2e3v5ccex + h0cg4jnrg5 * ehcygfucdl ) + ld5zvvrfqt ( S ) ->
c50gw0z2bl ; ckrl0nmlwt = ( lfv3m5pb5c * lebvfutt11 + h0cg4jnrg5 * iiis24gb3o
) + ld5zvvrfqt ( S ) -> c50gw0z2bl ; lfv3m5pb5c = ( ( ( 0.0 - lebvfutt11 ) -
f2e3v5ccex ) * lfv3m5pb5c + ( ( 0.0 - iiis24gb3o ) - ehcygfucdl ) *
h0cg4jnrg5 ) + ld5zvvrfqt ( S ) -> c50gw0z2bl ; _rtB -> dfj5cpg0v2 [ 0 ] = (
real_T ) _rtB -> ovboqennya . forbrjhq11 * byehzqrbel + 1.5384615384615383 *
lduwq00gqj ; _rtB -> dfj5cpg0v2 [ 1 ] = ( real_T ) _rtB -> ifhlf2te5a .
forbrjhq11 * i5nu34w4uj + 1.5384615384615383 * ckrl0nmlwt ; _rtB ->
dfj5cpg0v2 [ 2 ] = ( real_T ) _rtB -> dtnq4yt00p . forbrjhq11 * lstej3qx0u +
1.5384615384615383 * lfv3m5pb5c ; if ( _rtDW -> kopxzfb0sb <= 1.0 ) {
h0cg4jnrg5 = 1.0 ; } else { h0cg4jnrg5 = _rtDW -> kopxzfb0sb ; } _rtB ->
mpak5gso2c = _rtDW -> lp13v2ihui / h0cg4jnrg5 ; _rtB -> mwu35mneec = _rtDW ->
ebwur5qeqq ; ssCallAccelRunBlock ( S , 16 , 493 , SS_CALL_MDL_OUTPUTS ) ;
_rtB -> eq5unt5day = _rtB -> k1fwhzg1af - 0.30769230769230771 * _rtB ->
aibll5qkty [ 33 ] ; ssCallAccelRunBlock ( S , 16 , 496 , SS_CALL_MDL_OUTPUTS
) ; lfv3m5pb5c = muDoubleScalarAbs ( _rtB -> aibll5qkty [ 33 ] ) ; _rtB ->
jdjzldp1u3 = ( ( real_T ) ( _rtB -> aibll5qkty [ 33 ] < ld5zvvrfqt ( S ) ->
k1fx0ardpd ) * 18.82114106089411 - f4ufgq33gz ) * lfv3m5pb5c *
0.00064102564102564092 ; _rtB -> cqyvcf4dzn = 3600.0 * eskeehll14 ; }
ssCallAccelRunBlock ( S , 14 , 0 , SS_CALL_MDL_OUTPUTS ) ; if ( _rtB ->
j1z103ne1b <= 1.0 ) { i5nu34w4uj = 1.0 ; } else { i5nu34w4uj = _rtB ->
j1z103ne1b ; } if ( ssIsMajorTimeStep ( S ) ) { if ( i5nu34w4uj >=
20.943951023931955 ) { _rtDW -> bmy4qihc4v = true ; } else { if ( i5nu34w4uj
<= 10.471975511965978 ) { _rtDW -> bmy4qihc4v = false ; } } } _rtB ->
iwnuavr5zh = ! _rtDW -> bmy4qihc4v ; if ( ssIsSampleHit ( S , 2 , 0 ) ) {
_rtB -> fylr2qsvta = ld5zvvrfqt ( S ) -> cirzscpgrb - ( ld5zvvrfqt ( S ) ->
es2brvfsf4 - _rtB -> eq5unt5day ) * 200.0 ; } puuqlcshxw = _rtB -> fylr2qsvta
; if ( puuqlcshxw > 21000.0 ) { _rtB -> kc2vpriwaf = 21000.0 ; } else if (
puuqlcshxw < 0.0 ) { _rtB -> kc2vpriwaf = 0.0 ; } else { _rtB -> kc2vpriwaf =
puuqlcshxw ; } if ( ( _rtDW -> n33aen2wbt >= ssGetTaskTime ( S , 0 ) ) && (
_rtDW -> fjojh4ewqs >= ssGetTaskTime ( S , 0 ) ) ) { _rtB -> c0tqxoxafw =
_rtB -> kc2vpriwaf ; } else { if ( ( ( _rtDW -> n33aen2wbt < _rtDW ->
fjojh4ewqs ) && ( _rtDW -> fjojh4ewqs < ssGetTaskTime ( S , 0 ) ) ) || ( (
_rtDW -> n33aen2wbt >= _rtDW -> fjojh4ewqs ) && ( _rtDW -> n33aen2wbt >=
ssGetTaskTime ( S , 0 ) ) ) ) { iiis24gb3o = ssGetTaskTime ( S , 0 ) - _rtDW
-> fjojh4ewqs ; lebvfutt11 = _rtDW -> d21ysphefx ; } else { iiis24gb3o =
ssGetTaskTime ( S , 0 ) - _rtDW -> n33aen2wbt ; lebvfutt11 = _rtDW ->
evmu5j4txb ; } lstej3qx0u = iiis24gb3o * 210000.0 ; f2e3v5ccex = _rtB ->
kc2vpriwaf - lebvfutt11 ; if ( f2e3v5ccex > lstej3qx0u ) { _rtB -> c0tqxoxafw
= lebvfutt11 + lstej3qx0u ; } else { iiis24gb3o *= - 210000.0 ; if (
f2e3v5ccex < iiis24gb3o ) { _rtB -> c0tqxoxafw = lebvfutt11 + iiis24gb3o ; }
else { _rtB -> c0tqxoxafw = _rtB -> kc2vpriwaf ; } } } fviymzl3aa = ( _rtB ->
hnfw3iptxu != ld5zvvrfqt ( S ) -> j4pidrlt4y ) ; byehzqrbel = j0jhyqa1p3 -
_rtB -> il4mgadolv [ 1 ] * _rtB -> m2y1khvsri [ 11 ] ; if ( fviymzl3aa ) {
_rtB -> ntwwmshxi0 = _rtB -> hnfw3iptxu ; } else { _rtB -> ntwwmshxi0 =
byehzqrbel ; } if ( ( _rtDW -> nolj4flzwb >= ssGetTaskTime ( S , 0 ) ) && (
_rtDW -> bluedlz4ee >= ssGetTaskTime ( S , 0 ) ) ) { _rtB -> l1qrn1jl2e =
_rtB -> ntwwmshxi0 ; } else { if ( ( ( _rtDW -> nolj4flzwb < _rtDW ->
bluedlz4ee ) && ( _rtDW -> bluedlz4ee < ssGetTaskTime ( S , 0 ) ) ) || ( (
_rtDW -> nolj4flzwb >= _rtDW -> bluedlz4ee ) && ( _rtDW -> nolj4flzwb >=
ssGetTaskTime ( S , 0 ) ) ) ) { iiis24gb3o = ssGetTaskTime ( S , 0 ) - _rtDW
-> bluedlz4ee ; lebvfutt11 = _rtDW -> awi4nxie0m ; } else { iiis24gb3o =
ssGetTaskTime ( S , 0 ) - _rtDW -> nolj4flzwb ; lebvfutt11 = _rtDW ->
ppmw3hzciy ; } lstej3qx0u = iiis24gb3o * 21000.0 ; f2e3v5ccex = _rtB ->
ntwwmshxi0 - lebvfutt11 ; if ( f2e3v5ccex > lstej3qx0u ) { _rtB -> l1qrn1jl2e
= lebvfutt11 + lstej3qx0u ; } else { iiis24gb3o *= - 21000.0 ; if (
f2e3v5ccex < iiis24gb3o ) { _rtB -> l1qrn1jl2e = lebvfutt11 + iiis24gb3o ; }
else { _rtB -> l1qrn1jl2e = _rtB -> ntwwmshxi0 ; } } } if ( _rtB ->
iwnuavr5zh != 0.0 ) { _rtB -> hihe2s4kvk = _rtB -> bwqretfuxy ; } else { if (
fviymzl3aa ) { byehzqrbel = _rtB -> l1qrn1jl2e ; } if ( byehzqrbel > _rtB ->
c0tqxoxafw ) { byehzqrbel = _rtB -> c0tqxoxafw ; } else { if ( byehzqrbel < -
_rtB -> c0tqxoxafw ) { byehzqrbel = - _rtB -> c0tqxoxafw ; } } _rtB ->
hihe2s4kvk = ( _rtB -> m2y1khvsri [ 7 ] * _rtB -> ceod1aisyk + byehzqrbel ) /
i5nu34w4uj ; } ssCallAccelRunBlock ( S , 16 , 546 , SS_CALL_MDL_OUTPUTS ) ;
if ( ssIsSampleHit ( S , 2 , 0 ) ) { ssCallAccelRunBlock ( S , 16 , 547 ,
SS_CALL_MDL_OUTPUTS ) ; } ssCallAccelRunBlock ( S , 16 , 548 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> boctzwx3r2 = 9.5492965855137211 * _rtB ->
j1z103ne1b ; if ( ssIsSampleHit ( S , 2 , 0 ) && ssIsSampleHit ( S , 3 , 0 )
) { _rtB -> i30nk3avon = _rtDW -> bv5gvrfela ; } _rtB -> fez00ly5gv = _rtB ->
kgfazmviyv * _rtB -> j1z103ne1b ; ssCallAccelRunBlock ( S , 16 , 552 ,
SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSampleHit ( S , 2 , 0 ) ) {
ssCallAccelRunBlock ( S , 16 , 555 , SS_CALL_MDL_OUTPUTS ) ; }
ssCallAccelRunBlock ( S , 16 , 556 , SS_CALL_MDL_OUTPUTS ) ; if (
ssIsSampleHit ( S , 2 , 0 ) ) { lfv3m5pb5c = 0.013480000230266853 * _rtDW ->
pe31gvq3pv ; h0cg4jnrg5 = 0.013480000230266853 * _rtDW -> bw5cwo255x ; rowIdx
= ( int32_T ) ( ( ( ( ( uint32_T ) ( lfv3m5pb5c > h0cg4jnrg5 ) << 1 ) + (
lfv3m5pb5c < 0.9 * h0cg4jnrg5 ) ) << 1 ) + _rtDW -> l2t4rgxmml ) ; _rtB ->
g33hibypbt [ 0U ] = ni220kbneq . h0dkarmdmw [ ( uint32_T ) rowIdx ] ; _rtB ->
g33hibypbt [ 1U ] = ni220kbneq . h0dkarmdmw [ rowIdx + 8U ] ; h100jbae3x = (
uint8_T ) ( _rtB -> g33hibypbt [ 0 ] << 7 ) ; _rtB -> k31tgmex5c = ( real_T )
h100jbae3x * 0.0078125 ; _rtB -> nwcrbxkob3 = ( real_T ) h100jbae3x *
0.0078125 ; _rtB -> pot2bhgbcu = ( real_T ) h100jbae3x * 0.0078125 ;
fviymzl3aa = ! ( h100jbae3x != 0 ) ; _rtB -> fc1zwwau0d = fviymzl3aa ; _rtB
-> ab22rl2mcl = fviymzl3aa ; _rtB -> mmdoodonai = fviymzl3aa ; _rtB ->
kqhibdmrst = ( ( _rtB -> aibll5qkty [ 30 ] * _rtB -> aibll5qkty [ 30 ] + _rtB
-> aibll5qkty [ 31 ] * _rtB -> aibll5qkty [ 31 ] ) + _rtB -> aibll5qkty [ 32
] * _rtB -> aibll5qkty [ 32 ] ) * 0.001 + ( _rtB -> aibll5qkty [ 21 ] * _rtB
-> aibll5qkty [ 30 ] + _rtB -> aibll5qkty [ 22 ] * _rtB -> aibll5qkty [ 31 ]
) ; } byehzqrbel = muDoubleScalarPower ( ( 0.006391889398924 * _rtB ->
j1z103ne1b * _rtB -> aorbsvsy2v + 0.0065 * _rtB -> deue3miwlt ) +
0.702664574517444 * _rtB -> j1z103ne1b , 2.0 ) + muDoubleScalarPower ( 0.0065
* _rtB -> aorbsvsy2v - 0.008228209001868 * _rtB -> j1z103ne1b * _rtB ->
deue3miwlt , 2.0 ) ; if ( byehzqrbel < 0.0 ) { byehzqrbel = -
muDoubleScalarSqrt ( - byehzqrbel ) ; } else { byehzqrbel =
muDoubleScalarSqrt ( byehzqrbel ) ; } _rtB -> pgpl5aw1mw = 1.5707963267948966
* byehzqrbel ; if ( ssIsSampleHit ( S , 2 , 0 ) ) { _rtB -> dvubszjv5v = ( (
2.0 * _rtB -> aibll5qkty [ 14 ] + _rtB -> aibll5qkty [ 15 ] ) * mizlp41tvx +
1.7320508075688772 * _rtB -> aibll5qkty [ 15 ] * po0ockmy2b ) *
0.33333333333333331 ; _rtB -> htg4ufwc50 = ( ( 2.0 * _rtB -> aibll5qkty [ 14
] + _rtB -> aibll5qkty [ 15 ] ) * po0ockmy2b + - 1.7320508075688772 * _rtB ->
aibll5qkty [ 15 ] * mizlp41tvx ) * 0.33333333333333331 ; _rtB -> m3ieo43hnc =
625.79305591134812 * _rtB -> htg4ufwc50 ; } _rtB -> j5h1g1a2gl = 4.0 * _rtB
-> j1z103ne1b ; if ( ssIsSampleHit ( S , 2 , 0 ) ) { _rtB -> hqjbsmylej =
4.0676548634237628 * _rtB -> aorbsvsy2v ; } _rtB -> nz3cfakluj = _rtB ->
j5h1g1a2gl * _rtB -> deue3miwlt * 1.2872890139890598 + ( _rtB -> m3ieo43hnc -
_rtB -> hqjbsmylej ) ; if ( ssIsSampleHit ( S , 2 , 0 ) ) { _rtB ->
bek5ikc30q = 486.13252277523628 * _rtB -> dvubszjv5v ; _rtB -> jbhnsaucba =
3.1598613980390358 * _rtB -> deue3miwlt ; } _rtB -> ivk531rbyj = ( ( _rtB ->
bek5ikc30q - _rtB -> jbhnsaucba ) - _rtB -> aorbsvsy2v * _rtB -> j5h1g1a2gl *
0.77682632969980325 ) - 85.397025568738272 * _rtB -> j5h1g1a2gl ; puuqlcshxw
= muDoubleScalarAbs ( _rtB -> j1z103ne1b ) ; HEV_acc_LookUp_real_T_real_T ( &
( bqmdh4lvh2 ) , ni220kbneq . jmw3cjssuc , puuqlcshxw , ni220kbneq .
imwrxglx2u , 6U ) ; if ( _rtB -> hihe2s4kvk > bqmdh4lvh2 ) { puuqlcshxw =
bqmdh4lvh2 ; } else if ( _rtB -> hihe2s4kvk < - bqmdh4lvh2 ) { puuqlcshxw = -
bqmdh4lvh2 ; } else { puuqlcshxw = _rtB -> hihe2s4kvk ; } puuqlcshxw *=
ld5zvvrfqt ( S ) -> bacmzqco3u ; if ( ( _rtDW -> dlegz3mcx5 == ( rtMinusInf )
) || ( _rtDW -> dlegz3mcx5 == ssGetTaskTime ( S , 0 ) ) ) { _rtDW ->
dlegz3mcx5 = ssGetTaskTime ( S , 0 ) ; _rtB -> hh3l1eza4j = 0.0 ; } else {
_rtB -> hh3l1eza4j = puuqlcshxw ; } if ( ssIsSampleHit ( S , 3 , 0 ) ) { _rtB
-> jcxxdwjwci = _rtB -> hh3l1eza4j ; if ( _rtB -> jcxxdwjwci > 400.0 ) { _rtB
-> fpqhfdmsru = 400.0 ; } else if ( _rtB -> jcxxdwjwci < - 400.0 ) { _rtB ->
fpqhfdmsru = - 400.0 ; } else { _rtB -> fpqhfdmsru = _rtB -> jcxxdwjwci ; } }
if ( ssIsSampleHit ( S , 1 , 0 ) && ssIsSampleHit ( S , 3 , 0 ) ) { _rtB ->
jjkx10yeed = ld5zvvrfqt ( S ) -> bacmzqco3u ; } if ( ssIsSampleHit ( S , 3 ,
0 ) ) { _rtB -> oecxc3muyp = _rtB -> fpqhfdmsru * _rtB -> jjkx10yeed ; } if (
ssIsSampleHit ( S , 2 , 0 ) ) { ssCallAccelRunBlock ( S , 16 , 697 ,
SS_CALL_MDL_OUTPUTS ) ; } ssCallAccelRunBlock ( S , 16 , 698 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> boctzwx3r2 = 9.5492965855137211 * _rtB ->
m2y1khvsri [ 7 ] ; if ( ssIsSampleHit ( S , 1 , 0 ) && ssIsSampleHit ( S , 2
, 0 ) ) { _rtB -> fc4r1lejoh = ld5zvvrfqt ( S ) -> dlqmatuaok ; } if (
ssIsSampleHit ( S , 2 , 0 ) ) { _rtB -> pldqmspvgi = dztyrqu4xa * _rtB ->
fc4r1lejoh ; } _rtB -> fez00ly5gv = _rtB -> netq4xlqvp * _rtB -> m2y1khvsri [
7 ] ; ssCallAccelRunBlock ( S , 16 , 703 , SS_CALL_MDL_OUTPUTS ) ; if (
ssIsSampleHit ( S , 2 , 0 ) ) { lfv3m5pb5c = 0.013480000230266853 * _rtDW ->
dy4ppyw4mo ; h0cg4jnrg5 = 0.013480000230266853 * _rtDW -> hmybg5b1mi ; rowIdx
= ( int32_T ) ( ( ( ( ( uint32_T ) ( lfv3m5pb5c > h0cg4jnrg5 ) << 1 ) + (
lfv3m5pb5c < 0.9 * h0cg4jnrg5 ) ) << 1 ) + _rtDW -> gkq12xkctn ) ; _rtB ->
noc4c0qkjo [ 0U ] = ni220kbneq . h0dkarmdmw [ ( uint32_T ) rowIdx ] ; _rtB ->
noc4c0qkjo [ 1U ] = ni220kbneq . h0dkarmdmw [ rowIdx + 8U ] ; h100jbae3x = (
uint8_T ) ( _rtB -> noc4c0qkjo [ 0 ] << 7 ) ; _rtB -> dqxprvnwis = ( real_T )
h100jbae3x * 0.0078125 ; _rtB -> cvt0clhka1 = ( real_T ) h100jbae3x *
0.0078125 ; _rtB -> chmwopmagd = ( real_T ) h100jbae3x * 0.0078125 ;
fviymzl3aa = ! ( h100jbae3x != 0 ) ; _rtB -> od3d2wkvgo = fviymzl3aa ; _rtB
-> kcia5wy55r = fviymzl3aa ; _rtB -> hlesaknin3 = fviymzl3aa ; _rtB ->
gge1siyfxe = ( ( _rtB -> aibll5qkty [ 26 ] * _rtB -> aibll5qkty [ 26 ] + _rtB
-> aibll5qkty [ 27 ] * _rtB -> aibll5qkty [ 27 ] ) + _rtB -> aibll5qkty [ 28
] * _rtB -> aibll5qkty [ 28 ] ) * 0.001 + ( _rtB -> aibll5qkty [ 17 ] * _rtB
-> aibll5qkty [ 26 ] + _rtB -> aibll5qkty [ 18 ] * _rtB -> aibll5qkty [ 27 ]
) ; } byehzqrbel = muDoubleScalarPower ( ( 0.000635 * _rtB -> m2y1khvsri [ 7
] * _rtB -> gthgcz50sq + 0.05 * _rtB -> bw2nhi51td ) + 0.192 * _rtB ->
m2y1khvsri [ 7 ] , 2.0 ) + muDoubleScalarPower ( 0.05 * _rtB -> gthgcz50sq -
0.000635 * _rtB -> m2y1khvsri [ 7 ] * _rtB -> bw2nhi51td , 2.0 ) ; if (
byehzqrbel < 0.0 ) { byehzqrbel = - muDoubleScalarSqrt ( - byehzqrbel ) ; }
else { byehzqrbel = muDoubleScalarSqrt ( byehzqrbel ) ; } _rtB -> n1gbyberwg
= 1.5707963267948966 * byehzqrbel ; if ( ssIsSampleHit ( S , 2 , 0 ) ) { _rtB
-> lkkzfx3t03 = ( ( 2.0 * _rtB -> aibll5qkty [ 12 ] + _rtB -> aibll5qkty [ 13
] ) * mkcfwi2fsi + 1.7320508075688772 * _rtB -> aibll5qkty [ 13 ] *
ehtkh2wauy ) * 0.33333333333333331 ; _rtB -> p3bo2y3kw5 = ( ( 2.0 * _rtB ->
aibll5qkty [ 12 ] + _rtB -> aibll5qkty [ 13 ] ) * ehtkh2wauy + -
1.7320508075688772 * _rtB -> aibll5qkty [ 13 ] * mkcfwi2fsi ) *
0.33333333333333331 ; _rtB -> pme2nztw2h = 1574.803149606299 * _rtB ->
p3bo2y3kw5 ; _rtB -> eoxdne2pfw = 78.740157480314963 * _rtB -> gthgcz50sq ; }
_rtB -> hwgpv13xpn = ( _rtB -> pme2nztw2h - _rtB -> eoxdne2pfw ) + _rtB ->
m2y1khvsri [ 7 ] * _rtB -> bw2nhi51td ; if ( ssIsSampleHit ( S , 2 , 0 ) ) {
_rtB -> b5csxaxx3b = 1574.803149606299 * _rtB -> lkkzfx3t03 ; _rtB ->
m4yasshlmn = 78.740157480314963 * _rtB -> bw2nhi51td ; } _rtB -> ptlcfubn2y =
( ( _rtB -> b5csxaxx3b - _rtB -> m4yasshlmn ) - _rtB -> gthgcz50sq * _rtB ->
m2y1khvsri [ 7 ] ) - 302.36220472440942 * _rtB -> m2y1khvsri [ 7 ] ; if (
ssIsSampleHit ( S , 2 , 0 ) ) { ssCallAccelRunBlock ( S , 16 , 832 ,
SS_CALL_MDL_OUTPUTS ) ; } puuqlcshxw = ssGetT ( S ) ; if ( ssIsSampleHit ( S
, 2 , 0 ) ) { _rtB -> cno0kxd2pq = _rtB -> aibll5qkty [ 16 ] - ld5zvvrfqt ( S
) -> iz54xu1bvd ; } _rtB -> c3esxbsqjj = ( real_T ) ( puuqlcshxw > ld5zvvrfqt
( S ) -> lz0tyrysj4 ) * _rtB -> cno0kxd2pq ; if ( ssIsSampleHit ( S , 2 , 0 )
) { if ( _rtDW -> llu3sg1ihp != 0 ) { _rtB -> pabbygan1q = _rtDW ->
fj2gixcnhk ; } else { _rtB -> pabbygan1q = 3.0E-5 * _rtB -> c3esxbsqjj +
_rtDW -> fj2gixcnhk ; } if ( _rtB -> pabbygan1q >= 1.0 ) { _rtB -> pabbygan1q
= 1.0 ; } else { if ( _rtB -> pabbygan1q <= - 1.0 ) { _rtB -> pabbygan1q = -
1.0 ; } } } puuqlcshxw = 0.001 * _rtB -> c3esxbsqjj + _rtB -> pabbygan1q ; if
( puuqlcshxw > 0.95 ) { h0cg4jnrg5 = 0.95 ; } else if ( puuqlcshxw < - 0.95 )
{ h0cg4jnrg5 = - 0.95 ; } else { h0cg4jnrg5 = puuqlcshxw ; } _rtB ->
e4m3b3l42x = ( h0cg4jnrg5 + 1.0 ) * 0.5 ; if ( ssIsSampleHit ( S , 2 , 0 ) )
{ lfv3m5pb5c = _rtDW -> dco4afubi3 ; _rtB -> fzfj2bbqis = _rtDW -> dco4afubi3
* _rtB -> aibll5qkty [ 24 ] ; _rtB -> daw1svm0il = _rtDW -> dco4afubi3 * _rtB
-> aibll5qkty [ 34 ] ; } ssCallAccelRunBlock ( S , 16 , 879 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 16 , 880 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 16 , 881 ,
SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSampleHit ( S , 2 , 0 ) ) {
ssCallAccelRunBlock ( S , 16 , 882 , SS_CALL_MDL_OUTPUTS ) ; } if (
ssIsSampleHit ( S , 4 , 0 ) ) { ssCallAccelRunBlock ( S , 16 , 883 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 16 , 884 ,
SS_CALL_MDL_OUTPUTS ) ; } if ( _rtB -> pymde5nzv1 > 136.0 ) { h0cg4jnrg5 =
136.0 ; } else if ( _rtB -> pymde5nzv1 < 0.0 ) { h0cg4jnrg5 = 0.0 ; } else {
h0cg4jnrg5 = _rtB -> pymde5nzv1 ; } puuqlcshxw = h0cg4jnrg5 * ld5zvvrfqt ( S
) -> citnorfywz ; if ( puuqlcshxw > 1.0 ) { _rtB -> boctzwx3r2 = 1.0 ; } else
if ( puuqlcshxw < 0.0 ) { _rtB -> boctzwx3r2 = 0.0 ; } else { _rtB ->
boctzwx3r2 = puuqlcshxw ; } ssCallAccelRunBlock ( S , 16 , 889 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 16 , 890 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 16 , 891 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 16 , 892 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 16 , 893 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 16 , 894 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 16 , 895 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 16 , 896 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 16 , 897 ,
SS_CALL_MDL_OUTPUTS ) ; puuqlcshxw = _rtB -> npqw2hqsht * ( real_T )
o3khhk3fbg ; if ( ( _rtDW -> nn1a5wvgr5 == ( rtMinusInf ) ) || ( _rtDW ->
nn1a5wvgr5 == ssGetTaskTime ( S , 0 ) ) ) { _rtDW -> nn1a5wvgr5 =
ssGetTaskTime ( S , 0 ) ; _rtB -> gocu1jhwsd = 0.0 ; } else { _rtB ->
gocu1jhwsd = puuqlcshxw ; } if ( ( _rtDW -> ewhcynzuun >= ssGetTaskTime ( S ,
0 ) ) && ( _rtDW -> ciu3b0lpet >= ssGetTaskTime ( S , 0 ) ) ) { _rtB ->
bso0xqecj4 = _rtB -> gocu1jhwsd ; } else { if ( ( ( _rtDW -> ewhcynzuun <
_rtDW -> ciu3b0lpet ) && ( _rtDW -> ciu3b0lpet < ssGetTaskTime ( S , 0 ) ) )
|| ( ( _rtDW -> ewhcynzuun >= _rtDW -> ciu3b0lpet ) && ( _rtDW -> ewhcynzuun
>= ssGetTaskTime ( S , 0 ) ) ) ) { iiis24gb3o = ssGetTaskTime ( S , 0 ) -
_rtDW -> ciu3b0lpet ; lebvfutt11 = _rtDW -> mmlyeyihwy ; } else { iiis24gb3o
= ssGetTaskTime ( S , 0 ) - _rtDW -> ewhcynzuun ; lebvfutt11 = _rtDW ->
h4ipbzntlo ; } lstej3qx0u = iiis24gb3o * 50000.0 ; f2e3v5ccex = _rtB ->
gocu1jhwsd - lebvfutt11 ; if ( f2e3v5ccex > lstej3qx0u ) { _rtB -> bso0xqecj4
= lebvfutt11 + lstej3qx0u ; } else { iiis24gb3o *= - 50000.0 ; if (
f2e3v5ccex < iiis24gb3o ) { _rtB -> bso0xqecj4 = lebvfutt11 + iiis24gb3o ; }
else { _rtB -> bso0xqecj4 = _rtB -> gocu1jhwsd ; } } } if ( ssIsSampleHit ( S
, 2 , 0 ) ) { _rtB -> pbf1a3yqhj = o3khhk3fbg ; h0cg4jnrg5 = ( _rtB ->
bso0xqecj4 - 0.036997346603025116 * _rtDW -> jctbfc4f1e ) * ( real_T ) _rtB
-> pbf1a3yqhj ; _rtB -> ehm05itqhc = 0.1 * h0cg4jnrg5 ; if ( _rtDW ->
h4pa1qmmy5 != 0 ) { _rtB -> d0eztedmuw = _rtDW -> olv3cnxtoy ; } else { _rtB
-> d0eztedmuw = 3.0E-5 * _rtB -> ehm05itqhc + _rtDW -> olv3cnxtoy ; } if (
_rtB -> d0eztedmuw >= 1.0 ) { _rtB -> d0eztedmuw = 1.0 ; } else { if ( _rtB
-> d0eztedmuw <= 0.0 ) { _rtB -> d0eztedmuw = 0.0 ; } } lfv3m5pb5c = 0.01 *
h0cg4jnrg5 + _rtB -> d0eztedmuw ; if ( lfv3m5pb5c > 1.0 ) { lfv3m5pb5c = 1.0
; } else { if ( lfv3m5pb5c < 0.0 ) { lfv3m5pb5c = 0.0 ; } } } puuqlcshxw =
_rtB -> m2y1khvsri [ 11 ] * ( real_T ) o3khhk3fbg ; _rtB -> d3masju4ca =
9.5492965855137211 * puuqlcshxw ; if ( ssIsSampleHit ( S , 2 , 0 ) ) { _rtB
-> gxqfziopir = _rtB -> d3masju4ca ; _rtB -> acoi1pgdho = lfv3m5pb5c * (
real_T ) _rtB -> pbf1a3yqhj ; } _rtB -> jvrzworo0h = muDoubleScalarAbs ( _rtB
-> chkwevbcym ) ; if ( ( _rtDW -> en15lu4hm1 >= ssGetT ( S ) ) && ( _rtDW ->
km4yirabra >= ssGetT ( S ) ) ) { _rtB -> jhlhkn2bro = 0.0 ; } else {
byehzqrbel = _rtDW -> en15lu4hm1 ; lastU = & _rtDW -> aa3vndu55f ; if ( _rtDW
-> en15lu4hm1 < _rtDW -> km4yirabra ) { if ( _rtDW -> km4yirabra < ssGetT ( S
) ) { byehzqrbel = _rtDW -> km4yirabra ; lastU = & _rtDW -> ke4dqjfdz3 ; } }
else { if ( _rtDW -> en15lu4hm1 >= ssGetT ( S ) ) { byehzqrbel = _rtDW ->
km4yirabra ; lastU = & _rtDW -> ke4dqjfdz3 ; } } _rtB -> jhlhkn2bro = ( _rtB
-> g123hlbqqb - * lastU ) / ( ssGetT ( S ) - byehzqrbel ) ; } _rtB ->
jqrojiimfx = muDoubleScalarAbs ( _rtB -> ib5hrgd3aj ) ; _rtB -> p44y0w4hfk =
1.093 * _rtB -> jqrojiimfx ; _rtB -> o0mdtsxsuo = 1.0464 * _rtB -> g123hlbqqb
; { uint32_T iLeftU0 , iRghtU0 , iLeftU1 , iRghtU1 ;
HEV_acc_BINARYSEARCH_real_T ( & ( iLeftU0 ) , & ( iRghtU0 ) , _rtB ->
p44y0w4hfk , ni220kbneq . c4qvyaa1p5 , 108U ) ; if ( _rtB -> o0mdtsxsuo <=
0.0 ) { iLeftU1 = 0U ; iRghtU1 = 0U ; } else if ( _rtB -> o0mdtsxsuo >=
6000.0 ) { iLeftU1 = 100U ; iRghtU1 = 100U ; } else { iLeftU1 = ( uint32_T )
( ( _rtB -> o0mdtsxsuo ) / 60.0 ) ; iRghtU1 = iLeftU1 + 1 ; } { real_T yTemp
; real_T u1Lambda ; real_T u0Lambda ; if ( iLeftU1 != iRghtU1 ) { { real_T
num = ( real_T ) ( _rtB -> o0mdtsxsuo ) - ( iLeftU1 * 60.0 ) ; u1Lambda = num
/ 60.0 ; } } else { u1Lambda = 0.0 ; } if ( ( ni220kbneq . c4qvyaa1p5 [
iRghtU0 ] ) > ( ni220kbneq . c4qvyaa1p5 [ iLeftU0 ] ) ) { real_T num ; real_T
den ; den = ( ni220kbneq . c4qvyaa1p5 [ iRghtU0 ] ) ; den -= ( ni220kbneq .
c4qvyaa1p5 [ iLeftU0 ] ) ; num = _rtB -> p44y0w4hfk ; num -= ( ni220kbneq .
c4qvyaa1p5 [ iLeftU0 ] ) ; u0Lambda = num / den ; } else { u0Lambda = 0.0 ; }
{ real_T yLeftCast ; real_T yRghtCast ; yLeftCast = ( ni220kbneq . dca3iiaooc
[ ( iLeftU0 + 109U * iLeftU1 ) ] ) ; yRghtCast = ( ni220kbneq . dca3iiaooc [
( iLeftU0 + 109U * iRghtU1 ) ] ) ; yLeftCast += u1Lambda * ( yRghtCast -
yLeftCast ) ; boxfyroykz = yLeftCast ; } { real_T yLeftCast ; real_T
yRghtCast ; yLeftCast = ( ni220kbneq . dca3iiaooc [ ( iRghtU0 + 109U *
iLeftU1 ) ] ) ; yRghtCast = ( ni220kbneq . dca3iiaooc [ ( iRghtU0 + 109U *
iRghtU1 ) ] ) ; yLeftCast += u1Lambda * ( yRghtCast - yLeftCast ) ; yTemp =
yLeftCast ; } { real_T yLeftCast ; real_T yRghtCast ; yLeftCast = boxfyroykz
; yRghtCast = yTemp ; yLeftCast += u0Lambda * ( yRghtCast - yLeftCast ) ;
boxfyroykz = yLeftCast ; } } } _rtB -> jzrbbioo5t = 1.0351048413332149 *
boxfyroykz ; _rtB -> beud2e32er = 1.933764640184292E-6 * _rtB -> jzrbbioo5t ;
_rtB -> p34el342ry = muDoubleScalarSign ( _rtB -> ib5hrgd3aj ) ; _rtB ->
maccidjr03 = muDoubleScalarAbs ( _rtB -> ib5hrgd3aj ) ; _rtB -> ptlppe1ifn =
1.093 * _rtB -> maccidjr03 ; _rtB -> pw2tl3utlu = 1.0464 * _rtB -> g123hlbqqb
; { uint32_T iLeftU0 , iRghtU0 , iLeftU1 , iRghtU1 ;
HEV_acc_BINARYSEARCH_real_T ( & ( iLeftU0 ) , & ( iRghtU0 ) , _rtB ->
ptlppe1ifn , ni220kbneq . c4qvyaa1p5 , 108U ) ; if ( _rtB -> pw2tl3utlu <=
0.0 ) { iLeftU1 = 0U ; iRghtU1 = 0U ; } else if ( _rtB -> pw2tl3utlu >=
6000.0 ) { iLeftU1 = 100U ; iRghtU1 = 100U ; } else { iLeftU1 = ( uint32_T )
( ( _rtB -> pw2tl3utlu ) / 60.0 ) ; iRghtU1 = iLeftU1 + 1 ; } { real_T yTemp
; real_T u1Lambda ; real_T u0Lambda ; if ( iLeftU1 != iRghtU1 ) { { real_T
num = ( real_T ) ( _rtB -> pw2tl3utlu ) - ( iLeftU1 * 60.0 ) ; u1Lambda = num
/ 60.0 ; } } else { u1Lambda = 0.0 ; } if ( ( ni220kbneq . c4qvyaa1p5 [
iRghtU0 ] ) > ( ni220kbneq . c4qvyaa1p5 [ iLeftU0 ] ) ) { real_T num ; real_T
den ; den = ( ni220kbneq . c4qvyaa1p5 [ iRghtU0 ] ) ; den -= ( ni220kbneq .
c4qvyaa1p5 [ iLeftU0 ] ) ; num = _rtB -> ptlppe1ifn ; num -= ( ni220kbneq .
c4qvyaa1p5 [ iLeftU0 ] ) ; u0Lambda = num / den ; } else { u0Lambda = 0.0 ; }
{ real_T yLeftCast ; real_T yRghtCast ; yLeftCast = ( ni220kbneq . eds5bo2ge0
[ ( iLeftU0 + 109U * iLeftU1 ) ] ) ; yRghtCast = ( ni220kbneq . eds5bo2ge0 [
( iLeftU0 + 109U * iRghtU1 ) ] ) ; yLeftCast += u1Lambda * ( yRghtCast -
yLeftCast ) ; gfnebsmhwv = yLeftCast ; } { real_T yLeftCast ; real_T
yRghtCast ; yLeftCast = ( ni220kbneq . eds5bo2ge0 [ ( iRghtU0 + 109U *
iLeftU1 ) ] ) ; yRghtCast = ( ni220kbneq . eds5bo2ge0 [ ( iRghtU0 + 109U *
iRghtU1 ) ] ) ; yLeftCast += u1Lambda * ( yRghtCast - yLeftCast ) ; yTemp =
yLeftCast ; } { real_T yLeftCast ; real_T yRghtCast ; yLeftCast = gfnebsmhwv
; yRghtCast = yTemp ; yLeftCast += u0Lambda * ( yRghtCast - yLeftCast ) ;
gfnebsmhwv = yLeftCast ; } } } _rtB -> mjdaz1dfbc = 1.0351048413332149 *
gfnebsmhwv ; _rtB -> dvrnjuhxq0 = _rtB -> p34el342ry * _rtB -> mjdaz1dfbc ;
_rtB -> b5vmom5wxn = _rtB -> dvrnjuhxq0 * _rtB -> jhlhkn2bro ; _rtB ->
bmi1gwmfom = 1.933764640184292E-6 * _rtB -> b5vmom5wxn ; _rtB -> eudz2caljm =
_rtB -> jvrzworo0h * _rtB -> ib5hrgd3aj ; if ( _rtB -> beud2e32er <= 0.02 ) {
_rtB -> aejzfi3sed = 0.02 ; } else { _rtB -> aejzfi3sed = _rtB -> beud2e32er
; } _rtB -> kmvpngafr2 = ( ( 0.0 - _rtB -> bmi1gwmfom ) - _rtB -> mcmpwax5wu
) - _rtB -> eudz2caljm ; _rtB -> o1u0b0eaee = 1.0 / _rtB -> aejzfi3sed * _rtB
-> kmvpngafr2 ; _rtB -> c10yhy4jg5 = _rtB -> mv0scjuozy + _rtB -> cwuinypz5p
; _rtB -> nwxcavrw13 = ( _rtB -> c10yhy4jg5 - _rtB -> jdx1oh4myt ) -
ld5zvvrfqt ( S ) -> oapjufkr55 ; _rtB -> hlud4d2vcm = 0.00075471698113207543
* _rtB -> nwxcavrw13 ; _rtB -> gj0g1zwoni = muDoubleScalarAbs ( _rtB ->
chkwevbcym ) ; if ( ( _rtDW -> cgi523usaj >= ssGetT ( S ) ) && ( _rtDW ->
irt5havirw >= ssGetT ( S ) ) ) { _rtB -> bxq5xvdikw = 0.0 ; } else {
byehzqrbel = _rtDW -> cgi523usaj ; lastU = & _rtDW -> edrzze2flm ; if ( _rtDW
-> cgi523usaj < _rtDW -> irt5havirw ) { if ( _rtDW -> irt5havirw < ssGetT ( S
) ) { byehzqrbel = _rtDW -> irt5havirw ; lastU = & _rtDW -> gljjadsfzv ; } }
else { if ( _rtDW -> cgi523usaj >= ssGetT ( S ) ) { byehzqrbel = _rtDW ->
irt5havirw ; lastU = & _rtDW -> gljjadsfzv ; } } _rtB -> bxq5xvdikw = ( _rtB
-> eqtatbfsoc - * lastU ) / ( ssGetT ( S ) - byehzqrbel ) ; } _rtB ->
j45ecso0xc = muDoubleScalarAbs ( _rtB -> iyq5z5g4dk ) ; _rtB -> dalnffdjau =
1.093 * _rtB -> j45ecso0xc ; _rtB -> nzwvbjtqss = 1.0464 * _rtB -> eqtatbfsoc
; { uint32_T iLeftU0 , iRghtU0 , iLeftU1 , iRghtU1 ;
HEV_acc_BINARYSEARCH_real_T ( & ( iLeftU0 ) , & ( iRghtU0 ) , _rtB ->
dalnffdjau , ni220kbneq . c4qvyaa1p5 , 108U ) ; if ( _rtB -> nzwvbjtqss <=
0.0 ) { iLeftU1 = 0U ; iRghtU1 = 0U ; } else if ( _rtB -> nzwvbjtqss >=
6000.0 ) { iLeftU1 = 100U ; iRghtU1 = 100U ; } else { iLeftU1 = ( uint32_T )
( ( _rtB -> nzwvbjtqss ) / 60.0 ) ; iRghtU1 = iLeftU1 + 1 ; } { real_T yTemp
; real_T u1Lambda ; real_T u0Lambda ; if ( iLeftU1 != iRghtU1 ) { { real_T
num = ( real_T ) ( _rtB -> nzwvbjtqss ) - ( iLeftU1 * 60.0 ) ; u1Lambda = num
/ 60.0 ; } } else { u1Lambda = 0.0 ; } if ( ( ni220kbneq . c4qvyaa1p5 [
iRghtU0 ] ) > ( ni220kbneq . c4qvyaa1p5 [ iLeftU0 ] ) ) { real_T num ; real_T
den ; den = ( ni220kbneq . c4qvyaa1p5 [ iRghtU0 ] ) ; den -= ( ni220kbneq .
c4qvyaa1p5 [ iLeftU0 ] ) ; num = _rtB -> dalnffdjau ; num -= ( ni220kbneq .
c4qvyaa1p5 [ iLeftU0 ] ) ; u0Lambda = num / den ; } else { u0Lambda = 0.0 ; }
{ real_T yLeftCast ; real_T yRghtCast ; yLeftCast = ( ni220kbneq . dca3iiaooc
[ ( iLeftU0 + 109U * iLeftU1 ) ] ) ; yRghtCast = ( ni220kbneq . dca3iiaooc [
( iLeftU0 + 109U * iRghtU1 ) ] ) ; yLeftCast += u1Lambda * ( yRghtCast -
yLeftCast ) ; ludevrgvrx = yLeftCast ; } { real_T yLeftCast ; real_T
yRghtCast ; yLeftCast = ( ni220kbneq . dca3iiaooc [ ( iRghtU0 + 109U *
iLeftU1 ) ] ) ; yRghtCast = ( ni220kbneq . dca3iiaooc [ ( iRghtU0 + 109U *
iRghtU1 ) ] ) ; yLeftCast += u1Lambda * ( yRghtCast - yLeftCast ) ; yTemp =
yLeftCast ; } { real_T yLeftCast ; real_T yRghtCast ; yLeftCast = ludevrgvrx
; yRghtCast = yTemp ; yLeftCast += u0Lambda * ( yRghtCast - yLeftCast ) ;
ludevrgvrx = yLeftCast ; } } } _rtB -> atdqjfwiuq = 1.0351048413332149 *
ludevrgvrx ; _rtB -> p4couh5qkh = 1.933764640184292E-6 * _rtB -> atdqjfwiuq ;
_rtB -> et04u5jyil = muDoubleScalarSign ( _rtB -> iyq5z5g4dk ) ; _rtB ->
bvzmclvrtm = muDoubleScalarAbs ( _rtB -> iyq5z5g4dk ) ; _rtB -> pfrgh32csb =
1.093 * _rtB -> bvzmclvrtm ; _rtB -> hx2xopo0cd = 1.0464 * _rtB -> eqtatbfsoc
; { uint32_T iLeftU0 , iRghtU0 , iLeftU1 , iRghtU1 ;
HEV_acc_BINARYSEARCH_real_T ( & ( iLeftU0 ) , & ( iRghtU0 ) , _rtB ->
pfrgh32csb , ni220kbneq . c4qvyaa1p5 , 108U ) ; if ( _rtB -> hx2xopo0cd <=
0.0 ) { iLeftU1 = 0U ; iRghtU1 = 0U ; } else if ( _rtB -> hx2xopo0cd >=
6000.0 ) { iLeftU1 = 100U ; iRghtU1 = 100U ; } else { iLeftU1 = ( uint32_T )
( ( _rtB -> hx2xopo0cd ) / 60.0 ) ; iRghtU1 = iLeftU1 + 1 ; } { real_T yTemp
; real_T u1Lambda ; real_T u0Lambda ; if ( iLeftU1 != iRghtU1 ) { { real_T
num = ( real_T ) ( _rtB -> hx2xopo0cd ) - ( iLeftU1 * 60.0 ) ; u1Lambda = num
/ 60.0 ; } } else { u1Lambda = 0.0 ; } if ( ( ni220kbneq . c4qvyaa1p5 [
iRghtU0 ] ) > ( ni220kbneq . c4qvyaa1p5 [ iLeftU0 ] ) ) { real_T num ; real_T
den ; den = ( ni220kbneq . c4qvyaa1p5 [ iRghtU0 ] ) ; den -= ( ni220kbneq .
c4qvyaa1p5 [ iLeftU0 ] ) ; num = _rtB -> pfrgh32csb ; num -= ( ni220kbneq .
c4qvyaa1p5 [ iLeftU0 ] ) ; u0Lambda = num / den ; } else { u0Lambda = 0.0 ; }
{ real_T yLeftCast ; real_T yRghtCast ; yLeftCast = ( ni220kbneq . eds5bo2ge0
[ ( iLeftU0 + 109U * iLeftU1 ) ] ) ; yRghtCast = ( ni220kbneq . eds5bo2ge0 [
( iLeftU0 + 109U * iRghtU1 ) ] ) ; yLeftCast += u1Lambda * ( yRghtCast -
yLeftCast ) ; htsyt1c0no = yLeftCast ; } { real_T yLeftCast ; real_T
yRghtCast ; yLeftCast = ( ni220kbneq . eds5bo2ge0 [ ( iRghtU0 + 109U *
iLeftU1 ) ] ) ; yRghtCast = ( ni220kbneq . eds5bo2ge0 [ ( iRghtU0 + 109U *
iRghtU1 ) ] ) ; yLeftCast += u1Lambda * ( yRghtCast - yLeftCast ) ; yTemp =
yLeftCast ; } { real_T yLeftCast ; real_T yRghtCast ; yLeftCast = htsyt1c0no
; yRghtCast = yTemp ; yLeftCast += u0Lambda * ( yRghtCast - yLeftCast ) ;
htsyt1c0no = yLeftCast ; } } } _rtB -> buucgoatng = 1.0351048413332149 *
htsyt1c0no ; _rtB -> pm0xi4xhc2 = _rtB -> et04u5jyil * _rtB -> buucgoatng ;
_rtB -> g5hcl41rwe = _rtB -> pm0xi4xhc2 * _rtB -> bxq5xvdikw ; _rtB ->
gz2tncshzk = 1.933764640184292E-6 * _rtB -> g5hcl41rwe ; _rtB -> hfvvibzkie =
_rtB -> gj0g1zwoni * _rtB -> iyq5z5g4dk ; if ( _rtB -> p4couh5qkh <= 0.02 ) {
_rtB -> mggpdszlz1 = 0.02 ; } else { _rtB -> mggpdszlz1 = _rtB -> p4couh5qkh
; } _rtB -> oi0tsimr55 = ( ( 0.0 - _rtB -> gz2tncshzk ) - _rtB -> pv0hkzonpw
) - _rtB -> hfvvibzkie ; _rtB -> c1byakqa41 = 1.0 / _rtB -> mggpdszlz1 * _rtB
-> oi0tsimr55 ; ssCallAccelRunBlock ( S , 16 , 972 , SS_CALL_MDL_OUTPUTS ) ;
_rtB -> npqw2hqsht = _rtB -> m2y1khvsri [ 9 ] * _rtB -> il4mgadolv [ 2 ] ;
_rtB -> boctzwx3r2 = _rtB -> il4mgadolv [ 3 ] * _rtB -> m2y1khvsri [ 6 ] ;
_rtB -> fez00ly5gv = _rtB -> m2y1khvsri [ 8 ] * _rtB -> il4mgadolv [ 11 ] ;
_rtB -> lvjrio3qws = _rtB -> boctzwx3r2 + _rtB -> fez00ly5gv ;
ssCallAccelRunBlock ( S , 16 , 1020 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 16 , 1021 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 16 , 1022 , SS_CALL_MDL_OUTPUTS ) ;
UNUSED_PARAMETER ( tid ) ; }
#define MDL_UPDATE
static void mdlUpdate ( SimStruct * S , int_T tid ) { real_T * lastU ;
fdj1laa40s * _rtB ; h04hj5x5sk * _rtDW ; _rtDW = ( ( h04hj5x5sk * )
ssGetRootDWork ( S ) ) ; _rtB = ( ( fdj1laa40s * ) _ssGetBlockIO ( S ) ) ; if
( ssIsSampleHit ( S , 2 , 0 ) ) { _rtDW -> epw20ibixm += 6.0E-5 * _rtB ->
ivk531rbyj ; _rtDW -> emjtqjwqij += 6.0E-5 * _rtB -> nz3cfakluj ; _rtDW ->
aekc0mbj0y += 6.0E-5 * _rtB -> ptlcfubn2y ; _rtDW -> oi2n4lur1q += 6.0E-5 *
_rtB -> hwgpv13xpn ; _rtDW -> jnhtlxaxxk = _rtB -> acoi1pgdho ; } if (
ssIsSampleHit ( S , 2 , 0 ) ) { _rtDW -> eaosag5owj += 6.0E-5 * _rtB ->
m2y1khvsri [ 7 ] ; _rtDW -> jcugjk0yp0 += 6.0E-5 * _rtB -> j5h1g1a2gl ; _rtDW
-> jly33pdwub += 6.0E-5 * _rtB -> jdjzldp1u3 ; _rtDW -> f2z5i2ds5e = _rtB ->
aibll5qkty [ 33 ] - - 0.999994000018 * _rtDW -> f2z5i2ds5e ; } if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtDW -> b50c0wk1dc = _rtB -> cqyvcf4dzn ; }
if ( ssIsSampleHit ( S , 2 , 0 ) ) { _rtDW -> o05rwe50bo = 0U ; _rtDW ->
pk42w2cjcz += 6.0E-5 * _rtB -> aibll5qkty [ 33 ] ; if ( _rtDW -> pk42w2cjcz
>= 25200.0 ) { _rtDW -> pk42w2cjcz = 25200.0 ; } else { if ( _rtDW ->
pk42w2cjcz <= rtMinusInf ) { _rtDW -> pk42w2cjcz = rtMinusInf ; } } if ( _rtB
-> nzg45ejzyh > 0.0 ) { _rtDW -> f0fxu4veqt = 1 ; } else if ( _rtB ->
nzg45ejzyh < 0.0 ) { _rtDW -> f0fxu4veqt = - 1 ; } else if ( _rtB ->
nzg45ejzyh == 0.0 ) { _rtDW -> f0fxu4veqt = 0 ; } else { _rtDW -> f0fxu4veqt
= 2 ; } _rtDW -> fezg0yhyh2 = _rtB -> aibll5qkty [ 19 ] ; _rtDW -> hdqerfit1p
[ 0 ] = _rtB -> aibll5qkty [ 35 ] ; _rtDW -> hdqerfit1p [ 1 ] = _rtB ->
aibll5qkty [ 36 ] ; _rtDW -> hdqerfit1p [ 2 ] = _rtB -> aibll5qkty [ 37 ] ; }
if ( _rtDW -> mg242c3vwq == ( rtInf ) ) { _rtDW -> mg242c3vwq = ssGetTaskTime
( S , 0 ) ; _rtDW -> oiqwpboxgd = _rtB -> ffl5hinbtg ; } else if ( _rtDW ->
k1wt3kvmem == ( rtInf ) ) { _rtDW -> k1wt3kvmem = ssGetTaskTime ( S , 0 ) ;
_rtDW -> lzjsh0qxsz = _rtB -> ffl5hinbtg ; } else if ( _rtDW -> mg242c3vwq <
_rtDW -> k1wt3kvmem ) { _rtDW -> mg242c3vwq = ssGetTaskTime ( S , 0 ) ; _rtDW
-> oiqwpboxgd = _rtB -> ffl5hinbtg ; } else { _rtDW -> k1wt3kvmem =
ssGetTaskTime ( S , 0 ) ; _rtDW -> lzjsh0qxsz = _rtB -> ffl5hinbtg ; } if (
_rtDW -> cwivfg5ijd == ( rtInf ) ) { _rtDW -> cwivfg5ijd = ssGetTaskTime ( S
, 0 ) ; _rtDW -> kguctqvwvn = _rtB -> p1oacvuoap ; } else if ( _rtDW ->
m1iuzueluk == ( rtInf ) ) { _rtDW -> m1iuzueluk = ssGetTaskTime ( S , 0 ) ;
_rtDW -> bvl1znuobh = _rtB -> p1oacvuoap ; } else if ( _rtDW -> cwivfg5ijd <
_rtDW -> m1iuzueluk ) { _rtDW -> cwivfg5ijd = ssGetTaskTime ( S , 0 ) ; _rtDW
-> kguctqvwvn = _rtB -> p1oacvuoap ; } else { _rtDW -> m1iuzueluk =
ssGetTaskTime ( S , 0 ) ; _rtDW -> bvl1znuobh = _rtB -> p1oacvuoap ; } if (
ssIsSampleHit ( S , 2 , 0 ) ) { _rtDW -> bvad1zjfik = _rtB -> igiwwchpml [ 0
] ; } if ( _rtDW -> hfvh40s0je == ( rtInf ) ) { _rtDW -> hfvh40s0je =
ssGetTaskTime ( S , 0 ) ; _rtDW -> lidlmlim32 = _rtB -> hnfw3iptxu ; } else
if ( _rtDW -> f41a3yqptq == ( rtInf ) ) { _rtDW -> f41a3yqptq = ssGetTaskTime
( S , 0 ) ; _rtDW -> aq3qjo4ji4 = _rtB -> hnfw3iptxu ; } else if ( _rtDW ->
hfvh40s0je < _rtDW -> f41a3yqptq ) { _rtDW -> hfvh40s0je = ssGetTaskTime ( S
, 0 ) ; _rtDW -> lidlmlim32 = _rtB -> hnfw3iptxu ; } else { _rtDW ->
f41a3yqptq = ssGetTaskTime ( S , 0 ) ; _rtDW -> aq3qjo4ji4 = _rtB ->
hnfw3iptxu ; } if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtDW -> aln04uuynj =
_rtB -> hnfw3iptxu ; _rtDW -> nlh5qppt4m = _rtB -> fiujcjo4ly ; } if (
ssIsSampleHit ( S , 2 , 0 ) ) { _rtDW -> bro0cn1wmi = _rtB -> aibll5qkty [ 23
] ; _rtDW -> j31s1kcymk [ 0 ] = _rtB -> aibll5qkty [ 38 ] ; _rtDW ->
j31s1kcymk [ 1 ] = _rtB -> aibll5qkty [ 39 ] ; _rtDW -> j31s1kcymk [ 2 ] =
_rtB -> aibll5qkty [ 40 ] ; } if ( ssIsSampleHit ( S , 3 , 0 ) ) { _rtDW ->
gsr0ogd2xb = _rtB -> fpqhfdmsru ; } if ( _rtDW -> joiszbfghn == ( rtInf ) ) {
_rtDW -> joiszbfghn = ssGetTaskTime ( S , 0 ) ; _rtDW -> narm2z4h4g = _rtB ->
bwi32ct0dr ; } else if ( _rtDW -> jlnwqqs23l == ( rtInf ) ) { _rtDW ->
jlnwqqs23l = ssGetTaskTime ( S , 0 ) ; _rtDW -> miwjijsda1 = _rtB ->
bwi32ct0dr ; } else if ( _rtDW -> joiszbfghn < _rtDW -> jlnwqqs23l ) { _rtDW
-> joiszbfghn = ssGetTaskTime ( S , 0 ) ; _rtDW -> narm2z4h4g = _rtB ->
bwi32ct0dr ; } else { _rtDW -> jlnwqqs23l = ssGetTaskTime ( S , 0 ) ; _rtDW
-> miwjijsda1 = _rtB -> bwi32ct0dr ; } if ( ssIsSampleHit ( S , 2 , 0 ) ) {
_rtDW -> kzrq2xyp0f = _rtB -> fzfj2bbqis ; _rtDW -> nonllthbl2 = _rtB ->
p3bo2y3kw5 - - 0.94176453358424872 * _rtDW -> nonllthbl2 ; _rtDW ->
kol45dq53x = _rtB -> lkkzfx3t03 - - 0.94176453358424872 * _rtDW -> kol45dq53x
; _rtDW -> fw2k5vojpd = _rtB -> gge1siyfxe ; _rtDW -> ehaijafsot = _rtB ->
aibll5qkty [ 19 ] ; _rtDW -> lvw3lta2fy = _rtB -> htg4ufwc50 - -
0.94176453358424872 * _rtDW -> lvw3lta2fy ; _rtDW -> c20b4oc1jp = _rtB ->
dvubszjv5v - - 0.94176453358424872 * _rtDW -> c20b4oc1jp ; _rtDW ->
lp13v2ihui = _rtB -> kqhibdmrst ; _rtDW -> kopxzfb0sb = _rtB -> aibll5qkty [
23 ] ; _rtDW -> ebwur5qeqq = _rtB -> daw1svm0il ; ssCallAccelRunBlock ( S ,
16 , 493 , SS_CALL_MDL_UPDATE ) ; } if ( _rtDW -> n33aen2wbt == ( rtInf ) ) {
_rtDW -> n33aen2wbt = ssGetTaskTime ( S , 0 ) ; _rtDW -> evmu5j4txb = _rtB ->
c0tqxoxafw ; } else if ( _rtDW -> fjojh4ewqs == ( rtInf ) ) { _rtDW ->
fjojh4ewqs = ssGetTaskTime ( S , 0 ) ; _rtDW -> d21ysphefx = _rtB ->
c0tqxoxafw ; } else if ( _rtDW -> n33aen2wbt < _rtDW -> fjojh4ewqs ) { _rtDW
-> n33aen2wbt = ssGetTaskTime ( S , 0 ) ; _rtDW -> evmu5j4txb = _rtB ->
c0tqxoxafw ; } else { _rtDW -> fjojh4ewqs = ssGetTaskTime ( S , 0 ) ; _rtDW
-> d21ysphefx = _rtB -> c0tqxoxafw ; } if ( _rtDW -> nolj4flzwb == ( rtInf )
) { _rtDW -> nolj4flzwb = ssGetTaskTime ( S , 0 ) ; _rtDW -> ppmw3hzciy =
_rtB -> l1qrn1jl2e ; } else if ( _rtDW -> bluedlz4ee == ( rtInf ) ) { _rtDW
-> bluedlz4ee = ssGetTaskTime ( S , 0 ) ; _rtDW -> awi4nxie0m = _rtB ->
l1qrn1jl2e ; } else if ( _rtDW -> nolj4flzwb < _rtDW -> bluedlz4ee ) { _rtDW
-> nolj4flzwb = ssGetTaskTime ( S , 0 ) ; _rtDW -> ppmw3hzciy = _rtB ->
l1qrn1jl2e ; } else { _rtDW -> bluedlz4ee = ssGetTaskTime ( S , 0 ) ; _rtDW
-> awi4nxie0m = _rtB -> l1qrn1jl2e ; } if ( ssIsSampleHit ( S , 3 , 0 ) ) {
_rtDW -> bv5gvrfela = _rtB -> oecxc3muyp ; } if ( ssIsSampleHit ( S , 2 , 0 )
) { _rtDW -> pe31gvq3pv = _rtB -> pgpl5aw1mw - - 0.98651999976973315 * _rtDW
-> pe31gvq3pv ; _rtDW -> bw5cwo255x = _rtB -> kktx4eqlpq - -
0.98651999976973315 * _rtDW -> bw5cwo255x ; _rtDW -> l2t4rgxmml = _rtB ->
g33hibypbt [ 0 ] ; } if ( ssIsSampleHit ( S , 2 , 0 ) ) { _rtDW -> dy4ppyw4mo
= _rtB -> n1gbyberwg - - 0.98651999976973315 * _rtDW -> dy4ppyw4mo ; _rtDW ->
hmybg5b1mi = _rtB -> jxjfrhnnrc - - 0.98651999976973315 * _rtDW -> hmybg5b1mi
; _rtDW -> gkq12xkctn = _rtB -> noc4c0qkjo [ 0 ] ; _rtDW -> llu3sg1ihp = 0U ;
_rtDW -> fj2gixcnhk = 3.0E-5 * _rtB -> c3esxbsqjj + _rtB -> pabbygan1q ; if (
_rtDW -> fj2gixcnhk >= 1.0 ) { _rtDW -> fj2gixcnhk = 1.0 ; } else { if (
_rtDW -> fj2gixcnhk <= - 1.0 ) { _rtDW -> fj2gixcnhk = - 1.0 ; } } _rtDW ->
dco4afubi3 = _rtB -> e4m3b3l42x ; } if ( _rtDW -> ewhcynzuun == ( rtInf ) ) {
_rtDW -> ewhcynzuun = ssGetTaskTime ( S , 0 ) ; _rtDW -> h4ipbzntlo = _rtB ->
bso0xqecj4 ; } else if ( _rtDW -> ciu3b0lpet == ( rtInf ) ) { _rtDW ->
ciu3b0lpet = ssGetTaskTime ( S , 0 ) ; _rtDW -> mmlyeyihwy = _rtB ->
bso0xqecj4 ; } else if ( _rtDW -> ewhcynzuun < _rtDW -> ciu3b0lpet ) { _rtDW
-> ewhcynzuun = ssGetTaskTime ( S , 0 ) ; _rtDW -> h4ipbzntlo = _rtB ->
bso0xqecj4 ; } else { _rtDW -> ciu3b0lpet = ssGetTaskTime ( S , 0 ) ; _rtDW
-> mmlyeyihwy = _rtB -> bso0xqecj4 ; } if ( ssIsSampleHit ( S , 2 , 0 ) ) {
_rtDW -> jctbfc4f1e = _rtB -> gxqfziopir - - 0.96300265339697488 * _rtDW ->
jctbfc4f1e ; _rtDW -> h4pa1qmmy5 = 0U ; _rtDW -> olv3cnxtoy = 3.0E-5 * _rtB
-> ehm05itqhc + _rtB -> d0eztedmuw ; if ( _rtDW -> olv3cnxtoy >= 1.0 ) {
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
nlkba1lokv = _rtB -> jvnivwhexw ; _rtXdot -> eackaa2e5o = _rtB -> c1byakqa41
; _rtXdot -> a3p154yttn = _rtB -> hlud4d2vcm ; _rtXdot -> lvhb24m1u3 [ 0 ] =
0.0 ; _rtXdot -> lvhb24m1u3 [ 1 ] = 0.0 ; _rtXdot -> lvhb24m1u3 [ 0 ] += -
20.106192982974676 * _rtX -> lvhb24m1u3 [ 0 ] ; _rtXdot -> lvhb24m1u3 [ 0 ]
+= - 157.91367041742973 * _rtX -> lvhb24m1u3 [ 1 ] ; _rtXdot -> lvhb24m1u3 [
1 ] += _rtX -> lvhb24m1u3 [ 0 ] ; _rtXdot -> lvhb24m1u3 [ 0 ] += _rtB ->
nwxcavrw13 ; _rtXdot -> oiuvfykmtf = _rtB -> o1u0b0eaee ; _rtXdot ->
pi4mr5hhgl = _rtB -> ik1quccdcq ; _rtXdot -> bjc4xqhn0t = _rtB -> jiuie0tfic
; _rtXdot -> oy1vxpvao1 = _rtB -> otp4c53e0a ; _rtXdot -> iglmayn3zq = _rtB
-> gwhokqj4dv ; _rtXdot -> p24x5vnk3x = _rtB -> lasykkrzbv ; _rtXdot ->
jntxheunx4 = _rtB -> fc1o4q5r0w ; _rtXdot -> ix50zu3rlz = 0.0 ; _rtXdot ->
ix50zu3rlz += - 125.66370614359172 * _rtX -> ix50zu3rlz ; _rtXdot ->
ix50zu3rlz += _rtB -> otp4c53e0a ; { boolean_T lsat ; boolean_T usat ; lsat =
( ( ( hgl3elxkcb * ) ssGetContStates ( S ) ) -> f0udlm3lxk <= ( - 5.0 ) ) ;
usat = ( ( ( hgl3elxkcb * ) ssGetContStates ( S ) ) -> f0udlm3lxk >= 5.0 ) ;
if ( ( ! lsat && ! usat ) || ( lsat && ( _rtB -> nktcz1jlg1 > 0 ) ) || ( usat
&& ( _rtB -> nktcz1jlg1 < 0 ) ) ) { ( ( aab5tqo4s5 * ) ssGetdX ( S ) ) ->
f0udlm3lxk = _rtB -> nktcz1jlg1 ; } else { ( ( aab5tqo4s5 * ) ssGetdX ( S ) )
-> f0udlm3lxk = 0.0 ; } } }
#define MDL_PROJECTION
static void mdlProjection ( SimStruct * S ) { fdj1laa40s * _rtB ; h04hj5x5sk
* _rtDW ; _rtDW = ( ( h04hj5x5sk * ) ssGetRootDWork ( S ) ) ; _rtB = ( (
fdj1laa40s * ) _ssGetBlockIO ( S ) ) ; ssCallAccelRunBlock ( S , 16 , 30 ,
SS_CALL_MDL_PROJECTION ) ; } static void mdlInitializeSizes ( SimStruct * S )
{ ssSetChecksumVal ( S , 0 , 4214113643U ) ; ssSetChecksumVal ( S , 1 ,
2246669955U ) ; ssSetChecksumVal ( S , 2 , 1385471575U ) ; ssSetChecksumVal (
S , 3 , 573617845U ) ; { mxArray * slVerStructMat = NULL ; mxArray * slStrMat
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
