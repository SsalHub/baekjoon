del /F %1\%2.exe
g++ %1\%2.cpp -o %1\%2.exe
timeout /t 1
%1\%2.exe
pause