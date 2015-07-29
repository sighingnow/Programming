# include <iostream>
# include <cstdio>
# include <cmath>
using namespace std;

int main()
{
	double x, y, z, m;
	cin >> x >> y >> z;
	if(x + y > z && x + z > y && y + z > x)
	{
		m = (x + y + z) / 2.0;
		printf("%.2f", sqrt(m * (m - x) * (m-y) * (m-z)));
	}
	else
		printf("No answer");
	return 0;
}
