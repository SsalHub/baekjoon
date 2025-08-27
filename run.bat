del /F %1\main.exe
g++ %1\main.cpp -o %1\main.exe
timeout /t 1
%1\main.exe
pause