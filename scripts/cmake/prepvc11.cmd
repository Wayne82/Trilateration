@echo off & setlocal enableextensions enabledelayedexpansion

if "%T_BUILD_ARCH%" == "x64" ( set T_GEN="Visual Studio 11 Win64" )
if "%T_BUILD_ARCH%" == "x86" ( set T_GEN="Visual Studio 11" )

call "%~d0%~p0\prepwin.cmd" %*
