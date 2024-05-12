#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"

class Rectangle : public Shape{
public:
  Rectangle(Point center, std::string name, double width, double height);

  double area() const override;
  void draw(std::ostream& out) const override;
  Rectangle* clone() const override;

protected: 
  Rectangle(const Rectangle& other) = default;

private:
  double width;
  double height; 


};


// class Rectangle

#endif
