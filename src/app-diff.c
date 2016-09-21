#include <stdio.h>
#include "api.h"

int main(int argc, const char *argv[])
{
	printf("NOT IMPLEMENTED YET\n");
	if (argc != 3) {
		return;
	}
	const char *first = argv[1];
	const char *second = argv[2];

	printf("> COMPARING %s %s\n> > Score is %f\n", first, second,
	       diff_score_files(first, second));

	return 0;
}
