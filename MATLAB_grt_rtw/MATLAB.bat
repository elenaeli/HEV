set MATLAB=C:\Program Files (x86)\MATLAB\R2015a

cd .

if "%1"=="" (C:\PROGRA~2\MATLAB\R2015a\bin\win32\gmake -f MATLAB.mk all) else (C:\PROGRA~2\MATLAB\R2015a\bin\win32\gmake -f MATLAB.mk %1)
@if errorlevel 1 goto error_exit

exit /B 0

:error_exit
echo The make command returned an error of %errorlevel%
An_error_occurred_during_the_call_to_make
