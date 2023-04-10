/*
 * Identify some of the likely virtual functions as well as pubic and protected members.
 *
 * Virtual destructors are useful when you might potentially delete an instance of a derived class through a pointer to base class:
 * */


class Shape {
public:
	virtual ~Shape() = default;
};

class Shape2D : public Shape {
public:
	virtual double area() const = 0;
	virtual double circumference() const = 0;
};

class Shape3D : public Shape {
public:
	virtual double area() const = 0;
	virtual double volumn() const = 0;
};

class Circle : public Shape2D {
protected:
	double radius = 0.0;
};
class Ellipse : public Shape2D { };
class Square : public Shape2D { };
class Rectangle : public Shape2D { };
class Sphere : public Shape3D { };
class Cube : public Shape3D { };
class Box : public Shape3D { };
class Cone : public Shape3D { };
