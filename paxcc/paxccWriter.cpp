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

 #include "./paxccWriter.h"

namespace PAXCC
{
    PaxWriter::PaxWriter(void)
    {
        _parser = new SYS::XmlParser();
    } // constructor

    PaxWriter::~PaxWriter(void)
    {
        delete _parser;
    } // destructor

    void PaxWriter::write(const SYS::Str fileName, Pax* root)
    {
        // use the filestream to write the file
        std::string header = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";

        std::string xml_ = root->XML();  // generate XML from object tree ..
        SYS::FileStr fileStr;            // file string object
        fileStr.open(fileName, SYS::FileStrOut::out | SYS::FileStrOut::trunc); // open file
        fileStr << header; // write XML header to file        
        fileStr << xml_; // write XML to file
        fileStr.close(); // close file
    } // write

} // namespace PAXCC