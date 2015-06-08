/*
 * Copyright (C) 2015 Voipac.
 *
 * Configuration settings for the Fedevel i.MX6 REX board.
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef __CONFIG_H
#define __CONFIG_H

#include <asm/arch/imx-regs.h>
#include <asm/imx-common/gpio.h>
#include <linux/sizes.h>
#include "mx6_common.h"

#define CONFIG_MX6
#define CONFIG_DISPLAY_CPUINFO
#define CONFIG_DISPLAY_BOARDINFO

#define MACH_TYPE_MX6REX		4777
#define CONFIG_MACH_TYPE		MACH_TYPE_MX6REX
#define CONFIG_BOOTDELAY		3

#define CONFIG_LOADADDR			0x10800000
#define CONFIG_SYS_TEXT_BASE		0x17800000

#if defined(CONFIG_MX6Q)
#define CONFIG_REX_DEFAULT_ARCH_PREFIX	"imx6q"
#define CONFIG_REX_PHYS_SDRAM_SIZE	SZ_2G
#elif defined(CONFIG_MX6DL)
#define CONFIG_REX_DEFAULT_ARCH_PREFIX	"imx6dl"
#define CONFIG_REX_PHYS_SDRAM_SIZE	SZ_2G
#elif defined(CONFIG_MX6S)
#define CONFIG_REX_DEFAULT_ARCH_PREFIX	"imx6s"
#define CONFIG_REX_PHYS_SDRAM_SIZE	SZ_1G
#endif

/* TAGs */
#define CONFIG_CMDLINE_TAG
#define CONFIG_SETUP_MEMORY_TAGS
#define CONFIG_INITRD_TAG
#define CONFIG_REVISION_TAG

#define CONFIG_SYS_GENERIC_BOARD

/* Size of malloc() pool */
#define CONFIG_SYS_MALLOC_LEN		(10 * SZ_1M)

#define CONFIG_BOARD_EARLY_INIT_F
#define CONFIG_BOARD_LATE_INIT

/* Gpio Configs */
#define CONFIG_MXC_GPIO

/* Uart Configs */
#define CONFIG_MXC_UART
#define CONFIG_MXC_UART_BASE		UART1_BASE

/* MMC Configs */
#define CONFIG_FSL_ESDHC
#define CONFIG_FSL_USDHC
#define CONFIG_SYS_FSL_ESDHC_ADDR	USDHC2_BASE_ADDR

#define CONFIG_MMC
#define CONFIG_CMD_MMC
#define CONFIG_GENERIC_MMC
#define CONFIG_BOUNCE_BUFFER
#define CONFIG_CMD_FAT
#define CONFIG_FAT_WRITE
#define CONFIG_CMD_EXT2
#define CONFIG_CMD_EXT4
#define CONFIG_CMD_EXT4_WRITE
#define CONFIG_DOS_PARTITION
#define CONFIG_SYS_FSL_USDHC_NUM	1

/* SPI Configs */
#define CONFIG_CMD_SF
#ifdef CONFIG_CMD_SF
#define CONFIG_SPI_FLASH
#define CONFIG_SPI_FLASH_SST
#define CONFIG_MXC_SPI
#define CONFIG_SF_DEFAULT_BUS		2
#define CONFIG_SF_DEFAULT_CS		2
#define CONFIG_SF_DEFAULT_SPEED		20000000
#define CONFIG_SF_DEFAULT_MODE		SPI_MODE_0
#endif

/* Ethernet config */
#define CONFIG_CMD_PING
#define CONFIG_CMD_DHCP
#define CONFIG_CMD_MII
#define CONFIG_CMD_NET
#define CONFIG_FEC_MXC
#define CONFIG_MII
#define IMX_FEC_BASE			ENET_BASE_ADDR
#define CONFIG_FEC_XCV_TYPE		RGMII
#define CONFIG_ETHPRIME			"FEC"
#define CONFIG_FEC_MXC_PHYADDR		3

#define CONFIG_PHYLIB
#define CONFIG_PHY_MICREL
#define CONFIG_PHY_MICREL_KSZ9021

/* allow to overwrite serial and ethaddr */
#define CONFIG_ENV_OVERWRITE
#define CONFIG_CONS_INDEX		1
#define CONFIG_BAUDRATE			115200

