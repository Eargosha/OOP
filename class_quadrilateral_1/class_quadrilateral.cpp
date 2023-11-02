// Автор Eargosha, ИВТ-22
// Класс квадратов

#define _USE_MATH_DEFINES
#include "class_quadrilateral.h"
#include <cmath>
#include <string>

/// Конструктор
	Quadrilateral::Quadrilateral(){
		x1 = 0; y1 = 0;
		x2 = 0; y2 = 0;
		x3 = 0; y3 = 0;
		x4 = 0; y4 = 0;	
		a,b,c,d = 0;
		angle_a, angle_b, angle_c, angle_d = 0;
		type = "Other quadrilateral"; }

/// геттер x,y x i-ой точки (Операция: Прочитать x,y i-ой (i=1,2,3,4) точки четырехугольника)
	double Quadrilateral::get_x1(){return x1;} double Quadrilateral::get_y1(){return y1;} //i=1
	double Quadrilateral::get_x2(){return x2;} double Quadrilateral::get_y2(){return y2;} //i=2
	double Quadrilateral::get_x3(){return x3;} double Quadrilateral::get_y3(){return y3;} //i=3
	double Quadrilateral::get_x4(){return x4;} double Quadrilateral::get_y4(){return y4;} //i=4

/// сеттер x,y x i-ой точки (Операция: Ввод x,y i-ой (i=1,2,3,4) точки четырехугольника)
	void Quadrilateral::set_x1(double x_1){x1 = x_1;} void Quadrilateral::set_y1(double y_1){y1 = y_1;} //i=1
	void Quadrilateral::set_x2(double x_2){x2 = x_2;} void Quadrilateral::set_y2(double y_2){y2 = y_2;} //i=2 
	void Quadrilateral::set_x3(double x_3){x3 = x_3;} void Quadrilateral::set_y3(double y_3){y3 = y_3;} //i=3 
	void Quadrilateral::set_x4(double x_4){x4 = x_4;} void Quadrilateral::set_y4(double y_4){y4 = y_4;} //i=4 

/// геттеры a,b,c,d (Операция: Прочитать сторону (a,b,c,d) четырехугольника )
	double Quadrilateral::get_a(){return a;} 
	double Quadrilateral::get_b(){return b;}
	double Quadrilateral::get_c(){return c;}
	double Quadrilateral::get_d(){return d;}

/// геттеры углов (Операция: Прочитать угол (angle_a, angle_b, angle_c, angle_d) четырехугольника)
	double Quadrilateral::get_angle_a(){return angle_a;} 
	double Quadrilateral::get_angle_b(){return angle_b;}
	double Quadrilateral::get_angle_c(){return angle_c;}
	double Quadrilateral::get_angle_d(){return angle_d;}

/// нахождение длины сторон и углов четырёхугольника (Операция: Нахождение характеристик четырёхугольника)
	void Quadrilateral::find_angle_length () {
		// Вычисляем векторы между точками
    	double v1x = x2 - x1;
    	double v1y = y2 - y1;
    	double v2x = x3 - x2;
    	double v2y = y3 - y2;
    	double v3x = x4 - x3;
    	double v3y = y4 - y3;
    	double v4x = x1 - x4;
    	double v4y = y1 - y4;

    	a = sqrt(pow((v1x), 2) + pow((v1y),2)); //формула длины стороны четырёхугольника
		b = sqrt(pow((v2x), 2) + pow((v2y),2));
		c = sqrt(pow((v3x), 2) + pow((v3y),2));
		d = sqrt(pow((v4x), 2) + pow((v4y),2));

		double Prod;
    	// Вычисляем скалярное произведение векторов
    	Prod = v1x * v2x + v1y * v2y;
    	angle_a = (acos(Prod / (a * b))) * 180.0 / M_PI; // находим углы

    	Prod = v2x * v3x + v2y * v3y;
    	angle_b = (acos(Prod / (b * c))) * 180.0 / M_PI;

    	Prod = v3x * v4x + v3y * v4y;
    	angle_c = (acos(Prod / (c * d))) * 180.0 / M_PI;

    	Prod = v4x * v1x + v4y * v1y;
    	angle_d = (acos(Prod / (d * a))) * 180.0 / M_PI;
	}

// /// нахождение длины сторон четырёхугольника (Операция: Нахождение длины сторон четырёхугольника)
// 	void Quadrilateral::find_length () {
// 		a = sqrt(pow((x2-x1), 2) + pow((y2-y1),2)); //формула длины стороны четырёхугольника
// 		b = sqrt(pow((x3-x2), 2) + pow((y3-y2),2));
// 		c = sqrt(pow((x4-x3), 2) + pow((y4-y3),2));
// 		d = sqrt(pow((x1-x4), 2) + pow((y1-y4),2));
// 	}

// /// нахождение углов (Операция: Нахождение углов четырёхугольника)
// 	void Quadrilateral::find_angle ()
// 	{
// 		// Вычисляем векторы между точками
//     	double v1x = x2 - x1;
//     	double v1y = y2 - y1;
//     	double v2x = x3 - x2;
//     	double v2y = y3 - y2;
//     	double v3x = x4 - x3;
//     	double v3y = y4 - y3;
//     	double v4x = x1 - x4;
//     	double v4y = y1 - y4;

//     	double Prod;
//     	// Вычисляем скалярное произведение векторов
//     	Prod = v1x * v2x + v1y * v2y;
//     	angle_a = (acos(Prod / (a * b))) * 180.0 / M_PI; // находим углы

