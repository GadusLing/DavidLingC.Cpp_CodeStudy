#define _CRT_SECURE_NO_WARNINGS

////// test.cpp
////#include<stdio.h>
////int main()
////{
////	printf("hello world\n");
////	return 0;
////}
//
//
//// test.cpp
//// 这⾥的std cout等我们都看不懂，没关系，下⾯我们会依次讲解
//
////#include <iostream> //iostream == input output stream
////using namespace std;//这里涉及到namespace 的 using 的知识
////int main()
////{
////    cout << "hello world\n" << endl;//这里涉及C++输入与输出的知识
////
////    return 0;
////}
//
////#include <iostream>
////int main()
////{
////    std::cout << "hello world\n" << std::endl; //这种写法运用了std库，用了::访问std库中的cout和endl
////
////    return 0;
////}
//
//
//
//#include <stdio.h>                                                             
//#include <stdio.h>
//#include <stdlib.h>
//#include"Stack.h"
//
//namespace ling //命名空间的写法：namespace + 命名空间名 + { }  命名空间本质是新建了一个域，同一个域中名称不能重复，但不同域就不存在这个问题
//{
//    int rand = 10;
//
//    int Add(int left, int right)//命名空间也可以在其中定义函数
//    {
//        return left + right;
//    }
//
//    struct Node//或者结构体 / 类
//    {
//        struct Node* next;
//        int val;
//    };
//}//namespace这里不要加分号;哈
//
////int rand = 10;//rand在stdlib里面本身是作为一个rand函数存在，那如果我用rand再起个名字，包了<stdlib.h>后就会重名报错
////int main()
////{
////    // 编译报错：error C2365 : “rand”:重定义；以前的定义是“函数”
////    printf("%p\n", rand); // 这⾥默认访问的是全局<stdlib.h>中的rand函数指针，不是namespace中的
////
////    printf("%d\n", ling::rand);// 这⾥指定ling命名空间中的rand   ::叫做域作用限定符，用它来访问namespace中的成员
////
////    return 0;
////}
//
//
////2. 命名空间可以嵌套
//namespace bit
//{
//    // 鹏哥
//    namespace pg
//    {
//        int rand = 1;
//        int Add(int left, int right)
//        {
//            return left + right;
//        }
//
//        struct Node
//        {
//            struct Node* next;
//            int val;
//        };
//
//    }
//    // 杭哥
//    namespace hg
//    {
//        int rand = 2;
//        int Add(int left, int right)
//        {
//            return (left + right) * 10;
//        }
//    }
//}
//
//
//int main()
//{
//    //namespace bit //namespace不支持在局部定义哈，只支持在全局定义
//    //{
//    //    int a;
//    //}
//    printf("%d\n", bit::pg::rand);
//    printf("%d\n", bit::hg::rand);
//    printf("%d\n", bit::pg::Add(1, 2));
//    printf("%d\n", bit::hg::Add(1, 2));
//
//    bit::pg::Node node;//namespace封装的是名字，不是类型什么的，所以索引的时候要去索引你取的名字
//
//    bit::ST st2;
//    printf("%d\n", sizeof(st2));
//    bit::STInit(&st2, 10);
//    bit::STPush(&st2, 1);
//    bit::STPush(&st2, 2);
//
//    return 0;
//}

#include "Stack.h"

//using namespace bit;//using展开全部命名空间和头文件展开不是一回事  命名空间展开的本质是影响查找规则 查找时除了局部查找和全局查找，还会到展开的这个namespace bit中去查找
//这种命名空间全部展开的方式很危险，一般不要这样用啊，冲突就很麻烦了


//那么除了::指定使用这种麻烦但是安全的用法 和全展开这种方便但是非常危险的用法，还有一种折中的方式，部分展开
using bit::STPush;//只把命名空间中常用的方法展开出来，减少了一些危险

int main()
{

    bit::ST st2;
    printf("%d\n", sizeof(st2));
    bit::STInit(&st2, 10);
    STPush(&st2, 1);
    STPush(&st2, 2);

    return 0;
}

