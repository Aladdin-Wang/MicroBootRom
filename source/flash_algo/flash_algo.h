/****************************************************************************
*  Copyright 2022 KK (https://github.com/WALI-KANG)                                    *
*                                                                           *
*  Licensed under the Apache License, Version 2.0 (the "License");          *
*  you may not use this file except in compliance with the License.         *
*  You may obtain a copy of the License at                                  *
*                                                                           *
*     http://www.apache.org/licenses/LICENSE-2.0                            *
*                                                                           *
*  Unless required by applicable law or agreed to in writing, software      *
*  distributed under the License is distributed on an "AS IS" BASIS,        *
*  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. *
*  See the License for the specific language governing permissions and      *
*  limitations under the License.                                           *
*                                                                           *
****************************************************************************/

#ifndef FLASH_ALGO_H
#define FLASH_ALGO_H
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>
#include "./app_cfg.h"

#ifndef __FLASH_CFG_PORTING_INCLUDE__
#   include "flash_port_default.h"
#else
#   include __FLASH_CFG_PORTING_INCLUDE__
#endif


#define VERS       1           // Interface Version 1.01

#define UNKNOWN    0           // Unknown
#define ONCHIP     1           // On-chip Flash Memory
#define EXT8BIT    2           // External Flash Device on 8-bit  Bus
#define EXT16BIT   3           // External Flash Device on 16-bit Bus
#define EXT32BIT   4           // External Flash Device on 32-bit Bus
#define EXTSPI     5           // External Flash Device on SPI

#define SECTOR_NUM 16         // Max Number of Sector Items

#define FLASH_DRV_VERS (0x0100+VERS)

#define SECTOR_END 0xFFFFFFFF, 0xFFFFFFFF

struct FlashSectors  {
    unsigned long   szSector;    // Sector Size in Bytes
    unsigned long   AddrSector;    // Address of Sector
};

typedef struct FlashDevice  {
    unsigned short  Vers;       // Version Number and Architecture
    char            DevName[128];// Device Name and Description
    unsigned short  DevType;    // Device Type: ONCHIP, EXT8BIT, EXT16BIT, ...
    unsigned long   DevAdr;    // Default Device Start Address
    unsigned long   szDev;    // Total Size of Device
    unsigned long   szPage;    // Programming Page Size
    unsigned long   Res;    // Reserved for future Extension
    unsigned char   valEmpty;    // Content of Erased Memory

    unsigned long   toProg;    // Time Out of Program Page Function
    unsigned long   toErase;    // Time Out of Erase Sector Function

    struct FlashSectors sectors[SECTOR_NUM];
} flash_dev_t;

typedef struct {
    int32_t (*Init)(uint32_t adr, uint32_t clk, uint32_t fnc);
    int32_t (*UnInit)(uint32_t fnc);
    int32_t (*EraseChip)(void);
    int32_t (*EraseSector)(uint32_t adr);
    int32_t (*Program)(uint32_t adr, uint32_t sz, uint8_t* buf);
    int32_t (*Read)(uint32_t adr, uint32_t sz, uint8_t* buf);
} flash_ops_t;

typedef struct flash_algo_t{
    flash_dev_t const *ptFlashDev;
    flash_ops_t tFlashops;
} flash_algo_t;

extern uint32_t get_flash_sector(uint32_t Address);
extern uint32_t get_flash_sector_size(uint32_t Address);
extern bool target_flash_init(uint32_t addr);
extern bool target_flash_uninit(uint32_t addr);
extern int target_flash_write(uint32_t addr, const uint8_t *buf, size_t size);
extern int target_flash_erase(uint32_t addr, size_t size);
extern int target_flash_read(uint32_t addr, uint8_t *buf, size_t size);

#endif
