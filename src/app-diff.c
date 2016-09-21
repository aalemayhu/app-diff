#include <stdio.h>
#include "api.h"

void compare_files(const char *argv);

int main(int argc, const char *argv[])
{
	printf("NOT IMPLEMENTED YET\n");
	if (argc == 3) {
		compare_files(argv);
	}

	return 0;
}

void compare_files(const char *argv)
{
	const char *first = argv[1];
	const char *second = argv[2];

	printf("> COMPARING %s %s\n> > Score is %f\n", first, second,
	       diff_score_files(first, second));
}
