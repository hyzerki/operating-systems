@echo off
echo - ��ப� ��ࠬ��஢: %1 %2
echo - ०��: %1
echo - 䠩�: %2

if "%1" EQU "" goto error
if "%1" EQU "ᮧ����" goto create
if "%1" EQU "㤠����" goto delete
if "%1" NEQ "㤠����" goto error1
if "%1" NEQ "ᮧ����" goto error1

:create
if "%2" NEQ "" goto checkFileToCreate
echo - �� ������ ��� 䠩��
goto exit

:checkFileToCreate
if exist %2 (goto existFile)
copy NUL %2
echo - 䠩� %2 ᮧ���
goto exit

:existFile
echo - 䠩� %2 㦥 �������
goto exit

:delete
if "%2" NEQ "" goto checkFileToDelete
echo - �� ������ ��� 䠩��
goto exit

:checkFileToDelete
if not exist %2 (goto notFoundFile)
del %2
echo - 䠩� %2 㤠��
goto exit

:notFoundFile
echo - 䠩� %2 �� ������
goto exit

:error
echo - %0 mode file
echo - mode = {ᮧ����, 㤠����}
echo - file = filename
goto exit

:error1
echo - ������ ०��
goto exit

:exit