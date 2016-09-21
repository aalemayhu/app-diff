// FROM: http://www.fundza.com/c4serious/fileIO_reading_all/

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

char *contents_of(const char *path)
{
	FILE    *infile;
	char    *buffer;
	long    numbytes;

	infile = fopen(path, "r");

	if(infile == NULL)
		return NULL;

	fseek(infile, 0L, SEEK_END);
	numbytes = ftell(infile);

	fseek(infile, 0L, SEEK_SET);

	buffer = (char*)calloc(numbytes, sizeof(char));

	if(buffer == NULL)
		return NULL;

	fread(buffer, sizeof(char), numbytes, infile);
	fclose(infile);

	return buffer;
}

