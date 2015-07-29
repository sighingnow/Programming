# include <iostream>
using namespace std;

int main()
{
	long long int s[4][4];
	long long int max = 0, i, j;
	for(i = 1; i <= 3; i++)
	{
		for(j = 1; j <= 3; j++)
		{
			cin >> s[i][j];
		}
	}
	max = max > s[1][1] + s[2][2] + s[3][3] ? max : s[1][1] + s[2][2] + s[3][3];
	max = max > s[1][1] + s[2][3] + s[3][2] ? max : s[1][1] + s[2][3] + s[3][2];
	max = max > s[1][2] + s[2][1] + s[3][3] ? max : s[1][2] + s[2][1] + s[3][3];
	max = max > s[1][2] + s[2][3] + s[3][1] ? max : s[1][2] + s[2][3] + s[3][1];
	max = max > s[1][3] + s[2][1] + s[3][2] ? max : s[1][3] + s[2][1] + s[3][2];
	max = max > s[1][3] + s[2][2] + s[3][1] ? max : s[1][3] + s[2][2] + s[3][1];
	cout << max;
	return 0;
}
