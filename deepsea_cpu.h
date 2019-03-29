#ifndef _DEEP_CPU_H_
#define	_DEEP_CPU_H_


extern zend_class_entry *deepsea_cpu_ce;

PHP_METHOD(DS_CPU,getMemory);
PHP_METHOD(DS_CPU,getCompany);
PHP_METHOD(DS_CPU,getModel);
PHP_METHOD(DS_CPU,getkernelInfo);
DEEP_STARTUP_FUNCTION(deepsea);

#endif
