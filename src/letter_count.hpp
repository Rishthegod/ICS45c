#include <iostream>
using namespace std;
int char_to_index(char ch){
    return ch - 'A';
}

char index_to_char(int i){
    return 'A'+ i;
}
void count(string s, int counts[]){
    for(char c : s){
        if (isalpha(c)){
            c = toupper(c);
            counts[char_to_index(c)]++;
        }
    }
}
void print_counts(int counts[], int len){
    for(int i = 0; i < len ; ++i){
        cout << index_to_char(i) << " "<< counts[i]<<endl;
        
    }
}
