#include "api.h"

void compare_files(const char *argv[]);
void compare_files_in_directory(const char *path);
void print_comparison(const char *first, const char *second);

int main(int argc, const char *argv[])
{
	switch(argc) {
	case 1:
		compare_files_in_directory(".");
		break;
	case 2:
		compare_files_in_directory(argv[1]);
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
	print_comparison(first, second);
}

void print_comparison(const char *first, const char *second)
{
	printf(">> %f: %s %s\n",
	       diff_score_files(first, second),
	       first, second);
}

void compare_files_in_directory(const char *path)
{
	char **files;
	size_t count;
	int i, j;

	count = file_list(path, &files);

	printf("> %ld\n", count);

	for (i = 0; i < count; i++) {
		for (j = 0; j < count; j++) {
			char *first, *second;
			asprintf(&first, "%s%s", path, files[i]);
			asprintf(&second, "%s%s", path, files[j]);
			if ((!first && !second) && strcmp(first, second))
				print_comparison(first, second);
			free(first);
			free(second);
		}
	}
	free(files);
}
