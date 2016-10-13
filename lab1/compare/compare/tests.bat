set PROGRAM="%~1"

rem cравнение пустых файлов
%PROGRAM% empty.txt empty2.txt > "%TEMP%\output.txt"
if NOT ERRORLEVEL 0 goto error
fc.exe "%TEMP%\output.txt" empty-result.txt
if NOT ERRORLEVEL 0 goto error

rem ожидаем код ошибки, не равный нулю, если один файл пуст, а второй нет
%PROGRAM% empty.txt firstFile.txt > "%TEMP%\output.txt"
if NOT ERRORLEVEL 1 goto error
fc.exe "%TEMP%\output.txt" empty-and-not-empty-file.txt
if NOT ERRORLEVEL 0 goto error

rem ожидаем код ошибки, не равный нулю, если файлы разные
%PROGRAM% firstFile.txt secondFile.txt > "%TEMP%\output.txt"
IF NOT ERRORLEVEL 0 goto error
fc.exe "%TEMP%\output.txt" expected-firstFile-and-secondFile.txt
if ERRORLEVEL 1 goto error

rem ожидаем код ошибки, не равный нулю, если не найден один из входящих файлов (программа не смогла открыть файл)
%PROGRAM% non-existing-file.txt firstFile.txt > "%TEMP%\output.txt"
if NOT ERRORLEVEL 1 goto error
fc.exe "%TEMP%\output.txt" expected-output-when-input-file-is-missing.txt
if ERRORLEVEL 1 goto error

rem проверка программы, если не передано параметров
%PROGRAM% > "%TEMP%\output.txt"
if NOT ERRORLEVEL 1 goto error
fc.exe %TEMP%\output.txt output-parameters-count-error.txt
if ERRORLEVEL 1 goto error

rem проверка программы, если передан только один параметр
%PROGRAM% firstFile.txt > "%TEMP%\output.txt"
if NOT ERRORLEVEL 1 goto error
fc.exe %TEMP%\output.txt output-parameters-count-error.txt
if ERRORLEVEL 1 goto error

echo Program testing succeeded
exit 0

:error
echo Program testing failed
exit 1