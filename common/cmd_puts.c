/*
 * Copyright (C) 2000-2005, DENX Software Engineering
 *		Wolfgang Denk <wd@denx.de>
 * Copyright (C) Procsys. All rights reserved.
 *		Mushtaq Khan <mushtaq_k@procsys.com>
 *			<mushtaqk_921@yahoo.co.in>
 * (C) Copyright 2008-2009 Freescale Semiconductor, Inc.
 *		Terry Lv <r65388@freescale.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#include <common.h>

#ifdef CONFIG_CONSOLE_QUIET
#define PUTS dmesg_puts
#else
#define PUTS printf
#endif

static int do_puts(cmd_tbl_t *cmdtp, int flag, int argc, char *argv[])
{
  int i;
  if(argc>1) {
    for(i=1;i<argc;i++) {
      dmesg_puts(argv[i]);
      if(i!=argc-1)
	dmesg_puts(" ");
      else
	dmesg_puts("\n");
    };
    return 0;
  }

  cmd_usage(cmdtp);
  return 1;
}

U_BOOT_CMD(
	puts,	CONFIG_SYS_MAXARGS,	1,	do_puts,
#ifdef CONFIG_CONSOLE_QUIET
	"puts string to console (override the quiet option)",
	"- puts string to console (override the quiet option)"
#else
	"puts string to console",
	"- puts string to console"
#endif
);