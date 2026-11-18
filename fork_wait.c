#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

void SortAsc(int arr[],int size){
    for(int i = 0;i<size-1;i++){
        int temp;
        for(int j = 0;j<size-i-1;j++){
            if(arr[j]>arr[j+1]){
                temp = arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
            }
        }
    }
    return;
}

void SortDsc(int arr[],int size){
    for(int i = 0;i<size-1;i++){
        int temp;
        for(int j = 0;j<size-i-1;j++){
            if(arr[j]<arr[j+1]){
                temp = arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
            }
        }
    }
    return;
}

int main(){
    int status;
    int nums[] = {3,5,4,2,1};
    int size = sizeof(nums)/sizeof(nums[0]);
    pid_t pid;

    printf("\nOriginal array: \n");
    for(int i = 0;i<size;i++){
        printf("%d ",nums[i]);
    }

    fflush(stdout);
    pid = fork();

    if(pid==0){
        //child process
        //sleep(2); //for making it orphan
        printf("\nThis is Child Process.\nChild Process ID:%d\nParent Process ID:%d",getpid(),getppid());
        printf("\n----Child Process Ascending Sort-----\n");
        SortAsc(nums,size);
        printf("Asc: ");
        for(int i = 0;i<size;i++){
            printf("%d ",nums[i]);
        }
        exit(0);//for terminating child
    }

    else if(pid>0){
        //Parent process
        //sleep(2); //For zombie
        printf("\n");
        system("ps -l");//detect zombie
        printf("\nThis is parent process.\nParent process ID:%d\nChild Process ID:%d",getpid(),pid);
        printf("\n----Parent Process Descending Sort----\n");
        SortDsc(nums,size);
        printf("Dsc: ");
        for(int i = 0;i<size;i++){
            printf("%d ",nums[i]);
        }
        wait(&status);//reap zombie process
        //exit(0); //for orphan child terminate this.
        system("ps -l");//detect zombie cleared.
    }
    return 0;
}