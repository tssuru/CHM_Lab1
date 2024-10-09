#include <iostream>
#include <cmath>
#include <iomanip>

// Визначаємо функцію f(x)
double f(double x) {
    return pow(x - 0.7, 2) - 2 * sin(3 * x) - 1.5;
}

// Визначаємо похідну f'(x0) (сталий)
double df(double x0) {
    return 2 * (x0 - 0.7) - 6 * cos(3 * x0);
}

int main() {
    // Початкові умови
    double epsilon = 1e-5; // Точність
    double x0 = -0.1;      // Початкове наближення
    double f_derivative = df(x0); // Похідна в початковій точці

    // Максимальна кількість ітерацій
    int max_iterations = 1000;

    // Виведення заголовку таблиці
    std::cout << std::fixed << std::setprecision(10);
    std::cout << "Precision (epsilon): " << epsilon << std::endl;
    std::cout << "Initial approximation (x0): " << x0 << std::endl << std::endl;
    std::cout << std::setw(5) << "k"
              << std::setw(20) << "x_k"
              << std::setw(20) << "x_{k+1}"
              << std::setw(20) << "f(x_k)" << std::endl;

    // Змінні для ітерацій
    double x_prev = x0;
    double x_curr;
    int k = 0;

    // Ітераційний процес
    while (k < max_iterations) {
        double fx = f(x_prev);
        x_curr = x_prev - fx / f_derivative;
        double diff = std::abs(x_curr - x_prev);

        // Виведення результатів
        std::cout << std::setw(5) << k
                  << std::setw(20) << x_prev
                  << std::setw(20) << x_curr
                  << std::setw(20) << fx << std::endl;

        // Перевірка умов зупинки
        if (diff < epsilon && std::abs(fx) < epsilon) {
            break;
        }

        x_prev = x_curr;
        k++;
    }

    // Перевірка на збіжність
    if (k == max_iterations) {
        std::cout << "The method does not match after " << max_iterations << "iterations." << std::endl;
    } else {
        std::cout << std::endl << "Found root: x = " << x_prev << std::endl;
        std::cout << "Num of iterations: " << k << std::endl;
    }

    return 0;
}