#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(void){
    char buf[1024]={0};
    printf("%d",sizeof(buf));
    fgets(buf,sizeof(buf),stdin);
}