/* Miscellaneous configurable options */
#define CONFIG_SYS_LONGHELP
#define CONFIG_SYS_HUSH_PARSER
#define CONFIG_SYS_PROMPT	       "Rex U-Boot > "
#define CONFIG_SYS_PROMPT_HUSH_PS2     "Rex U-Boot > "
#define CONFIG_AUTO_COMPLETE
#define CONFIG_SYS_CBSIZE		256

/* Print Buffer Size */
#define CONFIG_SYS_PBSIZE		(CONFIG_SYS_CBSIZE + sizeof(CONFIG_SYS_PROMPT) + 16)
#define CONFIG_SYS_MAXARGS		16
#define CONFIG_SYS_BARGSIZE		CONFIG_SYS_CBSIZE

#define CONFIG_SYS_MEMTEST_START	0x80000000
#define CONFIG_SYS_MEMTEST_END		(CONFIG_SYS_MEMTEST_START + SZ_512M)
#define CONFIG_SYS_MEMTEST_SCRATCH	CONFIG_LOADADDR

#define CONFIG_SYS_LOAD_ADDR		CONFIG_LOADADDR

#define CONFIG_CMDLINE_EDITING
#define CONFIG_STACKSIZE		SZ_128K

/* Physical Memory Map */
#define CONFIG_NR_DRAM_BANKS		1
#define PHYS_SDRAM			MMDC0_ARB_BASE_ADDR
#define PHYS_SDRAM_SIZE			CONFIG_REX_PHYS_SDRAM_SIZE

#define CONFIG_SYS_SDRAM_BASE		PHYS_SDRAM
#define CONFIG_SYS_INIT_RAM_ADDR	IRAM_BASE_ADDR
#define CONFIG_SYS_INIT_RAM_SIZE	IRAM_SIZE

#define CONFIG_SYS_INIT_SP_OFFSET \
	(CONFIG_SYS_INIT_RAM_SIZE - GENERATED_GBL_DATA_SIZE)
#define CONFIG_SYS_INIT_SP_ADDR \
	(CONFIG_SYS_INIT_RAM_ADDR + CONFIG_SYS_INIT_SP_OFFSET)

/* FLASH and environment organization */
#define CONFIG_SYS_NO_FLASH
#define CONFIG_ENV_IS_IN_SPI_FLASH

#if defined(CONFIG_ENV_IS_IN_SPI_FLASH)
#define CONFIG_ENV_SIZE			(SZ_8K)
#define CONFIG_ENV_OFFSET		(8 * SZ_64K)
#define CONFIG_ENV_SECT_SIZE		CONFIG_ENV_SIZE
#define CONFIG_ENV_SPI_BUS		CONFIG_SF_DEFAULT_BUS
#define CONFIG_ENV_SPI_CS		CONFIG_SF_DEFAULT_CS
#define CONFIG_ENV_SPI_MAX_HZ		CONFIG_SF_DEFAULT_SPEED
#define CONFIG_ENV_SPI_MODE		CONFIG_SF_DEFAULT_MODE
#endif

/* Command definition */
#include <config_cmd_default.h>

#undef CONFIG_CMD_IMLS

/* Miscellaneous commands */
#define CONFIG_OF_LIBFDT
#define CONFIG_CMD_BMODE
#define CONFIG_CMD_BOOTZ
#define CONFIG_CMD_SETEXPR

#ifndef CONFIG_SYS_DCACHE_OFF
#define CONFIG_CMD_CACHE
#endif

/* I2C Configs */
#define CONFIG_CMD_I2C
#define CONFIG_SYS_I2C
#define CONFIG_SYS_I2C_MXC
#define CONFIG_SYS_I2C_SPEED		100000

/* Framebuffer */
#if 0
#define CONFIG_VIDEO
#define CONFIG_VIDEO_IPUV3
#define CONFIG_CFB_CONSOLE
#define CONFIG_VGA_AS_SINGLE_DEVICE
#define CONFIG_SYS_CONSOLE_IS_IN_ENV
#define CONFIG_SYS_CONSOLE_OVERWRITE_ROUTINE
#define CONFIG_VIDEO_BMP_RLE8
#define CONFIG_SPLASH_SCREEN
#define CONFIG_SPLASH_SCREEN_ALIGN
#define CONFIG_BMP_16BPP
#define CONFIG_VIDEO_LOGO
#define CONFIG_VIDEO_BMP_LOGO
#define CONFIG_IPUV3_CLK 260000000
#define CONFIG_IMX_HDMI
#define CONFIG_IMX_VIDEO_SKIP
#endif

