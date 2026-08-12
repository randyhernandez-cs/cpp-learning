// Number Classifier - identifies properties of a user-provided number
// Outputs: even/odd, positive/negative/zero, and digit count
#include <iostream>
#include "NumberClassifier.h"

int main()
{
    double Numberclassifier{};
    std::cout << "Please insert a number to classify its identity" << '\n';
    std::cin >> Numberclassifier;
    printEvenOrOdd(Numberclassifier);                            // even or odd
    printPositiveNegativeZero(Numberclassifier);                 // positive, negative, or zero
    printMagnitude(Numberclassifier);                               // single, double, triple, or quad digit

}


