#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ(2.61)
AC_INIT(lab, 0.1)
AC_CONFIG_SRCDIR([src/lab.c])
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_HEADER([src/config.h])

AM_INIT_AUTOMAKE

# Checks for programs.
AC_PROG_CC
AM_PROG_CC_C_O
AM_PROG_AS
AC_PROG_RANLIB

# Checks for features
AC_C_CONST
AC_C_INLINE

AC_CONFIG_FILES([Makefile src/Makefile])
AC_OUTPUT

echo
echo "Type 'make' to compile Lab."
echo
