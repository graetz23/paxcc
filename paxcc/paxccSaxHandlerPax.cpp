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
#include "./paxccSaxHandlerPax.h" // header

/******************************************************************************/

namespace PAXCC {

namespace SAX {

/******************************************************************************/

/// constructor
HandlerPax::HandlerPax( void ) {
  _level = 0;
  _current = 0; /// C++98 C++03 C++11
  // _current = nullptr; /// modern

  // TODO take this from some global static later for abstract factoy pattern
  _factory = new Factory(); // creating standard factory

  _tokenizer = new PaxTokenizer(); // creating tokenizer
} // HandlerPax

/// destructor
HandlerPax::~HandlerPax( void ) {
  if(_tokenizer != 0) {
    delete _tokenizer;
    _tokenizer = 0;
  } // if
  if(_factory != 0) {
    delete _factory;
    _factory = 0;
  } // if
} // ~HandlerPax

/******************************************************************************/

void // called before reading document
HandlerPax::startDoc( void ) {
  // nothing to do here ..
} // HandlerPax::startDocument

/******************************************************************************/

void // called for each starting XML tag
HandlerPax::startTag( Str tag ) {

  Pax* pax = _tokenizer->convert( tag ); // convert tag to Pax object(s)

  if(_level == 0) { // only for root ..
    _root = pax; // set root Pax
  } else {
    _current->Child()->add( pax ); // add to root's children
  } // if

  bool isStandAloneTag = _xmlTool.check4StandAlone( tag );
  if(!isStandAloneTag) {
    _current = pax; // set current to new Pax
    _level++;
  } // if

} // HandlerPax::startNode

/******************************************************************************/

void // called for each text value in XML
HandlerPax::characters( Str txt ) {

  _current->Val( txt ); // set value of current Pax

} // HandlerPax::characters

/******************************************************************************/

void // called for each ending XML tag
HandlerPax::endTag( Str tag ) {

  Pax* dad = _current->Dad(); // get parent Pax
  _current = dad; // set current to parent Pax

  _level--;

} // HandlerPax::endNode

/******************************************************************************/

void // called after reading document
HandlerPax::endDoc( void ) {
  // nothing to do here ..
} // HandlerPax::endDocument

/******************************************************************************/

Pax* // get root Pax object
HandlerPax::Root( void ) {
  return _root;
} // HandlerPax::Root 

/******************************************************************************/

} // namespace SAX

} // namespace PAXCC

/******************************************************************************/
