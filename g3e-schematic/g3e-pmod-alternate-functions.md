# RZ/G3E SMARC – Alternate functions of SoC pins routed to PMOD

Source: RZ/G3E SMARC Module D019552_04 v0.10, pages 15/17 (SoC pin symbols:
full pin-function lists), cross-checked with RZ SMARC Carrier-II D019232_04
v2.0, page 19 (PMOD level shifters).

Related extracts: [module pin map](g3e-smarc-schematic.md) and
[carrier schematic](g3e-carrier-schematic.md).

Purpose: list every non-reserved pin function shown in the SoC symbols for
the **20 distinct SoC signal pins** routed to PMOD, then filter by what the
carrier hardware allows (level-shifter direction, pull-ups, shared buses).
The three headers have 24 signal-pin positions in total; four signals
(GPIO10–13) are shared between the Type-3A and Type-6A headers.

This document records the supplied supplemental analysis. The module extract
contains the pin-function lists, but not all routing sheets for GPIO6–13,
SER0 or the STG3692 switches. Those routing details require the full module
schematic. A direction-compatible pin assignment is a candidate, not proof
of electrical timing, Linux driver support or operation on hardware.

Legend for "HW path":

- `OUT-only` = TXU0304/TXU0204 buffer SoC → PMOD (cannot receive).
- `IN-only` = TXU buffer PMOD → SoC (cannot drive).
- `BIDIR` = LSF0204 auto-bidirectional + 4K7 pull-up to PWR_PMODx
  (open-drain friendly).
- STG3692 on module (`SW_LCD_EN#=H`) is an analog switch: bidirectional;
  it does not impose the fixed direction of a TXU buffer.

## 1. Full pin-function list per PMOD pin

### PMOD0 (Type-2A header)

| PMOD pin | Default use | SoC pin | HW path | All functions in SoC pin symbol (excluding GPIO/TINT and reserved entries) |
|---|---|---|---|---|
| 1 | SPI CS | PM7 | OUT-only | XSPI0_IO7, SSLA0, CTX3, SDA5, SS8_CTS8N_RTS8N, DE8, PDMDAT12, SSI5_SCK, GTIOC13B, GTIOC13NB, IRQ11 |
| 2 | SPI MOSI | PM5 | OUT-only | XSPI0_IO5, MOSIA, CTXDP3, SDA4, TXD8_MOSI8_SDA8, DE6, PDMDAT11, SSI4_WS, GTIOC12B, GTIOC12NB, USB20_VBUSEN, IRQ9 |
| 3 | SPI MISO | PM4 | IN-only | XSPI0_IO4, MISOA, CRXDP3, SCL4, RXD8_MISO8_SCL8, CTS6N, PDMCLK11, SSI4_SCK, GTIOC12A, GTIOC12NA, USB20_OVRCURN, IRQ8 |
| 4 | SPI SCK | PM6 | OUT-only | XSPI0_IO6, RSPCKA, CRX3, SCL5, SCK8, CTS8N, PDMCLK12, SSI5_SDATA, GTIOC13A, GTIOC13NA, USB20_OTGEXICEN, IRQ10 |
| 7 | GPIO4 / INT | P31 | BIDIR | SDA0, MOSIA, CTXDP3, SDA8, TXD6_MOSI6_SDA6, GTIOC0B, GTIOC0NB, USB20_VBUSEN, SPDIF0_OUT, TIC01, IRQ14 |
| 8 | GPIO5 / RESET | P36 | BIDIR | SCL3, SSLA3, SCL8, SCK7, CTS7N, PDMCLK12, AUDIO_CLKOUT, SSI9_SCK, GTIOC3A, GTIOC3NA, TOC10, IRQ3 |
| 9 | GPIO6 / CS2 | P84 | STG3692 → BIDIR | LCD_B0, SSLA2, CRX1, SCL6, SCK9, CTS9N, AUDIO_CLKC, XSPI0_INT1N, GTIOC7A, GTIOC7NA, USB20_OTGEXICEN, USB21_OVRCURN, GTETRGG, IRQ3 |
| 10 | GPIO7 / CS3 | P85 | STG3692 → BIDIR | LCD_R0, SSLA3, CTX1, SDA6, SS9_CTS9N_RTS9N, DE9, XSPI0_WP0N, AUDIO_CLKOUT, XSPI0_ECS1N, GTIOC7B, GTIOC7NB, USB21_VBUSEN, GTETRGH, IRQ4 |

