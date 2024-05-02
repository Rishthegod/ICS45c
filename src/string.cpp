#include <iostream>

using namespace std;

#include "string.hpp"

String::String(const char*s){
  buf = strdup(s);
}

String::String(int length){
  buf = new char[length+1];
}

String::String(const String& s){
  buf = strdup(s.buf);
}

String::String(String&& s) {
 
    buf = s.buf;
    
    s.buf = nullptr;
}

String& String::operator=(String && s){
    if(this != &s){
      delete[] buf;
      buf = s.buf;
      
    }
    s.buf = nullptr;
    return *this;
}

String::~String(){
  delete[] buf;
}


void String::swap(String& s)
{
    std::swap(buf, s.buf);
}

String & String::operator=(const String &s){
  delete[] buf; 
  buf = strdup(s.buf);
  return *this;
}

char & String::operator[](int index){
  if (index < 0 || index >= strlen(buf)) {
      std::cout << "ERROR: Index Out Of Bounds" << std::endl;
      return buf[0];
  }
  return buf[index];
}

const char &String::operator[](int index) const{
  if (index < 0 || index >= strlen(buf)) {
    std::cout << "ERROR: Index Out Of Bounds" << std::endl;
    return buf[0];
  }
  return buf[index];
}

int String::size() const{
  return strlen(buf);
}

String String::reverse() const{
  int length = size();
  String result(length);
  reverse_cpy(result.buf,buf);
  return result;
  
}

int String::indexOf(char c) const{
  const char* result = strchr(buf, c);
  if (result == nullptr) {
      return -1; // Character not found
  }
  return result - buf; // Calculate index of character
  
}

int String::indexOf(const String &s) const{
    const char* result = strstr(buf, s.buf);
    if (result == nullptr) {
        return -1; // Substring not found
    }
    return result - buf; // Calculate index of substring
}

bool String::operator==(const String &s) const {
    return strcmp(buf, s.buf) == 0;
}

bool String::operator!=(const String &s) const {
    return strcmp(buf, s.buf) != 0;
}

bool String::operator<(const String &s) const {
    return strcmp(buf, s.buf) < 0;
}

bool String::operator>(const String &s) const {
    return strcmp(buf, s.buf) > 0;
}

bool String::operator<=(const String &s) const {
    return strcmp(buf, s.buf) <= 0;
}

bool String::operator>=(const String &s) const {
    return strcmp(buf, s.buf) >= 0;
}

String String::operator+(const String &s) const{
  int len =  size() + s.size();
  String result(len);
  strcat(result.buf, buf);
  strcat(result.buf, s.buf);
  return result;
}

String & String::operator+=(const String &s){ 
  int len = strlen(s.buf)+strlen(buf);
  char* new_buf = new char[len+1];
  strcpy(new_buf, buf);
  strcat(new_buf, s.buf);
  delete[] buf;
  buf = new_buf;
  return *this;
  
}
void String::print(std::ostream &out) const{
  out << buf;
}

void String::read(std::istream &in){
  char temp[4096];
  in >> temp;
  int len = strlen(temp) + size();
  char* new_buf = new char[len+1];
  strcpy(new_buf, buf);
  strcat(new_buf, temp);
  delete[] buf;
  buf = new_buf;
  
  
}


int String::strlen(const char* s) {
    int len = 0;
    while (s[len] != '\0') {
        len++;
    }
    return len;
}

char* String::strcpy(char* dest, const char* src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
char* String::strdup(const char *src){
  int len = strlen(src);
  char* dest = new char[len + 1];
  strcpy(dest, src);
  return dest;
}
char* String::strncpy(char* dest, const char* src, int n) {
    int i = 0;
    // Copy at most n char
    for (; i < n && src[i] != '\0'; ++i) {
        dest[i] = src[i];
    }
    // Ensure null terminator
    dest[i] = '\0';
    return dest;
}

char* String::strcat(char* dest, const char* src) {
    int dest_len = strlen(dest);
    int i = 0;
    while (src[i] != '\0') {
        dest[dest_len + i] = src[i];
        i++;
    }
    dest[dest_len + i] = '\0';
    return dest;
}

char* String::strncat(char* dest, const char* src, int n) {
    int dest_len = strlen(dest);
    int i = 0;
    while (src[i] != '\0' && i < n) {
        dest[dest_len + i] = src[i];
        i++;
    }
    dest[dest_len + i] = '\0';
    return dest;
}

int String::strcmp(const char* left, const char* right) {
    int i = 0;
    while (left[i] == right[i] && left[i] != '\0' && right[i] != '\0') {
        i++;
    }
    return left[i] - right[i];
}

int String::strncmp(const char* left, const char* right, int n) {
    int i = 0;
    while (left[i] == right[i] && left[i] != '\0' && right[i] != '\0' && i < n) {
        i++;
    }
    if (i == n) {
        return 0; // Strings are equal up to n characters
    }
    return left[i] - right[i];
}

void String::reverse_cpy(char* dest, const char* src) {
    int len = strlen(src);
    for (int i = 0; i < len; i++) {
        dest[i] = src[len - i - 1];
    }
    dest[len] = '\0';
}

const char* String::strchr(const char* str, char c) {
    if(c=='\0'){
      return str +strlen(str);
    }
    while (*str != '\0') {
        if (*str == c) {
            return str;
        }
        ++str;
    }
    return nullptr; // Character not found
}

const char* String::strstr(const char* haystack, const char* needle) {
    while (*haystack != '\0') {
        const char* h = haystack;
        const char* n = needle;
        while (*h != '\0' && *n != '\0' && *h == *n) {
            h++;
            n++;
        }
        if (*n == '\0') {
            return haystack; // Found the substring
        }
        haystack++;
    }
    return nullptr; // Substring not found
}




std::ostream& operator<<(std::ostream& out, const String& s) {
    s.print(out);
    return out;
}

std::istream& operator>>(std::istream& in, String& s) {
    s.read(in);
    return in;
}


