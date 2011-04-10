noinst_PROGRAMS=lab

lab_LDFLAGS=-Wl,-Ttext=0x100000,--defsym,video_mem=0xB8000
lab_CFLAGS=-nostdinc -nostdlib -fno-builtin -I.
lab_SOURCES= boot.S \
             multiboot.h \
	     lab.c

