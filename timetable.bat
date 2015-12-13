@echo off
set /p choice=Enter Choice.. 0 for Even Sem, 1 for Odd Sem :%=%
@echo %choice%

IF %choice%==0 ( "C:\Users\admin\Desktop\Timetable Gen\Evensem\Algorithm\evensem.exe"
) ELSE IF %choice%==1 ( "C:\Users\admin\Desktop\Timetable Gen\Oddsem\Algorithm\oddsem.exe" 
) ELSE ( echo Wrong choice )