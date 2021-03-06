#include "shell.h"
#include "dbg.h"
#include <stdarg.h>

int Shell_exec(Shell template, ...)
{
  apr_pool_t *p = NULL;
  int rc = -1;
  apr_status_t rv = APR_SUCCESS;
  va_list argp;
  const char *key = NULL;
  const char *arg = NULL;
  int i = 0;

  rv = apr_pool_create(&p, NULL);
  check(rv == APR_SUCCESS, "Failed to create pool");

  va_start(argp, template);

  for(key = va_arg(argp, const char *);
      key != NULL;
      key = va_arg(argp, const char *))
  {
    arg = va_arg(argp, const char *);

    for(i = 0; template.args[i] != NULL; i++) {
      if(strcmp(template.args[i], key) == 0) {
        template.args[i] = arg;
        break; /* found it */
      }
    }
  }

  rc = Shell_run(p, &template);
  apr_pool_destory(p);
  va_end(argp);
  return rc;

error:
  if(p) {
    apr_pool_destroy(p);
  }
  return rc;
}
