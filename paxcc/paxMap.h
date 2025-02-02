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


#include <map>
#include <unordered_map>
#include <vector>
#include <iostream>

namespace PAXCC {

class PaxMap {

private:
    std::vector<std::string> _seq; // member
    std::map<std::string, std::string> _map; // member
    std::vector<std::string>::iterator _it; // member

public:

    PaxMap( void ); // constructor
    virtual ~PaxMap( void ); // destructor

    void put(std::string key, std::string value); // method

    std::string get(std::string key); // method

    std::vector<std::string>::iterator start(); // method

    std::vector<std::string>::iterator end(); // method

}; // class

} // namespace