### PMOD1 (Type-3A / Type-6A headers)

| PMOD pin | Default use | SoC pin | HW path | All functions in SoC pin symbol (excluding GPIO/TINT and reserved entries) |
|---|---|---|---|---|
| 3A-1 | UART CTS# | P80 | STG3692 → IN-only | LCD_G1, MOSIA, CRX0, SCL8, SCK4, CTS4N, CTS8N, SD0CD, XSPI0_WP1N, XSPI0_WP0N, USB21_OVRCURN, USB30_VBUSEN, GTETRGG, IRQ15 |
| 3A-2 | UART TXD | P77 | STG3692 → OUT-only | LCD_R2, MISOA, CTXDP0, SDA7, TXD4_MOSI4_SDA4, XSPI0_ECS1N, USB30_VBUSEN, USB21_OVRCURN, GTETRGF, IRQ14 |
| 3A-3 | UART RXD | P76 | STG3692 → IN-only | LCD_B2, SSLC3, CRXDP0, SCL7, RXD4_MISO4_SCL4, XSPI0_INT1N, USB30_OVRCURN, USB21_VBUSEN, GTETRGE, IRQ13 |
| 3A-4 | UART RTS# | P81 | STG3692 → OUT-only | LCD_B1, RSPCKA, CTX0, SDA8, SS4_CTS4N_RTS4N, DE4, CTS9N, SD0WP, XSPI0_CS1N, USB21_VBUSEN, USB30_OVRCURN, GTETRGH, IRQ0 |
| 3A-7 / 6A-1 | GPIO10 / INT | P65 | STG3692 → BIDIR | LCD_R5, SSLB2, SCL7, RXD9_MISO9_SCL9, CTS6N, SSI7_SCK, SCL6, TIC30, IRQ5 |
| 3A-8 / 6A-2 | GPIO11 / RESET | P56 | STG3692 → BIDIR | LCD_R7, SSLA3, CRX5, SCL4, SCK7, CTS7N, PDMCLK10, SD1PWEN, GTIOC5A, GTIOC5NA, SCL3, TOC10, IRQ10 |
| 3A-9 / 6A-9 | GPIO12 | P66 | STG3692 → BIDIR | LCD_G4, SSLB3, SDA7, TXD9_MOSI9_SDA9, DE6, SSI7_WS, SDA6, TIC31, IRQ6 |
| 3A-10 / 6A-10 | GPIO13 | P64 | STG3692 → BIDIR | LCD_B5, SSLB1, SDA6, SS8_CTS8N_RTS8N, DE8, PDMDAT12, SSI8_SDATA, GTIOC1B, GTIOC1NB, SDA5, TOC21, IRQ15 |
| 6A-7 | GPIO8 | P54 | STG3692 → BIDIR | LCD_G7, SSLA1, CRXDP5, SCL3, RXD7_MISO7_SCL7, CTS2N, PDMCLK02, SD1CD, SSI6_SCK, GTIOC4A, GTIOC4NA, SCL2, TIC10, IRQ8 |
| 6A-8 | GPIO9 | P55 | STG3692 → BIDIR | LCD_B7, SSLA2, CTXDP5, SDA3, TXD7_MOSI7_SDA7, DE2, PDMDAT02, SD1IOVS, SSI6_WS, GTIOC4B, GTIOC4NB, SDA2, TIC11, IRQ9 |
| 6A-3 | I2C SCL | P32 | BIDIR (+2K2 module pull-up, shared bus) | SCL1, RSPCKA, CRX3, SCL8, SCK6, CTS6N, SSI0_SDATA, GTIOC1A, GTIOC1NA, USB20_OTGEXICEN, SPDIF1_IN, TOC00, IRQ15 |
| 6A-4 | I2C SDA | P33 | BIDIR (+2K2 module pull-up, shared bus) | SDA1, SSLA0, CTX3, SDA8, SS6_CTS6N_RTS6N, DE6, SSI0_SCK, GTIOC1B, GTIOC1NB, SPDIF1_OUT, TOC01, IRQ0 |

