// Автор Eargosha, ИВТ-22
// Класс квадратов

#ifndef CLASS_QUADRILATERAL_H
#define CLASS_QUADRILATERAL_H

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
	/// стороны
	double a,b,c,d;
	/// углы
	double angle_a, angle_b, angle_c, angle_d;
	/// тип четырёхугольника
	std::string type;

public:
				// Методы класса:

	/// Конструктор
	Quadrilateral();

	/// геттер x,y x i-ой точки (Операция: Прочитать x,y i-ой (i=1,2,3,4) точки четырехугольника)
	double get_x1(); double get_y1(); //i=1
	double get_x2(); double get_y2(); //i=2
	double get_x3(); double get_y3(); //i=3
	double get_x4(); double get_y4(); //i=4

	/// сеттер x,y x i-ой точки (Операция: Ввод x,y i-ой (i=1,2,3,4) точки четырехугольника)
	void set_x1(double x_1); void set_y1(double y_1); //i=1
	void set_x2(double x_2); void set_y2(double y_2); //i=2 
	void set_x3(double x_3); void set_y3(double y_3); //i=3 
	void set_x4(double x_4); void set_y4(double y_4); //i=4 

	/// геттеры a,b,c,d (Операция: Прочитать сторону (a,b,c,d) четырехугольника )
	double get_a(); 
	double get_b(); 
	double get_c(); 
	double get_d(); 

	/// геттеры углов (Операция: Прочитать угол (angle_a, angle_b, angle_c, angle_d) четырехугольника)
	double get_angle_a(); 
	double get_angle_b(); 
	double get_angle_c(); 
	double get_angle_d(); 

	/// нахождение длины сторон и углов четырёхугольника (Операция: Нахождение характеристик четырёхугольника)
	void find_angle_length ();

	// /// нахождение длины сторон четырёхугольника (Операция: Нахождение длины сторон четырёхугольника)
	// void find_length ();
	
	// /// нахождение углов (Операция: Нахождение углов четырёхугольника)
	// void find_angle ();

	/// нахождение периметра четырёхугольника (Операция: Расчет P четырехугольника)
	double P ();

	/// нахождение площади четырёхугольника (Операция: Расчет S четырехугольника )
	double S ();

	/// метод to string (Операция: Вывод результатов)
	std::string fin_to_string (); //не константа, т.к. в функции происходят вычисления во время вывода

	/// определение вида четырёхугольника (Операция: Определить вид четырехугольника)
	void find_type ();

	/// проверка на выпуклость (Операция: Проверка на выпуклость четырехугольника )
	std::string check_vip();

	/// радиус описанной окружности (Операция: Расчет радиуса описанной окружности четырехугольника)
	double rad_around();

	/// радиус вписанной окружности в четырёхугольник (Операция:  Расчет радиуса вписанной окружности четырехугольника)
	double rad_in();

};

#endif //CLASS_QUADRILATERAL_H