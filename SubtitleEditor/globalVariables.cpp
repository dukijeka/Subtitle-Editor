#include "globalVariables.h"

QString GlobalVariables::inFilePath = nullptr;
QString GlobalVariables::outFilePath = nullptr;

SubtitleIO* GlobalVariables::inSubtitle = nullptr;
SubtitleIO* GlobalVariables::outSubtitle = nullptr;

Subtitles* GlobalVariables::subtitles = nullptr;

vector<Subtitle>* GlobalVariables::dummyVector = new vector<Subtitle>();
vector<Subtitle>::iterator GlobalVariables::iter = nullIterator;
