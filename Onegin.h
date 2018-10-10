#include <stdio.h>
#include <stdlib.h>

#define ASSERT(CONDITION) 																	\
	if(!(CONDITION))																		\
	{																						\
		fprintf (stderr, "Assertation failed, file %s, function %s, line %d\n",				\
				__FILE__, __PRETTY_FUNCTION__, __LINE__);									\
		exit (EXIT_SUCCESS);																\
	}


struct Keys
{
	int enumerate;			// -n
	int no_changes;			// -s
	int reverse_order;		// -r
	int from_the_end;		// -e
	int std_output;			// -t
	int help;				// -h
};

void GetKeys (char **argv);
void Help (void);
void GetFileNames (int *file_descriptors, const int argc, char **argv);
char **ReadStrings (int fd);
char **SortStrings (char **strings);
void PrintStrings (char **strings, int fd);
void FreeStrings (char **strings);
long int StringsNumber (char **strings);

