#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
int findgcd(int a,int b){
   while(b!=0){
      int temp=b;
      b=a%b;
      a=temp;
   }
   return a;
}
int main(){
   int fd[2];
   int a,b,lcm;
   pipe(fd);
   int p2;
   p2=fork();
   if(p2==0){
      close(fd[0]);
      printf("Enter two numbers:");
      scanf("%d%d",&a,&b);
      printf("P2 PROCESS WRITE NUMBERS IN PIPE\n");
      write(fd[1],&a,sizeof(int));
      write(fd[1],&b,sizeof(int));
      close(fd[1]);
   }
   else{
      wait(NULL);
      close(fd[1]);
      printf("P1 PROCESS READ NUMBERS IN PIPE\n");
      int c,d;
      read(fd[0],&c,sizeof(int));
      read(fd[0],&d,sizeof(int));
      close(fd[0]);
      lcm=(c*d)/findgcd(c,d);
      printf("LCM:%d\n",lcm);
   }
   return 0;
}

