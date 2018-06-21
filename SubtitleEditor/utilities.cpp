// utilities.cpp

#include "utilities.h"

/*
 * Is the file provided MicroDVD subtitle
 */
bool isItMicroDVD(QString path) {
    ifstream inFile(path.toStdString());
    string line;

    if (!inFile.is_open()) {
       // cout << "Cannot open file.";
        throw CannotOpenFileException();
    }

    while (getline(inFile, line)) {
        if (line[0] != '{') {
            inFile.close();
            return false;
        }
    }

    inFile.close();

    return true;
}
