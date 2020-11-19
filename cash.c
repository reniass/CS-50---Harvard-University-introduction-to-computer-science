#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <cs50.h>


int main(void)
{
    float odd_money;
    int coins = 0;

	do
	{
		odd_money = get_float("Change owed: ");

	}
	while (odd_money < 0);

	int quantity;

	quantity = round(odd_money * 100);


	while (quantity >= 25)
	{
	    quantity = quantity - 25;
	    coins = coins + 1;

	}
	while (quantity >= 10)
	{
	    quantity = quantity - 10;
	    coins = coins + 1;
	}
	while (quantity >= 5)
	{
	    quantity = quantity - 5;
	    coins = coins + 1;
	}
	while (quantity >= 1)
	{
	    quantity = quantity - 1;
	    coins = coins + 1;
	}

	printf("%i\n", coins);

	return 0;
}
