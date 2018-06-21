#include "Subtitles.h"

void Subtitles::push_back(const Subtitle & subtitle) {
	if (size() != 0 && subtitle .getTimeOfAppearance() < back().getTimeOfRemoval()) {
		throw TimesOverlapException();
	}

    vector<Subtitle>::push_back(subtitle);
}
