#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "rfc1123_gmt_timestamp.h"

int main(void)
{
    char ts[RFC1123_GMT_SIZE] = {0};
    int tslen;
    time_t t = time(NULL);

    if (t == (time_t)(-1)) {
        /** Error handling would go here... */
        exit(EXIT_FAILURE);
    }

    tslen = rfc1123_gmt_timestamp(ts, &t);

    if (tslen != RFC1123_GMT_LEN) {
        /** Error handling would go here... */
        exit(EXIT_FAILURE);
    }

    printf("%.*s\\n", RFC1123_GMT_LEN, ts);
}
