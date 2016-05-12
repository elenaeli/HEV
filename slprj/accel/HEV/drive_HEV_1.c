#include "__cf_HEV.h"
#include "drive_HEV_1.h"
DriveLine * _drive_HEV_1_drive_line ; DriveLine * drive_HEV_1_drive_line (
drive_HEV_1_data_table * _table ) { DriveLine * _dline ; _dline = & _table ->
_dline ; _dline -> compilerData = _table -> DriveCompilerData_table ; _dline
-> compilerData -> numBlocks = 47 ; _dline -> compilerData -> block = _table
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
[ 7 ] . name , "HEV/Gearbox/Torque Sensor1/Torque Sensor\\\\nInternal" ) ;
_dline -> compilerData -> block [ 7 ] . visibleName = ( char * ) ( _table ->
UINT8_table + 937 ) ; strcpy ( _dline -> compilerData -> block [ 7 ] .
visibleName , "HEV/Gearbox/Torque Sensor1" ) ; _dline -> compilerData ->
block [ 7 ] . type = DRIVESTRAINGAUGE ; _dline -> compilerData -> block [ 7 ]
. flange = _table -> INT32_table + 7 ; _dline -> compilerData -> block [ 7 ]
. flange [ 0 ] = 2 ; _dline -> compilerData -> block [ 7 ] . flange [ 1 ] = 3
; _dline -> compilerData -> block [ 7 ] . strainGauge = _table ->
DriveStrainGauge_table + 1 ; _dline -> compilerData -> block [ 7 ] .
strainGauge [ 0 ] . measurementFlange = 1 ; _dline -> compilerData -> block [
7 ] . strainGauge [ 0 ] . flag = ( char * ) ( _table -> UINT8_table + 964 ) ;
strcpy ( _dline -> compilerData -> block [ 7 ] . strainGauge [ 0 ] . flag ,
"drive_1dce1e1" ) ; _dline -> compilerData -> block [ 8 ] . numFlanges = 3 ;
_dline -> compilerData -> block [ 8 ] . numParameters = 1 ; _dline ->
compilerData -> block [ 8 ] . parameter = _table -> DriveParameter_table + 2
; _dline -> compilerData -> block [ 8 ] . parameter [ 0 ] . type =
DRIVERTP_PLANETPLANETGEARRATIO ; _dline -> compilerData -> block [ 8 ] .
parameter [ 0 ] . flag = ( char * ) ( _table -> UINT8_table + 978 ) ; strcpy
( _dline -> compilerData -> block [ 8 ] . parameter [ 0 ] . flag ,
"drive_ed509dbaPlanetPlanetRatio" ) ; _dline -> compilerData -> block [ 8 ] .
numPlanetPlanet = 1 ; _dline -> compilerData -> block [ 8 ] . name = ( char *
) ( _table -> UINT8_table + 1010 ) ; strcpy ( _dline -> compilerData -> block
[ 8 ] . name , "HEV/Gearbox/Planetary Gear/Planet-Planet" ) ; _dline ->
compilerData -> block [ 8 ] . visibleName = ( char * ) ( _table ->
UINT8_table + 1051 ) ; strcpy ( _dline -> compilerData -> block [ 8 ] .
visibleName , "HEV/Gearbox/Planetary Gear" ) ; _dline -> compilerData ->
block [ 8 ] . type = DRIVEPLANETPLANET ; _dline -> compilerData -> block [ 8
] . flange = _table -> INT32_table + 9 ; _dline -> compilerData -> block [ 8
] . flange [ 0 ] = 3 ; _dline -> compilerData -> block [ 8 ] . flange [ 1 ] =
4 ; _dline -> compilerData -> block [ 8 ] . flange [ 2 ] = 8 ; _dline ->
compilerData -> block [ 8 ] . planetPlanet = _table ->
DrivePlanetPlanet_table ; _dline -> compilerData -> block [ 8 ] .
planetPlanet [ 0 ] . sunFlange = 2 ; _dline -> compilerData -> block [ 8 ] .
planetPlanet [ 0 ] . planetFlange = 1 ; _dline -> compilerData -> block [ 8 ]
. planetPlanet [ 0 ] . ratio = 0.8 ; _dline -> compilerData -> block [ 9 ] .
numFlanges = 3 ; _dline -> compilerData -> block [ 9 ] . numParameters = 1 ;
_dline -> compilerData -> block [ 9 ] . parameter = _table ->
DriveParameter_table + 3 ; _dline -> compilerData -> block [ 9 ] . parameter
[ 0 ] . type = DRIVERTP_RINGPLANETGEARRATIO ; _dline -> compilerData -> block
[ 9 ] . parameter [ 0 ] . flag = ( char * ) ( _table -> UINT8_table + 1078 )
; strcpy ( _dline -> compilerData -> block [ 9 ] . parameter [ 0 ] . flag ,
"drive_e0323d9RingPlanetRatio" ) ; _dline -> compilerData -> block [ 9 ] .
numPlanetRing = 1 ; _dline -> compilerData -> block [ 9 ] . name = ( char * )
( _table -> UINT8_table + 1107 ) ; strcpy ( _dline -> compilerData -> block [
9 ] . name , "HEV/Gearbox/Planetary Gear/Ring-Planet" ) ; _dline ->
compilerData -> block [ 9 ] . visibleName = ( char * ) ( _table ->
UINT8_table + 1146 ) ; strcpy ( _dline -> compilerData -> block [ 9 ] .
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
block [ 10 ] . name = ( char * ) ( _table -> UINT8_table + 1173 ) ; strcpy (
_dline -> compilerData -> block [ 10 ] . name ,
"HEV/Gearbox/Torque Sensor2/Torque Sensor\\\\nInternal" ) ; _dline ->
compilerData -> block [ 10 ] . visibleName = ( char * ) ( _table ->
UINT8_table + 1223 ) ; strcpy ( _dline -> compilerData -> block [ 10 ] .
visibleName , "HEV/Gearbox/Torque Sensor2" ) ; _dline -> compilerData ->
block [ 10 ] . type = DRIVESTRAINGAUGE ; _dline -> compilerData -> block [ 10
] . flange = _table -> INT32_table + 15 ; _dline -> compilerData -> block [
10 ] . flange [ 0 ] = 5 ; _dline -> compilerData -> block [ 10 ] . flange [ 1
] = 6 ; _dline -> compilerData -> block [ 10 ] . strainGauge = _table ->
DriveStrainGauge_table + 2 ; _dline -> compilerData -> block [ 10 ] .
strainGauge [ 0 ] . measurementFlange = 1 ; _dline -> compilerData -> block [
10 ] . strainGauge [ 0 ] . flag = ( char * ) ( _table -> UINT8_table + 1250 )
; strcpy ( _dline -> compilerData -> block [ 10 ] . strainGauge [ 0 ] . flag
, "drive_ba57fc4e" ) ; _dline -> compilerData -> block [ 11 ] . numFlanges =
1 ; _dline -> compilerData -> block [ 11 ] . numTransducer = 1 ; _dline ->
compilerData -> block [ 11 ] . name = ( char * ) ( _table -> UINT8_table +
1265 ) ; strcpy ( _dline -> compilerData -> block [ 11 ] . name ,
"HEV/Electric Motor Controller\\\\n/Gen Motion Sensor/Transducer" ) ; _dline
-> compilerData -> block [ 11 ] . visibleName = ( char * ) ( _table ->
UINT8_table + 1325 ) ; strcpy ( _dline -> compilerData -> block [ 11 ] .
visibleName , "HEV/Electric Motor Controller\\\\n/Gen Motion Sensor" ) ;
_dline -> compilerData -> block [ 11 ] . type = DRIVETRANSDUCER ; _dline ->
compilerData -> block [ 11 ] . flange = _table -> INT32_table + 17 ; _dline
-> compilerData -> block [ 11 ] . flange [ 0 ] = 6 ; _dline -> compilerData
-> block [ 11 ] . transducer = _table -> DriveTransducer_table + 2 ; _dline
-> compilerData -> block [ 11 ] . transducer [ 0 ] . numSignals = 2 ; _dline
-> compilerData -> block [ 11 ] . transducer [ 0 ] . positionFlag = ( char *
) ( _table -> UINT8_table + 1374 ) ; strcpy ( _dline -> compilerData -> block
[ 11 ] . transducer [ 0 ] . positionFlag , "Undefined" ) ; _dline ->
compilerData -> block [ 11 ] . transducer [ 0 ] . velocityFlag = ( char * ) (
_table -> UINT8_table + 1384 ) ; strcpy ( _dline -> compilerData -> block [
11 ] . transducer [ 0 ] . velocityFlag , "Undefined" ) ; _dline ->
compilerData -> block [ 11 ] . transducer [ 0 ] . accelerationFlag = ( char *
) ( _table -> UINT8_table + 1394 ) ; strcpy ( _dline -> compilerData -> block
[ 11 ] . transducer [ 0 ] . accelerationFlag , "Undefined" ) ; _dline ->
compilerData -> block [ 11 ] . transducer [ 0 ] . signal = _table ->
DriveSignal_table + 3 ; _dline -> compilerData -> block [ 11 ] . transducer [
0 ] . signal [ 0 ] . type = DRIVEVELOCITY ; _dline -> compilerData -> block [
11 ] . transducer [ 0 ] . signal [ 0 ] . flag = ( char * ) ( _table ->
UINT8_table + 1404 ) ; strcpy ( _dline -> compilerData -> block [ 11 ] .
transducer [ 0 ] . signal [ 0 ] . flag , "drive_fc09825aVelocity" ) ; _dline
-> compilerData -> block [ 11 ] . transducer [ 0 ] . signal [ 1 ] . type =
DRIVEACCELERATION ; _dline -> compilerData -> block [ 11 ] . transducer [ 0 ]
. signal [ 1 ] . flag = ( char * ) ( _table -> UINT8_table + 1427 ) ; strcpy
( _dline -> compilerData -> block [ 11 ] . transducer [ 0 ] . signal [ 1 ] .
flag , "drive_fc09825aAcceleration" ) ; _dline -> compilerData -> block [ 12
] . numFlanges = 1 ; _dline -> compilerData -> block [ 12 ] . numTransducer =
1 ; _dline -> compilerData -> block [ 12 ] . name = ( char * ) ( _table ->
UINT8_table + 1454 ) ; strcpy ( _dline -> compilerData -> block [ 12 ] . name
, "HEV/Electric Motor Controller\\\\n/Torque Actuator Gen/Transducer" ) ;
_dline -> compilerData -> block [ 12 ] . visibleName = ( char * ) ( _table ->
UINT8_table + 1516 ) ; strcpy ( _dline -> compilerData -> block [ 12 ] .
visibleName , "HEV/Electric Motor Controller\\\\n/Torque Actuator Gen" ) ;
_dline -> compilerData -> block [ 12 ] . type = DRIVETRANSDUCER ; _dline ->
compilerData -> block [ 12 ] . flange = _table -> INT32_table + 18 ; _dline
-> compilerData -> block [ 12 ] . flange [ 0 ] = 6 ; _dline -> compilerData
-> block [ 12 ] . transducer = _table -> DriveTransducer_table + 3 ; _dline
-> compilerData -> block [ 12 ] . transducer [ 0 ] . numSignals = 1 ; _dline
-> compilerData -> block [ 12 ] . transducer [ 0 ] . positionFlag = ( char *
) ( _table -> UINT8_table + 1567 ) ; strcpy ( _dline -> compilerData -> block
[ 12 ] . transducer [ 0 ] . positionFlag , "Undefined" ) ; _dline ->
compilerData -> block [ 12 ] . transducer [ 0 ] . velocityFlag = ( char * ) (
_table -> UINT8_table + 1577 ) ; strcpy ( _dline -> compilerData -> block [
12 ] . transducer [ 0 ] . velocityFlag , "Undefined" ) ; _dline ->
compilerData -> block [ 12 ] . transducer [ 0 ] . accelerationFlag = ( char *
) ( _table -> UINT8_table + 1587 ) ; strcpy ( _dline -> compilerData -> block
[ 12 ] . transducer [ 0 ] . accelerationFlag , "Undefined" ) ; _dline ->
compilerData -> block [ 12 ] . transducer [ 0 ] . signal = _table ->
DriveSignal_table + 5 ; _dline -> compilerData -> block [ 12 ] . transducer [
0 ] . signal [ 0 ] . type = DRIVEEXTERNALTORQUE ; _dline -> compilerData ->
block [ 12 ] . transducer [ 0 ] . signal [ 0 ] . flag = ( char * ) ( _table
-> UINT8_table + 1597 ) ; strcpy ( _dline -> compilerData -> block [ 12 ] .
transducer [ 0 ] . signal [ 0 ] . flag , "drive_831c2968Tor" ) ; _dline ->
compilerData -> block [ 13 ] . numFlanges = 1 ; _dline -> compilerData ->
block [ 13 ] . numTransducer = 1 ; _dline -> compilerData -> block [ 13 ] .
name = ( char * ) ( _table -> UINT8_table + 1615 ) ; strcpy ( _dline ->
compilerData -> block [ 13 ] . name ,
"HEV/Gearbox/Mot Motion Sensor/Transducer" ) ; _dline -> compilerData ->
block [ 13 ] . visibleName = ( char * ) ( _table -> UINT8_table + 1656 ) ;
strcpy ( _dline -> compilerData -> block [ 13 ] . visibleName ,
"HEV/Gearbox/Mot Motion Sensor" ) ; _dline -> compilerData -> block [ 13 ] .
type = DRIVETRANSDUCER ; _dline -> compilerData -> block [ 13 ] . flange =
_table -> INT32_table + 19 ; _dline -> compilerData -> block [ 13 ] . flange
[ 0 ] = 6 ; _dline -> compilerData -> block [ 13 ] . transducer = _table ->
DriveTransducer_table + 4 ; _dline -> compilerData -> block [ 13 ] .
transducer [ 0 ] . numSignals = 2 ; _dline -> compilerData -> block [ 13 ] .
transducer [ 0 ] . positionFlag = ( char * ) ( _table -> UINT8_table + 1686 )
; strcpy ( _dline -> compilerData -> block [ 13 ] . transducer [ 0 ] .
positionFlag , "Undefined" ) ; _dline -> compilerData -> block [ 13 ] .
transducer [ 0 ] . velocityFlag = ( char * ) ( _table -> UINT8_table + 1696 )
; strcpy ( _dline -> compilerData -> block [ 13 ] . transducer [ 0 ] .
velocityFlag , "Undefined" ) ; _dline -> compilerData -> block [ 13 ] .
transducer [ 0 ] . accelerationFlag = ( char * ) ( _table -> UINT8_table +
1706 ) ; strcpy ( _dline -> compilerData -> block [ 13 ] . transducer [ 0 ] .
accelerationFlag , "Undefined" ) ; _dline -> compilerData -> block [ 13 ] .
transducer [ 0 ] . signal = _table -> DriveSignal_table + 6 ; _dline ->
compilerData -> block [ 13 ] . transducer [ 0 ] . signal [ 0 ] . type =
DRIVEVELOCITY ; _dline -> compilerData -> block [ 13 ] . transducer [ 0 ] .
signal [ 0 ] . flag = ( char * ) ( _table -> UINT8_table + 1716 ) ; strcpy (
_dline -> compilerData -> block [ 13 ] . transducer [ 0 ] . signal [ 0 ] .
flag , "drive_dc17081aVelocity" ) ; _dline -> compilerData -> block [ 13 ] .
transducer [ 0 ] . signal [ 1 ] . type = DRIVEACCELERATION ; _dline ->
compilerData -> block [ 13 ] . transducer [ 0 ] . signal [ 1 ] . flag = (
char * ) ( _table -> UINT8_table + 1739 ) ; strcpy ( _dline -> compilerData
-> block [ 13 ] . transducer [ 0 ] . signal [ 1 ] . flag ,
"drive_dc17081aAcceleration" ) ; _dline -> compilerData -> block [ 14 ] .
numFlanges = 2 ; _dline -> compilerData -> block [ 14 ] . numStrainGauge = 1
; _dline -> compilerData -> block [ 14 ] . name = ( char * ) ( _table ->
UINT8_table + 1766 ) ; strcpy ( _dline -> compilerData -> block [ 14 ] . name
, "HEV/Gearbox/T3/Torque Sensor\\\\nInternal" ) ; _dline -> compilerData ->
block [ 14 ] . visibleName = ( char * ) ( _table -> UINT8_table + 1804 ) ;
strcpy ( _dline -> compilerData -> block [ 14 ] . visibleName ,
"HEV/Gearbox/T3" ) ; _dline -> compilerData -> block [ 14 ] . type =
DRIVESTRAINGAUGE ; _dline -> compilerData -> block [ 14 ] . flange = _table
-> INT32_table + 20 ; _dline -> compilerData -> block [ 14 ] . flange [ 0 ] =
4 ; _dline -> compilerData -> block [ 14 ] . flange [ 1 ] = 7 ; _dline ->
compilerData -> block [ 14 ] . strainGauge = _table -> DriveStrainGauge_table
+ 3 ; _dline -> compilerData -> block [ 14 ] . strainGauge [ 0 ] .
measurementFlange = 1 ; _dline -> compilerData -> block [ 14 ] . strainGauge
[ 0 ] . flag = ( char * ) ( _table -> UINT8_table + 1819 ) ; strcpy ( _dline
-> compilerData -> block [ 14 ] . strainGauge [ 0 ] . flag , "drive_2ad67e17"
) ; _dline -> compilerData -> block [ 15 ] . numFlanges = 1 ; _dline ->
compilerData -> block [ 15 ] . numTransducer = 1 ; _dline -> compilerData ->
block [ 15 ] . name = ( char * ) ( _table -> UINT8_table + 1834 ) ; strcpy (
_dline -> compilerData -> block [ 15 ] . name , "HEV/Gearbox/M3/Transducer" )
; _dline -> compilerData -> block [ 15 ] . visibleName = ( char * ) ( _table
-> UINT8_table + 1860 ) ; strcpy ( _dline -> compilerData -> block [ 15 ] .
visibleName , "HEV/Gearbox/M3" ) ; _dline -> compilerData -> block [ 15 ] .
type = DRIVETRANSDUCER ; _dline -> compilerData -> block [ 15 ] . flange =
_table -> INT32_table + 22 ; _dline -> compilerData -> block [ 15 ] . flange
[ 0 ] = 7 ; _dline -> compilerData -> block [ 15 ] . transducer = _table ->
DriveTransducer_table + 5 ; _dline -> compilerData -> block [ 15 ] .
transducer [ 0 ] . numSignals = 2 ; _dline -> compilerData -> block [ 15 ] .
transducer [ 0 ] . positionFlag = ( char * ) ( _table -> UINT8_table + 1875 )
; strcpy ( _dline -> compilerData -> block [ 15 ] . transducer [ 0 ] .
positionFlag , "Undefined" ) ; _dline -> compilerData -> block [ 15 ] .
transducer [ 0 ] . velocityFlag = ( char * ) ( _table -> UINT8_table + 1885 )
; strcpy ( _dline -> compilerData -> block [ 15 ] . transducer [ 0 ] .
velocityFlag , "Undefined" ) ; _dline -> compilerData -> block [ 15 ] .
transducer [ 0 ] . accelerationFlag = ( char * ) ( _table -> UINT8_table +
1895 ) ; strcpy ( _dline -> compilerData -> block [ 15 ] . transducer [ 0 ] .
accelerationFlag , "Undefined" ) ; _dline -> compilerData -> block [ 15 ] .
transducer [ 0 ] . signal = _table -> DriveSignal_table + 8 ; _dline ->
compilerData -> block [ 15 ] . transducer [ 0 ] . signal [ 0 ] . type =
DRIVEVELOCITY ; _dline -> compilerData -> block [ 15 ] . transducer [ 0 ] .
signal [ 0 ] . flag = ( char * ) ( _table -> UINT8_table + 1905 ) ; strcpy (
_dline -> compilerData -> block [ 15 ] . transducer [ 0 ] . signal [ 0 ] .
flag , "drive_48e7ed30Velocity" ) ; _dline -> compilerData -> block [ 15 ] .
transducer [ 0 ] . signal [ 1 ] . type = DRIVEACCELERATION ; _dline ->
compilerData -> block [ 15 ] . transducer [ 0 ] . signal [ 1 ] . flag = (
char * ) ( _table -> UINT8_table + 1928 ) ; strcpy ( _dline -> compilerData
-> block [ 15 ] . transducer [ 0 ] . signal [ 1 ] . flag ,
"drive_48e7ed30Acceleration" ) ; _dline -> compilerData -> block [ 16 ] .
numFlanges = 2 ; _dline -> compilerData -> block [ 16 ] . numStrainGauge = 1
; _dline -> compilerData -> block [ 16 ] . name = ( char * ) ( _table ->
UINT8_table + 1955 ) ; strcpy ( _dline -> compilerData -> block [ 16 ] . name
, "HEV/Gearbox/Torque Sensor3/Torque Sensor\\\\nInternal" ) ; _dline ->
compilerData -> block [ 16 ] . visibleName = ( char * ) ( _table ->
UINT8_table + 2005 ) ; strcpy ( _dline -> compilerData -> block [ 16 ] .
visibleName , "HEV/Gearbox/Torque Sensor3" ) ; _dline -> compilerData ->
block [ 16 ] . type = DRIVESTRAINGAUGE ; _dline -> compilerData -> block [ 16
] . flange = _table -> INT32_table + 23 ; _dline -> compilerData -> block [
16 ] . flange [ 0 ] = 8 ; _dline -> compilerData -> block [ 16 ] . flange [ 1
] = 9 ; _dline -> compilerData -> block [ 16 ] . strainGauge = _table ->
DriveStrainGauge_table + 4 ; _dline -> compilerData -> block [ 16 ] .
strainGauge [ 0 ] . measurementFlange = 1 ; _dline -> compilerData -> block [
16 ] . strainGauge [ 0 ] . flag = ( char * ) ( _table -> UINT8_table + 2032 )
; strcpy ( _dline -> compilerData -> block [ 16 ] . strainGauge [ 0 ] . flag
, "drive_d32ef72b" ) ; _dline -> compilerData -> block [ 17 ] . numFlanges =
2 ; _dline -> compilerData -> block [ 17 ] . numStrainGauge = 1 ; _dline ->
compilerData -> block [ 17 ] . name = ( char * ) ( _table -> UINT8_table +
2047 ) ; strcpy ( _dline -> compilerData -> block [ 17 ] . name ,
"HEV/Vehicle/Torque Sensor/Torque Sensor\\\\nInternal" ) ; _dline ->
compilerData -> block [ 17 ] . visibleName = ( char * ) ( _table ->
UINT8_table + 2096 ) ; strcpy ( _dline -> compilerData -> block [ 17 ] .
visibleName , "HEV/Vehicle/Torque Sensor" ) ; _dline -> compilerData -> block
[ 17 ] . type = DRIVESTRAINGAUGE ; _dline -> compilerData -> block [ 17 ] .
flange = _table -> INT32_table + 25 ; _dline -> compilerData -> block [ 17 ]
. flange [ 0 ] = 9 ; _dline -> compilerData -> block [ 17 ] . flange [ 1 ] =
10 ; _dline -> compilerData -> block [ 17 ] . strainGauge = _table ->
DriveStrainGauge_table + 5 ; _dline -> compilerData -> block [ 17 ] .
strainGauge [ 0 ] . measurementFlange = 1 ; _dline -> compilerData -> block [
17 ] . strainGauge [ 0 ] . flag = ( char * ) ( _table -> UINT8_table + 2122 )
; strcpy ( _dline -> compilerData -> block [ 17 ] . strainGauge [ 0 ] . flag
, "drive_3a0f24a5" ) ; _dline -> compilerData -> block [ 18 ] . name = ( char
* ) ( _table -> UINT8_table + 2137 ) ; strcpy ( _dline -> compilerData ->
block [ 18 ] . name ,
 "HEV/Vehicle/Torsional \\\\nSpring-Damper \\\\n(Friction)/Free/Shared\\\\nEnvironment\\\\nInternal"
) ; _dline -> compilerData -> block [ 18 ] . visibleName = ( char * ) (
_table -> UINT8_table + 2219 ) ; strcpy ( _dline -> compilerData -> block [
18 ] . visibleName ,
"HEV/Vehicle/Torsional \\\\nSpring-Damper \\\\n(Friction)" ) ; _dline ->
compilerData -> block [ 18 ] . type = DRIVEFREEGEAR ; _dline -> compilerData
-> block [ 19 ] . numFlanges = 1 ; _dline -> compilerData -> block [ 19 ] .
numTransducer = 1 ; _dline -> compilerData -> block [ 19 ] . name = ( char *
) ( _table -> UINT8_table + 2268 ) ; strcpy ( _dline -> compilerData -> block
[ 19 ] . name ,
 "HEV/Vehicle/Torsional \\\\nSpring-Damper \\\\n(Friction)/base_torque/Transducer"
) ; _dline -> compilerData -> block [ 19 ] . visibleName = ( char * ) (
_table -> UINT8_table + 2340 ) ; strcpy ( _dline -> compilerData -> block [
19 ] . visibleName ,
"HEV/Vehicle/Torsional \\\\nSpring-Damper \\\\n(Friction)" ) ; _dline ->
compilerData -> block [ 19 ] . type = DRIVETRANSDUCER ; _dline ->
compilerData -> block [ 19 ] . flange = _table -> INT32_table + 27 ; _dline
-> compilerData -> block [ 19 ] . flange [ 0 ] = 11 ; _dline -> compilerData
-> block [ 19 ] . transducer = _table -> DriveTransducer_table + 6 ; _dline
-> compilerData -> block [ 19 ] . transducer [ 0 ] . numSignals = 1 ; _dline
-> compilerData -> block [ 19 ] . transducer [ 0 ] . positionFlag = ( char *
) ( _table -> UINT8_table + 2389 ) ; strcpy ( _dline -> compilerData -> block
[ 19 ] . transducer [ 0 ] . positionFlag , "Undefined" ) ; _dline ->
compilerData -> block [ 19 ] . transducer [ 0 ] . velocityFlag = ( char * ) (
_table -> UINT8_table + 2399 ) ; strcpy ( _dline -> compilerData -> block [
19 ] . transducer [ 0 ] . velocityFlag , "Undefined" ) ; _dline ->
compilerData -> block [ 19 ] . transducer [ 0 ] . accelerationFlag = ( char *
) ( _table -> UINT8_table + 2409 ) ; strcpy ( _dline -> compilerData -> block
[ 19 ] . transducer [ 0 ] . accelerationFlag , "Undefined" ) ; _dline ->
compilerData -> block [ 19 ] . transducer [ 0 ] . signal = _table ->
DriveSignal_table + 10 ; _dline -> compilerData -> block [ 19 ] . transducer
[ 0 ] . signal [ 0 ] . type = DRIVEEXTERNALTORQUE ; _dline -> compilerData ->
block [ 19 ] . transducer [ 0 ] . signal [ 0 ] . flag = ( char * ) ( _table
-> UINT8_table + 2419 ) ; strcpy ( _dline -> compilerData -> block [ 19 ] .
transducer [ 0 ] . signal [ 0 ] . flag , "drive_cdf4ee1bTor" ) ; _dline ->
compilerData -> block [ 20 ] . numFlanges = 1 ; _dline -> compilerData ->
block [ 20 ] . numTransducer = 1 ; _dline -> compilerData -> block [ 20 ] .
name = ( char * ) ( _table -> UINT8_table + 2437 ) ; strcpy ( _dline ->
compilerData -> block [ 20 ] . name ,
 "HEV/Vehicle/Torsional \\\\nSpring-Damper \\\\n(Friction)/base_velocity/Transducer"
) ; _dline -> compilerData -> block [ 20 ] . visibleName = ( char * ) (
_table -> UINT8_table + 2511 ) ; strcpy ( _dline -> compilerData -> block [
20 ] . visibleName ,
"HEV/Vehicle/Torsional \\\\nSpring-Damper \\\\n(Friction)" ) ; _dline ->
compilerData -> block [ 20 ] . type = DRIVETRANSDUCER ; _dline ->
compilerData -> block [ 20 ] . flange = _table -> INT32_table + 28 ; _dline
-> compilerData -> block [ 20 ] . flange [ 0 ] = 11 ; _dline -> compilerData
-> block [ 20 ] . transducer = _table -> DriveTransducer_table + 7 ; _dline
-> compilerData -> block [ 20 ] . transducer [ 0 ] . numSignals = 2 ; _dline
-> compilerData -> block [ 20 ] . transducer [ 0 ] . positionFlag = ( char *
) ( _table -> UINT8_table + 2560 ) ; strcpy ( _dline -> compilerData -> block
[ 20 ] . transducer [ 0 ] . positionFlag , "Undefined" ) ; _dline ->
compilerData -> block [ 20 ] . transducer [ 0 ] . velocityFlag = ( char * ) (
_table -> UINT8_table + 2570 ) ; strcpy ( _dline -> compilerData -> block [
20 ] . transducer [ 0 ] . velocityFlag , "Undefined" ) ; _dline ->
compilerData -> block [ 20 ] . transducer [ 0 ] . accelerationFlag = ( char *
) ( _table -> UINT8_table + 2580 ) ; strcpy ( _dline -> compilerData -> block
[ 20 ] . transducer [ 0 ] . accelerationFlag , "Undefined" ) ; _dline ->
compilerData -> block [ 20 ] . transducer [ 0 ] . signal = _table ->
DriveSignal_table + 11 ; _dline -> compilerData -> block [ 20 ] . transducer
[ 0 ] . signal [ 0 ] . type = DRIVEVELOCITY ; _dline -> compilerData -> block
[ 20 ] . transducer [ 0 ] . signal [ 0 ] . flag = ( char * ) ( _table ->
UINT8_table + 2590 ) ; strcpy ( _dline -> compilerData -> block [ 20 ] .
transducer [ 0 ] . signal [ 0 ] . flag , "drive_80da075eVelocity" ) ; _dline
-> compilerData -> block [ 20 ] . transducer [ 0 ] . signal [ 1 ] . type =
DRIVEACCELERATION ; _dline -> compilerData -> block [ 20 ] . transducer [ 0 ]
. signal [ 1 ] . flag = ( char * ) ( _table -> UINT8_table + 2613 ) ; strcpy
( _dline -> compilerData -> block [ 20 ] . transducer [ 0 ] . signal [ 1 ] .
flag , "drive_80da075eAcceleration" ) ; _dline -> compilerData -> block [ 21
] . numFlanges = 1 ; _dline -> compilerData -> block [ 21 ] . numWeld = 1 ;
_dline -> compilerData -> block [ 21 ] . name = ( char * ) ( _table ->
UINT8_table + 2640 ) ; strcpy ( _dline -> compilerData -> block [ 21 ] . name
, "HEV/Vehicle/Housing/Housing\\\\nInternal" ) ; _dline -> compilerData ->
block [ 21 ] . visibleName = ( char * ) ( _table -> UINT8_table + 2677 ) ;
strcpy ( _dline -> compilerData -> block [ 21 ] . visibleName ,
"HEV/Vehicle/Housing" ) ; _dline -> compilerData -> block [ 21 ] . type =
DRIVEWELD ; _dline -> compilerData -> block [ 21 ] . flange = _table ->
INT32_table + 29 ; _dline -> compilerData -> block [ 21 ] . flange [ 0 ] = 11
; _dline -> compilerData -> block [ 21 ] . weld = _table -> DriveWeld_table +
1 ; _dline -> compilerData -> block [ 21 ] . weld [ 0 ] . isWeld = TRUE ;
_dline -> compilerData -> block [ 22 ] . numFlanges = 2 ; _dline ->
compilerData -> block [ 22 ] . numParameters = 1 ; _dline -> compilerData ->
block [ 22 ] . parameter = _table -> DriveParameter_table + 4 ; _dline ->
compilerData -> block [ 22 ] . parameter [ 0 ] . type =
DRIVERTP_SIMPLEGEARRATIO ; _dline -> compilerData -> block [ 22 ] . parameter
[ 0 ] . flag = ( char * ) ( _table -> UINT8_table + 2697 ) ; strcpy ( _dline
-> compilerData -> block [ 22 ] . parameter [ 0 ] . flag ,
"drive_72945f1GearRatio" ) ; _dline -> compilerData -> block [ 22 ] .
numSimpleGear = 1 ; _dline -> compilerData -> block [ 22 ] . name = ( char *
) ( _table -> UINT8_table + 2720 ) ; strcpy ( _dline -> compilerData -> block
[ 22 ] . name , "HEV/Vehicle/Simple Gear" ) ; _dline -> compilerData -> block
[ 22 ] . visibleName = ( char * ) ( _table -> UINT8_table + 2744 ) ; strcpy (
_dline -> compilerData -> block [ 22 ] . visibleName ,
"HEV/Vehicle/Simple Gear" ) ; _dline -> compilerData -> block [ 22 ] . type =
DRIVESIMPLEGEAR ; _dline -> compilerData -> block [ 22 ] . flange = _table ->
INT32_table + 30 ; _dline -> compilerData -> block [ 22 ] . flange [ 0 ] = 10
; _dline -> compilerData -> block [ 22 ] . flange [ 1 ] = 12 ; _dline ->
compilerData -> block [ 22 ] . simpleGear = _table -> DriveSimpleGear_table ;
_dline -> compilerData -> block [ 22 ] . simpleGear [ 0 ] . outputFlange = 1
; _dline -> compilerData -> block [ 22 ] . simpleGear [ 0 ] . ratio = 4.113 ;
_dline -> compilerData -> block [ 23 ] . numFlanges = 1 ; _dline ->
compilerData -> block [ 23 ] . numParameters = 2 ; _dline -> compilerData ->
block [ 23 ] . parameter = _table -> DriveParameter_table + 5 ; _dline ->
compilerData -> block [ 23 ] . parameter [ 0 ] . type = DRIVERTP_INERTIA ;
_dline -> compilerData -> block [ 23 ] . parameter [ 0 ] . flag = ( char * )
( _table -> UINT8_table + 2768 ) ; strcpy ( _dline -> compilerData -> block [
23 ] . parameter [ 0 ] . flag , "drive_f8a0f554Inertia" ) ; _dline ->
compilerData -> block [ 23 ] . parameter [ 1 ] . type =
DRIVERTP_INITIALCONDITION ; _dline -> compilerData -> block [ 23 ] .
parameter [ 1 ] . flag = ( char * ) ( _table -> UINT8_table + 2790 ) ; strcpy
( _dline -> compilerData -> block [ 23 ] . parameter [ 1 ] . flag ,
"drive_f8a0f554InitialCondition" ) ; _dline -> compilerData -> block [ 23 ] .
numInertia = 1 ; _dline -> compilerData -> block [ 23 ] . name = ( char * ) (
_table -> UINT8_table + 2821 ) ; strcpy ( _dline -> compilerData -> block [
23 ] . name , "HEV/Vehicle/Transmission \\\\nInertia" ) ; _dline ->
compilerData -> block [ 23 ] . visibleName = ( char * ) ( _table ->
UINT8_table + 2855 ) ; strcpy ( _dline -> compilerData -> block [ 23 ] .
visibleName , "HEV/Vehicle/Transmission \\\\nInertia" ) ; _dline ->
compilerData -> block [ 23 ] . type = DRIVEINERTIA ; _dline -> compilerData
-> block [ 23 ] . flange = _table -> INT32_table + 32 ; _dline ->
compilerData -> block [ 23 ] . flange [ 0 ] = 12 ; _dline -> compilerData ->
block [ 23 ] . inertia = _table -> DriveInertia_table + 1 ; _dline ->
compilerData -> block [ 23 ] . inertia [ 0 ] . inertia = 0.5 ; _dline ->
compilerData -> block [ 24 ] . numFlanges = 2 ; _dline -> compilerData ->
block [ 24 ] . numParameters = 1 ; _dline -> compilerData -> block [ 24 ] .
parameter = _table -> DriveParameter_table + 7 ; _dline -> compilerData ->
block [ 24 ] . parameter [ 0 ] . type = DRIVERTP_SIMPLEGEARRATIO ; _dline ->
compilerData -> block [ 24 ] . parameter [ 0 ] . flag = ( char * ) ( _table
-> UINT8_table + 2889 ) ; strcpy ( _dline -> compilerData -> block [ 24 ] .
parameter [ 0 ] . flag , "drive_f09289b7GearRatio" ) ; _dline -> compilerData
-> block [ 24 ] . numSimpleGear = 1 ; _dline -> compilerData -> block [ 24 ]
. name = ( char * ) ( _table -> UINT8_table + 2913 ) ; strcpy ( _dline ->
compilerData -> block [ 24 ] . name , "HEV/Vehicle/Differential/Simple Gear1"
) ; _dline -> compilerData -> block [ 24 ] . visibleName = ( char * ) (
_table -> UINT8_table + 2951 ) ; strcpy ( _dline -> compilerData -> block [
24 ] . visibleName , "HEV/Vehicle/Differential" ) ; _dline -> compilerData ->
block [ 24 ] . type = DRIVESIMPLEGEAR ; _dline -> compilerData -> block [ 24
] . flange = _table -> INT32_table + 33 ; _dline -> compilerData -> block [
24 ] . flange [ 0 ] = 12 ; _dline -> compilerData -> block [ 24 ] . flange [
1 ] = 13 ; _dline -> compilerData -> block [ 24 ] . simpleGear = _table ->
DriveSimpleGear_table + 1 ; _dline -> compilerData -> block [ 24 ] .
simpleGear [ 0 ] . reversing = TRUE ; _dline -> compilerData -> block [ 24 ]
. simpleGear [ 0 ] . outputFlange = 1 ; _dline -> compilerData -> block [ 24
] . simpleGear [ 0 ] . ratio = 2.0 ; _dline -> compilerData -> block [ 25 ] .
numFlanges = 3 ; _dline -> compilerData -> block [ 25 ] . numParameters = 1 ;
_dline -> compilerData -> block [ 25 ] . parameter = _table ->
DriveParameter_table + 8 ; _dline -> compilerData -> block [ 25 ] . parameter
[ 0 ] . type = DRIVERTP_PLANETPLANETGEARRATIO ; _dline -> compilerData ->
block [ 25 ] . parameter [ 0 ] . flag = ( char * ) ( _table -> UINT8_table +
2976 ) ; strcpy ( _dline -> compilerData -> block [ 25 ] . parameter [ 0 ] .
flag , "drive_48b6a0f1PlanetPlanetRatio" ) ; _dline -> compilerData -> block
[ 25 ] . numPlanetPlanet = 1 ; _dline -> compilerData -> block [ 25 ] . name
= ( char * ) ( _table -> UINT8_table + 3008 ) ; strcpy ( _dline ->
compilerData -> block [ 25 ] . name ,
"HEV/Vehicle/Differential/Planet-Planet" ) ; _dline -> compilerData -> block
[ 25 ] . visibleName = ( char * ) ( _table -> UINT8_table + 3047 ) ; strcpy (
_dline -> compilerData -> block [ 25 ] . visibleName ,
"HEV/Vehicle/Differential" ) ; _dline -> compilerData -> block [ 25 ] . type
= DRIVEPLANETPLANET ; _dline -> compilerData -> block [ 25 ] . flange =
_table -> INT32_table + 35 ; _dline -> compilerData -> block [ 25 ] . flange
[ 0 ] = 13 ; _dline -> compilerData -> block [ 25 ] . flange [ 1 ] = 14 ;
_dline -> compilerData -> block [ 25 ] . flange [ 2 ] = 18 ; _dline ->
compilerData -> block [ 25 ] . planetPlanet = _table ->
DrivePlanetPlanet_table + 1 ; _dline -> compilerData -> block [ 25 ] .
planetPlanet [ 0 ] . sunFlange = 2 ; _dline -> compilerData -> block [ 25 ] .
planetPlanet [ 0 ] . planetFlange = 1 ; _dline -> compilerData -> block [ 25
] . planetPlanet [ 0 ] . ratio = 1.0 ; _dline -> compilerData -> block [ 26 ]
. numFlanges = 2 ; _dline -> compilerData -> block [ 26 ] . numParameters = 1
; _dline -> compilerData -> block [ 26 ] . parameter = _table ->
DriveParameter_table + 9 ; _dline -> compilerData -> block [ 26 ] . parameter
[ 0 ] . type = DRIVERTP_SIMPLEGEARRATIO ; _dline -> compilerData -> block [
26 ] . parameter [ 0 ] . flag = ( char * ) ( _table -> UINT8_table + 3072 ) ;
strcpy ( _dline -> compilerData -> block [ 26 ] . parameter [ 0 ] . flag ,
"drive_c8840e85GearRatio" ) ; _dline -> compilerData -> block [ 26 ] .
numSimpleGear = 1 ; _dline -> compilerData -> block [ 26 ] . name = ( char *
) ( _table -> UINT8_table + 3096 ) ; strcpy ( _dline -> compilerData -> block
[ 26 ] . name , "HEV/Vehicle/Differential/Simple Gear" ) ; _dline ->
compilerData -> block [ 26 ] . visibleName = ( char * ) ( _table ->
UINT8_table + 3133 ) ; strcpy ( _dline -> compilerData -> block [ 26 ] .
visibleName , "HEV/Vehicle/Differential" ) ; _dline -> compilerData -> block
[ 26 ] . type = DRIVESIMPLEGEAR ; _dline -> compilerData -> block [ 26 ] .
flange = _table -> INT32_table + 38 ; _dline -> compilerData -> block [ 26 ]
. flange [ 0 ] = 14 ; _dline -> compilerData -> block [ 26 ] . flange [ 1 ] =
15 ; _dline -> compilerData -> block [ 26 ] . simpleGear = _table ->
DriveSimpleGear_table + 2 ; _dline -> compilerData -> block [ 26 ] .
simpleGear [ 0 ] . reversing = TRUE ; _dline -> compilerData -> block [ 26 ]
. simpleGear [ 0 ] . outputFlange = 1 ; _dline -> compilerData -> block [ 26
] . simpleGear [ 0 ] . ratio = 1.0 ; _dline -> compilerData -> block [ 27 ] .
numFlanges = 3 ; _dline -> compilerData -> block [ 27 ] . numParameters = 1 ;
_dline -> compilerData -> block [ 27 ] . parameter = _table ->
DriveParameter_table + 10 ; _dline -> compilerData -> block [ 27 ] .
parameter [ 0 ] . type = DRIVERTP_PLANETPLANETGEARRATIO ; _dline ->
compilerData -> block [ 27 ] . parameter [ 0 ] . flag = ( char * ) ( _table
-> UINT8_table + 3158 ) ; strcpy ( _dline -> compilerData -> block [ 27 ] .
parameter [ 0 ] . flag , "drive_8aaf3b98PlanetPlanetRatio" ) ; _dline ->
compilerData -> block [ 27 ] . numPlanetPlanet = 1 ; _dline -> compilerData
-> block [ 27 ] . name = ( char * ) ( _table -> UINT8_table + 3190 ) ; strcpy
( _dline -> compilerData -> block [ 27 ] . name ,
"HEV/Vehicle/Differential/Planet-Planet1" ) ; _dline -> compilerData -> block
[ 27 ] . visibleName = ( char * ) ( _table -> UINT8_table + 3230 ) ; strcpy (
_dline -> compilerData -> block [ 27 ] . visibleName ,
"HEV/Vehicle/Differential" ) ; _dline -> compilerData -> block [ 27 ] . type
= DRIVEPLANETPLANET ; _dline -> compilerData -> block [ 27 ] . flange =
_table -> INT32_table + 40 ; _dline -> compilerData -> block [ 27 ] . flange
[ 0 ] = 15 ; _dline -> compilerData -> block [ 27 ] . flange [ 1 ] = 16 ;
_dline -> compilerData -> block [ 27 ] . flange [ 2 ] = 13 ; _dline ->
compilerData -> block [ 27 ] . planetPlanet = _table ->
DrivePlanetPlanet_table + 2 ; _dline -> compilerData -> block [ 27 ] .
planetPlanet [ 0 ] . sunFlange = 1 ; _dline -> compilerData -> block [ 27 ] .
planetPlanet [ 0 ] . carrierFlange = 2 ; _dline -> compilerData -> block [ 27
] . planetPlanet [ 0 ] . ratio = 1.0 ; _dline -> compilerData -> block [ 28 ]
. numFlanges = 2 ; _dline -> compilerData -> block [ 28 ] . numParameters = 1
; _dline -> compilerData -> block [ 28 ] . parameter = _table ->
DriveParameter_table + 11 ; _dline -> compilerData -> block [ 28 ] .
parameter [ 0 ] . type = DRIVERTP_SIMPLEGEARRATIO ; _dline -> compilerData ->
block [ 28 ] . parameter [ 0 ] . flag = ( char * ) ( _table -> UINT8_table +
3255 ) ; strcpy ( _dline -> compilerData -> block [ 28 ] . parameter [ 0 ] .
flag , "drive_699bd80dGearRatio" ) ; _dline -> compilerData -> block [ 28 ] .
numSimpleGear = 1 ; _dline -> compilerData -> block [ 28 ] . name = ( char *
) ( _table -> UINT8_table + 3279 ) ; strcpy ( _dline -> compilerData -> block
[ 28 ] . name , "HEV/Vehicle/Differential/Simple Gear2" ) ; _dline ->
compilerData -> block [ 28 ] . visibleName = ( char * ) ( _table ->
UINT8_table + 3317 ) ; strcpy ( _dline -> compilerData -> block [ 28 ] .
visibleName , "HEV/Vehicle/Differential" ) ; _dline -> compilerData -> block
[ 28 ] . type = DRIVESIMPLEGEAR ; _dline -> compilerData -> block [ 28 ] .
flange = _table -> INT32_table + 43 ; _dline -> compilerData -> block [ 28 ]
. flange [ 0 ] = 16 ; _dline -> compilerData -> block [ 28 ] . flange [ 1 ] =
17 ; _dline -> compilerData -> block [ 28 ] . simpleGear = _table ->
DriveSimpleGear_table + 3 ; _dline -> compilerData -> block [ 28 ] .
simpleGear [ 0 ] . reversing = TRUE ; _dline -> compilerData -> block [ 28 ]
. simpleGear [ 0 ] . outputFlange = 1 ; _dline -> compilerData -> block [ 28
] . simpleGear [ 0 ] . ratio = 1.0 ; _dline -> compilerData -> block [ 29 ] .
numFlanges = 1 ; _dline -> compilerData -> block [ 29 ] . numParameters = 2 ;
_dline -> compilerData -> block [ 29 ] . parameter = _table ->
DriveParameter_table + 12 ; _dline -> compilerData -> block [ 29 ] .
parameter [ 0 ] . type = DRIVERTP_INERTIA ; _dline -> compilerData -> block [
29 ] . parameter [ 0 ] . flag = ( char * ) ( _table -> UINT8_table + 3342 ) ;
strcpy ( _dline -> compilerData -> block [ 29 ] . parameter [ 0 ] . flag ,
"drive_66b082ddInertia" ) ; _dline -> compilerData -> block [ 29 ] .
parameter [ 1 ] . type = DRIVERTP_INITIALCONDITION ; _dline -> compilerData
-> block [ 29 ] . parameter [ 1 ] . flag = ( char * ) ( _table -> UINT8_table
+ 3364 ) ; strcpy ( _dline -> compilerData -> block [ 29 ] . parameter [ 1 ]
. flag , "drive_66b082ddInitialCondition" ) ; _dline -> compilerData -> block
[ 29 ] . numInertia = 1 ; _dline -> compilerData -> block [ 29 ] . name = (
char * ) ( _table -> UINT8_table + 3395 ) ; strcpy ( _dline -> compilerData
-> block [ 29 ] . name , "HEV/Vehicle/Right Tire Inertia" ) ; _dline ->
compilerData -> block [ 29 ] . visibleName = ( char * ) ( _table ->
UINT8_table + 3426 ) ; strcpy ( _dline -> compilerData -> block [ 29 ] .
visibleName , "HEV/Vehicle/Right Tire Inertia" ) ; _dline -> compilerData ->
block [ 29 ] . type = DRIVEINERTIA ; _dline -> compilerData -> block [ 29 ] .
flange = _table -> INT32_table + 45 ; _dline -> compilerData -> block [ 29 ]
. flange [ 0 ] = 17 ; _dline -> compilerData -> block [ 29 ] . inertia =
_table -> DriveInertia_table + 2 ; _dline -> compilerData -> block [ 29 ] .
inertia [ 0 ] . inertia = 0.5 ; _dline -> compilerData -> block [ 30 ] .
numFlanges = 1 ; _dline -> compilerData -> block [ 30 ] . numTransducer = 1 ;
_dline -> compilerData -> block [ 30 ] . name = ( char * ) ( _table ->
UINT8_table + 3457 ) ; strcpy ( _dline -> compilerData -> block [ 30 ] . name
, "HEV/Vehicle/Right Tire/Wheel dynamics/Motion Sensor/Transducer" ) ; _dline
-> compilerData -> block [ 30 ] . visibleName = ( char * ) ( _table ->
UINT8_table + 3520 ) ; strcpy ( _dline -> compilerData -> block [ 30 ] .
visibleName , "HEV/Vehicle/Right Tire" ) ; _dline -> compilerData -> block [
30 ] . type = DRIVETRANSDUCER ; _dline -> compilerData -> block [ 30 ] .
flange = _table -> INT32_table + 46 ; _dline -> compilerData -> block [ 30 ]
. flange [ 0 ] = 17 ; _dline -> compilerData -> block [ 30 ] . transducer =
_table -> DriveTransducer_table + 8 ; _dline -> compilerData -> block [ 30 ]
. transducer [ 0 ] . numSignals = 2 ; _dline -> compilerData -> block [ 30 ]
. transducer [ 0 ] . positionFlag = ( char * ) ( _table -> UINT8_table + 3543
) ; strcpy ( _dline -> compilerData -> block [ 30 ] . transducer [ 0 ] .
positionFlag , "Undefined" ) ; _dline -> compilerData -> block [ 30 ] .
transducer [ 0 ] . velocityFlag = ( char * ) ( _table -> UINT8_table + 3553 )
; strcpy ( _dline -> compilerData -> block [ 30 ] . transducer [ 0 ] .
velocityFlag , "Undefined" ) ; _dline -> compilerData -> block [ 30 ] .
transducer [ 0 ] . accelerationFlag = ( char * ) ( _table -> UINT8_table +
3563 ) ; strcpy ( _dline -> compilerData -> block [ 30 ] . transducer [ 0 ] .
accelerationFlag , "Undefined" ) ; _dline -> compilerData -> block [ 30 ] .
transducer [ 0 ] . signal = _table -> DriveSignal_table + 13 ; _dline ->
compilerData -> block [ 30 ] . transducer [ 0 ] . signal [ 0 ] . type =
DRIVEVELOCITY ; _dline -> compilerData -> block [ 30 ] . transducer [ 0 ] .
signal [ 0 ] . flag = ( char * ) ( _table -> UINT8_table + 3573 ) ; strcpy (
_dline -> compilerData -> block [ 30 ] . transducer [ 0 ] . signal [ 0 ] .
flag , "drive_41d49eb1Velocity" ) ; _dline -> compilerData -> block [ 30 ] .
transducer [ 0 ] . signal [ 1 ] . type = DRIVEACCELERATION ; _dline ->
compilerData -> block [ 30 ] . transducer [ 0 ] . signal [ 1 ] . flag = (
char * ) ( _table -> UINT8_table + 3596 ) ; strcpy ( _dline -> compilerData
-> block [ 30 ] . transducer [ 0 ] . signal [ 1 ] . flag ,
"drive_41d49eb1Acceleration" ) ; _dline -> compilerData -> block [ 31 ] .
numFlanges = 1 ; _dline -> compilerData -> block [ 31 ] . numTransducer = 1 ;
_dline -> compilerData -> block [ 31 ] . name = ( char * ) ( _table ->
UINT8_table + 3623 ) ; strcpy ( _dline -> compilerData -> block [ 31 ] . name
, "HEV/Vehicle/Right Tire/Wheel dynamics/Torque Actuator/Transducer" ) ;
_dline -> compilerData -> block [ 31 ] . visibleName = ( char * ) ( _table ->
UINT8_table + 3688 ) ; strcpy ( _dline -> compilerData -> block [ 31 ] .
visibleName , "HEV/Vehicle/Right Tire" ) ; _dline -> compilerData -> block [
31 ] . type = DRIVETRANSDUCER ; _dline -> compilerData -> block [ 31 ] .
flange = _table -> INT32_table + 47 ; _dline -> compilerData -> block [ 31 ]
. flange [ 0 ] = 17 ; _dline -> compilerData -> block [ 31 ] . transducer =
_table -> DriveTransducer_table + 9 ; _dline -> compilerData -> block [ 31 ]
. transducer [ 0 ] . numSignals = 1 ; _dline -> compilerData -> block [ 31 ]
. transducer [ 0 ] . positionFlag = ( char * ) ( _table -> UINT8_table + 3711
) ; strcpy ( _dline -> compilerData -> block [ 31 ] . transducer [ 0 ] .
positionFlag , "Undefined" ) ; _dline -> compilerData -> block [ 31 ] .
transducer [ 0 ] . velocityFlag = ( char * ) ( _table -> UINT8_table + 3721 )
; strcpy ( _dline -> compilerData -> block [ 31 ] . transducer [ 0 ] .
velocityFlag , "Undefined" ) ; _dline -> compilerData -> block [ 31 ] .
transducer [ 0 ] . accelerationFlag = ( char * ) ( _table -> UINT8_table +
3731 ) ; strcpy ( _dline -> compilerData -> block [ 31 ] . transducer [ 0 ] .
accelerationFlag , "Undefined" ) ; _dline -> compilerData -> block [ 31 ] .
transducer [ 0 ] . signal = _table -> DriveSignal_table + 15 ; _dline ->
compilerData -> block [ 31 ] . transducer [ 0 ] . signal [ 0 ] . type =
DRIVEEXTERNALTORQUE ; _dline -> compilerData -> block [ 31 ] . transducer [ 0
] . signal [ 0 ] . flag = ( char * ) ( _table -> UINT8_table + 3741 ) ;
strcpy ( _dline -> compilerData -> block [ 31 ] . transducer [ 0 ] . signal [
0 ] . flag , "drive_ebfa3480Tor" ) ; _dline -> compilerData -> block [ 32 ] .
numFlanges = 2 ; _dline -> compilerData -> block [ 32 ] . numParameters = 1 ;
_dline -> compilerData -> block [ 32 ] . parameter = _table ->
DriveParameter_table + 14 ; _dline -> compilerData -> block [ 32 ] .
parameter [ 0 ] . type = DRIVERTP_SIMPLEGEARRATIO ; _dline -> compilerData ->
block [ 32 ] . parameter [ 0 ] . flag = ( char * ) ( _table -> UINT8_table +
3759 ) ; strcpy ( _dline -> compilerData -> block [ 32 ] . parameter [ 0 ] .
flag , "drive_1e9ce89bGearRatio" ) ; _dline -> compilerData -> block [ 32 ] .
numSimpleGear = 1 ; _dline -> compilerData -> block [ 32 ] . name = ( char *
) ( _table -> UINT8_table + 3783 ) ; strcpy ( _dline -> compilerData -> block
[ 32 ] . name , "HEV/Vehicle/Differential/Simple Gear3" ) ; _dline ->
compilerData -> block [ 32 ] . visibleName = ( char * ) ( _table ->
UINT8_table + 3821 ) ; strcpy ( _dline -> compilerData -> block [ 32 ] .
visibleName , "HEV/Vehicle/Differential" ) ; _dline -> compilerData -> block
[ 32 ] . type = DRIVESIMPLEGEAR ; _dline -> compilerData -> block [ 32 ] .
flange = _table -> INT32_table + 48 ; _dline -> compilerData -> block [ 32 ]
. flange [ 0 ] = 18 ; _dline -> compilerData -> block [ 32 ] . flange [ 1 ] =
19 ; _dline -> compilerData -> block [ 32 ] . simpleGear = _table ->
DriveSimpleGear_table + 4 ; _dline -> compilerData -> block [ 32 ] .
simpleGear [ 0 ] . reversing = TRUE ; _dline -> compilerData -> block [ 32 ]
. simpleGear [ 0 ] . outputFlange = 1 ; _dline -> compilerData -> block [ 32
] . simpleGear [ 0 ] . ratio = 1.0 ; _dline -> compilerData -> block [ 33 ] .
numFlanges = 1 ; _dline -> compilerData -> block [ 33 ] . numParameters = 2 ;
_dline -> compilerData -> block [ 33 ] . parameter = _table ->
DriveParameter_table + 15 ; _dline -> compilerData -> block [ 33 ] .
parameter [ 0 ] . type = DRIVERTP_INERTIA ; _dline -> compilerData -> block [
33 ] . parameter [ 0 ] . flag = ( char * ) ( _table -> UINT8_table + 3846 ) ;
strcpy ( _dline -> compilerData -> block [ 33 ] . parameter [ 0 ] . flag ,
"drive_80d28a58Inertia" ) ; _dline -> compilerData -> block [ 33 ] .
parameter [ 1 ] . type = DRIVERTP_INITIALCONDITION ; _dline -> compilerData
-> block [ 33 ] . parameter [ 1 ] . flag = ( char * ) ( _table -> UINT8_table
+ 3868 ) ; strcpy ( _dline -> compilerData -> block [ 33 ] . parameter [ 1 ]
. flag , "drive_80d28a58InitialCondition" ) ; _dline -> compilerData -> block
[ 33 ] . numInertia = 1 ; _dline -> compilerData -> block [ 33 ] . name = (
char * ) ( _table -> UINT8_table + 3899 ) ; strcpy ( _dline -> compilerData
-> block [ 33 ] . name , "HEV/Vehicle/Left Tire Inertia" ) ; _dline ->
compilerData -> block [ 33 ] . visibleName = ( char * ) ( _table ->
UINT8_table + 3929 ) ; strcpy ( _dline -> compilerData -> block [ 33 ] .
visibleName , "HEV/Vehicle/Left Tire Inertia" ) ; _dline -> compilerData ->
block [ 33 ] . type = DRIVEINERTIA ; _dline -> compilerData -> block [ 33 ] .
flange = _table -> INT32_table + 50 ; _dline -> compilerData -> block [ 33 ]
. flange [ 0 ] = 19 ; _dline -> compilerData -> block [ 33 ] . inertia =
_table -> DriveInertia_table + 3 ; _dline -> compilerData -> block [ 33 ] .
inertia [ 0 ] . inertia = 0.5 ; _dline -> compilerData -> block [ 34 ] .
numFlanges = 1 ; _dline -> compilerData -> block [ 34 ] . numTransducer = 1 ;
_dline -> compilerData -> block [ 34 ] . name = ( char * ) ( _table ->
UINT8_table + 3959 ) ; strcpy ( _dline -> compilerData -> block [ 34 ] . name
, "HEV/Vehicle/Left Tire/Wheel dynamics/Motion Sensor/Transducer" ) ; _dline
-> compilerData -> block [ 34 ] . visibleName = ( char * ) ( _table ->
UINT8_table + 4021 ) ; strcpy ( _dline -> compilerData -> block [ 34 ] .
visibleName , "HEV/Vehicle/Left Tire" ) ; _dline -> compilerData -> block [
34 ] . type = DRIVETRANSDUCER ; _dline -> compilerData -> block [ 34 ] .
flange = _table -> INT32_table + 51 ; _dline -> compilerData -> block [ 34 ]
. flange [ 0 ] = 19 ; _dline -> compilerData -> block [ 34 ] . transducer =
_table -> DriveTransducer_table + 10 ; _dline -> compilerData -> block [ 34 ]
. transducer [ 0 ] . numSignals = 2 ; _dline -> compilerData -> block [ 34 ]
. transducer [ 0 ] . positionFlag = ( char * ) ( _table -> UINT8_table + 4043
) ; strcpy ( _dline -> compilerData -> block [ 34 ] . transducer [ 0 ] .
positionFlag , "Undefined" ) ; _dline -> compilerData -> block [ 34 ] .
transducer [ 0 ] . velocityFlag = ( char * ) ( _table -> UINT8_table + 4053 )
; strcpy ( _dline -> compilerData -> block [ 34 ] . transducer [ 0 ] .
velocityFlag , "Undefined" ) ; _dline -> compilerData -> block [ 34 ] .
transducer [ 0 ] . accelerationFlag = ( char * ) ( _table -> UINT8_table +
4063 ) ; strcpy ( _dline -> compilerData -> block [ 34 ] . transducer [ 0 ] .
accelerationFlag , "Undefined" ) ; _dline -> compilerData -> block [ 34 ] .
transducer [ 0 ] . signal = _table -> DriveSignal_table + 16 ; _dline ->
compilerData -> block [ 34 ] . transducer [ 0 ] . signal [ 0 ] . type =
DRIVEVELOCITY ; _dline -> compilerData -> block [ 34 ] . transducer [ 0 ] .
signal [ 0 ] . flag = ( char * ) ( _table -> UINT8_table + 4073 ) ; strcpy (
_dline -> compilerData -> block [ 34 ] . transducer [ 0 ] . signal [ 0 ] .
flag , "drive_8c9aa461Velocity" ) ; _dline -> compilerData -> block [ 34 ] .
transducer [ 0 ] . signal [ 1 ] . type = DRIVEACCELERATION ; _dline ->
compilerData -> block [ 34 ] . transducer [ 0 ] . signal [ 1 ] . flag = (
char * ) ( _table -> UINT8_table + 4096 ) ; strcpy ( _dline -> compilerData
-> block [ 34 ] . transducer [ 0 ] . signal [ 1 ] . flag ,
"drive_8c9aa461Acceleration" ) ; _dline -> compilerData -> block [ 35 ] .
numFlanges = 1 ; _dline -> compilerData -> block [ 35 ] . numTransducer = 1 ;
_dline -> compilerData -> block [ 35 ] . name = ( char * ) ( _table ->
UINT8_table + 4123 ) ; strcpy ( _dline -> compilerData -> block [ 35 ] . name
, "HEV/Vehicle/Left Tire/Wheel dynamics/Torque Actuator/Transducer" ) ;
_dline -> compilerData -> block [ 35 ] . visibleName = ( char * ) ( _table ->
UINT8_table + 4187 ) ; strcpy ( _dline -> compilerData -> block [ 35 ] .
visibleName , "HEV/Vehicle/Left Tire" ) ; _dline -> compilerData -> block [
35 ] . type = DRIVETRANSDUCER ; _dline -> compilerData -> block [ 35 ] .
flange = _table -> INT32_table + 52 ; _dline -> compilerData -> block [ 35 ]
. flange [ 0 ] = 19 ; _dline -> compilerData -> block [ 35 ] . transducer =
_table -> DriveTransducer_table + 11 ; _dline -> compilerData -> block [ 35 ]
. transducer [ 0 ] . numSignals = 1 ; _dline -> compilerData -> block [ 35 ]
. transducer [ 0 ] . positionFlag = ( char * ) ( _table -> UINT8_table + 4209
) ; strcpy ( _dline -> compilerData -> block [ 35 ] . transducer [ 0 ] .
positionFlag , "Undefined" ) ; _dline -> compilerData -> block [ 35 ] .
transducer [ 0 ] . velocityFlag = ( char * ) ( _table -> UINT8_table + 4219 )
; strcpy ( _dline -> compilerData -> block [ 35 ] . transducer [ 0 ] .
velocityFlag , "Undefined" ) ; _dline -> compilerData -> block [ 35 ] .
transducer [ 0 ] . accelerationFlag = ( char * ) ( _table -> UINT8_table +
4229 ) ; strcpy ( _dline -> compilerData -> block [ 35 ] . transducer [ 0 ] .
accelerationFlag , "Undefined" ) ; _dline -> compilerData -> block [ 35 ] .
transducer [ 0 ] . signal = _table -> DriveSignal_table + 18 ; _dline ->
compilerData -> block [ 35 ] . transducer [ 0 ] . signal [ 0 ] . type =
DRIVEEXTERNALTORQUE ; _dline -> compilerData -> block [ 35 ] . transducer [ 0
] . signal [ 0 ] . flag = ( char * ) ( _table -> UINT8_table + 4239 ) ;
strcpy ( _dline -> compilerData -> block [ 35 ] . transducer [ 0 ] . signal [
0 ] . flag , "drive_6f7d31d9Tor" ) ; _dline -> compilerData -> block [ 36 ] .
numFlanges = 1 ; _dline -> compilerData -> block [ 36 ] . numTransducer = 1 ;
_dline -> compilerData -> block [ 36 ] . name = ( char * ) ( _table ->
UINT8_table + 4257 ) ; strcpy ( _dline -> compilerData -> block [ 36 ] . name
,
 "HEV/Vehicle/Torsional \\\\nSpring-Damper \\\\n(Friction)/follower_torque/Transducer"
) ; _dline -> compilerData -> block [ 36 ] . visibleName = ( char * ) (
_table -> UINT8_table + 4333 ) ; strcpy ( _dline -> compilerData -> block [
36 ] . visibleName ,
"HEV/Vehicle/Torsional \\\\nSpring-Damper \\\\n(Friction)" ) ; _dline ->
compilerData -> block [ 36 ] . type = DRIVETRANSDUCER ; _dline ->
compilerData -> block [ 36 ] . flange = _table -> INT32_table + 53 ; _dline
-> compilerData -> block [ 36 ] . flange [ 0 ] = 10 ; _dline -> compilerData
-> block [ 36 ] . transducer = _table -> DriveTransducer_table + 12 ; _dline
-> compilerData -> block [ 36 ] . transducer [ 0 ] . numSignals = 1 ; _dline
-> compilerData -> block [ 36 ] . transducer [ 0 ] . positionFlag = ( char *
) ( _table -> UINT8_table + 4382 ) ; strcpy ( _dline -> compilerData -> block
[ 36 ] . transducer [ 0 ] . positionFlag , "Undefined" ) ; _dline ->
compilerData -> block [ 36 ] . transducer [ 0 ] . velocityFlag = ( char * ) (
_table -> UINT8_table + 4392 ) ; strcpy ( _dline -> compilerData -> block [
36 ] . transducer [ 0 ] . velocityFlag , "Undefined" ) ; _dline ->
compilerData -> block [ 36 ] . transducer [ 0 ] . accelerationFlag = ( char *
) ( _table -> UINT8_table + 4402 ) ; strcpy ( _dline -> compilerData -> block
[ 36 ] . transducer [ 0 ] . accelerationFlag , "Undefined" ) ; _dline ->
compilerData -> block [ 36 ] . transducer [ 0 ] . signal = _table ->
DriveSignal_table + 19 ; _dline -> compilerData -> block [ 36 ] . transducer
[ 0 ] . signal [ 0 ] . type = DRIVEEXTERNALTORQUE ; _dline -> compilerData ->
block [ 36 ] . transducer [ 0 ] . signal [ 0 ] . flag = ( char * ) ( _table
-> UINT8_table + 4412 ) ; strcpy ( _dline -> compilerData -> block [ 36 ] .
transducer [ 0 ] . signal [ 0 ] . flag , "drive_46a5b3a3Tor" ) ; _dline ->
compilerData -> block [ 37 ] . numFlanges = 1 ; _dline -> compilerData ->
block [ 37 ] . numTransducer = 1 ; _dline -> compilerData -> block [ 37 ] .
name = ( char * ) ( _table -> UINT8_table + 4430 ) ; strcpy ( _dline ->
compilerData -> block [ 37 ] . name ,
 "HEV/Vehicle/Torsional \\\\nSpring-Damper \\\\n(Friction)/follower_velocity/Transducer"
) ; _dline -> compilerData -> block [ 37 ] . visibleName = ( char * ) (
_table -> UINT8_table + 4508 ) ; strcpy ( _dline -> compilerData -> block [
37 ] . visibleName ,
"HEV/Vehicle/Torsional \\\\nSpring-Damper \\\\n(Friction)" ) ; _dline ->
compilerData -> block [ 37 ] . type = DRIVETRANSDUCER ; _dline ->
compilerData -> block [ 37 ] . flange = _table -> INT32_table + 54 ; _dline
-> compilerData -> block [ 37 ] . flange [ 0 ] = 10 ; _dline -> compilerData
-> block [ 37 ] . transducer = _table -> DriveTransducer_table + 13 ; _dline
-> compilerData -> block [ 37 ] . transducer [ 0 ] . numSignals = 2 ; _dline
-> compilerData -> block [ 37 ] . transducer [ 0 ] . positionFlag = ( char *
) ( _table -> UINT8_table + 4557 ) ; strcpy ( _dline -> compilerData -> block
[ 37 ] . transducer [ 0 ] . positionFlag , "Undefined" ) ; _dline ->
compilerData -> block [ 37 ] . transducer [ 0 ] . velocityFlag = ( char * ) (
_table -> UINT8_table + 4567 ) ; strcpy ( _dline -> compilerData -> block [
37 ] . transducer [ 0 ] . velocityFlag , "Undefined" ) ; _dline ->
compilerData -> block [ 37 ] . transducer [ 0 ] . accelerationFlag = ( char *
) ( _table -> UINT8_table + 4577 ) ; strcpy ( _dline -> compilerData -> block
[ 37 ] . transducer [ 0 ] . accelerationFlag , "Undefined" ) ; _dline ->
compilerData -> block [ 37 ] . transducer [ 0 ] . signal = _table ->
DriveSignal_table + 20 ; _dline -> compilerData -> block [ 37 ] . transducer
[ 0 ] . signal [ 0 ] . type = DRIVEVELOCITY ; _dline -> compilerData -> block
[ 37 ] . transducer [ 0 ] . signal [ 0 ] . flag = ( char * ) ( _table ->
UINT8_table + 4587 ) ; strcpy ( _dline -> compilerData -> block [ 37 ] .
transducer [ 0 ] . signal [ 0 ] . flag , "drive_e5b2ea75Velocity" ) ; _dline
-> compilerData -> block [ 37 ] . transducer [ 0 ] . signal [ 1 ] . type =
DRIVEACCELERATION ; _dline -> compilerData -> block [ 37 ] . transducer [ 0 ]
. signal [ 1 ] . flag = ( char * ) ( _table -> UINT8_table + 4610 ) ; strcpy
( _dline -> compilerData -> block [ 37 ] . transducer [ 0 ] . signal [ 1 ] .
flag , "drive_e5b2ea75Acceleration" ) ; _dline -> compilerData -> block [ 38
] . numFlanges = 1 ; _dline -> compilerData -> block [ 38 ] . numTransducer =
1 ; _dline -> compilerData -> block [ 38 ] . name = ( char * ) ( _table ->
UINT8_table + 4637 ) ; strcpy ( _dline -> compilerData -> block [ 38 ] . name
, "HEV/Electric Motor Controller\\\\n/Motor Motion Sensor/Transducer" ) ;
_dline -> compilerData -> block [ 38 ] . visibleName = ( char * ) ( _table ->
UINT8_table + 4699 ) ; strcpy ( _dline -> compilerData -> block [ 38 ] .
visibleName , "HEV/Electric Motor Controller\\\\n/Motor Motion Sensor" ) ;
_dline -> compilerData -> block [ 38 ] . type = DRIVETRANSDUCER ; _dline ->
compilerData -> block [ 38 ] . flange = _table -> INT32_table + 55 ; _dline
-> compilerData -> block [ 38 ] . flange [ 0 ] = 9 ; _dline -> compilerData
-> block [ 38 ] . transducer = _table -> DriveTransducer_table + 14 ; _dline
-> compilerData -> block [ 38 ] . transducer [ 0 ] . numSignals = 2 ; _dline
-> compilerData -> block [ 38 ] . transducer [ 0 ] . positionFlag = ( char *
) ( _table -> UINT8_table + 4750 ) ; strcpy ( _dline -> compilerData -> block
[ 38 ] . transducer [ 0 ] . positionFlag , "Undefined" ) ; _dline ->
compilerData -> block [ 38 ] . transducer [ 0 ] . velocityFlag = ( char * ) (
_table -> UINT8_table + 4760 ) ; strcpy ( _dline -> compilerData -> block [
38 ] . transducer [ 0 ] . velocityFlag , "Undefined" ) ; _dline ->
compilerData -> block [ 38 ] . transducer [ 0 ] . accelerationFlag = ( char *
) ( _table -> UINT8_table + 4770 ) ; strcpy ( _dline -> compilerData -> block
[ 38 ] . transducer [ 0 ] . accelerationFlag , "Undefined" ) ; _dline ->
compilerData -> block [ 38 ] . transducer [ 0 ] . signal = _table ->
DriveSignal_table + 22 ; _dline -> compilerData -> block [ 38 ] . transducer
[ 0 ] . signal [ 0 ] . type = DRIVEVELOCITY ; _dline -> compilerData -> block
[ 38 ] . transducer [ 0 ] . signal [ 0 ] . flag = ( char * ) ( _table ->
UINT8_table + 4780 ) ; strcpy ( _dline -> compilerData -> block [ 38 ] .
transducer [ 0 ] . signal [ 0 ] . flag , "drive_f4b8de34Velocity" ) ; _dline
-> compilerData -> block [ 38 ] . transducer [ 0 ] . signal [ 1 ] . type =
DRIVEACCELERATION ; _dline -> compilerData -> block [ 38 ] . transducer [ 0 ]
. signal [ 1 ] . flag = ( char * ) ( _table -> UINT8_table + 4803 ) ; strcpy
( _dline -> compilerData -> block [ 38 ] . transducer [ 0 ] . signal [ 1 ] .
flag , "drive_f4b8de34Acceleration" ) ; _dline -> compilerData -> block [ 39
] . numFlanges = 1 ; _dline -> compilerData -> block [ 39 ] . numTransducer =
1 ; _dline -> compilerData -> block [ 39 ] . name = ( char * ) ( _table ->
UINT8_table + 4830 ) ; strcpy ( _dline -> compilerData -> block [ 39 ] . name
, "HEV/Electric Motor Controller\\\\n/Torque Actuator Mot/Transducer" ) ;
_dline -> compilerData -> block [ 39 ] . visibleName = ( char * ) ( _table ->
UINT8_table + 4892 ) ; strcpy ( _dline -> compilerData -> block [ 39 ] .
visibleName , "HEV/Electric Motor Controller\\\\n/Torque Actuator Mot" ) ;
_dline -> compilerData -> block [ 39 ] . type = DRIVETRANSDUCER ; _dline ->
compilerData -> block [ 39 ] . flange = _table -> INT32_table + 56 ; _dline
-> compilerData -> block [ 39 ] . flange [ 0 ] = 9 ; _dline -> compilerData
-> block [ 39 ] . transducer = _table -> DriveTransducer_table + 15 ; _dline
-> compilerData -> block [ 39 ] . transducer [ 0 ] . numSignals = 1 ; _dline
-> compilerData -> block [ 39 ] . transducer [ 0 ] . positionFlag = ( char *
) ( _table -> UINT8_table + 4943 ) ; strcpy ( _dline -> compilerData -> block
[ 39 ] . transducer [ 0 ] . positionFlag , "Undefined" ) ; _dline ->
compilerData -> block [ 39 ] . transducer [ 0 ] . velocityFlag = ( char * ) (
_table -> UINT8_table + 4953 ) ; strcpy ( _dline -> compilerData -> block [
39 ] . transducer [ 0 ] . velocityFlag , "Undefined" ) ; _dline ->
compilerData -> block [ 39 ] . transducer [ 0 ] . accelerationFlag = ( char *
) ( _table -> UINT8_table + 4963 ) ; strcpy ( _dline -> compilerData -> block
[ 39 ] . transducer [ 0 ] . accelerationFlag , "Undefined" ) ; _dline ->
compilerData -> block [ 39 ] . transducer [ 0 ] . signal = _table ->
DriveSignal_table + 24 ; _dline -> compilerData -> block [ 39 ] . transducer
[ 0 ] . signal [ 0 ] . type = DRIVEEXTERNALTORQUE ; _dline -> compilerData ->
block [ 39 ] . transducer [ 0 ] . signal [ 0 ] . flag = ( char * ) ( _table
-> UINT8_table + 4973 ) ; strcpy ( _dline -> compilerData -> block [ 39 ] .
transducer [ 0 ] . signal [ 0 ] . flag , "drive_ccb66a09Tor" ) ; _dline ->
compilerData -> block [ 40 ] . numFlanges = 1 ; _dline -> compilerData ->
block [ 40 ] . numTransducer = 1 ; _dline -> compilerData -> block [ 40 ] .
name = ( char * ) ( _table -> UINT8_table + 4991 ) ; strcpy ( _dline ->
compilerData -> block [ 40 ] . name ,
"HEV/Gearbox/Gen Motion Sensor/Transducer" ) ; _dline -> compilerData ->
block [ 40 ] . visibleName = ( char * ) ( _table -> UINT8_table + 5032 ) ;
strcpy ( _dline -> compilerData -> block [ 40 ] . visibleName ,
"HEV/Gearbox/Gen Motion Sensor" ) ; _dline -> compilerData -> block [ 40 ] .
type = DRIVETRANSDUCER ; _dline -> compilerData -> block [ 40 ] . flange =
_table -> INT32_table + 57 ; _dline -> compilerData -> block [ 40 ] . flange
[ 0 ] = 9 ; _dline -> compilerData -> block [ 40 ] . transducer = _table ->
DriveTransducer_table + 16 ; _dline -> compilerData -> block [ 40 ] .
transducer [ 0 ] . numSignals = 2 ; _dline -> compilerData -> block [ 40 ] .
transducer [ 0 ] . positionFlag = ( char * ) ( _table -> UINT8_table + 5062 )
; strcpy ( _dline -> compilerData -> block [ 40 ] . transducer [ 0 ] .
positionFlag , "Undefined" ) ; _dline -> compilerData -> block [ 40 ] .
transducer [ 0 ] . velocityFlag = ( char * ) ( _table -> UINT8_table + 5072 )
; strcpy ( _dline -> compilerData -> block [ 40 ] . transducer [ 0 ] .
velocityFlag , "Undefined" ) ; _dline -> compilerData -> block [ 40 ] .
transducer [ 0 ] . accelerationFlag = ( char * ) ( _table -> UINT8_table +
5082 ) ; strcpy ( _dline -> compilerData -> block [ 40 ] . transducer [ 0 ] .
accelerationFlag , "Undefined" ) ; _dline -> compilerData -> block [ 40 ] .
transducer [ 0 ] . signal = _table -> DriveSignal_table + 25 ; _dline ->
compilerData -> block [ 40 ] . transducer [ 0 ] . signal [ 0 ] . type =
DRIVEVELOCITY ; _dline -> compilerData -> block [ 40 ] . transducer [ 0 ] .
signal [ 0 ] . flag = ( char * ) ( _table -> UINT8_table + 5092 ) ; strcpy (
_dline -> compilerData -> block [ 40 ] . transducer [ 0 ] . signal [ 0 ] .
flag , "drive_53507db2Velocity" ) ; _dline -> compilerData -> block [ 40 ] .
transducer [ 0 ] . signal [ 1 ] . type = DRIVEACCELERATION ; _dline ->
compilerData -> block [ 40 ] . transducer [ 0 ] . signal [ 1 ] . flag = (
char * ) ( _table -> UINT8_table + 5115 ) ; strcpy ( _dline -> compilerData
-> block [ 40 ] . transducer [ 0 ] . signal [ 1 ] . flag ,
"drive_53507db2Acceleration" ) ; _dline -> compilerData -> block [ 41 ] .
numFlanges = 1 ; _dline -> compilerData -> block [ 41 ] . numTransducer = 1 ;
_dline -> compilerData -> block [ 41 ] . name = ( char * ) ( _table ->
UINT8_table + 5142 ) ; strcpy ( _dline -> compilerData -> block [ 41 ] . name
, "HEV/Gearbox/Eng Motion Sensor/Transducer" ) ; _dline -> compilerData ->
block [ 41 ] . visibleName = ( char * ) ( _table -> UINT8_table + 5183 ) ;
strcpy ( _dline -> compilerData -> block [ 41 ] . visibleName ,
"HEV/Gearbox/Eng Motion Sensor" ) ; _dline -> compilerData -> block [ 41 ] .
type = DRIVETRANSDUCER ; _dline -> compilerData -> block [ 41 ] . flange =
_table -> INT32_table + 58 ; _dline -> compilerData -> block [ 41 ] . flange
[ 0 ] = 3 ; _dline -> compilerData -> block [ 41 ] . transducer = _table ->
DriveTransducer_table + 17 ; _dline -> compilerData -> block [ 41 ] .
transducer [ 0 ] . numSignals = 2 ; _dline -> compilerData -> block [ 41 ] .
transducer [ 0 ] . positionFlag = ( char * ) ( _table -> UINT8_table + 5213 )
; strcpy ( _dline -> compilerData -> block [ 41 ] . transducer [ 0 ] .
positionFlag , "Undefined" ) ; _dline -> compilerData -> block [ 41 ] .
transducer [ 0 ] . velocityFlag = ( char * ) ( _table -> UINT8_table + 5223 )
; strcpy ( _dline -> compilerData -> block [ 41 ] . transducer [ 0 ] .
velocityFlag , "Undefined" ) ; _dline -> compilerData -> block [ 41 ] .
transducer [ 0 ] . accelerationFlag = ( char * ) ( _table -> UINT8_table +
5233 ) ; strcpy ( _dline -> compilerData -> block [ 41 ] . transducer [ 0 ] .
accelerationFlag , "Undefined" ) ; _dline -> compilerData -> block [ 41 ] .
transducer [ 0 ] . signal = _table -> DriveSignal_table + 27 ; _dline ->
compilerData -> block [ 41 ] . transducer [ 0 ] . signal [ 0 ] . type =
DRIVEVELOCITY ; _dline -> compilerData -> block [ 41 ] . transducer [ 0 ] .
signal [ 0 ] . flag = ( char * ) ( _table -> UINT8_table + 5243 ) ; strcpy (
_dline -> compilerData -> block [ 41 ] . transducer [ 0 ] . signal [ 0 ] .
flag , "drive_f9653595Velocity" ) ; _dline -> compilerData -> block [ 41 ] .
transducer [ 0 ] . signal [ 1 ] . type = DRIVEACCELERATION ; _dline ->
compilerData -> block [ 41 ] . transducer [ 0 ] . signal [ 1 ] . flag = (
char * ) ( _table -> UINT8_table + 5266 ) ; strcpy ( _dline -> compilerData
-> block [ 41 ] . transducer [ 0 ] . signal [ 1 ] . flag ,
"drive_f9653595Acceleration" ) ; _dline -> compilerData -> block [ 42 ] .
numFlanges = 1 ; _dline -> compilerData -> block [ 42 ] . numTransducer = 1 ;
_dline -> compilerData -> block [ 42 ] . name = ( char * ) ( _table ->
UINT8_table + 5293 ) ; strcpy ( _dline -> compilerData -> block [ 42 ] . name
, "HEV/Engine Controller/Gasoline Engine1/Motion Sensor/Transducer" ) ;
_dline -> compilerData -> block [ 42 ] . visibleName = ( char * ) ( _table ->
UINT8_table + 5357 ) ; strcpy ( _dline -> compilerData -> block [ 42 ] .
visibleName , "HEV/Engine Controller/Gasoline Engine1" ) ; _dline ->
compilerData -> block [ 42 ] . type = DRIVETRANSDUCER ; _dline ->
compilerData -> block [ 42 ] . flange = _table -> INT32_table + 59 ; _dline
-> compilerData -> block [ 42 ] . transducer = _table ->
DriveTransducer_table + 18 ; _dline -> compilerData -> block [ 42 ] .
transducer [ 0 ] . numSignals = 2 ; _dline -> compilerData -> block [ 42 ] .
transducer [ 0 ] . positionFlag = ( char * ) ( _table -> UINT8_table + 5396 )
; strcpy ( _dline -> compilerData -> block [ 42 ] . transducer [ 0 ] .
positionFlag , "Undefined" ) ; _dline -> compilerData -> block [ 42 ] .
transducer [ 0 ] . velocityFlag = ( char * ) ( _table -> UINT8_table + 5406 )
; strcpy ( _dline -> compilerData -> block [ 42 ] . transducer [ 0 ] .
velocityFlag , "Undefined" ) ; _dline -> compilerData -> block [ 42 ] .
transducer [ 0 ] . accelerationFlag = ( char * ) ( _table -> UINT8_table +
5416 ) ; strcpy ( _dline -> compilerData -> block [ 42 ] . transducer [ 0 ] .
accelerationFlag , "Undefined" ) ; _dline -> compilerData -> block [ 42 ] .
transducer [ 0 ] . signal = _table -> DriveSignal_table + 29 ; _dline ->
compilerData -> block [ 42 ] . transducer [ 0 ] . signal [ 0 ] . type =
DRIVEVELOCITY ; _dline -> compilerData -> block [ 42 ] . transducer [ 0 ] .
signal [ 0 ] . flag = ( char * ) ( _table -> UINT8_table + 5426 ) ; strcpy (
_dline -> compilerData -> block [ 42 ] . transducer [ 0 ] . signal [ 0 ] .
flag , "drive_846eabc9Velocity" ) ; _dline -> compilerData -> block [ 42 ] .
transducer [ 0 ] . signal [ 1 ] . type = DRIVEACCELERATION ; _dline ->
compilerData -> block [ 42 ] . transducer [ 0 ] . signal [ 1 ] . flag = (
char * ) ( _table -> UINT8_table + 5449 ) ; strcpy ( _dline -> compilerData
-> block [ 42 ] . transducer [ 0 ] . signal [ 1 ] . flag ,
"drive_846eabc9Acceleration" ) ; _dline -> compilerData -> block [ 43 ] .
numFlanges = 1 ; _dline -> compilerData -> block [ 43 ] . numTransducer = 1 ;
_dline -> compilerData -> block [ 43 ] . name = ( char * ) ( _table ->
UINT8_table + 5476 ) ; strcpy ( _dline -> compilerData -> block [ 43 ] . name
, "HEV/Engine Controller/Gasoline Engine1/Torque Actuator/Transducer" ) ;
_dline -> compilerData -> block [ 43 ] . visibleName = ( char * ) ( _table ->
UINT8_table + 5542 ) ; strcpy ( _dline -> compilerData -> block [ 43 ] .
visibleName , "HEV/Engine Controller/Gasoline Engine1" ) ; _dline ->
compilerData -> block [ 43 ] . type = DRIVETRANSDUCER ; _dline ->
compilerData -> block [ 43 ] . flange = _table -> INT32_table + 60 ; _dline
-> compilerData -> block [ 43 ] . transducer = _table ->
DriveTransducer_table + 19 ; _dline -> compilerData -> block [ 43 ] .
transducer [ 0 ] . numSignals = 1 ; _dline -> compilerData -> block [ 43 ] .
transducer [ 0 ] . positionFlag = ( char * ) ( _table -> UINT8_table + 5581 )
; strcpy ( _dline -> compilerData -> block [ 43 ] . transducer [ 0 ] .
positionFlag , "Undefined" ) ; _dline -> compilerData -> block [ 43 ] .
transducer [ 0 ] . velocityFlag = ( char * ) ( _table -> UINT8_table + 5591 )
; strcpy ( _dline -> compilerData -> block [ 43 ] . transducer [ 0 ] .
velocityFlag , "Undefined" ) ; _dline -> compilerData -> block [ 43 ] .
transducer [ 0 ] . accelerationFlag = ( char * ) ( _table -> UINT8_table +
5601 ) ; strcpy ( _dline -> compilerData -> block [ 43 ] . transducer [ 0 ] .
accelerationFlag , "Undefined" ) ; _dline -> compilerData -> block [ 43 ] .
transducer [ 0 ] . signal = _table -> DriveSignal_table + 31 ; _dline ->
compilerData -> block [ 43 ] . transducer [ 0 ] . signal [ 0 ] . type =
DRIVEEXTERNALTORQUE ; _dline -> compilerData -> block [ 43 ] . transducer [ 0
] . signal [ 0 ] . flag = ( char * ) ( _table -> UINT8_table + 5611 ) ;
strcpy ( _dline -> compilerData -> block [ 43 ] . transducer [ 0 ] . signal [
0 ] . flag , "drive_92f5eb85Tor" ) ; _dline -> compilerData -> block [ 44 ] .
numFlanges = 1 ; _dline -> compilerData -> block [ 44 ] . numTransducer = 1 ;
_dline -> compilerData -> block [ 44 ] . name = ( char * ) ( _table ->
UINT8_table + 5629 ) ; strcpy ( _dline -> compilerData -> block [ 44 ] . name
, "HEV/Engine Controller/Motion Sensor/Transducer" ) ; _dline -> compilerData
-> block [ 44 ] . visibleName = ( char * ) ( _table -> UINT8_table + 5676 ) ;
strcpy ( _dline -> compilerData -> block [ 44 ] . visibleName ,
"HEV/Engine Controller/Motion Sensor" ) ; _dline -> compilerData -> block [
44 ] . type = DRIVETRANSDUCER ; _dline -> compilerData -> block [ 44 ] .
flange = _table -> INT32_table + 61 ; _dline -> compilerData -> block [ 44 ]
. transducer = _table -> DriveTransducer_table + 20 ; _dline -> compilerData
-> block [ 44 ] . transducer [ 0 ] . numSignals = 2 ; _dline -> compilerData
-> block [ 44 ] . transducer [ 0 ] . positionFlag = ( char * ) ( _table ->
UINT8_table + 5712 ) ; strcpy ( _dline -> compilerData -> block [ 44 ] .
transducer [ 0 ] . positionFlag , "Undefined" ) ; _dline -> compilerData ->
block [ 44 ] . transducer [ 0 ] . velocityFlag = ( char * ) ( _table ->
UINT8_table + 5722 ) ; strcpy ( _dline -> compilerData -> block [ 44 ] .
transducer [ 0 ] . velocityFlag , "Undefined" ) ; _dline -> compilerData ->
block [ 44 ] . transducer [ 0 ] . accelerationFlag = ( char * ) ( _table ->
UINT8_table + 5732 ) ; strcpy ( _dline -> compilerData -> block [ 44 ] .
transducer [ 0 ] . accelerationFlag , "Undefined" ) ; _dline -> compilerData
-> block [ 44 ] . transducer [ 0 ] . signal = _table -> DriveSignal_table +
32 ; _dline -> compilerData -> block [ 44 ] . transducer [ 0 ] . signal [ 0 ]
. type = DRIVEVELOCITY ; _dline -> compilerData -> block [ 44 ] . transducer
[ 0 ] . signal [ 0 ] . flag = ( char * ) ( _table -> UINT8_table + 5742 ) ;
strcpy ( _dline -> compilerData -> block [ 44 ] . transducer [ 0 ] . signal [
0 ] . flag , "drive_a16c2233Velocity" ) ; _dline -> compilerData -> block [
44 ] . transducer [ 0 ] . signal [ 1 ] . type = DRIVEACCELERATION ; _dline ->
compilerData -> block [ 44 ] . transducer [ 0 ] . signal [ 1 ] . flag = (
char * ) ( _table -> UINT8_table + 5765 ) ; strcpy ( _dline -> compilerData
-> block [ 44 ] . transducer [ 0 ] . signal [ 1 ] . flag ,
"drive_a16c2233Acceleration" ) ; _dline -> compilerData -> block [ 45 ] .
numFlanges = 1 ; _dline -> compilerData -> block [ 45 ] . numTransducer = 1 ;
_dline -> compilerData -> block [ 45 ] . name = ( char * ) ( _table ->
UINT8_table + 5792 ) ; strcpy ( _dline -> compilerData -> block [ 45 ] . name
, "HEV/Engine Controller/Torsional \\\\nSpring-Damper/base_torque/Transducer"
) ; _dline -> compilerData -> block [ 45 ] . visibleName = ( char * ) (
_table -> UINT8_table + 5862 ) ; strcpy ( _dline -> compilerData -> block [
45 ] . visibleName , "HEV/Engine Controller/Torsional \\\\nSpring-Damper" ) ;
_dline -> compilerData -> block [ 45 ] . type = DRIVETRANSDUCER ; _dline ->
compilerData -> block [ 45 ] . flange = _table -> INT32_table + 62 ; _dline
-> compilerData -> block [ 45 ] . transducer = _table ->
DriveTransducer_table + 21 ; _dline -> compilerData -> block [ 45 ] .
transducer [ 0 ] . numSignals = 1 ; _dline -> compilerData -> block [ 45 ] .
transducer [ 0 ] . positionFlag = ( char * ) ( _table -> UINT8_table + 5909 )
; strcpy ( _dline -> compilerData -> block [ 45 ] . transducer [ 0 ] .
positionFlag , "Undefined" ) ; _dline -> compilerData -> block [ 45 ] .
transducer [ 0 ] . velocityFlag = ( char * ) ( _table -> UINT8_table + 5919 )
; strcpy ( _dline -> compilerData -> block [ 45 ] . transducer [ 0 ] .
velocityFlag , "Undefined" ) ; _dline -> compilerData -> block [ 45 ] .
transducer [ 0 ] . accelerationFlag = ( char * ) ( _table -> UINT8_table +
5929 ) ; strcpy ( _dline -> compilerData -> block [ 45 ] . transducer [ 0 ] .
accelerationFlag , "Undefined" ) ; _dline -> compilerData -> block [ 45 ] .
transducer [ 0 ] . signal = _table -> DriveSignal_table + 34 ; _dline ->
compilerData -> block [ 45 ] . transducer [ 0 ] . signal [ 0 ] . type =
DRIVEEXTERNALTORQUE ; _dline -> compilerData -> block [ 45 ] . transducer [ 0
] . signal [ 0 ] . flag = ( char * ) ( _table -> UINT8_table + 5939 ) ;
strcpy ( _dline -> compilerData -> block [ 45 ] . transducer [ 0 ] . signal [
0 ] . flag , "drive_ce701f87Tor" ) ; _dline -> compilerData -> block [ 46 ] .
numFlanges = 1 ; _dline -> compilerData -> block [ 46 ] . numTransducer = 1 ;
_dline -> compilerData -> block [ 46 ] . name = ( char * ) ( _table ->
UINT8_table + 5957 ) ; strcpy ( _dline -> compilerData -> block [ 46 ] . name
,
"HEV/Engine Controller/Torsional \\\\nSpring-Damper/base_velocity/Transducer"
) ; _dline -> compilerData -> block [ 46 ] . visibleName = ( char * ) (
_table -> UINT8_table + 6029 ) ; strcpy ( _dline -> compilerData -> block [
46 ] . visibleName , "HEV/Engine Controller/Torsional \\\\nSpring-Damper" ) ;
_dline -> compilerData -> block [ 46 ] . type = DRIVETRANSDUCER ; _dline ->
compilerData -> block [ 46 ] . flange = _table -> INT32_table + 63 ; _dline
-> compilerData -> block [ 46 ] . transducer = _table ->
DriveTransducer_table + 22 ; _dline -> compilerData -> block [ 46 ] .
transducer [ 0 ] . numSignals = 2 ; _dline -> compilerData -> block [ 46 ] .
transducer [ 0 ] . positionFlag = ( char * ) ( _table -> UINT8_table + 6076 )
; strcpy ( _dline -> compilerData -> block [ 46 ] . transducer [ 0 ] .
positionFlag , "Undefined" ) ; _dline -> compilerData -> block [ 46 ] .
transducer [ 0 ] . velocityFlag = ( char * ) ( _table -> UINT8_table + 6086 )
; strcpy ( _dline -> compilerData -> block [ 46 ] . transducer [ 0 ] .
velocityFlag , "Undefined" ) ; _dline -> compilerData -> block [ 46 ] .
transducer [ 0 ] . accelerationFlag = ( char * ) ( _table -> UINT8_table +
6096 ) ; strcpy ( _dline -> compilerData -> block [ 46 ] . transducer [ 0 ] .
accelerationFlag , "Undefined" ) ; _dline -> compilerData -> block [ 46 ] .
transducer [ 0 ] . signal = _table -> DriveSignal_table + 35 ; _dline ->
compilerData -> block [ 46 ] . transducer [ 0 ] . signal [ 0 ] . type =
DRIVEVELOCITY ; _dline -> compilerData -> block [ 46 ] . transducer [ 0 ] .
signal [ 0 ] . flag = ( char * ) ( _table -> UINT8_table + 6106 ) ; strcpy (
_dline -> compilerData -> block [ 46 ] . transducer [ 0 ] . signal [ 0 ] .
flag , "drive_5ac4c50Velocity" ) ; _dline -> compilerData -> block [ 46 ] .
transducer [ 0 ] . signal [ 1 ] . type = DRIVEACCELERATION ; _dline ->
compilerData -> block [ 46 ] . transducer [ 0 ] . signal [ 1 ] . flag = (
char * ) ( _table -> UINT8_table + 6128 ) ; strcpy ( _dline -> compilerData
-> block [ 46 ] . transducer [ 0 ] . signal [ 1 ] . flag ,
"drive_5ac4c50Acceleration" ) ; _dline -> compilerData -> ioSizes .
numDynamicInputs = 9 ; _dline -> compilerData -> ioSizes . numDynamicOutputs
= 20 ; _dline -> compilerData -> ioSizes . numKinematicOutputs = 14 ; _dline
-> compilerData -> ioSizes . numRtParameters = 17 ; _dline -> compilerData ->
name = ( char * ) ( _table -> UINT8_table + 6154 ) ; strcpy ( _dline ->
compilerData -> name , "HEV/Engine Controller/Driveline\\\\nEnvironment" ) ;
_dline -> compilerData -> mdlHandle = 3.0001220703125 ; return _dline ; }
