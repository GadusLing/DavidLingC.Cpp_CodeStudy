#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

////����ָ��
//int main()
//{
//	int a = 10;
//	int* pa = &a;//pa��һ��ָ�������һ��ָ�����
//	int** ppa =  &pa;//ppa��һ������ָ�����
//
//
//
//	//*pa = 20;
//	//printf("%d\n", a);
//
//	return 0;
//}


//ָ������
//���ָ����������ָ������

//int main()
//{
//	//int a = 10;
//	//int b = 20;
//	//int c = 30;
//
//	//int arr[10];
//
//	//int* pa = &a;
//	//int* pb = &b;
//	//int* pc = &c;
//
//	////parr���Ǵ��ָ�������
//	////ָ������
//	//int* parr[10] = { &a,&b,&c };
//
//	//for (int i = 0; i < 3; i++)
//	//{
//	//	printf("%d ", *(parr[i]));
//	//}
//
//	//int arr[3][4] = { 1,2,3,4,2,3,4,5,3,4,5,6 };
//	////1 2 3 4 
//	////2 3 4 5 
//	////3 4 5 6
//	//int i = 0;
//	//int j = 0;
//	//for (i = 0; i < 3; i++)
//	//{
//	//	for (j = 0; j < 4; j++)
//	//	{
//	//		printf("%d ", arr[i][j]);
//	//	}
//	//	printf("\n");
//	//}
//
//	int arr1[4] = { 1,2,3,4 };
//	int arr2[4] = { 2,3,4,5 };
//	int arr3[4] = { 3,4,5,6 };
//	
//	int* parr[3] = { arr1, arr2, arr3 };
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 4; j++)
//		{
//			printf("%d ", parr[i][j]);
//		}
//		printf("\n");
//	}
//
//	return 0;
//}


//��
//struct peo
//{
//	char name[20];
//	char tele[12];
//	char sex[5];
//	int high;
//};
//struct Peo
//{
//	char name[20];
//	char tele[12];
//	char sex[5];
//	int high;
//}p1, p2;//p1��p2������ȫ�ֵĽṹ�����,����ȫ�ֱ���
//
//struct Peo p3, p4;
//
//struct St
//{
//	struct Peo p;
//	int num;
//	float f;
//};
//
//void print2(struct Peo* sp)
//{
//	printf("%s %s %s %d\n", sp->name, sp->tele, sp->sex, sp->high);//�ṹ��ָ��->��Ա����
//}
//
//void print1(struct Peo p)
//{
//	printf("%s %s %s %d\n", p.name, p.tele, p.sex, p.high);//�ṹ�����.��Ա����
//}
//
//int main()
//{
//	struct Peo p1 = { "����","15601526589","��",181 };//�ṹ������Ĵ���
//	struct St s = { {"����","15596668888","Ů",166},100,3.14f };
//
//	printf("%s %s %s %d\n", p1.name, p1.tele, p1.sex, p1.high);//�ṹ�����.��Ա����
//	printf("%s %s %s %d %d %f\n", s.p.name, s.p.tele, s.p.sex, s.p.high, s.num, s.f);
//
//	print1(p1);
//	print2(&p1);
//
//	return 0;
//}

//struct Peo
//{
//	char name[20];
//	char tele[12];
//	char sex[5];
//	int high;
//};
//
//struct St
//{
//	struct Peo p;
//	int num;
//	float f;
//};


//int main()
//{
//	int a, b, c;
//
//	a = 5;
//	c = ++a;//c = 6, a = 6
//	b = ++c, c++, ++a, a++;// b = 7, a = 8, c = 8
//	b += a++ + c;//b = 23, a = 9, c = 8
//	printf("a = %d b = %d c = %d\n:", a, b, c);
//		
//	return 0;
//}


//int count_num_of_1(unsigned int n)
//{
//	int count = 0;
//	while (n)
//	{
//		if ((n % 2) == 1)
//		{
//			count++;
//		}
//		n /= 2;
//	}
//	return count;
//}


