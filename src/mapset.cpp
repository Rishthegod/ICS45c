#include "mapset.hpp"
#include <algorithm>
#include <cctype>
#include <fstream>
#include <sstream>
#include <ranges>

std::string to_lowercase(const std::string& str) {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(),
                   [](unsigned char c) { return std::tolower(c); });
    return result;
}

std::set<std::string> load_stopwords(std::istream& stopwords) {
    std::set<std::string> stopwords_set;
    std::string word;
    while (stopwords >> word) {
        stopwords_set.insert(to_lowercase(word));
    }
    return stopwords_set;
}

std::map<std::string, int> count_words(std::istream& document, const std::set<std::string>& stopwords) {
    std::map<std::string, int> word_count;
    std::string line, word;

    while (std::getline(document, line)) {
        std::istringstream iss(line);
        while (iss >> word) {
            word = to_lowercase(word);
            // Remove punctuation from the word
            word.erase(std::remove_if(word.begin(), word.end(), ::ispunct), word.end());
            if (!stopwords.contains(word) && !word.empty()) {
                ++word_count[word];
            }
        }
    }

    return word_count;
}

void output_word_counts(const std::map<std::string, int>& word_counts, std::ostream& output) {
    for (const auto& [word, count] : word_counts) {
        output << word << " " << count << "\n";
    }
}


