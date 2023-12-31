// Иванов Егор
// Задача 136k
// https://ivtipm.github.io/Programming/Glava06/index06.htm#z136

#ifndef MODULE_FOR_7_H
#define MODULE_FOR_7_H

#include <string>

using namespace std;                                    // Пространоство имен

namespace printing {								    // П И для вывода на экран	

	/// Функция вывода массива из векторов arr размера size на экран
    void print_vector(vector<float> &arr);
}					

namespace arrays_vector {							    // П И для работы с массивами векторами
    /// Функция суммы элементов массива - 136к
    float summ_array_136k(const vector<float> &arr);
 
    /// Функция заполнения массива рандомными цифрами. low, hign - для диапозана
    void rand_fill_array(vector<float> &arr, int hign, int low);

    /// Функция вывода массива в текстовый файл
    void array_to_file(const vector<float> &arr, const string &file_name);

    /// Функция поиска кол-ва элементов массива в файле
    unsigned array_size_form_file(const string &file_name);

    /// Функция загрузки массива из файла
    void array_from_file(vector<float> &arr,  const string &file_name);

    ///Загоняет массив в бинарный файл
    void array_to_bin_file(const vector<float> &arr, const string& file_name); 

    ///Выгоняет массив из бинарного файла
    void array_from_bin_file(vector<float> &arr, unsigned size, const string& file_name); 
}   				

#endif