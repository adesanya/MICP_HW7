#include"VendingMachineImpl.hpp"

VendingMachineImpl::VendingMachineImpl()
{

}

void VendingMachineImpl::initialize(std::list<item> items, int quantity,Coins startingCoins)
{
	InitialQuantity=quantity;
    InitialCoins=startingCoins;
    CoinsInVm=startingCoins;
    initalBallance=CoinsInVm.total_value_in_cents();
    currentBallance=initalBallance;
    myInventoryItems=items;
	for(auto anitem:items)
	{
        myinventory.add(anitem);
		myinventory.put(anitem,quantity);
	}
}

long VendingMachineImpl:: selectItemAndGetPrice(item aitem)
{
	std::list<item>::iterator possibleitem=std::find(myInventoryItems.begin(),myInventoryItems.end(),aitem);
	if(myinventory.hasItem(aitem) && possibleitem!=myInventoryItems.end())
		return (*std::find(myInventoryItems.begin(),myInventoryItems.end(),aitem)).getprice();
	return 0.0;
}

void  VendingMachineImpl:: insertCoin(Coins acoin)
{
    CoinsInserted.clear();
    CoinsInserted.deposit_coins(acoin);
}


Coins VendingMachineImpl:: collectItemAndChange(item anitem,int quantity)
{
    CoinsInVm.deposit_coins(CoinsInserted);
	long change=CoinsInserted.total_value_in_cents()-(anitem.getprice()*quantity);
    cout<<"#change:"<<change<<endl;
	std::map<item,Coins> Item_Change;
	collectItem(anitem,quantity);
	Coins customer_change=collectChange(change);
    CoinsInserted.clear();
	return customer_change;
}


item VendingMachineImpl::  collectItem(item anitem,int quantity)
{
	if(isFullyPaid(anitem,quantity))
	{
		myinventory.remove(anitem,quantity);
		totalSales+=(anitem.getprice()*quantity);
	}
	return anitem;
}

Coins  VendingMachineImpl:: collectChange(long amount)
{
	return CoinsInVm.extract_exact_change_for_cents((int)amount);
}

Coins  VendingMachineImpl:: refund()
{
	return CoinsInserted;
}

bool VendingMachineImpl:: isFullyPaid(item anitem,int quantity)
{
	return (CoinsInserted.total_value_in_cents())>=(anitem.getprice()*quantity);
}

Coins VendingMachineImpl:: getChange(long amount)
{
	return CoinsInVm.extract_exact_change_for_cents((int)amount);
}

void VendingMachineImpl::reset()
{
	CoinsInVm=InitialCoins;
	totalSales=0;
	currentBallance=CoinsInVm.total_value_in_cents();
	myinventory.clear();
	for(auto anitem:myInventoryItems )
	{
		myinventory.put(anitem,InitialQuantity);
	}
}


void  VendingMachineImpl:: PrintStats()
{
    cout<<"__________________________________________"<<endl;
    cout<<"          Transaction Summary"<<endl;
    cout<<"__________________________________________"<<endl;
	cout<<"Total Sales:"<<totalSales<<endl;
	cout<<"Current Ballance:"<<currentBallance<<endl;
	cout<<"Coins in Vending Machine:"<<endl;
    CoinsInVm.print();
    cout<<"___________________________________________"<<endl;
    cout<<"            Item Inventory"<<endl;
    cout<<"___________________________________________"<<endl;
	for(auto anitem:myInventoryItems)
	{
		cout<<anitem.getname()<<": "<<myinventory.getQuantity(anitem)<<endl;
	}
}

bool VendingMachineImpl::  hasSufficentChange()
{
    long amount=(long)CoinsInserted.total_value_in_cents();
    return CoinsInVm.has_exact_change_for_cents(amount);
}

bool  VendingMachineImpl::hasSufficentChangeForAmount(long amount)
{
	return CoinsInVm.has_exact_change_for_cents((int)amount);
}

void VendingMachineImpl:: updateCashInventory(Coins newCoins)
{
	CoinsInVm=newCoins;
}

long VendingMachineImpl:: getTotalSales()
{
	return totalSales;
}


