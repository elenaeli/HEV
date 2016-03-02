/*
 * MATLAB.c
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

#include "MATLAB.h"
#include "MATLAB_private.h"

/* Block signals (auto storage) */
B_MATLAB_T MATLAB_B;

/* External inputs (root inport signals with auto storage) */
ExtU_MATLAB_T MATLAB_U;

/* External outputs (root outports fed by signals with auto storage) */
ExtY_MATLAB_T MATLAB_Y;

/* Real-time model */
RT_MODEL_MATLAB_T MATLAB_M_;
RT_MODEL_MATLAB_T *const MATLAB_M = &MATLAB_M_;

/* Forward declaration for local functions */
static void MATLAB_repmat(const real_T a[61], real_T b[3721]);
static void MATLAB_paretoSet(const real_T payoff[7442], real_T pareto_data[],
  int32_T pareto_sizes[2]);
static void MATLAB_abs(const real_T x[10], real_T y[10]);

/* Function for MATLAB Function: '<Root>/MATLAB Function' */
static void MATLAB_repmat(const real_T a[61], real_T b[3721])
{
  int32_T ibtile;
  int32_T jtilecol;
  for (jtilecol = 0; jtilecol < 61; jtilecol++) {
    ibtile = jtilecol * 61;
    memcpy(&b[ibtile], &a[0], 61U * sizeof(real_T));
  }
}

/* Function for MATLAB Function: '<Root>/MATLAB Function' */
static void MATLAB_paretoSet(const real_T payoff[7442], real_T pareto_data[],
  int32_T pareto_sizes[2])
{
  int8_T paretoIndex[2];
  int32_T not;
  int32_T flag;
  int32_T m;
  int32_T n;
  int32_T nb;
  int32_T k;
  boolean_T exitg1;
  boolean_T exitg2;
  real_T b_data[2];
  real_T ycol_data;
  for (k = 0; k < 61; k++) {
    for (nb = 0; nb < 122; nb++) {
      MATLAB_B.M[k + 61 * nb] = payoff[(((1 + k) << 1) + 61 * nb) - 1];
      MATLAB_B.E[k + 61 * nb] = payoff[((1 + k) << 1) + 61 * nb];
    }
  }

  /*  connect last point to first in the graph */
  paretoIndex[0] = 0;
  paretoIndex[1] = 0;
  pareto_data[0] = 0.0;
  pareto_data[1] = 0.0;
  for (k = 0; k < 61; k++) {
    for (nb = 0; nb < 122; nb++) {
      not = 0;
      flag = 0;
      m = 0;
      exitg1 = false;
      while ((!exitg1) && (m < 61)) {
        n = 0;
        exitg2 = false;
        while ((!exitg2) && (n < 122)) {
          if ((MATLAB_B.E[61 * nb + k] > MATLAB_B.E[61 * n + m]) && (MATLAB_B.M
               [61 * nb + k] > MATLAB_B.M[61 * n + m])) {
            not = 1;
            flag = 1;
            exitg2 = true;
          } else {
            n++;
          }
        }

        if (flag == 1) {
          exitg1 = true;
        } else {
          m++;
        }
      }

      if (not == 0) {
        paretoIndex[0] = (int8_T)(1 + k);
        paretoIndex[1] = (int8_T)(1 + nb);
        pareto_data[0] = MATLAB_B.M[61 * nb + k];
        pareto_data[1] = MATLAB_B.E[61 * nb + k];
      }
    }
  }

  b_data[0] = pareto_data[0];
  ycol_data = pareto_data[1];
  pareto_sizes[0] = 1;
  pareto_sizes[1] = 2;
  for (k = 0; k < 1; k++) {
    pareto_data[0] = b_data[0];
  }

  for (k = 0; k < 1; k++) {
    pareto_data[1] = ycol_data;
  }

  k = 0;
  while (k <= 0) {
    /* text(M(paretoIndex(i,1), paretoIndex(i,2))+2, E(paretoIndex(i,1), paretoIndex(i,2)), 'Pareto optimum')   */
    pareto_data[0] = paretoIndex[0];
    pareto_data[1] = paretoIndex[1];
    k = 1;
  }
}

