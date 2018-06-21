#include "SubtitleIO.h"

#include <QMessageBox>
#include <regex>

Subtitles* SubtitleIO::load(const string & path) {
    ifstream inFile(path);
    string line;
    Subtitles* subtitles = new Subtitles();

    if (!inFile.is_open()) {
       // cout << "Cannot open file.";
        throw CannotOpenFileException();
    }

    while (getline(inFile, line)) {
        processInputLine(*subtitles, line);
    }
    processInputLine(*subtitles, ""); // save the last subtitle

    inFile.close();

    return subtitles;
}

void SubtitleIO::save(const string & path, const Subtitles& subtitles) {
    ofstream outFile(path);

    if (!outFile.is_open()) {
        throw CannotWriteFileException();
    }

    while (true) {
        try {
            outFile << processOutputLine(subtitles);
        } catch (NoMoreSubtitlesException) {
            outFile.close();
            break;
        }
    }
}

bool SubtitleIO::checkSRT(const string path) {
    ifstream inFile(path);
    string line;
    Subtitles* subtitles = new Subtitles();

//    if (!inFile.is_open()) {
//       // cout << "Cannot open file.";
//        throw CannotOpenFileException();
//    }

    while (getline(inFile, line)) {
        string tmpStr;
        //processInputLine(*subtitles, line);
        if (line != "") {
            tmpStr += line + "\n";
        } else {
            if (line[0] != '0') {

            }
        }

    }
   // processInputLine(*subtitles, ""); // save the last subtitle

    inFile.close();
    return true;
}

