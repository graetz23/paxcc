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

#ifndef __PaxReader_h__
#define __PaxReader_h__

#include "./paxccDefines.h" // include the xml tooling libary
#include "./paxccSys.h" // include the xml tooling libary
#include "./paxccSaxHandlerPax.h" // include the xml tooling libary

namespace PAXCC
{

    class PaxReader {

        protected:
        
        SAX::HandlerPax* _paxHandler; /// XML handler instance

        SYS::XmlParser* _parser; /// XML parser instance

        public:
            
        PaxReader(void); // constructor
        virtual ~PaxReader(void); // destructor

        Pax* read(const Str fileName); // read from file

        std::vector<Pax*> readAll(const Str folderPath); // read all files in folder

        std::vector<Pax*> readAll(
            const Str folderPath, 
            const  Str fileEnding); // read all files in folder
    
        protected:

        std::vector<std::string> listFiles(std::string folderPath); // all files in folder

    }; // class

} // namespace PAXCC

 #endif // __PaxReader_h__
