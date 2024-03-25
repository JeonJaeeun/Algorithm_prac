#include<stdio.h>

int main()
{
	int people, i, num, zero, one;
	zero = 0, one = 0, num = 0;

	scanf("%d", &people);

	for (i = 1; i <= people; i++)
	{
		scanf("%d", &num);

		if (num == 0)
			zero++;
		else
			one++;
	}
	if (zero < one)
		printf("Junhee is cute!\n");
	else
		printf("Junhee is not cute!\n");

	return 0;
}