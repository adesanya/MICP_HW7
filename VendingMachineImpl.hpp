#ifndef VENDINGMACHINEIMPL
#define VENDINGMACHINEIMPL

#include<iostream>
#include"item.hpp"
#include"inventory.hpp"
#include"coin.hpp"
#include"custom_exceptions.hpp"
#include<list>
#include<map>
#include<vector>
#include <algorithm>


class VendingMachineImpl
{
	private:
	long totalSales;

	long initalBallance;
	long currentBallance;

	Coins InitialCoins;	
	Coins CoinsInVm;
	Coins CoinsInserted;
	
	int InitialQuantity;
	inventory<item> myinventory;

	std::list<item> myInventoryItems;
	public:
	
	VendingMachineImpl();

	void initialize(std::list<item> items, int quantity, Coins startingCoins);

	long selectItemAndGetPrice(item aitem);

	void insertCoin(Coins acoin);

	Coins collectItemAndChange(item anitem,int quantity);

	item collectItem(item anitem,int quantity);

 	Coins collectChange(long amount);

	Coins refund();

	bool isFullyPaid(item anitem,int quantity);

	Coins getChange(long  amount);

  	void reset();
	
	void PrintStats();

	bool hasSufficentChange();

	bool hasSufficentChangeForAmount(long amount);

	void updateCashInventory(Coins newCoins);

	long getTotalSales();
	
};

#endif
