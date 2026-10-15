---
doc: RZ SMARC Carrier-II schematic (AI-readable conversion)
source: d019232_04_s01_v0200_rz_smarc_carrier_2_schem.pdf
drawing_no: D019232_04
revision: v2.0 (ES Release 2.0, 30/03/2023; WS Release 1.0 16/01/2023)
owner: Renesas Electronics Europe GmbH (REE/IIBU/SDD)
pages: 27 (A3)
form_factor: SMARC 2.1 carrier board
---

# RZ SMARC Carrier-II – Schematic in AI-readable form

## 0. How to read this file
- `Net` = net label as printed in the schematic. `#` suffix = active low. `+/-` = differential pair.
- `Page` = schematic page (1–27). Off-page refs in the PDF use `<page><zone-row><zone-col><dir>` e.g. `26D7<>` = page 26, zone D7, bidirectional.
- SMARC pin `Dir` is relative to the **module**: `IN` = carrier → module, `OUT` = module → carrier, `BI` = bidirectional.
- Switch "ON" on DIP switches = the line is pulled to GND (all DIP commons go to GND; 10K pull-ups to 3.3V unless stated).
- Items marked *(inferred)* were read from the drawing graphics, not from text; verify on the PDF before relying on them.
- Generic datasheet extracts pasted into the PDF (PMOD type tables, mux truth tables, PCIe CEM table) are summarized, not copied.

## 1. System block diagram (page 1)
SMARC module connector → carrier functions:

| SMARC interface | Carrier function | Via |
|---|---|---|
| VDD_IN | 5V_MODULE from USB-C PD power | Power/reset circuitry (p2–4) |
| VDD_RTC | CR927 coin cell or 2.8V local regulator | Jumper VBAT_SEL (p2) |
| CSI1 + I2C_CAM1 | Camera interface 1 (4-lane) | FFC CAM_CSI1 (p9) |
| CSI0 + I2C_CAM0 | Camera interface 0 (2-lane) | FFC CAM_CSI0 (p9) |
| GBE0 / GBE1 | Ethernet 0 / 1 (dual RJ45) | p16 |
| SER3 | USB-micro debug UART | FT234XD (p7) |
| SER1 | 4-pin header (1.8V IO) | p7 |
| SER0, GPIO8–13, I2C_GP | PMOD1 Type-3A / Type-6A | Level shifters (p19); SER0 also muxed to M.2 E |
| SPI1, GPIO4–7 | PMOD0 Type-2A | Level shifters (p19) |
| CAN0 / CAN1 | 2× CAN connectors | TCAN1046V-Q1 (p17) |
| I2S0 | Audio: mic in, headphone out, aux in, speaker | DA7212 codec (p18) |
| USB5, USB4 | Dual stacked USB2.0 Type-A | p11 |
| USB3 (USB3.2 10Gbps) | USB Type-C | HD3SS3220 CC/mux (p13) |
| USB1 | USB2.0 hub → dual Type-A + M.2 Key-E + M.2 Key-B | uPD720115K8 (p10) |
| USB0 | USB2.0 OTG (micro-AB) | p11 |
| I2C_PM | GreenPAK logic, PCIe mux control, current monitor, HD3SS3220 | p4, p6, p13, p20 |
| HDMI | Micro-HDMI (Type D) | HDMI2C1-14HDS ESD/level (p14) |
| LVDS1 | Display connector DISP1 | p15 |
| LVDS0/DSI0 | Display connector DISP0 | p15 |
| I2S2 | MUX → DISP0 or M.2 Key-E | 74CBTLV3257 (p15) |
| SDIO | MUX → microSD or M.2 Key-E | MAX4996L (p8) |
| SER2 (and SER0) | MUX → M.2 Key-E UART | 74CBTLV3257 (p23) |
| PCIE_A/B/C/D | PCIe MUX → PCIe x4 slot, M.2 Key-E, M.2 Key-B | p20–22 |
| USB2 (USB3.2 10Gbps) | MUX → USB Type-A or M.2 Key-B | PI3DBS16212 (p12, p24) |
| SPI0, SATA, I2C_GP, others | General-purpose 24-pin header | p7 |

## 2. Page index

| Page | Title | Main parts |
|---|---|---|
| 1 | Table of contents / block diagram | – |
| 2 | Power Source (USB-C PD sink, alt DC jack, ext 12V, RTC battery) | IC43 CYPD3177, TR2 IRF9358TRPBF, USB-C_PWR_IN UJC-HP-3-SMT-TR, PWR_USB_ALT PJ-002BH-SMT (DNF), PWR_12V_EXT terminal block, BAT_RTC CR927 holder, VBAT_SEL header |
| 3 | 5V Power Regulation | IC24 ISL81401FRZ (4-switch buck-boost), TR4/5/7/8 RJK03M5DNS, L8 3.3µH; IC5 ISL61852ACRZ, IC2 ISL61851DIBZ (load switches) |
| 4 | Other Power Regulation | IC30 ISL95870BIRZ (3.3V buck, TR9/TR10, L9 1.5µH), IC10 ISL80102IRAJZ (1.8V LDO), IC11 ISL97519A (12V boost), IC59 ISL9008AIEJZ-T (2.8V VBAT LDO), IC32 ISL28022FRZ (module current monitor), IC45 TXS0102DCUR |
| 5 | Mode Options (buttons, DIP switches, rotary switch) | SW_MODE, SW_OPT_MUX, SW_PCIE_MUX, SW_M2_DIS, SW_GPIO_OPT_SEL, VBUS_SEL, RESET/POWER/SLEEP buttons |
| 6 | GreenPAK Logic | IC40 SLG4AR45947 (SLG46826V), IC20 SLG4AE45948 (SLG46538V) |
| 7 | User IO (LEDs, buttons, debug UART, GP header, fan, VBAT indicator) | IC47 FT234XD-T, IC46/IC48 74LV1T126GVH, IC60 ISL28915, TR6/TR15 NXV55UN |
| 8 | uSD Card | IC4 MAX4996L (SDIO mux), IC6 SLG59M1557V (USD_VDD switch), SDIO_USD 1040310811 |
| 9 | Camera Interfaces | CAM_CSI0, CAM_CSI1 (22-pin 2-1734592-2) |
| 10 | USB2.0 Hub and Power | IC37 uPD720115K8-711-BAK-A, X1 24MHz, IC35/IC36/IC38 ISL61852ACRZ, TR11 NXV55UN, TR12 2SJ626 |
| 11 | USB2.0 Type-A & OTG | USB5-4_HOST, USB1B-1A_HOST (72309-8014), USB0_OTG (629105150921), ECMF02-4CMX8 filters |
| 12 | USB3.2 Type-A | IC33 PI3DBS16212ZBBEX, IC39 ISL61852CCRZ, USB2_HOST 692122030100 |
| 13 | USB3.2 Type-C | IC42 HD3SS3220RNH, USB3_TYPE-C 1054500101 |
| 14 | Display HDMI | IC34 HDMI2C1-14HDS, D13 BAT54CLT1G, Micro-HDMI Type D |
| 15 | Display External (LVDS/DSI) | DISP0, DISP1 (2041262-1, 52-pin), IC27 74CBTLV3257PGG |
| 16 | Ethernet | ETHERNET1-0 2301997-7 (dual RJ45 with LEDs) |
| 17 | CAN | IC41 TCAN1046V-Q1, CAN0/CAN1 SM03B-SRSS-TB, SW_GPIO_CAN_PMOD |
| 18 | Audio | IC3 DA7212-01UM, AUDIO jack STX-4335-5BGP-S1, SPEAKER header |
| 19 | PMOD Interfaces | IC29 TXU0304RUTR, IC31/IC17/IC25 LSF0204GU12X, IC22 TXU0204RUTR, PMOD0_2A, PMOD1_3A, PMOD1_6A, PMOD_PWR_SEL, SW_PMOD0_PWR_SLP |
| 20 | PCIe Multiplexing Control | IC1 SLG4L45949 (SLG46533V), IC16 SLG4R45950 (SLG46120V), IC15/IC13 QS3VH125 |
| 21 | PCIe Clock Multiplexing | IC9/IC12/IC19 RC19202AGNT, IC8/IC14 RC19004AGNL |
| 22 | PCIe Data Multiplexing | IC18/IC21/IC26/IC44 PI3DBS16222ZLEX (2×2 crossbar), IC23/IC28 PI3DBS16213ZLEX (1:3 mux) |
| 23 | M.2 Key-E (2230) | M2_KEY_E MDT420E01001, IC7 74CBTLV3257PGG (UART mux), OSC1 32.768kHz |
| 24 | M.2 Key-B (2230/3042/3052) | M2_KEY_B MDT420B01001_3052, IC56 PI3DBS16212ZBBEX, M2B_SIM 78646_3001, M2B_GPIO header |
| 25 | PCIe Slot (4-lane) | PCIE_SLOT 10061913-111PLF, SW_PWR_12V, TR1/TR3/TR13 |
| 26 | SMARC 2.1 Connector (Primary) | SMARC_MODULE_CN AS0B826-S55B-7H (P1–P156), RSVD_PWR header |
| 27 | SMARC 2.1 Connector (Secondary) | SMARC_MODULE_CN (S1–S158) |

## 3. Power architecture (pages 2–4, 25)

```
USB-C (USB-C_PWR_IN, PD sink IC43 CYPD3177, 5–20V) ──TR2 (VBUS_FET_EN)──► USBC_VBUS_OUT
Alt DC jack PWR_USB_ALT (DNF, 5–20V, max 5A, only if no USB-C) ─────────► USBC_VBUS_OUT
USBC_VBUS_OUT ─► IC24 ISL81401 buck-boost ─► 5.0V (5V_BOARD)  [PGOOD → VIN_PWR_BAD#]
5.0V ─► IC5 ISL61852 (EN=CARRIER_PWR_ON) ─► 5V_BOARD, 5V_PMOD
5.0V ─► IC2 ISL61851 (EN=CARRIER_PWR_ON) ─► 5V_DISPL0, 5V_DISPL1
USBC_VBUS_OUT ─► IC30 ISL95870 buck ─► 3.3V   [PGOOD → RESET_IN#]
3.3V ─► IC10 ISL80102 LDO (EN=CARRIER_PWR_ON) ─► 1.8V  [PG → RESET_IN#]
5.0V ─► IC11 ISL97519A boost (EN=CARRIER_PWR_ON) ─► 12V (on-board, PCIe slot ≤10W)
5.0V ─► IC59 ISL9008 LDO ─► VBAT_REG (2.8V)
5.0V ─► R94 shunt 0.008Ω (sensed by IC32 ISL28022, I2C via IC45 → I2C_PM) ─► MODULE_PWR jumper ─► 5V_MODULE ─► SMARC VDD_IN  (topology inferred)
PWR_12V_EXT (terminal block) ─► PCIE_EXT_12V ─► PCIe slot 12V when SW_PWR_12V=ON
```

