###
```c++
 struct _finddata_t 
        { 
             unsigned attrib; 
             time_t time_create; 
             time_t time_access; 
             time_t time_write; 
             _fsize_t size; 
             char name[_MAX_FNAME]; 
        };
```

tm

```c++
struct tm {
                  int tm_sec;         /* seconds */
                  int tm_min;         /* minutes */
                  int tm_hour;        /* hours */
                  int tm_mday;        /* day of the month */
                  int tm_mon;         /* month */
                  int tm_year;        /* year */
                  int tm_wday;        /* day of the week */
                  int tm_yday;        /* day in the year */
                  int tm_isdst;       /* daylight saving time */

              };

       tm_sec The  number of seconds after the minute, normally in the range 0 to 59, but can be up to 60 to allow for leap seconds.

       tm_min The number of minutes after the hour, in the range 0 to 59.

       tm_hour
              The number of hours past midnight, in the range 0 to 23.

       tm_mday
              The day of the month, in the range 1 to 31.

       tm_mon The number of months since January, in the range 0 to 11.

       tm_year
              The number of years since 1900.

       tm_wday
              The number of days since Sunday, in the range 0 to 6.

       tm_yday
              The number of days since January 1, in the range 0 to 365.

       tm_isdst
              A flag that indicates whether daylight saving time is in effect at the  time  described. The value is positive if daylight saving time is in effect, zero if it is not, and negative if the information is not available.
```