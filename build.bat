@echo off

del *.exe

echo Compiling:
echo ==========

set FLAGS=/nologo /W3

for %%i in (*.c) do (
	cl %FLAGS% %%i
)

echo.
echo Answers:
echo ========

for %%i in (*.exe) do (
	.\%%i
)