/**************************************************************************//**
  \file   bspSpi.c

  \brief  Implementation of board specific Spi pin configuration

  \author
      Atmel Corporation: http://www.atmel.com \n
      Support email: avr@atmel.com

    Copyright (c) 2008-2015, Atmel Corporation. All rights reserved.
    Licensed under Atmel's Limited License Agreement (BitCloudTM).

  \internal
    History:
      26/05/14 Mahendran - Created
 ******************************************************************************/
/******************************************************************************
 *   WARNING: CHANGING THIS FILE MAY AFFECT CORE FUNCTIONALITY OF THE STACK.  *
 *   EXPERT USERS SHOULD PROCEED WITH CAUTION.                                *
 ******************************************************************************/
#if BSP_SUPPORT != BOARD_FAKE
/******************************************************************************
                   Includes section
******************************************************************************/
#include <spi.h>

/******************************************************************************
                   Implementations section
******************************************************************************/
/**************************************************************************//**
\brief Configure the usart pin based on the board
******************************************************************************/
void BSP_BoardSpecificSpiPinInit(SpiChannel_t tty)
{
  // configure spi
  if (tty == SPI_CHANNEL_0)
  {
    tty->sercom = &(SERCOM2->SPI);
    tty->spiPinConfig[SPI_CS_SIG].pinNum = 14;
    tty->spiPinConfig[SPI_CS_SIG].portNum = PORT_A;
    tty->spiPinConfig[SPI_CS_SIG].functionConfig = 2;
    
    tty->spiPinConfig[SPI_SCK_SIG].pinNum = 9;
    tty->spiPinConfig[SPI_SCK_SIG].portNum = PORT_A;
    tty->spiPinConfig[SPI_SCK_SIG].functionConfig = 3;
    
    tty->spiPinConfig[SPI_MISO_SIG].pinNum = 15;
    tty->spiPinConfig[SPI_MISO_SIG].portNum = PORT_A;
    tty->spiPinConfig[SPI_MISO_SIG].functionConfig = 2;
    
    tty->spiPinConfig[SPI_MOSI_SIG].pinNum = 8;
    tty->spiPinConfig[SPI_MOSI_SIG].portNum = PORT_A;
    tty->spiPinConfig[SPI_MOSI_SIG].functionConfig = 3;
    
    tty->dopoConfig = 0;
    tty->dipoConfig = 3;
  }
  else if (tty == SPI_CHANNEL_1)
  {
    tty->sercom = &(SERCOM5->SPI);
    tty->spiPinConfig[SPI_CS_SIG].pinNum = 22;
    tty->spiPinConfig[SPI_CS_SIG].portNum = PORT_B;
    tty->spiPinConfig[SPI_CS_SIG].functionConfig = 3;
    
    tty->spiPinConfig[SPI_SCK_SIG].pinNum = 3;
    tty->spiPinConfig[SPI_SCK_SIG].portNum = PORT_B;
    tty->spiPinConfig[SPI_SCK_SIG].functionConfig = 3;
    
    tty->spiPinConfig[SPI_MISO_SIG].pinNum = 2;
    tty->spiPinConfig[SPI_MISO_SIG].portNum = PORT_B;
    tty->spiPinConfig[SPI_MISO_SIG].functionConfig = 3;
    
    tty->dopoConfig = 0;
    tty->dipoConfig = 3;
  }
}
#endif // if BSP_SUPPORT != BOARD_FAKE
// eof bspSpi.c
