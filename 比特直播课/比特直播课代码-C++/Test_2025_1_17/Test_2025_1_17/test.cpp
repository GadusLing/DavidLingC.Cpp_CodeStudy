#define _CRT_SECURE_NO_WARNINGS

#include<stack>
#include<queue>
#include<iostream>
#include<assert.h>

using namespace std;

int main() {
    std::stack<int> mystack;
    for (int i = 0; i < 5; ++i) 
    {
        mystack.push(i);
    }

    std::cout << "Popping out elements...";
    while (!mystack.empty()) 
    {
        std::cout << ' ' << mystack.top();
        mystack.pop();
    }
    std::cout << '\n';

    return 0;
}
