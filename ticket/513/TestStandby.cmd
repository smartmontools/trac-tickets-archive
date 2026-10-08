@ECHO OFF

SET _disk=sdc

ECHO.
ECHO SET DISK SLEEP TIMEOUT TO 1 MINUTE
ECHO.

ECHO Press Y when disk "%_disk%" is in standby (OFF)
ECHO.
:wait_standby1
  <nul (set/p _any_variable=%TIME:~0,-3%  )
  IF EXIST DiskPowerStatus.exe DiskPowerStatus
  ECHO.
  CHOICE /C yn /D n /T 5 >nul
if errorlevel 2 GOTO wait_standby1

smartctl -r ioctl,2 -n standby -i %_disk%

ECHO.
ECHO WATCH FOR DISK SPIN ON AND OFF
ECHO.

ECHO Press Y to finish
ECHO.
:wait_standby2
  <nul (set/p _any_variable=%TIME:~0,-3%  )
  IF EXIST DiskPowerStatus.exe DiskPowerStatus
  ECHO.
  CHOICE /C yn /D n /T 5 >nul
if errorlevel 2 GOTO wait_standby2


ECHO.
ECHO RESET DISK SLEEP TIMER TO ITS NORMAL VALUE
ECHO.
