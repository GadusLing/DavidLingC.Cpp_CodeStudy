
#include <iostream>
#include "string.h"

using namespace std;
using namespace LDW;

void TestString()
{
    // 1. 测试构造函数
    LDW::string s1;                // 默认构造
    LDW::string s2("hello");      // C字符串构造
    LDW::string s3(s2);            // 拷贝构造

    cout << "构造测试:" << endl;
    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;
    cout << "s3: " << s3 << endl;

    // 2. 测试赋值运算符
    s1 = s2;
    cout << "赋值运算符测试: " << s1 << endl;

    // 3. 测试 += 追加字符和字符串
    s1 += '!';
    s1 += " world";
    cout << "+= 测试: " << s1 << endl;

    // 4. 测试 push_back
    s1.push_back('?');
    cout << "push_back 测试: " << s1 << endl;

    // 5. 测试迭代器
    cout << "迭代器遍历: ";
    for (auto ch : s1) cout << ch;
    cout << endl;

    // 6. 测试大小和容量管理
    cout << "size: " << s1.size() << " capacity: " << s1.capacity() << endl;
    s1.reserve(50);
    cout << "reserve(50)后 capacity: " << s1.capacity() << endl;

    // 7. 测试访问元素
    cout << "s1[1]: " << s1[1] << endl;

    // 8. 测试关系运算符
    cout << "s2 == s3: " << (s2 == s3) << endl;
    cout << "s2 < s3: " << (s2 < s3) << endl;

    // 9. 测试 find
    cout << "find 'l' in s1: " << s1.find('l') << endl;
    cout << "find \"world\" in s1: " << s1.find("world") << endl;

    // 10. 测试插入
    s1.insert(5, 3, '*');
    s1.insert(8, "INSERT");
    cout << "插入测试: " << s1 << endl;

    // 11. 测试删除
    s1.erase(5, 3);
    cout << "删除测试: " << s1 << endl;

    // 12. 测试输入输出
    cout << "请输入字符串: ";
    cin >> s1;
    cout << "输入的字符串: " << s1 << endl;
}

int main()
{
    TestString();
    return 0;
}
