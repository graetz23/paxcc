/**
 * MIT License
 *
 * PAXCC - A pretty simple C++ Data Passenger
 *
 * Copyright (c) 2025 Christian (graetz23@gmail.com)
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

  PaxMap<std::string> map; // generally used hashmap ..
  map.dbg();               // debugging the pax map ..

  Pax *pax1 = new Pax();
  pax1->Tag("Bob");
  pax1->Val("Dylon");
  std::cout << pax1->Tag() << " => " << pax1->Val() << std::endl
            << std::flush;

  Pax *pax2 = new Pax();
  pax2->Tag("Dolly");
  pax2->Val("Parton");

  pax1->Child()->add(pax2);

  Pax *pax3 = new Pax();
  pax3->Tag("Johnny");
  pax3->Val("Cash");

  pax2->Child()->add(pax3);

  std::string val2_ = pax1->Child()->get("Dolly")->Val();
  Pax *pax3_ = pax2->Child()->get("Johnny");
  std::string val3_ = pax1->Child()->get("Dolly")->Child()->get("Johnny")->Val();

  Pax *pax3__ = pax2->Child("Johnny");
  std::string val3__ = pax1->Child("Dolly")->Child("Johnny")->Val();

  delete pax1; // working recursively well on first run ..

  return 0;
} // main
