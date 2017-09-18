#ifndef VEND
#define VEND

#include<iostream>
#include<string>
#include"item.hpp"
#include"inventory.hpp"
#include"coin.hpp"
#include"custom_exceptions.hpp"
#include"VendingMachineImpl.hpp"
#include<list>

using namespace std;

class VendingMachine
{
private:
    VendingMachineImpl vendingMachine1;
    
    std::list<item> VMitems;
    
    std::map<int,item> item_map;
    
    item selectItemAndGetPrice();
    
    void print_menu();
    
    int select_item();
    
    Coins insertCoin();
    
    void show_transaction_stats();
    
public:
	VendingMachine();
    
    void runVM();

	

};
#endif
