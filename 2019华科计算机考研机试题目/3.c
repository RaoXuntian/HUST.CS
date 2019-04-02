#include<stdio.h>
#include<math.h>
int tra(char ch){
	int a = ch;
	if(a>='a' && a<='x'){
		return a+2;
	}
	else if(a>='A' && a<='X'){
		return a+2;
	}
	else if(a=='y'){
		return 'a';
	}
	else if(a=='z'){
		return 'b';
	}
	else if(a=='Y'){
		return 'A';
	}
	else if(a=='Z'){
		return 'B';
	}
	else
		return a;
}

void xiaoyan(int num){
	int buf[8];
	int count=0;
	int sum = 0;
	for(int i=0;num!=0;i++){
		buf[i] = num % 2;
		num = num / 2;
		if (buf[i]==1){
			count++;
		}
	}
	if(count%2==0){
		buf[7]=1;
	}
	else{
		buf[7]=0;
	}

	for (int i = 0; i < 8; ++i)
	{
		printf("%d", buf[7-i]);
		sum = sum + buf[7-i]*pow(2,7-i);
	}

	printf("  %d\n", sum);
}

int main(int argc, char const *argv[])
{
	char str[50];

	scanf("%s",str);
	for (int i = 0; str[i] != '\0'; ++i)
	{
		printf("%c", tra(str[i]));
	}
	printf("\n");

	for (int i = 0; str[i] != '\0'; ++i)
	{
		printf("%c  ", tra(str[i]));
		xiaoyan(tra(str[i]));
	}
	return 0;
}