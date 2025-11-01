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
  //_current = nullptr; /// modern

  // TODO take this from some global static later for abstract factoy pattern
  _factory = new Factory(); // creating standard factory

} // HandlerPax

/// destructor
HandlerPax::~HandlerPax( void ) {
} // ~HandlerPax

/******************************************************************************/

void // called before reading document
HandlerPax::startDoc( void ) {

  // std::cout << "PAXCC::SAX::HandlerPax starts reading document" << std::endl;

  _root = _factory->produce( "root" ); // create root object
  _current = _root; // set base pointer to root object

} // HandlerPax::startDocument

/******************************************************************************/

void // called for each starting XML tag
HandlerPax::startTag( Str tag ) {

  bool indent = false; // should we increase indentation

  if(_xmlTool.check4Header( tag ) ) {
    // TODO handle XML header here ..
    Str tag_ = _xmlTool.removeSpikes(tag); // remove '<' and '>'
    
    Pax* pax = _factory->produce( tag_ ); // create new Pax
    
    _current->Child()->add( pax ); // add to root's children
  } else if( _xmlTool.check4Comment( tag ) ) {
    // TODO handle comments here ..
      Str val = _xmlTool.cleanComment( tag );
      Pax* pax = _factory->produce( "#comment", val ); // create new Pax
    
      _current->Child()->add( pax ); // add to root's children
      _current = pax; // set current to new Pax
  } else if( _xmlTool.check4CData( tag ) ) {
    // TODO handle special tags here ..
      Str val = _xmlTool.cleanCData( tag );
      Pax* pax = _factory->produce( "#cdata", val ); // create new Pax
    
      _current->Child()->add( pax ); // add to root's children
      _current = pax; // set current to new Pax
  } else {
    // TODO explode the sting from <tag attrib1="val1" attrib2="val2" .. > to objects
    Str tag_ = _xmlTool.removeSpikes(tag); // remove '<' and '>'
    
    Pax* pax = _factory->produce( tag_ ); // create new Pax
    
    _current->Child()->add( pax ); // add to root's children
    _current = pax; // set current to new Pax

    indent = true; // increase indentation

} // if
  
  
  // for( int t = 0; t < _level; t++ ) // print some white spaces
  //   std::cout << " " << std::flush;
  // std::cout << tag << std::endl << std::flush;

  if(indent) {
    _level += _PAXCC_INDENT_; // increase indentation
  } // if


} // HandlerPax::startNode

/******************************************************************************/

void // called for each text value in XML
HandlerPax::characters( Str txt ) {

  _current->Val( txt ); // set value of current Pax

  // for( int t = 0; t < _level; t++ ) // print some white spaces
  //   std::cout << " " << std::flush;
  // std::cout << txt << std::endl << std::flush;

} // HandlerPax::characters

/******************************************************************************/

void // called for each ending XML tag
HandlerPax::endTag( Str tag ) {

  _level -= _PAXCC_INDENT_; // reduce indentation
  if(_level < 0) 
    _level = 0;

  Pax* dad = _current->Dad(); // get parent Pax
  _current = dad; // set current to parent Pax

  // for( int t = 0; t < _level; t++ ) // print some white spaces
  //   std::cout << " " << std::flush;
  // std::cout << tag << std::endl << std::flush;

} // HandlerPax::endNode

/******************************************************************************/

void // called after reading document
HandlerPax::endDoc( void ) {

  // std::cout << "PAXCC::SAX::HandlerPax ends reading document" << std::endl
  //   << std::flush;

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
