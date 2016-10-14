#include <stdio.h>
#include "ts/ts.h"
#include "file_log.h"

void
TSPluginInit(int argc , const char *argv[] )
{
  int i;
  for (i = 0; i < argc; i++)
  {
      DEBUG_INFO("arg %d: %s", i, argv[i]);
	  printf("[stdout] arg %d: %s", i, argv[i]);
  }

  TSPluginRegistrationInfo info;
  info.plugin_name   = "hello-fucking-world";
  info.vendor_name   = "ucloud";
  info.support_email = "enoch.cheng@ucloud.cn";

  if (TSPluginRegister(&info) != TS_SUCCESS) {
    TSError("[hello-world] Plugin registration failed.");
  }
    
  TSError("error-hello,   Hello World!\n");
  TSDebug("debug-hello", "Hello World!\n");
}
