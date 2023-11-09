// Иванов Егор
// Задача 136k
// https://ivtipm.github.io/Programming/Glava06/index06.htm#z136

    #include <iostream>                                     // Библиотека cin cout
    #include <fstream>                                      // Для работы с файлами
    #include <cstdlib>                                      // Для RAND_MAX
    #include <cmath>                                        // Для окрунления
    #include <iomanip>

    // Во всех функциях - arr - дин. массив. чисел с плавающей точкой
    // size - размер массива. file_name - название файла

    using namespace std;                                    // Пространоство имен

    namespace printing                                      // Своё пространство имён для элементов, что участвуют в выводе
    {
        /// Функция вывода массива arr размера size на экран
        void print_array(float* arr, unsigned size)
        {
        for(unsigned i = 0; i<size; i++)                    // Цикл от 0 до конца массива
        cout << setprecision(3) << arr[i] << " ";           // Происходит вывод с округлением в цикле
        cout << endl;                                       // Переход на новую строку
        }
    }

    namespace arrays
    {
        /// Функция суммы элементов массива - 136к
        float summ_array_136k(float* arr, unsigned size)
        {
            float sum = 0;                                      // Переменная для счёта
            for (unsigned i = 0; i < size; i++)                 // Цикл самого счёта элементов
            {   
                sum = sum + arr[i];
            }
            return sum * sum * 2;                               // Возращаем значение, необходимое по условию задачи
        }

        /// Функция заполнения массива рандомными цифрами. low, hign - для диапозана
        void rand_fill_array(float* arr, unsigned size, int hign, int low)
        {
            int diap = hign - low;                              // Диапозон рандома
            for (unsigned i = 0; i<size; i++)                   // Цикл для ввода заполнения
            {
                arr[i] = (float)rand()/RAND_MAX*diap+low;   // Сама функция заполнения массива
                //RAND_MAX - константа записанная в бибилиотеке cstdlib.  Гарантируется, что это значение не менее 32767
            }
        }

        /// Функция вывода массива в текстовый файл
        void array_to_file(float *arr, unsigned size, const string &file_name)
        {
            ofstream file(file_name);                           // Открытие файла Out file stream
            if (!file.is_open())                                // Если не открыт файл
                {
                    throw runtime_error("File not found");               // Если что, то в ошибку
                    //return;
                }
            for (unsigned i=0; i<size; i++)                     // Цикл для вывода массива в файл
            {
                file << arr[i] << endl;                         // Выводим элемент, затем новую строку
            }
        }

        /// Функция поиска кол-ва элементов массива в файле
        unsigned array_size_form_file(const string &file_name)
        {
            unsigned res = 0;                                   // Переменная для счета кол-ва строк
            string line;                                        // Строка, с помощью которой ищем кол-во строк
            ifstream file(file_name);                           // Открытие файла In file stream
            if (!file.is_open())                                // Если не открыт файл
                {
                    throw runtime_error("File not found");      // Если что, то в ошибку
                   // return 0;
                }
            while (getline(file, line))                         // Цикл счёта кол-ва строк -> кол-ва элементов массива
                {
                    res++;                                      // Цикл будет жить, пока getline делает переходы
                }
            file.close();                                       // Закрыть файл
            if (res == 0)                                       // Ошибка, если файл пуст
                throw runtime_error("Array not found in file - file is empty");                                  
            return res;
        }

        /// Функция загрузки массива из файла
        void array_from_file(float *arr, int size,  const string &file_name)
        {
            ifstream file(file_name);                           // Открытие файла In file stream
            if (!file.is_open())                                // Если не открыт файл
                {
                    throw runtime_error("File not found");      // Если что, то в ошибку
                   // cout << "File not found:" << endl;          // Если что, то в ошибку
                }
            for (unsigned i = 0; i < size; i++)                 // Цикл для чтения массива из файла
            {
                file >> arr[i];                                 // Построчно числа в массив
            }
        }
    }

    
