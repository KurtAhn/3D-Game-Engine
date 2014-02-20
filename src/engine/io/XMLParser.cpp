#include "XMLParser.h"

XMLParser::XMLParser() {}

XMLParser::XMLParser(const std::string &path) {
    loadDocument(path);
}

XMLParser::~XMLParser() {
    delete document;
}

xml_document<> *const &XMLParser::getDocument() const {
    return document;
}

xml_document<> *const &XMLParser::loadDocument(const std::string &path) {
    std::ifstream file(path);
    std::string line;
    std::string source;

    while (getline(file, line))
        source += line + "\n";

    file.close();

    document = new xml_document<>;
    document->parse<0>(const_cast<char*>(source.c_str()));

    return document;
}

void XMLParser::saveDocument(const std::string &path) {
    std::string source;
    print(std::back_inserter(source), *document, 0);

    std::istringstream sourceIn(source);

    std::ofstream file(path);
    std::string line;

    while (getline(sourceIn, line))
        file << line << std::endl;

    file.close();
}
