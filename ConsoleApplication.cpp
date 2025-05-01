#include <iostream>
#include <numeric> 
#include <cmath>
#include <complex>

using namespace std;

template <typename T, size_t i>
double average(const T(&arr)[i]) {
    if (i == 0) {
        return 0.0; // Обработка случая пустого массива
    }

    T sum = accumulate(arr, arr + i, (T)0); // Вычисляем сумму элементов
    return static_cast<double>(sum) / i;          // Вычисляем среднее 
}

// Шаблон функции для решения линейного уравнения (a*x + b = 0)
template <typename T>
T line(T a, T b) {
    if (a == 0) {
        if (b == 0) {
            cout << "Уравнение имеет бесконечное число решений." << endl;
        }
        else {
            cout << "Уравнение не имеет решений." <<endl;
        }
        return 0; 
    }
    else {
        return -b / a;
    }
}

// Шаблон функции для решения квадратного уравнения (a*x^2 + b*x + c = 0)
template <typename T>
pair<T, T> kvadr(T a, T b, T c) {
    if (a == 0) {
        cout << "Это не квадратное уравнение, а линейное!" << endl;
        return { 0,0 };
    }

    T discriminant = b * b - 4 * a * c;

    if (discriminant >= 0) {
        T x1 = (-b + sqrt(discriminant)) / (2 * a);
        T x2 = (-b - sqrt(discriminant)) / (2 * a);
        return { x1, x2 };
    }
    else {
        complex<T> x1((-b) / (2 * a), sqrt(-discriminant) / (2 * a));
        complex<T> x2((-b) / (2 * a), -sqrt(-discriminant) / (2 * a));
        cout << "Комплексные корни:" << endl;
        cout << "x1 = " << x1 << endl;
        cout << "x2 = " << x2 << endl;
        return { 0,0 };

    }
}
template <typename T>
T maximum(T a, T b) {
    return (a > b) ? a : b;
}
template <typename T>
T minimum(T a, T b) {
    return (a < b) ? a : b;
}
int main() {
    setlocale(LC_ALL, "ru");
    int numbers[] = { 1, 2, 3, 4, 5 };
    double avg1 = average(numbers);
    int x = 10, y = 20;
    double a1 = 2.0, b1 = -4.0;
    
    double x_linear = line(a1, b1);

    cout << "Среднее арифметическое массива: " << avg1 << endl<<endl;

    
    cout << "Решение линейного уравнения: " << x_linear << endl;

    // Пример использования квадратного уравнения
    double a2 = 1.0, b2 = -5.0, c2 = 6.0;
    pair<double, double> roots = kvadr(a2, b2, c2);
    cout << "Решение квадратного уравнения:" << endl;
    cout << "x1 = " << roots.first << endl;
    cout << "x2 = " << roots.second << endl;

    //Пример комплексного корня:
    double a3 = 1.0, b3 = 2.0, c3 = 5.0;
    pair<double, double> roots2 = kvadr(a3, b3, c3);
    cout << "Попытка решения квадратного уравнения с комплексными корнями:" << endl;
    cout << "x1 = " << roots2.first << endl;
    cout << "x2 = " << roots2.second << endl; 
    
    int maxInt = maximum(x, y);
    cout << "Максимум из " << x << " и " << y << ": " << maxInt << endl;

    int minInt = minimum(x, y);
    cout << "Минимум из " << x << " и " << y << ": " << minInt << endl;
    return 0;
}
