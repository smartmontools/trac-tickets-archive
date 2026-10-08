  { "Kingston SSDNow V Series SSDs",
    "Kingston SSDNow V Series [0-9]*GB",
    "", "",
  //"-v 9,raw48,Power_On_Hours " // raw value always 0?
  //"-v 12,raw48,Power_Cycle_Count "
  //"-v 194,tempminmax,Temperature_Celsius " // raw value always 0?
    "-v 229,hex64:w012345r,Halt_System/Flash_ID " // Halt, Flash[7]
    "-v 232,hex64:w012345r,Firmware_Version_Info " // "YYMMDD", #Channels, #Banks
    "-v 233,hex48:w01234,ECC_Fail_Record " // Fail number, Row[3], Channel, Bank
    "-v 234,raw24/raw24:w01234,Avg/Max_Erase_Ct "
    "-v 235,raw24/raw24:w01z23,Good/Sys_Block_Ct"
    //  1.....................................40 chars limit for smartmontools < 5.41
  }
