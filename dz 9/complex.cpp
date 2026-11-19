#include "complex.h"
#include <cmath>
#include <stdexcept>

Complex::Complex() : real_(0.0), imaginary_(0.0) {}

Complex::Complex(double real, double imaginary)
    : real_(real), imaginary_(imaginary) {
}

Complex::Complex(const Complex& other)
    : real_(other.real_), imaginary_(other.imaginary_) {
}

Complex::~Complex() {}

double Complex::Modul() const {
    return std::sqrt(real_ * real_ + imaginary_ * imaginary_);
}

Complex& Complex::operator=(const Complex& other) {
    if (this != &other) {
        real_ = other.real_;
        imaginary_ = other.imaginary_;
    }
    return *this;
}

Complex Complex::operator+(const Complex& other) const {
    return Complex(
        real_ + other.real_,
        imaginary_ + other.imaginary_
    );
}

Complex Complex::operator-(const Complex& other) const {
    return Complex(
        real_ - other.real_,
        imaginary_ - other.imaginary_
    );
}

Complex Complex::operator*(const Complex& other) const {
    return Complex(
        real_ * other.real_ - imaginary_ * other.imaginary_,
        real_ * other.imaginary_ + imaginary_ * other.real_
    );
}

Complex Complex::operator/(const Complex& other) const {
    double denominator = other.real_ * other.real_ + other.imaginary_ * other.imaginary_;
    if (denominator == 0.0) {
        throw std::invalid_argument("Division by zero complex number");
    }
    return Complex(
        (real_ * other.real_ + imaginary_ * other.imaginary_) / denominator,
        (imaginary_ * other.real_ - real_ * other.imaginary_) / denominator
    );
}

Complex& Complex::operator++() {
    ++real_;
    return *this;
}

Complex Complex::operator++(int) {
    Complex temp(*this);
    ++(*this);
    return temp;
}

Complex& Complex::operator--() {
    --real_;
    return *this;
}

Complex Complex::operator--(int) {
    Complex temp(*this);
    --(*this);
    return temp;
}

bool Complex::operator>(const Complex& other) const {
    return Modul() > other.Modul();
}

bool Complex::operator<(const Complex& other) const {
    return Modul() < other.Modul();
}

bool Complex::operator==(const Complex& other) const {
    return Modul() == other.Modul();
}

bool Complex::operator!=(const Complex& other) const {
    return !(*this == other);
}

static void PrintImaginary(std::ostream& os, double imag, bool showSign) {
    if (showSign) {
        os << (imag < 0.0 ? "-" : "+");
    }
    else if (imag < 0.0) {
        os << "-";
    }

    if (std::abs(imag) != 1.0) {
        os << std::abs(imag) << "*";
    }
    os << "i";
}

std::ostream& operator<<(std::ostream& os, const Complex& complex) {
    if (complex.real_ == 0.0 && complex.imaginary_ == 0.0) {
        return os << 0;
    }

    if (complex.real_ == 0.0) {
        PrintImaginary(os, complex.imaginary_, false);
        return os;
    }

    os << complex.real_;
    if (complex.imaginary_ != 0.0) {
        PrintImaginary(os, complex.imaginary_, true);
    }
    return os;
}

std::istream& operator>>(std::istream& is, Complex& complex) {
    double tempReal, tempImaginary;
    if (is >> tempReal >> tempImaginary) {
        complex.real_ = tempReal;
        complex.imaginary_ = tempImaginary;
    }
    return is;
}

void Complex::Show() const {
    std::cout << *this << '\n';
}