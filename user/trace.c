//trace.c
#include "kernel/param.h"
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char* argv[]){

    if(strcmp(argv[0], "trace") == 0){
        printf("Strcmp to trace success\n");
        int mask = atoi(argv[1]);
        if(mask < 0){
            fprintf(2, "Mask < 0, trace failed\n");
            exit(1);
        }
        //int ret = trace(mask);
        if(trace(mask) < 0)
            fprintf(2, "Return value <0, trace failed");
        //copy arguments into another program
        char* array[MAXARG];
        int j;
        for(j = 2; j < argc; j++){
            array[j-2] = argv[j];
            printf("array[%d] = %s\n", j-2, argv[j]);
        }
        exec(array[0], array);
    }
    return 0;
}