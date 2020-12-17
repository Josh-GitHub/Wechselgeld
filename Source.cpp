#include <iostream>	//printf
#include "CoinChange.h"

int main()
{
	//Test the CoinChange Class
	double change = 5.99; //

	CoinChange* coins = new CoinChange();


	int* pointerCoins = coins->getChange(change);
	const double* pointerCoinValues = coins->getCoinValues();



	printf("Coins for Change of %4.2f Euros\n", change);
	for (int i = 0; i < coins->getCoinsReturnedLength(); i++)
	{
		printf("%d of %4.2f Euro coins\n", pointerCoins[i], pointerCoinValues[i]);
	}

}