#ifndef _EXCEPTIONS_H_
#define _EXCEPTIONS_H_

#include<exception>
using namespace std;

class NoMoreSubtitlesException : public exception {
public:
	virtual const char* what(void) const throw() override {
		return "End of subtitle container reached.";
	}
};

class TimesOverlapException : public exception {
public:
	virtual const char* what(void) const throw() override {
		return "Times of 2 subtitles overlap.";
	}
};

class CannotOpenFileException : public exception {
public:
    virtual const char* what(void) const throw() override {
        return "There was an error while opening the file";
    }
};

class CannotWriteFileException : public exception {
public:
    virtual const char* what(void) const throw() override {
        return "There was an error while writing to file";
    }
};
#endif
