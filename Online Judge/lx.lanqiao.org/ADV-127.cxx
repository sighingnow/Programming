#include<iostream>
#include<cstdio>
using namespace std;

int main(int argc, char **argv)
{
    int y, m, d, w, c;
    scanf("%d%d%d", &y, &m, &d);
    if(m < 3) {
        y -= 1;
        m += 12;
    } 
    y = y % 100;
    c = y / 100;
    w = (y+y/4+c/4-2*c+26*(m+1)/10+d-1)%7;
    printf("%d", w == 0 ? 7 : w);
    return 0;
}
