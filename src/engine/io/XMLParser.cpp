#include "XMLParser.h"

XMLParser::XMLParser() {}

XMLParser::XMLParser(const std::string &filePath) {
    loadDocument(filePath);
}

XMLParser::~XMLParser() {
    delete document;
}

xml_document<> *const &XMLParser::getDocument() const {
    return document;
}

xml_document<> *const &XMLParser::loadDocument(const std::string &filePath) {
    try {
        std::ifstream file(filePath);

        if (!file)
            throw IOException("Failed to load: " + filePath);

        std::ostringstream buffer;
        buffer << file.rdbuf();// << std::endl;
        //std::vector<char> bufferCopy(buffer.str().begin(), buffer.str().end());
        //bufferCopy.push_back('\0');
        source = buffer.str();

        document = new xml_document<>;
        //document->parse<0>(csource.c_str());
        document->parse<0>(const_cast<char*>(source.c_str()));
        file.close();
    } catch (std::runtime_error &e) {
        LOG_ERROR(e);
        document = nullptr;
    }

    return document;
/*
    std::ifstream file(path);
    std::string line;
    std::string source;

    while (getline(file, line))
        source += line + "\n";

    file.close();

    document = new xml_document<>;
    document->parse<0>(const_cast<char*>(source.c_str()));

    return document;*/
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
