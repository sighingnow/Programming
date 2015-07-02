#include<iostream>
#include<cstdlib>
#include<stdio.h>
using namespace std;

/**
 * n为奇数肯定为0.
 * n为偶数，每次都是加两列，我们把两列看为一列，如果这一列与前面分开就只有三种
 * 方法即3*a[n-2],如果这一列不与前面的分开，那么不可分解矩形都只有两种情况所以
 * 为2*（a[n-4]+a[n-6]+……a[0])
 * 化简即为a[n]=4*a[n-2]-a[n-4]
 */

int main(int argc, char **argv) {
    long long n, a[31] = {0};
    a[0]=1; a[2]=3;
    for(int i = 4; i <= 30; i += 2) {
        a[i]=4*a[i-2]-a[i-4];
    }
    while(scanf("%lld",&n)!=EOF && n != -1) {
        printf("%lld\n",a[n]);
    }

    return 0;
}
