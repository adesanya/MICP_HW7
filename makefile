vend:main.cpp
	g++ -std=c++11 main.cpp VendingMachineImpl.cpp  coin.cpp item.cpp inventory.hpp VendingMachine.cpp -o vend