| Item | Setting |
|---|---|
| USB-C PD minimum voltage (VBUS_MIN, rotary VBUS_SEL) | 1: 5V, 2: 9V, 3: 15V, 4: 20V |
| USB-C PD minimum current (ISINK_COARSE, SW_MODE pos 4) | ON: 2A, OFF: 4A |
| VBUS_MAX | Fixed 20V |
| ISNK_FINE | Fixed 0mA |
| VBAT_SEL jumper (RTC) | 1-2: coin cell CR927; 2-3: local regulator VBAT_REG (default) → VDD_RTC |
| SW_PWR_12V (p25) | ON: external 12V (PCIE_EXT_12V), slot up to 75W; OFF (default): on-board 12V, slot limited to 10W |
| MODULE_PWR | 2-way jumper/socket in series with 5V_MODULE (for current measurement) |
| Power LEDs (p7) | VBUS_PWR_ON (green), VBUS_PWR_FAULT (red, from USB_FAULT), SOM_PWR_ON (green, 5.0V), CARRIER_PWR_ON (green, 3.3V), BAT_LOW (red) |
| VBAT indicator (p7) | IC60 ISL28915 compares VDD_RTC vs 2.0V ref → BATLOW# to module (S156) + red LED |

Power sequencing signals: `CARRIER_PWR_ON` (module S154 → enables IC2, IC5, IC10, IC11, USB power, PCIe 12V), `RESET_IN#` (wired-OR of PGOODs + RESET button → module P127), `VIN_PWR_BAD#` (IC24 PGOOD → module S150).

## 4. Configuration switches, buttons and jumpers (page 5 unless noted)

### 4.1 Buttons
| Ref | Part | Net | Module pin |
|---|---|---|---|
| RESET (blue) | PTS645SM43SMTR92LFS | RESET_IN# | P127 |
| POWER (red) | PTS645SK43SMTR92LFS | POWER_BTN# | P128 |
| SLEEP (grey) | PTS645SH43SMTR92LFS | SLEEP# | S149 |
| USER_SW1 (grey, p7) | PTS645SH43 | GPIO4 | P112 |
| USER_SW2 (blue, p7) | PTS645SM43 | GPIO6 | P114 |
| USER_SW3 (blue, p7) | PTS645SM43 | GPIO7 | P115 |

### 4.2 SW_MODE – BOOT select & PD current (4-pos DIP, ON = GND)
| Pos | Net | Function |
|---|---|---|
| 1 | BOOT_SEL0# | Module boot select bit 0 (P123) |
| 2 | BOOT_SEL1# | Module boot select bit 1 (P124) |
| 3 | BOOT_SEL2# | Module boot select bit 2 (P125) |
| 4 | ISINK_COARSE (via R97 3k16) | PD sink min current: ON 2A / OFF 4A |

Boot mode meaning of BOOT_SEL[2:0] is defined by the SMARC module, not the carrier.

### 4.3 SW_OPT_MUX – Multiplexing options (10K pull-up to 3.3V, ON = low)
| Pos | Net | Consumer | Effect (from page notes) |
|---|---|---|---|
| 1 | SW_SDIO_M2E | IC4 MAX4996L (p8), GreenPAK IC20 | L: SDIO → microSD; H: SDIO → M.2 Key-E |
| 2 | SW_I2S2_M2E | IC27 74CBTLV3257 (p15), IC20 | L: I2S2 → DISP0; H: I2S2 → M.2 Key-E |
| 3 | SW_SPARE | IC20 pin "SW_DSI0_HDMI" | Spare (GreenPAK input named SW_DSI0_HDMI) |
| 4 | SW_SER0_PMOD | IC7 UART mux (p23), IC22 OE (p19), IC40 | p23: L: SER0 → M.2 E UART, H: SER2 → M.2 E UART; also gates PMOD1 SER0 level shifter |

### 4.4 SW_PCIE_MUX – PCIe routing (ON = 0)
| Pos | Net |
|---|---|
| 1 | SW_PCIE_MUX0 |
| 2 | SW_PCIE_MUX1 |
| 3 | SW_PCIE_MUX2 |
| 4 | SW_USB2_M2B (IC33/IC56 SEL: USB2 SuperSpeed → Type-A or M.2 Key-B) |

SW_PCIE_MUX[0:2] feed GreenPAK IC1 (data/clock mux control) and IC16 (reset routing). See section 6.

### 4.5 SW_M2_DIS – M.2 disable (passes GreenPAK outputs through to M.2)
| Pos | In (from IC40) | Out (to M.2) |
|---|---|---|
| 1 | S_M2E_W_DISABLE1# | M2E_W_DISABLE1# |
| 2 | S_M2E_W_DISABLE2# | M2E_W_DISABLE2# |
| 3 | S_M2B_RESET# | M2B_RESET# |
| 4 | 3.3V via R121 10K | SW_GPIO_PMOD |

### 4.6 SW_GPIO_OPT_SEL (CAS-D20A slide, p5) – GPIO2/GPIO10 option
Default: GPIO10 ↔ PMOD1 (GPIO10_PMOD1), GPIO2 ↔ DISP_INT#. Alternate positions route GPIO10 ↔ DISP_INT# and GPIO2 ↔ CAM0_RST#. Module nets: GPIO10 (P118), GPIO2/CAM0_RST# (P110).

### 4.7 Other selectors
| Ref | Page | Function |
|---|---|---|
| SW_GPIO_CAN_PMOD (CAS-D20A) | 17 | GPIO8 → GPIO8_CAN0_STB or GPIO8_PMOD; GPIO9 → GPIO9_CAN1_STB or GPIO9_PMOD |
| SW_PMOD0_PWR_SLP (CAS-D20A) | 19 | PMOD0_GPIO/CS2 ← POWER_BTN# or PMOD0_GPIO6; PMOD0_GPIO/CS3 ← SLEEP# or PMOD0_GPIO7 |
| PMOD_PWR_SEL (6-pin, 2mm) | 19 | Selects PWR_PMOD0 / PWR_PMOD1 = 3.3V or 5V_PMOD. Note on drawing: default jumper 1-3, alternative 2-4 *(pin assignment inferred: 1=PWR_PMOD0, 2=PWR_PMOD1, 3/4=3.3V, 5/6=5V_PMOD)* |
| VBAT_SEL | 2 | RTC supply (see section 3) |
| RSVD_PWR (6-pin) | 26 | Connects to module RSVD[0..2] |

## 5. GreenPAK logic (page 6) – both on I2C_PM, VDD=3.3V, VDD2=1.8V
| Device | Inputs | Outputs |
|---|---|---|
| IC40 SLG4AR45947 (generic SLG46826V; program SLG4AR45947_GP_r004U_01102023.gp6) | RESET_OUT#, GPIO12, GPIO13, GPIO8_PMOD, GPIO9_PMOD, I2C_PM | S_M2E_W_DISABLE1#, S_M2E_W_DISABLE2#, S_M2B_RESET# (pin labelled S_M2B_W_DISABLE1#), S_M2B_FULL_CARD_POWER_OFF# (pin S_SPARE), SW_GPIO_PMOD, SW_SER0_PMOD (BI); board-variant resistors R122 (MSB)/R124 (LSB) |
| IC20 SLG4AE45948 (generic SLG46538V; program SLG4AE45948_GP_r002U_11102022.gp5) | USB1_HUB_A_EN#, USB1_HUB_B_EN#, M2B_CONFIG0..3, I2C_PM, DSI0_HDMI_INT# (unconnected pin 17) | USB1_HUB_A_EN, USB1_HUB_B_EN; BI: SW_USB2_M2B, SW_SPARE (SW_DSI0_HDMI), SW_I2S2_M2E, SW_SDIO_M2E |

## 6. PCIe routing (pages 20–22, 25)

Control: IC1 SLG4L45949 (generic SLG46533V) reads SW_PCIE_MUX0..2 + PCIE_SLOT_PRSNT# + I2C_PM and drives S_PCIE_A_SEL1/2, S_PCIE_B_SEL1/2, S_PCIE_SLOT_X, S_PCIE_M2_X, S_PCIE_A_{SLOT,M2E0,M2B}_EN#, S_PCIE_B_{M2E0,M2E1,M2B}_EN#. IC16 SLG4R45950 (generic SLG46120V) maps PCIE_A/B/C_RST# → PCIE_SLOT_RST#, PCIE_M2E_RST0#, PCIE_M2E_RST1#, PCIE_M2B_RST#. IC15/IC13 QS3VH125 route PCIE_A_CKREQ# / PCIE_B_CKREQ# from PCIE_M2E_CKREQ0#/1#, PCIE_M2B_CKREQ#.

Data path (p22): IC23/IC28 PI3DBS16213 (1:3 mux; SEL1/SEL2 = S_PCIE_A_SEL1/2, S_PCIE_B_SEL1/2) route PCIE_A and PCIE_B towards SLOT / M2E / M2B. IC18/IC21/IC26/IC44 PI3DBS16222 (2×2 crossbars, SEL = S_PCIE_SLOT_X or S_PCIE_M2_X) route PCIE_C/PCIE_D and second-lane signals between slot lanes and M.2 lanes *(exact per-IC assignment: see page 22)*. Crossbar truth: SEL=0 → A↔B, C↔D; SEL=1 → A↔D, C↔B; PD=1 → all Hi-Z. 1:3 mux / PI3DBS16212 truth: SEL=L → A↔B, SEL=H → A↔C, PD=H → Hi-Z.