Every PMOD GPIO-capable pin also has GPIO + TINT (GPIO interrupt). The
fixed-direction buffers still limit GPIO input/output use on their pins.

## 2. Alternative peripheral candidates (pin-pair matched + direction-checked)

"Yes" below means that the listed signals match the carrier buffer directions.
It does not establish a usable speed or a complete Linux implementation.

| Alternative peripheral | PMOD pins | SoC pins / functions | Direction OK? | Notes |
|---|---|---|---|---|
| SCI8 UART (or simple SPI) | PMOD0 1/2/3/4 | PM5 TXD8 (out), PM4 RXD8 (in), PM6 SCK8 (out), PM7 SS8_CTS8N_RTS8N (out) | Yes | Alternative to RSPI A on same header; UART CTS cannot use an OUT-only path |
| CAN ch3 "DP" pair | PMOD0 2/3 | PM5 CTXDP3 (out), PM4 CRXDP3 (in) | Yes | Needs external CAN transceiver module |
| CAN ch3 (CTX3/CRX3) | PMOD0 1/4 | PM7 CTX3 (out), PM6 CRX3 | **No** – PMOD0 pin 4 is OUT-only | |
| RIIC "8" (SCL8/SDA8) | PMOD0 8/7 | P36 SCL8, P31 SDA8 | Yes (LSF + 4K7) | I2C on GPIO4/5; verify controller mapping as noted below |
| SCI6 TX only | PMOD0 7 | P31 TXD6_MOSI6_SDA6 | Yes | No RXD6 on PMOD |
| CAN ch1 | PMOD0 9/10 | P84 CRX1, P85 CTX1 | Yes | Needs SW_PMOD0_PWR_SLP on GPIO side and an external CAN transceiver |
| I2C "6" (SCL6/SDA6) | PMOD0 9/10 | P84 SCL6, P85 SDA6 | Yes | |
| GPT7 PWM pair | PMOD0 9/10 | P84 GTIOC7A, P85 GTIOC7B | Yes | |
| CAN ch0 | PMOD1-3A 1/4 | P80 CRX0 (in), P81 CTX0 (out) | Yes | Same pins as SER0 CTS/RTS; external CAN transceiver required |
| CAN ch0 "DP" pair | PMOD1-3A 3/2 | P76 CRXDP0 (in), P77 CTXDP0 (out) | Yes | Same pins as SER0 RX/TX; external CAN transceiver required |
| SCI9 UART | PMOD1-3A 7/9 | P65 RXD9, P66 TXD9 | Yes | 2nd UART on PMOD1 (GPIO10/12) |
| I2C "7" / "6" pair | PMOD1 GPIO10/GPIO12 | P65 SCL7/SCL6, P66 SDA7/SDA6 | Yes | |
| SCI7 UART | PMOD1-6A 7/8 | P54 RXD7, P55 TXD7 | Yes | Needs SW_GPIO_CAN_PMOD=PMOD, SW_GPIO_PMOD=ON |
| I2C "3" / "2" pair | PMOD1-6A 7/8 | P54 SCL3/SCL2, P55 SDA3/SDA2 | Yes | |
| GPT4 PWM pair | PMOD1-6A 7/8 | P54 GTIOC4A, P55 GTIOC4B | Yes | |
| SSI6 clock/WS | PMOD1-6A 7/8 | P54 SSI6_SCK, P55 SSI6_WS | Partial | No SSI6 data pin on PMOD |
| PDM mic (CLK02/DAT02) | PMOD1-6A 7/8 | P54 PDMCLK02, P55 PDMDAT02 | Yes | PDM MEMS mic module; electrical timing needs verification |
| Single PWM | PMOD1 GPIO11 / GPIO13 | P56 GTIOC5A, P64 GTIOC1B | Yes | |
| RSPI ch.A on I2C pins | 6A-3/4 | P32 RSPCKA, P33 SSLA0 | Not practical | 2K2 pull-up + shared I2C_GP bus |

Naming note: the symbol lists both SCI simple-I2C names (e.g.
`RXD9_MISO9_SCL9`) and stand-alone `SCLn`/`SDAn`. Map each stand-alone
`SCLn`/`SDAn` (and the second SCL/SDA entry at the end of P5x/P6x pins) to
the correct RIIC/I3C instance and its pinmux code with the RZ/G3E Hardware
Manual pin-function table before writing pinctrl. Likewise, GTIOC channel
numbers do not directly identify a Linux DT node: the supplied board DTS
configures GTIOC4A/B through `&gpt0`.

