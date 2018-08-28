/*
An Library for CoreApps .

This file is part of libcsys.

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA*/

#ifndef FORMAT_UTIL_H
#define FORMAT_UTIL_H

#include <QString>

#include "libcsys_global.h"


class LIBCSYSSHARED_EXPORT FormatUtil
{
public:
    static QString formatBytes(const quint64 &bytes);

public:
    static const quint64 KIBI = 1024;
    static const quint64 MEBI = 1048576;
    static const quint64 GIBI = 1073741824;
    static const quint64 TEBI = 1099511627776;
};

#endif // FORMAT_UTIL_H
