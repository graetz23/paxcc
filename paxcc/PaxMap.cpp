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

#include "./PaxMap.h"

namespace PAXCC
{

    PaxMap::PaxMap(void)
    {
    } // constructor

    PaxMap::~PaxMap(void)
    {
    } // destructor

    bool
    PaxMap::has(std::string key)
    {
        bool isStored = false;
        if (_map.count(key) > 0)
        {
            isStored = true;
        } // if
        return isStored;
    } // method

    bool
    PaxMap::add(std::string key, std::string value)
    {
        bool wasStored = false;
        if (!has(key))
        {
            _seq.push_back(key);
            _map[key] = value;
        } // if
        return wasStored;
    } // method

    std::string
    PaxMap::get(std::string key)
    {
        return _map[key];
    } // method

    bool
    PaxMap::del(std::string key)
    {
        bool wasDeleted = false;
        if (has(key))
        { // take from map and sequence ..
            _map.erase(key);
            _seq.erase(std::remove(_seq.begin(), _seq.end(), key), _seq.end());
            wasDeleted = true;
        } // if
        return wasDeleted;
    } // method

    std::size_t
    PaxMap::cnt(void)
    {
        std::size_t count = 0;
        count = _seq.size();
        return count;
    } // method

    std::vector<std::string>
    PaxMap::keys()
    {
        std::vector<std::string> vec;
        if (cnt() > 0)
        {
            for (size_t k = 0; k < cnt(); k++)
            {
                std::string key = _seq[k];
                vec.push_back(key);
            } // loop
        } // if
        return vec;
    } // method

    std::vector<std::string>
    PaxMap::vals()
    {
        std::vector<std::string> vec;
        if (cnt() > 0)
        {
            for (size_t k = 0; k < cnt(); k++)
            {
                std::string key = _seq[k];
                if (has(key))
                { // however, not necessarily ..
                    std::string val = _map[key];
                    vec.push_back(val);
                } // if
            } // loop
        } // if
        return vec;
    } // method

    void
    PaxMap::dbg(void)
    {

        PaxMap pax;
        pax.add("Bob", "Dylan");

        for (int i = 0; i < 100; i++)
        {
            std::string key = std::to_string(i + 1);
            std::string val = std::to_string((i + 1) * (i + 1));
            pax.add(key, val);
        } // loop

        bool isStored = pax.has("42");

        bool wasDeleted = pax.del("23");

        std::vector<std::string> keys = pax.keys();
        std::vector<std::string> vals = pax.vals();
        for (std::size_t k = 0; k < keys.size(); k++)
        { // those are of same size
            std::string key = keys[k];
            std::string val = vals[k];
            std::cout
                << "key: " << key
                << " => "
                << "val: " << val
                << std::endl
                << std::flush;
        } // loop
    } // method

} // namespace