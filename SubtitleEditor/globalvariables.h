#ifndef GLOBALVARIABLES_H
#define GLOBALVARIABLES_H

#include "SubtitleIO.h"

#include <QString>
#include <QDialog>

#define nullIterator GlobalVariables::dummyVector->end()

namespace GlobalVariables {
    extern QString inFilePath;
    extern QString outFilePath;

    extern SubtitleIO* inSubtitle;
    extern SubtitleIO* outSubtitle;
    extern Subtitles* subtitles;

    extern vector<Subtitle> *dummyVector;
    extern vector<Subtitle>::iterator iter;
}


#endif // GLOBALVARIABLES_H
