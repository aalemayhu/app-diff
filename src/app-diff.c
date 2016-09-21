#include <stdio.h>
#include <dirent.h>
#include "api.h"

void compare_files(const char *argv[]);
void compare_files_in_current_directory();

int main(int argc, const char *argv[])
{
	switch(argc) {
	case 1:
		compare_files_in_current_directory(".");
		break;
	case 2:
		compare_files_in_current_directory(argv[1]);
		break;
	case 3:

		compare_files(argv);
		break;
	}

	return EXIT_SUCCESS;
}

void compare_files(const char *argv[])
{
	const char *first = argv[1];
	const char *second = argv[2];

	printf("> COMPARING %s %s\n> > Score is %f\n", first, second,
	       diff_score_files(first, second));
}

void compare_files_in_current_directory(char *path)
{
		printf("NOT IMPLEMENTED YET\n");
}
