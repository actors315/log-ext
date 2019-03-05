
#ifndef PHP_TWINKLE_LOG_H
#define PHP_TWINKLE_LOG_H

extern zend_module_entry twinkle_log_module_entry;
#define phpext_twinkle_log_ptr &twinkle_log_module_entry

#define PHP_TWINKLE_LOG_VERSION "0.1.0" /* Replace with version number for your extension */

#ifdef PHP_WIN32
#	define PHP_TWINKLE_LOG_API __declspec(dllexport)
#elif defined(__GNUC__) && __GNUC__ >= 4
#	define PHP_TWINKLE_LOG_API __attribute__ ((visibility("default")))
#else
#	define PHP_TWINKLE_LOG_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

/*
  	Declare any global variables you may need between the BEGIN
	and END macros here:

ZEND_BEGIN_MODULE_GLOBALS(twinkle_log)
	zend_long  global_value;
	char *global_string;
ZEND_END_MODULE_GLOBALS(twinkle_log)
*/

/* Always refer to the globals in your function as TWINKLE_LOG_G(variable).
   You are encouraged to rename these macros something shorter, see
   examples in any other php module directory.
*/
#define TWINKLE_LOG_G(v) ZEND_MODULE_GLOBALS_ACCESSOR(twinkle_log, v)

#if defined(ZTS) && defined(COMPILE_DL_TWINKLE_LOG)
ZEND_TSRMLS_CACHE_EXTERN()
#endif

#endif	/* PHP_TWINKLE_LOG_H */

