/**************************************************************************//**
  \file  halInterrupt.h

  \brief Interface for interrupt registration.

  \author
      Atmel Corporation: http://www.atmel.com \n
      Support email: avr@atmel.com

    Copyright (c) 2008-2015, Atmel Corporation. All rights reserved.
    Licensed under Atmel's Limited License Agreement (BitCloudTM).

  \internal
    History:
    07/04/14 karthik.p_u - Created
 ******************************************************************************/
/******************************************************************************
 *   WARNING: CHANGING THIS FILE MAY AFFECT CORE FUNCTIONALITY OF THE STACK.  *
 *   EXPERT USERS SHOULD PROCEED WITH CAUTION.                                *
 ******************************************************************************/

#ifndef _HALINTERRUPT_H
#define _HALINTERRUPT_H

/******************************************************************************
                   Includes section
******************************************************************************/
#include <sysTypes.h>
#include <core_cm0plus.h>

/******************************************************************************
                   Define(s) section
******************************************************************************/
/******************************************************************************
                   Types section
******************************************************************************/
//! Function prototype for exception table items (interrupt handler).
typedef void(* HalIntFunc_t)(void);

// Type of entry in vector table
typedef union
{
  HalIntFunc_t __fun;
  void *__ptr;
} HalIntVector_t;

/*****************************************************************************
                              Prototypes section
******************************************************************************/

/**************************************************************************//**
\brief Register interrupt handler in vector table

\param[in] num - number of irq vector starting from zeroth IRQ handler (IRQ0)
\param[in] handler - vector handler function. Pass NULL to unregister vector
\return true if succeed, false otherwise
******************************************************************************/
bool HAL_InstallInterruptVector(int32_t num, HalIntFunc_t handler);
#endif

// eof halInterrupt.h
