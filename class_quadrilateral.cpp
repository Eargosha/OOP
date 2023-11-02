// Автор Eargosha, ИВТ-22
// Класс квадратов

#define _USE_MATH_DEFINES
#include "class_quadrilateral.h"
#include <cmath>
#include <string>
#include <cassert>
#include <iostream>

/// Конструктор
	Quadrilateral::Quadrilateral(){
		x1 = 0; y1 = 0;
		x2 = 0; y2 = 0;
		x3 = 0; y3 = 0;
		x4 = 0; y4 = 0;	}

	/// Конструктор с заданием значений
	Quadrilateral::Quadrilateral(double x1_, double y1_,double x2_, double y2_,double x3_, double y3_, double x4_, double y4_){
	set_x1 (x1_);			set_y1 (y1_);
	set_x2 (x2_);			set_y2 (y2_);
	set_x3 (x3_);			set_y3 (y3_);
	set_x4 (x4_);			set_y4 (y4_);
	}	

/// геттер x,y x i-ой точки (Операция: Прочитать x,y i-ой (i=1,2,3,4) точки четырехугольника)
	double Quadrilateral::get_x1() const {return x1;} double Quadrilateral::get_y1() const {return y1;} //i=1
	double Quadrilateral::get_x2() const {return x2;} double Quadrilateral::get_y2() const {return y2;} //i=2
	double Quadrilateral::get_x3() const {return x3;} double Quadrilateral::get_y3() const {return y3;} //i=3
	double Quadrilateral::get_x4() const {return x4;} double Quadrilateral::get_y4() const {return y4;} //i=4

/// сеттер x,y x i-ой точки (Операция: Ввод x,y i-ой (i=1,2,3,4) точки четырехугольника)
	void Quadrilateral::set_x1(double x_1){x1 = x_1;} void Quadrilateral::set_y1(double y_1){y1 = y_1;} //i=1
	void Quadrilateral::set_x2(double x_2){x2 = x_2;} void Quadrilateral::set_y2(double y_2){y2 = y_2;} //i=2 
	void Quadrilateral::set_x3(double x_3){x3 = x_3;} void Quadrilateral::set_y3(double y_3){y3 = y_3;} //i=3 
	void Quadrilateral::set_x4(double x_4){x4 = x_4;} void Quadrilateral::set_y4(double y_4){y4 = y_4;} //i=4 

/// нахождение длины сторон четырёхугольника (Операция: Нахождение длины сторон четырёхугольника)
	double Quadrilateral::find_length (double x1, double y1, double x2, double y2) {
		return sqrt(pow((x2-x1), 2) + pow((y2-y1),2)); //формула длины стороны четырёхугольника
	}

/// нахождение углов (Операция: Нахождение углов в градусах четырёхугольника)
	double Quadrilateral::find_angle (double x1, double y1, double x2, double y2, double x3, double y3)
	{
		// Вычисляем характеристики векторов между точками
    	double v1x = x2 - x1;
    	double v1y = y2 - y1;
    	double v2x = x3 - x2;
    	double v2y = y3 - y2;
    	// double v3x = x4 - x3;
    	// double v3y = y4 - y3;
    	// double v4x = x1 - x4;
    	// double v4y = y1 - y4;

    	double Prod;
    	// Вычисляем векторное произведение векторов
    	Prod = v1x * v2x + v1y * v2y;
    	return (acos(Prod / (find_length(x1,y1,x2,y2) * find_length(x2,y2,x3,y3)))) * 180.0 / M_PI; // находим углы в градусах

    	// Prod = v2x * v3x + v2y * v3y;
    	// angle_b = (acos(Prod / (b * c))) * 180.0 / M_PI;

    	// Prod = v3x * v4x + v3y * v4y;
    	// angle_c = (acos(Prod / (c * d))) * 180.0 / M_PI;

    	// Prod = v4x * v1x + v4y * v1y;
    	// angle_d = (acos(Prod / (d * a))) * 180.0 / M_PI;
	}

/// нахождение периметра четырёхугольника (Операция: Расчет P четырехугольника)
	double Quadrilateral::P () const{
		return a+b+c+d;
	}

