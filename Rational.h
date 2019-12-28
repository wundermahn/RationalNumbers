#include <iostream>
using namespace std;

class Rational
{
    /// Create public functions
    public:

    // Constructor when passed two numbers
    explicit Rational(int numerator, int denominator){
        this->numerator = numerator;
        this->denominator = denominator;    
    }//end constructor

    // Constructor when passed one number
    // Example of constructor overloading
    explicit Rational(int numerator){
        this->numerator = numerator;
        denominator = 1;    
    } //end constructor

    // return the numerator
    int getNumerator(){
        return numerator;
    } //end getNumerator

    // return the denominator
    int getDenominator(){
        return denominator;
    } //end getDenominator

    // Support conversion to a double
    operator double(){
        return double(numerator)/denominator;
    } //end double
    
    /**
    Use a friend to overload the << operator
    Decided to use "friend" implementation based on e-mail 
    correspondance with Professor Pierson
    **/
    friend ostream& operator << (ostream& os, Rational& fraction) {
        if(fraction.denominator == 0 && fraction.numerator != 0){
            if(fraction.numerator > 0){
                cout << "Positive Infinity" << endl;
                return os;
            }else{
                cout << "Negative Infinity" << endl;
                return os;
            } //end else
        } //end infinity check

        // Print out the fraction, numerator / denominator
        os << fraction.numerator;
        os << '/';
        os << fraction.denominator;

        return os;
    } //end operator overload


    // Simplify a fraction
    void simplifyFraction(){
        // Check to see if the fraction is infinity
        if(denominator == 0 && numerator != 0){
            // Check for positive or negative infinity
            if(numerator > 0){
                cout << "Positive Infinity" << endl;
                // Return back
                return;
            }else{
                cout << "Negative Infinity" << endl;
                // Return back
                return;
            } //end if else
        } //end infinity check        

        // Get the greatest common denominator
        int gcd = getGCD(numerator, denominator);

        // Calculate new numerator and denominator
        numerator /= gcd;
        denominator /= gcd;
        
        // Used for formatting purposes for printing
        int a = numerator % denominator;
        int b = numerator / denominator;

        // Pretty print formatting
        if (b == 0){
            if (a != 0){
                cout << a << "/" << denominator << endl;
            }else{
                cout << 0 << endl;
            }
        }else{
            if (a != 0){
                cout << b << " " << a << "/" << denominator << endl;
            }else{
                cout << b << endl;
            } //end inner if else
        } //end outer if else
    } //end simplifyFraction

    // Overload the = assignment operator
    // http://www.cplusplus.com/forum/general/1889/
    Rational& operator=(int const& numerator){
        this->numerator = numerator;
        denominator = 1;
        return *this;
    }//end assignment overload    

    // Private member data
    private:
    // Calculate the greatest common denominator
    int getGCD(int numerator, int denominator){
        //https://en.wikipedia.org/wiki/Euclidean_algorithm
        // If the denominator is 0, then it is the numerator
        if (denominator == 0){
            return numerator;
        // Otherwise
        }else{
            // Recursively recall the function
            return getGCD(denominator, numerator % denominator);
        } //end else
    } //end gcd

    // Private member data
    int numerator;
    int denominator;
}; //end class Rational

// Per C++ Coding Standards 101 Rule 27, defining these as non member functions
// Addition operator
Rational operator+ (Rational r1, Rational r2){
    // Get the numerators and denominators of the two rational fractions
    int r1Numerator = r1.getNumerator();
    int r1Denominator = r1.getDenominator();
    int r2Numerator = r2.getNumerator();
    int r2Denominator = r2.getDenominator();

    // The new Rational Fraction    
    int r3Numerator, r3Denominator;

    // Set the new denominator and numerator
    r3Denominator = r1Denominator * r2Denominator;
    r3Numerator = (r1Numerator * r2Denominator) + (r2Numerator * r1Denominator);

    // Create the new result rational
    Rational r3 (r3Numerator, r3Denominator);

    // Return it
    return r3;
} //end operator+

// Substraction operator
Rational operator- (Rational r1, Rational r2){
    // Get the numerators and denominators of the two rational fractions
    int r1Numerator = r1.getNumerator();
    int r1Denominator = r1.getDenominator();
    int r2Numerator = r2.getNumerator();
    int r2Denominator = r2.getDenominator();

    // The new Rational Fraction    
    int r3Numerator, r3Denominator;

    // Set the new denominator and numerator
    r3Denominator = r1Denominator * r2Denominator;
    r3Numerator = (r1Numerator * r2Denominator) - (r2Numerator * r1Denominator);

    // Create the new result rational
    Rational r3 (r3Numerator, r3Denominator);

    // Return it
    return r3;    
} //end operator-

// Multiplication Operator
Rational operator* (Rational r1, Rational r2){
    // Get the numerators and denominators of the two rational fractions
    int r1Numerator = r1.getNumerator();
    int r1Denominator = r1.getDenominator();
    int r2Numerator = r2.getNumerator();
    int r2Denominator = r2.getDenominator();

    // The new Rational Fraction    
    int r3Numerator, r3Denominator;

    // Set the new denominator and numerator
    r3Denominator = r1Denominator * r2Denominator;
    r3Numerator = r1Numerator * r2Numerator;

    // Create the new result rational
    Rational r3 (r3Numerator, r3Denominator);

    // Return it
    return r3;    
} //end operator*

// Division Operator
Rational operator/ (Rational r1, Rational r2){
    // Get the numerators and denominators of the two rational fractions
    int r1Numerator = r1.getNumerator();
    int r1Denominator = r1.getDenominator();
    int r2Numerator = r2.getNumerator();
    int r2Denominator = r2.getDenominator();

    // The new Rational Fraction    
    int r3Numerator, r3Denominator;

    // Set the new denominator and numerator
    r3Denominator = r1Denominator * r2Numerator;
    r3Numerator = r1Numerator * r2Denominator;

    // Create the new result rational
    Rational r3 (r3Numerator, r3Denominator);

    // Return it
    return r3;    
} //end operator/