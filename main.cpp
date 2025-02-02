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

int main( int arc, char** argv ) {

  PaxMap pax;
  pax.add("Bob", "Dylan");

  for(int i=0; i < 100; i++) {
    std::string key = std::to_string(i+1);
    pax.add(key, key);
  } // loop

  bool isStored = pax.has("42");

  bool wasDeleted = pax.del("23");

  std::vector<std::string> vec =pax.vec();
  for(std::size_t k = 0; k < vec.size(); k++) {
    std::string val = vec[k];
    std::cout << "val: " << val << std::endl << std::flush;
  } // loop


  return 0;
} // main
