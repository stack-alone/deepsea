dnl $Id$
dnl config.m4 for extension deepsea

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary. This file will not work
dnl without editing.

dnl If your extension references something external, use with:

dnl PHP_ARG_WITH(deepsea, for deepsea support,
dnl Make sure that the comment is aligned:
dnl [  --with-deepsea             Include deepsea support])

dnl Otherwise use enable:

dnl PHP_ARG_ENABLE(deepsea, whether to enable deepsea support,
dnl Make sure that the comment is aligned:
dnl [  --enable-deepsea           Enable deepsea support])

if test "$PHP_DEEPSEA" != "no"; then
  dnl Write more examples of tests here...

  dnl # --with-deepsea -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/deepsea.h"  # you most likely want to change this
  dnl if test -r $PHP_DEEPSEA/$SEARCH_FOR; then # path given as parameter
  dnl   DEEPSEA_DIR=$PHP_DEEPSEA
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for deepsea files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       DEEPSEA_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$DEEPSEA_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the deepsea distribution])
  dnl fi

  dnl # --with-deepsea -> add include path
  dnl PHP_ADD_INCLUDE($DEEPSEA_DIR/include)

  dnl # --with-deepsea -> check for lib and symbol presence
  dnl LIBNAME=deepsea # you may want to change this
  dnl LIBSYMBOL=deepsea # you most likely want to change this 

  dnl PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
  dnl [
  dnl   PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $DEEPSEA_DIR/$PHP_LIBDIR, DEEPSEA_SHARED_LIBADD)
  dnl   AC_DEFINE(HAVE_DEEPSEALIB,1,[ ])
  dnl ],[
  dnl   AC_MSG_ERROR([wrong deepsea lib version or lib not found])
  dnl ],[
  dnl   -L$DEEPSEA_DIR/$PHP_LIBDIR -lm
  dnl ])
  dnl
  dnl PHP_SUBST(DEEPSEA_SHARED_LIBADD)

  PHP_NEW_EXTENSION(deepsea, deepsea.c, $ext_shared,, -DZEND_ENABLE_STATIC_TSRMLS_CACHE=1)
fi
