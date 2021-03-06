/** @file HL_reg_pmm.h
*   @brief PMM Register Layer Header File
*   @date 20.May.2014
*   @version 04.00.00
*   
*   This file contains:
*   - Definitions
*   - Types
*   .
*   which are relevant for the PMM driver.
*/

/* (c) Texas Instruments 2009-2013, All rights reserved. */

#ifndef __REG_PMM_H__
#define __REG_PMM_H__

#include "HL_sys_common.h"

/* USER CODE BEGIN (0) */
/* USER CODE END */

/* Pmm Register Frame Definition */
/** @struct pmmBase
*   @brief Pmm Register Frame Definition
*
*   This type is used to access the Pmm Registers.
*/
/** @typedef pmmBase_t
*   @brief Pmm Register Frame Type Definition
*
*   This type is used to access the Pmm Registers.
*/
typedef volatile struct pmmBase
{
    uint32 LOGICPDPWRCTRL0;      /**< 0x0000: Logic Power Domain Control Register 0 */
    uint32 LOGICPDPWRCTRL1;      /**< 0x0000: Logic Power Domain Control Register 1 */	
    uint32 rsvd1[6U];            /**< 0x0008 - 0x001C: Reserved*/
    uint32 PDCLKDIS;             /**< 0x0020: Power Domain Clock Disable Register */
    uint32 PDCLKDISSET;          /**< 0x0024: Power Domain Clock Disable Set Register */
    uint32 PDCLKDISCLR;          /**< 0x0028: Power Domain Clock Disable Clear Register */
    uint32 rsvd2[5U];            /**< 0x002C - 0x003C: Reserved */
    uint32 LOGICPDPWRSTAT[5U];   /**< 0x0040 - 0x0050: Logic Power Domain Power Status Register 
                                        - 0: PD2
                                        - 1: PD3
                                        - 2: PD4
                                        - 3: PD5 
                                        - 4: PD6 */
    uint32 rsvd3[19U];           /**< 0x0054 - 0x009F: Reserved*/
    uint32 GLOBALCTRL1;          /**< 0x00A0: Global Control Register 1 */
    uint32 rsvd4;                /**< 0x00A4: Reserved */
    uint32 GLOBALSTAT;           /**< 0x00A8: Global Status Register */
    uint32 PRCKEYREG;            /**< 0x00AC: PSCON Diagnostic Compare Key Register */
    uint32 LPDDCSTAT1;           /**< 0x00B0: LogicPD PSCON Diagnostic Compare Status Register 1 */
    uint32 LPDDCSTAT2;           /**< 0x00B4: LogicPD PSCON Diagnostic Compare Status Register 2 */
    uint32 rsvd5;                /**< 0x00B8: Reserved */
    uint32 rsvd6;                /**< 0x00BC: Reserved */	
    uint32 ISODIAGSTAT;          /**< 0x00C0: Isolation Diagnostic Status Register */
}pmmBase_t;


/** @def pmmREG
*   @brief Pmm Register Frame Pointer
*
*   This pointer is used by the Pmm driver to access the Pmm registers.
*/
#define pmmREG ((pmmBase_t *)0xFFFF0000U)

/* USER CODE BEGIN (1) */
/* USER CODE END */


#endif
