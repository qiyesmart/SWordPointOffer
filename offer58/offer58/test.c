//��ת�ַ���
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
	//ʹendָ���ַ������һ���ַ�
	char *end = p;
	while (*end != '\0')
	{
		end++;
	}
	end--;
	//��ת�����ַ���
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
			//��ת��������
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
//����ת�ַ���

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
	Reverse(p, p + n - 1);    //����ǰ�벿��
	Reverse(p + n, p + len - 1);   //�����벿��
	Reverse(p, p + len - 1);	 //��������

}
int main()
{
	
	char arr[] = "abcdefghi";
	LeftRotateString(arr, 2);
	printf("%s\n", arr);
	system("pause");
	return 0;
}

//����ת�ַ���

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
	Reverse(p, p + len - 1);	 //��������
	Reverse(p, p + n - 1);    //����ǰ�벿��
	Reverse(p + n, p + len - 1);   //�����벿��

}
int main()
{

	char arr[] = "abcdefghi";
	LeftRotateString(arr, 2);
	printf("%s\n", arr);
	system("pause");
	return 0;
}