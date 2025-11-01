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

#include "./paxccPaxTokenizer.h" // header

/******************************************************************************/

namespace PAXCC {

/******************************************************************************/

/// constructor
PaxTokenizer::PaxTokenizer( void ) {
  _paxFactory = new Factory( ); // creating standard factory
} // PaxTokenizer

/// destructor
PaxTokenizer::~PaxTokenizer( void ) {
  if(_paxFactory != 0) {
    delete _paxFactory;
    _paxFactory = 0;
  } // if
} // ~PaxTokenizer

/******************************************************************************/

Pax*  /// convert XML tag or text 2 objects
PaxTokenizer::convert( Str tag ) {

  Pax* pax = 0;

  if( _xmlTool.check4Tag( tag ) )
    pax = convertTagComplete( tag );
  else
    pax = convertValue( tag );

  return pax;

} // PaxTokenizer::convert

/******************************************************************************/

Pax*  // convert a tag 2 pax
PaxTokenizer::convertTag( Str tag ) {

  Pax* pax = 0;

  tag = _strTool.trimS( tag );
  tag = _strTool.filterWs( tag );

  pax = convert2Node( tag );

  return pax;

} // Parser::convertTag

Pax*  // convert a tag 2 pax
PaxTokenizer::convertTagComplete( Str tag ) {

  Pax* pax = 0;

  tag = _strTool.trimS( tag );
  tag = _strTool.filterWs( tag );

  pax = convert2PaxComplete( tag );

  return pax;

} // Parser::convertTagComplete

Pax* // convert a val 2 pax
PaxTokenizer::convertValue( Str value ) {

  Pax* pax = 0;

  value = _strTool.trimS( value );
  value = _strTool.filterWs( value );

  pax = conv2Val( value );

  return pax;

} // Parser::convertValue

/******************************************************************************/

bool /// check if tag is ending
PaxTokenizer::check4Ending( Str tag ) {

  bool isTagEnding = false;

  tag = _strTool.trimS( tag );
  tag = _strTool.filterWs( tag );

  if( tag.length( ) > 0 ) {

    char m = tag[ 0 ];

    if( m == '/' )
      isTagEnding = true;
    else
      isTagEnding = false;

  } else
    throw SYS::Failure( "PaxTokenizer::check4TagEnding - no tag given; no chars" );

  return isTagEnding;

} // PaxTokenizer::check4TagEnding

bool /// check if tag is standalone
PaxTokenizer::check4StandAlone( Str tag ) {

  bool isTagStandAlone = false;

  tag = _strTool.trimS( tag );
  tag = _strTool.filterWs( tag );

  size_t tagLength = tag.length( );

  if( tagLength > 0 ) {

    char m = tag[ tagLength - 1 ];

    if( m == '/' )
      isTagStandAlone = true;
    else
      isTagStandAlone = false;

  } else
    throw SYS::Failure(
      "PaxTokenizer::check4TagStandAlone - no tag given; no chars" );

  return isTagStandAlone;

} // PaxTokenizer::check4TagStandAlone

/******************************************************************************/

Pax* /// filter a string and hand back objects
PaxTokenizer::convert2Node( Str line ) {

  Pax* pax = 0;

  size_t length = line.size( );

  if( length < 1 )
    throw SYS::Failure( "PaxTokenizer::convert2Node - line has no char" );

  char m = line[ 0 ];

  if( m == '!' ) {  // check for comment

    if( length > 5 ) { // !---- has minimum of 5

      char s0 = line[ 0 ];
      char s1 = line[ 1 ];
      char s2 = line[ 2 ];

      if( ( s0 == '!' ) && ( s1 == '-' ) && ( s2 == '-' ) ) { // comment

        char e0 = line[ length - 1 ];
        char e1 = line[ length - 2 ];

        if( ( e1 == '-' ) && ( e0 == '-' ) ) { // found comment
          return conv2Comment( line );
        } // if --

      } // if !--

    } // if 5

  } // if !

  if( m == '?' ) { // check for a header

    char s0 = line[ 0 ];

    if( s0 == '?' ) {

      char e0 = line[ length - 1 ];

      if( e0 == '?' ) {
        return conv2Header( line );
      } // if ?

    } // if ?
  } // if ?  

  if( ( m != '!' ) && ( m != '?' ) ) { // check for a ending tag 

    char s0 = line[ 0 ];

    if( s0 == '/' ) {

      char e0 = line[ length - 1 ];

      if( e0 != '/' ) { // have to be

        Str tag = line.substr( 1, ( length - ( 1 ) ) );
        pax = conv2Tag( tag );

        return pax; // return zero

      } else { // useless else here
        throw SYS::Error(
          "PaxTokenizer::convert2Node - tag is malformed like </text/>" );
      } // if tag / ... /

    } // if ?
  } // if ?  

  // check for a tag starting
  if( ( m != '/' ) && ( m != '!' ) && ( m != '?' ) )
    return conv2Tag( line );

  return pax;

} // PaxTokenizer::convert2Node

/******************************************************************************/

Pax* /// filter a string and hand back objects
PaxTokenizer::convert2PaxComplete( Str line ) {

  Pax* pax = 0;

  size_t length = line.size( );

  if( length < 1 )
    throw SYS::Failure( "PaxTokenizer::convert2NodeComplete - line has no char" );

  char a = line[ 0 ];

  if( a != '<' )
    throw SYS::Failure(
      "PaxTokenizer::convert2NodeComplete - line has no starting <" );

  char e = line[ length - 1 ];

  if( e != '>' )
    throw SYS::Failure(
      "PaxTokenizer::convert2NodeComplete - line has no ending >" );

  line = line.substr( 1, ( length - ( 1 + 1 ) ) ); // without < .. >
  length = line.size( );

  char m = line[ 0 ]; // the first after '<'

  if( m == '!' ) {  // check for comment

    if( length > 5 ) { // <!----> has minimum of 7 -> 3 for beginning

      char s0 = line[ 0 ];
      char s1 = line[ 1 ];
      char s2 = line[ 2 ];

      if( ( s0 == '!' ) && ( s1 == '-' ) && ( s2 == '-' ) ) { // comment

        char e0 = line[ length - 1 ]; // -
        char e1 = line[ length - 2 ]; // --

        if( ( e1 == '-' ) && ( e0 == '-' ) ) { // found <!---->
          return conv2Comment( line );
        } // if --

      } // if !--

      if( ( s0 == '!' ) && ( s1 == '[' ) && ( s2 == 'C' ) ) { // ![C -> DATA[

        if( length > 10 ) {

          char s3 = line[ 3 ]; // D
          char s4 = line[ 4 ]; // A
          char s5 = line[ 5 ]; // T
          char s6 = line[ 6 ]; // A
          char s7 = line[ 7 ]; // [

          if( ( s3 == 'D' ) && ( s4 == 'A' ) && ( s5 == 'T' ) && ( s6 == 'A' )
              && ( s7 == '[' ) ) {

            char e0 = line[ length - 1 ]; // ]
            char e1 = line[ length - 2 ]; // ]]

            if( ( e1 == ']' ) && ( e0 == ']' ) ) { // found comment

              return conv2CData( line );

            } // if "]]"

          } // if "DATA["

        } // if length > 10

      } // if "![C"

      if( ( s0 == '!' ) && ( s1 == 'D' || s1 == 'd' )
          && ( s2 == 'O' || s2 == 'o' ) ) { // !DO

        if( length > 10 ) {

          char s3 = line[ 3 ]; // C
          char s4 = line[ 4 ]; // T
          char s5 = line[ 5 ]; // Y
          char s6 = line[ 6 ]; // P
          char s7 = line[ 7 ]; // E

          if( ( s3 == 'C' || s3 == 'c' ) && ( s4 == 'T' || s4 == 't' )
              && ( s5 == 'Y' || s5 == 'y' ) && ( s6 == 'P' || s6 == 'p' )
              && ( s7 == 'E' || s7 == 'e' ) ) {

            return conv2Doctype( line );

          } // if "CTYPE"

        } // if length > 10

      } // if "!DO"

    } // if 5

  } // if !

  if( m == '?' ) { // check for a header

    char s0 = line[ 0 ];

    if( s0 == '?' ) {

      char e0 = line[ length - 1 ];

      if( e0 == '?' ) {
        return conv2Header( line );
      } // if ?

    } // if ?
  } // if ?  

  if( ( m != '!' ) && ( m != '?' ) ) { // check for a ending tag 

    char s0 = line[ 0 ];

    if( s0 == '/' ) {

      char e0 = line[ length - 1 ];

      if( e0 != '/' ) { // have to be

        Str tag = line.substr( 1, ( length - ( 1 + 1 ) ) );
        pax = conv2Tag( tag );

        return pax; // return zero

      } else { // useless else here
        throw SYS::Error(
          "PaxTokenizer::convert2NodeComplete - tag is malformed like </text/>" );
      } // if tag / ... /

    } // if ?
  } // if ?  

  // check for a tag starting
  if( ( m != '/' ) && ( m != '!' ) && ( m != '?' ) )
    return conv2Tag( line );

  return pax;

} // PaxTokenizer::convert2NodeComplete

/******************************************************************************/

Pax* /// convert a known header string to an pax
PaxTokenizer::conv2Header( Str line ) {

  Pax* pax = 0;

  line = line.substr( 1, ( line.length( ) - ( 1 + 1 ) ) );
  line = _strTool.trimS( line );

  Str tag = getTag( line ); // search for tag first

  // pax = new Header( tag );
  pax = _paxFactory->produce( "#header", tag);
  SYS::List<Pax*>* objList = convAttAndValList( line );

  for( int o = 0; o < objList->size( ); o++ )
    pax->Child()->add( objList->get( o ) );

  delete objList;

  return pax;

} // PaxTokenizer::convert2Tag

/******************************************************************************/

Pax* /// convert a known comment string to an pax
PaxTokenizer::conv2Comment( Str line ) {

  Pax* pax = 0;

  line = line.substr( 3, ( line.length( ) - ( 3 + 2 ) ) );
  line = _strTool.trimS( line );
  line = _strTool.filterWs( line );

  pax = _paxFactory->produce( "#comment", line );

  return pax;

} // PaxTokenizer::convert2Comment;

/******************************************************************************/

Pax* /// convert CDATA to an pax
PaxTokenizer::conv2CData( Str line ) {

  Pax* pax = 0;

  // <![CDATA[ ... ]]>
  line = line.substr( 8, ( line.length( ) - ( 8 + 2 ) ) );
  line = _strTool.trimS( line );
  line = _strTool.filterWs( line );

  pax = _paxFactory->produce( "#cdata", line );

  return pax;

} // PaxTokenizer::convert2Comment;

/******************************************************************************/

Pax* /// convert DOCTYPE to an pax
PaxTokenizer::conv2Doctype( Str line ) {

  Pax* pax = 0;

  // <!DOCTYPE >
  line = line.substr( 8, ( line.length( ) - ( 8 + 2 ) ) );
  line = _strTool.trimS( line );
  line = _strTool.filterWs( line );

  // TODO: filter DOCTYPE to white spaces and quotes

  pax = _paxFactory->produce( "#doctype", line );

  return pax;

} // PaxTokenizer::convert2Comment;

/******************************************************************************/

Pax* /// convert a known starting tag string to an pax
PaxTokenizer::conv2Tag( Str line ) {

  Pax* pax = 0;

  char e0 = line[ line.length( ) - ( 1 ) ];

  if( e0 == '/' ) // standalone tag
    line = line.substr( 0, line.length( ) - ( 1 ) );
  else if( e0 != '/' ) // normal tag
    line = line.substr( 0, line.length( ) - ( 0 ) );
  else
    // useless else here
    throw SYS::Failure( "PaxTokenizer::conv2Tag - tag is not of chars" );

  line = _strTool.trimS( line );

  Str tag = getTag( line ); // search for tag first

  pax = _paxFactory->produce( tag );

  SYS::List<Pax*>* objList = convAttAndValList( line );

  for( int o = 0; o < objList->size( ); o++ )
    pax->Attrib()->add( objList->get( o ) );

  delete objList;

  return pax;

} // PaxTokenizer::convert2Tag

/******************************************************************************/

SYS::List<Pax*>* /// get Str with strings as: att="val"
PaxTokenizer::convAttAndValList( Str line ) {

  StrList* strList = new StrList( 10 );

  bool firstWhiteSpace = false;
  bool firstExclamationMark = false;

  Str str; // define here for collecting chars in foor loop

  for( Str::iterator i = line.begin( ); i != line.end( ); i++ ) {

    char c = *i; // actual char

    if( firstWhiteSpace ) {

      if( c != ' ' )
        str += c;

      if( firstExclamationMark ) {

        if( c == ' ' )
          str += c; // now add whiteys

        if( ( c == '"' ) || ( i == ( line.end( ) - ( 1 ) ) ) ) {

          strList->add( str );

          str.clear( );

        } // "

      } // if

      if( c == '"' ) {

        if( !firstExclamationMark ) {
          firstExclamationMark = true;
        } else
          firstExclamationMark = false;
        {
        } // first

      } // "
    } // if not first white (after tag)

    if( !firstWhiteSpace && c == ' ' )
      firstWhiteSpace = true;

  } // for i

  SYS::List<Pax*>* paxList = new SYS::List<Pax*>( 5 );

  for( int s = 0; s < strList->size( ); s++ ) {

    Str str = strList->get( s );

    Pax* attribute = conv2AttAndVal( str );

    if( attribute != 0 )
      paxList->add( attribute );

  } // for s

  delete strList;

  return paxList;

} // PaxTokenizer::getAttAndValList

/******************************************************************************/

Pax* /// convert a string to attribute and value pax
PaxTokenizer::conv2AttAndVal( Str line ) {

  Pax* pax = 0;

  line = _strTool.trimS( line );

  Str str; // define here for collecting chars in foor loop

  StrList* strList = new StrList( 10 );

  for( Str::iterator i = line.begin( ); i != line.end( ); i++ ) {

    char c = *i; // actual char

    if( ( c != '=' ) && ( c != '"' ) )
      str += c;

    if( c == '"' ) {

      str = _strTool.trimS( str );
      str = _strTool.filterWs( str );

      strList->add( str );

      str.clear( );

    } // if

  } // for i

  int strListSize = strList->size( );

  if( strListSize == 2 ) {

    Str attributeStr = strList->get( 0 );
    Str valueStr = strList->get( 1 );

    pax = _paxFactory->produce( attributeStr, valueStr );

  } else
    throw SYS::Error(
      "PaxTokenizer::conv2AttAndVal - attribute has no correct XML syntax" );

  delete strList;

  return pax;

} // PaxTokenizer::convert2AttributeAndValue

/******************************************************************************/

Pax* /// convert a known value string to an pax
PaxTokenizer::conv2Val( Str line ) {

  Pax* pax = 0;

  Str str = _strTool.trimS( line );

  if( str.length( ) < 1 )
    return pax;

  pax = _paxFactory->produce( "#value", str );

  return pax;

} // PaxTokenizer::convert2Value

/******************************************************************************/

Str // hand the tag back as string
PaxTokenizer::getTag( Str line ) {

  // search for tag first
  Str tag;

  size_t posOfFirstWhite = 0;
  size_t lineLength = line.length( );

  bool isFound = false;

  while( !isFound ) {

    char t = line[ posOfFirstWhite ];

    if( t != ' ' )
      tag += t;

    if( t == ' ' )
      isFound = true;

    if( posOfFirstWhite >= ( lineLength - ( 1 ) ) )
      isFound = true;

    posOfFirstWhite++;

  } // while

  return tag;

} // PaxTokenizer::getTag

/******************************************************************************/

} // namespace PAXCC

/******************************************************************************/
