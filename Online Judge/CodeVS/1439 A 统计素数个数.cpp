# include <iostream>
# include <cstdio>
# include <cmath>
using namespace std;
int ispri(int n)
{
	int i, k = sqrt(n);
	if(n == 0 || n == 1)
		return 0;
	else
	{
		for(i = 2; i <= k; i++)
		{
			if(n % i == 0)
				break;
		}
		if(i > k)
			return 1;
		else
			return 0;
	}
}
int main()
{
	int m, n, t = 0, i;
	cin >> m >> n;
	for(i = m; i <= n; i++)
		if(ispri(i) == 1)
			t++;
	cout << t << endl;
	return 0;
}
