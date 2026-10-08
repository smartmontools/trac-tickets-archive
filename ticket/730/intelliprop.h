///////////////////////////////////////////////////////////////////////////////
//
// FILENAME: intelliprop.h
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
 * intelliprop.h
 *
 * Home page of code is: http://www.smartmontools.org
 *
 * Copyright (C) 2016 Casey Biemiller
 * Copyright (C) 2002-11 Bruce Allen
 * Copyright (C) 2008-15 Christian Franke
 * Copyright (C) 1999-2000 Michael Cornwell <cornwell@acm.org>
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

#ifndef INTELLIPROP_H_
#define INTELLIPROP_H_


#include "dev_interface.h" // ata_device
#include "atacmds.h" //ATTR_PACKED and ASSERT_SIZEOF_STRUCT

//Vendor Specific log addresses
#define LOG_C0           0xC0
#define PAGE_0           0

//Return Codes
#define IPRSUCCESS          0
#define IPRDEVFAIL          1
#define IPRCODEFAIL         2
#define IPRCMDFAIL          3

//This struct is used for the Vendor Specific log C0 on devices that support it.
#pragma pack(1)
struct iprop_internal_log
{
  uint32_t drive_select;       // Bytes - [  3:  0] of Log C0
  uint32_t obsolete;           // Bytes - [  7:  4] of Log C0
  uint8_t  mode_control;       // Byte  - [      8] of Log C0
  uint8_t  log_passthrough;    // Byte  - [      9] of Log C0
  uint16_t tier_id;            // Bytes - [ 11: 10] of Log C0
  uint32_t hw_version;         // Bytes - [ 15: 12] of Log C0
  uint32_t fw_version;         // Bytes - [ 19: 16] of Log C0
  uint8_t  variant[8];         // Bytes - [ 27: 20] of Log C0
  uint8_t  reserved[228];      // Bytes - [255: 28] of Log C0
  uint16_t port_0_settings[3]; // Bytes - [263:256] of Log C0
  uint16_t port_0_reserved;
  uint16_t port_1_settings[3]; // Bytes - [271:264] of Log C0
  uint16_t port_1_reserved;
  uint16_t port_2_settings[3]; // Bytes - [279:272] of Log C0
  uint16_t port_2_reserved;
  uint16_t port_3_settings[3]; // Bytes - [287:280] of Log C0
  uint16_t port_3_reserved;
  uint16_t port_4_settings[3]; // Bytes - [295:288] of Log C0
  uint16_t port_4_reserved;
  uint8_t  reserved2[214];     // Bytes - [509:296] of Log C0
  uint16_t crc;                // Bytes - [511:510] of Log C0
} ATTR_PACKED;
#pragma pack()
ASSERT_SIZEOF_STRUCT(iprop_internal_log, 512);


// VS LOG MODE CONTROL BITS
enum {
  IPROP_VS_LOG_MODE_CTL_AUTO_SUPPORTED   = (0 << 0), // NOTE: Not supported
  IPROP_VS_LOG_MODE_CTL_MANUAL_SUPPORTED = (1 << 1),
  IPROP_VS_LOG_MODE_CTL_AUTO_ENABLED     = (0 << 2), // NOTE: Not supported
  IPROP_VS_LOG_MODE_CTL_MANUAL_ENABLED   = (1 << 3),
};


// VS LOG PORT SETTING BITS
enum {
  IPROP_VS_LOG_PORT_WRITE_ENABLE_MASK  = 0xC000,
  IPROP_VS_LOG_PORT_WRITE_ENABLE_VALID = 0x8000,
  IPROP_VS_LOG_PORT_RX_DC_GAIN_MASK    = 0x3000,
  IPROP_VS_LOG_PORT_RX_DC_GAIN_SHIFT   = 12,
  IPROP_VS_LOG_PORT_RX_EQ_MASK         = 0x0F00,
  IPROP_VS_LOG_PORT_RX_EQ_SHIFT        = 8,
  IPROP_VS_LOG_PORT_TX_PREEMP_MASK     = 0x00F8,
  IPROP_VS_LOG_PORT_TX_PREEMP_SHIFT    = 3,
  IPROP_VS_LOG_PORT_TX_VOD_MASK        = 0x0007,
  IPROP_VS_LOG_PORT_TX_VOD_SHIFT       = 0,
};

//Used to get options selected in smartctl.cpp to functions in intelliprop.cpp
struct intelliprop_args
{
  bool issue_intelliprop_cmd;
  bool is_routed_cmd;
  int drive_select;
};

void iprop_dump_log_structure(struct iprop_internal_log const * const log);

//The only function that should need to be called for ata devices.
int iprop_main_ata(ata_device * device, intelliprop_args iprop_args);
#endif /* INTELLIPROP_H_ */
