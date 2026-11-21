# Домашняя работа
# Индивидуальный вариант 22
# Описание программы


<img width="749" height="185" alt="{F890EC09-1E07-400C-80C3-D673A67B6B2D}" src="https://github.com/user-attachments/assets/485d3775-e920-45f6-98c0-c9edccadaa9e" />
<img width="756" height="79" alt="{33DE9E8A-3AF2-4D36-84A1-8673D1800E93}" src="https://github.com/user-attachments/assets/e5ad6f84-8f12-49e6-a7c1-709236cb1e4e" />


# Алгоритм и блок-схема
Алгоритм функции main (главная программа):

Начало.

Объявить статический массив array типа double размером N = 1000.

Объявить целочисленную переменную size.

Запросить у пользователя размер массива size.

Проверка ввода: если ввод некорректен (не число, size ≤ 0 или size > N), вывести ошибку и завершить программу (возврат 1).

Вызвать функцию full_elements(array, size) для заполнения массива.

Вызвать функцию put_elements(array, size) для вывода исходного массива на экран.

Запросить у пользователя пороговое значение A.

Проверка ввода A: если ввод некорректен, вывести ошибку и завершить программу.

Запросить у пользователя параметр type (0 – чётные позиции, 1 – нечётные позиции).

Проверка ввода type: если type не равен 0 и не равен 1, вывести ошибку и завершить программу.

Вызвать функцию sum_less_on_parity(array, size, A, type) и сохранить результат в переменную result.

Вывести на экран значение result, а также параметры A и type.

Конец.

Алгоритм функции sum_less_on_parity (обработка по варианту 22):

Начало функции. (Входные данные: указатель на массив ptr_array, размер n, пороговое значение A, тип позиций type).

Инициализировать переменную sum = 0.0.

Установить счетчик i = 0.

Начало цикла: если i < n, перейти к шагу 5, иначе перейти к шагу 9.

Проверка позиции: если остаток от деления i на 2 равен type (i % 2 == type), перейти к шагу 6, иначе перейти к шагу 8.

Проверка условия: если ptr_array[i] < A, перейти к шагу 7, иначе перейти к шагу 8.

Прибавить значение ptr_array[i] к переменной sum (sum = sum + ptr_array[i]).

Увеличить счетчик i на 1 (i = i + 1). Перейти к шагу 4 (следующая итерация).

Конец цикла. Вернуть значение sum.

Конец функции.

<img width="616" height="867" alt="{EFB2592D-858E-4F9D-B8E0-00D76E901797}" src="https://github.com/user-attachments/assets/4be3da7b-ad0e-4961-862e-ec927cac713d" />


 # Реализация программы

    #include <stdio.h>

    #define N 1000   // максимальный размер массива


    double* full_elements(double *ptr_array, int n) {
    for (int i = 0; i < n; i++) {
        // Пример заполнения: 1.5, 3.0, 4.5, 6.0...
        ptr_array[i] = (i + 1) * 1.5;
    }
    return ptr_array;
     }


    int put_elements(double *ptr_array, int n) {
    printf("Элементы массива:\n");
    for (int i = 0; i < n; i++) {
        printf("array[%d] = %.2f\n", i, ptr_array[i]);
    }
    return 0;
    }


    double sum_less_on_parity(double *ptr_array, int n, double A, int type) {
    double sum = 0.0;

    for (int i = 0; i < n; i++) {
        // Проверяем позицию (чётная/нечётная)
        if ((i % 2) == type) {
            // Проверяем условие: значение меньше A
            if (ptr_array[i] < A) {
                sum += ptr_array[i];
            }
        }
    }
    return sum;
    }


    int main(void) {
      double array[N];
    int size;

    /* ---------- Ввод размера ---------- */
    printf("Введите размер массива > ");
    if (scanf("%d", &size) != 1 || size <= 0 || size > N) {
        printf("Некорректный размер массива!\n");
        return 1;
    }

    /* ---------- Заполнение и печать массива ---------- */
    full_elements(array, size);
    put_elements(array, size);

    /* ---------- Задание 3 ---------- */
    double A;
    int type;

    printf("\nВведите пороговое значение A > ");
    if (scanf("%lf", &A) != 1) {
        printf("Ошибка ввода A!\n");
        return 1;
    }

    printf("Введите type (0 - чётные позиции, 1 - нечётные) > ");
    if (scanf("%d", &type) != 1 || (type != 0 && type != 1)) {
        printf("Некорректный type! Допустимо 0 или 1.\n");
        return 1;
    }

    /* Вызов функции и вывод результата */
    double result = sum_less_on_parity(array, size, A, type);

    printf("\nСумма элементов < %.2f на %s позициях = %.2f\n",
           A, 
           (type == 0) ? "чётных" : "нечётных", 
           result);

    return 0;
      }
# Информация о разработчике
Попова Елена, БТИИ 262


