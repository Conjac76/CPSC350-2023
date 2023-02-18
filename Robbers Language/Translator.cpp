#include <iostream>
#include "Translator.h"
#include "Model.h"

Translator::Translator() {
}

Translator::~Translator() {
}

std::string Translator::translateEnglishWord(std::string singleWord) {
    Model model;
    std::string printString;
    for(int i = 0; i < singleWord.size(); ++i) {
     
        char singleChar = singleWord[i]; 
        // Translates single consonant.
        if(singleChar == 'b'||singleChar == 'c'||singleChar == 'd'||singleChar == 'f'||singleChar == 'g'
                ||singleChar == 'h'||singleChar == 'j'||singleChar == 'k'||singleChar == 'l'||singleChar == 'm'
                ||singleChar == 'n'||singleChar == 'p'||singleChar == 'q'||singleChar == 'r'||singleChar == 's'
                ||singleChar == 't'||singleChar == 'v'||singleChar == 'w'||singleChar == 'x'||singleChar == 'y'
                ||singleChar == 'z'||singleChar == 'B'||singleChar == 'C'||singleChar == 'D'||singleChar == 'F'
                ||singleChar == 'G'||singleChar == 'H'||singleChar == 'J'||singleChar == 'K'||singleChar == 'L'
                ||singleChar == 'M'||singleChar == 'N'||singleChar == 'P'||singleChar == 'Q'||singleChar == 'R'
                ||singleChar == 'S'||singleChar == 'T'||singleChar == 'V'||singleChar == 'W'||singleChar == 'X'
                ||singleChar == 'Y'||singleChar == 'Z') {
            printString += model.translateSingleConsonant(singleChar);
        // Translate vowels.
        } else if (singleChar == 'a'||singleChar == 'e'||singleChar == 'i'||singleChar == 'o'||singleChar == 'u'
                ||singleChar == 'A'||singleChar == 'E'||singleChar == 'I'||singleChar == 'O'||singleChar == 'U') {
            printString += model.translateSingleVowel(singleChar);
        // No translation required.
        } else {
            printString += singleChar;
        }
    }
    return printString;
}

std::string Translator::translateEnglishSentence(std::string singleSentence) {
    std::string printSentence;
    std::string word;
    for(int i = 0; i < singleSentence.size(); ++i) {
        char c = singleSentence[i];
            if(c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z') {
                word += c;
            }
            else {
                printSentence += translateEnglishWord(word) + c;
                word = "";
            } 
    }
    printSentence += translateEnglishWord(word);
    return printSentence; 
}