//     	Prod = v2x * v3x + v2y * v3y;
//     	angle_b = (acos(Prod / (b * c))) * 180.0 / M_PI;

//     	Prod = v3x * v4x + v3y * v4y;
//     	angle_c = (acos(Prod / (c * d))) * 180.0 / M_PI;

//     	Prod = v4x * v1x + v4y * v1y;
//     	angle_d = (acos(Prod / (d * a))) * 180.0 / M_PI;
// 	}

/// нахождение периметра четырёхугольника (Операция: Расчет P четырехугольника)
	double Quadrilateral::P (){
		return a+b+c+d;
	}

/// нахождение площади четырёхугольника (Операция: Расчет S четырехугольника )
	double Quadrilateral::S () {
		return abs(((x4*y3+x3*y2+x2*y1+x1*y4)-(y4*x3+y3*x2+y2*x1+y1*x4))/2);
	}

/// определение вида четырёхугольника (Операция: Определить вид четырехугольника)
	void Quadrilateral::find_type () {
		bool yes = false; //нужно если нашли фигуру, чтобы не попасть в ложное условие
		if ((a==b) && (b==c) && (c==d) && (angle_a == angle_b) && (angle_b == angle_c) && (angle_c==angle_d)) {
			type = "Sqare"; //квадрат
			yes = true;
		}
		if ((yes == false) && (a==b) && (b==c) && (c==d) && (angle_a != angle_b) && (angle_d != angle_c) && (angle_a == angle_c) && (angle_d == angle_b)){
			type = "Rhombus"; //ромб
			yes = true;
		}
		if ((yes == false) && (a!=d) && (b!=c) && (a!=b) && (a==c) && (b==d) && (c!=d) && (angle_a == angle_b) && (angle_b == angle_c) && (angle_c==angle_d)){
			type = "Rectangle"; //прямоугольник
			yes = true;
		}
		if ((yes == false) && (a!=d) && (b!=c) && (a!=b) && (a==c) && (b==d) && (c!=d) && (angle_a != angle_b) && (angle_d != angle_c) && (angle_a == angle_c) && (angle_d == angle_b)){
			type = "Parallelogram"; //параллелограмм
			yes = true;
		}
		if ((yes == false) && (a==d) && (b==c) && (a!=b) && (a!=c) && (d!=b) && (b!=a) && (angle_a == angle_c)){
			type = "Deltoid"; //дельтоид
			yes = true;
		}
		if ((yes == false) && (angle_a != angle_b) && (angle_c != angle_d) && (trunc(angle_a+angle_b) == 180) && (trunc(angle_d+angle_c) == 180)){
			type = "Trapezoid"; //трапеция общего вида
			yes = true;
		}
		if (yes == false)
			type = "Other quadrilateral";
	}

/// проверка на выпуклость (Операция: Проверка на выпуклость четырехугольника )
	std::string Quadrilateral::check_vip() {
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
    if (Prod1 * Prod2 >= 0) {
        return "Your "+type+" is convex";
    } else {
        return "Your "+type+" is not convex";
    }
}

/// радиус описанной окружности (Операция: Расчет радиуса описанной окружности четырехугольника)
	double Quadrilateral::rad_around(){
	double p = (a+b+c+d)/2;  //полупериметр
	double res = 0;
	if (type == "Other quadrilateral")
		res = 0.25 * sqrt(((a*b+c*d)*(a*d+b*c)*(a*c+b*d))/((p-a)*(p-b)*(p-c)*(p-d)));
	if (type == "Sqare")
		res = a/sqrt(2);
	if (type == "Rectangle")
		res = (sqrt(a * a + b * b))/2;
	if (type == "Trapezoid") 
		{if (d == b) {
			double h = sqrt(c * c - pow(((a-b)/(2)),2));
			double temp = sqrt(h*h + pow(((c+b)/(2)),2)); 
			res = ((temp*c*b)/(4 * sqrt(p*(p-b)*(p-temp)*(p-c)))); }
			else
			res = 0.0;}		
	return res;
}

/// радиус вписанной окружности в четырёхугольник (Операция:  Расчет радиуса вписанной окружности четырехугольника)
	double Quadrilateral::rad_in(){
	double p = (a+b+c+d)/2;
	double res = 0;
	if (type == "Sqare")
		res = a/2; 
	if (type == "Trapezoid")
		if ((b==d)||(a==c)||(a==b)||(c==d)) //проверяем на равнобедренность
			{
				double h = sqrt(c * c - pow(((a-b)/(2)),2));
				res = h/2; 
			}
			else
			res = 0.0;
	if (type == "Rhombus")
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
	std::string Quadrilateral::fin_to_string () { 
		std::string s = "Length a = " + std::to_string(a) + "\n" + "Length b = " + std::to_string(b) + "\n" + "Length c = " + std::to_string(c) + "\n" 
		+ "Length d = " + std::to_string(d) + "\n" + "A angle of your "+type+" = " + std::to_string(angle_a) + "\n" 
		+ "B angle of your "+type+" = " + std::to_string(angle_b) + "\n" + "C angle of your "+type+" = " + std::to_string(angle_c) + "\n" 
		+ "D angle of your "+type+" = " + std::to_string(angle_d) + "\n"+ "It's a " + type + "\n" + check_vip() + "\n"  
		+ "Circumradius = " + std::to_string(rad_around()) + "\n"  + "Inscribed circle radius = " + std::to_string(rad_in()) + "\n" 
		+ "S of your "+type+" = " + std::to_string(S()) + "\n" + "P of your "+type+" = " + std::to_string(P()) + "\n";
		return s;
	}

