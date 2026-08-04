#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

void main(){
   int p1,p4,p3,p5;
   p1=fork();
   if(p1==0){
      printf("p2\n  child :%d \t parent :%d\n",getpid(),getppid());
   }
   else{
      p3=fork();
      if(p3==0){
	 p4=fork();
	 if(p4==0){
	     printf("p4\n  child :%d \t parent :%d\n",getpid(),getppid());
	 }
	 else{
	    p5=fork();
	    if(p5==0){
	        printf("p5\n  child :%d \t parent :%d\n",getpid(),getppid());
	    }
	    else{
	        wait(NULL);
	        wait(NULL);
	        printf("p3\n  child :%d \t parent :%d\n",getpid(),getppid());
	    }
	 }
      }
      else{
	 wait(NULL);
	 wait(NULL);
	 printf("p1\n  child :%d \t parent :%d\n",getpid(),getppid());
      }
   }
}

