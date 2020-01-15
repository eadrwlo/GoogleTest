#include <cmath>
#include <vector>
#include <string>
#include <stdexcept>
#include <iostream>
#include "Controller/Controller.h"
// Get the Square root of a number.
double squareRoot(const double a)
{
    std::cout << "squareRoot()";
    double b = sqrt(a);
    if(b != b)
    {
        return -1.0;
    }
    else
    {
        return sqrt(a);
    }
}

double findMaximum(std::vector<double> vect){
    double maxValue = 0;
    for(double & it : vect){
        if (it > maxValue)
            maxValue=it;
    }
    return maxValue;
}

bool isPalindrome (std::string word){
    if (word == std::string(word.rbegin(), word.rend()))
        return true;
    else
        return false;

}

double div(const double a, const double b){
    if(b == 0.0)
        throw std::invalid_argument("Invalid argument second!");
    if(a == 0.0)
        throw std::invalid_argument("Invalid argument first!");
    return a/b;
}

bool isAscending(std::vector<double> vect){
    for(int i = 0; i < vect.size()-1; i++){
        if (vect[i] > vect[i+1])
            return false;
    }
    return true;
}

double isDescending(std::vector<double> vect){
    for(int i =0; i < vect.size()-1; i++){
        if (vect[i] < vect[i+1])
            return false;
    }
    return true;
}

int fibonacci(int n){

    return 2137;
}

bool isProperOrder(const std::vector<double>& vect, ControllerIfU *c, int order)
{
    std::cout << "isProperOrder() - order = " << order << std::endl;
    if (c->isAllowedAscending(order))
    {
        std::cout << "return isAscending(vect);" << std::endl;
        return isAscending(vect);
    }
    else
    {
        std::cout << "return isDescending(vect);" << std::endl;
        return isDescending(vect);
    }
}