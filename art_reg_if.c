#include <neorv32.h>
#include <string.h>

#include "art_reg_if.h"

int art_reg_if(struct art_reg_if_cb *cb, void *user_data)
{
	neorv32_uart0_puts(cb->version);
	neorv32_uart0_puts(" / art_reg_if-v1.0\n");

	while (1) {
		int instruction = neorv32_uart0_getc();
	}
}
