#ifndef XMLPARSER_H
#define XMLPARSER_H

#include "Common.h"

using namespace rapidxml;

class XMLParser {
public:
    XMLParser();
    XMLParser(const std::string &path);
    XMLParser(const XMLParser &src) = delete;
    XMLParser &operator=(const XMLParser &src) = delete;
    virtual ~XMLParser();

    xml_document<> *const &getDocument() const;

    xml_document<> *const &loadDocument(const std::string &path);
    void saveDocument(const std::string &path);

private:
    xml_document<> *document;
    std::string source;
};

#endif // XMLPARSER_H
