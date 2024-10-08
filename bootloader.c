// By Jeroen Taverne

#include "pico/stdlib.h"
#include "hardware/structs/watchdog.h"
#include "flash_firmware.h"

#ifdef M33_VTOR_OFFSET
#define START_OFFSET 0
#define VTOR_OFFSET M33_VTOR_OFFSET
#else
#define START_OFFSET 0x100
#define VTOR_OFFSET M0PLUS_VTOR_OFFSET
#endif

static uint32_t sStart = 0;
static const uint32_t offset[NR_OF_FIRMWARES] = {FLASH_FIRMWARE0, FLASH_FIRMWARE1, FLASH_FIRMWARE2, FLASH_FIRMWARE3, FLASH_FIRMWARE4, FLASH_FIRMWARE5};

int main(void) {
	uint32_t firmware_nr = watchdog_hw->scratch[3];

	if (firmware_nr >= NR_OF_FIRMWARES) {
		firmware_nr = 0;
	}

	sStart = offset[firmware_nr] + XIP_BASE;

	// Jump to application
	asm volatile
	(
	    "mov r0, %[start]\n"
	    "ldr r1, =%[vtable]\n"
	    "str r0, [r1]\n"
	    "ldmia r0, {r0, r1}\n"
	    "msr msp, r0\n"
	    "bx r1\n"
	    :
	    : [start] "r" (sStart + START_OFFSET), [vtable] "X" (PPB_BASE + VTOR_OFFSET)
	    :
	);

	return 0;
}
