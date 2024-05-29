#include <stdio.h>
#include <unistd.h>

int main(int argc,char *argv[]){
	int i;
	char str[] = "/sys/class/leds/fpga_led0/brightness";
	FILE * file;
	
	while(1)
	{
		for(i=0;i<10;i++)
		{	
			sprintf(str,"/sys/class/leds/fpga_led%d/brightness",i);
			file = fopen(str,"w");
			fprintf(file,"1");
			fclose(file);
			usleep(100000);
		}
		for(i=0;i<10;i++)
		{	
			sprintf(str,"/sys/class/leds/fpga_led%d/brightness",i);
			file = fopen(str,"w");
			fprintf(file,"0");
			fclose(file);
			usleep(100000);
		}
	}
	return 0;
}
