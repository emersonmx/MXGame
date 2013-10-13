# Prelude
AC_INIT([mxgame], [1.0], [emersonmx@gmail.com], [],
        [https://bitbucket.org/emersonmx/mxgame])
AC_PREREQ(2.5)
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_MACRO_DIR([m4])
AM_INIT_AUTOMAKE([-Wall subdir-objects])

# Configure options
AC_ARG_ENABLE([build_tests],
    [AS_HELP_STRING([--enable-build-tests], [Enable mxgame build tests])],
    [build_tests=yes])
AC_ARG_WITH([boost],
    [AS_HELP_STRING([--without-boost], [Boost support])],
    [with_boost=no],
    [with_boost=yes])
AC_ARG_WITH([bullet],
    [AS_HELP_STRING([--without-bullet], [Bullet support])],
    [with_bullet=no],
    [with_bullet=yes])
AC_ARG_WITH([ogre],
    [AS_HELP_STRING([--without-ogre], [Ogre support])],
    [with_ogre=no],
    [with_ogre=yes])

# Conditionals
AM_CONDITIONAL([BUILD_TESTS], [test "$build_tests" = yes])
AM_CONDITIONAL([WITH_BOOST], [test "$with_boost" = yes])
AM_CONDITIONAL([WITH_BULLET], [test "$with_bullet" = yes])
AM_CONDITIONAL([WITH_OGRE], [test "$with_ogre" = yes])

# Checks for programs.
AC_PROG_CXX
AM_PROG_AR
AC_PROG_LIBTOOL
LT_INIT

# Checks for libraries.
if [ test "$with_bullet" = yes ]; then
    PKG_CHECK_MODULES([BULLET], [bullet >= 2.80], [with_bullet=yes])
    if [ test "$with_bullet" = yes ]; then
        AC_DEFINE([HAVE_BULLET], [1],
                  [Define to 1 if you have the Bullet installed.])
    fi
fi

if [ test "$with_ogre" = yes ]; then
    PKG_CHECK_MODULES([OGRE], [OGRE >= 1.8.1], [with_ogre=yes])
    if [ test "$with_ogre" = yes ]; then
        AC_DEFINE([HAVE_OGRE], [1],
                  [Define to 1 if you have the Ogre installed.])
    fi
fi

# Checks for header files.
if [ test "$with_boost" = yes ]; then
    AC_LANG_PUSH([C++])
    AC_CHECK_HEADER([boost/asio.hpp], [with_boost=yes])
    AC_LANG_POP([C++])
    if [ test "$with_boost" = yes ]; then
        AC_DEFINE([HAVE_BOOST], [1],
                [Define to 1 if you have the Boost installed.])
    fi
fi

# Checks for typedefs, structures and compiler characteristics.

# Checks for library functions.

# Output files.
AC_CONFIG_HEADERS([src/mxgame/config.h])
AC_CONFIG_FILES([Makefile])
AC_OUTPUT

