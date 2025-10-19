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

#include <iostream>
#include "./paxcc/paxcc.h"

using namespace PAXCC;

int main(int arc, char **argv)
{

  Pax *pax1 = new Pax("Bob", "Dylon");
  pax1->Attrib()->add("plays", "guitar");
  pax1->Attrib()->add("sings", "songs");

  Pax *pax2 = new Pax("Dolly", "Parton");
  pax2->Attrib()->add("sings", "songs");
  pax2->Attrib()->add("plays", "country guitar");

  Pax *pax3 = new Pax("Johnny", "Cash");
  pax3->Attrib()->add("plays", "guitar");
  pax3->Attrib()->add("sings", "country songs");

  Pax *pax4 = new Pax("John", "Denver");
  pax4->Attrib()->add("sings", "country songs");
  pax4->Attrib()->add("plays", "country guitar");

  pax1->Child()->add(pax2); // pax2 as child of pax1
  pax2->Child()->add(pax3); // pax3 as child of pax2
  pax2->Child()->add(pax4); // pax3 as child of pax2

  std::string xml = pax1->XML();
  std::cout << xml << std::endl
            << std::flush;
  
  Pax* pax2_ = pax1->Child("Dolly");

  Pax* pax3_ = pax2->Child("Johnny"); // from pax2
  
  Pax* pax4_ = pax1->Child("Dolly")->Child("John"); // chained
  
  std::string val3_ = pax1->Child("Dolly")->Child("Johnny")->Val();

  Pax* pax = pax1->Child("Dolly")->Child("John"); // chained
  std::string tag = pax->Tag();
  std::string val = pax->Val();
  std::string attribTag = pax->Attrib("sings")->Tag();
  std::string attribVal = pax->Attrib("sings")->Val();


  std::string xml_ = pax1->XML();  // generate XML from object tree ..
  std::cout << xml_ << std::flush; // print out

  delete pax1; // working recursively well on first run ..

  return 0;
} // main
