#include <string>
#include <iostream>

using namespace std;


//int myAtoi(string str)
//{
//    int result = 0; int symbol = 1;//结果,正负符号
//    int traverse = 0;// 遍历用下标
//    int n = str.size();// 所有的字符都要用ASCII码值来判断，需要有一个字符边界来终止循环
//    while (traverse < n && str[traverse] == ' ')
//    {
//        ++traverse;// 丢弃无用的前导空格
//    }
//    while (traverse < n && str[traverse] == '-' || str[traverse] == '+')// 确认符号
//    {
//        symbol = (str[traverse] == '-') ? -1 : 1;// 如果有-号,更新标识为-1,表示负数
//        ++traverse;
//        break;
//    }
//    while (traverse < n && (str[traverse] <= '9' && str[traverse] >= '0'))
//    {
//        int digit = str[traverse] - '0';// 字符要-'0'才能变成int
//        if (result >= INT_MAX / 10 && digit > 7)
//        {
//            return symbol == 1 ? INT_MAX : INT_MIN;// -2147483648 ----  2147483647
//        }
//        result = result * 10 + digit;
//        ++traverse;
//    }
//    return result * symbol;
//}
//
//int main()
//{
//    cout << myAtoi("-91283472332") << endl;
//
//}

#include <iostream>
using namespace std;

int main()
{
    string str;
    cin >> str;
    int index = 0;
    for (auto i = str.end() - 1; i != str.begin() - 1; i--)
    {
        if ((*i - 'A' >= 0 && *i - 'A' <= 25) || (*i - 'a' >= 0 && *i - 'a' <= 25))
        {
            ++index;
        }
        else if (index > 0) // 如果已经计数且遇到非字母，结束
        {
            break;
        }
    }
    cout << index << endl;
}