#ifndef _SUBTITLEIO_H_
#define _SUBTITLEIO_H_

#include "Subtitles.h"
//#include "Exceptions.h"

#include <fstream>
#include <regex>
#include <algorithm>
using namespace std;

class SubtitleIO {
public:
    SubtitleIO(void) {}

    Subtitles* load(const string& path);
    void save(const string& path, const Subtitles& subtitles);

    static bool checkSRT (const string path);


protected:
    virtual void processInputLine(Subtitles& subtitles, const string& line) = 0;
    virtual const string processOutputLine(const Subtitles& subtitles) const = 0;

//protected:
//	ofstream* outfile = nullptr;
//
//private:
//	ifstream* infile = nullptr;
};

#endif
