//
//  main.cpp
//  lab02-1
//
//  Created by Илья Шахназаров on 30.06.2020.
//  Copyright © 2020 PentaBob. All rights reserved.
//

#include <iostream>
using namespace std;

class safe_long_long_t {

private:
    long long value;

public:
    explicit safe_long_long_t (long long x) { value = x; }

    safe_long_long_t operator=(const safe_long_long_t &a) {
        value = a.value;
        return *this; }

    safe_long_long_t &operator+=(const safe_long_long_t& a) {
        value += a.value;
        return *this; }

    safe_long_long_t &operator-=(const safe_long_long_t& a) {
        value -= a.value;
        return *this; }

    safe_long_long_t &operator*=(const safe_long_long_t& a) {
        value *= a.value;
        return *this; }

    safe_long_long_t &operator/=(const safe_long_long_t& a) {
        value /= a.value;
        return *this; }

    safe_long_long_t &operator%=(const safe_long_long_t& a) {
        value %= a.value;
        return *this; }

    safe_long_long_t& operator++() {
        value++;
        return *this; }
    
    safe_long_long_t operator++(int i) {
        safe_long_long_t oldValue = *this;
        ++*this;
        return oldValue; }

    safe_long_long_t operator--(int i) {
        safe_long_long_t oldValue = *this;
        --*this;
        return oldValue; }
    
    safe_long_long_t& operator--() {
        --value;
        return *this; }

    
    friend ostream &operator<<(ostream &out, const safe_long_long_t &a) {
        out << a.value;
        return out;
    };

    friend istream &operator>>(istream &in, safe_long_long_t &a) {
        in >> a.value;
        return in;
    };

    friend bool operator==(const safe_long_long_t& a, const safe_long_long_t& b);
    friend bool operator>(const safe_long_long_t& a, const safe_long_long_t& b);
    friend bool operator<(const safe_long_long_t& a, const safe_long_long_t& b);
    friend bool operator>=(const safe_long_long_t& a, const safe_long_long_t& b);
    friend bool operator<=(const safe_long_long_t& a, const safe_long_long_t& b);
};



safe_long_long_t operator+(safe_long_long_t a, const safe_long_long_t& b) { return (a += b); }
safe_long_long_t operator-(safe_long_long_t a, const safe_long_long_t& b) { return (a -= b); }
safe_long_long_t operator*(safe_long_long_t a, const safe_long_long_t& b) { return (a *= b); }
safe_long_long_t operator/(safe_long_long_t a, const safe_long_long_t& b) { return (a /= b); }
safe_long_long_t operator%(safe_long_long_t a, const safe_long_long_t& b) { return (a %= b); }

bool operator==(const safe_long_long_t& a, const safe_long_long_t& b) { return (a.value == b.value); }
bool operator!=(const safe_long_long_t& a, const safe_long_long_t& b) { return !(a == b); }
bool operator>(const safe_long_long_t& a, const safe_long_long_t& b) { return (a.value > b.value); }
bool operator<(const safe_long_long_t& a, const safe_long_long_t& b) { return !((a > b)||(a == b)); }
bool operator>=(const safe_long_long_t& a, const safe_long_long_t& b) { return ((a > b)||(a == b)); }
bool operator<=(const safe_long_long_t& a, const safe_long_long_t& b) { return !(a > b); }



int main() {
    safe_long_long_t a(20);
    safe_long_long_t b(25);
    safe_long_long_t c(55);
    
    cout << a + b << endl;
    cout << a - c << endl;
    cout << a * b << endl;
    cout << a / b << endl;
    cout << a * b - c << endl;
    cout << (a + c) / b << endl;
    cout << a-- << ' ' << --a << endl;
}
