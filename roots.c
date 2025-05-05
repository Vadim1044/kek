#include <math.h>
#include <stdio.h>

void solveQuadratic(double a, double b, double c, double roots[2], int *root_count, double epsilon) {
    // Если a равно нулю или меньше epsilon, корней нет
    if (a == 0 || a < epsilon) {
        *root_count = 0;
        return;
    }

    // Если абсолютное значение b или c меньше epsilon, зануляем
    if (fabs(b) < epsilon) {
        b = 0;
    }
    if (fabs(c) < epsilon) {
        c = 0;
    }

    // Вычисляем дискриминант
    double discriminant = (b * b) - 4 * a * c;
    if (sqrt(discriminant) < epsilon) {
        discriminant = 0;
    }

    // Обрабатываем случаи в зависимости от значения дискриминанта
    if (discriminant > 0) {
        // Применяем формулу Виетта, если a = 1
        if (a == 1) {
            if (b > 0) {
                roots[0] = (-b - sqrt(discriminant)) / 2;
                roots[1] = c / roots[0];
            } else {
                roots[1] = (-b + sqrt(discriminant)) / 2;
                roots[0] = c / roots[1];
            }
        } else {
            roots[0] = (-b + sqrt(discriminant)) / (2 * a);
            roots[1] = (-b - sqrt(discriminant)) / (2 * a);
        }

        *root_count = 2;

        // Сортируем корни
        if (roots[0] > roots[1]) {
            double temp = roots[0];
            roots[0] = roots[1];
            roots[1] = temp;
        }
    } else if (discriminant == 0) {
        roots[0] = -b / (2 * a);
        *root_count = 1;
    } else {
        *root_count = 0;
    }
}