/// нахождение площади четырёхугольника (Операция: Расчет S четырехугольника )
	double Quadrilateral::S () const{
		return abs(((x4*y3+x3*y2+x2*y1+x1*y4)-(y4*x3+y3*x2+y2*x1+y1*x4))/2);
	}

/// определение вида четырёхугольника (Операция: Определить вид четырехугольника)
	void Quadrilateral::find_type () {
		bool yes = false; //нужно если нашли фигуру, чтобы не попасть в ложное условие
		if ((a==b) && (b==c) && (c==d) && (angle_a == angle_b) && (angle_b == angle_c) && (angle_c==angle_d)) {
			type = Quadik::Sqare; //квадрат    
			yes = true;
		}
		if ((yes == false) && (a==b) && (b==c) && (c==d) && (angle_a != angle_b) && (angle_d != angle_c) && (angle_a == angle_c) && (angle_d == angle_b)){
			type = Quadik::Rhombus; //ромб
			yes = true;
		}
		if ((yes == false) && (a!=d) && (b!=c) && (a!=b) && (a==c) && (b==d) && (c!=d) && (angle_a == angle_b) && (angle_b == angle_c) && (angle_c==angle_d)){
			type = Quadik::Rectangle; //прямоугольник
			yes = true;
		}
		if ((yes == false) && (a!=d) && (b!=c) && (a!=b) && (a==c) && (b==d) && (c!=d) && (angle_a != angle_b) && (angle_d != angle_c) && (angle_a == angle_c) && (angle_d == angle_b)){
			type = Quadik::Parallelogram; //параллелограмм
			yes = true;
		}
		if ((yes == false) && (a==d) && (b==c) && (a!=b) && (a!=c) && (d!=b) && (b!=a) && (angle_a == angle_c)){
			type = Quadik::Deltoid; //дельтоид
			yes = true;
		}
		if ((yes == false) && (angle_a != angle_b) && (angle_c != angle_d) && (trunc(angle_a+angle_b) == 180) && (trunc(angle_d+angle_c) == 180)){
			type = Quadik::Trapezoid; //трапеция общего вида
			yes = true;
		}
		if (yes == false)
			type = Quadik::Other;
	}

/// проверка на выпуклость (Операция: Проверка на выпуклость четырехугольника )
	bool Quadrilateral::check_convex() const{ 
    // Вычисляем два вектора между соседними точками
    double v1x = x2 - x1;
    double v1y = y2 - y1;
    double v2x = x3 - x2;
    double v2y = y3 - y2;
    // Вычисляем векторное произведение этих векторов
    double Prod1 = v1x * v2y - v1y * v2x;
    // Повторяем для оставшихся двух сторон четырехугольника
    v1x = x3 - x2;
    v1y = y3 - y2;
    v2x = x4 - x3;
    v2y = y4 - y3;
    double Prod2 = v1x * v2y - v1y * v2x;
    // Если знаки векторных произведений одинаковые, то четырехугольник выпуклый
    if (Prod1 * Prod2 >= 0) 
    	return true;
    else 
    	return false;
}

/// радиус описанной окружности (Операция: Расчет радиуса описанной окружности четырехугольника)
	double Quadrilateral::rad_around() const{
	double p = (a+b+c+d)/2;  //полупериметр
	double res = 0;
	if (type == Quadik::Other)
		res = 0.25 * sqrt(((a*b+c*d)*(a*d+b*c)*(a*c+b*d))/((p-a)*(p-b)*(p-c)*(p-d)));
	if (type == Quadik::Sqare)
		res = a/sqrt(2);
	if (type == Quadik::Rectangle)
		res = (sqrt(a * a + b * b))/2;
	if (type == Quadik::Trapezoid) 
		{if (d == b) {
			double h = sqrt(c * c - pow(((a-b)/(2)),2));
			double temp = sqrt(h*h + pow(((c+b)/(2)),2)); 
			res = ((temp*c*b)/(4 * sqrt(p*(p-b)*(p-temp)*(p-c)))); }
			else
			res = 0.0;}		
	return res;
}

