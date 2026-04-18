#ifndef BOOTLOADER_H_
#define BOOTLOADER_H_
#include ".\app_cfg.h"
#include <stdint.h>
#include <stdbool.h>
#include "../flash_algo/flash_algo.h"
// <o>The user data size
//  <i>Default: 192
#define USER_DATA_SIZE            192

#ifndef NOINIT_SECTION_NAME
    #define NOINIT_SECTION_NAME ".bss.noinit"
#endif

#ifndef NOINIT
    #define NOINIT   __attribute__((section(NOINIT_SECTION_NAME)))
#endif

#ifndef ALIGN
    #define ALIGN(n) __attribute__((aligned(n)))
#endif

typedef struct {
    char chProjectName[16];
    char chHardWareVersion[16];
    char chSoftBootVersion[16];
    char chSoftAppVersion[16];	
} msgSig_t;
typedef struct {
    union {
        msgSig_t sig;
        uint8_t B[USER_DATA_SIZE];
    } msg_data;
} user_magic_data_t;

extern user_magic_data_t tUserMagicData;
extern void enter_bootloader(uint8_t *pchDate, uint16_t hwLength);
extern void begin_download(void);
extern void finalize_download(void);
extern bool clear_magic_enter_app(void);
#endif


