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
	printf("%s\n", __func__);
	printf("comparing %f with %f \n", expected, actual);
	assert(expected == actual);
}

static void test_score_single_word(void)
{
	printf("%s\n", __func__);
	float expected = 83.333328;
	float actual = diff_score("import", "impors");
	verbose_assert(expected, actual);
}

int test_score_multiple_words()
{
	printf("%s\n", __func__);
	verbose_assert(100, diff_score("one two", "one two"));
	verbose_assert(55.555557, diff_score("real tech", "real cars"));

	assert(diff_score("1 2 3 4", "1 2 3") > 50);

	return TEST_OK;
}

int test_score_files()
{
	printf("%s\n", __func__);
	char *test_file = "testing/data/hello.swift";
	assert(diff_score_files(test_file, test_file) == 100);
	assert(diff_score_files(test_file, "testing/data/hello.c") != 100);

	return TEST_OK;
}

int test_api(void)
{
	printf("%s\n", __func__);
	test_score_single_word();
	test_score_multiple_words();
	test_score_files();
	return TEST_OK;
}

// TODO: test multiple lines
// TODO: test using directories
// TODO: test different character encodings
// TODO: test different words
