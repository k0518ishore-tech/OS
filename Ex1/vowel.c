#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<ctype.h>
#include<sys/wait.h>
int main(){
   int p2,p3,i;
   char str[100];
   printf("Enter the string:");
   fgets(str,sizeof(str),stdin);
   p2=fork();
   if(p2==0){
      int vow=0;
      for( i=0;str[i]!='\0';i++){
	 char ch=tolower(str[i]);
	 if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'){
	    vow++;
	 }
      }
      printf("No of vowels:%d\n",vow);
   }
   else{
      p3=fork();
      if(p3==0){
	 int special=0;
	 for( i=0;str[i]!='\0';i++){
	    if(!isalnum(str[i])&&!isspace(str[i])){
	       special++;
	    }
	 }
	 printf("No of special character:%d\n",special);
      }
      else{
	 wait(NULL);
	 wait(NULL);
      }
   }
   return 0;
}
