#include "MicroDVD.h"

MicroDVD::MicroDVD(double fps) {
	this->fps = fps;
}

void MicroDVD::processInputLine(Subtitles & subtitles, const string & line) {

	if (line == "") return;

	smatch results;

	regex_match(line, results, regex("^\\{(\\d+)\\}\\{(\\d+)\\}.*"));
	
	TimeStamp timeOfAppearance(stoi(results[1]) / (double) fps);
	TimeStamp timeOfRemoval(stoi(results[2]) / (double)fps);

	regex_match(line, results, regex("^\\{\\d+\\}\\{\\d+\\}(.*)$"));



	string tmpLine = results[1];

	replace(tmpLine.begin(), tmpLine.end(), '|', '\n');

	Subtitle subtitle(tmpLine + "\n", timeOfAppearance, timeOfRemoval);

	subtitles.push_back(subtitle);

}

const string MicroDVD::processOutputLine(const Subtitles & subtitles) const {
	static auto i = subtitles.begin();

	if (i == subtitles.end()) {
		auto i = subtitles.begin();
		throw NoMoreSubtitlesException();
	}

	string ret = "{" + to_string( (int) (round(i->getTimeOfAppearance().getTimeInSeconds() * fps))) + "}" + \
		"{" + to_string( (int) (round(i->getTimeOfRemoval().getTimeInSeconds() * fps))) + "}" + \
		i->getSubtitleText();

	replace(ret.begin(), ret.end(), '\n', '|');
	ret.back() = '\n';
		
	++i;

	return ret;
}


