#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/wait.h>
#include<unistd.h>
#include<string.h>

int main(){
    pid_t pid;
    char buffer[200] = {0}, filename[20]={0};
    int fd;
    int pipe1[2],pipe2[2];

    pipe(pipe1);
    pipe(pipe2);

    pid = fork();

    if(pid>0){
        close(pipe1[0]);
        close(pipe2[1]);
        int status;

        printf("Sending filename to child...\n");

        write(pipe1[1],"nikhil.txt",11);
        close(pipe1[1]);

        printf("Waiting for file content from child: \n");
        read(pipe2[0],buffer,sizeof(buffer));
        wait(&status);
        printf("File content:\n%s\n",buffer);
        close(pipe2[0]);

    }
    else{
        close(pipe2[0]);
        close(pipe1[1]);

        read(pipe1[0],filename,sizeof(filename));
        close(pipe1[0]);
        printf("Received filename from parent %s\n", filename);

        fd = open(filename,O_RDONLY);

        printf("Child Reading file content...\n");
        read(fd,buffer,sizeof(buffer));

        printf("Sending file content to parent...\n");
        write(pipe2[1],buffer,sizeof(buffer));
        close(pipe2[1]);

        close(fd);
    }
    return 0;
}