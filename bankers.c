#include<stdio.h>

int main(){

    int n = 3,m=3;
    int alloc[3][3] = {
        {1,0,1},
        {1,1,0},
        {1,0,1}
    };

    int max[3][3] = {
        {2,1,1},
        {2,2,2},
        {3,1,2}
    };

    int avail[3] = {0,2,2};
    int need[3][3],finish[3]={0,0,0};
    int safe[3];
    int work[3]={3,2,2};
    int count = 0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    while(count<n){
        int found = 0;

        for(int i = 0;i<n;i++){
            if(finish[i]==0){
                int j;
                for(j=0;j<m;j++){
                    if(need[i][j]>work[j]){
                        break;
                    }
                }
                if(j==m){
                    for(int k =0;k<m;k++){
                        work[k]+=alloc[i][k];
                    }
                    safe[count]=i;
                    count++;
                    finish[i]=1;
                    found=1;
                }
            }
        }
        if(found==0){
            break;
        }
    }

    if(count==n){
        printf("System is in a safe state.\nSafe Sequence:");
        for(int i=0;i<n;i++){
            printf("P%d",safe[i]);
            if(i<n-1){
                printf("->");
            }
        }
        printf("\n");

    }
    else{
        printf("System is in unsafe state.\n");
    }
    return 0;
}