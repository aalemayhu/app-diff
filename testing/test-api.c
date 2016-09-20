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

static void test_score_singe_word(void)
{
	float expected = 83.333328;
	float actual = diff_score("import", "impors");

	printf("comparing %f with %f \n", expected, actual);
	assert(expected == actual);
}

int test_api(void)
{
	test_score_singe_word();

	return TEST_OK;
}
