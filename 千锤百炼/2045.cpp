#include <bits/stdc++.h>
using namespace std;
int cmp(int a[], int b[])
{
    if (a[0] > b[0])
        return 1;
    if (a[0] < b[0])
        return -1;
    for (int i = a[0]; i > 0; i--)
    {
        if (a[i] > b[i])
            return 1;
        if (a[i] < b[i])
            return -1;
    }
    return 0;
}
void _minus(int a[], int b[])
{
    int flag = cmp(a, b);
    if (flag == 0)
    {
        a[0] = 0;
        return;
    }
    if (flag == 1)
    {
        for (int i = 1; i <= a[0]; i++)
        {
            if (a[i] < b[i])
            {
                a[i + 1]--;
                a[i] += 10;
            }
            a[i] -= b[i];
        }
        while (a[0] > 0 && a[a[0]] == 0)
        {
            a[0] -= 1;
        }
    }
}
void print(int x[], int n)
{
    for (int i = n; i >= 1; i--)
    {
        cout << x[i];
    }
    cout << endl;
}
void numcpy(int b[], int tmp[], int s)
{
    for (int i = 1; i <= b[0]; i++)
    {
        tmp[i + s - 1] = b[i];
    }
    tmp[0] = b[0] + s - 1;
}
void divide(int a[], int b[], int c[])
{
    int tmp[101];
    c[0] = a[0] - b[0] + 1;
    for (int i = c[0]; i >= 1; i--)
    {
        memset(tmp, 0, sizeof(tmp));
        numcpy(b, tmp, i);
        while (cmp(a, tmp) >= 0)
        {
            c[i]++;
            _minus(a, tmp);
        }
    }
    while (c[0] > 0 && c[c[0]] == 0)
    {
        c[0]--;
    }
}
int main()
{
    char s1[100] = {};
    char s2[100] = {};
    int a[100] = {}, b[100] = {}, c[100] = {};
    scanf("%s",s1);
    scanf("%s",s2);
    a[0] = strlen(s1);
    b[0] = strlen(s2);
    c[0] = 1;
    for (unsigned i = 0, j = strlen(s1); i <= strlen(s1) - 1; i++, j--)
    {
        a[j] = s1[i] - 48;
    }
    for (unsigned int i = 0, j = strlen(s2); i <= strlen(s2) - 1; i++, j--)
    {
        b[j] = s2[i] - 48;
    }
    divide(a, b, c);
    print(c, c[0]);
}
