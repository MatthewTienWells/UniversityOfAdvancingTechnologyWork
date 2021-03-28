#include "Header.h"

void score_countdown(int* score, bool* run)
{
	while (*run)
	{
		sleep_for(nanoseconds(500));
		*score -= 1;
	}
}

