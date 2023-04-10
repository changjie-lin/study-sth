// (b) Geometric primitives (such as box, circle, sphere, cone)
//

class Shape {};
class Shape2D : public Shape { };
class Shape3D : public Shape { };
class Circle : public Shape2D { };
class Ellipse : public Shape2D { };
class Square : public Shape2D { };
class Rectangle : public Shape2D { };
class Sphere : public Shape3D { };
class Cube : public Shape3D { };
class Box : public Shape3D { };
class Cone : public Shape3D { };
