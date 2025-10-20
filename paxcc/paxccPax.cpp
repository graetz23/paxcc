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

namespace PAXCC
{

    Pax::Pax(void)
    {
        _attributes = new Attributes(this);
        _children = new Children(this);
        _tag.clear();
        _val.clear();
    } // constructor

    Pax::Pax(std::string tag)
    {
        _attributes = new Attributes(this);
        _children = new Children(this);
        _tag = tag;
        _val.clear();
    } // constructor

    Pax::Pax(std::string tag, std::string val)
    {
        _attributes = new Attributes(this);
        _children = new Children(this);
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
        _val.clear();
        _tag.clear();
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

    bool
    Pax::hasTag(void)
    {
        bool hasTag = false;
        std::string tag = Tag();
        if (!tag.empty())
        {
            hasTag = true;
        } // if
        return hasTag;
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
    Pax::hasVal(void)
    {
        bool hasVal = false;
        std::string val = Val();
        if (!val.empty())
        {
            hasVal = true;
        } // if
        return hasVal;
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
        if (cnt > 0)
        {
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
        if (cnt > 0)
        {
            hasChild = true;
        } // if
        return hasChild;
    } // method

    size_t
    Pax::cntChilds()
    {
        size_t cnt = Child()->cnt();
        return cnt;
    } // method

    std::vector<Pax *> Pax::Childs()
    {
        std::vector<Pax *> vec = Child()->vals();
        return vec;
    } // method

    Pax *
    Pax::Dad(void)
    {
        return Child()->dad();
    } // method

    std::string Pax::XML(void)
    {
        std::string xml;
        std::vector<std::string> lines = XML_lines();
        for (size_t l = 0; l < lines.size(); l++)
        {
            xml.append(lines[l]);
            xml.append("\n");
        } // loop
        return xml;
    } // method

    std::vector<std::string>
    Pax::XML_lines(uint indent)
    {
        std::vector<std::string> vec;
        std::string whitespaces = "";
        if (indent > 0)
        {
            for (uint w = 0; w < indent; w++)
            {
                whitespaces.append(" ");
            } // loop
        } // if
        if (!hasChild())
        {
            if (!hasAttrib())
            { // no attributes
                if (!hasVal())
                { // standalone tag
                    std::string xml;
                    xml.append(whitespaces);
                    std::string tag = Tag();
                    xml.append("<");
                    xml.append(tag);
                    xml.append(" />");
                    vec.push_back(xml);
                }
                else
                { // tag value
                    std::string xml;
                    xml.append(whitespaces);
                    std::string tag = Tag();
                    std::string val = Val();
                    xml.append("<");
                    xml.append(tag);
                    xml.append(">");
                    xml.append(val);
                    xml.append("</");
                    xml.append(tag);
                    xml.append(">");
                    vec.push_back(xml);
                } // if
            }
            else
            { // add attributes
                if (!hasVal())
                { // standalone tag attributes
                    std::string xml;
                    xml.append(whitespaces);
                    std::string tag = Tag();
                    std::string attribs = Attrib()->XML();
                    xml.append("<");
                    xml.append(tag);
                    xml.append(" ");
                    xml.append(attribs);
                    xml.append(" />");
                    vec.push_back(xml);
                }
                else
                { // tag attributes value
                    std::string xml;
                    xml.append(whitespaces);
                    std::string tag = Tag();
                    std::string val = Val();
                    std::string attribs = Attrib()->XML();
                    xml.append("<");
                    xml.append(tag);
                    xml.append(" ");
                    xml.append(attribs);
                    xml.append(">");
                    xml.append(val);
                    xml.append("</");
                    xml.append(tag);
                    xml.append(">");
                    vec.push_back(xml);
                } // if
            } // if
        }
        else
        { // recurse instead of value
            std::string tag = Tag();
            if (!hasAttrib())
            { // no attributes
                std::string xml_;
                xml_.append(whitespaces);
                xml_.append("<");
                xml_.append(tag);
                xml_.append(">");
                vec.push_back(xml_);
            }
            else
            { // add attributes
                std::string xml_;
                xml_.append(whitespaces);
                std::string attribs = Attrib()->XML();
                xml_.append("<");
                xml_.append(tag);
                xml_.append(" ");
                xml_.append(attribs);
                xml_.append(">");
                vec.push_back(xml_);

            } // if

            std::string xml;
            xml.append(whitespaces);

            size_t cnt = cntChilds();
            std::vector<Pax *> paxs = Childs();
            indent += 2;
            for (size_t p = 0; p < cnt; p++)
            { // here we go recursive ..
                Pax *child = paxs[p];
                std::vector<std::string> xmlLines = child->XML_lines(indent);
                vec.insert(std::end(vec), std::begin(xmlLines), std::end(xmlLines));
            } // loop
            indent -= 2;

            xml.append("</");
            xml.append(tag);
            xml.append(">");
            vec.push_back(xml);

        } // if
        return vec;
    } // method

} // namespace
