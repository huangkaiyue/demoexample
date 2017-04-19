#include <stdio.h>
#include <string.h>

int main(void){
	FILE *fp=NULL;
	char buf[512]={0};
	while(1){
		if((fp = popen("ping 192.168.6.1", "r"))==NULL){
			printf("popen failed \n");
			return -1;
		}
		memset(buf,0,128);
		fread(buf,128, 1, fp);
		//fgets(buf, 128, fp);
		//fgets(buf, 128, fp);
		if(strstr(buf,"unreach")){
			printf("unreachable \n");	
		}
		printf("buf = %s len =%c \n",buf,buf[1]);
		pclose(fp);
		sleep(1);
	}
	return 0;
}

