///////////////////////////////////////////////////////////////////////////////
//
// FILENAME: intelliprop.c
// PROJECT : 
// KEYWORDS:
// LANGUAGE: C++
// INTELLIPROP AUTHOR  : caseyb
// CREATED : 07/13/2016
//
// DESCRIPTION:
//
// TESTS USED/CREATED:
//
// REVISION HISTORY: Rev1.0
// Date     Person      Description
// -------- ----------- -------------------------------------------------------
//
// CURRENT ISSUES: none.
//
// REMAINING WORK:
//
//
// This media contains an authorized copy or copies of material owned by
// IntelliProp Inc. This ownership notice and any other notices included in
// machine readable copies must be reproduced on all authorized copies.
//
// This is confidential and unpublished property of IntelliProp Inc.
//
// All rights reserved.
// Copyright [$Year] [IntelliProp Inc.]
//
// Licensed under the IntelliProp Software Products License,
// Version 1.0 (the \"License\");
//
// You may not use this file except in compliance with the IntelliProp
// Software Products License Agreement.
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an \"AS IS\" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//
///////////////////////////////////////////////////////////////////////////////

/*
 * intelliprop.cpp
 *
 * Home page of code is: http://www.smartmontools.org
 *
 * Copyright (C) 2016 Casey Biemiller
 * Copyright (C) 2002-11 Bruce Allen
 * Copyright (C) 2008-15 Christian Franke
 * Copyright (C) 1999-2000 Michael Cornwell <cornwell@acm.org>
 * Copyright (C) 2000 Andre Hedrick <andre@linux-ide.org>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * You should have received a copy of the GNU General Public License
 * (for example COPYING); If not, see <http://www.gnu.org/licenses/>.
 *
 * This code was originally developed as a Senior Thesis by Michael Cornwell
 * at the Concurrent Systems Laboratory (now part of the Storage Systems
 * Research Center), Jack Baskin School of Engineering, University of
 * California, Santa Cruz. http://ssrc.soe.ucsc.edu/
 *
 */

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <ctype.h>

#include "config.h"
#include "int64.h"
#include "atacmds.h"
#include "intelliprop.h"
#include "knowndrives.h"  // get_default_attr_defs()
#include "utility.h"
#include "dev_ata_cmd_set.h" // for parsed_ata_device

/**
 * buffer is a pointer to a buffer of bytes, which should include data and
 *   also CRC if the function is being used to check CRC
 * len is the number of bytes in the buffer (including CRC if it is present)
 * check_crc is a boolean value, set true to check an existing CRC, false
 *   to calculate a new CRC
 *
 * FIXME: This does not currently support a running CRC input
 */
uint16_t iprop_crc16_1(uint8_t * buffer, uint32_t len, bool check_crc)
{
  uint32_t ii, jj;
  uint8_t crc[16];
  uint16_t crc_final = 0;
  uint8_t data;
  uint8_t crc_msb;
  uint8_t data_msb;
  uint32_t total_len;

  // Initialize CRC array
  for (ii = 0; ii < 16; ii++) {
    crc[ii] = 0;
    //crc[ii] = (crc_in >> ii) & 1;
  }

  // If calculating a new CRC, we need to pad the data with extra zeroes
  total_len = check_crc ? len : len + 2;

  // Loop for each byte, plus extra for the CRC itself
  for (ii = 0; ii < total_len; ii++) {
    data = (ii < len) ? buffer[ii] : 0;

    // Loop for each bit
    for (jj = 0; jj < 8; jj++) {
      crc_msb = crc[15];
      data_msb = (data >> (8 - jj - 1)) & 1;

      crc[15] = crc[14] ^ crc_msb;
      crc[14] = crc[13];
      crc[13] = crc[12];
      crc[12] = crc[11];
      crc[11] = crc[10] ^ crc_msb;
      crc[10] = crc[9];
      crc[9] = crc[8] ^ crc_msb;
      crc[8] = crc[7] ^ crc_msb;
      crc[7] = crc[6] ^ crc_msb;
      crc[6] = crc[5];
      crc[5] = crc[4] ^ crc_msb;
      crc[4] = crc[3] ^ crc_msb;
      crc[3] = crc[2];
      crc[2] = crc[1] ^ crc_msb;
      crc[1] = crc[0] ^ crc_msb;
      crc[0] = data_msb ^ crc_msb;
    }
  }

  // Convert CRC array to final value
  for (ii = 0; ii < 16; ii++) {
    if (crc[ii] == 1) {
      crc_final |= (1 << ii);
    } else {
      crc_final &= ~(1 << ii);
    }
  }

  return crc_final;
}


