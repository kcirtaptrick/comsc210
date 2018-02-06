// inserting into a list
#include <iostream>
#include <list>
#include <sstream>
using namespace std;


 
class Frac; // Forward Declaration
 
// Function Prototypes for Overloaded Stream Operators
ostream &operator << (ostream &, const Frac &);
istream &operator >> (istream &, Frac &);
 
class Frac {
private:
    int num, den; // num/den is a frac number
public:
    // constructors
    Frac() {num = 0; den = 1;}
    Frac(string s){
        stringstream strm(s);
        strm >> num;
        
        char peekchar = strm.peek();
        if(strm && peekchar == '/') {
            strm.get();
            strm >> den;
        }
        else den = 1;
    };
    Frac(int num_, int den_) : num(num_), den(den_) {}
    Frac(const Frac& rhs) : num(rhs.num), den(rhs.den) {}
    // assignment operator
    Frac operator=(const Frac& rhs);
    // math + - * /
    Frac operator + (Frac &f2) {
        Frac temp;
        temp.num = num*f2.den + den*f2.num;
        temp.den = den*f2.den;
        return temp;
    }
    Frac operator - (Frac &f2);
    Frac operator * (Frac &f2);
    Frac operator / (Frac &f2);
    // increment ++ decrement --
    Frac operator++();
    Frac operator++(int);
    Frac operator--();
    Frac operator--(int);
    // comparators
    bool operator == (Frac &f2);
    bool operator != (Frac &f2);
    bool operator < (Frac &f2);
    bool operator > (Frac &f2);
    bool operator <= (Frac &f2);
    bool operator >= (Frac &f2);
 
    // type cast
    double get_value();
 
    //stream extraction operators
    friend istream& operator>>(istream& strm, Frac& f);
 
    // stream insertion operator overload

	friend ostream& operator<<(ostream& strm,const Frac& f){
	    strm << f.num << '/' << f.den;
	    return strm;
    } 
 
    // auxiliary method
    Frac lowterms(Frac &f); //arg reduced to lowest terms
};




int main () {
    list<double> mylist = {5.4, 6.8, 8.1};
    list<double>::iterator it;
 
    for(auto item:mylist) cout << ' ' << item;// 5.4, 6.8, 8.1
 
    it = mylist.begin();
    ++it;       // it points now to 2nd number
 
    mylist.insert (it,2.3);     // 5.4, 2.3, 6.8, 8.1
 
    mylist.insert (it,2,7.8);   // 5.4, 2.3, 7.8, 7.8, 6.8, 8.1                                    // 1 10 20 30 30 20 2 3 4 5
 
    cout << "\nmylist contains:\n";
    for(auto item:mylist) cout << ' ' << item;
    cout << '\n';
 
    double sum = 0;
    while (!mylist.empty()){
        sum += mylist.back();
        mylist.pop_back();
    }
    cout << "Sum is " << sum << endl;
    for(auto item:mylist) cout << ' ' << item;
    cout << endl;
    
    // Frac number testing
    Frac f1("2/3"), f2("3/4");
    list<Frac> flist;
    flist.insert(f1);
    flist.insert(f2);
    for(auto item:flist) cout << ' ' << item;
    
    return 0;
}