#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>

//sever answer for read
int main(void){
    mkfifo("letter.p",0644);
    int fd=open("letter.p",O_RDONLY);
    if(fd==-1) perror("open"),exit(1);

    char buf[1024]={0};
    while(1){
        memset(buf,0x00,sizeof(buf));
        int ret=read(fd,buf,sizeof(buf)-1);
        if(ret==-1){
            perror("read");
            return -1;
        }else if(ret==0){
            printf("client quit...\n");
            break;
        }else{
            buf[ret]=0;
            printf("client say:%s\n",buf);
        }
    }
    close(fd);
    return 0;
}
