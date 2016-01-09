#include <iostream>
using namespace std;
/*

题目描述 Description
黑板上有n个数字X1，X2，X3，……Xn，男主和女主玩起了数字游戏。
女主和男主轮流对其中一个数进行游戏操作：
将Xi改为区间[(Xi+1)/2,Xi )中的一个数。(除法向下取整，区间左闭右开)
如果这个数变成了1，便将其擦去(优先于人物操作)，无法修改数字的人失败。
男主希望女主在双方均采取最优策略的情况下永远取得胜利。
* */
//对于奇数,sg(x)=sg(x/2),对于偶数,sg(x)=x/2;n堆的sg值异或,若为0,先手必败.
int sg(int n)
{
    if(n % 2)
        return sg(n / 2);
    else
        return n / 2;
}
int main(int argc, char **argv)
{
    int n, num, ans;
    cin >> n >> num;
    ans = sg(num), n -= 1;
    while(n--)
    {
        cin >> num;
        ans ^= sg(num);
    }
    if(ans == 0)
        cout << "You Are An Apple of My Eyes";
    else
        cout << "Lady First";
    return 0;
}
/*
输入描述 Input Description
第一行为一个正整数n，代表数字个数。
第二行为n个正整数，代表X1，X2，X3，……Xn这n个数字。
输出描述 Output Description
如果从女主开始游戏，女主可以获胜，输出"Lady First" (不含引号)，表示男主将主动权让给了女主。
否则必须是从男主开始，女主才能获胜，输出"You Are An Apple of My Eyes" (不含引号)，表示男主赞美了女主之后才能获得主动权。
样例输入 Sample Input
【样例输入1】
1
5201314
【样例输入2】
6
20 13 3 22 17 25
样例输出 Sample Output
【样例输出1】
Lady First
【样例输出2】
You Are An Apple of My Eyes
数据范围及提示 Data Size & Hint
【数据范围与约定】
对于100%的数据，1 ≤ n ≤ 520，1 ≤ ai ≤ 10^18。
【来源】
2013年3月24日白色情人节欢乐赛Day2T1。
* */
