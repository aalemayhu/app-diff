#ifndef _APP_DIFF_H
#define _APP_DIFF_H

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

	}

	return (float)points / (float)longest * 100;
}

#endif /* _APP_DIFF_H */
