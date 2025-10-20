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

#include "./paxccSaxHandler.h" // header
#include "./paxccSysException.h" // base class for exceptions in SYS::
#include "./paxccSysFailure.h" // exception class for marking failures
#include "./paxccSysError.h" // exception class for marking errors

/******************************************************************************/

#ifdef _MSC_VER
#pragma warning( disable:4100 ) // for unused objects
#endif // _MSC_VER // _WIN32

/******************************************************************************/

namespace PAXCC {

namespace SAX {

/******************************************************************************/

/// constructor
Handler::Handler( void ) {
  _isTalking = true; // std::cout or throw an exception if this is used
  //_isTalking = false; // std::cout or throw an exception if this is used
} // Handler

/// destructor
Handler::~Handler( void ) {
} // ~Handler

/******************************************************************************/

void // called before reading document
Handler::startDoc( void ) {

  if( _isTalking ) {
    std::cout << std::endl << std::endl;
    std::cout << "PAXCC::SYS::XmlParser starts reading document" << std::endl;
  } else {
    throw SYS::Failure( "SYS::XmlHandler - do not use base handler class" );
  } // if _istalking

} // Handler::startDocument

/******************************************************************************/

void // called for each starting XML tag
Handler::startTag( Str tag ) {

  if( _isTalking )
    std::cout << tag << std::endl;
  else
    throw SYS::Failure( "SYS::XmlHandler - do not use base handler class" );

} // Handler::startNode

/******************************************************************************/

void // called for each text value in XML
Handler::characters( Str txt ) {

  if( _isTalking )
    std::cout << txt << std::endl;
  else
    throw SYS::Failure( "SYS::XmlHandler - do not use base handler class" );

} // Handler::characters

/******************************************************************************/

void // called for each ending XML tag
Handler::endTag( Str tag ) {

  if( _isTalking )
    std::cout << tag << std::endl;
  else
    throw SYS::Failure( "SYS::XmlHandler - do not use base handler class" );

} // Handler::endNode

/******************************************************************************/

void // called after reading document
Handler::endDoc( void ) {
  
  if( _isTalking ) {
    std::cout << "PAXCC::SYS::XmlParser ends reading document";
    std::cout << std::endl << std::endl;
  } else {
    throw SYS::Failure( "SYS::XmlHandler - do not use base handler class" );
  } // if _istalking

} // Handler::endDocument

/******************************************************************************/

} // namespace SAX

} // namespace PAXCC

/******************************************************************************/
