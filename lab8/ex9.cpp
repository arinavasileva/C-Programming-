#include <iostream>
using namespace std;

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

class LimitedCounter : public Counter {
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
    int limit;
};

LimitedCounter::LimitedCounter(int initialValue, int upperLimit) : Counter(initialValue), limit(upperLimit) {}

LimitedCounter::LimitedCounter(const Counter& counter, int upperLimit) : Counter(counter), limit(upperLimit) {}

LimitedCounter::LimitedCounter(const LimitedCounter& other) : Counter(other), limit(other.limit) {}

LimitedCounter& LimitedCounter::operator=(const LimitedCounter& other) {
    if (this != &other) {
        Counter::operator=(other);
        limit = other.limit;
    }
    return *this;
}

LimitedCounter::~LimitedCounter() {}

LimitedCounter& LimitedCounter::operator++() {
    if (Counter::getCount() < limit) {
        Counter::operator++();
    }
    return *this;
}

LimitedCounter LimitedCounter::operator++(int) {
    LimitedCounter old = *this;
    if (Counter::getCount() < limit) {
        Counter::operator++();
    }
    return old;
}

bool LimitedCounter::operator<(int value) const {
    return Counter::getCount() < value;
}

void LimitedCounter::reset() {
    Counter::reset();
}

int LimitedCounter::getCount() const {
    return Counter::getCount();
}

void LimitedCounter::setLimit(int upperLimit) {
    limit = upperLimit;
}

ostream& operator<<(ostream& out, const LimitedCounter& lc) {
    out << "\nLimitedCounter value is now " << lc.getCount();
    return out;
}

class RoundupCounter : public Counter {
public:
    RoundupCounter(int initialValue, int upperLimit);
    RoundupCounter(const Counter& counter, int upperLimit);
    RoundupCounter(const RoundupCounter& other);
    RoundupCounter& operator=(const RoundupCounter& other);
    ~RoundupCounter();

    RoundupCounter& operator++();
    RoundupCounter operator++(int);
    bool operator<(int value) const;
    void reset();
    int getCount() const;
    void setLimit(int upperLimit);

    friend ostream& operator<<(ostream& out, const RoundupCounter& rc);

private:
    int limit;
};

RoundupCounter::RoundupCounter(int initialValue, int upperLimit) : Counter(initialValue), limit(upperLimit) {}

RoundupCounter::RoundupCounter(const Counter& counter, int upperLimit) : Counter(counter), limit(upperLimit) {}

RoundupCounter::RoundupCounter(const RoundupCounter& other) : Counter(other), limit(other.limit) {}

RoundupCounter& RoundupCounter::operator=(const RoundupCounter& other) {
    if (this != &other) {
        Counter::operator=(other);
        limit = other.limit;
    }
    return *this;
}

RoundupCounter::~RoundupCounter() {}

RoundupCounter& RoundupCounter::operator++() {
    if (Counter::getCount() >= limit) {
        Counter::reset();
    } else {
        Counter::operator++();
    }
    return *this;
}

RoundupCounter RoundupCounter::operator++(int) {
    RoundupCounter old = *this;
    if (Counter::getCount() >= limit) {
        Counter::reset();
    } else {
        Counter::operator++();
    }
    return old;
}

bool RoundupCounter::operator<(int value) const {
    return Counter::getCount() < value;
}

void RoundupCounter::reset() {
    Counter::reset();
}

int RoundupCounter::getCount() const {
    return Counter::getCount();
}

void RoundupCounter::setLimit(int upperLimit) {
    limit = upperLimit;
}

ostream& operator<<(ostream& out, const RoundupCounter& rc) {
    out << "\nRoundupCounter value is now " << rc.getCount();
    return out;
}

void UseCounter(Counter* counter, int times) {
    for (int i = 0; i < times; ++i) {
        ++(*counter);
    }
}

int main() {
    LimitedCounter counterA(0, 5);
    RoundupCounter counterB(0, 5);

    UseCounter(&counterA, 8);
    UseCounter(&counterB, 8);

    cout << "Counter A: " << counterA << endl; // output should be 5
    cout << "Counter B: " << counterB << endl; // output should be 2

    return 0;
}

