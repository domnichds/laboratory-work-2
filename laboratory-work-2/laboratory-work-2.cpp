#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

unsigned long long int factorial(int number)
{
    if (number > 1) {
        return factorial(number - 1) * number;
    }
    else {
        return number;
    }
}

long double func(int n)
{
    long double result = 1;
    for (int k = 1; k <= n; k++) {
        result += pow(-1, k) / (factorial(2 * k));
    }
    return result;
}

int main()
{
    int counter = 2;
    setlocale(LC_ALL, "Russian");
    for (int n = 1; n < 10; n++) {
        if ((fabs(cos(1) - func(n)) < pow(10, -counter)) && (counter <= 6)) {
            cout << "Для точности 10^" << -counter << " требуется " << n << " ш." << endl;
            cout << fixed << setprecision(6) << func(n) << endl;
            counter++;
        }
    }
    return 0;
}
