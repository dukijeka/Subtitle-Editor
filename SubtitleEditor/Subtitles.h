#ifndef _SUBTITLES_H
#define _SUBTITLES_H

#include "Subtitle.h"
#include "Exceptions.h"

#include <vector>

class Subtitles : public vector<Subtitle> {
public:
    void push_back(const Subtitle &  subtitle);
}; 


#endif
