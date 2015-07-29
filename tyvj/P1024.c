# include <stdio.h>
# include <string.h>
# define max(a,b) (a)>=(b)?(a):(b)

int up(char s[],int ch[])
{
    int i,m,len,j;
    int f[256];
    len = strlen(s);
    for(i = 0; i < 256; i++)
    {
    	f[i] = 1;
    }
    for(i = 1; i < len; i++)
    {
		for(j = 0; j < i; j++)
		{
			if(ch[s[j]-'a'] <= ch[s[i]-'a'])
			{
				f[i] = max(f[i],f[j]+1);
			}
		}
    }
    m = f[0];
    for(i = 1; i < len; i++)
		m = max(m,f[i]);

    return m;
}

int main()
{
    int i;
    int ch[26];
    char s[256],op;
    for(i = 0; i < 26; i++)
	{
		op = getchar();
		ch[op-'a'] = i+1;
	}
    while((scanf("%s", s)) == 1)
    {
		printf("%d", up(s,ch));
    }
   
    return 0;
}
