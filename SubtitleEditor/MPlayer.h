#ifndef _MPLAYER_H_
#define _MPLAYER_H_

#include "SubtitleIO.h"

class MPlayer : public SubtitleIO {
public:

    virtual void processInputLine(Subtitles& subtitles, const string& line);
    virtual const string processOutputLine(const Subtitles& subtitles) const;
	
};


#endif
