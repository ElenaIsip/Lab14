#include <stdio.h>

#define N 1000   


double* full_elements(double* ptr_array, int n) {
    for (int i = 0; i < n; i++) {
        ptr_array[i] = (i + 1) * 1.5;   
    }
    return ptr_array;
}

int put_elements(double* ptr_array, int n) {
    printf("Элементы массива:\n");
    for (int i = 0; i < n; i++) {
        printf("array[%d] = %.2f\n", i, ptr_array[i]);
    }
    return 0;
}


double max_by_parity(double* ptr_array, int n, int type) {
    double max_val = 0.0;
    int found = 0;   

    for (int i = 0; i < n; i++) {
        if ((i % 2) == type) {
            if (!found || ptr_array[i] > max_val) {
                max_val = ptr_array[i];
                found = 1;
            }
        }
    }
    return found ? max_val : 0.0;
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


    int type;
    printf("\nВведите type (0 - чётные позиции, 1 - нечётные) > ");
    if (scanf("%d", &type) != 1 || (type != 0 && type != 1)) {
        printf("Некорректный type! Допустимо 0 или 1.\n");
        return 1;
    }

    int exists = 0;
    for (int i = 0; i < size; i++) {
        if ((i % 2) == type) { exists = 1; break; }
    }

    if (!exists) {
        printf("В массиве нет позиций типа %d.\n", type);
    }
    else {
        double mx = max_by_parity(array, size, type);
        printf("Максимум на %s позициях = %.2f\n",
            (type == 0) ? "чётных" : "нечётных", mx);
    }

    return 0;
}