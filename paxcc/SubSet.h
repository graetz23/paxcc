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

#ifndef __SubSet_h__
#define __SubSet_h__

#include "./PaxMap.h"

namespace PAXCC
{
    class Pax; // link it up ..

    class SubSet
    {

    private:
        PaxMap<Pax *> *_map; // member

    protected:
    public:
        SubSet(void);          // constructor
        virtual ~SubSet(void); // destructor

        bool has(std::string tag); // method

        bool add(Pax *pax);                         // method
        bool add(std::string tag);                  // method
        bool add(std::string tag, std::string val); // method

        Pax *get(std::string tag); // method
        bool del(std::string tag); // method

        size_t cnt(void);                // method
        std::vector<std::string> tags(); // method
        std::vector<Pax *> vals();       // method

        virtual std::vector<std::string> XML() = 0; // method

    }; // class

} // namespace

#endif // __SubSet_h__
