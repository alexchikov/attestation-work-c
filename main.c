#include <stdio.h>
#include "lib/functions.h"

int main(int argc, char *argv[]) {
    printf("Контрольная работа\nВыполнил Чиков Александр\n");
    printf("Вариант 28\n");

    /*
     * Задача 1:
     * Получить и вывести 10 случайных вещественных чисел в диапазоне от 10 до 100.
     */
    double random_nums[10];
    task_one(random_nums, sizeof(random_nums)/sizeof(double));
    printf("Ответ на задачу 1: ");
    for (int i = 0; i < sizeof(random_nums)/sizeof(double); i++) {
        printf("%lf ", random_nums[i]);
    }
    printf("\n");

    /*
     * Задача 2:
     * Вручную сформировать текстовый файл с баллами учеников условной группы за 8 семинаров.
     * Иванов 1 2 1 - 1 0,5 0.1 1
     * Написать программу расчета и вывода на экран среднего балла всех учеников.
     */
    int missing_sems = task_two("/home/aleks/CLionProjects/kr/data/input_file");
    printf("Ответ на задачу 2: ");
    printf("общее количество незащищенных семинаров по группе равно %d\n", missing_sems);

    /*
     * Задача 3:
     * Вручную сформировать текстовый файл с баллами учеников условной группы за 8 семинаров.
     * Иванов 1 2 1 - 1 0.5 0.1 1
     * Написать программу расчета и вывода на экран среднего балла всех учеников.
     */
    printf("Ответ на задачу 3: ");
    task_three("/home/aleks/CLionProjects/kr/data/data_all.csv");
    printf("ответ записан в файл 'output'\n");

    return 0;
}
