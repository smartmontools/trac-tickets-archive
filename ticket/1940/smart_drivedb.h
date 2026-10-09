{ "Exascend SI4 series SSD",
	// spec rev. 008 found at https://exascend.com/wp-content/uploads/dlm_uploads/2023/07/Exascend-SI4-datasheet-General-Common-PN-V8.pdf
	// tested with EXSI4A960GB-00-GIN001
	"EXSI4[ABM](120|240|480|960|1920|3840|7680|15360)GB-.*",
	"", "",
	"-v 165,raw48,Max_Erase_Count "
        "-v 166,raw48,Min_Erase_Count "
        "-v 167,raw48,Avg_Erase_Count "
        "-v 169,raw48,Remain_Life "
        "-v 170,raw48,Percent_Rsvd_Space_Avail "
        "-v 171,raw48,Program_Fail_Count "
        "-v 172,raw48,Erase_Fail_Count "
        "-v 174,raw48,Unexpect_Power_Loss_Ct "
        "-v 183,raw16(raw16),LT_LnkDwnGrd_Dead/SATA1/2 "
        "-v 249,raw48,Total_NAND_Writes "
        "-v 250,raw16(raw16),Lnk_DwnGrd_Dead/SATA1/2 "
        "-v 251,raw48,Total_SATA_Iface_CRC_Ct "
},
