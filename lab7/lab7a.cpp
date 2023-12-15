#include <iostream>
using namespace std;


// forwarding to Counter class
class Counter;

// definition for LimitedCounter
class LimitedCounter {
public:
    LimitedCounter(int initialValue, int upperLimit);
    LimitedCounter(const Counter& counter, int upperLimit); 
    LimitedCounter(const LimitedCounter& other);
    LimitedCounter& operator=(const LimitedCounter& other); 
    ~LimitedCounter();

    LimitedCounter& operator++();    
    LimitedCounter operator++(int); 
    bool operator<(int value) const;
    void reset();
    int getCount() const;
    void setLimit(int upperLimit);

    friend ostream& operator<<(ostream& out, const LimitedCounter& lc);

private:
    Counter* counter; 
    int limit;
};

// Counter class definition (same as in the original code)
class Counter {
    friend ostream& operator<<(ostream& out, const Counter& c);

public:
    Counter(int n0 = 0);
    Counter& operator++();
    Counter operator++(int);
    bool operator<(const Counter& c2) const;
    void reset();
    int getCount() const;

private:
    int count;
};

// Overload for Counter
ostream& operator<<(ostream& out, const Counter& c) {
    out << "\nCounter value is now " << c.count;
    return out;
}

// Overload for LimitedCounter
ostream& operator<<(ostream& out, const LimitedCounter& lc) {
    out << *lc.counter; // Use the existing operator<< for Counter
    return out;
}

// Counter class implementation (same as in the original code)

Counter:: Counter(int n0) {
     count = n0;
}
Counter& Counter::operator++() {
   count++;
   return *this;
}
Counter Counter::operator++(int) {
   Counter old = *this;;
   count++;
   return old;
}
void Counter::reset(){
   count = 0;
}
int Counter::getCount() const{
   return count;
}

bool Counter::operator<(const Counter &c2) const {
 	return count < c2.count;
}
ostream &operator<<(ostream & out, const Counter &c) {
     out << "\nCounter value is now " << c.count ;
     return out;

}

// LimitedCounter class implementation

LimitedCounter::LimitedCounter(int initialValue, int upperLimit) {
    counter = new Counter(initialValue);
    limit = upperLimit;
}

LimitedCounter::LimitedCounter(const Counter& counterObj, int upperLimit) {
    counter = new Counter(counterObj);
    limit = upperLimit;
}

LimitedCounter::LimitedCounter(const LimitedCounter& other) {
    counter = new Counter(*(other.counter));
    limit = other.limit;
}

LimitedCounter& LimitedCounter::operator=(const LimitedCounter& other) {
    if (this != &other) {
        delete counter;
        counter = new Counter(*(other.counter));
        limit = other.limit;
    }
    return *this;
}

LimitedCounter::~LimitedCounter() {
    delete counter;
}

LimitedCounter& LimitedCounter::operator++() {
    if (counter->getCount() < limit) {
        ++(*counter);
    }
    return *this;
}

LimitedCounter LimitedCounter::operator++(int) {
    LimitedCounter old = *this;
    if (counter->getCount() < limit) {
        (*counter)++;
    }
    return old;
}

bool LimitedCounter::operator<(int value) const {
    return counter->getCount() < value;
}

void LimitedCounter::reset() {
    counter->reset();
}

int LimitedCounter::getCount() const {
    return counter->getCount();
}

void LimitedCounter::setLimit(int upperLimit) {
    limit = upperLimit;
}

// Program test
int main() {
    LimitedCounter lc(0, 5);
    cout << lc++ << endl;
    cout << ++lc << endl;
    lc.reset();
    for (int i = 0; i < 9; i++) {
        lc++;
        cout << lc << endl;
    }
    cout << lc.getCount() << endl;
    cout << (lc < 7); 
    cout << (lc < 1); 
    return 0;
}
