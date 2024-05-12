#ifndef SQUARE_HPP
#define SQUARE_HPP
#include "rectangle.hpp"

class Square : public Rectangle{
public:
Square(Point center, std::string name, double side);

  Square* clone() const override;

protected: 
  Square(const Square& other) = default;


};
// class Square 

#endif
