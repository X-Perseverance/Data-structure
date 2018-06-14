#define _CRT_SECURE_NO_WARNINGS 1

#include "RPN.h"

//�ַ�ջ��ʼ��
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

//����
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

//��ջ
void CStackPush(CStack* s, char x)
{
	assert(s);
	CCheckCapacity(s);
	s->_array[s->_size] = x;
	s->_size++;
}

//��ջ
void CStackPop(CStack* s)
{
	assert(s);
	if (s->_size == 0)
	{
		printf("��ջΪ��\n");
	}
	else
	{
		s->_size--;
	}
}

//��ȡջ��Ԫ��
char CStackTop(CStack* s)
{
	assert(s);
	if (s->_size == 0)
	{
		printf("��ջΪ��\n");
		return 0;
	}
	return s->_array[(s->_size) - 1];
}

//�п�
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


//����ջ��ʼ��
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

//����
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

//��ջ
void IStackPush(IStack* s, int x)
{
	assert(s);
	ICheckCapacity(s);
	s->_array[s->_size] = x;
	s->_size++;
}

//��ջ
void IStackPop(IStack* s)
{
	assert(s);
	if (s->_size == 0)
	{
		printf("��ջΪ��\n");
	}
	else
	{
		s->_size--;
	}
}

//��ȡջ��Ԫ��
int IStackTop(IStack* s)
{
	assert(s);
	if (s->_size == 0)
	{
		printf("��ջΪ��\n");
		return 0;
	}
	return s->_array[(s->_size) - 1];
}

//�������ջ���⣺
//top�ǵ�ǰջ���������newnode��Ҫ�����µ������
//��newnode�����ȼ�����topʱ��i=1��newnodeֱ����ջ
//��newnode�����ȼ����ڻ����topʱ��i=0��top�ȳ�ջ��newnode����ջ
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

//��׺���ʽת��׺���ʽ
void Infix_to_Suffix(char* p, char *arr)
{
	CStack s;
	CStackInit(&s);
	printf("�沨�����ʽΪ��");

	while (*p)
	{
		//һ����*pΪ����
		if (*p >= '0' && *p <= '9')
		{
			int res = 0;
			while (*p >= '0' && *p <= '9')
			{
				*(arr++) = *p; // ���浽arr��ȥ
				res = res * 10 + *p - '0'; // �����λ����
				p++;
			}
			printf("%d ", res);
			*(arr++) = ' '; // �����
		}

		//������*pΪ�����
		if (*p == '+' || *p == '-' || *p == '*' || *p == '/')
		{
			if (CStackEmpty(&s)) //ջΪ�գ������ֱ����ջ
			{
				CStackPush(&s, *p);
			}
			else // ջ��Ϊ�գ��ж�����������ȼ�
			{
				char top = CStackTop(&s);
				if (Precede(top, *p)) // ��Ҫ��ջ������������ȼ����ڴ�ʱջ������������ȼ���ֱ����ջ
				{
					CStackPush(&s, *p);
				}
				else // ��Ҫ��ջ������������ȼ������ڴ�ʱջ������������ȼ�
				{
					while (Precede(top, *p) == 0) // ��1��ֱ���ҵ���ջ����������ȼ��ߵ�λ��ʱ��ֱ����ջ
					{
						printf("%c ", top);
						*(arr++) = top; // ���浽arr��ȥ
						*(arr++) = ' '; // �����
						CStackPop(&s); // ��ջ
						if (!CStackEmpty(&s))
						{
							top = CStackTop(&s);
						}
						else
						{
							break; // ��2��ջΪ��ʱ������ѭ����ֱ����ջ
						}
					}
					CStackPush(&s, *p);
				}
			}
			p++;
		}

		//������*pΪ����
		if (*p == '(') // ������ֱ����ջ
		{
			CStackPush(&s, *p);
			p++;
		}
		if (*p == ')') // ������ʱ����Ϊ����������ȼ��ߣ�Ҫ�ȳ�ջ
		{
			if (!CStackEmpty(&s))
			{
				char top = CStackTop(&s);
				while (top != '(') // ���γ�ջ��ֱ������������
				{
					printf("%c ", top);
					*(arr++) = top; // ���浽arr��ȥ
					*(arr++) = ' '; // �����
					CStackPop(&s);
					top = CStackTop(&s);
				}
				CStackPop(&s); // �����ų�ջ
			}
			p++;
		}
	}

	while (!CStackEmpty(&s)) // ջ��Ϊ��ʱ�����γ�ջ
	{
		printf("%c ", CStackTop(&s));
		*(arr++) = CStackTop(&s); // ���浽arr��ȥ
		*(arr++) = ' '; // �����
		CStackPop(&s);
	}
	printf("\n");
	*(arr++) = '#'; // #��Ϊ���ʽ������
}

//����
int Count_Suffix(char *arr)
{
	IStack c; // ����ջ
	IStackInit(&c);

	while (*arr != '#') // ֱ��arr��β
	{
		// һ����*arrΪ�����ַ�
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

		// ������*arrΪ�����
		else if (*arr == '+' || *arr == '-' || *arr == '*' || *arr == '/')
		{
			int right = IStackTop(&c); // ȡ��ֵ
			IStackPop(&c);
			int left = IStackTop(&c); // ȡ��ֵ
			IStackPop(&c);
			if (*arr == '+')
			{
				IStackPush(&c, left + right); // �����ֵ������ջ
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

		// ������*arrΪ�ո�
		else
		{
			arr++;
		}
	}
	return IStackTop(&c); // ��ʱջ��ֵ��Ϊ���յĽ��
}