/* Function for MATLAB Function: '<Root>/MATLAB Function' */
static void MATLAB_abs(const real_T x[10], real_T y[10])
{
  int32_T k;
  for (k = 0; k < 10; k++) {
    y[k] = fabs(x[k]);
  }
}

/* Model step function */
void MATLAB_step(void)
{
  real_T strategyEng[61];
  real_T strategyMot[61];
  real_T tmpT[10];
  int32_T b_j;
  real_T mtmp;
  int32_T ixstart;
  real_T b_mtmp;
  int32_T itmp;
  int32_T c_ixstart;
  int32_T ix;
  static const real_T percentage[61] = { 0.0, 0.016666666666666666,
    0.033333333333333333, 0.05, 0.066666666666666666, 0.083333333333333329, 0.1,
    0.11666666666666667, 0.13333333333333333, 0.15, 0.16666666666666666,
    0.18333333333333332, 0.2, 0.21666666666666667, 0.23333333333333334, 0.25,
    0.26666666666666666, 0.28333333333333333, 0.3, 0.31666666666666665,
    0.33333333333333331, 0.35, 0.36666666666666664, 0.3833333333333333, 0.4,
    0.41666666666666669, 0.43333333333333335, 0.45, 0.46666666666666667,
    0.48333333333333334, 0.5, 0.51666666666666661, 0.53333333333333333, 0.55,
    0.56666666666666665, 0.58333333333333326, 0.6, 0.6166666666666667,
    0.6333333333333333, 0.65, 0.66666666666666674, 0.68333333333333335, 0.7,
    0.71666666666666667, 0.73333333333333339, 0.75, 0.76666666666666661,
    0.78333333333333333, 0.8, 0.81666666666666665, 0.83333333333333337, 0.85,
    0.8666666666666667, 0.8833333333333333, 0.9, 0.91666666666666663,
    0.93333333333333335, 0.95, 0.96666666666666667, 0.98333333333333328, 1.0 };

  static const real_T b[100] = { 0.010670000000000011, 0.015618129299747378,
    0.020296001506892716, 0.024703616621436039, 0.028840974643377336,
    0.032708075572716613, 0.036304919409453865, 0.03963150615358909,
    0.042687835805122309, 0.045473908364053496, 0.010741671544147057,
    0.015692222222222232, 0.02037251580769538, 0.024782552300566515,
    0.028922331700835628, 0.032791854008502715, 0.036391119223567775,
    0.039720127346030816, 0.042778878375891845, 0.04556737231315084,
    0.011078757424240504, 0.016031729480643488, 0.020714444444444452,
    0.025126902315643393, 0.029269103094240308, 0.0331410467802352,
    0.03674273337362808, 0.04007416287441893, 0.043135335282607774,
    0.045926250598194586, 0.011681257640280347, 0.016636651075011145,
    0.021321787417139918, 0.025736666666666672, 0.029881288823591402,
    0.033755653887914114, 0.037359761859634792, 0.040693612738753458,
    0.043757206525270105, 0.046550543219184719, 0.012549172192266598,
    0.017506987005325204, 0.022194544725781789, 0.026611845353636351,
    0.030758888888888898, 0.034635675331539419, 0.038242204681587913,
    0.041578476939034388, 0.044644492103878844, 0.047440250176121281,
    0.013682501080199246, 0.018642737271585667, 0.023332716370370061,
    0.027752438376552432, 0.031901903290132788, 0.035781111111111118,
    0.039390061839487421, 0.042728755475261705, 0.045797192018433991,
    0.04859537146900423, 0.0150812443040783, 0.020043901873792531,
    0.024736302350904734, 0.029158445735414922, 0.033310332027323086,
    0.037191961226629225, 0.040803333333333344, 0.044144448347435437,
    0.047215306268935518, 0.050015907097833566, 0.016745401863903747,
    0.021710480811945789, 0.026405302667385805, 0.030829867430223798,
    0.034984175100459779, 0.038868225678093733, 0.042482019163125655,
    0.045825555555555564, 0.048898834855383454, 0.051701857062609317,
    0.0186749737596756, 0.023642474086045456, 0.028339717319813287,
    0.032766703460979089, 0.036923432509542879, 0.040809904465504643,
    0.04442611932886438, 0.0477720770996221, 0.050847777777777804,
    0.05365322136333147, 0.020869959991393856, 0.025839881696091523,
    0.030539546308187164, 0.034968953827680775, 0.039128104254572374,
    0.043016997588861947, 0.046635633830549493, 0.04998401297963502,
    0.053062135036118542, 0.055870000000000038 };

  static const real_T c[100] = { 0.01539999999999999, 0.040819283413210207,
    0.065157538456012326, 0.088414765128406347, 0.11059096343039229,
    0.13168613336197016, 0.15170027492313992, 0.17063338811390161,
    0.18848547293425519, 0.20525652938420072, 0.014238406323287857,
    0.039477777777777751, 0.063636120861859546, 0.086713435575533265,
    0.10870972191879891, 0.12962497989165642, 0.14945920949410588,
    0.16821241072614723, 0.18588458358778051, 0.20247572807900568,
    0.014517664934424461, 0.039577124430194038, 0.063555555555555518,
    0.086452958310508893, 0.1082693326950542, 0.12900467870919144,
    0.14865899635292054, 0.16723228562624159, 0.18472454652915452,
    0.20113577906165939, 0.016237775833409816, 0.04111732337045907,
    0.064915842537100227, 0.087633333333333313, 0.10926979575915829,
    0.1298252298145752, 0.14929963549958397, 0.16769301281418469,
    0.18500536175837731, 0.20123668233216183, 0.019398739020243878,
    0.044098374598572812, 0.067716981806493659, 0.090254560644006415,
    0.11171111111111107, 0.13208663320780767, 0.15138112693409611,
    0.16959459228997653, 0.18672702927544879, 0.202778437890513,
    0.024000554494926694, 0.048520278114535319, 0.071958973363735815,
    0.094316640242528255, 0.11559327875091258, 0.13578888888888885,
    0.154903470656457, 0.17293702405361708, 0.18988954908036906,
    0.20576104573671292, 0.030043222257458254, 0.054383033918346549,
    0.077641817208826749, 0.099819572128898859, 0.12091629867856288,
    0.14093199685781882, 0.15986666666666663, 0.17772030810510642,
    0.19449292117313802, 0.21018450587076162, 0.037526742307838527,
    0.061686642010006495, 0.084765513341766366, 0.10676335630311815,
    0.12768017089406186, 0.1475159571145975, 0.16627071496472498,
    0.18394444444444441, 0.20053714555375571, 0.216048818292659,
    0.046451114646067583, 0.070431102389515235, 0.093330061762554789,
    0.11514799276518625, 0.13588489539740964, 0.15554076965922495,
    0.17411561555063212, 0.19160943307163125, 0.20802222222222225,
    0.22335398300240514, 0.056816339272145321, 0.080616415056872656,
    0.10333546247119187, 0.12497348151510304, 0.14553047218860607,
    0.16500643449170105, 0.18340136842438795, 0.20071527398666678,
    0.21694815117853741, 0.23210000000000006 };

  static const real_T d[100] = { 0.0070700000000000112, 0.025685581693398636,
    0.043220135016389181, 0.059673659968971622, 0.075046156551145993,
    0.089337624762912266, 0.10254806460427043, 0.11467747607522047,
    0.12572585917576251, 0.13569321390589639, 0.0028766489603381249,
    0.021881111111111129, 0.039804544891476036, 0.056646950301432859,
    0.0724083273409816, 0.08708867601012224, 0.10068799630885478,
    0.11320628823717924, 0.12464355179509562, 0.1349997869826039,
    -0.0010134346236644271, 0.018379907984482947, 0.03669222222222223,
    0.053923508089553422, 0.07007376558647653, 0.085142994712991554,
    0.09913119546909846, 0.11203836785479726, 0.12386451187008807,
    0.13460962751497069, -0.0046002507520076343, 0.015181972313514114,
    0.033883167008627771, 0.051503333333333338, 0.068042471287630815,
    0.083500580871520208, 0.097877662085001482, 0.11117371492807468,
    0.1233887394007398, 0.13452273550299684, -0.0078837994246914941,
    0.012287304098204626, 0.031377379250692651, 0.04938642603277258,
    0.066314444444444454, 0.0821614344857082, 0.096927396156563844,
    0.11061232945701144, 0.12321623438705095, 0.13473911094668234,
    -0.010864080641716005, 0.0096959033385544836, 0.029174858948416885,
    0.04757278618787119, 0.064889685056917418, 0.081125555555555562,
    0.096280397683785574, 0.11035421144160754, 0.12334699682902142,
    0.13525875384602717, -0.013541094403081166, 0.0074077700345637019,
    0.027275606101800472, 0.046062413798629152, 0.063768193125049763,
    0.080392944081062262, 0.09593666666666667, 0.11039936088186297,
    0.12378102672665123, 0.13608166420103138, -0.015914840708786966,
    0.00542290418623227, 0.025679620710843412, 0.044855308865046468,
    0.062949968648841448, 0.079963600062228329, 0.095896203105207078,
    0.11074777777777778, 0.12451832407994037, 0.13720784201169492,
    -0.017985319558833434, 0.003741305793560178, 0.0243869027755457,
    0.043951471387123124, 0.062435011628292472, 0.079837523499053736,
    0.096159006999406854, 0.11139946212935192, 0.12555888888888891,
    0.1386372872780178, -0.019752530953220566, 0.0023629748565474149,
    0.023397452295907305, 0.043350901364859105, 0.062223322063402822,
    0.080014714391538455, 0.096725078349265942, 0.11235441393658541,
    0.12690272115349677, 0.14037000000000002 };

  static const real_T e[100] = { 0.29967975409960163, 0.233912666284796,
    0.20404960921488507, 0.21009058288986876, 0.25203558730974712,
    0.32988462247452011, 0.44363768838418755, 0.59329478503874988,
    0.77885591243820673, 1.0003210705825585, 0.61075918186834754,
    0.56303468952046365, 0.55121422791747432, 0.57529779705937989,
    0.6352853969461798, 0.73117702757787462, 0.86297268895446377,
    1.0306723810759477, 1.2342761039423265, 1.4737838575535995,
    0.84984938795835563, 0.8201674910773934, 0.82638962494132584,
    0.86851578955015307, 0.94654598490387476, 1.0604802110024911,
    1.2103184678460022, 1.3960607554344078, 1.6177070737677082,
    1.8752574228459031, 1.0169503723696256, 1.005311070955585,
    1.0295758002864392, 1.089744560362188, 1.1858173511828316,
    1.3177941727483697, 1.4856750250588022, 1.6894599081141295,
    1.9291488219143518, 2.2047417664594686, 1.1120621351021576,
    1.1184654291550389, 1.1607727539528148, 1.2389841094954852,
    1.3530994957830504, 1.5031189128155105, 1.6890423605928646,
    1.9108698391151138, 2.1686013483822575, 2.4622368883942958,
    1.1351846761559514, 1.1596305656757542, 1.2199804859404519,
    1.3162344369500441, 1.4483924187045312, 1.6164544312039126,
    1.8204204744481887, 2.0602905484373593, 2.3360646531714249,
    2.6477427886503855, 1.0863179955310072, 1.1288064805177318,
    1.207198996249351, 1.321495542725865, 1.4716961199472738, 1.6578007279135771,
    1.8798093666247748, 2.1377220360808673, 2.4315387362818544,
    2.7612594672277364, 0.96546209322732479, 1.0259931736809711,
    1.122428284879512, 1.2547674268229476, 1.4230105995112781,
    1.6271578029445033, 1.8672090371226227, 2.143164302045637,
    2.4550235977135455, 2.80278692412635, 0.77261696924490408,
    0.85119064516547227, 0.965668351830935, 1.1160500892412923,
    1.3023358573965447, 1.5245256562966913, 1.7826194859417321,
    2.0766173463316679, 2.4065192374664988, 2.7723251593462246,
    0.50778262358374626, 0.60439889497123589, 0.73691919710362042,
    0.90534352998089951, 1.1096718936030732, 1.3499042879701417,
    1.6260407130821042, 1.9380811689389623, 2.2860256555407141,
    2.6698741728873618 };

  static const real_T f[100] = { 3.4069999999999823, -8.782110696067452,
    -9.887460495000937, -2.0279260718719794, 12.677615898247943,
    32.110288740287331, 54.151215779174656, 76.681520339838514,
    97.582325747207321, 114.73475532620965, 25.347266483404233,
    7.5641111111110888, 1.1129801380875364, 3.8749968892620941,
    13.731284689563283, 28.5629668639196, 46.251166737259524, 64.677007634511639,
    81.721612880604368, 95.266105800466278, 45.979276972078395,
    23.060105646447674, 11.72122222222222, 9.843750024330534, 15.30881237770115,
    25.997532607262549, 39.791034037943234, 54.570439994671744,
    68.216873802376583, 78.611458785986244, 65.303031466022389,
    37.705872909942272, 21.937265757403082, 15.87833333333333,
    17.410198962661529, 24.413985970316194, 34.770817681225807,
    46.361817420318914, 57.068108512524, 64.770814282769564, 83.318529965236252,
    51.50141290159489, 31.761110743630141, 21.978746816270483,
    20.035444444444444, 23.812326953080536, 31.190517667107233,
    40.051139911453092, 48.2753170110466, 53.744172290816252, 100.02577246971997,
    64.446725621405548, 41.1927571809034, 28.144990473141991, 23.184548823049884,
    24.192555555555561, 29.05013399558753, 35.638407468074305,
    41.838499297944381, 45.531532810126293, 115.42475897947357,
    76.541811069374248, 50.232205069222843, 34.377064303947876,
    26.857512098477851, 25.554671777741287, 28.349666666666671,
    33.123620090182527, 37.757655373217375, 40.1328958406997, 129.515489494497,
    87.786669245500931, 58.879454408588472, 40.674968308688094,
    31.054334270728337, 27.898675619637689, 29.089115680344676,
    32.506777777777785, 36.032785236865543, 37.548261382536438,
    142.2979640147903, 98.18130014978567, 67.134505199000316, 47.0387024873627,
    35.775015339801357, 31.2245670812448, 31.268481036621541, 33.787880530860079,
    36.663888888888906, 37.777629435636555, 153.77218254035344,
    107.72570378222841, 74.997357440458316, 53.468266839971626,
    41.019555305696883, 35.5323461625626, 34.887762735497255, 36.966928349429367,
    39.650966329287463, 40.821000000000012 };

  boolean_T exitg1;
  real_T tmp[10];
  real_T pareto_data[2];
  int32_T pareto_sizes[2];

  /* MATLAB Function: '<Root>/MATLAB Function' incorporates:
   *  Inport: '<Root>/requiredTorque'
   */
  /* MATLAB Function 'MATLAB Function': '<S1>:1' */
  /* FuelConsTable = fuel; */
  /* GasEmisTable = exhaustEmis; */
  /* requiredTorque = 189; */
  /* '<S1>:1:21' */
  /* '<S1>:1:22' */
  for (c_ixstart = 0; c_ixstart < 3721; c_ixstart++) {
    MATLAB_B.payoffMotor[c_ixstart] = 0.0;
    MATLAB_B.payoffEngine[c_ixstart] = 0.0;
  }

  /* '<S1>:1:23' */
  /* '<S1>:1:24' */
  ixstart = 1;
  mtmp = MATLAB_U.RequiredtorqueNm;
  if (rtIsNaN(MATLAB_U.RequiredtorqueNm)) {
    ixstart = 2;
    mtmp = 400.0;
  }

  if ((ixstart < 2) && (400.0 < mtmp)) {
    mtmp = 400.0;
  }

  /* '<S1>:1:25' */
  ixstart = 1;
  b_mtmp = MATLAB_U.RequiredtorqueNm;
  if (rtIsNaN(MATLAB_U.RequiredtorqueNm)) {
    ixstart = 2;
    b_mtmp = 136.0;
  }

  if ((ixstart < 2) && (136.0 < b_mtmp)) {
    b_mtmp = 136.0;
  }

  /* '<S1>:1:27' */
  /* '<S1>:1:28' */
  for (c_ixstart = 0; c_ixstart < 61; c_ixstart++) {
    strategyEng[c_ixstart] = percentage[c_ixstart] * b_mtmp;
    strategyMot[c_ixstart] = percentage[c_ixstart] * mtmp;
  }

  /* strategyMot = fliplr(strategyMot); */
  /* '<S1>:1:30' */
  MATLAB_repmat(strategyEng, MATLAB_B.tmpTorque);

  /* '<S1>:1:36' */
  /* '<S1>:1:37' */
  for (ixstart = 0; ixstart < 61; ixstart++) {
    /* '<S1>:1:37' */
    /* '<S1>:1:38' */
    for (b_j = 0; b_j < 61; b_j++) {
      /* '<S1>:1:38' */
      /* '<S1>:1:39' */
      MATLAB_B.totalTorque[ixstart + 61 * b_j] = MATLAB_B.tmpTorque[61 * b_j +
        ixstart] + strategyMot[b_j];

      /* '<S1>:1:38' */
    }

    /* '<S1>:1:37' */
  }

  /* T = P * 9.549 / n */
  /* fuelConsumedGPS = zeros(1,1); */
  /* powerKW = zeros(1,1); */
  /* HCEmissions = zeros(1,1); */
  /* COEmissions = zeros(1,1); */
  /* NOXEmissions = zeros(1,1); */
  /* '<S1>:1:64' */
  for (ixstart = 0; ixstart < 61; ixstart++) {
    /* '<S1>:1:64' */
    /* '<S1>:1:65' */
    for (b_j = 0; b_j < 61; b_j++) {
      /* '<S1>:1:65' */
      /* '<S1>:1:66' */
      for (c_ixstart = 0; c_ixstart < 10; c_ixstart++) {
        tmp[c_ixstart] = (8.1533333333333324 * (real_T)c_ixstart + 24.81) -
          strategyEng[b_j];
      }

      MATLAB_abs(tmp, tmpT);
      c_ixstart = 1;
      mtmp = tmpT[0];
      itmp = 0;
      if (rtIsNaN(tmpT[0])) {
        ix = 1;
        exitg1 = false;
        while ((!exitg1) && (ix + 1 < 11)) {
          c_ixstart = ix + 1;
          if (!rtIsNaN(tmpT[ix])) {
            mtmp = tmpT[ix];
            itmp = ix;
            exitg1 = true;
          } else {
            ix++;
          }
        }
      }

      if (c_ixstart < 10) {
        while (c_ixstart + 1 < 11) {
          if (tmpT[c_ixstart] < mtmp) {
            mtmp = tmpT[c_ixstart];
            itmp = c_ixstart;
          }

          c_ixstart++;
        }
      }

      /* '<S1>:1:70' */
      /* '<S1>:1:71' */
      /* '<S1>:1:72' */
      /* '<S1>:1:73' */
      /* '<S1>:1:74' */
      /* '<S1>:1:77' */
      MATLAB_B.payoffEngine[ixstart + 61 * b_j] = ((((fabs
        (MATLAB_U.RequiredtorqueNm - MATLAB_B.totalTorque[61 * b_j + ixstart]) +
        e[90 + itmp] * 60.0) + 1.05) + b[90 + itmp] * 45.0) + c[90 + itmp] *
        56.0) + d[90 + itmp] * 28.0;

      /* '<S1>:1:78' */
      MATLAB_B.payoffMotor[ixstart + 61 * b_j] = ((((fabs
        (MATLAB_U.RequiredtorqueNm - MATLAB_B.totalTorque[61 * b_j + ixstart]) +
        f[90 + itmp] * 0.5) + 1.05) + b[90 + itmp] * 45.0) + c[90 + itmp] * 56.0)
        + d[90 + itmp] * 28.0;

      /* '<S1>:1:65' */
    }

    /* '<S1>:1:64' */
  }

  /* '<S1>:1:82' */
  for (c_ixstart = 0; c_ixstart < 61; c_ixstart++) {
    memcpy(&MATLAB_B.x[122 * c_ixstart], &MATLAB_B.payoffMotor[61 * c_ixstart],
           61U * sizeof(real_T));
  }

  for (c_ixstart = 0; c_ixstart < 61; c_ixstart++) {
    memcpy(&MATLAB_B.x[122 * c_ixstart + 61], &MATLAB_B.payoffEngine[61 *
           c_ixstart], 61U * sizeof(real_T));
  }

  memcpy(&MATLAB_B.payoffBoth[0], &MATLAB_B.x[0], 7442U * sizeof(real_T));

  /* payoff = mat2cell(payoffBoth, ones(1,M+1), ones(1,M+1).*2); */
  /* '<S1>:1:88' */
  MATLAB_paretoSet(MATLAB_B.payoffBoth, pareto_data, pareto_sizes);

  /* Outport: '<Root>/engineTorque' incorporates:
   *  MATLAB Function: '<Root>/MATLAB Function'
   */
  /* '<S1>:1:92' */
  /* '<S1>:1:93' */
  MATLAB_Y.engineTorque = strategyEng[(int32_T)pareto_data[1] - 1];

  /* Outport: '<Root>/motorTorque' incorporates:
   *  MATLAB Function: '<Root>/MATLAB Function'
   */
  MATLAB_Y.motorTorque = strategyMot[(int32_T)pareto_data[0] - 1];

  /* Matfile logging */
  rt_UpdateTXYLogVars(MATLAB_M->rtwLogInfo, (&MATLAB_M->Timing.taskTime0));

  /* signal main to stop simulation */
  {                                    /* Sample time: [6.0E-5s, 0.0s] */
    if ((rtmGetTFinal(MATLAB_M)!=-1) &&
        !((rtmGetTFinal(MATLAB_M)-MATLAB_M->Timing.taskTime0) >
          MATLAB_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(MATLAB_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++MATLAB_M->Timing.clockTick0)) {
    ++MATLAB_M->Timing.clockTickH0;
  }

  MATLAB_M->Timing.taskTime0 = MATLAB_M->Timing.clockTick0 *
    MATLAB_M->Timing.stepSize0 + MATLAB_M->Timing.clockTickH0 *
    MATLAB_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void MATLAB_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)MATLAB_M, 0,
                sizeof(RT_MODEL_MATLAB_T));
  rtmSetTFinal(MATLAB_M, 9.99996);
  MATLAB_M->Timing.stepSize0 = 6.0E-5;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    MATLAB_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(MATLAB_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(MATLAB_M->rtwLogInfo, (NULL));
    rtliSetLogT(MATLAB_M->rtwLogInfo, "tout");
    rtliSetLogX(MATLAB_M->rtwLogInfo, "");
    rtliSetLogXFinal(MATLAB_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(MATLAB_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(MATLAB_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(MATLAB_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(MATLAB_M->rtwLogInfo, 1);

    /*
     * Set pointers to the data and signal info for each output
     */
    {
      static void * rt_LoggedOutputSignalPtrs[] = {
        &MATLAB_Y.engineTorque,
        &MATLAB_Y.motorTorque
      };

      rtliSetLogYSignalPtrs(MATLAB_M->rtwLogInfo, ((LogSignalPtrsType)
        rt_LoggedOutputSignalPtrs));
    }

    {
      static int_T rt_LoggedOutputWidths[] = {
        1,
        1
      };

      static int_T rt_LoggedOutputNumDimensions[] = {
        1,
        1
      };

      static int_T rt_LoggedOutputDimensions[] = {
        1,
        1
      };

      static boolean_T rt_LoggedOutputIsVarDims[] = {
        0,
        0
      };

      static void* rt_LoggedCurrentSignalDimensions[] = {
        (NULL),
        (NULL)
      };

      static int_T rt_LoggedCurrentSignalDimensionsSize[] = {
        4,
        4
      };

      static BuiltInDTypeId rt_LoggedOutputDataTypeIds[] = {
        SS_DOUBLE,
        SS_DOUBLE
      };

      static int_T rt_LoggedOutputComplexSignals[] = {
        0,
        0
      };

      static const char_T *rt_LoggedOutputLabels[] = {
        "engineTorque",
        "motorTorque" };

      static const char_T *rt_LoggedOutputBlockNames[] = {
        "MATLAB/engineTorque",
        "MATLAB/motorTorque" };

      static RTWLogDataTypeConvert rt_RTWLogDataTypeConvert[] = {
        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 }
      };

      static RTWLogSignalInfo rt_LoggedOutputSignalInfo[] = {
        {
          2,
          rt_LoggedOutputWidths,
          rt_LoggedOutputNumDimensions,
          rt_LoggedOutputDimensions,
          rt_LoggedOutputIsVarDims,
          rt_LoggedCurrentSignalDimensions,
          rt_LoggedCurrentSignalDimensionsSize,
          rt_LoggedOutputDataTypeIds,
          rt_LoggedOutputComplexSignals,
          (NULL),

          { rt_LoggedOutputLabels },
          (NULL),
          (NULL),
          (NULL),

          { rt_LoggedOutputBlockNames },

          { (NULL) },
          (NULL),
          rt_RTWLogDataTypeConvert
        }
      };

      rtliSetLogYSignalInfo(MATLAB_M->rtwLogInfo, rt_LoggedOutputSignalInfo);

      /* set currSigDims field */
      rt_LoggedCurrentSignalDimensions[0] = &rt_LoggedOutputWidths[0];
      rt_LoggedCurrentSignalDimensions[1] = &rt_LoggedOutputWidths[1];
    }

    rtliSetLogY(MATLAB_M->rtwLogInfo, "yout");
  }

  /* external inputs */
  MATLAB_U.RequiredtorqueNm = 0.0;

  /* external outputs */
  (void) memset((void *)&MATLAB_Y, 0,
                sizeof(ExtY_MATLAB_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(MATLAB_M->rtwLogInfo, 0.0, rtmGetTFinal
    (MATLAB_M), MATLAB_M->Timing.stepSize0, (&rtmGetErrorStatus(MATLAB_M)));
}

/* Model terminate function */
void MATLAB_terminate(void)
{
  /* (no terminate code required) */
}
