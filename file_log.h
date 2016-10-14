#ifndef __LOG2FILE_H_
#define __LOG2FILE_H_

#include <errno.h>

//change USE_DEBUG to 0 if you want to close logging
#define USE_DEBUG 1
extern int log2file(const char *format, ...);
#define LOGFILE_PATH "/tmp/ats620_debug.log"

#if USE_DEBUG
#define DEBUG_LINE() log2file("[%s:%s] line=%d\r\n",__FILE__, __func__, __LINE__)
#define DEBUG_ERR(fmt, args...) log2file("\033[46;31m[%s:%d]\033[0m "#fmt" errno=%d, %m\r\n", __func__, __LINE__, ##args, errno, errno)
#define DEBUG_INFO(fmt, args...) log2file("\033[33m[%s:%d]\033[0m "#fmt"\r\n", __func__, __LINE__, ##args)
#else
#define DEBUG_LINE() do{}while(0)
#define DEBUG_ERR(fmt, ...) do{}while(0)
#define DEBUG_INFO(fmt, ...) do{}while(0)
#endif

#endif
