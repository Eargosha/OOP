// Иванов Егор
// Задача 136k
// https://ivtipm.github.io/Programming/Glava06/index06.htm#z136

#include <iostream>       								// Библиотека cin cout
#include <cassert>		  								// Для assert
#include <time.h>						   				// Время для рандомных элементов массива
#include <fstream>										// Для работы с файлами
#include <exception>
#include "module_for_z136k.h" 							// Мой модуль


using namespace std;  									// Пространоство имен
using namespace printing;  								// Пространоство имен для вывода на экран
using namespace arrays;									// Пространоство имен для работы с массивами

int main()
{

    string file_name;       							// Переменная - имя файла

					/* Проверка функции суммы при помощи assert */
	srand(time(0));                                     // Время необходимо для рандома, библиотека подключена в main

	unsigned size_test = 3;								// Переменная - размер массивчиков в проверке

	float *test = new float[size_test] {1, 2, 3};		// Создаем массив 1
	assert(summ_array_136k(test, size_test) == 72);		// Проводим проверку
	delete[] test;										// Чистим его

	float *test2 = new float[size_test] {4, 5, 6};		// Создаем массив 2
	assert(summ_array_136k(test2, size_test) == 450);	// Проводим проверку
	delete[] test2;										// Чистим его

	float *test3 = new float[size_test] {7, 8, 9};		// Создаем массив 2
	assert(summ_array_136k(test3, size_test) == 1152);	// Проводим проверку
	delete[] test3;										// Чистим его

	unsigned size;										// Переменная - размер массива
	char check;											// Переменная - для проверки Y/N
	int maxim;											// Переменная - для диапозона - максимальное число
	int minim;											// Переменная - для диапозона - минимальное число


cout << "Create a new array? If so, enter Y " << endl;	/*   Спрашиваем о создании нового мас   */
cin >> check;											// Чар для проверки
if ((check == 'Y') or (check == 'y'))					// Условный оператор

	{													/*            Если ввели Y...           */
	cout << "Enter size of array: "; 					// Вводим размер массива в переменную size					
	cin >> size;

	float *a = new float[size]; 						// Выделяем память под динамический массив

cout << "Enter the maximum value in the numbers in the array: " << endl;
cin >> maxim;											// Ввод диапозона для чисел массива - макс

cout << "Enter the minimum value in the numbers in the array: " << endl;
cin >> minim;											// Ввод диапозона для чисел массива - миним
					
    rand_fill_array(a, size, maxim, minim);				// Заполняем массив действительными числами
    print_array(a,size);					   	 		// Выводим массив на экран

	cout << "Array sum by rule (2*(a1+...+an)^2) = " 	// Итоговый вывод суммы - условия задачи
	<< summ_array_136k(a, size) << endl;

    cout << "Save array? If so, enter Y " << endl;		/*   Спрашиваем о сохранении  массива   */
    cin >> check;
    if ((check == 'Y') or (check == 'y'))				// Если пользователь соглашается...
    	{
    	cout << "Type name of file (.txt): " << endl;	// Просим у пользователя название файла
    	cin >> file_name;
    	    array_to_file(a, size, file_name);			// Выводим массив в файл
    	}

    delete[] a;											// Подчищаем память
	}
else													/*       Если не ввели в начале Y       */
	{
cout << "Type name of file (.txt): " << endl; 			// Просим у пользователя название файла
cin >> file_name;
cout << "Array is loading from file..." << endl;

	try {												// Проверка на исключения
		unsigned size_1 = array_size_form_file(file_name);
	}
	catch (const exception &error) {					// М Б "Не открыт файл" и "Файл пуст"
		cout << error.what();
	}

	size = array_size_form_file(file_name);				// Находим кол-во элементов мас из файла
	float *a = new float[size]; 						// Выделяем память под динамический массив
	array_from_file(a, size, file_name);				// Считываем массив из файла
	print_array(a,size);					   	 		// Выводим массив на экран 
	
	cout << "Array sum by rule (2*(a1+...+an)^2) = " 	// Итоговый вывод суммы - условия задачи
	<< summ_array_136k(a, size) << endl; 

    delete[] a;											// Подчищаем память
	}

}
