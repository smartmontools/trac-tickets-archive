  { "Advantech SSDs and mSATA Devices",
    // see https://advdownload.advantech.com/productfile/Downloadfile1/1-2INXOU4/SQFlash%20SMART%20ID%20Definition(SATA)_v1.5.1_Y2023.pdf
    "SQF-SHMM2-(32|64)G-.*|"	// tested with SQF-SHMM2-32G-S9E, SQF-SHMM2-64G-SBE
    "SQF-S25S4-(16|32)G-.*|"	// tested with SQF-S25S4-16G-S8E SQF-S25S4-32G-S9E
    "SQF-S25M4-64G-.*",		// tested with SQF-S25M4-64G-SBE
    "", "",
    "-v 9,raw48,Power_On_Hours "		// override default raw24(raw8) format
    "-v 14,raw48,Device_Capacity "
    "-v 15,raw48,User_Capacity "
    "-v 16,raw48,Initial_Spare_Blocks "
    "-v 17,raw48,Spare_Blocks_Remaining "
    "-v 100,raw48,Total_Erase_Count "
    "-v 168,raw48,SATA_PHY_Error_Count "
    "-v 170,raw16(raw16),Bad_Block_Count "
    "-v 173,raw16(raw16),Erase_count "
    "-v 174,raw48,Unexpect_Power_Loss_Ct "
    "-v 175,raw16(raw16),Power_Fail_Prot_Stat "
    "-v 192,raw48,Unexpect_Power_Loss_Ct "
    "-v 202,raw48,Perc_Spares_Remain "
    "-v 218,raw48,CRC_error "
    "-v 231,raw48,Perc_SSD_Life_Remain "
    "-v 234,raw48,Total_NAND_Read "
    "-v 235,raw48,Total_NAND_Written "
    "-v 241,raw48,Total_Host_Write "
    "-v 242,raw48,Total_Host_Read "
    "-v 244,raw48,Average_Erase_Count "
    "-v 245,raw48,Max_Erase_Count "
  }
