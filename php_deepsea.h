/*
  +----------------------------------------------------------------------+
  | PHP Version 7                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2016 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author:                                                              |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifndef PHP_DEEPSEA_H
#define PHP_DEEPSEA_H

extern zend_module_entry deepsea_module_entry;
#define phpext_deepsea_ptr &deepsea_module_entry

#define PHP_DEEPSEA_VERSION "0.1.0" /* Replace with version number for your extension */



#ifdef ZTS
#	include "TSRM.h"
#endif
#include <ext/standard/info.h>
#include <ext/standard/base64.h>
#include <ext/standard/basic_functions.h>
#include <ext/standard/php_var.h>
#include <ext/standard/php_smart_string.h>
#include <Zend/zend_extensions.h>
#include <Zend/zend_hash.h>
#include <Zend/zend_interfaces.h>
#include <Zend/zend_smart_str.h>
#ifdef __cplusplus
} /* extern "C" */
#endif

extern zend_module_entry deepsea_module_entry;

#define DEEP_STARTUP_FUNCTION(module)   	ZEND_MINIT_FUNCTION(deep_##module)
#define DEEP_RINIT_FUNCTION(module)		ZEND_RINIT_FUNCTION(deep_##module)
#define DEEP_STARTUP(module)	 		  	ZEND_MODULE_STARTUP_N(deep_##module)(INIT_FUNC_ARGS_PASSTHRU)
#define DEEP_SHUTDOWN_FUNCTION(module)  	ZEND_MSHUTDOWN_FUNCTION(deep_##module)
#define DEEP_SHUTDOWN(module)	 	    	ZEND_MODULE_SHUTDOWN_N(deep_##module)(INIT_FUNC_ARGS_PASSTHRU)


#ifdef PHP_WIN32
#	define PHP_DEEPSEA_API __declspec(dllexport)
#elif defined(__GNUC__) && __GNUC__ >= 4
#	define PHP_DEEPSEA_API __attribute__ ((visibility("default")))
#else
#	define PHP_DEEPSEA_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

/*
  	Declare any global variables you may need between the BEGIN
	and END macros here:
/*/
ZEND_BEGIN_MODULE_GLOBALS(deepsea)
	zend_long  global_value;
	char *global_string;
ZEND_END_MODULE_GLOBALS(deepsea)


extern ZEND_DECLARE_MODULE_GLOBALS(deepsea);

/* Always refer to the globals in your function as DEEPSEA_G(variable).
   You are encouraged to rename these macros something shorter, see
   examples in any other php module directory.
*/
#define DEEPSEA_G(v) ZEND_MODULE_GLOBALS_ACCESSOR(deepsea, v)

#if defined(ZTS) && defined(COMPILE_DL_DEEPSEA)
ZEND_TSRMLS_CACHE_EXTERN()
#endif

#endif	/* PHP_DEEPSEA_H */


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
