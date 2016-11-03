#include "Auto.h"

Auto::Auto(const char* name, int ps)
{
	Auto::name = name;
	Auto::ps = ps;
}

int Auto::getPS()
{
	return ps;
}