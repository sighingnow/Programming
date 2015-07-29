# include <iostream>
# include <cstdio>
# include <cmath>
using namespace std;
int main()
{
	int n;
	char x, y;
	scanf("%d", &n);
	getchar();
	while(n--)
	{
		while((y = getchar()) != '\n' && y != '\n')
		{
			x = y;
		}
		if((x-'0') % 2 == 1)
			printf("odd\n");
		else
			printf("even\n");
	}
	
	return 0;
}
