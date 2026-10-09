{ "Advantech SQFlash 640/650/830/840/910 series SSD",
	// spec rev. 1.5.1 found at https://advdownload.advantech.com/productfile/Downloadfile1/1-2INXOU4/SQFlash%20SMART%20ID%20Definition(SATA)_v1.5.1_Y2023.pdf
	// tested with SQF-S25V4-960GDSCE
	"SQF-S25[VZ]4-(240G|480G|960G|1K9G|3K8G|7K6G|15T3)DSC[CE]",
	"", "",
	"-v 14,raw48,Device_Capacity "
	"-v 15,raw48,User_Capacity "
	"-v 16,raw48,Initial_Spare_Blocks "
	"-v 17,raw48,Spare_Blocks_Remaining "
	"-v 100,raw48,Total_Erase_Count "
	"-v 168,raw48,SATA_PHY_Error_Count "
	"-v 170,raw24/raw24:z54z10,Bad_Blk_Ct_Early/Later "
	"-v 174,raw48,Unexpected_Power_Loss "
	"-v 202,raw48,Percent_Lifetime_Used "
	"-v 218,raw48,CRC_Error_Count "
	"-v 231,raw48,Percent_Life_Left "
	"-v 234,raw48,NAND_Sectors_Read "
	"-v 235,raw48,NAND_Sectors_Written "
	"-v 244,raw48,Average_Erase_Count "
	"-v 245,raw48,Max_Erase_Count "
},
