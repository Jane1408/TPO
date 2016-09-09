rem @echo off
SET program="%1"


%program% 1 > out.txt
if ERRORLEVEL 1 goto testFailed
fc.exe out.txt NotEnoughArguments.txt
if ERRORLEVEL 1 goto testFailed

%program% 2 4.2 > out.txt
if ERRORLEVEL 1 goto testFailed
fc.exe out.txt NotEnoughArguments.txt
if ERRORLEVEL 1 goto testFailed

%program% 1 3 6 2 > out.txt
if ERRORLEVEL 1 goto testFailed
fc.exe out.txt ManyArguments.txt
if ERRORLEVEL 1 goto testFailed

%program% 10 5 -4 > out.txt
if ERRORLEVEL 1 goto testFailed
fc.exe out.txt NotCorrectArgument.txt
if ERRORLEVEL 1 goto testFailed

%program% 5 5 2 > out.txt
if ERRORLEVEL 1 goto testFailed
fc.exe out.txt Isosceles.txt
if ERRORLEVEL 1 goto testFailed

%program% 2 2 2 > out.txt
if ERRORLEVEL 1 goto testFailed
fc.exe out.txt Equilateral.txt
if ERRORLEVEL 1 goto testFailed

%program% 1 1,2 1,1 > out.txt
if ERRORLEVEL 1 goto testFailed
fc.exe out.txt Normal.txt
if ERRORLEVEL 1 goto testFailed

%program% 1.2 1.1 1.1 > out.txt
if ERRORLEVEL 1 goto testFailed
fc.exe out.txt Isosceles.txt
if ERRORLEVEL 1 goto testFailed

%program% 0 0 0 > out.txt
if ERRORLEVEL 1 goto testFailed
fc.exe out.txt NoTriangle.txt
if ERRORLEVEL 1 goto testFailed

%program% 4 2 2 > out.txt
if ERRORLEVEL 1 goto testFailed
fc.exe out.txt NoTriangle.txt
if ERRORLEVEL 1 goto testFailed

echo OK
exit /B

:testFailed
echo Testing failed
exit /B

:err
echo Usage: test.bat <Path to program>