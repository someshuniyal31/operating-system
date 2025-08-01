#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    pid_t p1,p2;
    p1=fork();
    if(p1<0){
        printf("Process Not Created!!!\n");
        exit(1);
    }
    if(p1==0){
        printf("Child 1 ID: %d, used to print files...\n",getpid());
        execlp("ls","ls","-l",(char*)NULL);
        exit(1);
    }
    else{
        wait(NULL);
        printf("Parent ID: %d\n",getpid());
        printf("Child has finished its execution...\n");
        p2=fork();
        if(p2<0){
            printf("Process Not Created!!!\n");
            exit(1);
        }
        if(p2==0){
            sleep(10);
            printf("Child 2 ID: %d\n",getpid());
            printf("Parent ID of Child 2: %d\n",getppid());
        }
        else{
            printf("Completed chlild 2 of Parent: %d\n",getpid());
            exit(0);
        }
    }
    return 0;
}