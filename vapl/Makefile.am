lib_LTLIBRARIES =
if ENABLE_VAPL
lib_LTLIBRARIES += libvapl.la
endif

codecparsers_srcdir = \
	$(top_srcdir)/gst-libs/gst/codecparsers

gen_vapl_sources = \
	$(top_srcdir)/scripts/gen_vapl_sources

gen_source_c = \
	dboolhuff.c			\
	gstvp8rangedecoder.c		\
	nalutils.c			\
	parserutils.c			\
	vp8utils.c			\
	$(NULL)

gen_source_h = \
	$(NULL)

gen_source_priv_h = \
	dboolhuff.h			\
	gstvp8rangedecoder.h		\
	nalutils.h			\
	parserutils.h			\
	vp8utils.h			\
	$(NULL)

gen_vapl_source_c = \
	vapl_h264_parser.c		\
	vapl_h265_parser.c		\
	vapl_jpeg_parser.c		\
	vapl_mpeg4_parser.c		\
	vapl_mpegvideo_parser.c		\
	vapl_vc1_parser.c		\
	vapl_vp8_parser.c		\
	$(NULL)

gen_vapl_source_h = \
	vapl_h264_parser.h		\
	vapl_h265_parser.h		\
	vapl_jpeg_parser.h		\
	vapl_mpeg4_parser.h		\
	vapl_mpegvideo_parser.h		\
	vapl_vc1_parser.h		\
	vapl_vp8_parser.h		\
	$(NULL)

gen_source_all_c = $(gen_source_c)
gen_source_all_h = $(gen_source_h) $(gen_source_priv_h)

vapl_parser_source_c = \
	$(gen_source_c)			\
	$(gen_vapl_source_c)		\
	vapl_arrays.c			\
	$(NULL)

vapl_parser_source_h = \
	$(gen_source_h)			\
	$(gen_vapl_source_h)		\
	vapl_arrays.h			\
	vapl_core.h			\
	$(NULL)

vapl_parser_cflags = \
	-I$(top_srcdir)/gst-libs	\
	-I$(top_srcdir)/gcl		\
	-I$(top_srcdir)/gcl/glib	\
	-DGST_USE_UNSTABLE_API		\
	-fvisibility=hidden		\
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
$(gen_vapl_source_c): vapl_%_parser.c: $(codecparsers_srcdir)/gst%parser.c $(gen_vapl_sources)
	$(gen_vapl_sources) --gen-source -o $@ $<
$(gen_vapl_source_h): vapl_%_parser.h: $(codecparsers_srcdir)/gst%parser.h $(gen_vapl_sources)
	$(gen_vapl_sources) --gen-header -o $@ $<

DISTCLEANFILES = \
	.timestamp.prepare		\
	.timestamp.sources		\
	.timestamp.headers		\
	$(gen_source_all_c)		\
	$(gen_source_all_h)		\
	$(gen_vapl_source_c)		\
	$(gen_vapl_source_h)		\
	$(NULL)

# Extra clean files so that maintainer-clean removes *everything*
MAINTAINERCLEANFILES = Makefile.in
