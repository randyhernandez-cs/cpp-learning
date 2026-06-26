#include <iostream>
#include "NumberClassifier.h"

int main()
{
    double Numberclassifier{};
    std::cout << "Please insert a number to classify its identity" << '\n';
    std::cin >> Numberclassifier;
    Classification(Numberclassifier);
    PorNorO(Numberclassifier);
    numberRange(Numberclassifier);

}


