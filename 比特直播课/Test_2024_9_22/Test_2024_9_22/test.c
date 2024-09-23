#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


















int main()
{
#if 2==3
	printf("hehe\n");
#endif


	return 0;
}








////#define __DEBUG__
//int main()
//{
//	int arr[10] = { 0 };
//	for (int i = 0; i < 10; i++)
//	{
//		arr[i] = i + 1;
//#ifdef __DEBUG__
//		printf("%d ", arr[i]);
//#endif
//	}
//
//	return 0;
//}





//#define M 100
//
//int main()
//{
//	printf("%d\n", M);
//#undef M
//	//printf("%d\n", M);
//#define M "hehe"
//	printf("%s\n", M);
//
//
//	return 0;
//}






////int int_max(int x, int y)
////{
////	return x > y ? x : y;
////}
////float float_max(float x, float y)
////{
////	return x > y ? x : y;
////}
//
////GENERIC_MAX(int)
////GENERIC_MAX(float)
//
//#define GENERIC_MAX(type)\
//type type##_max(type x, type y)\
//{\
//    return (x > y ? x : y);\
//}
//
//GENERIC_MAX(int)
//GENERIC_MAX(float)
//GENERIC_MAX(double)
//GENERIC_MAX(char)
//
//int main()
//{
//	printf("Max(5, 3) = %d\n", int_max(5, 3));
//	printf("Max(3.14, 2.71) = %f\n", float_max(3.14f, 2.71f));
//
//	return 0;
//}



//#define CAT(x,y) x##y
////Class115
//
//int main()
//{
//	int Class115 = 100;
//	printf("%d\n", CAT(Class, 115));
//	//printf("%d\n", Class115);
//	return 0;
//}





//#define PRINT(V, FORMAT) printf("the value of "#V" is "FORMAT"\n", V)
//
//int main()
//{
//	int a = 5;
//	//the value of a is 3
//	PRINT(a, "%d");
//	//printf("the value of a is %d\n", a);
//
//	int b = 20;
//	PRINT(b, "%d");
//	//printf("the value of b is %d\n", b);
//
//	float f = 3.14f;
//	PRINT(f, "%f");
//	//printf("the value of f is %f\n", f);
//
//	return 0;
//}



//int main()
//{
//
//	printf("helloworld\n");
//	printf("hello""world\n");
// 
//  return 0;
//}






//#define MALLOC(N, TYPE) (TYPE*)malloc(N * sizeof(TYPE))
//
//int main()
//{
//	//int* p = (int*)malloc(10 * sizeof(int));
//
//	int* p2 = MALLOC(10, int);
//	//int* p2 = (int*)malloc(10 * sizeof(int));
//
//	return 0;
//}







//int Max(int x, int y)
//{
//	return x > y ? x : y;
//}
//
//int main()
//{
//	int a = 7, b = 5;
//	int m = Max(a++, b++);
//
//
//	printf("%d\n", m);//7
//	printf("%d\n", a);//8
//	printf("%d\n", b);//6
//
//
//	return 0;
//}





//#define MAX(X,Y) ((X) > (Y) ? (X) : (Y))
//
//int main()
//{
//	int a = 7, b = 5;
//	int m = MAX(a++, b++);
//
//	//((a++) > (b++) ? (a++) : (b++))
//	//   7       5       8 
//
//	printf("%d\n", m);//8
//	printf("%d\n", a);//8 9
//	printf("%d\n", b);//6
//
//
//	return 0;
//}




//#define MAX(X,Y) ((X) > (Y) ? (X) : (Y))
//
//int main()
//{
//	int a = 7, b = 5;
//	int m = MAX(a, b);
//	printf("%d\n", m);
//
//
//	return 0;
//}



//#define DOUBLE(N) ((N)+(N))
//
//int main()
//{
//	int x = 6;
//	int ret = 10 * DOUBLE(x);
//	printf("%d\n", ret);
//
//
//	return 0;
//}





//#define SQUARE(N) (N)*(N)
//
//int main()
//{
//	int x = 5;
//	int ret = SQUARE(x + 1);
//	printf("%d\n", ret);
//
//
//	return 0;
//}






//#define M 100
//
//int main()
//{
//	printf("%d\n", M);
//		
//	return 0;
//}





//#define DEBUG_PRINT printf("file:%s\tline:%d\tdate:%s\ttime:%s\n",\
//                           __FILE__,\
//                           __LINE__,\
//						   __DATE__,\
//						   __TIME__)
//// \在这里表示续航符
//int main()
//{
//	DEBUG_PRINT;
//
//	return 0;
//}





//#define CASE break;case
//
//int main()
//{
//	int n = 0;
//	switch (n)
//	{
//	case 1:
//	CASE 2:
//	CASE 3:
//	CASE 4:
//	}
//
//	return 0;
//}




//int main()
//{
//	int n = 0;
//	switch (n)
//	{
//	case 1:
//		break;
//	case 2:
//		break;
//	case 3:
//		break;
//	case 4:
//		break;
//
//	}
//
//
//	return 0;
//}





//#define M 100
//#define STR "hehe"
//
//int main()
//{
//	int a = M;
//	printf("%d\n", a);
//	printf("%d\n", M);
//	printf("%s\n", STR);
//
//	return 0;
//}





//int main()
//{
//	printf("%s\n", __FILE__);
//	printf("%d\n", __LINE__);
//	printf("%s\n", __DATE__);
//	printf("%s\n", __TIME__);
//	//printf("%d\n", __STDC__);
//
//
//	return 0;
//}