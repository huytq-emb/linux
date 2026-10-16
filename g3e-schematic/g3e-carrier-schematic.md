---
doc_id: D019232_04
title: RZ SMARC Carrier-II — Schematic (extract, sheets 18–19 of 27)
revision: v2.0
date_printed: "Thu Mar 30 2023"
publisher: Renesas Electronics Europe GmbH
source_pdf: d019232_04_s01_v0200_rz_smarc_carrier_2_schem_range.pdf
sheets_in_extract:
  - {pdf_page: 1, sheet: 18, title: "Audio CODEC"}
  - {pdf_page: 2, sheet: 19, title: "PMOD Interfaces"}
format_note: >
  Machine-readable conversion, transcribed from 400-dpi renders of the vector PDF.
  Signal names are the carrier (SMARC-side) names. Off-page refs use "<sheet><zone>"
  (e.g. 26D4> = sheet 26, zone D4). Sheet 26 is the SMARC edge connector (not in this extract).
---

# RZ SMARC Carrier-II — Audio CODEC & PMOD Interfaces

## 0. Conventions

- **SMARC-side net**: signal coming from the SMARC connector (1.8 V domain).
- **PMOD-side net**: signal after the level shifter, in the `PWR_PMODx` domain (3.3 V or 5 V, jumper-selected).
- `#` = active-low.
- Direction (`IN`/`OUT`/`BI`) = off-page connector symbol as drawn.

---

## 1. Sheet 18 — Audio CODEC

### 1.1 Parts

| Ref | Part | Function |
|---|---|---|
| IC3 | DA7212-01UM | Audio codec (I2S + I2C control) |
| AUDIO | STX-4335-5BGP-S1 | Triple 3.5 mm jack stack: A=Blue (AUX in), B=Lime (Headphone out), C=Pink (MIC in) |
| SPEAKER | header 2-way | Speaker out (pin1 = SP_P, pin2 = SP_N) |
| R2 | 0 Ω | Ties digital GND to analog GND |

### 1.2 Digital interface (IC3)

| IC3 pin | Ball | Net | Dir (off-page) | Off-page xref |
|---|---|---|---|---|
| MCLK | C11 | AUDIO_MCK | IN | 27C4<> |
| BCLK | D4 | I2S0_CK | IN | 27D4> |
| WCLK | D6 | I2S0_LRCK | IN | 27C4> |
| DATIN | C5 | I2S0_SDOUT | IN | 27C4> |
| DATOUT | C7 | I2S0_SDIN | OUT | 27D4< |
| SCL | D8 | I2C_GP_CK | BI | 27D4<> 23B8<> 19E1<> 7C6<> |
| SDA | C9 | I2C_GP_DAT | BI | 27D4<> 23C8<> 19E1<> 7C6<> |

> Codec DATIN ← SoC I2S0_SDOUT (playback); codec DATOUT → SoC I2S0_SDIN (capture). The codec shares **I2C_GP** with PMOD1 (sheet 19, via IC25).

### 1.3 Power (IC3)

| IC3 pin | Ball | Rail | Decoupling |
|---|---|---|---|
| VDD_A | B6 | 1.8V | C214 1 µF |
| VDD_SP | A11 | 3.3V | C206 1 µF |
| VDD_MIC | B14 | 3.3V | C209 1 µF |
| VDD_IO | D10 | 1.8V | C211 1 µF |
| VDIG | D12 | no rail drawn (cap only) | C7 1 µF |
| GND_CP | B2 | GND | — |
| GND_A | B10 | AGND | — |
| DACREF / VMID / VREF | A7 / A9 / B8 | — | C23, C13, C24 1 µF to AGND |


### 1.4 Analog paths

