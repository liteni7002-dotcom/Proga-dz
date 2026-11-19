#include <iostream>
#include "complex.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    Complex c1;
    Complex c2(3.0, 4.0);
    Complex c3(c2);
    Complex c4(1.0, -2.0);

    cout << "c1 (по умолчанию): " << c1 << '\n';
    cout << "c2 (с параметрами): " << c2 << '\n';
    cout << "c3 (копия c2): " << c3 << '\n';
    cout << "c4: " << c4 << '\n';

    c1 = c4;
    cout << "c1 после присваивания c4: " << c1 << '\n';

    cout << "\nОперации\n";
    cout << "c2 + c4 = " << (c2 + c4) << '\n';
    cout << "c2 - c4 = " << (c2 - c4) << '\n';
    cout << "c2 * c4 = " << (c2 * c4) << '\n';
    cout << "c2 / c4 = " << (c2 / c4) << '\n';

    cout << "\nИнкременты и декременты\n";
    Complex c5(2.0, 3.0);
    cout << "\c5: " << c5 << '\n';
    cout << "Префиксный ++c5: " << (++c5) << '\n';
    cout << "Постфиксный c5++: " << (c5++) << " (после: " << c5 << ")\n";
    cout << "Префиксный --c5: " << (--c5) << '\n';
    cout << "Постфиксный c5--: " << (c5--) << " (после: " << c5 << ")\n";

    cout << "\nСравнение\n";
    Complex c6(4.0, 3.0);
    cout << boolalpha;
    cout << "c2 == c6 (|3+4*i| == |4+3*i|): " << (c2 == c6) << '\n';
    cout << "c2 != c4: " << (c2 != c4) << '\n';
    cout << "c2 > c4: " << (c2 > c4) << '\n';
    cout << "c4 < c2: " << (c4 < c2) << '\n';

    cout << "\nВведите действительную и мнимую части через пробел: ";
    Complex userComplex;
    if (cin >> userComplex) {
        cout << "Вы ввели: " << userComplex << '\n';
    }
    else {
        cout << "Ошибка!\n";
    }

    return 0;
}