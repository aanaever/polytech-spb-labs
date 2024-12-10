#include <iostream>
#include "Vector.h"


int main() {

    Vector2D vector1; 
    Vector2D vector2(15, 8); 
    std::cout << "Empty constructor: " << vector1.getX() << ", " << vector1.getY() << std::endl;
    std::cout << '\n';

    std::cout << "Constructor with parameters: " << vector2.getX() << ", " << vector2.getY() << std::endl;
    std::cout << '\n';

    vector1.setX(22); 
    vector1.setY(34);
    std::cout << "Set to vector (0, 0) other values and get it: " << vector1.getX() << ", " << vector1.getY()<< std::endl;
    std::cout << '\n';

    vector2.setXY(10, 15); 
    std::cout << "Use setter with two parameters: " << vector2.getX() << ", " << vector2.getY() << std::endl;
    std::cout << '\n';

    std::cout << "Overloaded  operator << :" << std::endl;
    std::cout << vector2 << std::endl;
    std::cout << '\n';

    std::cout <<"Vector 1 :"<< vector1 << std::endl;
    std::cout <<"Vector 2 :"<< vector2 << std::endl;
    std::cout << "Sum two vectors using overloaded operator + : " << vector1 + vector2 <<std::endl;
    std::cout << '\n';
    std::cout << "Subtractions two vectors using overloaded operator - : " << vector1 - vector2 <<std::endl;
    std::cout << '\n';
    std::cout << "Multiply two vectors using overloaded operator * : " << vector1 * vector2 <<std::endl;
    std::cout << '\n';
    std::cout << "Division two vectors using overloaded operator / : " << vector1 / vector2 <<std::endl;
    std::cout << '\n';
  
    std::cout << "Length of vector: " << vector1.lengthVector() << std::endl;
   
    std::cout <<"Scalar multiply two vectors: "<< Vector2D::scalarMultiply(vector1, vector2)<<std::endl;
    std::cout << '\n';

    double num = 23.0;
    std::cout << "Multiply vector1"<< vector1 << " on the number " << num << " is: " << vector1.multiplyToNumber(num) << std::endl;
    std::cout << '\n';

    Vector2D vector3;
   
    std::cin >> vector3;
    std::cout << "Vector from input stream cin: " << vector3 << std::endl;
    std::cout << '\n';

    return 0;


}
