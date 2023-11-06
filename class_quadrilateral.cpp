// Автор Eargosha, Иванов Егор, ИВТ-22
// Класс квадратов

#define _USE_MATH_DEFINES
#include "class_quadrilateral.h"
#include <cmath>
#include <string>
#include <cassert>

///добавить тест нового обьекта на поиск типа и на поиск углов

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
	double Quadrilateral::find_length (double x1, double y1, double x2, double y2) const {
		return sqrt(pow((x2-x1), 2) + pow((y2-y1),2)); //формула длины стороны четырёхугольника
	}

/// вычисляем длины сторон a,b,c,d
	double Quadrilateral::find_a() const{ return find_length(x1,y1,x2,y2); }
	double Quadrilateral::find_b() const{ return find_length(x2,y2,x3,y3); }
	double Quadrilateral::find_c() const{ return find_length(x3,y3,x4,y4); }
	double Quadrilateral::find_d() const{ return find_length(x4,y4,x1,y1); }

/// нахождение углов (Операция: Нахождение углов в градусах четырёхугольника)
	double Quadrilateral::find_angle (double x1, double y1, double x2, double y2, double x3, double y3) const
	{
		// Вычисляем характеристики векторов между точками
    	double v1x = x2 - x1;
    	double v1y = y2 - y1;
    	double v2x = x3 - x2;
    	double v2y = y3 - y2;

    	// Вычисляем векторное произведение векторов
    	double Prod;
    	Prod = v1x * v2x + v1y * v2y;

    	return (acos(Prod / (find_length(x1,y1,x2,y2) * find_length(x2,y2,x3,y3)))) * 180.0 / M_PI; //сразу находим углы в градусах
	}

/// вычисляем углы a,b,c,d
	double Quadrilateral::find_angle_a() const{ return find_angle(x1,y1,x2,y2,x3,y3); }
	double Quadrilateral::find_angle_b() const{ return find_angle(x2,y2,x3,y3,x4,y4); }
	double Quadrilateral::find_angle_c() const{ return find_angle(x3,y3,x4,y4,x1,y1); }
	double Quadrilateral::find_angle_d() const{ return find_angle(x4,y4,x1,y1,x2,y2); }


/// нахождение периметра четырёхугольника (Операция: Расчет P четырехугольника)
	double Quadrilateral::P () const{
		return find_a()+find_b()+find_c()+find_d();
	}

/// нахождение площади четырёхугольника (Операция: Расчет S четырехугольника )
	double Quadrilateral::S () const{
		return abs(((x4*y3+x3*y2+x2*y1+x1*y4)-(y4*x3+y3*x2+y2*x1+y1*x4))/2);
	}