/* PCI Configs */
#define CONFIG_CMD_PCI
#ifdef CONFIG_CMD_PCI
#define CONFIG_PCI
#define CONFIG_PCI_PNP
#define CONFIG_PCI_SCAN_SHOW
#define CONFIG_PCIE_IMX
#define CONFIG_PCIE_IMX_PERST_GPIO	IMX_GPIO_NR(5, 2)
#endif

/* Fuse Configs */
#define CONFIG_CMD_FUSE
#ifdef CONFIG_CMD_FUSE
#define CONFIG_MXC_OCOTP
#endif

/* Env settings */
#define CONFIG_ENV_CONSOLE_DEV		"ttymxc0"
#define CONFIG_ENV_MMCROOT		"/dev/mmcblk2p2"
#define CONFIG_ENV_DEFAULT_FDT_FILE	CONFIG_REX_DEFAULT_ARCH_PREFIX "-rex.dtb"
#define CONFIG_ENV_DEFAULT_ETH_ADDR	"00:0D:15:00:D1:75"
#define CONFIG_ENV_DEFAULT_CLIENT_IP	"192.168.0.150"
#define CONFIG_ENV_DEFAULT_SERVER_IP	"192.168.0.1"
#define CONFIG_ENV_DEFAULT_NETMASK	"255.255.255.0"
#define CONFIG_ENV_DEFAULT_UPD_UBOOT	"imx6/u-boot-" CONFIG_REX_DEFAULT_ARCH_PREFIX "-rex.imx"
#define CONFIG_ENV_DEFAULT_UPD_KERNEL	"imx6/zImage-" CONFIG_REX_DEFAULT_ARCH_PREFIX "-rex"
#define CONFIG_ENV_DEFAULT_UPD_FDT	"imx6/"        CONFIG_ENV_DEFAULT_FDT_FILE
#define CONFIG_ENV_DEFAULT_UPD_SCRIPT	"imx6/boot-"   CONFIG_REX_DEFAULT_ARCH_PREFIX "-rex.scr"

