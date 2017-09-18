#ifndef INVENTORY
#define INVENTORY

#include<iostream>
#include<map>



template<typename T>
class inventory
{

	private:
	
	std::map<T,int> my_inventory;	

	public:

	inventory();

	int getQuantity(T item);

	void add(T item);

	void deduct(T item);

	bool hasItem(T item);

	void clear();

	void put(T item, int quantity);

	 void remove(T item, int quantity);

	~inventory();
}
;

template<typename T>
inventory<T>::inventory()
{
}

template<typename T>
int inventory<T>:: getQuantity(T item)
{
    return my_inventory[item];
}

template<typename T>
void inventory<T>:: add(T item)
{
    if(my_inventory[item]==0)
    	my_inventory[item]=0;
}

template<typename T>
void inventory<T>:: deduct(T item)
{
    auto it=my_inventory.find(item);
    my_inventory.erase(it);
}

template<typename T>
bool inventory<T>:: hasItem(T item)
{
    if(my_inventory[item]>0)
        return true;
    return false;
}

template<typename T>
void inventory<T>:: clear()
{
    my_inventory.clear();
}

template<typename T>
void inventory<T>::put(T item, int quantity)
{
    my_inventory[item]+=quantity;
}

template<typename T>
void inventory<T>::remove(T item, int quantity)
{
    my_inventory[item]-=quantity;
}

template<typename T>
inventory<T>::~inventory()
{
    
}

#endif
