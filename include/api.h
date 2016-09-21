#ifndef _APP_DIFF_H
#define _APP_DIFF_H

#include "io.h"
#include <string.h>

/*
 * Return a score calculated by comparing all characters in $a and $b.
 */
float diff_score(char *a, char *b)
{
	int i;
	int points;
	int a_len = strlen(a);
	int b_len = strlen(b);
	int longest = a_len > b_len ? a_len : b_len;

	points = 0;
	if (a_len == b_len) {
		for (i = 0; i < a_len; i++) {
			if (a[i] == b[i])
				points++;
		}

	} else {
		int shortest = a_len < b_len ? a_len : b_len;
		for (i = 0; i < shortest; i++) {
			if (a[i] == b[i])
				points++;
		}
	}

	return (float)points / (float)longest * 100;
}

/*
 * Return a score by comparing two files
 */
float diff_score_files(char *first_path, char *second_path)
{
	char *first_content = contents_of(first_path);
	char *second_content = contents_of(second_path);
	float score = diff_score(first_content, second_content);
	free(first_content);
	free(second_content);
	return score;
}

#endif /* _APP_DIFF_H */
