# Blinky for Microchip PIC32CM PL10-CNANO

The **Blinky** project can be easily used to verify the basic tool setup:

- In the beginning, `vioLED0` (LED0 on the board) blinks in 1 sec interval.
- Pressing `vioBUTTON0` )SW0 on the board) changes the blink frequency of `vioLED0`.

Refer to [Project Configuration](#project-configuration) for board specific settings.

## Prerequisites

The following tools need to be installed on your machine:

- [Microsoft Visual Studio Code](https://code.visualstudio.com/download) with
  [Keil Studio Pack](https://marketplace.visualstudio.com/items?itemName=Arm.keil-studio-pack) extension
- [Arm Compiler 6](https://developer.arm.com/Tools%20and%20Software/Arm%20Compiler%20for%20Embedded) (automatically
  installed when using Visual Studio Code with vcpkg)

## Project Configuration

### Keil RTX5 real-time operating system

The real-time operating system [Keil RTX5](https://arm-software.github.io/CMSIS-RTX/latest/index.html) implements
the resource management.

It is configured with the following settings:

- [Global Dynamic Memory size](https://arm-software.github.io/CMSIS-RTX/latest/config_rtx5.html#systemConfig_glob_mem):
  1024 bytes
- [Default Thread Stack size](https://arm-software.github.io/CMSIS-RTX/latest/config_rtx5.html#threadConfig): 128 bytes
- [Idle Thread Stack size](https://arm-software.github.io/CMSIS-RTX/latest/config_rtx5.html#threadConfig): 128 bytes
- [Timer Thread Stack size](hhttps://arm-software.github.io/CMSIS-RTX/latest/config_rtx5.html#timerConfig): 128 bytes
- [Stack Overflow Checking](https://arm-software.github.io/CMSIS-RTX/latest/config_rtx5.html#threadConfig_ovfcheck) and
  [Stack Usage Watermark](https://arm-software.github.io/CMSIS-RTX/latest/config_rtx5.html#threadConfig_watermark)
  enabled

Refer to [Configure RTX v5](https://arm-software.github.io/CMSIS-RTX/latest/config_rtx5.html) for a detailed
description of all configuration options.

## Build solution

Required tools described in file `vcpkg-configuration.json` will be automatically installed by vcpkg. You can see the
status of vcpkg in the status bar (**Arm Tools**). Required CMSIS packs will also be installed automatically.

Open the **CMSIS view** from the side bar and press the **Build** button.

## Run and debug

### Run

- Connect the board's USB-C to the PC (provides also power).
- Open the **CMSIS** view from the side bar and press the **Run** button and wait until the image is programmed and
  starts running.

### Debug

Open the **CMSIS** view from the side bar and press the **Debug** button. A connection is established via the on-board
[nEDBG](https://ww1.microchip.com/downloads/aemDocuments/documents/MCU08/ProductDocuments/UserGuides/Microchip-Nano-Debugger-Manual-DS50003996.pdf)
debug adapter.

RTOS awareness is available through the **XRTOS** view in the bottom panel.

### printf output

`printf` output is redirected to the **SERIAL MONITOR** in VS Code. Observe the output with the following settings:

- Monitor Mode: SERIAL
- View Mode: Text
- Port: Select the Microchip Technology usbmodem
- Baud rate: `115200`
- Line ending: CR
