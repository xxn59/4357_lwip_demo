/*
 * DP83640.h
 */

/* Copyright (C) 2010 Texas Instruments Incorporated - www.ti.com
 * ALL RIGHTS RESERVED
 */

#ifndef _PHY_DP83640_H_
#define _PHY_DP83640_H_

#ifdef __cplusplus
extern "C" {
#endif

/** @enum PHY_timestamp
*   @brief Alias names for transmit and receive timestamps
*   This enumeration is used to provide alias names for getting the transmit and receive timestamps from the Dp83640GetTimeStamp API.
*/
typedef enum phyTimeStamp
{
	Txtimestamp = 1, /*Transmit Timestamp*/
	Rxtimestamp = 2 /*Receive Timestamp */
}phyTimeStamp_t;
/* PHY register offset definitions */
#define PHY_BCR                           (0u)
#define PHY_BSR                           (1u)
#define PHY_ID1                           (2u)
#define PHY_ID2                           (3u)
#define PHY_AUTONEG_ADV                   (4u)
#define PHY_LINK_PARTNER_ABLTY            (5u)
#define PHY_TXTS						  (28u)
#define PHY_RXTS						  (29u)

/* PHY status definitions */
#define PHY_ID_SHIFT                      (16u)
#define PHY_SOFTRESET                     (0x8000U)
#define PHY_AUTONEG_ENABLE                (0x1000u)
#define PHY_AUTONEG_RESTART               (0x0200u)
#define PHY_AUTONEG_COMPLETE              (0x0020u)
#define PHY_AUTONEG_INCOMPLETE            (0x0000u)
#define PHY_AUTONEG_STATUS                (0x0020u)
#define PHY_AUTONEG_ABLE                  (0x0008u)
#define PHY_LPBK_ENABLE                   (0x4000u)
#define PHY_LINK_STATUS                   (0x0004u)
#define PHY_INVALID_TYPE				  (0x0u)


/* PHY ID. The LSB nibble will vary between different phy revisions */
#define DP83640_PHY_ID                   (0x0007C0F0u)
#define DP83640_PHY_ID_REV_MASK          (0x0000000Fu)

/* Pause operations */
#define DP83640_PAUSE_NIL                (0x0000u)
#define DP83640_PAUSE_SYM                (0x0400u)
#define DP83640_PAUSE_ASYM               (0x0800u)
#define DP83640_PAUSE_BOTH_SYM_ASYM      (0x0C00u)

/* 100 Base TX Full Duplex capablity */
#define DP83640_100BTX_HD                (0x0000u)
#define DP83640_100BTX_FD                (0x0100u)

/* 100 Base TX capability */
#define DP83640_NO_100BTX                (0x0000u)
#define DP83640_100BTX                   (0x0080u)

/* 10 BaseT duplex capabilities */
#define DP83640_10BT_HD                  (0x0000u)
#define DP83640_10BT_FD                  (0x0040u)

/* 10 BaseT ability*/
#define DP83640_NO_10BT                  (0x0000u)
#define DP83640_10BT                     (0x0020u)

/**************************************************************************
                        API function Prototypes
***************************************************************************/
extern uint32 Dp83640IDGet(uint32 mdioBaseAddr, uint32 phyAddr);
extern void Dp83640Reset(uint32 mdioBaseAddr, uint32 phyAddr);
extern boolean Dp83640AutoNegotiate(uint32 mdioBaseAddr, uint32 phyAddr, uint16 advVal);
extern boolean Dp83640PartnerAbilityGet(uint32 mdioBaseAddr, uint32 phyAddr,uint16 *ptnerAblty);
extern boolean Dp83640LinkStatusGet(uint32 mdioBaseAddr, uint32 phyAddr,volatile uint32 retries);
extern uint64 Dp83640GetTimeStamp(uint32 mdioBaseAddr, uint32 phyAddr, phyTimeStamp_t type);
extern void Dp83640EnableLoopback(uint32 mdioBaseAddr, uint32 phyAddr);
extern void Dp83640DisableLoopback(uint32 mdioBaseAddr, uint32 phyAddr);

#ifdef __cplusplus
}
#endif
#endif