| Path | Codec pins | External circuit | Jack / connector |
|---|---|---|---|
| MIC_L | MIC1_P (C17), MICBIAS1 (A15) | C15 1 µF series into MIC1_P; R6 2K2 bias from MICBIAS1; C22 1 µF on MICBIAS1 | AUDIO pin 5 (Pink) |
| MIC_R | MIC2_P (D16), MICBIAS2 (A17) | C2 1 µF series; R1 2K2 bias from MICBIAS2; C1 1 µF on MICBIAS2 | AUDIO pin 2 (Pink) |
| MIC1_N / MIC2_N | B16 / C15 | no connection drawn | — |
| AUX_L | AUX_L (C13) | L4 ferrite → C16 1 µF series; C9 100 pF + R4 47K to GND | AUDIO pin 35 (Blue) |
| AUX_R | AUX_R (D14) | L1 ferrite → C8 1 µF series; C4 100 pF + R3 47K to GND | AUDIO pin 32 (Blue) |
| HP_L | HP_L (A3) → HPL | L3 ferrite; C26 100 pF to GND | AUDIO pin 25 (Lime) |
| HP_R | HP_R (A5) → HPR | L2 ferrite; C25 100 pF to GND | AUDIO pin 22 (Lime) |
| GND_SENSE | B4 | to HP ground node | — |
| Speaker | SP_P (B12), SP_N (A13) | direct | SPEAKER pin 1 / 2 |
| Charge pump | HPCSP (A1), HPCFP (D2), HPCFN (C3), HPCSN (C1) | C27, C17, C28 1 µF | — |

Jack AUDIO pin 1 → GND; MH1–MH4 → GND. Pins 33/34, 23/24, 3/4 are switch contacts (not connected to nets).

---

## 2. Sheet 19 — PMOD Interfaces

### 2.1 PMOD power selection (`PMOD_PWR_SEL`, 6-way 2 mm header)

| Header pin | Net |
|---|---|
| 1 | 3.3V |
| 2 | 3.3V |
| 3 | PWR_PMOD0 |
| 4 | PWR_PMOD1 |
| 5 | 5V_PMOD |
| 6 | 5V_PMOD |

| Jumper | Result |
|---|---|
| 1-3 (**default**) | PWR_PMOD0 = 3.3 V |
| 3-5 | PWR_PMOD0 = 5 V |
| 2-4 (**default**) | PWR_PMOD1 = 3.3 V |
| 4-6 | PWR_PMOD1 = 5 V |

### 2.2 Level shifters

All A-sides are 1.8 V (SMARC side); B-sides are `PWR_PMODx`.

| Ref | Part | VCCA/REFA | VCCB/REFB | OE/EN | B-side pull-ups | Purpose |
|---|---|---|---|---|---|---|
| IC29 | TXU0304RUTR (fixed-direction) | 1.8V | PWR_PMOD0 | OE = 1.8V (always on) | none | PMOD0 SPI |
| IC31 | LSF0204GU12X (bidirectional) | 1.8V | PWR_PMOD0 | EN = 1.8V (always on) | R87, R85, R84, R81 = 4K7 to PWR_PMOD0 | PMOD0 GPIO4–7 |
| IC22 | TXU0204RUTR (fixed-direction) | 1.8V | PWR_PMOD1 | **OE = SW_SER0_PMOD** | none | PMOD1 UART (Type-3A) |
| IC17 | LSF0204GU12X | 1.8V | PWR_PMOD1 | **EN = SW_GPIO_PMOD** | R48, R47, R45, R44 = 4K7 to PWR_PMOD1 | PMOD1 GPIO12/13/8/9 |
| IC25 | LSF0204GU12X | 1.8V | PWR_PMOD1 | EN = 1.8V (always on) | R67, R65, R62, R59 = 4K7 to PWR_PMOD1 | PMOD1 GPIO10/11 + I2C_GP |

Decoupling: C148, C152 (1.8V), C151, C147 (PWR_PMOD0), C228, C131, C94 (1.8V), C130, C229, C93 (PWR_PMOD1) — all 100 nF.

`SW_SER0_PMOD` (xref 23E5< 6B6<> 5C4>) and `SW_GPIO_PMOD` (xref 5E4> 6B6<>) are control signals from sheets 5/6/23 (not in this extract).

#### Level-shifter channel map

