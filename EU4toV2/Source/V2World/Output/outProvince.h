#ifndef OUT_PROVINCE_H
#define OUT_PROVINCE_H

#include "../Province/Province.h"

namespace V2
{
	std::ostream& operator<<(std::ostream& output, const Province& province);
}

#endif // OUT_PROVINCE_H
