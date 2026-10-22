@echo off
setlocal

if not defined CXX set "CXX=g++"
where "%CXX%" >nul 2>&1
if errorlevel 1 (
    echo Error: C++ compiler "%CXX%" not found. Install MinGW-w64/Clang or set CXX. 1>&2
    exit /b 1
)

pushd "%~dp0.."
if errorlevel 1 exit /b 1

if not exist "build\" mkdir "build"
if not exist "build\" (
    echo Error: unable to create the build directory. 1>&2
    popd
    exit /b 1
)

"%CXX%" -std=c++17 -Wall -Wextra -pedantic -O2 src\main.cpp src\chip8.cpp -o build\chip8.exe
set "BUILD_EXIT_CODE=%ERRORLEVEL%"
if not "%BUILD_EXIT_CODE%"=="0" (
    echo Build failed. 1>&2
    popd
    exit /b %BUILD_EXIT_CODE%
)

echo Built build\chip8.exe
popd
exit /b 0
