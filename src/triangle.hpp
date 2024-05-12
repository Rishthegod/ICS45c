#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "shape.hpp"
class Triangle : public Shape{
public:
Triangle(Point center, std::string name, double base, double height);


double area() const override;
void draw(std::ostream& out) const override;
Triangle *clone() const override;




protected:
  Triangle(const Triangle& other) = default;

private:
  double base;
  double height;

// class Triangle
};
#endif