## 3. Constraints that remove functions

- **Fixed-direction buffers** (IC29 TXU0304 on PMOD0 1–4, IC22 TXU0204 on
  PMOD1-3A 1–4): only functions matching the buffer direction work.
- **PMOD1-3A UART buffer IC22** is enabled only when the `SW_SER0_PMOD`
  control signal is high. This is not the same as a physical DIP switch
  being labelled ON; follow the board's switch-to-signal mapping.
- **All P5x–P8x pins listed here** need module `SW_LCD_EN#=H` (STG3692 S1
  path) to reach the carrier rather than LCD.
- **GPIO8/9/12/13** need `SW_GPIO_PMOD` high (IC17 EN); GPIO8/9 also need
  SW_GPIO_CAN_PMOD on the PMOD side; GPIO10 needs SW_GPIO_OPT_SEL to select
  the PMOD1 path.
- **PMOD0 pins 9/10** require SW_PMOD0_PWR_SLP on the GPIO side for the
  P84/P85 alternatives. Otherwise they carry POWER_BTN#/SLEEP#.
- **LSF0204 + 4K7 pull-up**: candidates include GPIO/I2C/UART/PWM at
  moderate speed. Check the translator datasheet, load and timing before
  choosing a rate; the path is not suitable for analog/ADC signals.
- **I/O voltage**: SoC side is 1.8 V; PMOD side follows PWR_PMODx
  (3.3 V or 5 V).
- **Shared I2C_GP bus**: P32/P33 also serve the DA7212 codec and other
  I2C_GP consumers. Repurposing them would affect those devices.
- **Existing DT consumers** must release pins before another function
  takes them. The supplied default DTS uses P31/P84/P85 for user keys,
  P54/P55 for GPT PWM and P32/P33 for I2C1. RSCI9 is already enabled on
  P82/P83; using it on P65/P66 requires replacing that pin assignment.
- **Not available as complete interfaces on PMOD**: ADC (ANI0xx are
  separate pins), XSPI0 as memory (only IO4–7, with direction limitations),
  SDHI and Ethernet. Individual control-signal functions in the tables
  do not constitute those complete interfaces.

## 4. Overlay configuration in this tree

The shared `arch/arm64/boot/dts/renesas/rzg3e-smarc-switches.h` follows
the naming, include guard and comment style of upstream
`rzg3s-smarc-switches.h`. It contains only board `SW_*` selections and
`SW_OFF`/`SW_ON` constants.

| Configuration file | Selectors |
|---|---|
| `rzg3e-smarc-switches.h` | `SW_LCD_EN`, `SW_PDM_EN`, `SW_SD0_DEV_SEL`, `SW_HDMI_EN`, `SW_GPIO8_CAN0_STB`, `SW_GPIO9_CAN1_STB`, `SW_SER0_PMOD`, `SW_SER2_EN`, `SW_SDIO_M2E` |
| `r9a09g047e57-smarc.dts` | `RZG3E_SMARC_MIPI_DSI_ENABLE`, `RZG3E_SMARC_LVDS_ENABLE`, `PMOD_GPIO4`, `PMOD_GPIO6`, `PMOD_GPIO7` |
| Type 2A `.dtso` | `RSPI0_RSCI8_SEL` |

Edit selectors directly in the file listed above rather than overriding
them with compiler `-D` options. Included SoM/carrier files use the
switch definitions from the header. The display-selection check stays
in the base DTS; the UART routing check belongs to Type 3A.
The base DTS also retains the `KEY_*_GPIO` pin-mapping macros.

Rebuild the base DTB and all overlays after changing shared settings.
Changing an overlay-only selector requires rebuilding that overlay and
its composite DTB. PMOD-specific peripherals are enabled by their
respective overlays; the shared I2C1 bus remains enabled in the base DT.

