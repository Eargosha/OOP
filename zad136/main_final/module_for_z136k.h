// Иванов Егор
// Задача 136k
// https://ivtipm.github.io/Programming/Glava06/index06.htm#z136

#ifndef MODULE_FOR_7_H
#define MODULE_FOR_7_H

#include <string>
#include <iomanip>

using namespace std;                                    // Пространоство имен

namespace printing {									// П И для вывода на экран	
   /// Функция вывода массива arr размера size на экран
    template < typename Element >                       // typename - тип, указанный в параметре шаблона
    void print_array(const Element * arr, unsigned size)// Тут этот тип применился
    {
    for(unsigned i = 0; i<size; i++)                    // Цикл от 0 до конца массива
    cout << setprecision(3) << arr[i] << " ";           // Происходит вывод с округлением в цикле
    cout << endl;                                       // Переход на новую строку
    }
}					

namespace arrays {										// П И для работы с массивами
    ///Загоняет массив в бинарный файл
    void array_to_bin_file(float* arr,  unsigned size, const string& file_name); 

    ///Выгоняет массив из бинарного файла
    void array_from_bin_file(float*& arr,  unsigned& size, const string& file_name); 

	/// Функция суммы элементов массива - 136к
	float summ_array_136k(float* arr, unsigned size);
	
	/// Функция заполнения массива рандомными человеческими циферками
	void rand_fill_array(float* arr, unsigned size, int hign, int low);

    /// Функция вывода массива в текстовый файл
    void array_to_file(float* arr, unsigned size, const string &file_name);

    /// Функция поиска кол-ва элементов массива в файле
    unsigned array_size_form_file(const string &file_name);

    /// Функция загрузки массива из файла
    void array_from_file(float *arr, int size, const string &file_name);
}					

#endif