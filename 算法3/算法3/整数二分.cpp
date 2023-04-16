#define _CRT_SECURE_NO_WARNINGS



#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int a[N], n, m;

// Ѱ����˵�
int findL(int x)
{
    int l = 0, r = n - 1;
    // �����������Ϊ��Ѱ�Ҳ�С��x��ֵ����˵�
    while (l < r)
    {
        int mid = l + r >> 1;
        if (a[mid] >= x) r = mid;
        else l = mid + 1;
    }
    if (a[l] == x) return l;    // �ж��Ƿ��н�
    return -1;
}

// Ѱ���Ҷ˵�
int findR(int x)
{
    int l = 0, r = n - 1;
    // �����������Ϊ��Ѱ�Ҳ�����x���Ҷ˵�
    while (l < r)
    {
        int mid = l + r + 1 >> 1;
        if (a[mid] <= x) l = mid;
        else r = mid - 1;
    }
    return l;   // ��Ϊ��Ȼ��ִ�е�findR��˵��x�϶����ڣ��Ͳ��õ����Ҳ�����
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
