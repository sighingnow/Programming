# include <stdio.h>
# define abs(a) ((a)>=0?(a):(-(a)))

int gcd(int a,int b)
{
	int temp;
	if(a < b)
	{
		temp = a; a = b; b = temp;
	}
	if(a%b == 0)
		return b;
	else
		return gcd(a%b,b);
}
//两两求差，再求差的最大公约数 
int main()
{
	int f[101];
	int i,j,k,t,n;
	scanf("%d",&n);
	for(i = 0; i < n; i++)
		scanf("%d",&f[i]);
	t = abs(f[0] - f[1]);
	for(i = 0; i < n; i++)
	{
		for(j = i+1; j < n; j++)
		{
			t = gcd(t,abs(f[i]-f[j]));
		}
	}
	printf("%d\n",t);
	
	return 0;
}
