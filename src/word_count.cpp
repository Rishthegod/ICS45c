#include "word_count.hpp"
using namespace std;
#include <iostream>

void to_lowercase(string& str){
  for(auto& x : str){
    x = tolower(x);
  }
}

set<string> load_stopwords(istream& stopwords){
  set<string> stopwords_set;
  string word;
  while(stopwords >> word){
    to_lowercase(word);
    stopwords_set.insert(word);
  }
  return stopwords_set;
}

map<string, int> count_words(istream& document, const set<string>& stopwords){
  map<string, int> word_counts;
  string word;
  while(document >> word){
    to_lowercase(word);
    if (stopwords.find(word) == stopwords.end()){
      word_counts[word] ++;
    }
  }
  return word_counts;
}

void output_word_counts(const map<string, int>& word_counts, ostream& output){
  for(auto& x : word_counts){
    output << x.first <<" "<<x.second << endl;
  }
}
