## Process this file with automake to produce Makefile.in

INCLUDES = \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	@PACKAGE_CFLAGS@

bin_PROGRAMS = projetc

projetc_SOURCES = \
	main.c \
	support.c support.h \
	interface.c interface.h \
	callbacks.c callbacks.h \
	foyer.c foyer.h \
	nutritionniste.c nutritionniste.h \
	produit.c produit.h \
	user.c user.h \
	fonction.c fonction.h \
	technicien.c technicien.h \
	alarme.c alarme.h

projetc_LDADD = @PACKAGE_LIBS@ $(INTLLIBS)

