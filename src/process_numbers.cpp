#include "process_numbers.hpp"

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <ranges>

void split_odd_even(std::istream& numbers, std::ostream& odds, std::ostream& evens){
  std::vector<int> numbers_vec{std::istream_iterator<int>{numbers}, std::istream_iterator<int>{}};
  std::ranges::sort(numbers_vec);

  std::ranges::copy_if(numbers_vec, std::ostream_iterator<int>{odds, " "}, [](int i){return i % 2 == 1;});
  odds <<  '\n';

  std::ranges::copy_if(numbers_vec, std::ostream_iterator<int>{evens, "\n"}, [](int i){return i % 2 == 0;});
  
  
}

