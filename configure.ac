# Prelude
AC_INIT([mxgame], [1.0], [emersonmx@gmail.com], [],
        [https://bitbucket.org/emersonmx/mxgame])
AC_PREREQ(2.5)
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_MACRO_DIR([m4])
AM_INIT_AUTOMAKE([1.11 -Wall foreign subdir-objects silent-rules])
AM_SILENT_RULES([yes])

# Configure options
AC_ARG_WITH([boost], AS_HELP_STRING([--without-boost], [Ignore presence of Boost and disable it]))
AC_ARG_WITH([bullet], AS_HELP_STRING([--without-bullet], [Ignore presence of Bullet and disable it]))
AC_ARG_WITH([ogre], AS_HELP_STRING([--without-ogre], [Ignore presence of Ogre and disable it]))

# Conditionals
AM_CONDITIONAL([WITH_BOOST], [test "x$with_boost" != "xno"])
AM_CONDITIONAL([WITH_BULLET], [test "x$with_bullet" != "xno"])
AM_CONDITIONAL([WITH_OGRE], [test "x$with_ogre" != "xno"])

# Checks for programs.
AC_PROG_CXX
AM_PROG_AR
AC_PROG_LIBTOOL
LT_INIT

# Guess the operating system of the user.
case "$host" in
    *-*-mingw*|*-*-cygwin*)
        AC_DEFINE(PLATFORM_WINDOWS, 1, [Platform is Windows])
        ;;
    *-*-linux*)
        AC_DEFINE(PLATFORM_LINUX, 1, [Platform is Linux])
        ;;
    *-*-darwin*)
        AC_DEFINE(PLATFORM_APPLE, 1, [Platform is Apple])
        ;;
    *)
        AC_MSG_WARN([Your platform is not currently supported])
        ;;
esac

# Checks for libraries.
AS_IF([test "x$with_bullet" != "xno"], [
    PKG_CHECK_MODULES([BULLET], [bullet >= 2.80], [
        AC_DEFINE([HAVE_BULLET], [1],
                  [Define to 1 if you have the Bullet installed.])
    ])
])
AS_IF([test "x$with_ogre" != "xno"], [
    PKG_CHECK_MODULES([OGRE], [OGRE >= 1.8.1], [
        AC_DEFINE([HAVE_OGRE], [1],
                  [Define to 1 if you have the Ogre installed.])
    ])
])

# Checks for header files.
AS_IF([test "x$with_boost" != "xno"], [
    AC_LANG_PUSH([C++])
    AC_CHECK_HEADER([boost/asio.hpp], [with_boost=yes], [
        AC_DEFINE([HAVE_BOOST], [1],
                  [Define to 1 if you have the Boost installed.])
    ])
    AC_LANG_POP([C++])
])

# Checks for typedefs, structures and compiler characteristics.

# Checks for library functions.

# Output files.
AC_CONFIG_HEADERS([mxgame/config.h])
AC_CONFIG_FILES([Makefile mxgame.pc])
AC_OUTPUT

