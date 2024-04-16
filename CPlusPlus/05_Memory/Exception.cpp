#include "Exception.h"


double DevideNumber(double _Numberator, double _Denomirator)
{
	if (_Denomirator == 0.0)
	{
		throw std::invalid_argument("This is Not vailable.");
	}

	return _Numberator / _Denomirator;
}