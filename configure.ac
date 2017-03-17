#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT(pixel-tank, 1.0.0, txgvnn@gmail.com)
AC_CONFIG_SRCDIR([src/player.h])
#AC_CONFIG_HEADERS([config.h])
AM_INIT_AUTOMAKE

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC

# Checks for libraries.
AC_CHECK_LIB([SDL2_image], [main])
AC_CHECK_LIB([SDL2_mixer], [main])
AC_CHECK_LIB([SDL2_ttf], [main])
AC_CHECK_LIB([SDL2], [main])

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_HEADER_STDBOOL

# Checks for library functions.

AC_CONFIG_FILES([Makefile src/Makefile])
#AC_OUTPUT(Makefile src/Makefile)
AC_OUTPUT
