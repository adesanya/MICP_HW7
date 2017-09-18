#ifndef COINS
#define COINS   

#include<iostream>
using namespace std;

const int CENTS_PER_QUARTER = 25, CENTS_PER_DIME = 10, CENTS_PER_NICKEL = 5,CENTS_PER_PENNY=1;

class Coins
{
    
private:
    int quarters, dimes, nickels, pennies;
    
public:
    Coins();
    
    Coins(int q,int d,int n,int p);
    
    void deposit_coins(Coins & c);
    
    bool has_exact_change_for_cents(int amount_in_cents);
    
    Coins extract_exact_change_for_cents(int amount_in_cents);
    
    int total_value_in_cents();
    
    bool operator==(const Coins LCoins ) const;
    
    void print();
    
    void clear();
    ~Coins();
    
};

#endif
