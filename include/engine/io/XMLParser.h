#ifndef XMLPARSER_H
#define XMLPARSER_H

#include "FileIOCommon.h"

using namespace rapidxml;

class XMLParser {
public:
    XMLParser();
    XMLParser(const std::string &filePath);
    XMLParser(const XMLParser &src) = delete;
    XMLParser &operator=(const XMLParser &src) = delete;
    virtual ~XMLParser();

    xml_document<> *const &getDocument() const;

    xml_document<> *const &loadDocument(const std::string &filePath);
    void saveDocument(const std::string &filePath);

private:
    xml_document<> *document;
    std::string source;
};

#endif // XMLPARSER_H
