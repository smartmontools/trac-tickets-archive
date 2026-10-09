/*
 * drivedb.h - smartmontools drive database file
 *
 * Home page of code is: https://www.smartmontools.org
 *
 * Copyright (C) 2003-11 Philip Williams, Bruce Allen
 * Copyright (C) 2008-24 Christian Franke
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*
 * Structure used to store drive database entries:
 *
 * struct drive_settings {
 *   const char * modelfamily;
 *   const char * modelregexp;
 *   const char * firmwareregexp;
 *   const char * warningmsg;
 *   const char * presets;
 * };
 *
 * The elements are used in the following ways:
 *
 *  modelfamily     Informal string about the model family/series of a
 *                  device. Set to "" if no info (apart from device id)
 *                  known.  The entry is ignored if this string starts with
 *                  a dollar sign.  Must not start with "USB:", see below.
 *  modelregexp     POSIX extended regular expression to match the model of
 *                  a device.  This should never be "".
 *  firmwareregexp  POSIX extended regular expression to match a devices's
 *                  firmware.  This is optional and should be "" if it is not
 *                  to be used.  If it is nonempty then it will be used to
 *                  narrow the set of devices matched by modelregexp.
 *  warningmsg      A message that may be displayed for matching drives.  For
 *                  example, to inform the user that they may need to apply a
 *                  firmware patch.
 *  presets         String with vendor-specific attribute ('-v') and firmware
 *                  bug fix ('-F') options.  Same syntax as in smartctl command
 *                  line.  The user's own settings override these.
 *
 * The regular expressions for drive model and firmware must match the full
 * string.  The effect of "^FULLSTRING$" is identical to "FULLSTRING".
 * The form ".*SUBSTRING.*" can be used if substring match is desired.
 *
 * The table will be searched from the start to end or until the first match,
 * so the order in the table is important for distinct entries that could match
 * the same drive.
 *
 *
 * Format for USB ID entries:
 *
 *  modelfamily     String with format "USB: DEVICE; BRIDGE" where
 *                  DEVICE is the name of the device and BRIDGE is
 *                  the name of the USB bridge.  Both may be empty
 *                  if no info known.
 *  modelregexp     POSIX extended regular expression to match the USB
 *                  vendor:product ID in hex notation ("0x1234:0xabcd").
 *                  This should never be "".
 *  firmwareregexp  POSIX extended regular expression to match the USB
 *                  bcdDevice info.  Only compared during search if other
 *                  entries with same USB vendor:product ID exist.
 *  warningmsg      Not used yet.
 *  presets         String with one device type ('-d') option.
 *
 */

/*
const drive_settings builtin_knowndrives[] = {
 */
  {
  "SQFlash SATA SSDs ", // See SQFlash SMART ID Definition(SATA)_v1.5.1_Y2024.pdf
  "SQF-S25V4-1TDSDC|SQF-S25Z8-960GDSCC|SQF-S25V4-1T-SBC|SQF-S25C9-960GDCGE",
  "SHFMA21[123]|SCFIP5A0|SBFMA61[123]|SCEBH5A0",
  "",
  // Comment out DEFAULT-covered attributes
  "-v 1,raw48,Uncorrectable_ECC_Count " 
  "-v 9,raw48,Power_On_Hours " 
  "-v 12,raw48,Power_Cycle_Count " 
  "-v 14,raw48,Device_Capacity " 
  "-v 15,raw48,User_Capacity " 
  "-v 16,raw48,Available_Spare_Block " 
  "-v 17,raw48,Remaining_Spare_Block " 
  "-v 100,raw48,Total_Erase_Count " 
  "-v 168,raw48,SATA_Phy_Error_Count " 
  "-v 173,raw16(avg16),MaxAvgErase_Ct " 
  "-v 174,raw48,Power_Loss_Count " 
  "-v 192,raw48,Power_Loss_Count " 
  "-v 194,tempminmax,Temperature_Celsius " 
  "-v 202,raw48,Life_Used_Percent " 
  "-v 218,raw48,CRC_Error_Count " 
  "-v 231,raw48,Life_Remaining_Percent " 
  "-v 234,raw48,NAND_Read_(Sector) " 
  "-v 235,raw48,NAND_Written_(Sector) " 
  "-v 241,raw48,Host_Write_(Sector) " 
  "-v 242,raw48,Host_Read_(Sector) " 
  "-v 244,raw48,Average_Erase_Count " 
  "-v 245,raw48,Max_Erase_Count " 
  },



/*
}; // builtin_knowndrives[]
 */
