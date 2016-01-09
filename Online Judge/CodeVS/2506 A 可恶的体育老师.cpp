# include <iostream>
using namespace std;
int p[65][2];
int main()
{
	int n, i, x, y, t1, t2;
	cin >> n;
	for(i = 0; i < n; i++)
		cin >> p[i][0] >> p[i][1];
	cin >> x >> y;
	for(i = 0; i < n; i++)
	{
		if(p[i][0] % x == 0)
			t1 = p[i][0] / x;
		else
			t1 = p[i][0] / x + 1;
		if(y % p[i][1] == 0)
			t2 = y / p[i][1];
		else
			t2 = y / p[i][1] + 1;
		if(t1 - t2 > 1)
			break;
		else
		{
			y -= (t1-1) * p[i][1];
		}
	}
	if(i == n)
		cout << "yes!!very good" << endl;
	else
		cout << "oh shit!" << endl;
		
	return 0;
}
