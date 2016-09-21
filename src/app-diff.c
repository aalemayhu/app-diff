#include <stdio.h>
#include "api.h"

void compare_files(const char *argv);

int main(int argc, const char *argv[])
{
	if (argc == 3) {
		compare_files(argv);
	} else {
		compare_files_in_current_directory();
	}

	return EXIT_SUCCESS;
}

void compare_files(const char *argv)
{
	const char *first = argv[1];
	const char *second = argv[2];

	printf("> COMPARING %s %s\n> > Score is %f\n", first, second,
	       diff_score_files(first, second));
}

void compare_files_in_current_directory()
{
		printf("NOT IMPLEMENTED YET\n");
}
