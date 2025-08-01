// you need to find sum of even numbers in parent process and find sum of odd number sum in child process
// print even sum first and odd sum after it
// p1<0, error
// p1=0, child
// p1>0, parent
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main(){
    int n;
    scanf("%d",&n);
    int nums[n];
    for(int i=0;i<n;i++){
        scanf("%d",&nums[i]);
    }
    pid_t p1=fork();
    if(p1<0){
        printf("Process Not Created!!!\n");
        exit(1);
    }
    else if(p1==0){ // child process, odd sum
        int odd_sum=0;
        for(int i=0;i<n;i++){
            if(nums[i]%2==1){
                odd_sum+=nums[i];
            }
        }
        wait(NULL);
        printf("Odd sum: %d\n",odd_sum);
    }
    else{ // parent process, even sum
        int even_sum=0;
        for(int i=0;i<n;i++){
            if(nums[i]%2==0){
                even_sum+=nums[i];
            }
        }
        printf("Even sum: %d\n",even_sum);
        exit(0);
    }
    return 0;
}
