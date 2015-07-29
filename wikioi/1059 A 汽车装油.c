/*
题目描述 Description
    设在一环行公路上有N个汽车站，每一站存有若干数量的汽油（其中有的站可能不存）。
	现在使一辆原来没有油的汽车从某站依反时针方向沿公路行驶，车站编号为反时针；
	每到一站即把该站的汽油全部带上（出发的站也如此）。试求从哪几站出发可以使汽车从该站出发环行一周，
	不致在中途因缺油而停车。
*/
int main()
{
	int n,i,j,k,t,flag;
	scanf("%d",&n);
	int f[2][n];
	for(i = 0; i < 2; i++)
		for(j = 0; j < n; j++)
		scanf("%d",&f[i][j]);
	k = 0;     // k 用来记录有几个符合条件的车站 
	for(i = 0; i < n; i++)
	{
		t = 0;
		flag = 0;
		for(j = i; j < n; j++)
		{
			t = f[0][j] - f[1][j] + t;
			if(t < 0)
			{
				flag = 1;
				break;
			}
		}
		for(j = 0; j < i; j++)
		{
			t = f[0][j] - f[1][j] + t;
			if(t < 0)
			{
				flag = 1;
				break;
			}
		}
		if(flag == 0)
		{
			k ++;
			printf("%d ",i+1);
		}
	}
	if(k == 0)
		printf("No Result!");
	
	return 0;
}

/*
输入描述 Input Description
输入：输入文件第一行有一个N（站点数N<1000），
第二行有N个数字m1 m2 …… mn，数字间用空格作分隔符（mi描述第I站的存油数，mi≤100），
第三行有N个数字w1 w2 …… wn，数字间用空格作分隔符（wi描述第I站至第I+1站汽车耗油量，wn描述第n站至第1站的耗油量，wi≤100）。
输出描述 Output Description

输出：在一行中按站点编号由小到大输出可出发站点编号(中间用一个空格分隔)。若不存在可出发站点，则输出“No Result!”。
样例输入 Sample Input
5
2  3  4  5  3
3  2  1  5  4 
样例输出 Sample Output
2  3
*/
