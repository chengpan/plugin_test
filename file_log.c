#include<stdio.h>
#include<string.h>
#include<stdarg.h>
#include<stdlib.h>
#include "file_log.h"

int log2file(const char *fmt, ...)
{
    static FILE *fp = NULL;
    if (!fp)
    {
        fp = fopen(LOGFILE_PATH, "a");
        if (!fp)
        {
            perror("open log file failed");
            exit(1);
        }
    }

    int cnt;
    va_list argptr;
    va_start(argptr, fmt);
    cnt = vfprintf(fp, fmt, argptr);
    va_end(argptr);
    fflush(fp);
    return cnt;
}