/// определение вида четырёхугольника (Операция: Определить вид четырехугольника)
	typeof Quadrilateral::type Quadrilateral::find_type () const {
		bool yes = false; //если нашли уже фигуру, то кидаем метку, чтобы не попасть в ложное условие
		if ((find_a()==find_b()) && (find_b()==find_c()) && (find_c()==find_d()) && (find_angle_a() == find_angle_b()) && (find_angle_b() == find_angle_c()) && (find_angle_c()==find_angle_d())) {
			return Quadik::Sqare; 						//квадрат    
			yes = true;
		}
		if ((yes == false) && (find_a()==find_b()) && (find_b()==find_c()) && (find_c()==find_d()) && (find_angle_a() != find_angle_b()) && (find_angle_d() != find_angle_c()) && (find_angle_a() == find_angle_c()) && (find_angle_d() == find_angle_b())){
			return Quadik::Rhombus; 					//ромб
			yes = true;
		}
		if ((yes == false) && (find_a()!=find_d()) && (find_b()!=find_c()) && (find_a()!=find_b()) && (find_a()==find_c()) && (find_b()==find_d()) && (find_c()!=find_d()) && (find_angle_a() == find_angle_b()) && (find_angle_b() == find_angle_c()) && (find_angle_c()==find_angle_d())){
			return Quadik::Rectangle;					//прямоугольник
			yes = true;
		}
		int temp3 = (x4-x3)/(x2-x1); //легка проверка на коллинеальность для параллелограмма...
		bool bo = false;
		if (temp3 * (x2-x1) == (x4-x3))
			bo = true;
		if ((yes == false) && (find_a()!=find_d()) && (find_b()!=find_c()) && (bo==true) && (find_angle_a() != find_angle_b()) && (find_angle_d() != find_angle_c()) ){
			return Quadik::Parallelogram; 				//параллелограмм
			yes = true;
		}
		if ((yes == false) && (find_a()==find_d()) && (find_b()==find_c()) && (find_a()!=find_b()) && (find_a()!=find_c()) && (find_d()!=find_b()) && (find_b()!=find_a()) && (find_angle_a() == find_angle_c())){
			return Quadik::Deltoid; 					//дельтоид
			yes = true;
		}
		 if ((yes == false) && (find_angle_a() != find_angle_b()) && (find_angle_c() != find_angle_d()) && (trunc(find_angle_a()+find_angle_b()) == 180) && (trunc(find_angle_d()+find_angle_c()) == 180)){
		 	return Quadik::Trapezoid; 					//трапеция общего вида
		 	yes = true;
		}
		if (yes == false)
			return Quadik::Other;  //выдает ошибку при компиляции, что нет ретерна, хоть он и есть???
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
	double p = (find_a()+find_b()+find_c()+find_d())/2;  //полупериметр для других четырёхугольников
	double res = 0;
	if (find_type() == Quadik::Other)			//если тип другой, вычисляем так
		res = 0.25 * sqrt(((find_a()*find_b()+find_c()*find_d())*(find_a()*find_d()+find_b()*find_c())*(find_a()*find_c()+find_b()*find_d()))/((p-find_a())*(p-find_b())*(p-find_c())*(p-find_d())));
	if (find_type() == Quadik::Sqare)			//если тип квадрат, вычисляем так
		res = find_a()/sqrt(2);
	if (find_type() == Quadik::Rectangle)		//если тип прямоугольник, вычисляем так	
		res = (sqrt(find_a() * find_a() + find_b() * find_b()))/2;
	if (find_type() == Quadik::Trapezoid) 		//если тип трапеция, вычисляем так
		{if (find_d() == find_b()) {	//проверка на равнобедренность, иначе будет = 0
			double h = sqrt(find_c() * find_c() - pow(((find_a()-find_b())/(2)),2));
			double temp = sqrt(h*h + pow(((find_c()+find_b())/(2)),2)); 
			res = ((temp*find_c()*find_b())/(4 * sqrt(p*(p-find_b())*(p-temp)*(p-find_c())))); }
			else
			res = 0.0;}		
	return res;
}

/// радиус вписанной окружности в четырёхугольник (Операция:  Расчет радиуса вписанной окружности четырехугольника)
	double Quadrilateral::rad_in() const{
	double res = 0;
	if (find_type() == Quadik::Sqare)			//если тип квадрат, вычисляем так
		res = find_a()/2; 
	if (find_type() == Quadik::Trapezoid)		//если тип трапеция, вычисляем так
		if ((find_b()==find_d())||(find_a()==find_c())||(find_a()==find_b())||(find_c()==find_d())) //проверяем на равнобедренность
			{
				double h = sqrt(find_c() * find_c() - pow(((find_a()-find_b())/(2)),2));
				res = h/2; 
			}
			else
			res = 0.0;
	if (find_type() == Quadik::Rhombus)			//если тип ромб, вычисляем так
		{
			double temp;
			if (find_angle_a()<find_angle_b())	//находим больший угол, затем ищем диагонали, а там по формуле
				temp = find_angle_b();
			else
				temp = find_angle_a();
			double D_big = (2 * find_a() * sin(temp/2)) - 0.5;
			double D_smal = sqrt(4*(find_a()*find_a())-(D_big*D_big));
			res = (D_big*D_smal)/(4*find_a());
		}		
	return res;
}
 
