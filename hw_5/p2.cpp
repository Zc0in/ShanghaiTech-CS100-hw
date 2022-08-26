#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class ReportParser
{
public:
    ReportParser(int numStudents, int numProblems) : n(numStudents), m(numProblems){};
    ~ReportParser(){};
    void readReport();
    void writeStructuredReport();

private:
    int n, m;
    string sub_str[100][100];
    // Your additional declarations here
};
void ReportParser::readReport()
{
    for (int b = 0; b < n; b++)
    {
        string str;
        getline(cin, str);
        int len = str.length();
        int head = -1;
        int tail = 0;
        int sub_len = 0;
        int a = 0;
        for (int i = 0; i < len; i++)
        {
            if (str[i] == ' ')
            {
                tail = i;
                head += 1;
                sub_len = tail - head;
                sub_str[b][a] = str.substr(head, sub_len);
                head = tail;
                a += 1;
            }
        }
        head += 1;
        sub_len = len - head;
        sub_str[b][a] = str.substr(head, sub_len);
    }
}

void ReportParser::writeStructuredReport()
{
    int max[m];
    memset(max, 0, sizeof(max));
    for (int a = 0; a < m; a++)
    {
        max[a] = sub_str[0][a].length() + 2;
        for (int b = 0; b < n - 1; b++)
        {
            if (max[a] < sub_str[b + 1][a].length() + 2)
            {
                max[a] = sub_str[b + 1][a].length() + 2;
            }
        }
    }
    int total = 0;
    for (int a = 0; a < m; a++)
    {
        total += max[a];
        // cout << max[a] << endl;
    }
    // cout << total << endl;
    // total += (m + 1);

    for (int i = 0; i < (2 * n + 1); i++)
    {
        if (i == 0)
        {
            for (int j = 0; j < total + m + 1; j++)
            {
                if (j == 0)
                {
                    cout << '/';
                }
                else if (j == total + m)
                {
                    cout << "\\" << endl;
                }
                else
                {
                    cout << '-';
                }
            }
        }
        else if (i == 2 * n)
        {
            for (int j = 0; j < total + m + 1; j++)
            {
                if (j == 0)
                {
                    cout << '\\';
                }
                else if (j == total + m)
                {
                    cout << "/" << endl;
                }
                else
                {
                    cout << '-';
                }
            }
        }
        else if (i % 2 == 0)
        {
            for (int j = 0; j < m; j++)
            {
                cout << '|';
                for (int i = 0; i < max[j]; i++)
                {
                    cout << '-';
                }
            }
            cout << '|' << endl;
        }
        else if (i % 2 == 1)
        {
            for (int j = 0; j < m; j++)
            {
                cout << "| ";
                cout << sub_str[(i - 1) / 2][j];

                for (int s = 0; s < max[j] - sub_str[(i - 1) / 2][j].length() - 1; s++)
                {
                    cout << ' ';
                }
            }
            cout << '|' << endl;
        }
    }
}

// DO NOT modify the main function
int main()
{
    int n, m;
    std::cin >> n >> m;
    getchar();
    ReportParser a(n, m);
    a.readReport();
    a.writeStructuredReport();
    return 0;
}
