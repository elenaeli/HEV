#include "__cf_HEV.h"
#include "drive_std.h"
#ifdef __cplusplus
extern "C" {
#endif
#ifndef DRIVE_HEV_1_H
#define DRIVE_HEV_1_H 1
#ifndef struct_drive_HEV_1_data_table_tag
#define struct_drive_HEV_1_data_table_tag
typedef struct drive_HEV_1_data_table_tag { DriveLine _dline ;
DriveSimpleGear DriveSimpleGear_table [ 5 ] ; DrivePlanetRing
DrivePlanetRing_table [ 1 ] ; DrivePlanetPlanet DrivePlanetPlanet_table [ 3 ]
; DriveStrainGauge DriveStrainGauge_table [ 6 ] ; DriveInertia
DriveInertia_table [ 4 ] ; DriveParameter DriveParameter_table [ 17 ] ;
DriveWeld DriveWeld_table [ 2 ] ; DriveSignal DriveSignal_table [ 37 ] ;
DriveTransducer DriveTransducer_table [ 23 ] ; DriveSolver DriveSolver_table
[ 1 ] ; uint8_T UINT8_table [ 6198 ] ; DriveBlock DriveBlock_table [ 47 ] ;
int32_T INT32_table [ 64 ] ; DriveCompilerData DriveCompilerData_table [ 1 ]
; } drive_HEV_1_data_table ;
#else
typedef struct drive_HEV_1_data_table_tag drive_HEV_1_data_table ;
#endif
extern DriveLine * _drive_HEV_1_drive_line ; extern DriveLine *
drive_HEV_1_drive_line ( drive_HEV_1_data_table * _table ) ;
#endif
#ifdef __cplusplus
}
#endif
