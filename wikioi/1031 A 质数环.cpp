# include <iostream>
# include <cstdio>
using namespace std;
bool prime[40] = {0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,1};
int n, num[18] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17}, flag[18], buf[18] = {0, 1};
void func(int m)
{
	int i;
	if(m > n && prime[buf[1]+buf[n]])
	{
		for(i = 1; i <= n; i++)
			printf("%d ", buf[i]);
		printf("\n");
	}
	else
	{
		if(m % 2 == 1)
		{
			for(i = 3; i <= n; i += 2)
			{
				if(flag[i] == 0 && prime[buf[m-1]+i] == 1)
				{
					buf[m] = i;
					flag[i] = 1;
					func(m+1);
					flag[i] = 0;
				}
			}
		}
		else
		{
			for(i = 2; i <= n; i += 2)
			{
				if(!flag[i] && prime[buf[m-1]+i])
				{
					buf[m] = i;
					flag[i] = 1;
					func(m+1);
					flag[i] = 0;
				}
			}
		}
	}
}
int main()
{
	cin >> n;
	if(n % 2 == 1)
		return 0;
	else
		func(2);
	return 0;
}
