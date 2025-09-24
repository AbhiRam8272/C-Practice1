AUTOMAKE_OPTIONS = subdir-objects

bin_PROGRAMS=calci

calci_SOURCES=calculator.c
# Include path for headers
calci_CPPFLAGS = -I$(top_srcdir)/include
calci_LDADD= $(top_builddir)/src/libcal.a

