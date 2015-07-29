# include <iostream>
# include <cstdio>
# include <cmath>
using namespace std;

int main()
{
	double r;
	cin >> r;
	r += 6400;
	printf("%.2f\n", sqrt(7.9 * 7.9 * 6400 / r));
	return 0;
}
