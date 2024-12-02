/**
 * \file
 *
 * \brief User board initialization template
 *
 */
/*
 * Support and FAQ: visit <a href="https://www.microchip.com/support/">Microchip Support</a>
 */

#include <asf.h>
#include <board.h>
#include <conf_board.h>

void board_init(void)
{
	/* This function is meant to contain board-specific initialization code
	 * for, e.g., the I/O pins. The initialization can rely on application-
	 * specific board configuration, found in conf_board.h.
	 */
	sysclk_init();
	
	sysclk_enable_peripheral_clock(ID_PIOA);
	pio_set_peripheral(PIOA, PIO_PERIPH_A,  PIO_PA9 | PIO_PA10);
		
	sysclk_enable_peripheral_clock(ID_FLEXCOM0);
	flexcom_set_opmode(FLEXCOM0, FLEXCOM_MR_OPMODE_USART);


	
}
