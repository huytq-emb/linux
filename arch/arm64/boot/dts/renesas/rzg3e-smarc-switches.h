/* SPDX-License-Identifier: (GPL-2.0-only OR BSD-2-Clause) */
/*
 * Shared switch selection settings for the RZ/G3E SMARC base DT and overlays.
 * Values describe the selected routing, not the physical DIP switch position.
 * See rzg3e-smarc-som.dtsi and renesas-smarc2.dtsi for the routing options.
 */

#ifndef __RZG3E_SMARC_SWITCHES_H__
#define __RZG3E_SMARC_SWITCHES_H__

#define SW_GPIO8_CAN0_STB	0
#define SW_GPIO9_CAN1_STB	0
#define SW_LCD_EN		0
#define SW_PDM_EN		0
#define SW_SER0_PMOD		1
#define SW_SER2_EN		1
#define SW_SD0_DEV_SEL		0
#define SW_SDIO_M2E		0

#endif /* __RZG3E_SMARC_SWITCHES_H__ */
