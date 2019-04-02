#include<stdio.h>
#include<math.h>
int ss(int n){
	int flag = 1;
	for (int i = 2; i < n; ++i){
		if (n%i==0){
			flag = 0;
			break;
		}
	}
	if(n == 2){
		flag = 1;
	}
	return flag;
}
/*
输入第九个梅森素数（19位）M(61)会出bug
*/
int main(int argc, char const *argv[]){	//start!!!
	long long num;
	int a=2;
	long long b;
	scanf("%lld",&num);
	b = pow(2,a)-1;
	for(a=2;b<=num;a++){
		b = pow(2,a)-1;
		if(ss(a) && ss(b)){
			printf("M(%d) = %lld\n",a,b);
		}
	}
	return 0;
}