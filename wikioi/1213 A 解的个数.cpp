#include <cstdio>
#include <iostream>
using namespace std;

long long a, b, c;
long long x1, x2, y1, y2;
long long x, y;

long long gcd(long long a, long long b) {
    return a%b==0?b:gcd(b,a%b);
}

void exgcd(long long a, long long b) {
    if(b == 0) {
        x = 1; y = 0;
    }
    else {
        exgcd(b, a%b);
        long long tmp = x;
        x = y;
        y = tmp-(a/b)*y;
    }
}

long long solve() {
    // read.
    scanf("%lld %lld %lld", &a, &b, &c);
    scanf("%lld %lld %lld %lld", &x1, &x2, &y1, &y2);
    
    if(a == 0 && b == 0 && c != 0) {
        return 0;
    }
    if(a == 0 && b == 0 && c == 0) {
        return max((long long)0,x2-x1+1)*max((long long)0,y2-y1+1);
    }
    
    if(a == 0) {
        long long sign = 0;
        if(y1 <= -c/b && y2 >= -c/b && -c%b == 0) {
            sign = 1;
        }
        return max((long long)0, x2-x1+1)*sign;
    }
    if(b == 0) {
        long long sign = 0;
        if(x1 <= -c/a && x2 >= -c/a && -c%a == 0) {
            sign = 1;
        }
        return max((long long)0, y2-y1+1)*sign;
    }

    exgcd(a, b);
    long long ans = 0, GCD = gcd(a, b);
    
    if(-c%GCD!=0) {
        return 0;
    }

    x = x*(-c/GCD);
    y = y*(-c/GCD);
    printf("x = %d, y = %d\n", x, y);
    a /= GCD;
    b /= GCD;
    if(b < 0) {
        b = -b, a = -a;
    }
    while(x1 <= x) {
        x -= b;
        y += a;
    printf("x = %d, y = %d\n", x, y);
    }
    while(x <= x2) {
        if(x1 <= x && x <= x2 && y1 <= y && y <= y2) {
            ans += 1;
        }
        x += b;
        y -= a;
    printf("x = %d, y = %d\n", x, y);
    }
    return ans;
}

int main(int argc, char **argv) {
    int n;
    scanf("%d", &n);
    while(n--) {
        printf("%lld\n", solve());
    }
    return 0;
}

