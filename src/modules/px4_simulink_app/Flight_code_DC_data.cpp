//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Flight_code_DC_data.cpp
//
// Code generated for Simulink model 'Flight_code_DC'.
//
// Model version                  : 1.227
// Simulink Coder version         : 9.0 (R2018b) 24-May-2018
// C/C++ source code generated on : Tue Jun  4 18:27:06 2019
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "Flight_code_DC.h"
#include "Flight_code_DC_private.h"

// Block parameters (default storage)
P_Flight_code_DC_T Flight_code_DC_P = {
  // Variable: AILERON_LIMITS
  //  Referenced by:
  //    '<S9>/Gain1'
  //    '<S12>/Gain'
  //    '<S79>/Gain1'
  //    '<S122>/Gain1'
  //    '<S103>/max deflection limit'
  //    '<S103>/max deflection limit '
  //    '<S103>/max limit'
  //    '<S103>/min deflection limit'
  //    '<S103>/min deflection limit '
  //    '<S103>/min limit'
  //    '<S146>/max deflection limit'
  //    '<S146>/max deflection limit '
  //    '<S146>/max limit'
  //    '<S146>/min deflection limit'
  //    '<S146>/min deflection limit '
  //    '<S146>/min limit'

  0.2618,

  // Variable: BANK_LIMITS
  //  Referenced by:
  //    '<S79>/Gain6'
  //    '<S122>/Gain6'

  1.0,

  // Variable: BETA_LIMITS
  //  Referenced by:
  //    '<S79>/Gain3'
  //    '<S122>/Gain3'

  1.0,

  // Variable: ELEVATOR_LIMITS
  //  Referenced by:
  //    '<S9>/Gain4'
  //    '<S12>/Gain2'
  //    '<S79>/Gain4'
  //    '<S122>/Gain4'
  //    '<S93>/min deflection limit'
  //    '<S94>/max deflection limit'
  //    '<S94>/max deflection limit '
  //    '<S94>/max limit'
  //    '<S94>/min deflection limit'
  //    '<S94>/min deflection limit '
  //    '<S94>/min limit'
  //    '<S136>/min deflection limit'
  //    '<S137>/max deflection limit'
  //    '<S137>/max deflection limit '
  //    '<S137>/max limit'
  //    '<S137>/min deflection limit'
  //    '<S137>/min deflection limit '
  //    '<S137>/min limit'

  0.2618,

  // Variable: F11
  //  Referenced by:
  //    '<S80>/F11'
  //    '<S123>/F11'

  { -2.5919152360261988, -3.2726178269872341, -3.778710996268364,
    -4.3833763481134209, -4.5308368019535967, -4.6010233160116982,
    -4.6090027787983043, -4.5668079926392826, -4.4841075704060431,
    -4.3685716483300441, -4.22633272601694, -4.0622863635388358,
    -3.8803697407440718, -3.6838487975923426, -3.4754144087629362,
    -3.2574166012868111, -3.03201801406186, -2.8012722033431134,
    -2.5673835207390279, -2.3328050287455131, -2.1005347077285368,
    -1.8744798725504677, -1.6599739817138304, -1.4646974927224541,
    -1.3001998233554066, -1.1847822800239369, -1.1492372830329591,
    -1.2496125557291682, -1.6000109147514956, -2.4753162615021869 },

  // Variable: F12
  //  Referenced by:
  //    '<S80>/F12'
  //    '<S123>/F12'

  { -14.996394326847184, -17.094229083819855, -18.833263722807025,
    -21.441198576321096, -22.40255217411169, -23.186882383312124,
    -23.825343522064777, -24.343281741135424, -24.761451585573411,
    -25.096767361972304, -25.362748267359237, -25.570315367238084,
    -25.728015453841955, -25.842697692631145, -25.919715482698113,
    -25.963169785283235, -25.976080840499847, -25.960545953199354,
    -25.917798336085038, -25.848333214138375, -25.751709572858772,
    -25.6266552926675, -25.470778281820703, -25.28029680204785,
    -25.049361361168032, -24.768976313402636, -24.424710588137778,
    -23.991657590735958, -23.41948274676675, -22.575588285447978 },

  // Variable: F13
  //  Referenced by:
  //    '<S80>/F13'
  //    '<S123>/F13'

  { 4.6866261426469489, 4.8795673701900464, 5.0402771394703754, 5.28339628648164,
    5.3740578080237045, 5.4486863476441441, 5.5100374165059778, 5.5603313398431,
    5.6013568758763244, 5.6345529838966035, 5.6610407442528947,
    5.6816845551892063, 5.6971409409246885, 5.7078780163787313,
    5.7142208628759086, 5.7163633943663053, 5.7143730044924981,
    5.7082056630279423, 5.6976990366817342, 5.6825735222295339,
    5.662404306318189, 5.6365938289332362, 5.6043170865715286, 5.564428816916295,
    5.5152999416850328, 5.4545112647519929, 5.3782594180851673,
    5.279952262581614, 5.1462251375279449, 4.9414233669990217 },

  // Variable: F14
  //  Referenced by:
  //    '<S80>/F14'
  //    '<S123>/F14'

  { 157.19565384641319, 172.53124151130893, 185.88526648094472,
    207.82234091433693, 216.95236884940527, 225.17016954090695,
    232.67360465283372, 239.6295778332269, 246.1797444634075, 252.44682239883298,
    258.53691855551597, 264.54515317971027, 270.55776860532711,
    276.6556832908966, 282.92185609611931, 289.44118048688949,
    296.30609204621993, 303.62427190239669, 311.52330855374453,
    320.16535215093222, 329.76036800245231, 340.59390188152162,
    353.07118926800428, 367.79295058625024, 385.70508779477251,
    408.40139814348129, 438.8330876231077, 483.26813684139137,
    558.29980297738132, 731.94128276877984 },

  // Variable: F21
  //  Referenced by:
  //    '<S80>/F21'
  //    '<S123>/F21'

  { -6.3778558373341179, -6.6910606596766344, -6.9931187324868818,
    -7.5464626046114454, -7.7944473881274057, -8.02319773871751,
    -8.23360184617758, -8.4268203760851446, -8.6041357475937961,
    -8.7669393748976638, -8.9165220233122842, -9.0541236656567214,
    -9.1808684903797566, -9.2977428871649952, -9.405674612937629,
    -9.505459787193411, -9.5977808596580179, -9.6832606623790518,
    -9.7623933437999071, -9.8356304424195411, -9.90332904172132,
    -9.9657744474907, -10.023176764843301, -10.075665806303206,
    -10.12326499924475, -10.165828288390657, -10.202883159097317,
    -10.233183531591823, -10.253164266825051, -10.250134801371559 },

  // Variable: F22
  //  Referenced by:
  //    '<S80>/F22'
  //    '<S123>/F22'

  { 11.048680208147093, 10.471485158123816, 9.8915749768145549, 8.77452887934645,
    8.2507414211561709, 7.7538573129547679, 7.2840489100795072,
    6.8405360767409107, 6.42193486561779, 6.0263061968434339, 5.6516989474905683,
    5.2960554082116928, 4.9573961460606819, 4.6339169709793531,
    4.3237869492897776, 4.0253744904392805, 3.7372271586746897,
    3.4579186415286469, 3.1863066962890971, 2.9212519736009432,
    2.661842667635502, 2.4073332154021077, 2.1572149374825864,
    1.9112833931810138, 1.6698247455857025, 1.433962865349472,
    1.2063297689532677, 0.99247401106555655, 0.80413874255560558,
    0.66471750469369262 },

  // Variable: F23
  //  Referenced by:
  //    '<S80>/F23'
  //    '<S123>/F23'

  { -0.86790312246404766, -0.81936682640986536, -0.7703716906337591,
    -0.67578499236261713, -0.63147065963292015, -0.58951667010502906,
    -0.54996208381630562, -0.51275461553526924, -0.47778510263031015,
    -0.44489584097108931, -0.41392542013952965, -0.38470340544959813,
    -0.35706741466240249, -0.33087122651687845, -0.30596930031784692,
    -0.28223712983737326, -0.259568943781799, -0.23786776326980763,
    -0.21706748076565693, -0.19711334575063, -0.17798349584236989,
    -0.15968968129887556, -0.14229289654990629, -0.12592319391450732,
    -0.11082171735687625, -0.097415688676618775, -0.086465137208833254,
    -0.079379114290315328, -0.078974782802440732, -0.091384730753718529 },

  // Variable: F24
  //  Referenced by:
  //    '<S80>/F24'
  //    '<S123>/F24'

  { -89.405698659618338, -86.236506448526342, -82.9743119015554,
    -76.51184065122132, -73.406870394439864, -70.41657864450444,
    -67.546556818239708, -64.795481028317852, -62.157393846063592,
    -59.622123787063643, -57.178689752377778, -54.8146226151925,
    -52.517284252983444, -50.274526077495558, -48.073233113075453,
    -45.900913211757278, -43.745477447423532, -41.5939884741656,
    -39.434639002517081, -37.254412285172968, -35.040649943750658,
    -32.780629878132558, -30.462167026842195, -28.074480267984715,
    -25.611484238290771, -23.079544924270294, -20.518576258930072,
    -18.066158572265671, -16.20464901329321, -17.202344913965014 },

  // Variable: FI11
  //  Referenced by:
  //    '<S80>/FI11'
  //    '<S123>/FI11'

  { 98.53781919596382, 99.842480985876662, 99.881236796966363,
    97.315402336889179, 95.144156224899575, 92.5889154387105, 89.757205579527039,
    86.728676194970149, 83.561550936169127, 80.295999328630955,
    76.960617404882242, 73.573912283058092, 70.147620101876143,
    66.689022264975748, 63.200079002090455, 59.68049889067062, 56.1284152590793,
    52.539185016723387, 48.908816063073843, 45.231148397846084,
    41.500711237237027, 37.712453892446483, 33.86277358027295,
    29.950836835275496, 25.981481777089087, 21.971114787206925,
    17.960009230173547, 14.040770921461082, 10.43860736646722,
    7.7801552570939752 },

  // Variable: FI12
  //  Referenced by:
  //    '<S80>/FI12'
  //    '<S123>/FI12'

  { -17.03813922038244, -5.6106140986289521, 4.872220838286534,
    23.015483223560949, 30.7829422935324, 37.779528026214756, 44.086778591269749,
    49.780887150261854, 54.931477361727985, 59.603292625608042,
    63.851886179345563, 67.726504644503251, 71.269287873837911,
    74.515597758747944, 77.496774217584274, 80.238631918540861,
    82.762316307025344, 85.08603902978551, 87.223435562404632, 89.18600346809346,
    90.981816682258014, 92.6162557082154, 94.0920430506843, 95.409367322429887,
    96.565845953253231, 97.5564970414966, 98.373970482302568, 99.0093770909235,
    99.453685081290814, 99.696886531999368 },

  // Variable: FI21
  //  Referenced by:
  //    '<S80>/FI21'
  //    '<S123>/FI21'

  { -5.3879327027336332, -1.7742319623659464, 1.5407315112453857,
    7.278134843583139, 9.7344210729157989, 11.946935748900378,
    13.941463504795514, 15.742098733864829, 17.370858370103054,
    18.848216074248231, 20.191739322452495, 21.41700126386446,
    22.537327689952761, 23.563901012653186, 24.506631784336, 25.373683319850372,
    26.171742396150787, 26.906568041611195, 27.582472172211926,
    28.203090636686927, 28.770976637583221, 29.287831639453497,
    29.754516573877464, 30.171091085451927, 30.536801739322161,
    30.850073119860564, 31.108580919823385, 31.309514132178862,
    31.450016655398837, 31.52692370685044 },

  // Variable: FI22
  //  Referenced by:
  //    '<S80>/FI22'
  //    '<S123>/FI22'

  { -31.16039443252637, -31.572964715771445, -31.585220379318319,
    -30.773832280016467, -30.087223972562093, -29.279185887105125,
    -28.383720604326257, -27.426015522734115, -26.424482577447151,
    -25.391824487784241, -24.337084113223838, -23.266113918392278,
    -22.182625196213596, -21.088920528701848, -19.985619794916794,
    -18.872630838967076, -17.749363367442964, -16.614349106183589,
    -15.466325642154205, -14.303345012227982, -13.123677202661304,
    -11.925725045422904, -10.708349240422161, -9.4712862227554542,
    -8.2160659401762786, -6.9478765460583025, -5.6794535964995561,
    -4.4400816216456889, -3.3009774878242109, -2.4603011162151205 },

  // Variable: K11
  //  Referenced by:
  //    '<S71>/K11'
  //    '<S74>/K11'

  { 0.002025034075595079, 0.0019846133095037435, 0.0019434993566921955,
    0.0019016418144542444, 0.0018589885520496295, 0.0018154721686158919,
    0.0017709471757139251, 0.0017084631482386331, 0.0016456416954401959,
    0.0015823305494132979, 0.0015183540801744859, 0.0014534567863803006,
    0.0013873110682164663, 0.0013194585955558405, 0.0012492156279162582,
    0.0011192826969567114, 0.00099284547416194887, 0.00086620491075722937,
    0.00063986469530286441 },

  // Variable: K12
  //  Referenced by:
  //    '<S71>/K12'
  //    '<S74>/K12'

  { -0.00096944691382368014, -0.00095009623354929936, -0.00093041370319168462,
    -0.0009103751934046373, -0.00088995574757846311, -0.00086912309882009,
    -0.00084780759728015655, -0.00081789454627070315, -0.00078781995924458376,
    -0.00075751094081067793, -0.00072688341142320551, -0.00069581505462742825,
    -0.00066414903818386162, -0.00063166594517868576, -0.00059803844773712392,
    -0.00053583550486291007, -0.00047530606641636594, -0.00041467928248359152,
    -0.00030632316838613853 },

  // Variable: K13
  //  Referenced by:
  //    '<S71>/K13'
  //    '<S74>/K13'

  { -0.00098557017371387473, -0.00096589766452581161, -0.0009458877861228314,
    -0.00092551600785407875, -0.0009047569580463695, -0.00088357783316296448,
    -0.00086190782497995791, -0.00083149727803888125, -0.00080092250851095733,
    -0.00077010940865267176, -0.00073897250055754492, -0.00070738743347688326,
    -0.00067519476683151078, -0.00064217143449701549, -0.00060798466467766024,
    -0.00054474719974792745, -0.00048321107196839234, -0.00042157597971083182,
    -0.00031141775168286637 },

  // Variable: K31
  //  Referenced by:
  //    '<S71>/K31'
  //    '<S74>/K31'

  { -0.044505770269136873, -0.0451719659948086, -0.045898801413516217,
    -0.046695683951330884, -0.047574039170875194, -0.048548196868959691,
    -0.049636420772976343, -0.050867559388662921, -0.052266471842467986,
    -0.053874520089820459, -0.055748339274791482, -0.057969567960509533,
    -0.060659293015630583, -0.064007463550380242, -0.068333983994374445,
    -0.07424538396855139, -0.082970306560938512, -0.097795226018073778,
    -0.13220115381851191 },

  // Variable: K32
  //  Referenced by:
  //    '<S71>/K32'
  //    '<S74>/K32'

  { -0.0057275289184618994, -0.0058027529297078337, -0.0058852678070702626,
    -0.0059762131191428485, -0.006076974251350553, -0.006189288436636832,
    -0.0063153577885564915, -0.0064552334402446752, -0.0066154590951377195,
    -0.0068010408370446328, -0.007018838458691193, -0.0072787398628286039,
    -0.0075954189457758054, -0.00799190342171555, -0.0085069895036106,
    -0.0092041296264494515, -0.010243709768134115, -0.012024481202360765,
    -0.01616769924729038 },

  // Variable: K33
  //  Referenced by:
  //    '<S71>/K33'
  //    '<S74>/K33'

  { 0.026490444753738324, 0.026885095907911084, 0.027315748993614788,
    0.027787990739049442, 0.028308606611475308, 0.028886106804911202,
    0.029531335649227761, 0.03026081002856558, 0.0310899239619939,
    0.032043240042868272, 0.03315439169738571, 0.034471860851607757,
    0.036067557671692486, 0.038054289282405646, 0.040622043255811036,
    0.044129225411364076, 0.049307546453194129, 0.058108839000417592,
    0.078536883200415047 },

  // Variable: K_RUDDER_AILERON
  //  Referenced by:
  //    '<S24>/K_RUDDER_AILERON'
  //    '<S25>/K_RUDDER_AILERON'
  //    '<S45>/K_RUDDER_AILERON'
  //    '<S46>/Constant'
  //    '<S73>/Constant'
  //    '<S76>/Constant'

  0.0095477386934673357,

  // Variable: K_phi
  //  Referenced by:
  //    '<S78>/Gain'
  //    '<S121>/Gain'

  3.3,

  // Variable: Ki_Beta
  //  Referenced by:
  //    '<S77>/Gain2'
  //    '<S120>/Gain2'

  4.5,

  // Variable: Ki_p
  //  Referenced by:
  //    '<S104>/Gain2'
  //    '<S147>/Gain2'

  24.2,

  // Variable: Kp_Beta
  //  Referenced by:
  //    '<S77>/Gain'
  //    '<S120>/Gain'

  0.6,

  // Variable: Kp_p
  //  Referenced by:
  //    '<S104>/Gain'
  //    '<S147>/Gain'

  0.02269,

  // Variable: REF_SPEED
  //  Referenced by:
  //    '<S77>/Constant'
  //    '<S86>/Constant'
  //    '<S120>/Constant'
  //    '<S129>/Constant'
  //    '<S104>/Constant'
  //    '<S147>/Constant'

  21.0914,

  // Variable: RUDDER_LIMITS
  //  Referenced by:
  //    '<S9>/Gain2'
  //    '<S12>/Gain1'
  //    '<S79>/Gain2'
  //    '<S122>/Gain2'
  //    '<S88>/max deflection limit'
  //    '<S88>/max deflection limit '
  //    '<S88>/max limit'
  //    '<S88>/min deflection limit'
  //    '<S88>/min deflection limit '
  //    '<S88>/min limit'
  //    '<S131>/max deflection limit'
  //    '<S131>/max deflection limit '
  //    '<S131>/max limit'
  //    '<S131>/min deflection limit'
  //    '<S131>/min deflection limit '
  //    '<S131>/min limit'

  0.2618,

  // Variable: V0
  //  Referenced by:
  //    '<S80>/F11'
  //    '<S80>/F12'
  //    '<S80>/F13'
  //    '<S80>/F14'
  //    '<S80>/F21'
  //    '<S80>/F22'
  //    '<S80>/F23'
  //    '<S80>/F24'
  //    '<S80>/FI11'
  //    '<S80>/FI12'
  //    '<S80>/FI21'
  //    '<S80>/FI22'
  //    '<S123>/F11'
  //    '<S123>/F12'
  //    '<S123>/F13'
  //    '<S123>/F14'
  //    '<S123>/F21'
  //    '<S123>/F22'
  //    '<S123>/F23'
  //    '<S123>/F24'
  //    '<S123>/FI11'
  //    '<S123>/FI12'
  //    '<S123>/FI21'
  //    '<S123>/FI22'

  { 6.29635, 6.34152, 6.38935, 6.494, 6.5514, 6.61262, 6.67808, 6.74823, 6.82358,
    6.90477, 6.99252, 7.08769, 7.1913, 7.30456, 7.42898, 7.56641, 7.71913,
    7.89007, 8.08294, 8.30269, 8.55592, 8.85177, 9.20332, 9.63004, 10.16255,
    10.8523, 11.79421, 13.18909, 15.56644, 21.09143 },

  // Variable: VELOCITY_LIMITS
  //  Referenced by:
  //    '<S79>/Gain7'
  //    '<S122>/Gain7'

  1.0,

  // Variable: V_K_SAS
  //  Referenced by:
  //    '<S71>/K11'
  //    '<S71>/K12'
  //    '<S71>/K13'
  //    '<S71>/K31'
  //    '<S71>/K32'
  //    '<S71>/K33'
  //    '<S74>/K11'
  //    '<S74>/K12'
  //    '<S74>/K13'
  //    '<S74>/K31'
  //    '<S74>/K32'
  //    '<S74>/K33'

  { 7.13787, 7.24194, 7.3556, 7.48034, 7.61797, 7.77076, 7.9416, 8.13415,
    8.35328, 8.60554, 8.8999, 9.24929, 9.67289, 10.20079, 10.88367, 11.81495,
    13.19228, 15.53636, 20.97928 },

  // Variable: W_LIMITS
  //  Referenced by:
  //    '<S79>/Gain5'
  //    '<S122>/Gain5'

  1.0,

  // Variable: BIAS_CONRAD
  //  Referenced by: '<S32>/Bias'

  -0.0029F,

  // Variable: K_d_b
  //  Referenced by:
  //    '<S114>/Gain4'
  //    '<S114>/Gain5'
  //    '<S157>/Gain4'
  //    '<S157>/Gain5'

  1.0F,

  // Variable: Kp_r
  //  Referenced by:
  //    '<S86>/Gain3'
  //    '<S129>/Gain3'

  -0.16F,

  // Variable: SCALE_CONRAD
  //  Referenced by: '<S32>/Gain1'

  0.275801212F,

  // Computed Parameter: Out1_Y0
  //  Referenced by: '<S33>/Out1'

  {
    0.0,                               // timestamp

    {
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // vel_pos_innov

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // mag_innov
    0.0F,                              // heading_innov
    0.0F,                              // airspeed_innov
    0.0F,                              // beta_innov

    {
      0.0F, 0.0F }
    ,                                  // flow_innov
    0.0F,                              // hagl_innov

    {
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // vel_pos_innov_var

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // mag_innov_var
    0.0F,                              // heading_innov_var
    0.0F,                              // airspeed_innov_var
    0.0F,                              // beta_innov_var

    {
      0.0F, 0.0F }
    ,                                  // flow_innov_var
    0.0F,                              // hagl_innov_var

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // output_tracking_error

    {
      0.0F, 0.0F }
    ,                                  // drag_innov

    {
      0.0F, 0.0F }
    ,                                  // drag_innov_var

    {
      0.0F, 0.0F }
    ,                                  // aux_vel_innov

    {
      0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value
  //  Referenced by: '<S31>/Constant'

  {
    0.0,                               // timestamp

    {
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // vel_pos_innov

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // mag_innov
    0.0F,                              // heading_innov
    0.0F,                              // airspeed_innov
    0.0F,                              // beta_innov

    {
      0.0F, 0.0F }
    ,                                  // flow_innov
    0.0F,                              // hagl_innov

    {
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // vel_pos_innov_var

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // mag_innov_var
    0.0F,                              // heading_innov_var
    0.0F,                              // airspeed_innov_var
    0.0F,                              // beta_innov_var

    {
      0.0F, 0.0F }
    ,                                  // flow_innov_var
    0.0F,                              // hagl_innov_var

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // output_tracking_error

    {
      0.0F, 0.0F }
    ,                                  // drag_innov

    {
      0.0F, 0.0F }
    ,                                  // drag_innov_var

    {
      0.0F, 0.0F }
    ,                                  // aux_vel_innov

    {
      0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Out1_Y0_h
  //  Referenced by: '<S53>/Out1'

  {
    0.0,                               // timestamp
    0.0,                               // ref_timestamp
    0.0,                               // ref_lat
    0.0,                               // ref_lon
    0.0F,                              // x
    0.0F,                              // y
    0.0F,                              // z

    {
      0.0F, 0.0F }
    ,                                  // delta_xy
    0.0F,                              // delta_z
    0.0F,                              // vx
    0.0F,                              // vy
    0.0F,                              // vz
    0.0F,                              // z_deriv

    {
      0.0F, 0.0F }
    ,                                  // delta_vxy
    0.0F,                              // delta_vz
    0.0F,                              // ax
    0.0F,                              // ay
    0.0F,                              // az
    0.0F,                              // yaw
    0.0F,                              // ref_alt
    0.0F,                              // dist_bottom
    0.0F,                              // dist_bottom_rate
    0.0F,                              // eph
    0.0F,                              // epv
    0.0F,                              // evh
    0.0F,                              // evv
    0.0F,                              // vxy_max
    0.0F,                              // vz_max
    0.0F,                              // hagl_min
    0.0F,                              // hagl_max
    false,                             // xy_valid
    false,                             // z_valid
    false,                             // v_xy_valid
    false,                             // v_z_valid
    0U,                                // xy_reset_counter
    0U,                                // z_reset_counter
    0U,                                // vxy_reset_counter
    0U,                                // vz_reset_counter
    false,                             // xy_global
    false,                             // z_global
    false,                             // dist_bottom_valid

    {
      0U, 0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_j
  //  Referenced by: '<S50>/Constant'

  {
    0.0,                               // timestamp
    0.0,                               // ref_timestamp
    0.0,                               // ref_lat
    0.0,                               // ref_lon
    0.0F,                              // x
    0.0F,                              // y
    0.0F,                              // z

    {
      0.0F, 0.0F }
    ,                                  // delta_xy
    0.0F,                              // delta_z
    0.0F,                              // vx
    0.0F,                              // vy
    0.0F,                              // vz
    0.0F,                              // z_deriv

    {
      0.0F, 0.0F }
    ,                                  // delta_vxy
    0.0F,                              // delta_vz
    0.0F,                              // ax
    0.0F,                              // ay
    0.0F,                              // az
    0.0F,                              // yaw
    0.0F,                              // ref_alt
    0.0F,                              // dist_bottom
    0.0F,                              // dist_bottom_rate
    0.0F,                              // eph
    0.0F,                              // epv
    0.0F,                              // evh
    0.0F,                              // evv
    0.0F,                              // vxy_max
    0.0F,                              // vz_max
    0.0F,                              // hagl_min
    0.0F,                              // hagl_max
    false,                             // xy_valid
    false,                             // z_valid
    false,                             // v_xy_valid
    false,                             // v_z_valid
    0U,                                // xy_reset_counter
    0U,                                // z_reset_counter
    0U,                                // vxy_reset_counter
    0U,                                // vz_reset_counter
    false,                             // xy_global
    false,                             // z_global
    false,                             // dist_bottom_valid

    {
      0U, 0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Out1_Y0_p
  //  Referenced by: '<S52>/Out1'

  {
    0.0,                               // timestamp
    0.0,                               // time_utc_usec
    0,                                 // lat
    0,                                 // lon
    0,                                 // alt
    0,                                 // alt_ellipsoid
    0.0F,                              // s_variance_m_s
    0.0F,                              // c_variance_rad
    0.0F,                              // eph
    0.0F,                              // epv
    0.0F,                              // hdop
    0.0F,                              // vdop
    0,                                 // noise_per_ms
    0,                                 // jamming_indicator
    0.0F,                              // vel_m_s
    0.0F,                              // vel_n_m_s
    0.0F,                              // vel_e_m_s
    0.0F,                              // vel_d_m_s
    0.0F,                              // cog_rad
    0,                                 // timestamp_time_relative
    0U,                                // fix_type
    false,                             // vel_ned_valid
    0U,                                // satellites_used

    {
      0U, 0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_b
  //  Referenced by: '<S51>/Constant'

  {
    0.0,                               // timestamp
    0.0,                               // time_utc_usec
    0,                                 // lat
    0,                                 // lon
    0,                                 // alt
    0,                                 // alt_ellipsoid
    0.0F,                              // s_variance_m_s
    0.0F,                              // c_variance_rad
    0.0F,                              // eph
    0.0F,                              // epv
    0.0F,                              // hdop
    0.0F,                              // vdop
    0,                                 // noise_per_ms
    0,                                 // jamming_indicator
    0.0F,                              // vel_m_s
    0.0F,                              // vel_n_m_s
    0.0F,                              // vel_e_m_s
    0.0F,                              // vel_d_m_s
    0.0F,                              // cog_rad
    0,                                 // timestamp_time_relative
    0U,                                // fix_type
    false,                             // vel_ned_valid
    0U,                                // satellites_used

    {
      0U, 0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Out1_Y0_g
  //  Referenced by: '<S70>/Out1'

  {
    0.0,                               // timestamp
    0.0,                               // timestamp_last_signal
    0U,                                // channel_count
    0,                                 // rssi
    0U,                                // rc_lost_frame_count
    0U,                                // rc_total_frame_count
    0U,                                // rc_ppm_frame_length

    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
    ,                                  // values
    false,                             // rc_failsafe
    false,                             // rc_lost
    0U,                                // input_source

    {
      0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_o
  //  Referenced by: '<S69>/Constant'

  {
    0.0,                               // timestamp
    0.0,                               // timestamp_last_signal
    0U,                                // channel_count
    0,                                 // rssi
    0U,                                // rc_lost_frame_count
    0U,                                // rc_total_frame_count
    0U,                                // rc_ppm_frame_length

    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
    ,                                  // values
    false,                             // rc_failsafe
    false,                             // rc_lost
    0U,                                // input_source

    {
      0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Out1_Y0_f
  //  Referenced by: '<S30>/Out1'

  {
    0.0,                               // timestamp
    0.0,                               // integral_dt
    0.0,                               // error_count
    0.0F,                              // x
    0.0F,                              // y
    0.0F,                              // z
    0.0F,                              // x_integral
    0.0F,                              // y_integral
    0.0F,                              // z_integral
    0.0F,                              // temperature
    0.0F,                              // range_m_s2
    0.0F,                              // scaling
    0U,                                // device_id
    0,                                 // x_raw
    0,                                 // y_raw
    0,                                 // z_raw
    0                                  // temperature_raw
  },

  // Computed Parameter: Constant_Value_m
  //  Referenced by: '<S29>/Constant'

  {
    0.0,                               // timestamp
    0.0,                               // integral_dt
    0.0,                               // error_count
    0.0F,                              // x
    0.0F,                              // y
    0.0F,                              // z
    0.0F,                              // x_integral
    0.0F,                              // y_integral
    0.0F,                              // z_integral
    0.0F,                              // temperature
    0.0F,                              // range_m_s2
    0.0F,                              // scaling
    0U,                                // device_id
    0,                                 // x_raw
    0,                                 // y_raw
    0,                                 // z_raw
    0                                  // temperature_raw
  },

  // Computed Parameter: Out1_Y0_d
  //  Referenced by: '<S44>/Out1'

  {
    0.0,                               // timestamp
    0.0F,                              // rollspeed
    0.0F,                              // pitchspeed
    0.0F,                              // yawspeed

    {
      0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // q

    {
      0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // delta_q_reset
    0U,                                // quat_reset_counter

    {
      0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_p
  //  Referenced by: '<S43>/Constant'

  {
    0.0,                               // timestamp
    0.0F,                              // rollspeed
    0.0F,                              // pitchspeed
    0.0F,                              // yawspeed

    {
      0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // q

    {
      0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // delta_q_reset
    0U,                                // quat_reset_counter

    {
      0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Out1_Y0_m
  //  Referenced by: '<S37>/Out1'

  {
    0.0,                               // timestamp
    0.0F,                              // indicated_airspeed_m_s
    0.0F,                              // true_airspeed_m_s
    0.0F,                              // true_airspeed_unfiltered_m_s
    0.0F,                              // air_temperature_celsius
    0.0F,                              // confidence

    {
      0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_j1
  //  Referenced by: '<S34>/Constant'

  {
    0.0,                               // timestamp
    0.0F,                              // indicated_airspeed_m_s
    0.0F,                              // true_airspeed_m_s
    0.0F,                              // true_airspeed_unfiltered_m_s
    0.0F,                              // air_temperature_celsius
    0.0F,                              // confidence

    {
      0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Out1_Y0_n
  //  Referenced by: '<S39>/Out1'

  {
    0.0,                               // timestamp
    0.0,                               // error_count
    0.0F,                              // differential_pressure_raw_pa
    0.0F,                              // differential_pressure_filtered_pa
    0.0F,                              // temperature
    0U                                 // device_id
  },

  // Computed Parameter: Constant_Value_f
  //  Referenced by: '<S36>/Constant'

  {
    0.0,                               // timestamp
    0.0,                               // error_count
    0.0F,                              // differential_pressure_raw_pa
    0.0F,                              // differential_pressure_filtered_pa
    0.0F,                              // temperature
    0U                                 // device_id
  },

  // Computed Parameter: Out1_Y0_n5
  //  Referenced by: '<S38>/Out1'

  {
    0.0,                               // timestamp
    0.0,                               // error_count
    0.0F,                              // differential_pressure_raw_pa
    0.0F,                              // differential_pressure_filtered_pa
    0.0F,                              // temperature
    0U                                 // device_id
  },

  // Computed Parameter: Constant_Value_py
  //  Referenced by: '<S35>/Constant'

  {
    0.0,                               // timestamp
    0.0,                               // error_count
    0.0F,                              // differential_pressure_raw_pa
    0.0F,                              // differential_pressure_filtered_pa
    0.0F,                              // temperature
    0U                                 // device_id
  },

  // Computed Parameter: Out1_Y0_p3
  //  Referenced by: '<S164>/Out1'

  {
    0.0,                               // timestamp
    0.0F,                              // baro_alt_meter
    0.0F,                              // baro_temp_celcius
    0.0F,                              // baro_pressure_pa
    0.0F                               // rho
  },

  // Computed Parameter: Constant_Value_bt
  //  Referenced by: '<S163>/Constant'

  {
    0.0,                               // timestamp
    0.0F,                              // baro_alt_meter
    0.0F,                              // baro_temp_celcius
    0.0F,                              // baro_pressure_pa
    0.0F                               // rho
  },

  // Computed Parameter: Constant_Value_pi
  //  Referenced by: '<S13>/Constant'

  {
    0.0,                               // timestamp
    0U,                                // led_mask
    0U,                                // color
    0U,                                // mode
    0U,                                // num_blinks
    0U,                                // priority

    {
      0U, 0U, 0U }
    // _padding0
  },

  // Expression: 0
  //  Referenced by: '<S57>/Constant'

  0.0,

  // Expression: 0
  //  Referenced by: '<S58>/Constant'

  0.0,

  // Expression: 0
  //  Referenced by: '<S59>/Constant'

  0.0,

  // Expression: 1
  //  Referenced by: '<S93>/max deflection limit'

  1.0,

  // Expression: 1
  //  Referenced by: '<S93>/max deflection limit '

  1.0,

  // Expression: 0
  //  Referenced by: '<S93>/min deflection limit '

  0.0,

  // Expression: 1
  //  Referenced by: '<S136>/max deflection limit'

  1.0,

  // Expression: 1
  //  Referenced by: '<S136>/max deflection limit '

  1.0,

  // Expression: 0
  //  Referenced by: '<S136>/min deflection limit '

  0.0,

  // Expression: 1
  //  Referenced by: '<S9>/Saturation1'

  1.0,

  // Expression: 0
  //  Referenced by: '<S9>/Saturation1'

  0.0,

  // Expression: 1
  //  Referenced by: '<S9>/Gain'

  1.0,

  // Expression: 1
  //  Referenced by: '<S9>/Saturation2'

  1.0,

  // Expression: -1
  //  Referenced by: '<S9>/Saturation2'

  -1.0,

  // Expression: 1
  //  Referenced by: '<S9>/Saturation9'

  1.0,

  // Expression: -1
  //  Referenced by: '<S9>/Saturation9'

  -1.0,

  // Expression: 0
  //  Referenced by: '<S7>/Constant'

  0.0,

  // Expression: 1
  //  Referenced by: '<S9>/Saturation3'

  1.0,

  // Expression: -1
  //  Referenced by: '<S9>/Saturation3'

  -1.0,

  // Expression: 0
  //  Referenced by: '<S71>/Constant7'

  0.0,

  // Expression: 0
  //  Referenced by: '<S71>/Constant1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S71>/Constant2'

  0.0,

  // Expression: 0
  //  Referenced by: '<S71>/Constant3'

  0.0,

  // Expression: 0
  //  Referenced by: '<S71>/Constant4'

  0.0,

  // Expression: 0
  //  Referenced by: '<S71>/Constant5'

  0.0,

  // Expression: 0
  //  Referenced by: '<S71>/Constant6'

  0.0,

  // Expression: 0
  //  Referenced by: '<S71>/Constant8'

  0.0,

  // Expression: 0
  //  Referenced by: '<S71>/Constant9'

  0.0,

  // Expression: 0
  //  Referenced by: '<S71>/Constant16'

  0.0,

  // Expression: 0
  //  Referenced by: '<S79>/Memory'

  0.0,

  // Expression: 0
  //  Referenced by: '<S80>/Constant'

  0.0,

  // Computed Parameter: DiscreteTimeIntegrator_gainval
  //  Referenced by: '<S93>/Discrete-Time Integrator'

  0.01,

  // Expression: 0
  //  Referenced by: '<S80>/Constant1'

  0.0,

  // Computed Parameter: DiscreteTimeIntegrator_gainva_n
  //  Referenced by: '<S94>/Discrete-Time Integrator'

  0.01,

  // Computed Parameter: DiscreteTimeIntegrator_gainva_o
  //  Referenced by: '<S103>/Discrete-Time Integrator'

  0.01,

  // Computed Parameter: DiscreteTimeIntegrator_gainva_k
  //  Referenced by: '<S88>/Discrete-Time Integrator'

  0.01,

  // Expression: 13
  //  Referenced by: '<S27>/Airspeed2'

  13.0,

  // Expression: 0
  //  Referenced by: '<S122>/Memory'

  0.0,

  // Expression: 0
  //  Referenced by: '<S123>/Constant'

  0.0,

  // Computed Parameter: DiscreteTimeIntegrator_gainva_b
  //  Referenced by: '<S136>/Discrete-Time Integrator'

  0.01,

  // Expression: 0
  //  Referenced by: '<S123>/Constant1'

  0.0,

  // Computed Parameter: DiscreteTimeIntegrator_gainva_m
  //  Referenced by: '<S137>/Discrete-Time Integrator'

  0.01,

  // Expression: 13
  //  Referenced by: '<S27>/Airspeed'

  13.0,

  // Computed Parameter: DiscreteTimeIntegrator_gainv_kd
  //  Referenced by: '<S146>/Discrete-Time Integrator'

  0.01,

  // Computed Parameter: DiscreteTimeIntegrator_gainv_nl
  //  Referenced by: '<S131>/Discrete-Time Integrator'

  0.01,

  // Expression: 13
  //  Referenced by: '<S27>/Airspeed1'

  13.0,

  // Expression: 13
  //  Referenced by: '<S25>/Constant'

  13.0,

  // Expression: 0
  //  Referenced by: '<S74>/Constant7'

  0.0,

  // Expression: 0
  //  Referenced by: '<S74>/Constant1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S74>/Constant2'

  0.0,

  // Expression: 0
  //  Referenced by: '<S74>/Constant3'

  0.0,

  // Expression: 0
  //  Referenced by: '<S74>/Constant4'

  0.0,

  // Expression: 0
  //  Referenced by: '<S74>/Constant5'

  0.0,

  // Expression: 0
  //  Referenced by: '<S74>/Constant6'

  0.0,

  // Expression: 0
  //  Referenced by: '<S74>/Constant8'

  0.0,

  // Expression: 0
  //  Referenced by: '<S74>/Constant9'

  0.0,

  // Expression: 0
  //  Referenced by: '<S74>/Constant16'

  0.0,

  // Expression: 13
  //  Referenced by: '<S25>/Constant1'

  13.0,

  // Expression: 13
  //  Referenced by: '<S25>/Constant2'

  13.0,

  // Expression: K_RUDDER_DIFF
  //  Referenced by: '<S76>/Gain'

  -0.008439469640857046,

  // Expression: 2000
  //  Referenced by: '<S12>/Output_Limits4'

  2000.0,

  // Expression: 1000
  //  Referenced by: '<S12>/Output_Limits4'

  1000.0,

  // Expression: 2000
  //  Referenced by: '<S12>/Output_Limits7'

  2000.0,

  // Expression: 1000
  //  Referenced by: '<S12>/Output_Limits7'

  1000.0,

  // Expression: 2000
  //  Referenced by: '<S12>/Output_Limits6'

  2000.0,

  // Expression: 1000
  //  Referenced by: '<S12>/Output_Limits6'

  1000.0,

  // Expression: 1050
  //  Referenced by: '<S59>/Switch'

  1050.0,

  // Expression: 2000
  //  Referenced by: '<S12>/Output_Limits3'

  2000.0,

  // Expression: 1000
  //  Referenced by: '<S12>/Output_Limits3'

  1000.0,

  // Expression: 1050
  //  Referenced by: '<S57>/Switch'

  1050.0,

  // Expression: 2000
  //  Referenced by: '<S12>/Output_Limits1'

  2000.0,

  // Expression: 1000
  //  Referenced by: '<S12>/Output_Limits1'

  1000.0,

  // Expression: 1050
  //  Referenced by: '<S58>/Switch'

  1050.0,

  // Expression: 2000
  //  Referenced by: '<S12>/Output_Limits2'

  2000.0,

  // Expression: 1000
  //  Referenced by: '<S12>/Output_Limits2'

  1000.0,

  // Expression: 0
  //  Referenced by: '<S89>/Constant'

  0.0,

  // Expression: 0
  //  Referenced by: '<S90>/Constant'

  0.0,

  // Expression: 0
  //  Referenced by: '<S91>/Constant'

  0.0,

  // Expression: 0
  //  Referenced by: '<S92>/Constant'

  0.0,

  // Expression: -1 %negative_sign
  //  Referenced by: '<S88>/min deflection limit1'

  -1.0,

  // Expression: -1 %negative_sign
  //  Referenced by: '<S88>/min deflection limit2'

  -1.0,

  // Expression: 0
  //  Referenced by: '<S95>/Constant'

  0.0,

  // Expression: 0
  //  Referenced by: '<S96>/Constant'

  0.0,

  // Expression: 0
  //  Referenced by: '<S97>/Constant'

  0.0,

  // Expression: 0
  //  Referenced by: '<S98>/Constant'

  0.0,

  // Expression: 1
  //  Referenced by: '<S93>/max limit'

  1.0,

  // Expression: 0
  //  Referenced by: '<S93>/min limit'

  0.0,

  // Expression: -1 %negative_sign
  //  Referenced by: '<S93>/min deflection limit1'

  -1.0,

  // Expression: -1 %negative_sign
  //  Referenced by: '<S93>/min deflection limit2'

  -1.0,

  // Expression: 0
  //  Referenced by: '<S99>/Constant'

  0.0,

  // Expression: 0
  //  Referenced by: '<S100>/Constant'

  0.0,

  // Expression: 0
  //  Referenced by: '<S101>/Constant'

  0.0,

  // Expression: 0
  //  Referenced by: '<S102>/Constant'

  0.0,

  // Expression: -1 %negative_sign
  //  Referenced by: '<S94>/min deflection limit1'

  -1.0,

  // Expression: -1 %negative_sign
  //  Referenced by: '<S94>/min deflection limit2'

  -1.0,

  // Expression: 0
  //  Referenced by: '<S105>/Constant'

  0.0,

  // Expression: 0
  //  Referenced by: '<S106>/Constant'

  0.0,

  // Expression: 0
  //  Referenced by: '<S107>/Constant'

  0.0,

  // Expression: 0
  //  Referenced by: '<S108>/Constant'

  0.0,

  // Expression: -1 %negative_sign
  //  Referenced by: '<S103>/min deflection limit1'

  -1.0,

  // Expression: -1 %negative_sign
  //  Referenced by: '<S103>/min deflection limit2'

  -1.0,

  // Expression: 13
  //  Referenced by: '<S27>/Airspeed3'

  13.0,

  // Expression: 0
  //  Referenced by: '<S132>/Constant'

  0.0,

  // Expression: 0
  //  Referenced by: '<S133>/Constant'

  0.0,

  // Expression: 0
  //  Referenced by: '<S134>/Constant'

  0.0,

  // Expression: 0
  //  Referenced by: '<S135>/Constant'

  0.0,

  // Expression: -1 %negative_sign
  //  Referenced by: '<S131>/min deflection limit1'

  -1.0,

  // Expression: -1 %negative_sign
  //  Referenced by: '<S131>/min deflection limit2'

  -1.0,

  // Expression: 0
  //  Referenced by: '<S138>/Constant'

  0.0,

  // Expression: 0
  //  Referenced by: '<S139>/Constant'

  0.0,

  // Expression: 0
  //  Referenced by: '<S140>/Constant'

  0.0,

  // Expression: 0
  //  Referenced by: '<S141>/Constant'

  0.0,

  // Expression: 1
  //  Referenced by: '<S136>/max limit'

  1.0,

  // Expression: 0
  //  Referenced by: '<S136>/min limit'

  0.0,

  // Expression: -1 %negative_sign
  //  Referenced by: '<S136>/min deflection limit1'

  -1.0,

  // Expression: -1 %negative_sign
  //  Referenced by: '<S136>/min deflection limit2'

  -1.0,

  // Expression: 0
  //  Referenced by: '<S142>/Constant'

  0.0,

  // Expression: 0
  //  Referenced by: '<S143>/Constant'

  0.0,

  // Expression: 0
  //  Referenced by: '<S144>/Constant'

  0.0,

  // Expression: 0
  //  Referenced by: '<S145>/Constant'

  0.0,

  // Expression: -1 %negative_sign
  //  Referenced by: '<S137>/min deflection limit1'

  -1.0,

  // Expression: -1 %negative_sign
  //  Referenced by: '<S137>/min deflection limit2'

  -1.0,

  // Expression: 0
  //  Referenced by: '<S148>/Constant'

  0.0,

  // Expression: 0
  //  Referenced by: '<S149>/Constant'

  0.0,

  // Expression: 0
  //  Referenced by: '<S150>/Constant'

  0.0,

  // Expression: 0
  //  Referenced by: '<S151>/Constant'

  0.0,

  // Expression: -1 %negative_sign
  //  Referenced by: '<S146>/min deflection limit1'

  -1.0,

  // Expression: -1 %negative_sign
  //  Referenced by: '<S146>/min deflection limit2'

  -1.0,

  // Computed Parameter: Gain_Gain_h5
  //  Referenced by: '<S32>/Gain'

  0.5F,

  // Expression: K_RUDDER_DIFF
  //  Referenced by: '<S46>/Gain'

  -0.00843947F,

  // Expression: K_RUDDER_DIFF
  //  Referenced by: '<S73>/Gain'

  -0.00843947F,

  // Computed Parameter: Memory_InitialCondition_b
  //  Referenced by: '<S86>/Memory'

  0.0F,

  // Computed Parameter: DiscreteTimeIntegrator_gainva_f
  //  Referenced by: '<S114>/Discrete-Time Integrator'

  0.01F,

  // Computed Parameter: Memory_InitialCondition_g
  //  Referenced by: '<S129>/Memory'

  0.0F,

  // Computed Parameter: DiscreteTimeIntegrator_gainva_i
  //  Referenced by: '<S157>/Discrete-Time Integrator'

  0.01F,

  // Computed Parameter: Constant_Value_ig
  //  Referenced by: '<Root>/Constant'

  1,

  // Computed Parameter: Constant5_Value_c
  //  Referenced by: '<Root>/Constant5'

  0,

  // Computed Parameter: Gain1_Gain
  //  Referenced by: '<S23>/Gain1'

  128U,

  // Computed Parameter: Gain_Gain_m
  //  Referenced by: '<S23>/Gain'

  128U,

  // Computed Parameter: Constant3_Value_f
  //  Referenced by: '<Root>/Constant3'

  5U,

  // Computed Parameter: Constant4_Value_d
  //  Referenced by: '<Root>/Constant4'

  255U
};

//
// File trailer for generated code.
//
// [EOF]
//
