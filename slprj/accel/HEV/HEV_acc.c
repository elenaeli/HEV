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
nzpvluxqo1 ; real_T bypkl1sbku ; real_T dinenyqhbn ; real_T jwhxrwpoow ;
real_T dgero0mtoj ; real_T chrjv2ws5i ; real_T c0prckfmta ; real_T nl0syzv5zt
; real_T g1lvj1hvai ; boolean_T ld5p5vfhmu ; int32_T rowIdx ; real_T * lastU
; boolean_T o3khhk3fbg ; uint8_T h100jbae3x ; real_T iiis24gb3o ; real_T
jwhz1ujp3w ; real_T ehtkh2wauy ; real_T mkcfwi2fsi ; real_T ehcygfucdl ;
real_T po0ockmy2b ; real_T mizlp41tvx ; real_T f4ufgq33gz ; real_T i5nu34w4uj
; real_T dztyrqu4xa ; real_T eskeehll14 ; real_T ckrl0nmlwt ; real_T
lduwq00gqj ; real_T byehzqrbel ; boolean_T fviymzl3aa ; real_T j0jhyqa1p3 ;
real_T aqlslovppe ; real_T dyfxp2slod ; real_T dk4tk42hhp ; real_T ctpq3axefx
; real_T f1b5simhxh ; real_T lstej3qx0u ; real_T h0cg4jnrg5 ; real_T
lfv3m5pb5c ; real_T f2e3v5ccex ; real_T lebvfutt11 ; real_T lvh3r5z3vn_idx_0
; real_T lvh3r5z3vn_idx_1 ; real_T lvh3r5z3vn_idx_2 ; ZCEventType
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
iLeftU0 ) , & ( iRghtU0 ) , _rtB -> g013xtkmbh , ni220kbneq . hlsjpbjuty ,
108U ) ; if ( _rtB -> p3144ypepf <= 0.0 ) { iLeftU1 = 0U ; iRghtU1 = 0U ; }
else if ( _rtB -> p3144ypepf >= 6000.0 ) { iLeftU1 = 100U ; iRghtU1 = 100U ;
} else { iLeftU1 = ( uint32_T ) ( ( _rtB -> p3144ypepf ) / 60.0 ) ; iRghtU1 =
iLeftU1 + 1 ; } { real_T yTemp ; real_T u1Lambda ; real_T u0Lambda ; if (
iLeftU1 != iRghtU1 ) { { real_T num = ( real_T ) ( _rtB -> p3144ypepf ) - (
iLeftU1 * 60.0 ) ; u1Lambda = num / 60.0 ; } } else { u1Lambda = 0.0 ; } if (
( ni220kbneq . hlsjpbjuty [ iRghtU0 ] ) > ( ni220kbneq . hlsjpbjuty [ iLeftU0
] ) ) { real_T num ; real_T den ; den = ( ni220kbneq . hlsjpbjuty [ iRghtU0 ]
) ; den -= ( ni220kbneq . hlsjpbjuty [ iLeftU0 ] ) ; num = _rtB -> g013xtkmbh
; num -= ( ni220kbneq . hlsjpbjuty [ iLeftU0 ] ) ; u0Lambda = num / den ; }
else { u0Lambda = 0.0 ; } { real_T yLeftCast ; real_T yRghtCast ; yLeftCast =
( ni220kbneq . bhvyvhymk2 [ ( iLeftU0 + 109U * iLeftU1 ) ] ) ; yRghtCast = (
ni220kbneq . bhvyvhymk2 [ ( iLeftU0 + 109U * iRghtU1 ) ] ) ; yLeftCast +=
u1Lambda * ( yRghtCast - yLeftCast ) ; fepbibcdbq = yLeftCast ; } { real_T
yLeftCast ; real_T yRghtCast ; yLeftCast = ( ni220kbneq . bhvyvhymk2 [ (
iRghtU0 + 109U * iLeftU1 ) ] ) ; yRghtCast = ( ni220kbneq . bhvyvhymk2 [ (
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
iLeftU0 ) , & ( iRghtU0 ) , _rtB -> jla0sqmgz1 , ni220kbneq . hlsjpbjuty ,
108U ) ; if ( _rtB -> gy3qknpzse <= 0.0 ) { iLeftU1 = 0U ; iRghtU1 = 0U ; }
else if ( _rtB -> gy3qknpzse >= 6000.0 ) { iLeftU1 = 100U ; iRghtU1 = 100U ;
} else { iLeftU1 = ( uint32_T ) ( ( _rtB -> gy3qknpzse ) / 60.0 ) ; iRghtU1 =
iLeftU1 + 1 ; } { real_T yTemp ; real_T u1Lambda ; real_T u0Lambda ; if (
iLeftU1 != iRghtU1 ) { { real_T num = ( real_T ) ( _rtB -> gy3qknpzse ) - (
iLeftU1 * 60.0 ) ; u1Lambda = num / 60.0 ; } } else { u1Lambda = 0.0 ; } if (
( ni220kbneq . hlsjpbjuty [ iRghtU0 ] ) > ( ni220kbneq . hlsjpbjuty [ iLeftU0
] ) ) { real_T num ; real_T den ; den = ( ni220kbneq . hlsjpbjuty [ iRghtU0 ]
) ; den -= ( ni220kbneq . hlsjpbjuty [ iLeftU0 ] ) ; num = _rtB -> jla0sqmgz1
; num -= ( ni220kbneq . hlsjpbjuty [ iLeftU0 ] ) ; u0Lambda = num / den ; }
else { u0Lambda = 0.0 ; } { real_T yLeftCast ; real_T yRghtCast ; yLeftCast =
( ni220kbneq . bhvyvhymk2 [ ( iLeftU0 + 109U * iLeftU1 ) ] ) ; yRghtCast = (
ni220kbneq . bhvyvhymk2 [ ( iLeftU0 + 109U * iRghtU1 ) ] ) ; yLeftCast +=
u1Lambda * ( yRghtCast - yLeftCast ) ; nzpvluxqo1 = yLeftCast ; } { real_T
yLeftCast ; real_T yRghtCast ; yLeftCast = ( ni220kbneq . bhvyvhymk2 [ (
iRghtU0 + 109U * iLeftU1 ) ] ) ; yRghtCast = ( ni220kbneq . bhvyvhymk2 [ (
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
uint8_T ) ( _rtB -> jkneh55zyo > ld5zvvrfqt ( S ) -> kridhzpqfr ) ; _rtB ->
kvnqgaladt = 9.5492965855137211 * _rtB -> jkneh55zyo ; if ( ( _rtB ->
kvnqgaladt > ld5zvvrfqt ( S ) -> d5wvj2kdmb ) && ( _rtB -> kvnqgaladt <
ld5zvvrfqt ( S ) -> n2vfo2vrru ) ) { _rtB -> fauxe3m13g = ld5zvvrfqt ( S ) ->
evxfoz4vu2 ; } else { _rtB -> fauxe3m13g = _rtB -> kvnqgaladt ; } if (
ssIsSampleHit ( S , 1 , 0 ) ) { if ( ssIsSampleHit ( S , 2 , 0 ) ) { _rtB ->
kdbapz55x4 = _rtDW -> jnhtlxaxxk ; } if ( _rtB -> kdbapz55x4 > 1.0 ) { _rtB
-> buxtah014k = 1.0 ; } else if ( _rtB -> kdbapz55x4 < 0.0 ) { _rtB ->
buxtah014k = 0.0 ; } else { _rtB -> buxtah014k = _rtB -> kdbapz55x4 ; } } if
( h100jbae3x >= 1 ) { _rtB -> ptsgpigbyk = ld5zvvrfqt ( S ) -> jpwtxo3hpd ; }
else { _rtB -> mdkqtu35rx = rt_Lookup ( ni220kbneq . jqglboln4v , 101 , _rtB
-> fauxe3m13g , ni220kbneq . i2vn1liwwa ) * _rtB -> buxtah014k ; if ( _rtB ->
mdkqtu35rx > 136.0757 ) { _rtB -> lyt0ccqovt = 136.0757 ; } else if ( _rtB ->
mdkqtu35rx < 0.0 ) { _rtB -> lyt0ccqovt = 0.0 ; } else { _rtB -> lyt0ccqovt =
_rtB -> mdkqtu35rx ; } _rtB -> ptsgpigbyk = _rtB -> lyt0ccqovt ; } _rtB ->
chzfalc2ug = - _rtB -> f42rmc3fdw ; _rtB -> dobt0vhlkj [ 0 ] = _rtB ->
f42rmc3fdw ; _rtB -> dobt0vhlkj [ 1 ] = _rtB -> lt41u3p0z3 ; _rtB ->
dobt0vhlkj [ 2 ] = _rtB -> oac35s35vw ; _rtB -> dobt0vhlkj [ 3 ] = _rtB ->
jv1hez3310 ; _rtB -> dobt0vhlkj [ 4 ] = _rtB -> hea4gjqawa ; _rtB ->
dobt0vhlkj [ 5 ] = _rtB -> cbttxcrlpy ; _rtB -> dobt0vhlkj [ 6 ] = _rtB ->
c1dd1abfch ; _rtB -> dobt0vhlkj [ 7 ] = _rtB -> ptsgpigbyk ; _rtB ->
dobt0vhlkj [ 8 ] = _rtB -> chzfalc2ug ; ssCallAccelRunBlock ( S , 16 , 187 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 16 , 188 ,
SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) {
ssCallAccelRunBlock ( S , 16 , 189 , SS_CALL_MDL_OUTPUTS ) ; } if ( ( _rtB ->
m2y1khvsri [ 11 ] > ld5zvvrfqt ( S ) -> cgz0vpmbrx ) && ( _rtB -> m2y1khvsri
[ 11 ] < ld5zvvrfqt ( S ) -> lyds3vjisi ) ) { _rtB -> jvdklob0se = ld5zvvrfqt
( S ) -> jqz4ph5fgm ; } else { _rtB -> jvdklob0se = _rtB -> m2y1khvsri [ 11 ]
; } ssCallAccelRunBlock ( S , 16 , 197 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
jll1misqee = 9.5492965854826952 * _rtB -> jvdklob0se ; _rtB -> lwfbwjlpyt =
_rtB -> jvdklob0se * _rtB -> gsc0pyt5qr [ 1 ] ; ssCallAccelRunBlock ( S , 16
, 200 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> ldtde1xbbx = _rtX -> pi4mr5hhgl ;
_rtB -> ghlslwhk3d = _rtX -> bjc4xqhn0t ; nl0syzv5zt = 1.0 / _rtB ->
ldtde1xbbx * _rtB -> ghlslwhk3d * 100.0 ; if ( nl0syzv5zt > 15.0 ) { _rtB ->
lwfbwjlpyt = 15.0 ; } else if ( nl0syzv5zt < 0.0 ) { _rtB -> lwfbwjlpyt = 0.0
; } else { _rtB -> lwfbwjlpyt = nl0syzv5zt ; }
HEV_acc_Look2D_real_T_real_T_real_T ( & ( _rtB -> j3bq5daw1x ) , ( (
baqezl5ja5 * ) ssGetDefaultParam ( S ) ) -> FuelConsTable . lookupTableFuel ,
_rtB -> jll1misqee , ( ( baqezl5ja5 * ) ssGetDefaultParam ( S ) ) ->
FuelConsTable . speed , 9U , _rtB -> gsc0pyt5qr [ 1 ] , ( ( baqezl5ja5 * )
ssGetDefaultParam ( S ) ) -> FuelConsTable . torque , 9U ) ;
HEV_acc_Look2D_real_T_real_T_real_T ( & ( _rtB -> jn2wa1f4jf ) , ( (
baqezl5ja5 * ) ssGetDefaultParam ( S ) ) -> GasEmisTable . lookupTableCO ,
_rtB -> jll1misqee , ( ( baqezl5ja5 * ) ssGetDefaultParam ( S ) ) ->
GasEmisTable . speed , 9U , _rtB -> gsc0pyt5qr [ 1 ] , ( ( baqezl5ja5 * )
ssGetDefaultParam ( S ) ) -> GasEmisTable . torque , 9U ) ;
HEV_acc_Look2D_real_T_real_T_real_T ( & ( _rtB -> iqazxwtowf ) , ( (
baqezl5ja5 * ) ssGetDefaultParam ( S ) ) -> GasEmisTable . lookupTableHC ,
_rtB -> jll1misqee , ( ( baqezl5ja5 * ) ssGetDefaultParam ( S ) ) ->
GasEmisTable . speed , 9U , _rtB -> gsc0pyt5qr [ 1 ] , ( ( baqezl5ja5 * )
ssGetDefaultParam ( S ) ) -> GasEmisTable . torque , 9U ) ;
HEV_acc_Look2D_real_T_real_T_real_T ( & ( _rtB -> e1dlbtwqho ) , ( (
baqezl5ja5 * ) ssGetDefaultParam ( S ) ) -> GasEmisTable . lookupTableNOX ,
_rtB -> jll1misqee , ( ( baqezl5ja5 * ) ssGetDefaultParam ( S ) ) ->
GasEmisTable . speed , 9U , _rtB -> gsc0pyt5qr [ 1 ] , ( ( baqezl5ja5 * )
ssGetDefaultParam ( S ) ) -> GasEmisTable . torque , 9U ) ;
ssCallAccelRunBlock ( S , 16 , 210 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 16 , 211 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 16 , 212 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
h55hpbactd = ! ( h100jbae3x != 0 ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) {
ssCallAccelRunBlock ( S , 16 , 214 , SS_CALL_MDL_OUTPUTS ) ; } _rtB ->
gh4h2ehrsg = _rtX -> oy1vxpvao1 ; nl0syzv5zt = ssGetT ( S ) ; _rtB ->
nyaqe33lbw = _rtB -> gh4h2ehrsg / nl0syzv5zt ; ssCallAccelRunBlock ( S , 16 ,
223 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> jqepcndq0g = _rtX -> iglmayn3zq ; _rtB
-> hmpiirraho = nl0syzv5zt * ld5zvvrfqt ( S ) -> pmssvqfyfg ; _rtB ->
nyaqe33lbw *= _rtB -> hmpiirraho ; nl0syzv5zt = _rtB -> jqepcndq0g / _rtB ->
nyaqe33lbw ; if ( nl0syzv5zt <= 0.0 ) { _rtB -> lvthxz35q2 = 0.0 ; } else {
_rtB -> lvthxz35q2 = nl0syzv5zt ; } ssCallAccelRunBlock ( S , 16 , 230 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 16 , 231 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> khkxgxnt14 = _rtX -> p24x5vnk3x ; nl0syzv5zt
= _rtB -> khkxgxnt14 / _rtB -> nyaqe33lbw ; if ( nl0syzv5zt <= 0.0 ) { _rtB
-> lvthxz35q2 = 0.0 ; } else { _rtB -> lvthxz35q2 = nl0syzv5zt ; }
ssCallAccelRunBlock ( S , 16 , 235 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
b43xavxzc1 = _rtX -> jntxheunx4 ; nl0syzv5zt = _rtB -> b43xavxzc1 / _rtB ->
nyaqe33lbw ; if ( nl0syzv5zt <= 0.0 ) { _rtB -> lvthxz35q2 = 0.0 ; } else {
_rtB -> lvthxz35q2 = nl0syzv5zt ; } ssCallAccelRunBlock ( S , 16 , 239 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 16 , 240 ,
SS_CALL_MDL_OUTPUTS ) ; if ( _rtB -> ghlslwhk3d <= 0.0 ) { h0cg4jnrg5 = 0.0 ;
} else { h0cg4jnrg5 = _rtB -> ghlslwhk3d ; } _rtB -> jjvw4j1avq = h0cg4jnrg5
+ ld5zvvrfqt ( S ) -> pvgn4kiugc ; ssCallAccelRunBlock ( S , 16 , 244 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 16 , 245 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> ouoax44l4j = 0.001 * _rtB -> j3bq5daw1x ;
_rtB -> d1tbpb0ikl = _rtB -> ouoax44l4j / ld5zvvrfqt ( S ) -> apxssuuhcc ;
_rtB -> cxf2psnneg = 3.6 * _rtB -> chkwevbcym ; if ( _rtB -> cxf2psnneg >
200.0 ) { _rtB -> mkg0mz45iy = 200.0 ; } else if ( _rtB -> cxf2psnneg < 0.0 )
{ _rtB -> mkg0mz45iy = 0.0 ; } else { _rtB -> mkg0mz45iy = _rtB -> cxf2psnneg
; } _rtB -> cwjl3j1x5k = 0.0002777777777778 * _rtB -> mkg0mz45iy ; _rtB ->
najtolxp1g = 1000.0 * _rtB -> d1tbpb0ikl ; ssCallAccelRunBlock ( S , 16 , 259
, SS_CALL_MDL_OUTPUTS ) ; _rtB -> j21fkdd52h = 0 ; ssCallAccelRunBlock ( S ,
16 , 280 , SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 16 , 281 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 16 , 282 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 16 , 283 ,
SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSampleHit ( S , 4 , 0 ) ) {
ssCallAccelRunBlock ( S , 16 , 284 , SS_CALL_MDL_OUTPUTS ) ; } _rtB ->
o4wgus3qw0 = 0.0 ; _rtB -> o4wgus3qw0 += 125.66370614359172 * _rtX ->
ix50zu3rlz ; ssCallAccelRunBlock ( S , 16 , 286 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 16 , 287 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
b4eqcq0xl3 = _rtB -> lvthxz35q2 - _rtB -> o4wgus3qw0 ; iiis24gb3o = 0.02 *
_rtB -> b4eqcq0xl3 ; if ( ( ( hgl3elxkcb * ) ssGetContStates ( S ) ) ->
f0udlm3lxk >= 5.0 ) { if ( ( ( hgl3elxkcb * ) ssGetContStates ( S ) ) ->
f0udlm3lxk != 5.0 ) { ( ( hgl3elxkcb * ) ssGetContStates ( S ) ) ->
f0udlm3lxk = 5.0 ; ssSetSolverNeedsReset ( S ) ; } } else if ( ( ( hgl3elxkcb
* ) ssGetContStates ( S ) ) -> f0udlm3lxk <= ( - 5.0 ) ) { if ( ( (
hgl3elxkcb * ) ssGetContStates ( S ) ) -> f0udlm3lxk != ( - 5.0 ) ) { ( (
hgl3elxkcb * ) ssGetContStates ( S ) ) -> f0udlm3lxk = ( - 5.0 ) ;
ssSetSolverNeedsReset ( S ) ; } } _rtB -> hb5owfyryy = ( ( hgl3elxkcb * )
ssGetContStates ( S ) ) -> f0udlm3lxk ; nl0syzv5zt = iiis24gb3o + _rtB ->
hb5owfyryy ; if ( nl0syzv5zt > 1.0 ) { _rtB -> i3qwusyalv = 1.0 ; } else if (
nl0syzv5zt < - 1.0 ) { _rtB -> i3qwusyalv = - 1.0 ; } else { _rtB ->
i3qwusyalv = nl0syzv5zt ; } ssCallAccelRunBlock ( S , 16 , 293 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 16 , 294 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> oodc01xuy0 = 0.04 * _rtB -> b4eqcq0xl3 ; if (
ssIsSampleHit ( S , 2 , 0 ) ) { jwhz1ujp3w = _rtDW -> eaosag5owj ; ehtkh2wauy
= muDoubleScalarSin ( _rtDW -> eaosag5owj ) ; mkcfwi2fsi = muDoubleScalarCos
( _rtDW -> eaosag5owj ) ; _rtB -> piiare0zhu = _rtB -> bw2nhi51td *
mkcfwi2fsi + _rtB -> gthgcz50sq * ehtkh2wauy ; _rtB -> pg0wxmcbcc = ( ( -
_rtB -> bw2nhi51td - 1.7320508075688772 * _rtB -> gthgcz50sq ) * mkcfwi2fsi +
( 1.7320508075688772 * _rtB -> bw2nhi51td - _rtB -> gthgcz50sq ) * ehtkh2wauy
) * 0.5 ; ehcygfucdl = _rtDW -> jcugjk0yp0 ; po0ockmy2b = muDoubleScalarSin (
_rtDW -> jcugjk0yp0 ) ; mizlp41tvx = muDoubleScalarCos ( _rtDW -> jcugjk0yp0
) ; _rtB -> pboh1r2kor = _rtB -> deue3miwlt * mizlp41tvx + _rtB -> aorbsvsy2v
* po0ockmy2b ; _rtB -> n1lgg0011x = ( ( - _rtB -> deue3miwlt -
1.7320508075688772 * _rtB -> aorbsvsy2v ) * mizlp41tvx + ( 1.7320508075688772
* _rtB -> deue3miwlt - _rtB -> aorbsvsy2v ) * po0ockmy2b ) * 0.5 ; f4ufgq33gz
= _rtDW -> jly33pdwub ; i5nu34w4uj = 5.9999820000156134E-6 * _rtDW ->
f2z5i2ds5e ; _rtB -> l0j0hqaqrx = ( i5nu34w4uj > ld5zvvrfqt ( S ) ->
j532m1ivhv ) ; } if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> cl0eiluvkr =
_rtDW -> b50c0wk1dc ; } if ( ssIsSampleHit ( S , 2 , 0 ) ) { if ( _rtDW ->
o05rwe50bo != 0 ) { _rtDW -> pk42w2cjcz = _rtB -> cl0eiluvkr ; if ( _rtDW ->
pk42w2cjcz >= 25200.0 ) { _rtDW -> pk42w2cjcz = 25200.0 ; } else { if ( _rtDW
-> pk42w2cjcz <= rtMinusInf ) { _rtDW -> pk42w2cjcz = rtMinusInf ; } } } if (
( _rtB -> l0j0hqaqrx > 0.0 ) && ( _rtDW -> f0fxu4veqt <= 0 ) ) { _rtDW ->
pk42w2cjcz = _rtB -> cl0eiluvkr ; if ( _rtDW -> pk42w2cjcz >= 25200.0 ) {
_rtDW -> pk42w2cjcz = 25200.0 ; } else { if ( _rtDW -> pk42w2cjcz <=
rtMinusInf ) { _rtDW -> pk42w2cjcz = rtMinusInf ; } } } if ( _rtDW ->
pk42w2cjcz >= 25200.0 ) { _rtDW -> pk42w2cjcz = 25200.0 ; } else { if ( _rtDW
-> pk42w2cjcz <= rtMinusInf ) { _rtDW -> pk42w2cjcz = rtMinusInf ; } }
dztyrqu4xa = 0.00027777777777777778 * _rtDW -> pk42w2cjcz ; if ( dztyrqu4xa >
6.9993 ) { eskeehll14 = 6.9993 ; } else if ( dztyrqu4xa < 0.0 ) { eskeehll14
= 0.0 ; } else { eskeehll14 = dztyrqu4xa ; } if ( dztyrqu4xa >= 6.9993 ) {
dztyrqu4xa = 6.9993 ; } lvh3r5z3vn_idx_0 = ld5zvvrfqt ( S ) -> gughk5qkcu *
dztyrqu4xa ; lvh3r5z3vn_idx_2 = ( real_T ) ( i5nu34w4uj < ld5zvvrfqt ( S ) ->
inygnhesyk ) * ld5zvvrfqt ( S ) -> gughk5qkcu ; byehzqrbel = ( ( 7.0 / ( 7.0
- eskeehll14 ) * - 0.23801451555567835 * eskeehll14 + ( ld5zvvrfqt ( S ) ->
io0krbsejw + f4ufgq33gz ) ) + - _rtB -> l0j0hqaqrx * 0.23801451555567835 *
i5nu34w4uj * ( 7.0 / ( 7.0 - eskeehll14 ) ) ) + - lvh3r5z3vn_idx_2 *
0.23801451555567835 * ( ld5zvvrfqt ( S ) -> gughk5qkcu * i5nu34w4uj ) * ( 7.0
/ ( muDoubleScalarAbs ( lvh3r5z3vn_idx_0 ) + 0.70000000000000007 ) ) ; if (
byehzqrbel > ld5zvvrfqt ( S ) -> mmmonmcvsy ) { _rtB -> e1ecrlckkf =
ld5zvvrfqt ( S ) -> mmmonmcvsy ; } else { iiis24gb3o = 0.30769230769230771 *
i5nu34w4uj ; if ( byehzqrbel < iiis24gb3o ) { _rtB -> e1ecrlckkf = iiis24gb3o
; } else { _rtB -> e1ecrlckkf = byehzqrbel ; } } _rtB -> l3tn2h3her = _rtDW
-> fezg0yhyh2 ; lvh3r5z3vn_idx_0 = _rtDW -> hdqerfit1p [ 0 ] ;
lvh3r5z3vn_idx_1 = _rtDW -> hdqerfit1p [ 1 ] ; lvh3r5z3vn_idx_2 = _rtDW ->
hdqerfit1p [ 2 ] ; lduwq00gqj = muDoubleScalarCos ( jwhz1ujp3w ) ; ckrl0nmlwt
= muDoubleScalarSin ( jwhz1ujp3w ) ; } if ( _rtB -> m2y1khvsri [ 7 ] <= 1.0 )
{ nl0syzv5zt = 1.0 ; } else { nl0syzv5zt = _rtB -> m2y1khvsri [ 7 ] ; }
nl0syzv5zt = 1.0 / nl0syzv5zt ; nl0syzv5zt *= 30000.0 ; i5nu34w4uj =
muDoubleScalarAbs ( nl0syzv5zt ) ; if ( ssIsMajorTimeStep ( S ) ) { if ( _rtB
-> m2y1khvsri [ 7 ] >= 300.0 ) { _rtDW -> ch52ed4whv = true ; } else { if (
_rtB -> m2y1khvsri [ 7 ] <= 200.0 ) { _rtDW -> ch52ed4whv = false ; } } }
_rtB -> phcwnuwl5n = _rtDW -> ch52ed4whv ; if ( ( _rtDW -> mg242c3vwq >=
ssGetTaskTime ( S , 0 ) ) && ( _rtDW -> k1wt3kvmem >= ssGetTaskTime ( S , 0 )
) ) { _rtB -> olmdvncqn2 = _rtB -> phcwnuwl5n ; } else { if ( ( ( _rtDW ->
mg242c3vwq < _rtDW -> k1wt3kvmem ) && ( _rtDW -> k1wt3kvmem < ssGetTaskTime (
S , 0 ) ) ) || ( ( _rtDW -> mg242c3vwq >= _rtDW -> k1wt3kvmem ) && ( _rtDW ->
mg242c3vwq >= ssGetTaskTime ( S , 0 ) ) ) ) { iiis24gb3o = ssGetTaskTime ( S
, 0 ) - _rtDW -> k1wt3kvmem ; lebvfutt11 = _rtDW -> lzjsh0qxsz ; } else {
iiis24gb3o = ssGetTaskTime ( S , 0 ) - _rtDW -> mg242c3vwq ; lebvfutt11 =
_rtDW -> oiqwpboxgd ; } lstej3qx0u = iiis24gb3o * 10.0 ; f2e3v5ccex = _rtB ->
phcwnuwl5n - lebvfutt11 ; if ( f2e3v5ccex > lstej3qx0u ) { _rtB -> olmdvncqn2
= lebvfutt11 + lstej3qx0u ; } else { iiis24gb3o *= - 10.0 ; if ( f2e3v5ccex <
iiis24gb3o ) { _rtB -> olmdvncqn2 = lebvfutt11 + iiis24gb3o ; } else { _rtB
-> olmdvncqn2 = _rtB -> phcwnuwl5n ; } } } if ( _rtB -> m2y1khvsri [ 5 ] >
628.31853071795865 ) { _rtB -> kepj353xwf = 628.31853071795865 ; } else if (
_rtB -> m2y1khvsri [ 5 ] < 0.0 ) { _rtB -> kepj353xwf = 0.0 ; } else { _rtB
-> kepj353xwf = _rtB -> m2y1khvsri [ 5 ] ; } nl0syzv5zt = muDoubleScalarAbs (
_rtB -> kepj353xwf ) ; HEV_acc_LookUp_real_T_real_T ( & ( bypkl1sbku ) ,
ni220kbneq . kra3wm5gfy , nl0syzv5zt , ni220kbneq . elvuv43juu , 6U ) ; if (
( _rtDW -> cwivfg5ijd >= ssGetTaskTime ( S , 0 ) ) && ( _rtDW -> m1iuzueluk
>= ssGetTaskTime ( S , 0 ) ) ) { _rtB -> jn051xe0u0 = _rtB -> i3qwusyalv ; }
else { if ( ( ( _rtDW -> cwivfg5ijd < _rtDW -> m1iuzueluk ) && ( _rtDW ->
m1iuzueluk < ssGetTaskTime ( S , 0 ) ) ) || ( ( _rtDW -> cwivfg5ijd >= _rtDW
-> m1iuzueluk ) && ( _rtDW -> cwivfg5ijd >= ssGetTaskTime ( S , 0 ) ) ) ) {
iiis24gb3o = ssGetTaskTime ( S , 0 ) - _rtDW -> m1iuzueluk ; lebvfutt11 =
_rtDW -> bvl1znuobh ; } else { iiis24gb3o = ssGetTaskTime ( S , 0 ) - _rtDW
-> cwivfg5ijd ; lebvfutt11 = _rtDW -> kguctqvwvn ; } f2e3v5ccex = _rtB ->
i3qwusyalv - lebvfutt11 ; if ( f2e3v5ccex > iiis24gb3o ) { _rtB -> jn051xe0u0
= lebvfutt11 + iiis24gb3o ; } else { iiis24gb3o = - iiis24gb3o ; if (
f2e3v5ccex < iiis24gb3o ) { _rtB -> jn051xe0u0 = lebvfutt11 + iiis24gb3o ; }
else { _rtB -> jn051xe0u0 = _rtB -> i3qwusyalv ; } } } byehzqrbel = 400.0 *
_rtB -> jn051xe0u0 ; if ( byehzqrbel > bypkl1sbku ) { nl0syzv5zt = bypkl1sbku
; } else if ( byehzqrbel < - bypkl1sbku ) { nl0syzv5zt = - bypkl1sbku ; }
else { nl0syzv5zt = byehzqrbel ; } g1lvj1hvai = ssGetT ( S ) ; _rtB ->
p1stoedzmp = ( real_T ) ( g1lvj1hvai > ld5zvvrfqt ( S ) -> dj05t05dsm ) *
nl0syzv5zt ; g1lvj1hvai = _rtB -> p1stoedzmp * _rtB -> kepj353xwf ; if (
ssIsSampleHit ( S , 2 , 0 ) ) { _rtB -> hcmgyxfcpa = ( 1.0 - eskeehll14 / 7.0
) * 100.0 ; rowIdx = ( int32_T ) ( ( ( ( ( uint32_T ) ( _rtB -> hcmgyxfcpa <
ld5zvvrfqt ( S ) -> hskj2gq3ot ) << 1 ) + ( _rtB -> hcmgyxfcpa > ld5zvvrfqt (
S ) -> huspnf2yod ) ) << 1 ) + _rtDW -> bvad1zjfik ) ; _rtB -> gjh03haoma [
0U ] = ni220kbneq . i1nwoqgijo [ ( uint32_T ) rowIdx ] ; _rtB -> gjh03haoma [
1U ] = ni220kbneq . i1nwoqgijo [ rowIdx + 8U ] ; } nl0syzv5zt = _rtB ->
gjh03haoma [ 0 ] ; _rtB -> kpy3ewm1tr = - 21000.0 * nl0syzv5zt ; if ( ( _rtDW
-> hfvh40s0je >= ssGetTaskTime ( S , 0 ) ) && ( _rtDW -> f41a3yqptq >=
ssGetTaskTime ( S , 0 ) ) ) { _rtB -> hu13clizcm = _rtB -> kpy3ewm1tr ; }
else { if ( ( ( _rtDW -> hfvh40s0je < _rtDW -> f41a3yqptq ) && ( _rtDW ->
f41a3yqptq < ssGetTaskTime ( S , 0 ) ) ) || ( ( _rtDW -> hfvh40s0je >= _rtDW
-> f41a3yqptq ) && ( _rtDW -> hfvh40s0je >= ssGetTaskTime ( S , 0 ) ) ) ) {
iiis24gb3o = ssGetTaskTime ( S , 0 ) - _rtDW -> f41a3yqptq ; lebvfutt11 =
_rtDW -> aq3qjo4ji4 ; } else { iiis24gb3o = ssGetTaskTime ( S , 0 ) - _rtDW
-> hfvh40s0je ; lebvfutt11 = _rtDW -> lidlmlim32 ; } lstej3qx0u = iiis24gb3o
* 42000.0 ; f2e3v5ccex = _rtB -> kpy3ewm1tr - lebvfutt11 ; if ( f2e3v5ccex >
lstej3qx0u ) { _rtB -> hu13clizcm = lebvfutt11 + lstej3qx0u ; } else {
iiis24gb3o *= - 42000.0 ; if ( f2e3v5ccex < iiis24gb3o ) { _rtB -> hu13clizcm
= lebvfutt11 + iiis24gb3o ; } else { _rtB -> hu13clizcm = _rtB -> kpy3ewm1tr
; } } } j0jhyqa1p3 = g1lvj1hvai - _rtB -> hu13clizcm ; nl0syzv5zt =
muDoubleScalarAbs ( j0jhyqa1p3 ) ; nl0syzv5zt = 1.1 * rt_Lookup ( _rtP ->
EngineSpeedPower . power , 84 , nl0syzv5zt , _rtP -> EngineSpeedPower . speed
) ; if ( nl0syzv5zt > 5000.0 ) { _rtB -> lvthxz35q2 = 5000.0 ; } else if (
nl0syzv5zt < 750.0 ) { _rtB -> lvthxz35q2 = 750.0 ; } else { _rtB ->
lvthxz35q2 = nl0syzv5zt ; } if ( ( _rtB -> lvthxz35q2 > ld5zvvrfqt ( S ) ->
gcfoyt2y11 ) && ( _rtB -> lvthxz35q2 < ld5zvvrfqt ( S ) -> il2caevbru ) ) {
_rtB -> hmpiirraho = ld5zvvrfqt ( S ) -> gb2czhk2ko ; } else { _rtB ->
hmpiirraho = _rtB -> lvthxz35q2 ; } byehzqrbel = 0.10471975511965977 * _rtB
-> hmpiirraho ; if ( ssIsMajorTimeStep ( S ) ) { if ( g1lvj1hvai >= 12000.0 )
{ _rtDW -> guq5pq4c5s = true ; } else { if ( g1lvj1hvai <= 11000.0 ) { _rtDW
-> guq5pq4c5s = false ; } } } if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB ->
ietnn42gm4 = ! ! _rtDW -> guq5pq4c5s ; _rtB -> fzc01db25p = ( _rtDW ->
aln04uuynj != ld5zvvrfqt ( S ) -> ltzkvlmi5k ) ; } o3khhk3fbg = ( _rtB ->
ietnn42gm4 || ( ( g1lvj1hvai > ld5zvvrfqt ( S ) -> jgtkfabjb2 ) && _rtB ->
fzc01db25p ) ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> ilkku5s2bn =
_rtDW -> nlh5qppt4m ; } if ( o3khhk3fbg ) { if ( j0jhyqa1p3 > 57000.0 ) {
h0cg4jnrg5 = 57000.0 ; } else if ( j0jhyqa1p3 < - 57000.0 ) { h0cg4jnrg5 = -
57000.0 ; } else { h0cg4jnrg5 = j0jhyqa1p3 ; } _rtB -> ersrpfk3o2 = 1.0 /
byehzqrbel * h0cg4jnrg5 * _rtB -> olmdvncqn2 ; } else { _rtB -> ersrpfk3o2 =
_rtB -> ilkku5s2bn ; } g1lvj1hvai = 1.0 / byehzqrbel * _rtB -> jvdklob0se ;
if ( g1lvj1hvai > 1.0 ) { h0cg4jnrg5 = 1.0 ; } else if ( g1lvj1hvai < 0.0 ) {
h0cg4jnrg5 = 0.0 ; } else { h0cg4jnrg5 = g1lvj1hvai ; } iiis24gb3o = _rtB ->
olmdvncqn2 * _rtB -> ersrpfk3o2 * h0cg4jnrg5 * 0.27777777777777779 ; if (
iiis24gb3o > i5nu34w4uj ) { _rtB -> nk4zs1whes = i5nu34w4uj ; } else if (
iiis24gb3o < - i5nu34w4uj ) { _rtB -> nk4zs1whes = - i5nu34w4uj ; } else {
_rtB -> nk4zs1whes = iiis24gb3o ; } g1lvj1hvai = - _rtB -> nk4zs1whes *
ld5zvvrfqt ( S ) -> j531fxm4yb ; if ( ( _rtDW -> mtptmi2003 == ( rtMinusInf )
) || ( _rtDW -> mtptmi2003 == ssGetTaskTime ( S , 0 ) ) ) { _rtDW ->
mtptmi2003 = ssGetTaskTime ( S , 0 ) ; _rtB -> fx01pahyvh = 0.0 ; } else {
_rtB -> fx01pahyvh = g1lvj1hvai ; } if ( ssIsSampleHit ( S , 2 , 0 ) ) { if (
_rtB -> fx01pahyvh > 45.0 ) { dztyrqu4xa = 45.0 ; } else if ( _rtB ->
fx01pahyvh < - 45.0 ) { dztyrqu4xa = - 45.0 ; } else { dztyrqu4xa = _rtB ->
fx01pahyvh ; } aqlslovppe = 3.4722222222222219 * dztyrqu4xa ; dyfxp2slod = -
ld5zvvrfqt ( S ) -> brvuyzmave * ckrl0nmlwt + aqlslovppe * lduwq00gqj ;
ctpq3axefx = dyfxp2slod - lvh3r5z3vn_idx_0 ; if ( ctpq3axefx >= 0.0 ) { _rtDW
-> mdrfaaqhlc = true ; } else { if ( ctpq3axefx <= 0.0 ) { _rtDW ->
mdrfaaqhlc = false ; } } dk4tk42hhp = ( 1.7320508 * ckrl0nmlwt + - lduwq00gqj
) * aqlslovppe * 0.5 + ( 1.7320508 * lduwq00gqj + ckrl0nmlwt ) * ld5zvvrfqt (
S ) -> brvuyzmave * 0.5 ; aqlslovppe = dk4tk42hhp - lvh3r5z3vn_idx_1 ; if (
aqlslovppe >= 0.0 ) { _rtDW -> hi5e5wjvfn = true ; } else { if ( aqlslovppe
<= 0.0 ) { _rtDW -> hi5e5wjvfn = false ; } } f1b5simhxh = ( 0.0 - dk4tk42hhp
) - dyfxp2slod ; lduwq00gqj = f1b5simhxh - lvh3r5z3vn_idx_2 ; if ( lduwq00gqj
>= 0.0 ) { _rtDW -> ltj2mwt3by = true ; } else { if ( lduwq00gqj <= 0.0 ) {
_rtDW -> ltj2mwt3by = false ; } } _rtB -> chqqcqlozl [ 0 ] = ( ( real_T )
_rtDW -> mdrfaaqhlc - ( real_T ) _rtDW -> hi5e5wjvfn ) * ld5zvvrfqt ( S ) ->
j531fxm4yb * _rtB -> l3tn2h3her ; _rtB -> chqqcqlozl [ 1 ] = ( ( real_T )
_rtDW -> hi5e5wjvfn - ( real_T ) _rtDW -> ltj2mwt3by ) * ld5zvvrfqt ( S ) ->
j531fxm4yb * _rtB -> l3tn2h3her ; _rtB -> hy1c0w2zn1 = _rtDW -> bro0cn1wmi ;
lvh3r5z3vn_idx_0 = _rtDW -> j31s1kcymk [ 0 ] ; lvh3r5z3vn_idx_1 = _rtDW ->
j31s1kcymk [ 1 ] ; lvh3r5z3vn_idx_2 = _rtDW -> j31s1kcymk [ 2 ] ; ehcygfucdl
/= 4.0 ; ctpq3axefx = 4.0 * ehcygfucdl ; aqlslovppe = muDoubleScalarCos (
ctpq3axefx ) ; ctpq3axefx = muDoubleScalarSin ( ctpq3axefx ) ; if (
ssIsSampleHit ( S , 3 , 0 ) ) { _rtB -> ppdvv1yeyz = _rtDW -> gsr0ogd2xb ; }
_rtB -> npki002lys = 0.002479481623358034 * _rtB -> ppdvv1yeyz ; } if ( (
_rtDW -> joiszbfghn >= ssGetTaskTime ( S , 0 ) ) && ( _rtDW -> jlnwqqs23l >=
ssGetTaskTime ( S , 0 ) ) ) { _rtB -> ewebcl0qdv = _rtB -> npki002lys ; }
else { if ( ( ( _rtDW -> joiszbfghn < _rtDW -> jlnwqqs23l ) && ( _rtDW ->
jlnwqqs23l < ssGetTaskTime ( S , 0 ) ) ) || ( ( _rtDW -> joiszbfghn >= _rtDW
-> jlnwqqs23l ) && ( _rtDW -> joiszbfghn >= ssGetTaskTime ( S , 0 ) ) ) ) {
iiis24gb3o = ssGetTaskTime ( S , 0 ) - _rtDW -> jlnwqqs23l ; lebvfutt11 =
_rtDW -> miwjijsda1 ; } else { iiis24gb3o = ssGetTaskTime ( S , 0 ) - _rtDW
-> joiszbfghn ; lebvfutt11 = _rtDW -> narm2z4h4g ; } lstej3qx0u = iiis24gb3o
* 10.0 ; f2e3v5ccex = _rtB -> npki002lys - lebvfutt11 ; if ( f2e3v5ccex >
lstej3qx0u ) { _rtB -> ewebcl0qdv = lebvfutt11 + lstej3qx0u ; } else {
iiis24gb3o *= - 10.0 ; if ( f2e3v5ccex < iiis24gb3o ) { _rtB -> ewebcl0qdv =
lebvfutt11 + iiis24gb3o ; } else { _rtB -> ewebcl0qdv = _rtB -> npki002lys ;
} } } g1lvj1hvai = muDoubleScalarAbs ( _rtB -> ewebcl0qdv ) ; _rtB ->
bltyzp5yrb = rt_Lookup ( ni220kbneq . hvtx2huqpc , 301 , g1lvj1hvai ,
ni220kbneq . fjibtn4wrs ) ; if ( ssIsSampleHit ( S , 2 , 0 ) ) { _rtB ->
puvvtvlgou = _rtB -> kepj353xwf ; ssCallAccelRunBlock ( S , 5 , 0 ,
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
= byehzqrbel - lvh3r5z3vn_idx_0 ; if ( iiis24gb3o >= 0.0 ) { _rtDW ->
bmg0h5hxwy = true ; } else { if ( iiis24gb3o <= 0.0 ) { _rtDW -> bmg0h5hxwy =
false ; } } i5nu34w4uj = ( 1.7320508 * ctpq3axefx + - aqlslovppe ) *
ckrl0nmlwt * 0.5 + ( 1.7320508 * aqlslovppe + ctpq3axefx ) * lduwq00gqj * 0.5
; ctpq3axefx = i5nu34w4uj - lvh3r5z3vn_idx_1 ; if ( ctpq3axefx >= 0.0 ) {
_rtDW -> kakc11drsq = true ; } else { if ( ctpq3axefx <= 0.0 ) { _rtDW ->
kakc11drsq = false ; } } lstej3qx0u = ( 0.0 - i5nu34w4uj ) - byehzqrbel ;
aqlslovppe = lstej3qx0u - lvh3r5z3vn_idx_2 ; if ( aqlslovppe >= 0.0 ) { _rtDW
-> d1uemo0w03 = true ; } else { if ( aqlslovppe <= 0.0 ) { _rtDW ->
d1uemo0w03 = false ; } } _rtB -> n1nkm5c3os [ 0 ] = ( ( real_T ) _rtDW ->
bmg0h5hxwy - ( real_T ) _rtDW -> kakc11drsq ) * ld5zvvrfqt ( S ) ->
m5d2tvi1jg * _rtB -> hy1c0w2zn1 ; _rtB -> n1nkm5c3os [ 1 ] = ( ( real_T )
_rtDW -> kakc11drsq - ( real_T ) _rtDW -> d1uemo0w03 ) * ld5zvvrfqt ( S ) ->
m5d2tvi1jg * _rtB -> hy1c0w2zn1 ; _rtB -> gye2c4lpsk = _rtDW -> kzrq2xyp0f ;
ld5p5vfhmu = ( ld5zvvrfqt ( S ) -> j531fxm4yb != 0.0 ) ; zcEvent_idx_0 =
rt_ZCFcn ( ANY_ZERO_CROSSING , & _rtZCE -> gn3hyklx0i [ 0 ] , ( dyfxp2slod )
) ; zcEvent_idx_1 = rt_ZCFcn ( ANY_ZERO_CROSSING , & _rtZCE -> gn3hyklx0i [ 1
] , ( dk4tk42hhp ) ) ; zcEvent_idx_2 = rt_ZCFcn ( ANY_ZERO_CROSSING , &
_rtZCE -> gn3hyklx0i [ 2 ] , ( f1b5simhxh ) ) ; lvh3r5z3vn_idx_0 = dyfxp2slod
; lvh3r5z3vn_idx_2 = f1b5simhxh ; if ( _rtDW -> p5ivrte15o [ 0 ] == 0 ) { if
( zcEvent_idx_0 != NO_ZCEVENT ) { _rtB -> e0ekalanvj [ 0 ] = ! _rtB ->
e0ekalanvj [ 0 ] ; _rtDW -> p5ivrte15o [ 0 ] = 1 ; } else if ( _rtB ->
e0ekalanvj [ 0 ] ) { if ( dyfxp2slod != 0.0 ) { _rtB -> e0ekalanvj [ 0 ] =
false ; } } else { if ( dyfxp2slod == 0.0 ) { _rtB -> e0ekalanvj [ 0 ] = true
; } } } else { if ( lvh3r5z3vn_idx_0 != 0.0 ) { _rtB -> e0ekalanvj [ 0 ] =
false ; } _rtDW -> p5ivrte15o [ 0 ] = 0 ; } if ( _rtDW -> p5ivrte15o [ 1 ] ==
0 ) { if ( zcEvent_idx_1 != NO_ZCEVENT ) { _rtB -> e0ekalanvj [ 1 ] = ! _rtB
-> e0ekalanvj [ 1 ] ; _rtDW -> p5ivrte15o [ 1 ] = 1 ; } else if ( _rtB ->
e0ekalanvj [ 1 ] ) { if ( dk4tk42hhp != 0.0 ) { _rtB -> e0ekalanvj [ 1 ] =
false ; } } else { if ( dk4tk42hhp == 0.0 ) { _rtB -> e0ekalanvj [ 1 ] = true
; } } } else { if ( dk4tk42hhp != 0.0 ) { _rtB -> e0ekalanvj [ 1 ] = false ;
} _rtDW -> p5ivrte15o [ 1 ] = 0 ; } if ( _rtDW -> p5ivrte15o [ 2 ] == 0 ) {
if ( zcEvent_idx_2 != NO_ZCEVENT ) { _rtB -> e0ekalanvj [ 2 ] = ! _rtB ->
e0ekalanvj [ 2 ] ; _rtDW -> p5ivrte15o [ 2 ] = 1 ; } else if ( _rtB ->
e0ekalanvj [ 2 ] ) { if ( f1b5simhxh != 0.0 ) { _rtB -> e0ekalanvj [ 2 ] =
false ; } } else { if ( f1b5simhxh == 0.0 ) { _rtB -> e0ekalanvj [ 2 ] = true
; } } } else { if ( lvh3r5z3vn_idx_2 != 0.0 ) { _rtB -> e0ekalanvj [ 2 ] =
false ; } _rtDW -> p5ivrte15o [ 2 ] = 0 ; } keyxmz53xi ( S , _rtB ->
e0ekalanvj [ 0 ] , ld5p5vfhmu , & _rtB -> keyxmz53xiy , & _rtDW ->
keyxmz53xiy ) ; keyxmz53xi ( S , _rtB -> e0ekalanvj [ 1 ] , ld5p5vfhmu , &
_rtB -> d5h5wn4011 , & _rtDW -> d5h5wn4011 ) ; keyxmz53xi ( S , _rtB ->
e0ekalanvj [ 2 ] , ld5p5vfhmu , & _rtB -> hlr1ddtilb , & _rtDW -> hlr1ddtilb
) ; iiis24gb3o = 0.05823546641575128 * _rtDW -> nonllthbl2 ; ctpq3axefx =
0.05823546641575128 * _rtDW -> kol45dq53x ; aqlslovppe = muDoubleScalarSin (
jwhz1ujp3w ) ; jwhz1ujp3w = muDoubleScalarCos ( jwhz1ujp3w ) ; lduwq00gqj = (
0.0 - aqlslovppe * ld5zvvrfqt ( S ) -> otbl4qxcfp ) - jwhz1ujp3w * ld5zvvrfqt
( S ) -> o4vlkkhabu ; ckrl0nmlwt = aqlslovppe * ld5zvvrfqt ( S ) ->
o4vlkkhabu - jwhz1ujp3w * ld5zvvrfqt ( S ) -> otbl4qxcfp ; h0cg4jnrg5 = (
iiis24gb3o * aqlslovppe + ctpq3axefx * jwhz1ujp3w ) + ld5zvvrfqt ( S ) ->
gqr1j03oxu ; lfv3m5pb5c = ( iiis24gb3o * lduwq00gqj + ctpq3axefx * ckrl0nmlwt
) + ld5zvvrfqt ( S ) -> gqr1j03oxu ; iiis24gb3o = ( ( ( 0.0 - lduwq00gqj ) -
aqlslovppe ) * iiis24gb3o + ( ( 0.0 - ckrl0nmlwt ) - jwhz1ujp3w ) *
ctpq3axefx ) + ld5zvvrfqt ( S ) -> gqr1j03oxu ; _rtB -> i32ykv1m2d [ 0 ] = (
real_T ) _rtB -> keyxmz53xiy . forbrjhq11 * dyfxp2slod + 0.2 * h0cg4jnrg5 ;
_rtB -> i32ykv1m2d [ 1 ] = ( real_T ) _rtB -> d5h5wn4011 . forbrjhq11 *
dk4tk42hhp + 0.2 * lfv3m5pb5c ; _rtB -> i32ykv1m2d [ 2 ] = ( real_T ) _rtB ->
hlr1ddtilb . forbrjhq11 * f1b5simhxh + 0.2 * iiis24gb3o ; if ( _rtDW ->
ehaijafsot <= 1.0 ) { h0cg4jnrg5 = 1.0 ; } else { h0cg4jnrg5 = _rtDW ->
ehaijafsot ; } _rtB -> lq00vmqxfn = _rtDW -> fw2k5vojpd / h0cg4jnrg5 ;
zcEvent_idx_0 = rt_ZCFcn ( ANY_ZERO_CROSSING , & _rtZCE -> iw5dmb04jk [ 0 ] ,
( byehzqrbel ) ) ; zcEvent_idx_1 = rt_ZCFcn ( ANY_ZERO_CROSSING , & _rtZCE ->
iw5dmb04jk [ 1 ] , ( i5nu34w4uj ) ) ; zcEvent_idx_2 = rt_ZCFcn (
ANY_ZERO_CROSSING , & _rtZCE -> iw5dmb04jk [ 2 ] , ( lstej3qx0u ) ) ;
lvh3r5z3vn_idx_0 = byehzqrbel ; lvh3r5z3vn_idx_2 = lstej3qx0u ; if ( _rtDW ->
l43ws31i1a [ 0 ] == 0 ) { if ( zcEvent_idx_0 != NO_ZCEVENT ) { _rtB ->
dodw3yla1g [ 0 ] = ! _rtB -> dodw3yla1g [ 0 ] ; _rtDW -> l43ws31i1a [ 0 ] = 1
; } else if ( _rtB -> dodw3yla1g [ 0 ] ) { if ( byehzqrbel != 0.0 ) { _rtB ->
dodw3yla1g [ 0 ] = false ; } } else { if ( byehzqrbel == 0.0 ) { _rtB ->
dodw3yla1g [ 0 ] = true ; } } } else { if ( lvh3r5z3vn_idx_0 != 0.0 ) { _rtB
-> dodw3yla1g [ 0 ] = false ; } _rtDW -> l43ws31i1a [ 0 ] = 0 ; } if ( _rtDW
-> l43ws31i1a [ 1 ] == 0 ) { if ( zcEvent_idx_1 != NO_ZCEVENT ) { _rtB ->
dodw3yla1g [ 1 ] = ! _rtB -> dodw3yla1g [ 1 ] ; _rtDW -> l43ws31i1a [ 1 ] = 1
; } else if ( _rtB -> dodw3yla1g [ 1 ] ) { if ( i5nu34w4uj != 0.0 ) { _rtB ->
dodw3yla1g [ 1 ] = false ; } } else { if ( i5nu34w4uj == 0.0 ) { _rtB ->
dodw3yla1g [ 1 ] = true ; } } } else { if ( i5nu34w4uj != 0.0 ) { _rtB ->
dodw3yla1g [ 1 ] = false ; } _rtDW -> l43ws31i1a [ 1 ] = 0 ; } if ( _rtDW ->
l43ws31i1a [ 2 ] == 0 ) { if ( zcEvent_idx_2 != NO_ZCEVENT ) { _rtB ->
dodw3yla1g [ 2 ] = ! _rtB -> dodw3yla1g [ 2 ] ; _rtDW -> l43ws31i1a [ 2 ] = 1
; } else if ( _rtB -> dodw3yla1g [ 2 ] ) { if ( lstej3qx0u != 0.0 ) { _rtB ->
dodw3yla1g [ 2 ] = false ; } } else { if ( lstej3qx0u == 0.0 ) { _rtB ->
dodw3yla1g [ 2 ] = true ; } } } else { if ( lvh3r5z3vn_idx_2 != 0.0 ) { _rtB
-> dodw3yla1g [ 2 ] = false ; } _rtDW -> l43ws31i1a [ 2 ] = 0 ; } keyxmz53xi
( S , _rtB -> dodw3yla1g [ 0 ] , ld5zvvrfqt ( S ) -> aolqv23tty , & _rtB ->
ovboqennya , & _rtDW -> ovboqennya ) ; keyxmz53xi ( S , _rtB -> dodw3yla1g [
1 ] , ld5zvvrfqt ( S ) -> aolqv23tty , & _rtB -> ifhlf2te5a , & _rtDW ->
ifhlf2te5a ) ; keyxmz53xi ( S , _rtB -> dodw3yla1g [ 2 ] , ld5zvvrfqt ( S )
-> aolqv23tty , & _rtB -> dtnq4yt00p , & _rtDW -> dtnq4yt00p ) ; lfv3m5pb5c =
0.05823546641575128 * _rtDW -> lvw3lta2fy ; h0cg4jnrg5 = 0.05823546641575128
* _rtDW -> c20b4oc1jp ; ehcygfucdl *= 4.0 ; f2e3v5ccex = muDoubleScalarSin (
ehcygfucdl ) ; ehcygfucdl = muDoubleScalarCos ( ehcygfucdl ) ; lebvfutt11 = (
0.0 - f2e3v5ccex * ld5zvvrfqt ( S ) -> jv2kntmtfh ) - ehcygfucdl * ld5zvvrfqt
( S ) -> h2i3abqflw ; iiis24gb3o = f2e3v5ccex * ld5zvvrfqt ( S ) ->
h2i3abqflw - ehcygfucdl * ld5zvvrfqt ( S ) -> jv2kntmtfh ; lduwq00gqj = (
lfv3m5pb5c * f2e3v5ccex + h0cg4jnrg5 * ehcygfucdl ) + ld5zvvrfqt ( S ) ->
fkxyeiqohv ; ckrl0nmlwt = ( lfv3m5pb5c * lebvfutt11 + h0cg4jnrg5 * iiis24gb3o
) + ld5zvvrfqt ( S ) -> fkxyeiqohv ; lfv3m5pb5c = ( ( ( 0.0 - lebvfutt11 ) -
f2e3v5ccex ) * lfv3m5pb5c + ( ( 0.0 - iiis24gb3o ) - ehcygfucdl ) *
h0cg4jnrg5 ) + ld5zvvrfqt ( S ) -> fkxyeiqohv ; _rtB -> hftdnluwmw [ 0 ] = (
real_T ) _rtB -> ovboqennya . forbrjhq11 * byehzqrbel + 1.5384615384615383 *
lduwq00gqj ; _rtB -> hftdnluwmw [ 1 ] = ( real_T ) _rtB -> ifhlf2te5a .
forbrjhq11 * i5nu34w4uj + 1.5384615384615383 * ckrl0nmlwt ; _rtB ->
hftdnluwmw [ 2 ] = ( real_T ) _rtB -> dtnq4yt00p . forbrjhq11 * lstej3qx0u +
1.5384615384615383 * lfv3m5pb5c ; if ( _rtDW -> kopxzfb0sb <= 1.0 ) {
h0cg4jnrg5 = 1.0 ; } else { h0cg4jnrg5 = _rtDW -> kopxzfb0sb ; } _rtB ->
myq23iqbv1 = _rtDW -> lp13v2ihui / h0cg4jnrg5 ; _rtB -> lftrr2kakn = _rtDW ->
ebwur5qeqq ; ssCallAccelRunBlock ( S , 16 , 516 , SS_CALL_MDL_OUTPUTS ) ;
_rtB -> avmwtshft0 = _rtB -> e1ecrlckkf - 0.30769230769230771 * _rtB ->
ptzrcdocdc [ 33 ] ; ssCallAccelRunBlock ( S , 16 , 519 , SS_CALL_MDL_OUTPUTS
) ; lfv3m5pb5c = muDoubleScalarAbs ( _rtB -> ptzrcdocdc [ 33 ] ) ; _rtB ->
hq20ys4jiq = ( ( real_T ) ( _rtB -> ptzrcdocdc [ 33 ] < ld5zvvrfqt ( S ) ->
jpis122ot0 ) * 18.82114106089411 - f4ufgq33gz ) * lfv3m5pb5c *
0.00064102564102564092 ; _rtB -> glnaf4fasi = 3600.0 * eskeehll14 ; }
ssCallAccelRunBlock ( S , 14 , 0 , SS_CALL_MDL_OUTPUTS ) ; if ( _rtB ->
kepj353xwf <= 1.0 ) { i5nu34w4uj = 1.0 ; } else { i5nu34w4uj = _rtB ->
kepj353xwf ; } if ( ssIsMajorTimeStep ( S ) ) { if ( i5nu34w4uj >=
20.943951023931955 ) { _rtDW -> bmy4qihc4v = true ; } else { if ( i5nu34w4uj
<= 10.471975511965978 ) { _rtDW -> bmy4qihc4v = false ; } } } _rtB ->
lpk3v5k5iw = ! _rtDW -> bmy4qihc4v ; if ( ssIsSampleHit ( S , 2 , 0 ) ) {
_rtB -> pwynm2svfg = ld5zvvrfqt ( S ) -> pl25v5g33b - ( ld5zvvrfqt ( S ) ->
iua3bl24vy - _rtB -> avmwtshft0 ) * 200.0 ; } g1lvj1hvai = _rtB -> pwynm2svfg
; if ( g1lvj1hvai > 21000.0 ) { _rtB -> p1ekjm2mvt = 21000.0 ; } else if (
g1lvj1hvai < 0.0 ) { _rtB -> p1ekjm2mvt = 0.0 ; } else { _rtB -> p1ekjm2mvt =
g1lvj1hvai ; } if ( ( _rtDW -> n33aen2wbt >= ssGetTaskTime ( S , 0 ) ) && (
_rtDW -> fjojh4ewqs >= ssGetTaskTime ( S , 0 ) ) ) { _rtB -> laaoigtxzq =
_rtB -> p1ekjm2mvt ; } else { if ( ( ( _rtDW -> n33aen2wbt < _rtDW ->
fjojh4ewqs ) && ( _rtDW -> fjojh4ewqs < ssGetTaskTime ( S , 0 ) ) ) || ( (
_rtDW -> n33aen2wbt >= _rtDW -> fjojh4ewqs ) && ( _rtDW -> n33aen2wbt >=
ssGetTaskTime ( S , 0 ) ) ) ) { iiis24gb3o = ssGetTaskTime ( S , 0 ) - _rtDW
-> fjojh4ewqs ; lebvfutt11 = _rtDW -> d21ysphefx ; } else { iiis24gb3o =
ssGetTaskTime ( S , 0 ) - _rtDW -> n33aen2wbt ; lebvfutt11 = _rtDW ->
evmu5j4txb ; } lstej3qx0u = iiis24gb3o * 210000.0 ; f2e3v5ccex = _rtB ->
p1ekjm2mvt - lebvfutt11 ; if ( f2e3v5ccex > lstej3qx0u ) { _rtB -> laaoigtxzq
= lebvfutt11 + lstej3qx0u ; } else { iiis24gb3o *= - 210000.0 ; if (
f2e3v5ccex < iiis24gb3o ) { _rtB -> laaoigtxzq = lebvfutt11 + iiis24gb3o ; }
else { _rtB -> laaoigtxzq = _rtB -> p1ekjm2mvt ; } } } fviymzl3aa = ( _rtB ->
hu13clizcm != ld5zvvrfqt ( S ) -> eachtdj50l ) ; byehzqrbel = j0jhyqa1p3 -
_rtB -> gsc0pyt5qr [ 1 ] * _rtB -> jvdklob0se ; if ( fviymzl3aa ) { _rtB ->
hqgqkdvpxl = _rtB -> hu13clizcm ; } else { _rtB -> hqgqkdvpxl = byehzqrbel ;
} if ( ( _rtDW -> nolj4flzwb >= ssGetTaskTime ( S , 0 ) ) && ( _rtDW ->
bluedlz4ee >= ssGetTaskTime ( S , 0 ) ) ) { _rtB -> eclqlk2jz3 = _rtB ->
hqgqkdvpxl ; } else { if ( ( ( _rtDW -> nolj4flzwb < _rtDW -> bluedlz4ee ) &&
( _rtDW -> bluedlz4ee < ssGetTaskTime ( S , 0 ) ) ) || ( ( _rtDW ->
nolj4flzwb >= _rtDW -> bluedlz4ee ) && ( _rtDW -> nolj4flzwb >= ssGetTaskTime
( S , 0 ) ) ) ) { iiis24gb3o = ssGetTaskTime ( S , 0 ) - _rtDW -> bluedlz4ee
; lebvfutt11 = _rtDW -> awi4nxie0m ; } else { iiis24gb3o = ssGetTaskTime ( S
, 0 ) - _rtDW -> nolj4flzwb ; lebvfutt11 = _rtDW -> ppmw3hzciy ; } lstej3qx0u
= iiis24gb3o * 21000.0 ; f2e3v5ccex = _rtB -> hqgqkdvpxl - lebvfutt11 ; if (
f2e3v5ccex > lstej3qx0u ) { _rtB -> eclqlk2jz3 = lebvfutt11 + lstej3qx0u ; }
else { iiis24gb3o *= - 21000.0 ; if ( f2e3v5ccex < iiis24gb3o ) { _rtB ->
eclqlk2jz3 = lebvfutt11 + iiis24gb3o ; } else { _rtB -> eclqlk2jz3 = _rtB ->
hqgqkdvpxl ; } } } if ( _rtB -> lpk3v5k5iw != 0.0 ) { _rtB -> dsz5fdjlpk =
_rtB -> bwqretfuxy ; } else { if ( fviymzl3aa ) { byehzqrbel = _rtB ->
eclqlk2jz3 ; } if ( byehzqrbel > _rtB -> laaoigtxzq ) { byehzqrbel = _rtB ->
laaoigtxzq ; } else { if ( byehzqrbel < - _rtB -> laaoigtxzq ) { byehzqrbel =
- _rtB -> laaoigtxzq ; } } _rtB -> dsz5fdjlpk = ( _rtB -> m2y1khvsri [ 7 ] *
_rtB -> nk4zs1whes + byehzqrbel ) / i5nu34w4uj ; } ssCallAccelRunBlock ( S ,
16 , 569 , SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSampleHit ( S , 2 , 0 ) ) {
ssCallAccelRunBlock ( S , 16 , 570 , SS_CALL_MDL_OUTPUTS ) ; }
ssCallAccelRunBlock ( S , 16 , 571 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
nyaqe33lbw = 9.5492965855137211 * _rtB -> kepj353xwf ; if ( ssIsSampleHit ( S
, 2 , 0 ) && ssIsSampleHit ( S , 3 , 0 ) ) { _rtB -> gpw3isscxt = _rtDW ->
bv5gvrfela ; } _rtB -> j3bq5daw1x = _rtB -> kgfazmviyv * _rtB -> kepj353xwf ;
ssCallAccelRunBlock ( S , 16 , 575 , SS_CALL_MDL_OUTPUTS ) ; if (
ssIsSampleHit ( S , 2 , 0 ) ) { ssCallAccelRunBlock ( S , 16 , 578 ,
SS_CALL_MDL_OUTPUTS ) ; } ssCallAccelRunBlock ( S , 16 , 579 ,
SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSampleHit ( S , 2 , 0 ) ) { lfv3m5pb5c =
0.013480000230266853 * _rtDW -> pe31gvq3pv ; h0cg4jnrg5 =
0.013480000230266853 * _rtDW -> bw5cwo255x ; rowIdx = ( int32_T ) ( ( ( ( (
uint32_T ) ( lfv3m5pb5c > h0cg4jnrg5 ) << 1 ) + ( lfv3m5pb5c < 0.9 *
h0cg4jnrg5 ) ) << 1 ) + _rtDW -> l2t4rgxmml ) ; _rtB -> gtnxjfzazw [ 0U ] =
ni220kbneq . i1nwoqgijo [ ( uint32_T ) rowIdx ] ; _rtB -> gtnxjfzazw [ 1U ] =
ni220kbneq . i1nwoqgijo [ rowIdx + 8U ] ; h100jbae3x = ( uint8_T ) ( _rtB ->
gtnxjfzazw [ 0 ] << 7 ) ; _rtB -> o4rzcluk5d = ( real_T ) h100jbae3x *
0.0078125 ; _rtB -> llznabodvk = ( real_T ) h100jbae3x * 0.0078125 ; _rtB ->
hrzmwjlorh = ( real_T ) h100jbae3x * 0.0078125 ; fviymzl3aa = ! ( h100jbae3x
!= 0 ) ; _rtB -> b1jngwykl0 = fviymzl3aa ; _rtB -> pe3hxtq4du = fviymzl3aa ;
_rtB -> nayfcwmvbo = fviymzl3aa ; _rtB -> boedvgyxkk = ( ( _rtB -> ptzrcdocdc
[ 30 ] * _rtB -> ptzrcdocdc [ 30 ] + _rtB -> ptzrcdocdc [ 31 ] * _rtB ->
ptzrcdocdc [ 31 ] ) + _rtB -> ptzrcdocdc [ 32 ] * _rtB -> ptzrcdocdc [ 32 ] )
* 0.001 + ( _rtB -> ptzrcdocdc [ 21 ] * _rtB -> ptzrcdocdc [ 30 ] + _rtB ->
ptzrcdocdc [ 22 ] * _rtB -> ptzrcdocdc [ 31 ] ) ; } byehzqrbel =
muDoubleScalarPower ( ( 0.006391889398924 * _rtB -> kepj353xwf * _rtB ->
aorbsvsy2v + 0.0065 * _rtB -> deue3miwlt ) + 0.702664574517444 * _rtB ->
kepj353xwf , 2.0 ) + muDoubleScalarPower ( 0.0065 * _rtB -> aorbsvsy2v -
0.008228209001868 * _rtB -> kepj353xwf * _rtB -> deue3miwlt , 2.0 ) ; if (
byehzqrbel < 0.0 ) { byehzqrbel = - muDoubleScalarSqrt ( - byehzqrbel ) ; }
else { byehzqrbel = muDoubleScalarSqrt ( byehzqrbel ) ; } _rtB -> d53qabdhri
= 1.5707963267948966 * byehzqrbel ; if ( ssIsSampleHit ( S , 2 , 0 ) ) { _rtB
-> efjx13ngvd = ( ( 2.0 * _rtB -> ptzrcdocdc [ 14 ] + _rtB -> ptzrcdocdc [ 15
] ) * mizlp41tvx + 1.7320508075688772 * _rtB -> ptzrcdocdc [ 15 ] *
po0ockmy2b ) * 0.33333333333333331 ; _rtB -> ft15o4y5jn = ( ( 2.0 * _rtB ->
ptzrcdocdc [ 14 ] + _rtB -> ptzrcdocdc [ 15 ] ) * po0ockmy2b + -
1.7320508075688772 * _rtB -> ptzrcdocdc [ 15 ] * mizlp41tvx ) *
0.33333333333333331 ; _rtB -> mstqntcdpj = 625.79305591134812 * _rtB ->
ft15o4y5jn ; } _rtB -> bngrjsjriv = 4.0 * _rtB -> kepj353xwf ; if (
ssIsSampleHit ( S , 2 , 0 ) ) { _rtB -> nzyx4c1qvt = 4.0676548634237628 *
_rtB -> aorbsvsy2v ; } _rtB -> jngfhp3qt3 = _rtB -> bngrjsjriv * _rtB ->
deue3miwlt * 1.2872890139890598 + ( _rtB -> mstqntcdpj - _rtB -> nzyx4c1qvt )
; if ( ssIsSampleHit ( S , 2 , 0 ) ) { _rtB -> bwhnstpx53 =
486.13252277523628 * _rtB -> efjx13ngvd ; _rtB -> bent3b52ta =
3.1598613980390358 * _rtB -> deue3miwlt ; } _rtB -> dnc2vczue4 = ( ( _rtB ->
bwhnstpx53 - _rtB -> bent3b52ta ) - _rtB -> aorbsvsy2v * _rtB -> bngrjsjriv *
0.77682632969980325 ) - 85.397025568738272 * _rtB -> bngrjsjriv ; g1lvj1hvai
= muDoubleScalarAbs ( _rtB -> kepj353xwf ) ; HEV_acc_LookUp_real_T_real_T ( &
( dinenyqhbn ) , ni220kbneq . kra3wm5gfy , g1lvj1hvai , ni220kbneq .
elvuv43juu , 6U ) ; if ( _rtB -> dsz5fdjlpk > dinenyqhbn ) { g1lvj1hvai =
dinenyqhbn ; } else if ( _rtB -> dsz5fdjlpk < - dinenyqhbn ) { g1lvj1hvai = -
dinenyqhbn ; } else { g1lvj1hvai = _rtB -> dsz5fdjlpk ; } g1lvj1hvai *=
ld5zvvrfqt ( S ) -> m5d2tvi1jg ; if ( ( _rtDW -> dlegz3mcx5 == ( rtMinusInf )
) || ( _rtDW -> dlegz3mcx5 == ssGetTaskTime ( S , 0 ) ) ) { _rtDW ->
dlegz3mcx5 = ssGetTaskTime ( S , 0 ) ; _rtB -> lxpieeokrg = 0.0 ; } else {
_rtB -> lxpieeokrg = g1lvj1hvai ; } if ( ssIsSampleHit ( S , 3 , 0 ) ) { _rtB
-> jrxlqb3hqn = _rtB -> lxpieeokrg ; if ( _rtB -> jrxlqb3hqn > 400.0 ) { _rtB
-> jsrftgte5f = 400.0 ; } else if ( _rtB -> jrxlqb3hqn < - 400.0 ) { _rtB ->
jsrftgte5f = - 400.0 ; } else { _rtB -> jsrftgte5f = _rtB -> jrxlqb3hqn ; } }
if ( ssIsSampleHit ( S , 1 , 0 ) && ssIsSampleHit ( S , 3 , 0 ) ) { _rtB ->
ldemm4lkgo = ld5zvvrfqt ( S ) -> m5d2tvi1jg ; } if ( ssIsSampleHit ( S , 3 ,
0 ) ) { _rtB -> fhtdciv4bw = _rtB -> jsrftgte5f * _rtB -> ldemm4lkgo ; } if (
ssIsSampleHit ( S , 2 , 0 ) ) { ssCallAccelRunBlock ( S , 16 , 720 ,
SS_CALL_MDL_OUTPUTS ) ; } ssCallAccelRunBlock ( S , 16 , 721 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> nyaqe33lbw = 9.5492965855137211 * _rtB ->
m2y1khvsri [ 7 ] ; if ( ssIsSampleHit ( S , 1 , 0 ) && ssIsSampleHit ( S , 2
, 0 ) ) { _rtB -> ld4ghhjyjn = ld5zvvrfqt ( S ) -> j531fxm4yb ; } if (
ssIsSampleHit ( S , 2 , 0 ) ) { _rtB -> kwvc3jim5c = dztyrqu4xa * _rtB ->
ld4ghhjyjn ; } _rtB -> j3bq5daw1x = _rtB -> netq4xlqvp * _rtB -> m2y1khvsri [
7 ] ; ssCallAccelRunBlock ( S , 16 , 726 , SS_CALL_MDL_OUTPUTS ) ; if (
ssIsSampleHit ( S , 2 , 0 ) ) { lfv3m5pb5c = 0.013480000230266853 * _rtDW ->
dy4ppyw4mo ; h0cg4jnrg5 = 0.013480000230266853 * _rtDW -> hmybg5b1mi ; rowIdx
= ( int32_T ) ( ( ( ( ( uint32_T ) ( lfv3m5pb5c > h0cg4jnrg5 ) << 1 ) + (
lfv3m5pb5c < 0.9 * h0cg4jnrg5 ) ) << 1 ) + _rtDW -> gkq12xkctn ) ; _rtB ->
egjon3bn1l [ 0U ] = ni220kbneq . i1nwoqgijo [ ( uint32_T ) rowIdx ] ; _rtB ->
egjon3bn1l [ 1U ] = ni220kbneq . i1nwoqgijo [ rowIdx + 8U ] ; h100jbae3x = (
uint8_T ) ( _rtB -> egjon3bn1l [ 0 ] << 7 ) ; _rtB -> oorpx05pk1 = ( real_T )
h100jbae3x * 0.0078125 ; _rtB -> dauqgcc0wt = ( real_T ) h100jbae3x *
0.0078125 ; _rtB -> nfev430ywl = ( real_T ) h100jbae3x * 0.0078125 ;
fviymzl3aa = ! ( h100jbae3x != 0 ) ; _rtB -> hqfkb51sl0 = fviymzl3aa ; _rtB
-> c4kyzbhbgu = fviymzl3aa ; _rtB -> o1b0ykrlnd = fviymzl3aa ; _rtB ->
pksqcqhxle = ( ( _rtB -> ptzrcdocdc [ 26 ] * _rtB -> ptzrcdocdc [ 26 ] + _rtB
-> ptzrcdocdc [ 27 ] * _rtB -> ptzrcdocdc [ 27 ] ) + _rtB -> ptzrcdocdc [ 28
] * _rtB -> ptzrcdocdc [ 28 ] ) * 0.001 + ( _rtB -> ptzrcdocdc [ 17 ] * _rtB
-> ptzrcdocdc [ 26 ] + _rtB -> ptzrcdocdc [ 18 ] * _rtB -> ptzrcdocdc [ 27 ]
) ; } byehzqrbel = muDoubleScalarPower ( ( 0.000635 * _rtB -> m2y1khvsri [ 7
] * _rtB -> gthgcz50sq + 0.05 * _rtB -> bw2nhi51td ) + 0.192 * _rtB ->
m2y1khvsri [ 7 ] , 2.0 ) + muDoubleScalarPower ( 0.05 * _rtB -> gthgcz50sq -
0.000635 * _rtB -> m2y1khvsri [ 7 ] * _rtB -> bw2nhi51td , 2.0 ) ; if (
byehzqrbel < 0.0 ) { byehzqrbel = - muDoubleScalarSqrt ( - byehzqrbel ) ; }
else { byehzqrbel = muDoubleScalarSqrt ( byehzqrbel ) ; } _rtB -> ogrxkbaunf
= 1.5707963267948966 * byehzqrbel ; if ( ssIsSampleHit ( S , 2 , 0 ) ) { _rtB
-> pvrtgxnfdc = ( ( 2.0 * _rtB -> ptzrcdocdc [ 12 ] + _rtB -> ptzrcdocdc [ 13
] ) * mkcfwi2fsi + 1.7320508075688772 * _rtB -> ptzrcdocdc [ 13 ] *
ehtkh2wauy ) * 0.33333333333333331 ; _rtB -> ixhf3zpb2w = ( ( 2.0 * _rtB ->
ptzrcdocdc [ 12 ] + _rtB -> ptzrcdocdc [ 13 ] ) * ehtkh2wauy + -
1.7320508075688772 * _rtB -> ptzrcdocdc [ 13 ] * mkcfwi2fsi ) *
0.33333333333333331 ; _rtB -> cns4ivgkjo = 1574.803149606299 * _rtB ->
ixhf3zpb2w ; _rtB -> nuptkkmhrj = 78.740157480314963 * _rtB -> gthgcz50sq ; }
_rtB -> mld1pdgowl = ( _rtB -> cns4ivgkjo - _rtB -> nuptkkmhrj ) + _rtB ->
m2y1khvsri [ 7 ] * _rtB -> bw2nhi51td ; if ( ssIsSampleHit ( S , 2 , 0 ) ) {
_rtB -> jd3nzcw1bi = 1574.803149606299 * _rtB -> pvrtgxnfdc ; _rtB ->
iyz5nscesw = 78.740157480314963 * _rtB -> bw2nhi51td ; } _rtB -> bfaypyat3p =
( ( _rtB -> jd3nzcw1bi - _rtB -> iyz5nscesw ) - _rtB -> gthgcz50sq * _rtB ->
m2y1khvsri [ 7 ] ) - 302.36220472440942 * _rtB -> m2y1khvsri [ 7 ] ; if (
ssIsSampleHit ( S , 2 , 0 ) ) { ssCallAccelRunBlock ( S , 16 , 855 ,
SS_CALL_MDL_OUTPUTS ) ; } g1lvj1hvai = ssGetT ( S ) ; if ( ssIsSampleHit ( S
, 2 , 0 ) ) { _rtB -> f4osadyzmc = _rtB -> ptzrcdocdc [ 16 ] - ld5zvvrfqt ( S
) -> d1kndo3452 ; } _rtB -> dkrybiu0am = ( real_T ) ( g1lvj1hvai > ld5zvvrfqt
( S ) -> guxxyygraj ) * _rtB -> f4osadyzmc ; if ( ssIsSampleHit ( S , 2 , 0 )
) { if ( _rtDW -> llu3sg1ihp != 0 ) { _rtB -> az1l3lujmm = _rtDW ->
fj2gixcnhk ; } else { _rtB -> az1l3lujmm = 3.0E-5 * _rtB -> dkrybiu0am +
_rtDW -> fj2gixcnhk ; } if ( _rtB -> az1l3lujmm >= 1.0 ) { _rtB -> az1l3lujmm
= 1.0 ; } else { if ( _rtB -> az1l3lujmm <= - 1.0 ) { _rtB -> az1l3lujmm = -
1.0 ; } } } g1lvj1hvai = 0.001 * _rtB -> dkrybiu0am + _rtB -> az1l3lujmm ; if
( g1lvj1hvai > 0.95 ) { h0cg4jnrg5 = 0.95 ; } else if ( g1lvj1hvai < - 0.95 )
{ h0cg4jnrg5 = - 0.95 ; } else { h0cg4jnrg5 = g1lvj1hvai ; } _rtB ->
ipw0m5d5ah = ( h0cg4jnrg5 + 1.0 ) * 0.5 ; if ( ssIsSampleHit ( S , 2 , 0 ) )
{ lfv3m5pb5c = _rtDW -> dco4afubi3 ; _rtB -> kstuixbrhz = _rtDW -> dco4afubi3
* _rtB -> ptzrcdocdc [ 24 ] ; _rtB -> gnpfhoxjb1 = _rtDW -> dco4afubi3 * _rtB
-> ptzrcdocdc [ 34 ] ; } ssCallAccelRunBlock ( S , 16 , 902 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 16 , 903 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 16 , 904 ,
SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSampleHit ( S , 2 , 0 ) ) {
ssCallAccelRunBlock ( S , 16 , 905 , SS_CALL_MDL_OUTPUTS ) ; } if (
ssIsSampleHit ( S , 4 , 0 ) ) { ssCallAccelRunBlock ( S , 16 , 906 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 16 , 907 ,
SS_CALL_MDL_OUTPUTS ) ; } if ( _rtB -> pymde5nzv1 > 136.0 ) { h0cg4jnrg5 =
136.0 ; } else if ( _rtB -> pymde5nzv1 < 0.0 ) { h0cg4jnrg5 = 0.0 ; } else {
h0cg4jnrg5 = _rtB -> pymde5nzv1 ; } g1lvj1hvai = h0cg4jnrg5 * ld5zvvrfqt ( S
) -> gcraap3rxj ; if ( g1lvj1hvai > 1.0 ) { _rtB -> nyaqe33lbw = 1.0 ; } else
if ( g1lvj1hvai < 0.0 ) { _rtB -> nyaqe33lbw = 0.0 ; } else { _rtB ->
nyaqe33lbw = g1lvj1hvai ; } ssCallAccelRunBlock ( S , 16 , 912 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 16 , 913 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 16 , 914 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 16 , 915 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 16 , 916 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 16 , 917 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 16 , 918 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 16 , 919 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 16 , 920 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 16 , 921 ,
SS_CALL_MDL_OUTPUTS ) ; g1lvj1hvai = _rtB -> hmpiirraho * ( real_T )
o3khhk3fbg ; if ( ( _rtDW -> nn1a5wvgr5 == ( rtMinusInf ) ) || ( _rtDW ->
nn1a5wvgr5 == ssGetTaskTime ( S , 0 ) ) ) { _rtDW -> nn1a5wvgr5 =
ssGetTaskTime ( S , 0 ) ; _rtB -> ebc1w1doio = 0.0 ; } else { _rtB ->
ebc1w1doio = g1lvj1hvai ; } if ( ( _rtDW -> ewhcynzuun >= ssGetTaskTime ( S ,
0 ) ) && ( _rtDW -> ciu3b0lpet >= ssGetTaskTime ( S , 0 ) ) ) { _rtB ->
bdot1hoyd4 = _rtB -> ebc1w1doio ; } else { if ( ( ( _rtDW -> ewhcynzuun <
_rtDW -> ciu3b0lpet ) && ( _rtDW -> ciu3b0lpet < ssGetTaskTime ( S , 0 ) ) )
|| ( ( _rtDW -> ewhcynzuun >= _rtDW -> ciu3b0lpet ) && ( _rtDW -> ewhcynzuun
>= ssGetTaskTime ( S , 0 ) ) ) ) { iiis24gb3o = ssGetTaskTime ( S , 0 ) -
_rtDW -> ciu3b0lpet ; lebvfutt11 = _rtDW -> mmlyeyihwy ; } else { iiis24gb3o
= ssGetTaskTime ( S , 0 ) - _rtDW -> ewhcynzuun ; lebvfutt11 = _rtDW ->
h4ipbzntlo ; } lstej3qx0u = iiis24gb3o * 50000.0 ; f2e3v5ccex = _rtB ->
ebc1w1doio - lebvfutt11 ; if ( f2e3v5ccex > lstej3qx0u ) { _rtB -> bdot1hoyd4
= lebvfutt11 + lstej3qx0u ; } else { iiis24gb3o *= - 50000.0 ; if (
f2e3v5ccex < iiis24gb3o ) { _rtB -> bdot1hoyd4 = lebvfutt11 + iiis24gb3o ; }
else { _rtB -> bdot1hoyd4 = _rtB -> ebc1w1doio ; } } } if ( ssIsSampleHit ( S
, 2 , 0 ) ) { _rtB -> ihb2iwwf2e = o3khhk3fbg ; h0cg4jnrg5 = ( _rtB ->
bdot1hoyd4 - 0.036997346603025116 * _rtDW -> jctbfc4f1e ) * ( real_T ) _rtB
-> ihb2iwwf2e ; _rtB -> buk0lzzgpx = 0.1 * h0cg4jnrg5 ; if ( _rtDW ->
h4pa1qmmy5 != 0 ) { _rtB -> peiuomqxy4 = _rtDW -> olv3cnxtoy ; } else { _rtB
-> peiuomqxy4 = 3.0E-5 * _rtB -> buk0lzzgpx + _rtDW -> olv3cnxtoy ; } if (
_rtB -> peiuomqxy4 >= 1.0 ) { _rtB -> peiuomqxy4 = 1.0 ; } else { if ( _rtB
-> peiuomqxy4 <= 0.0 ) { _rtB -> peiuomqxy4 = 0.0 ; } } lfv3m5pb5c = 0.01 *
h0cg4jnrg5 + _rtB -> peiuomqxy4 ; if ( lfv3m5pb5c > 1.0 ) { lfv3m5pb5c = 1.0
; } else { if ( lfv3m5pb5c < 0.0 ) { lfv3m5pb5c = 0.0 ; } } } g1lvj1hvai =
_rtB -> jvdklob0se * ( real_T ) o3khhk3fbg ; _rtB -> anqsfozfne =
9.5492965855137211 * g1lvj1hvai ; if ( ssIsSampleHit ( S , 2 , 0 ) ) { _rtB
-> f0oijtvdsb = _rtB -> anqsfozfne ; _rtB -> n5hhjcgkxx = lfv3m5pb5c * (
real_T ) _rtB -> ihb2iwwf2e ; } _rtB -> c0gdaln4pz = muDoubleScalarAbs ( _rtB
-> chkwevbcym ) ; if ( ( _rtDW -> en15lu4hm1 >= ssGetT ( S ) ) && ( _rtDW ->
km4yirabra >= ssGetT ( S ) ) ) { _rtB -> i3cer4molf = 0.0 ; } else {
byehzqrbel = _rtDW -> en15lu4hm1 ; lastU = & _rtDW -> aa3vndu55f ; if ( _rtDW
-> en15lu4hm1 < _rtDW -> km4yirabra ) { if ( _rtDW -> km4yirabra < ssGetT ( S
) ) { byehzqrbel = _rtDW -> km4yirabra ; lastU = & _rtDW -> ke4dqjfdz3 ; } }
else { if ( _rtDW -> en15lu4hm1 >= ssGetT ( S ) ) { byehzqrbel = _rtDW ->
km4yirabra ; lastU = & _rtDW -> ke4dqjfdz3 ; } } _rtB -> i3cer4molf = ( _rtB
-> g123hlbqqb - * lastU ) / ( ssGetT ( S ) - byehzqrbel ) ; } _rtB ->
bzp0galr4p = muDoubleScalarAbs ( _rtB -> ib5hrgd3aj ) ; _rtB -> cye4qdpr3n =
1.093 * _rtB -> bzp0galr4p ; _rtB -> i0k4nyofsv = 1.0464 * _rtB -> g123hlbqqb
; { uint32_T iLeftU0 , iRghtU0 , iLeftU1 , iRghtU1 ;
HEV_acc_BINARYSEARCH_real_T ( & ( iLeftU0 ) , & ( iRghtU0 ) , _rtB ->
cye4qdpr3n , ni220kbneq . hlsjpbjuty , 108U ) ; if ( _rtB -> i0k4nyofsv <=
0.0 ) { iLeftU1 = 0U ; iRghtU1 = 0U ; } else if ( _rtB -> i0k4nyofsv >=
6000.0 ) { iLeftU1 = 100U ; iRghtU1 = 100U ; } else { iLeftU1 = ( uint32_T )
( ( _rtB -> i0k4nyofsv ) / 60.0 ) ; iRghtU1 = iLeftU1 + 1 ; } { real_T yTemp
; real_T u1Lambda ; real_T u0Lambda ; if ( iLeftU1 != iRghtU1 ) { { real_T
num = ( real_T ) ( _rtB -> i0k4nyofsv ) - ( iLeftU1 * 60.0 ) ; u1Lambda = num
/ 60.0 ; } } else { u1Lambda = 0.0 ; } if ( ( ni220kbneq . hlsjpbjuty [
iRghtU0 ] ) > ( ni220kbneq . hlsjpbjuty [ iLeftU0 ] ) ) { real_T num ; real_T
den ; den = ( ni220kbneq . hlsjpbjuty [ iRghtU0 ] ) ; den -= ( ni220kbneq .
hlsjpbjuty [ iLeftU0 ] ) ; num = _rtB -> cye4qdpr3n ; num -= ( ni220kbneq .
hlsjpbjuty [ iLeftU0 ] ) ; u0Lambda = num / den ; } else { u0Lambda = 0.0 ; }
{ real_T yLeftCast ; real_T yRghtCast ; yLeftCast = ( ni220kbneq . lj0gbaycmo
[ ( iLeftU0 + 109U * iLeftU1 ) ] ) ; yRghtCast = ( ni220kbneq . lj0gbaycmo [
( iLeftU0 + 109U * iRghtU1 ) ] ) ; yLeftCast += u1Lambda * ( yRghtCast -
yLeftCast ) ; jwhxrwpoow = yLeftCast ; } { real_T yLeftCast ; real_T
yRghtCast ; yLeftCast = ( ni220kbneq . lj0gbaycmo [ ( iRghtU0 + 109U *
iLeftU1 ) ] ) ; yRghtCast = ( ni220kbneq . lj0gbaycmo [ ( iRghtU0 + 109U *
iRghtU1 ) ] ) ; yLeftCast += u1Lambda * ( yRghtCast - yLeftCast ) ; yTemp =
yLeftCast ; } { real_T yLeftCast ; real_T yRghtCast ; yLeftCast = jwhxrwpoow
; yRghtCast = yTemp ; yLeftCast += u0Lambda * ( yRghtCast - yLeftCast ) ;
jwhxrwpoow = yLeftCast ; } } } _rtB -> kpkotqkdja = 1.0351048413332149 *
jwhxrwpoow ; _rtB -> cypubq2bde = 1.933764640184292E-6 * _rtB -> kpkotqkdja ;
_rtB -> dxbq0rfmco = muDoubleScalarSign ( _rtB -> ib5hrgd3aj ) ; _rtB ->
kvnazprh2a = muDoubleScalarAbs ( _rtB -> ib5hrgd3aj ) ; _rtB -> hpsmnl3mt1 =
1.093 * _rtB -> kvnazprh2a ; _rtB -> js1fpqvsoo = 1.0464 * _rtB -> g123hlbqqb
; { uint32_T iLeftU0 , iRghtU0 , iLeftU1 , iRghtU1 ;
HEV_acc_BINARYSEARCH_real_T ( & ( iLeftU0 ) , & ( iRghtU0 ) , _rtB ->
hpsmnl3mt1 , ni220kbneq . hlsjpbjuty , 108U ) ; if ( _rtB -> js1fpqvsoo <=
0.0 ) { iLeftU1 = 0U ; iRghtU1 = 0U ; } else if ( _rtB -> js1fpqvsoo >=
6000.0 ) { iLeftU1 = 100U ; iRghtU1 = 100U ; } else { iLeftU1 = ( uint32_T )
( ( _rtB -> js1fpqvsoo ) / 60.0 ) ; iRghtU1 = iLeftU1 + 1 ; } { real_T yTemp
; real_T u1Lambda ; real_T u0Lambda ; if ( iLeftU1 != iRghtU1 ) { { real_T
num = ( real_T ) ( _rtB -> js1fpqvsoo ) - ( iLeftU1 * 60.0 ) ; u1Lambda = num
/ 60.0 ; } } else { u1Lambda = 0.0 ; } if ( ( ni220kbneq . hlsjpbjuty [
iRghtU0 ] ) > ( ni220kbneq . hlsjpbjuty [ iLeftU0 ] ) ) { real_T num ; real_T
den ; den = ( ni220kbneq . hlsjpbjuty [ iRghtU0 ] ) ; den -= ( ni220kbneq .
hlsjpbjuty [ iLeftU0 ] ) ; num = _rtB -> hpsmnl3mt1 ; num -= ( ni220kbneq .
hlsjpbjuty [ iLeftU0 ] ) ; u0Lambda = num / den ; } else { u0Lambda = 0.0 ; }
{ real_T yLeftCast ; real_T yRghtCast ; yLeftCast = ( ni220kbneq . fiqfpbio0e
[ ( iLeftU0 + 109U * iLeftU1 ) ] ) ; yRghtCast = ( ni220kbneq . fiqfpbio0e [
( iLeftU0 + 109U * iRghtU1 ) ] ) ; yLeftCast += u1Lambda * ( yRghtCast -
yLeftCast ) ; dgero0mtoj = yLeftCast ; } { real_T yLeftCast ; real_T
yRghtCast ; yLeftCast = ( ni220kbneq . fiqfpbio0e [ ( iRghtU0 + 109U *
iLeftU1 ) ] ) ; yRghtCast = ( ni220kbneq . fiqfpbio0e [ ( iRghtU0 + 109U *
iRghtU1 ) ] ) ; yLeftCast += u1Lambda * ( yRghtCast - yLeftCast ) ; yTemp =
yLeftCast ; } { real_T yLeftCast ; real_T yRghtCast ; yLeftCast = dgero0mtoj
; yRghtCast = yTemp ; yLeftCast += u0Lambda * ( yRghtCast - yLeftCast ) ;
dgero0mtoj = yLeftCast ; } } } _rtB -> mnvy5i2u2d = 1.0351048413332149 *
dgero0mtoj ; _rtB -> p2v5lblnai = _rtB -> dxbq0rfmco * _rtB -> mnvy5i2u2d ;
_rtB -> ffa1tdctjr = _rtB -> p2v5lblnai * _rtB -> i3cer4molf ; _rtB ->
n0fxbk25ar = 1.933764640184292E-6 * _rtB -> ffa1tdctjr ; _rtB -> gd2tigxyid =
_rtB -> c0gdaln4pz * _rtB -> ib5hrgd3aj ; if ( _rtB -> cypubq2bde <= 0.02 ) {
_rtB -> kawdxjmdkt = 0.02 ; } else { _rtB -> kawdxjmdkt = _rtB -> cypubq2bde
; } _rtB -> agmpqmirph = ( ( 0.0 - _rtB -> n0fxbk25ar ) - _rtB -> mcmpwax5wu
) - _rtB -> gd2tigxyid ; _rtB -> cbxuzb05j1 = 1.0 / _rtB -> kawdxjmdkt * _rtB
-> agmpqmirph ; _rtB -> cdjaak3pfw = _rtB -> mv0scjuozy + _rtB -> cwuinypz5p
; _rtB -> hzqyysp3lg = ( _rtB -> cdjaak3pfw - _rtB -> jdx1oh4myt ) -
ld5zvvrfqt ( S ) -> oapjufkr55 ; _rtB -> mtsrafprq4 = 0.00075471698113207543
* _rtB -> hzqyysp3lg ; _rtB -> pzjopfniir = muDoubleScalarAbs ( _rtB ->
chkwevbcym ) ; if ( ( _rtDW -> cgi523usaj >= ssGetT ( S ) ) && ( _rtDW ->
irt5havirw >= ssGetT ( S ) ) ) { _rtB -> ipbkkeuhyx = 0.0 ; } else {
byehzqrbel = _rtDW -> cgi523usaj ; lastU = & _rtDW -> edrzze2flm ; if ( _rtDW
-> cgi523usaj < _rtDW -> irt5havirw ) { if ( _rtDW -> irt5havirw < ssGetT ( S
) ) { byehzqrbel = _rtDW -> irt5havirw ; lastU = & _rtDW -> gljjadsfzv ; } }
else { if ( _rtDW -> cgi523usaj >= ssGetT ( S ) ) { byehzqrbel = _rtDW ->
irt5havirw ; lastU = & _rtDW -> gljjadsfzv ; } } _rtB -> ipbkkeuhyx = ( _rtB
-> eqtatbfsoc - * lastU ) / ( ssGetT ( S ) - byehzqrbel ) ; } _rtB ->
ohnte4jidv = muDoubleScalarAbs ( _rtB -> iyq5z5g4dk ) ; _rtB -> azhllplsno =
1.093 * _rtB -> ohnte4jidv ; _rtB -> fkv340uzri = 1.0464 * _rtB -> eqtatbfsoc
; { uint32_T iLeftU0 , iRghtU0 , iLeftU1 , iRghtU1 ;
HEV_acc_BINARYSEARCH_real_T ( & ( iLeftU0 ) , & ( iRghtU0 ) , _rtB ->
azhllplsno , ni220kbneq . hlsjpbjuty , 108U ) ; if ( _rtB -> fkv340uzri <=
0.0 ) { iLeftU1 = 0U ; iRghtU1 = 0U ; } else if ( _rtB -> fkv340uzri >=
6000.0 ) { iLeftU1 = 100U ; iRghtU1 = 100U ; } else { iLeftU1 = ( uint32_T )
( ( _rtB -> fkv340uzri ) / 60.0 ) ; iRghtU1 = iLeftU1 + 1 ; } { real_T yTemp
; real_T u1Lambda ; real_T u0Lambda ; if ( iLeftU1 != iRghtU1 ) { { real_T
num = ( real_T ) ( _rtB -> fkv340uzri ) - ( iLeftU1 * 60.0 ) ; u1Lambda = num
/ 60.0 ; } } else { u1Lambda = 0.0 ; } if ( ( ni220kbneq . hlsjpbjuty [
iRghtU0 ] ) > ( ni220kbneq . hlsjpbjuty [ iLeftU0 ] ) ) { real_T num ; real_T
den ; den = ( ni220kbneq . hlsjpbjuty [ iRghtU0 ] ) ; den -= ( ni220kbneq .
hlsjpbjuty [ iLeftU0 ] ) ; num = _rtB -> azhllplsno ; num -= ( ni220kbneq .
hlsjpbjuty [ iLeftU0 ] ) ; u0Lambda = num / den ; } else { u0Lambda = 0.0 ; }
{ real_T yLeftCast ; real_T yRghtCast ; yLeftCast = ( ni220kbneq . lj0gbaycmo
[ ( iLeftU0 + 109U * iLeftU1 ) ] ) ; yRghtCast = ( ni220kbneq . lj0gbaycmo [
( iLeftU0 + 109U * iRghtU1 ) ] ) ; yLeftCast += u1Lambda * ( yRghtCast -
yLeftCast ) ; chrjv2ws5i = yLeftCast ; } { real_T yLeftCast ; real_T
yRghtCast ; yLeftCast = ( ni220kbneq . lj0gbaycmo [ ( iRghtU0 + 109U *
iLeftU1 ) ] ) ; yRghtCast = ( ni220kbneq . lj0gbaycmo [ ( iRghtU0 + 109U *
iRghtU1 ) ] ) ; yLeftCast += u1Lambda * ( yRghtCast - yLeftCast ) ; yTemp =
yLeftCast ; } { real_T yLeftCast ; real_T yRghtCast ; yLeftCast = chrjv2ws5i
; yRghtCast = yTemp ; yLeftCast += u0Lambda * ( yRghtCast - yLeftCast ) ;
chrjv2ws5i = yLeftCast ; } } } _rtB -> kxd50txmlc = 1.0351048413332149 *
chrjv2ws5i ; _rtB -> pakwij30bm = 1.933764640184292E-6 * _rtB -> kxd50txmlc ;
_rtB -> bzl3djz21a = muDoubleScalarSign ( _rtB -> iyq5z5g4dk ) ; _rtB ->
pvgkccuj44 = muDoubleScalarAbs ( _rtB -> iyq5z5g4dk ) ; _rtB -> op5rhm3cmy =
1.093 * _rtB -> pvgkccuj44 ; _rtB -> goucy4dmfb = 1.0464 * _rtB -> eqtatbfsoc
; { uint32_T iLeftU0 , iRghtU0 , iLeftU1 , iRghtU1 ;
HEV_acc_BINARYSEARCH_real_T ( & ( iLeftU0 ) , & ( iRghtU0 ) , _rtB ->
op5rhm3cmy , ni220kbneq . hlsjpbjuty , 108U ) ; if ( _rtB -> goucy4dmfb <=
0.0 ) { iLeftU1 = 0U ; iRghtU1 = 0U ; } else if ( _rtB -> goucy4dmfb >=
6000.0 ) { iLeftU1 = 100U ; iRghtU1 = 100U ; } else { iLeftU1 = ( uint32_T )
( ( _rtB -> goucy4dmfb ) / 60.0 ) ; iRghtU1 = iLeftU1 + 1 ; } { real_T yTemp
; real_T u1Lambda ; real_T u0Lambda ; if ( iLeftU1 != iRghtU1 ) { { real_T
num = ( real_T ) ( _rtB -> goucy4dmfb ) - ( iLeftU1 * 60.0 ) ; u1Lambda = num
/ 60.0 ; } } else { u1Lambda = 0.0 ; } if ( ( ni220kbneq . hlsjpbjuty [
iRghtU0 ] ) > ( ni220kbneq . hlsjpbjuty [ iLeftU0 ] ) ) { real_T num ; real_T
den ; den = ( ni220kbneq . hlsjpbjuty [ iRghtU0 ] ) ; den -= ( ni220kbneq .
hlsjpbjuty [ iLeftU0 ] ) ; num = _rtB -> op5rhm3cmy ; num -= ( ni220kbneq .
hlsjpbjuty [ iLeftU0 ] ) ; u0Lambda = num / den ; } else { u0Lambda = 0.0 ; }
{ real_T yLeftCast ; real_T yRghtCast ; yLeftCast = ( ni220kbneq . fiqfpbio0e
[ ( iLeftU0 + 109U * iLeftU1 ) ] ) ; yRghtCast = ( ni220kbneq . fiqfpbio0e [
( iLeftU0 + 109U * iRghtU1 ) ] ) ; yLeftCast += u1Lambda * ( yRghtCast -
yLeftCast ) ; c0prckfmta = yLeftCast ; } { real_T yLeftCast ; real_T
yRghtCast ; yLeftCast = ( ni220kbneq . fiqfpbio0e [ ( iRghtU0 + 109U *
iLeftU1 ) ] ) ; yRghtCast = ( ni220kbneq . fiqfpbio0e [ ( iRghtU0 + 109U *
iRghtU1 ) ] ) ; yLeftCast += u1Lambda * ( yRghtCast - yLeftCast ) ; yTemp =
yLeftCast ; } { real_T yLeftCast ; real_T yRghtCast ; yLeftCast = c0prckfmta
; yRghtCast = yTemp ; yLeftCast += u0Lambda * ( yRghtCast - yLeftCast ) ;
c0prckfmta = yLeftCast ; } } } _rtB -> e0qbqbep5f = 1.0351048413332149 *
c0prckfmta ; _rtB -> ncr5r2fzsv = _rtB -> bzl3djz21a * _rtB -> e0qbqbep5f ;
_rtB -> mevnxjmrpr = _rtB -> ncr5r2fzsv * _rtB -> ipbkkeuhyx ; _rtB ->
ihqfc3ppr1 = 1.933764640184292E-6 * _rtB -> mevnxjmrpr ; _rtB -> b0cd5wcoot =
_rtB -> pzjopfniir * _rtB -> iyq5z5g4dk ; if ( _rtB -> pakwij30bm <= 0.02 ) {
_rtB -> gz44io5s5u = 0.02 ; } else { _rtB -> gz44io5s5u = _rtB -> pakwij30bm
; } _rtB -> pw55n0hxqj = ( ( 0.0 - _rtB -> ihqfc3ppr1 ) - _rtB -> pv0hkzonpw
) - _rtB -> b0cd5wcoot ; _rtB -> fiznqggt3l = 1.0 / _rtB -> gz44io5s5u * _rtB
-> pw55n0hxqj ; ssCallAccelRunBlock ( S , 16 , 996 , SS_CALL_MDL_OUTPUTS ) ;
_rtB -> lvthxz35q2 = _rtB -> m2y1khvsri [ 9 ] * _rtB -> gsc0pyt5qr [ 2 ] ;
_rtB -> hmpiirraho = _rtB -> gsc0pyt5qr [ 3 ] * _rtB -> m2y1khvsri [ 6 ] ;
_rtB -> nyaqe33lbw = _rtB -> m2y1khvsri [ 8 ] * _rtB -> gsc0pyt5qr [ 11 ] ;
_rtB -> j3bq5daw1x = _rtB -> hmpiirraho + _rtB -> nyaqe33lbw ;
ssCallAccelRunBlock ( S , 16 , 1044 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 16 , 1045 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 16 , 1046 , SS_CALL_MDL_OUTPUTS ) ;
UNUSED_PARAMETER ( tid ) ; }
#define MDL_UPDATE
static void mdlUpdate ( SimStruct * S , int_T tid ) { real_T * lastU ;
fdj1laa40s * _rtB ; h04hj5x5sk * _rtDW ; _rtDW = ( ( h04hj5x5sk * )
ssGetRootDWork ( S ) ) ; _rtB = ( ( fdj1laa40s * ) _ssGetBlockIO ( S ) ) ; if
( ssIsSampleHit ( S , 2 , 0 ) ) { _rtDW -> epw20ibixm += 6.0E-5 * _rtB ->
dnc2vczue4 ; _rtDW -> emjtqjwqij += 6.0E-5 * _rtB -> jngfhp3qt3 ; _rtDW ->
aekc0mbj0y += 6.0E-5 * _rtB -> bfaypyat3p ; _rtDW -> oi2n4lur1q += 6.0E-5 *
_rtB -> mld1pdgowl ; _rtDW -> jnhtlxaxxk = _rtB -> n5hhjcgkxx ; } if (
ssIsSampleHit ( S , 2 , 0 ) ) { _rtDW -> eaosag5owj += 6.0E-5 * _rtB ->
m2y1khvsri [ 7 ] ; _rtDW -> jcugjk0yp0 += 6.0E-5 * _rtB -> bngrjsjriv ; _rtDW
-> jly33pdwub += 6.0E-5 * _rtB -> hq20ys4jiq ; _rtDW -> f2z5i2ds5e = _rtB ->
ptzrcdocdc [ 33 ] - - 0.999994000018 * _rtDW -> f2z5i2ds5e ; } if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtDW -> b50c0wk1dc = _rtB -> glnaf4fasi ; }
if ( ssIsSampleHit ( S , 2 , 0 ) ) { _rtDW -> o05rwe50bo = 0U ; _rtDW ->
pk42w2cjcz += 6.0E-5 * _rtB -> ptzrcdocdc [ 33 ] ; if ( _rtDW -> pk42w2cjcz
>= 25200.0 ) { _rtDW -> pk42w2cjcz = 25200.0 ; } else { if ( _rtDW ->
pk42w2cjcz <= rtMinusInf ) { _rtDW -> pk42w2cjcz = rtMinusInf ; } } if ( _rtB
-> l0j0hqaqrx > 0.0 ) { _rtDW -> f0fxu4veqt = 1 ; } else if ( _rtB ->
l0j0hqaqrx < 0.0 ) { _rtDW -> f0fxu4veqt = - 1 ; } else if ( _rtB ->
l0j0hqaqrx == 0.0 ) { _rtDW -> f0fxu4veqt = 0 ; } else { _rtDW -> f0fxu4veqt
= 2 ; } _rtDW -> fezg0yhyh2 = _rtB -> ptzrcdocdc [ 19 ] ; _rtDW -> hdqerfit1p
[ 0 ] = _rtB -> ptzrcdocdc [ 35 ] ; _rtDW -> hdqerfit1p [ 1 ] = _rtB ->
ptzrcdocdc [ 36 ] ; _rtDW -> hdqerfit1p [ 2 ] = _rtB -> ptzrcdocdc [ 37 ] ; }
if ( _rtDW -> mg242c3vwq == ( rtInf ) ) { _rtDW -> mg242c3vwq = ssGetTaskTime
( S , 0 ) ; _rtDW -> oiqwpboxgd = _rtB -> olmdvncqn2 ; } else if ( _rtDW ->
k1wt3kvmem == ( rtInf ) ) { _rtDW -> k1wt3kvmem = ssGetTaskTime ( S , 0 ) ;
_rtDW -> lzjsh0qxsz = _rtB -> olmdvncqn2 ; } else if ( _rtDW -> mg242c3vwq <
_rtDW -> k1wt3kvmem ) { _rtDW -> mg242c3vwq = ssGetTaskTime ( S , 0 ) ; _rtDW
-> oiqwpboxgd = _rtB -> olmdvncqn2 ; } else { _rtDW -> k1wt3kvmem =
ssGetTaskTime ( S , 0 ) ; _rtDW -> lzjsh0qxsz = _rtB -> olmdvncqn2 ; } if (
_rtDW -> cwivfg5ijd == ( rtInf ) ) { _rtDW -> cwivfg5ijd = ssGetTaskTime ( S
, 0 ) ; _rtDW -> kguctqvwvn = _rtB -> jn051xe0u0 ; } else if ( _rtDW ->
m1iuzueluk == ( rtInf ) ) { _rtDW -> m1iuzueluk = ssGetTaskTime ( S , 0 ) ;
_rtDW -> bvl1znuobh = _rtB -> jn051xe0u0 ; } else if ( _rtDW -> cwivfg5ijd <
_rtDW -> m1iuzueluk ) { _rtDW -> cwivfg5ijd = ssGetTaskTime ( S , 0 ) ; _rtDW
-> kguctqvwvn = _rtB -> jn051xe0u0 ; } else { _rtDW -> m1iuzueluk =
ssGetTaskTime ( S , 0 ) ; _rtDW -> bvl1znuobh = _rtB -> jn051xe0u0 ; } if (
ssIsSampleHit ( S , 2 , 0 ) ) { _rtDW -> bvad1zjfik = _rtB -> gjh03haoma [ 0
] ; } if ( _rtDW -> hfvh40s0je == ( rtInf ) ) { _rtDW -> hfvh40s0je =
ssGetTaskTime ( S , 0 ) ; _rtDW -> lidlmlim32 = _rtB -> hu13clizcm ; } else
if ( _rtDW -> f41a3yqptq == ( rtInf ) ) { _rtDW -> f41a3yqptq = ssGetTaskTime
( S , 0 ) ; _rtDW -> aq3qjo4ji4 = _rtB -> hu13clizcm ; } else if ( _rtDW ->
hfvh40s0je < _rtDW -> f41a3yqptq ) { _rtDW -> hfvh40s0je = ssGetTaskTime ( S
, 0 ) ; _rtDW -> lidlmlim32 = _rtB -> hu13clizcm ; } else { _rtDW ->
f41a3yqptq = ssGetTaskTime ( S , 0 ) ; _rtDW -> aq3qjo4ji4 = _rtB ->
hu13clizcm ; } if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtDW -> aln04uuynj =
_rtB -> hu13clizcm ; _rtDW -> nlh5qppt4m = _rtB -> ersrpfk3o2 ; } if (
ssIsSampleHit ( S , 2 , 0 ) ) { _rtDW -> bro0cn1wmi = _rtB -> ptzrcdocdc [ 23
] ; _rtDW -> j31s1kcymk [ 0 ] = _rtB -> ptzrcdocdc [ 38 ] ; _rtDW ->
j31s1kcymk [ 1 ] = _rtB -> ptzrcdocdc [ 39 ] ; _rtDW -> j31s1kcymk [ 2 ] =
_rtB -> ptzrcdocdc [ 40 ] ; } if ( ssIsSampleHit ( S , 3 , 0 ) ) { _rtDW ->
gsr0ogd2xb = _rtB -> jsrftgte5f ; } if ( _rtDW -> joiszbfghn == ( rtInf ) ) {
_rtDW -> joiszbfghn = ssGetTaskTime ( S , 0 ) ; _rtDW -> narm2z4h4g = _rtB ->
ewebcl0qdv ; } else if ( _rtDW -> jlnwqqs23l == ( rtInf ) ) { _rtDW ->
jlnwqqs23l = ssGetTaskTime ( S , 0 ) ; _rtDW -> miwjijsda1 = _rtB ->
ewebcl0qdv ; } else if ( _rtDW -> joiszbfghn < _rtDW -> jlnwqqs23l ) { _rtDW
-> joiszbfghn = ssGetTaskTime ( S , 0 ) ; _rtDW -> narm2z4h4g = _rtB ->
ewebcl0qdv ; } else { _rtDW -> jlnwqqs23l = ssGetTaskTime ( S , 0 ) ; _rtDW
-> miwjijsda1 = _rtB -> ewebcl0qdv ; } if ( ssIsSampleHit ( S , 2 , 0 ) ) {
_rtDW -> kzrq2xyp0f = _rtB -> kstuixbrhz ; _rtDW -> nonllthbl2 = _rtB ->
ixhf3zpb2w - - 0.94176453358424872 * _rtDW -> nonllthbl2 ; _rtDW ->
kol45dq53x = _rtB -> pvrtgxnfdc - - 0.94176453358424872 * _rtDW -> kol45dq53x
; _rtDW -> fw2k5vojpd = _rtB -> pksqcqhxle ; _rtDW -> ehaijafsot = _rtB ->
ptzrcdocdc [ 19 ] ; _rtDW -> lvw3lta2fy = _rtB -> ft15o4y5jn - -
0.94176453358424872 * _rtDW -> lvw3lta2fy ; _rtDW -> c20b4oc1jp = _rtB ->
efjx13ngvd - - 0.94176453358424872 * _rtDW -> c20b4oc1jp ; _rtDW ->
lp13v2ihui = _rtB -> boedvgyxkk ; _rtDW -> kopxzfb0sb = _rtB -> ptzrcdocdc [
23 ] ; _rtDW -> ebwur5qeqq = _rtB -> gnpfhoxjb1 ; ssCallAccelRunBlock ( S ,
16 , 516 , SS_CALL_MDL_UPDATE ) ; } if ( _rtDW -> n33aen2wbt == ( rtInf ) ) {
_rtDW -> n33aen2wbt = ssGetTaskTime ( S , 0 ) ; _rtDW -> evmu5j4txb = _rtB ->
laaoigtxzq ; } else if ( _rtDW -> fjojh4ewqs == ( rtInf ) ) { _rtDW ->
fjojh4ewqs = ssGetTaskTime ( S , 0 ) ; _rtDW -> d21ysphefx = _rtB ->
laaoigtxzq ; } else if ( _rtDW -> n33aen2wbt < _rtDW -> fjojh4ewqs ) { _rtDW
-> n33aen2wbt = ssGetTaskTime ( S , 0 ) ; _rtDW -> evmu5j4txb = _rtB ->
laaoigtxzq ; } else { _rtDW -> fjojh4ewqs = ssGetTaskTime ( S , 0 ) ; _rtDW
-> d21ysphefx = _rtB -> laaoigtxzq ; } if ( _rtDW -> nolj4flzwb == ( rtInf )
) { _rtDW -> nolj4flzwb = ssGetTaskTime ( S , 0 ) ; _rtDW -> ppmw3hzciy =
_rtB -> eclqlk2jz3 ; } else if ( _rtDW -> bluedlz4ee == ( rtInf ) ) { _rtDW
-> bluedlz4ee = ssGetTaskTime ( S , 0 ) ; _rtDW -> awi4nxie0m = _rtB ->
eclqlk2jz3 ; } else if ( _rtDW -> nolj4flzwb < _rtDW -> bluedlz4ee ) { _rtDW
-> nolj4flzwb = ssGetTaskTime ( S , 0 ) ; _rtDW -> ppmw3hzciy = _rtB ->
eclqlk2jz3 ; } else { _rtDW -> bluedlz4ee = ssGetTaskTime ( S , 0 ) ; _rtDW
-> awi4nxie0m = _rtB -> eclqlk2jz3 ; } if ( ssIsSampleHit ( S , 3 , 0 ) ) {
_rtDW -> bv5gvrfela = _rtB -> fhtdciv4bw ; } if ( ssIsSampleHit ( S , 2 , 0 )
) { _rtDW -> pe31gvq3pv = _rtB -> d53qabdhri - - 0.98651999976973315 * _rtDW
-> pe31gvq3pv ; _rtDW -> bw5cwo255x = _rtB -> hy1c0w2zn1 - -
0.98651999976973315 * _rtDW -> bw5cwo255x ; _rtDW -> l2t4rgxmml = _rtB ->
gtnxjfzazw [ 0 ] ; } if ( ssIsSampleHit ( S , 2 , 0 ) ) { _rtDW -> dy4ppyw4mo
= _rtB -> ogrxkbaunf - - 0.98651999976973315 * _rtDW -> dy4ppyw4mo ; _rtDW ->
hmybg5b1mi = _rtB -> l3tn2h3her - - 0.98651999976973315 * _rtDW -> hmybg5b1mi
; _rtDW -> gkq12xkctn = _rtB -> egjon3bn1l [ 0 ] ; _rtDW -> llu3sg1ihp = 0U ;
_rtDW -> fj2gixcnhk = 3.0E-5 * _rtB -> dkrybiu0am + _rtB -> az1l3lujmm ; if (
_rtDW -> fj2gixcnhk >= 1.0 ) { _rtDW -> fj2gixcnhk = 1.0 ; } else { if (
_rtDW -> fj2gixcnhk <= - 1.0 ) { _rtDW -> fj2gixcnhk = - 1.0 ; } } _rtDW ->
dco4afubi3 = _rtB -> ipw0m5d5ah ; } if ( _rtDW -> ewhcynzuun == ( rtInf ) ) {
_rtDW -> ewhcynzuun = ssGetTaskTime ( S , 0 ) ; _rtDW -> h4ipbzntlo = _rtB ->
bdot1hoyd4 ; } else if ( _rtDW -> ciu3b0lpet == ( rtInf ) ) { _rtDW ->
ciu3b0lpet = ssGetTaskTime ( S , 0 ) ; _rtDW -> mmlyeyihwy = _rtB ->
bdot1hoyd4 ; } else if ( _rtDW -> ewhcynzuun < _rtDW -> ciu3b0lpet ) { _rtDW
-> ewhcynzuun = ssGetTaskTime ( S , 0 ) ; _rtDW -> h4ipbzntlo = _rtB ->
bdot1hoyd4 ; } else { _rtDW -> ciu3b0lpet = ssGetTaskTime ( S , 0 ) ; _rtDW
-> mmlyeyihwy = _rtB -> bdot1hoyd4 ; } if ( ssIsSampleHit ( S , 2 , 0 ) ) {
_rtDW -> jctbfc4f1e = _rtB -> f0oijtvdsb - - 0.96300265339697488 * _rtDW ->
jctbfc4f1e ; _rtDW -> h4pa1qmmy5 = 0U ; _rtDW -> olv3cnxtoy = 3.0E-5 * _rtB
-> buk0lzzgpx + _rtB -> peiuomqxy4 ; if ( _rtDW -> olv3cnxtoy >= 1.0 ) {
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
nlkba1lokv = _rtB -> jvnivwhexw ; _rtXdot -> eackaa2e5o = _rtB -> fiznqggt3l
; _rtXdot -> a3p154yttn = _rtB -> mtsrafprq4 ; _rtXdot -> lvhb24m1u3 [ 0 ] =
0.0 ; _rtXdot -> lvhb24m1u3 [ 1 ] = 0.0 ; _rtXdot -> lvhb24m1u3 [ 0 ] += -
20.106192982974676 * _rtX -> lvhb24m1u3 [ 0 ] ; _rtXdot -> lvhb24m1u3 [ 0 ]
+= - 157.91367041742973 * _rtX -> lvhb24m1u3 [ 1 ] ; _rtXdot -> lvhb24m1u3 [
1 ] += _rtX -> lvhb24m1u3 [ 0 ] ; _rtXdot -> lvhb24m1u3 [ 0 ] += _rtB ->
hzqyysp3lg ; _rtXdot -> oiuvfykmtf = _rtB -> cbxuzb05j1 ; _rtXdot ->
pi4mr5hhgl = _rtB -> cwjl3j1x5k ; _rtXdot -> bjc4xqhn0t = _rtB -> najtolxp1g
; _rtXdot -> oy1vxpvao1 = _rtB -> mkg0mz45iy ; _rtXdot -> iglmayn3zq = _rtB
-> jn2wa1f4jf ; _rtXdot -> p24x5vnk3x = _rtB -> iqazxwtowf ; _rtXdot ->
jntxheunx4 = _rtB -> e1dlbtwqho ; _rtXdot -> ix50zu3rlz = 0.0 ; _rtXdot ->
ix50zu3rlz += - 125.66370614359172 * _rtX -> ix50zu3rlz ; _rtXdot ->
ix50zu3rlz += _rtB -> mkg0mz45iy ; { boolean_T lsat ; boolean_T usat ; lsat =
( ( ( hgl3elxkcb * ) ssGetContStates ( S ) ) -> f0udlm3lxk <= ( - 5.0 ) ) ;
usat = ( ( ( hgl3elxkcb * ) ssGetContStates ( S ) ) -> f0udlm3lxk >= 5.0 ) ;
if ( ( ! lsat && ! usat ) || ( lsat && ( _rtB -> oodc01xuy0 > 0 ) ) || ( usat
&& ( _rtB -> oodc01xuy0 < 0 ) ) ) { ( ( aab5tqo4s5 * ) ssGetdX ( S ) ) ->
f0udlm3lxk = _rtB -> oodc01xuy0 ; } else { ( ( aab5tqo4s5 * ) ssGetdX ( S ) )
-> f0udlm3lxk = 0.0 ; } } }
#define MDL_PROJECTION
static void mdlProjection ( SimStruct * S ) { fdj1laa40s * _rtB ; h04hj5x5sk
* _rtDW ; _rtDW = ( ( h04hj5x5sk * ) ssGetRootDWork ( S ) ) ; _rtB = ( (
fdj1laa40s * ) _ssGetBlockIO ( S ) ) ; ssCallAccelRunBlock ( S , 16 , 30 ,
SS_CALL_MDL_PROJECTION ) ; } static void mdlInitializeSizes ( SimStruct * S )
{ ssSetChecksumVal ( S , 0 , 2410715260U ) ; ssSetChecksumVal ( S , 1 ,
2381568792U ) ; ssSetChecksumVal ( S , 2 , 3894532594U ) ; ssSetChecksumVal (
S , 3 , 4209743827U ) ; { mxArray * slVerStructMat = NULL ; mxArray *
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
