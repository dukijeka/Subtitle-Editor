#ifndef _serbian_subtitle_replacements_h_
#define _serbian_subtitle_replacements_h_

#include <unordered_map>

namespace poop2017cppmodification {
	
	extern std::unordered_map<std::string, std::string> replacements;
	extern const size_t WIDE_CHAR_LENGTH;
	extern bool inMap(const std::string &str, size_t position);
	extern std::string getReplacement(const std::string &str, size_t position);

	/**
	 * \brief Replaces all the wrong unicode characters with the right ones
	 * \param str String where the replacements occur
	 */
	inline void replace(std::string &str) {
		for (size_t i = 0; i < str.length(); i++) {
			if (inMap(str, i)) {
				str.replace(i, WIDE_CHAR_LENGTH, getReplacement(str, i));
			}
		}
	}

	std::unordered_map<std::string, std::string> replacements = {
		{ "\xc3\xa8", "\xc4\x8d" }, // è -> č
		{ "\xc3\x88", "\xc4\x8c" }, // È -> Č
		{ "\xc3\xa6", "\xc4\x87" }, // æ -> ć
		{ "\xc3\x86", "\xc4\x86" }, // Æ -> Ć
		{ "\xc3\xb0", "\xc4\x91" }, // ð -> đ
		{ "\xc3\x90", "\xc4\x90" }  // Ð -> Đ
	};

	const size_t WIDE_CHAR_LENGTH = 2;

	static bool inMap(const std::string &str, size_t position) {
		return replacements.count(str.substr(position, WIDE_CHAR_LENGTH)) > 0;
	}

	static std::string getReplacement(const std::string &str, size_t position) {
		return replacements[str.substr(position, WIDE_CHAR_LENGTH)];
	}
}

#endif
