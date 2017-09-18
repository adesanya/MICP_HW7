#ifndef CUSTOM_EXCEPTIONS
#define CUSTOM_EXCEPTIONS

#include<string>
using namespace std;

class SoldOutException : public exception
{

	private:
	
	string message;

	public:

	SoldOutException(string m);

	string getMessage();
};


class NotFullyPaidException: public exception
{
	private:
	string message;
	long remaining;

	public:

	NotFullyPaidException(string m,long r);

	long getRemaining();

	string getMessage();

};


class NotSufficentChangeException:public exception
{
	private:
	string message;

	public:
	
	NotSufficentChangeException(string m);

    string getMessage();
};

class soldOutException : public exception
{
	private:

	string message;

	public:

	soldOutException(string m);

	string getMessage();
};

#endif
