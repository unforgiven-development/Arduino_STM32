/**********************************************************************************************************************
 * The MIT License                                                                                                    *
 *                                                                                                                    *
 * Copyright (c) 2011 LeafLabs, LLC.                                                                                  *
 *                                                                                                                    *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated       *
 * documentation files (the "Software"), to deal in the Software without restriction, including without limitation    *
 * the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and   *
 * to permit persons to whom the Software is furnished to do so, subject to the following conditions:                 *
 *                                                                                                                    *
 * The above copyright notice and this permission notice shall be included in all copies or substantial portions of   *
 * the Software.                                                                                                      *
 *                                                                                                                    *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO   *
 * THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE     *
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF          *
 * CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS  *
 * IN THE SOFTWARE.                                                                                                   *
 **********************************************************************************************************************/

/**
 * \file	board.h
 * \author	Gerad Munsch <gmunsch@unforgivendevelopment.com>
 * \author	Marti Bolivar <mbolivar@leaflabs.com>
 *
 * \brief Private include file for the Embest/Element 14 Embedded Pi STM32 development board
 *
 * See maple.h for more information on these definitions.
 *
 * \todo Improve the documentation in this header
 */

#ifndef _BOARDS_EMBEDDED_PI_H__
#define _BOARDS_EMBEDDED_PI_H__


/*
 * A few of these values will seem strange given that it's a high-density board.
 */

/*! The default clock rate is \b 72MHz -- giving the following value */
#define CYCLES_PER_MICROSECOND	72
/*! Takes a cycle to reload */
#define SYSTICK_RELOAD_VAL		(F_CPU / 1000) - 1


/* -----[ USARTS ]----- */

#define BOARD_NR_USARTS 3

/**
 * \note On this board, \b USART1 does not seem to be used. However, \b USART1 should be usable at \b D26 for the \b TX1
 *       pin and \b D28 for the \b RX1 pin. The \b CTS and \b RTS functions seem to be associated with the \b USB
 *       peripheral.
 */
#define BOARD_USART1_TX_PIN PA9
#define BOARD_USART1_RX_PIN PA10

/**
 * \note On this board, \b USART2 is assigned to \b Serial2 (ie: the \b RX2 and \b TX2 pins, located at "Arduino" board
 *       pins \b D22 and \b D23 -- the inner row of the pin headers).
 */
#define BOARD_USART2_TX_PIN PA2
#define BOARD_USART2_RX_PIN PA3

/**
 * \note On this board, \b USART3 is assigned to \b Serial / \b Serial1 (ie: the \b RX and \b TX pins, located at the
 *       "Arduino" pin positions \b D0 and \b D1 on the board).
 */
#define BOARD_USART3_TX_PIN PC10
#define BOARD_USART3_RX_PIN PC11



/**
 * NOTE:
 *
 * SPI3 is unusable due to pin 43 (PB4) and NRST tie-together :(, but leave the definitions so as not to clutter things
 * up.  This is only OK since RET6 Ed. is specifically advertised as a beta board.
 */
#define BOARD_NR_SPI 2

/**
 * \note The \b SPI1 peripheral is associated with the \e secondary \b SPI port on this board, which is located on the
 *       following pins:
 *       \li \b SPI1_NSS -- pin \b D32
 *       \li \b SPI1_MOSI -- pin \b D33
 *       \li \b SPI1_MISO -- pin \b D34
 *       \li \b SPI1_SCK -- pin \b D35
 */
#define BOARD_SPI1_NSS_PIN	PA4
#define BOARD_SPI1_SCK_PIN	PA5
#define BOARD_SPI1_MISO_PIN	PA6
#define BOARD_SPI1_MOSI_PIN	PA7

/**
 * \note The \b SPI2 peripheral is associated with the primary \b SPI port on this board (ie: "Arduino" pins \b D10 to
 *       \b D13 and the \b SPI or \b ISP header at the bottom center of the board).
 */
#define BOARD_SPI2_NSS_PIN	PB12
#define BOARD_SPI2_SCK_PIN	PB13
#define BOARD_SPI2_MISO_PIN	PB14
#define BOARD_SPI2_MOSI_PIN	PB15



/* GPIO A to E = 5 * 16  - BOOT1 not used = 79*/
//#define BOARD_NR_GPIO_PINS      51
#define BOARD_NR_GPIO_PINS 45

/* Note: NOT 19. The missing one is D38 a.k.a. BOARD_BUTTON_PIN, which
 * isn't broken out to a header and is thus unusable for PWM. */

//#define BOARD_NR_PWM_PINS       19
//#define BOARD_NR_ADC_PINS       16
//#define BOARD_NR_USED_PINS      7
#define BOARD_NR_PWM_PINS	8
#define BOARD_NR_ADC_PINS	8
#define BOARD_NR_USED_PINS	8	/*! What does this define? */


/**
 * JTAG configuration
 * The following pins define the board's \b JTAG pins.
 */
#define BOARD_JTMS_SWDIO_PIN    39
#define BOARD_JTCK_SWCLK_PIN    40
#define BOARD_JTDI_PIN          41
#define BOARD_JTDO_PIN          42
#define BOARD_NJTRST_PIN        43


/**
 * USB configuration
 * \c BOARD_USB_DISC_DEV is the GPIO port containing the \b USB_DISC pin, and \c BOARD_USB_DISC_BIT is that pin's bit.
 */
#define BOARD_USB_DISC_DEV GPIOB
#define BOARD_USB_DISC_BIT 4


/**
 * SDIO configuration
 * The following pins define the board's \b SDIO pins.
 */
#define BOARD_SDIO_D0	PC8
#define BOARD_SDIO_D1	PC9
#define BOARD_SDIO_D2	PC10
#define BOARD_SDIO_D3	PC11
#define BOARD_SDIO_CLK	PC12
#define BOARD_SDIO_CMD	PD2

/**
 * Pin aliases:
 * These give the GPIO port/bit for each pin as an enum.
 *
 * These are optional, but recommended. They make it easier to write code using low-level GPIO functionality.
 */
enum {
	PA0,
	PA1,
	PA2,
	PA3,
	PA4,
	PA5,
	PA6,
	PA7,
	PA8,
	PA9,
	PA10,
	PA11,
	PA12,
	PA13,
	PA14,
	PA15,
	PB0,
	PB1,
	PB2,
	PB3,
	PB4,
	PB5,
	PB6,
	PB7,
	PB8,
	PB9,
	PB10,
	PB11,
	PB12,
	PB13,
	PB14,
	PB15,
	PC0,
	PC1,
	PC2,
	PC3,
	PC4,
	PC5,
	PC6,
	PC7,
	PC8,
	PC9,
	PC10,
	PC11,
	PC12,
	PC13,
	PC14,
	PC15,
	PD0,
	PD1,
	PD2
};
/* Note PB2 is skipped as this is Boot1 and is not going to be much use as its likely to be pulled permanently low */



#endif	/* _BOARDS_EMBEDDED_PI_H__ */
