@echo off
set MATLAB=C:\Program Files (x86)\MATLAB\R2015a
"%MATLAB%\bin\win32\gmake" -f HEV.mk  ISPROTECTINGMODEL=NOTPROTECTING
