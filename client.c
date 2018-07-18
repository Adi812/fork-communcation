#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(void){
    int fd=open("letter.p",O_WRONLY);
    if(fd==-1) perror("open"),exit(1);
 
     char buf[1024]={0};
     while(1){
         memset(buf,0x00,sizeof(buf));
         printf("Client Enter#");
         fflush(stdout);
         scanf("%s",buf);
         write(fd,buf,strlen(buf));
         }
    close(fd);
    return 0;
}
