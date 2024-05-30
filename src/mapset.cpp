#include "mapset.hpp"
#include <algorithm>
#include <cctype>
#include <fstream>
#include <sstream>
#include <ranges>
#include <iterator>
#include <set>
#include <map>
#include <string_view>
#include <vector>

std::string to_lowercase(const std::string& str) {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(),
                   [](unsigned char c) { return std::tolower(c); });
    return result;
}

std::set<std::string> load_stopwords(std::istream& stopwords) {
    std::vector<std::string> words{std::istream_iterator<std::string>{stopwords},     std::istream_iterator<std::string>{}};
    std::ranges::transform(words, words.begin(), to_lowercase);
    return {words.begin(), words.end()};
}

std::map<std::string, int> count_words(std::istream& document, const std::set<std::string>& stopwords) {
    std::map<std::string, int> word_count;

    std::transform(std::istream_iterator<std::string>{document}, std::istream_iterator<std::string>{},inserter(word_count, word_count.end()),[&](const std::string& word){
        auto lowerword = to_lowercase(word);
        if (stopwords.find(lowerword) == stopwords.end()){
            return std::make_pair(std::string(lowerword), word_count[std::string(lowerword)] + 1);
        }
        else{
            return std::make_pair(std::string(""), 0);
        }});
    if (word_count.find(std::string("")) != word_count.end()){
        word_count.erase(std::string(""));
    }
    
    return word_count;
    /*std::string content{std::istreambuf_iterator<char>(document), {}};

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

    return word_count;*/
}

void output_word_counts(const std::map<std::string, int>& word_counts, std::ostream& output) {
    for (const auto& [word, count] : word_counts) {
        output << word << " " << count << "\n";
    }
}


