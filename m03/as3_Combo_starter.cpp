#include <sstream>
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

template<class T>
struct Node
{
    T value; // The value in this node
    Node *next; // To point to the next node
};

template<class T>
class Combo
{
private:
    int count;
    Node<T> *head; // List head pointer
    
public:
    // Constructor
    Combo() { head = nullptr; count = 0; }

    // Destructor
    ~Combo() {
        Node<T> *p = head;
        while(p) { delete p; p = p->next; }
    }
    
    void insert(T); // ref. for push_front
    void remove(T); // ref. for pop_front and pop_back
    void display() const; // 
    std::string toString();

    // here are the new ones
    T front(); // read front
    T back(); // read back
    void push_front(T);
    void push_back(T); // i.e append
    void pop_front();
    void pop_back();
    int size() { return count; }
};
    
template<class T>
void Combo<T>::insert(T num) {
    Node<T> *newNode, *p, *prev=nullptr;
    newNode = new Node<T>;
    newNode->value = num;
    newNode->next = nullptr;

    // if(head == nullptr)
    if(!head) { // empty list
        head = newNode;
        count++; 
    }
    else {
        p = head;
        while( p != nullptr  && p->value < num) {
            prev = p; p = p->next; 
        }
        // p must be pointing to the first bigger, or end
        if(prev==nullptr) { // the first one is the last one.
            head = newNode;
            newNode->next = p; 
        } 
        else {
            prev->next = newNode;
            newNode->next = p; 
        } 
        count++; 
    } 
}

template<class T>
void Combo<T>::remove(T num) {
    Node<T> *p, *prev=nullptr;
    if(!head) return;
    if(head->value == num) {
        p = head->next;
        delete head;
        head = p; 
        count--; 
    }
    else {
        p = head;
        // skip all NOTs
        while( p != nullptr  && p->value != num) {
            prev = p; p = p->next; 
        }
        if(p) {
            prev->next = p->next;
            delete p; 
            count--; 
        } 
    } 
}

template<class T>
void Combo<T>::display() const {
    Node<T> *p = head;

    while(p->next) {
        std::cout << p->value << ", ";
        p=p->next;
    }
    std::cout << p->value << std::endl; 
}

template<class T>
std::string Combo<T>::toString() {
    std::stringstream ss;
    Node<T> *p = head;
    bool first = true;
    while(p){
        if (first) first = !first;
        else ss << ", ";
        ss << p->value;
        p = p->next;
    }
    return ss.str();
}

    
int main() {
    Combo<double> list;
    list.push_front(3.3);
    list.push_front(1.1);
    list.push_back(5.5);
    list.push_back(7.7);
    list.push_back(9.9);
    
    auto showd = [](Combo<double>& x) {
        cout << "\nlist has " << x.size() << " items; first: "
             << x.front() << " last: " << x.back() << endl
             << x.toString();
    };
    // cout << "\nlist has " << list.size() << " items; first: "
    //      << list.front() << " last: " << list.back() << endl
    //      << list.toString();
    showd(list);

    list.pop_front();
    list.pop_back();
    showd(list);

    list.pop_front(); 
    list.pop_back();
    showd(list);
         
    list.pop_front();
    list.pop_back(); 
    showd(list);
    
    Combo<string> slist;
    auto shows = [](Combo<string>& x) {
        cout << "\nlist has " << x.size() << " items; first: "
             << x.front() << " last: " << x.back() << endl
             << x.toString();
    };

    slist.push_front("fruits");
    slist.push_front("delicious");
    slist.push_front("eat");
    slist.push_back("like");
    slist.push_back("apple");
    shows(slist);
         
    slist.pop_front();
    slist.pop_back();
    shows(slist);

    slist.pop_front();
    slist.pop_back();
    shows(slist);

    slist.pop_front();
    slist.pop_back();
    shows(slist);
}