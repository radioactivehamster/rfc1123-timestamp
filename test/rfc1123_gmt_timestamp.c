#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include <check.h>

#include "../include/rfc1123_gmt_timestamp.h"
#include "./include/stdlib_rfc1123_gmt_timestamp.h"

// ------------------------------------------------------------

START_TEST(test_rfc1123_gmt_timestamp)
{
    time_t t = time(NULL);

    if (t == (time_t)(-1)) {
        fprintf(stderr, "Unable to make time via `time_t`!\n");
        exit(EXIT_FAILURE);
    }

    char stdlib_buf[RFC1123_GMT_SIZE] = {0};
    char rfc1123_buf[RFC1123_GMT_SIZE] = {0};

    stdlib_rfc1123_gmt_timestamp(stdlib_buf, &t);
    rfc1123_gmt_timestamp(rfc1123_buf, &t);
    ck_assert_str_eq(stdlib_buf, rfc1123_buf);
}
END_TEST

// ------------------------------------------------------------

Suite *rfc1123_gmt_timestamp_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("rfc1123_gmt_timestamp");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_rfc1123_gmt_timestamp);
    suite_add_tcase(s, tc_core);

    return s;
}

// ------------------------------------------------------------

int main(void)
{
    int num_failed;
    Suite *s;
    SRunner *sr;

    s = rfc1123_gmt_timestamp_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    num_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (num_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