#define CONFIG_EXTRA_ENV_SETTINGS \
	"script=boot.scr\0" \
	"image=zImage\0" \
	"fdt_file=" CONFIG_ENV_DEFAULT_FDT_FILE "\0" \
	"fdt_addr=0x18000000\0" \
	"boot_fdt=try\0" \
	"ip_dyn=yes\0" \
	"console=" CONFIG_ENV_CONSOLE_DEV "\0" \
	"fdt_high=0xffffffff\0" \
	"initrd_high=0xffffffff\0" \
	"mmcdev=0\0" \
	"mmcpart=1\0" \
	"mmcroot=" CONFIG_ENV_MMCROOT " rootwait rw\0" \
	"spidev=" __stringify(CONFIG_ENV_SPI_BUS) "\0" \
	"spics=" __stringify(CONFIG_ENV_SPI_CS) "\0" \
	"update_set_ethernet=" \
		"if test ${ethaddr}; then; else " \
			"setenv ethaddr  " CONFIG_ENV_DEFAULT_ETH_ADDR  "; " \
		"fi; " \
		"if test ${ipaddr}; then; else " \
			"setenv ipaddr   " CONFIG_ENV_DEFAULT_CLIENT_IP "; " \
		"fi; " \
		"if test ${serverip}; then; else " \
			"setenv serverip " CONFIG_ENV_DEFAULT_SERVER_IP "; " \
		"fi; " \
		"if test ${netmask}; then; else " \
			"setenv netmask  " CONFIG_ENV_DEFAULT_NETMASK   "; " \
		"fi\0" \
	"update_set_filename=" \
		"if test ${upd_uboot}; then; else " \
			"setenv upd_uboot " CONFIG_ENV_DEFAULT_UPD_UBOOT   "; " \
		"fi; " \
		"if test ${upd_kernel}; then; else " \
			"setenv upd_kernel " CONFIG_ENV_DEFAULT_UPD_KERNEL "; " \
		"fi; " \
		"if test ${upd_fdt}; then; else " \
			"setenv upd_fdt " CONFIG_ENV_DEFAULT_UPD_FDT       "; " \
		"fi; " \
		"if test ${upd_script}; then; else " \
			"setenv upd_script " CONFIG_ENV_DEFAULT_UPD_SCRIPT "; " \
		"fi\0" \
	"update_uboot=" \
		"run update_set_ethernet; " \
		"run update_set_filename; " \
		"if sf probe ${spidev}:${spics}; then "	\
			"if tftp ${upd_uboot}; then " \
				"setexpr align_sz ${filesize} + 0x7FFF; " \
				"setexpr align_sz ${align_sz} / 0x8000; " \
				"setexpr align_sz ${align_sz} * 0x8000; " \
				"sf erase 0x0 ${align_sz}; " \
				"sf write ${loadaddr} 0x400 ${filesize}; " \
			"fi; "	\
		"fi\0" \
	"update_kernel=" \
		"run update_set_ethernet; " \
		"run update_set_filename; " \
		"if mmc dev ${mmcdev}; then "	\
			"if tftp ${upd_kernel}; then " \
				"fatwrite mmc ${mmcdev}:${mmcpart} " \
				"${loadaddr} ${image} ${filesize}; " \
			"fi; "	\
		"fi\0" \
	"update_fdt=" \
		"run update_set_ethernet; " \
		"run update_set_filename; " \
		"if mmc dev ${mmcdev}; then "	\
			"if tftp ${upd_fdt}; then " \
				"fatwrite mmc ${mmcdev}:${mmcpart} " \
				"${loadaddr} ${fdt_file} ${filesize}; " \
			"fi; "	\
		"fi\0" \
	"update_script=" \
		"run update_set_ethernet; " \
		"run update_set_filename; " \
		"if mmc dev ${mmcdev}; then "	\
			"if tftp ${upd_script}; then " \
				"fatwrite mmc ${mmcdev}:${mmcpart} " \
				"${loadaddr} ${script} ${filesize}; " \
			"fi; "	\
		"fi\0" \
	"mmcargs=setenv bootargs console=${console},${baudrate} " \
		"root=${mmcroot}\0" \
	"loadbootscript=" \
		"fatload mmc ${mmcdev}:${mmcpart} ${loadaddr} ${script};\0" \
	"bootscript=echo Running bootscript from mmc ...; " \
		"source\0" \
	"loadimage=fatload mmc ${mmcdev}:${mmcpart} ${loadaddr} ${image}\0" \
	"loadfdt=fatload mmc ${mmcdev}:${mmcpart} ${fdt_addr} ${fdt_file}\0" \
	"mmcboot=echo Booting from mmc ...; " \
		"run mmcargs; " \
		"if test ${boot_fdt} = yes || test ${boot_fdt} = try; then " \
			"if run loadfdt; then " \
				"bootz ${loadaddr} - ${fdt_addr}; " \
			"else " \
				"if test ${boot_fdt} = try; then " \
					"bootz; " \
				"else " \
					"echo WARN: Cannot load the DT; " \
				"fi; " \
			"fi; " \
		"else " \
			"bootz; " \
		"fi;\0" \
	"netargs=setenv bootargs console=${console},${baudrate} " \
		"root=/dev/nfs " \
	"ip=dhcp nfsroot=${serverip}:${nfsroot},v3,tcp\0" \
		"netboot=echo Booting from net ...; " \
		"run netargs; " \
		"if test ${ip_dyn} = yes; then " \
			"setenv get_cmd dhcp; " \
		"else " \
			"setenv get_cmd tftp; " \
		"fi; " \
		"${get_cmd} ${image}; " \
		"if test ${boot_fdt} = yes || test ${boot_fdt} = try; then " \
			"if ${get_cmd} ${fdt_addr} ${fdt_file}; then " \
				"bootz ${loadaddr} - ${fdt_addr}; " \
			"else " \
				"if test ${boot_fdt} = try; then " \
					"bootz; " \
				"else " \
					"echo WARN: Cannot load the DT; " \
				"fi; " \
			"fi; " \
		"else " \
			"bootz; " \
		"fi;\0"

#define CONFIG_BOOTCOMMAND \
	"mmc dev ${mmcdev};" \
	"if mmc rescan; then " \
		"if run loadbootscript; then " \
			"run bootscript; " \
		"else " \
			"if run loadimage; then " \
				"run mmcboot; " \
			"else run netboot; " \
			"fi; " \
		"fi; " \
	"else run netboot; fi"

#endif