int iprop_switch_routed_drive_ata(ata_device * device, intelliprop_args iprop_args)
{
  // Declare a log page buffer and initialize it with what is on the drive currently
  iprop_internal_log write_payload;
  if (!ataReadLogExt(device, LOG_C0, 0, PAGE_0, &write_payload, 1)) {
    pout("Initial Read Log failed.\n");
  //return IPRDEVFAIL;
  }

  // Check the returned data is good
  uint16_t const crc_check = iprop_crc16_1((uint8_t *)&write_payload,
                                           sizeof(struct iprop_internal_log),
                                           false);
  if (crc_check != 0) {
    pout("Intelliprop WARNING: Received log crc(0x%04X) is invalid!\n", crc_check);
    iprop_dump_log_structure(&write_payload);
    memset(&write_payload, 0, sizeof(struct iprop_internal_log));
  }

  // Modify the current drive select to what we were given
  write_payload.drive_select = (uint32_t)iprop_args.drive_select;
  pout("Intelliprop - Change to port 0x%08X.\n", write_payload.drive_select);
  write_payload.log_passthrough = 0; // TEST (Set to 1, non hydra member drive will abort --> test error handling)
  write_payload.tier_id = 0; // TEST (Set to non-zero, non hydra member drive will abort --> test error handling)

  // Update the CRC area
  uint16_t const crc_new = iprop_crc16_1((uint8_t *)&write_payload,
                                         sizeof(struct iprop_internal_log) - sizeof(uint16_t),
                                         false);
  write_payload.crc = (crc_new >> 8) | (crc_new << 8);

  // Check our CRC work
  uint16_t const crc_check2 = iprop_crc16_1((uint8_t *)&write_payload,
                                            sizeof(struct iprop_internal_log),
                                            false);
  if (crc_check2 != 0) {
    pout("Intelliprop WARNING: Re-calculated log crc(0x%04X) is invalid!\n", crc_check2);
    return IPRCODEFAIL;
  }

  // Apply the Write LOG
  if (!ataWriteLogExt(device, LOG_C0, PAGE_0, &write_payload, 1)) {
    pout("Write Log failed.\n");
    return IPRDEVFAIL;
  }

  // Check that the Write LOG was applied
  iprop_internal_log check_payload;
  if (!ataReadLogExt(device, LOG_C0, 0, PAGE_0, &check_payload, 1)) {
    pout("Secondary Read Log failed.\n");
    return IPRDEVFAIL;
  }

  if (check_payload.drive_select != write_payload.drive_select) {
    pout("Current drive select val(0x%08X) is not expected(0x%08X)!\n",
         check_payload.drive_select,
         write_payload.drive_select);
    iprop_dump_log_structure(&check_payload);
    return IPRCMDFAIL;
  }
  return IPRSUCCESS;
}


void iprop_dump_log_structure(struct iprop_internal_log const * const log)
{
  pout("Dumping LOG Structure:\n");
  pout("  drive_select:           0x%08X\n", log->drive_select);
  pout("  obsolete:               0x%08X\n", log->obsolete);
  pout("  mode_control:           0x%02X\n", log->mode_control);
  pout("  log_passthrough:        0x%02X\n", log->log_passthrough);
  pout("  tier_id:                0x%04X\n", log->tier_id);
  pout("  hw_version:             0x%08X\n", log->hw_version);
  pout("  fw_version:             0x%08X\n", log->fw_version);
  pout("  variant:                \"");
  for (int ii = 0; ii < 8; ii++) {
    pout("%c", (char)log->variant[ii]);
  }
  pout("\"\n");
  pout("  port_0_settings(Gen 1): 0x%08X\n", log->port_0_settings[0]);
  pout("  port_0_settings(Gen 2): 0x%08X\n", log->port_0_settings[1]);
  pout("  port_0_settings(Gen 3): 0x%08X\n", log->port_0_settings[2]);
  pout("  port_1_settings(Gen 1): 0x%08X\n", log->port_1_settings[0]);
  pout("  port_1_settings(Gen 2): 0x%08X\n", log->port_1_settings[1]);
  pout("  port_1_settings(Gen 3): 0x%08X\n", log->port_1_settings[2]);
  pout("  port_2_settings(Gen 1): 0x%08X\n", log->port_2_settings[0]);
  pout("  port_2_settings(Gen 2): 0x%08X\n", log->port_2_settings[1]);
  pout("  port_2_settings(Gen 3): 0x%08X\n", log->port_2_settings[2]);
  pout("  port_3_settings(Gen 1): 0x%08X\n", log->port_3_settings[0]);
  pout("  port_3_settings(Gen 2): 0x%08X\n", log->port_3_settings[1]);
  pout("  port_3_settings(Gen 3): 0x%08X\n", log->port_3_settings[2]);
  pout("  port_4_settings(Gen 1): 0x%08X\n", log->port_4_settings[0]);
  pout("  port_4_settings(Gen 2): 0x%08X\n", log->port_4_settings[1]);
  pout("  port_4_settings(Gen 3): 0x%08X\n", log->port_4_settings[2]);
  pout("  crc:                    0x%04X\n", log->crc);
  pout("\n");
}


int iprop_main_ata(ata_device * device, intelliprop_args iprop_args)
{
  if(iprop_args.is_routed_cmd) {
    return iprop_switch_routed_drive_ata(device, iprop_args);
  } else {
    return IPRCMDFAIL;
  }
}
