set PROGRAM="%~1"

rem c�������� ����������� stdout
%PROGRAM% firstFile.txt secondFile.txt > "%TEMP%\output.txt"
IF NOT ERRORLEVEL 0 goto error
fc.exe "%TEMP%\output.txt" expected-firstFile-and-secondFile.txt
if ERRORLEVEL 1 goto error

rem c�������� ������ ������
fc.exe empty.txt empty2.txt
if NOT ERRORLEVEL 0 goto error

rem ������� ��� ������, �� ������ ����, ���� ���� ���� ����, � ������ ���
fc.exe empty.txt firstFile.txt
if NOT ERRORLEVEL 1 goto error

rem ������� ��� ������, �� ������ ����, ���� ����� ������
fc.exe firstFile.txt secondFile.txt
if NOT ERRORLEVEL 1 goto error

rem ������� ��� ������, �� ������ ����, ���� �� ������ ���� �� �������� ������
%PROGRAM% non-existing-file-name.txt firstFile.txt > "%TEMP%\output.txt"
if NOT ERRORLEVEL 1 goto error
fc.exe "%TEMP%\output.txt" expected-output-when-input-file-is-missing.txt
if ERRORLEVEL 1 goto error

echo Program testing succeeded
exit 0

:error
echo Program testing failed
exit 1