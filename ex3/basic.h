#ifndef basic_h
#define basic_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TRUE 1
#define MAXBUF 1024

enum ErrorCode {
    TooMany,
    TooLess,
    Unknown,
    Duplicate
};

#endif /* basic */
