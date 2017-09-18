#ifndef ITEM
#define ITEM

#include<string>
using namespace std;

class item
{
	private:

	string name;

	int price;

	public:
    
    item();

	item(string n,int p);

	string getname();

	int getprice();	

    bool operator<(const item& anitem )const ;

    bool operator==(const item& anitem )const ;

};

#endif

