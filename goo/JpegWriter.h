//========================================================================
//
// JpegWriter.h
//
// This file is licensed under the GPLv2 or later
//
// Copyright (C) 2009 Stefan Thomas <thomas@eload24.com>
// Copyright (C) 2010 Adrian Johnson <ajohnson@redneon.com>
// Copyright (C) 2010 Jürg Billeter <j@bitron.ch>
// Copyright (C) 2010 Harry Roberts <harry.roberts@midnight-labs.org>
// Copyright (C) 2010 Brian Cameron <brian.cameron@oracle.com>
// Copyright (C) 2011 Albert Astals Cid <aacid@kde.org>
// Copyright (C) 2011 Thomas Freitag <Thomas.Freitag@alfa.de>
//
//========================================================================

#ifndef JPEGWRITER_H
#define JPEGWRITER_H

#include "poppler/poppler-config.h"

#ifdef ENABLE_LIBJPEG

#include <sys/types.h>
#include "ImgWriter.h"

extern "C" {
#include <jpeglib.h>
}

class JpegWriter : public ImgWriter
{
	public:
		JpegWriter(int quality, bool progressive, J_COLOR_SPACE colorMode = JCS_RGB);
		JpegWriter(J_COLOR_SPACE colorMode = JCS_RGB);
		~JpegWriter();
		
		bool init(FILE *f, int width, int height, int hDPI, int vDPI);
		
		bool writePointers(unsigned char **rowPointers, int rowCount);
		bool writeRow(unsigned char **row);
		
		bool close();
		bool supportCMYK() { return colorMode == JCS_CMYK; }
	
	private:
		bool progressive;
		int quality;
		J_COLOR_SPACE colorMode;
		struct jpeg_compress_struct cinfo;
		struct jpeg_error_mgr jerr;
};

#endif

#endif
