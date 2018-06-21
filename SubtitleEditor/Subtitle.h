#ifndef _SUBTITLE_H_
#define _SUBTITLE_H_

#include "TimeStamp.h"


class Subtitle {
public:
	Subtitle(const string& subtitleText, TimeStamp timeOfAppearance, TimeStamp timeOfRemoval);

    const string& getSubtitleText() const;
	const TimeStamp& getTimeOfAppearance() const;
	const TimeStamp& getTimeOfRemoval() const;

    void setSubtitleText(const string subtitleText);
    void setTimeOfAppearance(const TimeStamp timeOfAppearance);
    void setTimeOfRemoval(const TimeStamp timeOfRemoval);

	bool operator==(const Subtitle& sub) const;
	bool operator!=(const Subtitle& sub) const;
	bool operator>(const Subtitle& sub) const;
	bool operator<(const Subtitle& sub) const;

    int getID() const;
    void setID(int ID);

private:
    static int IDCnt;
    int ID = IDCnt++;
	string subtitleText;
	TimeStamp timeOfAppearance;
	TimeStamp timeOfRemoval;

};

#endif

