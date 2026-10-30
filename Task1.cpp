#include <stdio.h>
#include <stdlib.h>
int main(void) {
 int stack_var = 42;
 int *heap_array = (int *)calloc(3, sizeof(int));
 if (!heap_array) {
 fprintf(stderr, "Помилка: calloc не зміг виділити пам'ять\n");
 return 1;
 }
 heap_array[0] = 10;
 heap_array[1] = 20;
 heap_array[2] = 30;
 printf("=== 1. Дослідження адрес (Stack vs Heap) ===\n");
 printf("[STACK] Адреса змінної stack_var: %p\n", (void *)&stack_var);
 printf("[STACK] Адреса вказівника heap_array: %p\n", (void *)&heap_array);
 printf("[HEAP] Адреса динамічного масиву: %p\n", (void *)heap_array);
 int *tmp = (int *)realloc(heap_array, 5 * sizeof(int));
 if (!tmp) {
 fprintf(stderr, "Помилка: realloc не зміг змінити розмір\n");
 free(heap_array);
 return 1;
 }
 heap_array = tmp;
 heap_array[3] = 40;
 heap_array[4] = 50;
 printf("\n=== 2. Стан масиву після realloc ===\n");
 printf("[HEAP] Адреса масиву після realloc: %p\n", (void *)heap_array);
 printf("\nВміст масиву в купі:\n");
 for (int i = 0; i < 5; i++) {
 printf(" heap_array[%d] = %d (адреса елемента: %p)\n",
 i, heap_array[i], (void *)&heap_array[i]);
 }
 free(heap_array);
 heap_array = NULL;
 return 0;
}