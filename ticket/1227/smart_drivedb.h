  { "Crucial/Micron MX500 SSDs",
    "CT(250|500|1000|2000)MX500SSD[14]", // tested with CT500MX500SSD1/M3CR023
    "M3CR023", // Firmware with bogus attribute 197 (see ticket #1237)
    "This firmware returns bogus raw values in attribute 197",
  //"-v 1,raw48,Raw_Read_Error_Rate "
    "-v 5,raw48,Reallocate_NAND_Blk_Cnt "
  //"-v 9,raw24(raw8),Power_On_Hours "
  //"-v 12,raw48,Power_Cycle_Count "
    "-v 171,raw48,Program_Fail_Count "
    "-v 172,raw48,Erase_Fail_Count "
    "-v 173,raw48,Ave_Block-Erase_Count "
    "-v 174,raw48,Unexpect_Power_Loss_Ct "
    "-v 180,raw48,Unused_Reserve_NAND_Blk "
    "-v 183,raw48,SATA_Interfac_Downshift "
    "-v 184,raw48,Error_Correction_Count "
  //"-v 187,raw48,Reported_Uncorrect "
  //"-v 194,tempminmax,Temperature_Celsius "
  //"-v 196,raw16(raw16),Reallocated_Event_Count "
    "-v 197,raw48,Bogus_Current_Pend_Sect " // Randomly flips 0 <> 1
  //"-v 198,raw48,Offline_Uncorrectable "
  //"-v 199,raw48,UDMA_CRC_Error_Count "
    "-v 202,raw48,Percent_Lifetime_Remain "
    "-v 206,raw48,Write_Error_Rate "
    "-v 210,raw48,Success_RAIN_Recov_Cnt "
    "-v 246,raw48,Total_LBAs_Written "
    "-v 247,raw48,Host_Program_Page_Count "
    "-v 248,raw48,FTL_Program_Page_Count"
  }
