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

#include <sstream>
#include "./Pax.h"
#include "./SubSet.h"

namespace PAXCC
{

    // it's all about the statics ..
    unsigned long long static _cnt = 0;
    std::string getNext()
    {
        std::string next;
        _cnt++;
        std::stringstream strstream;
        strstream << _cnt;
        strstream >> next;
        return next;
    } // method

    SubSet::SubSet()
    {
        _map = new PaxMap<Pax *>();
    } // constructor

    SubSet::~SubSet()
    { // deleting outside tree leads to no object here, thou we are doomed ..
        std::vector<Pax *> vec = _map->vals();
        for (size_t p = 0; p < vec.size(); p++)
        { // delete recursively all pax ..
            Pax *pax = vec[p];
            delete pax;
        } // loop
        delete _map;
        _map = nullptr;
    } // destructor

    bool
    SubSet::has(std::string tag)
    {
        return _map->has(tag);
    } // method

    bool
    SubSet::add(Pax *pax)
    {
        std::string tag = pax->Tag();
        if (has(tag))
        {
            std::string next = getNext();
            tag.append(" ");
            tag.append(next);
        } // if
        bool wasAdded = _map->add(tag, pax);
        return wasAdded;
    } // method

    bool SubSet::add(std::string tag)
    {
        bool wasAdded = false;
        Pax *pax = new Pax();
        pax->Tag(tag);
        wasAdded = add(pax);
        return wasAdded;
    } // method

    bool SubSet::add(std::string tag, std::string val)
    {
        bool wasAdded = false;
        Pax *pax = new Pax();
        pax->Tag(tag);
        pax->Val(val);
        wasAdded = add(pax);
        return wasAdded;
    } // method

    Pax *
    SubSet::get(std::string tag)
    {
        Pax *pax;
        if (has(tag))
        {
            pax = _map->get(tag);
        }
        else
        {
            pax = 0;
        } // if
        return pax;
    } // method

    bool
    SubSet::del(std::string tag)
    {
        bool wasDeleted = _map->del(tag);
        return wasDeleted;
    } // method

    size_t
    SubSet::cnt(void)
    {
        size_t cnt = _map->cnt();
        return cnt;
    } // method

    std::vector<std::string>
    SubSet::tags()
    {
        std::vector<std::string> vec = _map->keys();
        return vec;
    } // method

    std::vector<Pax *>
    SubSet::vals()
    {
        std::vector<Pax *> vec = _map->vals();
        return vec;
    } // method

} // namespace