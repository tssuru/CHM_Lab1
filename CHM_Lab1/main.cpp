#include <iostream>
#include <cmath>
#include <iomanip>

// Визначаємо функцію f(x)
double f(double x) {
    return pow(x - 0.7, 2) - 2 * sin(3 * x) - 1.5;
}

// Визначаємо похідну f'(x) для вибору λ
double df(double x) {
    return 2 * (x - 0.7) - 6 * cos(3 * x);
}

// Визначаємо функцію ітерації φ(x)
double phi(double x, double lambda) {
    return x - lambda * f(x);
}

int main() {
    // Початкові умови
    double epsilon = 1e-5; // Точність
    double x0 = 1.0;       // Початкове наближення

    // Вибір λ
    double lambda = -1.0 / df(x0);

    // Максимальна кількість ітерацій
    int max_iterations = 1000;

    // Виведення заголовку таблиці
    std::cout << std::fixed << std::setprecision(10);
    std::cout << "Precision (epsilon): " << epsilon << std::endl; //точність
    std::cout << "Initial approximation (x0): " << x0 << std::endl << std::endl; //початкове наближення
    std::cout << std::setw(5) << "k"
              << std::setw(15) << "x_k"
              << std::setw(15) << "phi(x_k)"
              << std::setw(15) << "f(x_k)" << std::endl;

    // Змінні для ітерацій
    double x_prev = x0;
    double x_curr;
    int k = 0;

    // Ітераційний процес
    while (k < max_iterations) {
        double fx = f(x_prev);
        x_curr = phi(x_prev, lambda);
        double phix = x_curr;
        double diff = std::abs(x_curr - x_prev);

        std::cout << std::setw(5) << k
                  << std::setw(15) << x_prev
                  << std::setw(15) << phix
                  << std::setw(15) << fx << std::endl;

        // Перевірка умови зупинки
        if (diff < epsilon) {
            break;
        }

        x_prev = x_curr;
        k++;
    }

    // Перевірка на збіжність
    if (k == max_iterations) {
        std::cout << "The method does not match after " << max_iterations << " iterations." << std::endl;
    } else {
        std::cout << std::endl << "Found root: x = " << x_curr << std::endl;
        std::cout << "Num of iterations: " << k << std::endl;
    }

    return 0;
}