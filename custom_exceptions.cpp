#include"custom_exceptions.hpp"



SoldOutException::SoldOutException(string m)
:message{m}
{

}

string SoldOutException:: getMessage()
{
	return message;
}


NotFullyPaidException::	NotFullyPaidException(string m,long r)
:message{m},remaining{r}
{

}


long NotFullyPaidException:: getRemaining()
{
	return remaining;
}

string NotFullyPaidException:: getMessage()
{
	return message;
}
	

NotSufficentChangeException::	NotSufficentChangeException(string m)
:message{m}
{

}

string NotSufficentChangeException::  getMessage()
{
	return message;
}



soldOutException::soldOutException(string m)
:message{m}
{

}

string soldOutException::  getMessage()
{
	return message;
}
