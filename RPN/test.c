#define _CRT_SECURE_NO_WARNINGS 1

#include "RPN.h"

int main()
{
	char *str = "12*((5-3)+6)-20/10";
	char arr[100] = { 0 };
	printf("ԭ���ʽΪ��%s\n", str);

	Infix_to_Suffix(str,arr);
	Count_Suffix(arr);

	printf("�������ǣ�%d\n", Count_Suffix(arr));

	system("pause");
	return 0;
}