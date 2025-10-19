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

#include "./paxccPax.h"
#include "./paxccAttributes.h"

namespace PAXCC
{
    class Pax; // we link em up ..

    Attributes::Attributes()
    {
    } // constructor

    Attributes::~Attributes()
    {
    } // destructor

    std::string
    Attributes::XML(void)
    {
        std::string xml;
        size_t cnt = this->cnt();
        if (cnt > 0)
        {
            std::vector<Pax *> paxs = this->vals();
            for (size_t p = 0; p < cnt; p++)
            {
                Pax *pax = paxs[p];
                std::string tag = pax->Tag();
                xml.append(tag);
                xml.append("=\"");
                if (pax->hasVal())
                {
                    std::string val = pax->Val();
                    xml.append(val);
                } // if
                xml.append("\"");
                if (p + 1 < cnt)
                {
                    xml.append(" ");
                } // if
            } // loop
        } // if
        return xml;
    } // method

} // namespace
