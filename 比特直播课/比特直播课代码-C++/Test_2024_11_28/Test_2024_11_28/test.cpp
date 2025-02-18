
#include <iostream>
#include "string.h"

using namespace std;
using namespace LDW;

void TestString()
{
    // 1. ���Թ��캯��
    LDW::string s1;                // Ĭ�Ϲ���
    LDW::string s2("hello");      // C�ַ�������
    LDW::string s3(s2);            // ��������

    cout << "�������:" << endl;
    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;
    cout << "s3: " << s3 << endl;

    // 2. ���Ը�ֵ�����
    s1 = s2;
    cout << "��ֵ���������: " << s1 << endl;

    // 3. ���� += ׷���ַ����ַ���
    s1 += '!';
    s1 += " world";
    cout << "+= ����: " << s1 << endl;

    // 4. ���� push_back
    s1.push_back('?');
    cout << "push_back ����: " << s1 << endl;

    // 5. ���Ե�����
    cout << "����������: ";
    for (auto ch : s1) cout << ch;
    cout << endl;

    // 6. ���Դ�С����������
    cout << "size: " << s1.size() << " capacity: " << s1.capacity() << endl;
    s1.reserve(50);
    cout << "reserve(50)�� capacity: " << s1.capacity() << endl;

    // 7. ���Է���Ԫ��
    cout << "s1[1]: " << s1[1] << endl;

    // 8. ���Թ�ϵ�����
    cout << "s2 == s3: " << (s2 == s3) << endl;
    cout << "s2 < s3: " << (s2 < s3) << endl;

    // 9. ���� find
    cout << "find 'l' in s1: " << s1.find('l') << endl;
    cout << "find \"world\" in s1: " << s1.find("world") << endl;

    // 10. ���Բ���
    s1.insert(5, 3, '*');
    s1.insert(8, "INSERT");
    cout << "�������: " << s1 << endl;

    // 11. ����ɾ��
    s1.erase(5, 3);
    cout << "ɾ������: " << s1 << endl;

    // 12. �����������
    cout << "�������ַ���: ";
    cin >> s1;
    cout << "������ַ���: " << s1 << endl;
}

int main()
{
    TestString();
    return 0;
}
