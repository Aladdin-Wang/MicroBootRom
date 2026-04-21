#ifndef __ATOM_CODE_PORT_H__
#define __ATOM_CODE_PORT_H__
#include "cmsis_compiler.h"	

#undef __CONNECT2
#undef CONNECT2
#undef __CONNECT3
#undef CONNECT3

#define __CONNECT3(__A, __B, __C)         __A##__B##__C
#define __CONNECT2(__A, __B)              __A##__B

#define CONNECT3(__A, __B, __C)           __CONNECT3(__A, __B, __C)
#define CONNECT2(__A, __B)                __CONNECT2(__A, __B)

#ifndef SAFE_NAME
#define SAFE_NAME(__NAME)   CONNECT3(__,__NAME,__LINE__)
#endif

#ifndef safe_atom_code
      #define safe_atom_code()                                         \
              for(  uint32_t SAFE_NAME(temp) =                          \
                          ({uint32_t SAFE_NAME(temp2)=atom_code_port_disable_global_interrupt();  \
                       SAFE_NAME(temp2);}),*SAFE_NAME(temp3) = NULL;    \
                       SAFE_NAME(temp3)++ == NULL;                      \
                      atom_code_port_resume_global_interrupt(SAFE_NAME(temp)))				 					
#endif

static
inline 
uint32_t atom_code_port_disable_global_interrupt(void)
{
    uint32_t tStatus = __get_PRIMASK();
    __disable_irq();
    
    return tStatus;
}

static
inline 
void atom_code_port_resume_global_interrupt(uint32_t tStatus)
{
    __set_PRIMASK(tStatus);
}

/*============================ INCLUDES ======================================*/
/*============================ MACROS ========================================*/
/*============================ MACROFIED FUNCTIONS ===========================*/
/*============================ TYPES =========================================*/
/*============================ GLOBAL VARIABLES ==============================*/
/*============================ LOCAL VARIABLES ===============================*/
/*============================ PROTOTYPES ====================================*/
 

#endif
/* EOF */


