set PROGRAM="%~1" 

rem �������� �����, ����� ��������� ������ �������� ������ �� ���������
%PROGRAM% 0 > "%TEMP%\output.txt"
fc "%TEMP%\output.txt" zero.txt
if ERRORLEVEL 1 goto error

rem �������� ����������� ����������
%PROGRAM%
if NOT ERRORLEVEL 1 goto error 

rem �������� ������ �� �������
%PROGRAM% -1 > "%TEMP%\output.txt"
fc "%TEMP%\output.txt" overflow.txt
if ERRORLEVEL 1 goto error 

rem �������� ������������ ��������, ������ ������� 96
%PROGRAM% 6 > "%TEMP%\output.txt"
fc "%TEMP%\output.txt" good.txt
if ERRORLEVEL 1 goto error

echo Program testing succeeded 
exit 0 

:error 
echo Program testing failed 
exit 1