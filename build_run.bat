@echo off
echo ==========================================
echo Compilando TaskMaster (Grupo 3)...
echo ==========================================

g++ main.cpp src/model/Task.cpp src/view/TaskView.cpp src/controller/TaskController.cpp -o taskmaster.exe

if %errorlevel% neq 0 (
    echo.
    echo [ERRO] Falha na compilacao! Verifique o codigo.
    pause
    exit /b %errorlevel%
)

echo.
echo [SUCESSO] Compilacao concluida!
echo Iniciando o programa...
echo ==========================================
echo.

.\taskmaster.exe

echo.
echo Programa finalizado.
pause