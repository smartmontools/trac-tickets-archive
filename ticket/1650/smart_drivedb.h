{
  "SAMSUNG PM897 (HPE Rebranded)",    // Info about model family/series.
  "MK000960GZXRB",   // Regular expression to match model of device.
  "",  // Regular expression to match firmware version(s).
  "This drive was retrieved from Algolia's local smart drive database",    // Warning message.
  //"-v 5,raw16(raw16),Reallocated_Sector_Ct "
  //"-v 9,raw24(raw8),Power_On_Hours "
  //"-v 12,raw48,Power_Cycle_Count "
    "-v 170,raw48,Unused_Rsvd_Blk_Ct_Chip " // CM871
    "-v 171,raw48,Program_Fail_Count_Chip " // CM871
    "-v 172,raw48,Erase_Fail_Count_Chip " // CM871
    "-v 173,raw48,Wear_Leveling_Count " // CM871
    "-v 174,raw48,Unexpect_Power_Loss_Ct " // CM871
  //"-v 175,raw48,Program_Fail_Count_Chip "
  //"-v 176,raw48,Erase_Fail_Count_Chip "
  //"-v 177,raw48,Wear_Leveling_Count "
  //"-v 178,raw48,Used_Rsvd_Blk_Cnt_Chip "
  //"-v 179,raw48,Used_Rsvd_Blk_Cnt_Tot "
  //"-v 180,raw48,Unused_Rsvd_Blk_Cnt_Tot "
  //"-v 181,raw48,Program_Fail_Cnt_Total "
  //"-v 182,raw48,Erase_Fail_Count_Total "
  //"-v 183,raw48,Runtime_Bad_Block "
  //"-v 184,raw48,End-to-End_Error " // SM843T Series
    "-v 187,raw48,Uncorrectable_Error_Cnt "
  //"-v 190,tempminmax,Airflow_Temperature_Cel "  // seems to be some sort of temperature value for 470 Series?
    "-v 191,raw48,Unknown_Samsung_Attr " // PM810
  //"-v 194,tempminmax,Temperature_Celsius "
    "-v 195,raw48,ECC_Error_Rate "
  //"-v 196,raw16(raw16),Reallocated_Event_Count "
  //"-v 197,raw48,Current_Pending_Sector " // PM893
  //"-v 198,raw48,Offline_Uncorrectable "
    "-v 199,raw48,CRC_Error_Count "
    "-v 201,raw48,Supercap_Status "
    "-v 202,raw48,Exception_Mode_Status " // PM893
  //"-v 233,raw48,Media_Wearout_Indicator " // PM851, 840
    "-v 234,raw48,Unknown_Samsung_Attr " // PM851, 840
    "-v 235,raw48,POR_Recovery_Count " // PM851, 830/840/850, PM893
    "-v 236,raw48,Unknown_Samsung_Attr " // PM851, 840
    "-v 237,raw48,Unknown_Samsung_Attr " // PM851, 840
    "-v 238,raw48,Unknown_Samsung_Attr " // PM851, 840
  //"-v 241,raw48,Total_LBAs_Written "
  //"-v 242,raw48,Total_LBAs_Read " // PM851, SM841N
    "-v 243,raw48,SATA_Downshift_Ct " // PM863, PM893
    "-v 244,raw48,Thermal_Throttle_St " // PM863, PM893
    "-v 245,raw48,Timed_Workld_Media_Wear " // PM863, PM893
    "-v 246,raw48,Timed_Workld_RdWr_Ratio " // PM863, PM893
    "-v 247,raw48,Timed_Workld_Timer " // PM863, PM893
    "-v 249,raw48,NAND_Writes_1GiB " // CM871a, PM871
    "-v 250,raw48,SATA_Iface_Downshift " // from the spec
    "-v 251,raw48,NAND_Writes" // PM863, PM893
}
