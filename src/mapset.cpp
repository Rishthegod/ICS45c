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
    return std::ranges::istream_view<std::string>(stopwords)
           | std::views::transform(to_lowercase)
           | std::ranges::to<std::set>();
}

std::map<std::string, int> count_words(std::istream& document, const std::set<std::string>& stopwords) {
    std::map<std::string, int> word_count;
    std::string content{std::istreambuf_iterator<char>(document), {}};

    auto words = content
                 | std::views::transform([](unsigned char c) { return std::isalpha(c) ? std::tolower(c) : ' '; })
                 | std::views::split(' ')
                 | std::views::transform([](auto&& word_range) -> std::string {
                       return std::string(word_range.begin(), word_range.end());
                   })
                 | std::views::remove_if([](const std::string& word) {
                       return word.empty();
                   });

    std::ranges::for_each(words, [&](const std::string& word) {
        if (!stopwords.contains(word)) {
            ++word_count[word];
        }
    });

    return word_count;
}

void output_word_counts(const std::map<std::string, int>& word_counts, std::ostream& output) {
    for (const auto& [word, count] : word_counts) {
        output << word << " " << count << "\n";
    }
}


