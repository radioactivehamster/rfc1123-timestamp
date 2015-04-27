### NAME

`rfc1123_gmt_timestamp` – creates an RFC 1123 GMT formatted timestamp

### SYNOPSIS

```c
#include <rfc1123_gmt_timestamp.h>

enum RFC1123_GMT_LEN, RFC1123_GMT_SIZE;

static inline int
rfc1123_gmt_timestamp(char *restrict dest, const time_t *restrict timer);
```

### DESCRIPTION

The `rfc1123_gmt_timestamp()` function takes a pointer to timer and formats it as a string via `%a, %d %b %Y %T GMT` which is then stored in the dest buffer.

### RETURN VALUES

Upon successful completion, the value of `RFC1123_GMT_LEN` is returned; otherwise the value `0` is returned to indicate the error.

### EXAMPLES

The following code gets the current Unix time and creates a RFC 1123 GMT formatted timestamp string.

```c
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

    printf("%.*s\n", RFC1123_GMT_LEN, ts);
}
```

### SEE ALSO

- Braden, R., Ed., "Requirements for Internet Hosts - Application and Support", STD 3, RFC 1123, October 1989, <<http://www.rfc-editor.org/info/rfc1123>>.

- Crocker, D., "Standard for the Format of ARPA Internet Text Messages", STD 11, RFC 822, August 1982, <<http://www.rfc-editor.org/info/rfc822>>.

### STANDARDS

Conforms to IETF RFCs:

__"RFC-822 Date and Time Specification: RFC-822 Section 5"__ (RFC 1123 § 5.2.14)

_(In regards to the syntax previously defined in RFC-822 § 5.1)_
> The syntax for the date is hereby changed to:

```
date = 1*2DIGIT month 2*4DIGIT
```

__"Syntax"__ (RFC 822 § 5.1)

```
date-time   =  [ day "," ] date time          ; dd mm yy
                                              ;   hh:mm:ss zzz
                                                                                         
day         =  "Mon"  / "Tue" /  "Wed"  / "Thu" 
            /  "Fri"  / "Sat" /  "Sun"
   
date        =  1*2DIGIT month 2DIGIT          ; day month year
                                              ;   e.g. 20 Jun 82
                                                 
month       =  "Jan"  /  "Feb" /  "Mar"  /  "Apr"
            /  "May"  /  "Jun" /  "Jul"  /  "Aug"
            /  "Sep"  /  "Oct" /  "Nov"  /  "Dec"

time        =  hour zone                      ; ANSI and Military
   
hour        =  2DIGIT ":" 2DIGIT [":" 2DIGIT] ; 00:00:00 - 23:59:59
   
zone        =  "UT"  / "GMT"                  ; Universal Time
                                              ; North American : UT
            /  "EST" / "EDT"                  ;   Eastern:  - 5/ - 4
            /  "CST" / "CDT"                  ;   Central:  - 6/ - 5
            /  "MST" / "MDT"                  ;   Mountain: - 7/ - 6
            /  "PST" / "PDT"                  ;   Pacific:  - 8/ - 7
            /  1ALPHA                         ; Military: Z = UT;
                                              ;   A:-1; (J not used)
                                              ;   M:-12; N:+1; Y:+12
            / ( ("+" / "-") 4DIGIT )          ; Local differential
                                              ;   hours+min. (HHMM)
```

__"Semantics"__ (RFC 822 § 5.2)

> If included, day-of-week must be the day implied by the date specification.
> Time zone may be indicated in several ways. "UT" is Universal Time (formerly
> called "Greenwich Mean Time"); "GMT" is permitted as a reference to Universal
> Time. The military standard uses a single character for each zone. "Z" is
> Universal Time. "A" indicates one hour earlier, and "M" indicates 12 hours
> earlier; "N" is one hour later, and "Y" is 12 hours later. The letter "J" is
> not used. The other remaining two forms are taken from ANSI standard
> X3.51-1975. One allows explicit indication of the amount of offset from UT;
> the other uses common 3-character strings for indicating time zones in North
> America.

### AUTHORS

Benner, James <<http://radioactivehamster.com>>
