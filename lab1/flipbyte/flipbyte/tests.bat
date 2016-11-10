set PROGRAM="%~1" 

rem проверка числа, после изменения байтов которого ничего не изменится
%PROGRAM% 0 > "%TEMP%\output.txt"
fc "%TEMP%\output.txt" zero.txt
if ERRORLEVEL 1 goto error

rem проверка колличества аргументов
%PROGRAM%
if NOT ERRORLEVEL 1 goto error 

rem проверка выхода за пределы
%PROGRAM% -1 > "%TEMP%\output.txt"
fc "%TEMP%\output.txt" overflow.txt
if ERRORLEVEL 1 goto error 

rem проверка оптимального варианта, должно вернуть 96
%PROGRAM% 6 > "%TEMP%\output.txt"
fc "%TEMP%\output.txt" good.txt
if ERRORLEVEL 1 goto error

echo Program testing succeeded 
exit 0 

:error 
echo Program testing failed 
exit 1