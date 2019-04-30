#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
bool isEqual2(char *str, char *pattern)
{
	//字符串匹配到尾部，返回true
	if (*str == '\0' && *pattern == '\0')
		return true;
	//pattern已经到最后，str还没有结束，返回false
	if (*str != '\0' && *pattern == '\0')
		return false;
	//pattern下一个字符为'*'
	if (*(pattern + 1) == '*')
	{
		//当前字符相等，则str向后移动一位或者pattern移动2位
		if (*pattern == *str || (*pattern == '.' && *str != '\0'))
			return isEqual2(str + 1, pattern + 2)
			|| isEqual2(str + 1, pattern)
			|| isEqual2(str, pattern + 2);
		//当前字符不相等，则pattern向后移动2位
		else
			return isEqual2(str, pattern + 2);
	}
	//pattern下一个字符不是'.'
	//如果当前字符相等，则str和pattern都向后移动一位继续比较;否则返回false
	if (*str == *pattern || (*pattern == '.' && *str != '\0'))
		return isEqual2(str + 1, pattern + 1);
	return false;
}
bool isEqual(char *str, char *pattern)
{
	if (str == NULL || pattern == NULL)
		return false;
	return isEqual2(str, pattern);
}

int main()
{
	char str[] = "aaa";
	char str2[] = "a.a";
	bool s = isEqual(str, str2);
	printf("%d", s);
	system("pause");
	return 0;
}