// Number Classifier - identifies properties of a user-provided number
// Outputs: even/odd, positive/negative/zero, and digit count
#include <iostream>
#include "NumberClassifier.h"

int main()
{
    double Numberclassifier{};
    std::cout << "Please insert a number to classify its identity" << '\n';
    std::cin >> Numberclassifier;
    Classification(Numberclassifier);       // even or odd
    PorNorO(Numberclassifier);              // positive, negative, or zero
    numberRange(Numberclassifier);          // single, double, triple, or quad digit

}