/// метод to string (Операция: Вывод результатов)
	std::string Quadrilateral::fin_to_string () const{

		std::string ss = "Other";  				//разбиваем перечислимый тип на строки
		if (find_type() == Quadik::Sqare)
			ss = "Sqare";
		if (find_type() == Quadik::Rhombus)
			ss = "Rhombus";
		if (find_type() == Quadik::Rectangle)
			ss = "Rectangle";
		if (find_type() == Quadik::Parallelogram)
			ss = "Parallelogram";
		if (find_type() == Quadik::Deltoid)
			ss = "Deltoid";
		if (find_type() == Quadik::Trapezoid)
			ss = "Trapezoid";
												//формируем строку вывода
		std::string s = "Length a = " + std::to_string(find_a()) + "\n" + "Length b = " + std::to_string(find_b()) + "\n" + "Length c = " + std::to_string(find_c()) + "\n" 
		+ "Length d = " + std::to_string(find_d()) + "\n" + "A angle = " + std::to_string(find_angle_a()) + "\n" + "B angle = " + std::to_string(find_angle_b()) + "\n" 
		+ "C angle = " + std::to_string(find_angle_c()) + "\n" + "D angle = " + std::to_string(find_angle_d()) + "\n" 
		+ "It's a " + ss + "\n" + (check_convex() ? "Your quadrilateral is convex" : "Your quadrilateral is not convex") + "\n"  
		+ "Circumradius = " + std::to_string(rad_around()) + "\n"  + "Inscribed circle radius = " + std::to_string(rad_in()) + "\n" 
		+ "S of your quadrilateral = " + std::to_string(S()) + "\n" + "P of your quadrilateral = " + std::to_string(P()) + "\n";  
		return s;								//выводим
	}	

///Производим тестирование кода, подопытный - прямоугольник (1,3) (4,3) (4,1) (1,1)
	void test_code_rectangle () {
		Quadrilateral Test;
	{	
	Test.set_x1 (1);			Test.set_y1 (3);  	//устанавливаем точки
	Test.set_x2 (4);			Test.set_y2 (3);
	Test.set_x3 (4);			Test.set_y3 (1);
	Test.set_x4 (1);			Test.set_y4 (1);
	}

		assert(Test.find_a() == 3.0);				//проверяем длины
		assert(Test.find_b() == 2.0);
		assert(Test.find_c() == 3.0);
		assert(Test.find_d() == 2.0);

		assert(Test.find_angle_a() == 90.0);		//проверяем углы
		assert(Test.find_angle_b() == 90.0);
		assert(Test.find_angle_c() == 90.0);
		assert(Test.find_angle_d() == 90.0);

		assert(Test.check_convex() == true);		//проверяем выпуклость

		Test.find_type();							//проверяем тип
		assert (Test.find_type() == 2);			

		assert(Test.S() == 6.00);					//проверяем площадь
		assert(Test.P() == 10.00);					//проверяем периметр

		double temp = round(Test.rad_in()*100)/100;	//проверяем радиус в
		assert(temp==0);
		temp = round(Test.rad_around()*100)/100;	//проверяем радиус вокруг
		assert(temp==1.8);
	}

///Производим тестирование кода, подопытный - параллелограмм (-4,-5) (3,-2) (16,11) (9,8)
	void test_code_parall () {
		Quadrilateral Test;
	{	
	Test.set_x1 (-4);			Test.set_y1 (-5);  		//устанавливаем точки
	Test.set_x2 (3);			Test.set_y2 (-2);
	Test.set_x3 (16);			Test.set_y3 (11);
	Test.set_x4 (9);			Test.set_y4 (8);
	}
		double temp4 = round(Test.find_a()*100)/100;
		assert(temp4 == 7.62);	
		 temp4 = round(Test.find_b()*100)/100;			//проверяем длины, используется округление
		assert(temp4 == 18.38);
		 temp4 = round(Test.find_c()*100)/100;
		assert(temp4 == 7.62);
		 temp4 = round(Test.find_d()*100)/100;
		assert(temp4 == 18.38);

		temp4 = (round(Test.find_angle_a()*100)/100);	//проверяем углы, используется округление
		assert(temp4 == 21.80);
		temp4 = (round(Test.find_angle_b()*100)/100);	
		assert(temp4 == 158.2);
		temp4 = (round(Test.find_angle_c()*100)/100);	
		assert(temp4 == 21.80);	
		temp4 = (round(Test.find_angle_d()*100)/100);
		assert(temp4 == 158.2);	

		assert(Test.check_convex() == true);			//проверяем выпуклость

		Test.find_type();
		assert (Test.find_type() == 3);					//проверяем тип

		assert(Test.S() == 52.00);						//проверяем площадь
		temp4 = round(Test.P()*100)/100;
		assert(temp4 == 52.00);							//проверяем периметр

		double temp = round(Test.rad_in()*100)/100;		//проверяем радиус в
		assert(temp==0);
		temp = round(Test.rad_around()*100)/100;		//проверяем радиус вокруг
		assert(temp==0);
	}