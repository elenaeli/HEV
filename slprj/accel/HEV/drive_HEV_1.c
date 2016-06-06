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
. solver [ 0 ] . defaultClutchVelocityTolerance = 0.001 ; _dline ->
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
2 ; _dline -> compilerData -> block [ 11 ] . numStrainGauge = 1 ; _dline ->
compilerData -> block [ 11 ] . name = ( char * ) ( _table -> UINT8_table +
1265 ) ; strcpy ( _dline -> compilerData -> block [ 11 ] . name ,
"HEV/Vehicle/Torque Sensor/Torque Sensor\\\\nInternal" ) ; _dline ->
compilerData -> block [ 11 ] . visibleName = ( char * ) ( _table ->
UINT8_table + 1314 ) ; strcpy ( _dline -> compilerData -> block [ 11 ] .
visibleName , "HEV/Vehicle/Torque Sensor" ) ; _dline -> compilerData -> block
[ 11 ] . type = DRIVESTRAINGAUGE ; _dline -> compilerData -> block [ 11 ] .
flange = _table -> INT32_table + 17 ; _dline -> compilerData -> block [ 11 ]
. flange [ 0 ] = 6 ; _dline -> compilerData -> block [ 11 ] . flange [ 1 ] =
7 ; _dline -> compilerData -> block [ 11 ] . strainGauge = _table ->
DriveStrainGauge_table + 3 ; _dline -> compilerData -> block [ 11 ] .
strainGauge [ 0 ] . measurementFlange = 1 ; _dline -> compilerData -> block [
11 ] . strainGauge [ 0 ] . flag = ( char * ) ( _table -> UINT8_table + 1340 )
; strcpy ( _dline -> compilerData -> block [ 11 ] . strainGauge [ 0 ] . flag
, "drive_3a0f24a5" ) ; _dline -> compilerData -> block [ 12 ] . name = ( char
* ) ( _table -> UINT8_table + 1355 ) ; strcpy ( _dline -> compilerData ->
block [ 12 ] . name ,
 "HEV/Vehicle/Torsional \\\\nSpring-Damper \\\\n(Friction)/Free/Shared\\\\nEnvironment\\\\nInternal"
) ; _dline -> compilerData -> block [ 12 ] . visibleName = ( char * ) (
_table -> UINT8_table + 1437 ) ; strcpy ( _dline -> compilerData -> block [
12 ] . visibleName ,
"HEV/Vehicle/Torsional \\\\nSpring-Damper \\\\n(Friction)" ) ; _dline ->
compilerData -> block [ 12 ] . type = DRIVEFREEGEAR ; _dline -> compilerData
-> block [ 13 ] . numFlanges = 1 ; _dline -> compilerData -> block [ 13 ] .
numTransducer = 1 ; _dline -> compilerData -> block [ 13 ] . name = ( char *
) ( _table -> UINT8_table + 1486 ) ; strcpy ( _dline -> compilerData -> block
[ 13 ] . name ,
 "HEV/Vehicle/Torsional \\\\nSpring-Damper \\\\n(Friction)/base_torque/Transducer"
) ; _dline -> compilerData -> block [ 13 ] . visibleName = ( char * ) (
_table -> UINT8_table + 1558 ) ; strcpy ( _dline -> compilerData -> block [
13 ] . visibleName ,
"HEV/Vehicle/Torsional \\\\nSpring-Damper \\\\n(Friction)" ) ; _dline ->
compilerData -> block [ 13 ] . type = DRIVETRANSDUCER ; _dline ->
compilerData -> block [ 13 ] . flange = _table -> INT32_table + 19 ; _dline
-> compilerData -> block [ 13 ] . flange [ 0 ] = 8 ; _dline -> compilerData
-> block [ 13 ] . transducer = _table -> DriveTransducer_table + 2 ; _dline
-> compilerData -> block [ 13 ] . transducer [ 0 ] . numSignals = 1 ; _dline
-> compilerData -> block [ 13 ] . transducer [ 0 ] . positionFlag = ( char *
) ( _table -> UINT8_table + 1607 ) ; strcpy ( _dline -> compilerData -> block
[ 13 ] . transducer [ 0 ] . positionFlag , "Undefined" ) ; _dline ->
compilerData -> block [ 13 ] . transducer [ 0 ] . velocityFlag = ( char * ) (
_table -> UINT8_table + 1617 ) ; strcpy ( _dline -> compilerData -> block [
13 ] . transducer [ 0 ] . velocityFlag , "Undefined" ) ; _dline ->
compilerData -> block [ 13 ] . transducer [ 0 ] . accelerationFlag = ( char *
) ( _table -> UINT8_table + 1627 ) ; strcpy ( _dline -> compilerData -> block
[ 13 ] . transducer [ 0 ] . accelerationFlag , "Undefined" ) ; _dline ->
compilerData -> block [ 13 ] . transducer [ 0 ] . signal = _table ->
DriveSignal_table + 3 ; _dline -> compilerData -> block [ 13 ] . transducer [
0 ] . signal [ 0 ] . type = DRIVEEXTERNALTORQUE ; _dline -> compilerData ->
block [ 13 ] . transducer [ 0 ] . signal [ 0 ] . flag = ( char * ) ( _table
-> UINT8_table + 1637 ) ; strcpy ( _dline -> compilerData -> block [ 13 ] .
transducer [ 0 ] . signal [ 0 ] . flag , "drive_cdf4ee1bTor" ) ; _dline ->
compilerData -> block [ 14 ] . numFlanges = 1 ; _dline -> compilerData ->
block [ 14 ] . numTransducer = 1 ; _dline -> compilerData -> block [ 14 ] .
name = ( char * ) ( _table -> UINT8_table + 1655 ) ; strcpy ( _dline ->
compilerData -> block [ 14 ] . name ,
 "HEV/Vehicle/Torsional \\\\nSpring-Damper \\\\n(Friction)/base_velocity/Transducer"
) ; _dline -> compilerData -> block [ 14 ] . visibleName = ( char * ) (
_table -> UINT8_table + 1729 ) ; strcpy ( _dline -> compilerData -> block [
14 ] . visibleName ,
"HEV/Vehicle/Torsional \\\\nSpring-Damper \\\\n(Friction)" ) ; _dline ->
compilerData -> block [ 14 ] . type = DRIVETRANSDUCER ; _dline ->
compilerData -> block [ 14 ] . flange = _table -> INT32_table + 20 ; _dline
-> compilerData -> block [ 14 ] . flange [ 0 ] = 8 ; _dline -> compilerData
-> block [ 14 ] . transducer = _table -> DriveTransducer_table + 3 ; _dline
-> compilerData -> block [ 14 ] . transducer [ 0 ] . numSignals = 2 ; _dline
-> compilerData -> block [ 14 ] . transducer [ 0 ] . positionFlag = ( char *
) ( _table -> UINT8_table + 1778 ) ; strcpy ( _dline -> compilerData -> block
[ 14 ] . transducer [ 0 ] . positionFlag , "Undefined" ) ; _dline ->
compilerData -> block [ 14 ] . transducer [ 0 ] . velocityFlag = ( char * ) (
_table -> UINT8_table + 1788 ) ; strcpy ( _dline -> compilerData -> block [
14 ] . transducer [ 0 ] . velocityFlag , "Undefined" ) ; _dline ->
compilerData -> block [ 14 ] . transducer [ 0 ] . accelerationFlag = ( char *
) ( _table -> UINT8_table + 1798 ) ; strcpy ( _dline -> compilerData -> block
[ 14 ] . transducer [ 0 ] . accelerationFlag , "Undefined" ) ; _dline ->
compilerData -> block [ 14 ] . transducer [ 0 ] . signal = _table ->
DriveSignal_table + 4 ; _dline -> compilerData -> block [ 14 ] . transducer [
0 ] . signal [ 0 ] . type = DRIVEVELOCITY ; _dline -> compilerData -> block [
14 ] . transducer [ 0 ] . signal [ 0 ] . flag = ( char * ) ( _table ->
UINT8_table + 1808 ) ; strcpy ( _dline -> compilerData -> block [ 14 ] .
transducer [ 0 ] . signal [ 0 ] . flag , "drive_80da075eVelocity" ) ; _dline
-> compilerData -> block [ 14 ] . transducer [ 0 ] . signal [ 1 ] . type =
DRIVEACCELERATION ; _dline -> compilerData -> block [ 14 ] . transducer [ 0 ]
. signal [ 1 ] . flag = ( char * ) ( _table -> UINT8_table + 1831 ) ; strcpy
( _dline -> compilerData -> block [ 14 ] . transducer [ 0 ] . signal [ 1 ] .
flag , "drive_80da075eAcceleration" ) ; _dline -> compilerData -> block [ 15
] . numFlanges = 1 ; _dline -> compilerData -> block [ 15 ] . numWeld = 1 ;
_dline -> compilerData -> block [ 15 ] . name = ( char * ) ( _table ->
UINT8_table + 1858 ) ; strcpy ( _dline -> compilerData -> block [ 15 ] . name
, "HEV/Vehicle/Housing/Housing\\\\nInternal" ) ; _dline -> compilerData ->
block [ 15 ] . visibleName = ( char * ) ( _table -> UINT8_table + 1895 ) ;
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
[ 0 ] . flag = ( char * ) ( _table -> UINT8_table + 1915 ) ; strcpy ( _dline
-> compilerData -> block [ 16 ] . parameter [ 0 ] . flag ,
"drive_72945f1GearRatio" ) ; _dline -> compilerData -> block [ 16 ] .
numSimpleGear = 1 ; _dline -> compilerData -> block [ 16 ] . name = ( char *
) ( _table -> UINT8_table + 1938 ) ; strcpy ( _dline -> compilerData -> block
[ 16 ] . name , "HEV/Vehicle/Simple Gear" ) ; _dline -> compilerData -> block
[ 16 ] . visibleName = ( char * ) ( _table -> UINT8_table + 1962 ) ; strcpy (
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
( _table -> UINT8_table + 1986 ) ; strcpy ( _dline -> compilerData -> block [
17 ] . parameter [ 0 ] . flag , "drive_f8a0f554Inertia" ) ; _dline ->
compilerData -> block [ 17 ] . parameter [ 1 ] . type =
DRIVERTP_INITIALCONDITION ; _dline -> compilerData -> block [ 17 ] .
parameter [ 1 ] . flag = ( char * ) ( _table -> UINT8_table + 2008 ) ; strcpy
( _dline -> compilerData -> block [ 17 ] . parameter [ 1 ] . flag ,
"drive_f8a0f554InitialCondition" ) ; _dline -> compilerData -> block [ 17 ] .
numInertia = 1 ; _dline -> compilerData -> block [ 17 ] . name = ( char * ) (
_table -> UINT8_table + 2039 ) ; strcpy ( _dline -> compilerData -> block [
17 ] . name , "HEV/Vehicle/Transmission \\\\nInertia" ) ; _dline ->
compilerData -> block [ 17 ] . visibleName = ( char * ) ( _table ->
UINT8_table + 2073 ) ; strcpy ( _dline -> compilerData -> block [ 17 ] .
visibleName , "HEV/Vehicle/Transmission \\\\nInertia" ) ; _dline ->
compilerData -> block [ 17 ] . type = DRIVEINERTIA ; _dline -> compilerData
-> block [ 17 ] . flange = _table -> INT32_table + 24 ; _dline ->
compilerData -> block [ 17 ] . flange [ 0 ] = 9 ; _dline -> compilerData ->
block [ 17 ] . inertia = _table -> DriveInertia_table + 1 ; _dline ->
compilerData -> block [ 17 ] . inertia [ 0 ] . inertia = 0.5 ; _dline ->
compilerData -> block [ 18 ] . numFlanges = 2 ; _dline -> compilerData ->
block [ 18 ] . numParameters = 1 ; _dline -> compilerData -> block [ 18 ] .
parameter = _table -> DriveParameter_table + 7 ; _dline -> compilerData ->
block [ 18 ] . parameter [ 0 ] . type = DRIVERTP_SIMPLEGEARRATIO ; _dline ->
compilerData -> block [ 18 ] . parameter [ 0 ] . flag = ( char * ) ( _table
-> UINT8_table + 2107 ) ; strcpy ( _dline -> compilerData -> block [ 18 ] .
parameter [ 0 ] . flag , "drive_f09289b7GearRatio" ) ; _dline -> compilerData
-> block [ 18 ] . numSimpleGear = 1 ; _dline -> compilerData -> block [ 18 ]
. name = ( char * ) ( _table -> UINT8_table + 2131 ) ; strcpy ( _dline ->
compilerData -> block [ 18 ] . name , "HEV/Vehicle/Differential/Simple Gear1"
) ; _dline -> compilerData -> block [ 18 ] . visibleName = ( char * ) (
_table -> UINT8_table + 2169 ) ; strcpy ( _dline -> compilerData -> block [
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
2194 ) ; strcpy ( _dline -> compilerData -> block [ 19 ] . parameter [ 0 ] .
flag , "drive_48b6a0f1PlanetPlanetRatio" ) ; _dline -> compilerData -> block
[ 19 ] . numPlanetPlanet = 1 ; _dline -> compilerData -> block [ 19 ] . name
= ( char * ) ( _table -> UINT8_table + 2226 ) ; strcpy ( _dline ->
compilerData -> block [ 19 ] . name ,
"HEV/Vehicle/Differential/Planet-Planet" ) ; _dline -> compilerData -> block
[ 19 ] . visibleName = ( char * ) ( _table -> UINT8_table + 2265 ) ; strcpy (
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
20 ] . parameter [ 0 ] . flag = ( char * ) ( _table -> UINT8_table + 2290 ) ;
strcpy ( _dline -> compilerData -> block [ 20 ] . parameter [ 0 ] . flag ,
"drive_c8840e85GearRatio" ) ; _dline -> compilerData -> block [ 20 ] .
numSimpleGear = 1 ; _dline -> compilerData -> block [ 20 ] . name = ( char *
) ( _table -> UINT8_table + 2314 ) ; strcpy ( _dline -> compilerData -> block
[ 20 ] . name , "HEV/Vehicle/Differential/Simple Gear" ) ; _dline ->
compilerData -> block [ 20 ] . visibleName = ( char * ) ( _table ->
UINT8_table + 2351 ) ; strcpy ( _dline -> compilerData -> block [ 20 ] .
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
-> UINT8_table + 2376 ) ; strcpy ( _dline -> compilerData -> block [ 21 ] .
parameter [ 0 ] . flag , "drive_8aaf3b98PlanetPlanetRatio" ) ; _dline ->
compilerData -> block [ 21 ] . numPlanetPlanet = 1 ; _dline -> compilerData
-> block [ 21 ] . name = ( char * ) ( _table -> UINT8_table + 2408 ) ; strcpy
( _dline -> compilerData -> block [ 21 ] . name ,
"HEV/Vehicle/Differential/Planet-Planet1" ) ; _dline -> compilerData -> block
[ 21 ] . visibleName = ( char * ) ( _table -> UINT8_table + 2448 ) ; strcpy (
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
2473 ) ; strcpy ( _dline -> compilerData -> block [ 22 ] . parameter [ 0 ] .
flag , "drive_699bd80dGearRatio" ) ; _dline -> compilerData -> block [ 22 ] .
numSimpleGear = 1 ; _dline -> compilerData -> block [ 22 ] . name = ( char *
) ( _table -> UINT8_table + 2497 ) ; strcpy ( _dline -> compilerData -> block
[ 22 ] . name , "HEV/Vehicle/Differential/Simple Gear2" ) ; _dline ->
compilerData -> block [ 22 ] . visibleName = ( char * ) ( _table ->
UINT8_table + 2535 ) ; strcpy ( _dline -> compilerData -> block [ 22 ] .
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
23 ] . parameter [ 0 ] . flag = ( char * ) ( _table -> UINT8_table + 2560 ) ;
strcpy ( _dline -> compilerData -> block [ 23 ] . parameter [ 0 ] . flag ,
"drive_66b082ddInertia" ) ; _dline -> compilerData -> block [ 23 ] .
parameter [ 1 ] . type = DRIVERTP_INITIALCONDITION ; _dline -> compilerData
-> block [ 23 ] . parameter [ 1 ] . flag = ( char * ) ( _table -> UINT8_table
+ 2582 ) ; strcpy ( _dline -> compilerData -> block [ 23 ] . parameter [ 1 ]
. flag , "drive_66b082ddInitialCondition" ) ; _dline -> compilerData -> block
[ 23 ] . numInertia = 1 ; _dline -> compilerData -> block [ 23 ] . name = (
char * ) ( _table -> UINT8_table + 2613 ) ; strcpy ( _dline -> compilerData
-> block [ 23 ] . name , "HEV/Vehicle/Right Tire Inertia" ) ; _dline ->
compilerData -> block [ 23 ] . visibleName = ( char * ) ( _table ->
UINT8_table + 2644 ) ; strcpy ( _dline -> compilerData -> block [ 23 ] .
visibleName , "HEV/Vehicle/Right Tire Inertia" ) ; _dline -> compilerData ->
block [ 23 ] . type = DRIVEINERTIA ; _dline -> compilerData -> block [ 23 ] .
flange = _table -> INT32_table + 37 ; _dline -> compilerData -> block [ 23 ]
. flange [ 0 ] = 14 ; _dline -> compilerData -> block [ 23 ] . inertia =
_table -> DriveInertia_table + 2 ; _dline -> compilerData -> block [ 23 ] .
inertia [ 0 ] . inertia = 0.5 ; _dline -> compilerData -> block [ 24 ] .
numFlanges = 1 ; _dline -> compilerData -> block [ 24 ] . numTransducer = 1 ;
_dline -> compilerData -> block [ 24 ] . name = ( char * ) ( _table ->
UINT8_table + 2675 ) ; strcpy ( _dline -> compilerData -> block [ 24 ] . name
, "HEV/Vehicle/Right Tire/Wheel dynamics/Motion Sensor/Transducer" ) ; _dline
-> compilerData -> block [ 24 ] . visibleName = ( char * ) ( _table ->
UINT8_table + 2738 ) ; strcpy ( _dline -> compilerData -> block [ 24 ] .
visibleName , "HEV/Vehicle/Right Tire" ) ; _dline -> compilerData -> block [
24 ] . type = DRIVETRANSDUCER ; _dline -> compilerData -> block [ 24 ] .
flange = _table -> INT32_table + 38 ; _dline -> compilerData -> block [ 24 ]
. flange [ 0 ] = 14 ; _dline -> compilerData -> block [ 24 ] . transducer =
_table -> DriveTransducer_table + 4 ; _dline -> compilerData -> block [ 24 ]
. transducer [ 0 ] . numSignals = 2 ; _dline -> compilerData -> block [ 24 ]
. transducer [ 0 ] . positionFlag = ( char * ) ( _table -> UINT8_table + 2761
) ; strcpy ( _dline -> compilerData -> block [ 24 ] . transducer [ 0 ] .
positionFlag , "Undefined" ) ; _dline -> compilerData -> block [ 24 ] .
transducer [ 0 ] . velocityFlag = ( char * ) ( _table -> UINT8_table + 2771 )
; strcpy ( _dline -> compilerData -> block [ 24 ] . transducer [ 0 ] .
velocityFlag , "Undefined" ) ; _dline -> compilerData -> block [ 24 ] .
transducer [ 0 ] . accelerationFlag = ( char * ) ( _table -> UINT8_table +
2781 ) ; strcpy ( _dline -> compilerData -> block [ 24 ] . transducer [ 0 ] .
accelerationFlag , "Undefined" ) ; _dline -> compilerData -> block [ 24 ] .
transducer [ 0 ] . signal = _table -> DriveSignal_table + 6 ; _dline ->
compilerData -> block [ 24 ] . transducer [ 0 ] . signal [ 0 ] . type =
DRIVEVELOCITY ; _dline -> compilerData -> block [ 24 ] . transducer [ 0 ] .
signal [ 0 ] . flag = ( char * ) ( _table -> UINT8_table + 2791 ) ; strcpy (
_dline -> compilerData -> block [ 24 ] . transducer [ 0 ] . signal [ 0 ] .
flag , "drive_41d49eb1Velocity" ) ; _dline -> compilerData -> block [ 24 ] .
transducer [ 0 ] . signal [ 1 ] . type = DRIVEACCELERATION ; _dline ->
compilerData -> block [ 24 ] . transducer [ 0 ] . signal [ 1 ] . flag = (
char * ) ( _table -> UINT8_table + 2814 ) ; strcpy ( _dline -> compilerData
-> block [ 24 ] . transducer [ 0 ] . signal [ 1 ] . flag ,
"drive_41d49eb1Acceleration" ) ; _dline -> compilerData -> block [ 25 ] .
numFlanges = 1 ; _dline -> compilerData -> block [ 25 ] . numTransducer = 1 ;
_dline -> compilerData -> block [ 25 ] . name = ( char * ) ( _table ->
UINT8_table + 2841 ) ; strcpy ( _dline -> compilerData -> block [ 25 ] . name
, "HEV/Vehicle/Right Tire/Wheel dynamics/Torque Actuator/Transducer" ) ;
_dline -> compilerData -> block [ 25 ] . visibleName = ( char * ) ( _table ->
UINT8_table + 2906 ) ; strcpy ( _dline -> compilerData -> block [ 25 ] .
visibleName , "HEV/Vehicle/Right Tire" ) ; _dline -> compilerData -> block [
25 ] . type = DRIVETRANSDUCER ; _dline -> compilerData -> block [ 25 ] .
flange = _table -> INT32_table + 39 ; _dline -> compilerData -> block [ 25 ]
. flange [ 0 ] = 14 ; _dline -> compilerData -> block [ 25 ] . transducer =
_table -> DriveTransducer_table + 5 ; _dline -> compilerData -> block [ 25 ]
. transducer [ 0 ] . numSignals = 1 ; _dline -> compilerData -> block [ 25 ]
. transducer [ 0 ] . positionFlag = ( char * ) ( _table -> UINT8_table + 2929
) ; strcpy ( _dline -> compilerData -> block [ 25 ] . transducer [ 0 ] .
positionFlag , "Undefined" ) ; _dline -> compilerData -> block [ 25 ] .
transducer [ 0 ] . velocityFlag = ( char * ) ( _table -> UINT8_table + 2939 )
; strcpy ( _dline -> compilerData -> block [ 25 ] . transducer [ 0 ] .
velocityFlag , "Undefined" ) ; _dline -> compilerData -> block [ 25 ] .
transducer [ 0 ] . accelerationFlag = ( char * ) ( _table -> UINT8_table +
2949 ) ; strcpy ( _dline -> compilerData -> block [ 25 ] . transducer [ 0 ] .
accelerationFlag , "Undefined" ) ; _dline -> compilerData -> block [ 25 ] .
transducer [ 0 ] . signal = _table -> DriveSignal_table + 8 ; _dline ->
compilerData -> block [ 25 ] . transducer [ 0 ] . signal [ 0 ] . type =
DRIVEEXTERNALTORQUE ; _dline -> compilerData -> block [ 25 ] . transducer [ 0
] . signal [ 0 ] . flag = ( char * ) ( _table -> UINT8_table + 2959 ) ;
strcpy ( _dline -> compilerData -> block [ 25 ] . transducer [ 0 ] . signal [
0 ] . flag , "drive_ebfa3480Tor" ) ; _dline -> compilerData -> block [ 26 ] .
numFlanges = 2 ; _dline -> compilerData -> block [ 26 ] . numParameters = 1 ;
_dline -> compilerData -> block [ 26 ] . parameter = _table ->
DriveParameter_table + 14 ; _dline -> compilerData -> block [ 26 ] .
parameter [ 0 ] . type = DRIVERTP_SIMPLEGEARRATIO ; _dline -> compilerData ->
block [ 26 ] . parameter [ 0 ] . flag = ( char * ) ( _table -> UINT8_table +
2977 ) ; strcpy ( _dline -> compilerData -> block [ 26 ] . parameter [ 0 ] .
flag , "drive_1e9ce89bGearRatio" ) ; _dline -> compilerData -> block [ 26 ] .
numSimpleGear = 1 ; _dline -> compilerData -> block [ 26 ] . name = ( char *
) ( _table -> UINT8_table + 3001 ) ; strcpy ( _dline -> compilerData -> block
[ 26 ] . name , "HEV/Vehicle/Differential/Simple Gear3" ) ; _dline ->
compilerData -> block [ 26 ] . visibleName = ( char * ) ( _table ->
UINT8_table + 3039 ) ; strcpy ( _dline -> compilerData -> block [ 26 ] .
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
27 ] . parameter [ 0 ] . flag = ( char * ) ( _table -> UINT8_table + 3064 ) ;
strcpy ( _dline -> compilerData -> block [ 27 ] . parameter [ 0 ] . flag ,
"drive_80d28a58Inertia" ) ; _dline -> compilerData -> block [ 27 ] .
parameter [ 1 ] . type = DRIVERTP_INITIALCONDITION ; _dline -> compilerData
-> block [ 27 ] . parameter [ 1 ] . flag = ( char * ) ( _table -> UINT8_table
+ 3086 ) ; strcpy ( _dline -> compilerData -> block [ 27 ] . parameter [ 1 ]
. flag , "drive_80d28a58InitialCondition" ) ; _dline -> compilerData -> block
[ 27 ] . numInertia = 1 ; _dline -> compilerData -> block [ 27 ] . name = (
char * ) ( _table -> UINT8_table + 3117 ) ; strcpy ( _dline -> compilerData
-> block [ 27 ] . name , "HEV/Vehicle/Left Tire Inertia" ) ; _dline ->
compilerData -> block [ 27 ] . visibleName = ( char * ) ( _table ->
UINT8_table + 3147 ) ; strcpy ( _dline -> compilerData -> block [ 27 ] .
visibleName , "HEV/Vehicle/Left Tire Inertia" ) ; _dline -> compilerData ->
block [ 27 ] . type = DRIVEINERTIA ; _dline -> compilerData -> block [ 27 ] .
flange = _table -> INT32_table + 42 ; _dline -> compilerData -> block [ 27 ]
. flange [ 0 ] = 16 ; _dline -> compilerData -> block [ 27 ] . inertia =
_table -> DriveInertia_table + 3 ; _dline -> compilerData -> block [ 27 ] .
inertia [ 0 ] . inertia = 0.5 ; _dline -> compilerData -> block [ 28 ] .
numFlanges = 1 ; _dline -> compilerData -> block [ 28 ] . numTransducer = 1 ;
_dline -> compilerData -> block [ 28 ] . name = ( char * ) ( _table ->
UINT8_table + 3177 ) ; strcpy ( _dline -> compilerData -> block [ 28 ] . name
, "HEV/Vehicle/Left Tire/Wheel dynamics/Motion Sensor/Transducer" ) ; _dline
-> compilerData -> block [ 28 ] . visibleName = ( char * ) ( _table ->
UINT8_table + 3239 ) ; strcpy ( _dline -> compilerData -> block [ 28 ] .
visibleName , "HEV/Vehicle/Left Tire" ) ; _dline -> compilerData -> block [
28 ] . type = DRIVETRANSDUCER ; _dline -> compilerData -> block [ 28 ] .
flange = _table -> INT32_table + 43 ; _dline -> compilerData -> block [ 28 ]
. flange [ 0 ] = 16 ; _dline -> compilerData -> block [ 28 ] . transducer =
_table -> DriveTransducer_table + 6 ; _dline -> compilerData -> block [ 28 ]
. transducer [ 0 ] . numSignals = 2 ; _dline -> compilerData -> block [ 28 ]
. transducer [ 0 ] . positionFlag = ( char * ) ( _table -> UINT8_table + 3261
) ; strcpy ( _dline -> compilerData -> block [ 28 ] . transducer [ 0 ] .
positionFlag , "Undefined" ) ; _dline -> compilerData -> block [ 28 ] .
transducer [ 0 ] . velocityFlag = ( char * ) ( _table -> UINT8_table + 3271 )
; strcpy ( _dline -> compilerData -> block [ 28 ] . transducer [ 0 ] .
velocityFlag , "Undefined" ) ; _dline -> compilerData -> block [ 28 ] .
transducer [ 0 ] . accelerationFlag = ( char * ) ( _table -> UINT8_table +
3281 ) ; strcpy ( _dline -> compilerData -> block [ 28 ] . transducer [ 0 ] .
accelerationFlag , "Undefined" ) ; _dline -> compilerData -> block [ 28 ] .
transducer [ 0 ] . signal = _table -> DriveSignal_table + 9 ; _dline ->
compilerData -> block [ 28 ] . transducer [ 0 ] . signal [ 0 ] . type =
DRIVEVELOCITY ; _dline -> compilerData -> block [ 28 ] . transducer [ 0 ] .
signal [ 0 ] . flag = ( char * ) ( _table -> UINT8_table + 3291 ) ; strcpy (
_dline -> compilerData -> block [ 28 ] . transducer [ 0 ] . signal [ 0 ] .
flag , "drive_8c9aa461Velocity" ) ; _dline -> compilerData -> block [ 28 ] .
transducer [ 0 ] . signal [ 1 ] . type = DRIVEACCELERATION ; _dline ->
compilerData -> block [ 28 ] . transducer [ 0 ] . signal [ 1 ] . flag = (
char * ) ( _table -> UINT8_table + 3314 ) ; strcpy ( _dline -> compilerData
-> block [ 28 ] . transducer [ 0 ] . signal [ 1 ] . flag ,
"drive_8c9aa461Acceleration" ) ; _dline -> compilerData -> block [ 29 ] .
numFlanges = 1 ; _dline -> compilerData -> block [ 29 ] . numTransducer = 1 ;
_dline -> compilerData -> block [ 29 ] . name = ( char * ) ( _table ->
UINT8_table + 3341 ) ; strcpy ( _dline -> compilerData -> block [ 29 ] . name
, "HEV/Vehicle/Left Tire/Wheel dynamics/Torque Actuator/Transducer" ) ;
_dline -> compilerData -> block [ 29 ] . visibleName = ( char * ) ( _table ->
UINT8_table + 3405 ) ; strcpy ( _dline -> compilerData -> block [ 29 ] .
visibleName , "HEV/Vehicle/Left Tire" ) ; _dline -> compilerData -> block [
29 ] . type = DRIVETRANSDUCER ; _dline -> compilerData -> block [ 29 ] .
flange = _table -> INT32_table + 44 ; _dline -> compilerData -> block [ 29 ]
. flange [ 0 ] = 16 ; _dline -> compilerData -> block [ 29 ] . transducer =
_table -> DriveTransducer_table + 7 ; _dline -> compilerData -> block [ 29 ]
. transducer [ 0 ] . numSignals = 1 ; _dline -> compilerData -> block [ 29 ]
. transducer [ 0 ] . positionFlag = ( char * ) ( _table -> UINT8_table + 3427
) ; strcpy ( _dline -> compilerData -> block [ 29 ] . transducer [ 0 ] .
positionFlag , "Undefined" ) ; _dline -> compilerData -> block [ 29 ] .
transducer [ 0 ] . velocityFlag = ( char * ) ( _table -> UINT8_table + 3437 )
; strcpy ( _dline -> compilerData -> block [ 29 ] . transducer [ 0 ] .
velocityFlag , "Undefined" ) ; _dline -> compilerData -> block [ 29 ] .
transducer [ 0 ] . accelerationFlag = ( char * ) ( _table -> UINT8_table +
3447 ) ; strcpy ( _dline -> compilerData -> block [ 29 ] . transducer [ 0 ] .
accelerationFlag , "Undefined" ) ; _dline -> compilerData -> block [ 29 ] .
transducer [ 0 ] . signal = _table -> DriveSignal_table + 11 ; _dline ->
compilerData -> block [ 29 ] . transducer [ 0 ] . signal [ 0 ] . type =
DRIVEEXTERNALTORQUE ; _dline -> compilerData -> block [ 29 ] . transducer [ 0
] . signal [ 0 ] . flag = ( char * ) ( _table -> UINT8_table + 3457 ) ;
strcpy ( _dline -> compilerData -> block [ 29 ] . transducer [ 0 ] . signal [
0 ] . flag , "drive_6f7d31d9Tor" ) ; _dline -> compilerData -> block [ 30 ] .
numFlanges = 1 ; _dline -> compilerData -> block [ 30 ] . numTransducer = 1 ;
_dline -> compilerData -> block [ 30 ] . name = ( char * ) ( _table ->
UINT8_table + 3475 ) ; strcpy ( _dline -> compilerData -> block [ 30 ] . name
,
 "HEV/Vehicle/Torsional \\\\nSpring-Damper \\\\n(Friction)/follower_torque/Transducer"
) ; _dline -> compilerData -> block [ 30 ] . visibleName = ( char * ) (
_table -> UINT8_table + 3551 ) ; strcpy ( _dline -> compilerData -> block [
30 ] . visibleName ,
"HEV/Vehicle/Torsional \\\\nSpring-Damper \\\\n(Friction)" ) ; _dline ->
compilerData -> block [ 30 ] . type = DRIVETRANSDUCER ; _dline ->
compilerData -> block [ 30 ] . flange = _table -> INT32_table + 45 ; _dline
-> compilerData -> block [ 30 ] . flange [ 0 ] = 7 ; _dline -> compilerData
-> block [ 30 ] . transducer = _table -> DriveTransducer_table + 8 ; _dline
-> compilerData -> block [ 30 ] . transducer [ 0 ] . numSignals = 1 ; _dline
-> compilerData -> block [ 30 ] . transducer [ 0 ] . positionFlag = ( char *
) ( _table -> UINT8_table + 3600 ) ; strcpy ( _dline -> compilerData -> block
[ 30 ] . transducer [ 0 ] . positionFlag , "Undefined" ) ; _dline ->
compilerData -> block [ 30 ] . transducer [ 0 ] . velocityFlag = ( char * ) (
_table -> UINT8_table + 3610 ) ; strcpy ( _dline -> compilerData -> block [
30 ] . transducer [ 0 ] . velocityFlag , "Undefined" ) ; _dline ->
compilerData -> block [ 30 ] . transducer [ 0 ] . accelerationFlag = ( char *
) ( _table -> UINT8_table + 3620 ) ; strcpy ( _dline -> compilerData -> block
[ 30 ] . transducer [ 0 ] . accelerationFlag , "Undefined" ) ; _dline ->
compilerData -> block [ 30 ] . transducer [ 0 ] . signal = _table ->
DriveSignal_table + 12 ; _dline -> compilerData -> block [ 30 ] . transducer
[ 0 ] . signal [ 0 ] . type = DRIVEEXTERNALTORQUE ; _dline -> compilerData ->
block [ 30 ] . transducer [ 0 ] . signal [ 0 ] . flag = ( char * ) ( _table
-> UINT8_table + 3630 ) ; strcpy ( _dline -> compilerData -> block [ 30 ] .
transducer [ 0 ] . signal [ 0 ] . flag , "drive_46a5b3a3Tor" ) ; _dline ->
compilerData -> block [ 31 ] . numFlanges = 1 ; _dline -> compilerData ->
block [ 31 ] . numTransducer = 1 ; _dline -> compilerData -> block [ 31 ] .
name = ( char * ) ( _table -> UINT8_table + 3648 ) ; strcpy ( _dline ->
compilerData -> block [ 31 ] . name ,
 "HEV/Vehicle/Torsional \\\\nSpring-Damper \\\\n(Friction)/follower_velocity/Transducer"
) ; _dline -> compilerData -> block [ 31 ] . visibleName = ( char * ) (
_table -> UINT8_table + 3726 ) ; strcpy ( _dline -> compilerData -> block [
31 ] . visibleName ,
"HEV/Vehicle/Torsional \\\\nSpring-Damper \\\\n(Friction)" ) ; _dline ->
compilerData -> block [ 31 ] . type = DRIVETRANSDUCER ; _dline ->
compilerData -> block [ 31 ] . flange = _table -> INT32_table + 46 ; _dline
-> compilerData -> block [ 31 ] . flange [ 0 ] = 7 ; _dline -> compilerData
-> block [ 31 ] . transducer = _table -> DriveTransducer_table + 9 ; _dline
-> compilerData -> block [ 31 ] . transducer [ 0 ] . numSignals = 2 ; _dline
-> compilerData -> block [ 31 ] . transducer [ 0 ] . positionFlag = ( char *
) ( _table -> UINT8_table + 3775 ) ; strcpy ( _dline -> compilerData -> block
[ 31 ] . transducer [ 0 ] . positionFlag , "Undefined" ) ; _dline ->
compilerData -> block [ 31 ] . transducer [ 0 ] . velocityFlag = ( char * ) (
_table -> UINT8_table + 3785 ) ; strcpy ( _dline -> compilerData -> block [
31 ] . transducer [ 0 ] . velocityFlag , "Undefined" ) ; _dline ->
compilerData -> block [ 31 ] . transducer [ 0 ] . accelerationFlag = ( char *
) ( _table -> UINT8_table + 3795 ) ; strcpy ( _dline -> compilerData -> block
[ 31 ] . transducer [ 0 ] . accelerationFlag , "Undefined" ) ; _dline ->
compilerData -> block [ 31 ] . transducer [ 0 ] . signal = _table ->
DriveSignal_table + 13 ; _dline -> compilerData -> block [ 31 ] . transducer
[ 0 ] . signal [ 0 ] . type = DRIVEVELOCITY ; _dline -> compilerData -> block
[ 31 ] . transducer [ 0 ] . signal [ 0 ] . flag = ( char * ) ( _table ->
UINT8_table + 3805 ) ; strcpy ( _dline -> compilerData -> block [ 31 ] .
transducer [ 0 ] . signal [ 0 ] . flag , "drive_e5b2ea75Velocity" ) ; _dline
-> compilerData -> block [ 31 ] . transducer [ 0 ] . signal [ 1 ] . type =
DRIVEACCELERATION ; _dline -> compilerData -> block [ 31 ] . transducer [ 0 ]
. signal [ 1 ] . flag = ( char * ) ( _table -> UINT8_table + 3828 ) ; strcpy
( _dline -> compilerData -> block [ 31 ] . transducer [ 0 ] . signal [ 1 ] .
flag , "drive_e5b2ea75Acceleration" ) ; _dline -> compilerData -> block [ 32
] . numFlanges = 1 ; _dline -> compilerData -> block [ 32 ] . numTransducer =
1 ; _dline -> compilerData -> block [ 32 ] . name = ( char * ) ( _table ->
UINT8_table + 3855 ) ; strcpy ( _dline -> compilerData -> block [ 32 ] . name
, "HEV/Electric Motor Controller\\\\n/Motor Motion Sensor/Transducer" ) ;
_dline -> compilerData -> block [ 32 ] . visibleName = ( char * ) ( _table ->
UINT8_table + 3917 ) ; strcpy ( _dline -> compilerData -> block [ 32 ] .
visibleName , "HEV/Electric Motor Controller\\\\n/Motor Motion Sensor" ) ;
_dline -> compilerData -> block [ 32 ] . type = DRIVETRANSDUCER ; _dline ->
compilerData -> block [ 32 ] . flange = _table -> INT32_table + 47 ; _dline
-> compilerData -> block [ 32 ] . flange [ 0 ] = 6 ; _dline -> compilerData
-> block [ 32 ] . transducer = _table -> DriveTransducer_table + 10 ; _dline
-> compilerData -> block [ 32 ] . transducer [ 0 ] . numSignals = 2 ; _dline
-> compilerData -> block [ 32 ] . transducer [ 0 ] . positionFlag = ( char *
) ( _table -> UINT8_table + 3968 ) ; strcpy ( _dline -> compilerData -> block
[ 32 ] . transducer [ 0 ] . positionFlag , "Undefined" ) ; _dline ->
compilerData -> block [ 32 ] . transducer [ 0 ] . velocityFlag = ( char * ) (
_table -> UINT8_table + 3978 ) ; strcpy ( _dline -> compilerData -> block [
32 ] . transducer [ 0 ] . velocityFlag , "Undefined" ) ; _dline ->
compilerData -> block [ 32 ] . transducer [ 0 ] . accelerationFlag = ( char *
) ( _table -> UINT8_table + 3988 ) ; strcpy ( _dline -> compilerData -> block
[ 32 ] . transducer [ 0 ] . accelerationFlag , "Undefined" ) ; _dline ->
compilerData -> block [ 32 ] . transducer [ 0 ] . signal = _table ->
DriveSignal_table + 15 ; _dline -> compilerData -> block [ 32 ] . transducer
[ 0 ] . signal [ 0 ] . type = DRIVEVELOCITY ; _dline -> compilerData -> block
[ 32 ] . transducer [ 0 ] . signal [ 0 ] . flag = ( char * ) ( _table ->
UINT8_table + 3998 ) ; strcpy ( _dline -> compilerData -> block [ 32 ] .
transducer [ 0 ] . signal [ 0 ] . flag , "drive_f4b8de34Velocity" ) ; _dline
-> compilerData -> block [ 32 ] . transducer [ 0 ] . signal [ 1 ] . type =
DRIVEACCELERATION ; _dline -> compilerData -> block [ 32 ] . transducer [ 0 ]
. signal [ 1 ] . flag = ( char * ) ( _table -> UINT8_table + 4021 ) ; strcpy
( _dline -> compilerData -> block [ 32 ] . transducer [ 0 ] . signal [ 1 ] .
flag , "drive_f4b8de34Acceleration" ) ; _dline -> compilerData -> block [ 33
] . numFlanges = 1 ; _dline -> compilerData -> block [ 33 ] . numTransducer =
1 ; _dline -> compilerData -> block [ 33 ] . name = ( char * ) ( _table ->
UINT8_table + 4048 ) ; strcpy ( _dline -> compilerData -> block [ 33 ] . name
, "HEV/Electric Motor Controller\\\\n/Torque Actuator Mot/Transducer" ) ;
_dline -> compilerData -> block [ 33 ] . visibleName = ( char * ) ( _table ->
UINT8_table + 4110 ) ; strcpy ( _dline -> compilerData -> block [ 33 ] .
visibleName , "HEV/Electric Motor Controller\\\\n/Torque Actuator Mot" ) ;
_dline -> compilerData -> block [ 33 ] . type = DRIVETRANSDUCER ; _dline ->
compilerData -> block [ 33 ] . flange = _table -> INT32_table + 48 ; _dline
-> compilerData -> block [ 33 ] . flange [ 0 ] = 6 ; _dline -> compilerData
-> block [ 33 ] . transducer = _table -> DriveTransducer_table + 11 ; _dline
-> compilerData -> block [ 33 ] . transducer [ 0 ] . numSignals = 1 ; _dline
-> compilerData -> block [ 33 ] . transducer [ 0 ] . positionFlag = ( char *
) ( _table -> UINT8_table + 4161 ) ; strcpy ( _dline -> compilerData -> block
[ 33 ] . transducer [ 0 ] . positionFlag , "Undefined" ) ; _dline ->
compilerData -> block [ 33 ] . transducer [ 0 ] . velocityFlag = ( char * ) (
_table -> UINT8_table + 4171 ) ; strcpy ( _dline -> compilerData -> block [
33 ] . transducer [ 0 ] . velocityFlag , "Undefined" ) ; _dline ->
compilerData -> block [ 33 ] . transducer [ 0 ] . accelerationFlag = ( char *
) ( _table -> UINT8_table + 4181 ) ; strcpy ( _dline -> compilerData -> block
[ 33 ] . transducer [ 0 ] . accelerationFlag , "Undefined" ) ; _dline ->
compilerData -> block [ 33 ] . transducer [ 0 ] . signal = _table ->
DriveSignal_table + 17 ; _dline -> compilerData -> block [ 33 ] . transducer
[ 0 ] . signal [ 0 ] . type = DRIVEEXTERNALTORQUE ; _dline -> compilerData ->
block [ 33 ] . transducer [ 0 ] . signal [ 0 ] . flag = ( char * ) ( _table
-> UINT8_table + 4191 ) ; strcpy ( _dline -> compilerData -> block [ 33 ] .
transducer [ 0 ] . signal [ 0 ] . flag , "drive_ccb66a09Tor" ) ; _dline ->
compilerData -> block [ 34 ] . numFlanges = 1 ; _dline -> compilerData ->
block [ 34 ] . numTransducer = 1 ; _dline -> compilerData -> block [ 34 ] .
name = ( char * ) ( _table -> UINT8_table + 4209 ) ; strcpy ( _dline ->
compilerData -> block [ 34 ] . name ,
"HEV/Gearbox/Mot Motion Sensor/Transducer" ) ; _dline -> compilerData ->
block [ 34 ] . visibleName = ( char * ) ( _table -> UINT8_table + 4250 ) ;
strcpy ( _dline -> compilerData -> block [ 34 ] . visibleName ,
"HEV/Gearbox/Mot Motion Sensor" ) ; _dline -> compilerData -> block [ 34 ] .
type = DRIVETRANSDUCER ; _dline -> compilerData -> block [ 34 ] . flange =
_table -> INT32_table + 49 ; _dline -> compilerData -> block [ 34 ] . flange
[ 0 ] = 6 ; _dline -> compilerData -> block [ 34 ] . transducer = _table ->
DriveTransducer_table + 12 ; _dline -> compilerData -> block [ 34 ] .
transducer [ 0 ] . numSignals = 2 ; _dline -> compilerData -> block [ 34 ] .
transducer [ 0 ] . positionFlag = ( char * ) ( _table -> UINT8_table + 4280 )
; strcpy ( _dline -> compilerData -> block [ 34 ] . transducer [ 0 ] .
positionFlag , "Undefined" ) ; _dline -> compilerData -> block [ 34 ] .
transducer [ 0 ] . velocityFlag = ( char * ) ( _table -> UINT8_table + 4290 )
; strcpy ( _dline -> compilerData -> block [ 34 ] . transducer [ 0 ] .
velocityFlag , "Undefined" ) ; _dline -> compilerData -> block [ 34 ] .
transducer [ 0 ] . accelerationFlag = ( char * ) ( _table -> UINT8_table +
4300 ) ; strcpy ( _dline -> compilerData -> block [ 34 ] . transducer [ 0 ] .
accelerationFlag , "Undefined" ) ; _dline -> compilerData -> block [ 34 ] .
transducer [ 0 ] . signal = _table -> DriveSignal_table + 18 ; _dline ->
compilerData -> block [ 34 ] . transducer [ 0 ] . signal [ 0 ] . type =
DRIVEVELOCITY ; _dline -> compilerData -> block [ 34 ] . transducer [ 0 ] .
signal [ 0 ] . flag = ( char * ) ( _table -> UINT8_table + 4310 ) ; strcpy (
_dline -> compilerData -> block [ 34 ] . transducer [ 0 ] . signal [ 0 ] .
flag , "drive_dc17081aVelocity" ) ; _dline -> compilerData -> block [ 34 ] .
transducer [ 0 ] . signal [ 1 ] . type = DRIVEACCELERATION ; _dline ->
compilerData -> block [ 34 ] . transducer [ 0 ] . signal [ 1 ] . flag = (
char * ) ( _table -> UINT8_table + 4333 ) ; strcpy ( _dline -> compilerData
-> block [ 34 ] . transducer [ 0 ] . signal [ 1 ] . flag ,
"drive_dc17081aAcceleration" ) ; _dline -> compilerData -> block [ 35 ] .
numFlanges = 2 ; _dline -> compilerData -> block [ 35 ] . numStrainGauge = 1
; _dline -> compilerData -> block [ 35 ] . name = ( char * ) ( _table ->
UINT8_table + 4360 ) ; strcpy ( _dline -> compilerData -> block [ 35 ] . name
, "HEV/Gearbox/Torque Sensor3/Torque Sensor\\\\nInternal" ) ; _dline ->
compilerData -> block [ 35 ] . visibleName = ( char * ) ( _table ->
UINT8_table + 4410 ) ; strcpy ( _dline -> compilerData -> block [ 35 ] .
visibleName , "HEV/Gearbox/Torque Sensor3" ) ; _dline -> compilerData ->
block [ 35 ] . type = DRIVESTRAINGAUGE ; _dline -> compilerData -> block [ 35
] . flange = _table -> INT32_table + 50 ; _dline -> compilerData -> block [
35 ] . flange [ 0 ] = 17 ; _dline -> compilerData -> block [ 35 ] . flange [
1 ] = 18 ; _dline -> compilerData -> block [ 35 ] . strainGauge = _table ->
DriveStrainGauge_table + 4 ; _dline -> compilerData -> block [ 35 ] .
strainGauge [ 0 ] . measurementFlange = 1 ; _dline -> compilerData -> block [
35 ] . strainGauge [ 0 ] . flag = ( char * ) ( _table -> UINT8_table + 4437 )
; strcpy ( _dline -> compilerData -> block [ 35 ] . strainGauge [ 0 ] . flag
, "drive_d32ef72b" ) ; _dline -> compilerData -> block [ 36 ] . numFlanges =
1 ; _dline -> compilerData -> block [ 36 ] . numTransducer = 1 ; _dline ->
compilerData -> block [ 36 ] . name = ( char * ) ( _table -> UINT8_table +
4452 ) ; strcpy ( _dline -> compilerData -> block [ 36 ] . name ,
"HEV/Electric Motor Controller\\\\n/Gen Motion Sensor/Transducer" ) ; _dline
-> compilerData -> block [ 36 ] . visibleName = ( char * ) ( _table ->
UINT8_table + 4512 ) ; strcpy ( _dline -> compilerData -> block [ 36 ] .
visibleName , "HEV/Electric Motor Controller\\\\n/Gen Motion Sensor" ) ;
_dline -> compilerData -> block [ 36 ] . type = DRIVETRANSDUCER ; _dline ->
compilerData -> block [ 36 ] . flange = _table -> INT32_table + 52 ; _dline
-> compilerData -> block [ 36 ] . flange [ 0 ] = 18 ; _dline -> compilerData
-> block [ 36 ] . transducer = _table -> DriveTransducer_table + 13 ; _dline
-> compilerData -> block [ 36 ] . transducer [ 0 ] . numSignals = 2 ; _dline
-> compilerData -> block [ 36 ] . transducer [ 0 ] . positionFlag = ( char *
) ( _table -> UINT8_table + 4561 ) ; strcpy ( _dline -> compilerData -> block
[ 36 ] . transducer [ 0 ] . positionFlag , "Undefined" ) ; _dline ->
compilerData -> block [ 36 ] . transducer [ 0 ] . velocityFlag = ( char * ) (
_table -> UINT8_table + 4571 ) ; strcpy ( _dline -> compilerData -> block [
36 ] . transducer [ 0 ] . velocityFlag , "Undefined" ) ; _dline ->
compilerData -> block [ 36 ] . transducer [ 0 ] . accelerationFlag = ( char *
) ( _table -> UINT8_table + 4581 ) ; strcpy ( _dline -> compilerData -> block
[ 36 ] . transducer [ 0 ] . accelerationFlag , "Undefined" ) ; _dline ->
compilerData -> block [ 36 ] . transducer [ 0 ] . signal = _table ->
DriveSignal_table + 20 ; _dline -> compilerData -> block [ 36 ] . transducer
[ 0 ] . signal [ 0 ] . type = DRIVEVELOCITY ; _dline -> compilerData -> block
[ 36 ] . transducer [ 0 ] . signal [ 0 ] . flag = ( char * ) ( _table ->
UINT8_table + 4591 ) ; strcpy ( _dline -> compilerData -> block [ 36 ] .
transducer [ 0 ] . signal [ 0 ] . flag , "drive_fc09825aVelocity" ) ; _dline
-> compilerData -> block [ 36 ] . transducer [ 0 ] . signal [ 1 ] . type =
DRIVEACCELERATION ; _dline -> compilerData -> block [ 36 ] . transducer [ 0 ]
. signal [ 1 ] . flag = ( char * ) ( _table -> UINT8_table + 4614 ) ; strcpy
( _dline -> compilerData -> block [ 36 ] . transducer [ 0 ] . signal [ 1 ] .
flag , "drive_fc09825aAcceleration" ) ; _dline -> compilerData -> block [ 37
] . numFlanges = 1 ; _dline -> compilerData -> block [ 37 ] . numTransducer =
1 ; _dline -> compilerData -> block [ 37 ] . name = ( char * ) ( _table ->
UINT8_table + 4641 ) ; strcpy ( _dline -> compilerData -> block [ 37 ] . name
, "HEV/Electric Motor Controller\\\\n/Torque Actuator Gen/Transducer" ) ;
_dline -> compilerData -> block [ 37 ] . visibleName = ( char * ) ( _table ->
UINT8_table + 4703 ) ; strcpy ( _dline -> compilerData -> block [ 37 ] .
visibleName , "HEV/Electric Motor Controller\\\\n/Torque Actuator Gen" ) ;
_dline -> compilerData -> block [ 37 ] . type = DRIVETRANSDUCER ; _dline ->
compilerData -> block [ 37 ] . flange = _table -> INT32_table + 53 ; _dline
-> compilerData -> block [ 37 ] . flange [ 0 ] = 18 ; _dline -> compilerData
-> block [ 37 ] . transducer = _table -> DriveTransducer_table + 14 ; _dline
-> compilerData -> block [ 37 ] . transducer [ 0 ] . numSignals = 1 ; _dline
-> compilerData -> block [ 37 ] . transducer [ 0 ] . positionFlag = ( char *
) ( _table -> UINT8_table + 4754 ) ; strcpy ( _dline -> compilerData -> block
[ 37 ] . transducer [ 0 ] . positionFlag , "Undefined" ) ; _dline ->
compilerData -> block [ 37 ] . transducer [ 0 ] . velocityFlag = ( char * ) (
_table -> UINT8_table + 4764 ) ; strcpy ( _dline -> compilerData -> block [
37 ] . transducer [ 0 ] . velocityFlag , "Undefined" ) ; _dline ->
compilerData -> block [ 37 ] . transducer [ 0 ] . accelerationFlag = ( char *
) ( _table -> UINT8_table + 4774 ) ; strcpy ( _dline -> compilerData -> block
[ 37 ] . transducer [ 0 ] . accelerationFlag , "Undefined" ) ; _dline ->
compilerData -> block [ 37 ] . transducer [ 0 ] . signal = _table ->
DriveSignal_table + 22 ; _dline -> compilerData -> block [ 37 ] . transducer
[ 0 ] . signal [ 0 ] . type = DRIVEEXTERNALTORQUE ; _dline -> compilerData ->
block [ 37 ] . transducer [ 0 ] . signal [ 0 ] . flag = ( char * ) ( _table
-> UINT8_table + 4784 ) ; strcpy ( _dline -> compilerData -> block [ 37 ] .
transducer [ 0 ] . signal [ 0 ] . flag , "drive_831c2968Tor" ) ; _dline ->
compilerData -> block [ 38 ] . numFlanges = 1 ; _dline -> compilerData ->
block [ 38 ] . numTransducer = 1 ; _dline -> compilerData -> block [ 38 ] .
name = ( char * ) ( _table -> UINT8_table + 4802 ) ; strcpy ( _dline ->
compilerData -> block [ 38 ] . name ,
"HEV/Gearbox/Gen Motion Sensor/Transducer" ) ; _dline -> compilerData ->
block [ 38 ] . visibleName = ( char * ) ( _table -> UINT8_table + 4843 ) ;
strcpy ( _dline -> compilerData -> block [ 38 ] . visibleName ,
"HEV/Gearbox/Gen Motion Sensor" ) ; _dline -> compilerData -> block [ 38 ] .
type = DRIVETRANSDUCER ; _dline -> compilerData -> block [ 38 ] . flange =
_table -> INT32_table + 54 ; _dline -> compilerData -> block [ 38 ] . flange
[ 0 ] = 18 ; _dline -> compilerData -> block [ 38 ] . transducer = _table ->
DriveTransducer_table + 15 ; _dline -> compilerData -> block [ 38 ] .
transducer [ 0 ] . numSignals = 2 ; _dline -> compilerData -> block [ 38 ] .
transducer [ 0 ] . positionFlag = ( char * ) ( _table -> UINT8_table + 4873 )
; strcpy ( _dline -> compilerData -> block [ 38 ] . transducer [ 0 ] .
positionFlag , "Undefined" ) ; _dline -> compilerData -> block [ 38 ] .
transducer [ 0 ] . velocityFlag = ( char * ) ( _table -> UINT8_table + 4883 )
; strcpy ( _dline -> compilerData -> block [ 38 ] . transducer [ 0 ] .
velocityFlag , "Undefined" ) ; _dline -> compilerData -> block [ 38 ] .
transducer [ 0 ] . accelerationFlag = ( char * ) ( _table -> UINT8_table +
4893 ) ; strcpy ( _dline -> compilerData -> block [ 38 ] . transducer [ 0 ] .
accelerationFlag , "Undefined" ) ; _dline -> compilerData -> block [ 38 ] .
transducer [ 0 ] . signal = _table -> DriveSignal_table + 23 ; _dline ->
compilerData -> block [ 38 ] . transducer [ 0 ] . signal [ 0 ] . type =
DRIVEVELOCITY ; _dline -> compilerData -> block [ 38 ] . transducer [ 0 ] .
signal [ 0 ] . flag = ( char * ) ( _table -> UINT8_table + 4903 ) ; strcpy (
_dline -> compilerData -> block [ 38 ] . transducer [ 0 ] . signal [ 0 ] .
flag , "drive_53507db2Velocity" ) ; _dline -> compilerData -> block [ 38 ] .
transducer [ 0 ] . signal [ 1 ] . type = DRIVEACCELERATION ; _dline ->
compilerData -> block [ 38 ] . transducer [ 0 ] . signal [ 1 ] . flag = (
char * ) ( _table -> UINT8_table + 4926 ) ; strcpy ( _dline -> compilerData
-> block [ 38 ] . transducer [ 0 ] . signal [ 1 ] . flag ,
"drive_53507db2Acceleration" ) ; _dline -> compilerData -> block [ 39 ] .
numFlanges = 1 ; _dline -> compilerData -> block [ 39 ] . numTransducer = 1 ;
_dline -> compilerData -> block [ 39 ] . name = ( char * ) ( _table ->
UINT8_table + 4953 ) ; strcpy ( _dline -> compilerData -> block [ 39 ] . name
, "HEV/Gearbox/Eng Motion Sensor/Transducer" ) ; _dline -> compilerData ->
block [ 39 ] . visibleName = ( char * ) ( _table -> UINT8_table + 4994 ) ;
strcpy ( _dline -> compilerData -> block [ 39 ] . visibleName ,
"HEV/Gearbox/Eng Motion Sensor" ) ; _dline -> compilerData -> block [ 39 ] .
type = DRIVETRANSDUCER ; _dline -> compilerData -> block [ 39 ] . flange =
_table -> INT32_table + 55 ; _dline -> compilerData -> block [ 39 ] . flange
[ 0 ] = 3 ; _dline -> compilerData -> block [ 39 ] . transducer = _table ->
DriveTransducer_table + 16 ; _dline -> compilerData -> block [ 39 ] .
transducer [ 0 ] . numSignals = 2 ; _dline -> compilerData -> block [ 39 ] .
transducer [ 0 ] . positionFlag = ( char * ) ( _table -> UINT8_table + 5024 )
; strcpy ( _dline -> compilerData -> block [ 39 ] . transducer [ 0 ] .
positionFlag , "Undefined" ) ; _dline -> compilerData -> block [ 39 ] .
transducer [ 0 ] . velocityFlag = ( char * ) ( _table -> UINT8_table + 5034 )
; strcpy ( _dline -> compilerData -> block [ 39 ] . transducer [ 0 ] .
velocityFlag , "Undefined" ) ; _dline -> compilerData -> block [ 39 ] .
transducer [ 0 ] . accelerationFlag = ( char * ) ( _table -> UINT8_table +
5044 ) ; strcpy ( _dline -> compilerData -> block [ 39 ] . transducer [ 0 ] .
accelerationFlag , "Undefined" ) ; _dline -> compilerData -> block [ 39 ] .
transducer [ 0 ] . signal = _table -> DriveSignal_table + 25 ; _dline ->
compilerData -> block [ 39 ] . transducer [ 0 ] . signal [ 0 ] . type =
DRIVEVELOCITY ; _dline -> compilerData -> block [ 39 ] . transducer [ 0 ] .
signal [ 0 ] . flag = ( char * ) ( _table -> UINT8_table + 5054 ) ; strcpy (
_dline -> compilerData -> block [ 39 ] . transducer [ 0 ] . signal [ 0 ] .
flag , "drive_f9653595Velocity" ) ; _dline -> compilerData -> block [ 39 ] .
transducer [ 0 ] . signal [ 1 ] . type = DRIVEACCELERATION ; _dline ->
compilerData -> block [ 39 ] . transducer [ 0 ] . signal [ 1 ] . flag = (
char * ) ( _table -> UINT8_table + 5077 ) ; strcpy ( _dline -> compilerData
-> block [ 39 ] . transducer [ 0 ] . signal [ 1 ] . flag ,
"drive_f9653595Acceleration" ) ; _dline -> compilerData -> block [ 40 ] .
numFlanges = 1 ; _dline -> compilerData -> block [ 40 ] . numTransducer = 1 ;
_dline -> compilerData -> block [ 40 ] . name = ( char * ) ( _table ->
UINT8_table + 5104 ) ; strcpy ( _dline -> compilerData -> block [ 40 ] . name
, "HEV/Engine Controller/Gasoline Engine/Motion Sensor/Transducer" ) ; _dline
-> compilerData -> block [ 40 ] . visibleName = ( char * ) ( _table ->
UINT8_table + 5167 ) ; strcpy ( _dline -> compilerData -> block [ 40 ] .
visibleName , "HEV/Engine Controller/Gasoline Engine/Motion Sensor" ) ;
_dline -> compilerData -> block [ 40 ] . type = DRIVETRANSDUCER ; _dline ->
compilerData -> block [ 40 ] . flange = _table -> INT32_table + 56 ; _dline
-> compilerData -> block [ 40 ] . transducer = _table ->
DriveTransducer_table + 17 ; _dline -> compilerData -> block [ 40 ] .
transducer [ 0 ] . numSignals = 2 ; _dline -> compilerData -> block [ 40 ] .
transducer [ 0 ] . positionFlag = ( char * ) ( _table -> UINT8_table + 5219 )
; strcpy ( _dline -> compilerData -> block [ 40 ] . transducer [ 0 ] .
positionFlag , "Undefined" ) ; _dline -> compilerData -> block [ 40 ] .
transducer [ 0 ] . velocityFlag = ( char * ) ( _table -> UINT8_table + 5229 )
; strcpy ( _dline -> compilerData -> block [ 40 ] . transducer [ 0 ] .
velocityFlag , "Undefined" ) ; _dline -> compilerData -> block [ 40 ] .
transducer [ 0 ] . accelerationFlag = ( char * ) ( _table -> UINT8_table +
5239 ) ; strcpy ( _dline -> compilerData -> block [ 40 ] . transducer [ 0 ] .
accelerationFlag , "Undefined" ) ; _dline -> compilerData -> block [ 40 ] .
transducer [ 0 ] . signal = _table -> DriveSignal_table + 27 ; _dline ->
compilerData -> block [ 40 ] . transducer [ 0 ] . signal [ 0 ] . type =
DRIVEVELOCITY ; _dline -> compilerData -> block [ 40 ] . transducer [ 0 ] .
signal [ 0 ] . flag = ( char * ) ( _table -> UINT8_table + 5249 ) ; strcpy (
_dline -> compilerData -> block [ 40 ] . transducer [ 0 ] . signal [ 0 ] .
flag , "drive_3f421e06Velocity" ) ; _dline -> compilerData -> block [ 40 ] .
transducer [ 0 ] . signal [ 1 ] . type = DRIVEACCELERATION ; _dline ->
compilerData -> block [ 40 ] . transducer [ 0 ] . signal [ 1 ] . flag = (
char * ) ( _table -> UINT8_table + 5272 ) ; strcpy ( _dline -> compilerData
-> block [ 40 ] . transducer [ 0 ] . signal [ 1 ] . flag ,
"drive_3f421e06Acceleration" ) ; _dline -> compilerData -> block [ 41 ] .
numFlanges = 1 ; _dline -> compilerData -> block [ 41 ] . numTransducer = 1 ;
_dline -> compilerData -> block [ 41 ] . name = ( char * ) ( _table ->
UINT8_table + 5299 ) ; strcpy ( _dline -> compilerData -> block [ 41 ] . name
, "HEV/Engine Controller/Gasoline Engine/Torque Actuator/Transducer" ) ;
_dline -> compilerData -> block [ 41 ] . visibleName = ( char * ) ( _table ->
UINT8_table + 5364 ) ; strcpy ( _dline -> compilerData -> block [ 41 ] .
visibleName , "HEV/Engine Controller/Gasoline Engine/Torque Actuator" ) ;
_dline -> compilerData -> block [ 41 ] . type = DRIVETRANSDUCER ; _dline ->
compilerData -> block [ 41 ] . flange = _table -> INT32_table + 57 ; _dline
-> compilerData -> block [ 41 ] . transducer = _table ->
DriveTransducer_table + 18 ; _dline -> compilerData -> block [ 41 ] .
transducer [ 0 ] . numSignals = 1 ; _dline -> compilerData -> block [ 41 ] .
transducer [ 0 ] . positionFlag = ( char * ) ( _table -> UINT8_table + 5418 )
; strcpy ( _dline -> compilerData -> block [ 41 ] . transducer [ 0 ] .
positionFlag , "Undefined" ) ; _dline -> compilerData -> block [ 41 ] .
transducer [ 0 ] . velocityFlag = ( char * ) ( _table -> UINT8_table + 5428 )
; strcpy ( _dline -> compilerData -> block [ 41 ] . transducer [ 0 ] .
velocityFlag , "Undefined" ) ; _dline -> compilerData -> block [ 41 ] .
transducer [ 0 ] . accelerationFlag = ( char * ) ( _table -> UINT8_table +
5438 ) ; strcpy ( _dline -> compilerData -> block [ 41 ] . transducer [ 0 ] .
accelerationFlag , "Undefined" ) ; _dline -> compilerData -> block [ 41 ] .
transducer [ 0 ] . signal = _table -> DriveSignal_table + 29 ; _dline ->
compilerData -> block [ 41 ] . transducer [ 0 ] . signal [ 0 ] . type =
DRIVEEXTERNALTORQUE ; _dline -> compilerData -> block [ 41 ] . transducer [ 0
] . signal [ 0 ] . flag = ( char * ) ( _table -> UINT8_table + 5448 ) ;
strcpy ( _dline -> compilerData -> block [ 41 ] . transducer [ 0 ] . signal [
0 ] . flag , "drive_1acc2884Tor" ) ; _dline -> compilerData -> block [ 42 ] .
numFlanges = 1 ; _dline -> compilerData -> block [ 42 ] . numTransducer = 1 ;
_dline -> compilerData -> block [ 42 ] . name = ( char * ) ( _table ->
UINT8_table + 5466 ) ; strcpy ( _dline -> compilerData -> block [ 42 ] . name
, "HEV/Engine Controller/Motion Sensor/Transducer" ) ; _dline -> compilerData
-> block [ 42 ] . visibleName = ( char * ) ( _table -> UINT8_table + 5513 ) ;
strcpy ( _dline -> compilerData -> block [ 42 ] . visibleName ,
"HEV/Engine Controller/Motion Sensor" ) ; _dline -> compilerData -> block [
42 ] . type = DRIVETRANSDUCER ; _dline -> compilerData -> block [ 42 ] .
flange = _table -> INT32_table + 58 ; _dline -> compilerData -> block [ 42 ]
. transducer = _table -> DriveTransducer_table + 19 ; _dline -> compilerData
-> block [ 42 ] . transducer [ 0 ] . numSignals = 2 ; _dline -> compilerData
-> block [ 42 ] . transducer [ 0 ] . positionFlag = ( char * ) ( _table ->
UINT8_table + 5549 ) ; strcpy ( _dline -> compilerData -> block [ 42 ] .
transducer [ 0 ] . positionFlag , "Undefined" ) ; _dline -> compilerData ->
block [ 42 ] . transducer [ 0 ] . velocityFlag = ( char * ) ( _table ->
UINT8_table + 5559 ) ; strcpy ( _dline -> compilerData -> block [ 42 ] .
transducer [ 0 ] . velocityFlag , "Undefined" ) ; _dline -> compilerData ->
block [ 42 ] . transducer [ 0 ] . accelerationFlag = ( char * ) ( _table ->
UINT8_table + 5569 ) ; strcpy ( _dline -> compilerData -> block [ 42 ] .
transducer [ 0 ] . accelerationFlag , "Undefined" ) ; _dline -> compilerData
-> block [ 42 ] . transducer [ 0 ] . signal = _table -> DriveSignal_table +
30 ; _dline -> compilerData -> block [ 42 ] . transducer [ 0 ] . signal [ 0 ]
. type = DRIVEVELOCITY ; _dline -> compilerData -> block [ 42 ] . transducer
[ 0 ] . signal [ 0 ] . flag = ( char * ) ( _table -> UINT8_table + 5579 ) ;
strcpy ( _dline -> compilerData -> block [ 42 ] . transducer [ 0 ] . signal [
0 ] . flag , "drive_a16c2233Velocity" ) ; _dline -> compilerData -> block [
42 ] . transducer [ 0 ] . signal [ 1 ] . type = DRIVEACCELERATION ; _dline ->
compilerData -> block [ 42 ] . transducer [ 0 ] . signal [ 1 ] . flag = (
char * ) ( _table -> UINT8_table + 5602 ) ; strcpy ( _dline -> compilerData
-> block [ 42 ] . transducer [ 0 ] . signal [ 1 ] . flag ,
"drive_a16c2233Acceleration" ) ; _dline -> compilerData -> block [ 43 ] .
numFlanges = 1 ; _dline -> compilerData -> block [ 43 ] . numTransducer = 1 ;
_dline -> compilerData -> block [ 43 ] . name = ( char * ) ( _table ->
UINT8_table + 5629 ) ; strcpy ( _dline -> compilerData -> block [ 43 ] . name
, "HEV/Engine Controller/Torsional \\\\nSpring-Damper/base_torque/Transducer"
) ; _dline -> compilerData -> block [ 43 ] . visibleName = ( char * ) (
_table -> UINT8_table + 5699 ) ; strcpy ( _dline -> compilerData -> block [
43 ] . visibleName , "HEV/Engine Controller/Torsional \\\\nSpring-Damper" ) ;
_dline -> compilerData -> block [ 43 ] . type = DRIVETRANSDUCER ; _dline ->
compilerData -> block [ 43 ] . flange = _table -> INT32_table + 59 ; _dline
-> compilerData -> block [ 43 ] . transducer = _table ->
DriveTransducer_table + 20 ; _dline -> compilerData -> block [ 43 ] .
transducer [ 0 ] . numSignals = 1 ; _dline -> compilerData -> block [ 43 ] .
transducer [ 0 ] . positionFlag = ( char * ) ( _table -> UINT8_table + 5746 )
; strcpy ( _dline -> compilerData -> block [ 43 ] . transducer [ 0 ] .
positionFlag , "Undefined" ) ; _dline -> compilerData -> block [ 43 ] .
transducer [ 0 ] . velocityFlag = ( char * ) ( _table -> UINT8_table + 5756 )
; strcpy ( _dline -> compilerData -> block [ 43 ] . transducer [ 0 ] .
velocityFlag , "Undefined" ) ; _dline -> compilerData -> block [ 43 ] .
transducer [ 0 ] . accelerationFlag = ( char * ) ( _table -> UINT8_table +
5766 ) ; strcpy ( _dline -> compilerData -> block [ 43 ] . transducer [ 0 ] .
accelerationFlag , "Undefined" ) ; _dline -> compilerData -> block [ 43 ] .
transducer [ 0 ] . signal = _table -> DriveSignal_table + 32 ; _dline ->
compilerData -> block [ 43 ] . transducer [ 0 ] . signal [ 0 ] . type =
DRIVEEXTERNALTORQUE ; _dline -> compilerData -> block [ 43 ] . transducer [ 0
] . signal [ 0 ] . flag = ( char * ) ( _table -> UINT8_table + 5776 ) ;
strcpy ( _dline -> compilerData -> block [ 43 ] . transducer [ 0 ] . signal [
0 ] . flag , "drive_ce701f87Tor" ) ; _dline -> compilerData -> block [ 44 ] .
numFlanges = 1 ; _dline -> compilerData -> block [ 44 ] . numTransducer = 1 ;
_dline -> compilerData -> block [ 44 ] . name = ( char * ) ( _table ->
UINT8_table + 5794 ) ; strcpy ( _dline -> compilerData -> block [ 44 ] . name
,
"HEV/Engine Controller/Torsional \\\\nSpring-Damper/base_velocity/Transducer"
) ; _dline -> compilerData -> block [ 44 ] . visibleName = ( char * ) (
_table -> UINT8_table + 5866 ) ; strcpy ( _dline -> compilerData -> block [
44 ] . visibleName , "HEV/Engine Controller/Torsional \\\\nSpring-Damper" ) ;
_dline -> compilerData -> block [ 44 ] . type = DRIVETRANSDUCER ; _dline ->
compilerData -> block [ 44 ] . flange = _table -> INT32_table + 60 ; _dline
-> compilerData -> block [ 44 ] . transducer = _table ->
DriveTransducer_table + 21 ; _dline -> compilerData -> block [ 44 ] .
transducer [ 0 ] . numSignals = 2 ; _dline -> compilerData -> block [ 44 ] .
transducer [ 0 ] . positionFlag = ( char * ) ( _table -> UINT8_table + 5913 )
; strcpy ( _dline -> compilerData -> block [ 44 ] . transducer [ 0 ] .
positionFlag , "Undefined" ) ; _dline -> compilerData -> block [ 44 ] .
transducer [ 0 ] . velocityFlag = ( char * ) ( _table -> UINT8_table + 5923 )
; strcpy ( _dline -> compilerData -> block [ 44 ] . transducer [ 0 ] .
velocityFlag , "Undefined" ) ; _dline -> compilerData -> block [ 44 ] .
transducer [ 0 ] . accelerationFlag = ( char * ) ( _table -> UINT8_table +
5933 ) ; strcpy ( _dline -> compilerData -> block [ 44 ] . transducer [ 0 ] .
accelerationFlag , "Undefined" ) ; _dline -> compilerData -> block [ 44 ] .
transducer [ 0 ] . signal = _table -> DriveSignal_table + 33 ; _dline ->
compilerData -> block [ 44 ] . transducer [ 0 ] . signal [ 0 ] . type =
DRIVEVELOCITY ; _dline -> compilerData -> block [ 44 ] . transducer [ 0 ] .
signal [ 0 ] . flag = ( char * ) ( _table -> UINT8_table + 5943 ) ; strcpy (
_dline -> compilerData -> block [ 44 ] . transducer [ 0 ] . signal [ 0 ] .
flag , "drive_5ac4c50Velocity" ) ; _dline -> compilerData -> block [ 44 ] .
transducer [ 0 ] . signal [ 1 ] . type = DRIVEACCELERATION ; _dline ->
compilerData -> block [ 44 ] . transducer [ 0 ] . signal [ 1 ] . flag = (
char * ) ( _table -> UINT8_table + 5965 ) ; strcpy ( _dline -> compilerData
-> block [ 44 ] . transducer [ 0 ] . signal [ 1 ] . flag ,
"drive_5ac4c50Acceleration" ) ; _dline -> compilerData -> ioSizes .
numDynamicInputs = 9 ; _dline -> compilerData -> ioSizes . numDynamicOutputs
= 18 ; _dline -> compilerData -> ioSizes . numKinematicOutputs = 13 ; _dline
-> compilerData -> ioSizes . numRtParameters = 17 ; _dline -> compilerData ->
name = ( char * ) ( _table -> UINT8_table + 5991 ) ; strcpy ( _dline ->
compilerData -> name , "HEV/Engine Controller/Driveline\\\\nEnvironment" ) ;
_dline -> compilerData -> mdlHandle = 3.0001220703125 ; return _dline ; }
