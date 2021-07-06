//trace.c
#include "kernel/param.h"
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char* argv[]){

    if(strcmp(argv[0], "trace")){
        int mask = atoi(argv[1]);
        if(mask < 0){
            printf("Mask < 0, trace failed\n");
            exit(1);
        }
        int ret = trace(mask);
        if(ret < 0)
            printf("Return value <0, trace failed");
        //copy arguments into another program
        char* array[MAXARG];
        int j;
        for(j = 2; j < argc; j++){
            array[j-2] = argv[j];
        }
        exec(array[0], array);
    }
    return 0;
}