#include "__cf_HEV.h"
#include "drive_HEV_1.h"
DriveLine * _drive_HEV_1_drive_line ; DriveLine * drive_HEV_1_drive_line (
drive_HEV_1_data_table * _table ) { DriveLine * _dline ; _dline = & _table ->
_dline ; _dline -> compilerData = _table -> DriveCompilerData_table ; _dline
-> compilerData -> numBlocks = 45 ; _dline -> compilerData -> block = _table
-> DriveBlock_table ; _dline -> compilerData -> block [ 0 ] . numFlanges = 1
; _dline -> compilerData -> block [ 0 ] . numSolver = 1 ; _dline ->
compilerData -> block [ 0 ] . name = ( char * ) _table -> UINT8_table ;
strcpy ( _dline -> compilerData -> block [ 0 ] . name ,
"HEV/Engine Controller/Driveline\\\\nEnvironment" ) ; _dline -> compilerData
-> block [ 0 ] . visibleName = ( char * ) ( _table -> UINT8_table + 44 ) ;
strcpy ( _dline -> compilerData -> block [ 0 ] . visibleName ,
"HEV/Engine Controller/Driveline\\\\nEnvironment" ) ; _dline -> compilerData
-> block [ 0 ] . type = DRIVESOLVER ; _dline -> compilerData -> block [ 0 ] .
flange = _table -> INT32_table ; _dline -> compilerData -> block [ 0 ] .
solver = _table -> DriveSolver_table ; _dline -> compilerData -> block [ 0 ]
. solver [ 0 ] . implementModeIteration = TRUE ; _dline -> compilerData ->
block [ 0 ] . solver [ 0 ] . defaultClutchVelocityTolerance = 0.001 ; _dline
-> compilerData -> block [ 0 ] . solver [ 0 ] .
defaultAutomaticVarStepClutchVelocityTolerance = TRUE ; _dline ->
compilerData -> block [ 1 ] . name = ( char * ) ( _table -> UINT8_table + 88
) ; strcpy ( _dline -> compilerData -> block [ 1 ] . name ,
 "HEV/Engine Controller/Torsional \\\\nSpring-Damper/Free/Shared\\\\nEnvironment\\\\nInternal"
) ; _dline -> compilerData -> block [ 1 ] . visibleName = ( char * ) ( _table
-> UINT8_table + 168 ) ; strcpy ( _dline -> compilerData -> block [ 1 ] .
visibleName , "HEV/Engine Controller/Torsional \\\\nSpring-Damper" ) ; _dline
-> compilerData -> block [ 1 ] . type = DRIVEFREEGEAR ; _dline ->
compilerData -> block [ 2 ] . numFlanges = 1 ; _dline -> compilerData ->
block [ 2 ] . numTransducer = 1 ; _dline -> compilerData -> block [ 2 ] .
name = ( char * ) ( _table -> UINT8_table + 215 ) ; strcpy ( _dline ->
compilerData -> block [ 2 ] . name ,
"HEV/Engine Controller/Torsional \\\\nSpring-Damper/follower_torque/Transducer"
) ; _dline -> compilerData -> block [ 2 ] . visibleName = ( char * ) ( _table
-> UINT8_table + 289 ) ; strcpy ( _dline -> compilerData -> block [ 2 ] .
visibleName , "HEV/Engine Controller/Torsional \\\\nSpring-Damper" ) ; _dline
-> compilerData -> block [ 2 ] . type = DRIVETRANSDUCER ; _dline ->
compilerData -> block [ 2 ] . flange = _table -> INT32_table + 1 ; _dline ->
compilerData -> block [ 2 ] . flange [ 0 ] = 1 ; _dline -> compilerData ->
block [ 2 ] . transducer = _table -> DriveTransducer_table ; _dline ->
compilerData -> block [ 2 ] . transducer [ 0 ] . numSignals = 1 ; _dline ->
compilerData -> block [ 2 ] . transducer [ 0 ] . positionFlag = ( char * ) (
_table -> UINT8_table + 336 ) ; strcpy ( _dline -> compilerData -> block [ 2
] . transducer [ 0 ] . positionFlag , "Undefined" ) ; _dline -> compilerData
-> block [ 2 ] . transducer [ 0 ] . velocityFlag = ( char * ) ( _table ->
UINT8_table + 346 ) ; strcpy ( _dline -> compilerData -> block [ 2 ] .
transducer [ 0 ] . velocityFlag , "Undefined" ) ; _dline -> compilerData ->
block [ 2 ] . transducer [ 0 ] . accelerationFlag = ( char * ) ( _table ->
UINT8_table + 356 ) ; strcpy ( _dline -> compilerData -> block [ 2 ] .
transducer [ 0 ] . accelerationFlag , "Undefined" ) ; _dline -> compilerData
-> block [ 2 ] . transducer [ 0 ] . signal = _table -> DriveSignal_table ;
_dline -> compilerData -> block [ 2 ] . transducer [ 0 ] . signal [ 0 ] .
type = DRIVEEXTERNALTORQUE ; _dline -> compilerData -> block [ 2 ] .
transducer [ 0 ] . signal [ 0 ] . flag = ( char * ) ( _table -> UINT8_table +
366 ) ; strcpy ( _dline -> compilerData -> block [ 2 ] . transducer [ 0 ] .
signal [ 0 ] . flag , "drive_3e020f6eTor" ) ; _dline -> compilerData -> block
[ 3 ] . numFlanges = 1 ; _dline -> compilerData -> block [ 3 ] .
numTransducer = 1 ; _dline -> compilerData -> block [ 3 ] . name = ( char * )
( _table -> UINT8_table + 384 ) ; strcpy ( _dline -> compilerData -> block [
3 ] . name ,
 "HEV/Engine Controller/Torsional \\\\nSpring-Damper/follower_velocity/Transducer"
) ; _dline -> compilerData -> block [ 3 ] . visibleName = ( char * ) ( _table
-> UINT8_table + 460 ) ; strcpy ( _dline -> compilerData -> block [ 3 ] .
visibleName , "HEV/Engine Controller/Torsional \\\\nSpring-Damper" ) ; _dline
-> compilerData -> block [ 3 ] . type = DRIVETRANSDUCER ; _dline ->
compilerData -> block [ 3 ] . flange = _table -> INT32_table + 2 ; _dline ->
compilerData -> block [ 3 ] . flange [ 0 ] = 1 ; _dline -> compilerData ->
block [ 3 ] . transducer = _table -> DriveTransducer_table + 1 ; _dline ->
compilerData -> block [ 3 ] . transducer [ 0 ] . numSignals = 2 ; _dline ->
compilerData -> block [ 3 ] . transducer [ 0 ] . positionFlag = ( char * ) (
_table -> UINT8_table + 507 ) ; strcpy ( _dline -> compilerData -> block [ 3
] . transducer [ 0 ] . positionFlag , "Undefined" ) ; _dline -> compilerData
-> block [ 3 ] . transducer [ 0 ] . velocityFlag = ( char * ) ( _table ->
UINT8_table + 517 ) ; strcpy ( _dline -> compilerData -> block [ 3 ] .
transducer [ 0 ] . velocityFlag , "Undefined" ) ; _dline -> compilerData ->
block [ 3 ] . transducer [ 0 ] . accelerationFlag = ( char * ) ( _table ->
UINT8_table + 527 ) ; strcpy ( _dline -> compilerData -> block [ 3 ] .
transducer [ 0 ] . accelerationFlag , "Undefined" ) ; _dline -> compilerData
-> block [ 3 ] . transducer [ 0 ] . signal = _table -> DriveSignal_table + 1
; _dline -> compilerData -> block [ 3 ] . transducer [ 0 ] . signal [ 0 ] .
type = DRIVEVELOCITY ; _dline -> compilerData -> block [ 3 ] . transducer [ 0
] . signal [ 0 ] . flag = ( char * ) ( _table -> UINT8_table + 537 ) ; strcpy
( _dline -> compilerData -> block [ 3 ] . transducer [ 0 ] . signal [ 0 ] .
flag , "drive_124908faVelocity" ) ; _dline -> compilerData -> block [ 3 ] .
transducer [ 0 ] . signal [ 1 ] . type = DRIVEACCELERATION ; _dline ->
compilerData -> block [ 3 ] . transducer [ 0 ] . signal [ 1 ] . flag = ( char
* ) ( _table -> UINT8_table + 560 ) ; strcpy ( _dline -> compilerData ->
block [ 3 ] . transducer [ 0 ] . signal [ 1 ] . flag ,
"drive_124908faAcceleration" ) ; _dline -> compilerData -> block [ 4 ] .
numFlanges = 1 ; _dline -> compilerData -> block [ 4 ] . numWeld = 1 ; _dline
-> compilerData -> block [ 4 ] . name = ( char * ) ( _table -> UINT8_table +
587 ) ; strcpy ( _dline -> compilerData -> block [ 4 ] . name ,
"HEV/Engine Controller/Housing/Housing\\\\nInternal" ) ; _dline ->
compilerData -> block [ 4 ] . visibleName = ( char * ) ( _table ->
UINT8_table + 634 ) ; strcpy ( _dline -> compilerData -> block [ 4 ] .
visibleName , "HEV/Engine Controller/Housing" ) ; _dline -> compilerData ->
block [ 4 ] . type = DRIVEWELD ; _dline -> compilerData -> block [ 4 ] .
flange = _table -> INT32_table + 3 ; _dline -> compilerData -> block [ 4 ] .
flange [ 0 ] = 1 ; _dline -> compilerData -> block [ 4 ] . weld = _table ->
DriveWeld_table ; _dline -> compilerData -> block [ 4 ] . weld [ 0 ] . isWeld
= TRUE ; _dline -> compilerData -> block [ 5 ] . numFlanges = 1 ; _dline ->
compilerData -> block [ 5 ] . numParameters = 2 ; _dline -> compilerData ->
block [ 5 ] . parameter = _table -> DriveParameter_table ; _dline ->
compilerData -> block [ 5 ] . parameter [ 0 ] . type = DRIVERTP_INERTIA ;
_dline -> compilerData -> block [ 5 ] . parameter [ 0 ] . flag = ( char * ) (
_table -> UINT8_table + 664 ) ; strcpy ( _dline -> compilerData -> block [ 5
] . parameter [ 0 ] . flag , "drive_929728cfInertia" ) ; _dline ->
compilerData -> block [ 5 ] . parameter [ 1 ] . type =
DRIVERTP_INITIALCONDITION ; _dline -> compilerData -> block [ 5 ] . parameter
[ 1 ] . flag = ( char * ) ( _table -> UINT8_table + 686 ) ; strcpy ( _dline
-> compilerData -> block [ 5 ] . parameter [ 1 ] . flag ,
"drive_929728cfInitialCondition" ) ; _dline -> compilerData -> block [ 5 ] .
numInertia = 1 ; _dline -> compilerData -> block [ 5 ] . name = ( char * ) (
_table -> UINT8_table + 717 ) ; strcpy ( _dline -> compilerData -> block [ 5
] . name , "HEV/Engine Controller/Inertia" ) ; _dline -> compilerData ->
block [ 5 ] . visibleName = ( char * ) ( _table -> UINT8_table + 747 ) ;
strcpy ( _dline -> compilerData -> block [ 5 ] . visibleName ,
"HEV/Engine Controller/Inertia" ) ; _dline -> compilerData -> block [ 5 ] .
type = DRIVEINERTIA ; _dline -> compilerData -> block [ 5 ] . flange = _table
-> INT32_table + 4 ; _dline -> compilerData -> block [ 5 ] . inertia = _table
-> DriveInertia_table ; _dline -> compilerData -> block [ 5 ] . inertia [ 0 ]
. inertia = 0.25 ; _dline -> compilerData -> block [ 6 ] . numFlanges = 2 ;
_dline -> compilerData -> block [ 6 ] . numStrainGauge = 1 ; _dline ->
compilerData -> block [ 6 ] . name = ( char * ) ( _table -> UINT8_table + 777
) ; strcpy ( _dline -> compilerData -> block [ 6 ] . name ,
"HEV/Engine Controller/Torque Sensor/Torque Sensor\\\\nInternal" ) ; _dline
-> compilerData -> block [ 6 ] . visibleName = ( char * ) ( _table ->
UINT8_table + 836 ) ; strcpy ( _dline -> compilerData -> block [ 6 ] .
visibleName , "HEV/Engine Controller/Torque Sensor" ) ; _dline ->
compilerData -> block [ 6 ] . type = DRIVESTRAINGAUGE ; _dline ->
compilerData -> block [ 6 ] . flange = _table -> INT32_table + 5 ; _dline ->
compilerData -> block [ 6 ] . flange [ 1 ] = 2 ; _dline -> compilerData ->
block [ 6 ] . strainGauge = _table -> DriveStrainGauge_table ; _dline ->
compilerData -> block [ 6 ] . strainGauge [ 0 ] . measurementFlange = 1 ;
_dline -> compilerData -> block [ 6 ] . strainGauge [ 0 ] . flag = ( char * )
( _table -> UINT8_table + 872 ) ; strcpy ( _dline -> compilerData -> block [
6 ] . strainGauge [ 0 ] . flag , "drive_511dbbf3" ) ; _dline -> compilerData
-> block [ 7 ] . numFlanges = 2 ; _dline -> compilerData -> block [ 7 ] .
numStrainGauge = 1 ; _dline -> compilerData -> block [ 7 ] . name = ( char *
) ( _table -> UINT8_table + 887 ) ; strcpy ( _dline -> compilerData -> block
[ 7 ] . name , "HEV/Gearbox/T1/Torque Sensor\\\\nInternal" ) ; _dline ->
compilerData -> block [ 7 ] . visibleName = ( char * ) ( _table ->
UINT8_table + 925 ) ; strcpy ( _dline -> compilerData -> block [ 7 ] .
visibleName , "HEV/Gearbox/T1" ) ; _dline -> compilerData -> block [ 7 ] .
type = DRIVESTRAINGAUGE ; _dline -> compilerData -> block [ 7 ] . flange =
_table -> INT32_table + 7 ; _dline -> compilerData -> block [ 7 ] . flange [
0 ] = 2 ; _dline -> compilerData -> block [ 7 ] . flange [ 1 ] = 3 ; _dline
-> compilerData -> block [ 7 ] . strainGauge = _table ->
DriveStrainGauge_table + 1 ; _dline -> compilerData -> block [ 7 ] .
strainGauge [ 0 ] . measurementFlange = 1 ; _dline -> compilerData -> block [
7 ] . strainGauge [ 0 ] . flag = ( char * ) ( _table -> UINT8_table + 940 ) ;
strcpy ( _dline -> compilerData -> block [ 7 ] . strainGauge [ 0 ] . flag ,
"drive_f82468dd" ) ; _dline -> compilerData -> block [ 8 ] . numFlanges = 3 ;
_dline -> compilerData -> block [ 8 ] . numParameters = 1 ; _dline ->
compilerData -> block [ 8 ] . parameter = _table -> DriveParameter_table + 2
; _dline -> compilerData -> block [ 8 ] . parameter [ 0 ] . type =
DRIVERTP_PLANETPLANETGEARRATIO ; _dline -> compilerData -> block [ 8 ] .
parameter [ 0 ] . flag = ( char * ) ( _table -> UINT8_table + 955 ) ; strcpy
( _dline -> compilerData -> block [ 8 ] . parameter [ 0 ] . flag ,
"drive_ed509dbaPlanetPlanetRatio" ) ; _dline -> compilerData -> block [ 8 ] .
numPlanetPlanet = 1 ; _dline -> compilerData -> block [ 8 ] . name = ( char *
) ( _table -> UINT8_table + 987 ) ; strcpy ( _dline -> compilerData -> block
[ 8 ] . name , "HEV/Gearbox/Planetary Gear/Planet-Planet" ) ; _dline ->
compilerData -> block [ 8 ] . visibleName = ( char * ) ( _table ->
UINT8_table + 1028 ) ; strcpy ( _dline -> compilerData -> block [ 8 ] .
visibleName , "HEV/Gearbox/Planetary Gear" ) ; _dline -> compilerData ->
block [ 8 ] . type = DRIVEPLANETPLANET ; _dline -> compilerData -> block [ 8
] . flange = _table -> INT32_table + 9 ; _dline -> compilerData -> block [ 8
] . flange [ 0 ] = 3 ; _dline -> compilerData -> block [ 8 ] . flange [ 1 ] =
4 ; _dline -> compilerData -> block [ 8 ] . flange [ 2 ] = 17 ; _dline ->
compilerData -> block [ 8 ] . planetPlanet = _table ->
DrivePlanetPlanet_table ; _dline -> compilerData -> block [ 8 ] .
planetPlanet [ 0 ] . sunFlange = 2 ; _dline -> compilerData -> block [ 8 ] .
planetPlanet [ 0 ] . planetFlange = 1 ; _dline -> compilerData -> block [ 8 ]
. planetPlanet [ 0 ] . ratio = 0.8 ; _dline -> compilerData -> block [ 9 ] .
numFlanges = 3 ; _dline -> compilerData -> block [ 9 ] . numParameters = 1 ;
_dline -> compilerData -> block [ 9 ] . parameter = _table ->
DriveParameter_table + 3 ; _dline -> compilerData -> block [ 9 ] . parameter
[ 0 ] . type = DRIVERTP_RINGPLANETGEARRATIO ; _dline -> compilerData -> block
[ 9 ] . parameter [ 0 ] . flag = ( char * ) ( _table -> UINT8_table + 1055 )
; strcpy ( _dline -> compilerData -> block [ 9 ] . parameter [ 0 ] . flag ,
"drive_e0323d9RingPlanetRatio" ) ; _dline -> compilerData -> block [ 9 ] .
numPlanetRing = 1 ; _dline -> compilerData -> block [ 9 ] . name = ( char * )
( _table -> UINT8_table + 1084 ) ; strcpy ( _dline -> compilerData -> block [
9 ] . name , "HEV/Gearbox/Planetary Gear/Ring-Planet" ) ; _dline ->
compilerData -> block [ 9 ] . visibleName = ( char * ) ( _table ->
UINT8_table + 1123 ) ; strcpy ( _dline -> compilerData -> block [ 9 ] .
visibleName , "HEV/Gearbox/Planetary Gear" ) ; _dline -> compilerData ->
block [ 9 ] . type = DRIVEPLANETRING ; _dline -> compilerData -> block [ 9 ]
. flange = _table -> INT32_table + 12 ; _dline -> compilerData -> block [ 9 ]
. flange [ 0 ] = 4 ; _dline -> compilerData -> block [ 9 ] . flange [ 1 ] = 5
; _dline -> compilerData -> block [ 9 ] . flange [ 2 ] = 3 ; _dline ->
compilerData -> block [ 9 ] . planetRing = _table -> DrivePlanetRing_table ;
_dline -> compilerData -> block [ 9 ] . planetRing [ 0 ] . ringFlange = 1 ;
_dline -> compilerData -> block [ 9 ] . planetRing [ 0 ] . carrierFlange = 2
; _dline -> compilerData -> block [ 9 ] . planetRing [ 0 ] . ratio = 3.25 ;
_dline -> compilerData -> block [ 10 ] . numFlanges = 2 ; _dline ->
compilerData -> block [ 10 ] . numStrainGauge = 1 ; _dline -> compilerData ->
block [ 10 ] . name = ( char * ) ( _table -> UINT8_table + 1150 ) ; strcpy (
_dline -> compilerData -> block [ 10 ] . name ,
"HEV/Gearbox/Torque Sensor/Torque Sensor\\\\nInternal" ) ; _dline ->
compilerData -> block [ 10 ] . visibleName = ( char * ) ( _table ->
UINT8_table + 1199 ) ; strcpy ( _dline -> compilerData -> block [ 10 ] .
visibleName , "HEV/Gearbox/Torque Sensor" ) ; _dline -> compilerData -> block
[ 10 ] . type = DRIVESTRAINGAUGE ; _dline -> compilerData -> block [ 10 ] .
flange = _table -> INT32_table + 15 ; _dline -> compilerData -> block [ 10 ]
. flange [ 0 ] = 5 ; _dline -> compilerData -> block [ 10 ] . flange [ 1 ] =
6 ; _dline -> compilerData -> block [ 10 ] . strainGauge = _table ->
DriveStrainGauge_table + 2 ; _dline -> compilerData -> block [ 10 ] .
strainGauge [ 0 ] . measurementFlange = 1 ; _dline -> compilerData -> block [
10 ] . strainGauge [ 0 ] . flag = ( char * ) ( _table -> UINT8_table + 1225 )
; strcpy ( _dline -> compilerData -> block [ 10 ] . strainGauge [ 0 ] . flag
, "drive_5a50dccb" ) ; _dline -> compilerData -> block [ 11 ] . numFlanges =
2 ; _dline -> compilerData -> block [ 11 ] . numStrainGauge = 1 ; _dline ->
compilerData -> block [ 11 ] . name = ( char * ) ( _table -> UINT8_table +
1240 ) ; strcpy ( _dline -> compilerData -> block [ 11 ] . name ,
"HEV/Vehicle/Torque Sensor/Torque Sensor\\\\nInternal" ) ; _dline ->
compilerData -> block [ 11 ] . visibleName = ( char * ) ( _table ->
UINT8_table + 1289 ) ; strcpy ( _dline -> compilerData -> block [ 11 ] .
visibleName , "HEV/Vehicle/Torque Sensor" ) ; _dline -> compilerData -> block
[ 11 ] . type = DRIVESTRAINGAUGE ; _dline -> compilerData -> block [ 11 ] .
flange = _table -> INT32_table + 17 ; _dline -> compilerData -> block [ 11 ]
. flange [ 0 ] = 6 ; _dline -> compilerData -> block [ 11 ] . flange [ 1 ] =
7 ; _dline -> compilerData -> block [ 11 ] . strainGauge = _table ->
DriveStrainGauge_table + 3 ; _dline -> compilerData -> block [ 11 ] .
strainGauge [ 0 ] . measurementFlange = 1 ; _dline -> compilerData -> block [
11 ] . strainGauge [ 0 ] . flag = ( char * ) ( _table -> UINT8_table + 1315 )
; strcpy ( _dline -> compilerData -> block [ 11 ] . strainGauge [ 0 ] . flag
, "drive_3a0f24a5" ) ; _dline -> compilerData -> block [ 12 ] . name = ( char
* ) ( _table -> UINT8_table + 1330 ) ; strcpy ( _dline -> compilerData ->
block [ 12 ] . name ,
 "HEV/Vehicle/Torsional \\\\nSpring-Damper \\\\n(Friction)/Free/Shared\\\\nEnvironment\\\\nInternal"
) ; _dline -> compilerData -> block [ 12 ] . visibleName = ( char * ) (
_table -> UINT8_table + 1412 ) ; strcpy ( _dline -> compilerData -> block [
12 ] . visibleName ,
"HEV/Vehicle/Torsional \\\\nSpring-Damper \\\\n(Friction)" ) ; _dline ->
compilerData -> block [ 12 ] . type = DRIVEFREEGEAR ; _dline -> compilerData
-> block [ 13 ] . numFlanges = 1 ; _dline -> compilerData -> block [ 13 ] .
numTransducer = 1 ; _dline -> compilerData -> block [ 13 ] . name = ( char *
) ( _table -> UINT8_table + 1461 ) ; strcpy ( _dline -> compilerData -> block
[ 13 ] . name ,
 "HEV/Vehicle/Torsional \\\\nSpring-Damper \\\\n(Friction)/base_torque/Transducer"
) ; _dline -> compilerData -> block [ 13 ] . visibleName = ( char * ) (
_table -> UINT8_table + 1533 ) ; strcpy ( _dline -> compilerData -> block [
13 ] . visibleName ,
"HEV/Vehicle/Torsional \\\\nSpring-Damper \\\\n(Friction)" ) ; _dline ->
compilerData -> block [ 13 ] . type = DRIVETRANSDUCER ; _dline ->
compilerData -> block [ 13 ] . flange = _table -> INT32_table + 19 ; _dline
-> compilerData -> block [ 13 ] . flange [ 0 ] = 8 ; _dline -> compilerData
-> block [ 13 ] . transducer = _table -> DriveTransducer_table + 2 ; _dline
-> compilerData -> block [ 13 ] . transducer [ 0 ] . numSignals = 1 ; _dline
-> compilerData -> block [ 13 ] . transducer [ 0 ] . positionFlag = ( char *
) ( _table -> UINT8_table + 1582 ) ; strcpy ( _dline -> compilerData -> block
[ 13 ] . transducer [ 0 ] . positionFlag , "Undefined" ) ; _dline ->
compilerData -> block [ 13 ] . transducer [ 0 ] . velocityFlag = ( char * ) (
_table -> UINT8_table + 1592 ) ; strcpy ( _dline -> compilerData -> block [
13 ] . transducer [ 0 ] . velocityFlag , "Undefined" ) ; _dline ->
compilerData -> block [ 13 ] . transducer [ 0 ] . accelerationFlag = ( char *
) ( _table -> UINT8_table + 1602 ) ; strcpy ( _dline -> compilerData -> block
[ 13 ] . transducer [ 0 ] . accelerationFlag , "Undefined" ) ; _dline ->
compilerData -> block [ 13 ] . transducer [ 0 ] . signal = _table ->
DriveSignal_table + 3 ; _dline -> compilerData -> block [ 13 ] . transducer [
0 ] . signal [ 0 ] . type = DRIVEEXTERNALTORQUE ; _dline -> compilerData ->
block [ 13 ] . transducer [ 0 ] . signal [ 0 ] . flag = ( char * ) ( _table
-> UINT8_table + 1612 ) ; strcpy ( _dline -> compilerData -> block [ 13 ] .
transducer [ 0 ] . signal [ 0 ] . flag , "drive_cdf4ee1bTor" ) ; _dline ->
compilerData -> block [ 14 ] . numFlanges = 1 ; _dline -> compilerData ->
block [ 14 ] . numTransducer = 1 ; _dline -> compilerData -> block [ 14 ] .
name = ( char * ) ( _table -> UINT8_table + 1630 ) ; strcpy ( _dline ->
compilerData -> block [ 14 ] . name ,
 "HEV/Vehicle/Torsional \\\\nSpring-Damper \\\\n(Friction)/base_velocity/Transducer"
) ; _dline -> compilerData -> block [ 14 ] . visibleName = ( char * ) (
_table -> UINT8_table + 1704 ) ; strcpy ( _dline -> compilerData -> block [
14 ] . visibleName ,
"HEV/Vehicle/Torsional \\\\nSpring-Damper \\\\n(Friction)" ) ; _dline ->
compilerData -> block [ 14 ] . type = DRIVETRANSDUCER ; _dline ->
compilerData -> block [ 14 ] . flange = _table -> INT32_table + 20 ; _dline
-> compilerData -> block [ 14 ] . flange [ 0 ] = 8 ; _dline -> compilerData
-> block [ 14 ] . transducer = _table -> DriveTransducer_table + 3 ; _dline
-> compilerData -> block [ 14 ] . transducer [ 0 ] . numSignals = 2 ; _dline
-> compilerData -> block [ 14 ] . transducer [ 0 ] . positionFlag = ( char *
) ( _table -> UINT8_table + 1753 ) ; strcpy ( _dline -> compilerData -> block
[ 14 ] . transducer [ 0 ] . positionFlag , "Undefined" ) ; _dline ->
compilerData -> block [ 14 ] . transducer [ 0 ] . velocityFlag = ( char * ) (
_table -> UINT8_table + 1763 ) ; strcpy ( _dline -> compilerData -> block [
14 ] . transducer [ 0 ] . velocityFlag , "Undefined" ) ; _dline ->
compilerData -> block [ 14 ] . transducer [ 0 ] . accelerationFlag = ( char *
) ( _table -> UINT8_table + 1773 ) ; strcpy ( _dline -> compilerData -> block
[ 14 ] . transducer [ 0 ] . accelerationFlag , "Undefined" ) ; _dline ->
compilerData -> block [ 14 ] . transducer [ 0 ] . signal = _table ->
DriveSignal_table + 4 ; _dline -> compilerData -> block [ 14 ] . transducer [
0 ] . signal [ 0 ] . type = DRIVEVELOCITY ; _dline -> compilerData -> block [
14 ] . transducer [ 0 ] . signal [ 0 ] . flag = ( char * ) ( _table ->
UINT8_table + 1783 ) ; strcpy ( _dline -> compilerData -> block [ 14 ] .
transducer [ 0 ] . signal [ 0 ] . flag , "drive_80da075eVelocity" ) ; _dline
-> compilerData -> block [ 14 ] . transducer [ 0 ] . signal [ 1 ] . type =
DRIVEACCELERATION ; _dline -> compilerData -> block [ 14 ] . transducer [ 0 ]
. signal [ 1 ] . flag = ( char * ) ( _table -> UINT8_table + 1806 ) ; strcpy
( _dline -> compilerData -> block [ 14 ] . transducer [ 0 ] . signal [ 1 ] .
flag , "drive_80da075eAcceleration" ) ; _dline -> compilerData -> block [ 15
] . numFlanges = 1 ; _dline -> compilerData -> block [ 15 ] . numWeld = 1 ;
_dline -> compilerData -> block [ 15 ] . name = ( char * ) ( _table ->
UINT8_table + 1833 ) ; strcpy ( _dline -> compilerData -> block [ 15 ] . name
, "HEV/Vehicle/Housing/Housing\\\\nInternal" ) ; _dline -> compilerData ->
block [ 15 ] . visibleName = ( char * ) ( _table -> UINT8_table + 1870 ) ;
strcpy ( _dline -> compilerData -> block [ 15 ] . visibleName ,
"HEV/Vehicle/Housing" ) ; _dline -> compilerData -> block [ 15 ] . type =
DRIVEWELD ; _dline -> compilerData -> block [ 15 ] . flange = _table ->
INT32_table + 21 ; _dline -> compilerData -> block [ 15 ] . flange [ 0 ] = 8
; _dline -> compilerData -> block [ 15 ] . weld = _table -> DriveWeld_table +
1 ; _dline -> compilerData -> block [ 15 ] . weld [ 0 ] . isWeld = TRUE ;
_dline -> compilerData -> block [ 16 ] . numFlanges = 2 ; _dline ->
compilerData -> block [ 16 ] . numParameters = 1 ; _dline -> compilerData ->
block [ 16 ] . parameter = _table -> DriveParameter_table + 4 ; _dline ->
compilerData -> block [ 16 ] . parameter [ 0 ] . type =
DRIVERTP_SIMPLEGEARRATIO ; _dline -> compilerData -> block [ 16 ] . parameter
[ 0 ] . flag = ( char * ) ( _table -> UINT8_table + 1890 ) ; strcpy ( _dline
-> compilerData -> block [ 16 ] . parameter [ 0 ] . flag ,
"drive_72945f1GearRatio" ) ; _dline -> compilerData -> block [ 16 ] .
numSimpleGear = 1 ; _dline -> compilerData -> block [ 16 ] . name = ( char *
) ( _table -> UINT8_table + 1913 ) ; strcpy ( _dline -> compilerData -> block
[ 16 ] . name , "HEV/Vehicle/Simple Gear" ) ; _dline -> compilerData -> block
[ 16 ] . visibleName = ( char * ) ( _table -> UINT8_table + 1937 ) ; strcpy (
_dline -> compilerData -> block [ 16 ] . visibleName ,
"HEV/Vehicle/Simple Gear" ) ; _dline -> compilerData -> block [ 16 ] . type =
DRIVESIMPLEGEAR ; _dline -> compilerData -> block [ 16 ] . flange = _table ->
INT32_table + 22 ; _dline -> compilerData -> block [ 16 ] . flange [ 0 ] = 7
; _dline -> compilerData -> block [ 16 ] . flange [ 1 ] = 9 ; _dline ->
compilerData -> block [ 16 ] . simpleGear = _table -> DriveSimpleGear_table ;
_dline -> compilerData -> block [ 16 ] . simpleGear [ 0 ] . outputFlange = 1
; _dline -> compilerData -> block [ 16 ] . simpleGear [ 0 ] . ratio = 4.113 ;
_dline -> compilerData -> block [ 17 ] . numFlanges = 1 ; _dline ->
compilerData -> block [ 17 ] . numParameters = 2 ; _dline -> compilerData ->
block [ 17 ] . parameter = _table -> DriveParameter_table + 5 ; _dline ->
compilerData -> block [ 17 ] . parameter [ 0 ] . type = DRIVERTP_INERTIA ;
_dline -> compilerData -> block [ 17 ] . parameter [ 0 ] . flag = ( char * )
( _table -> UINT8_table + 1961 ) ; strcpy ( _dline -> compilerData -> block [
17 ] . parameter [ 0 ] . flag , "drive_f8a0f554Inertia" ) ; _dline ->
compilerData -> block [ 17 ] . parameter [ 1 ] . type =
DRIVERTP_INITIALCONDITION ; _dline -> compilerData -> block [ 17 ] .
parameter [ 1 ] . flag = ( char * ) ( _table -> UINT8_table + 1983 ) ; strcpy
( _dline -> compilerData -> block [ 17 ] . parameter [ 1 ] . flag ,
"drive_f8a0f554InitialCondition" ) ; _dline -> compilerData -> block [ 17 ] .
numInertia = 1 ; _dline -> compilerData -> block [ 17 ] . name = ( char * ) (
_table -> UINT8_table + 2014 ) ; strcpy ( _dline -> compilerData -> block [
17 ] . name , "HEV/Vehicle/Transmission \\\\nInertia" ) ; _dline ->
compilerData -> block [ 17 ] . visibleName = ( char * ) ( _table ->
UINT8_table + 2048 ) ; strcpy ( _dline -> compilerData -> block [ 17 ] .
visibleName , "HEV/Vehicle/Transmission \\\\nInertia" ) ; _dline ->
compilerData -> block [ 17 ] . type = DRIVEINERTIA ; _dline -> compilerData
-> block [ 17 ] . flange = _table -> INT32_table + 24 ; _dline ->
compilerData -> block [ 17 ] . flange [ 0 ] = 9 ; _dline -> compilerData ->
block [ 17 ] . inertia = _table -> DriveInertia_table + 1 ; _dline ->
compilerData -> block [ 17 ] . inertia [ 0 ] . inertia = 0.0015 ; _dline ->
compilerData -> block [ 18 ] . numFlanges = 2 ; _dline -> compilerData ->
block [ 18 ] . numParameters = 1 ; _dline -> compilerData -> block [ 18 ] .
parameter = _table -> DriveParameter_table + 7 ; _dline -> compilerData ->
block [ 18 ] . parameter [ 0 ] . type = DRIVERTP_SIMPLEGEARRATIO ; _dline ->
compilerData -> block [ 18 ] . parameter [ 0 ] . flag = ( char * ) ( _table
-> UINT8_table + 2082 ) ; strcpy ( _dline -> compilerData -> block [ 18 ] .
parameter [ 0 ] . flag , "drive_f09289b7GearRatio" ) ; _dline -> compilerData
-> block [ 18 ] . numSimpleGear = 1 ; _dline -> compilerData -> block [ 18 ]
. name = ( char * ) ( _table -> UINT8_table + 2106 ) ; strcpy ( _dline ->
compilerData -> block [ 18 ] . name , "HEV/Vehicle/Differential/Simple Gear1"
) ; _dline -> compilerData -> block [ 18 ] . visibleName = ( char * ) (
_table -> UINT8_table + 2144 ) ; strcpy ( _dline -> compilerData -> block [
18 ] . visibleName , "HEV/Vehicle/Differential" ) ; _dline -> compilerData ->
block [ 18 ] . type = DRIVESIMPLEGEAR ; _dline -> compilerData -> block [ 18
] . flange = _table -> INT32_table + 25 ; _dline -> compilerData -> block [
18 ] . flange [ 0 ] = 9 ; _dline -> compilerData -> block [ 18 ] . flange [ 1
] = 10 ; _dline -> compilerData -> block [ 18 ] . simpleGear = _table ->
DriveSimpleGear_table + 1 ; _dline -> compilerData -> block [ 18 ] .
simpleGear [ 0 ] . reversing = TRUE ; _dline -> compilerData -> block [ 18 ]
. simpleGear [ 0 ] . outputFlange = 1 ; _dline -> compilerData -> block [ 18
] . simpleGear [ 0 ] . ratio = 2.0 ; _dline -> compilerData -> block [ 19 ] .
numFlanges = 3 ; _dline -> compilerData -> block [ 19 ] . numParameters = 1 ;
_dline -> compilerData -> block [ 19 ] . parameter = _table ->
DriveParameter_table + 8 ; _dline -> compilerData -> block [ 19 ] . parameter
[ 0 ] . type = DRIVERTP_PLANETPLANETGEARRATIO ; _dline -> compilerData ->
block [ 19 ] . parameter [ 0 ] . flag = ( char * ) ( _table -> UINT8_table +
2169 ) ; strcpy ( _dline -> compilerData -> block [ 19 ] . parameter [ 0 ] .
flag , "drive_48b6a0f1PlanetPlanetRatio" ) ; _dline -> compilerData -> block
[ 19 ] . numPlanetPlanet = 1 ; _dline -> compilerData -> block [ 19 ] . name
= ( char * ) ( _table -> UINT8_table + 2201 ) ; strcpy ( _dline ->
compilerData -> block [ 19 ] . name ,
"HEV/Vehicle/Differential/Planet-Planet" ) ; _dline -> compilerData -> block
[ 19 ] . visibleName = ( char * ) ( _table -> UINT8_table + 2240 ) ; strcpy (
_dline -> compilerData -> block [ 19 ] . visibleName ,
"HEV/Vehicle/Differential" ) ; _dline -> compilerData -> block [ 19 ] . type
= DRIVEPLANETPLANET ; _dline -> compilerData -> block [ 19 ] . flange =
_table -> INT32_table + 27 ; _dline -> compilerData -> block [ 19 ] . flange
[ 0 ] = 10 ; _dline -> compilerData -> block [ 19 ] . flange [ 1 ] = 11 ;
_dline -> compilerData -> block [ 19 ] . flange [ 2 ] = 15 ; _dline ->
compilerData -> block [ 19 ] . planetPlanet = _table ->
DrivePlanetPlanet_table + 1 ; _dline -> compilerData -> block [ 19 ] .
planetPlanet [ 0 ] . sunFlange = 2 ; _dline -> compilerData -> block [ 19 ] .
planetPlanet [ 0 ] . planetFlange = 1 ; _dline -> compilerData -> block [ 19
] . planetPlanet [ 0 ] . ratio = 1.0 ; _dline -> compilerData -> block [ 20 ]
. numFlanges = 2 ; _dline -> compilerData -> block [ 20 ] . numParameters = 1
; _dline -> compilerData -> block [ 20 ] . parameter = _table ->
DriveParameter_table + 9 ; _dline -> compilerData -> block [ 20 ] . parameter
[ 0 ] . type = DRIVERTP_SIMPLEGEARRATIO ; _dline -> compilerData -> block [
20 ] . parameter [ 0 ] . flag = ( char * ) ( _table -> UINT8_table + 2265 ) ;
strcpy ( _dline -> compilerData -> block [ 20 ] . parameter [ 0 ] . flag ,
"drive_c8840e85GearRatio" ) ; _dline -> compilerData -> block [ 20 ] .
numSimpleGear = 1 ; _dline -> compilerData -> block [ 20 ] . name = ( char *
) ( _table -> UINT8_table + 2289 ) ; strcpy ( _dline -> compilerData -> block
[ 20 ] . name , "HEV/Vehicle/Differential/Simple Gear" ) ; _dline ->
compilerData -> block [ 20 ] . visibleName = ( char * ) ( _table ->
UINT8_table + 2326 ) ; strcpy ( _dline -> compilerData -> block [ 20 ] .
visibleName , "HEV/Vehicle/Differential" ) ; _dline -> compilerData -> block
[ 20 ] . type = DRIVESIMPLEGEAR ; _dline -> compilerData -> block [ 20 ] .
flange = _table -> INT32_table + 30 ; _dline -> compilerData -> block [ 20 ]
. flange [ 0 ] = 11 ; _dline -> compilerData -> block [ 20 ] . flange [ 1 ] =
12 ; _dline -> compilerData -> block [ 20 ] . simpleGear = _table ->
DriveSimpleGear_table + 2 ; _dline -> compilerData -> block [ 20 ] .
simpleGear [ 0 ] . reversing = TRUE ; _dline -> compilerData -> block [ 20 ]
. simpleGear [ 0 ] . outputFlange = 1 ; _dline -> compilerData -> block [ 20
] . simpleGear [ 0 ] . ratio = 1.0 ; _dline -> compilerData -> block [ 21 ] .
numFlanges = 3 ; _dline -> compilerData -> block [ 21 ] . numParameters = 1 ;
_dline -> compilerData -> block [ 21 ] . parameter = _table ->
DriveParameter_table + 10 ; _dline -> compilerData -> block [ 21 ] .
parameter [ 0 ] . type = DRIVERTP_PLANETPLANETGEARRATIO ; _dline ->
compilerData -> block [ 21 ] . parameter [ 0 ] . flag = ( char * ) ( _table
-> UINT8_table + 2351 ) ; strcpy ( _dline -> compilerData -> block [ 21 ] .
parameter [ 0 ] . flag , "drive_8aaf3b98PlanetPlanetRatio" ) ; _dline ->
compilerData -> block [ 21 ] . numPlanetPlanet = 1 ; _dline -> compilerData
-> block [ 21 ] . name = ( char * ) ( _table -> UINT8_table + 2383 ) ; strcpy
( _dline -> compilerData -> block [ 21 ] . name ,
"HEV/Vehicle/Differential/Planet-Planet1" ) ; _dline -> compilerData -> block
[ 21 ] . visibleName = ( char * ) ( _table -> UINT8_table + 2423 ) ; strcpy (
_dline -> compilerData -> block [ 21 ] . visibleName ,
"HEV/Vehicle/Differential" ) ; _dline -> compilerData -> block [ 21 ] . type
= DRIVEPLANETPLANET ; _dline -> compilerData -> block [ 21 ] . flange =
_table -> INT32_table + 32 ; _dline -> compilerData -> block [ 21 ] . flange
[ 0 ] = 12 ; _dline -> compilerData -> block [ 21 ] . flange [ 1 ] = 13 ;
_dline -> compilerData -> block [ 21 ] . flange [ 2 ] = 10 ; _dline ->
compilerData -> block [ 21 ] . planetPlanet = _table ->
DrivePlanetPlanet_table + 2 ; _dline -> compilerData -> block [ 21 ] .
planetPlanet [ 0 ] . sunFlange = 1 ; _dline -> compilerData -> block [ 21 ] .
planetPlanet [ 0 ] . carrierFlange = 2 ; _dline -> compilerData -> block [ 21
] . planetPlanet [ 0 ] . ratio = 1.0 ; _dline -> compilerData -> block [ 22 ]
. numFlanges = 2 ; _dline -> compilerData -> block [ 22 ] . numParameters = 1
; _dline -> compilerData -> block [ 22 ] . parameter = _table ->
DriveParameter_table + 11 ; _dline -> compilerData -> block [ 22 ] .
parameter [ 0 ] . type = DRIVERTP_SIMPLEGEARRATIO ; _dline -> compilerData ->
block [ 22 ] . parameter [ 0 ] . flag = ( char * ) ( _table -> UINT8_table +
2448 ) ; strcpy ( _dline -> compilerData -> block [ 22 ] . parameter [ 0 ] .
flag , "drive_699bd80dGearRatio" ) ; _dline -> compilerData -> block [ 22 ] .
numSimpleGear = 1 ; _dline -> compilerData -> block [ 22 ] . name = ( char *
) ( _table -> UINT8_table + 2472 ) ; strcpy ( _dline -> compilerData -> block
[ 22 ] . name , "HEV/Vehicle/Differential/Simple Gear2" ) ; _dline ->
compilerData -> block [ 22 ] . visibleName = ( char * ) ( _table ->
UINT8_table + 2510 ) ; strcpy ( _dline -> compilerData -> block [ 22 ] .
visibleName , "HEV/Vehicle/Differential" ) ; _dline -> compilerData -> block
[ 22 ] . type = DRIVESIMPLEGEAR ; _dline -> compilerData -> block [ 22 ] .
flange = _table -> INT32_table + 35 ; _dline -> compilerData -> block [ 22 ]
. flange [ 0 ] = 13 ; _dline -> compilerData -> block [ 22 ] . flange [ 1 ] =
14 ; _dline -> compilerData -> block [ 22 ] . simpleGear = _table ->
DriveSimpleGear_table + 3 ; _dline -> compilerData -> block [ 22 ] .
simpleGear [ 0 ] . reversing = TRUE ; _dline -> compilerData -> block [ 22 ]
. simpleGear [ 0 ] . outputFlange = 1 ; _dline -> compilerData -> block [ 22
] . simpleGear [ 0 ] . ratio = 1.0 ; _dline -> compilerData -> block [ 23 ] .
numFlanges = 1 ; _dline -> compilerData -> block [ 23 ] . numParameters = 2 ;
_dline -> compilerData -> block [ 23 ] . parameter = _table ->
DriveParameter_table + 12 ; _dline -> compilerData -> block [ 23 ] .
parameter [ 0 ] . type = DRIVERTP_INERTIA ; _dline -> compilerData -> block [
23 ] . parameter [ 0 ] . flag = ( char * ) ( _table -> UINT8_table + 2535 ) ;
strcpy ( _dline -> compilerData -> block [ 23 ] . parameter [ 0 ] . flag ,
"drive_66b082ddInertia" ) ; _dline -> compilerData -> block [ 23 ] .
parameter [ 1 ] . type = DRIVERTP_INITIALCONDITION ; _dline -> compilerData
-> block [ 23 ] . parameter [ 1 ] . flag = ( char * ) ( _table -> UINT8_table
+ 2557 ) ; strcpy ( _dline -> compilerData -> block [ 23 ] . parameter [ 1 ]
. flag , "drive_66b082ddInitialCondition" ) ; _dline -> compilerData -> block
[ 23 ] . numInertia = 1 ; _dline -> compilerData -> block [ 23 ] . name = (
char * ) ( _table -> UINT8_table + 2588 ) ; strcpy ( _dline -> compilerData
-> block [ 23 ] . name , "HEV/Vehicle/Right Tire Inertia" ) ; _dline ->
compilerData -> block [ 23 ] . visibleName = ( char * ) ( _table ->
UINT8_table + 2619 ) ; strcpy ( _dline -> compilerData -> block [ 23 ] .
visibleName , "HEV/Vehicle/Right Tire Inertia" ) ; _dline -> compilerData ->
block [ 23 ] . type = DRIVEINERTIA ; _dline -> compilerData -> block [ 23 ] .
flange = _table -> INT32_table + 37 ; _dline -> compilerData -> block [ 23 ]
. flange [ 0 ] = 14 ; _dline -> compilerData -> block [ 23 ] . inertia =
_table -> DriveInertia_table + 2 ; _dline -> compilerData -> block [ 23 ] .
inertia [ 0 ] . inertia = 0.5 ; _dline -> compilerData -> block [ 24 ] .
numFlanges = 1 ; _dline -> compilerData -> block [ 24 ] . numTransducer = 1 ;
_dline -> compilerData -> block [ 24 ] . name = ( char * ) ( _table ->
UINT8_table + 2650 ) ; strcpy ( _dline -> compilerData -> block [ 24 ] . name
, "HEV/Vehicle/Right Tire/Wheel dynamics/Motion Sensor/Transducer" ) ; _dline
-> compilerData -> block [ 24 ] . visibleName = ( char * ) ( _table ->
UINT8_table + 2713 ) ; strcpy ( _dline -> compilerData -> block [ 24 ] .
visibleName , "HEV/Vehicle/Right Tire" ) ; _dline -> compilerData -> block [
24 ] . type = DRIVETRANSDUCER ; _dline -> compilerData -> block [ 24 ] .
flange = _table -> INT32_table + 38 ; _dline -> compilerData -> block [ 24 ]
. flange [ 0 ] = 14 ; _dline -> compilerData -> block [ 24 ] . transducer =
_table -> DriveTransducer_table + 4 ; _dline -> compilerData -> block [ 24 ]
. transducer [ 0 ] . numSignals = 2 ; _dline -> compilerData -> block [ 24 ]
. transducer [ 0 ] . positionFlag = ( char * ) ( _table -> UINT8_table + 2736
) ; strcpy ( _dline -> compilerData -> block [ 24 ] . transducer [ 0 ] .
positionFlag , "Undefined" ) ; _dline -> compilerData -> block [ 24 ] .
transducer [ 0 ] . velocityFlag = ( char * ) ( _table -> UINT8_table + 2746 )
; strcpy ( _dline -> compilerData -> block [ 24 ] . transducer [ 0 ] .
velocityFlag , "Undefined" ) ; _dline -> compilerData -> block [ 24 ] .
transducer [ 0 ] . accelerationFlag = ( char * ) ( _table -> UINT8_table +
2756 ) ; strcpy ( _dline -> compilerData -> block [ 24 ] . transducer [ 0 ] .
accelerationFlag , "Undefined" ) ; _dline -> compilerData -> block [ 24 ] .
transducer [ 0 ] . signal = _table -> DriveSignal_table + 6 ; _dline ->
compilerData -> block [ 24 ] . transducer [ 0 ] . signal [ 0 ] . type =
DRIVEVELOCITY ; _dline -> compilerData -> block [ 24 ] . transducer [ 0 ] .
signal [ 0 ] . flag = ( char * ) ( _table -> UINT8_table + 2766 ) ; strcpy (
_dline -> compilerData -> block [ 24 ] . transducer [ 0 ] . signal [ 0 ] .
flag , "drive_41d49eb1Velocity" ) ; _dline -> compilerData -> block [ 24 ] .
transducer [ 0 ] . signal [ 1 ] . type = DRIVEACCELERATION ; _dline ->
compilerData -> block [ 24 ] . transducer [ 0 ] . signal [ 1 ] . flag = (
char * ) ( _table -> UINT8_table + 2789 ) ; strcpy ( _dline -> compilerData
-> block [ 24 ] . transducer [ 0 ] . signal [ 1 ] . flag ,
"drive_41d49eb1Acceleration" ) ; _dline -> compilerData -> block [ 25 ] .
numFlanges = 1 ; _dline -> compilerData -> block [ 25 ] . numTransducer = 1 ;
_dline -> compilerData -> block [ 25 ] . name = ( char * ) ( _table ->
UINT8_table + 2816 ) ; strcpy ( _dline -> compilerData -> block [ 25 ] . name
, "HEV/Vehicle/Right Tire/Wheel dynamics/Torque Actuator/Transducer" ) ;
_dline -> compilerData -> block [ 25 ] . visibleName = ( char * ) ( _table ->
UINT8_table + 2881 ) ; strcpy ( _dline -> compilerData -> block [ 25 ] .
visibleName , "HEV/Vehicle/Right Tire" ) ; _dline -> compilerData -> block [
25 ] . type = DRIVETRANSDUCER ; _dline -> compilerData -> block [ 25 ] .
flange = _table -> INT32_table + 39 ; _dline -> compilerData -> block [ 25 ]
. flange [ 0 ] = 14 ; _dline -> compilerData -> block [ 25 ] . transducer =
_table -> DriveTransducer_table + 5 ; _dline -> compilerData -> block [ 25 ]
. transducer [ 0 ] . numSignals = 1 ; _dline -> compilerData -> block [ 25 ]
. transducer [ 0 ] . positionFlag = ( char * ) ( _table -> UINT8_table + 2904
) ; strcpy ( _dline -> compilerData -> block [ 25 ] . transducer [ 0 ] .
positionFlag , "Undefined" ) ; _dline -> compilerData -> block [ 25 ] .
transducer [ 0 ] . velocityFlag = ( char * ) ( _table -> UINT8_table + 2914 )
; strcpy ( _dline -> compilerData -> block [ 25 ] . transducer [ 0 ] .
velocityFlag , "Undefined" ) ; _dline -> compilerData -> block [ 25 ] .
transducer [ 0 ] . accelerationFlag = ( char * ) ( _table -> UINT8_table +
2924 ) ; strcpy ( _dline -> compilerData -> block [ 25 ] . transducer [ 0 ] .
accelerationFlag , "Undefined" ) ; _dline -> compilerData -> block [ 25 ] .
transducer [ 0 ] . signal = _table -> DriveSignal_table + 8 ; _dline ->
compilerData -> block [ 25 ] . transducer [ 0 ] . signal [ 0 ] . type =
DRIVEEXTERNALTORQUE ; _dline -> compilerData -> block [ 25 ] . transducer [ 0
] . signal [ 0 ] . flag = ( char * ) ( _table -> UINT8_table + 2934 ) ;
strcpy ( _dline -> compilerData -> block [ 25 ] . transducer [ 0 ] . signal [
0 ] . flag , "drive_ebfa3480Tor" ) ; _dline -> compilerData -> block [ 26 ] .
numFlanges = 2 ; _dline -> compilerData -> block [ 26 ] . numParameters = 1 ;
_dline -> compilerData -> block [ 26 ] . parameter = _table ->
DriveParameter_table + 14 ; _dline -> compilerData -> block [ 26 ] .
parameter [ 0 ] . type = DRIVERTP_SIMPLEGEARRATIO ; _dline -> compilerData ->
block [ 26 ] . parameter [ 0 ] . flag = ( char * ) ( _table -> UINT8_table +
2952 ) ; strcpy ( _dline -> compilerData -> block [ 26 ] . parameter [ 0 ] .
flag , "drive_1e9ce89bGearRatio" ) ; _dline -> compilerData -> block [ 26 ] .
numSimpleGear = 1 ; _dline -> compilerData -> block [ 26 ] . name = ( char *
) ( _table -> UINT8_table + 2976 ) ; strcpy ( _dline -> compilerData -> block
[ 26 ] . name , "HEV/Vehicle/Differential/Simple Gear3" ) ; _dline ->
compilerData -> block [ 26 ] . visibleName = ( char * ) ( _table ->
UINT8_table + 3014 ) ; strcpy ( _dline -> compilerData -> block [ 26 ] .
visibleName , "HEV/Vehicle/Differential" ) ; _dline -> compilerData -> block
[ 26 ] . type = DRIVESIMPLEGEAR ; _dline -> compilerData -> block [ 26 ] .
flange = _table -> INT32_table + 40 ; _dline -> compilerData -> block [ 26 ]
. flange [ 0 ] = 15 ; _dline -> compilerData -> block [ 26 ] . flange [ 1 ] =
16 ; _dline -> compilerData -> block [ 26 ] . simpleGear = _table ->
DriveSimpleGear_table + 4 ; _dline -> compilerData -> block [ 26 ] .
simpleGear [ 0 ] . reversing = TRUE ; _dline -> compilerData -> block [ 26 ]
. simpleGear [ 0 ] . outputFlange = 1 ; _dline -> compilerData -> block [ 26
] . simpleGear [ 0 ] . ratio = 1.0 ; _dline -> compilerData -> block [ 27 ] .
numFlanges = 1 ; _dline -> compilerData -> block [ 27 ] . numParameters = 2 ;
_dline -> compilerData -> block [ 27 ] . parameter = _table ->
DriveParameter_table + 15 ; _dline -> compilerData -> block [ 27 ] .
parameter [ 0 ] . type = DRIVERTP_INERTIA ; _dline -> compilerData -> block [
27 ] . parameter [ 0 ] . flag = ( char * ) ( _table -> UINT8_table + 3039 ) ;
strcpy ( _dline -> compilerData -> block [ 27 ] . parameter [ 0 ] . flag ,
"drive_80d28a58Inertia" ) ; _dline -> compilerData -> block [ 27 ] .
parameter [ 1 ] . type = DRIVERTP_INITIALCONDITION ; _dline -> compilerData
-> block [ 27 ] . parameter [ 1 ] . flag = ( char * ) ( _table -> UINT8_table
+ 3061 ) ; strcpy ( _dline -> compilerData -> block [ 27 ] . parameter [ 1 ]
. flag , "drive_80d28a58InitialCondition" ) ; _dline -> compilerData -> block
[ 27 ] . numInertia = 1 ; _dline -> compilerData -> block [ 27 ] . name = (
char * ) ( _table -> UINT8_table + 3092 ) ; strcpy ( _dline -> compilerData
-> block [ 27 ] . name , "HEV/Vehicle/Left Tire Inertia" ) ; _dline ->
compilerData -> block [ 27 ] . visibleName = ( char * ) ( _table ->
UINT8_table + 3122 ) ; strcpy ( _dline -> compilerData -> block [ 27 ] .
visibleName , "HEV/Vehicle/Left Tire Inertia" ) ; _dline -> compilerData ->
block [ 27 ] . type = DRIVEINERTIA ; _dline -> compilerData -> block [ 27 ] .
flange = _table -> INT32_table + 42 ; _dline -> compilerData -> block [ 27 ]
. flange [ 0 ] = 16 ; _dline -> compilerData -> block [ 27 ] . inertia =
_table -> DriveInertia_table + 3 ; _dline -> compilerData -> block [ 27 ] .
inertia [ 0 ] . inertia = 0.5 ; _dline -> compilerData -> block [ 28 ] .
numFlanges = 1 ; _dline -> compilerData -> block [ 28 ] . numTransducer = 1 ;
_dline -> compilerData -> block [ 28 ] . name = ( char * ) ( _table ->
UINT8_table + 3152 ) ; strcpy ( _dline -> compilerData -> block [ 28 ] . name
, "HEV/Vehicle/Left Tire/Wheel dynamics/Motion Sensor/Transducer" ) ; _dline
-> compilerData -> block [ 28 ] . visibleName = ( char * ) ( _table ->
UINT8_table + 3214 ) ; strcpy ( _dline -> compilerData -> block [ 28 ] .
visibleName , "HEV/Vehicle/Left Tire" ) ; _dline -> compilerData -> block [
28 ] . type = DRIVETRANSDUCER ; _dline -> compilerData -> block [ 28 ] .
flange = _table -> INT32_table + 43 ; _dline -> compilerData -> block [ 28 ]
. flange [ 0 ] = 16 ; _dline -> compilerData -> block [ 28 ] . transducer =
_table -> DriveTransducer_table + 6 ; _dline -> compilerData -> block [ 28 ]
. transducer [ 0 ] . numSignals = 2 ; _dline -> compilerData -> block [ 28 ]
. transducer [ 0 ] . positionFlag = ( char * ) ( _table -> UINT8_table + 3236
) ; strcpy ( _dline -> compilerData -> block [ 28 ] . transducer [ 0 ] .
positionFlag , "Undefined" ) ; _dline -> compilerData -> block [ 28 ] .
transducer [ 0 ] . velocityFlag = ( char * ) ( _table -> UINT8_table + 3246 )
; strcpy ( _dline -> compilerData -> block [ 28 ] . transducer [ 0 ] .
velocityFlag , "Undefined" ) ; _dline -> compilerData -> block [ 28 ] .
transducer [ 0 ] . accelerationFlag = ( char * ) ( _table -> UINT8_table +
3256 ) ; strcpy ( _dline -> compilerData -> block [ 28 ] . transducer [ 0 ] .
accelerationFlag , "Undefined" ) ; _dline -> compilerData -> block [ 28 ] .
transducer [ 0 ] . signal = _table -> DriveSignal_table + 9 ; _dline ->
compilerData -> block [ 28 ] . transducer [ 0 ] . signal [ 0 ] . type =
DRIVEVELOCITY ; _dline -> compilerData -> block [ 28 ] . transducer [ 0 ] .
signal [ 0 ] . flag = ( char * ) ( _table -> UINT8_table + 3266 ) ; strcpy (
_dline -> compilerData -> block [ 28 ] . transducer [ 0 ] . signal [ 0 ] .
flag , "drive_8c9aa461Velocity" ) ; _dline -> compilerData -> block [ 28 ] .
transducer [ 0 ] . signal [ 1 ] . type = DRIVEACCELERATION ; _dline ->
compilerData -> block [ 28 ] . transducer [ 0 ] . signal [ 1 ] . flag = (
char * ) ( _table -> UINT8_table + 3289 ) ; strcpy ( _dline -> compilerData
-> block [ 28 ] . transducer [ 0 ] . signal [ 1 ] . flag ,
"drive_8c9aa461Acceleration" ) ; _dline -> compilerData -> block [ 29 ] .
numFlanges = 1 ; _dline -> compilerData -> block [ 29 ] . numTransducer = 1 ;
_dline -> compilerData -> block [ 29 ] . name = ( char * ) ( _table ->
UINT8_table + 3316 ) ; strcpy ( _dline -> compilerData -> block [ 29 ] . name
, "HEV/Vehicle/Left Tire/Wheel dynamics/Torque Actuator/Transducer" ) ;
_dline -> compilerData -> block [ 29 ] . visibleName = ( char * ) ( _table ->
UINT8_table + 3380 ) ; strcpy ( _dline -> compilerData -> block [ 29 ] .
visibleName , "HEV/Vehicle/Left Tire" ) ; _dline -> compilerData -> block [
29 ] . type = DRIVETRANSDUCER ; _dline -> compilerData -> block [ 29 ] .
flange = _table -> INT32_table + 44 ; _dline -> compilerData -> block [ 29 ]
. flange [ 0 ] = 16 ; _dline -> compilerData -> block [ 29 ] . transducer =
_table -> DriveTransducer_table + 7 ; _dline -> compilerData -> block [ 29 ]
. transducer [ 0 ] . numSignals = 1 ; _dline -> compilerData -> block [ 29 ]
. transducer [ 0 ] . positionFlag = ( char * ) ( _table -> UINT8_table + 3402
) ; strcpy ( _dline -> compilerData -> block [ 29 ] . transducer [ 0 ] .
positionFlag , "Undefined" ) ; _dline -> compilerData -> block [ 29 ] .
transducer [ 0 ] . velocityFlag = ( char * ) ( _table -> UINT8_table + 3412 )
; strcpy ( _dline -> compilerData -> block [ 29 ] . transducer [ 0 ] .
velocityFlag , "Undefined" ) ; _dline -> compilerData -> block [ 29 ] .
transducer [ 0 ] . accelerationFlag = ( char * ) ( _table -> UINT8_table +
3422 ) ; strcpy ( _dline -> compilerData -> block [ 29 ] . transducer [ 0 ] .
accelerationFlag , "Undefined" ) ; _dline -> compilerData -> block [ 29 ] .
transducer [ 0 ] . signal = _table -> DriveSignal_table + 11 ; _dline ->
compilerData -> block [ 29 ] . transducer [ 0 ] . signal [ 0 ] . type =
DRIVEEXTERNALTORQUE ; _dline -> compilerData -> block [ 29 ] . transducer [ 0
] . signal [ 0 ] . flag = ( char * ) ( _table -> UINT8_table + 3432 ) ;
strcpy ( _dline -> compilerData -> block [ 29 ] . transducer [ 0 ] . signal [
0 ] . flag , "drive_6f7d31d9Tor" ) ; _dline -> compilerData -> block [ 30 ] .
numFlanges = 1 ; _dline -> compilerData -> block [ 30 ] . numTransducer = 1 ;
_dline -> compilerData -> block [ 30 ] . name = ( char * ) ( _table ->
UINT8_table + 3450 ) ; strcpy ( _dline -> compilerData -> block [ 30 ] . name
,
 "HEV/Vehicle/Torsional \\\\nSpring-Damper \\\\n(Friction)/follower_torque/Transducer"
) ; _dline -> compilerData -> block [ 30 ] . visibleName = ( char * ) (
_table -> UINT8_table + 3526 ) ; strcpy ( _dline -> compilerData -> block [
30 ] . visibleName ,
"HEV/Vehicle/Torsional \\\\nSpring-Damper \\\\n(Friction)" ) ; _dline ->
compilerData -> block [ 30 ] . type = DRIVETRANSDUCER ; _dline ->
compilerData -> block [ 30 ] . flange = _table -> INT32_table + 45 ; _dline
-> compilerData -> block [ 30 ] . flange [ 0 ] = 7 ; _dline -> compilerData
-> block [ 30 ] . transducer = _table -> DriveTransducer_table + 8 ; _dline
-> compilerData -> block [ 30 ] . transducer [ 0 ] . numSignals = 1 ; _dline
-> compilerData -> block [ 30 ] . transducer [ 0 ] . positionFlag = ( char *
) ( _table -> UINT8_table + 3575 ) ; strcpy ( _dline -> compilerData -> block
[ 30 ] . transducer [ 0 ] . positionFlag , "Undefined" ) ; _dline ->
compilerData -> block [ 30 ] . transducer [ 0 ] . velocityFlag = ( char * ) (
_table -> UINT8_table + 3585 ) ; strcpy ( _dline -> compilerData -> block [
30 ] . transducer [ 0 ] . velocityFlag , "Undefined" ) ; _dline ->
compilerData -> block [ 30 ] . transducer [ 0 ] . accelerationFlag = ( char *
) ( _table -> UINT8_table + 3595 ) ; strcpy ( _dline -> compilerData -> block
[ 30 ] . transducer [ 0 ] . accelerationFlag , "Undefined" ) ; _dline ->
compilerData -> block [ 30 ] . transducer [ 0 ] . signal = _table ->
DriveSignal_table + 12 ; _dline -> compilerData -> block [ 30 ] . transducer
[ 0 ] . signal [ 0 ] . type = DRIVEEXTERNALTORQUE ; _dline -> compilerData ->
block [ 30 ] . transducer [ 0 ] . signal [ 0 ] . flag = ( char * ) ( _table
-> UINT8_table + 3605 ) ; strcpy ( _dline -> compilerData -> block [ 30 ] .
transducer [ 0 ] . signal [ 0 ] . flag , "drive_46a5b3a3Tor" ) ; _dline ->
compilerData -> block [ 31 ] . numFlanges = 1 ; _dline -> compilerData ->
block [ 31 ] . numTransducer = 1 ; _dline -> compilerData -> block [ 31 ] .
name = ( char * ) ( _table -> UINT8_table + 3623 ) ; strcpy ( _dline ->
compilerData -> block [ 31 ] . name ,
 "HEV/Vehicle/Torsional \\\\nSpring-Damper \\\\n(Friction)/follower_velocity/Transducer"
) ; _dline -> compilerData -> block [ 31 ] . visibleName = ( char * ) (
_table -> UINT8_table + 3701 ) ; strcpy ( _dline -> compilerData -> block [
31 ] . visibleName ,
"HEV/Vehicle/Torsional \\\\nSpring-Damper \\\\n(Friction)" ) ; _dline ->
compilerData -> block [ 31 ] . type = DRIVETRANSDUCER ; _dline ->
compilerData -> block [ 31 ] . flange = _table -> INT32_table + 46 ; _dline
-> compilerData -> block [ 31 ] . flange [ 0 ] = 7 ; _dline -> compilerData
-> block [ 31 ] . transducer = _table -> DriveTransducer_table + 9 ; _dline
-> compilerData -> block [ 31 ] . transducer [ 0 ] . numSignals = 2 ; _dline
-> compilerData -> block [ 31 ] . transducer [ 0 ] . positionFlag = ( char *
) ( _table -> UINT8_table + 3750 ) ; strcpy ( _dline -> compilerData -> block
[ 31 ] . transducer [ 0 ] . positionFlag , "Undefined" ) ; _dline ->
compilerData -> block [ 31 ] . transducer [ 0 ] . velocityFlag = ( char * ) (
_table -> UINT8_table + 3760 ) ; strcpy ( _dline -> compilerData -> block [
31 ] . transducer [ 0 ] . velocityFlag , "Undefined" ) ; _dline ->
compilerData -> block [ 31 ] . transducer [ 0 ] . accelerationFlag = ( char *
) ( _table -> UINT8_table + 3770 ) ; strcpy ( _dline -> compilerData -> block
[ 31 ] . transducer [ 0 ] . accelerationFlag , "Undefined" ) ; _dline ->
compilerData -> block [ 31 ] . transducer [ 0 ] . signal = _table ->
DriveSignal_table + 13 ; _dline -> compilerData -> block [ 31 ] . transducer
[ 0 ] . signal [ 0 ] . type = DRIVEVELOCITY ; _dline -> compilerData -> block
[ 31 ] . transducer [ 0 ] . signal [ 0 ] . flag = ( char * ) ( _table ->
UINT8_table + 3780 ) ; strcpy ( _dline -> compilerData -> block [ 31 ] .
transducer [ 0 ] . signal [ 0 ] . flag , "drive_e5b2ea75Velocity" ) ; _dline
-> compilerData -> block [ 31 ] . transducer [ 0 ] . signal [ 1 ] . type =
DRIVEACCELERATION ; _dline -> compilerData -> block [ 31 ] . transducer [ 0 ]
. signal [ 1 ] . flag = ( char * ) ( _table -> UINT8_table + 3803 ) ; strcpy
( _dline -> compilerData -> block [ 31 ] . transducer [ 0 ] . signal [ 1 ] .
flag , "drive_e5b2ea75Acceleration" ) ; _dline -> compilerData -> block [ 32
] . numFlanges = 1 ; _dline -> compilerData -> block [ 32 ] . numTransducer =
1 ; _dline -> compilerData -> block [ 32 ] . name = ( char * ) ( _table ->
UINT8_table + 3830 ) ; strcpy ( _dline -> compilerData -> block [ 32 ] . name
, "HEV/Electric Motor Controller\\\\n/Motor Motion Sensor/Transducer" ) ;
_dline -> compilerData -> block [ 32 ] . visibleName = ( char * ) ( _table ->
UINT8_table + 3892 ) ; strcpy ( _dline -> compilerData -> block [ 32 ] .
visibleName , "HEV/Electric Motor Controller\\\\n/Motor Motion Sensor" ) ;
_dline -> compilerData -> block [ 32 ] . type = DRIVETRANSDUCER ; _dline ->
compilerData -> block [ 32 ] . flange = _table -> INT32_table + 47 ; _dline
-> compilerData -> block [ 32 ] . flange [ 0 ] = 6 ; _dline -> compilerData
-> block [ 32 ] . transducer = _table -> DriveTransducer_table + 10 ; _dline
-> compilerData -> block [ 32 ] . transducer [ 0 ] . numSignals = 2 ; _dline
-> compilerData -> block [ 32 ] . transducer [ 0 ] . positionFlag = ( char *
) ( _table -> UINT8_table + 3943 ) ; strcpy ( _dline -> compilerData -> block
[ 32 ] . transducer [ 0 ] . positionFlag , "Undefined" ) ; _dline ->
compilerData -> block [ 32 ] . transducer [ 0 ] . velocityFlag = ( char * ) (
_table -> UINT8_table + 3953 ) ; strcpy ( _dline -> compilerData -> block [
32 ] . transducer [ 0 ] . velocityFlag , "Undefined" ) ; _dline ->
compilerData -> block [ 32 ] . transducer [ 0 ] . accelerationFlag = ( char *
) ( _table -> UINT8_table + 3963 ) ; strcpy ( _dline -> compilerData -> block
[ 32 ] . transducer [ 0 ] . accelerationFlag , "Undefined" ) ; _dline ->
compilerData -> block [ 32 ] . transducer [ 0 ] . signal = _table ->
DriveSignal_table + 15 ; _dline -> compilerData -> block [ 32 ] . transducer
[ 0 ] . signal [ 0 ] . type = DRIVEVELOCITY ; _dline -> compilerData -> block
[ 32 ] . transducer [ 0 ] . signal [ 0 ] . flag = ( char * ) ( _table ->
UINT8_table + 3973 ) ; strcpy ( _dline -> compilerData -> block [ 32 ] .
transducer [ 0 ] . signal [ 0 ] . flag , "drive_f4b8de34Velocity" ) ; _dline
-> compilerData -> block [ 32 ] . transducer [ 0 ] . signal [ 1 ] . type =
DRIVEACCELERATION ; _dline -> compilerData -> block [ 32 ] . transducer [ 0 ]
. signal [ 1 ] . flag = ( char * ) ( _table -> UINT8_table + 3996 ) ; strcpy
( _dline -> compilerData -> block [ 32 ] . transducer [ 0 ] . signal [ 1 ] .
flag , "drive_f4b8de34Acceleration" ) ; _dline -> compilerData -> block [ 33
] . numFlanges = 1 ; _dline -> compilerData -> block [ 33 ] . numTransducer =
1 ; _dline -> compilerData -> block [ 33 ] . name = ( char * ) ( _table ->
UINT8_table + 4023 ) ; strcpy ( _dline -> compilerData -> block [ 33 ] . name
, "HEV/Electric Motor Controller\\\\n/Torque Actuator Mot/Transducer" ) ;
_dline -> compilerData -> block [ 33 ] . visibleName = ( char * ) ( _table ->
UINT8_table + 4085 ) ; strcpy ( _dline -> compilerData -> block [ 33 ] .
visibleName , "HEV/Electric Motor Controller\\\\n/Torque Actuator Mot" ) ;
_dline -> compilerData -> block [ 33 ] . type = DRIVETRANSDUCER ; _dline ->
compilerData -> block [ 33 ] . flange = _table -> INT32_table + 48 ; _dline
-> compilerData -> block [ 33 ] . flange [ 0 ] = 6 ; _dline -> compilerData
-> block [ 33 ] . transducer = _table -> DriveTransducer_table + 11 ; _dline
-> compilerData -> block [ 33 ] . transducer [ 0 ] . numSignals = 1 ; _dline
-> compilerData -> block [ 33 ] . transducer [ 0 ] . positionFlag = ( char *
) ( _table -> UINT8_table + 4136 ) ; strcpy ( _dline -> compilerData -> block
[ 33 ] . transducer [ 0 ] . positionFlag , "Undefined" ) ; _dline ->
compilerData -> block [ 33 ] . transducer [ 0 ] . velocityFlag = ( char * ) (
_table -> UINT8_table + 4146 ) ; strcpy ( _dline -> compilerData -> block [
33 ] . transducer [ 0 ] . velocityFlag , "Undefined" ) ; _dline ->
compilerData -> block [ 33 ] . transducer [ 0 ] . accelerationFlag = ( char *
) ( _table -> UINT8_table + 4156 ) ; strcpy ( _dline -> compilerData -> block
[ 33 ] . transducer [ 0 ] . accelerationFlag , "Undefined" ) ; _dline ->
compilerData -> block [ 33 ] . transducer [ 0 ] . signal = _table ->
DriveSignal_table + 17 ; _dline -> compilerData -> block [ 33 ] . transducer
[ 0 ] . signal [ 0 ] . type = DRIVEEXTERNALTORQUE ; _dline -> compilerData ->
block [ 33 ] . transducer [ 0 ] . signal [ 0 ] . flag = ( char * ) ( _table
-> UINT8_table + 4166 ) ; strcpy ( _dline -> compilerData -> block [ 33 ] .
transducer [ 0 ] . signal [ 0 ] . flag , "drive_ccb66a09Tor" ) ; _dline ->
compilerData -> block [ 34 ] . numFlanges = 1 ; _dline -> compilerData ->
block [ 34 ] . numTransducer = 1 ; _dline -> compilerData -> block [ 34 ] .
name = ( char * ) ( _table -> UINT8_table + 4184 ) ; strcpy ( _dline ->
compilerData -> block [ 34 ] . name ,
"HEV/Gearbox/Mot Motion Sensor/Transducer" ) ; _dline -> compilerData ->
block [ 34 ] . visibleName = ( char * ) ( _table -> UINT8_table + 4225 ) ;
strcpy ( _dline -> compilerData -> block [ 34 ] . visibleName ,
"HEV/Gearbox/Mot Motion Sensor" ) ; _dline -> compilerData -> block [ 34 ] .
type = DRIVETRANSDUCER ; _dline -> compilerData -> block [ 34 ] . flange =
_table -> INT32_table + 49 ; _dline -> compilerData -> block [ 34 ] . flange
[ 0 ] = 6 ; _dline -> compilerData -> block [ 34 ] . transducer = _table ->
DriveTransducer_table + 12 ; _dline -> compilerData -> block [ 34 ] .
transducer [ 0 ] . numSignals = 2 ; _dline -> compilerData -> block [ 34 ] .
transducer [ 0 ] . positionFlag = ( char * ) ( _table -> UINT8_table + 4255 )
; strcpy ( _dline -> compilerData -> block [ 34 ] . transducer [ 0 ] .
positionFlag , "Undefined" ) ; _dline -> compilerData -> block [ 34 ] .
transducer [ 0 ] . velocityFlag = ( char * ) ( _table -> UINT8_table + 4265 )
; strcpy ( _dline -> compilerData -> block [ 34 ] . transducer [ 0 ] .
velocityFlag , "Undefined" ) ; _dline -> compilerData -> block [ 34 ] .
transducer [ 0 ] . accelerationFlag = ( char * ) ( _table -> UINT8_table +
4275 ) ; strcpy ( _dline -> compilerData -> block [ 34 ] . transducer [ 0 ] .
accelerationFlag , "Undefined" ) ; _dline -> compilerData -> block [ 34 ] .
transducer [ 0 ] . signal = _table -> DriveSignal_table + 18 ; _dline ->
compilerData -> block [ 34 ] . transducer [ 0 ] . signal [ 0 ] . type =
DRIVEVELOCITY ; _dline -> compilerData -> block [ 34 ] . transducer [ 0 ] .
signal [ 0 ] . flag = ( char * ) ( _table -> UINT8_table + 4285 ) ; strcpy (
_dline -> compilerData -> block [ 34 ] . transducer [ 0 ] . signal [ 0 ] .
flag , "drive_dc17081aVelocity" ) ; _dline -> compilerData -> block [ 34 ] .
transducer [ 0 ] . signal [ 1 ] . type = DRIVEACCELERATION ; _dline ->
compilerData -> block [ 34 ] . transducer [ 0 ] . signal [ 1 ] . flag = (
char * ) ( _table -> UINT8_table + 4308 ) ; strcpy ( _dline -> compilerData
-> block [ 34 ] . transducer [ 0 ] . signal [ 1 ] . flag ,
"drive_dc17081aAcceleration" ) ; _dline -> compilerData -> block [ 35 ] .
numFlanges = 2 ; _dline -> compilerData -> block [ 35 ] . numStrainGauge = 1
; _dline -> compilerData -> block [ 35 ] . name = ( char * ) ( _table ->
UINT8_table + 4335 ) ; strcpy ( _dline -> compilerData -> block [ 35 ] . name
, "HEV/Gearbox/Torque Sensor1/Torque Sensor\\\\nInternal" ) ; _dline ->
compilerData -> block [ 35 ] . visibleName = ( char * ) ( _table ->
UINT8_table + 4385 ) ; strcpy ( _dline -> compilerData -> block [ 35 ] .
visibleName , "HEV/Gearbox/Torque Sensor1" ) ; _dline -> compilerData ->
block [ 35 ] . type = DRIVESTRAINGAUGE ; _dline -> compilerData -> block [ 35
] . flange = _table -> INT32_table + 50 ; _dline -> compilerData -> block [
35 ] . flange [ 0 ] = 17 ; _dline -> compilerData -> block [ 35 ] . flange [
1 ] = 18 ; _dline -> compilerData -> block [ 35 ] . strainGauge = _table ->
DriveStrainGauge_table + 4 ; _dline -> compilerData -> block [ 35 ] .
strainGauge [ 0 ] . measurementFlange = 1 ; _dline -> compilerData -> block [
35 ] . strainGauge [ 0 ] . flag = ( char * ) ( _table -> UINT8_table + 4412 )
; strcpy ( _dline -> compilerData -> block [ 35 ] . strainGauge [ 0 ] . flag
, "drive_1dce1e1" ) ; _dline -> compilerData -> block [ 36 ] . numFlanges = 1
; _dline -> compilerData -> block [ 36 ] . numTransducer = 1 ; _dline ->
compilerData -> block [ 36 ] . name = ( char * ) ( _table -> UINT8_table +
4426 ) ; strcpy ( _dline -> compilerData -> block [ 36 ] . name ,
"HEV/Electric Motor Controller\\\\n/Gen Motion Sensor/Transducer" ) ; _dline
-> compilerData -> block [ 36 ] . visibleName = ( char * ) ( _table ->
UINT8_table + 4486 ) ; strcpy ( _dline -> compilerData -> block [ 36 ] .
visibleName , "HEV/Electric Motor Controller\\\\n/Gen Motion Sensor" ) ;
_dline -> compilerData -> block [ 36 ] . type = DRIVETRANSDUCER ; _dline ->
compilerData -> block [ 36 ] . flange = _table -> INT32_table + 52 ; _dline
-> compilerData -> block [ 36 ] . flange [ 0 ] = 18 ; _dline -> compilerData
-> block [ 36 ] . transducer = _table -> DriveTransducer_table + 13 ; _dline
-> compilerData -> block [ 36 ] . transducer [ 0 ] . numSignals = 2 ; _dline
-> compilerData -> block [ 36 ] . transducer [ 0 ] . positionFlag = ( char *
) ( _table -> UINT8_table + 4535 ) ; strcpy ( _dline -> compilerData -> block
[ 36 ] . transducer [ 0 ] . positionFlag , "Undefined" ) ; _dline ->
compilerData -> block [ 36 ] . transducer [ 0 ] . velocityFlag = ( char * ) (
_table -> UINT8_table + 4545 ) ; strcpy ( _dline -> compilerData -> block [
36 ] . transducer [ 0 ] . velocityFlag , "Undefined" ) ; _dline ->
compilerData -> block [ 36 ] . transducer [ 0 ] . accelerationFlag = ( char *
) ( _table -> UINT8_table + 4555 ) ; strcpy ( _dline -> compilerData -> block
[ 36 ] . transducer [ 0 ] . accelerationFlag , "Undefined" ) ; _dline ->
compilerData -> block [ 36 ] . transducer [ 0 ] . signal = _table ->
DriveSignal_table + 20 ; _dline -> compilerData -> block [ 36 ] . transducer
[ 0 ] . signal [ 0 ] . type = DRIVEVELOCITY ; _dline -> compilerData -> block
[ 36 ] . transducer [ 0 ] . signal [ 0 ] . flag = ( char * ) ( _table ->
UINT8_table + 4565 ) ; strcpy ( _dline -> compilerData -> block [ 36 ] .
transducer [ 0 ] . signal [ 0 ] . flag , "drive_fc09825aVelocity" ) ; _dline
-> compilerData -> block [ 36 ] . transducer [ 0 ] . signal [ 1 ] . type =
DRIVEACCELERATION ; _dline -> compilerData -> block [ 36 ] . transducer [ 0 ]
. signal [ 1 ] . flag = ( char * ) ( _table -> UINT8_table + 4588 ) ; strcpy
( _dline -> compilerData -> block [ 36 ] . transducer [ 0 ] . signal [ 1 ] .
flag , "drive_fc09825aAcceleration" ) ; _dline -> compilerData -> block [ 37
] . numFlanges = 1 ; _dline -> compilerData -> block [ 37 ] . numTransducer =
1 ; _dline -> compilerData -> block [ 37 ] . name = ( char * ) ( _table ->
UINT8_table + 4615 ) ; strcpy ( _dline -> compilerData -> block [ 37 ] . name
, "HEV/Electric Motor Controller\\\\n/Torque Actuator Gen/Transducer" ) ;
_dline -> compilerData -> block [ 37 ] . visibleName = ( char * ) ( _table ->
UINT8_table + 4677 ) ; strcpy ( _dline -> compilerData -> block [ 37 ] .
visibleName , "HEV/Electric Motor Controller\\\\n/Torque Actuator Gen" ) ;
_dline -> compilerData -> block [ 37 ] . type = DRIVETRANSDUCER ; _dline ->
compilerData -> block [ 37 ] . flange = _table -> INT32_table + 53 ; _dline
-> compilerData -> block [ 37 ] . flange [ 0 ] = 18 ; _dline -> compilerData
-> block [ 37 ] . transducer = _table -> DriveTransducer_table + 14 ; _dline
-> compilerData -> block [ 37 ] . transducer [ 0 ] . numSignals = 1 ; _dline
-> compilerData -> block [ 37 ] . transducer [ 0 ] . positionFlag = ( char *
) ( _table -> UINT8_table + 4728 ) ; strcpy ( _dline -> compilerData -> block
[ 37 ] . transducer [ 0 ] . positionFlag , "Undefined" ) ; _dline ->
compilerData -> block [ 37 ] . transducer [ 0 ] . velocityFlag = ( char * ) (
_table -> UINT8_table + 4738 ) ; strcpy ( _dline -> compilerData -> block [
37 ] . transducer [ 0 ] . velocityFlag , "Undefined" ) ; _dline ->
compilerData -> block [ 37 ] . transducer [ 0 ] . accelerationFlag = ( char *
) ( _table -> UINT8_table + 4748 ) ; strcpy ( _dline -> compilerData -> block
[ 37 ] . transducer [ 0 ] . accelerationFlag , "Undefined" ) ; _dline ->
compilerData -> block [ 37 ] . transducer [ 0 ] . signal = _table ->
DriveSignal_table + 22 ; _dline -> compilerData -> block [ 37 ] . transducer
[ 0 ] . signal [ 0 ] . type = DRIVEEXTERNALTORQUE ; _dline -> compilerData ->
block [ 37 ] . transducer [ 0 ] . signal [ 0 ] . flag = ( char * ) ( _table
-> UINT8_table + 4758 ) ; strcpy ( _dline -> compilerData -> block [ 37 ] .
transducer [ 0 ] . signal [ 0 ] . flag , "drive_831c2968Tor" ) ; _dline ->
compilerData -> block [ 38 ] . numFlanges = 1 ; _dline -> compilerData ->
block [ 38 ] . numTransducer = 1 ; _dline -> compilerData -> block [ 38 ] .
name = ( char * ) ( _table -> UINT8_table + 4776 ) ; strcpy ( _dline ->
compilerData -> block [ 38 ] . name ,
"HEV/Gearbox/Gen Motion Sensor/Transducer" ) ; _dline -> compilerData ->
block [ 38 ] . visibleName = ( char * ) ( _table -> UINT8_table + 4817 ) ;
strcpy ( _dline -> compilerData -> block [ 38 ] . visibleName ,
"HEV/Gearbox/Gen Motion Sensor" ) ; _dline -> compilerData -> block [ 38 ] .
type = DRIVETRANSDUCER ; _dline -> compilerData -> block [ 38 ] . flange =
_table -> INT32_table + 54 ; _dline -> compilerData -> block [ 38 ] . flange
[ 0 ] = 18 ; _dline -> compilerData -> block [ 38 ] . transducer = _table ->
DriveTransducer_table + 15 ; _dline -> compilerData -> block [ 38 ] .
transducer [ 0 ] . numSignals = 2 ; _dline -> compilerData -> block [ 38 ] .
transducer [ 0 ] . positionFlag = ( char * ) ( _table -> UINT8_table + 4847 )
; strcpy ( _dline -> compilerData -> block [ 38 ] . transducer [ 0 ] .
positionFlag , "Undefined" ) ; _dline -> compilerData -> block [ 38 ] .
transducer [ 0 ] . velocityFlag = ( char * ) ( _table -> UINT8_table + 4857 )
; strcpy ( _dline -> compilerData -> block [ 38 ] . transducer [ 0 ] .
velocityFlag , "Undefined" ) ; _dline -> compilerData -> block [ 38 ] .
transducer [ 0 ] . accelerationFlag = ( char * ) ( _table -> UINT8_table +
4867 ) ; strcpy ( _dline -> compilerData -> block [ 38 ] . transducer [ 0 ] .
accelerationFlag , "Undefined" ) ; _dline -> compilerData -> block [ 38 ] .
transducer [ 0 ] . signal = _table -> DriveSignal_table + 23 ; _dline ->
compilerData -> block [ 38 ] . transducer [ 0 ] . signal [ 0 ] . type =
DRIVEVELOCITY ; _dline -> compilerData -> block [ 38 ] . transducer [ 0 ] .
signal [ 0 ] . flag = ( char * ) ( _table -> UINT8_table + 4877 ) ; strcpy (
_dline -> compilerData -> block [ 38 ] . transducer [ 0 ] . signal [ 0 ] .
flag , "drive_53507db2Velocity" ) ; _dline -> compilerData -> block [ 38 ] .
transducer [ 0 ] . signal [ 1 ] . type = DRIVEACCELERATION ; _dline ->
compilerData -> block [ 38 ] . transducer [ 0 ] . signal [ 1 ] . flag = (
char * ) ( _table -> UINT8_table + 4900 ) ; strcpy ( _dline -> compilerData
-> block [ 38 ] . transducer [ 0 ] . signal [ 1 ] . flag ,
"drive_53507db2Acceleration" ) ; _dline -> compilerData -> block [ 39 ] .
numFlanges = 1 ; _dline -> compilerData -> block [ 39 ] . numTransducer = 1 ;
_dline -> compilerData -> block [ 39 ] . name = ( char * ) ( _table ->
UINT8_table + 4927 ) ; strcpy ( _dline -> compilerData -> block [ 39 ] . name
, "HEV/Gearbox/Eng Motion Sensor/Transducer" ) ; _dline -> compilerData ->
block [ 39 ] . visibleName = ( char * ) ( _table -> UINT8_table + 4968 ) ;
strcpy ( _dline -> compilerData -> block [ 39 ] . visibleName ,
"HEV/Gearbox/Eng Motion Sensor" ) ; _dline -> compilerData -> block [ 39 ] .
type = DRIVETRANSDUCER ; _dline -> compilerData -> block [ 39 ] . flange =
_table -> INT32_table + 55 ; _dline -> compilerData -> block [ 39 ] . flange
[ 0 ] = 3 ; _dline -> compilerData -> block [ 39 ] . transducer = _table ->
DriveTransducer_table + 16 ; _dline -> compilerData -> block [ 39 ] .
transducer [ 0 ] . numSignals = 2 ; _dline -> compilerData -> block [ 39 ] .
transducer [ 0 ] . positionFlag = ( char * ) ( _table -> UINT8_table + 4998 )
; strcpy ( _dline -> compilerData -> block [ 39 ] . transducer [ 0 ] .
positionFlag , "Undefined" ) ; _dline -> compilerData -> block [ 39 ] .
transducer [ 0 ] . velocityFlag = ( char * ) ( _table -> UINT8_table + 5008 )
; strcpy ( _dline -> compilerData -> block [ 39 ] . transducer [ 0 ] .
velocityFlag , "Undefined" ) ; _dline -> compilerData -> block [ 39 ] .
transducer [ 0 ] . accelerationFlag = ( char * ) ( _table -> UINT8_table +
5018 ) ; strcpy ( _dline -> compilerData -> block [ 39 ] . transducer [ 0 ] .
accelerationFlag , "Undefined" ) ; _dline -> compilerData -> block [ 39 ] .
transducer [ 0 ] . signal = _table -> DriveSignal_table + 25 ; _dline ->
compilerData -> block [ 39 ] . transducer [ 0 ] . signal [ 0 ] . type =
DRIVEVELOCITY ; _dline -> compilerData -> block [ 39 ] . transducer [ 0 ] .
signal [ 0 ] . flag = ( char * ) ( _table -> UINT8_table + 5028 ) ; strcpy (
_dline -> compilerData -> block [ 39 ] . transducer [ 0 ] . signal [ 0 ] .
flag , "drive_f9653595Velocity" ) ; _dline -> compilerData -> block [ 39 ] .
transducer [ 0 ] . signal [ 1 ] . type = DRIVEACCELERATION ; _dline ->
compilerData -> block [ 39 ] . transducer [ 0 ] . signal [ 1 ] . flag = (
char * ) ( _table -> UINT8_table + 5051 ) ; strcpy ( _dline -> compilerData
-> block [ 39 ] . transducer [ 0 ] . signal [ 1 ] . flag ,
"drive_f9653595Acceleration" ) ; _dline -> compilerData -> block [ 40 ] .
numFlanges = 1 ; _dline -> compilerData -> block [ 40 ] . numTransducer = 1 ;
_dline -> compilerData -> block [ 40 ] . name = ( char * ) ( _table ->
UINT8_table + 5078 ) ; strcpy ( _dline -> compilerData -> block [ 40 ] . name
, "HEV/Engine Controller/Gasoline Engine/Motion Sensor/Transducer" ) ; _dline
-> compilerData -> block [ 40 ] . visibleName = ( char * ) ( _table ->
UINT8_table + 5141 ) ; strcpy ( _dline -> compilerData -> block [ 40 ] .
visibleName , "HEV/Engine Controller/Gasoline Engine" ) ; _dline ->
compilerData -> block [ 40 ] . type = DRIVETRANSDUCER ; _dline ->
compilerData -> block [ 40 ] . flange = _table -> INT32_table + 56 ; _dline
-> compilerData -> block [ 40 ] . transducer = _table ->
DriveTransducer_table + 17 ; _dline -> compilerData -> block [ 40 ] .
transducer [ 0 ] . numSignals = 2 ; _dline -> compilerData -> block [ 40 ] .
transducer [ 0 ] . positionFlag = ( char * ) ( _table -> UINT8_table + 5179 )
; strcpy ( _dline -> compilerData -> block [ 40 ] . transducer [ 0 ] .
positionFlag , "Undefined" ) ; _dline -> compilerData -> block [ 40 ] .
transducer [ 0 ] . velocityFlag = ( char * ) ( _table -> UINT8_table + 5189 )
; strcpy ( _dline -> compilerData -> block [ 40 ] . transducer [ 0 ] .
velocityFlag , "Undefined" ) ; _dline -> compilerData -> block [ 40 ] .
transducer [ 0 ] . accelerationFlag = ( char * ) ( _table -> UINT8_table +
5199 ) ; strcpy ( _dline -> compilerData -> block [ 40 ] . transducer [ 0 ] .
accelerationFlag , "Undefined" ) ; _dline -> compilerData -> block [ 40 ] .
transducer [ 0 ] . signal = _table -> DriveSignal_table + 27 ; _dline ->
compilerData -> block [ 40 ] . transducer [ 0 ] . signal [ 0 ] . type =
DRIVEVELOCITY ; _dline -> compilerData -> block [ 40 ] . transducer [ 0 ] .
signal [ 0 ] . flag = ( char * ) ( _table -> UINT8_table + 5209 ) ; strcpy (
_dline -> compilerData -> block [ 40 ] . transducer [ 0 ] . signal [ 0 ] .
flag , "drive_3f421e06Velocity" ) ; _dline -> compilerData -> block [ 40 ] .
transducer [ 0 ] . signal [ 1 ] . type = DRIVEACCELERATION ; _dline ->
compilerData -> block [ 40 ] . transducer [ 0 ] . signal [ 1 ] . flag = (
char * ) ( _table -> UINT8_table + 5232 ) ; strcpy ( _dline -> compilerData
-> block [ 40 ] . transducer [ 0 ] . signal [ 1 ] . flag ,
"drive_3f421e06Acceleration" ) ; _dline -> compilerData -> block [ 41 ] .
numFlanges = 1 ; _dline -> compilerData -> block [ 41 ] . numTransducer = 1 ;
_dline -> compilerData -> block [ 41 ] . name = ( char * ) ( _table ->
UINT8_table + 5259 ) ; strcpy ( _dline -> compilerData -> block [ 41 ] . name
, "HEV/Engine Controller/Gasoline Engine/Torque Actuator/Transducer" ) ;
_dline -> compilerData -> block [ 41 ] . visibleName = ( char * ) ( _table ->
UINT8_table + 5324 ) ; strcpy ( _dline -> compilerData -> block [ 41 ] .
visibleName , "HEV/Engine Controller/Gasoline Engine" ) ; _dline ->
compilerData -> block [ 41 ] . type = DRIVETRANSDUCER ; _dline ->
compilerData -> block [ 41 ] . flange = _table -> INT32_table + 57 ; _dline
-> compilerData -> block [ 41 ] . transducer = _table ->
DriveTransducer_table + 18 ; _dline -> compilerData -> block [ 41 ] .
transducer [ 0 ] . numSignals = 1 ; _dline -> compilerData -> block [ 41 ] .
transducer [ 0 ] . positionFlag = ( char * ) ( _table -> UINT8_table + 5362 )
; strcpy ( _dline -> compilerData -> block [ 41 ] . transducer [ 0 ] .
positionFlag , "Undefined" ) ; _dline -> compilerData -> block [ 41 ] .
transducer [ 0 ] . velocityFlag = ( char * ) ( _table -> UINT8_table + 5372 )
; strcpy ( _dline -> compilerData -> block [ 41 ] . transducer [ 0 ] .
velocityFlag , "Undefined" ) ; _dline -> compilerData -> block [ 41 ] .
transducer [ 0 ] . accelerationFlag = ( char * ) ( _table -> UINT8_table +
5382 ) ; strcpy ( _dline -> compilerData -> block [ 41 ] . transducer [ 0 ] .
accelerationFlag , "Undefined" ) ; _dline -> compilerData -> block [ 41 ] .
transducer [ 0 ] . signal = _table -> DriveSignal_table + 29 ; _dline ->
compilerData -> block [ 41 ] . transducer [ 0 ] . signal [ 0 ] . type =
DRIVEEXTERNALTORQUE ; _dline -> compilerData -> block [ 41 ] . transducer [ 0
] . signal [ 0 ] . flag = ( char * ) ( _table -> UINT8_table + 5392 ) ;
strcpy ( _dline -> compilerData -> block [ 41 ] . transducer [ 0 ] . signal [
0 ] . flag , "drive_1acc2884Tor" ) ; _dline -> compilerData -> block [ 42 ] .
numFlanges = 1 ; _dline -> compilerData -> block [ 42 ] . numTransducer = 1 ;
_dline -> compilerData -> block [ 42 ] . name = ( char * ) ( _table ->
UINT8_table + 5410 ) ; strcpy ( _dline -> compilerData -> block [ 42 ] . name
, "HEV/Engine Controller/Motion Sensor/Transducer" ) ; _dline -> compilerData
-> block [ 42 ] . visibleName = ( char * ) ( _table -> UINT8_table + 5457 ) ;
strcpy ( _dline -> compilerData -> block [ 42 ] . visibleName ,
"HEV/Engine Controller/Motion Sensor" ) ; _dline -> compilerData -> block [
42 ] . type = DRIVETRANSDUCER ; _dline -> compilerData -> block [ 42 ] .
flange = _table -> INT32_table + 58 ; _dline -> compilerData -> block [ 42 ]
. transducer = _table -> DriveTransducer_table + 19 ; _dline -> compilerData
-> block [ 42 ] . transducer [ 0 ] . numSignals = 2 ; _dline -> compilerData
-> block [ 42 ] . transducer [ 0 ] . positionFlag = ( char * ) ( _table ->
UINT8_table + 5493 ) ; strcpy ( _dline -> compilerData -> block [ 42 ] .
transducer [ 0 ] . positionFlag , "Undefined" ) ; _dline -> compilerData ->
block [ 42 ] . transducer [ 0 ] . velocityFlag = ( char * ) ( _table ->
UINT8_table + 5503 ) ; strcpy ( _dline -> compilerData -> block [ 42 ] .
transducer [ 0 ] . velocityFlag , "Undefined" ) ; _dline -> compilerData ->
block [ 42 ] . transducer [ 0 ] . accelerationFlag = ( char * ) ( _table ->
UINT8_table + 5513 ) ; strcpy ( _dline -> compilerData -> block [ 42 ] .
transducer [ 0 ] . accelerationFlag , "Undefined" ) ; _dline -> compilerData
-> block [ 42 ] . transducer [ 0 ] . signal = _table -> DriveSignal_table +
30 ; _dline -> compilerData -> block [ 42 ] . transducer [ 0 ] . signal [ 0 ]
. type = DRIVEVELOCITY ; _dline -> compilerData -> block [ 42 ] . transducer
[ 0 ] . signal [ 0 ] . flag = ( char * ) ( _table -> UINT8_table + 5523 ) ;
strcpy ( _dline -> compilerData -> block [ 42 ] . transducer [ 0 ] . signal [
0 ] . flag , "drive_a16c2233Velocity" ) ; _dline -> compilerData -> block [
42 ] . transducer [ 0 ] . signal [ 1 ] . type = DRIVEACCELERATION ; _dline ->
compilerData -> block [ 42 ] . transducer [ 0 ] . signal [ 1 ] . flag = (
char * ) ( _table -> UINT8_table + 5546 ) ; strcpy ( _dline -> compilerData
-> block [ 42 ] . transducer [ 0 ] . signal [ 1 ] . flag ,
"drive_a16c2233Acceleration" ) ; _dline -> compilerData -> block [ 43 ] .
numFlanges = 1 ; _dline -> compilerData -> block [ 43 ] . numTransducer = 1 ;
_dline -> compilerData -> block [ 43 ] . name = ( char * ) ( _table ->
UINT8_table + 5573 ) ; strcpy ( _dline -> compilerData -> block [ 43 ] . name
, "HEV/Engine Controller/Torsional \\\\nSpring-Damper/base_torque/Transducer"
) ; _dline -> compilerData -> block [ 43 ] . visibleName = ( char * ) (
_table -> UINT8_table + 5643 ) ; strcpy ( _dline -> compilerData -> block [
43 ] . visibleName , "HEV/Engine Controller/Torsional \\\\nSpring-Damper" ) ;
_dline -> compilerData -> block [ 43 ] . type = DRIVETRANSDUCER ; _dline ->
compilerData -> block [ 43 ] . flange = _table -> INT32_table + 59 ; _dline
-> compilerData -> block [ 43 ] . transducer = _table ->
DriveTransducer_table + 20 ; _dline -> compilerData -> block [ 43 ] .
transducer [ 0 ] . numSignals = 1 ; _dline -> compilerData -> block [ 43 ] .
transducer [ 0 ] . positionFlag = ( char * ) ( _table -> UINT8_table + 5690 )
; strcpy ( _dline -> compilerData -> block [ 43 ] . transducer [ 0 ] .
positionFlag , "Undefined" ) ; _dline -> compilerData -> block [ 43 ] .
transducer [ 0 ] . velocityFlag = ( char * ) ( _table -> UINT8_table + 5700 )
; strcpy ( _dline -> compilerData -> block [ 43 ] . transducer [ 0 ] .
velocityFlag , "Undefined" ) ; _dline -> compilerData -> block [ 43 ] .
transducer [ 0 ] . accelerationFlag = ( char * ) ( _table -> UINT8_table +
5710 ) ; strcpy ( _dline -> compilerData -> block [ 43 ] . transducer [ 0 ] .
accelerationFlag , "Undefined" ) ; _dline -> compilerData -> block [ 43 ] .
transducer [ 0 ] . signal = _table -> DriveSignal_table + 32 ; _dline ->
compilerData -> block [ 43 ] . transducer [ 0 ] . signal [ 0 ] . type =
DRIVEEXTERNALTORQUE ; _dline -> compilerData -> block [ 43 ] . transducer [ 0
] . signal [ 0 ] . flag = ( char * ) ( _table -> UINT8_table + 5720 ) ;
strcpy ( _dline -> compilerData -> block [ 43 ] . transducer [ 0 ] . signal [
0 ] . flag , "drive_ce701f87Tor" ) ; _dline -> compilerData -> block [ 44 ] .
numFlanges = 1 ; _dline -> compilerData -> block [ 44 ] . numTransducer = 1 ;
_dline -> compilerData -> block [ 44 ] . name = ( char * ) ( _table ->
UINT8_table + 5738 ) ; strcpy ( _dline -> compilerData -> block [ 44 ] . name
,
"HEV/Engine Controller/Torsional \\\\nSpring-Damper/base_velocity/Transducer"
) ; _dline -> compilerData -> block [ 44 ] . visibleName = ( char * ) (
_table -> UINT8_table + 5810 ) ; strcpy ( _dline -> compilerData -> block [
44 ] . visibleName , "HEV/Engine Controller/Torsional \\\\nSpring-Damper" ) ;
_dline -> compilerData -> block [ 44 ] . type = DRIVETRANSDUCER ; _dline ->
compilerData -> block [ 44 ] . flange = _table -> INT32_table + 60 ; _dline
-> compilerData -> block [ 44 ] . transducer = _table ->
DriveTransducer_table + 21 ; _dline -> compilerData -> block [ 44 ] .
transducer [ 0 ] . numSignals = 2 ; _dline -> compilerData -> block [ 44 ] .
transducer [ 0 ] . positionFlag = ( char * ) ( _table -> UINT8_table + 5857 )
; strcpy ( _dline -> compilerData -> block [ 44 ] . transducer [ 0 ] .
positionFlag , "Undefined" ) ; _dline -> compilerData -> block [ 44 ] .
transducer [ 0 ] . velocityFlag = ( char * ) ( _table -> UINT8_table + 5867 )
; strcpy ( _dline -> compilerData -> block [ 44 ] . transducer [ 0 ] .
velocityFlag , "Undefined" ) ; _dline -> compilerData -> block [ 44 ] .
transducer [ 0 ] . accelerationFlag = ( char * ) ( _table -> UINT8_table +
5877 ) ; strcpy ( _dline -> compilerData -> block [ 44 ] . transducer [ 0 ] .
accelerationFlag , "Undefined" ) ; _dline -> compilerData -> block [ 44 ] .
transducer [ 0 ] . signal = _table -> DriveSignal_table + 33 ; _dline ->
compilerData -> block [ 44 ] . transducer [ 0 ] . signal [ 0 ] . type =
DRIVEVELOCITY ; _dline -> compilerData -> block [ 44 ] . transducer [ 0 ] .
signal [ 0 ] . flag = ( char * ) ( _table -> UINT8_table + 5887 ) ; strcpy (
_dline -> compilerData -> block [ 44 ] . transducer [ 0 ] . signal [ 0 ] .
flag , "drive_5ac4c50Velocity" ) ; _dline -> compilerData -> block [ 44 ] .
transducer [ 0 ] . signal [ 1 ] . type = DRIVEACCELERATION ; _dline ->
compilerData -> block [ 44 ] . transducer [ 0 ] . signal [ 1 ] . flag = (
char * ) ( _table -> UINT8_table + 5909 ) ; strcpy ( _dline -> compilerData
-> block [ 44 ] . transducer [ 0 ] . signal [ 1 ] . flag ,
"drive_5ac4c50Acceleration" ) ; _dline -> compilerData -> ioSizes .
numDynamicInputs = 9 ; _dline -> compilerData -> ioSizes . numDynamicOutputs
= 18 ; _dline -> compilerData -> ioSizes . numKinematicOutputs = 13 ; _dline
-> compilerData -> ioSizes . numRtParameters = 17 ; _dline -> compilerData ->
name = ( char * ) ( _table -> UINT8_table + 5935 ) ; strcpy ( _dline ->
compilerData -> name , "HEV/Engine Controller/Driveline\\\\nEnvironment" ) ;
_dline -> compilerData -> mdlHandle = 3.0001220703125 ; return _dline ; }
