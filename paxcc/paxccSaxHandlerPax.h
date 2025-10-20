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

#ifndef __paxccSaxHandlerPax_h__
#define __paxccSaxHandlerPax_h__

/******************************************************************************/

#include "./paxccSaxHandler.h" // for converting strings 2 objects
#include "./paxccPax.h" // Pax object tree
#include "./paxccFactory.h" // Pax object tree factory

namespace PAXCC {

namespace SAX {

/******************************************************************************/

#define _PAXCC_VERSION_SAX_HandlerPax_ 1.00 // 20150101
#ifdef _PAXCC_DEBUG_
#define _PAXCC_DEBUG_SAX_HandlerPax_
#endif

/******************************************************************************/

class /// example for an handler pushing writing data 2 console
HandlerPax: public Handler {
  public:

    HandlerPax( void ); /// constructor
    virtual ~HandlerPax( void ); /// destructor

    void startDoc( void ); /// called before reading document

    void startTag( Str tag ); /// called for each starting XML tag

    void characters( Str txt ); /// called for each text value in XML

    void endTag( Str tag ); /// called for each ending XML tag

    void endDoc( void ); /// called after reading document

    Pax* Root( void ); /// get root Pax object

  protected:

    int _level; // count level in XML structure and print tabulators for it

    Pax* _root; /// root object of PAX tree structure aka composite pattern

    Factory* _factory; /// factory for creating and copying Pax objects

    SYS::XmlTool _xmlTool; /// tool class for std::string manipulations

    SYS::StrTool _strTool; /// tool class for XML tag & text manipulations

  private:

    Pax* _current; /// current Pax object being processed

}; // class

/******************************************************************************/

}// namespace SAX

} // namespace PAXCC

/******************************************************************************/

#endif // __paxccSaxHandlerPax_h__
