CFLAGS=-O2 -g -Wall
LFLAGS=
CC=gcc
CXX=g++
WDL_PATH=../vendor/WDL/WDL

CFLAGS += -D_FILE_OFFSET_BITS=64

ifdef NOSWELL
CFLAGS += -D_LICE_NO_SYSBITMAPS_
SWELL_OBJS =
else
	CFLAGS += -DSWELL_LICE_GDI

	ifdef GDK2
		CFLAGS += -DSWELL_TARGET_GDK=2 $(shell pkg-config --cflags gdk-2.0)
		LFLAGS += $(shell pkg-config --libs gdk-2.0) -lX11 -lXi
	else
		CFLAGS += -DSWELL_TARGET_GDK=3 $(shell pkg-config --cflags gdk-3.0)
		LFLAGS += $(shell pkg-config --libs gdk-3.0) -lX11 -lXi
	endif
	ifndef NOFREETYPE
		CFLAGS += -DSWELL_FREETYPE $(shell pkg-config --cflags freetype2)
		LFLAGS += $(shell pkg-config --libs freetype2)
	endif

	SWELL_OBJS = swell-wnd-generic.o swell-gdi-lice.o swell.o swell-misc-generic.o \
							 swell-dlg-generic.o swell-menu-generic.o swell-kb-generic.o \
							 swell-gdi-generic.o swell-ini.o swell-generic-gdk.o \
							 swell-appstub-generic.o swell-miscdlg-generic.o

	LFLAGS += -ldl -lGL

	vpath %.cpp $(WDL_PATH)/swell
endif

CXXFLAGS=$(CFLAGS)

#vpath %.c $(WDL_PATH)/zlib $(WDL_PATH)/libpng $(WDL_PATH)/jpeglib  $(WDL_PATH)/giflib
vpath %.cpp $(WDL_PATH)/lice $(WDL_PATH)/plush2

#ZLIB_OBJS = compress.o adler32.o crc32.o deflate.o infback.o inffast.o inflate.o inftrees.o trees.o uncompr.o zutil.o ioapi.o zip.o unzip.o

#PNGLIB_OBJS = png.o pngerror.o pngget.o pngmem.o pngpread.o pngread.o pngrio.o pngrtran.o pngrutil.o pngset.o pngtrans.o 

#JPEGLIB_OBJS = jcomapi.o jdapimin.o jdapistd.o jdatadst.o jdatasrc.o jdcoefct.o jdcolor.o jddctmgr.o jdhuff.o jdinput.o jdmainct.o jdmarker.o \
							 jdmaster.o jdmerge.o jdphuff.o jdpostct.o jdsample.o jerror.o jfdctflt.o jfdctfst.o jfdctint.o jidctflt.o jidctfst.o jidctint.o \
							 jidctred.o jmemmgr.o jmemnobs.o jquant1.o jquant2.o jutils.o

#GIFLIB_OBJS = dgif_lib.o egif_lib.o gifalloc.o gif_hash.o 

LICEOBJS = lice.o lice_arc.o lice_line.o lice_text.o lice_colorspace.o #lice_gif.o lice_gif_write.o lice_image.o lice_jpg.o lice_png.o lice_pcx.o lice_palette.o lice_line.o lice_arc.o lice_text.o lice_textnew.o lice_texgen.o lice_colorspace.o

#PLUSH_OBJS = pl_cam.o pl_make.o pl_math.o pl_obj.o pl_putface.o pl_read_3ds.o pl_read_cob.o pl_read_jaw.o pl_spline.o

.phony: clean default

default: basic_swell_template

#basic_swell_tempalte: $(LICEOBJS) $(JPEGLIB_OBJS) $(PNGLIB_OBJS) $(ZLIB_OBJS) $(GIFLIB_OBJS) $(SWELL_OBJS) $(PLUSH_OBJS) main.o fly.o
basic_swell_template: $(LICEOBJS) $(SWELL_OBJS) main.o 
	$(CXX) $(CFLAGS) -o $@ $^ $(LFLAGS)


clean: 
#	-rm $(LICEOBJS) $(JPEGLIB_OBJS) $(PNGLIB_OBJS) $(ZLIB_OBJS) $(GIFLIB_OBJS) imgs2gif.o imgs2gif $(SWELL_OBJS) $(PLUSH_OBJS) test main.o fly.o
	-rm $(SWELL_OBJS) basic_swell_template main.o 
