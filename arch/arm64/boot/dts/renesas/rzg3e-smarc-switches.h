/* SPDX-License-Identifier: (GPL-2.0-only OR BSD-2-Clause) */
/*
 * Switch selections for the Renesas RZ/G3E SMARC Module
 * and RZ SMARC Carrier II boards.
 *
 * Board switch selections.
 * Build the base DT and overlays with the same settings. These describe
 * logical selections, not necessarily the ON/OFF markings on the DIP
 * switches. Set the physical switches to match the selected routing.
 */

#ifndef __RZG3E_SMARC_SWITCHES_H__
#define __RZG3E_SMARC_SWITCHES_H__

/*
 * Selection states:
 * @SW_OFF: selection is disabled
 * @SW_ON:  selection is enabled
 */
#define SW_OFF		0
#define SW_ON		1

/*
 * Module routing selections:
 * @SW_LCD_EN (SYS.5):
 *	SW_OFF - Select miscellaneous signals, including PMOD GPIO/UART
 *	SW_ON  - Select LCD
 * @SW_PDM_EN (BOOT.6):
 *	SW_OFF - Select CAN routing
 *	SW_ON  - Select PDM
 * @SW_SD0_DEV_SEL (SYS.1):
 *	SW_OFF - SD0 is connected to eMMC
 *	SW_ON  - SD0 is connected to uSD0 card
 * @SW_HDMI_EN (when MIPI DSI is enabled):
 *	SW_OFF - Route MIPI DSI to carrier HDMI
 *	SW_ON  - Route MIPI DSI to the module DSI connector
 */
#define SW_LCD_EN	SW_OFF
#define SW_PDM_EN	SW_OFF
#define SW_SD0_DEV_SEL	SW_OFF
#define SW_HDMI_EN	SW_OFF

/*
 * Carrier routing selections:
 * @SW_GPIO8_CAN0_STB:
 *	SW_OFF - GPIO8 is routed to PMOD
 *	SW_ON  - GPIO8 is routed to CAN0 transceiver standby
 * @SW_GPIO9_CAN1_STB:
 *	SW_OFF - GPIO9 is routed to PMOD
 *	SW_ON  - GPIO9 is routed to CAN1 transceiver standby
 * @SW_SER0_PMOD:
 *	SW_OFF - SER0 is routed to M.2 Key E UART
 *	SW_ON  - SER0 is routed to PMOD1
 * @SW_SER2_EN:
 *	SW_OFF - Disable SER2
 *	SW_ON  - Enable SER2 when SER0 is routed to PMOD1
 * @SW_SDIO_M2E (SW_OPT_MUX.1):
 *	SW_OFF - SMARC SDIO is connected to uSD1
 *	SW_ON  - SMARC SDIO is connected to M.2 Key E
 */
#define SW_GPIO8_CAN0_STB	SW_OFF
#define SW_GPIO9_CAN1_STB	SW_OFF
#define SW_SER0_PMOD		SW_ON
#define SW_SER2_EN		SW_ON
#define SW_SDIO_M2E		SW_OFF

#endif /* __RZG3E_SMARC_SWITCHES_H__ */
