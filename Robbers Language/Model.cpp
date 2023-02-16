#include <iostream>
#include "Model.h"

Model::Model() {
    
}

Model::~Model() {

}

std::string Model::translateSingleConsonant(char singleConsonant) {
    std::string robbersConsonantString;
    robbersConsonantString += singleConsonant;
    robbersConsonantString += 'o';
    robbersConsonantString += singleConsonant;
    return robbersConsonantString;
}

std::string Model::translateSingleVowel(char singleVowel) {
    return std::string(1, singleVowel);
}
