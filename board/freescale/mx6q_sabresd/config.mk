LDSCRIPT := $(SRCTREE)/board/$(VENDOR)/$(BOARD)/u-boot.lds

sinclude $(OBJTREE)/board/$(VENDOR)/$(BOARD)/config.tmp

ifndef TEXT_BASE
	TEXT_BASE = 0x17800000
endif