| IC | A pin | SMARC-side net | B pin | PMOD-side net | Direction |
|---|---|---|---|---|---|
| IC29 | A1 (2) | SPI1_CK | B1Y (10) | PMOD0_SPI1_CK | SoC → PMOD |
| IC29 | A2 (3) | SPI1_CS0# | B2Y (9) | PMOD0_SPI1_CS0# | SoC → PMOD |
| IC29 | A3 (4) | SPI1_DO | B3Y (8) | PMOD0_SPI1_DO | SoC → PMOD |
| IC29 | A4Y (5) | SPI1_DIN | B4 (7) | PMOD0_SPI1_DIN | PMOD → SoC |
| IC31 | A1 (2) | GPIO4 ("INT") | B1 (10) | PMOD0_GPIO4 | bidir |
| IC31 | A2 (3) | GPIO5 ("RESET") | B2 (9) | PMOD0_GPIO5 | bidir |
| IC31 | A3 (4) | GPIO6 | B3 (8) | PMOD0_GPIO6 | bidir |
| IC31 | A4 (5) | GPIO7 | B4 (7) | PMOD0_GPIO7 | bidir |
| IC22 | A1 (2) | SER0_TX | B1Y (10) | PMOD1_SER0_TX | SoC → PMOD |
| IC22 | A2 (3) | SER0_RTS# | B2Y (9) | PMOD1_SER0_RTS# | SoC → PMOD |
| IC22 | A3Y (4) | SER0_RX | B3 (8) | PMOD1_SER0_RX | PMOD → SoC |
| IC22 | A4Y (5) | SER0_CTS# | B4 (7) | PMOD1_SER0_CTS# | PMOD → SoC |
| IC17 | A1 (2) | GPIO12 | B1 (10) | PMOD1_GPIO12 | bidir |
| IC17 | A2 (3) | GPIO13 | B2 (9) | PMOD1_GPIO13 | bidir |
| IC17 | A3 (4) | GPIO8_PMOD | B3 (8) | PMOD1_GPIO8_PMOD | bidir |
| IC17 | A4 (5) | GPIO9_PMOD | B4 (7) | PMOD1_GPIO9_PMOD | bidir |
| IC25 | A1 (2) | GPIO10_PMOD1 ("INT") | B1 (10) | PMOD1_GPIO10 | bidir |
| IC25 | A2 (3) | GPIO11 ("RESET") | B2 (9) | PMOD1_GPIO11 | bidir |
| IC25 | A3 (4) | I2C_GP_CK | B3 (8) | PMOD1_I2C_GP_CK | bidir |
| IC25 | A4 (5) | I2C_GP_DAT | B4 (7) | PMOD1_I2C_GP_DAT | bidir |

### 2.3 PMOD0 — Type-2A (expanded SPI), connector `PMOD0_2A`

| Pin | PMOD Type-2A role | Net | Source on SMARC side |
|---|---|---|---|
| 1 | CS (out) | PMOD0_SPI1_CS0# | SPI1_CS0# via IC29 |
| 2 | MOSI (out) | PMOD0_SPI1_DO | SPI1_DO via IC29 |
| 3 | MISO (in) | PMOD0_SPI1_DIN | SPI1_DIN via IC29 |
| 4 | SCK (out) | PMOD0_SPI1_CK | SPI1_CK via IC29 |
| 5 | GND | GND | — |
| 6 | VCC | PWR_PMOD0 | — |
| 7 | GPIO/INT | PMOD0_GPIO4 | GPIO4 via IC31 |
| 8 | GPIO/RESET | PMOD0_GPIO5 | GPIO5 via IC31 |
| 9 | GPIO/CS2 | PMOD0_GPIO/CS2 | **switch** `SW_PMOD0_PWR_SLP` (see 2.4) |
| 10 | GPIO/CS3 | PMOD0_GPIO/CS3 | **switch** `SW_PMOD0_PWR_SLP` (see 2.4) |
| 11 | GND | GND | — |
| 12 | VCC | PWR_PMOD0 | C141 4.7 µF |

### 2.4 `SW_PMOD0_PWR_SLP` (CAS-D20A, 2-circuit selector)

| Common pin | Net | Position A | Position B |
|---|---|---|---|
| 2 | PMOD0_GPIO/CS2 (PMOD0 pin 9) | pin 1: POWER_BTN# (OUT, xref 26D7< 7C9<> 5B4>) | pin 3: PMOD0_GPIO6 |
| 5 | PMOD0_GPIO/CS3 (PMOD0 pin 10) | pin 4: SLEEP# (OUT, xref 27E7< 7C9<> 5B4>) | pin 6: PMOD0_GPIO7 |

