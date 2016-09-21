// FROM: http://www.fundza.com/c4serious/fileIO_reading_all/

#include <dirent.h>
#include <malloc.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

// FROM: http://stackoverflow.com/questions/11291154/save-file-listing-into-array-or-something-else-c
size_t file_list(const char *path, char ***ls) {
    size_t count = 0;
    size_t length = 0;
    DIR *dp = NULL;
    struct dirent *ep = NULL;

    dp = opendir(path);
    if(NULL == dp) {
        fprintf(stderr, "no such directory: '%s'", path);
        return 0;
    }

    *ls = NULL;
    ep = readdir(dp);
    while(NULL != ep){
        count++;
        ep = readdir(dp);
    }

    rewinddir(dp);
    *ls = calloc(count, sizeof(char *));

    count = 0;
    ep = readdir(dp);
    while(NULL != ep){
	    if(strcmp(ep->d_name, ".")
	       && strcmp(ep->d_name, ".."))
	    {
		    (*ls)[count++] = strdup(ep->d_name);
	    }
        ep = readdir(dp);
    }

    closedir(dp);
    return count;
}

