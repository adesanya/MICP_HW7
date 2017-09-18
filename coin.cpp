#include"coin.hpp"

Coins:: Coins()
:quarters(0),dimes(0),nickels(0),pennies(0)
{

}

Coins::Coins(int q,int d,int n,int p):
quarters(q),dimes(d),nickels(n),pennies(p)
{
    
}

void Coins:: deposit_coins(Coins & c)
{
    quarters+=c.quarters;
    dimes+=c.dimes;
    nickels+=c.nickels;
    pennies+=c.pennies;
}


bool Coins:: has_exact_change_for_cents(int amount_in_cents)
{
    int cquarters=quarters,cdimes=dimes,cnickels=nickels,cpennies=pennies;
    int balance[4]={cquarters,cdimes,cnickels,cpennies};
    int coins[4]={CENTS_PER_QUARTER,CENTS_PER_DIME, CENTS_PER_NICKEL,CENTS_PER_PENNY };
    for(int coinType=0;coinType<4;coinType++)
    {
        while((amount_in_cents-coins[coinType])>=0 && balance[coinType]!=0)
        {
            amount_in_cents-=coins[coinType];
            balance[coinType]-=1;
        }
    }
    return amount_in_cents==0?true:false;
}

Coins Coins:: extract_exact_change_for_cents(int amount_in_cents)
{
    if(has_exact_change_for_cents(amount_in_cents))
    {
        int cquarters=quarters,cdimes=dimes,cnickels=nickels,cpennies=pennies;
        int balance[4]={quarters,dimes,nickels,pennies};
        int coins[4]={CENTS_PER_QUARTER,CENTS_PER_DIME, CENTS_PER_NICKEL,CENTS_PER_PENNY };
        for(int coinType=0;coinType<4;coinType++)
        {
            while((amount_in_cents-coins[coinType])>=0 && balance[coinType]>0)
            {
                amount_in_cents-=coins[coinType];
                balance[coinType]-=1;
            }
        }
        quarters=balance[0],dimes=balance[1],nickels=balance[2],pennies=balance[3];
        return Coins(cquarters-quarters,cdimes-dimes,cnickels-nickels,cpennies-pennies);
    }
    else
    {
        return Coins(0,0,0,0);
    }
}

int Coins::total_value_in_cents()
{
    return CENTS_PER_QUARTER*quarters+CENTS_PER_DIME*dimes+CENTS_PER_NICKEL
    *nickels+CENTS_PER_PENNY*pennies;
}

bool Coins:: operator==(const Coins LCoins ) const
{
    return (quarters==LCoins.quarters) && (dimes==LCoins.dimes) && (nickels==LCoins.nickels) && (pennies==LCoins.pennies);
}

void Coins:: print()
{
    cout<<"Quarter: "<<quarters<<endl;
    cout<<"Dimes: "<<dimes<<endl;
    cout<<"Nickels: "<<nickels<<endl;
    cout<<"Pennies: "<<pennies<<endl;
}

void Coins:: clear()
{
    quarters=0;
    dimes=0;
    nickels=0;
    pennies=0;
}

Coins:: ~Coins()
{
}

