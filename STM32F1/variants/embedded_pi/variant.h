/**
 * \file variant.h
 * Defines some information about this variant of Arduino board
 */

#ifndef _VARIANT_ARDUINO_STM32__
#define _VARIANT_ARDUINO_STM32__


#define digitalPinToPort(P)			( PIN_MAP[P].gpio_device )
#define digitalPinToBitMask(P)		( BIT(PIN_MAP[P].gpio_bit) )

#define portOutputRegister(port)	( &(port->regs->ODR) )
#define portInputRegister(port)		( &(port->regs->IDR) )

#define portSetRegister(pin)		( &(PIN_MAP[pin].gpio_device->regs->BSRR) )
#define portClearRegister(pin)		( &(PIN_MAP[pin].gpio_device->regs->BRR) )
#define portConfigRegister(pin)		( &(PIN_MAP[pin].gpio_device->regs->CRL) )

/* ================================================================================================================== *
static const uint8_t SS   = BOARD_SPI1_NSS_PIN;
static const uint8_t SS1  = BOARD_SPI2_NSS_PIN;
static const uint8_t MOSI = BOARD_SPI1_MOSI_PIN;
static const uint8_t MISO = BOARD_SPI1_MISO_PIN;
static const uint8_t SCK  = BOARD_SPI1_SCK_PIN;
 * ================================================================================================================== */


/**
 * Define static pin assignments for ease of use in the Arduino IDE
 */

/**
 * SPI port (primary):
 */
static const uint8_t SS		= BOARD_SPI2_NSS_PIN;	/*! Primary SPI port, \b SS pin */
static const uint8_t MOSI	= BOARD_SPI2_MOSI_PIN;	/*! Primary SPI port, \b MOSI pin */
static const uint8_t MISO	= BOARD_SPI2_MISO_PIN;	/*! Primary SPI port, \b MOSI pin */
static const uint8_t SCK	= BOARD_SPI2_SCK_PIN;	/*! Primary SPI port, \b SCK pin */



#endif	/* _VARIANT_ARDUINO_STM32__ */
