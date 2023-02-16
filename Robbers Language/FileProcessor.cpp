#include <iostream>
#include <fstream>
#include "FileProcessor.h"
#include "Translator.h"


FileProcessor::FileProcessor() {

}

FileProcessor::~FileProcessor() {

}

void FileProcessor::processFile(std::string inputFile, std::string outputFile) {
    std::fstream file;
    Translator translate;
    file.open(outputFile, std::ios::out);
    if(file.is_open()) {
        file << "<html><body><p>" << std::endl;
        file << "<b>" << inputFile << "</b>" << "<br>" << "<br>" << std::endl;
        file << "<i>" << translate.translateEnglishSentence(inputFile) << "</i>" << "<br>" << "<br>" << std::endl;
        file << "</p></body></html>" << std::endl;
        file.close();
    } else {
        std::cout << "error" << std::endl;
        file.close();
    }
}