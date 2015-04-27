#ifndef RFC1123_GMT_TIMESTAMP_H
#define RFC1123_GMT_TIMESTAMP_H

#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

//! This maximum number of characters in an RFC1123 date is 29 + 1 for '\0'.
enum { RFC1123_GMT_LEN = 29, RFC1123_GMT_SIZE };

static inline int rfc1123_gmt_timestamp(char *restrict dest, const time_t *restrict timer)
{
    struct tm *timeptr;

    memset(dest, 0, RFC1123_GMT_SIZE);

    if (timer == NULL || *timer == (time_t)(-1)) return -1;

    timeptr = gmtime(timer);

    const char *format = "%a, %d %b %Y %T GMT";
    size_t dlen = strftime(dest, RFC1123_GMT_SIZE, format, timeptr);

    return (dlen <= INT_MAX) ? (int)dlen : -1;
}

#endif /* !RFC1123_GMT_TIMESTAMP_H */
