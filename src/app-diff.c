#define _GNU_SOURCE
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdbool.h>

#include "api.h"

void print_comparison(const char *first, const char *second);
void compare_files_in_directory(const char *path);
void compare_files(const char *argv[]);

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

bool is_directory(char *path)
{
	struct stat s;

	if (0 > stat(path, &s))
		perror("stat");

	if (s.st_mode & S_IFDIR)
		return true;
	else if (s.st_mode & S_IFREG)
		return false;

	return false;
}

void compare_files_in_directory(const char *path)
{
	printf("%s\n", __func__);
	char **files;
	size_t count;
	int i, j;

	count = file_list(path, &files);

	printf("> %ld\n", count);

	for (i = 0; i < count; i++) {
		for (j = 0; j < count; j++) {
			char *first, *second;

			asprintf(&first, "%s/%s", path, files[i]);
			asprintf(&second, "%s/%s", path, files[j]);
			if (is_directory(first) || is_directory(second))
				goto cleanup;

			if (strcmp(first, second))
				print_comparison(first, second);
cleanup:
			free(first);
			free(second);
		}
	}
	free(files);
}
