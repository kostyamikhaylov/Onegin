#include <stdio.h>
#include <stdlib.h>

#define ASSERT(CONDITION) 																	\
	if(!(CONDITION))																		\
	{																						\
		fprintf (stderr, "Assertation failed, file %s, function %s, line %d\n",				\
				__FILE__, __PRETTY_FUNCTION__, __LINE__);									\
		exit (EXIT_SUCCESS);																\
	}

/*
В структуре содержатся все ключи, которые может обрабатывать программа
-n высавление порядкового номера при выводе строки (не изначального!)
-s вывод строк без сортировки
-r вывести строки в обратном порядке
-e сортировать по концу строки
-t добавить вывод в stdout
-h запустить функцию Help () (в ней ничего нет, мне лень было писать)

Ключи после считывания из параметров командной строки попадают в глобальную структуру keys.
-h и -s обрабатываются в main;
-t и -n обрабатываются в PrintStrings;
-r и -e -- в SortStrings;
*/

struct Keys
{
	int enumerate;			// -n
	int no_changes;			// -s
	int reverse_order;		// -r
	int from_the_end;		// -e
	int std_output;			// -t
	int help;			// -h
};

void GetKeys (char **argv);
void Help (void);
void GetFileNames (int *file_descriptors, const int argc, char **argv);
char **ReadStrings (int fd);
char **SortStrings (char **strings);
void PrintStrings (char **strings, int fd);
void FreeStrings (char **strings);
long int StringsNumber (char **strings);

