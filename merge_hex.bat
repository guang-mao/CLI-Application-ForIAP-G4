@echo off
srec_cat.exe Release\Application.hex -Intel ^
             submodule\Release\Bootloader.hex -Intel ^
             -o Combined_merge.hex -Intel
echo Merge completed!
pause
