//! \note do not move this pre-processor statement to other places
#include "../app_cfg.h"

#ifndef __COMMUNICATION_CFG_H__
#define __COMMUNICATION_CFG_H__

/*============================ INCLUDES ======================================*/
/*============================ MACROS ========================================*/
// <o>The maximum length of parameters <0-128>
//  <i>Default: 128
#ifndef MSG_ARG_LEN
#define MSG_ARG_LEN        128
#endif

// <o>The maximum number of parameters <0-16>
//  <i>Default: 8
#ifndef MSG_ARG_MAX
#define MSG_ARG_MAX        8
#endif

// <o>The maximum number of shell history lines <0-16>
//  <i>Default: 5
#ifndef SHELL_HISTORY_LINES
#define SHELL_HISTORY_LINES    5
#endif

#if (MSG_ARG_LEN * MSG_ARG_MAX) > 1024
#warning "MSG buffer size is large, check RAM usage"
#endif
/*============================ MACROFIED FUNCTIONS ===========================*/
/*============================ TYPES =========================================*/
/*============================ GLOBAL VARIABLES ==============================*/
/*============================ LOCAL VARIABLES ===============================*/
/*============================ PROTOTYPES ====================================*/
 

#endif
/* EOF */

