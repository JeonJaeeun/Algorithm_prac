#include<stdio.h>

int main()
{
	int i, bur, drink, min_bur = 2000, min_drink = 2000;
	for (i = 0; i < 3; i++)
	{
		scanf("%d", &bur);

		if (min_bur > bur)
			min_bur = bur;
	}

	for (i = 0; i < 2; i++)
	{
		scanf("%d", &drink);

		if (min_drink > drink)
			min_drink = drink;
	}
	printf("%d\n", min_bur + min_drink - 50);
	return 0;
}