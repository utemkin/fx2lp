@echo off
setlocal ENABLEDELAYEDEXPANSION
setlocal ENABLEEXTENSIONS

set BUILD_DIR=build_sdcc
set APP_NAME=test
set CC="sdcc" -c
set CC_FLAGS=-mmcs51 --opt-code-speed --fomit-frame-pointer --model-small --code-size 0x4000 --iram-size 0x0100 --stack-size 0x0080 --xram-size 0x0000
set LD="sdcc"
set LD_FLAGS=%CC_FLAGS%

set SOURCES=test.c fx2lp.c

if not exist "%BUILD_DIR%" mkdir "%BUILD_DIR%"

set SOURCES=ivect.c %SOURCES%
for %%f in (%SOURCES%) do (
  set OBJ="%BUILD_DIR%\%%~nf.rel"
  set OBJS=!OBJS! !OBJ!
  if exist !OBJ! del /q !OBJ!
  %CC% %CC_FLAGS% %%f -o !OBJ!
)
if exist "%BUILD_DIR%\%APP_NAME%.hex" del /q "%BUILD_DIR%\%APP_NAME%.hex"
%LD% %LD_FLAGS% %OBJS% -o "%BUILD_DIR%\%APP_NAME%.hex"
