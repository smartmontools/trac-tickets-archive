@echo on
:: This is just a wrapper to launch a PowerShell email script
:: Author: David Schaerer, ETH Zurich, 2016/07/14

REM Find out the location of the running service smartd.exe and set this location to run the PowerShell script.
FOR /F "tokens=* USEBACKQ" %%F IN (`%windir%\system32\WindowsPowerShell\v1.0\PowerShell.exe get-process smartd ^^^| fl path`) DO (
SET smartdloc=%%F
)
set smartdloc=%smartdloc:smartd.exe=%
set smartdloc=%smartdloc:Path : =%

REM Launch a PowerShell script that will send the smartd warings by email.
PowerShell -NoProfile -ExecutionPolicy Bypass -Command "& {set-location %smartdloc%;./emailSender.ps1}"