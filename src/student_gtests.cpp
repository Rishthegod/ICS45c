#include <gtest/gtest.h>
#include <sstream>
#include "word_count.hpp"

using namespace std;

TEST(WordCount, ToLowercase){

  string str1 = "HELLO EVERYONE";
  to_lowercase(str1);
  EXPECT_EQ(str1, "hello everyone");

  string str2 = "He123llo@gmail.com";
  to_lowercase(str2);
  EXPECT_EQ(str2, "he123llo@gmail.com");

  string str3 = "W O R L D";
  to_lowercase(str3);
  EXPECT_EQ(str3, "w o r l d");

  string str4 = "WORLD";
  to_lowercase(str4);
  EXPECT_NE(str4, "WORLD");
  EXPECT_EQ(str4, "world");

  
}

TEST(WordCount, LoadStopWords){
  istringstream stopwords_stream("is\nthe\nand\ngoodbye                   earth");
  auto stopwords_set = load_stopwords(stopwords_stream);

  EXPECT_EQ(stopwords_set.size(), 5);
  EXPECT_TRUE(stopwords_set.count("is"));
  EXPECT_TRUE(stopwords_set.count("the"));
  EXPECT_TRUE(stopwords_set.count("and"));
  EXPECT_FALSE(stopwords_set.count("not"));
  EXPECT_FALSE(stopwords_set.count("hello"));
  EXPECT_FALSE(stopwords_set.count(" "));
  EXPECT_TRUE(stopwords_set.count("earth"));

  istringstream empty_stopwords_stream("");
  auto empty_stopwords_set = load_stopwords(empty_stopwords_stream);
  EXPECT_EQ(empty_stopwords_set.size(), 0);
}

TEST(WordCount, CountWords){
  istringstream document_stream("apple banana Apple cherry      cherry");
  istringstream stopwords_stream("banana\nbananas");
  auto stopwords_set = load_stopwords(stopwords_stream);

  auto word_counts = count_words(document_stream, stopwords_set);

  EXPECT_EQ(word_counts.size(), 2);
  EXPECT_EQ(word_counts["apple"], 2);
  EXPECT_NE(word_counts["apple"], 0);
  EXPECT_EQ(word_counts["Apple"], 0);
  EXPECT_EQ(word_counts[" "], 0);
  EXPECT_EQ(word_counts["cherry"], 2);
  EXPECT_EQ(word_counts.count("banana"), 0);
  EXPECT_NE(word_counts.count("bananas"), 1);
  EXPECT_NE(word_counts["cherry"], 1);
  EXPECT_NE(word_counts["apple"], 3);
}

TEST(WordCount, OutputWordCounts){
  map<string, int> word_counts = {{"cherry", 1},{"banana", 2},{"apple", 3} };
  ostringstream output_stream;
  output_word_counts(word_counts, output_stream);
  string expected_output = "apple 3\nbanana 2\ncherry 1\n";
  EXPECT_EQ(output_stream.str(), expected_output);
  EXPECT_NE(output_stream.str(), "apple 3\nbananana 2\ncherry1\n");
  EXPECT_NE(output_stream.str(), "cherry 1\nbanana 2\napple 3");

  map<string, int> word_counts2;
  word_counts2["@asd"] = 1;
  word_counts2["134214"] = 2;
  word_counts2["Hello"] = 3;
  word_counts2["World"] = 0;
  ostringstream output_stream2;
  output_word_counts(word_counts2, output_stream2);
  string expected_output2 = "134214 2\n@asd 1\nHello 3\nWorld 0\n";
  EXPECT_EQ(output_stream2.str(), expected_output2);

}
