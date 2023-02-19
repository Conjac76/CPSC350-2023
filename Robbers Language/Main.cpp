#include <iostream>
#include "Model.h"
#include "Translator.h"
#include "FileProcessor.h"

int main() {
    FileProcessor f;
    f.processFile("hello.txt", "translation.html");
}