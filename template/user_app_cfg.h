/* WALI Serve config file */
#ifndef __WL_CFG_H__
#define __WL_CFG_H__

// <<< Use Configuration Wizard in Context Menu >>>

// <h>Boot Configuration
// <o>The starting address of the app
//  <i>Default: 0x08020000
//  <i>Must align with flash sector size
#define APP_PART_ADDR        0x08020000

// <o>The reset vector offset in the application
//  <i>Default: 0x4
//  <i>The offset of the reset vector from the application start
#define APP_PART_OFFSET      0x4

// <o>The app size
//  <i>Default: 0x60000
//  <i>Must align with flash sector size
#define APP_PART_SIZE        0x60000

// <o>The Boot Flash Ops Addr
//  <i>Default: 0x08001000
//  <i>Must align with flash sector size
#define BOOT_FLASH_OPS_ADDR  0x08001000
// </h>

// <<< end of configuration section >>>
#endif