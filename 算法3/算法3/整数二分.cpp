#define _CRT_SECURE_NO_WARNINGS



#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int a[N], n, m;

// 寻找左端点
int findL(int x)
{
    int l = 0, r = n - 1;
    // 这里的任务定义为：寻找不小于x的值的左端点
    while (l < r)
    {
        int mid = l + r >> 1;
        if (a[mid] >= x) r = mid;
        else l = mid + 1;
    }
    if (a[l] == x) return l;    // 判断是否有解
    return -1;
}

// 寻找右端点
int findR(int x)
{
    int l = 0, r = n - 1;
    // 这里的任务定义为：寻找不大于x的右端点
    while (l < r)
    {
        int mid = l + r + 1 >> 1;
        if (a[mid] <= x) l = mid;
        else r = mid - 1;
    }
    return l;   // 因为既然能执行到findR，说明x肯定存在，就不用担心找不到。
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    while (m--)
    {
        int x;
        scanf("%d", &x);

        int l = findL(x), r;
        if (l == -1) puts("-1 -1");
        else
        {
            r = findR(x);
            printf("%d %d\n", l, r);
        }
    }

    return 0;
}
