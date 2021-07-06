
#include "kernel/param.h"

#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

#include "kernel/fs.h"
#include "kernel/fcntl.h"
#include "kernel/syscall.h"
#include "kernel/memlayout.h"
#include "kernel/riscv.h"
//#include "kernel/proc.h"

//#include "kernel/string.c"

//#include "kernel/defs.h"
//#include "kernel/sysproc.c"

//simple sleep
int sleep_2(int);

int sleep_2(int time){
    if(time < 0){
        printf("Time needs to be positive");
        return -1;
    } else{
        
        //int i = 0;
        //for(i =0; i < time; i++){
            //syscall(13);
            sleep(time);
            //sys_sleep();
        //}
        return 0;
        
    }
    return 0;
}

int main(int argc, char *argv[]){
    if(argc < 1){
        printf("Error, needs 2 arguments");
    } else //if(strcmp(argv[0], "sleep") == 0)
        sleep_2(atoi(argv[1]));
    exit(1);
}