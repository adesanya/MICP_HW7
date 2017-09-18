#include"VendingMachine.hpp"


VendingMachine::VendingMachine()
{
    item coke("COKE",125);
    item pepsi("PEPSI",125);
    item soda("SODA",100);
    item water("WATER",100);

    VMitems.push_back(coke);
    VMitems.push_back(pepsi);
    VMitems.push_back(soda);
    VMitems.push_back(water);
    
    int index=0;
    for(auto aitem:VMitems)
    {
        item_map[index]=aitem;
        ++index;
    }
    Coins startingCoins(100,100,100,100);
    vendingMachine1.initialize(VMitems,10,startingCoins);

}


void VendingMachine:: print_menu()
{
    cout<<"____________________________________________________________________"<<endl;
    cout<<"                    Make Selection From MENU Below"<<endl;
    cout<<"____________________________________________________________________"<<endl;
    cout<<"Enter 0 for COKE"<<endl;
    cout<<"Enter 1 for PEPSI"<<endl;
    cout<<"Enter 2 for SODA"<<endl;
    cout<<"Enter 3 for WATER"<<endl;
    cout<<"Enter SELECTION: ";
}

int VendingMachine:: select_item()
{
    print_menu();
    int input;
    cin>>input;
    return input;
}

item VendingMachine::selectItemAndGetPrice()
{
    int index=select_item();
    cout<<"The price of "<<item_map[index].getname()<<" is "<< vendingMachine1.selectItemAndGetPrice(item_map[index])<<" Cents"<<endl;
    return item_map[index];
    
}

Coins VendingMachine:: insertCoin()
{
    int Quarter;
    int Dime;
    int Nickel;
    int Penny;
    cout<<"\nEnter amount of quaters: ";
    cin>>Quarter;
    cout<<"Enter amount of Dime: ";
    cin>>Dime;
    cout<<"Enter amount of Nickel: ";
    cin>>Nickel;
    cout<<"Enter amount of Penny: ";
    cin>>Penny;

    cout<<"\nYou Entered Quarters: "<<Quarter<<" Dimes: "<<Dime<<" Nickels: "<<Nickel<<" Pennies: "<<Penny<<endl;
    return Coins(Quarter,Dime,Nickel,Penny);
}

void VendingMachine:: show_transaction_stats()
{
    vendingMachine1.PrintStats();
}

void VendingMachine::runVM()
{
    vendingMachine1.PrintStats();
    char state;
    while(state!='Q')
    {
    item selected=selectItemAndGetPrice();
    Coins insertC=insertCoin();
    vendingMachine1.insertCoin(insertC);
    int options=0;
    if(vendingMachine1.isFullyPaid(selected,1))
    {
        cout<<"Enter 1 to purchase item OR Enter 0 to get refund: ";
        cin>>options;
        if(vendingMachine1.hasSufficentChange()==false)
        {
            cout<<"Vending Machine Does Not Have Sufficient Vhannge "<<endl;
            options=0;
        }
    }
    else
    {
        cout<<"You need more coins to purchase item"<<endl;
    }
    switch(options)
    {
        case 1:
        {
            cout<<"Purchasing Item ...."<<endl;
            Coins mychange=vendingMachine1.collectItemAndChange(selected,1);
            cout<<"Please pick up Item and Change (See Below)"<<endl;
            cout<<"Your Change is"<<endl;
            mychange.print();
            break;
        
        }
        case 0:
        {
            cout<<"Please pick up refund (Below)"<<endl;
            vendingMachine1.refund().print();
            break;
        }
    }
    cout<<"Thank you for using Ola's Vending Machine"<<endl;
    cout<<"Enter Q to quit and see trnsaction STATS OR anything else to continue making  transactions: "<<endl;
    cin>>state;
    }
    show_transaction_stats();
    
}
