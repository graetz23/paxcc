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
        _attributes = new Attributes();
        _children = new Children();
        _tag = nullptr;
        _val = nullptr;
    } // constructor

    Pax::Pax(std::string tag)
    {
        _attributes = new Attributes();
        _children = new Children();
        _tag = tag;
        _val = nullptr;
    } // constructor

    Pax::Pax(std::string tag, std::string val)
    {
        _attributes = new Attributes();
        _children = new Children();
        _tag = tag;
        _val = val;
    } // constructor

    Pax::Pax(Pax *pax)
    {
        // TODO do a recursive copy constructor here ..
    } // constructor

    Pax::~Pax(void)
    {
        delete _attributes;
        _attributes = nullptr;
        delete _children;
        _children = nullptr;
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

    Attributes *
    Pax::Attrib(void)
    {
        return _attributes;
    } // method

    Pax *
    Pax::Attrib(std::string tag)
    {
        Pax *pax = _attributes->get(tag);
        return pax;
    } // method

    bool Pax::hasAttrib(void)
    {
        bool hasAttrib = false;
        size_t cnt = Attrib()->cnt();
        if( cnt > 0) {
            hasAttrib = true;
        } // if
        return hasAttrib;
    } // method

    Children *
    Pax::Child(void)
    {
        return _children;
    } // method

    Pax *
    Pax::Child(std::string tag)
    {
        Pax *pax = _children->get(tag);
        return pax;
    } // method

    bool Pax::hasChild(void)
    {
        bool hasChild = false;
        size_t cnt = Child()->cnt();
        if( cnt > 0) {
            hasChild = true;
        } // if
        return hasChild;
    } // method


    std::vector<std::string> *
    Pax::XML(void)
    {
        std::vector<std::string> *vec = new std::vector<std::string>();

        return vec;
    } // method

} // namespace
