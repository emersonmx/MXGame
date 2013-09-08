# Prelude
AC_INIT([mxgame], [1.0], [emersonmx@gmail.com])
AC_PREREQ(2.5)
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_MACRO_DIR([m4])
AM_INIT_AUTOMAKE([-Wall])

# Configure options
AC_ARG_ENABLE([build_tests],
    [AS_HELP_STRING([--enable-build-tests], [enable mxgame build tests])],
    [build_tests=yes])
AC_ARG_WITH([boost_asio],
    [AS_HELP_STRING([--without-boost-asio], [Boost ASIO support])],
    [with_boost_asio=no],
    [with_boost_asio=yes])
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
AM_CONDITIONAL([WITH_BOOST_ASIO], [test "$with_boost_asio" = yes])
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
fi
if [ test "$with_ogre" = yes ]; then
    PKG_CHECK_MODULES([OGRE], [OGRE >= 1.8.1], [with_ogre=yes])
fi

# Checks for header files.
if [ test "$with_boost_asio" = yes ]; then
    AC_LANG_PUSH([C++])
    AC_CHECK_HEADER([boost/asio.hpp], [with_boost_asio=yes])
    AC_LANG_POP([C++])
fi

# Checks for typedefs, structures and compiler characteristics.

# Checks for library functions.

# Output files.
AC_CONFIG_HEADERS([src/mxgame/config.h])
AC_CONFIG_FILES([
    Makefile
    src/Makefile
    src/mxgame/Makefile
    src/mxgame/application/Makefile
    src/mxgame/boost/Makefile
    src/mxgame/boost/system/Makefile
    src/mxgame/boost/system/time/Makefile
    src/mxgame/core/Makefile
    src/mxgame/ogre/Makefile
    src/mxgame/ogre/bullet/Makefile
    src/mxgame/ogre/bullet/debug/Makefile
    src/mxgame/ogre/core/Makefile
    src/mxgame/ogre/util/Makefile
    src/mxgame/system/Makefile
    src/mxgame/system/time/Makefile
    src/mxgame/util/Makefile
    test/Makefile
])
AC_OUTPUT

