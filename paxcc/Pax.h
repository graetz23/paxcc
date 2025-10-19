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

#ifndef __Pax_h__
#define __Pax_h__

#include "./Children.h"   // insertation sequence ordered hash map ..
#include "./Attributes.h" // insertation sequence ordered hash map ..

namespace PAXCC
{

    class Pax
    {

    private:
        std::string _tag; // member
        std::string _val; // member

        Children *_children;     // member
        Attributes *_attributes; // member

    protected:
    public:
        Pax(void);                             // constructor
        Pax(std::string tag);                  // constructor
        Pax(std::string tag, std::string val); // constructor
        Pax(Pax *pax);                         // constructor
        virtual ~Pax(void);                    // destructor

        std::string Tag(void);     // method
        void Tag(std::string tag); // method
        bool hasTag(void);         // method

        std::string Val(void);     // method
        void Val(std::string val); // method
        bool hasVal(void);         // method

        Attributes *Attrib(void);     // method
        Pax *Attrib(std::string tag); // method
        bool hasAttrib(void);         // method

        Children *Child(void);       // method
        Pax *Child(std::string tag); // method
        bool hasChild();             // method
        size_t cntChilds(); // method
        std::vector<Pax *> Childs(); // method

        std::string XML(void); // method
        std::vector<std::string> XML_lines(uint indent = 0); // method

    }; // class

} // namespace

#endif // __Pax_h__