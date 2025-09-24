AC_INIT([cal], [1.0])
AM_INIT_AUTOMAKE([foreign -Wall -Werror subdir-objects])

# Check for C compiler
AC_PROG_CC          # check for C compiler
AM_PROG_AR          # check for 'ar' (archiver)
AC_PROG_RANLIB      # check for 'ranlib' (indexing static libs)

# Generate config headers
#AC_CONFIG_HEADERS([config.h])

# Generate Makefiles from templates
AC_CONFIG_FILES([
    Makefile
    src/Makefile
    test/Makefile
])

AC_OUTPUT

