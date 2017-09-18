#include"item.hpp"
   
item:: item()
{

}

item:: item(string n,int p)
:name{n},price{p}
{
	
}
    
string item:: getname()
{
	return name;
}
    
int item:: getprice()
{
	return price;
}

bool item::  operator<(const item& anitem )const 
{
    if(price<anitem.price)
        return true;
    return false;
}

bool item::  operator==(const item& anitem )const
{
    return anitem.name==name;
}
