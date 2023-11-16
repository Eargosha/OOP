// Автор Eargosha, Иванов Егор, ИВТ-22
// Класс квадратов
// ask something

#ifndef CLASS_QUADRILATERAL_H
#define CLASS_QUADRILATERAL_H

#include <exception>
#include <string>
#include <cmath>

/// Объект - четырехугольник
class Quadrilateral {
private:
				// поля класса:
	/// координаты первой точки
	double x1, y1;
	/// координаты второй точки
	double x2, y2;
	/// координаты третьей точки
	double x3, y3;
	/// координаты четвертой точки
	double x4, y4;

public:
				// Методы класса:
	/// перечислимый тип видов: квадрат, ромб, прямоугольник, параллелограмм, дельтоид, трапезоид, другой
	enum Quadik {Sqare, Rhombus, Rectangle, Parallelogram, Deltoid, Trapezoid, Other};
	Quadik type; //задаем переменную типа этого класса
	/// Конструктор
	Quadrilateral();
	/// Конструктор в котором 8 сетторов
	Quadrilateral(double x1_, double y1_,double x2_, double y2_,double x3_, double y3_, double x4_, double y4_);

	/// геттер x,y x i-ой точки (Операция: Прочитать x,y i-ой (i=1,2,3,4) точки четырехугольника)
	double get_x1() const; double get_y1() const; //i=1
	double get_x2() const; double get_y2() const; //i=2  															
	double get_x3() const; double get_y3() const; //i=3
	double get_x4() const; double get_y4() const; //i=4
	/// сеттер x,y x i-ой точки (Операция: Ввод x,y i-ой (i=1,2,3,4) точки четырехугольника)
	void set_x1(double x_1); void set_y1(double y_1); //i=1
	void set_x2(double x_2); void set_y2(double y_2); //i=2 
	void set_x3(double x_3); void set_y3(double y_3); //i=3 
	void set_x4(double x_4); void set_y4(double y_4); //i=4 

	/// нахождение длины сторон четырёхугольника (Операция: Нахождение длины сторон четырёхугольника)
	double find_length (double x1, double y1, double x2, double y2) const;

	/// Методы нахождения длины a
	double find_a() const;
	/// Методы нахождения длины b
	double find_b() const;
	/// Методы нахождения длины c
	double find_c() const;
	/// Методы нахождения длины d
	double find_d() const;
	
	/// нахождение углов (Операция: Нахождение углов в градусах четырёхугольника)
	double find_angle (double x1, double y1, double x2, double y2, double x3, double y3) const;

	/// Методы нахождения угла a в градусах
	double find_angle_a() const;
	/// Методы нахождения угла b в градусах
	double find_angle_b() const;
	/// Методы нахождения угла c в градусах
	double find_angle_c() const;
	/// Методы нахождения угла d в градусах
	double find_angle_d() const;

	/// нахождение периметра четырёхугольника (Операция: Расчет P четырехугольника)
	double P () const;

	/// нахождение площади четырёхугольника (Операция: Расчет S четырехугольника )
	double S () const;

	/// метод to string (Операция: Вывод результатов)
	std::string fin_to_string () const; 

	/// определение вида четырёхугольника (Операция: Определить вид четырехугольника)
	typeof type find_type () const;

	/// проверка на выпуклость (Операция: Проверка на выпуклость четырехугольника )
	bool check_convex() const;

	/// радиус описанной окружности (Операция: Расчет радиуса описанной окружности четырехугольника)
	double rad_around() const;
 
	/// радиус вписанной окружности в четырёхугольник (Операция:  Расчет радиуса вписанной окружности четырехугольника)
	double rad_in() const;
	
};
	
	/// Тестируем код с прямоугольником
	void test_code_rectangle ();
	/// Тестируем код с параллелограммом
	void test_code_parall ();
	/// Тестируем код с квадратом (только тип)
	void test_code_sqare ();
	/// Тестируем код с ромбом (только тип)
	void test_code_rhombus ();
	/// Тестируем код с дельтоид (только тип)
	void test_code_deltoid ();
	/// Тестируем код с трапецией (только тип)
	void test_code_trapezoid ();
	/// Тестируем код с другим четыреухгольником (только тип)
	void test_code_other ();

	/// Сохраняем поля класса в бинарный файлик
	void save_quadik (Quadrilateral& Quad ,const std::string& filename);
	///	Загружаем поля класса из бинарного файлика
	void load_quadik (Quadrilateral& Quad ,const std::string& filename);

#endif //CLASS_QUADRILATERAL_H
