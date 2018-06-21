#include "Subtitle.h"

int Subtitle::IDCnt = 0;

Subtitle::Subtitle(const string& subtitleText, TimeStamp timeOfAppearance, TimeStamp timeOfRemoval) {
	this->subtitleText = subtitleText;
	this->timeOfAppearance = timeOfAppearance;
	this->timeOfRemoval = timeOfRemoval;
}

const string &Subtitle::getSubtitleText() const {
	return subtitleText;
}

const TimeStamp & Subtitle::getTimeOfAppearance() const {
	return timeOfAppearance;
}

const TimeStamp & Subtitle::getTimeOfRemoval() const {
	return timeOfRemoval;
}

bool Subtitle::operator==(const Subtitle & sub) const {
	return subtitleText == sub.getSubtitleText() && timeOfAppearance == sub.getTimeOfAppearance() && timeOfRemoval == sub.getTimeOfRemoval();
}

bool Subtitle::operator!=(const Subtitle & sub) const {
	return !operator==(sub);
}

bool Subtitle::operator>(const Subtitle & sub) const {
	return timeOfAppearance > sub.getTimeOfAppearance();
}

bool Subtitle::operator<(const Subtitle & sub) const {
	return timeOfAppearance < sub.getTimeOfAppearance();
}

int Subtitle::getID() const {
    return ID;
}

void Subtitle::setID(int ID) {
    this->ID = ID;
}

void Subtitle::setSubtitleText(const string subtitleText) {
    this->subtitleText = subtitleText;
}

void Subtitle::setTimeOfAppearance(const TimeStamp timeOfAppearance) {
    this->timeOfAppearance = timeOfAppearance;
}

void Subtitle::setTimeOfRemoval(const TimeStamp timeOfRemoval) {
    this->timeOfRemoval = timeOfRemoval;
}
