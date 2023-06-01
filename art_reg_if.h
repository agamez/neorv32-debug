#ifndef __art_reg_if_h__
#define __art_reg_if_h__

#include <stdio.h>
#include <inttypes.h>

struct art_reg_if_cb {
	char *version;
	void (*reset)();
	const struct bank_manager *config_bank_manager;
	const struct bank_manager *bank_managers;
	size_t last_bank;
};

union bank_data {
	void *ptr;
	uint8_t u8;
	uint16_t u16;
	uint32_t u32;
	uint64_t u64;
};

struct bank_manager {
	union bank_data bank_data;
	char *regs;
};

int art_reg_if(struct art_reg_if_cb *cb, void *user_data);

#endif /* __art_reg_if_h__ */
