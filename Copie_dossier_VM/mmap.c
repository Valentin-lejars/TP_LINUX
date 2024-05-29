#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include <sys/mman.h>
#include <fcntl.h>

int main(int argc,char *argv[]){
	int i;
	uint32_t * p;
	int fd = open("/dev/mem", O_RDWR);

	while(1)
	{
		for(i=0;i<10;i++)
		{	
			p = (uint32_t*)mmap(NULL, 4, PROT_WRITE|PROT_READ, MAP_SHARED,
			fd, 0xFF203000);
			*p = (1<<i);
			usleep(10000);
		}
		for(i=0;i<10;i++)
		{	
			p = (uint32_t*)mmap(NULL, 4, PROT_WRITE|PROT_READ, MAP_SHARED,
			fd, 0xFF203000);
			*p = (0<<i);
			usleep(10000);
		}
	} 
	return 0;
}
