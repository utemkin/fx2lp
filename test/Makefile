# Copyright (C) 2010 Ubixum, Inc. 
# 
# This library is free software; you can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public
# License as published by the Free Software Foundation; either
# version 2.1 of the License, or (at your option) any later version.
# 
# This library is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# Lesser General Public License for more details.
# 
# You should have received a copy of the GNU Lesser General Public
# License along with this library; if not, write to the Free Software
# Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
                 
# change location of fx2libdir if needed
SOURCES=test.c
A51_SOURCES=
BASENAME=test
                 
include ../fx2lib/lib/fx2.mk

DSCR_AREA=
INT2JT=

all: hex
hex: $(BUILDDIR)/$(BASENAME).hex

$(BUILDDIR)/$(BASENAME).hex: $(BUILDDIR)/$(BASENAME).ihx
	cp $< $@
