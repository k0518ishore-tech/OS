#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/wait.h>
int main(){
   int fd[2];
   int pid;
   char write_msg[]="Hello from parent process";
   char read_msg[100];
   if(pipe(fd)==-1){
      perror("pipe creation failed:");
      return 1;
   }
   pid=fork();
   if(pid<0){
      perror("fork failed");
      return 1;
   }
   if(pid==0){
      close(fd[1]);
      int bytes_read=read(fd[0],read_msg,sizeof(read_msg)-1);
      if(bytes_read>0){
	 read_msg[bytes_read]='\0';
	 printf("child received:%s\n",read_msg);
      }
      close(fd[0]);
   }
   else{
      close(fd[0]);
      printf("parent sending:%s\n",write_msg);
      write(fd[1],write_msg,strlen(write_msg)+1);
      close(fd[1]);
      wait(NULL);
   }
   return 0;
}
