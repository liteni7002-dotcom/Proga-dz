#pragma once
#include <iostream>

class Complex {
private:
    double real_=0;
    double imaginary_=0;

    double Modul() const;

public:
    Complex();
    Complex(double real, double imaginary);
    Complex(const Complex& other);
    ~Complex();

    Complex& operator=(const Complex& other);

    Complex operator+(const Complex& other) const;
    Complex operator-(const Complex& other) const;
    Complex operator*(const Complex& other) const;
    Complex operator/(const Complex& other) const;

    Complex& operator++(); 
    Complex operator++(int);
    Complex& operator--();
    Complex operator--(int);

    bool operator>(const Complex& other) const;
    bool operator<(const Complex& other) const;
    bool operator==(const Complex& other) const;
    bool operator!=(const Complex& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Complex& complex);
    friend std::istream& operator>>(std::istream& is, Complex& complex);

    void Show() const;
};