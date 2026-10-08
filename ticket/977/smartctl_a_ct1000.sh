
# bob 2018.08.20 Decode new values for the Cruicial CT1000MX500SSD1, while waiting for the smartmon database to be updated

smartctl \
-v 171,raw48,NAND_Page_Program_Fails \
-v 172,raw48,NAND_Block_Erase_Fails \
-v 173,raw48,Block_Wear_Level_Erases \
-v 174,raw48,Unexpected_Power_Losses \
-v 202,raw48,Lifetime_Remaining \
-v 206,raw48,Program_Fails_MB \
-v 210,raw48,TUs_recovered_RAIN \
-v 246,raw48,Host_Sectors_Written \
-v 247,raw48,Host_Page_Count \
-v 248,raw48,FTL_Page_Count \
-A /dev/sda
