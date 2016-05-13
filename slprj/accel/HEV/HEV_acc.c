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
, int_T tid ) { real_T bf4leg14dv ; real_T iodspovcct ; real_T bqcgob22yd ;
real_T ddaxqpoc0f ; real_T cz11sb51me ; real_T ma5zkm3ak0 ; real_T d0xxkzbvri
; real_T p5ngqu1lob ; real_T i3fummpa1c ; real_T hiyz3mxgea ; boolean_T
m11fddtsiw ; int32_T rowIdx ; real_T * lastU ; boolean_T pbnk0frrk0 ; uint8_T
mjvuadvsvc ; real_T i5nu34w4uj ; real_T dztyrqu4xa ; real_T eskeehll14 ;
real_T jwhz1ujp3w ; real_T ehtkh2wauy ; real_T mkcfwi2fsi ; real_T ehcygfucdl
; real_T po0ockmy2b ; real_T mizlp41tvx ; real_T f4ufgq33gz ; real_T
ckrl0nmlwt ; real_T lduwq00gqj ; real_T byehzqrbel ; real_T awwg3xagjh ;
real_T aqlslovppe ; real_T dyfxp2slod ; real_T dk4tk42hhp ; real_T ctpq3axefx
; real_T f1b5simhxh ; real_T mqc0yqbsjn ; real_T lstej3qx0u ; real_T
j0bnh13vos ; real_T pzh42py0bn ; real_T dwqqadjaqz_idx_0 ; real_T
dwqqadjaqz_idx_1 ; real_T dwqqadjaqz_idx_2 ; ZCEventType zcEvent_idx_0 ;
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
SS_CALL_MDL_OUTPUTS ) ; _rtB -> bjy3ivl32q = _rtB -> nyjtqlivfc [ 13 ] - _rtB
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
bdttfjoqre ; if ( ssIsSampleHit ( S , 2 , 0 ) ) { _rtB -> gtbq2mrvsz = _rtDW
-> aekc0mbj0y ; _rtB -> m20ugbt2wz = _rtDW -> oi2n4lur1q ; _rtB -> fdvi4m0ynh
= ( 0.0 * _rtB -> gtbq2mrvsz * _rtB -> m20ugbt2wz + 0.192 * _rtB ->
gtbq2mrvsz ) * 1.5 ; } _rtB -> kaepwkonay = _rtX -> nlkba1lokv ; _rtB ->
iq45nri2y5 = _rtB -> kaepwkonay - ld5zvvrfqt ( S ) -> k1wq0o5e0g ; _rtB ->
fz2xgdbli4 = 0.0 * _rtB -> iq45nri2y5 ; _rtB -> gbtqehk21l = _rtB ->
iq45nri2y5 * ( real_T ) ld5zvvrfqt ( S ) -> ffhvwdskxk ; pbnk0frrk0 = ( _rtB
-> gbtqehk21l >= ld5zvvrfqt ( S ) -> nqudwn5obz ) ; _rtB -> gpoqd34dsh = _rtB
-> fz2xgdbli4 * ( real_T ) pbnk0frrk0 ; _rtB -> m3usbwf51h = _rtB ->
nyjtqlivfc [ 4 ] - _rtB -> nyjtqlivfc [ 7 ] ; _rtB -> crzu3ycdzu = 0.1 * _rtB
-> m3usbwf51h ; _rtB -> nqhnonebgj = ( real_T ) pbnk0frrk0 * _rtB ->
crzu3ycdzu ; _rtB -> fcsir4s5cn = ( 0.0 - _rtB -> gpoqd34dsh ) - _rtB ->
nqhnonebgj ; _rtB -> fwjn3q522r = _rtB -> kaepwkonay + ld5zvvrfqt ( S ) ->
lktpzwjh2v ; _rtB -> kys23i0abs = 0.0 * _rtB -> fwjn3q522r ; _rtB ->
ep1h1qrjkl = _rtB -> fwjn3q522r * ( real_T ) ld5zvvrfqt ( S ) -> fyjyz2m3fp ;
pbnk0frrk0 = ( _rtB -> ep1h1qrjkl <= ld5zvvrfqt ( S ) -> dtdqsewo41 ) ; _rtB
-> h50vef3zq5 = _rtB -> kys23i0abs * ( real_T ) pbnk0frrk0 ; _rtB ->
kfaov1eemp = 0.1 * _rtB -> m3usbwf51h ; _rtB -> i0osm33yqe = ( real_T )
pbnk0frrk0 * _rtB -> kfaov1eemp ; _rtB -> h4pcnnfyvp = ( 0.0 - _rtB ->
h50vef3zq5 ) - _rtB -> i0osm33yqe ; _rtB -> pp5olsieh5 = _rtB -> h4pcnnfyvp *
( real_T ) ld5zvvrfqt ( S ) -> ndgrxthyjh ; _rtB -> fcpkr3ms2q = ( 0.0 - _rtB
-> fcsir4s5cn ) - _rtB -> pp5olsieh5 ; _rtB -> mfi2ojpm25 = - _rtB ->
fcpkr3ms2q ; _rtB -> fd3rap22fd = _rtX -> eackaa2e5o ; _rtB -> pvtml134dd =
_rtX -> a3p154yttn ; _rtB -> nkahzrsddv = muDoubleScalarAbs ( _rtB ->
pvtml134dd ) ; _rtB -> ohlinyugs3 = ( ld5zvvrfqt ( S ) -> nubbj1xg3a > _rtB
-> nkahzrsddv ) ; _rtB -> eq0wjrul5m = 0.4 * _rtB -> nkahzrsddv ; _rtB ->
ptfuqsi4ah = 3.1415926535897931 * _rtB -> eq0wjrul5m ; _rtB -> i3rrvejisz = (
muDoubleScalarCos ( _rtB -> ptfuqsi4ah ) + 1.0 ) * 770.0 ; _rtB -> jpe0ocjwhw
= 0.5 * _rtB -> i3rrvejisz ; _rtB -> h3rvxx5bgj = 9.6688232009214591E-6 *
_rtB -> jpe0ocjwhw ; _rtB -> mmbf4fdchi = 0.3 * _rtB -> nyjtqlivfc [ 5 ] ;
_rtB -> d2ln0pkwig = _rtB -> pvtml134dd - _rtB -> mmbf4fdchi ; _rtB ->
koa5diek1c = _rtB -> ohlinyugs3 * _rtB -> h3rvxx5bgj * _rtB -> d2ln0pkwig ;
_rtB -> dscdnbpbk0 = _rtB -> fd3rap22fd - _rtB -> koa5diek1c ; _rtB ->
dmwgincjop = muDoubleScalarSign ( _rtB -> dscdnbpbk0 ) ; _rtB -> d40dtkffg5 =
muDoubleScalarAbs ( _rtB -> dscdnbpbk0 ) ; _rtB -> nbjjk53lvu = 1.093 * _rtB
-> d40dtkffg5 ; _rtB -> pfiqcu2uh2 = 0.0 ; _rtB -> pfiqcu2uh2 += 0.0 * _rtX
-> lvhb24m1u3 [ 0 ] ; _rtB -> pfiqcu2uh2 += 157.91367041742973 * _rtX ->
lvhb24m1u3 [ 1 ] ; _rtB -> emcp5ogyze = muDoubleScalarSign ( _rtB ->
pvtml134dd ) ; _rtB -> ixviqbzhri = _rtB -> pvtml134dd * _rtB -> pvtml134dd *
_rtB -> emcp5ogyze ; _rtB -> i4oz5rc0vc = 0.5 * _rtB -> ixviqbzhri ; _rtB ->
by0ahmlkqx = 1.2 * _rtB -> i4oz5rc0vc ; _rtB -> hkh4rhdmg3 = 0.26 * _rtB ->
by0ahmlkqx ; _rtB -> aycqigbrea = 2.57 * _rtB -> hkh4rhdmg3 ; _rtB ->
ffknrz0tau = ( ( 0.0 - ld5zvvrfqt ( S ) -> bk0wxmqie1 ) - _rtB -> pfiqcu2uh2
) - _rtB -> aycqigbrea ; _rtB -> gcc4nmnh41 = 0.18518518518518517 * _rtB ->
ffknrz0tau ; _rtB -> mlk1pjfolt = ( ld5zvvrfqt ( S ) -> lgdgr5cdww - _rtB ->
gcc4nmnh41 ) + ld5zvvrfqt ( S ) -> jirogj2213 ; if ( _rtB -> mlk1pjfolt <=
0.0 ) { _rtB -> floa0n1bxy = 0.0 ; } else { _rtB -> floa0n1bxy = _rtB ->
mlk1pjfolt ; } _rtB -> opg5ig3e0e = 1.0464 * _rtB -> floa0n1bxy ; { uint32_T
iLeftU0 , iRghtU0 , iLeftU1 , iRghtU1 ; HEV_acc_BINARYSEARCH_real_T ( & (
iLeftU0 ) , & ( iRghtU0 ) , _rtB -> nbjjk53lvu , ni220kbneq . c4qvyaa1p5 ,
108U ) ; if ( _rtB -> opg5ig3e0e <= 0.0 ) { iLeftU1 = 0U ; iRghtU1 = 0U ; }
else if ( _rtB -> opg5ig3e0e >= 6000.0 ) { iLeftU1 = 100U ; iRghtU1 = 100U ;
} else { iLeftU1 = ( uint32_T ) ( ( _rtB -> opg5ig3e0e ) / 60.0 ) ; iRghtU1 =
iLeftU1 + 1 ; } { real_T yTemp ; real_T u1Lambda ; real_T u0Lambda ; if (
iLeftU1 != iRghtU1 ) { { real_T num = ( real_T ) ( _rtB -> opg5ig3e0e ) - (
iLeftU1 * 60.0 ) ; u1Lambda = num / 60.0 ; } } else { u1Lambda = 0.0 ; } if (
( ni220kbneq . c4qvyaa1p5 [ iRghtU0 ] ) > ( ni220kbneq . c4qvyaa1p5 [ iLeftU0
] ) ) { real_T num ; real_T den ; den = ( ni220kbneq . c4qvyaa1p5 [ iRghtU0 ]
) ; den -= ( ni220kbneq . c4qvyaa1p5 [ iLeftU0 ] ) ; num = _rtB -> nbjjk53lvu
; num -= ( ni220kbneq . c4qvyaa1p5 [ iLeftU0 ] ) ; u0Lambda = num / den ; }
else { u0Lambda = 0.0 ; } { real_T yLeftCast ; real_T yRghtCast ; yLeftCast =
( ni220kbneq . mstlffh4xe [ ( iLeftU0 + 109U * iLeftU1 ) ] ) ; yRghtCast = (
ni220kbneq . mstlffh4xe [ ( iLeftU0 + 109U * iRghtU1 ) ] ) ; yLeftCast +=
u1Lambda * ( yRghtCast - yLeftCast ) ; bf4leg14dv = yLeftCast ; } { real_T
yLeftCast ; real_T yRghtCast ; yLeftCast = ( ni220kbneq . mstlffh4xe [ (
iRghtU0 + 109U * iLeftU1 ) ] ) ; yRghtCast = ( ni220kbneq . mstlffh4xe [ (
iRghtU0 + 109U * iRghtU1 ) ] ) ; yLeftCast += u1Lambda * ( yRghtCast -
yLeftCast ) ; yTemp = yLeftCast ; } { real_T yLeftCast ; real_T yRghtCast ;
yLeftCast = bf4leg14dv ; yRghtCast = yTemp ; yLeftCast += u0Lambda * (
yRghtCast - yLeftCast ) ; bf4leg14dv = yLeftCast ; } } } _rtB -> o5cxwrth5o =
1.0351048413332149 * bf4leg14dv ; _rtB -> povcbqqxqx = _rtB -> dmwgincjop *
_rtB -> o5cxwrth5o ; _rtB -> d1xqd1or1h = 0.3 * _rtB -> povcbqqxqx ; _rtB ->
i1toifbhlb = - _rtB -> d1xqd1or1h ; _rtB -> kvbe2ne4jw = _rtX -> oiuvfykmtf ;
_rtB -> oq35tpi5kl = muDoubleScalarAbs ( _rtB -> pvtml134dd ) ; _rtB ->
jrjrerhx4g = ( ld5zvvrfqt ( S ) -> eskxeenpxa > _rtB -> oq35tpi5kl ) ; _rtB
-> ltcqpnov5z = 0.4 * _rtB -> oq35tpi5kl ; _rtB -> pzqwmwpzn5 =
3.1415926535897931 * _rtB -> ltcqpnov5z ; _rtB -> enw2r2ttix = (
muDoubleScalarCos ( _rtB -> pzqwmwpzn5 ) + 1.0 ) * 770.0 ; _rtB -> avulwz4p5u
= 0.5 * _rtB -> enw2r2ttix ; _rtB -> oiwuiywhdv = 9.6688232009214591E-6 *
_rtB -> avulwz4p5u ; _rtB -> azcxqbrobg = 0.3 * _rtB -> nyjtqlivfc [ 6 ] ;
_rtB -> hovbh5g5g4 = _rtB -> pvtml134dd - _rtB -> azcxqbrobg ; _rtB ->
ejdizlwxad = _rtB -> jrjrerhx4g * _rtB -> oiwuiywhdv * _rtB -> hovbh5g5g4 ;
_rtB -> ijqe34mvfk = _rtB -> kvbe2ne4jw - _rtB -> ejdizlwxad ; _rtB ->
lmwiw4jlnb = muDoubleScalarSign ( _rtB -> ijqe34mvfk ) ; _rtB -> f5j4o1pkvd =
muDoubleScalarAbs ( _rtB -> ijqe34mvfk ) ; _rtB -> auzwrfwf2v = 1.093 * _rtB
-> f5j4o1pkvd ; _rtB -> bfhhzbkkye = ( _rtB -> gcc4nmnh41 + ld5zvvrfqt ( S )
-> grhvmzir1l ) + ld5zvvrfqt ( S ) -> p2o5y4jvsw ; if ( _rtB -> bfhhzbkkye <=
0.0 ) { _rtB -> bfsq0zyecv = 0.0 ; } else { _rtB -> bfsq0zyecv = _rtB ->
bfhhzbkkye ; } _rtB -> ija0da2eks = 1.0464 * _rtB -> bfsq0zyecv ; { uint32_T
iLeftU0 , iRghtU0 , iLeftU1 , iRghtU1 ; HEV_acc_BINARYSEARCH_real_T ( & (
iLeftU0 ) , & ( iRghtU0 ) , _rtB -> auzwrfwf2v , ni220kbneq . c4qvyaa1p5 ,
108U ) ; if ( _rtB -> ija0da2eks <= 0.0 ) { iLeftU1 = 0U ; iRghtU1 = 0U ; }
else if ( _rtB -> ija0da2eks >= 6000.0 ) { iLeftU1 = 100U ; iRghtU1 = 100U ;
} else { iLeftU1 = ( uint32_T ) ( ( _rtB -> ija0da2eks ) / 60.0 ) ; iRghtU1 =
iLeftU1 + 1 ; } { real_T yTemp ; real_T u1Lambda ; real_T u0Lambda ; if (
iLeftU1 != iRghtU1 ) { { real_T num = ( real_T ) ( _rtB -> ija0da2eks ) - (
iLeftU1 * 60.0 ) ; u1Lambda = num / 60.0 ; } } else { u1Lambda = 0.0 ; } if (
( ni220kbneq . c4qvyaa1p5 [ iRghtU0 ] ) > ( ni220kbneq . c4qvyaa1p5 [ iLeftU0
] ) ) { real_T num ; real_T den ; den = ( ni220kbneq . c4qvyaa1p5 [ iRghtU0 ]
) ; den -= ( ni220kbneq . c4qvyaa1p5 [ iLeftU0 ] ) ; num = _rtB -> auzwrfwf2v
; num -= ( ni220kbneq . c4qvyaa1p5 [ iLeftU0 ] ) ; u0Lambda = num / den ; }
else { u0Lambda = 0.0 ; } { real_T yLeftCast ; real_T yRghtCast ; yLeftCast =
( ni220kbneq . mstlffh4xe [ ( iLeftU0 + 109U * iLeftU1 ) ] ) ; yRghtCast = (
ni220kbneq . mstlffh4xe [ ( iLeftU0 + 109U * iRghtU1 ) ] ) ; yLeftCast +=
u1Lambda * ( yRghtCast - yLeftCast ) ; iodspovcct = yLeftCast ; } { real_T
yLeftCast ; real_T yRghtCast ; yLeftCast = ( ni220kbneq . mstlffh4xe [ (
iRghtU0 + 109U * iLeftU1 ) ] ) ; yRghtCast = ( ni220kbneq . mstlffh4xe [ (
iRghtU0 + 109U * iRghtU1 ) ] ) ; yLeftCast += u1Lambda * ( yRghtCast -
yLeftCast ) ; yTemp = yLeftCast ; } { real_T yLeftCast ; real_T yRghtCast ;
yLeftCast = iodspovcct ; yRghtCast = yTemp ; yLeftCast += u0Lambda * (
yRghtCast - yLeftCast ) ; iodspovcct = yLeftCast ; } } } _rtB -> atzddikxnz =
1.0351048413332149 * iodspovcct ; _rtB -> fizzwskkmv = _rtB -> lmwiw4jlnb *
_rtB -> atzddikxnz ; _rtB -> f1qkafmq3b = 0.3 * _rtB -> fizzwskkmv ; _rtB ->
guobmqwinv = - _rtB -> f1qkafmq3b ; if ( ssIsSampleHit ( S , 2 , 0 ) ) { _rtB
-> afxvvza3cb = _rtDW -> epw20ibixm ; _rtB -> faas3afdpe = _rtDW ->
emjtqjwqij ; _rtB -> hjpsmgfyh0 = ( - 0.00045907990073600015 * _rtB ->
afxvvza3cb * _rtB -> faas3afdpe + 0.175666143629361 * _rtB -> afxvvza3cb ) *
6.0 ; } mjvuadvsvc = ( uint8_T ) ( _rtB -> nyjtqlivfc [ 11 ] > ld5zvvrfqt ( S
) -> echc312qll ) ; if ( _rtB -> nyjtqlivfc [ 8 ] <= 0.0 ) { _rtB ->
pog4s1u1rz = 0.0 ; } else { _rtB -> pog4s1u1rz = _rtB -> nyjtqlivfc [ 8 ] ; }
_rtB -> gwin5i00rc = muDoubleScalarAbs ( _rtB -> pog4s1u1rz ) ;
HEV_acc_LookUp_real_T_real_T ( & ( bqcgob22yd ) , ni220kbneq . eizjdjflni ,
_rtB -> gwin5i00rc , ni220kbneq . c3doh0dipz , 6U ) ; ssCallAccelRunBlock ( S
, 14 , 174 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> chplveqgj1 = 0.0 ; _rtB ->
chplveqgj1 += 125.66370614359172 * _rtX -> ix50zu3rlz ; _rtB -> h3dgin415e =
_rtB -> gtajl4byik - _rtB -> chplveqgj1 ; _rtB -> jygl0z2gar = 0.02 * _rtB ->
h3dgin415e ; if ( ( ( hgl3elxkcb * ) ssGetContStates ( S ) ) -> f0udlm3lxk >=
5.0 ) { if ( ( ( hgl3elxkcb * ) ssGetContStates ( S ) ) -> f0udlm3lxk != 5.0
) { ( ( hgl3elxkcb * ) ssGetContStates ( S ) ) -> f0udlm3lxk = 5.0 ;
ssSetSolverNeedsReset ( S ) ; } } else if ( ( ( hgl3elxkcb * )
ssGetContStates ( S ) ) -> f0udlm3lxk <= ( - 5.0 ) ) { if ( ( ( hgl3elxkcb *
) ssGetContStates ( S ) ) -> f0udlm3lxk != ( - 5.0 ) ) { ( ( hgl3elxkcb * )
ssGetContStates ( S ) ) -> f0udlm3lxk = ( - 5.0 ) ; ssSetSolverNeedsReset ( S
) ; } } _rtB -> kofwjf1jj2 = ( ( hgl3elxkcb * ) ssGetContStates ( S ) ) ->
f0udlm3lxk ; _rtB -> nxksmvwfc3 = _rtB -> jygl0z2gar + _rtB -> kofwjf1jj2 ;
if ( _rtB -> nxksmvwfc3 > 1.0 ) { _rtB -> nykcfw13ui = 1.0 ; } else if ( _rtB
-> nxksmvwfc3 < - 1.0 ) { _rtB -> nykcfw13ui = - 1.0 ; } else { _rtB ->
nykcfw13ui = _rtB -> nxksmvwfc3 ; } if ( ( _rtDW -> cwivfg5ijd >=
ssGetTaskTime ( S , 0 ) ) && ( _rtDW -> m1iuzueluk >= ssGetTaskTime ( S , 0 )
) ) { _rtB -> dwu21sloy4 = _rtB -> nykcfw13ui ; } else { if ( ( ( _rtDW ->
cwivfg5ijd < _rtDW -> m1iuzueluk ) && ( _rtDW -> m1iuzueluk < ssGetTaskTime (
S , 0 ) ) ) || ( ( _rtDW -> cwivfg5ijd >= _rtDW -> m1iuzueluk ) && ( _rtDW ->
cwivfg5ijd >= ssGetTaskTime ( S , 0 ) ) ) ) { pzh42py0bn = ssGetTaskTime ( S
, 0 ) - _rtDW -> m1iuzueluk ; mqc0yqbsjn = _rtDW -> bvl1znuobh ; } else {
pzh42py0bn = ssGetTaskTime ( S , 0 ) - _rtDW -> cwivfg5ijd ; mqc0yqbsjn =
_rtDW -> kguctqvwvn ; } lstej3qx0u = _rtB -> nykcfw13ui - mqc0yqbsjn ; if (
lstej3qx0u > pzh42py0bn ) { _rtB -> dwu21sloy4 = mqc0yqbsjn + pzh42py0bn ; }
else { pzh42py0bn = - pzh42py0bn ; if ( lstej3qx0u < pzh42py0bn ) { _rtB ->
dwu21sloy4 = mqc0yqbsjn + pzh42py0bn ; } else { _rtB -> dwu21sloy4 = _rtB ->
nykcfw13ui ; } } } _rtB -> cfwkcd20fv = 400.0 * _rtB -> dwu21sloy4 ; if (
_rtB -> cfwkcd20fv > bqcgob22yd ) { _rtB -> o1s22oao2o = bqcgob22yd ; } else
{ _rtB -> cp1bwxtyzb = - bqcgob22yd ; if ( _rtB -> cfwkcd20fv < _rtB ->
cp1bwxtyzb ) { _rtB -> koiypnnkvf = _rtB -> cp1bwxtyzb ; } else { _rtB ->
koiypnnkvf = _rtB -> cfwkcd20fv ; } _rtB -> o1s22oao2o = _rtB -> koiypnnkvf ;
} i3fummpa1c = ssGetT ( S ) ; _rtB -> akftt1xsd1 = ( real_T ) ( i3fummpa1c >
ld5zvvrfqt ( S ) -> pd5ogdk4uw ) * _rtB -> o1s22oao2o ; if ( ssIsSampleHit (
S , 2 , 0 ) ) { i5nu34w4uj = 5.9999820000156134E-6 * _rtDW -> f2z5i2ds5e ;
_rtB -> g2ykehf41g = ( i5nu34w4uj > ld5zvvrfqt ( S ) -> igihruwrq3 ) ; } if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> owfd5w4uhl = _rtDW -> b50c0wk1dc ; }
if ( ssIsSampleHit ( S , 2 , 0 ) ) { if ( _rtDW -> o05rwe50bo != 0 ) { _rtDW
-> pk42w2cjcz = _rtB -> owfd5w4uhl ; if ( _rtDW -> pk42w2cjcz >= 25200.0 ) {
_rtDW -> pk42w2cjcz = 25200.0 ; } else { if ( _rtDW -> pk42w2cjcz <=
rtMinusInf ) { _rtDW -> pk42w2cjcz = rtMinusInf ; } } } if ( ( _rtB ->
g2ykehf41g > 0.0 ) && ( _rtDW -> f0fxu4veqt <= 0 ) ) { _rtDW -> pk42w2cjcz =
_rtB -> owfd5w4uhl ; if ( _rtDW -> pk42w2cjcz >= 25200.0 ) { _rtDW ->
pk42w2cjcz = 25200.0 ; } else { if ( _rtDW -> pk42w2cjcz <= rtMinusInf ) {
_rtDW -> pk42w2cjcz = rtMinusInf ; } } } if ( _rtDW -> pk42w2cjcz >= 25200.0
) { _rtDW -> pk42w2cjcz = 25200.0 ; } else { if ( _rtDW -> pk42w2cjcz <=
rtMinusInf ) { _rtDW -> pk42w2cjcz = rtMinusInf ; } } dztyrqu4xa =
0.00027777777777777778 * _rtDW -> pk42w2cjcz ; if ( dztyrqu4xa > 6.9993 ) {
eskeehll14 = 6.9993 ; } else if ( dztyrqu4xa < 0.0 ) { eskeehll14 = 0.0 ; }
else { eskeehll14 = dztyrqu4xa ; } _rtB -> kduw44qano = ( 1.0 - eskeehll14 /
7.0 ) * 100.0 ; } _rtB -> mszfu3re2h = _rtX -> bjc4xqhn0t ; if ( _rtB ->
mszfu3re2h <= 0.0 ) { _rtB -> jcygww153k = 0.0 ; } else { _rtB -> jcygww153k
= _rtB -> mszfu3re2h ; } ssCallAccelRunBlock ( S , 12 , 0 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> f5scsxfwsa = ld5zvvrfqt ( S ) -> nl2iewmuir *
_rtB -> m0m2dtwpv3 ; if ( _rtB -> f5scsxfwsa > 1.0 ) { _rtB -> h02dgdlfzh =
1.0 ; } else if ( _rtB -> f5scsxfwsa < 0.0 ) { _rtB -> h02dgdlfzh = 0.0 ; }
else { _rtB -> h02dgdlfzh = _rtB -> f5scsxfwsa ; } if ( mjvuadvsvc >= 1 ) {
_rtB -> cqe1e3fcou = ld5zvvrfqt ( S ) -> n3kzaalsmz ; } else { if ( _rtB ->
h02dgdlfzh > 1.0 ) { _rtB -> g4bihrba22 = 1.0 ; } else if ( _rtB ->
h02dgdlfzh < 0.0 ) { _rtB -> g4bihrba22 = 0.0 ; } else { _rtB -> g4bihrba22 =
_rtB -> h02dgdlfzh ; } _rtB -> j1xpohusob = 9.5492965855137211 * _rtB ->
nyjtqlivfc [ 11 ] ; _rtB -> d3yajrdw5d = rt_Lookup ( ni220kbneq . jqglboln4v
, 101 , _rtB -> j1xpohusob , ni220kbneq . i2vn1liwwa ) * _rtB -> g4bihrba22 ;
_rtB -> cqe1e3fcou = _rtB -> d3yajrdw5d ; } _rtB -> nomucmtc0o = - _rtB ->
gvbigsazx5 ; _rtB -> hhrascqgm4 [ 0 ] = _rtB -> gvbigsazx5 ; _rtB ->
hhrascqgm4 [ 1 ] = _rtB -> fdvi4m0ynh ; _rtB -> hhrascqgm4 [ 2 ] = _rtB ->
mfi2ojpm25 ; _rtB -> hhrascqgm4 [ 3 ] = _rtB -> i1toifbhlb ; _rtB ->
hhrascqgm4 [ 4 ] = _rtB -> guobmqwinv ; _rtB -> hhrascqgm4 [ 5 ] = _rtB ->
fcpkr3ms2q ; _rtB -> hhrascqgm4 [ 6 ] = _rtB -> hjpsmgfyh0 ; _rtB ->
hhrascqgm4 [ 7 ] = _rtB -> cqe1e3fcou ; _rtB -> hhrascqgm4 [ 8 ] = _rtB ->
nomucmtc0o ; ssCallAccelRunBlock ( S , 14 , 208 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 14 , 209 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 14 , 210 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 14 , 211 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
h0cqr0sona = 9.5492965854826952 * _rtB -> nyjtqlivfc [ 12 ] ; _rtB ->
neiceh2ylu = _rtB -> nyjtqlivfc [ 12 ] * _rtB -> p1o0lcfasn [ 1 ] ;
ssCallAccelRunBlock ( S , 14 , 214 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
h44qns4hga = ! ( mjvuadvsvc != 0 ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) {
ssCallAccelRunBlock ( S , 14 , 216 , SS_CALL_MDL_OUTPUTS ) ; }
ssCallAccelRunBlock ( S , 14 , 222 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
edb1wc4zge = 0.001 * rt_Lookup2D_Normal ( _rtP -> FuelConsTable . speed , 10
, _rtP -> FuelConsTable . torque , 10 , _rtP -> FuelConsTable .
lookupTableFuel , _rtB -> h0cqr0sona , _rtB -> p1o0lcfasn [ 1 ] ) ; _rtB ->
ovkqtquynl = _rtB -> edb1wc4zge / ld5zvvrfqt ( S ) -> cxl3vqpwom ; _rtB ->
kndxnn44r2 = 1000.0 * _rtB -> ovkqtquynl ; _rtB -> a5phvrw1br = 3.6 * _rtB ->
pvtml134dd ; _rtB -> adiysgphhg = 0.0002777777777778 * _rtB -> a5phvrw1br ;
ssCallAccelRunBlock ( S , 14 , 237 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
omuxs3adsn = 0 ; ssCallAccelRunBlock ( S , 14 , 258 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 14 , 259 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 14 , 260 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 14 , 261 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 14 , 262 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 14 , 263 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 14 , 264 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
cflxmahva4 = 0.04 * _rtB -> h3dgin415e ; if ( ssIsSampleHit ( S , 2 , 0 ) ) {
jwhz1ujp3w = _rtDW -> eaosag5owj ; ehtkh2wauy = muDoubleScalarSin ( _rtDW ->
eaosag5owj ) ; mkcfwi2fsi = muDoubleScalarCos ( _rtDW -> eaosag5owj ) ; _rtB
-> dckp4j2qca = _rtB -> gtbq2mrvsz * mkcfwi2fsi + _rtB -> m20ugbt2wz *
ehtkh2wauy ; _rtB -> i1pgvuvzli = ( ( - _rtB -> gtbq2mrvsz -
1.7320508075688772 * _rtB -> m20ugbt2wz ) * mkcfwi2fsi + ( 1.7320508075688772
* _rtB -> gtbq2mrvsz - _rtB -> m20ugbt2wz ) * ehtkh2wauy ) * 0.5 ; ehcygfucdl
= _rtDW -> jcugjk0yp0 ; po0ockmy2b = muDoubleScalarSin ( _rtDW -> jcugjk0yp0
) ; mizlp41tvx = muDoubleScalarCos ( _rtDW -> jcugjk0yp0 ) ; _rtB ->
ohmpdlpzhb = _rtB -> afxvvza3cb * mizlp41tvx + _rtB -> faas3afdpe *
po0ockmy2b ; _rtB -> i0wfdyoglw = ( ( - _rtB -> afxvvza3cb -
1.7320508075688772 * _rtB -> faas3afdpe ) * mizlp41tvx + ( 1.7320508075688772
* _rtB -> afxvvza3cb - _rtB -> faas3afdpe ) * po0ockmy2b ) * 0.5 ; f4ufgq33gz
= _rtDW -> jly33pdwub ; if ( dztyrqu4xa >= 6.9993 ) { dztyrqu4xa = 6.9993 ; }
byehzqrbel = ( ( 7.0 / ( 7.0 - eskeehll14 ) * - 0.23801451555567835 *
eskeehll14 + ( ld5zvvrfqt ( S ) -> cndpwxggrh + _rtDW -> jly33pdwub ) ) + -
_rtB -> g2ykehf41g * 0.23801451555567835 * i5nu34w4uj * ( 7.0 / ( 7.0 -
eskeehll14 ) ) ) + - ( ( real_T ) ( i5nu34w4uj < ld5zvvrfqt ( S ) ->
bpbq4f54cs ) * ld5zvvrfqt ( S ) -> i0hvets2bk ) * 0.23801451555567835 * (
ld5zvvrfqt ( S ) -> i0hvets2bk * i5nu34w4uj ) * ( 7.0 / ( muDoubleScalarAbs (
ld5zvvrfqt ( S ) -> i0hvets2bk * dztyrqu4xa ) + 0.70000000000000007 ) ) ; if
( byehzqrbel > ld5zvvrfqt ( S ) -> cmnkmqkdoy ) { _rtB -> ndekdloslm =
ld5zvvrfqt ( S ) -> cmnkmqkdoy ; } else { pzh42py0bn = 0.30769230769230771 *
i5nu34w4uj ; if ( byehzqrbel < pzh42py0bn ) { _rtB -> ndekdloslm = pzh42py0bn
; } else { _rtB -> ndekdloslm = byehzqrbel ; } } _rtB -> drvrbcfntm = _rtDW
-> fezg0yhyh2 ; dwqqadjaqz_idx_0 = _rtDW -> hdqerfit1p [ 0 ] ;
dwqqadjaqz_idx_1 = _rtDW -> hdqerfit1p [ 1 ] ; dwqqadjaqz_idx_2 = _rtDW ->
hdqerfit1p [ 2 ] ; lduwq00gqj = muDoubleScalarCos ( _rtDW -> eaosag5owj ) ;
ckrl0nmlwt = muDoubleScalarSin ( _rtDW -> eaosag5owj ) ; } if ( _rtB ->
nyjtqlivfc [ 1 ] <= 1.0 ) { i3fummpa1c = 1.0 ; } else { i3fummpa1c = _rtB ->
nyjtqlivfc [ 1 ] ; } i3fummpa1c = 1.0 / i3fummpa1c ; i3fummpa1c *= 30000.0 ;
awwg3xagjh = muDoubleScalarAbs ( i3fummpa1c ) ; if ( ssIsMajorTimeStep ( S )
) { if ( _rtB -> nyjtqlivfc [ 1 ] >= 300.0 ) { _rtDW -> ch52ed4whv = true ; }
else { if ( _rtB -> nyjtqlivfc [ 1 ] <= 200.0 ) { _rtDW -> ch52ed4whv = false
; } } } _rtB -> odqkm4cuj3 = _rtDW -> ch52ed4whv ; if ( ( _rtDW -> mg242c3vwq
>= ssGetTaskTime ( S , 0 ) ) && ( _rtDW -> k1wt3kvmem >= ssGetTaskTime ( S ,
0 ) ) ) { _rtB -> p1rlwerq1x = _rtB -> odqkm4cuj3 ; } else { if ( ( ( _rtDW
-> mg242c3vwq < _rtDW -> k1wt3kvmem ) && ( _rtDW -> k1wt3kvmem <
ssGetTaskTime ( S , 0 ) ) ) || ( ( _rtDW -> mg242c3vwq >= _rtDW -> k1wt3kvmem
) && ( _rtDW -> mg242c3vwq >= ssGetTaskTime ( S , 0 ) ) ) ) { pzh42py0bn =
ssGetTaskTime ( S , 0 ) - _rtDW -> k1wt3kvmem ; mqc0yqbsjn = _rtDW ->
lzjsh0qxsz ; } else { pzh42py0bn = ssGetTaskTime ( S , 0 ) - _rtDW ->
mg242c3vwq ; mqc0yqbsjn = _rtDW -> oiqwpboxgd ; } byehzqrbel = pzh42py0bn *
10.0 ; lstej3qx0u = _rtB -> odqkm4cuj3 - mqc0yqbsjn ; if ( lstej3qx0u >
byehzqrbel ) { _rtB -> p1rlwerq1x = mqc0yqbsjn + byehzqrbel ; } else {
pzh42py0bn *= - 10.0 ; if ( lstej3qx0u < pzh42py0bn ) { _rtB -> p1rlwerq1x =
mqc0yqbsjn + pzh42py0bn ; } else { _rtB -> p1rlwerq1x = _rtB -> odqkm4cuj3 ;
} } } i3fummpa1c = _rtB -> akftt1xsd1 * _rtB -> pog4s1u1rz ; if (
ssIsSampleHit ( S , 2 , 0 ) ) { rowIdx = ( int32_T ) ( ( ( ( ( uint32_T ) (
_rtB -> kduw44qano < ld5zvvrfqt ( S ) -> caecp4mowq ) << 1 ) + ( _rtB ->
kduw44qano > ld5zvvrfqt ( S ) -> e53dlhb2ic ) ) << 1 ) + _rtDW -> bvad1zjfik
) ; _rtB -> hcgsj5tdfn [ 0U ] = ni220kbneq . erefcqlbee [ ( uint32_T ) rowIdx
] ; _rtB -> hcgsj5tdfn [ 1U ] = ni220kbneq . erefcqlbee [ rowIdx + 8U ] ; }
hiyz3mxgea = _rtB -> hcgsj5tdfn [ 0 ] ; _rtB -> lr43ua3mxu = - 21000.0 *
hiyz3mxgea ; if ( ( _rtDW -> hfvh40s0je >= ssGetTaskTime ( S , 0 ) ) && (
_rtDW -> f41a3yqptq >= ssGetTaskTime ( S , 0 ) ) ) { _rtB -> dvszaytgyc =
_rtB -> lr43ua3mxu ; } else { if ( ( ( _rtDW -> hfvh40s0je < _rtDW ->
f41a3yqptq ) && ( _rtDW -> f41a3yqptq < ssGetTaskTime ( S , 0 ) ) ) || ( (
_rtDW -> hfvh40s0je >= _rtDW -> f41a3yqptq ) && ( _rtDW -> hfvh40s0je >=
ssGetTaskTime ( S , 0 ) ) ) ) { pzh42py0bn = ssGetTaskTime ( S , 0 ) - _rtDW
-> f41a3yqptq ; mqc0yqbsjn = _rtDW -> aq3qjo4ji4 ; } else { pzh42py0bn =
ssGetTaskTime ( S , 0 ) - _rtDW -> hfvh40s0je ; mqc0yqbsjn = _rtDW ->
lidlmlim32 ; } byehzqrbel = pzh42py0bn * 42000.0 ; lstej3qx0u = _rtB ->
lr43ua3mxu - mqc0yqbsjn ; if ( lstej3qx0u > byehzqrbel ) { _rtB -> dvszaytgyc
= mqc0yqbsjn + byehzqrbel ; } else { pzh42py0bn *= - 42000.0 ; if (
lstej3qx0u < pzh42py0bn ) { _rtB -> dvszaytgyc = mqc0yqbsjn + pzh42py0bn ; }
else { _rtB -> dvszaytgyc = _rtB -> lr43ua3mxu ; } } } pzh42py0bn =
i3fummpa1c - _rtB -> dvszaytgyc ; hiyz3mxgea = muDoubleScalarAbs ( pzh42py0bn
) ; hiyz3mxgea = 1.1 * rt_Lookup ( _rtP -> EngineSpeedPower . power , 84 ,
hiyz3mxgea , _rtP -> EngineSpeedPower . speed ) ; if ( hiyz3mxgea > 5000.0 )
{ j0bnh13vos = 5000.0 ; } else if ( hiyz3mxgea < 750.0 ) { j0bnh13vos = 750.0
; } else { j0bnh13vos = hiyz3mxgea ; } byehzqrbel = 0.10471975511965977 *
j0bnh13vos ; if ( ssIsMajorTimeStep ( S ) ) { if ( i3fummpa1c >= 12000.0 ) {
_rtDW -> guq5pq4c5s = true ; } else { if ( i3fummpa1c <= 11000.0 ) { _rtDW ->
guq5pq4c5s = false ; } } } if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB ->
cuu4r3jquz = ! ! _rtDW -> guq5pq4c5s ; _rtB -> mpmbihhjfh = ( _rtDW ->
aln04uuynj != ld5zvvrfqt ( S ) -> ea24vq2bbj ) ; _rtB -> pxna03hhfx = _rtDW
-> nlh5qppt4m ; } if ( _rtB -> cuu4r3jquz || ( ( i3fummpa1c > ld5zvvrfqt ( S
) -> cliypbtpif ) && _rtB -> mpmbihhjfh ) ) { if ( pzh42py0bn > 57000.0 ) {
pzh42py0bn = 57000.0 ; } else { if ( pzh42py0bn < - 57000.0 ) { pzh42py0bn =
- 57000.0 ; } } _rtB -> dl4pg30ojq = 1.0 / byehzqrbel * pzh42py0bn * _rtB ->
p1rlwerq1x ; } else { _rtB -> dl4pg30ojq = _rtB -> pxna03hhfx ; } hiyz3mxgea
= 1.0 / byehzqrbel * _rtB -> nyjtqlivfc [ 12 ] ; if ( hiyz3mxgea > 1.0 ) {
j0bnh13vos = 1.0 ; } else if ( hiyz3mxgea < 0.0 ) { j0bnh13vos = 0.0 ; } else
{ j0bnh13vos = hiyz3mxgea ; } byehzqrbel = _rtB -> p1rlwerq1x * _rtB ->
dl4pg30ojq * j0bnh13vos * 0.27777777777777779 ; if ( byehzqrbel > awwg3xagjh
) { _rtB -> neiceh2ylu = awwg3xagjh ; } else if ( byehzqrbel < - awwg3xagjh )
{ _rtB -> neiceh2ylu = - awwg3xagjh ; } else { _rtB -> neiceh2ylu =
byehzqrbel ; } hiyz3mxgea = - _rtB -> neiceh2ylu * ld5zvvrfqt ( S ) ->
clo4igzp0z ; if ( ( _rtDW -> mtptmi2003 == ( rtMinusInf ) ) || ( _rtDW ->
mtptmi2003 == ssGetTaskTime ( S , 0 ) ) ) { _rtDW -> mtptmi2003 =
ssGetTaskTime ( S , 0 ) ; _rtB -> cvtrowetv3 = 0.0 ; } else { _rtB ->
cvtrowetv3 = hiyz3mxgea ; } if ( ssIsSampleHit ( S , 2 , 0 ) ) { if ( _rtB ->
cvtrowetv3 > 45.0 ) { dztyrqu4xa = 45.0 ; } else if ( _rtB -> cvtrowetv3 < -
45.0 ) { dztyrqu4xa = - 45.0 ; } else { dztyrqu4xa = _rtB -> cvtrowetv3 ; }
aqlslovppe = 3.4722222222222219 * dztyrqu4xa ; dyfxp2slod = - ld5zvvrfqt ( S
) -> lxhcigjgar * ckrl0nmlwt + aqlslovppe * lduwq00gqj ; ctpq3axefx =
dyfxp2slod - dwqqadjaqz_idx_0 ; if ( ctpq3axefx >= 0.0 ) { _rtDW ->
mdrfaaqhlc = true ; } else { if ( ctpq3axefx <= 0.0 ) { _rtDW -> mdrfaaqhlc =
false ; } } dk4tk42hhp = ( 1.7320508 * ckrl0nmlwt + - lduwq00gqj ) *
aqlslovppe * 0.5 + ( 1.7320508 * lduwq00gqj + ckrl0nmlwt ) * ld5zvvrfqt ( S )
-> lxhcigjgar * 0.5 ; aqlslovppe = dk4tk42hhp - dwqqadjaqz_idx_1 ; if (
aqlslovppe >= 0.0 ) { _rtDW -> hi5e5wjvfn = true ; } else { if ( aqlslovppe
<= 0.0 ) { _rtDW -> hi5e5wjvfn = false ; } } f1b5simhxh = ( 0.0 - dk4tk42hhp
) - dyfxp2slod ; lduwq00gqj = f1b5simhxh - dwqqadjaqz_idx_2 ; if ( lduwq00gqj
>= 0.0 ) { _rtDW -> ltj2mwt3by = true ; } else { if ( lduwq00gqj <= 0.0 ) {
_rtDW -> ltj2mwt3by = false ; } } _rtB -> ka0odn3q1q [ 0 ] = ( ( real_T )
_rtDW -> mdrfaaqhlc - ( real_T ) _rtDW -> hi5e5wjvfn ) * ld5zvvrfqt ( S ) ->
clo4igzp0z * _rtB -> drvrbcfntm ; _rtB -> ka0odn3q1q [ 1 ] = ( ( real_T )
_rtDW -> hi5e5wjvfn - ( real_T ) _rtDW -> ltj2mwt3by ) * ld5zvvrfqt ( S ) ->
clo4igzp0z * _rtB -> drvrbcfntm ; _rtB -> avcmlw4bbo = _rtDW -> bro0cn1wmi ;
dwqqadjaqz_idx_0 = _rtDW -> j31s1kcymk [ 0 ] ; dwqqadjaqz_idx_1 = _rtDW ->
j31s1kcymk [ 1 ] ; dwqqadjaqz_idx_2 = _rtDW -> j31s1kcymk [ 2 ] ; ehcygfucdl
/= 4.0 ; ctpq3axefx = 4.0 * ehcygfucdl ; aqlslovppe = muDoubleScalarCos (
ctpq3axefx ) ; ctpq3axefx = muDoubleScalarSin ( ctpq3axefx ) ; if (
ssIsSampleHit ( S , 3 , 0 ) ) { _rtB -> fk5kawbfgf = _rtDW -> gsr0ogd2xb ; }
_rtB -> kryunfuh0m = 0.002479481623358034 * _rtB -> fk5kawbfgf ; } if ( (
_rtDW -> joiszbfghn >= ssGetTaskTime ( S , 0 ) ) && ( _rtDW -> jlnwqqs23l >=
ssGetTaskTime ( S , 0 ) ) ) { _rtB -> gdqhmtuzto = _rtB -> kryunfuh0m ; }
else { if ( ( ( _rtDW -> joiszbfghn < _rtDW -> jlnwqqs23l ) && ( _rtDW ->
jlnwqqs23l < ssGetTaskTime ( S , 0 ) ) ) || ( ( _rtDW -> joiszbfghn >= _rtDW
-> jlnwqqs23l ) && ( _rtDW -> joiszbfghn >= ssGetTaskTime ( S , 0 ) ) ) ) {
pzh42py0bn = ssGetTaskTime ( S , 0 ) - _rtDW -> jlnwqqs23l ; mqc0yqbsjn =
_rtDW -> miwjijsda1 ; } else { pzh42py0bn = ssGetTaskTime ( S , 0 ) - _rtDW
-> joiszbfghn ; mqc0yqbsjn = _rtDW -> narm2z4h4g ; } byehzqrbel = pzh42py0bn
* 10.0 ; lstej3qx0u = _rtB -> kryunfuh0m - mqc0yqbsjn ; if ( lstej3qx0u >
byehzqrbel ) { _rtB -> gdqhmtuzto = mqc0yqbsjn + byehzqrbel ; } else {
pzh42py0bn *= - 10.0 ; if ( lstej3qx0u < pzh42py0bn ) { _rtB -> gdqhmtuzto =
mqc0yqbsjn + pzh42py0bn ; } else { _rtB -> gdqhmtuzto = _rtB -> kryunfuh0m ;
} } } hiyz3mxgea = muDoubleScalarAbs ( _rtB -> gdqhmtuzto ) ; _rtB ->
mwmzcozcu5 = rt_Lookup ( ni220kbneq . hvtx2huqpc , 301 , hiyz3mxgea ,
ni220kbneq . fjibtn4wrs ) ; if ( ssIsSampleHit ( S , 2 , 0 ) ) { _rtB ->
ej4mmsjrtj = _rtB -> pog4s1u1rz ; ssCallAccelRunBlock ( S , 5 , 0 ,
SS_CALL_MDL_OUTPUTS ) ; lstej3qx0u = _rtB -> kqnrloov3e - _rtDW -> edm2y2p3wp
; if ( lstej3qx0u > 0.006 ) { lduwq00gqj = _rtDW -> edm2y2p3wp + 0.006 ; }
else if ( lstej3qx0u < - 0.006 ) { lduwq00gqj = _rtDW -> edm2y2p3wp + - 0.006
; } else { lduwq00gqj = _rtB -> kqnrloov3e ; } _rtDW -> edm2y2p3wp =
lduwq00gqj ; lduwq00gqj *= - 382.64830010578072 ; lstej3qx0u = _rtB ->
h0veg11mi0 - _rtDW -> asqvifamq0 ; if ( lstej3qx0u > 0.006 ) { ckrl0nmlwt =
_rtDW -> asqvifamq0 + 0.006 ; } else if ( lstej3qx0u < - 0.006 ) { ckrl0nmlwt
= _rtDW -> asqvifamq0 + - 0.006 ; } else { ckrl0nmlwt = _rtB -> h0veg11mi0 ;
} _rtDW -> asqvifamq0 = ckrl0nmlwt ; ckrl0nmlwt *= 382.64830010578072 ;
pzh42py0bn = - lduwq00gqj * ctpq3axefx + ckrl0nmlwt * aqlslovppe ; byehzqrbel
= pzh42py0bn - dwqqadjaqz_idx_0 ; if ( byehzqrbel >= 0.0 ) { _rtDW ->
bmg0h5hxwy = true ; } else { if ( byehzqrbel <= 0.0 ) { _rtDW -> bmg0h5hxwy =
false ; } } mqc0yqbsjn = ( 1.7320508 * ctpq3axefx + - aqlslovppe ) *
ckrl0nmlwt * 0.5 + ( 1.7320508 * aqlslovppe + ctpq3axefx ) * lduwq00gqj * 0.5
; ctpq3axefx = mqc0yqbsjn - dwqqadjaqz_idx_1 ; if ( ctpq3axefx >= 0.0 ) {
_rtDW -> kakc11drsq = true ; } else { if ( ctpq3axefx <= 0.0 ) { _rtDW ->
kakc11drsq = false ; } } lstej3qx0u = ( 0.0 - mqc0yqbsjn ) - pzh42py0bn ;
aqlslovppe = lstej3qx0u - dwqqadjaqz_idx_2 ; if ( aqlslovppe >= 0.0 ) { _rtDW
-> d1uemo0w03 = true ; } else { if ( aqlslovppe <= 0.0 ) { _rtDW ->
d1uemo0w03 = false ; } } _rtB -> jtyljnefzm [ 0 ] = ( ( real_T ) _rtDW ->
bmg0h5hxwy - ( real_T ) _rtDW -> kakc11drsq ) * ld5zvvrfqt ( S ) ->
kn51dbjiax * _rtB -> avcmlw4bbo ; _rtB -> jtyljnefzm [ 1 ] = ( ( real_T )
_rtDW -> kakc11drsq - ( real_T ) _rtDW -> d1uemo0w03 ) * ld5zvvrfqt ( S ) ->
kn51dbjiax * _rtB -> avcmlw4bbo ; _rtB -> lwq35dhwyh = _rtDW -> nvz0a2qmzg ;
m11fddtsiw = ( ld5zvvrfqt ( S ) -> clo4igzp0z != 0.0 ) ; zcEvent_idx_0 =
rt_ZCFcn ( ANY_ZERO_CROSSING , & _rtZCE -> gn3hyklx0i [ 0 ] , ( dyfxp2slod )
) ; zcEvent_idx_1 = rt_ZCFcn ( ANY_ZERO_CROSSING , & _rtZCE -> gn3hyklx0i [ 1
] , ( dk4tk42hhp ) ) ; zcEvent_idx_2 = rt_ZCFcn ( ANY_ZERO_CROSSING , &
_rtZCE -> gn3hyklx0i [ 2 ] , ( f1b5simhxh ) ) ; if ( _rtDW -> p5ivrte15o [ 0
] == 0 ) { if ( zcEvent_idx_0 != NO_ZCEVENT ) { _rtB -> mwwr3qxbsa [ 0 ] = !
_rtB -> mwwr3qxbsa [ 0 ] ; _rtDW -> p5ivrte15o [ 0 ] = 1 ; } else if ( _rtB
-> mwwr3qxbsa [ 0 ] ) { if ( dyfxp2slod != 0.0 ) { _rtB -> mwwr3qxbsa [ 0 ] =
false ; } } else { if ( dyfxp2slod == 0.0 ) { _rtB -> mwwr3qxbsa [ 0 ] = true
; } } } else { if ( dyfxp2slod != 0.0 ) { _rtB -> mwwr3qxbsa [ 0 ] = false ;
} _rtDW -> p5ivrte15o [ 0 ] = 0 ; } if ( _rtDW -> p5ivrte15o [ 1 ] == 0 ) {
if ( zcEvent_idx_1 != NO_ZCEVENT ) { _rtB -> mwwr3qxbsa [ 1 ] = ! _rtB ->
mwwr3qxbsa [ 1 ] ; _rtDW -> p5ivrte15o [ 1 ] = 1 ; } else if ( _rtB ->
mwwr3qxbsa [ 1 ] ) { if ( dk4tk42hhp != 0.0 ) { _rtB -> mwwr3qxbsa [ 1 ] =
false ; } } else { if ( dk4tk42hhp == 0.0 ) { _rtB -> mwwr3qxbsa [ 1 ] = true
; } } } else { if ( dk4tk42hhp != 0.0 ) { _rtB -> mwwr3qxbsa [ 1 ] = false ;
} _rtDW -> p5ivrte15o [ 1 ] = 0 ; } if ( _rtDW -> p5ivrte15o [ 2 ] == 0 ) {
if ( zcEvent_idx_2 != NO_ZCEVENT ) { _rtB -> mwwr3qxbsa [ 2 ] = ! _rtB ->
mwwr3qxbsa [ 2 ] ; _rtDW -> p5ivrte15o [ 2 ] = 1 ; } else if ( _rtB ->
mwwr3qxbsa [ 2 ] ) { if ( f1b5simhxh != 0.0 ) { _rtB -> mwwr3qxbsa [ 2 ] =
false ; } } else { if ( f1b5simhxh == 0.0 ) { _rtB -> mwwr3qxbsa [ 2 ] = true
; } } } else { if ( f1b5simhxh != 0.0 ) { _rtB -> mwwr3qxbsa [ 2 ] = false ;
} _rtDW -> p5ivrte15o [ 2 ] = 0 ; } keyxmz53xi ( S , _rtB -> mwwr3qxbsa [ 0 ]
, m11fddtsiw , & _rtB -> keyxmz53xiy , & _rtDW -> keyxmz53xiy ) ; keyxmz53xi
( S , _rtB -> mwwr3qxbsa [ 1 ] , m11fddtsiw , & _rtB -> d5h5wn4011 , & _rtDW
-> d5h5wn4011 ) ; keyxmz53xi ( S , _rtB -> mwwr3qxbsa [ 2 ] , m11fddtsiw , &
_rtB -> hlr1ddtilb , & _rtDW -> hlr1ddtilb ) ; byehzqrbel =
0.05823546641575128 * _rtDW -> nonllthbl2 ; ctpq3axefx = 0.05823546641575128
* _rtDW -> kol45dq53x ; aqlslovppe = muDoubleScalarSin ( jwhz1ujp3w ) ;
jwhz1ujp3w = muDoubleScalarCos ( jwhz1ujp3w ) ; lduwq00gqj = ( 0.0 -
aqlslovppe * ld5zvvrfqt ( S ) -> jjhn1k550y ) - jwhz1ujp3w * ld5zvvrfqt ( S )
-> ir4uot2x1x ; ckrl0nmlwt = aqlslovppe * ld5zvvrfqt ( S ) -> ir4uot2x1x -
jwhz1ujp3w * ld5zvvrfqt ( S ) -> jjhn1k550y ; j0bnh13vos = ( byehzqrbel *
aqlslovppe + ctpq3axefx * jwhz1ujp3w ) + ld5zvvrfqt ( S ) -> e230xql33z ;
dwqqadjaqz_idx_0 = ( byehzqrbel * lduwq00gqj + ctpq3axefx * ckrl0nmlwt ) +
ld5zvvrfqt ( S ) -> e230xql33z ; byehzqrbel = ( ( ( 0.0 - lduwq00gqj ) -
aqlslovppe ) * byehzqrbel + ( ( 0.0 - ckrl0nmlwt ) - jwhz1ujp3w ) *
ctpq3axefx ) + ld5zvvrfqt ( S ) -> e230xql33z ; _rtB -> fqumyl2mqk [ 0 ] = (
real_T ) _rtB -> keyxmz53xiy . forbrjhq11 * dyfxp2slod + 0.2 * j0bnh13vos ;
_rtB -> fqumyl2mqk [ 1 ] = ( real_T ) _rtB -> d5h5wn4011 . forbrjhq11 *
dk4tk42hhp + 0.2 * dwqqadjaqz_idx_0 ; _rtB -> fqumyl2mqk [ 2 ] = ( real_T )
_rtB -> hlr1ddtilb . forbrjhq11 * f1b5simhxh + 0.2 * byehzqrbel ; if ( _rtDW
-> ehaijafsot <= 1.0 ) { j0bnh13vos = 1.0 ; } else { j0bnh13vos = _rtDW ->
ehaijafsot ; } _rtB -> nbibelhq2z = _rtDW -> fw2k5vojpd / j0bnh13vos ;
zcEvent_idx_0 = rt_ZCFcn ( ANY_ZERO_CROSSING , & _rtZCE -> iw5dmb04jk [ 0 ] ,
( pzh42py0bn ) ) ; zcEvent_idx_1 = rt_ZCFcn ( ANY_ZERO_CROSSING , & _rtZCE ->
iw5dmb04jk [ 1 ] , ( mqc0yqbsjn ) ) ; zcEvent_idx_2 = rt_ZCFcn (
ANY_ZERO_CROSSING , & _rtZCE -> iw5dmb04jk [ 2 ] , ( lstej3qx0u ) ) ; if (
_rtDW -> l43ws31i1a [ 0 ] == 0 ) { if ( zcEvent_idx_0 != NO_ZCEVENT ) { _rtB
-> mqochbmh3t [ 0 ] = ! _rtB -> mqochbmh3t [ 0 ] ; _rtDW -> l43ws31i1a [ 0 ]
= 1 ; } else if ( _rtB -> mqochbmh3t [ 0 ] ) { if ( pzh42py0bn != 0.0 ) {
_rtB -> mqochbmh3t [ 0 ] = false ; } } else { if ( pzh42py0bn == 0.0 ) { _rtB
-> mqochbmh3t [ 0 ] = true ; } } } else { if ( pzh42py0bn != 0.0 ) { _rtB ->
mqochbmh3t [ 0 ] = false ; } _rtDW -> l43ws31i1a [ 0 ] = 0 ; } if ( _rtDW ->
l43ws31i1a [ 1 ] == 0 ) { if ( zcEvent_idx_1 != NO_ZCEVENT ) { _rtB ->
mqochbmh3t [ 1 ] = ! _rtB -> mqochbmh3t [ 1 ] ; _rtDW -> l43ws31i1a [ 1 ] = 1
; } else if ( _rtB -> mqochbmh3t [ 1 ] ) { if ( mqc0yqbsjn != 0.0 ) { _rtB ->
mqochbmh3t [ 1 ] = false ; } } else { if ( mqc0yqbsjn == 0.0 ) { _rtB ->
mqochbmh3t [ 1 ] = true ; } } } else { if ( mqc0yqbsjn != 0.0 ) { _rtB ->
mqochbmh3t [ 1 ] = false ; } _rtDW -> l43ws31i1a [ 1 ] = 0 ; } if ( _rtDW ->
l43ws31i1a [ 2 ] == 0 ) { if ( zcEvent_idx_2 != NO_ZCEVENT ) { _rtB ->
mqochbmh3t [ 2 ] = ! _rtB -> mqochbmh3t [ 2 ] ; _rtDW -> l43ws31i1a [ 2 ] = 1
; } else if ( _rtB -> mqochbmh3t [ 2 ] ) { if ( lstej3qx0u != 0.0 ) { _rtB ->
mqochbmh3t [ 2 ] = false ; } } else { if ( lstej3qx0u == 0.0 ) { _rtB ->
mqochbmh3t [ 2 ] = true ; } } } else { if ( lstej3qx0u != 0.0 ) { _rtB ->
mqochbmh3t [ 2 ] = false ; } _rtDW -> l43ws31i1a [ 2 ] = 0 ; } keyxmz53xi ( S
, _rtB -> mqochbmh3t [ 0 ] , ld5zvvrfqt ( S ) -> ceko0vbukh , & _rtB ->
ovboqennya , & _rtDW -> ovboqennya ) ; keyxmz53xi ( S , _rtB -> mqochbmh3t [
1 ] , ld5zvvrfqt ( S ) -> ceko0vbukh , & _rtB -> ifhlf2te5a , & _rtDW ->
ifhlf2te5a ) ; keyxmz53xi ( S , _rtB -> mqochbmh3t [ 2 ] , ld5zvvrfqt ( S )
-> ceko0vbukh , & _rtB -> dtnq4yt00p , & _rtDW -> dtnq4yt00p ) ;
dwqqadjaqz_idx_0 = 0.05823546641575128 * _rtDW -> lvw3lta2fy ; j0bnh13vos =
0.05823546641575128 * _rtDW -> c20b4oc1jp ; ehcygfucdl *= 4.0 ; awwg3xagjh =
muDoubleScalarSin ( ehcygfucdl ) ; ehcygfucdl = muDoubleScalarCos (
ehcygfucdl ) ; i5nu34w4uj = ( 0.0 - awwg3xagjh * ld5zvvrfqt ( S ) ->
mv3yyp304l ) - ehcygfucdl * ld5zvvrfqt ( S ) -> e404aljlol ; byehzqrbel =
awwg3xagjh * ld5zvvrfqt ( S ) -> e404aljlol - ehcygfucdl * ld5zvvrfqt ( S )
-> mv3yyp304l ; lduwq00gqj = ( dwqqadjaqz_idx_0 * awwg3xagjh + j0bnh13vos *
ehcygfucdl ) + ld5zvvrfqt ( S ) -> ghgq533s5d ; ckrl0nmlwt = (
dwqqadjaqz_idx_0 * i5nu34w4uj + j0bnh13vos * byehzqrbel ) + ld5zvvrfqt ( S )
-> ghgq533s5d ; dwqqadjaqz_idx_0 = ( ( ( 0.0 - i5nu34w4uj ) - awwg3xagjh ) *
dwqqadjaqz_idx_0 + ( ( 0.0 - byehzqrbel ) - ehcygfucdl ) * j0bnh13vos ) +
ld5zvvrfqt ( S ) -> ghgq533s5d ; _rtB -> mbrv34bum3 [ 0 ] = ( real_T ) _rtB
-> ovboqennya . forbrjhq11 * pzh42py0bn + 1.5384615384615383 * lduwq00gqj ;
_rtB -> mbrv34bum3 [ 1 ] = ( real_T ) _rtB -> ifhlf2te5a . forbrjhq11 *
mqc0yqbsjn + 1.5384615384615383 * ckrl0nmlwt ; _rtB -> mbrv34bum3 [ 2 ] = (
real_T ) _rtB -> dtnq4yt00p . forbrjhq11 * lstej3qx0u + 1.5384615384615383 *
dwqqadjaqz_idx_0 ; if ( _rtDW -> kopxzfb0sb <= 1.0 ) { j0bnh13vos = 1.0 ; }
else { j0bnh13vos = _rtDW -> kopxzfb0sb ; } _rtB -> o2hyrfl0mx = _rtDW ->
lp13v2ihui / j0bnh13vos ; _rtB -> cypk2aabxx = _rtDW -> mku0z44xf5 ;
ssCallAccelRunBlock ( S , 14 , 458 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
a2kbpkbjuu = _rtB -> ndekdloslm - 0.30769230769230771 * _rtB -> ku334ei2bl [
33 ] ; ssCallAccelRunBlock ( S , 14 , 461 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
jqu1gkb0rp = ( ( real_T ) ( _rtB -> ku334ei2bl [ 33 ] < ld5zvvrfqt ( S ) ->
frcacxveue ) * 18.82114106089411 - f4ufgq33gz ) * muDoubleScalarAbs ( _rtB ->
ku334ei2bl [ 33 ] ) * 0.00064102564102564092 ; _rtB -> ddakpqwpph = 3600.0 *
eskeehll14 ; } ssCallAccelRunBlock ( S , 14 , 492 , SS_CALL_MDL_OUTPUTS ) ;
if ( ssIsSampleHit ( S , 2 , 0 ) ) { ssCallAccelRunBlock ( S , 14 , 493 ,
SS_CALL_MDL_OUTPUTS ) ; } _rtB -> gtajl4byik = 9.5492965855137211 * _rtB ->
pog4s1u1rz ; if ( ssIsSampleHit ( S , 2 , 0 ) && ssIsSampleHit ( S , 3 , 0 )
) { _rtB -> ajv02ow5bg = _rtDW -> bv5gvrfela ; } ssCallAccelRunBlock ( S , 14
, 496 , SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSampleHit ( S , 2 , 0 ) ) {
ssCallAccelRunBlock ( S , 14 , 499 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 14 , 500 , SS_CALL_MDL_OUTPUTS ) ; }
ssCallAccelRunBlock ( S , 14 , 501 , SS_CALL_MDL_OUTPUTS ) ; if (
ssIsSampleHit ( S , 2 , 0 ) ) { dwqqadjaqz_idx_0 = 0.013480000230266853 *
_rtDW -> pe31gvq3pv ; j0bnh13vos = 0.013480000230266853 * _rtDW -> bw5cwo255x
; rowIdx = ( int32_T ) ( ( ( ( ( uint32_T ) ( dwqqadjaqz_idx_0 > j0bnh13vos )
<< 1 ) + ( dwqqadjaqz_idx_0 < 0.9 * j0bnh13vos ) ) << 1 ) + _rtDW ->
l2t4rgxmml ) ; _rtB -> kzdnvntv5y [ 0U ] = ni220kbneq . erefcqlbee [ (
uint32_T ) rowIdx ] ; _rtB -> kzdnvntv5y [ 1U ] = ni220kbneq . erefcqlbee [
rowIdx + 8U ] ; mjvuadvsvc = ( uint8_T ) ( _rtB -> kzdnvntv5y [ 0 ] << 7 ) ;
_rtB -> hoz3otlxz1 = ( real_T ) mjvuadvsvc * 0.0078125 ; _rtB -> ctex4on1s1 =
( real_T ) mjvuadvsvc * 0.0078125 ; _rtB -> nhazmgrm0i = ( real_T )
mjvuadvsvc * 0.0078125 ; pbnk0frrk0 = ! ( mjvuadvsvc != 0 ) ; _rtB ->
extitbvjhv = pbnk0frrk0 ; _rtB -> impelsn55m = pbnk0frrk0 ; _rtB ->
o1hm1ekwwd = pbnk0frrk0 ; _rtB -> cta1o51xeh = ( ( _rtB -> ku334ei2bl [ 30 ]
* _rtB -> ku334ei2bl [ 30 ] + _rtB -> ku334ei2bl [ 31 ] * _rtB -> ku334ei2bl
[ 31 ] ) + _rtB -> ku334ei2bl [ 32 ] * _rtB -> ku334ei2bl [ 32 ] ) * 0.001 +
( _rtB -> ku334ei2bl [ 21 ] * _rtB -> ku334ei2bl [ 30 ] + _rtB -> ku334ei2bl
[ 22 ] * _rtB -> ku334ei2bl [ 31 ] ) ; } pzh42py0bn = muDoubleScalarPower ( (
0.006391889398924 * _rtB -> pog4s1u1rz * _rtB -> faas3afdpe + 0.0065 * _rtB
-> afxvvza3cb ) + 0.702664574517444 * _rtB -> pog4s1u1rz , 2.0 ) +
muDoubleScalarPower ( 0.0065 * _rtB -> faas3afdpe - 0.008228209001868 * _rtB
-> pog4s1u1rz * _rtB -> afxvvza3cb , 2.0 ) ; if ( pzh42py0bn < 0.0 ) {
pzh42py0bn = - muDoubleScalarSqrt ( - pzh42py0bn ) ; } else { pzh42py0bn =
muDoubleScalarSqrt ( pzh42py0bn ) ; } _rtB -> loujqlcksb = 1.5707963267948966
* pzh42py0bn ; if ( ssIsSampleHit ( S , 2 , 0 ) ) { _rtB -> lfqz0z42je = ( (
2.0 * _rtB -> ku334ei2bl [ 14 ] + _rtB -> ku334ei2bl [ 15 ] ) * mizlp41tvx +
1.7320508075688772 * _rtB -> ku334ei2bl [ 15 ] * po0ockmy2b ) *
0.33333333333333331 ; _rtB -> hsrffi2sa0 = ( ( 2.0 * _rtB -> ku334ei2bl [ 14
] + _rtB -> ku334ei2bl [ 15 ] ) * po0ockmy2b + - 1.7320508075688772 * _rtB ->
ku334ei2bl [ 15 ] * mizlp41tvx ) * 0.33333333333333331 ; _rtB -> e1ilroxiq5 =
625.79305591134812 * _rtB -> hsrffi2sa0 ; } _rtB -> dbrflxk5gd = 4.0 * _rtB
-> pog4s1u1rz ; if ( ssIsSampleHit ( S , 2 , 0 ) ) { _rtB -> i31st3e5po =
4.0676548634237628 * _rtB -> faas3afdpe ; } _rtB -> nusjvtxrf1 = _rtB ->
dbrflxk5gd * _rtB -> afxvvza3cb * 1.2872890139890598 + ( _rtB -> e1ilroxiq5 -
_rtB -> i31st3e5po ) ; if ( ssIsSampleHit ( S , 2 , 0 ) ) { _rtB ->
jcct4rwla4 = 486.13252277523628 * _rtB -> lfqz0z42je ; _rtB -> jkwkw55ldi =
3.1598613980390358 * _rtB -> afxvvza3cb ; } _rtB -> duc2o2ht2z = ( ( _rtB ->
jcct4rwla4 - _rtB -> jkwkw55ldi ) - _rtB -> faas3afdpe * _rtB -> dbrflxk5gd *
0.77682632969980325 ) - 85.397025568738272 * _rtB -> dbrflxk5gd ; hiyz3mxgea
= muDoubleScalarAbs ( _rtB -> pog4s1u1rz ) ; HEV_acc_LookUp_real_T_real_T ( &
( ddaxqpoc0f ) , ni220kbneq . eizjdjflni , hiyz3mxgea , ni220kbneq .
c3doh0dipz , 6U ) ; if ( _rtB -> kz0iasghfr > ddaxqpoc0f ) { hiyz3mxgea =
ddaxqpoc0f ; } else if ( _rtB -> kz0iasghfr < - ddaxqpoc0f ) { hiyz3mxgea = -
ddaxqpoc0f ; } else { hiyz3mxgea = _rtB -> kz0iasghfr ; } hiyz3mxgea *=
ld5zvvrfqt ( S ) -> kn51dbjiax ; if ( ( _rtDW -> dlegz3mcx5 == ( rtMinusInf )
) || ( _rtDW -> dlegz3mcx5 == ssGetTaskTime ( S , 0 ) ) ) { _rtDW ->
dlegz3mcx5 = ssGetTaskTime ( S , 0 ) ; _rtB -> p0fbtrwfda = 0.0 ; } else {
_rtB -> p0fbtrwfda = hiyz3mxgea ; } if ( ssIsSampleHit ( S , 3 , 0 ) ) { _rtB
-> dlw4rgd0xv = _rtB -> p0fbtrwfda ; if ( _rtB -> dlw4rgd0xv > 400.0 ) { _rtB
-> khd5smw31u = 400.0 ; } else if ( _rtB -> dlw4rgd0xv < - 400.0 ) { _rtB ->
khd5smw31u = - 400.0 ; } else { _rtB -> khd5smw31u = _rtB -> dlw4rgd0xv ; } }
if ( ssIsSampleHit ( S , 1 , 0 ) && ssIsSampleHit ( S , 3 , 0 ) ) { _rtB ->
kyhgj4dxjg = ld5zvvrfqt ( S ) -> kn51dbjiax ; } if ( ssIsSampleHit ( S , 3 ,
0 ) ) { _rtB -> i1p0vb3mlk = _rtB -> khd5smw31u * _rtB -> kyhgj4dxjg ; } _rtB
-> gtajl4byik = 9.5492965855137211 * _rtB -> nyjtqlivfc [ 1 ] ; if (
ssIsSampleHit ( S , 1 , 0 ) && ssIsSampleHit ( S , 2 , 0 ) ) { _rtB ->
fsjrbgb3fj = ld5zvvrfqt ( S ) -> clo4igzp0z ; } if ( ssIsSampleHit ( S , 2 ,
0 ) ) { _rtB -> mwo1b43ujb = dztyrqu4xa * _rtB -> fsjrbgb3fj ; } _rtB ->
de5ms2eask = _rtB -> fdvi4m0ynh * _rtB -> nyjtqlivfc [ 1 ] ;
ssCallAccelRunBlock ( S , 14 , 646 , SS_CALL_MDL_OUTPUTS ) ; if (
ssIsSampleHit ( S , 2 , 0 ) ) { dwqqadjaqz_idx_0 = 0.013480000230266853 *
_rtDW -> dy4ppyw4mo ; j0bnh13vos = 0.013480000230266853 * _rtDW -> hmybg5b1mi
; rowIdx = ( int32_T ) ( ( ( ( ( uint32_T ) ( dwqqadjaqz_idx_0 > j0bnh13vos )
<< 1 ) + ( dwqqadjaqz_idx_0 < 0.9 * j0bnh13vos ) ) << 1 ) + _rtDW ->
gkq12xkctn ) ; _rtB -> lsb4mwefgj [ 0U ] = ni220kbneq . erefcqlbee [ (
uint32_T ) rowIdx ] ; _rtB -> lsb4mwefgj [ 1U ] = ni220kbneq . erefcqlbee [
rowIdx + 8U ] ; mjvuadvsvc = ( uint8_T ) ( _rtB -> lsb4mwefgj [ 0 ] << 7 ) ;
_rtB -> kotvgixwqz = ( real_T ) mjvuadvsvc * 0.0078125 ; _rtB -> cp1wfklalq =
( real_T ) mjvuadvsvc * 0.0078125 ; _rtB -> mmwz0zmiwa = ( real_T )
mjvuadvsvc * 0.0078125 ; pbnk0frrk0 = ! ( mjvuadvsvc != 0 ) ; _rtB ->
gtih4bwdts = pbnk0frrk0 ; _rtB -> azvq2v3gzm = pbnk0frrk0 ; _rtB ->
lleqdppmzb = pbnk0frrk0 ; _rtB -> ot20fbugxj = ( ( _rtB -> ku334ei2bl [ 26 ]
* _rtB -> ku334ei2bl [ 26 ] + _rtB -> ku334ei2bl [ 27 ] * _rtB -> ku334ei2bl
[ 27 ] ) + _rtB -> ku334ei2bl [ 28 ] * _rtB -> ku334ei2bl [ 28 ] ) * 0.001 +
( _rtB -> ku334ei2bl [ 17 ] * _rtB -> ku334ei2bl [ 26 ] + _rtB -> ku334ei2bl
[ 18 ] * _rtB -> ku334ei2bl [ 27 ] ) ; } pzh42py0bn = muDoubleScalarPower ( (
0.000635 * _rtB -> nyjtqlivfc [ 1 ] * _rtB -> m20ugbt2wz + 0.05 * _rtB ->
gtbq2mrvsz ) + 0.192 * _rtB -> nyjtqlivfc [ 1 ] , 2.0 ) + muDoubleScalarPower
( 0.05 * _rtB -> m20ugbt2wz - 0.000635 * _rtB -> nyjtqlivfc [ 1 ] * _rtB ->
gtbq2mrvsz , 2.0 ) ; if ( pzh42py0bn < 0.0 ) { pzh42py0bn = -
muDoubleScalarSqrt ( - pzh42py0bn ) ; } else { pzh42py0bn =
muDoubleScalarSqrt ( pzh42py0bn ) ; } _rtB -> girvtjfowv = 1.5707963267948966
* pzh42py0bn ; if ( ssIsSampleHit ( S , 2 , 0 ) ) { _rtB -> ktylovz541 = ( (
2.0 * _rtB -> ku334ei2bl [ 12 ] + _rtB -> ku334ei2bl [ 13 ] ) * mkcfwi2fsi +
1.7320508075688772 * _rtB -> ku334ei2bl [ 13 ] * ehtkh2wauy ) *
0.33333333333333331 ; _rtB -> avbov0npsw = ( ( 2.0 * _rtB -> ku334ei2bl [ 12
] + _rtB -> ku334ei2bl [ 13 ] ) * ehtkh2wauy + - 1.7320508075688772 * _rtB ->
ku334ei2bl [ 13 ] * mkcfwi2fsi ) * 0.33333333333333331 ; _rtB -> j3htt3ngta =
1574.803149606299 * _rtB -> avbov0npsw ; _rtB -> crs1kt1eyv =
78.740157480314963 * _rtB -> m20ugbt2wz ; } _rtB -> j2vl3osiif = ( _rtB ->
j3htt3ngta - _rtB -> crs1kt1eyv ) + _rtB -> nyjtqlivfc [ 1 ] * _rtB ->
gtbq2mrvsz ; if ( ssIsSampleHit ( S , 2 , 0 ) ) { _rtB -> ieen32uuwz =
1574.803149606299 * _rtB -> ktylovz541 ; _rtB -> jiyelkoaaw =
78.740157480314963 * _rtB -> gtbq2mrvsz ; } _rtB -> kpsomto212 = ( ( _rtB ->
ieen32uuwz - _rtB -> jiyelkoaaw ) - _rtB -> m20ugbt2wz * _rtB -> nyjtqlivfc [
1 ] ) - 302.36220472440942 * _rtB -> nyjtqlivfc [ 1 ] ; hiyz3mxgea = ssGetT (
S ) ; mjvuadvsvc = ( uint8_T ) ( hiyz3mxgea > ld5zvvrfqt ( S ) -> bga3mjfno1
) ; _rtB -> kdjm0cy5ej = 0.0 ; _rtB -> kdjm0cy5ej += 10000.0 * _rtX ->
jkhoijqyqa ; hiyz3mxgea = _rtB -> kdjm0cy5ej - ld5zvvrfqt ( S ) -> b4zqczdzfy
; _rtB -> nkiyg5kztm = hiyz3mxgea * ( real_T ) mjvuadvsvc ; if (
ssIsSampleHit ( S , 2 , 0 ) ) { if ( _rtDW -> ls01ttkmsv != 0 ) { _rtB ->
cklia345rv = _rtDW -> cuqd0cbao3 ; } else { _rtB -> cklia345rv = 3.0E-5 *
_rtB -> nkiyg5kztm + _rtDW -> cuqd0cbao3 ; } if ( _rtB -> cklia345rv >= 1.0 )
{ _rtB -> cklia345rv = 1.0 ; } else { if ( _rtB -> cklia345rv <= - 1.0 ) {
_rtB -> cklia345rv = - 1.0 ; } } } hiyz3mxgea = 0.001 * _rtB -> nkiyg5kztm +
_rtB -> cklia345rv ; if ( hiyz3mxgea > 0.95 ) { j0bnh13vos = 0.95 ; } else if
( hiyz3mxgea < - 0.95 ) { j0bnh13vos = - 0.95 ; } else { j0bnh13vos =
hiyz3mxgea ; } _rtB -> kfcvzga415 = ( j0bnh13vos + 1.0 ) * 0.5 ; if (
ssIsSampleHit ( S , 2 , 0 ) ) { _rtB -> gngrqsvxp1 = _rtDW -> gdvdkibu4i *
_rtB -> ku334ei2bl [ 24 ] ; _rtB -> ioxqlznmyz = _rtDW -> gdvdkibu4i * _rtB
-> ku334ei2bl [ 34 ] ; ssCallAccelRunBlock ( S , 14 , 822 ,
SS_CALL_MDL_OUTPUTS ) ; } ssCallAccelRunBlock ( S , 14 , 823 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 14 , 824 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 14 , 825 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 14 , 826 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 14 , 827 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 14 , 828 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 14 , 829 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 14 , 830 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 14 , 831 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 14 , 832 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 14 , 833 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> gw5zdcazle = muDoubleScalarAbs ( _rtB ->
pvtml134dd ) ; if ( ( _rtDW -> en15lu4hm1 >= ssGetT ( S ) ) && ( _rtDW ->
km4yirabra >= ssGetT ( S ) ) ) { _rtB -> dwu5gpx54e = 0.0 ; } else {
pzh42py0bn = _rtDW -> en15lu4hm1 ; lastU = & _rtDW -> aa3vndu55f ; if ( _rtDW
-> en15lu4hm1 < _rtDW -> km4yirabra ) { if ( _rtDW -> km4yirabra < ssGetT ( S
) ) { pzh42py0bn = _rtDW -> km4yirabra ; lastU = & _rtDW -> ke4dqjfdz3 ; } }
else { if ( _rtDW -> en15lu4hm1 >= ssGetT ( S ) ) { pzh42py0bn = _rtDW ->
km4yirabra ; lastU = & _rtDW -> ke4dqjfdz3 ; } } _rtB -> dwu5gpx54e = ( _rtB
-> bfsq0zyecv - * lastU ) / ( ssGetT ( S ) - pzh42py0bn ) ; } _rtB ->
iuuvkpmj32 = muDoubleScalarAbs ( _rtB -> kvbe2ne4jw ) ; _rtB -> koknwagqbr =
1.093 * _rtB -> iuuvkpmj32 ; _rtB -> nwptxp0rxu = 1.0464 * _rtB -> bfsq0zyecv
; { uint32_T iLeftU0 , iRghtU0 , iLeftU1 , iRghtU1 ;
HEV_acc_BINARYSEARCH_real_T ( & ( iLeftU0 ) , & ( iRghtU0 ) , _rtB ->
koknwagqbr , ni220kbneq . c4qvyaa1p5 , 108U ) ; if ( _rtB -> nwptxp0rxu <=
0.0 ) { iLeftU1 = 0U ; iRghtU1 = 0U ; } else if ( _rtB -> nwptxp0rxu >=
6000.0 ) { iLeftU1 = 100U ; iRghtU1 = 100U ; } else { iLeftU1 = ( uint32_T )
( ( _rtB -> nwptxp0rxu ) / 60.0 ) ; iRghtU1 = iLeftU1 + 1 ; } { real_T yTemp
; real_T u1Lambda ; real_T u0Lambda ; if ( iLeftU1 != iRghtU1 ) { { real_T
num = ( real_T ) ( _rtB -> nwptxp0rxu ) - ( iLeftU1 * 60.0 ) ; u1Lambda = num
/ 60.0 ; } } else { u1Lambda = 0.0 ; } if ( ( ni220kbneq . c4qvyaa1p5 [
iRghtU0 ] ) > ( ni220kbneq . c4qvyaa1p5 [ iLeftU0 ] ) ) { real_T num ; real_T
den ; den = ( ni220kbneq . c4qvyaa1p5 [ iRghtU0 ] ) ; den -= ( ni220kbneq .
c4qvyaa1p5 [ iLeftU0 ] ) ; num = _rtB -> koknwagqbr ; num -= ( ni220kbneq .
c4qvyaa1p5 [ iLeftU0 ] ) ; u0Lambda = num / den ; } else { u0Lambda = 0.0 ; }
{ real_T yLeftCast ; real_T yRghtCast ; yLeftCast = ( ni220kbneq . kdiaalgsdn
[ ( iLeftU0 + 109U * iLeftU1 ) ] ) ; yRghtCast = ( ni220kbneq . kdiaalgsdn [
( iLeftU0 + 109U * iRghtU1 ) ] ) ; yLeftCast += u1Lambda * ( yRghtCast -
yLeftCast ) ; cz11sb51me = yLeftCast ; } { real_T yLeftCast ; real_T
yRghtCast ; yLeftCast = ( ni220kbneq . kdiaalgsdn [ ( iRghtU0 + 109U *
iLeftU1 ) ] ) ; yRghtCast = ( ni220kbneq . kdiaalgsdn [ ( iRghtU0 + 109U *
iRghtU1 ) ] ) ; yLeftCast += u1Lambda * ( yRghtCast - yLeftCast ) ; yTemp =
yLeftCast ; } { real_T yLeftCast ; real_T yRghtCast ; yLeftCast = cz11sb51me
; yRghtCast = yTemp ; yLeftCast += u0Lambda * ( yRghtCast - yLeftCast ) ;
cz11sb51me = yLeftCast ; } } } _rtB -> lwyaqlsuzl = 1.0351048413332149 *
cz11sb51me ; _rtB -> g3xb414uz5 = 1.933764640184292E-6 * _rtB -> lwyaqlsuzl ;
_rtB -> ia5vjxt5rf = muDoubleScalarSign ( _rtB -> kvbe2ne4jw ) ; _rtB ->
afr2dy2os4 = muDoubleScalarAbs ( _rtB -> kvbe2ne4jw ) ; _rtB -> pgz0aejq10 =
1.093 * _rtB -> afr2dy2os4 ; _rtB -> d0mjpfpoo5 = 1.0464 * _rtB -> bfsq0zyecv
; { uint32_T iLeftU0 , iRghtU0 , iLeftU1 , iRghtU1 ;
HEV_acc_BINARYSEARCH_real_T ( & ( iLeftU0 ) , & ( iRghtU0 ) , _rtB ->
pgz0aejq10 , ni220kbneq . c4qvyaa1p5 , 108U ) ; if ( _rtB -> d0mjpfpoo5 <=
0.0 ) { iLeftU1 = 0U ; iRghtU1 = 0U ; } else if ( _rtB -> d0mjpfpoo5 >=
6000.0 ) { iLeftU1 = 100U ; iRghtU1 = 100U ; } else { iLeftU1 = ( uint32_T )
( ( _rtB -> d0mjpfpoo5 ) / 60.0 ) ; iRghtU1 = iLeftU1 + 1 ; } { real_T yTemp
; real_T u1Lambda ; real_T u0Lambda ; if ( iLeftU1 != iRghtU1 ) { { real_T
num = ( real_T ) ( _rtB -> d0mjpfpoo5 ) - ( iLeftU1 * 60.0 ) ; u1Lambda = num
/ 60.0 ; } } else { u1Lambda = 0.0 ; } if ( ( ni220kbneq . c4qvyaa1p5 [
iRghtU0 ] ) > ( ni220kbneq . c4qvyaa1p5 [ iLeftU0 ] ) ) { real_T num ; real_T
den ; den = ( ni220kbneq . c4qvyaa1p5 [ iRghtU0 ] ) ; den -= ( ni220kbneq .
c4qvyaa1p5 [ iLeftU0 ] ) ; num = _rtB -> pgz0aejq10 ; num -= ( ni220kbneq .
c4qvyaa1p5 [ iLeftU0 ] ) ; u0Lambda = num / den ; } else { u0Lambda = 0.0 ; }
{ real_T yLeftCast ; real_T yRghtCast ; yLeftCast = ( ni220kbneq . g1ttup4hss
[ ( iLeftU0 + 109U * iLeftU1 ) ] ) ; yRghtCast = ( ni220kbneq . g1ttup4hss [
( iLeftU0 + 109U * iRghtU1 ) ] ) ; yLeftCast += u1Lambda * ( yRghtCast -
yLeftCast ) ; ma5zkm3ak0 = yLeftCast ; } { real_T yLeftCast ; real_T
yRghtCast ; yLeftCast = ( ni220kbneq . g1ttup4hss [ ( iRghtU0 + 109U *
iLeftU1 ) ] ) ; yRghtCast = ( ni220kbneq . g1ttup4hss [ ( iRghtU0 + 109U *
iRghtU1 ) ] ) ; yLeftCast += u1Lambda * ( yRghtCast - yLeftCast ) ; yTemp =
yLeftCast ; } { real_T yLeftCast ; real_T yRghtCast ; yLeftCast = ma5zkm3ak0
; yRghtCast = yTemp ; yLeftCast += u0Lambda * ( yRghtCast - yLeftCast ) ;
ma5zkm3ak0 = yLeftCast ; } } } _rtB -> m2gh0dj0jn = 1.0351048413332149 *
ma5zkm3ak0 ; _rtB -> giytgfhaso = _rtB -> ia5vjxt5rf * _rtB -> m2gh0dj0jn ;
_rtB -> gm3ppofav4 = _rtB -> giytgfhaso * _rtB -> dwu5gpx54e ; _rtB ->
brwsqtpmbu = 1.933764640184292E-6 * _rtB -> gm3ppofav4 ; _rtB -> ekqlsj2klz =
_rtB -> gw5zdcazle * _rtB -> kvbe2ne4jw ; if ( _rtB -> g3xb414uz5 <= 0.02 ) {
_rtB -> aa5dfepdin = 0.02 ; } else { _rtB -> aa5dfepdin = _rtB -> g3xb414uz5
; } _rtB -> ogzdxsu0nx = ( ( 0.0 - _rtB -> brwsqtpmbu ) - _rtB -> hovbh5g5g4
) - _rtB -> ekqlsj2klz ; _rtB -> kcbn21m0fn = 1.0 / _rtB -> aa5dfepdin * _rtB
-> ogzdxsu0nx ; _rtB -> o0emm0jrwx = _rtB -> fizzwskkmv + _rtB -> povcbqqxqx
; _rtB -> f4sgtu5v1v = ( _rtB -> o0emm0jrwx - _rtB -> aycqigbrea ) -
ld5zvvrfqt ( S ) -> bk0wxmqie1 ; _rtB -> oohtojf2hk = 0.00075471698113207543
* _rtB -> f4sgtu5v1v ; _rtB -> japm3qsqwj = muDoubleScalarAbs ( _rtB ->
pvtml134dd ) ; if ( ( _rtDW -> cgi523usaj >= ssGetT ( S ) ) && ( _rtDW ->
irt5havirw >= ssGetT ( S ) ) ) { _rtB -> fabf1bjzrf = 0.0 ; } else {
pzh42py0bn = _rtDW -> cgi523usaj ; lastU = & _rtDW -> edrzze2flm ; if ( _rtDW
-> cgi523usaj < _rtDW -> irt5havirw ) { if ( _rtDW -> irt5havirw < ssGetT ( S
) ) { pzh42py0bn = _rtDW -> irt5havirw ; lastU = & _rtDW -> gljjadsfzv ; } }
else { if ( _rtDW -> cgi523usaj >= ssGetT ( S ) ) { pzh42py0bn = _rtDW ->
irt5havirw ; lastU = & _rtDW -> gljjadsfzv ; } } _rtB -> fabf1bjzrf = ( _rtB
-> floa0n1bxy - * lastU ) / ( ssGetT ( S ) - pzh42py0bn ) ; } _rtB ->
peikidc2k1 = muDoubleScalarAbs ( _rtB -> fd3rap22fd ) ; _rtB -> edfkzh1xaq =
1.093 * _rtB -> peikidc2k1 ; _rtB -> kkzyr2ab14 = 1.0464 * _rtB -> floa0n1bxy
; { uint32_T iLeftU0 , iRghtU0 , iLeftU1 , iRghtU1 ;
HEV_acc_BINARYSEARCH_real_T ( & ( iLeftU0 ) , & ( iRghtU0 ) , _rtB ->
edfkzh1xaq , ni220kbneq . c4qvyaa1p5 , 108U ) ; if ( _rtB -> kkzyr2ab14 <=
0.0 ) { iLeftU1 = 0U ; iRghtU1 = 0U ; } else if ( _rtB -> kkzyr2ab14 >=
6000.0 ) { iLeftU1 = 100U ; iRghtU1 = 100U ; } else { iLeftU1 = ( uint32_T )
( ( _rtB -> kkzyr2ab14 ) / 60.0 ) ; iRghtU1 = iLeftU1 + 1 ; } { real_T yTemp
; real_T u1Lambda ; real_T u0Lambda ; if ( iLeftU1 != iRghtU1 ) { { real_T
num = ( real_T ) ( _rtB -> kkzyr2ab14 ) - ( iLeftU1 * 60.0 ) ; u1Lambda = num
/ 60.0 ; } } else { u1Lambda = 0.0 ; } if ( ( ni220kbneq . c4qvyaa1p5 [
iRghtU0 ] ) > ( ni220kbneq . c4qvyaa1p5 [ iLeftU0 ] ) ) { real_T num ; real_T
den ; den = ( ni220kbneq . c4qvyaa1p5 [ iRghtU0 ] ) ; den -= ( ni220kbneq .
c4qvyaa1p5 [ iLeftU0 ] ) ; num = _rtB -> edfkzh1xaq ; num -= ( ni220kbneq .
c4qvyaa1p5 [ iLeftU0 ] ) ; u0Lambda = num / den ; } else { u0Lambda = 0.0 ; }
{ real_T yLeftCast ; real_T yRghtCast ; yLeftCast = ( ni220kbneq . kdiaalgsdn
[ ( iLeftU0 + 109U * iLeftU1 ) ] ) ; yRghtCast = ( ni220kbneq . kdiaalgsdn [
( iLeftU0 + 109U * iRghtU1 ) ] ) ; yLeftCast += u1Lambda * ( yRghtCast -
yLeftCast ) ; d0xxkzbvri = yLeftCast ; } { real_T yLeftCast ; real_T
yRghtCast ; yLeftCast = ( ni220kbneq . kdiaalgsdn [ ( iRghtU0 + 109U *
iLeftU1 ) ] ) ; yRghtCast = ( ni220kbneq . kdiaalgsdn [ ( iRghtU0 + 109U *
iRghtU1 ) ] ) ; yLeftCast += u1Lambda * ( yRghtCast - yLeftCast ) ; yTemp =
yLeftCast ; } { real_T yLeftCast ; real_T yRghtCast ; yLeftCast = d0xxkzbvri
; yRghtCast = yTemp ; yLeftCast += u0Lambda * ( yRghtCast - yLeftCast ) ;
d0xxkzbvri = yLeftCast ; } } } _rtB -> az5zxxrnwy = 1.0351048413332149 *
d0xxkzbvri ; _rtB -> g0eb1wdsd5 = 1.933764640184292E-6 * _rtB -> az5zxxrnwy ;
_rtB -> egw2u0wtrh = muDoubleScalarSign ( _rtB -> fd3rap22fd ) ; _rtB ->
mnsbflybll = muDoubleScalarAbs ( _rtB -> fd3rap22fd ) ; _rtB -> o5qxydn54i =
1.093 * _rtB -> mnsbflybll ; _rtB -> mv440fgtms = 1.0464 * _rtB -> floa0n1bxy
; { uint32_T iLeftU0 , iRghtU0 , iLeftU1 , iRghtU1 ;
HEV_acc_BINARYSEARCH_real_T ( & ( iLeftU0 ) , & ( iRghtU0 ) , _rtB ->
o5qxydn54i , ni220kbneq . c4qvyaa1p5 , 108U ) ; if ( _rtB -> mv440fgtms <=
0.0 ) { iLeftU1 = 0U ; iRghtU1 = 0U ; } else if ( _rtB -> mv440fgtms >=
6000.0 ) { iLeftU1 = 100U ; iRghtU1 = 100U ; } else { iLeftU1 = ( uint32_T )
( ( _rtB -> mv440fgtms ) / 60.0 ) ; iRghtU1 = iLeftU1 + 1 ; } { real_T yTemp
; real_T u1Lambda ; real_T u0Lambda ; if ( iLeftU1 != iRghtU1 ) { { real_T
num = ( real_T ) ( _rtB -> mv440fgtms ) - ( iLeftU1 * 60.0 ) ; u1Lambda = num
/ 60.0 ; } } else { u1Lambda = 0.0 ; } if ( ( ni220kbneq . c4qvyaa1p5 [
iRghtU0 ] ) > ( ni220kbneq . c4qvyaa1p5 [ iLeftU0 ] ) ) { real_T num ; real_T
den ; den = ( ni220kbneq . c4qvyaa1p5 [ iRghtU0 ] ) ; den -= ( ni220kbneq .
c4qvyaa1p5 [ iLeftU0 ] ) ; num = _rtB -> o5qxydn54i ; num -= ( ni220kbneq .
c4qvyaa1p5 [ iLeftU0 ] ) ; u0Lambda = num / den ; } else { u0Lambda = 0.0 ; }
{ real_T yLeftCast ; real_T yRghtCast ; yLeftCast = ( ni220kbneq . g1ttup4hss
[ ( iLeftU0 + 109U * iLeftU1 ) ] ) ; yRghtCast = ( ni220kbneq . g1ttup4hss [
( iLeftU0 + 109U * iRghtU1 ) ] ) ; yLeftCast += u1Lambda * ( yRghtCast -
yLeftCast ) ; p5ngqu1lob = yLeftCast ; } { real_T yLeftCast ; real_T
yRghtCast ; yLeftCast = ( ni220kbneq . g1ttup4hss [ ( iRghtU0 + 109U *
iLeftU1 ) ] ) ; yRghtCast = ( ni220kbneq . g1ttup4hss [ ( iRghtU0 + 109U *
iRghtU1 ) ] ) ; yLeftCast += u1Lambda * ( yRghtCast - yLeftCast ) ; yTemp =
yLeftCast ; } { real_T yLeftCast ; real_T yRghtCast ; yLeftCast = p5ngqu1lob
; yRghtCast = yTemp ; yLeftCast += u0Lambda * ( yRghtCast - yLeftCast ) ;
p5ngqu1lob = yLeftCast ; } } } _rtB -> kowfchovcv = 1.0351048413332149 *
p5ngqu1lob ; _rtB -> mwepv5ygx3 = _rtB -> egw2u0wtrh * _rtB -> kowfchovcv ;
_rtB -> lqsbynvw1f = _rtB -> mwepv5ygx3 * _rtB -> fabf1bjzrf ; _rtB ->
ly3jsfltxq = 1.933764640184292E-6 * _rtB -> lqsbynvw1f ; _rtB -> jy2l4xxaoh =
_rtB -> japm3qsqwj * _rtB -> fd3rap22fd ; if ( _rtB -> g0eb1wdsd5 <= 0.02 ) {
_rtB -> clsae4zyud = 0.02 ; } else { _rtB -> clsae4zyud = _rtB -> g0eb1wdsd5
; } _rtB -> g0pcljpxfy = ( ( 0.0 - _rtB -> ly3jsfltxq ) - _rtB -> d2ln0pkwig
) - _rtB -> jy2l4xxaoh ; _rtB -> elter1b14u = 1.0 / _rtB -> clsae4zyud * _rtB
-> g0pcljpxfy ; ssCallAccelRunBlock ( S , 14 , 891 , SS_CALL_MDL_OUTPUTS ) ;
_rtB -> de5ms2eask = _rtB -> nyjtqlivfc [ 10 ] * _rtB -> p1o0lcfasn [ 2 ] ;
_rtB -> neiceh2ylu = _rtB -> p1o0lcfasn [ 3 ] * _rtB -> nyjtqlivfc [ 2 ] ;
_rtB -> gtajl4byik = _rtB -> nyjtqlivfc [ 9 ] * _rtB -> p1o0lcfasn [ 8 ] ;
_rtB -> mqbg1xujtm = _rtB -> neiceh2ylu + _rtB -> gtajl4byik ;
ssCallAccelRunBlock ( S , 14 , 939 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 14 , 940 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 14 , 941 , SS_CALL_MDL_OUTPUTS ) ; UNUSED_PARAMETER
( tid ) ; }
#define MDL_UPDATE
static void mdlUpdate ( SimStruct * S , int_T tid ) { real_T * lastU ;
fdj1laa40s * _rtB ; h04hj5x5sk * _rtDW ; _rtDW = ( ( h04hj5x5sk * )
ssGetRootDWork ( S ) ) ; _rtB = ( ( fdj1laa40s * ) _ssGetBlockIO ( S ) ) ; if
( ssIsSampleHit ( S , 2 , 0 ) ) { _rtDW -> aekc0mbj0y += 6.0E-5 * _rtB ->
kpsomto212 ; _rtDW -> oi2n4lur1q += 6.0E-5 * _rtB -> j2vl3osiif ; _rtDW ->
epw20ibixm += 6.0E-5 * _rtB -> duc2o2ht2z ; _rtDW -> emjtqjwqij += 6.0E-5 *
_rtB -> nusjvtxrf1 ; } if ( _rtDW -> cwivfg5ijd == ( rtInf ) ) { _rtDW ->
cwivfg5ijd = ssGetTaskTime ( S , 0 ) ; _rtDW -> kguctqvwvn = _rtB ->
dwu21sloy4 ; } else if ( _rtDW -> m1iuzueluk == ( rtInf ) ) { _rtDW ->
m1iuzueluk = ssGetTaskTime ( S , 0 ) ; _rtDW -> bvl1znuobh = _rtB ->
dwu21sloy4 ; } else if ( _rtDW -> cwivfg5ijd < _rtDW -> m1iuzueluk ) { _rtDW
-> cwivfg5ijd = ssGetTaskTime ( S , 0 ) ; _rtDW -> kguctqvwvn = _rtB ->
dwu21sloy4 ; } else { _rtDW -> m1iuzueluk = ssGetTaskTime ( S , 0 ) ; _rtDW
-> bvl1znuobh = _rtB -> dwu21sloy4 ; } if ( ssIsSampleHit ( S , 2 , 0 ) ) {
_rtDW -> f2z5i2ds5e = _rtB -> ku334ei2bl [ 33 ] - - 0.999994000018 * _rtDW ->
f2z5i2ds5e ; } if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtDW -> b50c0wk1dc =
_rtB -> ddakpqwpph ; } if ( ssIsSampleHit ( S , 2 , 0 ) ) { _rtDW ->
o05rwe50bo = 0U ; _rtDW -> pk42w2cjcz += 6.0E-5 * _rtB -> ku334ei2bl [ 33 ] ;
if ( _rtDW -> pk42w2cjcz >= 25200.0 ) { _rtDW -> pk42w2cjcz = 25200.0 ; }
else { if ( _rtDW -> pk42w2cjcz <= rtMinusInf ) { _rtDW -> pk42w2cjcz =
rtMinusInf ; } } if ( _rtB -> g2ykehf41g > 0.0 ) { _rtDW -> f0fxu4veqt = 1 ;
} else if ( _rtB -> g2ykehf41g < 0.0 ) { _rtDW -> f0fxu4veqt = - 1 ; } else
if ( _rtB -> g2ykehf41g == 0.0 ) { _rtDW -> f0fxu4veqt = 0 ; } else { _rtDW
-> f0fxu4veqt = 2 ; } _rtDW -> eaosag5owj += 6.0E-5 * _rtB -> nyjtqlivfc [ 1
] ; _rtDW -> jcugjk0yp0 += 6.0E-5 * _rtB -> dbrflxk5gd ; _rtDW -> jly33pdwub
+= 6.0E-5 * _rtB -> jqu1gkb0rp ; _rtDW -> fezg0yhyh2 = _rtB -> ku334ei2bl [
19 ] ; _rtDW -> hdqerfit1p [ 0 ] = _rtB -> ku334ei2bl [ 35 ] ; _rtDW ->
hdqerfit1p [ 1 ] = _rtB -> ku334ei2bl [ 36 ] ; _rtDW -> hdqerfit1p [ 2 ] =
_rtB -> ku334ei2bl [ 37 ] ; } if ( _rtDW -> mg242c3vwq == ( rtInf ) ) { _rtDW
-> mg242c3vwq = ssGetTaskTime ( S , 0 ) ; _rtDW -> oiqwpboxgd = _rtB ->
p1rlwerq1x ; } else if ( _rtDW -> k1wt3kvmem == ( rtInf ) ) { _rtDW ->
k1wt3kvmem = ssGetTaskTime ( S , 0 ) ; _rtDW -> lzjsh0qxsz = _rtB ->
p1rlwerq1x ; } else if ( _rtDW -> mg242c3vwq < _rtDW -> k1wt3kvmem ) { _rtDW
-> mg242c3vwq = ssGetTaskTime ( S , 0 ) ; _rtDW -> oiqwpboxgd = _rtB ->
p1rlwerq1x ; } else { _rtDW -> k1wt3kvmem = ssGetTaskTime ( S , 0 ) ; _rtDW
-> lzjsh0qxsz = _rtB -> p1rlwerq1x ; } if ( ssIsSampleHit ( S , 2 , 0 ) ) {
_rtDW -> bvad1zjfik = _rtB -> hcgsj5tdfn [ 0 ] ; } if ( _rtDW -> hfvh40s0je
== ( rtInf ) ) { _rtDW -> hfvh40s0je = ssGetTaskTime ( S , 0 ) ; _rtDW ->
lidlmlim32 = _rtB -> dvszaytgyc ; } else if ( _rtDW -> f41a3yqptq == ( rtInf
) ) { _rtDW -> f41a3yqptq = ssGetTaskTime ( S , 0 ) ; _rtDW -> aq3qjo4ji4 =
_rtB -> dvszaytgyc ; } else if ( _rtDW -> hfvh40s0je < _rtDW -> f41a3yqptq )
{ _rtDW -> hfvh40s0je = ssGetTaskTime ( S , 0 ) ; _rtDW -> lidlmlim32 = _rtB
-> dvszaytgyc ; } else { _rtDW -> f41a3yqptq = ssGetTaskTime ( S , 0 ) ;
_rtDW -> aq3qjo4ji4 = _rtB -> dvszaytgyc ; } if ( ssIsSampleHit ( S , 1 , 0 )
) { _rtDW -> aln04uuynj = _rtB -> dvszaytgyc ; _rtDW -> nlh5qppt4m = _rtB ->
dl4pg30ojq ; } if ( ssIsSampleHit ( S , 2 , 0 ) ) { _rtDW -> bro0cn1wmi =
_rtB -> ku334ei2bl [ 23 ] ; _rtDW -> j31s1kcymk [ 0 ] = _rtB -> ku334ei2bl [
38 ] ; _rtDW -> j31s1kcymk [ 1 ] = _rtB -> ku334ei2bl [ 39 ] ; _rtDW ->
j31s1kcymk [ 2 ] = _rtB -> ku334ei2bl [ 40 ] ; } if ( ssIsSampleHit ( S , 3 ,
0 ) ) { _rtDW -> gsr0ogd2xb = _rtB -> khd5smw31u ; } if ( _rtDW -> joiszbfghn
== ( rtInf ) ) { _rtDW -> joiszbfghn = ssGetTaskTime ( S , 0 ) ; _rtDW ->
narm2z4h4g = _rtB -> gdqhmtuzto ; } else if ( _rtDW -> jlnwqqs23l == ( rtInf
) ) { _rtDW -> jlnwqqs23l = ssGetTaskTime ( S , 0 ) ; _rtDW -> miwjijsda1 =
_rtB -> gdqhmtuzto ; } else if ( _rtDW -> joiszbfghn < _rtDW -> jlnwqqs23l )
{ _rtDW -> joiszbfghn = ssGetTaskTime ( S , 0 ) ; _rtDW -> narm2z4h4g = _rtB
-> gdqhmtuzto ; } else { _rtDW -> jlnwqqs23l = ssGetTaskTime ( S , 0 ) ;
_rtDW -> miwjijsda1 = _rtB -> gdqhmtuzto ; } if ( ssIsSampleHit ( S , 2 , 0 )
) { _rtDW -> nvz0a2qmzg = _rtB -> gngrqsvxp1 ; _rtDW -> nonllthbl2 = _rtB ->
avbov0npsw - - 0.94176453358424872 * _rtDW -> nonllthbl2 ; _rtDW ->
kol45dq53x = _rtB -> ktylovz541 - - 0.94176453358424872 * _rtDW -> kol45dq53x
; _rtDW -> fw2k5vojpd = _rtB -> ot20fbugxj ; _rtDW -> ehaijafsot = _rtB ->
ku334ei2bl [ 19 ] ; _rtDW -> lvw3lta2fy = _rtB -> hsrffi2sa0 - -
0.94176453358424872 * _rtDW -> lvw3lta2fy ; _rtDW -> c20b4oc1jp = _rtB ->
lfqz0z42je - - 0.94176453358424872 * _rtDW -> c20b4oc1jp ; _rtDW ->
lp13v2ihui = _rtB -> cta1o51xeh ; _rtDW -> kopxzfb0sb = _rtB -> ku334ei2bl [
23 ] ; _rtDW -> mku0z44xf5 = _rtB -> ioxqlznmyz ; ssCallAccelRunBlock ( S ,
14 , 458 , SS_CALL_MDL_UPDATE ) ; } if ( ssIsSampleHit ( S , 3 , 0 ) ) {
_rtDW -> bv5gvrfela = _rtB -> i1p0vb3mlk ; } if ( ssIsSampleHit ( S , 2 , 0 )
) { _rtDW -> pe31gvq3pv = _rtB -> loujqlcksb - - 0.98651999976973315 * _rtDW
-> pe31gvq3pv ; _rtDW -> bw5cwo255x = _rtB -> avcmlw4bbo - -
0.98651999976973315 * _rtDW -> bw5cwo255x ; _rtDW -> l2t4rgxmml = _rtB ->
kzdnvntv5y [ 0 ] ; } if ( ssIsSampleHit ( S , 2 , 0 ) ) { _rtDW -> dy4ppyw4mo
= _rtB -> girvtjfowv - - 0.98651999976973315 * _rtDW -> dy4ppyw4mo ; _rtDW ->
hmybg5b1mi = _rtB -> drvrbcfntm - - 0.98651999976973315 * _rtDW -> hmybg5b1mi
; _rtDW -> gkq12xkctn = _rtB -> lsb4mwefgj [ 0 ] ; _rtDW -> ls01ttkmsv = 0U ;
_rtDW -> cuqd0cbao3 = 3.0E-5 * _rtB -> nkiyg5kztm + _rtB -> cklia345rv ; if (
_rtDW -> cuqd0cbao3 >= 1.0 ) { _rtDW -> cuqd0cbao3 = 1.0 ; } else { if (
_rtDW -> cuqd0cbao3 <= - 1.0 ) { _rtDW -> cuqd0cbao3 = - 1.0 ; } } _rtDW ->
gdvdkibu4i = _rtB -> kfcvzga415 ; } if ( _rtDW -> en15lu4hm1 == ( rtInf ) ) {
_rtDW -> en15lu4hm1 = ssGetT ( S ) ; lastU = & _rtDW -> aa3vndu55f ; } else
if ( _rtDW -> km4yirabra == ( rtInf ) ) { _rtDW -> km4yirabra = ssGetT ( S )
; lastU = & _rtDW -> ke4dqjfdz3 ; } else if ( _rtDW -> en15lu4hm1 < _rtDW ->
km4yirabra ) { _rtDW -> en15lu4hm1 = ssGetT ( S ) ; lastU = & _rtDW ->
aa3vndu55f ; } else { _rtDW -> km4yirabra = ssGetT ( S ) ; lastU = & _rtDW ->
ke4dqjfdz3 ; } * lastU = _rtB -> bfsq0zyecv ; if ( _rtDW -> cgi523usaj == (
rtInf ) ) { _rtDW -> cgi523usaj = ssGetT ( S ) ; lastU = & _rtDW ->
edrzze2flm ; } else if ( _rtDW -> irt5havirw == ( rtInf ) ) { _rtDW ->
irt5havirw = ssGetT ( S ) ; lastU = & _rtDW -> gljjadsfzv ; } else if ( _rtDW
-> cgi523usaj < _rtDW -> irt5havirw ) { _rtDW -> cgi523usaj = ssGetT ( S ) ;
lastU = & _rtDW -> edrzze2flm ; } else { _rtDW -> irt5havirw = ssGetT ( S ) ;
lastU = & _rtDW -> gljjadsfzv ; } * lastU = _rtB -> floa0n1bxy ;
UNUSED_PARAMETER ( tid ) ; }
#define MDL_DERIVATIVES
static void mdlDerivatives ( SimStruct * S ) { fdj1laa40s * _rtB ; hgl3elxkcb
* _rtX ; aab5tqo4s5 * _rtXdot ; h04hj5x5sk * _rtDW ; _rtDW = ( ( h04hj5x5sk *
) ssGetRootDWork ( S ) ) ; _rtXdot = ( ( aab5tqo4s5 * ) ssGetdX ( S ) ) ;
_rtX = ( ( hgl3elxkcb * ) ssGetContStates ( S ) ) ; _rtB = ( ( fdj1laa40s * )
_ssGetBlockIO ( S ) ) ; _rtXdot -> mh2wvbi24o = _rtB -> bjy3ivl32q ;
ssCallAccelRunBlock ( S , 14 , 30 , SS_CALL_MDL_DERIVATIVES ) ; _rtXdot ->
nlkba1lokv = _rtB -> m3usbwf51h ; _rtXdot -> eackaa2e5o = _rtB -> elter1b14u
; _rtXdot -> a3p154yttn = _rtB -> oohtojf2hk ; _rtXdot -> lvhb24m1u3 [ 0 ] =
0.0 ; _rtXdot -> lvhb24m1u3 [ 1 ] = 0.0 ; _rtXdot -> lvhb24m1u3 [ 0 ] += -
20.106192982974676 * _rtX -> lvhb24m1u3 [ 0 ] ; _rtXdot -> lvhb24m1u3 [ 0 ]
+= - 157.91367041742973 * _rtX -> lvhb24m1u3 [ 1 ] ; _rtXdot -> lvhb24m1u3 [
1 ] += _rtX -> lvhb24m1u3 [ 0 ] ; _rtXdot -> lvhb24m1u3 [ 0 ] += _rtB ->
f4sgtu5v1v ; _rtXdot -> oiuvfykmtf = _rtB -> kcbn21m0fn ; _rtXdot ->
ix50zu3rlz = 0.0 ; _rtXdot -> ix50zu3rlz += - 125.66370614359172 * _rtX ->
ix50zu3rlz ; _rtXdot -> ix50zu3rlz += _rtB -> a5phvrw1br ; { boolean_T lsat ;
boolean_T usat ; lsat = ( ( ( hgl3elxkcb * ) ssGetContStates ( S ) ) ->
f0udlm3lxk <= ( - 5.0 ) ) ; usat = ( ( ( hgl3elxkcb * ) ssGetContStates ( S )
) -> f0udlm3lxk >= 5.0 ) ; if ( ( ! lsat && ! usat ) || ( lsat && ( _rtB ->
cflxmahva4 > 0 ) ) || ( usat && ( _rtB -> cflxmahva4 < 0 ) ) ) { ( (
aab5tqo4s5 * ) ssGetdX ( S ) ) -> f0udlm3lxk = _rtB -> cflxmahva4 ; } else {
( ( aab5tqo4s5 * ) ssGetdX ( S ) ) -> f0udlm3lxk = 0.0 ; } } _rtXdot ->
bjc4xqhn0t = _rtB -> kndxnn44r2 ; _rtXdot -> pi4mr5hhgl = _rtB -> adiysgphhg
; _rtXdot -> jkhoijqyqa = 0.0 ; _rtXdot -> jkhoijqyqa += - 10000.0 * _rtX ->
jkhoijqyqa ; _rtXdot -> jkhoijqyqa += _rtB -> ku334ei2bl [ 16 ] ; }
#define MDL_PROJECTION
static void mdlProjection ( SimStruct * S ) { fdj1laa40s * _rtB ; h04hj5x5sk
* _rtDW ; _rtDW = ( ( h04hj5x5sk * ) ssGetRootDWork ( S ) ) ; _rtB = ( (
fdj1laa40s * ) _ssGetBlockIO ( S ) ) ; ssCallAccelRunBlock ( S , 14 , 30 ,
SS_CALL_MDL_PROJECTION ) ; } static void mdlInitializeSizes ( SimStruct * S )
{ ssSetChecksumVal ( S , 0 , 2508841860U ) ; ssSetChecksumVal ( S , 1 ,
2474493925U ) ; ssSetChecksumVal ( S , 2 , 2348041657U ) ; ssSetChecksumVal (
S , 3 , 4020227832U ) ; { mxArray * slVerStructMat = NULL ; mxArray *
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
