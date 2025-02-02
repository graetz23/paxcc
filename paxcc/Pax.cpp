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

#include "./Pax.h"

namespace PAXCC
{

    Pax::Pax(void)
    {
    } // constructor

    Pax::~Pax(void)
    {
    } // destructor

    std::string
    Pax::Tag(void)
    {
        return _tag;
    } // method

    void
    Pax::Tag(std::string tag)
    {
        _tag = tag;
    } // method

    std::string
    Pax::Val(void)
    {
        return _val;
    } // method

    void
    Pax::Val(std::string val)
    {
        _val = val;
    } // method

    bool
    Pax::isValid(void)
    {
        bool isValid = true;
        std::string na = "___na___";
        if (Tag() == na && Val() == na)
        {
            isValid = false;
        } // if
        return isValid;
    } // method

    PAX::Attributes
    Pax::Attrib(void)
    {
        PAX::Attributes attributes = _attributes;
        return attributes;
    } // method

    PAX::Children 
    Pax::Child(void){
        PAX::Children children = _children;
        return children;
    } // method

} // namespace
