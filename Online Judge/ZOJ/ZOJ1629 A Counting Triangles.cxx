#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>

using namespace std;
/* ZOJ 1629 Counting Triangles
Given an equilateral triangle with n the length of its side, program to count how many
triangles in it.
Input
The length n (n <= 500) of the equilateral triangle's side, one per line.
process to the end of the file
Output
The number of triangles in the equilateral triangle, one per line.
* */

int main(int argc, char **argv) {
    
    int n, sum;
    while(scanf("%d", &n) == 1) {
        sum = n * n;
        for(int i = 1; i <= n; ++i) {
            sum += (i*(i-1)/2);
        }
        for(int i = 2; i <= n-2; ++i) {
            for(int j = 2; j <= i; ++j) {
                if(i + j > n) {
                    break;
                }
                else {
                    sum += (i-j+1);
                }
            }
        }
        printf("%d\n", sum);
    }
    return 0;
}

/* Sample Input
1
2
3
Sample Output
1
5
13
* */

