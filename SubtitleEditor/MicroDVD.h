#ifndef _MICRODVD_H_
#define _MICRODVD_H_

#include "SubtitleIO.h"


class MicroDVD :public SubtitleIO {
public:
	MicroDVD(double fps = 25);
	
    virtual void processInputLine(Subtitles& subtitles, const string& line) override;
    virtual const string processOutputLine(const Subtitles& subtitles) const override;
private:
	double fps;
};

#endif

