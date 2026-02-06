/*
 * Project-local wrapper around the Microchip device pack header.
 *
 * CMSIS-RTOS2's SysTick implementation expects SystemCoreClock to be declared
 * by the CMSIS device header chain. The Microchip PIC32CM device headers keep
 * that declaration in system_<device>.h, which is not included by pic32c.h.
 *
 * This wrapper uses #include_next to pull in the original pack-provided
 * pic32c.h, then includes the matching system_<device>.h to provide the
 * required extern declarations.
 */

#ifndef BLINKY_WRAPPER_PIC32C_H
#define BLINKY_WRAPPER_PIC32C_H

#include_next "pic32c.h"

#if defined(__PIC32CM6408PL10048__) || defined(__PIC32CM6408PL10048)
#include "system_pic32cm6408pl10048.h"
#endif

#endif /* BLINKY_WRAPPER_PIC32C_H */
