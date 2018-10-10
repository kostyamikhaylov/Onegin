#include "Onegin.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern struct Keys keys;

int StrCompare (const void *string1, const void *string2);
int StrCompareFromTheEnd (const void *string1, const void *string2);
int IsLetter (char c);

char **SortStrings (char **strings)
{
	long int str_number = 0;

	ASSERT (strings);

	str_number = StringsNumber (strings);
	qsort (strings, str_number, sizeof (*strings), (keys.from_the_end == 0) ? StrCompare : StrCompareFromTheEnd);

	return strings;
}

long int StringsNumber (char **strings)
{
	long int number = 0;

	while (strings[number] != NULL)
		number++;

	return number;
}

int StrCompare (const void *string1, const void *string2)
{
	int i = 0, j = 0;
	char *str1 = * (char **) string1;
	char *str2 = * (char **) string2;
	
	while ((str1[i] != '\0') && (str2[j] != '\0'))
	{
		if ((str1[i] != str2[j]) && IsLetter (str1[i]) && IsLetter (str2[j]))
			return (keys.reverse_order == 0) ? str1[i] - str2[j] : str2[j] - str1[i];
		if ((str1[i] == str2[j]) && IsLetter (str1[i]) && IsLetter (str2[j]))
		{
			i++;
			j++;
			continue;
		}
		if (!IsLetter (str1[i]))
			i++;
		if (!IsLetter (str2[j]))
			j++;
	}

	if (str1[i] == '\0')
		return (keys.reverse_order == 0) ? -1 : 1;
	else if (str2[j] == '\0')
		return (keys.reverse_order == 0) ? 1 : -1;
	else
		return 0;
}

int StrCompareFromTheEnd (const void *string1, const void *string2)
{
	int i = 0, j = 0;
	char *str1 = * (char **) string1;
	char *str2 = * (char **) string2;
	int length1 = strlen (str1) - 1;
	int length2 = strlen (str2) - 1;
	
	while ((length1 - i >= 0) && (length2 - i >= 0))
	{
		if ((str1[length1 - i] != str2[length2 - j]) && IsLetter (str1[length1 - i]) && IsLetter (str2[length2 - j]))
			return (keys.reverse_order == 0) ? str1[length1 - i] - str2[length2 - j] : str2[length2 - j] - str1[length1 - i];
		if ((str1[length1 - i] == str2[length2 - j]) && IsLetter (str1[length1 - i]) && IsLetter (str2[length2 - j]))
		{
			i++;
			j++;
			continue;
		}
		if (!IsLetter (str1[length1 - i]))
			i++;
		if (!IsLetter (str2[length2 - j]))
			j++;
	}

	if (length1 - i < 0)
		return (keys.reverse_order == 0) ? -1 : 1;
	else if (length2 - j < 0)
		return (keys.reverse_order == 0) ? 1 : -1;
	else
		return 0;

}

int IsLetter (char c)
{
	if (((c >= 'A') && (c <= 'Z')) || ((c >= 'a') && (c <= 'z')))
		return 1;
	else
		return 0;
}

