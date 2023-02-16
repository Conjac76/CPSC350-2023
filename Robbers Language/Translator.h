#ifndef TRANSLATOR_H
#define TRANSLATOR_H

class Translator {
    public:
        Translator();
        ~Translator();
        std::string translateEnglishWord(std::string singleWord);
        std::string translateEnglishSentence(std::string singleSentence);
};

#endif
