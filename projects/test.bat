@echo off
for /R %%i in (*.sln) do (msbuild %%i)
for /R %%i in (*.exe) do (
%%i consoleOff
if errorlevel 1 (echo %%i- not ok :c ) else (echo %%i - ok c: )
)
pause