  { "Apacer SSDs",
    "([1248]|1[056]|20|3[02]|40|60|64|80|12[08]|160|240|256|320|480|512|640|960|1024|1280|1920|2048|3840|4096)(GB|TB) SATA Flash Drive|"
    "S[GHTV]250-(M2[48][02]|25) ([1248]|1[056]|20|3[02]|40|60|64|80|12[08]|160|240|256|320|480|512|640|960|1024|1280|1920|2048|3840|4096)(GB|TB) SSD", // tested with 120GB SATA Flash Drive/SFMB6130, SH250-M242 128GB SSD/SFMB8120, ST250-M280 256GB SSD/SFMD6110
    "SFM[BCDEGHJ][0-9A-Z][0-9A-Z][1-9A-Z][0-9A-Z]",
    "",
  //"-v 9,raw24(raw8),Power_On_Hours "
  //"-v 12,raw48,Power_Cycle_Count "
    "-v 163,raw48,Maximum_Erase_Count "
    "-v 164,raw48,Average_Erase_Count "
    "-v 166,raw48,Total_Later_Bad_Blk_Ct "
    "-v 167,raw48,SSD_Protect_Mode "
    "-v 168,raw48,SATA_PHY_Error_Count "
    "-v 171,raw48,Program_Fail_Count "
    "-v 172,raw48,Erase_Fail_Count "
    "-v 175,raw48,Bad_Cluster_Table_Ct "
    "-v 192,raw48,Unexpect_Power_Loss_Ct "
  //"-v 194,tempminmax,Temperature_Celsius "
    "-v 231,raw48,Lifetime_Left "
  //"-v 241,raw48,Total_LBAs_Written "
  }