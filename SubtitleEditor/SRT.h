#ifndef _SRT_H_
#define _SRT_H_

#include "SubtitleIO.h"

class SRT : public SubtitleIO {
protected:
    virtual void processInputLine(Subtitles& subtitles, const string& line) override;
    virtual const string processOutputLine(const Subtitles& subtitles) const override;

private:

    struct TimeStamps {
        TimeStamp timeOfAppearance;
        TimeStamp timeOfRemoval;
    };


    TimeStamps* processTimeStampLine(const string& line);
};



#endif
