// Illustrating user defined Data Type
// Frac Class
#include <iostream>
#include <string>

using namespace std;

// forward declaration for friend ostream operator << 
class Frac;
std:: ostream &operator << (std::ostream &, const Frac &);

class Frac {
// private:
    long num;
    long den;

public:
    Frac() {num=0; den=1;};
    Frac(long n) {num=n; den=1;};
    Frac(long n, long d) {num=n; den=d;};
    Frac(const Frac &x) {
        num = x.num; den = x.den;
    };
    Frac& operator = (const Frac &x) { 
        num = x.num; den = x.den;
    };

    Frac operator + (const Frac &x) {
        Frac temp;
        temp.num = num*x.den + x.num*den; 
        temp.den = den*x.den;
        return temp;
    };
    
    Frac operator / (const Frac &x) {
        Frac temp;
        temp.num = num * x.den; 
        temp.den = den * x.num;
        return temp;
    };
    bool operator > (const Frac &x) {
        return (num*x.den > den*x.num) ? true : false;
    }

    // Three console output methods
    // method 1, using cout (an OO principle violation)
    void show() { std::cout << num << "/" << den ; }
    
    // method 2, overloading the ostream << operator definition
    friend std::ostream &operator << (std::ostream &strm, const Frac &right){
        strm << right.num << "/" << right.den;
        return strm;
    }
    
    // method 3, convert the object data type to a string
    std::string toString() { 
        return std::to_string(num) + "/" + std::to_string(den);
    }
};

main() {
    // using method 1 show() to dispplay object content
    // exercise constructors and operator =
    Frac x(3,4);
    cout << "Create x: "; x.show();
    Frac y(2,3);
    cout << "\nCreate y: "; y.show();
    Frac z(x);
    cout << "\nCreate z from x: "; z.show();
    z = y; 
    cout << "\nAssign z as y: "; z.show();
    
    // using method 2 operator <<
    cout << "\nx+y: " << x << " + " << y << " is " << x+y;
    cout << "\nx/y: " << x << " / " << y << " is " << x/y << endl;
    cout << x << " is " << ((x>y) ? "":"not ") << "greater than " << y << endl;
    cout << y << " is " << ((y>x) ? "":"not ") << "greater than " << x;

    // using method 3 toString()
    cout << "\nx: " << x.toString() << "\ny: " << y.toString();
}