#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <locale.h>

#define N 100 // Массив из 100 элементов


double calculate_y(double x) {
    return (x * x) + (2.0 * 3.14159265358979323846 * cos(3.14159265358979323846 * x));
}

int main(void) {
    setlocale(LC_ALL, "Russian");

    double arr[N];
    double x_start = 0.1; // Начало интервала
    double x_end = 2.5;   // Конец интервала
    double step;

    // 1) В качестве приглашения к вводу вывести вычисляемую функцию
    printf("Программа табулирования функции: y = x^2 + 2*pi*cos(pi*x)\n");
    printf("Интервал: [%.1f; %.1f]\n\n", x_start, x_end);

    // 2) Организовать возможность ввода значения шага табуляции
    printf("Введите шаг табуляции (например, 0.024 для 100 элементов): ");
    if (scanf("%lf", &step) != 1 || step <= 0) {
        printf("Ошибка: шаг должен быть положительным числом.\n");
        return 1;
    }

    // Проверка
    if (x_start + (N - 1) * step > x_end + 1e-9) {
        printf("Предупреждение: при таком шаге массив выйдет за пределы интервала [0.1; 2.5].\n");
    }

    // Генерация массива из 100 вещественных значений
    double x = x_start;
    for (int i = 0; i < N; i++) {
        arr[i] = calculate_y(x);
        x += step;
    }

    // 3) Результаты оформить в виде таблицы
    printf("\n--------------------------------------------------\n");
    printf("| %-10s | %-25s |\n", "x", "f(x)");
    printf("--------------------------------------------------\n");

    x = x_start;
    for (int i = 0; i < N; i++) {
        if (i < 5 || i >= N - 5 || i % 10 == 0) {
            printf("| %-10.4f | %-25.4f |\n", x, arr[i]);
        }
        else if (i == 5) {
            printf("| ...        | ...                       |\n");
        }
        x += step;
    }
    printf("--------------------------------------------------\n");

    // Статистика
    double sum_pos = 0.0, sum_neg = 0.0;
    int count_pos = 0, count_neg = 0;

    for (int i = 0; i < N; i++) {
        if (arr[i] > 0) {
            sum_pos += arr[i];
            count_pos++;
        }
        else if (arr[i] < 0) {
            sum_neg += arr[i];
            count_neg++;
        }
    }

    // Вычисление средних значений
    double avg_pos = (count_pos > 0) ? (sum_pos / count_pos) : 0.0;
    double avg_neg = (count_neg > 0) ? (sum_neg / count_neg) : 0.0;

    // Результаты вывести в виде строки
    printf("\nРезультаты для массива arr:\n");
    printf("Положительные элементы: накопленное значение = %.4f, количество = %d, среднее = %.4f\n", sum_pos, count_pos, avg_pos);
    printf("Отрицательные элементы: накопленное значение = %.4f, количество = %d, среднее = %.4f\n", sum_neg, count_neg, avg_neg);

    // Вычисление среднего значения всех положительных элементов массива (как просили отдельно)
    printf("\nСреднее значение всех положительных элементов массива: %.4f\n", avg_pos);

    return 0;
}