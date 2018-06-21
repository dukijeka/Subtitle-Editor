#include "SRT.h"

#include <cstdio>


/*
 * Recives line by line of the SRT file, creates Subtitle objects
 * and inserts them into subtitles list
*/
void SRT::processInputLine(Subtitles & subtitles, const string & line) {
    static enum Status { SUBTITLE_NUMBER, TIME_STAMPS, SUBTITLE_CONTENT } status = SUBTITLE_NUMBER;
    static SRT::TimeStamps* timeStamps = nullptr;
    static string subtitleText = "";


    /*
    *   enum status represents various situations depending on the
    *   line recieved:
    *
    *   4										// SUBTITLE_NUMBER - error checking
    *	00:00 : 25, 000 --> 00:00 : 27, 500		// TIME_STAMPS - creates timestamps objects
    *	And I thought me and					// SUBTITLE_CONTENT - appends this line to subtitleText
    *	Qui - Gon Jinn could					// SUBTITLE_CONTENT - appends this line to subtitleText again
    *											// SUBTITLE_CONTENT - create subtitle, add it to subtitles, reset parameters, go to SUBTITLE_NUMBER phase
    *	5
    *	00 : 00 : 27, 500 --> 00:00 : 30, 000
    *	talk the Federation into
    */
    switch (status) {
    case SUBTITLE_NUMBER: {
        // TODO: error checking
        status = TIME_STAMPS;
    }
    break;
    case TIME_STAMPS: {
        timeStamps = processTimeStampLine(line);

        status = SUBTITLE_CONTENT;
    }
    break;

    case SUBTITLE_CONTENT: {
        smatch s;
        if (!(line == "" || regex_search(line, s, regex("^\\s*$")))) {
            subtitleText += line + "\n";
        } else {
            Subtitle subtitle(subtitleText, timeStamps->timeOfAppearance, timeStamps->timeOfRemoval);
            try {
                subtitles.push_back(subtitle);
            } catch (TimesOverlapException){
                throw;
            }

            subtitleText = "";
            delete timeStamps;

            status = SUBTITLE_NUMBER;
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
const string SRT::processOutputLine(const Subtitles & subtitles) const {
    static enum Status { SUBTITLE_NUMBER, TIME_STAMPS, SUBTITLE_CONTENT, NEXT } status = SUBTITLE_NUMBER;
    static auto i = subtitles.begin();
    static int lineNumber = 1;

    /*
    *   enum status represents various situations depending on the
    *   line recieved:
    *
    *   4										// SUBTITLE_NUMBER - print the line number
    *	00:00 : 25, 000 --> 00:00 : 27, 500		// TIME_STAMPS - print time stamps
    *	And I thought me and					// SUBTITLE_CONTENT - print subtitleText
    *	Qui - Gon Jinn could
    *											// print a new line move to the next element, go to SUBTITLE_NUMBER phase
    *	5
    *	00 : 00 : 27, 500 --> 00:00 : 30, 000
    *	talk the Federation into
    */
    switch (status) {
    case SUBTITLE_NUMBER: {
        if (i == subtitles.end()) {
            lineNumber = 1;
            i = subtitles.begin();
            throw NoMoreSubtitlesException();
        }

        status = TIME_STAMPS;
        return to_string(lineNumber++) + "\n"; // increments lineNumber
    }
        break;
    case TIME_STAMPS: {
        char tmpLine[100]; // no need for more

        sprintf(tmpLine, "%.2i:%.2i:%.2i,%.3i --> %.2i:%.2i:%.2i,%.3i\n", i->getTimeOfAppearance().getHours(), i->getTimeOfAppearance().getMinutes(), i->getTimeOfAppearance().getSeconds(), i->getTimeOfAppearance().getMiliseconds(), i->getTimeOfRemoval().getHours(), i->getTimeOfRemoval().getMinutes(), i->getTimeOfRemoval().getSeconds(), i->getTimeOfRemoval().getMiliseconds() );

        status = SUBTITLE_CONTENT;
        return tmpLine;
    }
        break;
    case SUBTITLE_CONTENT: {
        status = NEXT;
        return i->getSubtitleText();
    }
        break;
    case NEXT: {
        ++i;

        if (i == subtitles.end()) {
            lineNumber = 1;
            i = subtitles.begin();
            status = SUBTITLE_NUMBER;
            throw NoMoreSubtitlesException();
        }

        status = SUBTITLE_NUMBER;

        return "\n";
    }
        break;
    default:
        break;
    }

}

/*
 * Creates TimeStamps from a SRT file line that describes them, like this one:
 * 00:00 : 25, 000 --> 00:00 : 27, 500
*/
SRT::TimeStamps* SRT::processTimeStampLine(const string & line) {
    smatch results;

    regex_match(line, results, regex("(\\d\\d):(\\d\\d):(\\d\\d),(\\d\\d\\d) --> (\\d\\d):(\\d\\d):(\\d\\d),(\\d\\d\\d)"));

    TimeStamps* timeStamps = new TimeStamps;
    timeStamps->timeOfAppearance = TimeStamp(stoi(results[1]), stoi(results[2]), stoi(results[3]), stoi(results[4]));
    timeStamps->timeOfRemoval = TimeStamp(stoi(results[5]), stoi(results[6]), stoi(results[7]), stoi(results[8]));


    return timeStamps;
}
