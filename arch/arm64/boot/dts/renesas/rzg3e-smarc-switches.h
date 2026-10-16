/* SPDX-License-Identifier: (GPL-2.0-only OR BSD-2-Clause) */
/*
 * Switch and peripheral selections for the Renesas RZ/G3E SMARC Module
 * and RZ SMARC Carrier II boards.
 *
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
 * @SW_SD0_DEV_SEL (SYS.1):
 *	SW_OFF - SD0 is connected to eMMC
 *	SW_ON  - SD0 is connected to uSD0
 * @SW_LCD_EN (SYS.5):
 *	SW_OFF - Select miscellaneous signals, including PMOD GPIO/UART
 *	SW_ON  - Select LCD
 * @SW_PDM_EN (BOOT.6):
 *	SW_OFF - Select CAN routing
 *	SW_ON  - Select PDM
 */
#define SW_SD0_DEV_SEL	SW_OFF
#define SW_LCD_EN	SW_OFF
#define SW_PDM_EN	SW_OFF

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
 *	SW_OFF - Disable SER2 UART
 *	SW_ON  - Enable SER2 UART when SER0 is routed to PMOD1
 * @SW_SDIO_M2E:
 *	SW_OFF - SDIO is routed to uSD1
 *	SW_ON  - SDIO is routed to M.2 Key E
 */
#define SW_GPIO8_CAN0_STB	SW_OFF
#define SW_GPIO9_CAN1_STB	SW_OFF
#define SW_SER0_PMOD		SW_ON
#define SW_SER2_EN		SW_ON
#define SW_SDIO_M2E		SW_OFF

/*
 * Display selections:
 * @RZG3E_SMARC_MIPI_DSI_ENABLE: enable MIPI DSI support
 * @RZG3E_SMARC_LVDS_ENABLE:     enable LVDS support
 * @SW_HDMI_EN (when MIPI DSI is enabled):
 *	SW_OFF - Route MIPI DSI to carrier HDMI
 *	SW_ON  - Route MIPI DSI to the module DSI connector
 *
 * Parallel RGB is selected by SW_LCD_EN. At most two displays may be
 * selected at the same time.
 */
#define RZG3E_SMARC_MIPI_DSI_ENABLE	SW_ON
#define RZG3E_SMARC_LVDS_ENABLE		SW_OFF
#define SW_HDMI_EN			SW_OFF

#if (RZG3E_SMARC_MIPI_DSI_ENABLE & RZG3E_SMARC_LVDS_ENABLE & SW_LCD_EN)
#error "Only maximum 2 display selections are enabled at the same time"
#endif

/*
 * PMOD peripheral selections:
 * @RSPI0_RSCI8_SEL:
 *	0 - RSPI0 SPI on PMOD0 Type 2A
 *	1 - BSP RSCI8 SPI on PMOD0 Type 2A
 * @PMOD_GPIO4, @PMOD_GPIO6, @PMOD_GPIO7:
 *	0 - Enable the corresponding user key in Type 2A
 *	1 - Release the key's pin for the attached peripheral
 *	LCD selection always takes priority over GPIO6/7 keys.
 * @PMOD_PWM_ENABLE:
 *	0 - Disable PWM on PMOD1 GPIO8/9
 *	1 - Enable PWM in Type 6A when neither LCD nor CAN owns the pins
 */
#define RSPI0_RSCI8_SEL	0
#define PMOD_GPIO4	0
#define PMOD_GPIO6	0
#define PMOD_GPIO7	0
#define PMOD_PWM_ENABLE	1

#endif /* __RZG3E_SMARC_SWITCHES_H__ */
