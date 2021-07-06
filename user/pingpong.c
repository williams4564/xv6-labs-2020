//pingpong

/*
Write a program that uses UNIX system calls to ''ping-pong'' a byte between two processes over 
a pair of pipes, one for each direction. The parent should send a byte to the child; 
the child should print "<pid>: received ping", where <pid> is its process ID, 
write the byte on the pipe to the parent, and exit; 
the parent should read the byte from the child, print "<pid>: received pong", and exit.
 Your solution should be in the file user/pingpong.c. 
*/

/*
Use pipe to create a pipe.
Use fork to create a child.
Use read to read from the pipe, and write to write to the pipe.
Use getpid to find the process ID of the calling process.
Add the program to UPROGS in Makefile. 
*/
#include "kernel/param.h"

#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

#include "kernel/fs.h"
#include "kernel/fcntl.h"
#include "kernel/syscall.h"
#include "kernel/memlayout.h"
#include "kernel/riscv.h"

#define MAX 3

int main(){
    //uint8 byte = 'g';
    char buffer[MAX];
    int fd[2];
    int fd2[2];

    if(pipe(fd) == -1){
        printf("pipe create error");
        exit(1);
    }
    if(pipe(fd2) == -1){
        printf("pipe create error");
        exit(1);
    }
    int pid;
    if((pid = fork() )< 0){
        printf("fork error\n");
        exit(1);
    } else if( pid == 0){
        //wait(0);
        close(fd[1]);

        if(read(fd[0], buffer, 1) != 0){
            printf("%d: received ping\n", getpid());
        }
        close(fd[0]);
        //2nd pipe
        close(fd2[0]);
        write(fd2[1], buffer, strlen(buffer));
        close(fd2[1]);
        exit(0);
    } else {
        close(fd[0]);
        //write(fd[1], (const void*)'g', 1);
        write(fd[1], "g", 1);
        close(fd[1]);
        int st = 0;
        wait(&st);

        //2nd pipe
        close(fd2[1]);
        char strCpy[MAX];
        read(fd2[0], strCpy, MAX);
        printf("%d: received pong\n", getpid());
        close(fd2[0]);
    }
    return 0;
}