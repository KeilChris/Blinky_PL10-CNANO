# Blinky for Microchip PIC32CM PL10-Curiosity Nano

The **Blinky** project can be easily used to verify the basic tool setup:

- In the beginning, `vioLED0` (`LED0` on the board) blinks in 1 sec interval.
- Pressing `vioBUTTON0` (`SW0` on the board) changes the blink frequency of `vioLED0`.

Refer to [Project Configuration](#project-configuration) for board specific settings.

## Quick Start

1. Install [Keil Studio for VS Code](https://marketplace.visualstudio.com/items?itemName=Arm.keil-studio-pack) from the
   VS Code marketplace.
2. Clone this Git repository into a VS Code workspace.
3. The related tools and software packs are downloaded and installed. Review progress with
   **View - Output - CMSIS Solution**.
4. In the **CMSIS** view, use the
   [Action buttons](https://github.com/ARM-software/vscode-cmsis-csolution?tab=readme-ov-file#action-buttons) to build,
   load and debug the example on the hardware.
5. Observe the `LED0` and change its blinking frequency by pressing `SW0`.
6. In the [VS Code Panel](https://code.visualstudio.com/api/ux-guidelines/panel), click on **SERIAL MONITOR**. Set:
   - **Monitor Mode**: `SERIAL`
   - **View Mode**: `Text`
   - **Port**: "Microchip Technology USB device (COM port)"
   - **Baud rate**: `115200`
   - **Line ending**: `CR`

   Observe the output:

   ```txt
   Starting Blinky example...
   ```

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
