#include "Onegin.h"
#include <stdlib.h>

/*
FreeStrings чистит выделенную в Readstrings память.
Принимает указатель на массив указателей на начальные элементы строк.
Сначала чистятся все строки (память для них выделялась одним куском,
указатель на его начало лежит сразу после пустого указателя,
заканчивающего массив указателей на строки).
Затем чистится сам массив указателей.
*/

void FreeStrings (char **strings)
{
	ASSERT (strings);

	free (strings[StringsNumber (strings) + 1]);
	free (strings);
}

