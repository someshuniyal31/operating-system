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
    for(int i=0;i<n;i++){
        page[i]=-1;
    }
    int idx=0;
    double hit=0.00,miss=0.00;
    for(int i=0;i<s;i++){
        int p=nums[i];
        bool found=false;
        for(int j=0;j<n;j++){
            if(page[j]==p){
                found=true;hit++;
                break;
            }
        }
        if(!found){
            miss++;
            page[idx++]=p;
            idx=idx%n;
        }
        printf("Current Page container...\n");
        for(int k=0;k<n;k++){
            if(page[k]==-1){printf(" - ");}
            else{printf("[%d]",page[k]);}
        }
        printf("\n");
    }
    double attempts=hit+miss;
    double hit_ratio=hit/attempts;
    double miss_ratio=miss/attempts;
    printf("Total Attempts: %.0f\n",attempts);
    printf("Hit Ratio: %.2f, (Total Hits: %.0f)\n",hit_ratio,hit);
    printf("Miss Ratio: %.2f, (Total Misses: %.0f)",miss_ratio,miss);
    return 0;
}
 
