/* SPDX-License-Identifier: GPL-2.0 */
#ifndef AT91_SAMA5_BOOTSOURCE_H_
#define AT91_SAMA5_BOOTSOURCE_H_

#include <errno.h>
#include <bootsource.h>
#include <linux/bitops.h>
#include <linux/bitfield.h>
#include <mach/hardware.h>

/* Boot modes stored by BootROM in r4 */
#define SAMA5_BOOTSOURCE_SPI	0
#define SAMA5_BOOTSOURCE_MCI	1
#define SAMA5_BOOTSOURCE_SMC	2
#define SAMA5_BOOTSOURCE_TWI	3
#define SAMA5_BOOTSOURCE_QSPI	4
#define SAMA5_BOOTSOURCE_SAM_BA	7

#define SAMA5_BOOTSOURCE		GENMASK(3, 0)
#define SAMA5_BOOTSOURCE_INSTANCE	GENMASK(7, 4)

static inline int sama5_bootsource(u32 reg)
{
	u32 dev = FIELD_GET(SAMA5_BOOTSOURCE, reg);

	switch(dev) {
	case SAMA5_BOOTSOURCE_MCI:
		return BOOTSOURCE_MMC;
	case SAMA5_BOOTSOURCE_SPI:
		return BOOTSOURCE_SPI_NOR;
	case SAMA5_BOOTSOURCE_QSPI:
		return BOOTSOURCE_SPI;
	case SAMA5_BOOTSOURCE_SMC:
		return BOOTSOURCE_NAND;
	case SAMA5_BOOTSOURCE_SAM_BA:
		return BOOTSOURCE_SERIAL;
	}
	return BOOTSOURCE_UNKNOWN;
}

static inline int sama5_bootsource_instance(u32 reg)
{
	return FIELD_GET(SAMA5_BOOTSOURCE_INSTANCE, reg);
}

#define __sama5d2_stashed_bootrom_r4 \
	(*(volatile u32 *)(SAMA5D2_SRAM_BASE + SAMA5D2_SRAM_SIZE - 0x4))

#endif
