#include <iostream>
#include "Model.h"
#include "Translator.h"
#include "FileProcessor.h"

int main() {
    Model m;
    //m.translateSingleVowel('a');
    //m.translateSinlngeConsonant('c');
    Translator h;
    //h.translateEnglishWord("Theres");
    //h.translateEnglishSentence("Hello there, chicken is good!");
    FileProcessor f;
    f.processFile("hello.txt", "translation.html");
}