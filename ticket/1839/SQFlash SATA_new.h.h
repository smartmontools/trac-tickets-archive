{
  "SQFlash SATA SSDs", // See SQFlash SMART ID Definition(SATA)_v1.5.1_Y2024.pdf
  "SQFlash (6[456]0|830|840( FIPS)?) Series|SAFM(A2A3|02A[3-6])|SBFM(A611|A612|A613|A614|A615|AH12|AU12|AU13|A011|A012|A013)|SCEM(H2A3|H2A4|H2A5|12A3|12A4|12A5|13A4|MP3A0|I15A1|I15A2|I15A3|IH5A3|IP5A0)|SHFB(A221|A222|A223)|SHFM(A211|A212|A213|A231|A232)|S23A05S|SCPB13.0",
  "",
  // Comment out DEFAULT-covered attributes
  "-v 1,raw48,Uncorrectable_ECC_Count " // Not covered by DEFAULT
  "-v 9,raw48,Power_On_Hours " // Covered by DEFAULT
  "-v 12,raw48,Power_Cycle_Count " // Covered by DEFAULT
  "-v 14,raw48,Device_Capacity " // Custom attribute
  "-v 15,raw48,User_Capacity " // Custom attribute
  "-v 16,raw48,Total_Available_Spare_Block " // Custom attribute
  "-v 17,raw48,Remaining_Spare_Block " // Custom attribute
  "-v 100,raw48,Total_Erase_Count " // Not covered by DEFAULT
  "-v 168,raw48,SATA_Phy_Error_Count " // Not covered by DEFAULT
  "-v 173,raw16(avg16),MaxAvgErase_Ct " // Not covered by DEFAULT
  "-v 174,raw48,Unexpected_Power_Loss_Count " // Not covered by DEFAULT
  "-v 192,raw48,Unexpected_Power_Loss_Count " // Not covered by DEFAULT
  "-v 194,tempminmax,Temperature_Celsius " // Covered by DEFAULT
  "-v 202,raw48,SSD_Life_Used_Percentage " // Not covered by DEFAULT
  "-v 218,raw48,CRC_Error_Count " // Not covered by DEFAULT
  "-v 231,raw48,SSD_Life_Remaining_Percentage " // Not covered by DEFAULT
  "-v 234,raw48,Total_NAND_Read_(Sector) " // Not covered by DEFAULT
  "-v 235,raw48,Total_NAND_Written_(Sector) " // Not covered by DEFAULT
  "-v 241,raw48,Total_Host_Write_(Sector) " // Not covered by DEFAULT
  "-v 242,raw48,Total_Host_Read_(Sector) " // Not covered by DEFAULT
  "-v 244,raw48,Average_Erase_Count " // Not covered by DEFAULT
  "-v 245,raw48,Max_Erase_Count ", // Not covered by DEFAULT
},
