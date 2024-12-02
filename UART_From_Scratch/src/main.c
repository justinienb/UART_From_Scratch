/**
 * \file
 *
 * \brief Empty user application template
 *
 */

/**
 * \mainpage User Application template doxygen documentation
 *
 * \par Empty user application template
 *
 * Bare minimum empty user application template
 *
 * \par Content
 *
 * -# Include the ASF header files (through asf.h)
 * -# "Insert system clock initialization code here" comment
 * -# Minimal main function that starts with a call to board_init()
 * -# "Insert application code here" comment
 *
 */

/*
 * Include header files for all drivers that have been imported from
 * Atmel Software Framework (ASF).
 */
/*
 * Support and FAQ: visit <a href="https://www.microchip.com/support/">Microchip Support</a>
 */
#include <asf.h>
#include <stdio.h>

int main (void)
{

	/* Insert system clock initialization code here (sysclk_init()). */

	board_init();
	
	int32_t clk = sysclk_get_main_hz();


	sam_usart_opt_t usart_console_option = {
		.baudrate = 9600,
		.char_length = US_MR_CHRL_8_BIT,
		.parity_type = US_MR_PAR_NO,
		.stop_bits = US_MR_NBSTOP_1_BIT,
		.channel_mode = US_MR_CHMODE_NORMAL
	};
	
	usart_init_rs232(USART0, &usart_console_option, clk);
	
	usart_enable_tx(USART0);
	usart_enable_rx(USART0);
	
	while(!usart_is_tx_ready(USART0));
	usart_putchar(USART0, 'D');


	/* Insert application code here, after the board has been initialized. */
}
