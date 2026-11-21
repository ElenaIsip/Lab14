#include <stdio.h>

#define N 1000   // максимальный размер массива


double* full_elements(double *ptr_array, int n) {
    for (int i = 0; i < n; i++) {
       
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
 
        if ((i % 2) == type) {
           
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


    printf("Введите размер массива > ");
    if (scanf("%d", &size) != 1 || size <= 0 || size > N) {
        printf("Некорректный размер массива!\n");
        return 1;
    }

    full_elements(array, size);
    put_elements(array, size);

   
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

 
    double result = sum_less_on_parity(array, size, A, type);

    printf("\nСумма элементов < %.2f на %s позициях = %.2f\n",
           A, 
           (type == 0) ? "чётных" : "нечётных", 
           result);

    return 0;
}
