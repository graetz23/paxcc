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

#ifndef __paxccSysError_h__
#define __paxccSysError_h__

/******************************************************************************/

#include "./paxccSysException.h"

/******************************************************************************/

namespace PAXCC {

namespace SYS {

/******************************************************************************/

#define _PAXCC_VERSION_SYS_Error_ 1.00 // 20150101
#ifdef _PAXCC_DEBUG_
#define _PAXCC_DEBUG_SYS_Error_
#endif

/******************************************************************************/

class /// class for marking a non recoverable error
Error: public Exception { // for real errors
  public:

    Error( void ); /// constructor
    Error( Str message ); /// constructor overloaded
    Error( Str message, int lineNo ); /// use __LINE__ @ lineNo
    Error( Str message, char* fileName ); /// use __FILE__ @ fileName
    Error( Str message, char* fileName, int lineNo ); /// use __FILE__ @ fileName and __LINE__ @ lineNo
    virtual ~Error( void ); /// destructor

  private:

    virtual void mark( void ); /// mark an exception

};
// class Error

/******************************************************************************/

}// namespace PAXCC

} // namespace SYS

/******************************************************************************/

#endif // __paxccSysError_h__
