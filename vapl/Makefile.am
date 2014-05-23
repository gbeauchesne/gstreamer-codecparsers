lib_LTLIBRARIES =
if ENABLE_VAPL
lib_LTLIBRARIES += libvapl.la
endif

codecparsers_srcdir = \
	$(top_srcdir)/gst-libs/gst/codecparsers

gen_source_c = \
	dboolhuff.c			\
	gsth264parser.c			\
	gsth265parser.c			\
	gstjpegparser.c			\
	gstmpeg4parser.c		\
	gstmpegvideoparser.c		\
	gstvc1parser.c			\
	gstvp8parser.c			\
	gstvp8rangedecoder.c		\
	nalutils.c			\
	parserutils.c			\
	vp8utils.c			\
	$(NULL)

gen_source_h = \
	gsth264parser.h			\
	gsth265parser.h			\
	gstjpegparser.h			\
	gstmpeg4parser.h		\
	gstmpegvideoparser.h		\
	gstvc1parser.h			\
	gstvp8parser.h			\
	$(NULL)

gen_source_priv_h = \
	dboolhuff.h			\
	gstvp8rangedecoder.h		\
	nalutils.h			\
	parserutils.h			\
	vp8utils.h			\
	$(NULL)

gen_source_all_c = $(gen_source_c)
gen_source_all_h = $(gen_source_h) $(gen_source_priv_h)

vapl_parser_source_c = \
	$(gen_source_c)			\
	$(NULL)

vapl_parser_source_h = \
	$(gen_source_h)			\
	$(NULL)

vapl_parser_cflags = \
	-I$(top_srcdir)/gst-libs	\
	-I$(top_srcdir)/gcl		\
	-I$(top_srcdir)/gcl/glib	\
	-DGST_USE_UNSTABLE_API		\
	$(NULL)

vapl_parser_libs = \
	$(top_builddir)/gcl/gcl/libgcl_core.la \
	$(top_builddir)/gcl/gst/libgcl_gstreamer.la \
	$(NULL)

nodist_EXTRA_libvapl_la_SOURCES		= dummy.c
nodist_libvapl_la_SOURCES		= $(vapl_parser_source_c)
libvapl_include_HEADERS			= $(vapl_parser_source_h)
libvapl_includedir			= $(includedir)/vapl
libvapl_la_CFLAGS			= $(vapl_parser_cflags)
libvapl_la_LIBADD			= $(vapl_parser_libs)

all-local: .timestamp.prepare

.timestamp.prepare: .timestamp.sources .timestamp.headers
	touch $@
.timestamp.sources: $(gen_source_all_c)
	touch $@
.timestamp.headers: $(gen_source_all_h)
	touch $@

$(gen_source_all_c): %.c: $(codecparsers_srcdir)/%.c $(gen_source_all_h)
	$(LN_S) -f $< $@
$(gen_source_all_h): %.h: $(codecparsers_srcdir)/%.h
	$(LN_S) -f $< $@

DISTCLEANFILES = \
	.timestamp.prepare		\
	.timestamp.sources		\
	.timestamp.headers		\
	$(gen_source_all_c)		\
	$(gen_source_all_h)		\
	$(NULL)

# Extra clean files so that maintainer-clean removes *everything*
MAINTAINERCLEANFILES = Makefile.in
