/*
 * Copyright (C) 2016 Red Hat, Inc.
 *
 * udrm is free software; you can redistribute it and/or modify it under
 * the terms of the GNU Lesser General Public License as published by the
 * Free Software Foundation; either version 2.1 of the License, or (at
 * your option) any later version.
 */

#define _GNU_SOURCE
#include <stdlib.h>
#include "test.h"

#include "api.h"

void verbose_assert(float expected, float actual) {
	printf("comparing %f with %f \n", expected, actual);
	assert(expected == actual);
}

static void test_score_single_word(void)
{
	printf("test_score_single_word()\n");
	float expected = 83.333328;
	float actual = diff_score("import", "impors");
	verbose_assert(expected, actual);
}

int test_score_multiple_words()
{
	printf("test_score_multiple_words()\n");
	float expected = 100;
	float actual = diff_score("one two", "one two");
	verbose_assert(expected, actual);

	return TEST_OK;
}

int test_api(void)
{
	test_score_single_word();
	test_score_multiple_words();

	return TEST_OK;
}

// TODO: test multiple lines
// TODO: test using files
// TODO: test using directories
// TODO: test different character encodings
// TODO: test different words
