#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <iomanip>
#include <sstream>
#include <utility>

template <typename T>
class Array{
public:
  Array() : len{0}, buf{nullptr}{}

  explicit Array(int len): len{len}, buf{new T[len]}{}

  Array(const Array& other): len{other.len}, buf{ new T[other.len]}{
      for(int i = 0; i < other.len; ++i){
        buf[i] = other.buf[i];
      }
    
  }
  Array(Array&& other): len{0}, buf{nullptr}{
    swap(*this, other);
  }

  T& operator[](int index){
    if(!in_bounds(index)){
      std::string exceptmsg = "Exception operator[](" + std::to_string(index) + ") Out of Range";
      throw exceptmsg;
    }
    return buf[index];
  }

  const T& operator[](int index) const{
    if(!in_bounds(index)){
      std::string exceptmsg = "Exception operator[](" +       std::to_string(index) + ") Out of Range";
      throw exceptmsg;
    }
    return buf[index];
  }

  

  friend void swap(Array& lhs, Array& rhs) noexcept{
    std::swap(lhs.len, rhs.len);
    std::swap(lhs.buf, rhs.buf);
  }
  
  ~Array(){
    len = 0;
    delete[] buf;
  }
  int length() const{
    return len;
  }
  Array& operator=(Array&& other) noexcept{
    swap(*this, other);
    return *this;
  }

  Array& operator=(const Array& other){
    if(this != &other){
      delete[] buf;
      len = other.len;
      buf = new T[len];
      for(int i = 0; i < len; ++i){
        buf[i] = other.buf[i];

      }
    }
    return *this;
  }


  void fill(T val){
    for(int i = 0; i < len; ++i){
      buf[i] = val;
    }
  }


  template <typename Fn>
  void fill_with_fn(Fn fn){
    for(int i = 0; i < len; ++i){
      buf[i] = fn(i);
    }
  }
private:
  int len;
  T* buf;

  bool in_bounds(int index) const{
      return index >= 0  && index <len;
  }

};



template <typename T>
std::ostream& operator<<(std::ostream& out, const Array<T>& array){
  std::stringstream temp;

  temp <<std::setprecision(2) << std::fixed << std::right;

  for(int i = 0; i < array.length(); ++i){
    temp << std::setw(8)<< array[i];
  }

  out<< temp.str();
  return out;
}

template <typename T>
std::istream& operator>>(std::istream& in, Array<T>& array){
  for(int i = 0; i < array.length(); ++i){
    in >> array[i];
  }
  return in;
}

#endif
