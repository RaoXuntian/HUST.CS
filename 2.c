#include<stdio.h>
#include<stdlib.h>

int main(int argc, char const *argv[]){
	char buf[5000];
	int flag = 1;
	int count=1;
	FILE *fp;

	if ((fp=fopen("abc.c","r")) == NULL){
		printf("no exists!\n");
		exit(0);
	}
	for (int i = 0; i < 5000; ++i){
		buf[i] = fgetc(fp);
		if (buf[i]==EOF){
			break;
		}
	}

	printf("%d  ", count++);
	for (int i = 0; buf[i] != EOF; ++i){
		if (flag == 1){
			printf("%c", buf[i]);
		}
		else if(flag!=1 && buf[i]=='\n'){
			printf("%c", buf[i]);
		}

		if(buf[i]=='\n'){//输出行号
			printf("%d  ", count++);
		}

		if (buf[i+1]=='/' && buf[i+2]=='/'){//消除行注释
			flag = 0;
		}
		if(buf[i+1]=='\n' && flag == 0){
			flag = 1;
		}

		if(buf[i+1]=='/' && buf[i+2]=='*'){//消除快注释
			flag = -1;
		}
		if((buf[i-2]=='*' && buf[i-1]=='/') && flag==-1){
			flag = 1;
		}
	}

	printf("\n");
	return 0;
}