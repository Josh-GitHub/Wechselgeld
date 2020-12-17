#include "CoinChange.h"

CoinChange::CoinChange()
{
}

//Public 

int* CoinChange::getChange(double change)
{
	resetCoinsReturned();
	this->change = change + 0.0001; //Adjust for inaccuracy of double
	if (validateChange() > 0) 
	{
		calcChange();
		return coinsReturned;
	}
	else
	{
		return 0;
	}
}

const double* CoinChange::getCoinValues()
{
	return coinValues;
}

int CoinChange::getCoinsReturnedLength()
{
	return sizeof(coinsReturned)/sizeof(*coinsReturned);
}

//Private functions:
void CoinChange::resetCoinsReturned()
{
	for (int i = 0; i < getCoinsReturnedLength(); i++)
	{
		coinsReturned[i] = 0;
	}
}

void CoinChange::calcChange()
{	
	double change_val = change;
	for (int i = 0; i < (sizeof(coinValues) / sizeof(*coinValues)); i++)
	{
		coinsReturned[i] = change_val / coinValues[i];
		change_val = change_val - ((double)coinsReturned[i] * coinValues[i]);
	}
}

int CoinChange::validateChange()
{	//Checks, if change is in defined scope
	if ((change < 0) or (change > upperChangeLimit))
	{
		return -1;
	}
	else 
	{
		return 1;
	}
}
