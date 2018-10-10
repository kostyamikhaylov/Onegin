#include "Onegin.h"
#include <stdio.h>
#include <stdlib.h>

/*
typedef struct Keys
{
	int enumerate;			// -n
	int no_changes;			// -s
	int reverse_order;		// -r
	int from_the_end;		// -e
	int std_output;			// -t
	int help;			// -h
};

GeKeys принимает аргументы командной строки из мэйна и считывает ключи
(только те, которые идут сразу после названия программы, до текстовых файлов)
За что отвечают ключи написано в Onegin.h
*/

extern struct Keys keys;

void SetKeys (const char *str);

void GetKeys (char **argv)
{
	int param_number = 1;

	while (argv[param_number] != NULL)
	{
		if (argv[param_number][0] != '-')
			break;
		SetKeys (argv[param_number]);
		param_number++;
	}
}

void SetKeys (const char *str)
{
	int i = 1;

	while (str[i] != '\0')
	{
		switch (str[i])
		{
			case 'n':
				keys.enumerate = 1;
				break;
			case 's':
				keys.no_changes = 1;
				break;
			case 'r':
				keys.reverse_order = 1;
				break;
			case 'e':
				keys.from_the_end = 1;
				break;
			case 't':
				keys.std_output = 1;
				break;
			case 'h':
				keys.help = 1;
				break;
			default:
				fprintf (stderr, "Unknown key '%c' from the parameter %s\n", str[i], str);
				exit (EXIT_FAILURE);
				break;
		}
		i++;
	}
}