Clock path (p21): PCIE_A_REFCK and PCIE_B_REFCK from module → RC19202AGNT/RC19004AGNL fan-out buffers (output enables = S_PCIE_*_EN#, S_PCIE_SLOT_X, S_PCIE_M2_X) → PCIE_SLOT_REFCK, PCIE_M2E_REFCK0/1, PCIE_M2B_REFCK. PCIE_C_REFCK (P80/P81) is not used.

### 6.1 Usable PCIe configurations (table on page 20)
SW_PCIE_MUX bits shown as MUX0 MUX1 MUX2 (1 = OFF/high). Letters = module PCIe port (A/B/C/D) on that destination. Letters in parentheses are greyed out in the original table.

| Link config | MUX0 | MUX1 | MUX2 | Slot REFCK | Slot L0 | L1 | L2 | L3 | M.2E REFCK0 | M.2E L0 | M.2E REFCK1 | M.2E L1 | M.2B REFCK | M.2B L0 | M.2B L1 |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| 1× PCIe 1-lane | 1 | 0 | 0 | A | A | (B) | (C) | (D) | | | | | | | |
| 1× PCIe 1-lane | 0 | 1 | 1 | (B) | (C) | (D) | | | A | A | (B) | (B) | | | |
| 1× PCIe 1-lane | 1 | 0 | 1 | (B) | (C) | (D) | | | | | | | A | A | (B) |
| 2× PCIe 1-lane | 0 | 1 | 0 | A | A | | (C) | (D) | B | B | | | | | |
| 2× PCIe 1-lane | 0 | 0 | 1 | A | A | | (C) | (D) | | | | | B | B | |
| 2× PCIe 1-lane | 0 | 1 | 1 | B | (C) | (D) | | | A | A | B | B | | | |
| 2× PCIe 1-lane | 1 | 1 | 1 | (B) | | | (C) | (D) | A | A | | | B | B | |
| 1× PCIe 2-lane | 1 | 0 | 0 | A | A | B | (C) | (D) | | | | | | | |
| 1× PCIe 2-lane | 0 | 1 | 1 | (B) | (C) | (D) | | | A | A | (B) | B | | | |
| 1× PCIe 2-lane | 1 | 0 | 1 | (B) | (C) | (D) | | | | | | | A | A | B |
| 2× PCIe 2-lane | 0 | 1 | 1 | B | C | D | | | A | A | B | B | | | |
| 2× PCIe 2-lane | 1 | 0 | 1 | B | C | D | | | | | | | A | A | B |
| 1× PCIe 4-lane | 1 | 0 | 0 | A | A | B | C | D | | | | | | | |
| 1× PCIe 4-lane | 0 | 1 | 1 | (B) | (C) | (D) | | | A | A | (B) | B | | | |
| 1× PCIe 4-lane | 1 | 0 | 1 | (B) | (C) | (D) | | | | | | | A | A | B |

Note: greyed letters in the original likely mean "routed but not part of the active link" *(interpretation)*.

PCIe slot power: SW_PWR_12V selects PCIE_12V source; slot 3.3V from board 3.3V; PCIE_SLOT_PRSNT# → IC1.

## 7. Interface details

### 7.1 microSD / SDIO mux (page 8)
- IC4 MAX4996L: `SDIO_*` (module) ↔ `SDIO_USD_*` (microSD) when SW_SDIO_M2E = L, ↔ `SDIO_M2E_*` (M.2 Key-E) when H.
- IC6 SLG59M1557V: USD_VDD from 3.3V, ON = SDIO_PWR_EN (P37).
- SDIO_CD# (P35) from card detect switch (closed = card inserted). SDIO_WP (P33) not connected.

### 7.2 Cameras (page 9)
- CAM_CSI0 (22-pin): CSI0_CK±, CSI0_RX0±, CSI0_RX1± (2 lanes), I2C_CAM0, CAM0_RST#, CAM0_PWR#, CAM_MCK, 3.3V.
- CAM_CSI1 (22-pin): CSI1_CK±, CSI1_RX0..3± (4 lanes), I2C_CAM1, CAM1_RST#, CAM1_PWR#, CAM_MCK, 3.3V.
- CAM0_RST# reaches module via SW_GPIO_OPT_SEL (GPIO2).

### 7.3 USB (pages 10–13)
| Module port | Path | Connector |
|---|---|---|
| USB0 (OTG) | direct; VBUS switching on p10 (USB0_VBUS_OTG, USB0_VBUS_DET, USB0_EN_OC#; TR11/TR12 *(inferred)*) | USB0_OTG micro-AB |
| USB1 | IC37 uPD720115 hub (24MHz X1, reset = RESET_OUT#) → USB1_HUB_A, USB1_HUB_B, USB1_M2E, USB1_M2B | USB1B-1A_HOST dual Type-A; M.2 E pin 3/5; M.2 B pin 7/9 |
| USB2 (USB3.2) | USB2± direct to Type-A; USB2_SSTX/SSRX via IC33 PI3DBS16212 (SEL = SW_USB2_M2B) → Type-A or M.2 Key-B lane 1 (via IC56) | USB2_HOST Type-A |
| USB3 (USB3.2) | IC42 HD3SS3220 (CC logic + SS mux, I2C_PM, INT → SMB_ALERT#, ID → USB3_OTG_ID, VBUS_DET → USB3_VBUS_DET) | USB3_TYPE-C |
| USB4, USB5 | direct, VBUS switch on p10 (USB4_EN_OC#, USB5_EN_OC#) | USB5-4_HOST dual Type-A |
Hub port power: IC35/IC36 ISL61852 enabled by USB1_HUB_A_EN / USB1_HUB_B_EN (from GreenPAK IC20). USB2/USB3 VBUS: IC39 ISL61852CCRZ (USB2_EN_OC#, USB3_EN_OC#).

### 7.4 Displays (pages 14–15)
- HDMI: module HDMI_D0..2±, HDMI_CK±, HDMI_HPD, HDMI_CTRL_CK/DAT → IC34 HDMI2C1-14HDS → Micro-HDMI Type D; HDMI_5V from 5V_BOARD.
- DISP0 (52-pin): LVDS0/DSI0 lanes, LCD0_VDD_EN, LCD0_BKLT_EN, LCD0_BKLT_PWM, DSI0_TE, DISP_INT#, I2C_LCD, RESET_OUT#, I2S2_DISP0_*, 5V_DISPL0, 3.3V, 1.8V. Pin 52 DISP_ID: open *(inferred from page note order)*.
- DISP1 (52-pin): LVDS1 lanes, LCD1_VDD_EN, LCD1_BKLT_EN, LCD1_BKLT_PWM, DSI1_TE, I2C_LCD, 5V_DISPL1. Pin 52 DISP_ID: ground *(inferred)*.
- IC27 74CBTLV3257: I2S2 (module S50–S53) → I2S2_DISP0_* (S=L) or I2S2_M2E_* (S=H); S = SW_I2S2_M2E.

### 7.5 Ethernet (page 16)
Dual RJ45 (2301997-7): GBE0_MDI0..3± (lower/upper per drawing), GBE1_MDI0..3±; LEDs GBEx_LINK100#, GBEx_LINK1000#, GBEx_LINK_ACT# with 330Ω to 3.3V. GBEx_CTREF and GBEx_SDP not connected.

### 7.6 CAN (page 17)
IC41 TCAN1046V-Q1 dual transceiver, VCC=5V_BOARD, VIO=1.8V. CAN0_TX/RX ↔ CANH1/CANL1 → CAN0 (3-pin SM03B). CAN1_TX/RX ↔ CAN1 connector. Split termination 2×60.4Ω + 22pF per bus, PESD2CAN ESD. STB pins from GPIO8_CAN0_STB / GPIO9_CAN1_STB (via SW_GPIO_CAN_PMOD), 10K pull.

### 7.7 Audio (page 18)
IC3 DA7212 codec, VDD_IO 1.8V, analog 3.3V. Digital: I2S0_CK→BCLK, I2S0_LRCK→WCLK, I2S0_SDOUT→DATIN, I2S0_SDIN←DATOUT, AUDIO_MCK→MCLK, control on I2C_GP. Analog: MIC_L/MIC_R (MIC1/MIC2 inputs), HP_L/HP_R, AUX_L/AUX_R → 3-stack jack STX-4335-5BGP-S1 (blue/lime/pink); SP_P/SP_N → 2-pin SPEAKER header.

### 7.8 User IO (page 7)
- Debug UART: SER3_TX/RX (1.8V) → IC48/IC46 74LV1T126 buffers → IC47 FT234XD-T → ECMF02 filter → micro-USB SER3_UART (VBUS_UART).
- Spare UART: SER1_UART 4-pin header: SER1_RX, SER1_TX, 1.8V IO (pin order per drawing: 1 SER1_RX, 2 SER1_TX, 3 1.8V?, 4 GND *(inferred)*).
- FAN 3-pin header: 12V (R160 0Ω) or 5V (R159 DNF), SENSE unused.

General-purpose header GEN_PURPOSE (24-pin, GRPB122VWQS-RC):

| Pin | Net | Pin | Net |
|---|---|---|---|
| 1 | 1.8V | 2 | 5.0V |
| 3 | BOOT_SEL0# | 4 | POWER_BTN# |
| 5 | BOOT_SEL1# | 6 | RESET_IN# |
| 7 | BOOT_SEL2# | 8 | SLEEP# |
| 9 | 1.8V | 10 | 5.0V |
| 11 | SPI0_CS0# | 12 | GND *(inferred)* |
| 13 | SPI0_CK | 14 | SATA_TX+ |
| 15 | SPI0_DIN | 16 | SATA_TX- |
| 17 | SPI0_DO | 18 | GND *(inferred)* |
| 19 | I2C_GP_CK | 20 | SATA_RX+ |
| 21 | I2C_GP_DAT | 22 | SATA_RX- |
| 23 | GND *(inferred)* | 24 | GND *(inferred)* |

### 7.9 PMOD (page 19) – module side 1.8V, PMOD side PWR_PMOD0/1
| Connector | Pin 1 | 2 | 3 | 4 | 7 | 8 | 9 | 10 | 5/11 | 6/12 |
|---|---|---|---|---|---|---|---|---|---|---|
| PMOD0_2A (Type-2A SPI) | PMOD0_SPI1_CS0# | PMOD0_SPI1_DO | PMOD0_SPI1_DIN | PMOD0_SPI1_CK | PMOD0_GPIO4 | PMOD0_GPIO5 | PMOD0_GPIO/CS2 | PMOD0_GPIO/CS3 | GND | PWR_PMOD0 |
| PMOD1_3A (Type-3A UART) | PMOD1_SER0_CTS# | PMOD1_SER0_TX | PMOD1_SER0_RX | PMOD1_SER0_RTS# | PMOD1_GPIO10 | PMOD1_GPIO11 | PMOD1_GPIO12 | PMOD1_GPIO13 | GND | PWR_PMOD1 |
| PMOD1_6A (Type-6A I2C) | PMOD1_GPIO10 | PMOD1_GPIO11 | PMOD1_I2C_GP_CK | PMOD1_I2C_GP_DAT | PMOD1_GPIO8_PMOD | PMOD1_GPIO9_PMOD | PMOD1_GPIO12 | PMOD1_GPIO13 | GND | PWR_PMOD1 |

Level shifters:
| Ref | Part | Module-side signals | Enable |
|---|---|---|---|
| IC29 | TXU0304RUTR | SPI1_CK, SPI1_CS0#, SPI1_DO → ; SPI1_DIN ← | OE tied (1.8V) |
| IC31 | LSF0204GU12X | GPIO4, GPIO5, GPIO6, GPIO7 | EN 1.8V |
| IC22 | TXU0204RUTR | SER0_TX, SER0_RTS# → ; SER0_RX, SER0_CTS# ← | OE = SW_SER0_PMOD |
| IC17 | LSF0204GU12X | GPIO12, GPIO13, GPIO8_PMOD, GPIO9_PMOD | EN = SW_GPIO_PMOD |
| IC25 | LSF0204GU12X | GPIO10_PMOD1, GPIO11, I2C_GP_CK, I2C_GP_DAT | EN 1.8V |

### 7.10 M.2 Key-E 2230 (page 23)
| Function | M.2 pins → net |
|---|---|
| USB | 3/5 USB_D± ← USB1_M2E± (hub) |
| PCIe0 | 47/49 REFCLK0± ← PCIE_M2E_REFCK0±; 41/43 RX0± → PCIE_M2E_RX0±; 35/37 TX0± ← PCIE_M2E_TX0±; 52 PERST0# ← PCIE_M2E_RST0#; 53 CLKREQ0# ↔ PCIE_M2E_CKREQ0#; 55 PEWAKE0# = M2E_PEWAKE0# → D4 → PCIE_WAKE# |
| PCIe1 | 71/73 REFCLK1± ← PCIE_M2E_REFCK1±; 65/67 RX1±; 59/61 TX1±; 66 PERST1# ← PCIE_M2E_RST1#; 68 CLKREQ1# ↔ PCIE_M2E_CKREQ1#; 70 PEWAKE1# = M2E_PEWAKE1# → D1 → PCIE_WAKE# |
| SDIO | 9 CLK, 11 CMD, 13/15/17/19 D0–D3 ↔ SDIO_M2E_*; 23 SDIO_RESET# ← SDIO_M2E_RESET#; 21 SDIO_WAKE# → test point (10K pull-up) |
| I2S | 8 SCK ← I2S2_M2E_CK; 10 WS ← I2S2_M2E_LRCK; 12 I2S_IN → I2S2_M2E_SDIN; 14 SD_OUT ← I2S2_M2E_SDOUT |
| UART | 32 TXD → M2E_UART_TX; 22 RXD ← M2E_UART_RX; 36 RTS; 34 CTS; 20 UART_WAKE# → test point. IC7 74CBTLV3257: S = SW_SER0_PMOD (L: SER0, H: SER2) |
| I2C | 60 I2C_CLK = I2C_GP_CK; 58 I2C_DATA = I2C_GP_DAT; 62 ALERT# |
| Control | 56 W_DISABLE1# ← M2E_W_DISABLE1#; 54 W_DISABLE2# ← M2E_W_DISABLE2#; 50 SUSCLK ← M2E_SUSCLK (OSC1 32.768kHz via R238; R239 → CLK_32K for M.2 B); 6/16 LED1#/LED2# → red LEDs |
| Power | 2, 4, 72, 74 = 3.3V |

### 7.11 M.2 Key-B 2230/3042/3052 (page 24)
| Function | M.2 pins → net |
|---|---|
| USB2 | 7/9 USB_D± ← USB1_M2B± (hub) |
| PCIe lane 0 | 55/53 REFCLK0± ← PCIE_M2B_REFCK±; 49/47 TX0±; 43/41 RX0±; 50 PERST# ← PCIE_M2B_RST#; 52 CLKREQ# ↔ PCIE_M2B_CKREQ#; 54 PEWAKE# → D6 → PCIE_WAKE# (net label on this page reads M2E_PEWAKE0#) |
| Lane 1 (PCIe or USB3) | 37/35 TX1±, 31/29 RX1± ← IC56 PI3DBS16212 (SEL = SW_USB2_M2B): B port = PCIE_M2B_TX1/RX1±, C port = USB2_SSTX/SSRX_M2B± |
| SIM | 36 UIM-PWR → SIM_PWR, 34 UIM-DATA, 32 UIM-CLK, 30 UIM-RESET → M2B_SIM (78646_3001); 66 SIM_DETECT (R55 DNF) |
| Control | 67 RESET# ← M2B_RESET#; 6 FULL_CARD_POWER_OFF# ← S_M2B_FULL_CARD_POWER_OFF#; 8 W_DISABLE1# (10K); 26 W_DISABLE2# / WAKE_ON_WAN# (10K, D22 → PCIE_WAKE#); 38 DEVSLP; 68 SUSCLK; 25 DPR; 10 LED_1# → M2B_LED1# (red LED) |
| CONFIG | 21/69/75/1 CONFIG_0..3 → M2B_CONFIG0..3 → GreenPAK IC20 |
| GPIO/COEX/ANT | GPIO_0..8 (40,42,44,46,48,20,22,24,28), COEX 64/62/60, ANTCTL0..3 (59,61,63,65), RFFE 56/58 → M2B_GPIO header |
| Power | 2, 4, 70, 72, 74 = 3.3V |
| Spacers | SP_M2B1 Type-3052, SP_M2B2 Type-3042 (threaded), SP_M2B3 Type-2230 (threaded) |

M2B_GPIO header (24-pin): 1 1.8V; 2 M2B_RFFE_CLK; 3 M2B_DEVSLP; 4 M2B_RFFE_DATA; 5 M2B_SUSCLK; 6 CLK_32K; 7 M2B_GPIO_0; 8 M2B_GPIO_8; 9 M2B_GPIO_1; 10 M2B_ANTCTL0; 11 M2B_GPIO_2; 12 M2B_ANTCTL1; 13 M2B_GPIO_3; 14 M2B_ANTCTL2; 15 M2B_GPIO_4; 16 M2B_ANTCTL3; 17 M2B_GPIO_5; 18 M2B_COEX_RXD; 19 M2B_GPIO_6; 20 M2B_COEX_TXD; 21 M2B_GPIO_7; 22 M2B_COEX3; 23 GND; 24 M2B_DPR.

### 7.12 PCIe x4 slot (page 25)
Lanes PCIE_SLOT_TX0..3± / RX0..3± (from p22), PCIE_SLOT_REFCK±, PCIE_SLOT_RST# (PERST#), PCIE_WAKE#, PCIE_SLOT_PRSNT# → IC1. 12V = PCIE_12V (on-board 12V or PCIE_EXT_12V, selected by SW_PWR_12V with TR1/TR3/TR13). 3.3V from board 3.3V.

## 8. Shared control buses
| Bus | Devices on carrier | Module pins |
|---|---|---|
| I2C_PM (CK/DAT) | IC32 ISL28022 (via IC45 level shifter), IC40 + IC20 GreenPAK, IC1 PCIe GreenPAK, IC42 HD3SS3220 | P121/P122 |
| I2C_GP | DA7212 codec, M.2 Key-E I2C, PMOD1 6A, GP header | S48/S49 |
| I2C_LCD | DISP0, DISP1 | S139/S140 |
| I2C_CAM0 / I2C_CAM1 | CAM_CSI0 / CAM_CSI1 | S5/S7, S1/S2 |
| HDMI_CTRL | HDMI DDC via IC34 | P105/P106 |
| PCIE_WAKE# | M.2 E (2 wakes), M.2 B (2 sources), PCIe slot, diode-OR | S146 |
| RESET_OUT# | GreenPAK IC40, USB hub IC37, DISP0/DISP1 | P126 |
| SMB_ALERT# | HD3SS3220 INT | P1 |

## 9. Observations / possible inconsistencies found during conversion
1. SW_OPT_MUX position 3 is labelled `SW_SPARE` on page 5, but the GreenPAK IC20 pin it connects to is named `SW_DSI0_HDMI` (page 6).
2. SW_M2_DIS position 3 net `S_M2B_RESET#` comes from IC40 pin named `S_M2B_W_DISABLE1#`; IC40 pin `S_SPARE` drives `S_M2B_FULL_CARD_POWER_OFF#`.
3. M.2 Key-B PEWAKE# (pin 54) is labelled `M2E_PEWAKE0#` on page 24, the same label as M.2 Key-E pin 55 on page 23 — both then go through separate diodes to PCIE_WAKE#. If labels are global this ties the two wake pins together before the diodes.
4. SMARC P67 USB1_EN_OC# is not used (note "Not required (USB HUB)").
5. Module pins with no carrier connection: GBE0/1_SDP, GBE0/1_CTREF, SPI0_CS1#, SDIO_WP, ESPI_CS1#, PCIE_C_REFCK±, DP1_AUX_SEL, DP0_* (all), ESPI_ALERT0/1#, MDIO, SATA_ACT#, ESPI_IO_2/3, ESPI_RESET#, WDT_TIME_OUT#, LID#, CHARGING#, CHARGER_PRSNT#, CARRIER_STBY#, FORCE_RECOV#.

## 10. Limitations of this conversion
- Derived from the PDF text layer plus visual reading of the drawing. Passive component values are listed only where they define behaviour; a full BOM/netlist (every R/C pin-to-pin connection) is not reconstructable reliably from the PDF.
- SMARC pin → net mapping (section 11) was extracted programmatically by matching pin numbers, pin names and net labels on the same row; "Used on page(s)" comes from off-page references and label occurrence.
- For exact connectivity, use the original EDA netlist/design files if available.

## 11. SMARC 2.1 connector pin map (pages 26–27)
Dir relative to module. `—` = no carrier net on that pin.

### SMARC 2.1 connector – Primary (P1–P156), page 26

| Pin | SMARC signal | Carrier net | Dir* | Used on page(s) |
|---|---|---|---|---|
| P1 | SMB_ALERT# | SMB_ALERT# | IN | 13 |
| P3 | CSI1_CK+ | CSI1_CK+ | IN | 9 |
| P4 | CSI1_CK- | CSI1_CK- | IN | 9 |
| P5 | GBE1_SDP | — |  |  |
| P6 | GBE0_SDP | — |  |  |
| P7 | CSI1_RX0+ | CSI1_RX0+ | IN | 9 |
| P8 | CSI1_RX0- | CSI1_RX0- | IN | 9 |
| P10 | CSI1_RX1+ | CSI1_RX1+ | IN | 9 |
| P11 | CSI1_RX1- | CSI1_RX1- | IN | 9 |
| P13 | CSI1_RX2+ | CSI1_RX2+ | IN | 9 |
| P14 | CSI1_RX2- | CSI1_RX2- | IN | 9 |
| P16 | CSI1_RX3+ | CSI1_RX3+ | IN | 9 |
| P17 | CSI1_RX3- | CSI1_RX3- | IN | 9 |
| P19 | GBE0_MDI3- | GBE0_MDI3- | BI | 16 |
| P20 | GBE0_MDI3+ | GBE0_MDI3+ | BI | 16 |
| P21 | GBE0_LINK100# | GBE0_LINK100# | OUT | 16 |
| P22 | GBE0_LINK1000# | GBE0_LINK1000# | OUT | 16 |
| P23 | GBE0_MDI2- | GBE0_MDI2- | BI | 16 |
| P24 | GBE0_MDI2+ | GBE0_MDI2+ | BI | 16 |
| P25 | GBE0_LINK_ACT# | GBE0_LINK_ACT# | OUT | 16 |
| P26 | GBE0_MDI1- | GBE0_MDI1- | BI | 16 |
| P27 | GBE0_MDI1+ | GBE0_MDI1+ | BI | 16 |
| P28 | GBE0_CTREF | — |  |  |
| P29 | GBE0_MDI0- | GBE0_MDI0- | BI | 16 |
| P30 | GBE0_MDI0+ | GBE0_MDI0+ | BI | 16 |
| P31 | SPI0_CS1# | — |  |  |
| P33 | SDIO_WP | — |  |  |
| P34 | SDIO_CMD | SDIO_CMD | BI | 8 |
| P35 | SDIO_CD# | SDIO_CD# | IN | 8 |
| P36 | SDIO_CK | SDIO_CK | OUT | 8 |
| P37 | SDIO_PWR_EN | SDIO_PWR_EN | OUT | 8 |
| P39 | SDIO_D0 | SDIO_D0 | BI | 8 |
| P40 | SDIO_D1 | SDIO_D1 | BI | 8 |
| P41 | SDIO_D2 | SDIO_D2 | BI | 8 |
| P42 | SDIO_D3 | SDIO_D3 | BI | 8 |
| P43 | SPI0_CS0# | SPI0_CS0# | OUT | 7 |
| P44 | SPI0_CK | SPI0_CK | OUT | 7 |
| P45 | SPI0_DIN | SPI0_DIN | IN | 7 |
| P46 | SPI0_DO | SPI0_DO | OUT | 7 |
| P48 | SATA_TX+ | SATA_TX+ | OUT | 7 |
| P49 | SATA_TX- | SATA_TX- | OUT | 7 |
| P51 | SATA_RX+ | SATA_RX+ | IN | 7 |
| P52 | SATA_RX- | SATA_RX- | IN | 7 |
| P54 | ESPI_CS0# / SPI1_CS0# / QSPI_CS0# | SPI1_CS0# | OUT | 19 |
| P55 | ESPI_CS1# / SPI1_CS1# / QSPI_CS1# | — |  |  |
| P56 | ESPI_CK / SPI1_CK / QSPI_CK | SPI1_CK | OUT | 19 |
| P57 | ESPI_IO_1 / SPI1_DIN / QSPI_IO_1 | SPI1_DIN | IN | 19 |
| P58 | ESPI_IO_0 / SPI1_DO / QSPI_IO_0 | SPI1_DO | OUT | 19 |
| P60 | USB0+ | USB0+ | BI | 11 |
| P61 | USB0- | USB0- | BI | 11 |
| P62 | USB0_EN_OC# | USB0_EN_OC# | BI | 10 |
| P63 | USB0_VBUS_DET | USB0_VBUS_DET | IN | 10 |
| P64 | USB0_OTG_ID | USB0_OTG_ID | IN | 11 |
| P65 | USB1+ | USB1+ | BI | 10 |
| P66 | USB1- | USB1- | BI | 10 |
| P67 | USB1_EN_OC# | — (not used: USB hub on carrier) |  |  |
| P69 | USB2+ | USB2+ | BI | 12 |
| P70 | USB2- | USB2- | BI | 12 |
| P71 | USB2_EN_OC# | USB2_EN_OC# | BI | 12 |
| P72 | RSVD[0] | — |  |  |
| P73 | RSVD[1] | — |  |  |
| P74 | USB3_EN_OC# | USB3_EN_OC# | BI | 12 |
| P75 | PCIE_A_RST# | PCIE_A_RST# | OUT | 20 |
| P76 | USB4_EN_OC# | USB4_EN_OC# | BI | 10 |
| P77 | PCIE_B_CKREQ# | PCIE_B_CKREQ# | BI | 20 |
| P78 | PCIE_A_CKREQ# | PCIE_A_CKREQ# | BI | 20 |
| P80 | PCIE_C_REFCK+ | — |  |  |
| P81 | PCIE_C_REFCK- | — |  |  |
| P83 | PCIE_A_REFCK+ | PCIE_A_REFCK+ | OUT | 21 |
| P84 | PCIE_A_REFCK- | PCIE_A_REFCK- | OUT | 21 |
| P86 | PCIE_A_RX+ | PCIE_A_RX+ | IN | 22 |
| P87 | PCIE_A_RX- | PCIE_A_RX- | IN | 22 |
| P89 | PCIE_A_TX+ | PCIE_A_TX+ | OUT | 22 |
| P90 | PCIE_A_TX- | PCIE_A_TX- | OUT | 22 |
| P92 | HDMI_D2+ / DP1_LANE0+ | HDMI_D2+ | OUT | 14 |
| P93 | HDMI_D2- / DP1_LANE0- | HDMI_D2- | OUT | 14 |
| P95 | HDMI_D1+ / DP1_LANE1+ | HDMI_D1+ | OUT | 14 |
| P96 | HDMI_D1- / DP1_LANE1- | HDMI_D1- | OUT | 14 |
| P98 | HDMI_D0+ / DP1_LANE2+ | HDMI_D0+ | OUT | 14 |
| P99 | HDMI_D0- / DP1_LANE2- | HDMI_D0- | OUT | 14 |
| P101 | HDMI_CK+ / DP1_LANE3+ | HDMI_CK+ | OUT | 14 |
| P102 | HDMI_CK- / DP1_LANE3- | HDMI_CK- | OUT | 14 |
| P104 | HDMI_HPD / DP1_HPD | HDMI_HPD | IN | 14 |
| P105 | HDMI_CTRL_CK / DP1_AUX+ | HDMI_CTRL_CK | OUT | 14 |
| P106 | HDMI_CTRL_DAT / DP1_AUX- | HDMI_CTRL_DAT | OUT | 14 |
| P107 | DP1_AUX_SEL | — |  |  |
| P108 | GPIO0 / CAM0_PWR# | CAM0_PWR# | BI | 9 |
| P109 | GPIO1 / CAM1_PWR# | CAM1_PWR# | BI | 9 |
| P110 | GPIO2 / CAM0_RST# | GPIO2/CAM0_RST# | BI | 5 |
| P111 | GPIO3 / CAM1_RST# | CAM1_RST# | BI | 9 |
| P112 | GPIO4 / HDA_RST# | GPIO4 | BI | 7, 19 |
| P113 | GPIO5 / PWM_OUT | GPIO5 | BI | 19 |
| P114 | GPIO6 / TACHIN | GPIO6 | BI | 7, 19 |
| P115 | GPIO7 | GPIO7 | BI | 7, 19 |
| P116 | GPIO8 | GPIO8 | BI | 17 |
| P117 | GPIO9 | GPIO9 | BI | 17 |
| P118 | GPIO10 | GPIO10 | BI | 5 |
| P119 | GPIO11 | GPIO11 | BI | 19 |
| P121 | I2C_PM_CK | I2C_PM_CK | BI | 4, 6, 13, 20 |
| P122 | I2C_PM_DAT | I2C_PM_DAT | BI | 4, 6, 13, 20 |
| P123 | BOOT_SEL0# | BOOT_SEL0# | IN | 5, 7 |
| P124 | BOOT_SEL1# | BOOT_SEL1# | IN | 5, 7 |
| P125 | BOOT_SEL2# | BOOT_SEL2# | IN | 5, 7 |
| P126 | RESET_OUT# | RESET_OUT# | OUT | 6, 10, 15 |
| P127 | RESET_IN# | RESET_IN# | IN | 3, 4, 5, 7 |
| P128 | POWER_BTN# | POWER_BTN# | IN | 5, 7, 19 |
| P129 | SER0_TX | SER0_TX | OUT | 19, 23 |
| P130 | SER0_RX | SER0_RX | IN | 19, 23 |
| P131 | SER0_RTS# | SER0_RTS# | OUT | 19, 23 |
| P132 | SER0_CTS# | SER0_CTS# | IN | 19, 23 |
| P134 | SER1_TX | SER1_TX | OUT | 7 |
| P135 | SER1_RX | SER1_RX | IN | 7 |
| P136 | SER2_TX | SER2_TX | OUT | 23 |
| P137 | SER2_RX | SER2_RX | IN | 23 |
| P138 | SER2_RTS# | SER2_RTS# | OUT | 23 |
| P139 | SER2_CTS# | SER2_CTS# | IN | 23 |
| P140 | SER3_TX | SER3_TX | OUT | 7 |
| P141 | SER3_RX | SER3_RX | IN | 7 |
| P143 | CAN0_TX | CAN0_TX | OUT | 17 |
| P144 | CAN0_RX | CAN0_RX | IN | 17 |
| P145 | CAN1_TX | CAN1_TX | OUT | 17 |
| P146 | CAN1_RX | CAN1_RX | IN | 17 |
| P147 | VDD_IN[0] | 5V_MODULE |  |  |
| P148 | VDD_IN[1] | 5V_MODULE |  |  |
| P149 | VDD_IN[2] | 5V_MODULE |  |  |
| P150 | VDD_IN[3] | 5V_MODULE |  |  |
| P151 | VDD_IN[4] | 5V_MODULE |  |  |
| P152 | VDD_IN[5] | 5V_MODULE |  |  |
| P153 | VDD_IN[6] | 5V_MODULE |  | 4 |
| P154 | VDD_IN[7] | 5V_MODULE |  |  |
| P155 | VDD_IN[8] | 5V_MODULE |  |  |
| P156 | VDD_IN[9] | 5V_MODULE |  |  |

GND pins: P2, P9, P12, P15, P18, P32, P38, P47, P50, P53, P59, P68, P79, P82, P85, P88, P91, P94, P97, P100, P103, P120, P133, P142

### SMARC 2.1 connector – Secondary (S1–S158), page 27

| Pin | SMARC signal | Carrier net | Dir* | Used on page(s) |
|---|---|---|---|---|
| S1 | CSI1_TX+ / I2C_CAM1_CK | I2C_CAM1_CK | BI | 9 |
| S2 | CSI1_TX- / I2C_CAM1_DAT | I2C_CAM1_DAT | BI | 9 |
| S4 | RSVD[2] | RSVD[2] | BI | 26 |
| S5 | CSI0_TX+ / I2C_CAM0_CK | I2C_CAM0_CK | BI | 9 |
| S6 | CAM_MCK | CAM_MCK | OUT | 9 |
| S7 | CSI0_TX- / I2C_CAM0_DAT | I2C_CAM0_DAT | BI | 9 |
| S8 | CSI0_CK+ | CSI0_CK+ | IN | 9 |
| S9 | CSI0_CK- | CSI0_CK- | IN | 9 |
| S11 | CSI0_RX0+ | CSI0_RX0+ | IN | 9 |
| S12 | CSI0_RX0- | CSI0_RX0- | IN | 9 |
| S14 | CSI0_RX1+ | CSI0_RX1+ | IN | 9 |
| S15 | CSI0_RX1- | CSI0_RX1- | IN | 9 |
| S17 | GBE1_MDI0+ | GBE1_MDI0+ | BI | 16 |
| S18 | GBE1_MDI0- | GBE1_MDI0- | BI | 16 |
| S19 | GBE1_LINK100# | GBE1_LINK100# | BI | 16 |
| S20 | GBE1_MDI1+ | GBE1_MDI1+ | BI | 16 |
| S21 | GBE1_MDI1- | GBE1_MDI1- | BI | 16 |
| S22 | GBE1_LINK1000# | GBE1_LINK1000# | BI | 16 |
| S23 | GBE1_MDI2+ | GBE1_MDI2+ | BI | 16 |
| S24 | GBE1_MDI2- | GBE1_MDI2- | BI | 16 |
| S26 | GBE1_MDI3+ | GBE1_MDI3+ | BI | 16 |
| S27 | GBE1_MDI3- | GBE1_MDI3- | BI | 16 |
| S28 | GBE1_CTREF | — |  |  |
| S29 | PCIE_D_TX+ / SERDES_0_TX+ | PCIE_D_TX+ | OUT | 22 |
| S30 | PCIE_D_TX- / SERDES_0_TX- | PCIE_D_TX- | OUT | 22 |
| S31 | GBE1_LINK_ACT# | GBE1_LINK_ACT# | BI | 16 |
| S32 | PCIE_D_RX+ / SERDES_0_RX+ | PCIE_D_RX+ | IN | 22 |
| S33 | PCIE_D_RX- / SERDES_0_RX- | PCIE_D_RX- | IN | 22 |
| S35 | USB4+ | USB4+ | BI | 11 |
| S36 | USB4- | USB4- | BI | 11 |
| S37 | USB3_VBUS_DET | USB3_VBUS_DET | IN | 13 |
| S38 | AUDIO_MCK | AUDIO_MCK | BI | 18 |
| S39 | I2S0_LRCK | I2S0_LRCK | OUT | 18 |
| S40 | I2S0_SDOUT | I2S0_SDOUT | OUT | 18 |
| S41 | I2S0_SDIN | I2S0_SDIN | IN | 18 |
| S42 | I2S0_CK | I2S0_CK | OUT | 18 |
| S43 | ESPI_ALERT0# | — |  |  |
| S44 | ESPI_ALERT1# | — |  |  |
| S45 | MDIO_CLK | — |  |  |
| S46 | MDIO_DAT | — |  |  |
| S48 | I2C_GP_CK | I2C_GP_CK | BI | 7, 18, 19, 23 |
| S49 | I2C_GP_DAT | I2C_GP_DAT | BI | 7, 18, 19, 23 |
| S50 | HDA_SYNC / I2S2_LRCK | I2S2_LRCK | OUT | 15 |
| S51 | HDA_SDO / I2S2_SDOUT | I2S2_SDOUT | OUT | 15 |
| S52 | HDA_SDI / I2S2_SDIN | I2S2_SDIN | IN | 15 |
| S53 | HDA_CK / I2S2_CK | I2S2_CK | OUT | 15 |
| S54 | SATA_ACT# | — |  |  |
| S55 | USB5_EN_OC# | USB5_EN_OC# | BI | 10 |
| S56 | ESPI_IO_2 / QSPI_IO_2 | — |  |  |
| S57 | ESPI_IO_3 / QSPI_IO_3 | — |  |  |
| S58 | ESPI_RESET# | — |  |  |
| S59 | USB5+ | USB5+ | BI | 11 |
| S60 | USB5- | USB5- | BI | 11 |
| S62 | USB3_SSTX+ | USB3_SSTX+ | OUT | 13 |
| S63 | USB3_SSTX- | USB3_SSTX- | OUT | 13 |
| S65 | USB3_SSRX+ | USB3_SSRX+ | IN | 13 |
| S66 | USB3_SSRX- | USB3_SSRX- | IN | 13 |
| S68 | USB3+ | USB3+ | BI | 13 |
| S69 | USB3- | USB3- | BI | 13 |
| S71 | USB2_SSTX+ | USB2_SSTX+ | OUT | 12 |
| S72 | USB2_SSTX- | USB2_SSTX- | OUT | 12 |
| S74 | USB2_SSRX+ | USB2_SSRX+ | IN | 12 |
| S75 | USB2_SSRX- | USB2_SSRX- | IN | 12 |
| S76 | PCIE_B_RST# | PCIE_B_RST# | OUT | 20 |
| S77 | PCIE_C_RST# | — |  |  |
| S78 | PCIE_C_RX+ / SERDES_1_RX+ | PCIE_C_RX+ | IN | 22 |
| S79 | PCIE_C_RX- / SERDES_1_RX- | PCIE_C_RX- | IN | 22 |
| S81 | PCIE_C_TX+ / SERDES_1_TX+ | PCIE_C_TX+ | OUT | 22 |
| S82 | PCIE_C_TX- / SERDES_1_TX- | PCIE_C_TX- | OUT | 22 |
| S84 | PCIE_B_REFCK+ | PCIE_B_REFCK+ | OUT | 21 |
| S85 | PCIE_B_REFCK- | PCIE_B_REFCK- | OUT | 21 |
| S87 | PCIE_B_RX+ | PCIE_B_RX+ | IN | 22 |
| S88 | PCIE_B_RX- | PCIE_B_RX- | IN | 22 |
| S90 | PCIE_B_TX+ | PCIE_B_TX+ | OUT | 22 |
| S91 | PCIE_B_TX- | PCIE_B_TX- | OUT | 22 |
| S93 | DP0_LANE0+ | — |  |  |
| S94 | DP0_LANE0- | — |  |  |
| S95 | DP0_AUX_SEL | — |  |  |
| S96 | DP0_LANE1+ | — |  |  |
| S97 | DP0_LANE1- | — |  |  |
| S98 | DP0_HPD | — |  |  |
| S99 | DP0_LANE2+ | — |  |  |
| S100 | DP0_LANE2- | — |  |  |
| S102 | DP0_LANE3+ | — |  |  |
| S103 | DP0_LANE3- | — |  |  |
| S104 | USB3_OTG_ID | USB3_OTG_ID | IN | 13 |
| S105 | DP0_AUX+ | — |  |  |
| S106 | DP0_AUX- | — |  |  |
| S107 | LCD1_BKLT_EN | LCD1_BKLT_EN | OUT | 15 |
| S108 | LVDS1_CK+ / EDP1_AUX+ / DSI1_CLK+ | LVDS1_CK+ | OUT | 15 |
| S109 | LVDS1_CK- / EDP1_AUX- / DSI1_CLK- | LVDS1_CK- | OUT | 15 |
| S111 | LVDS1_0+ / EDP1_TX0+ / DSI1_D0+ | LVDS1_0+ | OUT | 15 |
| S112 | LVDS1_0- / EDP1_TX0- / DSI1_D0- | LVDS1_0- | OUT | 15 |
| S113 | EDP1_HPD / DSI1_TE | DSI1_TE | OUT | 15 |
| S114 | LVDS1_1+ / EDP1_TX1+ / DSI1_D1+ | LVDS1_1+ | OUT | 15 |
| S115 | LVDS1_1- / EDP1_TX1- / DSI1_D1- | LVDS1_1- | OUT | 15 |
| S116 | LCD1_VDD_EN | LCD1_VDD_EN | OUT | 15 |
| S117 | LVDS1_2+ / EDP1_TX2+ / DSI1_D2+ | LVDS1_2+ | OUT | 15 |
| S118 | LVDS1_2- / EDP1_TX2- / DSI1_D2- | LVDS1_2- | OUT | 15 |
| S120 | LVDS1_3+ / EDP1_TX3+ / DSI1_D3+ | LVDS1_3+ | OUT | 15 |
| S121 | LVDS1_3- / EDP1_TX3- / DSI1_D3- | LVDS1_3- | OUT | 15 |
| S122 | LCD1_BKLT_PWM | LCD1_BKLT_PWM | OUT | 15 |
| S123 | GPIO13 | GPIO13 | BI | 6, 19 |
| S125 | LVDS0_0+ / EDP0_TX0+ / DSI0_D0+ | LVDS0_0+/DSI0_D0+ | OUT | 15 |
| S126 | LVDS0_0- / EDP0_TX0- / DSI0_D0- | LVDS0_0-/DSI0_D0- | OUT | 15 |
| S127 | LCD0_BKLT_EN | LCD0_BKLT_EN | OUT | 15 |
| S128 | LVDS0_1+ / EDP0_TX1+ / DSI0_D1+ | LVDS0_1+/DSI0_D1+ | OUT | 15 |
| S129 | LVDS0_1- / EDP0_TX1- / DSI0_D1- | LVDS0_1-/DSI0_D1- | OUT | 15 |
| S131 | LVDS0_2+ / EDP0_TX2+ / DSI0_D2+ | LVDS0_2+/DSI0_D2+ | OUT | 15 |
| S132 | LVDS0_2- / EDP0_TX2- / DSI0_D2- | LVDS0_2-/DSI0_D2- | OUT | 15 |
| S133 | LCD0_VDD_EN | LCD0_VDD_EN | OUT | 15 |
| S134 | LVDS0_CK+ / EDP0_AUX+ / DSI0_CLK+ | LVDS0_CK+/DSI0_CLK+ | OUT | 15 |
| S135 | LVDS0_CK- / EDP0_AUX- / DSI0_CLK- | LVDS0_CK-/DSI0_CLK- | OUT | 15 |
| S137 | LVDS0_3+ / EDP0_TX3+ / DSI0_D3+ | LVDS0_3+/DSI0_D3+ | OUT | 15 |
| S138 | LVDS0_3- / EDP0_TX3- / DSI0_D3- | LVDS0_3-/DSI0_D3- | OUT | 15 |
| S139 | I2C_LCD_CK | I2C_LCD_CK | BI | 15 |
| S140 | I2C_LCD_DAT | I2C_LCD_DAT | BI | 15 |
| S141 | LCD0_BKLT_PWM | LCD0_BKLT_PWM | OUT | 15 |
| S142 | GPIO12 | GPIO12 | BI | 6, 19 |
| S144 | EDP0_HPD / DSI0_TE | DSI0_TE | OUT | 15 |
| S145 | WDT_TIME_OUT# | — |  |  |
| S146 | PCIE_WAKE# | PCIE_WAKE# | IN | 23, 24, 25 |
| S147 | VDD_RTC | VDD_RTC |  |  |
| S148 | LID# | — |  |  |
| S149 | SLEEP# | SLEEP# | IN | 5, 7, 19 |
| S150 | VIN_PWR_BAD# | VIN_PWR_BAD# | IN | 3 |
| S151 | CHARGING# | — |  |  |
| S152 | CHARGER_PRSNT# | — |  |  |
| S153 | CARRIER_STBY# | — |  |  |
| S154 | CARRIER_PWR_ON | CARRIER_PWR_ON | OUT | 3, 4, 7, 10, 25 |
| S155 | FORCE_RECOV# | — |  |  |
| S156 | BATLOW# | BATLOW# | IN | 7 |
| S157 | TEST# | TP_TEST# (test point) |  |  |

GND pins: S3, S10, S13, S16, S25, S34, S47, S61, S64, S67, S70, S73, S80, S83, S86, S89, S92, S101, S110, S119, S124, S130, S136, S143, S158

## 12. Cross-page net index
Nets whose label appears on more than one page (pages 26/27 = SMARC connector).

| Net | Pages |
|---|---|
| 1.8V | 4, 5, 6, 7, 14, 15, 17, 18, 19, 24 |
| 12V | 2, 4, 7, 25 |
| 3.3V | 4, 5, 6, 7, 8, 9, 10, 12, 13, 14, 15, 16, 18, 19, 20, 21, 22, 23, 24, 25 |
| 5.0V | 3, 4, 7, 10, 12, 13 |
| 5V_BOARD | 3, 4, 14, 17 |
| 5V_DISPL0 | 3, 15 |
| 5V_DISPL1 | 3, 15 |
| 5V_MODULE | 4, 26 |
| 5V_PMOD | 3, 19 |
| AUDIO_MCK | 18, 27 |
| BATLOW# | 7, 27 |
| BOOT_SEL0# | 5, 7, 26 |
| BOOT_SEL1# | 5, 7, 26 |
| BOOT_SEL2# | 5, 7, 26 |
| CAM0_PWR# | 9, 26 |
| CAM0_RST# | 5, 9, 26 |
| CAM1_PWR# | 9, 26 |
| CAM1_RST# | 9, 26 |
| CAM_MCK | 9, 27 |
| CAN0_RX | 17, 26 |
| CAN0_TX | 17, 26 |
| CAN1_RX | 17, 26 |
| CAN1_TX | 17, 26 |
| CARRIER_PWR_ON | 3, 4, 7, 10, 25, 27 |
| CLK_32K | 23, 24 |
| CSI0_CK+ | 9, 27 |
| CSI0_CK- | 9, 27 |
| CSI0_RX0+ | 9, 27 |
| CSI0_RX0- | 9, 27 |
| CSI0_RX1+ | 9, 27 |
| CSI0_RX1- | 9, 27 |
| CSI1_CK+ | 9, 26 |
| CSI1_CK- | 9, 26 |
| CSI1_RX0+ | 9, 26 |
| CSI1_RX0- | 9, 26 |
| CSI1_RX1+ | 9, 26 |
| CSI1_RX1- | 9, 26 |
| CSI1_RX2+ | 9, 26 |
| CSI1_RX2- | 9, 26 |
| CSI1_RX3+ | 9, 26 |
| CSI1_RX3- | 9, 26 |
| DISP_INT# | 5, 15 |
| DSI0_TE | 15, 27 |
| DSI1_TE | 15, 27 |
| GBE0_LINK100# | 16, 26 |
| GBE0_LINK1000# | 16, 26 |
| GBE0_LINK_ACT# | 16, 26 |
| GBE0_MDI0+ | 16, 26 |
| GBE0_MDI0- | 16, 26 |
| GBE0_MDI1+ | 16, 26 |
| GBE0_MDI1- | 16, 26 |
| GBE0_MDI2+ | 16, 26 |
| GBE0_MDI2- | 16, 26 |
| GBE0_MDI3+ | 16, 26 |
| GBE0_MDI3- | 16, 26 |
| GBE1_LINK100# | 16, 27 |
| GBE1_LINK1000# | 16, 27 |
| GBE1_LINK_ACT# | 16, 27 |
| GBE1_MDI0+ | 16, 27 |
| GBE1_MDI0- | 16, 27 |
| GBE1_MDI1+ | 16, 27 |
| GBE1_MDI1- | 16, 27 |
| GBE1_MDI2+ | 16, 27 |
| GBE1_MDI2- | 16, 27 |
| GBE1_MDI3+ | 16, 27 |
| GBE1_MDI3- | 16, 27 |
| GPIO10 | 5, 26 |
| GPIO10_PMOD1 | 5, 19 |
| GPIO11 | 19, 26 |
| GPIO12 | 6, 19, 27 |
| GPIO13 | 6, 19, 27 |
| GPIO2/CAM0_RST# | 5, 26 |
| GPIO4 | 7, 19, 26 |
| GPIO5 | 19, 26 |
| GPIO6 | 7, 19, 26 |
| GPIO7 | 7, 19, 26 |
| GPIO8 | 17, 26 |
| GPIO8_PMOD | 6, 17, 19 |
| GPIO9 | 17, 26 |
| GPIO9_PMOD | 6, 17, 19 |
| HDMI_CK+ | 14, 26 |
| HDMI_CK- | 14, 26 |
| HDMI_CTRL_CK | 14, 26 |
| HDMI_CTRL_DAT | 14, 26 |
| HDMI_D0+ | 14, 26 |
| HDMI_D0- | 14, 26 |
| HDMI_D1+ | 14, 26 |
| HDMI_D1- | 14, 26 |
| HDMI_D2+ | 14, 26 |
| HDMI_D2- | 14, 26 |
| HDMI_HPD | 14, 26 |
| I2C_CAM0_CK | 9, 27 |
| I2C_CAM0_DAT | 9, 27 |
| I2C_CAM1_CK | 9, 27 |
| I2C_CAM1_DAT | 9, 27 |
| I2C_GP_CK | 7, 18, 19, 23, 27 |
| I2C_GP_DAT | 7, 18, 19, 23, 27 |
| I2C_LCD_CK | 15, 27 |
| I2C_LCD_DAT | 15, 27 |
| I2C_PM_CK | 4, 6, 13, 20, 26 |
| I2C_PM_DAT | 4, 6, 13, 20, 26 |
| I2S0_CK | 18, 27 |
| I2S0_LRCK | 18, 27 |
| I2S0_SDIN | 18, 27 |
| I2S0_SDOUT | 18, 27 |
| I2S2_CK | 15, 27 |
| I2S2_LRCK | 15, 27 |
| I2S2_M2E_CK | 15, 23 |
| I2S2_M2E_LRCK | 15, 23 |
| I2S2_M2E_SDIN | 15, 23 |
| I2S2_M2E_SDOUT | 15, 23 |
| I2S2_SDIN | 15, 27 |
| I2S2_SDOUT | 15, 27 |
| ISINK_COARSE | 2, 5 |
| LCD0_BKLT_EN | 15, 27 |
| LCD0_BKLT_PWM | 15, 27 |
| LCD0_VDD_EN | 15, 27 |
| LCD1_BKLT_EN | 15, 27 |
| LCD1_BKLT_PWM | 15, 27 |
| LCD1_VDD_EN | 15, 27 |
| LVDS0_0+/DSI0_D0+ | 15, 27 |
| LVDS0_0-/DSI0_D0- | 15, 27 |
| LVDS0_1+/DSI0_D1+ | 15, 27 |
| LVDS0_1-/DSI0_D1- | 15, 27 |
| LVDS0_2+/DSI0_D2+ | 15, 27 |
| LVDS0_2-/DSI0_D2- | 15, 27 |
| LVDS0_3+/DSI0_D3+ | 15, 27 |
| LVDS0_3-/DSI0_D3- | 15, 27 |
| LVDS0_CK+/DSI0_CLK+ | 15, 27 |
| LVDS0_CK-/DSI0_CLK- | 15, 27 |
| LVDS1_0+ | 15, 27 |
| LVDS1_0- | 15, 27 |
| LVDS1_1+ | 15, 27 |
| LVDS1_1- | 15, 27 |
| LVDS1_2+ | 15, 27 |
| LVDS1_2- | 15, 27 |
| LVDS1_3+ | 15, 27 |
| LVDS1_3- | 15, 27 |
| LVDS1_CK+ | 15, 27 |
| LVDS1_CK- | 15, 27 |
| M2B_CONFIG0 | 6, 24 |
| M2B_CONFIG1 | 6, 24 |
| M2B_CONFIG2 | 6, 24 |
| M2B_CONFIG3 | 6, 24 |
| M2B_RESET# | 5, 24 |
| M2E_PEWAKE0# | 23, 24 |
| M2E_W_DISABLE1# | 5, 23 |
| M2E_W_DISABLE2# | 5, 23 |
| PCIE_A_CKREQ# | 20, 26 |
| PCIE_A_REFCK+ | 21, 26 |
| PCIE_A_REFCK- | 21, 26 |
| PCIE_A_RST# | 20, 26 |
| PCIE_A_RX+ | 22, 26 |
| PCIE_A_RX- | 22, 26 |
| PCIE_A_TX+ | 22, 26 |
| PCIE_A_TX- | 22, 26 |
| PCIE_B_CKREQ# | 20, 26 |
| PCIE_B_REFCK+ | 21, 27 |
| PCIE_B_REFCK- | 21, 27 |
| PCIE_B_RST# | 20, 27 |
| PCIE_B_RX+ | 22, 27 |
| PCIE_B_RX- | 22, 27 |
| PCIE_B_TX+ | 22, 27 |
| PCIE_B_TX- | 22, 27 |
| PCIE_C_RST# | 20, 27 |
| PCIE_C_RX+ | 22, 27 |
| PCIE_C_RX- | 22, 27 |
| PCIE_C_TX+ | 22, 27 |
| PCIE_C_TX- | 22, 27 |
| PCIE_D_RX+ | 22, 27 |
| PCIE_D_RX- | 22, 27 |
| PCIE_D_TX+ | 22, 27 |
| PCIE_D_TX- | 22, 27 |
| PCIE_EXT_12V | 2, 25 |
| PCIE_M2B_CKREQ# | 20, 24 |
| PCIE_M2B_REFCK+ | 21, 24 |
| PCIE_M2B_REFCK- | 21, 24 |
| PCIE_M2B_RST# | 20, 24 |
| PCIE_M2B_RX0+ | 22, 24 |
| PCIE_M2B_RX0- | 22, 24 |
| PCIE_M2B_RX1+ | 22, 24 |
| PCIE_M2B_RX1- | 22, 24 |
| PCIE_M2B_TX0+ | 22, 24 |
| PCIE_M2B_TX0- | 22, 24 |
| PCIE_M2B_TX1+ | 22, 24 |
| PCIE_M2B_TX1- | 22, 24 |
| PCIE_M2E_CKREQ0# | 20, 23 |
| PCIE_M2E_CKREQ1# | 20, 23 |
| PCIE_M2E_REFCK0+ | 21, 23 |
| PCIE_M2E_REFCK0- | 21, 23 |
| PCIE_M2E_REFCK1+ | 21, 23 |
| PCIE_M2E_REFCK1- | 21, 23 |
| PCIE_M2E_RST0# | 20, 23 |
| PCIE_M2E_RST1# | 20, 23 |
| PCIE_M2E_RX0+ | 22, 23 |
| PCIE_M2E_RX0- | 22, 23 |
| PCIE_M2E_RX1+ | 22, 23 |
| PCIE_M2E_RX1- | 22, 23 |
| PCIE_M2E_TX0+ | 22, 23 |
| PCIE_M2E_TX0- | 22, 23 |
| PCIE_M2E_TX1+ | 22, 23 |
| PCIE_M2E_TX1- | 22, 23 |
| PCIE_SLOT_PRSNT# | 20, 25 |
| PCIE_SLOT_REFCK+ | 21, 25 |
| PCIE_SLOT_REFCK- | 21, 25 |
| PCIE_SLOT_RST# | 20, 25 |
| PCIE_SLOT_RX0+ | 22, 25 |
| PCIE_SLOT_RX0- | 22, 25 |
| PCIE_SLOT_RX1+ | 22, 25 |
| PCIE_SLOT_RX1- | 22, 25 |
| PCIE_SLOT_RX2+ | 22, 25 |
| PCIE_SLOT_RX2- | 22, 25 |
| PCIE_SLOT_RX3+ | 22, 25 |
| PCIE_SLOT_RX3- | 22, 25 |
| PCIE_SLOT_TX0+ | 22, 25 |
| PCIE_SLOT_TX0- | 22, 25 |
| PCIE_SLOT_TX1+ | 22, 25 |
| PCIE_SLOT_TX1- | 22, 25 |
| PCIE_SLOT_TX2+ | 22, 25 |
| PCIE_SLOT_TX2- | 22, 25 |
| PCIE_SLOT_TX3+ | 22, 25 |
| PCIE_SLOT_TX3- | 22, 25 |
| PCIE_WAKE# | 23, 24, 25, 27 |
| POWER_BTN# | 5, 7, 19, 26 |
| RESET_IN# | 3, 4, 5, 7, 26 |
| RESET_OUT# | 6, 10, 15, 26 |
| SATA_RX+ | 7, 26 |
| SATA_RX- | 7, 26 |
| SATA_TX+ | 7, 26 |
| SATA_TX- | 7, 26 |
| SDIO_CD# | 8, 26 |
| SDIO_CK | 8, 26 |
| SDIO_CMD | 8, 26 |
| SDIO_D0 | 8, 26 |
| SDIO_D1 | 8, 26 |
| SDIO_D2 | 8, 26 |
| SDIO_D3 | 8, 26 |
| SDIO_M2E_CK | 8, 23 |
| SDIO_M2E_CMD | 8, 23 |
| SDIO_M2E_D0 | 8, 23 |
| SDIO_M2E_D1 | 8, 23 |
| SDIO_M2E_D2 | 8, 23 |
| SDIO_M2E_D3 | 8, 23 |
| SDIO_M2E_RESET# | 8, 23 |
| SDIO_PWR_EN | 8, 26 |
| SER0_CTS# | 19, 23, 26 |
| SER0_RTS# | 19, 23, 26 |
| SER0_RX | 19, 23, 26 |
| SER0_TX | 19, 23, 26 |
| SER1_RX | 7, 26 |
| SER1_TX | 7, 26 |
| SER2_CTS# | 23, 26 |
| SER2_RTS# | 23, 26 |
| SER2_RX | 23, 26 |
| SER2_TX | 23, 26 |
| SER3_RX | 7, 26 |
| SER3_TX | 7, 26 |
| SLEEP# | 5, 7, 19, 27 |
| SMB_ALERT# | 13, 26 |
| SPI0_CK | 7, 26 |
| SPI0_CS0# | 7, 26 |
| SPI0_DIN | 7, 26 |
| SPI0_DO | 7, 26 |
| SPI1_CK | 19, 26 |
| SPI1_CS0# | 19, 26 |
| SPI1_DIN | 19, 26 |
| SPI1_DO | 19, 26 |
| SW_GPIO_PMOD | 5, 6, 19 |
| SW_I2S2_M2E | 5, 6, 15 |
| SW_PCIE_MUX0 | 5, 20 |
| SW_PCIE_MUX1 | 5, 20 |
| SW_PCIE_MUX2 | 5, 20 |
| SW_SDIO_M2E | 5, 6, 8 |
| SW_SER0_PMOD | 5, 6, 19, 23 |
| SW_SPARE | 5, 6 |
| SW_USB2_M2B | 5, 6, 12, 24 |
| S_M2B_FULL_CARD_POWER_OFF# | 6, 24 |
| S_M2B_RESET# | 5, 6 |
| S_M2E_W_DISABLE1# | 5, 6 |
| S_M2E_W_DISABLE2# | 5, 6 |
| S_PCIE_A_M2B_EN# | 20, 21 |
| S_PCIE_A_M2E0_EN# | 20, 21 |
| S_PCIE_A_SEL1 | 20, 22 |
| S_PCIE_A_SEL2 | 20, 22 |
| S_PCIE_A_SLOT_EN# | 20, 21 |
| S_PCIE_B_M2B_EN# | 20, 21 |
| S_PCIE_B_M2E0_EN# | 20, 21 |
| S_PCIE_B_M2E1_EN# | 20, 21 |
| S_PCIE_B_SEL1 | 20, 22 |
| S_PCIE_B_SEL2 | 20, 22 |
| S_PCIE_M2_X | 20, 21, 22 |
| S_PCIE_SLOT_X | 20, 21, 22 |
| UPD_3V3 | 2, 5 |
| USB0+ | 11, 26 |
| USB0- | 11, 26 |
| USB0_EN_OC# | 10, 26 |
| USB0_OTG_ID | 11, 26 |
| USB0_VBUS_DET | 10, 26 |
| USB0_VBUS_OTG | 10, 11 |
| USB1+ | 10, 26 |
| USB1- | 10, 26 |
| USB1A_VBUS | 10, 11 |
| USB1B_VBUS | 10, 11 |
| USB1_HUB_A+ | 10, 11 |
| USB1_HUB_A- | 10, 11 |
| USB1_HUB_A_EN | 6, 10 |
| USB1_HUB_A_EN# | 6, 10 |
| USB1_HUB_B+ | 10, 11 |
| USB1_HUB_B- | 10, 11 |
| USB1_HUB_B_EN | 6, 10 |
| USB1_HUB_B_EN# | 6, 10 |
| USB1_M2B+ | 10, 24 |
| USB1_M2B- | 10, 24 |
| USB1_M2E+ | 10, 23 |
| USB1_M2E- | 10, 23 |
| USB2+ | 12, 26 |
| USB2- | 12, 26 |
| USB2_EN_OC# | 12, 26 |
| USB2_SSRX+ | 12, 27 |
| USB2_SSRX- | 12, 27 |
| USB2_SSRX_M2B+ | 12, 24 |
| USB2_SSRX_M2B- | 12, 24 |
| USB2_SSTX+ | 12, 27 |
| USB2_SSTX- | 12, 27 |
| USB2_SSTX_M2B+ | 12, 24 |
| USB2_SSTX_M2B- | 12, 24 |
| USB3+ | 13, 27 |
| USB3- | 13, 27 |
| USB3_EN_OC# | 12, 26 |
| USB3_OTG_ID | 13, 27 |
| USB3_SSRX+ | 13, 27 |
| USB3_SSRX- | 13, 27 |
| USB3_SSTX+ | 13, 27 |
| USB3_SSTX- | 13, 27 |
| USB3_VBUS | 12, 13 |
| USB3_VBUS_DET | 13, 27 |
| USB4+ | 11, 27 |
| USB4- | 11, 27 |
| USB4_EN_OC# | 10, 26 |
| USB4_VBUS | 10, 11 |
| USB5+ | 11, 27 |
| USB5- | 11, 27 |
| USB5_EN_OC# | 10, 27 |
| USB5_VBUS | 10, 11 |
| USBC_VBUS_IN | 2, 7 |
| USBC_VBUS_OUT | 2, 3, 4 |
| USB_FAULT | 2, 7 |
| VBAT_REG | 2, 4 |
| VBUS_MIN | 2, 5 |
| VDD_RTC | 2, 7, 27 |
| VIN_PWR_BAD# | 3, 27 |



