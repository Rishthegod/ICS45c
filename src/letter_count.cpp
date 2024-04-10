#include <iostream>
#include <string>
using namespace std;
#include "letter_count.hpp"

constexpr int N_CHARS = ('Z' - 'A' +1);

int main(){
    int counts[N_CHARS] = {0};
    string s;
    while(cin >> s){
        count(s,counts);
    }
    print_counts(counts,N_CHARS);
    
    return 0;
}
