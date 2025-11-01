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

#ifndef __paxccDomTokenizer_h__
#define __paxccDomTokenizer_h__

/******************************************************************************/

#include "./paxccDefines.h" // include the xml tooling libary
#include "./paxccSys.h" // SYS::
#include "./paxccPax.h" // Pax*
#include "./paxccFactory.h" // Factory

/******************************************************************************/

namespace PAXCC {

/******************************************************************************/

class /// class converts strings keeping tags into objects of the DOM structure
PaxTokenizer {
  public:

    PaxTokenizer( void ); /// constructor
    virtual ~PaxTokenizer( void ); /// destructor

    Pax* convert( Str tag ); /// convert XML tag or text 2 Pax* object tree

  protected:

    Pax* convertTag( Str tag ); /// convert a tag 2 node
    Pax* convertTagComplete( Str tag ); /// convert a tag 2 node
    Pax* convertValue( Str value ); /// convert a value 2 node

    bool check4Ending( Str tag ); /// check if tag is ending
    bool check4StandAlone( Str tag ); /// check if tag is standalone

    Pax* convert2Node( Str line ); /// filter string and hand back objects
    Pax* convert2PaxComplete( Str tag ); /// convert a tag 2 node

    Pax* conv2Header( Str line ); /// convert header string to an node
    Pax* conv2Comment( Str line ); /// convert comment string to an node
    Pax* conv2Tag( Str line ); /// convert tag string to an node
    Pax* conv2CData( Str line ); /// convert CDATA to an node
    Pax* conv2Doctype( Str line );  /// convert DOCTYPE to an node

    SYS::List<Pax*>* convAttAndValList( Str line ); /// get Strs: att="val"
    Pax* conv2AttAndVal( Str line ); /// convert to attrib and value node
    Pax* conv2Val( Str line ); /// convert a value string to an node

    Str getTag( Str line ); /// hand the tag back as string

    SYS::StrTool _strTool; /// string manipulation
    SYS::XmlTool _xmlTool; /// XML tags

    Factory* _paxFactory ; // factory for Pax objects

}; // class Tokenizer

/******************************************************************************/

} // namespace PAXCC

/******************************************************************************/

#endif // __paxccPaxTokenizer_h__
