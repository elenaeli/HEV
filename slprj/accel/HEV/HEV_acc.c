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
= yLeftCast ; } } } void keyxmz53xi ( SimStruct * const S , boolean_T
mfqvbclekq , boolean_T gbeq152nyt , h1kbqu5vwm * localB , his5kfh0i3 *
localDW ) { if ( mfqvbclekq ) { localB -> forbrjhq11 = gbeq152nyt ; if (
ssIsMajorTimeStep ( S ) ) { srUpdateBC ( localDW -> hx1jtpaojx ) ; } } } void
nxnb4xfekz ( SimStruct * const S ) { } static void mdlOutputs ( SimStruct * S
, int_T tid ) { real_T ijyb1ptiw5 ; real_T gdhbbe4us0 ; real_T c3uofirewl ;
real_T h2yfd4orwq ; real_T klp2rkbjun ; real_T h0odp1zuuc ; real_T gddgqjszw2
; real_T hrplwjajp2 ; real_T gyprtoeon3 ; real_T hrmedkfbdf ; boolean_T
h1tnk5yrr5 ; int32_T rowIdx ; real_T * lastU ; boolean_T pbnk0frrk0 ; uint8_T
mjvuadvsvc ; real_T i5nu34w4uj ; real_T dztyrqu4xa ; real_T eskeehll14 ;
real_T jwhz1ujp3w ; real_T ehtkh2wauy ; real_T mkcfwi2fsi ; real_T ehcygfucdl
; real_T po0ockmy2b ; real_T mizlp41tvx ; real_T f4ufgq33gz ; real_T
ckrl0nmlwt ; real_T lduwq00gqj ; real_T byehzqrbel ; real_T awwg3xagjh ;
real_T aqlslovppe ; real_T dyfxp2slod ; real_T dk4tk42hhp ; real_T ctpq3axefx
; real_T f1b5simhxh ; real_T mqc0yqbsjn ; real_T lstej3qx0u ; real_T
j0bnh13vos ; real_T pzh42py0bn ; real_T nfqwsurguw_idx_0 ; real_T
nfqwsurguw_idx_1 ; real_T nfqwsurguw_idx_2 ; ZCEventType zcEvent_idx_0 ;
ZCEventType zcEvent_idx_1 ; ZCEventType zcEvent_idx_2 ; fdj1laa40s * _rtB ;
baqezl5ja5 * _rtP ; hgl3elxkcb * _rtX ; bu2ncqpcar * _rtZCE ; h04hj5x5sk *
_rtDW ; _rtDW = ( ( h04hj5x5sk * ) ssGetRootDWork ( S ) ) ; _rtZCE = ( (
bu2ncqpcar * ) _ssGetPrevZCSigState ( S ) ) ; _rtX = ( ( hgl3elxkcb * )
ssGetContStates ( S ) ) ; _rtP = ( ( baqezl5ja5 * ) ssGetDefaultParam ( S ) )
; _rtB = ( ( fdj1laa40s * ) _ssGetBlockIO ( S ) ) ; _rtB -> hv44vg21xk = _rtX
-> mh2wvbi24o ; _rtB -> d50s1xm1sa = _rtB -> hv44vg21xk - ld5zvvrfqt ( S ) ->
g2v1neeeqt ; _rtB -> j3tc3ea0hk = 0.0 * _rtB -> d50s1xm1sa ; _rtB ->
nk0ucgxwdu = _rtB -> d50s1xm1sa * ( real_T ) ld5zvvrfqt ( S ) -> d1wkxkrb5d ;
pbnk0frrk0 = ( _rtB -> nk0ucgxwdu >= ld5zvvrfqt ( S ) -> b3g44p01iz ) ; _rtB
-> i53zuxdh4l = _rtB -> j3tc3ea0hk * ( real_T ) pbnk0frrk0 ; _rtB ->
b3x21rxith [ 0 ] = ld5zvvrfqt ( S ) -> obwxws0rl5 ; _rtB -> b3x21rxith [ 1 ]
= ld5zvvrfqt ( S ) -> dd2ctcdkt5 ; _rtB -> b3x21rxith [ 2 ] = ld5zvvrfqt ( S
) -> bvmxzgxdhn ; _rtB -> b3x21rxith [ 3 ] = ld5zvvrfqt ( S ) -> ly24eetavp ;
_rtB -> b3x21rxith [ 4 ] = ld5zvvrfqt ( S ) -> gqumcoq4ab ; _rtB ->
b3x21rxith [ 5 ] = ld5zvvrfqt ( S ) -> kdw0p1lsud ; _rtB -> b3x21rxith [ 6 ]
= ld5zvvrfqt ( S ) -> orazfd4jlf ; _rtB -> b3x21rxith [ 7 ] = ld5zvvrfqt ( S
) -> gtphamqzd4 ; _rtB -> b3x21rxith [ 8 ] = ld5zvvrfqt ( S ) -> h3ag4luqlz ;
_rtB -> b3x21rxith [ 9 ] = ld5zvvrfqt ( S ) -> prb13xkh2s ; _rtB ->
b3x21rxith [ 10 ] = ld5zvvrfqt ( S ) -> cj4grndocs ; _rtB -> b3x21rxith [ 11
] = ld5zvvrfqt ( S ) -> mishkheve2 ; _rtB -> b3x21rxith [ 12 ] = ld5zvvrfqt (
S ) -> o0j02bpyjh ; _rtB -> b3x21rxith [ 13 ] = ld5zvvrfqt ( S ) ->
o2qe4dvjgj ; _rtB -> b3x21rxith [ 14 ] = ld5zvvrfqt ( S ) -> ka1wmfe5gn ;
_rtB -> b3x21rxith [ 15 ] = ld5zvvrfqt ( S ) -> do2mszq2fa ; _rtB ->
b3x21rxith [ 16 ] = ld5zvvrfqt ( S ) -> o0u3wry1y0 ; ssCallAccelRunBlock ( S
, 14 , 29 , SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 14 , 30 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> bjy3ivl32q = _rtB -> nyjtqlivfc [ 12 ] - _rtB
-> nyjtqlivfc [ 0 ] ; _rtB -> g53r4m5jxl = 0.2079 * _rtB -> bjy3ivl32q ; _rtB
-> gvsfmbqiz5 = ( real_T ) pbnk0frrk0 * _rtB -> g53r4m5jxl ; _rtB ->
itfgpdcf3z = ( 0.0 - _rtB -> i53zuxdh4l ) - _rtB -> gvsfmbqiz5 ; _rtB ->
dpkschge1b = _rtB -> hv44vg21xk + ld5zvvrfqt ( S ) -> k1wrna0q43 ; _rtB ->
kvxtuomt0c = 0.0 * _rtB -> dpkschge1b ; _rtB -> bd1l0pi5zt = _rtB ->
dpkschge1b * ( real_T ) ld5zvvrfqt ( S ) -> opbj3fohw4 ; pbnk0frrk0 = ( _rtB
-> bd1l0pi5zt <= ld5zvvrfqt ( S ) -> i2uajyhed0 ) ; _rtB -> p5syyy2toz = _rtB
-> kvxtuomt0c * ( real_T ) pbnk0frrk0 ; _rtB -> jbmbwj3nlw = 0.2079 * _rtB ->
bjy3ivl32q ; _rtB -> mvdfvp232d = ( real_T ) pbnk0frrk0 * _rtB -> jbmbwj3nlw
; _rtB -> jkaaguptre = ( 0.0 - _rtB -> p5syyy2toz ) - _rtB -> mvdfvp232d ;
_rtB -> bdttfjoqre = _rtB -> jkaaguptre * ( real_T ) ld5zvvrfqt ( S ) ->
iy22c0e3zt ; _rtB -> gvbigsazx5 = ( 0.0 - _rtB -> itfgpdcf3z ) - _rtB ->
bdttfjoqre ; _rtB -> d2yacl34rt = _rtX -> nlkba1lokv ; _rtB -> kergubcj1u =
_rtB -> d2yacl34rt - ld5zvvrfqt ( S ) -> ouo10euwnj ; _rtB -> bnch51hrn0 =
0.0 * _rtB -> kergubcj1u ; _rtB -> kaun43eixf = _rtB -> kergubcj1u * ( real_T
) ld5zvvrfqt ( S ) -> mphfy0t40q ; pbnk0frrk0 = ( _rtB -> kaun43eixf >=
ld5zvvrfqt ( S ) -> hficsfxobw ) ; _rtB -> annccung2x = _rtB -> bnch51hrn0 *
( real_T ) pbnk0frrk0 ; _rtB -> mwaxumfq5f = _rtB -> nyjtqlivfc [ 1 ] - _rtB
-> nyjtqlivfc [ 4 ] ; _rtB -> fqot23uj5w = 0.1 * _rtB -> mwaxumfq5f ; _rtB ->
or4rq2ypek = ( real_T ) pbnk0frrk0 * _rtB -> fqot23uj5w ; _rtB -> oyjgizqrtx
= ( 0.0 - _rtB -> annccung2x ) - _rtB -> or4rq2ypek ; _rtB -> fkkpfv5re1 =
_rtB -> d2yacl34rt + ld5zvvrfqt ( S ) -> llrwa2zjo5 ; _rtB -> cv3ve5y03s =
0.0 * _rtB -> fkkpfv5re1 ; _rtB -> lgvhmbrvnh = _rtB -> fkkpfv5re1 * ( real_T
) ld5zvvrfqt ( S ) -> dymnmj5y0m ; pbnk0frrk0 = ( _rtB -> lgvhmbrvnh <=
ld5zvvrfqt ( S ) -> i4zkbshhvc ) ; _rtB -> g5pcn0mnnt = _rtB -> cv3ve5y03s *
( real_T ) pbnk0frrk0 ; _rtB -> fe3jqdqg2w = 0.1 * _rtB -> mwaxumfq5f ; _rtB
-> ei0hzh2m3i = ( real_T ) pbnk0frrk0 * _rtB -> fe3jqdqg2w ; _rtB ->
oqxxaxumbd = ( 0.0 - _rtB -> g5pcn0mnnt ) - _rtB -> ei0hzh2m3i ; _rtB ->
jfgwwgyir0 = _rtB -> oqxxaxumbd * ( real_T ) ld5zvvrfqt ( S ) -> fhaylzlmna ;
_rtB -> aouxegskc1 = ( 0.0 - _rtB -> oyjgizqrtx ) - _rtB -> jfgwwgyir0 ; _rtB
-> pxghcmhg5d = - _rtB -> aouxegskc1 ; _rtB -> gljz133asp = _rtX ->
eackaa2e5o ; _rtB -> pnrvucucvi = _rtX -> a3p154yttn ; _rtB -> jyppgsg1kl =
muDoubleScalarAbs ( _rtB -> pnrvucucvi ) ; _rtB -> goztrryl1s = ( ld5zvvrfqt
( S ) -> cvmndblf5q > _rtB -> jyppgsg1kl ) ; _rtB -> j2kmk2ws0i = 0.4 * _rtB
-> jyppgsg1kl ; _rtB -> e1r3bm5rzf = 3.1415926535897931 * _rtB -> j2kmk2ws0i
; _rtB -> gbrslwd0lz = ( muDoubleScalarCos ( _rtB -> e1r3bm5rzf ) + 1.0 ) *
770.0 ; _rtB -> laly5ncxtb = 0.5 * _rtB -> gbrslwd0lz ; _rtB -> djlz5qtijd =
9.6688232009214591E-6 * _rtB -> laly5ncxtb ; _rtB -> cew0kpx4fk = 0.3 * _rtB
-> nyjtqlivfc [ 2 ] ; _rtB -> cqxeynwevr = _rtB -> pnrvucucvi - _rtB ->
cew0kpx4fk ; _rtB -> hh00f4jecq = _rtB -> goztrryl1s * _rtB -> djlz5qtijd *
_rtB -> cqxeynwevr ; _rtB -> iglmdl2ivi = _rtB -> gljz133asp - _rtB ->
hh00f4jecq ; _rtB -> gmkvhdfijx = muDoubleScalarSign ( _rtB -> iglmdl2ivi ) ;
_rtB -> cieaw2snwb = muDoubleScalarAbs ( _rtB -> iglmdl2ivi ) ; _rtB ->
mywdqdbubf = 1.093 * _rtB -> cieaw2snwb ; _rtB -> nser4bbrfy = 0.0 ; _rtB ->
nser4bbrfy += 0.0 * _rtX -> lvhb24m1u3 [ 0 ] ; _rtB -> nser4bbrfy +=
157.91367041742973 * _rtX -> lvhb24m1u3 [ 1 ] ; _rtB -> nomqwvjv4n =
muDoubleScalarSign ( _rtB -> pnrvucucvi ) ; _rtB -> jbaes5helb = _rtB ->
pnrvucucvi * _rtB -> pnrvucucvi * _rtB -> nomqwvjv4n ; _rtB -> dbtj4e4azc =
0.5 * _rtB -> jbaes5helb ; _rtB -> ic54uymohf = 1.2 * _rtB -> dbtj4e4azc ;
_rtB -> eyov10bscx = 0.26 * _rtB -> ic54uymohf ; _rtB -> kbm252qyu0 = 2.57 *
_rtB -> eyov10bscx ; _rtB -> glew0kbg2d = ( ( 0.0 - ld5zvvrfqt ( S ) ->
elrm5be5m3 ) - _rtB -> nser4bbrfy ) - _rtB -> kbm252qyu0 ; _rtB -> bwzlez4gw1
= 0.18518518518518517 * _rtB -> glew0kbg2d ; _rtB -> gprhgidfbl = (
ld5zvvrfqt ( S ) -> ppacnbaahk - _rtB -> bwzlez4gw1 ) + ld5zvvrfqt ( S ) ->
dvbsx5tzee ; if ( _rtB -> gprhgidfbl <= 0.0 ) { _rtB -> nbdjvo1uig = 0.0 ; }
else { _rtB -> nbdjvo1uig = _rtB -> gprhgidfbl ; } _rtB -> b3zokbgpwa =
1.0464 * _rtB -> nbdjvo1uig ; { uint32_T iLeftU0 , iRghtU0 , iLeftU1 ,
iRghtU1 ; HEV_acc_BINARYSEARCH_real_T ( & ( iLeftU0 ) , & ( iRghtU0 ) , _rtB
-> mywdqdbubf , ni220kbneq . c4qvyaa1p5 , 108U ) ; if ( _rtB -> b3zokbgpwa <=
0.0 ) { iLeftU1 = 0U ; iRghtU1 = 0U ; } else if ( _rtB -> b3zokbgpwa >=
6000.0 ) { iLeftU1 = 100U ; iRghtU1 = 100U ; } else { iLeftU1 = ( uint32_T )
( ( _rtB -> b3zokbgpwa ) / 60.0 ) ; iRghtU1 = iLeftU1 + 1 ; } { real_T yTemp
; real_T u1Lambda ; real_T u0Lambda ; if ( iLeftU1 != iRghtU1 ) { { real_T
num = ( real_T ) ( _rtB -> b3zokbgpwa ) - ( iLeftU1 * 60.0 ) ; u1Lambda = num
/ 60.0 ; } } else { u1Lambda = 0.0 ; } if ( ( ni220kbneq . c4qvyaa1p5 [
iRghtU0 ] ) > ( ni220kbneq . c4qvyaa1p5 [ iLeftU0 ] ) ) { real_T num ; real_T
den ; den = ( ni220kbneq . c4qvyaa1p5 [ iRghtU0 ] ) ; den -= ( ni220kbneq .
c4qvyaa1p5 [ iLeftU0 ] ) ; num = _rtB -> mywdqdbubf ; num -= ( ni220kbneq .
c4qvyaa1p5 [ iLeftU0 ] ) ; u0Lambda = num / den ; } else { u0Lambda = 0.0 ; }
{ real_T yLeftCast ; real_T yRghtCast ; yLeftCast = ( ni220kbneq . mstlffh4xe
[ ( iLeftU0 + 109U * iLeftU1 ) ] ) ; yRghtCast = ( ni220kbneq . mstlffh4xe [
( iLeftU0 + 109U * iRghtU1 ) ] ) ; yLeftCast += u1Lambda * ( yRghtCast -
yLeftCast ) ; ijyb1ptiw5 = yLeftCast ; } { real_T yLeftCast ; real_T
yRghtCast ; yLeftCast = ( ni220kbneq . mstlffh4xe [ ( iRghtU0 + 109U *
iLeftU1 ) ] ) ; yRghtCast = ( ni220kbneq . mstlffh4xe [ ( iRghtU0 + 109U *
iRghtU1 ) ] ) ; yLeftCast += u1Lambda * ( yRghtCast - yLeftCast ) ; yTemp =
yLeftCast ; } { real_T yLeftCast ; real_T yRghtCast ; yLeftCast = ijyb1ptiw5
; yRghtCast = yTemp ; yLeftCast += u0Lambda * ( yRghtCast - yLeftCast ) ;
ijyb1ptiw5 = yLeftCast ; } } } _rtB -> ky5c3ifnxl = 1.0351048413332149 *
ijyb1ptiw5 ; _rtB -> hfesoiedao = _rtB -> gmkvhdfijx * _rtB -> ky5c3ifnxl ;
_rtB -> p5npqoth4u = 0.3 * _rtB -> hfesoiedao ; _rtB -> pi24m5y3nn = - _rtB
-> p5npqoth4u ; _rtB -> omlxqlcycc = _rtX -> oiuvfykmtf ; _rtB -> ecvs511gof
= muDoubleScalarAbs ( _rtB -> pnrvucucvi ) ; _rtB -> agpfncsjb5 = (
ld5zvvrfqt ( S ) -> k5hn0c0wwr > _rtB -> ecvs511gof ) ; _rtB -> cxe3y3mapo =
0.4 * _rtB -> ecvs511gof ; _rtB -> lo25xaamud = 3.1415926535897931 * _rtB ->
cxe3y3mapo ; _rtB -> igciu5zfqz = ( muDoubleScalarCos ( _rtB -> lo25xaamud )
+ 1.0 ) * 770.0 ; _rtB -> g2dxsm00aw = 0.5 * _rtB -> igciu5zfqz ; _rtB ->
ehkyilrkwp = 9.6688232009214591E-6 * _rtB -> g2dxsm00aw ; _rtB -> nrnzonb2kv
= 0.3 * _rtB -> nyjtqlivfc [ 3 ] ; _rtB -> ova4xpfsrf = _rtB -> pnrvucucvi -
_rtB -> nrnzonb2kv ; _rtB -> nemwurfphb = _rtB -> agpfncsjb5 * _rtB ->
ehkyilrkwp * _rtB -> ova4xpfsrf ; _rtB -> acqhpffrxz = _rtB -> omlxqlcycc -
_rtB -> nemwurfphb ; _rtB -> a05502ivli = muDoubleScalarSign ( _rtB ->
acqhpffrxz ) ; _rtB -> defzyw4hzw = muDoubleScalarAbs ( _rtB -> acqhpffrxz )
; _rtB -> cuehjsl5fs = 1.093 * _rtB -> defzyw4hzw ; _rtB -> a2xaxv2qei = (
_rtB -> bwzlez4gw1 + ld5zvvrfqt ( S ) -> kgqlljencp ) + ld5zvvrfqt ( S ) ->
jmotwtdgxd ; if ( _rtB -> a2xaxv2qei <= 0.0 ) { _rtB -> nkppx0xvpt = 0.0 ; }
else { _rtB -> nkppx0xvpt = _rtB -> a2xaxv2qei ; } _rtB -> ie2lbzgd1k =
1.0464 * _rtB -> nkppx0xvpt ; { uint32_T iLeftU0 , iRghtU0 , iLeftU1 ,
iRghtU1 ; HEV_acc_BINARYSEARCH_real_T ( & ( iLeftU0 ) , & ( iRghtU0 ) , _rtB
-> cuehjsl5fs , ni220kbneq . c4qvyaa1p5 , 108U ) ; if ( _rtB -> ie2lbzgd1k <=
0.0 ) { iLeftU1 = 0U ; iRghtU1 = 0U ; } else if ( _rtB -> ie2lbzgd1k >=
6000.0 ) { iLeftU1 = 100U ; iRghtU1 = 100U ; } else { iLeftU1 = ( uint32_T )
( ( _rtB -> ie2lbzgd1k ) / 60.0 ) ; iRghtU1 = iLeftU1 + 1 ; } { real_T yTemp
; real_T u1Lambda ; real_T u0Lambda ; if ( iLeftU1 != iRghtU1 ) { { real_T
num = ( real_T ) ( _rtB -> ie2lbzgd1k ) - ( iLeftU1 * 60.0 ) ; u1Lambda = num
/ 60.0 ; } } else { u1Lambda = 0.0 ; } if ( ( ni220kbneq . c4qvyaa1p5 [
iRghtU0 ] ) > ( ni220kbneq . c4qvyaa1p5 [ iLeftU0 ] ) ) { real_T num ; real_T
den ; den = ( ni220kbneq . c4qvyaa1p5 [ iRghtU0 ] ) ; den -= ( ni220kbneq .
c4qvyaa1p5 [ iLeftU0 ] ) ; num = _rtB -> cuehjsl5fs ; num -= ( ni220kbneq .
c4qvyaa1p5 [ iLeftU0 ] ) ; u0Lambda = num / den ; } else { u0Lambda = 0.0 ; }
{ real_T yLeftCast ; real_T yRghtCast ; yLeftCast = ( ni220kbneq . mstlffh4xe
[ ( iLeftU0 + 109U * iLeftU1 ) ] ) ; yRghtCast = ( ni220kbneq . mstlffh4xe [
( iLeftU0 + 109U * iRghtU1 ) ] ) ; yLeftCast += u1Lambda * ( yRghtCast -
yLeftCast ) ; gdhbbe4us0 = yLeftCast ; } { real_T yLeftCast ; real_T
yRghtCast ; yLeftCast = ( ni220kbneq . mstlffh4xe [ ( iRghtU0 + 109U *
iLeftU1 ) ] ) ; yRghtCast = ( ni220kbneq . mstlffh4xe [ ( iRghtU0 + 109U *
iRghtU1 ) ] ) ; yLeftCast += u1Lambda * ( yRghtCast - yLeftCast ) ; yTemp =
yLeftCast ; } { real_T yLeftCast ; real_T yRghtCast ; yLeftCast = gdhbbe4us0
; yRghtCast = yTemp ; yLeftCast += u0Lambda * ( yRghtCast - yLeftCast ) ;
gdhbbe4us0 = yLeftCast ; } } } _rtB -> d0ytpsusf1 = 1.0351048413332149 *
gdhbbe4us0 ; _rtB -> hl3k0hismi = _rtB -> a05502ivli * _rtB -> d0ytpsusf1 ;
_rtB -> jfjxwog1qb = 0.3 * _rtB -> hl3k0hismi ; _rtB -> m5rwfdhpag = - _rtB
-> jfjxwog1qb ; if ( ssIsSampleHit ( S , 2 , 0 ) ) { _rtB -> gw24bveokp =
_rtDW -> epw20ibixm ; _rtB -> cwott4tken = _rtDW -> emjtqjwqij ; _rtB ->
lk5aiczshe = ( - 0.00045907990073600015 * _rtB -> gw24bveokp * _rtB ->
cwott4tken + 0.175666143629361 * _rtB -> gw24bveokp ) * 6.0 ; if ( _rtB ->
lk5aiczshe > 400.0 ) { _rtB -> c5afmhi2to = 400.0 ; } else if ( _rtB ->
lk5aiczshe < - 400.0 ) { _rtB -> c5afmhi2to = - 400.0 ; } else { _rtB ->
c5afmhi2to = _rtB -> lk5aiczshe ; } _rtB -> nx5hrxfrql = _rtDW -> aekc0mbj0y
; _rtB -> gj05ld235c = _rtDW -> oi2n4lur1q ; _rtB -> cyi24unrh5 = ( 0.0 *
_rtB -> nx5hrxfrql * _rtB -> gj05ld235c + 0.192 * _rtB -> nx5hrxfrql ) * 1.5
; if ( _rtB -> cyi24unrh5 > 400.0 ) { _rtB -> nxr1uridpp = 400.0 ; } else if
( _rtB -> cyi24unrh5 < - 400.0 ) { _rtB -> nxr1uridpp = - 400.0 ; } else {
_rtB -> nxr1uridpp = _rtB -> cyi24unrh5 ; } } if ( _rtB -> nyjtqlivfc [ 10 ]
> 628.31853071795865 ) { _rtB -> cewjxskhz1 = 628.31853071795865 ; } else if
( _rtB -> nyjtqlivfc [ 10 ] < 0.0 ) { _rtB -> cewjxskhz1 = 0.0 ; } else {
_rtB -> cewjxskhz1 = _rtB -> nyjtqlivfc [ 10 ] ; } mjvuadvsvc = ( uint8_T ) (
_rtB -> cewjxskhz1 > ld5zvvrfqt ( S ) -> jxl5le0dzo ) ; if ( _rtB ->
nyjtqlivfc [ 5 ] > 628.31853071795865 ) { _rtB -> cnt5lxjdfi =
628.31853071795865 ; } else if ( _rtB -> nyjtqlivfc [ 5 ] < 0.0 ) { _rtB ->
cnt5lxjdfi = 0.0 ; } else { _rtB -> cnt5lxjdfi = _rtB -> nyjtqlivfc [ 5 ] ; }
_rtB -> ppsa1jbajv = muDoubleScalarAbs ( _rtB -> cnt5lxjdfi ) ;
HEV_acc_LookUp_real_T_real_T ( & ( c3uofirewl ) , ni220kbneq . icn4mwaz3x ,
_rtB -> ppsa1jbajv , ni220kbneq . mic5dtfppd , 6U ) ; ssCallAccelRunBlock ( S
, 14 , 176 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> goaamjmqrf = 0.0 ; _rtB ->
goaamjmqrf += 125.66370614359172 * _rtX -> ix50zu3rlz ; _rtB -> gnu1fbtq4s =
_rtB -> mlkkky1r0d - _rtB -> goaamjmqrf ; _rtB -> c0mhnsds4b = 0.02 * _rtB ->
gnu1fbtq4s ; if ( ( ( hgl3elxkcb * ) ssGetContStates ( S ) ) -> f0udlm3lxk >=
5.0 ) { if ( ( ( hgl3elxkcb * ) ssGetContStates ( S ) ) -> f0udlm3lxk != 5.0
) { ( ( hgl3elxkcb * ) ssGetContStates ( S ) ) -> f0udlm3lxk = 5.0 ;
ssSetSolverNeedsReset ( S ) ; } } else if ( ( ( hgl3elxkcb * )
ssGetContStates ( S ) ) -> f0udlm3lxk <= ( - 5.0 ) ) { if ( ( ( hgl3elxkcb *
) ssGetContStates ( S ) ) -> f0udlm3lxk != ( - 5.0 ) ) { ( ( hgl3elxkcb * )
ssGetContStates ( S ) ) -> f0udlm3lxk = ( - 5.0 ) ; ssSetSolverNeedsReset ( S
) ; } } _rtB -> fluzc35ru2 = ( ( hgl3elxkcb * ) ssGetContStates ( S ) ) ->
f0udlm3lxk ; _rtB -> juhkk3xacg = _rtB -> c0mhnsds4b + _rtB -> fluzc35ru2 ;
if ( _rtB -> juhkk3xacg > 1.0 ) { _rtB -> j3zls0jlif = 1.0 ; } else if ( _rtB
-> juhkk3xacg < - 1.0 ) { _rtB -> j3zls0jlif = - 1.0 ; } else { _rtB ->
j3zls0jlif = _rtB -> juhkk3xacg ; } if ( ( _rtDW -> cwivfg5ijd >=
ssGetTaskTime ( S , 0 ) ) && ( _rtDW -> m1iuzueluk >= ssGetTaskTime ( S , 0 )
) ) { _rtB -> miy4yla1ep = _rtB -> j3zls0jlif ; } else { if ( ( ( _rtDW ->
cwivfg5ijd < _rtDW -> m1iuzueluk ) && ( _rtDW -> m1iuzueluk < ssGetTaskTime (
S , 0 ) ) ) || ( ( _rtDW -> cwivfg5ijd >= _rtDW -> m1iuzueluk ) && ( _rtDW ->
cwivfg5ijd >= ssGetTaskTime ( S , 0 ) ) ) ) { pzh42py0bn = ssGetTaskTime ( S
, 0 ) - _rtDW -> m1iuzueluk ; mqc0yqbsjn = _rtDW -> bvl1znuobh ; } else {
pzh42py0bn = ssGetTaskTime ( S , 0 ) - _rtDW -> cwivfg5ijd ; mqc0yqbsjn =
_rtDW -> kguctqvwvn ; } lstej3qx0u = _rtB -> j3zls0jlif - mqc0yqbsjn ; if (
lstej3qx0u > pzh42py0bn ) { _rtB -> miy4yla1ep = mqc0yqbsjn + pzh42py0bn ; }
else { pzh42py0bn = - pzh42py0bn ; if ( lstej3qx0u < pzh42py0bn ) { _rtB ->
miy4yla1ep = mqc0yqbsjn + pzh42py0bn ; } else { _rtB -> miy4yla1ep = _rtB ->
j3zls0jlif ; } } } _rtB -> b3b3drpidq = 400.0 * _rtB -> miy4yla1ep ; if (
_rtB -> b3b3drpidq > c3uofirewl ) { _rtB -> j3lqurs52f = c3uofirewl ; } else
{ _rtB -> cp1bwxtyzb = - c3uofirewl ; if ( _rtB -> b3b3drpidq < _rtB ->
cp1bwxtyzb ) { _rtB -> koiypnnkvf = _rtB -> cp1bwxtyzb ; } else { _rtB ->
koiypnnkvf = _rtB -> b3b3drpidq ; } _rtB -> j3lqurs52f = _rtB -> koiypnnkvf ;
} gyprtoeon3 = ssGetT ( S ) ; _rtB -> j1irijycqv = ( real_T ) ( gyprtoeon3 >
ld5zvvrfqt ( S ) -> jbvd2cnnnr ) * _rtB -> j3lqurs52f ; if ( ssIsSampleHit (
S , 2 , 0 ) ) { i5nu34w4uj = 5.9999820000156134E-6 * _rtDW -> f2z5i2ds5e ;
_rtB -> orezp335bc = ( i5nu34w4uj > ld5zvvrfqt ( S ) -> ipholb24pb ) ; } if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> aezwqwzrk0 = _rtDW -> b50c0wk1dc ; }
if ( ssIsSampleHit ( S , 2 , 0 ) ) { if ( _rtDW -> o05rwe50bo != 0 ) { _rtDW
-> pk42w2cjcz = _rtB -> aezwqwzrk0 ; if ( _rtDW -> pk42w2cjcz >= 25200.0 ) {
_rtDW -> pk42w2cjcz = 25200.0 ; } else { if ( _rtDW -> pk42w2cjcz <=
rtMinusInf ) { _rtDW -> pk42w2cjcz = rtMinusInf ; } } } if ( ( _rtB ->
orezp335bc > 0.0 ) && ( _rtDW -> f0fxu4veqt <= 0 ) ) { _rtDW -> pk42w2cjcz =
_rtB -> aezwqwzrk0 ; if ( _rtDW -> pk42w2cjcz >= 25200.0 ) { _rtDW ->
pk42w2cjcz = 25200.0 ; } else { if ( _rtDW -> pk42w2cjcz <= rtMinusInf ) {
_rtDW -> pk42w2cjcz = rtMinusInf ; } } } if ( _rtDW -> pk42w2cjcz >= 25200.0
) { _rtDW -> pk42w2cjcz = 25200.0 ; } else { if ( _rtDW -> pk42w2cjcz <=
rtMinusInf ) { _rtDW -> pk42w2cjcz = rtMinusInf ; } } dztyrqu4xa =
0.00027777777777777778 * _rtDW -> pk42w2cjcz ; if ( dztyrqu4xa > 6.9993 ) {
eskeehll14 = 6.9993 ; } else if ( dztyrqu4xa < 0.0 ) { eskeehll14 = 0.0 ; }
else { eskeehll14 = dztyrqu4xa ; } _rtB -> cmqnjpd0ju = ( 1.0 - eskeehll14 /
7.0 ) * 100.0 ; } _rtB -> cjpouuuvac = _rtX -> bjc4xqhn0t ; if ( _rtB ->
cjpouuuvac <= 0.0 ) { _rtB -> dza5qhhyxj = 0.0 ; } else { _rtB -> dza5qhhyxj
= _rtB -> cjpouuuvac ; } ssCallAccelRunBlock ( S , 12 , 0 ,
SS_CALL_MDL_OUTPUTS ) ; if ( _rtB -> m0m2dtwpv3 > 136.0 ) { _rtB ->
itmf20weii = 136.0 ; } else if ( _rtB -> m0m2dtwpv3 < 83.0 ) { _rtB ->
itmf20weii = 83.0 ; } else { _rtB -> itmf20weii = _rtB -> m0m2dtwpv3 ; } _rtB
-> hc0cyiscwl = _rtB -> itmf20weii - ld5zvvrfqt ( S ) -> bbefy3psap ; _rtB ->
f5hskgjksi = _rtB -> hc0cyiscwl / ld5zvvrfqt ( S ) -> ewirny012j ; if ( _rtB
-> f5hskgjksi > 1.0 ) { _rtB -> lvhu1rcxta = 1.0 ; } else if ( _rtB ->
f5hskgjksi < 0.0 ) { _rtB -> lvhu1rcxta = 0.0 ; } else { _rtB -> lvhu1rcxta =
_rtB -> f5hskgjksi ; } if ( mjvuadvsvc >= 1 ) { _rtB -> pk0g40102w =
ld5zvvrfqt ( S ) -> nrrj0mjo2u ; } else { if ( _rtB -> lvhu1rcxta > 1.0 ) {
_rtB -> g4bihrba22 = 1.0 ; } else if ( _rtB -> lvhu1rcxta < 0.0 ) { _rtB ->
g4bihrba22 = 0.0 ; } else { _rtB -> g4bihrba22 = _rtB -> lvhu1rcxta ; } _rtB
-> j1xpohusob = 9.5492965855137211 * _rtB -> nyjtqlivfc [ 10 ] ; _rtB ->
d3yajrdw5d = rt_Lookup ( ni220kbneq . jqglboln4v , 101 , _rtB -> j1xpohusob ,
ni220kbneq . i2vn1liwwa ) * _rtB -> g4bihrba22 ; if ( _rtB -> d3yajrdw5d >
136.0 ) { _rtB -> kwgn4z3j25 = 136.0 ; } else if ( _rtB -> d3yajrdw5d < 0.0 )
{ _rtB -> kwgn4z3j25 = 0.0 ; } else { _rtB -> kwgn4z3j25 = _rtB -> d3yajrdw5d
; } _rtB -> pk0g40102w = _rtB -> kwgn4z3j25 ; } _rtB -> lckzepn2eb = - _rtB
-> gvbigsazx5 ; _rtB -> fohbznkgii [ 0 ] = _rtB -> gvbigsazx5 ; _rtB ->
fohbznkgii [ 1 ] = _rtB -> pxghcmhg5d ; _rtB -> fohbznkgii [ 2 ] = _rtB ->
pi24m5y3nn ; _rtB -> fohbznkgii [ 3 ] = _rtB -> m5rwfdhpag ; _rtB ->
fohbznkgii [ 4 ] = _rtB -> aouxegskc1 ; _rtB -> fohbznkgii [ 5 ] = _rtB ->
c5afmhi2to ; _rtB -> fohbznkgii [ 6 ] = _rtB -> nxr1uridpp ; _rtB ->
fohbznkgii [ 7 ] = _rtB -> pk0g40102w ; _rtB -> fohbznkgii [ 8 ] = _rtB ->
lckzepn2eb ; ssCallAccelRunBlock ( S , 14 , 214 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 14 , 215 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 14 , 216 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 14 , 217 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
oanomzayk0 = 9.5492965854826952 * _rtB -> nyjtqlivfc [ 11 ] ; _rtB ->
pbch31g2ba = _rtB -> nyjtqlivfc [ 11 ] * _rtB -> k5efrdwui0 [ 1 ] ;
ssCallAccelRunBlock ( S , 14 , 220 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
hbiro2dh45 = ! ( mjvuadvsvc != 0 ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) {
ssCallAccelRunBlock ( S , 14 , 222 , SS_CALL_MDL_OUTPUTS ) ; }
ssCallAccelRunBlock ( S , 14 , 228 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
cac2icyxje = 0.001 * rt_Lookup2D_Normal ( _rtP -> FuelConsTable . speed , 10
, _rtP -> FuelConsTable . torque , 10 , _rtP -> FuelConsTable .
lookupTableFuel , _rtB -> oanomzayk0 , _rtB -> k5efrdwui0 [ 1 ] ) ; _rtB ->
poyovgqtzs = _rtB -> cac2icyxje / ld5zvvrfqt ( S ) -> ptndk0yq1n ; _rtB ->
o2yvheac2c = 1000.0 * _rtB -> poyovgqtzs ; _rtB -> npe3vwaqwr = 3.6 * _rtB ->
pnrvucucvi ; if ( _rtB -> npe3vwaqwr > 200.0 ) { _rtB -> fscboqgb2j = 200.0 ;
} else if ( _rtB -> npe3vwaqwr < 0.0 ) { _rtB -> fscboqgb2j = 0.0 ; } else {
_rtB -> fscboqgb2j = _rtB -> npe3vwaqwr ; } _rtB -> b042adv2bo =
0.0002777777777778 * _rtB -> fscboqgb2j ; ssCallAccelRunBlock ( S , 14 , 244
, SS_CALL_MDL_OUTPUTS ) ; _rtB -> eejtrvhwoz = 0 ; ssCallAccelRunBlock ( S ,
14 , 265 , SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 14 , 266 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 14 , 267 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 14 , 268 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 14 , 269 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 14 , 270 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 14 , 271 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> kykxtw0osp = 0.04 * _rtB -> gnu1fbtq4s ; if (
ssIsSampleHit ( S , 2 , 0 ) ) { jwhz1ujp3w = _rtDW -> eaosag5owj ; ehtkh2wauy
= muDoubleScalarSin ( _rtDW -> eaosag5owj ) ; mkcfwi2fsi = muDoubleScalarCos
( _rtDW -> eaosag5owj ) ; _rtB -> m4oscdw3g1 = _rtB -> nx5hrxfrql *
mkcfwi2fsi + _rtB -> gj05ld235c * ehtkh2wauy ; _rtB -> j5im02hc3b = ( ( -
_rtB -> nx5hrxfrql - 1.7320508075688772 * _rtB -> gj05ld235c ) * mkcfwi2fsi +
( 1.7320508075688772 * _rtB -> nx5hrxfrql - _rtB -> gj05ld235c ) * ehtkh2wauy
) * 0.5 ; ehcygfucdl = _rtDW -> jcugjk0yp0 ; po0ockmy2b = muDoubleScalarSin (
_rtDW -> jcugjk0yp0 ) ; mizlp41tvx = muDoubleScalarCos ( _rtDW -> jcugjk0yp0
) ; _rtB -> ozkrkt404j = _rtB -> gw24bveokp * mizlp41tvx + _rtB -> cwott4tken
* po0ockmy2b ; _rtB -> kjr4hjewwv = ( ( - _rtB -> gw24bveokp -
1.7320508075688772 * _rtB -> cwott4tken ) * mizlp41tvx + ( 1.7320508075688772
* _rtB -> gw24bveokp - _rtB -> cwott4tken ) * po0ockmy2b ) * 0.5 ; f4ufgq33gz
= _rtDW -> jly33pdwub ; if ( dztyrqu4xa >= 6.9993 ) { dztyrqu4xa = 6.9993 ; }
byehzqrbel = ( ( 7.0 / ( 7.0 - eskeehll14 ) * - 0.23801451555567835 *
eskeehll14 + ( ld5zvvrfqt ( S ) -> jjkpzlobwp + _rtDW -> jly33pdwub ) ) + -
_rtB -> orezp335bc * 0.23801451555567835 * i5nu34w4uj * ( 7.0 / ( 7.0 -
eskeehll14 ) ) ) + - ( ( real_T ) ( i5nu34w4uj < ld5zvvrfqt ( S ) ->
a4x0sdh45j ) * ld5zvvrfqt ( S ) -> fyqzt3aphz ) * 0.23801451555567835 * (
ld5zvvrfqt ( S ) -> fyqzt3aphz * i5nu34w4uj ) * ( 7.0 / ( muDoubleScalarAbs (
ld5zvvrfqt ( S ) -> fyqzt3aphz * dztyrqu4xa ) + 0.70000000000000007 ) ) ; if
( byehzqrbel > ld5zvvrfqt ( S ) -> fc1kpzuvol ) { _rtB -> ai215trm2o =
ld5zvvrfqt ( S ) -> fc1kpzuvol ; } else { pzh42py0bn = 0.30769230769230771 *
i5nu34w4uj ; if ( byehzqrbel < pzh42py0bn ) { _rtB -> ai215trm2o = pzh42py0bn
; } else { _rtB -> ai215trm2o = byehzqrbel ; } } _rtB -> kabhe5eb4z = _rtDW
-> fezg0yhyh2 ; nfqwsurguw_idx_0 = _rtDW -> hdqerfit1p [ 0 ] ;
nfqwsurguw_idx_1 = _rtDW -> hdqerfit1p [ 1 ] ; nfqwsurguw_idx_2 = _rtDW ->
hdqerfit1p [ 2 ] ; lduwq00gqj = muDoubleScalarCos ( _rtDW -> eaosag5owj ) ;
ckrl0nmlwt = muDoubleScalarSin ( _rtDW -> eaosag5owj ) ; } if ( _rtB ->
nyjtqlivfc [ 7 ] <= 1.0 ) { gyprtoeon3 = 1.0 ; } else { gyprtoeon3 = _rtB ->
nyjtqlivfc [ 7 ] ; } gyprtoeon3 = 1.0 / gyprtoeon3 ; gyprtoeon3 *= 30000.0 ;
awwg3xagjh = muDoubleScalarAbs ( gyprtoeon3 ) ; if ( ssIsMajorTimeStep ( S )
) { if ( _rtB -> nyjtqlivfc [ 7 ] >= 300.0 ) { _rtDW -> ch52ed4whv = true ; }
else { if ( _rtB -> nyjtqlivfc [ 7 ] <= 200.0 ) { _rtDW -> ch52ed4whv = false
; } } } _rtB -> esogmnhcwd = _rtDW -> ch52ed4whv ; if ( ( _rtDW -> mg242c3vwq
>= ssGetTaskTime ( S , 0 ) ) && ( _rtDW -> k1wt3kvmem >= ssGetTaskTime ( S ,
0 ) ) ) { _rtB -> dgozwv1ban = _rtB -> esogmnhcwd ; } else { if ( ( ( _rtDW
-> mg242c3vwq < _rtDW -> k1wt3kvmem ) && ( _rtDW -> k1wt3kvmem <
ssGetTaskTime ( S , 0 ) ) ) || ( ( _rtDW -> mg242c3vwq >= _rtDW -> k1wt3kvmem
) && ( _rtDW -> mg242c3vwq >= ssGetTaskTime ( S , 0 ) ) ) ) { pzh42py0bn =
ssGetTaskTime ( S , 0 ) - _rtDW -> k1wt3kvmem ; mqc0yqbsjn = _rtDW ->
lzjsh0qxsz ; } else { pzh42py0bn = ssGetTaskTime ( S , 0 ) - _rtDW ->
mg242c3vwq ; mqc0yqbsjn = _rtDW -> oiqwpboxgd ; } byehzqrbel = pzh42py0bn *
10.0 ; lstej3qx0u = _rtB -> esogmnhcwd - mqc0yqbsjn ; if ( lstej3qx0u >
byehzqrbel ) { _rtB -> dgozwv1ban = mqc0yqbsjn + byehzqrbel ; } else {
pzh42py0bn *= - 10.0 ; if ( lstej3qx0u < pzh42py0bn ) { _rtB -> dgozwv1ban =
mqc0yqbsjn + pzh42py0bn ; } else { _rtB -> dgozwv1ban = _rtB -> esogmnhcwd ;
} } } gyprtoeon3 = _rtB -> j1irijycqv * _rtB -> cnt5lxjdfi ; if (
ssIsSampleHit ( S , 2 , 0 ) ) { rowIdx = ( int32_T ) ( ( ( ( ( uint32_T ) (
_rtB -> cmqnjpd0ju < ld5zvvrfqt ( S ) -> l00gpkyvly ) << 1 ) + ( _rtB ->
cmqnjpd0ju > ld5zvvrfqt ( S ) -> k4myhwuc2r ) ) << 1 ) + _rtDW -> bvad1zjfik
) ; _rtB -> eoylzmm3fo [ 0U ] = ni220kbneq . afb3sgvc3w [ ( uint32_T ) rowIdx
] ; _rtB -> eoylzmm3fo [ 1U ] = ni220kbneq . afb3sgvc3w [ rowIdx + 8U ] ; }
hrmedkfbdf = _rtB -> eoylzmm3fo [ 0 ] ; _rtB -> nhwv4gwihk = - 21000.0 *
hrmedkfbdf ; if ( ( _rtDW -> hfvh40s0je >= ssGetTaskTime ( S , 0 ) ) && (
_rtDW -> f41a3yqptq >= ssGetTaskTime ( S , 0 ) ) ) { _rtB -> k13oxnct1p =
_rtB -> nhwv4gwihk ; } else { if ( ( ( _rtDW -> hfvh40s0je < _rtDW ->
f41a3yqptq ) && ( _rtDW -> f41a3yqptq < ssGetTaskTime ( S , 0 ) ) ) || ( (
_rtDW -> hfvh40s0je >= _rtDW -> f41a3yqptq ) && ( _rtDW -> hfvh40s0je >=
ssGetTaskTime ( S , 0 ) ) ) ) { pzh42py0bn = ssGetTaskTime ( S , 0 ) - _rtDW
-> f41a3yqptq ; mqc0yqbsjn = _rtDW -> aq3qjo4ji4 ; } else { pzh42py0bn =
ssGetTaskTime ( S , 0 ) - _rtDW -> hfvh40s0je ; mqc0yqbsjn = _rtDW ->
lidlmlim32 ; } byehzqrbel = pzh42py0bn * 42000.0 ; lstej3qx0u = _rtB ->
nhwv4gwihk - mqc0yqbsjn ; if ( lstej3qx0u > byehzqrbel ) { _rtB -> k13oxnct1p
= mqc0yqbsjn + byehzqrbel ; } else { pzh42py0bn *= - 42000.0 ; if (
lstej3qx0u < pzh42py0bn ) { _rtB -> k13oxnct1p = mqc0yqbsjn + pzh42py0bn ; }
else { _rtB -> k13oxnct1p = _rtB -> nhwv4gwihk ; } } } pzh42py0bn =
gyprtoeon3 - _rtB -> k13oxnct1p ; hrmedkfbdf = muDoubleScalarAbs ( pzh42py0bn
) ; hrmedkfbdf = 1.1 * rt_Lookup ( _rtP -> EngineSpeedPower . power , 84 ,
hrmedkfbdf , _rtP -> EngineSpeedPower . speed ) ; if ( hrmedkfbdf > 5000.0 )
{ _rtB -> pbch31g2ba = 5000.0 ; } else if ( hrmedkfbdf < 750.0 ) { _rtB ->
pbch31g2ba = 750.0 ; } else { _rtB -> pbch31g2ba = hrmedkfbdf ; } byehzqrbel
= 0.10471975511965977 * _rtB -> pbch31g2ba ; if ( ssIsMajorTimeStep ( S ) ) {
if ( gyprtoeon3 >= 12000.0 ) { _rtDW -> guq5pq4c5s = true ; } else { if (
gyprtoeon3 <= 11000.0 ) { _rtDW -> guq5pq4c5s = false ; } } } if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> hd3a03eol4 = ! ! _rtDW -> guq5pq4c5s
; _rtB -> jdmfc03xft = ( _rtDW -> aln04uuynj != ld5zvvrfqt ( S ) ->
fn00mtgcac ) ; _rtB -> k5d23dzmaj = _rtDW -> nlh5qppt4m ; } if ( _rtB ->
hd3a03eol4 || ( ( gyprtoeon3 > ld5zvvrfqt ( S ) -> e3usxlrzs3 ) && _rtB ->
jdmfc03xft ) ) { if ( pzh42py0bn > 57000.0 ) { pzh42py0bn = 57000.0 ; } else
{ if ( pzh42py0bn < - 57000.0 ) { pzh42py0bn = - 57000.0 ; } } _rtB ->
bsp0cvfp2u = 1.0 / byehzqrbel * pzh42py0bn * _rtB -> dgozwv1ban ; } else {
_rtB -> bsp0cvfp2u = _rtB -> k5d23dzmaj ; } hrmedkfbdf = 1.0 / byehzqrbel *
_rtB -> nyjtqlivfc [ 11 ] ; if ( hrmedkfbdf > 1.0 ) { j0bnh13vos = 1.0 ; }
else if ( hrmedkfbdf < 0.0 ) { j0bnh13vos = 0.0 ; } else { j0bnh13vos =
hrmedkfbdf ; } byehzqrbel = _rtB -> dgozwv1ban * _rtB -> bsp0cvfp2u *
j0bnh13vos * 0.27777777777777779 ; if ( byehzqrbel > awwg3xagjh ) { _rtB ->
mlkkky1r0d = awwg3xagjh ; } else if ( byehzqrbel < - awwg3xagjh ) { _rtB ->
mlkkky1r0d = - awwg3xagjh ; } else { _rtB -> mlkkky1r0d = byehzqrbel ; }
hrmedkfbdf = - _rtB -> mlkkky1r0d * ld5zvvrfqt ( S ) -> m3cnkmvxti ; if ( (
_rtDW -> mtptmi2003 == ( rtMinusInf ) ) || ( _rtDW -> mtptmi2003 ==
ssGetTaskTime ( S , 0 ) ) ) { _rtDW -> mtptmi2003 = ssGetTaskTime ( S , 0 ) ;
_rtB -> ly02rlaby4 = 0.0 ; } else { _rtB -> ly02rlaby4 = hrmedkfbdf ; } if (
ssIsSampleHit ( S , 2 , 0 ) ) { if ( _rtB -> ly02rlaby4 > 45.0 ) { dztyrqu4xa
= 45.0 ; } else if ( _rtB -> ly02rlaby4 < - 45.0 ) { dztyrqu4xa = - 45.0 ; }
else { dztyrqu4xa = _rtB -> ly02rlaby4 ; } aqlslovppe = 3.4722222222222219 *
dztyrqu4xa ; dyfxp2slod = - ld5zvvrfqt ( S ) -> cgjwk3jciy * ckrl0nmlwt +
aqlslovppe * lduwq00gqj ; ctpq3axefx = dyfxp2slod - nfqwsurguw_idx_0 ; if (
ctpq3axefx >= 0.0 ) { _rtDW -> mdrfaaqhlc = true ; } else { if ( ctpq3axefx
<= 0.0 ) { _rtDW -> mdrfaaqhlc = false ; } } dk4tk42hhp = ( 1.7320508 *
ckrl0nmlwt + - lduwq00gqj ) * aqlslovppe * 0.5 + ( 1.7320508 * lduwq00gqj +
ckrl0nmlwt ) * ld5zvvrfqt ( S ) -> cgjwk3jciy * 0.5 ; aqlslovppe = dk4tk42hhp
- nfqwsurguw_idx_1 ; if ( aqlslovppe >= 0.0 ) { _rtDW -> hi5e5wjvfn = true ;
} else { if ( aqlslovppe <= 0.0 ) { _rtDW -> hi5e5wjvfn = false ; } }
f1b5simhxh = ( 0.0 - dk4tk42hhp ) - dyfxp2slod ; lduwq00gqj = f1b5simhxh -
nfqwsurguw_idx_2 ; if ( lduwq00gqj >= 0.0 ) { _rtDW -> ltj2mwt3by = true ; }
else { if ( lduwq00gqj <= 0.0 ) { _rtDW -> ltj2mwt3by = false ; } } _rtB ->
lxfhu1jywv [ 0 ] = ( ( real_T ) _rtDW -> mdrfaaqhlc - ( real_T ) _rtDW ->
hi5e5wjvfn ) * ld5zvvrfqt ( S ) -> m3cnkmvxti * _rtB -> kabhe5eb4z ; _rtB ->
lxfhu1jywv [ 1 ] = ( ( real_T ) _rtDW -> hi5e5wjvfn - ( real_T ) _rtDW ->
ltj2mwt3by ) * ld5zvvrfqt ( S ) -> m3cnkmvxti * _rtB -> kabhe5eb4z ; _rtB ->
nzkn3wqssh = _rtDW -> bro0cn1wmi ; nfqwsurguw_idx_0 = _rtDW -> j31s1kcymk [ 0
] ; nfqwsurguw_idx_1 = _rtDW -> j31s1kcymk [ 1 ] ; nfqwsurguw_idx_2 = _rtDW
-> j31s1kcymk [ 2 ] ; ehcygfucdl /= 4.0 ; ctpq3axefx = 4.0 * ehcygfucdl ;
aqlslovppe = muDoubleScalarCos ( ctpq3axefx ) ; ctpq3axefx =
muDoubleScalarSin ( ctpq3axefx ) ; if ( ssIsSampleHit ( S , 3 , 0 ) ) { _rtB
-> hbaycoc5sh = _rtDW -> gsr0ogd2xb ; } _rtB -> fwkiibhki3 =
0.002479481623358034 * _rtB -> hbaycoc5sh ; } if ( ( _rtDW -> joiszbfghn >=
ssGetTaskTime ( S , 0 ) ) && ( _rtDW -> jlnwqqs23l >= ssGetTaskTime ( S , 0 )
) ) { _rtB -> hrd2ygiqtf = _rtB -> fwkiibhki3 ; } else { if ( ( ( _rtDW ->
joiszbfghn < _rtDW -> jlnwqqs23l ) && ( _rtDW -> jlnwqqs23l < ssGetTaskTime (
S , 0 ) ) ) || ( ( _rtDW -> joiszbfghn >= _rtDW -> jlnwqqs23l ) && ( _rtDW ->
joiszbfghn >= ssGetTaskTime ( S , 0 ) ) ) ) { pzh42py0bn = ssGetTaskTime ( S
, 0 ) - _rtDW -> jlnwqqs23l ; mqc0yqbsjn = _rtDW -> miwjijsda1 ; } else {
pzh42py0bn = ssGetTaskTime ( S , 0 ) - _rtDW -> joiszbfghn ; mqc0yqbsjn =
_rtDW -> narm2z4h4g ; } byehzqrbel = pzh42py0bn * 10.0 ; lstej3qx0u = _rtB ->
fwkiibhki3 - mqc0yqbsjn ; if ( lstej3qx0u > byehzqrbel ) { _rtB -> hrd2ygiqtf
= mqc0yqbsjn + byehzqrbel ; } else { pzh42py0bn *= - 10.0 ; if ( lstej3qx0u <
pzh42py0bn ) { _rtB -> hrd2ygiqtf = mqc0yqbsjn + pzh42py0bn ; } else { _rtB
-> hrd2ygiqtf = _rtB -> fwkiibhki3 ; } } } hrmedkfbdf = muDoubleScalarAbs (
_rtB -> hrd2ygiqtf ) ; _rtB -> niuqfwzvzn = rt_Lookup ( ni220kbneq .
hvtx2huqpc , 301 , hrmedkfbdf , ni220kbneq . fjibtn4wrs ) ; if (
ssIsSampleHit ( S , 2 , 0 ) ) { _rtB -> k1fix0q13s = _rtB -> cnt5lxjdfi ;
ssCallAccelRunBlock ( S , 5 , 0 , SS_CALL_MDL_OUTPUTS ) ; lstej3qx0u = _rtB
-> kqnrloov3e - _rtDW -> edm2y2p3wp ; if ( lstej3qx0u > 0.006 ) { lduwq00gqj
= _rtDW -> edm2y2p3wp + 0.006 ; } else if ( lstej3qx0u < - 0.006 ) {
lduwq00gqj = _rtDW -> edm2y2p3wp + - 0.006 ; } else { lduwq00gqj = _rtB ->
kqnrloov3e ; } _rtDW -> edm2y2p3wp = lduwq00gqj ; lduwq00gqj *= -
382.64830010578072 ; lstej3qx0u = _rtB -> h0veg11mi0 - _rtDW -> asqvifamq0 ;
if ( lstej3qx0u > 0.006 ) { ckrl0nmlwt = _rtDW -> asqvifamq0 + 0.006 ; } else
if ( lstej3qx0u < - 0.006 ) { ckrl0nmlwt = _rtDW -> asqvifamq0 + - 0.006 ; }
else { ckrl0nmlwt = _rtB -> h0veg11mi0 ; } _rtDW -> asqvifamq0 = ckrl0nmlwt ;
ckrl0nmlwt *= 382.64830010578072 ; pzh42py0bn = - lduwq00gqj * ctpq3axefx +
ckrl0nmlwt * aqlslovppe ; byehzqrbel = pzh42py0bn - nfqwsurguw_idx_0 ; if (
byehzqrbel >= 0.0 ) { _rtDW -> bmg0h5hxwy = true ; } else { if ( byehzqrbel
<= 0.0 ) { _rtDW -> bmg0h5hxwy = false ; } } mqc0yqbsjn = ( 1.7320508 *
ctpq3axefx + - aqlslovppe ) * ckrl0nmlwt * 0.5 + ( 1.7320508 * aqlslovppe +
ctpq3axefx ) * lduwq00gqj * 0.5 ; ctpq3axefx = mqc0yqbsjn - nfqwsurguw_idx_1
; if ( ctpq3axefx >= 0.0 ) { _rtDW -> kakc11drsq = true ; } else { if (
ctpq3axefx <= 0.0 ) { _rtDW -> kakc11drsq = false ; } } lstej3qx0u = ( 0.0 -
mqc0yqbsjn ) - pzh42py0bn ; aqlslovppe = lstej3qx0u - nfqwsurguw_idx_2 ; if (
aqlslovppe >= 0.0 ) { _rtDW -> d1uemo0w03 = true ; } else { if ( aqlslovppe
<= 0.0 ) { _rtDW -> d1uemo0w03 = false ; } } _rtB -> gyeo13155t [ 0 ] = ( (
real_T ) _rtDW -> bmg0h5hxwy - ( real_T ) _rtDW -> kakc11drsq ) * ld5zvvrfqt
( S ) -> fjdpvlcyix * _rtB -> nzkn3wqssh ; _rtB -> gyeo13155t [ 1 ] = ( (
real_T ) _rtDW -> kakc11drsq - ( real_T ) _rtDW -> d1uemo0w03 ) * ld5zvvrfqt
( S ) -> fjdpvlcyix * _rtB -> nzkn3wqssh ; _rtB -> ahizc3we23 = _rtDW ->
kzrq2xyp0f ; h1tnk5yrr5 = ( ld5zvvrfqt ( S ) -> m3cnkmvxti != 0.0 ) ;
zcEvent_idx_0 = rt_ZCFcn ( ANY_ZERO_CROSSING , & _rtZCE -> gn3hyklx0i [ 0 ] ,
( dyfxp2slod ) ) ; zcEvent_idx_1 = rt_ZCFcn ( ANY_ZERO_CROSSING , & _rtZCE ->
gn3hyklx0i [ 1 ] , ( dk4tk42hhp ) ) ; zcEvent_idx_2 = rt_ZCFcn (
ANY_ZERO_CROSSING , & _rtZCE -> gn3hyklx0i [ 2 ] , ( f1b5simhxh ) ) ; if (
_rtDW -> p5ivrte15o [ 0 ] == 0 ) { if ( zcEvent_idx_0 != NO_ZCEVENT ) { _rtB
-> ogsn50uyme [ 0 ] = ! _rtB -> ogsn50uyme [ 0 ] ; _rtDW -> p5ivrte15o [ 0 ]
= 1 ; } else if ( _rtB -> ogsn50uyme [ 0 ] ) { if ( dyfxp2slod != 0.0 ) {
_rtB -> ogsn50uyme [ 0 ] = false ; } } else { if ( dyfxp2slod == 0.0 ) { _rtB
-> ogsn50uyme [ 0 ] = true ; } } } else { if ( dyfxp2slod != 0.0 ) { _rtB ->
ogsn50uyme [ 0 ] = false ; } _rtDW -> p5ivrte15o [ 0 ] = 0 ; } if ( _rtDW ->
p5ivrte15o [ 1 ] == 0 ) { if ( zcEvent_idx_1 != NO_ZCEVENT ) { _rtB ->
ogsn50uyme [ 1 ] = ! _rtB -> ogsn50uyme [ 1 ] ; _rtDW -> p5ivrte15o [ 1 ] = 1
; } else if ( _rtB -> ogsn50uyme [ 1 ] ) { if ( dk4tk42hhp != 0.0 ) { _rtB ->
ogsn50uyme [ 1 ] = false ; } } else { if ( dk4tk42hhp == 0.0 ) { _rtB ->
ogsn50uyme [ 1 ] = true ; } } } else { if ( dk4tk42hhp != 0.0 ) { _rtB ->
ogsn50uyme [ 1 ] = false ; } _rtDW -> p5ivrte15o [ 1 ] = 0 ; } if ( _rtDW ->
p5ivrte15o [ 2 ] == 0 ) { if ( zcEvent_idx_2 != NO_ZCEVENT ) { _rtB ->
ogsn50uyme [ 2 ] = ! _rtB -> ogsn50uyme [ 2 ] ; _rtDW -> p5ivrte15o [ 2 ] = 1
; } else if ( _rtB -> ogsn50uyme [ 2 ] ) { if ( f1b5simhxh != 0.0 ) { _rtB ->
ogsn50uyme [ 2 ] = false ; } } else { if ( f1b5simhxh == 0.0 ) { _rtB ->
ogsn50uyme [ 2 ] = true ; } } } else { if ( f1b5simhxh != 0.0 ) { _rtB ->
ogsn50uyme [ 2 ] = false ; } _rtDW -> p5ivrte15o [ 2 ] = 0 ; } keyxmz53xi ( S
, _rtB -> ogsn50uyme [ 0 ] , h1tnk5yrr5 , & _rtB -> keyxmz53xiy , & _rtDW ->
keyxmz53xiy ) ; keyxmz53xi ( S , _rtB -> ogsn50uyme [ 1 ] , h1tnk5yrr5 , &
_rtB -> d5h5wn4011 , & _rtDW -> d5h5wn4011 ) ; keyxmz53xi ( S , _rtB ->
ogsn50uyme [ 2 ] , h1tnk5yrr5 , & _rtB -> hlr1ddtilb , & _rtDW -> hlr1ddtilb
) ; byehzqrbel = 0.05823546641575128 * _rtDW -> nonllthbl2 ; ctpq3axefx =
0.05823546641575128 * _rtDW -> kol45dq53x ; aqlslovppe = muDoubleScalarSin (
jwhz1ujp3w ) ; jwhz1ujp3w = muDoubleScalarCos ( jwhz1ujp3w ) ; lduwq00gqj = (
0.0 - aqlslovppe * ld5zvvrfqt ( S ) -> nqul2ckvrn ) - jwhz1ujp3w * ld5zvvrfqt
( S ) -> dzfaecpybx ; ckrl0nmlwt = aqlslovppe * ld5zvvrfqt ( S ) ->
dzfaecpybx - jwhz1ujp3w * ld5zvvrfqt ( S ) -> nqul2ckvrn ; j0bnh13vos = (
byehzqrbel * aqlslovppe + ctpq3axefx * jwhz1ujp3w ) + ld5zvvrfqt ( S ) ->
f50rxdshkv ; nfqwsurguw_idx_0 = ( byehzqrbel * lduwq00gqj + ctpq3axefx *
ckrl0nmlwt ) + ld5zvvrfqt ( S ) -> f50rxdshkv ; byehzqrbel = ( ( ( 0.0 -
lduwq00gqj ) - aqlslovppe ) * byehzqrbel + ( ( 0.0 - ckrl0nmlwt ) -
jwhz1ujp3w ) * ctpq3axefx ) + ld5zvvrfqt ( S ) -> f50rxdshkv ; _rtB ->
e3ufrwhgt1 [ 0 ] = ( real_T ) _rtB -> keyxmz53xiy . forbrjhq11 * dyfxp2slod +
0.2 * j0bnh13vos ; _rtB -> e3ufrwhgt1 [ 1 ] = ( real_T ) _rtB -> d5h5wn4011 .
forbrjhq11 * dk4tk42hhp + 0.2 * nfqwsurguw_idx_0 ; _rtB -> e3ufrwhgt1 [ 2 ] =
( real_T ) _rtB -> hlr1ddtilb . forbrjhq11 * f1b5simhxh + 0.2 * byehzqrbel ;
if ( _rtDW -> ehaijafsot <= 1.0 ) { j0bnh13vos = 1.0 ; } else { j0bnh13vos =
_rtDW -> ehaijafsot ; } _rtB -> lajoqypqs0 = _rtDW -> fw2k5vojpd / j0bnh13vos
; zcEvent_idx_0 = rt_ZCFcn ( ANY_ZERO_CROSSING , & _rtZCE -> iw5dmb04jk [ 0 ]
, ( pzh42py0bn ) ) ; zcEvent_idx_1 = rt_ZCFcn ( ANY_ZERO_CROSSING , & _rtZCE
-> iw5dmb04jk [ 1 ] , ( mqc0yqbsjn ) ) ; zcEvent_idx_2 = rt_ZCFcn (
ANY_ZERO_CROSSING , & _rtZCE -> iw5dmb04jk [ 2 ] , ( lstej3qx0u ) ) ; if (
_rtDW -> l43ws31i1a [ 0 ] == 0 ) { if ( zcEvent_idx_0 != NO_ZCEVENT ) { _rtB
-> pklvnzle0m [ 0 ] = ! _rtB -> pklvnzle0m [ 0 ] ; _rtDW -> l43ws31i1a [ 0 ]
= 1 ; } else if ( _rtB -> pklvnzle0m [ 0 ] ) { if ( pzh42py0bn != 0.0 ) {
_rtB -> pklvnzle0m [ 0 ] = false ; } } else { if ( pzh42py0bn == 0.0 ) { _rtB
-> pklvnzle0m [ 0 ] = true ; } } } else { if ( pzh42py0bn != 0.0 ) { _rtB ->
pklvnzle0m [ 0 ] = false ; } _rtDW -> l43ws31i1a [ 0 ] = 0 ; } if ( _rtDW ->
l43ws31i1a [ 1 ] == 0 ) { if ( zcEvent_idx_1 != NO_ZCEVENT ) { _rtB ->
pklvnzle0m [ 1 ] = ! _rtB -> pklvnzle0m [ 1 ] ; _rtDW -> l43ws31i1a [ 1 ] = 1
; } else if ( _rtB -> pklvnzle0m [ 1 ] ) { if ( mqc0yqbsjn != 0.0 ) { _rtB ->
pklvnzle0m [ 1 ] = false ; } } else { if ( mqc0yqbsjn == 0.0 ) { _rtB ->
pklvnzle0m [ 1 ] = true ; } } } else { if ( mqc0yqbsjn != 0.0 ) { _rtB ->
pklvnzle0m [ 1 ] = false ; } _rtDW -> l43ws31i1a [ 1 ] = 0 ; } if ( _rtDW ->
l43ws31i1a [ 2 ] == 0 ) { if ( zcEvent_idx_2 != NO_ZCEVENT ) { _rtB ->
pklvnzle0m [ 2 ] = ! _rtB -> pklvnzle0m [ 2 ] ; _rtDW -> l43ws31i1a [ 2 ] = 1
; } else if ( _rtB -> pklvnzle0m [ 2 ] ) { if ( lstej3qx0u != 0.0 ) { _rtB ->
pklvnzle0m [ 2 ] = false ; } } else { if ( lstej3qx0u == 0.0 ) { _rtB ->
pklvnzle0m [ 2 ] = true ; } } } else { if ( lstej3qx0u != 0.0 ) { _rtB ->
pklvnzle0m [ 2 ] = false ; } _rtDW -> l43ws31i1a [ 2 ] = 0 ; } keyxmz53xi ( S
, _rtB -> pklvnzle0m [ 0 ] , ld5zvvrfqt ( S ) -> hewnde2vzx , & _rtB ->
ovboqennya , & _rtDW -> ovboqennya ) ; keyxmz53xi ( S , _rtB -> pklvnzle0m [
1 ] , ld5zvvrfqt ( S ) -> hewnde2vzx , & _rtB -> ifhlf2te5a , & _rtDW ->
ifhlf2te5a ) ; keyxmz53xi ( S , _rtB -> pklvnzle0m [ 2 ] , ld5zvvrfqt ( S )
-> hewnde2vzx , & _rtB -> dtnq4yt00p , & _rtDW -> dtnq4yt00p ) ;
nfqwsurguw_idx_0 = 0.05823546641575128 * _rtDW -> lvw3lta2fy ; j0bnh13vos =
0.05823546641575128 * _rtDW -> c20b4oc1jp ; ehcygfucdl *= 4.0 ; awwg3xagjh =
muDoubleScalarSin ( ehcygfucdl ) ; ehcygfucdl = muDoubleScalarCos (
ehcygfucdl ) ; i5nu34w4uj = ( 0.0 - awwg3xagjh * ld5zvvrfqt ( S ) ->
oiaeasobhv ) - ehcygfucdl * ld5zvvrfqt ( S ) -> gzfsnadk2s ; byehzqrbel =
awwg3xagjh * ld5zvvrfqt ( S ) -> gzfsnadk2s - ehcygfucdl * ld5zvvrfqt ( S )
-> oiaeasobhv ; lduwq00gqj = ( nfqwsurguw_idx_0 * awwg3xagjh + j0bnh13vos *
ehcygfucdl ) + ld5zvvrfqt ( S ) -> lu1tljydpa ; ckrl0nmlwt = (
nfqwsurguw_idx_0 * i5nu34w4uj + j0bnh13vos * byehzqrbel ) + ld5zvvrfqt ( S )
-> lu1tljydpa ; nfqwsurguw_idx_0 = ( ( ( 0.0 - i5nu34w4uj ) - awwg3xagjh ) *
nfqwsurguw_idx_0 + ( ( 0.0 - byehzqrbel ) - ehcygfucdl ) * j0bnh13vos ) +
ld5zvvrfqt ( S ) -> lu1tljydpa ; _rtB -> oodgaevstw [ 0 ] = ( real_T ) _rtB
-> ovboqennya . forbrjhq11 * pzh42py0bn + 1.5384615384615383 * lduwq00gqj ;
_rtB -> oodgaevstw [ 1 ] = ( real_T ) _rtB -> ifhlf2te5a . forbrjhq11 *
mqc0yqbsjn + 1.5384615384615383 * ckrl0nmlwt ; _rtB -> oodgaevstw [ 2 ] = (
real_T ) _rtB -> dtnq4yt00p . forbrjhq11 * lstej3qx0u + 1.5384615384615383 *
nfqwsurguw_idx_0 ; if ( _rtDW -> kopxzfb0sb <= 1.0 ) { j0bnh13vos = 1.0 ; }
else { j0bnh13vos = _rtDW -> kopxzfb0sb ; } _rtB -> ig5jkqsyak = _rtDW ->
lp13v2ihui / j0bnh13vos ; _rtB -> gyswg22nqn = _rtDW -> ebwur5qeqq ;
ssCallAccelRunBlock ( S , 14 , 465 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
hp0iwn432n = _rtB -> ai215trm2o - 0.30769230769230771 * _rtB -> bena5ymrlb [
25 ] ; ssCallAccelRunBlock ( S , 14 , 468 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
bmyhud4u5s = ( ( real_T ) ( _rtB -> bena5ymrlb [ 25 ] < ld5zvvrfqt ( S ) ->
atxjka1lxn ) * 18.82114106089411 - f4ufgq33gz ) * muDoubleScalarAbs ( _rtB ->
bena5ymrlb [ 25 ] ) * 0.00064102564102564092 ; _rtB -> h1pa12vucy = 3600.0 *
eskeehll14 ; } ssCallAccelRunBlock ( S , 14 , 499 , SS_CALL_MDL_OUTPUTS ) ;
if ( ssIsSampleHit ( S , 2 , 0 ) ) { ssCallAccelRunBlock ( S , 14 , 500 ,
SS_CALL_MDL_OUTPUTS ) ; } _rtB -> nxhcxqvvez = 9.5492965855137211 * _rtB ->
cnt5lxjdfi ; if ( ssIsSampleHit ( S , 2 , 0 ) && ssIsSampleHit ( S , 3 , 0 )
) { _rtB -> bmlkzye2ej = _rtDW -> bv5gvrfela ; } ssCallAccelRunBlock ( S , 14
, 503 , SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSampleHit ( S , 2 , 0 ) ) {
ssCallAccelRunBlock ( S , 14 , 506 , SS_CALL_MDL_OUTPUTS ) ; nfqwsurguw_idx_0
= 0.013480000230266853 * _rtDW -> pe31gvq3pv ; j0bnh13vos =
0.013480000230266853 * _rtDW -> bw5cwo255x ; rowIdx = ( int32_T ) ( ( ( ( (
uint32_T ) ( nfqwsurguw_idx_0 > j0bnh13vos ) << 1 ) + ( nfqwsurguw_idx_0 <
0.9 * j0bnh13vos ) ) << 1 ) + _rtDW -> l2t4rgxmml ) ; _rtB -> iq5me3ewfy [ 0U
] = ni220kbneq . afb3sgvc3w [ ( uint32_T ) rowIdx ] ; _rtB -> iq5me3ewfy [ 1U
] = ni220kbneq . afb3sgvc3w [ rowIdx + 8U ] ; mjvuadvsvc = ( uint8_T ) ( _rtB
-> iq5me3ewfy [ 0 ] << 7 ) ; _rtB -> niqvsoxfjj = ( real_T ) mjvuadvsvc *
0.0078125 ; _rtB -> opeypgfor0 = ( real_T ) mjvuadvsvc * 0.0078125 ; _rtB ->
fxyltlfc5u = ( real_T ) mjvuadvsvc * 0.0078125 ; pbnk0frrk0 = ! ( mjvuadvsvc
!= 0 ) ; _rtB -> ehcylecwwu = pbnk0frrk0 ; _rtB -> k4veqycxfb = pbnk0frrk0 ;
_rtB -> ntixyghseh = pbnk0frrk0 ; _rtB -> lxcqctajs1 = ( ( _rtB -> bena5ymrlb
[ 37 ] * _rtB -> bena5ymrlb [ 37 ] + _rtB -> bena5ymrlb [ 38 ] * _rtB ->
bena5ymrlb [ 38 ] ) + _rtB -> bena5ymrlb [ 39 ] * _rtB -> bena5ymrlb [ 39 ] )
* 0.001 + ( _rtB -> bena5ymrlb [ 20 ] * _rtB -> bena5ymrlb [ 37 ] + _rtB ->
bena5ymrlb [ 21 ] * _rtB -> bena5ymrlb [ 38 ] ) ; } pzh42py0bn =
muDoubleScalarPower ( ( 0.006391889398924 * _rtB -> cnt5lxjdfi * _rtB ->
cwott4tken + 0.0065 * _rtB -> gw24bveokp ) + 0.702664574517444 * _rtB ->
cnt5lxjdfi , 2.0 ) + muDoubleScalarPower ( 0.0065 * _rtB -> cwott4tken -
0.008228209001868 * _rtB -> cnt5lxjdfi * _rtB -> gw24bveokp , 2.0 ) ; if (
pzh42py0bn < 0.0 ) { pzh42py0bn = - muDoubleScalarSqrt ( - pzh42py0bn ) ; }
else { pzh42py0bn = muDoubleScalarSqrt ( pzh42py0bn ) ; } _rtB -> i2js5l42nk
= 1.5707963267948966 * pzh42py0bn ; if ( ssIsSampleHit ( S , 2 , 0 ) ) { _rtB
-> cglbwixnvl = ( ( 2.0 * _rtB -> bena5ymrlb [ 14 ] + _rtB -> bena5ymrlb [ 15
] ) * mizlp41tvx + 1.7320508075688772 * _rtB -> bena5ymrlb [ 15 ] *
po0ockmy2b ) * 0.33333333333333331 ; _rtB -> c33hzky0fu = ( ( 2.0 * _rtB ->
bena5ymrlb [ 14 ] + _rtB -> bena5ymrlb [ 15 ] ) * po0ockmy2b + -
1.7320508075688772 * _rtB -> bena5ymrlb [ 15 ] * mizlp41tvx ) *
0.33333333333333331 ; _rtB -> jjnmwnblw3 = 625.79305591134812 * _rtB ->
c33hzky0fu ; } _rtB -> gd34fxv5th = 4.0 * _rtB -> cnt5lxjdfi ; if (
ssIsSampleHit ( S , 2 , 0 ) ) { _rtB -> ndo5wtig4q = 4.0676548634237628 *
_rtB -> cwott4tken ; } _rtB -> etpk1e5ook = _rtB -> gd34fxv5th * _rtB ->
gw24bveokp * 1.2872890139890598 + ( _rtB -> jjnmwnblw3 - _rtB -> ndo5wtig4q )
; if ( ssIsSampleHit ( S , 2 , 0 ) ) { _rtB -> ajcrunslqi =
486.13252277523628 * _rtB -> cglbwixnvl ; _rtB -> obrmoapfkl =
3.1598613980390358 * _rtB -> gw24bveokp ; } _rtB -> krc04vab0s = ( ( _rtB ->
ajcrunslqi - _rtB -> obrmoapfkl ) - _rtB -> cwott4tken * _rtB -> gd34fxv5th *
0.77682632969980325 ) - 85.397025568738272 * _rtB -> gd34fxv5th ; hrmedkfbdf
= muDoubleScalarAbs ( _rtB -> cnt5lxjdfi ) ; HEV_acc_LookUp_real_T_real_T ( &
( h2yfd4orwq ) , ni220kbneq . icn4mwaz3x , hrmedkfbdf , ni220kbneq .
mic5dtfppd , 6U ) ; if ( _rtB -> kz0iasghfr > h2yfd4orwq ) { hrmedkfbdf =
h2yfd4orwq ; } else if ( _rtB -> kz0iasghfr < - h2yfd4orwq ) { hrmedkfbdf = -
h2yfd4orwq ; } else { hrmedkfbdf = _rtB -> kz0iasghfr ; } hrmedkfbdf *=
ld5zvvrfqt ( S ) -> fjdpvlcyix ; if ( ( _rtDW -> dlegz3mcx5 == ( rtMinusInf )
) || ( _rtDW -> dlegz3mcx5 == ssGetTaskTime ( S , 0 ) ) ) { _rtDW ->
dlegz3mcx5 = ssGetTaskTime ( S , 0 ) ; _rtB -> myzaamxq1b = 0.0 ; } else {
_rtB -> myzaamxq1b = hrmedkfbdf ; } if ( ssIsSampleHit ( S , 3 , 0 ) ) { _rtB
-> gs2vxvhjod = _rtB -> myzaamxq1b ; if ( _rtB -> gs2vxvhjod > 400.0 ) { _rtB
-> i2att01yfi = 400.0 ; } else if ( _rtB -> gs2vxvhjod < - 400.0 ) { _rtB ->
i2att01yfi = - 400.0 ; } else { _rtB -> i2att01yfi = _rtB -> gs2vxvhjod ; } }
if ( ssIsSampleHit ( S , 1 , 0 ) && ssIsSampleHit ( S , 3 , 0 ) ) { _rtB ->
ebla0tj0hy = ld5zvvrfqt ( S ) -> fjdpvlcyix ; } if ( ssIsSampleHit ( S , 3 ,
0 ) ) { _rtB -> eo1xa4liee = _rtB -> i2att01yfi * _rtB -> ebla0tj0hy ; } if (
ssIsSampleHit ( S , 2 , 0 ) ) { ssCallAccelRunBlock ( S , 14 , 647 ,
SS_CALL_MDL_OUTPUTS ) ; } _rtB -> nxhcxqvvez = 9.5492965855137211 * _rtB ->
nyjtqlivfc [ 7 ] ; if ( ssIsSampleHit ( S , 1 , 0 ) && ssIsSampleHit ( S , 2
, 0 ) ) { _rtB -> lczgflwlep = ld5zvvrfqt ( S ) -> m3cnkmvxti ; } if (
ssIsSampleHit ( S , 2 , 0 ) ) { _rtB -> p1d4auzzvf = dztyrqu4xa * _rtB ->
lczgflwlep ; } _rtB -> im3d432cdi = _rtB -> cyi24unrh5 * _rtB -> nyjtqlivfc [
7 ] ; ssCallAccelRunBlock ( S , 14 , 652 , SS_CALL_MDL_OUTPUTS ) ; if (
ssIsSampleHit ( S , 2 , 0 ) ) { nfqwsurguw_idx_0 = 0.013480000230266853 *
_rtDW -> dy4ppyw4mo ; j0bnh13vos = 0.013480000230266853 * _rtDW -> hmybg5b1mi
; rowIdx = ( int32_T ) ( ( ( ( ( uint32_T ) ( nfqwsurguw_idx_0 > j0bnh13vos )
<< 1 ) + ( nfqwsurguw_idx_0 < 0.9 * j0bnh13vos ) ) << 1 ) + _rtDW ->
gkq12xkctn ) ; _rtB -> iemvl1x4dw [ 0U ] = ni220kbneq . afb3sgvc3w [ (
uint32_T ) rowIdx ] ; _rtB -> iemvl1x4dw [ 1U ] = ni220kbneq . afb3sgvc3w [
rowIdx + 8U ] ; mjvuadvsvc = ( uint8_T ) ( _rtB -> iemvl1x4dw [ 0 ] << 7 ) ;
_rtB -> hz1er4tcne = ( real_T ) mjvuadvsvc * 0.0078125 ; _rtB -> exxli1ujcy =
( real_T ) mjvuadvsvc * 0.0078125 ; _rtB -> dvsvlfk1qa = ( real_T )
mjvuadvsvc * 0.0078125 ; pbnk0frrk0 = ! ( mjvuadvsvc != 0 ) ; _rtB ->
g0f5c5ngkd = pbnk0frrk0 ; _rtB -> lyhse2bw2c = pbnk0frrk0 ; _rtB ->
ny4q2volh1 = pbnk0frrk0 ; _rtB -> ic2zjwnuef = ( ( _rtB -> bena5ymrlb [ 31 ]
* _rtB -> bena5ymrlb [ 31 ] + _rtB -> bena5ymrlb [ 32 ] * _rtB -> bena5ymrlb
[ 32 ] ) + _rtB -> bena5ymrlb [ 33 ] * _rtB -> bena5ymrlb [ 33 ] ) * 0.001 +
( _rtB -> bena5ymrlb [ 17 ] * _rtB -> bena5ymrlb [ 31 ] + _rtB -> bena5ymrlb
[ 18 ] * _rtB -> bena5ymrlb [ 32 ] ) ; } pzh42py0bn = muDoubleScalarPower ( (
0.000635 * _rtB -> nyjtqlivfc [ 7 ] * _rtB -> gj05ld235c + 0.05 * _rtB ->
nx5hrxfrql ) + 0.192 * _rtB -> nyjtqlivfc [ 7 ] , 2.0 ) + muDoubleScalarPower
( 0.05 * _rtB -> gj05ld235c - 0.000635 * _rtB -> nyjtqlivfc [ 7 ] * _rtB ->
nx5hrxfrql , 2.0 ) ; if ( pzh42py0bn < 0.0 ) { pzh42py0bn = -
muDoubleScalarSqrt ( - pzh42py0bn ) ; } else { pzh42py0bn =
muDoubleScalarSqrt ( pzh42py0bn ) ; } _rtB -> pj1lluvq0w = 1.5707963267948966
* pzh42py0bn ; if ( ssIsSampleHit ( S , 2 , 0 ) ) { _rtB -> kjp4rrmaoz = ( (
2.0 * _rtB -> bena5ymrlb [ 12 ] + _rtB -> bena5ymrlb [ 13 ] ) * mkcfwi2fsi +
1.7320508075688772 * _rtB -> bena5ymrlb [ 13 ] * ehtkh2wauy ) *
0.33333333333333331 ; _rtB -> jg3duubwxq = ( ( 2.0 * _rtB -> bena5ymrlb [ 12
] + _rtB -> bena5ymrlb [ 13 ] ) * ehtkh2wauy + - 1.7320508075688772 * _rtB ->
bena5ymrlb [ 13 ] * mkcfwi2fsi ) * 0.33333333333333331 ; _rtB -> cxsxvkrvl2 =
1574.803149606299 * _rtB -> jg3duubwxq ; _rtB -> ehgt1d4pnd =
78.740157480314963 * _rtB -> gj05ld235c ; } _rtB -> g22pmp223s = ( _rtB ->
cxsxvkrvl2 - _rtB -> ehgt1d4pnd ) + _rtB -> nyjtqlivfc [ 7 ] * _rtB ->
nx5hrxfrql ; if ( ssIsSampleHit ( S , 2 , 0 ) ) { _rtB -> lsjwilubsh =
1574.803149606299 * _rtB -> kjp4rrmaoz ; _rtB -> f5khu2ogb0 =
78.740157480314963 * _rtB -> nx5hrxfrql ; } _rtB -> myzzzhzvyc = ( ( _rtB ->
lsjwilubsh - _rtB -> f5khu2ogb0 ) - _rtB -> gj05ld235c * _rtB -> nyjtqlivfc [
7 ] ) - 302.36220472440942 * _rtB -> nyjtqlivfc [ 7 ] ; if ( ssIsSampleHit (
S , 2 , 0 ) ) { ssCallAccelRunBlock ( S , 14 , 781 , SS_CALL_MDL_OUTPUTS ) ;
} hrmedkfbdf = ssGetT ( S ) ; if ( ssIsSampleHit ( S , 2 , 0 ) ) { _rtB ->
g4irlbdxmr = _rtB -> bena5ymrlb [ 24 ] - ld5zvvrfqt ( S ) -> nhcgmkwyb0 ; }
_rtB -> ik1e2l0kyc = ( real_T ) ( hrmedkfbdf > ld5zvvrfqt ( S ) -> mf3vkvpe5s
) * _rtB -> g4irlbdxmr ; if ( ssIsSampleHit ( S , 2 , 0 ) ) { if ( _rtDW ->
llu3sg1ihp != 0 ) { _rtB -> lelyjdafhy = _rtDW -> fj2gixcnhk ; } else { _rtB
-> lelyjdafhy = 3.0E-5 * _rtB -> ik1e2l0kyc + _rtDW -> fj2gixcnhk ; } if (
_rtB -> lelyjdafhy >= 1.0 ) { _rtB -> lelyjdafhy = 1.0 ; } else { if ( _rtB
-> lelyjdafhy <= - 1.0 ) { _rtB -> lelyjdafhy = - 1.0 ; } } } hrmedkfbdf =
0.001 * _rtB -> ik1e2l0kyc + _rtB -> lelyjdafhy ; if ( hrmedkfbdf > 0.95 ) {
j0bnh13vos = 0.95 ; } else if ( hrmedkfbdf < - 0.95 ) { j0bnh13vos = - 0.95 ;
} else { j0bnh13vos = hrmedkfbdf ; } _rtB -> giqpga4mf1 = ( j0bnh13vos + 1.0
) * 0.5 ; if ( ssIsSampleHit ( S , 2 , 0 ) ) { _rtB -> fztntlcyzw = _rtDW ->
dco4afubi3 * _rtB -> bena5ymrlb [ 23 ] ; _rtB -> ffmur2b4md = _rtDW ->
dco4afubi3 * _rtB -> bena5ymrlb [ 40 ] ; ssCallAccelRunBlock ( S , 14 , 828 ,
SS_CALL_MDL_OUTPUTS ) ; } ssCallAccelRunBlock ( S , 14 , 829 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 14 , 830 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 14 , 831 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 14 , 832 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 14 , 833 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 14 , 834 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 14 , 835 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 14 , 836 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 14 , 837 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 14 , 838 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 14 , 839 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 14 , 840 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> kv1dmerllk = muDoubleScalarAbs ( _rtB ->
pnrvucucvi ) ; if ( ( _rtDW -> en15lu4hm1 >= ssGetT ( S ) ) && ( _rtDW ->
km4yirabra >= ssGetT ( S ) ) ) { _rtB -> ez0k5qiuda = 0.0 ; } else {
pzh42py0bn = _rtDW -> en15lu4hm1 ; lastU = & _rtDW -> aa3vndu55f ; if ( _rtDW
-> en15lu4hm1 < _rtDW -> km4yirabra ) { if ( _rtDW -> km4yirabra < ssGetT ( S
) ) { pzh42py0bn = _rtDW -> km4yirabra ; lastU = & _rtDW -> ke4dqjfdz3 ; } }
else { if ( _rtDW -> en15lu4hm1 >= ssGetT ( S ) ) { pzh42py0bn = _rtDW ->
km4yirabra ; lastU = & _rtDW -> ke4dqjfdz3 ; } } _rtB -> ez0k5qiuda = ( _rtB
-> nkppx0xvpt - * lastU ) / ( ssGetT ( S ) - pzh42py0bn ) ; } _rtB ->
hkpwcze2ll = muDoubleScalarAbs ( _rtB -> omlxqlcycc ) ; _rtB -> gmgphzlr3a =
1.093 * _rtB -> hkpwcze2ll ; _rtB -> fen5sexort = 1.0464 * _rtB -> nkppx0xvpt
; { uint32_T iLeftU0 , iRghtU0 , iLeftU1 , iRghtU1 ;
HEV_acc_BINARYSEARCH_real_T ( & ( iLeftU0 ) , & ( iRghtU0 ) , _rtB ->
gmgphzlr3a , ni220kbneq . c4qvyaa1p5 , 108U ) ; if ( _rtB -> fen5sexort <=
0.0 ) { iLeftU1 = 0U ; iRghtU1 = 0U ; } else if ( _rtB -> fen5sexort >=
6000.0 ) { iLeftU1 = 100U ; iRghtU1 = 100U ; } else { iLeftU1 = ( uint32_T )
( ( _rtB -> fen5sexort ) / 60.0 ) ; iRghtU1 = iLeftU1 + 1 ; } { real_T yTemp
; real_T u1Lambda ; real_T u0Lambda ; if ( iLeftU1 != iRghtU1 ) { { real_T
num = ( real_T ) ( _rtB -> fen5sexort ) - ( iLeftU1 * 60.0 ) ; u1Lambda = num
/ 60.0 ; } } else { u1Lambda = 0.0 ; } if ( ( ni220kbneq . c4qvyaa1p5 [
iRghtU0 ] ) > ( ni220kbneq . c4qvyaa1p5 [ iLeftU0 ] ) ) { real_T num ; real_T
den ; den = ( ni220kbneq . c4qvyaa1p5 [ iRghtU0 ] ) ; den -= ( ni220kbneq .
c4qvyaa1p5 [ iLeftU0 ] ) ; num = _rtB -> gmgphzlr3a ; num -= ( ni220kbneq .
c4qvyaa1p5 [ iLeftU0 ] ) ; u0Lambda = num / den ; } else { u0Lambda = 0.0 ; }
{ real_T yLeftCast ; real_T yRghtCast ; yLeftCast = ( ni220kbneq . ndhdp2vfck
[ ( iLeftU0 + 109U * iLeftU1 ) ] ) ; yRghtCast = ( ni220kbneq . ndhdp2vfck [
( iLeftU0 + 109U * iRghtU1 ) ] ) ; yLeftCast += u1Lambda * ( yRghtCast -
yLeftCast ) ; klp2rkbjun = yLeftCast ; } { real_T yLeftCast ; real_T
yRghtCast ; yLeftCast = ( ni220kbneq . ndhdp2vfck [ ( iRghtU0 + 109U *
iLeftU1 ) ] ) ; yRghtCast = ( ni220kbneq . ndhdp2vfck [ ( iRghtU0 + 109U *
iRghtU1 ) ] ) ; yLeftCast += u1Lambda * ( yRghtCast - yLeftCast ) ; yTemp =
yLeftCast ; } { real_T yLeftCast ; real_T yRghtCast ; yLeftCast = klp2rkbjun
; yRghtCast = yTemp ; yLeftCast += u0Lambda * ( yRghtCast - yLeftCast ) ;
klp2rkbjun = yLeftCast ; } } } _rtB -> k4to1xm133 = 1.0351048413332149 *
klp2rkbjun ; _rtB -> fthsjka0i4 = 1.933764640184292E-6 * _rtB -> k4to1xm133 ;
_rtB -> no30ksdhnl = muDoubleScalarSign ( _rtB -> omlxqlcycc ) ; _rtB ->
mrgd4t1dl2 = muDoubleScalarAbs ( _rtB -> omlxqlcycc ) ; _rtB -> ovnnekij1i =
1.093 * _rtB -> mrgd4t1dl2 ; _rtB -> iwrextofmy = 1.0464 * _rtB -> nkppx0xvpt
; { uint32_T iLeftU0 , iRghtU0 , iLeftU1 , iRghtU1 ;
HEV_acc_BINARYSEARCH_real_T ( & ( iLeftU0 ) , & ( iRghtU0 ) , _rtB ->
ovnnekij1i , ni220kbneq . c4qvyaa1p5 , 108U ) ; if ( _rtB -> iwrextofmy <=
0.0 ) { iLeftU1 = 0U ; iRghtU1 = 0U ; } else if ( _rtB -> iwrextofmy >=
6000.0 ) { iLeftU1 = 100U ; iRghtU1 = 100U ; } else { iLeftU1 = ( uint32_T )
( ( _rtB -> iwrextofmy ) / 60.0 ) ; iRghtU1 = iLeftU1 + 1 ; } { real_T yTemp
; real_T u1Lambda ; real_T u0Lambda ; if ( iLeftU1 != iRghtU1 ) { { real_T
num = ( real_T ) ( _rtB -> iwrextofmy ) - ( iLeftU1 * 60.0 ) ; u1Lambda = num
/ 60.0 ; } } else { u1Lambda = 0.0 ; } if ( ( ni220kbneq . c4qvyaa1p5 [
iRghtU0 ] ) > ( ni220kbneq . c4qvyaa1p5 [ iLeftU0 ] ) ) { real_T num ; real_T
den ; den = ( ni220kbneq . c4qvyaa1p5 [ iRghtU0 ] ) ; den -= ( ni220kbneq .
c4qvyaa1p5 [ iLeftU0 ] ) ; num = _rtB -> ovnnekij1i ; num -= ( ni220kbneq .
c4qvyaa1p5 [ iLeftU0 ] ) ; u0Lambda = num / den ; } else { u0Lambda = 0.0 ; }
{ real_T yLeftCast ; real_T yRghtCast ; yLeftCast = ( ni220kbneq . nt40menwhi
[ ( iLeftU0 + 109U * iLeftU1 ) ] ) ; yRghtCast = ( ni220kbneq . nt40menwhi [
( iLeftU0 + 109U * iRghtU1 ) ] ) ; yLeftCast += u1Lambda * ( yRghtCast -
yLeftCast ) ; h0odp1zuuc = yLeftCast ; } { real_T yLeftCast ; real_T
yRghtCast ; yLeftCast = ( ni220kbneq . nt40menwhi [ ( iRghtU0 + 109U *
iLeftU1 ) ] ) ; yRghtCast = ( ni220kbneq . nt40menwhi [ ( iRghtU0 + 109U *
iRghtU1 ) ] ) ; yLeftCast += u1Lambda * ( yRghtCast - yLeftCast ) ; yTemp =
yLeftCast ; } { real_T yLeftCast ; real_T yRghtCast ; yLeftCast = h0odp1zuuc
; yRghtCast = yTemp ; yLeftCast += u0Lambda * ( yRghtCast - yLeftCast ) ;
h0odp1zuuc = yLeftCast ; } } } _rtB -> g0vkse2qfg = 1.0351048413332149 *
h0odp1zuuc ; _rtB -> hxadglq3xh = _rtB -> no30ksdhnl * _rtB -> g0vkse2qfg ;
_rtB -> i0lco4wxpv = _rtB -> hxadglq3xh * _rtB -> ez0k5qiuda ; _rtB ->
bp133fzcvu = 1.933764640184292E-6 * _rtB -> i0lco4wxpv ; _rtB -> i5qedqtijb =
_rtB -> kv1dmerllk * _rtB -> omlxqlcycc ; if ( _rtB -> fthsjka0i4 <= 0.02 ) {
_rtB -> hmwdmzk40y = 0.02 ; } else { _rtB -> hmwdmzk40y = _rtB -> fthsjka0i4
; } _rtB -> mpljjbwraa = ( ( 0.0 - _rtB -> bp133fzcvu ) - _rtB -> ova4xpfsrf
) - _rtB -> i5qedqtijb ; _rtB -> f1xm14z5cb = 1.0 / _rtB -> hmwdmzk40y * _rtB
-> mpljjbwraa ; _rtB -> cqc2hgl25l = _rtB -> hl3k0hismi + _rtB -> hfesoiedao
; _rtB -> mfch030lrq = ( _rtB -> cqc2hgl25l - _rtB -> kbm252qyu0 ) -
ld5zvvrfqt ( S ) -> elrm5be5m3 ; _rtB -> c0auiltlw3 = 0.00075471698113207543
* _rtB -> mfch030lrq ; _rtB -> nx4umwzhu5 = muDoubleScalarAbs ( _rtB ->
pnrvucucvi ) ; if ( ( _rtDW -> cgi523usaj >= ssGetT ( S ) ) && ( _rtDW ->
irt5havirw >= ssGetT ( S ) ) ) { _rtB -> kxigav0k1b = 0.0 ; } else {
pzh42py0bn = _rtDW -> cgi523usaj ; lastU = & _rtDW -> edrzze2flm ; if ( _rtDW
-> cgi523usaj < _rtDW -> irt5havirw ) { if ( _rtDW -> irt5havirw < ssGetT ( S
) ) { pzh42py0bn = _rtDW -> irt5havirw ; lastU = & _rtDW -> gljjadsfzv ; } }
else { if ( _rtDW -> cgi523usaj >= ssGetT ( S ) ) { pzh42py0bn = _rtDW ->
irt5havirw ; lastU = & _rtDW -> gljjadsfzv ; } } _rtB -> kxigav0k1b = ( _rtB
-> nbdjvo1uig - * lastU ) / ( ssGetT ( S ) - pzh42py0bn ) ; } _rtB ->
m2cgcpwzn2 = muDoubleScalarAbs ( _rtB -> gljz133asp ) ; _rtB -> erxdmthkjx =
1.093 * _rtB -> m2cgcpwzn2 ; _rtB -> ldc5qc2nhb = 1.0464 * _rtB -> nbdjvo1uig
; { uint32_T iLeftU0 , iRghtU0 , iLeftU1 , iRghtU1 ;
HEV_acc_BINARYSEARCH_real_T ( & ( iLeftU0 ) , & ( iRghtU0 ) , _rtB ->
erxdmthkjx , ni220kbneq . c4qvyaa1p5 , 108U ) ; if ( _rtB -> ldc5qc2nhb <=
0.0 ) { iLeftU1 = 0U ; iRghtU1 = 0U ; } else if ( _rtB -> ldc5qc2nhb >=
6000.0 ) { iLeftU1 = 100U ; iRghtU1 = 100U ; } else { iLeftU1 = ( uint32_T )
( ( _rtB -> ldc5qc2nhb ) / 60.0 ) ; iRghtU1 = iLeftU1 + 1 ; } { real_T yTemp
; real_T u1Lambda ; real_T u0Lambda ; if ( iLeftU1 != iRghtU1 ) { { real_T
num = ( real_T ) ( _rtB -> ldc5qc2nhb ) - ( iLeftU1 * 60.0 ) ; u1Lambda = num
/ 60.0 ; } } else { u1Lambda = 0.0 ; } if ( ( ni220kbneq . c4qvyaa1p5 [
iRghtU0 ] ) > ( ni220kbneq . c4qvyaa1p5 [ iLeftU0 ] ) ) { real_T num ; real_T
den ; den = ( ni220kbneq . c4qvyaa1p5 [ iRghtU0 ] ) ; den -= ( ni220kbneq .
c4qvyaa1p5 [ iLeftU0 ] ) ; num = _rtB -> erxdmthkjx ; num -= ( ni220kbneq .
c4qvyaa1p5 [ iLeftU0 ] ) ; u0Lambda = num / den ; } else { u0Lambda = 0.0 ; }
{ real_T yLeftCast ; real_T yRghtCast ; yLeftCast = ( ni220kbneq . ndhdp2vfck
[ ( iLeftU0 + 109U * iLeftU1 ) ] ) ; yRghtCast = ( ni220kbneq . ndhdp2vfck [
( iLeftU0 + 109U * iRghtU1 ) ] ) ; yLeftCast += u1Lambda * ( yRghtCast -
yLeftCast ) ; gddgqjszw2 = yLeftCast ; } { real_T yLeftCast ; real_T
yRghtCast ; yLeftCast = ( ni220kbneq . ndhdp2vfck [ ( iRghtU0 + 109U *
iLeftU1 ) ] ) ; yRghtCast = ( ni220kbneq . ndhdp2vfck [ ( iRghtU0 + 109U *
iRghtU1 ) ] ) ; yLeftCast += u1Lambda * ( yRghtCast - yLeftCast ) ; yTemp =
yLeftCast ; } { real_T yLeftCast ; real_T yRghtCast ; yLeftCast = gddgqjszw2
; yRghtCast = yTemp ; yLeftCast += u0Lambda * ( yRghtCast - yLeftCast ) ;
gddgqjszw2 = yLeftCast ; } } } _rtB -> ivg2yc5ylu = 1.0351048413332149 *
gddgqjszw2 ; _rtB -> lbd1or0s1d = 1.933764640184292E-6 * _rtB -> ivg2yc5ylu ;
_rtB -> pbvsplgfla = muDoubleScalarSign ( _rtB -> gljz133asp ) ; _rtB ->
avnrbdo02a = muDoubleScalarAbs ( _rtB -> gljz133asp ) ; _rtB -> aq32jo0hmc =
1.093 * _rtB -> avnrbdo02a ; _rtB -> dpk1aw5ifp = 1.0464 * _rtB -> nbdjvo1uig
; { uint32_T iLeftU0 , iRghtU0 , iLeftU1 , iRghtU1 ;
HEV_acc_BINARYSEARCH_real_T ( & ( iLeftU0 ) , & ( iRghtU0 ) , _rtB ->
aq32jo0hmc , ni220kbneq . c4qvyaa1p5 , 108U ) ; if ( _rtB -> dpk1aw5ifp <=
0.0 ) { iLeftU1 = 0U ; iRghtU1 = 0U ; } else if ( _rtB -> dpk1aw5ifp >=
6000.0 ) { iLeftU1 = 100U ; iRghtU1 = 100U ; } else { iLeftU1 = ( uint32_T )
( ( _rtB -> dpk1aw5ifp ) / 60.0 ) ; iRghtU1 = iLeftU1 + 1 ; } { real_T yTemp
; real_T u1Lambda ; real_T u0Lambda ; if ( iLeftU1 != iRghtU1 ) { { real_T
num = ( real_T ) ( _rtB -> dpk1aw5ifp ) - ( iLeftU1 * 60.0 ) ; u1Lambda = num
/ 60.0 ; } } else { u1Lambda = 0.0 ; } if ( ( ni220kbneq . c4qvyaa1p5 [
iRghtU0 ] ) > ( ni220kbneq . c4qvyaa1p5 [ iLeftU0 ] ) ) { real_T num ; real_T
den ; den = ( ni220kbneq . c4qvyaa1p5 [ iRghtU0 ] ) ; den -= ( ni220kbneq .
c4qvyaa1p5 [ iLeftU0 ] ) ; num = _rtB -> aq32jo0hmc ; num -= ( ni220kbneq .
c4qvyaa1p5 [ iLeftU0 ] ) ; u0Lambda = num / den ; } else { u0Lambda = 0.0 ; }
{ real_T yLeftCast ; real_T yRghtCast ; yLeftCast = ( ni220kbneq . nt40menwhi
[ ( iLeftU0 + 109U * iLeftU1 ) ] ) ; yRghtCast = ( ni220kbneq . nt40menwhi [
( iLeftU0 + 109U * iRghtU1 ) ] ) ; yLeftCast += u1Lambda * ( yRghtCast -
yLeftCast ) ; hrplwjajp2 = yLeftCast ; } { real_T yLeftCast ; real_T
yRghtCast ; yLeftCast = ( ni220kbneq . nt40menwhi [ ( iRghtU0 + 109U *
iLeftU1 ) ] ) ; yRghtCast = ( ni220kbneq . nt40menwhi [ ( iRghtU0 + 109U *
iRghtU1 ) ] ) ; yLeftCast += u1Lambda * ( yRghtCast - yLeftCast ) ; yTemp =
yLeftCast ; } { real_T yLeftCast ; real_T yRghtCast ; yLeftCast = hrplwjajp2
; yRghtCast = yTemp ; yLeftCast += u0Lambda * ( yRghtCast - yLeftCast ) ;
hrplwjajp2 = yLeftCast ; } } } _rtB -> hbtrxmcyof = 1.0351048413332149 *
hrplwjajp2 ; _rtB -> ij2wci3q4v = _rtB -> pbvsplgfla * _rtB -> hbtrxmcyof ;
_rtB -> hindp10isy = _rtB -> ij2wci3q4v * _rtB -> kxigav0k1b ; _rtB ->
hbmcgtw3z5 = 1.933764640184292E-6 * _rtB -> hindp10isy ; _rtB -> aokjqpu4cz =
_rtB -> nx4umwzhu5 * _rtB -> gljz133asp ; if ( _rtB -> lbd1or0s1d <= 0.02 ) {
_rtB -> fqm1tdudnc = 0.02 ; } else { _rtB -> fqm1tdudnc = _rtB -> lbd1or0s1d
; } _rtB -> noxzclt1en = ( ( 0.0 - _rtB -> hbmcgtw3z5 ) - _rtB -> cqxeynwevr
) - _rtB -> aokjqpu4cz ; _rtB -> njvfzeif14 = 1.0 / _rtB -> fqm1tdudnc * _rtB
-> noxzclt1en ; ssCallAccelRunBlock ( S , 14 , 898 , SS_CALL_MDL_OUTPUTS ) ;
_rtB -> im3d432cdi = _rtB -> nyjtqlivfc [ 9 ] * _rtB -> k5efrdwui0 [ 2 ] ;
_rtB -> nxhcxqvvez = _rtB -> k5efrdwui0 [ 3 ] * _rtB -> nyjtqlivfc [ 6 ] ;
_rtB -> pbch31g2ba = _rtB -> nyjtqlivfc [ 8 ] * _rtB -> k5efrdwui0 [ 11 ] ;
_rtB -> mlkkky1r0d = _rtB -> nxhcxqvvez + _rtB -> pbch31g2ba ;
ssCallAccelRunBlock ( S , 14 , 946 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 14 , 947 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 14 , 948 , SS_CALL_MDL_OUTPUTS ) ; UNUSED_PARAMETER
( tid ) ; }
#define MDL_UPDATE
static void mdlUpdate ( SimStruct * S , int_T tid ) { real_T * lastU ;
fdj1laa40s * _rtB ; h04hj5x5sk * _rtDW ; _rtDW = ( ( h04hj5x5sk * )
ssGetRootDWork ( S ) ) ; _rtB = ( ( fdj1laa40s * ) _ssGetBlockIO ( S ) ) ; if
( ssIsSampleHit ( S , 2 , 0 ) ) { _rtDW -> epw20ibixm += 6.0E-5 * _rtB ->
krc04vab0s ; _rtDW -> emjtqjwqij += 6.0E-5 * _rtB -> etpk1e5ook ; _rtDW ->
aekc0mbj0y += 6.0E-5 * _rtB -> myzzzhzvyc ; _rtDW -> oi2n4lur1q += 6.0E-5 *
_rtB -> g22pmp223s ; } if ( _rtDW -> cwivfg5ijd == ( rtInf ) ) { _rtDW ->
cwivfg5ijd = ssGetTaskTime ( S , 0 ) ; _rtDW -> kguctqvwvn = _rtB ->
miy4yla1ep ; } else if ( _rtDW -> m1iuzueluk == ( rtInf ) ) { _rtDW ->
m1iuzueluk = ssGetTaskTime ( S , 0 ) ; _rtDW -> bvl1znuobh = _rtB ->
miy4yla1ep ; } else if ( _rtDW -> cwivfg5ijd < _rtDW -> m1iuzueluk ) { _rtDW
-> cwivfg5ijd = ssGetTaskTime ( S , 0 ) ; _rtDW -> kguctqvwvn = _rtB ->
miy4yla1ep ; } else { _rtDW -> m1iuzueluk = ssGetTaskTime ( S , 0 ) ; _rtDW
-> bvl1znuobh = _rtB -> miy4yla1ep ; } if ( ssIsSampleHit ( S , 2 , 0 ) ) {
_rtDW -> f2z5i2ds5e = _rtB -> bena5ymrlb [ 25 ] - - 0.999994000018 * _rtDW ->
f2z5i2ds5e ; } if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtDW -> b50c0wk1dc =
_rtB -> h1pa12vucy ; } if ( ssIsSampleHit ( S , 2 , 0 ) ) { _rtDW ->
o05rwe50bo = 0U ; _rtDW -> pk42w2cjcz += 6.0E-5 * _rtB -> bena5ymrlb [ 25 ] ;
if ( _rtDW -> pk42w2cjcz >= 25200.0 ) { _rtDW -> pk42w2cjcz = 25200.0 ; }
else { if ( _rtDW -> pk42w2cjcz <= rtMinusInf ) { _rtDW -> pk42w2cjcz =
rtMinusInf ; } } if ( _rtB -> orezp335bc > 0.0 ) { _rtDW -> f0fxu4veqt = 1 ;
} else if ( _rtB -> orezp335bc < 0.0 ) { _rtDW -> f0fxu4veqt = - 1 ; } else
if ( _rtB -> orezp335bc == 0.0 ) { _rtDW -> f0fxu4veqt = 0 ; } else { _rtDW
-> f0fxu4veqt = 2 ; } _rtDW -> eaosag5owj += 6.0E-5 * _rtB -> nyjtqlivfc [ 7
] ; _rtDW -> jcugjk0yp0 += 6.0E-5 * _rtB -> gd34fxv5th ; _rtDW -> jly33pdwub
+= 6.0E-5 * _rtB -> bmyhud4u5s ; _rtDW -> fezg0yhyh2 = _rtB -> bena5ymrlb [
19 ] ; _rtDW -> hdqerfit1p [ 0 ] = _rtB -> bena5ymrlb [ 27 ] ; _rtDW ->
hdqerfit1p [ 1 ] = _rtB -> bena5ymrlb [ 28 ] ; _rtDW -> hdqerfit1p [ 2 ] =
_rtB -> bena5ymrlb [ 29 ] ; } if ( _rtDW -> mg242c3vwq == ( rtInf ) ) { _rtDW
-> mg242c3vwq = ssGetTaskTime ( S , 0 ) ; _rtDW -> oiqwpboxgd = _rtB ->
dgozwv1ban ; } else if ( _rtDW -> k1wt3kvmem == ( rtInf ) ) { _rtDW ->
k1wt3kvmem = ssGetTaskTime ( S , 0 ) ; _rtDW -> lzjsh0qxsz = _rtB ->
dgozwv1ban ; } else if ( _rtDW -> mg242c3vwq < _rtDW -> k1wt3kvmem ) { _rtDW
-> mg242c3vwq = ssGetTaskTime ( S , 0 ) ; _rtDW -> oiqwpboxgd = _rtB ->
dgozwv1ban ; } else { _rtDW -> k1wt3kvmem = ssGetTaskTime ( S , 0 ) ; _rtDW
-> lzjsh0qxsz = _rtB -> dgozwv1ban ; } if ( ssIsSampleHit ( S , 2 , 0 ) ) {
_rtDW -> bvad1zjfik = _rtB -> eoylzmm3fo [ 0 ] ; } if ( _rtDW -> hfvh40s0je
== ( rtInf ) ) { _rtDW -> hfvh40s0je = ssGetTaskTime ( S , 0 ) ; _rtDW ->
lidlmlim32 = _rtB -> k13oxnct1p ; } else if ( _rtDW -> f41a3yqptq == ( rtInf
) ) { _rtDW -> f41a3yqptq = ssGetTaskTime ( S , 0 ) ; _rtDW -> aq3qjo4ji4 =
_rtB -> k13oxnct1p ; } else if ( _rtDW -> hfvh40s0je < _rtDW -> f41a3yqptq )
{ _rtDW -> hfvh40s0je = ssGetTaskTime ( S , 0 ) ; _rtDW -> lidlmlim32 = _rtB
-> k13oxnct1p ; } else { _rtDW -> f41a3yqptq = ssGetTaskTime ( S , 0 ) ;
_rtDW -> aq3qjo4ji4 = _rtB -> k13oxnct1p ; } if ( ssIsSampleHit ( S , 1 , 0 )
) { _rtDW -> aln04uuynj = _rtB -> k13oxnct1p ; _rtDW -> nlh5qppt4m = _rtB ->
bsp0cvfp2u ; } if ( ssIsSampleHit ( S , 2 , 0 ) ) { _rtDW -> bro0cn1wmi =
_rtB -> bena5ymrlb [ 22 ] ; _rtDW -> j31s1kcymk [ 0 ] = _rtB -> bena5ymrlb [
34 ] ; _rtDW -> j31s1kcymk [ 1 ] = _rtB -> bena5ymrlb [ 35 ] ; _rtDW ->
j31s1kcymk [ 2 ] = _rtB -> bena5ymrlb [ 36 ] ; } if ( ssIsSampleHit ( S , 3 ,
0 ) ) { _rtDW -> gsr0ogd2xb = _rtB -> i2att01yfi ; } if ( _rtDW -> joiszbfghn
== ( rtInf ) ) { _rtDW -> joiszbfghn = ssGetTaskTime ( S , 0 ) ; _rtDW ->
narm2z4h4g = _rtB -> hrd2ygiqtf ; } else if ( _rtDW -> jlnwqqs23l == ( rtInf
) ) { _rtDW -> jlnwqqs23l = ssGetTaskTime ( S , 0 ) ; _rtDW -> miwjijsda1 =
_rtB -> hrd2ygiqtf ; } else if ( _rtDW -> joiszbfghn < _rtDW -> jlnwqqs23l )
{ _rtDW -> joiszbfghn = ssGetTaskTime ( S , 0 ) ; _rtDW -> narm2z4h4g = _rtB
-> hrd2ygiqtf ; } else { _rtDW -> jlnwqqs23l = ssGetTaskTime ( S , 0 ) ;
_rtDW -> miwjijsda1 = _rtB -> hrd2ygiqtf ; } if ( ssIsSampleHit ( S , 2 , 0 )
) { _rtDW -> kzrq2xyp0f = _rtB -> fztntlcyzw ; _rtDW -> nonllthbl2 = _rtB ->
jg3duubwxq - - 0.94176453358424872 * _rtDW -> nonllthbl2 ; _rtDW ->
kol45dq53x = _rtB -> kjp4rrmaoz - - 0.94176453358424872 * _rtDW -> kol45dq53x
; _rtDW -> fw2k5vojpd = _rtB -> ic2zjwnuef ; _rtDW -> ehaijafsot = _rtB ->
bena5ymrlb [ 19 ] ; _rtDW -> lvw3lta2fy = _rtB -> c33hzky0fu - -
0.94176453358424872 * _rtDW -> lvw3lta2fy ; _rtDW -> c20b4oc1jp = _rtB ->
cglbwixnvl - - 0.94176453358424872 * _rtDW -> c20b4oc1jp ; _rtDW ->
lp13v2ihui = _rtB -> lxcqctajs1 ; _rtDW -> kopxzfb0sb = _rtB -> bena5ymrlb [
22 ] ; _rtDW -> ebwur5qeqq = _rtB -> ffmur2b4md ; ssCallAccelRunBlock ( S ,
14 , 465 , SS_CALL_MDL_UPDATE ) ; } if ( ssIsSampleHit ( S , 3 , 0 ) ) {
_rtDW -> bv5gvrfela = _rtB -> eo1xa4liee ; } if ( ssIsSampleHit ( S , 2 , 0 )
) { _rtDW -> pe31gvq3pv = _rtB -> i2js5l42nk - - 0.98651999976973315 * _rtDW
-> pe31gvq3pv ; _rtDW -> bw5cwo255x = _rtB -> nzkn3wqssh - -
0.98651999976973315 * _rtDW -> bw5cwo255x ; _rtDW -> l2t4rgxmml = _rtB ->
iq5me3ewfy [ 0 ] ; } if ( ssIsSampleHit ( S , 2 , 0 ) ) { _rtDW -> dy4ppyw4mo
= _rtB -> pj1lluvq0w - - 0.98651999976973315 * _rtDW -> dy4ppyw4mo ; _rtDW ->
hmybg5b1mi = _rtB -> kabhe5eb4z - - 0.98651999976973315 * _rtDW -> hmybg5b1mi
; _rtDW -> gkq12xkctn = _rtB -> iemvl1x4dw [ 0 ] ; _rtDW -> llu3sg1ihp = 0U ;
_rtDW -> fj2gixcnhk = 3.0E-5 * _rtB -> ik1e2l0kyc + _rtB -> lelyjdafhy ; if (
_rtDW -> fj2gixcnhk >= 1.0 ) { _rtDW -> fj2gixcnhk = 1.0 ; } else { if (
_rtDW -> fj2gixcnhk <= - 1.0 ) { _rtDW -> fj2gixcnhk = - 1.0 ; } } _rtDW ->
dco4afubi3 = _rtB -> giqpga4mf1 ; } if ( _rtDW -> en15lu4hm1 == ( rtInf ) ) {
_rtDW -> en15lu4hm1 = ssGetT ( S ) ; lastU = & _rtDW -> aa3vndu55f ; } else
if ( _rtDW -> km4yirabra == ( rtInf ) ) { _rtDW -> km4yirabra = ssGetT ( S )
; lastU = & _rtDW -> ke4dqjfdz3 ; } else if ( _rtDW -> en15lu4hm1 < _rtDW ->
km4yirabra ) { _rtDW -> en15lu4hm1 = ssGetT ( S ) ; lastU = & _rtDW ->
aa3vndu55f ; } else { _rtDW -> km4yirabra = ssGetT ( S ) ; lastU = & _rtDW ->
ke4dqjfdz3 ; } * lastU = _rtB -> nkppx0xvpt ; if ( _rtDW -> cgi523usaj == (
rtInf ) ) { _rtDW -> cgi523usaj = ssGetT ( S ) ; lastU = & _rtDW ->
edrzze2flm ; } else if ( _rtDW -> irt5havirw == ( rtInf ) ) { _rtDW ->
irt5havirw = ssGetT ( S ) ; lastU = & _rtDW -> gljjadsfzv ; } else if ( _rtDW
-> cgi523usaj < _rtDW -> irt5havirw ) { _rtDW -> cgi523usaj = ssGetT ( S ) ;
lastU = & _rtDW -> edrzze2flm ; } else { _rtDW -> irt5havirw = ssGetT ( S ) ;
lastU = & _rtDW -> gljjadsfzv ; } * lastU = _rtB -> nbdjvo1uig ;
UNUSED_PARAMETER ( tid ) ; }
#define MDL_DERIVATIVES
static void mdlDerivatives ( SimStruct * S ) { fdj1laa40s * _rtB ; hgl3elxkcb
* _rtX ; aab5tqo4s5 * _rtXdot ; h04hj5x5sk * _rtDW ; _rtDW = ( ( h04hj5x5sk *
) ssGetRootDWork ( S ) ) ; _rtXdot = ( ( aab5tqo4s5 * ) ssGetdX ( S ) ) ;
_rtX = ( ( hgl3elxkcb * ) ssGetContStates ( S ) ) ; _rtB = ( ( fdj1laa40s * )
_ssGetBlockIO ( S ) ) ; _rtXdot -> mh2wvbi24o = _rtB -> bjy3ivl32q ;
ssCallAccelRunBlock ( S , 14 , 30 , SS_CALL_MDL_DERIVATIVES ) ; _rtXdot ->
nlkba1lokv = _rtB -> mwaxumfq5f ; _rtXdot -> eackaa2e5o = _rtB -> njvfzeif14
; _rtXdot -> a3p154yttn = _rtB -> c0auiltlw3 ; _rtXdot -> lvhb24m1u3 [ 0 ] =
0.0 ; _rtXdot -> lvhb24m1u3 [ 1 ] = 0.0 ; _rtXdot -> lvhb24m1u3 [ 0 ] += -
20.106192982974676 * _rtX -> lvhb24m1u3 [ 0 ] ; _rtXdot -> lvhb24m1u3 [ 0 ]
+= - 157.91367041742973 * _rtX -> lvhb24m1u3 [ 1 ] ; _rtXdot -> lvhb24m1u3 [
1 ] += _rtX -> lvhb24m1u3 [ 0 ] ; _rtXdot -> lvhb24m1u3 [ 0 ] += _rtB ->
mfch030lrq ; _rtXdot -> oiuvfykmtf = _rtB -> f1xm14z5cb ; _rtXdot ->
ix50zu3rlz = 0.0 ; _rtXdot -> ix50zu3rlz += - 125.66370614359172 * _rtX ->
ix50zu3rlz ; _rtXdot -> ix50zu3rlz += _rtB -> fscboqgb2j ; { boolean_T lsat ;
boolean_T usat ; lsat = ( ( ( hgl3elxkcb * ) ssGetContStates ( S ) ) ->
f0udlm3lxk <= ( - 5.0 ) ) ; usat = ( ( ( hgl3elxkcb * ) ssGetContStates ( S )
) -> f0udlm3lxk >= 5.0 ) ; if ( ( ! lsat && ! usat ) || ( lsat && ( _rtB ->
kykxtw0osp > 0 ) ) || ( usat && ( _rtB -> kykxtw0osp < 0 ) ) ) { ( (
aab5tqo4s5 * ) ssGetdX ( S ) ) -> f0udlm3lxk = _rtB -> kykxtw0osp ; } else {
( ( aab5tqo4s5 * ) ssGetdX ( S ) ) -> f0udlm3lxk = 0.0 ; } } _rtXdot ->
bjc4xqhn0t = _rtB -> o2yvheac2c ; _rtXdot -> pi4mr5hhgl = _rtB -> b042adv2bo
; }
#define MDL_PROJECTION
static void mdlProjection ( SimStruct * S ) { fdj1laa40s * _rtB ; h04hj5x5sk
* _rtDW ; _rtDW = ( ( h04hj5x5sk * ) ssGetRootDWork ( S ) ) ; _rtB = ( (
fdj1laa40s * ) _ssGetBlockIO ( S ) ) ; ssCallAccelRunBlock ( S , 14 , 30 ,
SS_CALL_MDL_PROJECTION ) ; } static void mdlInitializeSizes ( SimStruct * S )
{ ssSetChecksumVal ( S , 0 , 3384118637U ) ; ssSetChecksumVal ( S , 1 ,
348184140U ) ; ssSetChecksumVal ( S , 2 , 4280463097U ) ; ssSetChecksumVal (
S , 3 , 60013099U ) ; { mxArray * slVerStructMat = NULL ; mxArray * slStrMat
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
ld5zvvrfqt ( S ) -> dd2ctcdkt5 = rtNaN ; ld5zvvrfqt ( S ) -> orazfd4jlf =
rtNaN ; ld5zvvrfqt ( S ) -> o2qe4dvjgj = rtNaN ; ld5zvvrfqt ( S ) ->
o0u3wry1y0 = rtNaN ; } static void mdlInitializeSampleTimes ( SimStruct * S )
{ { SimStruct * childS ; SysOutputFcn * callSysFcns ; childS = ssGetSFunction
( S , 0 ) ; callSysFcns = ssGetCallSystemOutputFcnList ( childS ) ;
callSysFcns [ 3 + 0 ] = ( SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction (
S , 1 ) ; callSysFcns = ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns
[ 3 + 0 ] = ( SysOutputFcn ) ( NULL ) ; } } static void mdlTerminate (
SimStruct * S ) { }
#include "simulink.c"
