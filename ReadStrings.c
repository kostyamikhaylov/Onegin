#include "Onegin.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

/*
Сначала расчитывает длину файла (функция GetFileSize), выделяет нужное количество памяти,
считывает всё подряд в ОДИН выделенный массив. Затем (уже в MarkLines) в этом массиве считается количество строк,
заказывается соответствующий массив для указателей на начала сторок,
эти указатели записываются, после последнего идёт NULL, а после NULL'я дублируется адрес начала первой строки
(иначе в процессе сортировки эта первая строка затеряется, а чистить память как-то надо будет)
*/


long int GetFileSize (int fd);
char **MarkLines (char *text, char symb);

char **ReadStrings (int fd)
{
	long int text_size = 0;
	char *text = NULL;

	ASSERT (fd >= 0);

	text_size = GetFileSize (fd);
	text = (char *) calloc (text_size + 1, sizeof (*text));
	lseek (fd, 0, SEEK_SET);
	read (fd, text, text_size);
	text[text_size] = '\0';
	
	return MarkLines (text, '\n');	
}

long int GetFileSize (int fd)
{
	long int bgng = 0, end = 0;

	ASSERT (fd >= 0);
	
	bgng = lseek (fd, 0, SEEK_SET);
	end = lseek (fd, 0, SEEK_END);
	
	return end - bgng;
}

char **MarkLines (char *text, char symb)
{
	long int i = 0, line = 0;
	long int lines_number = 1;
	char **strings = NULL;
	
	ASSERT (text);

	while (text[i] != '\0')
	{
		if (text[i] == symb)
			lines_number++;
		i++;
	}

	strings = (char **) calloc (lines_number + 2, sizeof (*strings));
	
	strings[0] = text;
	i = 1;
	line = 1;
	while (text[i] != '\0')
	{
		if (text[i - 1] == symb)
		{
			strings[line] = text + i;
			text[i - 1] = '\0';
			line++;
		}
		i++;
	}
	strings[line] = NULL;
	strings[line + 1] = text;

	return strings;
}