/// радиус вписанной окружности в четырёхугольник (Операция:  Расчет радиуса вписанной окружности четырехугольника)
	double Quadrilateral::rad_in() const{
	double res = 0;
	if (type == Quadik::Sqare)
		res = a/2; 
	if (type == Quadik::Trapezoid)
		if ((b==d)||(a==c)||(a==b)||(c==d)) //проверяем на равнобедренность
			{
				double h = sqrt(c * c - pow(((a-b)/(2)),2));
				res = h/2; 
			}
			else
			res = 0.0;
	if (type == Quadik::Rhombus)
		{
			double temp;
			if (angle_a<angle_b)
				temp = angle_b;
			else
				temp = angle_a;
			double D_big = (2 * a * sin(temp/2)) - 0.5;
			double D_smal = sqrt(4*(a*a)-(D_big*D_big));
			res = (D_big*D_smal)/(4*a);
		}		
	return res;
}
 
/// метод to string (Операция: Вывод результатов)
	std::string Quadrilateral::fin_to_string () const{
		std::string ss = "Other";  		//разбиваем перечислимый тип на строки
		if (type == Quadik::Sqare)
			ss = "Sqare";
		if (type == Quadik::Rhombus)
			ss = "Rhombus";
		if (type == Quadik::Rectangle)
			ss = "Rectangle";
		if (type == Quadik::Parallelogram)
			ss = "Parallelogram";
		if (type == Quadik::Deltoid)
			ss = "Deltoid";
		if (type == Quadik::Trapezoid)
			ss = "Trapezoid";
		std::string s = "Length a = " + std::to_string(a) + "\n" + "Length b = " + std::to_string(b) + "\n" + "Length c = " + std::to_string(c) + "\n" 
		+ "Length d = " + std::to_string(d) + "\n" + "A angle = " + std::to_string(angle_a) + "\n" + "B angle = " + std::to_string(angle_b) + "\n" 
		+ "C angle = " + std::to_string(angle_c) + "\n" + "D angle = " + std::to_string(angle_d) + "\n" 
		+ "It's a " + ss + "\n" + (check_convex() ? "Your quadrilateral is convex" : "Your quadrilateral is not convex") + "\n"  
		+ "Circumradius = " + std::to_string(rad_around()) + "\n"  + "Inscribed circle radius = " + std::to_string(rad_in()) + "\n" 
		+ "S of your quadrilateral = " + std::to_string(S()) + "\n" + "P of your quadrilateral = " + std::to_string(P()) + "\n";  
		return s;
	}

	// Подопытный - прямоугольник (1,3) (4,3) (4,1) (1,1)
	void test_code () {
		Quadrilateral Test;
	{	
	Test.set_x1 (1);			Test.set_y1 (3);  //Если использовать конструктор, то он не определяет точки
	Test.set_x2 (4);			Test.set_y2 (3);
	Test.set_x3 (4);			Test.set_y3 (1);
	Test.set_x4 (1);			Test.set_y4 (1);
	}

		Test.a=Test.find_length(1,3,4,3);
		Test.b=Test.find_length(4,3,4,1);
		Test.c=Test.find_length(4,1,1,1);
		Test.d=Test.find_length(1,1,1,3);
		assert(Test.a == 3.0);	
		assert(Test.b == 2.0);
		assert(Test.c == 3.0);
		assert(Test.d == 2.0);

		Test.angle_a=Test.find_angle(1,3,4,3,4,1);
		Test.angle_b=Test.find_angle(4,3,4,1,1,1);
		Test.angle_c=Test.find_angle(4,1,1,1,1,3);
		Test.angle_d=Test.find_angle(1,1,1,3,4,3);
		assert(Test.angle_a == 90.0);	
		assert(Test.angle_b == 90.0);
		assert(Test.angle_c == 90.0);
		assert(Test.angle_d == 90.0);

		assert(Test.check_convex() == true);

		Test.find_type();
		assert (Test.type == 2);

		assert(Test.S() == 6.00);
		assert(Test.P() == 10.00);

		double temp = round(Test.rad_in()*100)/100;
		assert(temp==0);
		temp = round(Test.rad_around()*100)/100;
		assert(temp==1.8);
	}
