#include "Onegin.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


extern struct Keys keys;

void PrintStrings (char **strings, int fd)
{
	long int i = 0;

	ASSERT (strings);
	ASSERT (fd >= 0);

	if (keys.enumerate == 1)
	{
		if (keys.std_output == 1)
		{
			while (strings[i] != NULL)
			{
				printf ("%ld%c %s\n", i + 1, ')', strings[i]);
				i++;
			}
		}
		else
		{
			while (strings[i] != NULL)
			{
				dprintf (fd, "%ld%c %s\n", i + 1, ')', strings[i]);
				i++;
			}
		}
	}
	else
	{
		if (keys.std_output == 1)
		{	
			while (strings[i] != NULL)
			{
				printf ("%s\n", strings[i]);
				i++;
			}
		}
		else
		{
			while (strings[i] != NULL)
			{
				dprintf (fd, "%s\n", strings[i]);
				i++;
			}
		}
	}
}

