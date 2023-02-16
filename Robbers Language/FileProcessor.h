#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H

class FileProcessor {
    public:
        FileProcessor();
        ~FileProcessor();
        void processFile(std::string inputFile, std::string outputFile);
};

#endif