//int count_num_of_1(unsigned int n)
//{
//	int count = 0;
//	for (int i = 0; i < 32; i++)
//	{
//		if (((n >> i) & 1 == 1))
//		{
//			count++;
//		}
//	}
//	return count;
//}

//int count_num_of_1(unsigned int n)
//{
//	int count = 0;
//	while (n)
//	{
//		n = n & (n - 1);
//		count++;
//	}
//	return count;
//}
//
////
////���Ҫ�ж�һ�����ǲ���2��n�η�
////
////
////2^1
////10
////2^2
////100
////2^3
////1000
////if ((n & (n - 1)) == 0)
////{
////
////}
//
//
//int main()
//{
//	int num = 0;
//	scanf("%d", &num);
//	int n = count_num_of_1(num);
//	printf("%d\n", n);
//
//	return 0;
//}


//����int(32λ)����m��n�Ķ����Ʊ���У��ж��ٸ�λ(bit)��ͬ ?

//int count_diff_bit(int m, int n)
//{
//	int i = 0;
//	int count = 0;
//	for (i = 0; i < 32; i++)
//	{
//		if (((m >> i) & 1) != ((n >> i) & 1))
//		{
//			count++;
//		}
//	}
//	return count;
//}

//int count_diff_bit(int m, int n)
//{
//	int count = 0;
//	//^��������
//	//��ͬΪ0������Ϊ1
//	int ret = m ^ n;
//	//ͳ��һ��ret�ж�����λ�м���1
//	while (ret)
//	{
//		ret = ret & (ret - 1);//n = n & (n - 1)
//		count++;
//	}
//
//	return count;
//}
//
//
//int main()
//{
//	int m = 0;
//	int n = 0;
//	scanf("%d %d", &m, &n);
//	int ret = count_diff_bit(m, n);
//	printf("%d\n", ret);
//
//	return 0;
//}

//��ȡһ���������������������е�ż��λ������λ���ֱ��ӡ������������

//10
//00000000000000000000000000001010
//

//int main()
//{
//	//��ȡ����λ����
//	int num = 0;
//	scanf("%d", &num);
//	for (int i = 30; i >= 0; i -= 2)
//	{
//		printf("%d ", (num >> i) & 1);
//	}
//	printf("\n");
//	//��ȡż��λ����
//	for (int i = 31; i >= 1; i -= 2)
//	{
//		printf("%d ", (num >> i) & 1);
//	}
//	return 0;
//}



//#include <stdio.h>
////ȫ�ֱ�������̬�������Ƿ��ھ�̬��
////ȫ�ֱ�������̬��������ʼ����ʱ��Ĭ�ϻᱻ��ʼ��Ϊ0
////�ֲ��������Ƿ���ջ���ģ�����ʼ����Ĭ��ֵ�����ֵ
//
//int i;//0
//int main()
//{
//	i--;//-1
//	//sizeof������������㷵�صĽ����size_t���͵ģ����޷������͵�
//	//��һ���з������κ��޷������αȽϵ�ʱ��-1������ת��Ϊ�޷������������ڱȽϣ���ʱ-1�ᱻ�����һ���޴��������
//	//10000000000000000000000000000001 Դ
//	//11111111111111111111111111111110 ��
//	//11111111111111111111111111111111 ��  //�ڴ������Ĳ��룬�����������4294967295 42��
//	//
//
//	if (i > sizeof(i))//-1 > 4??
//	{
//		printf(">\n");
//	}
//	else
//	{
//		printf("<\n");
//	}return 0;
//}

#include <stdio.h>

int main()
{
    int n = 0;
    while (scanf("%d", &n) == 1)
    {
        int i = 0;
        int j = 0;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (i == j)
                {
                    printf("*");
                }
                else if (i + j == n - 1)
                {
                    printf("*");
                }
                else
                    printf(" ");
            }
            printf("\n");
        }
    }

    return 0;
}





























