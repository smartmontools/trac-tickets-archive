// Ticket #168
  { "Intel 320 Series SSDs",
    "INTEL SSDSA[12]CW(040|080|120|160|300|600)G3",
    "",
    "",
  //"-v 3,raw48,Spin_Up_Time "
  //"-v 4,raw48,Start_Stop_Count "
  //"-v 5,raw48,Reallocated_Sector_Ct "
  //"-v 9,raw48,Power_On_Hours "
  //"-v 12,raw48,Power_Cycle_Count "
    "-v 170,raw48,Reserve_Block_Count "
    "-v 171,raw48,Program_Fail_Count "
    "-v 172,raw48,Erase_Fail_Count "
  //"-v 184,raw48,End-to-End_Error "
  //"-v 187,raw48,Reported_Uncorrect "
    "-v 192,raw48,Unsafe_Shutdown_Count "
    "-v 225,raw48,Host_Writes_32MiB "
    "-v 226,raw48,Workld_Media_Wear_Indic " // Timed Workload Media Wear Indicator (percent*1024)
    "-v 227,raw48,Workld_Host_Reads_Perc "  // Timed Workload Host Reads Percentage
    "-v 228,raw48,Workload_Minutes " // 226,227,228 can be reset by 'smartctl -t vendor,0x40'
  //"-v 232,raw48,Available_Reservd_Space "
  //"-v 233,raw48,Media_Wearout_Indicator "
    "-v 241,raw48,Host_Writes_32MiB "
    "-v 242,raw48,Host_Reads_32MiB"
  },
