# include <stdio.h>
char s[52][4] = {"B1", "B2", "B3", "B4", "B5", "B6", "B7", "B8", "B9", "B10", "BJ", "BQ", "BK",
				 "H1", "H2", "H3", "H4", "H5", "H6", "H7", "H8", "H9", "H10", "HJ", "HQ", "HK",
				 "M1", "M2", "M3", "M4", "M5", "M6", "M7", "M8", "M9", "M10", "MJ", "MQ", "MK",
				 "F1", "F2", "F3", "F4", "F5", "F6", "F7", "F8", "F9", "F10", "FJ", "FQ", "FK"};
int main()
{
	int i, n, head = 0, t;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		scanf("%d", &t);
		head += t;
		head %= 52;
	}
	for(i = head; i < 52; i++)
		printf("%s ", s[i]);
	if(head > 0)
		for(i = 0; i < head; i++)
			printf("%s ", s[i]);
	return 0;
}
