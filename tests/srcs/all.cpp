
#include "all.hpp"

std::ostream & operator << (std::ostream &os, const Buffer &buf)
{
	os << buf.idx << " " << buf.buff << std::endl;
	return os;
}
