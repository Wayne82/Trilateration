pushd ""%T_BUILD_DIR%"" > NUL
if %errorlevel% == 1 goto error
popd > NUL
goto finished

:error
echo Build directory %T_BUILD_DIR% not found.
exit /B 2

:finished
echo Using projects in: %T_ROOT_DIR%
echo Generating build files in: %T_BUILD_DIR%
echo Output directory: %T_OUTPUT_DIR%

pushd ""%T_BUILD_DIR%"" > NUL

@echo on
cmake -G %T_GEN% -DT_OUTPUT_DIR=%T_OUTPUT_DIR% -DT_BUILD_LIBTYPE=%T_BUILD_LIBTYPE% -DT_BUILD_ARCH=%T_BUILD_ARCH% %T_ROOT_DIR%
@echo off

popd
