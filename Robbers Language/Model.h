#ifndef MODEL_H
#define MODEL_H

class Model {
    public:
        Model();
        ~Model();
        std::string translateSingleConsonant(char singleConsonant);
        std::string translateSingleVowel(char singleVowel);
};

#endif