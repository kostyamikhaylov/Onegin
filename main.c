#include "Onegin.h"
#include <stdio.h>
#include <unistd.h>


struct Keys keys = {0, 0, 0, 0, 0, 0};

int main (int argc, char *argv[])
{
	int files[] = {0, 0}; 
	char **strings_ptr = NULL;

	GetKeys (argv);

	if (keys.help == 1)
	{
		Help ();
		return 0;
	}

	GetFileNames (files, argc, argv);

	strings_ptr = ReadStrings (files[0]);

	if (keys.no_changes == 0)
	{
		strings_ptr = SortStrings (strings_ptr);
	}
	
	PrintStrings (strings_ptr, files[1]);

	FreeStrings (strings_ptr);
	
	close (files[0]);
	close (files[1]);
	return 0;
}

