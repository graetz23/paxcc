/**
 * MIT License
 *
 * PAXCC - A pretty simple C++ Data Passenger
 *
 * Copyright (c) 2017-2025 Christian (graetz23@gmail.com)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

#ifndef __paxccSys_h__
#define __paxccSys_h__

/******************************************************************************/

#define _PAXCC_VERSION_SYS_ 1.00 // 20170101

/******************************************************************************/

#include "./paxccSysDefines.h" /// common include file for headers and typedefs
#include "./paxccSysException.h" /// exception base class for errors & failures
#include "./paxccSysFailure.h" /// exception class for failures
#include "./paxccSysError.h" /// exception class for capital errors
#include "./paxccSysList.h" /// template based smart array for unit test objects
#include "./paxccSysStrTool.h" /// tool for manipulating std::string & char*
#include "./paxccSysXmlTool.h" /// tool for cleaning malformed XML tags
#include "./paxccSysXmlHandler.h" /// class for handling read XML tags & texts
#include "./paxccSysXmlParser.h" /// class for parsing XML files

/******************************************************************************/

namespace PAXCC {

namespace SYS {

/******************************************************************************/

/******************************************************************************/

} // namespace SYS

typedef SYS::StrList StrList; // namespace & template typedef
typedef SYS::Str Tag;         // namespace & template typedef
typedef SYS::StrList TagList; // namespace & template typedef

} // namespace PAXCC

/******************************************************************************/

#endif // __paxccSys_h__

/******************************************************************************/
