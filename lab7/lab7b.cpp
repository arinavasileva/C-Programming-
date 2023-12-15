#include <iostream>
using namespace std;

// Class definition for Counter

class Counter {
    friend ostream &operator<<(ostream &out, const Counter &c);

public:
    Counter(int n0 = 0);
    Counter &operator++();
    Counter operator++(int);
    bool operator<(const Counter &c2) const;
    void reset();
    int getCount() const;

private:
    int count;
};

// Counter class implementation (same as in the original code)

Counter::Counter(int n0) {
    count = n0;
}

Counter& Counter::operator++() {
    count++;
    return *this;
}

Counter Counter::operator++(int) {
    Counter old = *this;
    count++;
    return old;
}

void Counter::reset() {
    count = 0;
}

int Counter::getCount() const {
    return count;
}

bool Counter::operator<(const Counter &c2) const {
    return count < c2.count;
}

ostream &operator<<(ostream &out, const Counter &c) {
    out << "\nCounter value is now " << c.count;
    return out;
}

// Class definition for LimitedCounter (inherits from Counter)

class LimitedCounter : public Counter {
public:
    LimitedCounter(int initialValue, int upperLimit);
    LimitedCounter& operator++();    
    LimitedCounter operator++(int); 
    bool operator<(int value) const; 
    void setLimit(int upperLimit);    

private:
    int limit; // New member variable for the upper limit
};

// LimitedCounter class implementation

LimitedCounter::LimitedCounter(int initialValue, int upperLimit)
    : Counter(initialValue), limit(upperLimit) {}

LimitedCounter& LimitedCounter::operator++() {
    if (getCount() < limit) {
        Counter::operator++(); 
    }
    return *this;
}

LimitedCounter LimitedCounter::operator++(int) {
    LimitedCounter old = *this;
    if (getCount() < limit) {
        Counter::operator++(0); 
    }
    return old;
}

bool LimitedCounter::operator<(int value) const {
    return getCount() < value;
}

void LimitedCounter::setLimit(int upperLimit) {
    limit = upperLimit;
}

// Program testing

int main() {
    LimitedCounter lc(3, 5);
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
