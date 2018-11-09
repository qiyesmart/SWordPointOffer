#define _CRT_SECURE_NO_WARNINGS 1
////判断1-n中出现的1的个数
////暴力求解法
//#include<stdio.h>
//#include<stdlib.h>
//int numberone(int n)
//{
//	int count = 0;
//	while (n!=0)
//	{
//		if (n % 10 == 1)
//		{
//			count++;
//		}
//		n = n / 10;
//	}
//	return count;
//}
//int main()
//{
//	int number = 0;
//	int n = 0;
//	scanf("%d", &n);
//	for (int i = 1; i <=n; i++)
//	{
//		number = number + numberone(i);
//	}
//	printf("%d", number);
//	system("pause");
//	return 0;
//}
//规律求解法
#include<stdio.h>

long long int Count(long long int n){
	//1的个数
	long long int count = 0;
	//当前位
	long long int Factor = 1;
	//低位数字
	long long int LowerNum = 0;
	//当前位数字
	long long int CurrNum = 0;
	//高位数字
	long long int HigherNum = 0;
	if (n <= 0){
		return 0;
	}
	while (n / Factor != 0){
		//低位数字
		LowerNum = n - (n / Factor) * Factor;
		//当前位数字
		CurrNum = (n / Factor) % 10;
		//高位数字
		HigherNum = n / (Factor * 10);
		//如果为0,出现1的次数由高位决定
		if (CurrNum == 0){
			//等于高位数字 * 当前位数
			count += HigherNum * Factor;
		}
		//如果为1,出现1的次数由高位和低位决定
		else if (CurrNum == 1){
			//高位数字 * 当前位数 + 低位数字 + 1
			count += HigherNum * Factor + LowerNum + 1;
		}
		//如果大于1,出现1的次数由高位决定
		else{
			//（高位数字+1）* 当前位数
			count += (HigherNum + 1) * Factor;
		}
		//前移一位
		Factor *= 10;
	}
	return count;
}

int main(){
	  long long int a;
    while(scanf("%lld",&a) != EOF){
        printf("%lld\n",Count(a));
    }
    return 0;

}