> PMOD0 pins 9/10 carry **either** the SMARC GPIO6/GPIO7 (level-shifted) **or** POWER_BTN#/SLEEP#, depending on the switch. The schematic does not mark a default position.

### 2.5 PMOD1 — Type-3A (expanded UART), connector `PMOD1_3A`

| Pin | Type-3A role | Net | Source |
|---|---|---|---|
| 1 | CTS/GPIO | PMOD1_SER0_CTS# | SER0_CTS# via IC22 |
| 2 | TXD (out) | PMOD1_SER0_TX | SER0_TX via IC22 |
| 3 | RXD (in) | PMOD1_SER0_RX | SER0_RX via IC22 |
| 4 | RTS/GPIO | PMOD1_SER0_RTS# | SER0_RTS# via IC22 |
| 5 | GND | GND | — |
| 6 | VCC | PWR_PMOD1 | — |
| 7 | GPIO/INT | PMOD1_GPIO10 | GPIO10_PMOD1 via IC25 |
| 8 | GPIO/RESET | PMOD1_GPIO11 | GPIO11 via IC25 |
| 9 | GPIO | PMOD1_GPIO12 | GPIO12 via IC17 |
| 10 | GPIO | PMOD1_GPIO13 | GPIO13 via IC17 |
| 11 | GND | GND | — |
| 12 | VCC | PWR_PMOD1 | C102 4.7 µF |

### 2.6 PMOD1 — Type-6A (expanded I2C), connector `PMOD1_6A`

| Pin | Type-6A role | Net | Source |
|---|---|---|---|
| 1 | INT (in) | PMOD1_GPIO10 | GPIO10_PMOD1 via IC25 |
| 2 | RESET (out) | PMOD1_GPIO11 | GPIO11 via IC25 |
| 3 | SCL | PMOD1_I2C_GP_CK | I2C_GP_CK via IC25 |
| 4 | SDA | PMOD1_I2C_GP_DAT | I2C_GP_DAT via IC25 |
| 5 | GND | GND | — |
| 6 | VCC | PWR_PMOD1 | — |
| 7 | IO5 | PMOD1_GPIO8_PMOD | GPIO8_PMOD via IC17 |
| 8 | IO6 | PMOD1_GPIO9_PMOD | GPIO9_PMOD via IC17 |
| 9 | IO7 | PMOD1_GPIO12 | GPIO12 via IC17 |
| 10 | IO8 | PMOD1_GPIO13 | GPIO13 via IC17 |
| 11 | GND | GND | — |
| 12 | VCC | PWR_PMOD1 | C62 4.7 µF |

> PMOD1_3A and PMOD1_6A are two physical connectors sharing `PWR_PMOD1` and the nets PMOD1_GPIO10/11/12/13.

---

## 3. Cross-reference to RZ/G3E SMARC Module (D019552_04 v0.10, sheets 15–17)

| Carrier signal | Module net | RZ/G3E port (ball) | Usable SoC functions on that pin |
|---|---|---|---|
| SPI1_DIN | SPI1_DIN | PM4 (AA3) | MISOA / RXD8_MISO8_SCL8 |
| SPI1_DO | SPI1_DO | PM5 (AB2) | MOSIA / TXD8_MOSI8_SDA8 |
| SPI1_CK | SPI1_CK | PM6 (AA1) | RSPCKA / SCK8 |
| SPI1_CS0# | SPI1_CS0# | PM7 (AA2) | SSLA0 / SS8_CTS8N_RTS8N |
| GPIO4 | GPIO4 | P31 (AJ4) | GPIO |
| GPIO5 | GPIO5 | P36 (AH3) | GPIO |
| I2C_GP_CK | I2C_GP_CK | P32 (AH5) | SCL1 |
| I2C_GP_DAT | I2C_GP_DAT | P33 (AG10) | SDA1 |
| GPIO6, GPIO7, GPIO8_PMOD, GPIO9_PMOD, GPIO10_PMOD1, GPIO11, GPIO12, GPIO13, SER0_*, POWER_BTN#, SLEEP#, I2S0_*, AUDIO_MCK | — | **not on module sheets 15–17** | needs other module sheets |


## 4. Supplemental PMOD analysis

See [PMOD alternate functions](g3e-pmod-alternate-functions.md) for the
per-pin function tables, candidate peripherals and carrier path constraints.
