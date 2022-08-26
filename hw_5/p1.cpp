#include <bits/stdc++.h>
using namespace std;

bool check(string sub)
{
    int len = sub.length();
    for (int i = 0; i < (len / 2); i++)
    {
        if (sub[i] != sub[len - i - 1])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string str;
    cin >> str;
    int len = str.length();
    int head = -1;
    int tail = 0;
    int sub_len = 0;

    if (str.find_first_of(',') == string::npos)
    {
        if (check(str))
        {
            cout << str << endl;
        }
    }
    else
    {
        for (int i = 0; i < len; i++)
        {
            if (str[i] == ',')
            {
                tail = i;
                head += 1;
                sub_len = tail - head;
                string sub_str = str.substr(head, sub_len);
                // cout << sub_str << endl;
                head = tail;
                if (check(sub_str))
                {
                    cout << sub_str << endl;
                }
            }
        }
        head += 1;
        sub_len = len - head;
        string sub_str = str.substr(head, sub_len);
        if (check(sub_str))
        {
            cout << sub_str << endl;
        }
    }
    return 0;
}