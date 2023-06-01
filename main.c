/*
 * File:   %<%NAME%>%.%<%EXTENSION%>%
 * Author: %<%USER%>%
 *
 * Created on %<%DATE%>%, %<%TIME%>%
 */

#include <neorv32.h>
#include <string.h>

#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <art_reg_if.h>

#define BAUD_RATE 19200

#define VERSION_MSG "ART-NG-MCE-1.0"
char x;

const struct bank_manager config_bank_manager = {
	.regs = &x
};


#define RS232_REG_INTERFACE_VERSION " / art_reg_if-v1.0\n"

int main(void)
{	
	// capture all exceptions and give debug info via UART
	// this is not required, but keeps us safe
	neorv32_rte_setup();

	neorv32_uart_setup(NEORV32_UART0, BAUD_RATE, 0);

	struct art_reg_if_cb if_data = {
		.version = VERSION_MSG,
		.config_bank_manager = &config_bank_manager,
	};

	while (1) {
		art_reg_if(&if_data, NULL);
	}
}
