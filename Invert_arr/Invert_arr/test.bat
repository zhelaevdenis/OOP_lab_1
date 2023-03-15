@echo off

set PROGRAM= "%~1"

set OUTPUT="output.txt"


%PROGRAM% > nul
if NOT ERRORLEVEL 1 goto err

%PROGRAM% mt1.txt > %OUTPUT% 
if ERRORLEVEL 1 goto err

fc.exe %OUTPUT% mt1-out.txt > nul
if ERRORLEVEL 1 goto err

echo Program testing succeeded
exit 0

:err
echo Program testing failed
exit 1