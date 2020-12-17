#pragma once

/*	CoinChange.h
*	Returns number of coins for given change through the getChange function.
*	The Least amount of coins is beeing used
*	"change" must be between 0 and 200.
*	It is implied, that infinite coins of each value are available. 
* 
*/

class CoinChange
{
public:
	CoinChange();

	//Return a pointer to the array for the amount of coins
	//change must be between 0 and 200
	int* getChange(double change);

	//Return an pointer to the order and value of the coins
	const double* getCoinValues();

	//Return the Length of the array of getChange and getCoinValues
	int getCoinsReturnedLength();

private:
	double coinValues[8] = { 2, 1, 0.5, 0.2, 0.1, 0.05, 0.02, 0.01};
	const double upperChangeLimit = 200; //Limit for change value

	int coinsReturned[sizeof(coinValues)/sizeof(*coinValues)] = {0};
	double change = 0;

	void resetCoinsReturned();
	void calcChange();
	int validateChange();
};

