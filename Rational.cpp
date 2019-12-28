// Include the Rational.h header file which includes
// all of the logic and code for the header class
#include "Rational.h"

// Main program to demonstrate results
int main(){

    // Below are sample test cases to meet program requirements

    // Construction from one integer
    Rational two(2);

    // Construction from two integers
    Rational half (1, 2);

    // Stream output from construction of both one
    // and two integers
    cout << "Construction from one integer: " << endl;    
    cout << two << endl;
    cout << "Construction from two integers" << endl;
    cout << half << endl;

    cout << "\n" << endl;

    // Assignment from an integer
    Rational X (0);
    X = 5;
    cout << "Assignment from an integer: " << endl;
    cout << X << endl;

    cout << "\n" << endl;

    // Conversion to a double
    double d;
    Rational third (1, 3);
    d = third;
    cout << "Conversion to a double" << endl;
    cout << d << endl;

    cout << "\n" << endl;

    // Examples of reduction
    cout << "Examples of reduction: " << endl;
    Rational anotherThird(15,45);
    cout << " Before: " << anotherThird << endl;
    cout << " After: ";
    third.simplifyFraction();

    Rational fourth (25, 100);
    cout << " Before: " << fourth << endl;
    cout << " After: ";
    fourth.simplifyFraction();

    Rational anotherHalf (500,1000);
    cout << " Before: " << anotherHalf << endl;
    cout << " After: ";    
    anotherHalf.simplifyFraction();

    Rational carryOver (7, 3);
    cout << " Before: " << carryOver << endl;
    cout << " After: ";    
    // Should print out 2 1/3
    carryOver.simplifyFraction();

    cout << "Arithmetic Operations: " << endl;
    cout << "\n" << endl;

    // Addition
    cout << " Addition " << endl;
    Rational fracOne (3, 4);
    cout << "Fraction 1: " << fracOne << endl;
    Rational fracTwo (5, 8);
    cout << "Fraction 2: " << fracTwo << endl;
    Rational answerOne = fracOne + fracTwo;
    answerOne.simplifyFraction();
    
    cout << "\n" << endl;

    cout << " Subtraction " << endl;
    Rational fracThree (6, 7);
    cout << "Fraction 3: " << fracThree << endl;
    Rational fracFour (1, 2);
    cout << "Fraction 4: " << fracFour << endl;
    Rational answerTwo = fracThree - fracFour;
    answerTwo.simplifyFraction();

    cout << "\n" << endl;

    cout << " Multiplication " << endl;
    Rational fracFive (5, 9);
    cout << "Fraction 5: " << fracFive << endl;
    Rational fracSix (9, 10);
    cout << "Fraction 6: " << fracSix << endl;
    Rational answerThree = fracFive * fracSix;
    answerThree.simplifyFraction();

    cout << "\n" << endl;

    cout << " Division " << endl;
    Rational fracSeven (10, 21);
    cout << "Fraction 7: " << fracSeven << endl;
    Rational fracEight (5, 9);
    cout << "Fraction 8: " << fracEight << endl;
    Rational answerFour = fracSeven / fracEight;
    answerFour.simplifyFraction();   

    cout << "\n" << endl;

    cout << "Extra Credit - Represent Infinity" << endl;
    Rational infinityOne (11, 0);
    cout << "Testing: 11/0" << endl;
    cout << infinityOne << endl;
    Rational infinityTwo (-3, 0);
    cout << "Testing: -3 / 0" << endl;
    cout << infinityTwo << endl; 

}