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
mdlOutputs ( SimStruct * S , int_T tid ) { real_T o42x43zzka ; real_T
lrwvvimtdv ; real_T or4xk0d2hg ; real_T jk5r3ummcw ; real_T k0ayfyp2ys ;
real_T kfa2w4tlhe ; real_T avmmym1aoe ; real_T eso44m1g0y ; real_T jgewyk5b21
; real_T jpmexbyjov ; boolean_T m5tsngcasr ; int32_T rowIdx ; real_T * lastU
; boolean_T o3khhk3fbg ; uint8_T h100jbae3x ; real_T iiis24gb3o ; real_T
jwhz1ujp3w ; real_T ehtkh2wauy ; real_T mkcfwi2fsi ; real_T ehcygfucdl ;
real_T po0ockmy2b ; real_T mizlp41tvx ; real_T f4ufgq33gz ; real_T i5nu34w4uj
; real_T dztyrqu4xa ; real_T eskeehll14 ; real_T ckrl0nmlwt ; real_T
lduwq00gqj ; real_T byehzqrbel ; boolean_T fviymzl3aa ; real_T j0jhyqa1p3 ;
real_T aqlslovppe ; real_T dyfxp2slod ; real_T dk4tk42hhp ; real_T ctpq3axefx
; real_T f1b5simhxh ; real_T lstej3qx0u ; real_T h0cg4jnrg5 ; real_T
lfv3m5pb5c ; real_T f2e3v5ccex ; real_T lebvfutt11 ; real_T f0kpvfzk1l_idx_0
; real_T f0kpvfzk1l_idx_1 ; real_T f0kpvfzk1l_idx_2 ; ZCEventType
zcEvent_idx_0 ; ZCEventType zcEvent_idx_1 ; ZCEventType zcEvent_idx_2 ;
fdj1laa40s * _rtB ; baqezl5ja5 * _rtP ; hgl3elxkcb * _rtX ; bu2ncqpcar *
_rtZCE ; h04hj5x5sk * _rtDW ; _rtDW = ( ( h04hj5x5sk * ) ssGetRootDWork ( S )
) ; _rtZCE = ( ( bu2ncqpcar * ) _ssGetPrevZCSigState ( S ) ) ; _rtX = ( (
hgl3elxkcb * ) ssGetContStates ( S ) ) ; _rtP = ( ( baqezl5ja5 * )
ssGetDefaultParam ( S ) ) ; _rtB = ( ( fdj1laa40s * ) _ssGetBlockIO ( S ) ) ;
_rtB -> oyax3xl0wd = _rtX -> mh2wvbi24o ; _rtB -> lgvxgvk2jz = _rtB ->
oyax3xl0wd - ld5zvvrfqt ( S ) -> jlwezbsnkj ; _rtB -> ex3lseplqd = 0.0 * _rtB
-> lgvxgvk2jz ; _rtB -> lqxhreuofv = _rtB -> lgvxgvk2jz * ( real_T )
ld5zvvrfqt ( S ) -> exzcbmkl1r ; o3khhk3fbg = ( _rtB -> lqxhreuofv >=
ld5zvvrfqt ( S ) -> ebavdybpm4 ) ; _rtB -> gefbo3hjnd = _rtB -> ex3lseplqd *
( real_T ) o3khhk3fbg ; _rtB -> evt01lyvlo [ 0 ] = ld5zvvrfqt ( S ) ->
antxvfk3tq ; _rtB -> evt01lyvlo [ 1 ] = ld5zvvrfqt ( S ) -> fb3mkq0xr3 ; _rtB
-> evt01lyvlo [ 2 ] = ld5zvvrfqt ( S ) -> etktkukwpn ; _rtB -> evt01lyvlo [ 3
] = ld5zvvrfqt ( S ) -> e21g4clfl3 ; _rtB -> evt01lyvlo [ 4 ] = ld5zvvrfqt (
S ) -> o1b4mu1i2k ; _rtB -> evt01lyvlo [ 5 ] = ld5zvvrfqt ( S ) -> lc1ibr4hvr
; _rtB -> evt01lyvlo [ 6 ] = ld5zvvrfqt ( S ) -> bl5vufhrs4 ; _rtB ->
evt01lyvlo [ 7 ] = ld5zvvrfqt ( S ) -> mdyaxyrslt ; _rtB -> evt01lyvlo [ 8 ]
= ld5zvvrfqt ( S ) -> mnzoe25v0y ; _rtB -> evt01lyvlo [ 9 ] = ld5zvvrfqt ( S
) -> ghxc355dwt ; _rtB -> evt01lyvlo [ 10 ] = ld5zvvrfqt ( S ) -> itrlonvvcm
; _rtB -> evt01lyvlo [ 11 ] = ld5zvvrfqt ( S ) -> nadkun0wxj ; _rtB ->
evt01lyvlo [ 12 ] = ld5zvvrfqt ( S ) -> lzxjeftypt ; _rtB -> evt01lyvlo [ 13
] = ld5zvvrfqt ( S ) -> lvjngh1qvy ; _rtB -> evt01lyvlo [ 14 ] = ld5zvvrfqt (
S ) -> pg35t525g4 ; _rtB -> evt01lyvlo [ 15 ] = ld5zvvrfqt ( S ) ->
ll0pljtxac ; _rtB -> evt01lyvlo [ 16 ] = ld5zvvrfqt ( S ) -> naqiut5cmm ;
ssCallAccelRunBlock ( S , 15 , 29 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 15 , 30 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
pevp3t1c1i = _rtB -> deyer4xufx [ 12 ] - _rtB -> deyer4xufx [ 0 ] ; _rtB ->
idxwjmkb2s = 0.2079 * _rtB -> pevp3t1c1i ; _rtB -> l45hanl2nu = ( real_T )
o3khhk3fbg * _rtB -> idxwjmkb2s ; _rtB -> fmnf2kkpjk = ( 0.0 - _rtB ->
gefbo3hjnd ) - _rtB -> l45hanl2nu ; _rtB -> mopvfpxa20 = _rtB -> oyax3xl0wd +
ld5zvvrfqt ( S ) -> lo2b5mmfm3 ; _rtB -> mvhtmqpn2v = 0.0 * _rtB ->
mopvfpxa20 ; _rtB -> p2y2auk1nz = _rtB -> mopvfpxa20 * ( real_T ) ld5zvvrfqt
( S ) -> ebcjp1hl21 ; o3khhk3fbg = ( _rtB -> p2y2auk1nz <= ld5zvvrfqt ( S )
-> huw1l5nago ) ; _rtB -> mmwbawwcvg = _rtB -> mvhtmqpn2v * ( real_T )
o3khhk3fbg ; _rtB -> opui1amaqt = 0.2079 * _rtB -> pevp3t1c1i ; _rtB ->
ckuvoe5obn = ( real_T ) o3khhk3fbg * _rtB -> opui1amaqt ; _rtB -> payadlosqk
= ( 0.0 - _rtB -> mmwbawwcvg ) - _rtB -> ckuvoe5obn ; _rtB -> ip0jfv1dd4 =
_rtB -> payadlosqk * ( real_T ) ld5zvvrfqt ( S ) -> gf4cdvtw1m ; _rtB ->
lwgbf1qmzs = ( 0.0 - _rtB -> fmnf2kkpjk ) - _rtB -> ip0jfv1dd4 ; _rtB ->
miijnofofp = _rtX -> nlkba1lokv ; _rtB -> dhno0gj2ao = _rtB -> miijnofofp -
ld5zvvrfqt ( S ) -> in0pqet3mj ; _rtB -> gthdfazugd = 0.0 * _rtB ->
dhno0gj2ao ; _rtB -> nuftbzfpl2 = _rtB -> dhno0gj2ao * ( real_T ) ld5zvvrfqt
( S ) -> ov3x0yvwgc ; o3khhk3fbg = ( _rtB -> nuftbzfpl2 >= ld5zvvrfqt ( S )
-> m4xydklre5 ) ; _rtB -> afnruxzgre = _rtB -> gthdfazugd * ( real_T )
o3khhk3fbg ; _rtB -> oogljaqwka = _rtB -> deyer4xufx [ 1 ] - _rtB ->
deyer4xufx [ 4 ] ; _rtB -> f5frzvsuah = 0.1 * _rtB -> oogljaqwka ; _rtB ->
my5ot0o10y = ( real_T ) o3khhk3fbg * _rtB -> f5frzvsuah ; _rtB -> ng1tnhzqnk
= ( 0.0 - _rtB -> afnruxzgre ) - _rtB -> my5ot0o10y ; _rtB -> jguetwojgk =
_rtB -> miijnofofp + ld5zvvrfqt ( S ) -> e0lnpdkdea ; _rtB -> im521ya20g =
0.0 * _rtB -> jguetwojgk ; _rtB -> c3f3qu0xds = _rtB -> jguetwojgk * ( real_T
) ld5zvvrfqt ( S ) -> izumiqlf44 ; o3khhk3fbg = ( _rtB -> c3f3qu0xds <=
ld5zvvrfqt ( S ) -> dmsyqpvwdr ) ; _rtB -> fz4cbnmrx2 = _rtB -> im521ya20g *
( real_T ) o3khhk3fbg ; _rtB -> bvyof2spsr = 0.1 * _rtB -> oogljaqwka ; _rtB
-> of3xybxcdb = ( real_T ) o3khhk3fbg * _rtB -> bvyof2spsr ; _rtB ->
iyaxtisr2c = ( 0.0 - _rtB -> fz4cbnmrx2 ) - _rtB -> of3xybxcdb ; _rtB ->
maw5bq4fdn = _rtB -> iyaxtisr2c * ( real_T ) ld5zvvrfqt ( S ) -> llvdljiimi ;
_rtB -> kmftmcmoyv = ( 0.0 - _rtB -> ng1tnhzqnk ) - _rtB -> maw5bq4fdn ; _rtB
-> mwxn3abhxy = - _rtB -> kmftmcmoyv ; _rtB -> bn3r3upnmr = _rtX ->
eackaa2e5o ; _rtB -> cvcqn2f3ws = _rtX -> a3p154yttn ; _rtB -> conzimif1t =
muDoubleScalarAbs ( _rtB -> cvcqn2f3ws ) ; o3khhk3fbg = ( ld5zvvrfqt ( S ) ->
jzkomyri2u > _rtB -> conzimif1t ) ; _rtB -> cwo3ekdsbt = o3khhk3fbg ; _rtB ->
duwegvciyh = 0.4 * _rtB -> conzimif1t ; _rtB -> ed1ycrn3es =
3.1415926535897931 * _rtB -> duwegvciyh ; _rtB -> cutyphodab = (
muDoubleScalarCos ( _rtB -> ed1ycrn3es ) + 1.0 ) * 770.0 ; _rtB -> epb4i2r1qk
= 0.5 * _rtB -> cutyphodab ; _rtB -> ktgy2bbun0 = 9.6688232009214591E-6 *
_rtB -> epb4i2r1qk ; _rtB -> kjersnerwx = 0.3 * _rtB -> deyer4xufx [ 2 ] ;
_rtB -> fugepgv240 = _rtB -> cvcqn2f3ws - _rtB -> kjersnerwx ; _rtB ->
awmabzprgs = _rtB -> cwo3ekdsbt * _rtB -> ktgy2bbun0 * _rtB -> fugepgv240 ;
_rtB -> fw0sopdk50 = _rtB -> bn3r3upnmr - _rtB -> awmabzprgs ; _rtB ->
mq3ctgfwcu = muDoubleScalarSign ( _rtB -> fw0sopdk50 ) ; _rtB -> h21ecxh5bl =
muDoubleScalarAbs ( _rtB -> fw0sopdk50 ) ; _rtB -> dso0kuhggp = 1.093 * _rtB
-> h21ecxh5bl ; _rtB -> jdi4pvz5xz = 0.0 ; _rtB -> jdi4pvz5xz += 0.0 * _rtX
-> lvhb24m1u3 [ 0 ] ; _rtB -> jdi4pvz5xz += 157.91367041742973 * _rtX ->
lvhb24m1u3 [ 1 ] ; _rtB -> al3btfvfb5 = muDoubleScalarSign ( _rtB ->
cvcqn2f3ws ) ; _rtB -> ddz0iszih1 = _rtB -> cvcqn2f3ws * _rtB -> cvcqn2f3ws *
_rtB -> al3btfvfb5 ; _rtB -> fiyzas3vsx = 0.5 * _rtB -> ddz0iszih1 ; _rtB ->
bne4ib3niv = 1.2 * _rtB -> fiyzas3vsx ; _rtB -> euvt3qdmtp = 0.26 * _rtB ->
bne4ib3niv ; _rtB -> nnvhzguiuk = 2.57 * _rtB -> euvt3qdmtp ; _rtB ->
piubr01e4o = ( ( 0.0 - ld5zvvrfqt ( S ) -> hz4isiiiw4 ) - _rtB -> jdi4pvz5xz
) - _rtB -> nnvhzguiuk ; _rtB -> aaey5bq5wb = 0.18518518518518517 * _rtB ->
piubr01e4o ; _rtB -> ojkpa2tz4q = ( ld5zvvrfqt ( S ) -> ihqyjh43nc - _rtB ->
aaey5bq5wb ) + ld5zvvrfqt ( S ) -> cmgte30pgc ; if ( _rtB -> ojkpa2tz4q <=
0.0 ) { _rtB -> fdxtksxpa1 = 0.0 ; } else { _rtB -> fdxtksxpa1 = _rtB ->
ojkpa2tz4q ; } _rtB -> c450kisfxg = 1.0464 * _rtB -> fdxtksxpa1 ; { uint32_T
iLeftU0 , iRghtU0 , iLeftU1 , iRghtU1 ; HEV_acc_BINARYSEARCH_real_T ( & (
iLeftU0 ) , & ( iRghtU0 ) , _rtB -> dso0kuhggp , ni220kbneq . hlsjpbjuty ,
108U ) ; if ( _rtB -> c450kisfxg <= 0.0 ) { iLeftU1 = 0U ; iRghtU1 = 0U ; }
else if ( _rtB -> c450kisfxg >= 6000.0 ) { iLeftU1 = 100U ; iRghtU1 = 100U ;
} else { iLeftU1 = ( uint32_T ) ( ( _rtB -> c450kisfxg ) / 60.0 ) ; iRghtU1 =
iLeftU1 + 1 ; } { real_T yTemp ; real_T u1Lambda ; real_T u0Lambda ; if (
iLeftU1 != iRghtU1 ) { { real_T num = ( real_T ) ( _rtB -> c450kisfxg ) - (
iLeftU1 * 60.0 ) ; u1Lambda = num / 60.0 ; } } else { u1Lambda = 0.0 ; } if (
( ni220kbneq . hlsjpbjuty [ iRghtU0 ] ) > ( ni220kbneq . hlsjpbjuty [ iLeftU0
] ) ) { real_T num ; real_T den ; den = ( ni220kbneq . hlsjpbjuty [ iRghtU0 ]
) ; den -= ( ni220kbneq . hlsjpbjuty [ iLeftU0 ] ) ; num = _rtB -> dso0kuhggp
; num -= ( ni220kbneq . hlsjpbjuty [ iLeftU0 ] ) ; u0Lambda = num / den ; }
else { u0Lambda = 0.0 ; } { real_T yLeftCast ; real_T yRghtCast ; yLeftCast =
( ni220kbneq . bhvyvhymk2 [ ( iLeftU0 + 109U * iLeftU1 ) ] ) ; yRghtCast = (
ni220kbneq . bhvyvhymk2 [ ( iLeftU0 + 109U * iRghtU1 ) ] ) ; yLeftCast +=
u1Lambda * ( yRghtCast - yLeftCast ) ; o42x43zzka = yLeftCast ; } { real_T
yLeftCast ; real_T yRghtCast ; yLeftCast = ( ni220kbneq . bhvyvhymk2 [ (
iRghtU0 + 109U * iLeftU1 ) ] ) ; yRghtCast = ( ni220kbneq . bhvyvhymk2 [ (
iRghtU0 + 109U * iRghtU1 ) ] ) ; yLeftCast += u1Lambda * ( yRghtCast -
yLeftCast ) ; yTemp = yLeftCast ; } { real_T yLeftCast ; real_T yRghtCast ;
yLeftCast = o42x43zzka ; yRghtCast = yTemp ; yLeftCast += u0Lambda * (
yRghtCast - yLeftCast ) ; o42x43zzka = yLeftCast ; } } } _rtB -> ayj1hz2ysv =
1.0351048413332149 * o42x43zzka ; _rtB -> lvcp0zglue = _rtB -> mq3ctgfwcu *
_rtB -> ayj1hz2ysv ; _rtB -> gdnkayhhft = 0.3 * _rtB -> lvcp0zglue ; _rtB ->
hg4wowaxzw = - _rtB -> gdnkayhhft ; _rtB -> mxteghcp0h = _rtX -> oiuvfykmtf ;
_rtB -> aesjc5pkai = muDoubleScalarAbs ( _rtB -> cvcqn2f3ws ) ; o3khhk3fbg =
( ld5zvvrfqt ( S ) -> g3osblikoy > _rtB -> aesjc5pkai ) ; _rtB -> ffaltc4fnw
= o3khhk3fbg ; _rtB -> nqjzy5ayb3 = 0.4 * _rtB -> aesjc5pkai ; _rtB ->
izocizlp0w = 3.1415926535897931 * _rtB -> nqjzy5ayb3 ; _rtB -> mafzi51yud = (
muDoubleScalarCos ( _rtB -> izocizlp0w ) + 1.0 ) * 770.0 ; _rtB -> avuti3okp2
= 0.5 * _rtB -> mafzi51yud ; _rtB -> koyq1yjqok = 9.6688232009214591E-6 *
_rtB -> avuti3okp2 ; _rtB -> eni4xlvi1y = 0.3 * _rtB -> deyer4xufx [ 3 ] ;
_rtB -> mwmukr1b0s = _rtB -> cvcqn2f3ws - _rtB -> eni4xlvi1y ; _rtB ->
eeizlv44hv = _rtB -> ffaltc4fnw * _rtB -> koyq1yjqok * _rtB -> mwmukr1b0s ;
_rtB -> du2r4wdubo = _rtB -> mxteghcp0h - _rtB -> eeizlv44hv ; _rtB ->
cc2mxw3opu = muDoubleScalarSign ( _rtB -> du2r4wdubo ) ; _rtB -> dudm5smb15 =
muDoubleScalarAbs ( _rtB -> du2r4wdubo ) ; _rtB -> ivbyr1xfyv = 1.093 * _rtB
-> dudm5smb15 ; _rtB -> nowxzba34h = ( _rtB -> aaey5bq5wb + ld5zvvrfqt ( S )
-> lewwvpuidz ) + ld5zvvrfqt ( S ) -> djg5tpfirw ; if ( _rtB -> nowxzba34h <=
0.0 ) { _rtB -> f32s5izkc1 = 0.0 ; } else { _rtB -> f32s5izkc1 = _rtB ->
nowxzba34h ; } _rtB -> k1v551ilne = 1.0464 * _rtB -> f32s5izkc1 ; { uint32_T
iLeftU0 , iRghtU0 , iLeftU1 , iRghtU1 ; HEV_acc_BINARYSEARCH_real_T ( & (
iLeftU0 ) , & ( iRghtU0 ) , _rtB -> ivbyr1xfyv , ni220kbneq . hlsjpbjuty ,
108U ) ; if ( _rtB -> k1v551ilne <= 0.0 ) { iLeftU1 = 0U ; iRghtU1 = 0U ; }
else if ( _rtB -> k1v551ilne >= 6000.0 ) { iLeftU1 = 100U ; iRghtU1 = 100U ;
} else { iLeftU1 = ( uint32_T ) ( ( _rtB -> k1v551ilne ) / 60.0 ) ; iRghtU1 =
iLeftU1 + 1 ; } { real_T yTemp ; real_T u1Lambda ; real_T u0Lambda ; if (
iLeftU1 != iRghtU1 ) { { real_T num = ( real_T ) ( _rtB -> k1v551ilne ) - (
iLeftU1 * 60.0 ) ; u1Lambda = num / 60.0 ; } } else { u1Lambda = 0.0 ; } if (
( ni220kbneq . hlsjpbjuty [ iRghtU0 ] ) > ( ni220kbneq . hlsjpbjuty [ iLeftU0
] ) ) { real_T num ; real_T den ; den = ( ni220kbneq . hlsjpbjuty [ iRghtU0 ]
) ; den -= ( ni220kbneq . hlsjpbjuty [ iLeftU0 ] ) ; num = _rtB -> ivbyr1xfyv
; num -= ( ni220kbneq . hlsjpbjuty [ iLeftU0 ] ) ; u0Lambda = num / den ; }
else { u0Lambda = 0.0 ; } { real_T yLeftCast ; real_T yRghtCast ; yLeftCast =
( ni220kbneq . bhvyvhymk2 [ ( iLeftU0 + 109U * iLeftU1 ) ] ) ; yRghtCast = (
ni220kbneq . bhvyvhymk2 [ ( iLeftU0 + 109U * iRghtU1 ) ] ) ; yLeftCast +=
u1Lambda * ( yRghtCast - yLeftCast ) ; lrwvvimtdv = yLeftCast ; } { real_T
yLeftCast ; real_T yRghtCast ; yLeftCast = ( ni220kbneq . bhvyvhymk2 [ (
iRghtU0 + 109U * iLeftU1 ) ] ) ; yRghtCast = ( ni220kbneq . bhvyvhymk2 [ (
iRghtU0 + 109U * iRghtU1 ) ] ) ; yLeftCast += u1Lambda * ( yRghtCast -
yLeftCast ) ; yTemp = yLeftCast ; } { real_T yLeftCast ; real_T yRghtCast ;
yLeftCast = lrwvvimtdv ; yRghtCast = yTemp ; yLeftCast += u0Lambda * (
yRghtCast - yLeftCast ) ; lrwvvimtdv = yLeftCast ; } } } _rtB -> bw4zu0y452 =
1.0351048413332149 * lrwvvimtdv ; _rtB -> jl0wk2sppa = _rtB -> cc2mxw3opu *
_rtB -> bw4zu0y452 ; _rtB -> ixygmq3gc5 = 0.3 * _rtB -> jl0wk2sppa ; _rtB ->
p4hehek2r5 = - _rtB -> ixygmq3gc5 ; if ( ssIsSampleHit ( S , 2 , 0 ) ) { _rtB
-> itq4augluc = _rtDW -> epw20ibixm ; _rtB -> iwocvn0p4u = _rtDW ->
emjtqjwqij ; _rtB -> fp3x4xex4t = ( - 0.00045907990073600015 * _rtB ->
itq4augluc * _rtB -> iwocvn0p4u + 0.175666143629361 * _rtB -> itq4augluc ) *
6.0 ; if ( _rtB -> fp3x4xex4t > 400.0 ) { _rtB -> bj4zdemj02 = 400.0 ; } else
if ( _rtB -> fp3x4xex4t < - 400.0 ) { _rtB -> bj4zdemj02 = - 400.0 ; } else {
_rtB -> bj4zdemj02 = _rtB -> fp3x4xex4t ; } _rtB -> bei1xfdtco = _rtDW ->
aekc0mbj0y ; _rtB -> hvatssmzeb = _rtDW -> oi2n4lur1q ; _rtB -> au4vfwszcw =
( 0.0 * _rtB -> bei1xfdtco * _rtB -> hvatssmzeb + 0.192 * _rtB -> bei1xfdtco
) * 1.5 ; if ( _rtB -> au4vfwszcw > 400.0 ) { _rtB -> aiwl23f22u = 400.0 ; }
else if ( _rtB -> au4vfwszcw < - 400.0 ) { _rtB -> aiwl23f22u = - 400.0 ; }
else { _rtB -> aiwl23f22u = _rtB -> au4vfwszcw ; } } if ( _rtB -> deyer4xufx
[ 10 ] > 628.31853071795865 ) { _rtB -> fy2c5bu310 = 628.31853071795865 ; }
else if ( _rtB -> deyer4xufx [ 10 ] < 0.0 ) { _rtB -> fy2c5bu310 = 0.0 ; }
else { _rtB -> fy2c5bu310 = _rtB -> deyer4xufx [ 10 ] ; } h100jbae3x = (
uint8_T ) ( _rtB -> fy2c5bu310 > ld5zvvrfqt ( S ) -> nxzgx4xj0u ) ;
jpmexbyjov = 9.5492965855137211 * _rtB -> deyer4xufx [ 10 ] ; if (
ssIsMajorTimeStep ( S ) ) { if ( jpmexbyjov >= 3200.0 ) { _rtDW -> arwc5pcj54
= true ; } else { if ( jpmexbyjov <= 2800.0 ) { _rtDW -> arwc5pcj54 = false ;
} } } if ( ssIsSampleHit ( S , 1 , 0 ) ) { if ( ssIsSampleHit ( S , 2 , 0 ) )
{ _rtB -> dnnkxjlcwz = _rtDW -> jnhtlxaxxk ; } if ( _rtDW -> arwc5pcj54 ) {
rowIdx = 3200 ; } else { rowIdx = 2800 ; } if ( _rtB -> dnnkxjlcwz > 1.0 ) {
h0cg4jnrg5 = 1.0 ; } else if ( _rtB -> dnnkxjlcwz < 0.0 ) { h0cg4jnrg5 = 0.0
; } else { h0cg4jnrg5 = _rtB -> dnnkxjlcwz ; } h0cg4jnrg5 *= rt_Lookup (
ni220kbneq . jqglboln4v , 101 , rowIdx , ni220kbneq . i2vn1liwwa ) ; if (
h0cg4jnrg5 > 136.0757 ) { _rtB -> l52hikl1ww = 136.0757 ; } else if (
h0cg4jnrg5 < 0.0 ) { _rtB -> l52hikl1ww = 0.0 ; } else { _rtB -> l52hikl1ww =
h0cg4jnrg5 ; } } if ( h100jbae3x >= 1 ) { _rtB -> jok4j5qa1k = ld5zvvrfqt ( S
) -> adn0lwewvo ; } else { _rtB -> jok4j5qa1k = _rtB -> l52hikl1ww ; } _rtB
-> ket0jiwxqy = - _rtB -> lwgbf1qmzs ; _rtB -> hbtncuufsa [ 0 ] = _rtB ->
lwgbf1qmzs ; _rtB -> hbtncuufsa [ 1 ] = _rtB -> mwxn3abhxy ; _rtB ->
hbtncuufsa [ 2 ] = _rtB -> hg4wowaxzw ; _rtB -> hbtncuufsa [ 3 ] = _rtB ->
p4hehek2r5 ; _rtB -> hbtncuufsa [ 4 ] = _rtB -> kmftmcmoyv ; _rtB ->
hbtncuufsa [ 5 ] = _rtB -> bj4zdemj02 ; _rtB -> hbtncuufsa [ 6 ] = _rtB ->
aiwl23f22u ; _rtB -> hbtncuufsa [ 7 ] = _rtB -> jok4j5qa1k ; _rtB ->
hbtncuufsa [ 8 ] = _rtB -> ket0jiwxqy ; ssCallAccelRunBlock ( S , 15 , 183 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 15 , 184 ,
SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) {
ssCallAccelRunBlock ( S , 15 , 185 , SS_CALL_MDL_OUTPUTS ) ; }
ssCallAccelRunBlock ( S , 15 , 186 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
dn1ikv4qso = 9.5492965854826952 * _rtB -> deyer4xufx [ 11 ] ; _rtB ->
p0rfgbgvwl = _rtB -> deyer4xufx [ 11 ] * _rtB -> lqgl4qsfga [ 1 ] ;
ssCallAccelRunBlock ( S , 15 , 189 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
lmfs5imxxp = _rtX -> pi4mr5hhgl ; _rtB -> k1nktekma4 = _rtX -> bjc4xqhn0t ;
jpmexbyjov = 1.0 / _rtB -> lmfs5imxxp * _rtB -> k1nktekma4 * 100.0 ; if (
jpmexbyjov <= 0.0 ) { _rtB -> p0rfgbgvwl = 0.0 ; } else { _rtB -> p0rfgbgvwl
= jpmexbyjov ; } HEV_acc_Look2D_real_T_real_T_real_T ( & ( _rtB -> f4bztwm5yt
) , ( ( baqezl5ja5 * ) ssGetDefaultParam ( S ) ) -> FuelConsTable .
lookupTableFuel , _rtB -> dn1ikv4qso , ( ( baqezl5ja5 * ) ssGetDefaultParam (
S ) ) -> FuelConsTable . speed , 9U , _rtB -> lqgl4qsfga [ 1 ] , ( (
baqezl5ja5 * ) ssGetDefaultParam ( S ) ) -> FuelConsTable . torque , 9U ) ;
HEV_acc_Look2D_real_T_real_T_real_T ( & ( _rtB -> pogkxinemr ) , ( (
baqezl5ja5 * ) ssGetDefaultParam ( S ) ) -> GasEmisTable . lookupTableCO ,
_rtB -> dn1ikv4qso , ( ( baqezl5ja5 * ) ssGetDefaultParam ( S ) ) ->
GasEmisTable . speed , 9U , _rtB -> lqgl4qsfga [ 1 ] , ( ( baqezl5ja5 * )
ssGetDefaultParam ( S ) ) -> GasEmisTable . torque , 9U ) ;
HEV_acc_Look2D_real_T_real_T_real_T ( & ( _rtB -> hton2qzo1i ) , ( (
baqezl5ja5 * ) ssGetDefaultParam ( S ) ) -> GasEmisTable . lookupTableHC ,
_rtB -> dn1ikv4qso , ( ( baqezl5ja5 * ) ssGetDefaultParam ( S ) ) ->
GasEmisTable . speed , 9U , _rtB -> lqgl4qsfga [ 1 ] , ( ( baqezl5ja5 * )
ssGetDefaultParam ( S ) ) -> GasEmisTable . torque , 9U ) ;
HEV_acc_Look2D_real_T_real_T_real_T ( & ( _rtB -> jjjdylbqxb ) , ( (
baqezl5ja5 * ) ssGetDefaultParam ( S ) ) -> GasEmisTable . lookupTableNOX ,
_rtB -> dn1ikv4qso , ( ( baqezl5ja5 * ) ssGetDefaultParam ( S ) ) ->
GasEmisTable . speed , 9U , _rtB -> lqgl4qsfga [ 1 ] , ( ( baqezl5ja5 * )
ssGetDefaultParam ( S ) ) -> GasEmisTable . torque , 9U ) ;
ssCallAccelRunBlock ( S , 15 , 199 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
g4vw3zbhhb = ! ( h100jbae3x != 0 ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) {
ssCallAccelRunBlock ( S , 15 , 201 , SS_CALL_MDL_OUTPUTS ) ; } _rtB ->
fznp2kcsm1 = _rtX -> oy1vxpvao1 ; jpmexbyjov = ssGetT ( S ) ; _rtB ->
c1snypnc50 = _rtB -> fznp2kcsm1 / jpmexbyjov ; ssCallAccelRunBlock ( S , 15 ,
210 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> mshyr533vc = _rtX -> iglmayn3zq ; _rtB
-> pzfvurdnse = jpmexbyjov * ld5zvvrfqt ( S ) -> pxymsr2jxf ; _rtB ->
c1snypnc50 *= _rtB -> pzfvurdnse ; jpmexbyjov = _rtB -> mshyr533vc / _rtB ->
c1snypnc50 ; if ( jpmexbyjov <= 0.0 ) { _rtB -> hfck4o5hrr = 0.0 ; } else {
_rtB -> hfck4o5hrr = jpmexbyjov ; } ssCallAccelRunBlock ( S , 15 , 217 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 15 , 218 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> gsicgep2yy = _rtX -> p24x5vnk3x ; jpmexbyjov
= _rtB -> gsicgep2yy / _rtB -> c1snypnc50 ; if ( jpmexbyjov <= 0.0 ) { _rtB
-> hfck4o5hrr = 0.0 ; } else { _rtB -> hfck4o5hrr = jpmexbyjov ; }
ssCallAccelRunBlock ( S , 15 , 222 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
hgjdldvlzr = _rtX -> jntxheunx4 ; jpmexbyjov = _rtB -> hgjdldvlzr / _rtB ->
c1snypnc50 ; if ( jpmexbyjov <= 0.0 ) { _rtB -> hfck4o5hrr = 0.0 ; } else {
_rtB -> hfck4o5hrr = jpmexbyjov ; } ssCallAccelRunBlock ( S , 15 , 226 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 15 , 227 ,
SS_CALL_MDL_OUTPUTS ) ; if ( _rtB -> k1nktekma4 <= 0.0 ) { h0cg4jnrg5 = 0.0 ;
} else { h0cg4jnrg5 = _rtB -> k1nktekma4 ; } _rtB -> oj35f4ujq2 = h0cg4jnrg5
+ ld5zvvrfqt ( S ) -> mubzf04b2z ; ssCallAccelRunBlock ( S , 15 , 231 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 15 , 232 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> jmvi5l25or = 0.001 * _rtB -> f4bztwm5yt ;
_rtB -> n4vtopr0ll = _rtB -> jmvi5l25or / ld5zvvrfqt ( S ) -> bhn4nmwk3l ;
_rtB -> i1a11uxs0w = 3.6 * _rtB -> cvcqn2f3ws ; if ( _rtB -> i1a11uxs0w >
200.0 ) { _rtB -> neippz3iia = 200.0 ; } else if ( _rtB -> i1a11uxs0w < 0.0 )
{ _rtB -> neippz3iia = 0.0 ; } else { _rtB -> neippz3iia = _rtB -> i1a11uxs0w
; } _rtB -> fk1flnga04 = 0.0002777777777778 * _rtB -> neippz3iia ; _rtB ->
jrxupqq1lk = 1000.0 * _rtB -> n4vtopr0ll ; ssCallAccelRunBlock ( S , 15 , 246
, SS_CALL_MDL_OUTPUTS ) ; _rtB -> csbq50brdb = 0 ; ssCallAccelRunBlock ( S ,
15 , 267 , SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 15 , 268 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 15 , 269 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 15 , 270 ,
SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSampleHit ( S , 4 , 0 ) ) {
ssCallAccelRunBlock ( S , 15 , 271 , SS_CALL_MDL_OUTPUTS ) ; } _rtB ->
o1f0umplsm = 0.0 ; _rtB -> o1f0umplsm += 125.66370614359172 * _rtX ->
ix50zu3rlz ; ssCallAccelRunBlock ( S , 15 , 273 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 15 , 274 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
d3lpxulf2w = _rtB -> hfck4o5hrr - _rtB -> o1f0umplsm ; iiis24gb3o = 0.02 *
_rtB -> d3lpxulf2w ; if ( ( ( hgl3elxkcb * ) ssGetContStates ( S ) ) ->
f0udlm3lxk >= 5.0 ) { if ( ( ( hgl3elxkcb * ) ssGetContStates ( S ) ) ->
f0udlm3lxk != 5.0 ) { ( ( hgl3elxkcb * ) ssGetContStates ( S ) ) ->
f0udlm3lxk = 5.0 ; ssSetSolverNeedsReset ( S ) ; } } else if ( ( ( hgl3elxkcb
* ) ssGetContStates ( S ) ) -> f0udlm3lxk <= ( - 5.0 ) ) { if ( ( (
hgl3elxkcb * ) ssGetContStates ( S ) ) -> f0udlm3lxk != ( - 5.0 ) ) { ( (
hgl3elxkcb * ) ssGetContStates ( S ) ) -> f0udlm3lxk = ( - 5.0 ) ;
ssSetSolverNeedsReset ( S ) ; } } _rtB -> o0mjc4jw2g = ( ( hgl3elxkcb * )
ssGetContStates ( S ) ) -> f0udlm3lxk ; jpmexbyjov = iiis24gb3o + _rtB ->
o0mjc4jw2g ; if ( jpmexbyjov > 1.0 ) { _rtB -> i5flvigm1f = 1.0 ; } else if (
jpmexbyjov < - 1.0 ) { _rtB -> i5flvigm1f = - 1.0 ; } else { _rtB ->
i5flvigm1f = jpmexbyjov ; } ssCallAccelRunBlock ( S , 15 , 280 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 15 , 281 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> iaqsobebwc = 0.04 * _rtB -> d3lpxulf2w ; if (
ssIsSampleHit ( S , 2 , 0 ) ) { jwhz1ujp3w = _rtDW -> eaosag5owj ; ehtkh2wauy
= muDoubleScalarSin ( _rtDW -> eaosag5owj ) ; mkcfwi2fsi = muDoubleScalarCos
( _rtDW -> eaosag5owj ) ; _rtB -> in3py4vfm1 = _rtB -> bei1xfdtco *
mkcfwi2fsi + _rtB -> hvatssmzeb * ehtkh2wauy ; _rtB -> aj4wnnqgxa = ( ( -
_rtB -> bei1xfdtco - 1.7320508075688772 * _rtB -> hvatssmzeb ) * mkcfwi2fsi +
( 1.7320508075688772 * _rtB -> bei1xfdtco - _rtB -> hvatssmzeb ) * ehtkh2wauy
) * 0.5 ; ehcygfucdl = _rtDW -> jcugjk0yp0 ; po0ockmy2b = muDoubleScalarSin (
_rtDW -> jcugjk0yp0 ) ; mizlp41tvx = muDoubleScalarCos ( _rtDW -> jcugjk0yp0
) ; _rtB -> dibnhbg20m = _rtB -> itq4augluc * mizlp41tvx + _rtB -> iwocvn0p4u
* po0ockmy2b ; _rtB -> poep3mhx0b = ( ( - _rtB -> itq4augluc -
1.7320508075688772 * _rtB -> iwocvn0p4u ) * mizlp41tvx + ( 1.7320508075688772
* _rtB -> itq4augluc - _rtB -> iwocvn0p4u ) * po0ockmy2b ) * 0.5 ; f4ufgq33gz
= _rtDW -> jly33pdwub ; i5nu34w4uj = 5.9999820000156134E-6 * _rtDW ->
f2z5i2ds5e ; _rtB -> cgltpaixht = ( i5nu34w4uj > ld5zvvrfqt ( S ) ->
kdsedi141w ) ; } if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> nvpfcersrg =
_rtDW -> b50c0wk1dc ; } if ( ssIsSampleHit ( S , 2 , 0 ) ) { if ( _rtDW ->
o05rwe50bo != 0 ) { _rtDW -> pk42w2cjcz = _rtB -> nvpfcersrg ; if ( _rtDW ->
pk42w2cjcz >= 25200.0 ) { _rtDW -> pk42w2cjcz = 25200.0 ; } else { if ( _rtDW
-> pk42w2cjcz <= rtMinusInf ) { _rtDW -> pk42w2cjcz = rtMinusInf ; } } } if (
( _rtB -> cgltpaixht > 0.0 ) && ( _rtDW -> f0fxu4veqt <= 0 ) ) { _rtDW ->
pk42w2cjcz = _rtB -> nvpfcersrg ; if ( _rtDW -> pk42w2cjcz >= 25200.0 ) {
_rtDW -> pk42w2cjcz = 25200.0 ; } else { if ( _rtDW -> pk42w2cjcz <=
rtMinusInf ) { _rtDW -> pk42w2cjcz = rtMinusInf ; } } } if ( _rtDW ->
pk42w2cjcz >= 25200.0 ) { _rtDW -> pk42w2cjcz = 25200.0 ; } else { if ( _rtDW
-> pk42w2cjcz <= rtMinusInf ) { _rtDW -> pk42w2cjcz = rtMinusInf ; } }
dztyrqu4xa = 0.00027777777777777778 * _rtDW -> pk42w2cjcz ; if ( dztyrqu4xa >
6.9993 ) { eskeehll14 = 6.9993 ; } else if ( dztyrqu4xa < 0.0 ) { eskeehll14
= 0.0 ; } else { eskeehll14 = dztyrqu4xa ; } if ( dztyrqu4xa >= 6.9993 ) {
dztyrqu4xa = 6.9993 ; } byehzqrbel = ( ( 7.0 / ( 7.0 - eskeehll14 ) * -
0.23801451555567835 * eskeehll14 + ( ld5zvvrfqt ( S ) -> hjknybunce +
f4ufgq33gz ) ) + - _rtB -> cgltpaixht * 0.23801451555567835 * i5nu34w4uj * (
7.0 / ( 7.0 - eskeehll14 ) ) ) + - ( ( real_T ) ( i5nu34w4uj < ld5zvvrfqt ( S
) -> ftmwan3rst ) * ld5zvvrfqt ( S ) -> ly03i0hz21 ) * 0.23801451555567835 *
( ld5zvvrfqt ( S ) -> ly03i0hz21 * i5nu34w4uj ) * ( 7.0 / ( muDoubleScalarAbs
( ld5zvvrfqt ( S ) -> ly03i0hz21 * dztyrqu4xa ) + 0.70000000000000007 ) ) ;
if ( byehzqrbel > ld5zvvrfqt ( S ) -> igtdeyuhg2 ) { _rtB -> kj40rnmrww =
ld5zvvrfqt ( S ) -> igtdeyuhg2 ; } else { iiis24gb3o = 0.30769230769230771 *
i5nu34w4uj ; if ( byehzqrbel < iiis24gb3o ) { _rtB -> kj40rnmrww = iiis24gb3o
; } else { _rtB -> kj40rnmrww = byehzqrbel ; } } _rtB -> bhwfaderrt = _rtDW
-> fezg0yhyh2 ; f0kpvfzk1l_idx_0 = _rtDW -> hdqerfit1p [ 0 ] ;
f0kpvfzk1l_idx_1 = _rtDW -> hdqerfit1p [ 1 ] ; f0kpvfzk1l_idx_2 = _rtDW ->
hdqerfit1p [ 2 ] ; lduwq00gqj = muDoubleScalarCos ( jwhz1ujp3w ) ; ckrl0nmlwt
= muDoubleScalarSin ( jwhz1ujp3w ) ; } if ( _rtB -> deyer4xufx [ 7 ] <= 1.0 )
{ jpmexbyjov = 1.0 ; } else { jpmexbyjov = _rtB -> deyer4xufx [ 7 ] ; }
jpmexbyjov = 1.0 / jpmexbyjov ; jpmexbyjov *= 30000.0 ; i5nu34w4uj =
muDoubleScalarAbs ( jpmexbyjov ) ; if ( ssIsMajorTimeStep ( S ) ) { if ( _rtB
-> deyer4xufx [ 7 ] >= 300.0 ) { _rtDW -> ch52ed4whv = true ; } else { if (
_rtB -> deyer4xufx [ 7 ] <= 200.0 ) { _rtDW -> ch52ed4whv = false ; } } }
_rtB -> aorh4zkl20 = _rtDW -> ch52ed4whv ; if ( ( _rtDW -> mg242c3vwq >=
ssGetTaskTime ( S , 0 ) ) && ( _rtDW -> k1wt3kvmem >= ssGetTaskTime ( S , 0 )
) ) { _rtB -> fr5a2e2puy = _rtB -> aorh4zkl20 ; } else { if ( ( ( _rtDW ->
mg242c3vwq < _rtDW -> k1wt3kvmem ) && ( _rtDW -> k1wt3kvmem < ssGetTaskTime (
S , 0 ) ) ) || ( ( _rtDW -> mg242c3vwq >= _rtDW -> k1wt3kvmem ) && ( _rtDW ->
mg242c3vwq >= ssGetTaskTime ( S , 0 ) ) ) ) { iiis24gb3o = ssGetTaskTime ( S
, 0 ) - _rtDW -> k1wt3kvmem ; lebvfutt11 = _rtDW -> lzjsh0qxsz ; } else {
iiis24gb3o = ssGetTaskTime ( S , 0 ) - _rtDW -> mg242c3vwq ; lebvfutt11 =
_rtDW -> oiqwpboxgd ; } lstej3qx0u = iiis24gb3o * 10.0 ; f2e3v5ccex = _rtB ->
aorh4zkl20 - lebvfutt11 ; if ( f2e3v5ccex > lstej3qx0u ) { _rtB -> fr5a2e2puy
= lebvfutt11 + lstej3qx0u ; } else { iiis24gb3o *= - 10.0 ; if ( f2e3v5ccex <
iiis24gb3o ) { _rtB -> fr5a2e2puy = lebvfutt11 + iiis24gb3o ; } else { _rtB
-> fr5a2e2puy = _rtB -> aorh4zkl20 ; } } } if ( _rtB -> deyer4xufx [ 5 ] >
628.31853071795865 ) { _rtB -> cgf1ndpvv5 = 628.31853071795865 ; } else if (
_rtB -> deyer4xufx [ 5 ] < 0.0 ) { _rtB -> cgf1ndpvv5 = 0.0 ; } else { _rtB
-> cgf1ndpvv5 = _rtB -> deyer4xufx [ 5 ] ; } jpmexbyjov = muDoubleScalarAbs (
_rtB -> cgf1ndpvv5 ) ; HEV_acc_LookUp_real_T_real_T ( & ( or4xk0d2hg ) ,
ni220kbneq . kra3wm5gfy , jpmexbyjov , ni220kbneq . elvuv43juu , 6U ) ; if (
( _rtDW -> cwivfg5ijd >= ssGetTaskTime ( S , 0 ) ) && ( _rtDW -> m1iuzueluk
>= ssGetTaskTime ( S , 0 ) ) ) { _rtB -> l5gtfbbgdv = _rtB -> i5flvigm1f ; }
else { if ( ( ( _rtDW -> cwivfg5ijd < _rtDW -> m1iuzueluk ) && ( _rtDW ->
m1iuzueluk < ssGetTaskTime ( S , 0 ) ) ) || ( ( _rtDW -> cwivfg5ijd >= _rtDW
-> m1iuzueluk ) && ( _rtDW -> cwivfg5ijd >= ssGetTaskTime ( S , 0 ) ) ) ) {
iiis24gb3o = ssGetTaskTime ( S , 0 ) - _rtDW -> m1iuzueluk ; lebvfutt11 =
_rtDW -> bvl1znuobh ; } else { iiis24gb3o = ssGetTaskTime ( S , 0 ) - _rtDW
-> cwivfg5ijd ; lebvfutt11 = _rtDW -> kguctqvwvn ; } f2e3v5ccex = _rtB ->
i5flvigm1f - lebvfutt11 ; if ( f2e3v5ccex > iiis24gb3o ) { _rtB -> l5gtfbbgdv
= lebvfutt11 + iiis24gb3o ; } else { iiis24gb3o = - iiis24gb3o ; if (
f2e3v5ccex < iiis24gb3o ) { _rtB -> l5gtfbbgdv = lebvfutt11 + iiis24gb3o ; }
else { _rtB -> l5gtfbbgdv = _rtB -> i5flvigm1f ; } } } byehzqrbel = 400.0 *
_rtB -> l5gtfbbgdv ; if ( byehzqrbel > or4xk0d2hg ) { jpmexbyjov = or4xk0d2hg
; } else if ( byehzqrbel < - or4xk0d2hg ) { jpmexbyjov = - or4xk0d2hg ; }
else { jpmexbyjov = byehzqrbel ; } jgewyk5b21 = ssGetT ( S ) ; _rtB ->
jrrfpeahxw = ( real_T ) ( jgewyk5b21 > ld5zvvrfqt ( S ) -> mg4dltlmgj ) *
jpmexbyjov ; jgewyk5b21 = _rtB -> jrrfpeahxw * _rtB -> cgf1ndpvv5 ; if (
ssIsSampleHit ( S , 2 , 0 ) ) { _rtB -> igyrajdzpr = ( 1.0 - eskeehll14 / 7.0
) * 100.0 ; rowIdx = ( int32_T ) ( ( ( ( ( uint32_T ) ( _rtB -> igyrajdzpr <
ld5zvvrfqt ( S ) -> pdrubkuuvu ) << 1 ) + ( _rtB -> igyrajdzpr > ld5zvvrfqt (
S ) -> adu01xsk2c ) ) << 1 ) + _rtDW -> bvad1zjfik ) ; _rtB -> ew213nrs0e [
0U ] = ni220kbneq . i1nwoqgijo [ ( uint32_T ) rowIdx ] ; _rtB -> ew213nrs0e [
1U ] = ni220kbneq . i1nwoqgijo [ rowIdx + 8U ] ; } jpmexbyjov = _rtB ->
ew213nrs0e [ 0 ] ; _rtB -> prfsgkkwqv = - 21000.0 * jpmexbyjov ; if ( ( _rtDW
-> hfvh40s0je >= ssGetTaskTime ( S , 0 ) ) && ( _rtDW -> f41a3yqptq >=
ssGetTaskTime ( S , 0 ) ) ) { _rtB -> phabbozbp4 = _rtB -> prfsgkkwqv ; }
else { if ( ( ( _rtDW -> hfvh40s0je < _rtDW -> f41a3yqptq ) && ( _rtDW ->
f41a3yqptq < ssGetTaskTime ( S , 0 ) ) ) || ( ( _rtDW -> hfvh40s0je >= _rtDW
-> f41a3yqptq ) && ( _rtDW -> hfvh40s0je >= ssGetTaskTime ( S , 0 ) ) ) ) {
iiis24gb3o = ssGetTaskTime ( S , 0 ) - _rtDW -> f41a3yqptq ; lebvfutt11 =
_rtDW -> aq3qjo4ji4 ; } else { iiis24gb3o = ssGetTaskTime ( S , 0 ) - _rtDW
-> hfvh40s0je ; lebvfutt11 = _rtDW -> lidlmlim32 ; } lstej3qx0u = iiis24gb3o
* 42000.0 ; f2e3v5ccex = _rtB -> prfsgkkwqv - lebvfutt11 ; if ( f2e3v5ccex >
lstej3qx0u ) { _rtB -> phabbozbp4 = lebvfutt11 + lstej3qx0u ; } else {
iiis24gb3o *= - 42000.0 ; if ( f2e3v5ccex < iiis24gb3o ) { _rtB -> phabbozbp4
= lebvfutt11 + iiis24gb3o ; } else { _rtB -> phabbozbp4 = _rtB -> prfsgkkwqv
; } } } j0jhyqa1p3 = jgewyk5b21 - _rtB -> phabbozbp4 ; jpmexbyjov =
muDoubleScalarAbs ( j0jhyqa1p3 ) ; jpmexbyjov = 1.1 * rt_Lookup ( _rtP ->
EngineSpeedPower . power , 84 , jpmexbyjov , _rtP -> EngineSpeedPower . speed
) ; if ( jpmexbyjov > 5000.0 ) { _rtB -> hfck4o5hrr = 5000.0 ; } else if (
jpmexbyjov < 750.0 ) { _rtB -> hfck4o5hrr = 750.0 ; } else { _rtB ->
hfck4o5hrr = jpmexbyjov ; } byehzqrbel = 0.10471975511965977 * _rtB ->
hfck4o5hrr ; if ( ssIsMajorTimeStep ( S ) ) { if ( jgewyk5b21 >= 12000.0 ) {
_rtDW -> guq5pq4c5s = true ; } else { if ( jgewyk5b21 <= 11000.0 ) { _rtDW ->
guq5pq4c5s = false ; } } } if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB ->
la4wzwmbxz = ! ! _rtDW -> guq5pq4c5s ; _rtB -> hjewtimmyr = ( _rtDW ->
aln04uuynj != ld5zvvrfqt ( S ) -> cqkpi54zvb ) ; } o3khhk3fbg = ( _rtB ->
la4wzwmbxz || ( ( jgewyk5b21 > ld5zvvrfqt ( S ) -> ksh4edpfej ) && _rtB ->
hjewtimmyr ) ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> cr4xqq3gbr =
_rtDW -> nlh5qppt4m ; } if ( o3khhk3fbg ) { if ( j0jhyqa1p3 > 57000.0 ) {
h0cg4jnrg5 = 57000.0 ; } else if ( j0jhyqa1p3 < - 57000.0 ) { h0cg4jnrg5 = -
57000.0 ; } else { h0cg4jnrg5 = j0jhyqa1p3 ; } _rtB -> n4rpd2rl5y = 1.0 /
byehzqrbel * h0cg4jnrg5 * _rtB -> fr5a2e2puy ; } else { _rtB -> n4rpd2rl5y =
_rtB -> cr4xqq3gbr ; } jgewyk5b21 = 1.0 / byehzqrbel * _rtB -> deyer4xufx [
11 ] ; if ( jgewyk5b21 > 1.0 ) { h0cg4jnrg5 = 1.0 ; } else if ( jgewyk5b21 <
0.0 ) { h0cg4jnrg5 = 0.0 ; } else { h0cg4jnrg5 = jgewyk5b21 ; } iiis24gb3o =
_rtB -> fr5a2e2puy * _rtB -> n4rpd2rl5y * h0cg4jnrg5 * 0.27777777777777779 ;
if ( iiis24gb3o > i5nu34w4uj ) { _rtB -> abrqa35ynz = i5nu34w4uj ; } else if
( iiis24gb3o < - i5nu34w4uj ) { _rtB -> abrqa35ynz = - i5nu34w4uj ; } else {
_rtB -> abrqa35ynz = iiis24gb3o ; } jgewyk5b21 = - _rtB -> abrqa35ynz *
ld5zvvrfqt ( S ) -> n2qw0mbreu ; if ( ( _rtDW -> mtptmi2003 == ( rtMinusInf )
) || ( _rtDW -> mtptmi2003 == ssGetTaskTime ( S , 0 ) ) ) { _rtDW ->
mtptmi2003 = ssGetTaskTime ( S , 0 ) ; _rtB -> fzv0awyrul = 0.0 ; } else {
_rtB -> fzv0awyrul = jgewyk5b21 ; } if ( ssIsSampleHit ( S , 2 , 0 ) ) { if (
_rtB -> fzv0awyrul > 45.0 ) { dztyrqu4xa = 45.0 ; } else if ( _rtB ->
fzv0awyrul < - 45.0 ) { dztyrqu4xa = - 45.0 ; } else { dztyrqu4xa = _rtB ->
fzv0awyrul ; } aqlslovppe = 3.4722222222222219 * dztyrqu4xa ; dyfxp2slod = -
ld5zvvrfqt ( S ) -> gkm5nruzvb * ckrl0nmlwt + aqlslovppe * lduwq00gqj ;
ctpq3axefx = dyfxp2slod - f0kpvfzk1l_idx_0 ; if ( ctpq3axefx >= 0.0 ) { _rtDW
-> mdrfaaqhlc = true ; } else { if ( ctpq3axefx <= 0.0 ) { _rtDW ->
mdrfaaqhlc = false ; } } dk4tk42hhp = ( 1.7320508 * ckrl0nmlwt + - lduwq00gqj
) * aqlslovppe * 0.5 + ( 1.7320508 * lduwq00gqj + ckrl0nmlwt ) * ld5zvvrfqt (
S ) -> gkm5nruzvb * 0.5 ; aqlslovppe = dk4tk42hhp - f0kpvfzk1l_idx_1 ; if (
aqlslovppe >= 0.0 ) { _rtDW -> hi5e5wjvfn = true ; } else { if ( aqlslovppe
<= 0.0 ) { _rtDW -> hi5e5wjvfn = false ; } } f1b5simhxh = ( 0.0 - dk4tk42hhp
) - dyfxp2slod ; lduwq00gqj = f1b5simhxh - f0kpvfzk1l_idx_2 ; if ( lduwq00gqj
>= 0.0 ) { _rtDW -> ltj2mwt3by = true ; } else { if ( lduwq00gqj <= 0.0 ) {
_rtDW -> ltj2mwt3by = false ; } } _rtB -> jvmbdvgoz4 [ 0 ] = ( ( real_T )
_rtDW -> mdrfaaqhlc - ( real_T ) _rtDW -> hi5e5wjvfn ) * ld5zvvrfqt ( S ) ->
n2qw0mbreu * _rtB -> bhwfaderrt ; _rtB -> jvmbdvgoz4 [ 1 ] = ( ( real_T )
_rtDW -> hi5e5wjvfn - ( real_T ) _rtDW -> ltj2mwt3by ) * ld5zvvrfqt ( S ) ->
n2qw0mbreu * _rtB -> bhwfaderrt ; _rtB -> on11bzhrh5 = _rtDW -> bro0cn1wmi ;
f0kpvfzk1l_idx_0 = _rtDW -> j31s1kcymk [ 0 ] ; f0kpvfzk1l_idx_1 = _rtDW ->
j31s1kcymk [ 1 ] ; f0kpvfzk1l_idx_2 = _rtDW -> j31s1kcymk [ 2 ] ; ehcygfucdl
/= 4.0 ; ctpq3axefx = 4.0 * ehcygfucdl ; aqlslovppe = muDoubleScalarCos (
ctpq3axefx ) ; ctpq3axefx = muDoubleScalarSin ( ctpq3axefx ) ; if (
ssIsSampleHit ( S , 3 , 0 ) ) { _rtB -> obm4oho3zg = _rtDW -> gsr0ogd2xb ; }
_rtB -> mgo4w0scce = 0.002479481623358034 * _rtB -> obm4oho3zg ; } if ( (
_rtDW -> joiszbfghn >= ssGetTaskTime ( S , 0 ) ) && ( _rtDW -> jlnwqqs23l >=
ssGetTaskTime ( S , 0 ) ) ) { _rtB -> eijf3boo05 = _rtB -> mgo4w0scce ; }
else { if ( ( ( _rtDW -> joiszbfghn < _rtDW -> jlnwqqs23l ) && ( _rtDW ->
jlnwqqs23l < ssGetTaskTime ( S , 0 ) ) ) || ( ( _rtDW -> joiszbfghn >= _rtDW
-> jlnwqqs23l ) && ( _rtDW -> joiszbfghn >= ssGetTaskTime ( S , 0 ) ) ) ) {
iiis24gb3o = ssGetTaskTime ( S , 0 ) - _rtDW -> jlnwqqs23l ; lebvfutt11 =
_rtDW -> miwjijsda1 ; } else { iiis24gb3o = ssGetTaskTime ( S , 0 ) - _rtDW
-> joiszbfghn ; lebvfutt11 = _rtDW -> narm2z4h4g ; } lstej3qx0u = iiis24gb3o
* 10.0 ; f2e3v5ccex = _rtB -> mgo4w0scce - lebvfutt11 ; if ( f2e3v5ccex >
lstej3qx0u ) { _rtB -> eijf3boo05 = lebvfutt11 + lstej3qx0u ; } else {
iiis24gb3o *= - 10.0 ; if ( f2e3v5ccex < iiis24gb3o ) { _rtB -> eijf3boo05 =
lebvfutt11 + iiis24gb3o ; } else { _rtB -> eijf3boo05 = _rtB -> mgo4w0scce ;
} } } jgewyk5b21 = muDoubleScalarAbs ( _rtB -> eijf3boo05 ) ; _rtB ->
iwiiksahno = rt_Lookup ( ni220kbneq . hvtx2huqpc , 301 , jgewyk5b21 ,
ni220kbneq . fjibtn4wrs ) ; if ( ssIsSampleHit ( S , 2 , 0 ) ) { _rtB ->
mv43hebl0s = _rtB -> cgf1ndpvv5 ; ssCallAccelRunBlock ( S , 5 , 0 ,
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
= byehzqrbel - f0kpvfzk1l_idx_0 ; if ( iiis24gb3o >= 0.0 ) { _rtDW ->
bmg0h5hxwy = true ; } else { if ( iiis24gb3o <= 0.0 ) { _rtDW -> bmg0h5hxwy =
false ; } } i5nu34w4uj = ( 1.7320508 * ctpq3axefx + - aqlslovppe ) *
ckrl0nmlwt * 0.5 + ( 1.7320508 * aqlslovppe + ctpq3axefx ) * lduwq00gqj * 0.5
; ctpq3axefx = i5nu34w4uj - f0kpvfzk1l_idx_1 ; if ( ctpq3axefx >= 0.0 ) {
_rtDW -> kakc11drsq = true ; } else { if ( ctpq3axefx <= 0.0 ) { _rtDW ->
kakc11drsq = false ; } } lstej3qx0u = ( 0.0 - i5nu34w4uj ) - byehzqrbel ;
aqlslovppe = lstej3qx0u - f0kpvfzk1l_idx_2 ; if ( aqlslovppe >= 0.0 ) { _rtDW
-> d1uemo0w03 = true ; } else { if ( aqlslovppe <= 0.0 ) { _rtDW ->
d1uemo0w03 = false ; } } _rtB -> ek3txos0g0 [ 0 ] = ( ( real_T ) _rtDW ->
bmg0h5hxwy - ( real_T ) _rtDW -> kakc11drsq ) * ld5zvvrfqt ( S ) ->
atmyqjofcf * _rtB -> on11bzhrh5 ; _rtB -> ek3txos0g0 [ 1 ] = ( ( real_T )
_rtDW -> kakc11drsq - ( real_T ) _rtDW -> d1uemo0w03 ) * ld5zvvrfqt ( S ) ->
atmyqjofcf * _rtB -> on11bzhrh5 ; _rtB -> o05cdvr1sz = _rtDW -> kzrq2xyp0f ;
m5tsngcasr = ( ld5zvvrfqt ( S ) -> n2qw0mbreu != 0.0 ) ; zcEvent_idx_0 =
rt_ZCFcn ( ANY_ZERO_CROSSING , & _rtZCE -> gn3hyklx0i [ 0 ] , ( dyfxp2slod )
) ; zcEvent_idx_1 = rt_ZCFcn ( ANY_ZERO_CROSSING , & _rtZCE -> gn3hyklx0i [ 1
] , ( dk4tk42hhp ) ) ; zcEvent_idx_2 = rt_ZCFcn ( ANY_ZERO_CROSSING , &
_rtZCE -> gn3hyklx0i [ 2 ] , ( f1b5simhxh ) ) ; if ( _rtDW -> p5ivrte15o [ 0
] == 0 ) { if ( zcEvent_idx_0 != NO_ZCEVENT ) { _rtB -> f2piwart1v [ 0 ] = !
_rtB -> f2piwart1v [ 0 ] ; _rtDW -> p5ivrte15o [ 0 ] = 1 ; } else if ( _rtB
-> f2piwart1v [ 0 ] ) { if ( dyfxp2slod != 0.0 ) { _rtB -> f2piwart1v [ 0 ] =
false ; } } else { if ( dyfxp2slod == 0.0 ) { _rtB -> f2piwart1v [ 0 ] = true
; } } } else { if ( dyfxp2slod != 0.0 ) { _rtB -> f2piwart1v [ 0 ] = false ;
} _rtDW -> p5ivrte15o [ 0 ] = 0 ; } if ( _rtDW -> p5ivrte15o [ 1 ] == 0 ) {
if ( zcEvent_idx_1 != NO_ZCEVENT ) { _rtB -> f2piwart1v [ 1 ] = ! _rtB ->
f2piwart1v [ 1 ] ; _rtDW -> p5ivrte15o [ 1 ] = 1 ; } else if ( _rtB ->
f2piwart1v [ 1 ] ) { if ( dk4tk42hhp != 0.0 ) { _rtB -> f2piwart1v [ 1 ] =
false ; } } else { if ( dk4tk42hhp == 0.0 ) { _rtB -> f2piwart1v [ 1 ] = true
; } } } else { if ( dk4tk42hhp != 0.0 ) { _rtB -> f2piwart1v [ 1 ] = false ;
} _rtDW -> p5ivrte15o [ 1 ] = 0 ; } if ( _rtDW -> p5ivrte15o [ 2 ] == 0 ) {
if ( zcEvent_idx_2 != NO_ZCEVENT ) { _rtB -> f2piwart1v [ 2 ] = ! _rtB ->
f2piwart1v [ 2 ] ; _rtDW -> p5ivrte15o [ 2 ] = 1 ; } else if ( _rtB ->
f2piwart1v [ 2 ] ) { if ( f1b5simhxh != 0.0 ) { _rtB -> f2piwart1v [ 2 ] =
false ; } } else { if ( f1b5simhxh == 0.0 ) { _rtB -> f2piwart1v [ 2 ] = true
; } } } else { if ( f1b5simhxh != 0.0 ) { _rtB -> f2piwart1v [ 2 ] = false ;
} _rtDW -> p5ivrte15o [ 2 ] = 0 ; } keyxmz53xi ( S , _rtB -> f2piwart1v [ 0 ]
, m5tsngcasr , & _rtB -> keyxmz53xiy , & _rtDW -> keyxmz53xiy ) ; keyxmz53xi
( S , _rtB -> f2piwart1v [ 1 ] , m5tsngcasr , & _rtB -> d5h5wn4011 , & _rtDW
-> d5h5wn4011 ) ; keyxmz53xi ( S , _rtB -> f2piwart1v [ 2 ] , m5tsngcasr , &
_rtB -> hlr1ddtilb , & _rtDW -> hlr1ddtilb ) ; iiis24gb3o =
0.05823546641575128 * _rtDW -> nonllthbl2 ; ctpq3axefx = 0.05823546641575128
* _rtDW -> kol45dq53x ; aqlslovppe = muDoubleScalarSin ( jwhz1ujp3w ) ;
jwhz1ujp3w = muDoubleScalarCos ( jwhz1ujp3w ) ; lduwq00gqj = ( 0.0 -
aqlslovppe * ld5zvvrfqt ( S ) -> gyf3xdu5zi ) - jwhz1ujp3w * ld5zvvrfqt ( S )
-> knz552yyea ; ckrl0nmlwt = aqlslovppe * ld5zvvrfqt ( S ) -> knz552yyea -
jwhz1ujp3w * ld5zvvrfqt ( S ) -> gyf3xdu5zi ; h0cg4jnrg5 = ( iiis24gb3o *
aqlslovppe + ctpq3axefx * jwhz1ujp3w ) + ld5zvvrfqt ( S ) -> iogbsrfmit ;
lfv3m5pb5c = ( iiis24gb3o * lduwq00gqj + ctpq3axefx * ckrl0nmlwt ) +
ld5zvvrfqt ( S ) -> iogbsrfmit ; iiis24gb3o = ( ( ( 0.0 - lduwq00gqj ) -
aqlslovppe ) * iiis24gb3o + ( ( 0.0 - ckrl0nmlwt ) - jwhz1ujp3w ) *
ctpq3axefx ) + ld5zvvrfqt ( S ) -> iogbsrfmit ; _rtB -> j1xen50co2 [ 0 ] = (
real_T ) _rtB -> keyxmz53xiy . forbrjhq11 * dyfxp2slod + 0.2 * h0cg4jnrg5 ;
_rtB -> j1xen50co2 [ 1 ] = ( real_T ) _rtB -> d5h5wn4011 . forbrjhq11 *
dk4tk42hhp + 0.2 * lfv3m5pb5c ; _rtB -> j1xen50co2 [ 2 ] = ( real_T ) _rtB ->
hlr1ddtilb . forbrjhq11 * f1b5simhxh + 0.2 * iiis24gb3o ; if ( _rtDW ->
ehaijafsot <= 1.0 ) { h0cg4jnrg5 = 1.0 ; } else { h0cg4jnrg5 = _rtDW ->
ehaijafsot ; } _rtB -> origpq54mo = _rtDW -> fw2k5vojpd / h0cg4jnrg5 ;
zcEvent_idx_0 = rt_ZCFcn ( ANY_ZERO_CROSSING , & _rtZCE -> iw5dmb04jk [ 0 ] ,
( byehzqrbel ) ) ; zcEvent_idx_1 = rt_ZCFcn ( ANY_ZERO_CROSSING , & _rtZCE ->
iw5dmb04jk [ 1 ] , ( i5nu34w4uj ) ) ; zcEvent_idx_2 = rt_ZCFcn (
ANY_ZERO_CROSSING , & _rtZCE -> iw5dmb04jk [ 2 ] , ( lstej3qx0u ) ) ; if (
_rtDW -> l43ws31i1a [ 0 ] == 0 ) { if ( zcEvent_idx_0 != NO_ZCEVENT ) { _rtB
-> d3hizouv5f [ 0 ] = ! _rtB -> d3hizouv5f [ 0 ] ; _rtDW -> l43ws31i1a [ 0 ]
= 1 ; } else if ( _rtB -> d3hizouv5f [ 0 ] ) { if ( byehzqrbel != 0.0 ) {
_rtB -> d3hizouv5f [ 0 ] = false ; } } else { if ( byehzqrbel == 0.0 ) { _rtB
-> d3hizouv5f [ 0 ] = true ; } } } else { if ( byehzqrbel != 0.0 ) { _rtB ->
d3hizouv5f [ 0 ] = false ; } _rtDW -> l43ws31i1a [ 0 ] = 0 ; } if ( _rtDW ->
l43ws31i1a [ 1 ] == 0 ) { if ( zcEvent_idx_1 != NO_ZCEVENT ) { _rtB ->
d3hizouv5f [ 1 ] = ! _rtB -> d3hizouv5f [ 1 ] ; _rtDW -> l43ws31i1a [ 1 ] = 1
; } else if ( _rtB -> d3hizouv5f [ 1 ] ) { if ( i5nu34w4uj != 0.0 ) { _rtB ->
d3hizouv5f [ 1 ] = false ; } } else { if ( i5nu34w4uj == 0.0 ) { _rtB ->
d3hizouv5f [ 1 ] = true ; } } } else { if ( i5nu34w4uj != 0.0 ) { _rtB ->
d3hizouv5f [ 1 ] = false ; } _rtDW -> l43ws31i1a [ 1 ] = 0 ; } if ( _rtDW ->
l43ws31i1a [ 2 ] == 0 ) { if ( zcEvent_idx_2 != NO_ZCEVENT ) { _rtB ->
d3hizouv5f [ 2 ] = ! _rtB -> d3hizouv5f [ 2 ] ; _rtDW -> l43ws31i1a [ 2 ] = 1
; } else if ( _rtB -> d3hizouv5f [ 2 ] ) { if ( lstej3qx0u != 0.0 ) { _rtB ->
d3hizouv5f [ 2 ] = false ; } } else { if ( lstej3qx0u == 0.0 ) { _rtB ->
d3hizouv5f [ 2 ] = true ; } } } else { if ( lstej3qx0u != 0.0 ) { _rtB ->
d3hizouv5f [ 2 ] = false ; } _rtDW -> l43ws31i1a [ 2 ] = 0 ; } keyxmz53xi ( S
, _rtB -> d3hizouv5f [ 0 ] , ld5zvvrfqt ( S ) -> dwyd0w24zz , & _rtB ->
ovboqennya , & _rtDW -> ovboqennya ) ; keyxmz53xi ( S , _rtB -> d3hizouv5f [
1 ] , ld5zvvrfqt ( S ) -> dwyd0w24zz , & _rtB -> ifhlf2te5a , & _rtDW ->
ifhlf2te5a ) ; keyxmz53xi ( S , _rtB -> d3hizouv5f [ 2 ] , ld5zvvrfqt ( S )
-> dwyd0w24zz , & _rtB -> dtnq4yt00p , & _rtDW -> dtnq4yt00p ) ; lfv3m5pb5c =
0.05823546641575128 * _rtDW -> lvw3lta2fy ; h0cg4jnrg5 = 0.05823546641575128
* _rtDW -> c20b4oc1jp ; ehcygfucdl *= 4.0 ; f2e3v5ccex = muDoubleScalarSin (
ehcygfucdl ) ; ehcygfucdl = muDoubleScalarCos ( ehcygfucdl ) ; lebvfutt11 = (
0.0 - f2e3v5ccex * ld5zvvrfqt ( S ) -> az2u42exdr ) - ehcygfucdl * ld5zvvrfqt
( S ) -> jszi5go1lh ; iiis24gb3o = f2e3v5ccex * ld5zvvrfqt ( S ) ->
jszi5go1lh - ehcygfucdl * ld5zvvrfqt ( S ) -> az2u42exdr ; lduwq00gqj = (
lfv3m5pb5c * f2e3v5ccex + h0cg4jnrg5 * ehcygfucdl ) + ld5zvvrfqt ( S ) ->
hh2uemtcci ; ckrl0nmlwt = ( lfv3m5pb5c * lebvfutt11 + h0cg4jnrg5 * iiis24gb3o
) + ld5zvvrfqt ( S ) -> hh2uemtcci ; lfv3m5pb5c = ( ( ( 0.0 - lebvfutt11 ) -
f2e3v5ccex ) * lfv3m5pb5c + ( ( 0.0 - iiis24gb3o ) - ehcygfucdl ) *
h0cg4jnrg5 ) + ld5zvvrfqt ( S ) -> hh2uemtcci ; _rtB -> kofky1abg5 [ 0 ] = (
real_T ) _rtB -> ovboqennya . forbrjhq11 * byehzqrbel + 1.5384615384615383 *
lduwq00gqj ; _rtB -> kofky1abg5 [ 1 ] = ( real_T ) _rtB -> ifhlf2te5a .
forbrjhq11 * i5nu34w4uj + 1.5384615384615383 * ckrl0nmlwt ; _rtB ->
kofky1abg5 [ 2 ] = ( real_T ) _rtB -> dtnq4yt00p . forbrjhq11 * lstej3qx0u +
1.5384615384615383 * lfv3m5pb5c ; if ( _rtDW -> kopxzfb0sb <= 1.0 ) {
h0cg4jnrg5 = 1.0 ; } else { h0cg4jnrg5 = _rtDW -> kopxzfb0sb ; } _rtB ->
hoydntjogd = _rtDW -> lp13v2ihui / h0cg4jnrg5 ; _rtB -> oxchrbk4st = _rtDW ->
ebwur5qeqq ; ssCallAccelRunBlock ( S , 15 , 496 , SS_CALL_MDL_OUTPUTS ) ;
_rtB -> ovablii5uy = _rtB -> kj40rnmrww - 0.30769230769230771 * _rtB ->
lyhdwkntva [ 33 ] ; ssCallAccelRunBlock ( S , 15 , 499 , SS_CALL_MDL_OUTPUTS
) ; lfv3m5pb5c = muDoubleScalarAbs ( _rtB -> lyhdwkntva [ 33 ] ) ; _rtB ->
odcgudjzw0 = ( ( real_T ) ( _rtB -> lyhdwkntva [ 33 ] < ld5zvvrfqt ( S ) ->
gjguxlmcap ) * 18.82114106089411 - f4ufgq33gz ) * lfv3m5pb5c *
0.00064102564102564092 ; _rtB -> nkqb3xlmau = 3600.0 * eskeehll14 ; }
ssCallAccelRunBlock ( S , 13 , 0 , SS_CALL_MDL_OUTPUTS ) ; if ( _rtB ->
cgf1ndpvv5 <= 1.0 ) { i5nu34w4uj = 1.0 ; } else { i5nu34w4uj = _rtB ->
cgf1ndpvv5 ; } if ( ssIsMajorTimeStep ( S ) ) { if ( i5nu34w4uj >=
20.943951023931955 ) { _rtDW -> bmy4qihc4v = true ; } else { if ( i5nu34w4uj
<= 10.471975511965978 ) { _rtDW -> bmy4qihc4v = false ; } } } _rtB ->
lxjiyfzas2 = ! _rtDW -> bmy4qihc4v ; if ( ssIsSampleHit ( S , 2 , 0 ) ) {
_rtB -> lclsswngjq = ld5zvvrfqt ( S ) -> ira4syeobn - ( ld5zvvrfqt ( S ) ->
k5zbhla4ae - _rtB -> ovablii5uy ) * 200.0 ; } jgewyk5b21 = _rtB -> lclsswngjq
; if ( jgewyk5b21 > 21000.0 ) { _rtB -> mud5k31uc5 = 21000.0 ; } else if (
jgewyk5b21 < 0.0 ) { _rtB -> mud5k31uc5 = 0.0 ; } else { _rtB -> mud5k31uc5 =
jgewyk5b21 ; } if ( ( _rtDW -> n33aen2wbt >= ssGetTaskTime ( S , 0 ) ) && (
_rtDW -> fjojh4ewqs >= ssGetTaskTime ( S , 0 ) ) ) { _rtB -> jmnbkdhupp =
_rtB -> mud5k31uc5 ; } else { if ( ( ( _rtDW -> n33aen2wbt < _rtDW ->
fjojh4ewqs ) && ( _rtDW -> fjojh4ewqs < ssGetTaskTime ( S , 0 ) ) ) || ( (
_rtDW -> n33aen2wbt >= _rtDW -> fjojh4ewqs ) && ( _rtDW -> n33aen2wbt >=
ssGetTaskTime ( S , 0 ) ) ) ) { iiis24gb3o = ssGetTaskTime ( S , 0 ) - _rtDW
-> fjojh4ewqs ; lebvfutt11 = _rtDW -> d21ysphefx ; } else { iiis24gb3o =
ssGetTaskTime ( S , 0 ) - _rtDW -> n33aen2wbt ; lebvfutt11 = _rtDW ->
evmu5j4txb ; } lstej3qx0u = iiis24gb3o * 210000.0 ; f2e3v5ccex = _rtB ->
mud5k31uc5 - lebvfutt11 ; if ( f2e3v5ccex > lstej3qx0u ) { _rtB -> jmnbkdhupp
= lebvfutt11 + lstej3qx0u ; } else { iiis24gb3o *= - 210000.0 ; if (
f2e3v5ccex < iiis24gb3o ) { _rtB -> jmnbkdhupp = lebvfutt11 + iiis24gb3o ; }
else { _rtB -> jmnbkdhupp = _rtB -> mud5k31uc5 ; } } } fviymzl3aa = ( _rtB ->
phabbozbp4 != ld5zvvrfqt ( S ) -> ohsizqvf54 ) ; byehzqrbel = j0jhyqa1p3 -
_rtB -> lqgl4qsfga [ 1 ] * _rtB -> deyer4xufx [ 11 ] ; if ( fviymzl3aa ) {
_rtB -> lqxbpucx05 = _rtB -> phabbozbp4 ; } else { _rtB -> lqxbpucx05 =
byehzqrbel ; } if ( ( _rtDW -> nolj4flzwb >= ssGetTaskTime ( S , 0 ) ) && (
_rtDW -> bluedlz4ee >= ssGetTaskTime ( S , 0 ) ) ) { _rtB -> jqlvrukm35 =
_rtB -> lqxbpucx05 ; } else { if ( ( ( _rtDW -> nolj4flzwb < _rtDW ->
bluedlz4ee ) && ( _rtDW -> bluedlz4ee < ssGetTaskTime ( S , 0 ) ) ) || ( (
_rtDW -> nolj4flzwb >= _rtDW -> bluedlz4ee ) && ( _rtDW -> nolj4flzwb >=
ssGetTaskTime ( S , 0 ) ) ) ) { iiis24gb3o = ssGetTaskTime ( S , 0 ) - _rtDW
-> bluedlz4ee ; lebvfutt11 = _rtDW -> awi4nxie0m ; } else { iiis24gb3o =
ssGetTaskTime ( S , 0 ) - _rtDW -> nolj4flzwb ; lebvfutt11 = _rtDW ->
ppmw3hzciy ; } lstej3qx0u = iiis24gb3o * 21000.0 ; f2e3v5ccex = _rtB ->
lqxbpucx05 - lebvfutt11 ; if ( f2e3v5ccex > lstej3qx0u ) { _rtB -> jqlvrukm35
= lebvfutt11 + lstej3qx0u ; } else { iiis24gb3o *= - 21000.0 ; if (
f2e3v5ccex < iiis24gb3o ) { _rtB -> jqlvrukm35 = lebvfutt11 + iiis24gb3o ; }
else { _rtB -> jqlvrukm35 = _rtB -> lqxbpucx05 ; } } } if ( _rtB ->
lxjiyfzas2 != 0.0 ) { _rtB -> pxu1svzzij = _rtB -> potdmqfdua ; } else { if (
fviymzl3aa ) { byehzqrbel = _rtB -> jqlvrukm35 ; } if ( byehzqrbel > _rtB ->
jmnbkdhupp ) { byehzqrbel = _rtB -> jmnbkdhupp ; } else { if ( byehzqrbel < -
_rtB -> jmnbkdhupp ) { byehzqrbel = - _rtB -> jmnbkdhupp ; } } _rtB ->
pxu1svzzij = ( _rtB -> deyer4xufx [ 7 ] * _rtB -> abrqa35ynz + byehzqrbel ) /
i5nu34w4uj ; } ssCallAccelRunBlock ( S , 15 , 549 , SS_CALL_MDL_OUTPUTS ) ;
if ( ssIsSampleHit ( S , 2 , 0 ) ) { ssCallAccelRunBlock ( S , 15 , 550 ,
SS_CALL_MDL_OUTPUTS ) ; } ssCallAccelRunBlock ( S , 15 , 551 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> pzfvurdnse = 9.5492965855137211 * _rtB ->
cgf1ndpvv5 ; if ( ssIsSampleHit ( S , 2 , 0 ) && ssIsSampleHit ( S , 3 , 0 )
) { _rtB -> pj334wzmya = _rtDW -> bv5gvrfela ; } _rtB -> c1snypnc50 = _rtB ->
fp3x4xex4t * _rtB -> cgf1ndpvv5 ; ssCallAccelRunBlock ( S , 15 , 555 ,
SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSampleHit ( S , 2 , 0 ) ) {
ssCallAccelRunBlock ( S , 15 , 558 , SS_CALL_MDL_OUTPUTS ) ; }
ssCallAccelRunBlock ( S , 15 , 559 , SS_CALL_MDL_OUTPUTS ) ; if (
ssIsSampleHit ( S , 2 , 0 ) ) { lfv3m5pb5c = 0.013480000230266853 * _rtDW ->
pe31gvq3pv ; h0cg4jnrg5 = 0.013480000230266853 * _rtDW -> bw5cwo255x ; rowIdx
= ( int32_T ) ( ( ( ( ( uint32_T ) ( lfv3m5pb5c > h0cg4jnrg5 ) << 1 ) + (
lfv3m5pb5c < 0.9 * h0cg4jnrg5 ) ) << 1 ) + _rtDW -> l2t4rgxmml ) ; _rtB ->
lsjmvd53ha [ 0U ] = ni220kbneq . i1nwoqgijo [ ( uint32_T ) rowIdx ] ; _rtB ->
lsjmvd53ha [ 1U ] = ni220kbneq . i1nwoqgijo [ rowIdx + 8U ] ; h100jbae3x = (
uint8_T ) ( _rtB -> lsjmvd53ha [ 0 ] << 7 ) ; _rtB -> b3dcnn13ix = ( real_T )
h100jbae3x * 0.0078125 ; _rtB -> f03cmnom4l = ( real_T ) h100jbae3x *
0.0078125 ; _rtB -> ns4dlzmexp = ( real_T ) h100jbae3x * 0.0078125 ;
fviymzl3aa = ! ( h100jbae3x != 0 ) ; _rtB -> my2c0hxv3e = fviymzl3aa ; _rtB
-> l2dlcyvo1u = fviymzl3aa ; _rtB -> k0gqzsmhmp = fviymzl3aa ; _rtB ->
alf2wq40zx = ( ( _rtB -> lyhdwkntva [ 30 ] * _rtB -> lyhdwkntva [ 30 ] + _rtB
-> lyhdwkntva [ 31 ] * _rtB -> lyhdwkntva [ 31 ] ) + _rtB -> lyhdwkntva [ 32
] * _rtB -> lyhdwkntva [ 32 ] ) * 0.001 + ( _rtB -> lyhdwkntva [ 21 ] * _rtB
-> lyhdwkntva [ 30 ] + _rtB -> lyhdwkntva [ 22 ] * _rtB -> lyhdwkntva [ 31 ]
) ; } byehzqrbel = muDoubleScalarPower ( ( 0.006391889398924 * _rtB ->
cgf1ndpvv5 * _rtB -> iwocvn0p4u + 0.0065 * _rtB -> itq4augluc ) +
0.702664574517444 * _rtB -> cgf1ndpvv5 , 2.0 ) + muDoubleScalarPower ( 0.0065
* _rtB -> iwocvn0p4u - 0.008228209001868 * _rtB -> cgf1ndpvv5 * _rtB ->
itq4augluc , 2.0 ) ; if ( byehzqrbel < 0.0 ) { byehzqrbel = -
muDoubleScalarSqrt ( - byehzqrbel ) ; } else { byehzqrbel =
muDoubleScalarSqrt ( byehzqrbel ) ; } _rtB -> izwwv4sglz = 1.5707963267948966
* byehzqrbel ; if ( ssIsSampleHit ( S , 2 , 0 ) ) { _rtB -> jqaligr4kv = ( (
2.0 * _rtB -> lyhdwkntva [ 14 ] + _rtB -> lyhdwkntva [ 15 ] ) * mizlp41tvx +
1.7320508075688772 * _rtB -> lyhdwkntva [ 15 ] * po0ockmy2b ) *
0.33333333333333331 ; _rtB -> ngag1sitta = ( ( 2.0 * _rtB -> lyhdwkntva [ 14
] + _rtB -> lyhdwkntva [ 15 ] ) * po0ockmy2b + - 1.7320508075688772 * _rtB ->
lyhdwkntva [ 15 ] * mizlp41tvx ) * 0.33333333333333331 ; _rtB -> dim0zirdbp =
625.79305591134812 * _rtB -> ngag1sitta ; } _rtB -> ogrvzfntu3 = 4.0 * _rtB
-> cgf1ndpvv5 ; if ( ssIsSampleHit ( S , 2 , 0 ) ) { _rtB -> aensjs02yb =
4.0676548634237628 * _rtB -> iwocvn0p4u ; } _rtB -> ffd3nrol1c = _rtB ->
ogrvzfntu3 * _rtB -> itq4augluc * 1.2872890139890598 + ( _rtB -> dim0zirdbp -
_rtB -> aensjs02yb ) ; if ( ssIsSampleHit ( S , 2 , 0 ) ) { _rtB ->
pjhwtgkqwl = 486.13252277523628 * _rtB -> jqaligr4kv ; _rtB -> i2xgt4nij4 =
3.1598613980390358 * _rtB -> itq4augluc ; } _rtB -> pwu4ma5azo = ( ( _rtB ->
pjhwtgkqwl - _rtB -> i2xgt4nij4 ) - _rtB -> iwocvn0p4u * _rtB -> ogrvzfntu3 *
0.77682632969980325 ) - 85.397025568738272 * _rtB -> ogrvzfntu3 ; jgewyk5b21
= muDoubleScalarAbs ( _rtB -> cgf1ndpvv5 ) ; HEV_acc_LookUp_real_T_real_T ( &
( jk5r3ummcw ) , ni220kbneq . kra3wm5gfy , jgewyk5b21 , ni220kbneq .
elvuv43juu , 6U ) ; if ( _rtB -> pxu1svzzij > jk5r3ummcw ) { jgewyk5b21 =
jk5r3ummcw ; } else if ( _rtB -> pxu1svzzij < - jk5r3ummcw ) { jgewyk5b21 = -
jk5r3ummcw ; } else { jgewyk5b21 = _rtB -> pxu1svzzij ; } jgewyk5b21 *=
ld5zvvrfqt ( S ) -> atmyqjofcf ; if ( ( _rtDW -> dlegz3mcx5 == ( rtMinusInf )
) || ( _rtDW -> dlegz3mcx5 == ssGetTaskTime ( S , 0 ) ) ) { _rtDW ->
dlegz3mcx5 = ssGetTaskTime ( S , 0 ) ; _rtB -> gfj4qcofr5 = 0.0 ; } else {
_rtB -> gfj4qcofr5 = jgewyk5b21 ; } if ( ssIsSampleHit ( S , 3 , 0 ) ) { _rtB
-> ozwulgm1db = _rtB -> gfj4qcofr5 ; if ( _rtB -> ozwulgm1db > 400.0 ) { _rtB
-> hebcnz5ztd = 400.0 ; } else if ( _rtB -> ozwulgm1db < - 400.0 ) { _rtB ->
hebcnz5ztd = - 400.0 ; } else { _rtB -> hebcnz5ztd = _rtB -> ozwulgm1db ; } }
if ( ssIsSampleHit ( S , 1 , 0 ) && ssIsSampleHit ( S , 3 , 0 ) ) { _rtB ->
cbkmt3uyb3 = ld5zvvrfqt ( S ) -> atmyqjofcf ; } if ( ssIsSampleHit ( S , 3 ,
0 ) ) { _rtB -> nkbjhftee3 = _rtB -> hebcnz5ztd * _rtB -> cbkmt3uyb3 ; } if (
ssIsSampleHit ( S , 2 , 0 ) ) { ssCallAccelRunBlock ( S , 15 , 700 ,
SS_CALL_MDL_OUTPUTS ) ; } ssCallAccelRunBlock ( S , 15 , 701 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> pzfvurdnse = 9.5492965855137211 * _rtB ->
deyer4xufx [ 7 ] ; if ( ssIsSampleHit ( S , 1 , 0 ) && ssIsSampleHit ( S , 2
, 0 ) ) { _rtB -> j0xcvzwure = ld5zvvrfqt ( S ) -> n2qw0mbreu ; } if (
ssIsSampleHit ( S , 2 , 0 ) ) { _rtB -> adkwuaznnh = dztyrqu4xa * _rtB ->
j0xcvzwure ; } _rtB -> c1snypnc50 = _rtB -> au4vfwszcw * _rtB -> deyer4xufx [
7 ] ; ssCallAccelRunBlock ( S , 15 , 706 , SS_CALL_MDL_OUTPUTS ) ; if (
ssIsSampleHit ( S , 2 , 0 ) ) { lfv3m5pb5c = 0.013480000230266853 * _rtDW ->
dy4ppyw4mo ; h0cg4jnrg5 = 0.013480000230266853 * _rtDW -> hmybg5b1mi ; rowIdx
= ( int32_T ) ( ( ( ( ( uint32_T ) ( lfv3m5pb5c > h0cg4jnrg5 ) << 1 ) + (
lfv3m5pb5c < 0.9 * h0cg4jnrg5 ) ) << 1 ) + _rtDW -> gkq12xkctn ) ; _rtB ->
g31w3nr4hv [ 0U ] = ni220kbneq . i1nwoqgijo [ ( uint32_T ) rowIdx ] ; _rtB ->
g31w3nr4hv [ 1U ] = ni220kbneq . i1nwoqgijo [ rowIdx + 8U ] ; h100jbae3x = (
uint8_T ) ( _rtB -> g31w3nr4hv [ 0 ] << 7 ) ; _rtB -> iroibsu4le = ( real_T )
h100jbae3x * 0.0078125 ; _rtB -> hwses4osjk = ( real_T ) h100jbae3x *
0.0078125 ; _rtB -> pme5i13tqx = ( real_T ) h100jbae3x * 0.0078125 ;
fviymzl3aa = ! ( h100jbae3x != 0 ) ; _rtB -> oyjta5mc2h = fviymzl3aa ; _rtB
-> aj5usbdncr = fviymzl3aa ; _rtB -> egkvrydwqr = fviymzl3aa ; _rtB ->
fqonxys5pb = ( ( _rtB -> lyhdwkntva [ 26 ] * _rtB -> lyhdwkntva [ 26 ] + _rtB
-> lyhdwkntva [ 27 ] * _rtB -> lyhdwkntva [ 27 ] ) + _rtB -> lyhdwkntva [ 28
] * _rtB -> lyhdwkntva [ 28 ] ) * 0.001 + ( _rtB -> lyhdwkntva [ 17 ] * _rtB
-> lyhdwkntva [ 26 ] + _rtB -> lyhdwkntva [ 18 ] * _rtB -> lyhdwkntva [ 27 ]
) ; } byehzqrbel = muDoubleScalarPower ( ( 0.000635 * _rtB -> deyer4xufx [ 7
] * _rtB -> hvatssmzeb + 0.05 * _rtB -> bei1xfdtco ) + 0.192 * _rtB ->
deyer4xufx [ 7 ] , 2.0 ) + muDoubleScalarPower ( 0.05 * _rtB -> hvatssmzeb -
0.000635 * _rtB -> deyer4xufx [ 7 ] * _rtB -> bei1xfdtco , 2.0 ) ; if (
byehzqrbel < 0.0 ) { byehzqrbel = - muDoubleScalarSqrt ( - byehzqrbel ) ; }
else { byehzqrbel = muDoubleScalarSqrt ( byehzqrbel ) ; } _rtB -> nsa1sh1pgu
= 1.5707963267948966 * byehzqrbel ; if ( ssIsSampleHit ( S , 2 , 0 ) ) { _rtB
-> exanjqd2yw = ( ( 2.0 * _rtB -> lyhdwkntva [ 12 ] + _rtB -> lyhdwkntva [ 13
] ) * mkcfwi2fsi + 1.7320508075688772 * _rtB -> lyhdwkntva [ 13 ] *
ehtkh2wauy ) * 0.33333333333333331 ; _rtB -> kcndnqkq4w = ( ( 2.0 * _rtB ->
lyhdwkntva [ 12 ] + _rtB -> lyhdwkntva [ 13 ] ) * ehtkh2wauy + -
1.7320508075688772 * _rtB -> lyhdwkntva [ 13 ] * mkcfwi2fsi ) *
0.33333333333333331 ; _rtB -> gux1vpgoht = 1574.803149606299 * _rtB ->
kcndnqkq4w ; _rtB -> c32aqw1s4v = 78.740157480314963 * _rtB -> hvatssmzeb ; }
_rtB -> k5fv4ucxld = ( _rtB -> gux1vpgoht - _rtB -> c32aqw1s4v ) + _rtB ->
deyer4xufx [ 7 ] * _rtB -> bei1xfdtco ; if ( ssIsSampleHit ( S , 2 , 0 ) ) {
_rtB -> mfoj0z340m = 1574.803149606299 * _rtB -> exanjqd2yw ; _rtB ->
mg1evzxx31 = 78.740157480314963 * _rtB -> bei1xfdtco ; } _rtB -> mt3smrrwns =
( ( _rtB -> mfoj0z340m - _rtB -> mg1evzxx31 ) - _rtB -> hvatssmzeb * _rtB ->
deyer4xufx [ 7 ] ) - 302.36220472440942 * _rtB -> deyer4xufx [ 7 ] ; if (
ssIsSampleHit ( S , 2 , 0 ) ) { ssCallAccelRunBlock ( S , 15 , 835 ,
SS_CALL_MDL_OUTPUTS ) ; } jgewyk5b21 = ssGetT ( S ) ; if ( ssIsSampleHit ( S
, 2 , 0 ) ) { _rtB -> kraonyhmjh = _rtB -> lyhdwkntva [ 16 ] - ld5zvvrfqt ( S
) -> ojdtgpkggs ; } _rtB -> az4z0umyma = ( real_T ) ( jgewyk5b21 > ld5zvvrfqt
( S ) -> mws3xlil1z ) * _rtB -> kraonyhmjh ; if ( ssIsSampleHit ( S , 2 , 0 )
) { if ( _rtDW -> llu3sg1ihp != 0 ) { _rtB -> g1heig2g2s = _rtDW ->
fj2gixcnhk ; } else { _rtB -> g1heig2g2s = 3.0E-5 * _rtB -> az4z0umyma +
_rtDW -> fj2gixcnhk ; } if ( _rtB -> g1heig2g2s >= 1.0 ) { _rtB -> g1heig2g2s
= 1.0 ; } else { if ( _rtB -> g1heig2g2s <= - 1.0 ) { _rtB -> g1heig2g2s = -
1.0 ; } } } jgewyk5b21 = 0.001 * _rtB -> az4z0umyma + _rtB -> g1heig2g2s ; if
( jgewyk5b21 > 0.95 ) { h0cg4jnrg5 = 0.95 ; } else if ( jgewyk5b21 < - 0.95 )
{ h0cg4jnrg5 = - 0.95 ; } else { h0cg4jnrg5 = jgewyk5b21 ; } _rtB ->
lxo30patnp = ( h0cg4jnrg5 + 1.0 ) * 0.5 ; if ( ssIsSampleHit ( S , 2 , 0 ) )
{ lfv3m5pb5c = _rtDW -> dco4afubi3 ; _rtB -> n4uphgztn5 = _rtDW -> dco4afubi3
* _rtB -> lyhdwkntva [ 24 ] ; _rtB -> id01unheeo = _rtDW -> dco4afubi3 * _rtB
-> lyhdwkntva [ 34 ] ; } ssCallAccelRunBlock ( S , 15 , 882 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 15 , 883 ,
SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSampleHit ( S , 2 , 0 ) ) {
ssCallAccelRunBlock ( S , 15 , 884 , SS_CALL_MDL_OUTPUTS ) ; }
ssCallAccelRunBlock ( S , 15 , 885 , SS_CALL_MDL_OUTPUTS ) ; if (
ssIsSampleHit ( S , 4 , 0 ) ) { ssCallAccelRunBlock ( S , 15 , 886 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 15 , 887 ,
SS_CALL_MDL_OUTPUTS ) ; } if ( _rtB -> ouzbqmpx2w > 136.0 ) { h0cg4jnrg5 =
136.0 ; } else if ( _rtB -> ouzbqmpx2w < 0.0 ) { h0cg4jnrg5 = 0.0 ; } else {
h0cg4jnrg5 = _rtB -> ouzbqmpx2w ; } jgewyk5b21 = h0cg4jnrg5 * ld5zvvrfqt ( S
) -> bvbribfw2u ; if ( jgewyk5b21 > 1.0 ) { _rtB -> pzfvurdnse = 1.0 ; } else
if ( jgewyk5b21 < 0.0 ) { _rtB -> pzfvurdnse = 0.0 ; } else { _rtB ->
pzfvurdnse = jgewyk5b21 ; } ssCallAccelRunBlock ( S , 15 , 892 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 15 , 893 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 15 , 894 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 15 , 895 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 15 , 896 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 15 , 897 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 15 , 898 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 15 , 899 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 15 , 900 ,
SS_CALL_MDL_OUTPUTS ) ; jgewyk5b21 = _rtB -> hfck4o5hrr * ( real_T )
o3khhk3fbg ; if ( ( _rtDW -> nn1a5wvgr5 == ( rtMinusInf ) ) || ( _rtDW ->
nn1a5wvgr5 == ssGetTaskTime ( S , 0 ) ) ) { _rtDW -> nn1a5wvgr5 =
ssGetTaskTime ( S , 0 ) ; _rtB -> fn0lnlijgk = 0.0 ; } else { _rtB ->
fn0lnlijgk = jgewyk5b21 ; } if ( ( _rtDW -> ewhcynzuun >= ssGetTaskTime ( S ,
0 ) ) && ( _rtDW -> ciu3b0lpet >= ssGetTaskTime ( S , 0 ) ) ) { _rtB ->
mlv3wqd2k2 = _rtB -> fn0lnlijgk ; } else { if ( ( ( _rtDW -> ewhcynzuun <
_rtDW -> ciu3b0lpet ) && ( _rtDW -> ciu3b0lpet < ssGetTaskTime ( S , 0 ) ) )
|| ( ( _rtDW -> ewhcynzuun >= _rtDW -> ciu3b0lpet ) && ( _rtDW -> ewhcynzuun
>= ssGetTaskTime ( S , 0 ) ) ) ) { iiis24gb3o = ssGetTaskTime ( S , 0 ) -
_rtDW -> ciu3b0lpet ; lebvfutt11 = _rtDW -> mmlyeyihwy ; } else { iiis24gb3o
= ssGetTaskTime ( S , 0 ) - _rtDW -> ewhcynzuun ; lebvfutt11 = _rtDW ->
h4ipbzntlo ; } lstej3qx0u = iiis24gb3o * 50000.0 ; f2e3v5ccex = _rtB ->
fn0lnlijgk - lebvfutt11 ; if ( f2e3v5ccex > lstej3qx0u ) { _rtB -> mlv3wqd2k2
= lebvfutt11 + lstej3qx0u ; } else { iiis24gb3o *= - 50000.0 ; if (
f2e3v5ccex < iiis24gb3o ) { _rtB -> mlv3wqd2k2 = lebvfutt11 + iiis24gb3o ; }
else { _rtB -> mlv3wqd2k2 = _rtB -> fn0lnlijgk ; } } } if ( ssIsSampleHit ( S
, 2 , 0 ) ) { _rtB -> mxdg1j4sbh = o3khhk3fbg ; h0cg4jnrg5 = ( _rtB ->
mlv3wqd2k2 - 0.036997346603025116 * _rtDW -> jctbfc4f1e ) * ( real_T ) _rtB
-> mxdg1j4sbh ; _rtB -> cxtiircebz = 0.1 * h0cg4jnrg5 ; if ( _rtDW ->
h4pa1qmmy5 != 0 ) { _rtB -> fys0ai44nk = _rtDW -> olv3cnxtoy ; } else { _rtB
-> fys0ai44nk = 3.0E-5 * _rtB -> cxtiircebz + _rtDW -> olv3cnxtoy ; } if (
_rtB -> fys0ai44nk >= 1.0 ) { _rtB -> fys0ai44nk = 1.0 ; } else { if ( _rtB
-> fys0ai44nk <= 0.0 ) { _rtB -> fys0ai44nk = 0.0 ; } } lfv3m5pb5c = 0.01 *
h0cg4jnrg5 + _rtB -> fys0ai44nk ; if ( lfv3m5pb5c > 1.0 ) { lfv3m5pb5c = 1.0
; } else { if ( lfv3m5pb5c < 0.0 ) { lfv3m5pb5c = 0.0 ; } } } jgewyk5b21 =
_rtB -> deyer4xufx [ 11 ] * ( real_T ) o3khhk3fbg ; _rtB -> nmkykeqk42 =
9.5492965855137211 * jgewyk5b21 ; if ( ssIsSampleHit ( S , 2 , 0 ) ) { _rtB
-> mntwfgi23x = _rtB -> nmkykeqk42 ; _rtB -> etfajiplps = lfv3m5pb5c * (
real_T ) _rtB -> mxdg1j4sbh ; } _rtB -> mt2nkeqr4b = muDoubleScalarAbs ( _rtB
-> cvcqn2f3ws ) ; if ( ( _rtDW -> en15lu4hm1 >= ssGetT ( S ) ) && ( _rtDW ->
km4yirabra >= ssGetT ( S ) ) ) { _rtB -> f5bbezwkea = 0.0 ; } else {
byehzqrbel = _rtDW -> en15lu4hm1 ; lastU = & _rtDW -> aa3vndu55f ; if ( _rtDW
-> en15lu4hm1 < _rtDW -> km4yirabra ) { if ( _rtDW -> km4yirabra < ssGetT ( S
) ) { byehzqrbel = _rtDW -> km4yirabra ; lastU = & _rtDW -> ke4dqjfdz3 ; } }
else { if ( _rtDW -> en15lu4hm1 >= ssGetT ( S ) ) { byehzqrbel = _rtDW ->
km4yirabra ; lastU = & _rtDW -> ke4dqjfdz3 ; } } _rtB -> f5bbezwkea = ( _rtB
-> f32s5izkc1 - * lastU ) / ( ssGetT ( S ) - byehzqrbel ) ; } _rtB ->
cjae301qvi = muDoubleScalarAbs ( _rtB -> mxteghcp0h ) ; _rtB -> dxnoxgjhb1 =
1.093 * _rtB -> cjae301qvi ; _rtB -> d5224gbyeq = 1.0464 * _rtB -> f32s5izkc1
; { uint32_T iLeftU0 , iRghtU0 , iLeftU1 , iRghtU1 ;
HEV_acc_BINARYSEARCH_real_T ( & ( iLeftU0 ) , & ( iRghtU0 ) , _rtB ->
dxnoxgjhb1 , ni220kbneq . hlsjpbjuty , 108U ) ; if ( _rtB -> d5224gbyeq <=
0.0 ) { iLeftU1 = 0U ; iRghtU1 = 0U ; } else if ( _rtB -> d5224gbyeq >=
6000.0 ) { iLeftU1 = 100U ; iRghtU1 = 100U ; } else { iLeftU1 = ( uint32_T )
( ( _rtB -> d5224gbyeq ) / 60.0 ) ; iRghtU1 = iLeftU1 + 1 ; } { real_T yTemp
; real_T u1Lambda ; real_T u0Lambda ; if ( iLeftU1 != iRghtU1 ) { { real_T
num = ( real_T ) ( _rtB -> d5224gbyeq ) - ( iLeftU1 * 60.0 ) ; u1Lambda = num
/ 60.0 ; } } else { u1Lambda = 0.0 ; } if ( ( ni220kbneq . hlsjpbjuty [
iRghtU0 ] ) > ( ni220kbneq . hlsjpbjuty [ iLeftU0 ] ) ) { real_T num ; real_T
den ; den = ( ni220kbneq . hlsjpbjuty [ iRghtU0 ] ) ; den -= ( ni220kbneq .
hlsjpbjuty [ iLeftU0 ] ) ; num = _rtB -> dxnoxgjhb1 ; num -= ( ni220kbneq .
hlsjpbjuty [ iLeftU0 ] ) ; u0Lambda = num / den ; } else { u0Lambda = 0.0 ; }
{ real_T yLeftCast ; real_T yRghtCast ; yLeftCast = ( ni220kbneq . lj0gbaycmo
[ ( iLeftU0 + 109U * iLeftU1 ) ] ) ; yRghtCast = ( ni220kbneq . lj0gbaycmo [
( iLeftU0 + 109U * iRghtU1 ) ] ) ; yLeftCast += u1Lambda * ( yRghtCast -
yLeftCast ) ; k0ayfyp2ys = yLeftCast ; } { real_T yLeftCast ; real_T
yRghtCast ; yLeftCast = ( ni220kbneq . lj0gbaycmo [ ( iRghtU0 + 109U *
iLeftU1 ) ] ) ; yRghtCast = ( ni220kbneq . lj0gbaycmo [ ( iRghtU0 + 109U *
iRghtU1 ) ] ) ; yLeftCast += u1Lambda * ( yRghtCast - yLeftCast ) ; yTemp =
yLeftCast ; } { real_T yLeftCast ; real_T yRghtCast ; yLeftCast = k0ayfyp2ys
; yRghtCast = yTemp ; yLeftCast += u0Lambda * ( yRghtCast - yLeftCast ) ;
k0ayfyp2ys = yLeftCast ; } } } _rtB -> ce0uixknbl = 1.0351048413332149 *
k0ayfyp2ys ; _rtB -> a2ufzmzymb = 1.933764640184292E-6 * _rtB -> ce0uixknbl ;
_rtB -> kbz2voprmo = muDoubleScalarSign ( _rtB -> mxteghcp0h ) ; _rtB ->
dkocvhlvsg = muDoubleScalarAbs ( _rtB -> mxteghcp0h ) ; _rtB -> gfupnoowen =
1.093 * _rtB -> dkocvhlvsg ; _rtB -> macyp1addf = 1.0464 * _rtB -> f32s5izkc1
; { uint32_T iLeftU0 , iRghtU0 , iLeftU1 , iRghtU1 ;
HEV_acc_BINARYSEARCH_real_T ( & ( iLeftU0 ) , & ( iRghtU0 ) , _rtB ->
gfupnoowen , ni220kbneq . hlsjpbjuty , 108U ) ; if ( _rtB -> macyp1addf <=
0.0 ) { iLeftU1 = 0U ; iRghtU1 = 0U ; } else if ( _rtB -> macyp1addf >=
6000.0 ) { iLeftU1 = 100U ; iRghtU1 = 100U ; } else { iLeftU1 = ( uint32_T )
( ( _rtB -> macyp1addf ) / 60.0 ) ; iRghtU1 = iLeftU1 + 1 ; } { real_T yTemp
; real_T u1Lambda ; real_T u0Lambda ; if ( iLeftU1 != iRghtU1 ) { { real_T
num = ( real_T ) ( _rtB -> macyp1addf ) - ( iLeftU1 * 60.0 ) ; u1Lambda = num
/ 60.0 ; } } else { u1Lambda = 0.0 ; } if ( ( ni220kbneq . hlsjpbjuty [
iRghtU0 ] ) > ( ni220kbneq . hlsjpbjuty [ iLeftU0 ] ) ) { real_T num ; real_T
den ; den = ( ni220kbneq . hlsjpbjuty [ iRghtU0 ] ) ; den -= ( ni220kbneq .
hlsjpbjuty [ iLeftU0 ] ) ; num = _rtB -> gfupnoowen ; num -= ( ni220kbneq .
hlsjpbjuty [ iLeftU0 ] ) ; u0Lambda = num / den ; } else { u0Lambda = 0.0 ; }
{ real_T yLeftCast ; real_T yRghtCast ; yLeftCast = ( ni220kbneq . fiqfpbio0e
[ ( iLeftU0 + 109U * iLeftU1 ) ] ) ; yRghtCast = ( ni220kbneq . fiqfpbio0e [
( iLeftU0 + 109U * iRghtU1 ) ] ) ; yLeftCast += u1Lambda * ( yRghtCast -
yLeftCast ) ; kfa2w4tlhe = yLeftCast ; } { real_T yLeftCast ; real_T
yRghtCast ; yLeftCast = ( ni220kbneq . fiqfpbio0e [ ( iRghtU0 + 109U *
iLeftU1 ) ] ) ; yRghtCast = ( ni220kbneq . fiqfpbio0e [ ( iRghtU0 + 109U *
iRghtU1 ) ] ) ; yLeftCast += u1Lambda * ( yRghtCast - yLeftCast ) ; yTemp =
yLeftCast ; } { real_T yLeftCast ; real_T yRghtCast ; yLeftCast = kfa2w4tlhe
; yRghtCast = yTemp ; yLeftCast += u0Lambda * ( yRghtCast - yLeftCast ) ;
kfa2w4tlhe = yLeftCast ; } } } _rtB -> a5fvrf2lyb = 1.0351048413332149 *
kfa2w4tlhe ; _rtB -> ho5actsw4x = _rtB -> kbz2voprmo * _rtB -> a5fvrf2lyb ;
_rtB -> lu3vcekbc4 = _rtB -> ho5actsw4x * _rtB -> f5bbezwkea ; _rtB ->
c3e0c1nulf = 1.933764640184292E-6 * _rtB -> lu3vcekbc4 ; _rtB -> hdxyjdbz31 =
_rtB -> mt2nkeqr4b * _rtB -> mxteghcp0h ; if ( _rtB -> a2ufzmzymb <= 0.02 ) {
_rtB -> it54nlyvwz = 0.02 ; } else { _rtB -> it54nlyvwz = _rtB -> a2ufzmzymb
; } _rtB -> gob13mn3ud = ( ( 0.0 - _rtB -> c3e0c1nulf ) - _rtB -> mwmukr1b0s
) - _rtB -> hdxyjdbz31 ; _rtB -> creyxg0p4j = 1.0 / _rtB -> it54nlyvwz * _rtB
-> gob13mn3ud ; _rtB -> oxrw2eptzy = _rtB -> jl0wk2sppa + _rtB -> lvcp0zglue
; _rtB -> gusra3qrhw = ( _rtB -> oxrw2eptzy - _rtB -> nnvhzguiuk ) -
ld5zvvrfqt ( S ) -> hz4isiiiw4 ; _rtB -> jtchakzyhg = 0.00075471698113207543
* _rtB -> gusra3qrhw ; _rtB -> iuowvpytqa = muDoubleScalarAbs ( _rtB ->
cvcqn2f3ws ) ; if ( ( _rtDW -> cgi523usaj >= ssGetT ( S ) ) && ( _rtDW ->
irt5havirw >= ssGetT ( S ) ) ) { _rtB -> clovp5pk0s = 0.0 ; } else {
byehzqrbel = _rtDW -> cgi523usaj ; lastU = & _rtDW -> edrzze2flm ; if ( _rtDW
-> cgi523usaj < _rtDW -> irt5havirw ) { if ( _rtDW -> irt5havirw < ssGetT ( S
) ) { byehzqrbel = _rtDW -> irt5havirw ; lastU = & _rtDW -> gljjadsfzv ; } }
else { if ( _rtDW -> cgi523usaj >= ssGetT ( S ) ) { byehzqrbel = _rtDW ->
irt5havirw ; lastU = & _rtDW -> gljjadsfzv ; } } _rtB -> clovp5pk0s = ( _rtB
-> fdxtksxpa1 - * lastU ) / ( ssGetT ( S ) - byehzqrbel ) ; } _rtB ->
jemy00bds0 = muDoubleScalarAbs ( _rtB -> bn3r3upnmr ) ; _rtB -> puamkrvbee =
1.093 * _rtB -> jemy00bds0 ; _rtB -> pn4roijmmu = 1.0464 * _rtB -> fdxtksxpa1
; { uint32_T iLeftU0 , iRghtU0 , iLeftU1 , iRghtU1 ;
HEV_acc_BINARYSEARCH_real_T ( & ( iLeftU0 ) , & ( iRghtU0 ) , _rtB ->
puamkrvbee , ni220kbneq . hlsjpbjuty , 108U ) ; if ( _rtB -> pn4roijmmu <=
0.0 ) { iLeftU1 = 0U ; iRghtU1 = 0U ; } else if ( _rtB -> pn4roijmmu >=
6000.0 ) { iLeftU1 = 100U ; iRghtU1 = 100U ; } else { iLeftU1 = ( uint32_T )
( ( _rtB -> pn4roijmmu ) / 60.0 ) ; iRghtU1 = iLeftU1 + 1 ; } { real_T yTemp
; real_T u1Lambda ; real_T u0Lambda ; if ( iLeftU1 != iRghtU1 ) { { real_T
num = ( real_T ) ( _rtB -> pn4roijmmu ) - ( iLeftU1 * 60.0 ) ; u1Lambda = num
/ 60.0 ; } } else { u1Lambda = 0.0 ; } if ( ( ni220kbneq . hlsjpbjuty [
iRghtU0 ] ) > ( ni220kbneq . hlsjpbjuty [ iLeftU0 ] ) ) { real_T num ; real_T
den ; den = ( ni220kbneq . hlsjpbjuty [ iRghtU0 ] ) ; den -= ( ni220kbneq .
hlsjpbjuty [ iLeftU0 ] ) ; num = _rtB -> puamkrvbee ; num -= ( ni220kbneq .
hlsjpbjuty [ iLeftU0 ] ) ; u0Lambda = num / den ; } else { u0Lambda = 0.0 ; }
{ real_T yLeftCast ; real_T yRghtCast ; yLeftCast = ( ni220kbneq . lj0gbaycmo
[ ( iLeftU0 + 109U * iLeftU1 ) ] ) ; yRghtCast = ( ni220kbneq . lj0gbaycmo [
( iLeftU0 + 109U * iRghtU1 ) ] ) ; yLeftCast += u1Lambda * ( yRghtCast -
yLeftCast ) ; avmmym1aoe = yLeftCast ; } { real_T yLeftCast ; real_T
yRghtCast ; yLeftCast = ( ni220kbneq . lj0gbaycmo [ ( iRghtU0 + 109U *
iLeftU1 ) ] ) ; yRghtCast = ( ni220kbneq . lj0gbaycmo [ ( iRghtU0 + 109U *
iRghtU1 ) ] ) ; yLeftCast += u1Lambda * ( yRghtCast - yLeftCast ) ; yTemp =
yLeftCast ; } { real_T yLeftCast ; real_T yRghtCast ; yLeftCast = avmmym1aoe
; yRghtCast = yTemp ; yLeftCast += u0Lambda * ( yRghtCast - yLeftCast ) ;
avmmym1aoe = yLeftCast ; } } } _rtB -> a2tj1darjv = 1.0351048413332149 *
avmmym1aoe ; _rtB -> oxv3hgb2ea = 1.933764640184292E-6 * _rtB -> a2tj1darjv ;
_rtB -> ibcjegghix = muDoubleScalarSign ( _rtB -> bn3r3upnmr ) ; _rtB ->
g4lzuqnuj4 = muDoubleScalarAbs ( _rtB -> bn3r3upnmr ) ; _rtB -> jmwdezamd5 =
1.093 * _rtB -> g4lzuqnuj4 ; _rtB -> ar5o0dodhm = 1.0464 * _rtB -> fdxtksxpa1
; { uint32_T iLeftU0 , iRghtU0 , iLeftU1 , iRghtU1 ;
HEV_acc_BINARYSEARCH_real_T ( & ( iLeftU0 ) , & ( iRghtU0 ) , _rtB ->
jmwdezamd5 , ni220kbneq . hlsjpbjuty , 108U ) ; if ( _rtB -> ar5o0dodhm <=
0.0 ) { iLeftU1 = 0U ; iRghtU1 = 0U ; } else if ( _rtB -> ar5o0dodhm >=
6000.0 ) { iLeftU1 = 100U ; iRghtU1 = 100U ; } else { iLeftU1 = ( uint32_T )
( ( _rtB -> ar5o0dodhm ) / 60.0 ) ; iRghtU1 = iLeftU1 + 1 ; } { real_T yTemp
; real_T u1Lambda ; real_T u0Lambda ; if ( iLeftU1 != iRghtU1 ) { { real_T
num = ( real_T ) ( _rtB -> ar5o0dodhm ) - ( iLeftU1 * 60.0 ) ; u1Lambda = num
/ 60.0 ; } } else { u1Lambda = 0.0 ; } if ( ( ni220kbneq . hlsjpbjuty [
iRghtU0 ] ) > ( ni220kbneq . hlsjpbjuty [ iLeftU0 ] ) ) { real_T num ; real_T
den ; den = ( ni220kbneq . hlsjpbjuty [ iRghtU0 ] ) ; den -= ( ni220kbneq .
hlsjpbjuty [ iLeftU0 ] ) ; num = _rtB -> jmwdezamd5 ; num -= ( ni220kbneq .
hlsjpbjuty [ iLeftU0 ] ) ; u0Lambda = num / den ; } else { u0Lambda = 0.0 ; }
{ real_T yLeftCast ; real_T yRghtCast ; yLeftCast = ( ni220kbneq . fiqfpbio0e
[ ( iLeftU0 + 109U * iLeftU1 ) ] ) ; yRghtCast = ( ni220kbneq . fiqfpbio0e [
( iLeftU0 + 109U * iRghtU1 ) ] ) ; yLeftCast += u1Lambda * ( yRghtCast -
yLeftCast ) ; eso44m1g0y = yLeftCast ; } { real_T yLeftCast ; real_T
yRghtCast ; yLeftCast = ( ni220kbneq . fiqfpbio0e [ ( iRghtU0 + 109U *
iLeftU1 ) ] ) ; yRghtCast = ( ni220kbneq . fiqfpbio0e [ ( iRghtU0 + 109U *
iRghtU1 ) ] ) ; yLeftCast += u1Lambda * ( yRghtCast - yLeftCast ) ; yTemp =
yLeftCast ; } { real_T yLeftCast ; real_T yRghtCast ; yLeftCast = eso44m1g0y
; yRghtCast = yTemp ; yLeftCast += u0Lambda * ( yRghtCast - yLeftCast ) ;
eso44m1g0y = yLeftCast ; } } } _rtB -> owykfqd04c = 1.0351048413332149 *
eso44m1g0y ; _rtB -> huaravwsbs = _rtB -> ibcjegghix * _rtB -> owykfqd04c ;
_rtB -> lqzekhtgxm = _rtB -> huaravwsbs * _rtB -> clovp5pk0s ; _rtB ->
n5yck3vruy = 1.933764640184292E-6 * _rtB -> lqzekhtgxm ; _rtB -> jpytldhjar =
_rtB -> iuowvpytqa * _rtB -> bn3r3upnmr ; if ( _rtB -> oxv3hgb2ea <= 0.02 ) {
_rtB -> dbmk330qqr = 0.02 ; } else { _rtB -> dbmk330qqr = _rtB -> oxv3hgb2ea
; } _rtB -> gzo4gtfca3 = ( ( 0.0 - _rtB -> n5yck3vruy ) - _rtB -> fugepgv240
) - _rtB -> jpytldhjar ; _rtB -> kvvltoat4y = 1.0 / _rtB -> dbmk330qqr * _rtB
-> gzo4gtfca3 ; ssCallAccelRunBlock ( S , 15 , 975 , SS_CALL_MDL_OUTPUTS ) ;
_rtB -> hfck4o5hrr = _rtB -> deyer4xufx [ 9 ] * _rtB -> lqgl4qsfga [ 2 ] ;
_rtB -> pzfvurdnse = _rtB -> lqgl4qsfga [ 3 ] * _rtB -> deyer4xufx [ 6 ] ;
_rtB -> c1snypnc50 = _rtB -> deyer4xufx [ 8 ] * _rtB -> lqgl4qsfga [ 11 ] ;
_rtB -> f4bztwm5yt = _rtB -> pzfvurdnse + _rtB -> c1snypnc50 ;
ssCallAccelRunBlock ( S , 15 , 1023 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 15 , 1024 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 15 , 1025 , SS_CALL_MDL_OUTPUTS ) ;
UNUSED_PARAMETER ( tid ) ; }
#define MDL_UPDATE
static void mdlUpdate ( SimStruct * S , int_T tid ) { real_T * lastU ;
fdj1laa40s * _rtB ; h04hj5x5sk * _rtDW ; _rtDW = ( ( h04hj5x5sk * )
ssGetRootDWork ( S ) ) ; _rtB = ( ( fdj1laa40s * ) _ssGetBlockIO ( S ) ) ; if
( ssIsSampleHit ( S , 2 , 0 ) ) { _rtDW -> epw20ibixm += 6.0E-5 * _rtB ->
pwu4ma5azo ; _rtDW -> emjtqjwqij += 6.0E-5 * _rtB -> ffd3nrol1c ; _rtDW ->
aekc0mbj0y += 6.0E-5 * _rtB -> mt3smrrwns ; _rtDW -> oi2n4lur1q += 6.0E-5 *
_rtB -> k5fv4ucxld ; _rtDW -> jnhtlxaxxk = _rtB -> etfajiplps ; } if (
ssIsSampleHit ( S , 2 , 0 ) ) { _rtDW -> eaosag5owj += 6.0E-5 * _rtB ->
deyer4xufx [ 7 ] ; _rtDW -> jcugjk0yp0 += 6.0E-5 * _rtB -> ogrvzfntu3 ; _rtDW
-> jly33pdwub += 6.0E-5 * _rtB -> odcgudjzw0 ; _rtDW -> f2z5i2ds5e = _rtB ->
lyhdwkntva [ 33 ] - - 0.999994000018 * _rtDW -> f2z5i2ds5e ; } if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtDW -> b50c0wk1dc = _rtB -> nkqb3xlmau ; }
if ( ssIsSampleHit ( S , 2 , 0 ) ) { _rtDW -> o05rwe50bo = 0U ; _rtDW ->
pk42w2cjcz += 6.0E-5 * _rtB -> lyhdwkntva [ 33 ] ; if ( _rtDW -> pk42w2cjcz
>= 25200.0 ) { _rtDW -> pk42w2cjcz = 25200.0 ; } else { if ( _rtDW ->
pk42w2cjcz <= rtMinusInf ) { _rtDW -> pk42w2cjcz = rtMinusInf ; } } if ( _rtB
-> cgltpaixht > 0.0 ) { _rtDW -> f0fxu4veqt = 1 ; } else if ( _rtB ->
cgltpaixht < 0.0 ) { _rtDW -> f0fxu4veqt = - 1 ; } else if ( _rtB ->
cgltpaixht == 0.0 ) { _rtDW -> f0fxu4veqt = 0 ; } else { _rtDW -> f0fxu4veqt
= 2 ; } _rtDW -> fezg0yhyh2 = _rtB -> lyhdwkntva [ 19 ] ; _rtDW -> hdqerfit1p
[ 0 ] = _rtB -> lyhdwkntva [ 35 ] ; _rtDW -> hdqerfit1p [ 1 ] = _rtB ->
lyhdwkntva [ 36 ] ; _rtDW -> hdqerfit1p [ 2 ] = _rtB -> lyhdwkntva [ 37 ] ; }
if ( _rtDW -> mg242c3vwq == ( rtInf ) ) { _rtDW -> mg242c3vwq = ssGetTaskTime
( S , 0 ) ; _rtDW -> oiqwpboxgd = _rtB -> fr5a2e2puy ; } else if ( _rtDW ->
k1wt3kvmem == ( rtInf ) ) { _rtDW -> k1wt3kvmem = ssGetTaskTime ( S , 0 ) ;
_rtDW -> lzjsh0qxsz = _rtB -> fr5a2e2puy ; } else if ( _rtDW -> mg242c3vwq <
_rtDW -> k1wt3kvmem ) { _rtDW -> mg242c3vwq = ssGetTaskTime ( S , 0 ) ; _rtDW
-> oiqwpboxgd = _rtB -> fr5a2e2puy ; } else { _rtDW -> k1wt3kvmem =
ssGetTaskTime ( S , 0 ) ; _rtDW -> lzjsh0qxsz = _rtB -> fr5a2e2puy ; } if (
_rtDW -> cwivfg5ijd == ( rtInf ) ) { _rtDW -> cwivfg5ijd = ssGetTaskTime ( S
, 0 ) ; _rtDW -> kguctqvwvn = _rtB -> l5gtfbbgdv ; } else if ( _rtDW ->
m1iuzueluk == ( rtInf ) ) { _rtDW -> m1iuzueluk = ssGetTaskTime ( S , 0 ) ;
_rtDW -> bvl1znuobh = _rtB -> l5gtfbbgdv ; } else if ( _rtDW -> cwivfg5ijd <
_rtDW -> m1iuzueluk ) { _rtDW -> cwivfg5ijd = ssGetTaskTime ( S , 0 ) ; _rtDW
-> kguctqvwvn = _rtB -> l5gtfbbgdv ; } else { _rtDW -> m1iuzueluk =
ssGetTaskTime ( S , 0 ) ; _rtDW -> bvl1znuobh = _rtB -> l5gtfbbgdv ; } if (
ssIsSampleHit ( S , 2 , 0 ) ) { _rtDW -> bvad1zjfik = _rtB -> ew213nrs0e [ 0
] ; } if ( _rtDW -> hfvh40s0je == ( rtInf ) ) { _rtDW -> hfvh40s0je =
ssGetTaskTime ( S , 0 ) ; _rtDW -> lidlmlim32 = _rtB -> phabbozbp4 ; } else
if ( _rtDW -> f41a3yqptq == ( rtInf ) ) { _rtDW -> f41a3yqptq = ssGetTaskTime
( S , 0 ) ; _rtDW -> aq3qjo4ji4 = _rtB -> phabbozbp4 ; } else if ( _rtDW ->
hfvh40s0je < _rtDW -> f41a3yqptq ) { _rtDW -> hfvh40s0je = ssGetTaskTime ( S
, 0 ) ; _rtDW -> lidlmlim32 = _rtB -> phabbozbp4 ; } else { _rtDW ->
f41a3yqptq = ssGetTaskTime ( S , 0 ) ; _rtDW -> aq3qjo4ji4 = _rtB ->
phabbozbp4 ; } if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtDW -> aln04uuynj =
_rtB -> phabbozbp4 ; _rtDW -> nlh5qppt4m = _rtB -> n4rpd2rl5y ; } if (
ssIsSampleHit ( S , 2 , 0 ) ) { _rtDW -> bro0cn1wmi = _rtB -> lyhdwkntva [ 23
] ; _rtDW -> j31s1kcymk [ 0 ] = _rtB -> lyhdwkntva [ 38 ] ; _rtDW ->
j31s1kcymk [ 1 ] = _rtB -> lyhdwkntva [ 39 ] ; _rtDW -> j31s1kcymk [ 2 ] =
_rtB -> lyhdwkntva [ 40 ] ; } if ( ssIsSampleHit ( S , 3 , 0 ) ) { _rtDW ->
gsr0ogd2xb = _rtB -> hebcnz5ztd ; } if ( _rtDW -> joiszbfghn == ( rtInf ) ) {
_rtDW -> joiszbfghn = ssGetTaskTime ( S , 0 ) ; _rtDW -> narm2z4h4g = _rtB ->
eijf3boo05 ; } else if ( _rtDW -> jlnwqqs23l == ( rtInf ) ) { _rtDW ->
jlnwqqs23l = ssGetTaskTime ( S , 0 ) ; _rtDW -> miwjijsda1 = _rtB ->
eijf3boo05 ; } else if ( _rtDW -> joiszbfghn < _rtDW -> jlnwqqs23l ) { _rtDW
-> joiszbfghn = ssGetTaskTime ( S , 0 ) ; _rtDW -> narm2z4h4g = _rtB ->
eijf3boo05 ; } else { _rtDW -> jlnwqqs23l = ssGetTaskTime ( S , 0 ) ; _rtDW
-> miwjijsda1 = _rtB -> eijf3boo05 ; } if ( ssIsSampleHit ( S , 2 , 0 ) ) {
_rtDW -> kzrq2xyp0f = _rtB -> n4uphgztn5 ; _rtDW -> nonllthbl2 = _rtB ->
kcndnqkq4w - - 0.94176453358424872 * _rtDW -> nonllthbl2 ; _rtDW ->
kol45dq53x = _rtB -> exanjqd2yw - - 0.94176453358424872 * _rtDW -> kol45dq53x
; _rtDW -> fw2k5vojpd = _rtB -> fqonxys5pb ; _rtDW -> ehaijafsot = _rtB ->
lyhdwkntva [ 19 ] ; _rtDW -> lvw3lta2fy = _rtB -> ngag1sitta - -
0.94176453358424872 * _rtDW -> lvw3lta2fy ; _rtDW -> c20b4oc1jp = _rtB ->
jqaligr4kv - - 0.94176453358424872 * _rtDW -> c20b4oc1jp ; _rtDW ->
lp13v2ihui = _rtB -> alf2wq40zx ; _rtDW -> kopxzfb0sb = _rtB -> lyhdwkntva [
23 ] ; _rtDW -> ebwur5qeqq = _rtB -> id01unheeo ; ssCallAccelRunBlock ( S ,
15 , 496 , SS_CALL_MDL_UPDATE ) ; } if ( _rtDW -> n33aen2wbt == ( rtInf ) ) {
_rtDW -> n33aen2wbt = ssGetTaskTime ( S , 0 ) ; _rtDW -> evmu5j4txb = _rtB ->
jmnbkdhupp ; } else if ( _rtDW -> fjojh4ewqs == ( rtInf ) ) { _rtDW ->
fjojh4ewqs = ssGetTaskTime ( S , 0 ) ; _rtDW -> d21ysphefx = _rtB ->
jmnbkdhupp ; } else if ( _rtDW -> n33aen2wbt < _rtDW -> fjojh4ewqs ) { _rtDW
-> n33aen2wbt = ssGetTaskTime ( S , 0 ) ; _rtDW -> evmu5j4txb = _rtB ->
jmnbkdhupp ; } else { _rtDW -> fjojh4ewqs = ssGetTaskTime ( S , 0 ) ; _rtDW
-> d21ysphefx = _rtB -> jmnbkdhupp ; } if ( _rtDW -> nolj4flzwb == ( rtInf )
) { _rtDW -> nolj4flzwb = ssGetTaskTime ( S , 0 ) ; _rtDW -> ppmw3hzciy =
_rtB -> jqlvrukm35 ; } else if ( _rtDW -> bluedlz4ee == ( rtInf ) ) { _rtDW
-> bluedlz4ee = ssGetTaskTime ( S , 0 ) ; _rtDW -> awi4nxie0m = _rtB ->
jqlvrukm35 ; } else if ( _rtDW -> nolj4flzwb < _rtDW -> bluedlz4ee ) { _rtDW
-> nolj4flzwb = ssGetTaskTime ( S , 0 ) ; _rtDW -> ppmw3hzciy = _rtB ->
jqlvrukm35 ; } else { _rtDW -> bluedlz4ee = ssGetTaskTime ( S , 0 ) ; _rtDW
-> awi4nxie0m = _rtB -> jqlvrukm35 ; } if ( ssIsSampleHit ( S , 3 , 0 ) ) {
_rtDW -> bv5gvrfela = _rtB -> nkbjhftee3 ; } if ( ssIsSampleHit ( S , 2 , 0 )
) { _rtDW -> pe31gvq3pv = _rtB -> izwwv4sglz - - 0.98651999976973315 * _rtDW
-> pe31gvq3pv ; _rtDW -> bw5cwo255x = _rtB -> on11bzhrh5 - -
0.98651999976973315 * _rtDW -> bw5cwo255x ; _rtDW -> l2t4rgxmml = _rtB ->
lsjmvd53ha [ 0 ] ; } if ( ssIsSampleHit ( S , 2 , 0 ) ) { _rtDW -> dy4ppyw4mo
= _rtB -> nsa1sh1pgu - - 0.98651999976973315 * _rtDW -> dy4ppyw4mo ; _rtDW ->
hmybg5b1mi = _rtB -> bhwfaderrt - - 0.98651999976973315 * _rtDW -> hmybg5b1mi
; _rtDW -> gkq12xkctn = _rtB -> g31w3nr4hv [ 0 ] ; _rtDW -> llu3sg1ihp = 0U ;
_rtDW -> fj2gixcnhk = 3.0E-5 * _rtB -> az4z0umyma + _rtB -> g1heig2g2s ; if (
_rtDW -> fj2gixcnhk >= 1.0 ) { _rtDW -> fj2gixcnhk = 1.0 ; } else { if (
_rtDW -> fj2gixcnhk <= - 1.0 ) { _rtDW -> fj2gixcnhk = - 1.0 ; } } _rtDW ->
dco4afubi3 = _rtB -> lxo30patnp ; } if ( _rtDW -> ewhcynzuun == ( rtInf ) ) {
_rtDW -> ewhcynzuun = ssGetTaskTime ( S , 0 ) ; _rtDW -> h4ipbzntlo = _rtB ->
mlv3wqd2k2 ; } else if ( _rtDW -> ciu3b0lpet == ( rtInf ) ) { _rtDW ->
ciu3b0lpet = ssGetTaskTime ( S , 0 ) ; _rtDW -> mmlyeyihwy = _rtB ->
mlv3wqd2k2 ; } else if ( _rtDW -> ewhcynzuun < _rtDW -> ciu3b0lpet ) { _rtDW
-> ewhcynzuun = ssGetTaskTime ( S , 0 ) ; _rtDW -> h4ipbzntlo = _rtB ->
mlv3wqd2k2 ; } else { _rtDW -> ciu3b0lpet = ssGetTaskTime ( S , 0 ) ; _rtDW
-> mmlyeyihwy = _rtB -> mlv3wqd2k2 ; } if ( ssIsSampleHit ( S , 2 , 0 ) ) {
_rtDW -> jctbfc4f1e = _rtB -> mntwfgi23x - - 0.96300265339697488 * _rtDW ->
jctbfc4f1e ; _rtDW -> h4pa1qmmy5 = 0U ; _rtDW -> olv3cnxtoy = 3.0E-5 * _rtB
-> cxtiircebz + _rtB -> fys0ai44nk ; if ( _rtDW -> olv3cnxtoy >= 1.0 ) {
_rtDW -> olv3cnxtoy = 1.0 ; } else { if ( _rtDW -> olv3cnxtoy <= 0.0 ) {
_rtDW -> olv3cnxtoy = 0.0 ; } } } if ( _rtDW -> en15lu4hm1 == ( rtInf ) ) {
_rtDW -> en15lu4hm1 = ssGetT ( S ) ; lastU = & _rtDW -> aa3vndu55f ; } else
if ( _rtDW -> km4yirabra == ( rtInf ) ) { _rtDW -> km4yirabra = ssGetT ( S )
; lastU = & _rtDW -> ke4dqjfdz3 ; } else if ( _rtDW -> en15lu4hm1 < _rtDW ->
km4yirabra ) { _rtDW -> en15lu4hm1 = ssGetT ( S ) ; lastU = & _rtDW ->
aa3vndu55f ; } else { _rtDW -> km4yirabra = ssGetT ( S ) ; lastU = & _rtDW ->
ke4dqjfdz3 ; } * lastU = _rtB -> f32s5izkc1 ; if ( _rtDW -> cgi523usaj == (
rtInf ) ) { _rtDW -> cgi523usaj = ssGetT ( S ) ; lastU = & _rtDW ->
edrzze2flm ; } else if ( _rtDW -> irt5havirw == ( rtInf ) ) { _rtDW ->
irt5havirw = ssGetT ( S ) ; lastU = & _rtDW -> gljjadsfzv ; } else if ( _rtDW
-> cgi523usaj < _rtDW -> irt5havirw ) { _rtDW -> cgi523usaj = ssGetT ( S ) ;
lastU = & _rtDW -> edrzze2flm ; } else { _rtDW -> irt5havirw = ssGetT ( S ) ;
lastU = & _rtDW -> gljjadsfzv ; } * lastU = _rtB -> fdxtksxpa1 ;
UNUSED_PARAMETER ( tid ) ; }
#define MDL_DERIVATIVES
static void mdlDerivatives ( SimStruct * S ) { fdj1laa40s * _rtB ; hgl3elxkcb
* _rtX ; aab5tqo4s5 * _rtXdot ; h04hj5x5sk * _rtDW ; _rtDW = ( ( h04hj5x5sk *
) ssGetRootDWork ( S ) ) ; _rtXdot = ( ( aab5tqo4s5 * ) ssGetdX ( S ) ) ;
_rtX = ( ( hgl3elxkcb * ) ssGetContStates ( S ) ) ; _rtB = ( ( fdj1laa40s * )
_ssGetBlockIO ( S ) ) ; _rtXdot -> mh2wvbi24o = _rtB -> pevp3t1c1i ;
ssCallAccelRunBlock ( S , 15 , 30 , SS_CALL_MDL_DERIVATIVES ) ; _rtXdot ->
nlkba1lokv = _rtB -> oogljaqwka ; _rtXdot -> eackaa2e5o = _rtB -> kvvltoat4y
; _rtXdot -> a3p154yttn = _rtB -> jtchakzyhg ; _rtXdot -> lvhb24m1u3 [ 0 ] =
0.0 ; _rtXdot -> lvhb24m1u3 [ 1 ] = 0.0 ; _rtXdot -> lvhb24m1u3 [ 0 ] += -
20.106192982974676 * _rtX -> lvhb24m1u3 [ 0 ] ; _rtXdot -> lvhb24m1u3 [ 0 ]
+= - 157.91367041742973 * _rtX -> lvhb24m1u3 [ 1 ] ; _rtXdot -> lvhb24m1u3 [
1 ] += _rtX -> lvhb24m1u3 [ 0 ] ; _rtXdot -> lvhb24m1u3 [ 0 ] += _rtB ->
gusra3qrhw ; _rtXdot -> oiuvfykmtf = _rtB -> creyxg0p4j ; _rtXdot ->
pi4mr5hhgl = _rtB -> fk1flnga04 ; _rtXdot -> bjc4xqhn0t = _rtB -> jrxupqq1lk
; _rtXdot -> oy1vxpvao1 = _rtB -> neippz3iia ; _rtXdot -> iglmayn3zq = _rtB
-> pogkxinemr ; _rtXdot -> p24x5vnk3x = _rtB -> hton2qzo1i ; _rtXdot ->
jntxheunx4 = _rtB -> jjjdylbqxb ; _rtXdot -> ix50zu3rlz = 0.0 ; _rtXdot ->
ix50zu3rlz += - 125.66370614359172 * _rtX -> ix50zu3rlz ; _rtXdot ->
ix50zu3rlz += _rtB -> neippz3iia ; { boolean_T lsat ; boolean_T usat ; lsat =
( ( ( hgl3elxkcb * ) ssGetContStates ( S ) ) -> f0udlm3lxk <= ( - 5.0 ) ) ;
usat = ( ( ( hgl3elxkcb * ) ssGetContStates ( S ) ) -> f0udlm3lxk >= 5.0 ) ;
if ( ( ! lsat && ! usat ) || ( lsat && ( _rtB -> iaqsobebwc > 0 ) ) || ( usat
&& ( _rtB -> iaqsobebwc < 0 ) ) ) { ( ( aab5tqo4s5 * ) ssGetdX ( S ) ) ->
f0udlm3lxk = _rtB -> iaqsobebwc ; } else { ( ( aab5tqo4s5 * ) ssGetdX ( S ) )
-> f0udlm3lxk = 0.0 ; } } }
#define MDL_PROJECTION
static void mdlProjection ( SimStruct * S ) { fdj1laa40s * _rtB ; h04hj5x5sk
* _rtDW ; _rtDW = ( ( h04hj5x5sk * ) ssGetRootDWork ( S ) ) ; _rtB = ( (
fdj1laa40s * ) _ssGetBlockIO ( S ) ) ; ssCallAccelRunBlock ( S , 15 , 30 ,
SS_CALL_MDL_PROJECTION ) ; } static void mdlInitializeSizes ( SimStruct * S )
{ ssSetChecksumVal ( S , 0 , 61714536U ) ; ssSetChecksumVal ( S , 1 ,
3823973139U ) ; ssSetChecksumVal ( S , 2 , 3850828190U ) ; ssSetChecksumVal (
S , 3 , 3333718374U ) ; { mxArray * slVerStructMat = NULL ; mxArray *
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
ld5zvvrfqt ( S ) -> fb3mkq0xr3 = rtNaN ; ld5zvvrfqt ( S ) -> bl5vufhrs4 =
rtNaN ; ld5zvvrfqt ( S ) -> lvjngh1qvy = rtNaN ; ld5zvvrfqt ( S ) ->
naqiut5cmm = rtNaN ; } static void mdlInitializeSampleTimes ( SimStruct * S )
{ { SimStruct * childS ; SysOutputFcn * callSysFcns ; childS = ssGetSFunction
( S , 0 ) ; callSysFcns = ssGetCallSystemOutputFcnList ( childS ) ;
callSysFcns [ 3 + 0 ] = ( SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction (
S , 1 ) ; callSysFcns = ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns
[ 3 + 0 ] = ( SysOutputFcn ) ( NULL ) ; } } static void mdlTerminate (
SimStruct * S ) { }
#include "simulink.c"
