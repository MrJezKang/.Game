@echo off
setlocal enabledelayedexpansion

:: --- CONFIGURATION ---
set COMPILER=C:\msys64\ucrt64\bin\g++.exe
set INCLUDE_PATH=-I C:/msys64/ucrt64/include
set LIB_PATH=-L C:/msys64/ucrt64/lib
set LIBS=-lmingw32 -lSDL2main -lSDL2
set OUTPUT=bin\game.exe
set SOURCE=src\main.cpp

:: --- BUILD PROCESS ---
echo Starting Build: %date% %time%
echo ------------------------------------------

if not exist bin (
    echo [SYSTEM] Creating bin directory...
    mkdir bin
)

echo [COMPILER] Compiling Source Files...
%COMPILER% %SOURCE% -o %OUTPUT% %INCLUDE_PATH% %LIB_PATH% %LIBS%

:: --- ERROR CHECKING ---
if %errorlevel% neq 0 (
    echo.
    echo ------------------------------------------
    echo [ERROR] Build Failed with code %errorlevel%
    pause
    exit /b %errorlevel%
)

echo [SUCCESS] Build Complete: %OUTPUT%
echo [SYSTEM] Launching Game...
echo ------------------------------------------

:: Run the game from within the bin folder so it finds the DLL and Assets
cd bin
start game.exe
cd ..

exit /b 0