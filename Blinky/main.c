/*---------------------------------------------------------------------------
 * Copyright (c) 2021-2026 Arm Limited (or its affiliates). 
 * All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *---------------------------------------------------------------------------*/

#include "RTE_Components.h"
#include  CMSIS_device_header
#include "cmsis_os2.h"
#include "stdio.h"
#include "cmsis_vio.h"

#include "main.h"

//-----------------------------------------------------------------------------
// Pin Definitions
//-----------------------------------------------------------------------------
#define LED0_PIN    PIN_PB02
#define SW0_PIN     PIN_PB03

//-----------------------------------------------------------------------------
// Clock Configuration
//-----------------------------------------------------------------------------
static void configure_clock(void)
{
    OSCCTRL_OSCHF_EnableAutotune();
    OSCCTRL_OSCHF_SetFrequency(OSCCTRL_OSCHF_FREQ_24M);
    SystemCoreClock = OSCCTRL_OSCHF_GetFrequency();

    // SERCOM1 clock (USART)
    GCLK_SetGeneratorSource(GCLK_GENERATOR_1, GCLK_SRC_OSCHF);
    GCLK_SetDivisionParameters(GCLK_GENERATOR_1, 6, GCLK_DIVISION_INTEGER, 0);
    GCLK_GeneratorEnable(GCLK_GENERATOR_1);
    GCLK_SetPeripheralChannelGenSrc(GCLK_PCHCCTRL_8, GCLK_GENERATOR_1);
    GCLK_EnablePeripheralChannel(GCLK_PCHCCTRL_8);

    MCLK_EnableAPBCClock(MCLK_APBC_SERCOM1);
}

int main (void) {
  // System Initialization
  configure_clock();

  __DMB();
  __enable_irq();

  // USART Initialization
  NVIC_EnableIRQ(SERCOM1_IRQn);

  PORT_SetPeripheralMuxing(PIN_PB00, PORT_PERIPHERAL_FUNC_D); // TX
  PORT_SetPeripheralMuxing(PIN_PB01, PORT_PERIPHERAL_FUNC_D); // RX

  USARTdrv->Initialize(NULL);
  USARTdrv->PowerControl(ARM_POWER_FULL);
  USARTdrv->Control(ARM_USART_CONTROL_TX, 1);
  
  // Main Application
  printf("\nStarting Blinky example...\r\n\n");

  vioInit();

  app_main();

  for (;;) {}
}
