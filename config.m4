dnl $Id$
dnl config.m4 for extension twinkle_log

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary. This file will not work
dnl without editing.

dnl If your extension references something external, use with:

dnl PHP_ARG_WITH(twinkle_log, for twinkle_log support,
dnl Make sure that the comment is aligned:
dnl [  --with-twinkle_log             Include twinkle_log support])

dnl Otherwise use enable:

PHP_ARG_ENABLE(twinkle_log, whether to enable twinkle_log support,
dnl Make sure that the comment is aligned:
[  --enable-twinkle_log           Enable twinkle_log support])

if test "$PHP_TWINKLE_LOG" != "no"; then
  dnl Write more examples of tests here...

  dnl # --with-twinkle_log -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/twinkle_log.h"  # you most likely want to change this
  dnl if test -r $PHP_TWINKLE_LOG/$SEARCH_FOR; then # path given as parameter
  dnl   TWINKLE_LOG_DIR=$PHP_TWINKLE_LOG
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for twinkle_log files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       TWINKLE_LOG_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$TWINKLE_LOG_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the twinkle_log distribution])
  dnl fi

  dnl # --with-twinkle_log -> add include path
  dnl PHP_ADD_INCLUDE($TWINKLE_LOG_DIR/include)

  dnl # --with-twinkle_log -> check for lib and symbol presence
  dnl LIBNAME=twinkle_log # you may want to change this
  dnl LIBSYMBOL=twinkle_log # you most likely want to change this 

  dnl PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
  dnl [
  dnl   PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $TWINKLE_LOG_DIR/$PHP_LIBDIR, TWINKLE_LOG_SHARED_LIBADD)
  dnl   AC_DEFINE(HAVE_TWINKLE_LOGLIB,1,[ ])
  dnl ],[
  dnl   AC_MSG_ERROR([wrong twinkle_log lib version or lib not found])
  dnl ],[
  dnl   -L$TWINKLE_LOG_DIR/$PHP_LIBDIR -lm
  dnl ])
  dnl
  dnl PHP_SUBST(TWINKLE_LOG_SHARED_LIBADD)

  PHP_NEW_EXTENSION(twinkle_log, twinkle_log.c, $ext_shared,, -DZEND_ENABLE_STATIC_TSRMLS_CACHE=1)
fi
