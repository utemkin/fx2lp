@echo off
setlocal ENABLEDELAYEDEXPANSION
setlocal ENABLEEXTENSIONS

set BUILD_DIR=build_keil
set APP_NAME=test
set KEIL=C:\Keil_v5\C51
set C51INC=%KEIL%\Inc;%KEIL%\Inc\Cypress
set C51LIB=%KEIL%\Lib
set AS="%KEIL%\bin\a51"
set AS_FLAGS="SET(SMALL)" "DEBUG" "XREF" "EP"
set CC="%KEIL%\bin\c51"
set CC_FLAGS="ROM(COMPACT)" "OPTIMIZE(8,SPEED)" "BROWSE" "MODDP2" "DEBUG" "OBJECTEXTEND" "CODE" "LISTINCLUDE" "SYMBOLS" "TABS(2)"
set LD="%KEIL%\bin\bl51"
set LD_FLAGS="IXREF" "RAMSIZE(256)" "CODE(0x0000-0x3fff)"

set SOURCES=test.c fx2lp.c
set ASM_SOURCES=startup_keil.a51

if not exist "%BUILD_DIR%" mkdir "%BUILD_DIR%"

  rem for %%f in (%SOURCES%) do (
  rem   set A51="%BUILD_DIR%\%%~nf.a51"
  rem   if exist !A51! del /q !A51!
  rem   %CC% %%f "SRC(%BUILD_DIR%\%%~nf.a51)" "PRINT(%BUILD_DIR%\%%~nf.c2a)" "PREPRINT(%BUILD_DIR%\%%~nf.i)" %CC_FLAGS%
  rem   set ASM_SOURCES=!ASM_SOURCES! !A51!
  rem )
for %%f in (%SOURCES%) do (
  set OBJ="%BUILD_DIR%\%%~nf.obj"
  IF DEFINED OBJS (set OBJS=!OBJS!,)
  set OBJS=!OBJS! !OBJ!
  if exist !OBJ! del /q !OBJ!
  %CC% %%f "OBJECT(!OBJ!)" "PRINT(%BUILD_DIR%\%%~nf.lst)" "PREPRINT(%BUILD_DIR%\%%~nf.i)" %CC_FLAGS%
)
for %%f in (%ASM_SOURCES%) do (
  set OBJ="%BUILD_DIR%\%%~nf.obj"
  IF DEFINED OBJS (set OBJS=!OBJS!,)
  set OBJS=!OBJS! !OBJ!
  if exist !OBJ! del /q !OBJ!
  %AS% %%f "OBJECT(!OBJ!)" "PRINT(%BUILD_DIR%\%%~nf.lst)" %AS_FLAGS%
)
if exist "%BUILD_DIR%\%APP_NAME%.exe" del /q "%BUILD_DIR%\%APP_NAME%.exe"
if exist "%BUILD_DIR%\%APP_NAME%.hex" del /q "%BUILD_DIR%\%APP_NAME%.hex"
  rem , "%KEIL%\Lib\C51S.LIB"
%LD% %OBJS% TO "%BUILD_DIR%\%APP_NAME%.exe" "PRINT(%BUILD_DIR%\%APP_NAME%.map)" %LD_FLAGS% && "%KEIL%\bin\OH51.EXE" "%BUILD_DIR%\%APP_NAME%.exe" HEXFILE("%BUILD_DIR%\%APP_NAME%.hex")
