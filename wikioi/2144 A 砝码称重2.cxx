#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
/*
题目描述 Description
有n个砝码，现在要称一个质量为m的物体，请问最少需要挑出几个砝码来称？
注意一个砝码最多只能挑一次
* */
int wei[30];
map<int, int>sum[2];

void dfs(int flag, int m, int k, int n, int s)
{
    sum[flag].insert(pair<int, int>(s, m));
    if(k <= n)
    {
        for(int i = k; i <= n; ++i)
        {
            s += wei[i];
            m ++;
            dfs(flag, m, i + 1, n, s);
            s -= wei[i];
            m --;
        }
    }
}

int main(int argc, char **argv)
{
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        cin >> wei[i];
    dfs(0, 0, 1, n / 2, 0);
    dfs(1, 0, n / 2 + 1, n, 0);
    int ans = 0x3fffffff;
    map<int, int>::iterator it0 = sum[0].begin(), it1 = sum[1].end();
    it1 --;
    while(it0 != sum[0].end() && it1 != sum[1].begin())
    {
        int tmp = it0->first + it1->first;
        if(tmp == m && it0->second + it1->second < ans)
            ans = it0->second + it1->second;
        if(tmp < m)
            it0 ++;
        else
            it1 --;
    }
    cout << ans;
    return 0;
}
/*
输入描述 Input Description
第一行两个整数n和m，接下来n行每行一个整数表示每个砝码的重量。
输出描述 Output Description
输出选择的砝码的总数k，你的程序必须使得k尽量的小。
样例输入 Sample Input
3 10
5
9
1
样例输出 Sample Output
2
数据范围及提示 Data Size & Hint
1<=n<=30，1<=m<=2^31，1<=每个砝码的质量<=2^30
* */

