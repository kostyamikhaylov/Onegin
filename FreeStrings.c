#include "Onegin.h"
#include <stdlib.h>


void FreeStrings (char **strings)
{
	ASSERT (strings);

	free (strings[StringsNumber (strings) + 1]);
	free (strings);
}

