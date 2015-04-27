#ifndef RFC1123_GMT_TIMESTAMP_H
#define RFC1123_GMT_TIMESTAMP_H

#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

//! Hey, guess what? `#define`s are formally called "Symbolic Constants" (or "Symbolic Names") according to K&R
//! <http://www.mla.org/style/handbook_faq/cite_an_ebook>
//!
//!<  Kernighan, Brian W., and Dennis Ritchie. "Symbolic Constants"
//!<  _The C Programming Language_. 2nd ed.
//!<  1988. Murray Hill: Prentice Hall, 2012. (ch. 1, sec. 4). Kindle file.

//!<  §1.4 Symbolic Constants.

//! This maximum number of characters in an RFC1123 date is 29 + 1 for '\0'.
enum { RFC1123_GMT_LEN = 29, RFC1123_GMT_SIZE };

//!< If `timer` is provided a nullptr then we automatically supply "now" for our time
static inline int rfc1123_gmt_timestamp(char *restrict dest, const time_t *restrict timer)
{
    struct tm *timeptr;
    time_t now;

    /**
     * All four of these conditions are equivelent. For reference the `NULL`
     * variant is used in K&R.
     *
     *   `if (timer == '\0' && timer == 0 && timer == NULL && !timer) printf("!!!0!!!\n");`
     *
     * This fails though, it probably requires a `static_assert`.
     *
     *   `assert(timer == 0);`
     */

    //! Nullptr so zero terminate the dest and return
    //if (timer == NULL) {
    //    dest[0] = '\0';
    //    return 0;
    //}

    memset(dest, 0, RFC1123_GMT_SIZE);

    //if (*timer == (time_t)(-1)) return 0;

    if (timer == NULL) {
        //return -1;
        now = time(NULL);
        printf("%ld\n", now);
        //return 1;
        if (now == (time_t)(-1)) fprintf(stderr, "Danger Will Robinson!!!!\n");
        timeptr = gmtime(&now);
    } else {
        timeptr = gmtime(timer);
    }

    //struct tm *tdata = (timer == NULL) ? gmtime(&now) : gmtime(timer);

    //struct tm *tdata = gmtime(&now);

    //printf("[.tm_mon] %d\n", tdata->tm_mon);
    //return 2;

    //return 0;

    //! Verify if `timer` is a nullptr before checking `(time_t)(-1)` otherwise
    //! you will probably get segfaults.
    if (*timer == (time_t)(-1)) return 0;

    //if (timeptr == NULL) return 0;

    const char *format = "%a, %d %b %Y %T GMT";
    size_t dlen = strftime(dest, RFC1123_GMT_SIZE, format, timeptr);

    return (dlen <= INT_MAX) ? (int)dlen : -1;
}

#endif /* !RFC1123_GMT_TIMESTAMP_H */

//!<  Normative References
//!<  ====================
//!< [RFC1123] "Requirements for Internet Hosts - Application and Support",
//!<           IETF Host Requirements Working Group, R. Braden, Ed.,
//!<           RFC-1122, October 1989.

//! [1] R. Braden, Ed., "Requirements for Internet Hosts - Application and Support
//!     -- RFC-822 Date and Time Specification", STD 3, RFC 1123 §5.2.14, October 1989

    //!< RFC 1123§5.2.14 RFC-822 Date and Time Specification: RFC-822 Section 5

//! [RFC1123] Braden, R., Ed., "Requirements for Internet Hosts - Application and
//!           Support", STD 3, RFC 1123, October 1989,
//!           <http://www.rfc-editor.org/info/rfc1123>.

/**
 * @link https://www.rfc-editor.org/rfc-style-guide/style.txt
 *
 * * When citing a document, the reference tag should not contain spaces.

	Example
	[RFC 2119] should appear as [RFC2119]

* However, when referencing a document within the text (not
using it as a tagged citation), it should appear with a space.

	Example
	"See RFC 2119 [BCP14] for more information".
 *
 * ====================
 *
 * 6. References
 *
 *        3. "The Elements of Style" by Strunk & White (4th Ed., 2000)
 *        4. "A Pocket Style Manual" by Diana Hacker (4th Ed., 2004)
 *        8. Merriam Webster Online (www.merriamwebster.com) --
 *           preferred dictionary
 */
