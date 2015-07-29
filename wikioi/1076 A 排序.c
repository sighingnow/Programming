# include <stdio.h>  //”√Õ∞≈≈–ÚÀ„∑®–¥

int main()
{
    int backet[100001] = {0};
    int i,j,n,num;
    scanf("%d",&n);
    for(i = 0; i < n; i++)
   	{
	   	scanf("%d",&num);
	   	backet[num] ++;
	}
	for(i = 0; i < 100001; i++)
	{
		if(backet[i] > 0)
			for(j = 1; j <= backet[i]; j++)
				printf("%d ",i);
	}
	
	return 0;
}
