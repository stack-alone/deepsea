#ifndef _DEEP_CPU_H_
#define	_DEEP_CPU_H_

#define MAXBUFSIZE 1024
#define ONE_MB (1024 * 1024)
extern zend_class_entry *deepsea_cpu_ce;

PHP_METHOD(DS_CPU,getMemory);
PHP_METHOD(DS_CPU,getCompany);
PHP_METHOD(DS_CPU,getModel);
PHP_METHOD(DS_CPU,getkernelInfo);
DEEP_STARTUP_FUNCTION(deepsea);

#endif
