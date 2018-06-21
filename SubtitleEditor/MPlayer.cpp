#include "MPlayer.h"

#include <cstdio>


/*
* Recives line by line of the SUB file, creates Subtitle objects
* and inserts them into subtitles list
*/
void MPlayer::processInputLine(Subtitles & subtitles, const string & line) {
	static enum Status { TIME_STAMPS, SUBTITLE_CONTENT } status = TIME_STAMPS;
	static TimeStamp* timeOfAppearance = nullptr;
	static TimeStamp* timeOfRemoval = nullptr;
	static string subtitleText = "";
	static double time = 0.0;

	/*
	 *   enum status represents various situations depending on the
	 *   line recieved:
	 *
	 * 110.35 2.07			// TIME_STAMPS - creates timestamps objects
	 * - Captain.			// SUBTITLE_CONTENT - appends this line to subtitleText
	 * - Yes, sir ?			// SUBTITLE_CONTENT - appends this line to subtitleText again
	 *						// SUBTITLE_CONTENT - create subtitle, add it to subtitles, reset parameters, go to TIME_STAMPS phase
	 * 0.13 2.04
	 *  Tell them we wish
	 *  to board at once.
	 */

	switch (status) {
	case TIME_STAMPS:
	{
		double time1, time2;

		sscanf(line.c_str(), "%lf %lf", &time1, &time2);

		timeOfAppearance = new TimeStamp(time + time1);
		timeOfRemoval = new TimeStamp(time + time1 + time2);

		time += time1 + time2;

		status = SUBTITLE_CONTENT;
	}
	break;

	case SUBTITLE_CONTENT:
	{
		smatch s;
		if (!(line == "" || regex_search(line, s, regex("^\\s*$")))) {
			if (line == "") time = 0.0;
			subtitleText += line + "\n";
		} else {
			Subtitle subtitle(subtitleText, *timeOfAppearance, *timeOfRemoval);
			try {
				subtitles.push_back(subtitle);
			} catch (TimesOverlapException) {
				throw;
			}

			subtitleText = "";
			delete timeOfAppearance;
			delete timeOfRemoval;

			status = TIME_STAMPS;
		}
	}
	break;

	default:
		break;
	}
	

}

/*
* Returns The next line to be writen to the output file.
* Works similarly to void processInputLine(Subtitles& subtitles, const string& line), but reversed.
* When all elements are printed, all the parameters are restarted and the function returns NoMoreSubtitlesException.
*/
const string MPlayer::processOutputLine(const Subtitles & subtitles) const {
	static enum Status { TIME_STAMPS, SUBTITLE_CONTENT, NEXT } status = TIME_STAMPS;
	static auto i = subtitles.begin();
	static double time = 0.0;

	/*
	*   enum status represents various situations depending on the
	*   line recieved:
	*
	* 110.35 2.07			// TIME_STAMPS - print times
	* - Captain.			// SUBTITLE_CONTENT - print string
	* - Yes, sir ?			// SUBTITLE_CONTENT - print string
	*						// print a new line move to the next element, go to TIME_STAMPS phase
	* 0.13 2.04
	*  Tell them we wish
	*  to board at once.
	*/
	switch (status) {
	case TIME_STAMPS:
	{
		if (i == subtitles.end()) {
			time = 0.0;
			i = subtitles.begin();
			throw NoMoreSubtitlesException();
		}
		char tmpLine[100]; // no need for more

		sprintf(tmpLine, "%.2f %.2f\n", i->getTimeOfAppearance().getTimeInSeconds() - time, i->getTimeOfRemoval().getTimeInSeconds() - i->getTimeOfAppearance().getTimeInSeconds()) ;

		time = i->getTimeOfRemoval().getTimeInSeconds();

		status = SUBTITLE_CONTENT;
		return tmpLine;
	}
	break;
	case SUBTITLE_CONTENT:
	{
		status = NEXT;
		return i->getSubtitleText();
	}
	break;
	case NEXT:
	{
		++i;

		if (i == subtitles.end()) {
			time = 0.0;
			i = subtitles.begin();
			status = TIME_STAMPS;
			throw NoMoreSubtitlesException();
		}

		status = TIME_STAMPS;

		return "\n";
	}
	break;
	default:
		break;
	}


}
