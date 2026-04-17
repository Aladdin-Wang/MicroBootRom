#ifndef __FLASH_PORT_DEFAULT_H__
#define __FLASH_PORT_DEFAULT_H__
#include "cmsis_compiler.h"	

/* ===================== Flash device Configuration ========================= */ 
typedef struct flash_algo_t flash_algo_t;
extern const  flash_algo_t  onchip_flash_device;
/* flash device table */
#ifndef FLASH_DEV_TABLE
    #define FLASH_DEV_TABLE                                          \
    {                                                                   \
        &onchip_flash_device                                            \
    };                                                                
#endif
/*============================ INCLUDES ======================================*/
/*============================ MACROS ========================================*/
/*============================ MACROFIED FUNCTIONS ===========================*/
/*============================ TYPES =========================================*/
/*============================ GLOBAL VARIABLES ==============================*/
/*============================ LOCAL VARIABLES ===============================*/
/*============================ PROTOTYPES ====================================*/
 

#endif
/* EOF */


