# include <stdio.h>
# include <stdlib.h>
/*
题目描述 Description
乐乐学习编程有两年之久，练就了过硬的指法，打字速度超快，他被选拔代表班级参加校园文化周活动之汉字录入比赛。
比赛规则：组织方提供一篇文章，利用金山打字软件测试选手的成绩，选手录入完之后，系统马上会显示录入速度和正确率。最终成绩为：
速度×正确率，个人奖按成绩的高低进行排名。我校共有n名同学参加了打字比赛，编号1到n，组织方请乐乐计算各选手的成绩，并按成绩
高低进行排列，以便组织方按成绩来评定个人奖项。乐乐发挥他的特长利用编程一下子就解决了组织方的问题。聪明的你会吗？
*/
struct student
{
	int num, scord;
} stu[30001];
int cmp(const void *a, const void *b)  //结构体二级排序
{
	struct student *x = (struct student *)a;
	struct student *y = (struct student *)b;
	if(x->scord != y->scord)
		return (y->scord - x->scord);
	else
		return (x->num - y->num);
}
int main()
{
	int n, i, tmp1, tmp2;
	scanf("%d", &n);
	for(i = 0; i < n; ++i)
	{
		scanf("%d %d", &tmp1, &tmp2);
		stu[i].num = i + 1;
		stu[i].scord = tmp1 * tmp2;
	}
	qsort(stu, n, sizeof(struct student), cmp);   //快排
	for(i = 0; i < n; ++i)
	{
		printf("%d %.2f\n", stu[i].num, stu[i].scord / 100.0);
	}
	return 0;
}
/*
输入描述 Input Description
第一行是一个正整数n（n<=3000）。
接下来有n行，每行有两个用空格隔开的正整数。第i行表示编号为i同学的打字速度（字/分）和正确率（%）。
输出描述 Output Description
按成绩高低输出n行，每行有两个用空格隔开的数，分别为编号和成绩。（成绩相等的，编号小的排在前面，输出的成绩保留两位小数）
样例输入 Sample Input
5
71 100
79 99
35 98
104 100
55 96
样例输出 Sample Output
4 104.00
2 78.21
1 71.00
5 52.80
3 34.30
数据范围及提示 Data Size & Hint
n<=3000
*/
