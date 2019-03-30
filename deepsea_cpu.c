#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>
#include <php_ini.h>
#include <SAPI.h>
#include "Zend/zend_interfaces.h"
#include "Zend/zend_types.h"
#include "Zend/zend_API.h"
#include "php_deepsea.h"
#include "deepsea_cpu.h"

#ifdef PHP_WIN32
#include "windows.h"
#else
#include <unistd.h>
#endif
#include <stdio.h>
#include <stdlib.h>

typedef struct occupy CPU_OCCUPY;

typedef  struct occupy
{
	char name[20];
	unsigned int user;
	unsigned int nice;
	unsigned int system;
	unsigned int idle;
};


zend_class_entry *deepsea_cpu_ce;



PHP_METHOD(DS_CPU,getMemory) {
	php_printf("aaaaaaaaaaaaa");
}


PHP_METHOD(DS_CPU,getCompany) {
	php_printf("aaaaaaaaaaaaa");
}


PHP_METHOD(DS_CPU,getSystemInfo) {
	long num_procs;
	long page_size;
	long num_pages;
	long free_pages;
	long long mem;
	long long free_mem;



	#ifdef PHP_WIN32
		SYSTEM_INFO sysInfo;
		GetSystemInfo( &sysInfo );
		//php_printf("system cpu num is %d\n", sysInfo.dwNumberOfProcessors);
		num = sysInfo.dwNumberOfProcessors;
	#else
		zval *arr = (zval *) emalloc(sizeof(zval));;

		array_init(arr);
		//array_init(retValue);

		num_procs = sysconf (_SC_NPROCESSORS_CONF);;
		//printf ("CPU 个数为: %ld 个\n", num_procs);
		add_assoc_long(arr,"cpuNum",num_procs);
		//add_next_index_log();
		page_size = sysconf (_SC_PAGESIZE);
		add_assoc_long(arr,"page_size",page_size);
		//printf ("系统页面的大小为: %ld K\n", page_size / 1024 );

		num_pages = sysconf (_SC_PHYS_PAGES);
		add_assoc_long(arr,"num_pages",num_pages);
		//printf ("系统中物理页数个数: %ld 个\n", num_pages);

		//free_pages = sysconf (_SC_AVPHYS_PAGES);
		//printf ("系统中可用的页面个数为: %ld 个\n", free_pages);
		//add_assoc_long(arr,"free_pages",free_pages);

		mem = (long long) ((long long)num_pages * (long long)page_size);
		mem /= ONE_MB;
		free_mem = (long long)free_pages * (long long)page_size;
		free_mem /= ONE_MB;
		//printf ("总共有 %lld MB 的物理内存, 空闲的物理内存有: %lld MB\n", mem, free_mem);
		add_assoc_long(arr,"mem",mem);
		add_assoc_long(arr,"free_mem",free_mem);

		RETURN_ZVAL(arr,0,1);

	#endif



}

PHP_METHOD(DS_CPU,getOccupy) {

	zval *arr = (zval *) emalloc(sizeof(zval));
	//MAKE_STD_ZVAL(subarray);
	array_init(arr);

	#ifdef PHP_WIN32

	#else
		CPU_OCCUPY	*o;
		FILE *fd;
		int n;
		char buff[MAXBUFSIZE];
		fd = fopen ("/proc/stat", "r"); //这里只读取stat文件的第一行及cpu总信息，如需获取每核cpu的使用情况，请分析stat文件的接下来几行。
		fgets (buff, sizeof(buff), fd);
		sscanf (buff, "%s %u %u %u %u", o->name, &o->user, &o->nice,&o->system, &o->idle);
		add_assoc_long(arr,"system",o->system);
		add_assoc_long(arr,"idle",o->idle);
		add_assoc_string(arr,"name",o->name);

	   fclose(fd);
	#endif

	  RETURN_ZVAL(arr,0,1);
}




PHP_METHOD(DS_CPU,getkernelInfo) {
	php_printf("aaaaaaaaaaaaa");
}


/** {{{ alone_config_methods
*/
zend_function_entry deepsea_cpu_methods[] = {
	PHP_ME(DS_CPU, getMemory, NULL, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC )
	PHP_ME(DS_CPU, getCompany, NULL, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC )
	PHP_ME(DS_CPU, getSystemInfo, NULL, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC )
	PHP_ME(DS_CPU, getOccupy, NULL, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC )
	PHP_ME(DS_CPU, getkernelInfo, NULL, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC )
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

