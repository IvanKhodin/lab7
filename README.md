# Лабораторная работа № 7

Выполнил Ходин Иван, 427 группа

### Вариант № 9

Задание: Решить методом Мерсона задачу Коши 
![https://github.com/IvanKhodin/lab7/blob/master/1](https://github.com/IvanKhodin/lab7/blob/master/1.png)

## Теоретическая часть:

Явный пятикратный метод Рунге-Кутты (метод Мерсона): ![https://github.com/IvanKhodin/lab7/blob/master/2](https://github.com/IvanKhodin/lab7/blob/master/2.png)

## Практическая часть:

Функция double F(double x, double y1, double y2, double y3, int number) использует параметр number для выведения значения нужной функции (производной порядка number) для упрощения подсчетов, double Y1[n+1], Y2[n+1], Y3[n+1] - массивы значений функций производных соотвествующего порядка, double k1[4], k2[4], k3[4], k4[4], k5[4] - коэффициенты метода Рунге-Кутты, программа параллельно вычисляет коэффициенты для производных функций первого, второго и третьего порядка соотвественно, записывая полученные данные в массивы значений этих функций.

## Результаты:

В результате решения задачи методом Мерсона были построены следующие графики: ![https://github.com/IvanKhodin/lab7/blob/master/Graphics](https://github.com/IvanKhodin/lab7/blob/master/Graphics.png)





