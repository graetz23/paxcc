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

#include "dirent.h" // only UNIX ..
#include "./paxccReader.h"
#include "./paxccSysXmlParser.h"      // SAX::Handler
#include "./paxccSaxHandler.h"        // SAX::Handler
#include "./paxccSaxHandlerExample.h" // SAX::HandlerExample
#include "./paxccSaxHandlerPax.h"     // SAX::HandlerPax

namespace PAXCC
{

    PaxReader::PaxReader(void)
    {
        _paxHandler = new SAX::HandlerPax();
        _parser = new SYS::XmlParser(_paxHandler);
    } // constructor

    PaxReader::~PaxReader(void)
    {
        if (_parser != 0)
        {
            delete _parser;
            _parser = 0;
        } // if

        if (_paxHandler != 0)
        {
            delete _paxHandler;
            _paxHandler = 0;
        } // if
    } // destructor

    Pax *PaxReader::read(const Str fileName)
    {
        // std::cout << "PaxReader::read(): Reading file '" << fileName << "' .." << std::endl;
        // use the XML parser to read the file
        _parser->parse(fileName);
        Pax *root = _paxHandler->Root();
        return root;
    } // read

    std::vector<Pax *> // read all files in folder
    PaxReader::readAll(const Str folderPath)
    {
        std::vector<Pax *> paxList;
        std::vector<std::string> filePaths = listFiles(folderPath);
        for (size_t i = 0; i < filePaths.size(); i++)
        {
            std::string filePath = filePaths[i];
            std::string ending = ".xml";
            std::string ending2 = ".XML";
            bool readFile = false;
            if (!filePath.empty())
            {
                int cmp = filePath.compare(filePath.size() - ending.size(), ending.size(), ending);
                if (cmp == 0)
                {
                    readFile = true;
                } // if

                int cmp2 = filePath.compare(filePath.size() - ending2.size(), ending2.size(), ending2);
                if (cmp2 == 0)
                {
                    readFile = true;
                } // if
            } // if
            if (readFile)
            {
                Pax *pax = read(filePath);
                if (pax != 0)
                {
                    paxList.push_back(pax);
                } // if
            } // if
        } // loop
        return paxList;
    } // method

    std::vector<Pax *> // read all files in folder
    PaxReader::readAll(
        const Str folderPath,
        const Str fileEnding)
    {
        std::vector<Pax *> paxList;
        std::vector<std::string> filePaths = listFiles(folderPath);
        for (size_t i = 0; i < filePaths.size(); i++)
        {
            std::string filePath = filePaths[i];
            bool readFile = false;
            if (!filePath.empty())
            {
                int cmp = filePath.compare(filePath.size() - fileEnding.size(), fileEnding.size(), fileEnding);
                if (cmp == 0)
                {
                    readFile = true;
                } // if
            } // if
            if (readFile)
            {
                Pax *pax = read(filePath);
                if (pax != 0)
                {
                    paxList.push_back(pax);
                } // if
            }
            else
            {
                std::cout << "PaxReader::readAll(): skipping file '" << filePath << "' due to file ending mismatch .." << std::endl;
            } // if
        } // loop
        return paxList;
    } // method

    std::vector<std::string> // all files in folder
    PaxReader::listFiles(std::string folderPath)
    {
        std::vector<std::string> filePaths;
        ;
        if (!folderPath.empty() && *folderPath.rbegin() != '/')
        {
            folderPath += '/'; // make sure it ends with a slash ..
        } // if
        const char *folderPath_ = folderPath.c_str();
        DIR *directory = opendir(folderPath_);
        if (directory != NULL)
        {
            struct dirent *fileName_ = NULL;
            // readDir has to be called often ..
            while ((fileName_ = readdir(directory)) != NULL)
            {
                std::string fileName = std::string(fileName_->d_name);
                // std::cout << fileName << std::endl;
                std::string filePath = folderPath;
                filePath.append(fileName);
                // std::cout << filePath << std::endl;
                filePaths.push_back(filePath);
            } // loop
            if (filePaths.size() > 2)
            {
                filePaths.erase(filePaths.begin()); // remove .
                filePaths.erase(filePaths.begin()); // remove ..
            } // if
            std::sort(filePaths.begin(), filePaths.end());
            closedir(directory);
        }
        else
        { // could not open directory
            std::cout << "can not find directory " << folderPath << std::endl;
        } // if
        return filePaths;
    } // method

} // namespace PAXCC
