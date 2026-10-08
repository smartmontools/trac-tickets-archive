# Frieder Ferlemann: this AWK script makes sense for SSD drives with Indilinx controller
BEGIN { print "#Power_On_Hours Write_Sectors_Tot_Ct Write_Commands_Tot_Ct Error_Bits_Flash_Tot_Ct Corr_Read_Errors_Tot_Ct Min_Erase_Count Max_Erase_Count Average_Erase_Count Remaining_Lifetime_Perc" }
/Power_On_Hours/        { POH  = $10; printf "%d", POH }
/Write_Sectors_Tot_Ct/  { WSTC = $10; printf " %d", WSTC }
/Write_Commands_Tot_Ct/ { WCTC = $10; printf " %d", WCTC }
/Error_Bits_Flash_Tot_Ct/ {EBFTC = $10; printf " %d", EBFTC}
/Corr_Read_Errors_Tot_Ct/ {CRETC = $10; printf " %d", CRETC}
/Min_Erase_Count/         {MIEC = $10; printf " %d", MIEC}
/Max_Erase_Count/         {MAEC = $10; printf " %d", MAEC}
/Average_Erase_Count/   { AEC  = $10; printf " %d", AEC }
/Remaining_Lifetime_Perc/ {RLP = $10; printf " %d\n", RLP}