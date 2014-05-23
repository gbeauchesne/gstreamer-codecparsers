noinst_LTLIBRARIES =
if ENABLE_VAPL
noinst_LTLIBRARIES += libgcl_gstreamer.la
endif

source_c = \
	gstinfo.c		\
	$(NULL)

source_h = \
	gst.h			\
	gstconfig.h		\
	gstinfo.h		\
	gstutils.h		\
	$(NULL)

libgcl_gstreamer_la_SOURCES	= $(source_c)
libgcl_gstreamer_la_CFLAGS	= -I$(top_srcdir)/gcl

EXTRA_DIST = $(source_h)

# Extra clean files so that maintainer-clean removes *everything*
MAINTAINERCLEANFILES = Makefile.in
