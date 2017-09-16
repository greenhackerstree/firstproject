#include<stdio.h>
#include<string.h>
int main(int argc, char const *argv[])
{
 FILE *fp;
 char key[20][20],string[20],path[50];
 int count=0,n=0,i;
 printf("Enter the path of file");
 scanf("%s",path);
 printf("enter the no.of strings you want to search for");
 scanf("%d",&n);
 printf("Enter the set of strings(each in a new line)that you want to find frequencies of");
 for(i=0;i<n;i++)
  scanf("%s",key[i]);
 for(i=0;i<n;i++){
  count=0;
  fp=fopen(path,"r");
  while(fscanf(fp,"%s",string)==1){
   if(strcmp(key[i],string)==0) count++;
  }
  fclose(fp);
  fp=fopen(path,"a");
  fprintf(fp,"\n occurances of %s=%d",key[i],count);
  fclose(fp);
 }
 return 0;
