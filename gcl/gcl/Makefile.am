noinst_LTLIBRARIES =
if ENABLE_VAPL
noinst_LTLIBRARIES += libgcl_core.la
endif

source_c = \
	gcl_memory.c		\
	gcl_messages.c		\
	gcl_string.c		\
	gcl_thread.c		\
	$(NULL)

source_h = \
	gcl.h			\
	gcl_macros.h		\
	gcl_memory.h		\
	gcl_messages.h		\
	gcl_numeric.h		\
	gcl_string.h		\
	gcl_thread.h		\
	gcl_types.h		\
	$(NULL)

libgcl_core_la_SOURCES		= $(source_c)
libgcl_core_la_CFLAGS		= -I$(top_srcdir)/gcl -fvisibility=hidden
libgcl_core_la_LIBADD		= -lpthread

EXTRA_DIST = $(source_h)

# Extra clean files so that maintainer-clean removes *everything*
MAINTAINERCLEANFILES = Makefile.in
