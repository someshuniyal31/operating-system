
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int main(){
    int s;
    printf("Enter size of input string: ");
    scanf("%d",&s);    
    int *nums=(int*)malloc(s*sizeof(int));
    printf("Enter input string...\n");
    for(int i=0;i<s;i++){
        scanf("%d",&nums[i]);
    }
    int n;
    printf("Enter size of page array: ");
    scanf("%d",&n);
    int *page=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){page[i]=-1;}
    int *index=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){index[i]=-1;}
    double hit=0.00,fault=0.00;
    for(int i=0;i<s;i++){
        int p=nums[i];
        bool found=false;
        for(int j=0;j<n;j++){
            if(page[j]==p){
                index[j]=i;
                hit++;found=true;
                break;
            }
        }
        if(!found){
            int minindex=0;int minelement=index[0];
            for(int j=0;j<n;j++){
                if(index[j]<minelement){
                    minindex=j;minelement=index[j];
                }
            }
            page[minindex]=p;
            index[minindex]=i;
            fault++;
        }
        printf("Current Page container...\n");
        for(int k=0;k<n;k++){
            if(page[k]==-1){printf(" - ");}
            else{printf("[%d]",page[k]);}
        }
        printf("\n");
    }
    double attempts=hit+fault;
    double hit_ratio=hit/attempts;
    double fault_ratio=fault/attempts;
    printf("Total Attempts: %.0f\n",attempts);
    printf("Hit Ratio: %.2f, (Total Hits: %.0f)\n",hit_ratio,hit);
    printf("Fault Ratio: %.2f, (Total Fault Pages: %.0f)",fault_ratio,fault);
    return 0;
}
 
