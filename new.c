#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define KEYMAX 32
typedef struct keyword{
	char word[10];
	int occur;
}keyword;
keyword key[32] = {"auto", 0, "break", 0, "case", 0, "char", 0, "const", 0, "continue", 0, "default", 0, "do", 0, "double", 0, "else", 0, "enum", 0, "extern", 0, "float", 0, "for", 0, "goto", 0, "if", 0, "int", 0, "long", 0, "register", 0, "return", 0, "short", 0, "signed", 0, "sizeof", 0, "static", 0, "struct", 0, "switch", 0, "typedef", 0, "union", 0, "unsigned", 0, "void", 0, "volatile", 0, "while", 0,};
int binarysearch(char *);
int main(int argc,char* argv[])
{
	FILE *fp;
	int i = 0, j = 0, pos;
	char unit[20],c;
	char* string;
	long int size;
	fp=fopen(argv[1],"r");
	if(fp==NULL){
		printf("Error opening file!\n");
		exit(0);
	}
	fseek(fp,0,SEEK_END);
	size=ftell(fp);
	rewind(fp);
	string=calloc(size+1,1);
	fread(string,1,size,fp);
	for(i=0;i<strlen(string);i++){
		if(string[i]=='"'){
			i++;
			do{
				while(string[i]!='"')
					i++;
			}while(string[i++-1]=='\\');
		}
		if(string[i]=='/' && string[i+1]=='*'){
			i=i+3;
			while(string[i]!='/' && string[i-1]!='*') i++;
		}
		if(string[i]=='/' && string[i+1]=='/'){
			while(string[i]!='\n')	i++;
		}
		while(i<strlen(string)&&string[i]!=' '&&isalpha(string[i])){
			unit[j++]=string[i++];
		}
		if(j!=0){
			unit[j]='\0';
			pos=binarysearch(unit);
			j=0;
			if(pos!=-1){
				key[pos].occur++;
			}
		}
	}
	printf("\tKeyword\tCount\n");
	for(i=0;i<KEYMAX;i++){
		if(key[i].occur){
			printf(" %s\t %d\n", key[i].word, key[i].occur);
		}
	}
	return 0;
}
int binarysearch(char *word)
{
	int low,high,mid;
	low=0;
	high=KEYMAX-1;
	while(low<=high){ 
		mid=(low+high)/2;
		if(strcmp(word,key[mid].word)<0)
			high=mid-1; 
		else if (strcmp(word, key[mid].word) > 0)
			low=mid+1;
		else
			return mid;
	}
	return -1;
}
