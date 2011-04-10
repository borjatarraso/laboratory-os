/* lab.c -- An experimental operative system */

#include <multiboot.h>

#define OS_VERSION "Laboratory-OS v0.0"
#define VGA_COL 80
#define VGA_ROW 25

struct _video{
  char c;
  char attr;
} __attribute__((__packed__));

struct _video video_mem[VGA_ROW][VGA_COL];

int strlen(char *s)
{
	int size = 0;
	char *p = s;
	
	while(*p++ != '\0')
		size++;
		
	return size;
}

static __inline__ void
outb(unsigned short port, unsigned char val)
{
  __asm__ volatile("outb %0, %1"::"a"(val), "Nd"(port));
}

int
main (unsigned long magic, multiboot_info_t *mbi)
{
  const char *os_version = OS_VERSION;
  char *os_name = os_version;

  struct _video *write = &video_mem[2][0];

  while(*os_name != '\0'){
    write->c = *os_name;
    write++;
    os_name++;
  }

  os_name = os_version;

  outb(0x3D4, 0x0F);
  outb(0x3D5, (2*VGA_COL+strlen(os_version)) & 0xff);
  outb(0x3D4, 0x0E);
  outb(0x3D5, (2*VGA_COL+strlen(os_version)) >> 8 & 0xff);

  return 0;
}
