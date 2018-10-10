#include "Onegin.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/*
Открывает файлы для чтения (всегда, если не указан, выдаётся ошибка)
и для записи (является необязательным, если указан ключ -t,
однако если файл всё же указан, то и в него тоже).
Если файла для записи с данным именем нет, то создаёт,
если есть - то чистит.
*/


int OpenRd (const char *path);
int OpenWr (const char *path);

void GetFileNames (int *file_descriptors, const int argc, char **argv)
{
	int param_number = 0;
	int got_file_to_read = 0;
	int got_file_to_write = 0;

	for (param_number = 1; param_number < argc; param_number++)
	{
		if (argv[param_number][0] == '-')
			continue;
		else if (got_file_to_read == 0)
		{
			file_descriptors[0] = OpenRd (argv[param_number]);
			got_file_to_read = 1;
		}
		else if (got_file_to_write == 0)
		{
			file_descriptors[1] = OpenWr (argv[param_number]);
			got_file_to_write = 1;
		}
		else 
		{
			fprintf (stderr, "Usage: <prog_name>  .../keys/...  <file_to_read>  <file_to_write>\nFor more information refer to help (\"-h\" key)\n");
			exit (EXIT_FAILURE);
		}
	}

	if ((got_file_to_read == 0) || (got_file_to_read == 0))
	{
		fprintf (stderr, "Usage: <prog_name>  .../keys/...  <file_to_read>  <file_to_write>\nFor more information refer to help (\"-h\" key)\n");
		exit (EXIT_FAILURE);
	}
}

int OpenRd (const char *path)
{
	int fd = 0;
	fd = open (path, O_RDONLY);
	if (fd < 0)
	{
		fprintf (stderr, "Can't open file %s for reading\n", path);
		exit (EXIT_FAILURE);
	}
	return fd;
}

int OpenWr (const char *path)
{
	int fd = 0;
	fd = open (path, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (fd < 0)
	{
		fprintf (stderr, "Can't open file %s for writing\n", path);
		exit (EXIT_FAILURE);
	}
	return fd;
}

