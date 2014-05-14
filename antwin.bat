@setlocal
@set ANT_HOME=%~dp0external\ant
%ANT_HOME%\bin\ant.bat -Dplatform=win %*
@endlocal