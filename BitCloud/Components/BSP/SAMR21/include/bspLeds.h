/***************************************************************************//**
\file  leds.h

\brief Declaration of leds interface.

\author
    Atmel Corporation: http://www.atmel.com \n
    Support email: avr@atmel.com

  Copyright (c) 2008-2015, Atmel Corporation. All rights reserved.
  Licensed under Atmel's Limited License Agreement (BitCloudTM).

\internal
  History:
    07/04/14 karthik.p_u - Created
*******************************************************************************/

#ifndef _BSPLEDS_H
#define _BSPLEDS_H

/******************************************************************************
                   Includes section
******************************************************************************/
#include <gpio.h>
#include <leds.h>

/******************************************************************************
                   Define(s) section
******************************************************************************/
#if BSP_SUPPORT == BOARD_FAKE
  #define halInitFirstLed()     (void)0
  #define halUnInitFirstLed()   (void)0
  #define halOnFirstLed()       (void)0
  #define halOffFirstLed()      (void)0
  #define halReadFirstLed()     (void)0
  #define halToggleFirstLed()   (void)0
#elif BSP_SUPPORT == BOARD_SAMR21_XPRO
  #define halInitFirstLed()     GPIO_A19_make_out()
  #define halUnInitFirstLed()   GPIO_A19_make_in()
  #define halOnFirstLed()       GPIO_A19_clr()
  #define halOffFirstLed()      GPIO_A19_set()
  #define halReadFirstLed()     GPIO_A19_read()
  #define halToggleFirstLed()   GPIO_A19_toggle()
#elif BSP_SUPPORT == BOARD_SAMR21_ZLLEK
  #define halInitFirstLed()     GPIO_A19_make_out()
  #define halUnInitFirstLed()   GPIO_A19_make_in()
  #define halOnFirstLed()       GPIO_A19_set()
  #define halOffFirstLed()      GPIO_A19_clr()
  #define halReadFirstLed()     GPIO_A19_read()
  #define halToggleFirstLed()   GPIO_A19_toggle()
#elif BSP_SUPPORT == BOARD_SAMR21_CUSTOM
  #define halInitFirstLed()     GPIO_A18_make_out()
  #define halUnInitFirstLed()   GPIO_A18_make_in()
  #define halOnFirstLed()       GPIO_A18_clr()
  #define halOffFirstLed()      GPIO_A18_set()
  #define halReadFirstLed()     GPIO_A18_read()
  #define halToggleFirstLed()   GPIO_A18_toggle()
#endif

/**************************************************************************//**
\brief Set duty cycle for PWM channels
\param[in] ch1, ch2, ch3, ch4 - Duty cycle
******************************************************************************/
void bspSetPwmChanelDutyCycle(uint8_t ch1, uint8_t ch2, uint8_t ch3, uint8_t ch4);
#endif /*_BSPLEDS_H*/
// eof leds.h
