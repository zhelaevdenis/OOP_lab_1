@echo off

set PROGRAM="%~1"
set OUTPUT="output.txt"

rem no params
::%PROGRAM% > nul
::if NOT ERRORLEVEL 1 goto err
::echo Passed 1
::
::%PROGRAM% 1000 > %OUTPUT%
::if ERRORLEVEL 1 goto err
::fc.exe %OUTPUT% tests/bin1-out.txt > nul
::if ERRORLEVEL 1 goto err

echo Program testing succeeded
exit 0

:err
echo Program testing failed
exit 1