#include <cstring>
#include <stack>
#include <queue>

bool checkPalindrome(const char *_str)
{
    std::stack<char> s; // 스택 선언
    std::queue<char> q; // 큐 선언 후

    int len = strlen(_str);
    for (int i = 0; i < len; i++) // 문자열 하나씩 쭉쭉 넣고
    {
        s.push(_str[i]);
        q.push(_str[i]);
    }

    while (!s.empty()) // 빌때까지 계속 비교.
    {
        if (s.top() != q.front())
            return false;
        s.pop();
        q.pop();
    }
    return true;
}

int main()
{
    if (checkPalindrome("mem"))
    {
        printf("hi");
    }
    else
    {
        printf("bye");
    }
    return 0;
}