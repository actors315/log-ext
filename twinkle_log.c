
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_twinkle_log.h"

/* If you declare any globals in php_twinkle_log.h uncomment this:
ZEND_DECLARE_MODULE_GLOBALS(twinkle_log)
*/

/* True global resources - no need for thread safety here */
static int le_twinkle_log;

/* {{{ PHP_INI
 */
/* Remove comments and fill if you need to have entries in php.ini
PHP_INI_BEGIN()
    STD_PHP_INI_ENTRY("twinkle_log.global_value",      "42", PHP_INI_ALL, OnUpdateLong, global_value, zend_twinkle_log_globals, twinkle_log_globals)
    STD_PHP_INI_ENTRY("twinkle_log.global_string", "foobar", PHP_INI_ALL, OnUpdateString, global_string, zend_twinkle_log_globals, twinkle_log_globals)
PHP_INI_END()
*/
/* }}} */

/* Remove the following function when you have successfully modified config.m4
   so that your module can be compiled into PHP, it exists only for testing
   purposes. */

/* Every user-visible function in PHP should document itself in the source */
/* {{{ proto string confirm_twinkle_log_compiled(string arg)
   Return a string to confirm that the module is compiled in */
PHP_FUNCTION(confirm_twinkle_log_compiled)
{
	char *arg = NULL;
	size_t arg_len, len;
	zend_string *strg;

	if (zend_parse_parameters(ZEND_NUM_ARGS(), "s", &arg, &arg_len) == FAILURE) {
		return;
	}

	strg = strpprintf(0, "Congratulations! You have successfully modified ext/%.78s/config.m4. Module %.78s is now compiled into PHP.", "twinkle_log", arg);

	RETURN_STR(strg);
}
/* }}} */
/* The previous line is meant for vim and emacs, so it can correctly fold and
   unfold functions in source code. See the corresponding marks just before
   function definition, where the functions purpose is also documented. Please
   follow this convention for the convenience of others editing your code.
*/


/* {{{ php_twinkle_log_init_globals
 */
/* Uncomment this function if you have INI entries
static void php_twinkle_log_init_globals(zend_twinkle_log_globals *twinkle_log_globals)
{
	twinkle_log_globals->global_value = 0;
	twinkle_log_globals->global_string = NULL;
}
*/
/* }}} */

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(twinkle_log)
{
	/* If you have INI entries, uncomment these lines
	REGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(twinkle_log)
{
	/* uncomment this line if you have INI entries
	UNREGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request start */
/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(twinkle_log)
{
#if defined(COMPILE_DL_TWINKLE_LOG) && defined(ZTS)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request end */
/* {{{ PHP_RSHUTDOWN_FUNCTION
 */
PHP_RSHUTDOWN_FUNCTION(twinkle_log)
{
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(twinkle_log)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "twinkle_log support", "enabled");
	php_info_print_table_end();

	/* Remove comments if you have entries in php.ini
	DISPLAY_INI_ENTRIES();
	*/
}
/* }}} */

/* {{{ twinkle_log_functions[]
 *
 * Every user visible function must have an entry in twinkle_log_functions[].
 */
const zend_function_entry twinkle_log_functions[] = {
	PHP_FE(confirm_twinkle_log_compiled,	NULL)		/* For testing, remove later. */
	PHP_FE_END	/* Must be the last line in twinkle_log_functions[] */
};
/* }}} */

/* {{{ twinkle_log_module_entry
 */
zend_module_entry twinkle_log_module_entry = {
	STANDARD_MODULE_HEADER,
	"twinkle_log",
	twinkle_log_functions,
	PHP_MINIT(twinkle_log),
	PHP_MSHUTDOWN(twinkle_log),
	PHP_RINIT(twinkle_log),		/* Replace with NULL if there's nothing to do at request start */
	PHP_RSHUTDOWN(twinkle_log),	/* Replace with NULL if there's nothing to do at request end */
	PHP_MINFO(twinkle_log),
	PHP_TWINKLE_LOG_VERSION,
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_TWINKLE_LOG
#ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
#endif
ZEND_GET_MODULE(twinkle_log)
#endif

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