The base DT leaves RSPI0, RSCI8, RSCI4, GPT0 and POEG0GD disabled.
I2C1 pinmux, bus speed and enablement remain in `rzg3e-smarc-som.dtsi`
so that the on-board DA7212 codec is available without a PMOD overlay.
USER_SW1/2/3 are board buttons inherited from `renesas-smarc2.dtsi` and
are enabled by default. The G3E base removes USER_SW1 when `PMOD_GPIO4=1`,
USER_SW2 when `SW_LCD_EN=1` or `PMOD_GPIO6=1`, and USER_SW3 when
`SW_LCD_EN=1` or `PMOD_GPIO7=1`. Set the PMOD GPIO selections in the
base DTS and rebuild the base DTB to release those pins, even when no
overlay is loaded. The sleep key remains in the base DT. The
`KEY_1_GPIO`, `KEY_2_GPIO` and `KEY_3_GPIO` mappings in the G3E base
supply the shared carrier definitions.

None of the three PMOD overlays defines, disables or recreates buttons.
A plain SPI overlay does not require removing any buttons.
The shared carrier DTSI and the G3L board DTS are unchanged.

| Overlay | Configuration it enables | Selectors and routing checks |
|---|---|---|
| PMOD0 Type 2A | RSPI0 or BSP RSCI8 SPI | `RSPI0_RSCI8_SEL`: 0 = RSPI0, 1 = RSCI8. `PMOD_GPIO4/6/7` in the base DTS: 0 = keep the board button, 1 = remove it from the base DT. With LCD enabled, USER_SW2/3 remain absent from the base. |
| PMOD1 Type 3A | RSCI4 UART | Compilation fails unless `SW_LCD_EN=0` and `SW_SER0_PMOD=1`. |
| PMOD1 Type 6A | Optional GPT PWM on P54/P55 and POEG0GD; uses I2C1 on P32/P33 already enabled at 100 kHz by the base DT | PWM is enabled when `SW_LCD_EN=0` and both `SW_GPIO8_CAN0_STB`/`SW_GPIO9_CAN1_STB` set to 0. I2C1 configuration is not duplicated in the overlay. |

With `SW_LCD_EN=1`, Type 2A retains SPI and, unless `PMOD_GPIO4=1`,
USER_SW1. Type 6A retains I2C1 but does not configure GPT/POEG or their
pinmux. Type 3A cannot be used with LCD. Build the compatible targets
explicitly instead of requesting all three composites in this mode, once
the LCD board support files are available:

```sh
make ARCH=arm64 CROSS_COMPILE=aarch64-linux-gnu- \
  renesas/r9a09g047e57-smarc.dtb \
  renesas/r9a09g047e57-smarc-pmod0-type-2a.dtb \
  renesas/r9a09g047e57-smarc-pmod1-type-6a.dtb
```

The supplied source snapshot references `renesas-smarc2-rgb.dtsi` but
does not contain that file. A full base-DTB build with `SW_LCD_EN=1` is
therefore currently blocked independently of the PMOD changes. The
overlays themselves can be compiled to check their LCD conditions.

DA7212 audio does not require Type 6A: the codec node, shared I2C1 bus
and pinmux are all available in the base DT. All three PMOD overlays
leave that bus configuration unchanged. Add PMOD I2C
devices under `&i2c1` in Type 6A, using addresses free on the shared bus.
If CAN uses either
GPIO8/9 pin, the entire PWM pair is omitted. The GPT/POEG configuration
and RSCI8 SPI option require the corresponding BSP drivers; the
mainline RSCI UART driver does not implement `renesas,rsci_spi`.

The header does not read or change physical switches. For PMOD UART,
SYS.5 must be OFF and SW_OPT_MUX.4 OFF (SER0 routed to PMOD). GPIO6/7
require GPIO routing on SW_PMOD0_PWR_SLP and LCD off. PWM requires LCD
off, SW_GPIO_CAN_PMOD on the PMOD side and SW_GPIO_PMOD enabling IC17.
Select the PMOD supply with PMOD_PWR_SEL.

These conditions protect artifacts built with the same header settings.
An overlay built with LCD off can still conflict with a base DTB built
with LCD on: the overlay loader does not check preprocessor settings.
Deploy matching artifacts together. Rebuild from the base DT when
changing modes; stacking another version of an overlay does not remove
nodes added by an earlier version. Releasing a key or PWM pin does not
by itself configure an alternative peripheral or change hardware routing.
