//翻转字符串
#include<stdio.h>
#include<stdlib.h>
void Reverse(char *begin, char *end)
{
	if (begin == NULL || end == NULL)
	{
		return;
	}
	char tmp;
	while (begin < end)
	{
		 tmp = *begin;
		*begin = *end;
		*end = tmp;
		begin++;
		end--;
    }
}
char *ReverseSentence(char *p)
{
	if (p == NULL)
	{
		return NULL;
	}
	char * begin = p;
	//使end指向字符串最后一个字符
	char *end = p;
	while (*end != '\0')
	{
		end++;
	}
	end--;
	//翻转整个字符串
	Reverse(begin, end);
	begin = end = p;
	while (*begin != '\0')
	{
		if (*begin == ' ')
		{
			begin++;
			end++;
		}
		else if (*end == ' ' || *end == '\0')
		{
			//翻转单个单词
			Reverse(begin, --end);
			begin = ++end ;
		}
		else
		{
			end++;
		}
	}
    return p;
}
int main()
{
	char arr1[20] = "aduo duo";
	char *ret=ReverseSentence(arr1);
	printf("%s", ret);
	system("pause");
	return 0;
}
//左旋转字符串

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
void Reverse(char *begin, char *end)
{
	if (begin == NULL || end == NULL)
	{
		return;
	}
	char tmp;
	while (begin < end)
	{
		tmp = *begin;
		*begin = *end;
		*end = tmp;
		begin++;
		end--;
	}
}

void LeftRotateString(char *p,int  n)
{
	int len = strlen(p);
	assert(p);
	Reverse(p, p + n - 1);    //逆序前半部分
	Reverse(p + n, p + len - 1);   //逆序后半部分
	Reverse(p, p + len - 1);	 //整体逆序

}
int main()
{
	
	char arr[] = "abcdefghi";
	LeftRotateString(arr, 2);
	printf("%s\n", arr);
	system("pause");
	return 0;
}

//左旋转字符串

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
void Reverse(char *begin, char *end)
{
	if (begin == NULL || end == NULL)
	{
		return;
	}
	char tmp;
	while (begin < end)
	{
		tmp = *begin;
		*begin = *end;
		*end = tmp;
		begin++;
		end--;
	}
}

void LeftRotateString(char *p, int  n)
{
	int len = strlen(p);
	assert(p);
	Reverse(p, p + len - 1);	 //整体逆序
	Reverse(p, p + n - 1);    //逆序前半部分
	Reverse(p + n, p + len - 1);   //逆序后半部分

}
int main()
{

	char arr[] = "abcdefghi";
	LeftRotateString(arr, 2);
	printf("%s\n", arr);
	system("pause");
	return 0;
}