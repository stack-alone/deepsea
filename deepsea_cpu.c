#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>
#include <php_ini.h>
#include <SAPI.h>
#include "Zend/zend_interfaces.h"
#include "php_deepsea.h"
#include "deepsea_cpu.h"




zend_class_entry *deepsea_cpu_ce;



PHP_METHOD(DS_CPU,getMemory) {

}


PHP_METHOD(DS_CPU,getCompany) {

}

PHP_METHOD(DS_CPU,getModel) {

}

PHP_METHOD(DS_CPU,getkernelInfo) {

}


/** {{{ alone_config_methods
*/
zend_function_entry deepsea_cpu_methods[] = {
	PHP_ME(DS_CPU, getMemory, NULL, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC )
//	PHP_ME(DS_CPU, getCompany, NULL, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC )
//	PHP_ME(DS_CPU, getModel, NULL, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC )
//	PHP_ME(DS_CPU, getkernelInfo, NULL, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC )
	{NULL, NULL, NULL}
};
/* }}} */



/** {{{ deepsea_STARTUP_FUNCTION
*/
DEEP_STARTUP_FUNCTION(deepsea) {

	zend_class_entry ce;
	INIT_CLASS_ENTRY(ce, "DS_CPU", deepsea_cpu_methods);
	deepsea_cpu_ce = zend_register_internal_class_ex(&ce, NULL);
	deepsea_cpu_ce->ce_flags |= ZEND_ACC_FINAL;


	return SUCCESS;
}
/* }}} */

