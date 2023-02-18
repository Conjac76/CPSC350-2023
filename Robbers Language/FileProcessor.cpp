#include <iostream>
#include <fstream>
#include "FileProcessor.h"
#include "Translator.h"


FileProcessor::FileProcessor() {

}

FileProcessor::~FileProcessor() {

}

void FileProcessor::processFile(std::string inputFile, std::string outputFile) {
    std::fstream output;
    std::fstream input;
    Translator translate;
    output.open(outputFile, std::ios::out);
    input.open(inputFile, std::ios::in);
    std::string textFromFile;
    std::string lineFromFile = "";
    if(input.is_open()) {
        while(std::getline(input, textFromFile)){
            lineFromFile += textFromFile;
        }
        input.close();
    }
    
    if(output.is_open()) {
        output << "<html>" << std::endl;
        output << "<body>" << std::endl;
        output << "<p><b>" << lineFromFile << "</b></p>" << std::endl;
        output << "<p><i>" << translate.translateEnglishSentence(lineFromFile) << "</i></p>" << "<br>" << "<br>" << std::endl;
        output << "</body>" << std::endl;
        output << "</html>" << std::endl;
        output.close();
    } else {
        std::cout << "error" << std::endl;
    }
}