#define _CRT_SECURE_NO_WARNINGS 1

#include "RPN.h"

//字符栈初始化
void CStackInit(CStack* s)
{
	assert(s);
	s->_size = 0;
	s->_capacity = Initsize;
	s->_array = (char*)malloc(Initsize*sizeof(char));
	if (s->_array == NULL)
	{
		perror("StackInit");
		return;
	}
	memset(s->_array, 0, s->_capacity * sizeof(char));
}

//扩容
void CCheckCapacity(CStack* s)
{
	assert(s);
	if (s->_size >= s->_capacity)
	{
		char* ptr = (char*)realloc(s->_array, (s->_capacity + Increment)*sizeof(char));
		if (ptr == NULL)
		{
			perror("CheckCapacity");
		}
		else
		{
			s->_array = ptr;
			s->_capacity += Increment;
		}
	}
}

//入栈
void CStackPush(CStack* s, char x)
{
	assert(s);
	CCheckCapacity(s);
	s->_array[s->_size] = x;
	s->_size++;
}

//出栈
void CStackPop(CStack* s)
{
	assert(s);
	if (s->_size == 0)
	{
		printf("该栈为空\n");
	}
	else
	{
		s->_size--;
	}
}

//获取栈顶元素
char CStackTop(CStack* s)
{
	assert(s);
	if (s->_size == 0)
	{
		printf("该栈为空\n");
		return 0;
	}
	return s->_array[(s->_size) - 1];
}

//判空
int CStackEmpty(CStack* s)
{
	assert(s);
	if (s->_size)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}


//数字栈初始化
void IStackInit(IStack* s)
{
	assert(s);
	s->_size = 0;
	s->_capacity = Initsize;
	s->_array = (int*)malloc(Initsize*sizeof(int));
	if (s->_array == NULL)
	{
		perror("StackInit");
		return;
	}
	memset(s->_array, 0, s->_capacity * sizeof(int));
}

//扩容
void ICheckCapacity(IStack* s)
{
	assert(s);
	if (s->_size >= s->_capacity)
	{
		int* ptr = (int*)realloc(s->_array, (s->_capacity + Increment)*sizeof(int));
		if (ptr == NULL)
		{
			perror("CheckCapacity");
		}
		else
		{
			s->_array = ptr;
			s->_capacity += Increment;
		}
	}
}

//入栈
void IStackPush(IStack* s, int x)
{
	assert(s);
	ICheckCapacity(s);
	s->_array[s->_size] = x;
	s->_size++;
}

//出栈
void IStackPop(IStack* s)
{
	assert(s);
	if (s->_size == 0)
	{
		printf("该栈为空\n");
	}
	else
	{
		s->_size--;
	}
}

//获取栈顶元素
int IStackTop(IStack* s)
{
	assert(s);
	if (s->_size == 0)
	{
		printf("该栈为空\n");
		return 0;
	}
	return s->_array[(s->_size) - 1];
}

//运算符入栈问题：
//top是当前栈顶运算符，newnode是要插入新的运算符
//当newnode的优先级高于top时，i=1，newnode直接入栈
//当newnode的优先级低于或等于top时，i=0，top先出栈，newnode再入栈
int Precede(char top, char newnode)
{
	int i = 0;
	if ((top == '+' || top == '-') && (newnode == '*' || newnode == '/'))
	{
		i = 1;
	}
	if (top == '(' || top == ')')
	{
		i = 1;
	}
	return i;
}

//中缀表达式转后缀表达式
void Infix_to_Suffix(char* p, char *arr)
{
	CStack s;
	CStackInit(&s);
	printf("逆波兰表达式为：");

	while (*p)
	{
		//一、当*p为数字
		if (*p >= '0' && *p <= '9')
		{
			int res = 0;
			while (*p >= '0' && *p <= '9')
			{
				*(arr++) = *p; // 保存到arr中去
				res = res * 10 + *p - '0'; // 计算多位数字
				p++;
			}
			printf("%d ", res);
			*(arr++) = ' '; // 间隔符
		}

		//二、当*p为运算符
		if (*p == '+' || *p == '-' || *p == '*' || *p == '/')
		{
			if (CStackEmpty(&s)) //栈为空，运算符直接入栈
			{
				CStackPush(&s, *p);
			}
			else // 栈不为空，判断运算符的优先级
			{
				char top = CStackTop(&s);
				if (Precede(top, *p)) // 当要入栈的运算符的优先级高于此时栈顶运算符的优先级，直接入栈
				{
					CStackPush(&s, *p);
				}
				else // 当要入栈的运算符的优先级不高于此时栈顶运算符的优先级
				{
					while (Precede(top, *p) == 0) // （1）直到找到比栈顶运算符优先级高的位置时，直接入栈
					{
						printf("%c ", top);
						*(arr++) = top; // 保存到arr中去
						*(arr++) = ' '; // 间隔符
						CStackPop(&s); // 出栈
						if (!CStackEmpty(&s))
						{
							top = CStackTop(&s);
						}
						else
						{
							break; // （2）栈为空时，跳出循环，直接入栈
						}
					}
					CStackPush(&s, *p);
				}
			}
			p++;
		}

		//三、当*p为括号
		if (*p == '(') // 左括号直接入栈
		{
			CStackPush(&s, *p);
			p++;
		}
		if (*p == ')') // 右括号时，因为括号里的优先级高，要先出栈
		{
			if (!CStackEmpty(&s))
			{
				char top = CStackTop(&s);
				while (top != '(') // 依次出栈，直到遇到左括号
				{
					printf("%c ", top);
					*(arr++) = top; // 保存到arr中去
					*(arr++) = ' '; // 间隔符
					CStackPop(&s);
					top = CStackTop(&s);
				}
				CStackPop(&s); // 左括号出栈
			}
			p++;
		}
	}

	while (!CStackEmpty(&s)) // 栈不为空时，依次出栈
	{
		printf("%c ", CStackTop(&s));
		*(arr++) = CStackTop(&s); // 保存到arr中去
		*(arr++) = ' '; // 间隔符
		CStackPop(&s);
	}
	printf("\n");
	*(arr++) = '#'; // #作为表达式结束符
}

//计算
int Count_Suffix(char *arr)
{
	IStack c; // 数字栈
	IStackInit(&c);

	while (*arr != '#') // 直到arr到尾
	{
		// 一、当*arr为数字字符
		if (*arr >= '0' && *arr <= '9')
		{
			int num = 0;
			while (*arr >= '0' && *arr <= '9')
			{
				num = num * 10 + *arr - '0';
				arr++;
			}
			IStackPush(&c, num);
		}

		// 二、当*arr为运算符
		else if (*arr == '+' || *arr == '-' || *arr == '*' || *arr == '/')
		{
			int right = IStackTop(&c); // 取右值
			IStackPop(&c);
			int left = IStackTop(&c); // 取左值
			IStackPop(&c);
			if (*arr == '+')
			{
				IStackPush(&c, left + right); // 计算的值重新入栈
			}
			else if (*arr == '-')
			{
				IStackPush(&c, left - right);
			}
			else if (*arr == '*')
			{
				IStackPush(&c, left * right);
			}
			else if (*arr == '/')
			{
				IStackPush(&c, left / right);
			}
			arr++;
		}

		// 三、当*arr为空格
		else
		{
			arr++;
		}
	}
	return IStackTop(&c); // 此时栈顶值即为最终的结果
}