/******************************************************************************
 * @file     vio.c
 * @brief    Virtual I/O implementation template
 * @version  V1.0.0
 * @date     24. May 2023
 ******************************************************************************/
/*
 * Copyright (c) 2019-2023 Arm Limited. All rights reserved.
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
 */

/*! \page vio.c Physical I/O Mapping

The table below lists the physical I/O mapping of this CMSIS-Driver VIO implementation.

| Virtual I/O   | Variable       | Board component    | Pin
|:--------------|:---------------|:-------------------|:------
| vioBUTTON0    | vioSignalIn.0  | USER button (SW0)  | PB03
| vioLED0       | vioSignalOut.0 | LED red     (LED0) | PB02
*/

#include <string.h>
#include "cmsis_vio.h"

#include "RTE_Components.h"                 // Component selection
#include CMSIS_device_header

#if !defined CMSIS_VOUT || !defined CMSIS_VIN
#include "Driver_GPIO.h"

#endif

// VIO input, output definitions
#define VIO_VALUE_NUM           5U          // Number of values

// VIO input, output variables
__USED uint32_t vioSignalIn;                // Memory for incoming signal
__USED uint32_t vioSignalOut;               // Memory for outgoing signal
__USED int32_t  vioValue[VIO_VALUE_NUM];    // Memory for value used in vioGetValue/vioSetValue

#if !defined CMSIS_VOUT || !defined CMSIS_VIN
extern ARM_DRIVER_GPIO Driver_GPIO;
static ARM_DRIVER_GPIO *gpioDrv = &Driver_GPIO;
#endif

#if !defined CMSIS_VOUT
#define VIO_LED0_PIN            PIN_PB02
#define VIO_LED0_ACTIVE_LOW     1U
#endif

#if !defined CMSIS_VIN
#define VIO_BUTTON0_PIN         PIN_PB03
#define VIO_BUTTON0_ACTIVE_LOW  1U
#endif

// Initialize test input, output.
void vioInit (void) {
#if !defined CMSIS_VOUT
  uint32_t led_off_level;

#endif
#if !defined CMSIS_VIN
  ARM_GPIO_PULL_RESISTOR button_pull;

#endif

  vioSignalIn  = 0U;
  vioSignalOut = 0U;

  memset(vioValue, 0, sizeof(vioValue));

#if !defined CMSIS_VOUT
  led_off_level = (VIO_LED0_ACTIVE_LOW != 0U) ? 1U : 0U;

  gpioDrv->Setup(VIO_LED0_PIN, NULL);
  gpioDrv->SetDirection(VIO_LED0_PIN, ARM_GPIO_OUTPUT);
  gpioDrv->SetOutputMode(VIO_LED0_PIN, ARM_GPIO_PUSH_PULL);
  gpioDrv->SetOutput(VIO_LED0_PIN, led_off_level);

#endif

#if !defined CMSIS_VIN
  button_pull = (VIO_BUTTON0_ACTIVE_LOW != 0U) ? ARM_GPIO_PULL_UP : ARM_GPIO_PULL_DOWN;

  gpioDrv->Setup(VIO_BUTTON0_PIN, NULL);
  gpioDrv->SetDirection(VIO_BUTTON0_PIN, ARM_GPIO_INPUT);
  gpioDrv->SetPullResistor(VIO_BUTTON0_PIN, button_pull);

#endif
}

// Set signal output.
void vioSetSignal (uint32_t mask, uint32_t signal) {
#if !defined CMSIS_VOUT
// Add user variables here:

#endif

  vioSignalOut &= ~mask;
  vioSignalOut |=  mask & signal;

#if !defined CMSIS_VOUT
  if ((mask & vioLED0) != 0U) {
    uint32_t led_on = ((vioSignalOut & vioLED0) != 0U) ? 1U : 0U;
    if (VIO_LED0_ACTIVE_LOW != 0U) {
      led_on = (led_on != 0U) ? 0U : 1U;
    }
    gpioDrv->SetOutput(VIO_LED0_PIN, led_on);
  }

#endif
}

// Get signal input.
uint32_t vioGetSignal (uint32_t mask) {
  uint32_t signal;
#if !defined CMSIS_VIN
// Add user variables here:

#endif

#if !defined CMSIS_VIN
// Add user code here:

  if ((mask & vioBUTTON0) != 0U) {
    uint32_t pressed = gpioDrv->GetInput(VIO_BUTTON0_PIN);
    if (VIO_BUTTON0_ACTIVE_LOW != 0U) {
      pressed = (pressed != 0U) ? 0U : 1U;
    }
    if (pressed != 0U) {
      vioSignalIn |= vioBUTTON0;
    } else {
      vioSignalIn &= ~vioBUTTON0;
    }
  }
#endif

  signal = vioSignalIn & mask;

  return signal;
}

// Set value output.
void vioSetValue (uint32_t id, int32_t value) {
  uint32_t index = id;
#if !defined CMSIS_VOUT
// Add user variables here:

#endif

  if (index >= VIO_VALUE_NUM) {
    return;                             /* return in case of out-of-range index */
  }

  vioValue[index] = value;

#if !defined CMSIS_VOUT
// Add user code here:

#endif
}

// Get value input.
int32_t vioGetValue (uint32_t id) {
  uint32_t index = id;
  int32_t  value = 0;
#if !defined CMSIS_VIN
// Add user variables here:

#endif

  if (index >= VIO_VALUE_NUM) {
    return value;                       /* return default in case of out-of-range index */
  }

#if !defined CMSIS_VIN
// Add user code here:

//   vioValue[index] = ...;
#endif

  value = vioValue[index];

  return value;
}
