#include <string>
#include <iostream>

using namespace std;


//int myAtoi(string str)
//{
//    int result = 0; int symbol = 1;//���,��������
//    int traverse = 0;// �������±�
//    int n = str.size();// ���е��ַ���Ҫ��ASCII��ֵ���жϣ���Ҫ��һ���ַ��߽�����ֹѭ��
//    while (traverse < n && str[traverse] == ' ')
//    {
//        ++traverse;// �������õ�ǰ���ո�
//    }
//    while (traverse < n && str[traverse] == '-' || str[traverse] == '+')// ȷ�Ϸ���
//    {
//        symbol = (str[traverse] == '-') ? -1 : 1;// �����-��,���±�ʶΪ-1,��ʾ����
//        ++traverse;
//        break;
//    }
//    while (traverse < n && (str[traverse] <= '9' && str[traverse] >= '0'))
//    {
//        int digit = str[traverse] - '0';// �ַ�Ҫ-'0'���ܱ��int
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
        else if (index > 0) // ����Ѿ���������������ĸ������
        {
            break;
        }
    }
    cout << index << endl;
}