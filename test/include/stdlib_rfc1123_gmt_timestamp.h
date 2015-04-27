#include <time.h>

char *stdlib_rfc1123_gmt_timestamp(char *restrict buf, const time_t *restrict t)
{
    const char *fmt = "%a, %d %b %Y %T GMT";
    strftime(buf, 30, fmt, gmtime(t));

    return buf;
}
