pcfiles_in  =
if ENABLE_VAPL
pcfiles_in += libvapl.pc.in
endif

pcfiles = $(pcfiles_in:%.pc.in=%.pc)

all_pcfiles_in =
all_pcfiles_in += libvapl.pc.in

all_pcfiles = $(all_pcfiles_in:%.pc.in=%.pc)

pkgconfigdir = @pkgconfigdir@
pkgconfig_DATA = $(pcfiles)

EXTRA_DIST = $(all_pcfiles_in)

DISTCLEANFILES = $(all_pcfiles)

# Extra clean files so that maintainer-clean removes *everything*
MAINTAINERCLEANFILES = Makefile.in
