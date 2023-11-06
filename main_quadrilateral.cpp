// Автор Eargosha, Иванов Егор, ИВТ-22
// Класс квадратов

#include "class_quadrilateral.h"
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main () {
	// Quad - экземпляр класса Quadrilateral
	Quadrilateral Quad;

	// Производим тестирование кода
	test_code_rectangle();
	test_code_parall ();

	// Динамическое создание объекта
	Quadrilateral * Quad_din = new Quadrilateral;
	(*Quad_din).set_x1(50); //работа с его методами первым способом
	Quad_din->set_y1(25); 	//работа с его методами вторым способом
	cout << "1-st coordinate of dynamic object is x = " << Quad_din->get_x1() << ", y = "<< Quad_din->get_y1() << endl;
	delete Quad_din; 		//удаление динамического объекта

	// Стат массив из объектов
	Quadrilateral Quad_mas[1];
	Quad_mas[0].set_x1(10);
	Quad_mas[1].set_x1(-10);
	cout << "1-st coordinate x of Quad_mas[0] = " << Quad_mas[0].get_x1() << endl;
	cout << "1-st coordinate x of Quad_mas[1] = " << Quad_mas[1].get_x1() << endl;

	Quadrilateral Quad_mo[2] { Quadrilateral(1,2,3,4,5,6,7,8),
							   Quadrilateral(8,7,6,5,4,3,2,1) };

	// Массив из указателей на объекты
	Quadrilateral *Quad_uk[2];
	Quad_uk[0] = new Quadrilateral();
	Quad_uk[1] = new Quadrilateral(1,2,3,4,5,6,7,8);	

	delete Quad_uk[0];
	delete Quad_uk[1];

	// Дин. массив из указателей на объекты
 	Quadrilateral * * Quad_din_uk = new Quadrilateral* [10];
 	for (int i = 0; i < 10; i++) Quad_din_uk[i] = new Quadrilateral(); //создание
 	for (int i = 0; i < 10; i++) delete Quad_din_uk[i]; //удаление
	//delete[] Quad_din_uk; //удалить весь		   

 	// Массив с помощью векторов
 	vector<Quadrilateral> Quad_vec(3);

 	// Массив с помощью векторов из указателей
 	vector<Quadrilateral*> Quad_vec_uk(3);
 	for (int i = 0; i < Quad_vec_uk.size(); i++) Quad_vec_uk[i] = new Quadrilateral(); //создание

	char stop = '1';
	while (stop == '1')
	{
	cout << "========================================================================="<<endl; 
	cout << "Enter the coordinates of the points of your quadrilateral..." << endl; //производим ввод координат
	double temp;
	for (unsigned i = 0; i < 4; i++)
	{
		cout << "Enter coordinate x" << i+1 << ": ";
		cin >> temp;
		switch (i) {
		case 0: Quad.set_x1(temp); break;
		case 1: Quad.set_x2(temp); break;
		case 2: Quad.set_x3(temp); break;
		case 3: Quad.set_x4(temp); break;
		}
		cout << "Enter coordinate y" << i+1 << ": ";
		cin >> temp;
		switch (i) {
		case 0: Quad.set_y1(temp); break;
		case 1: Quad.set_y2(temp); break;
		case 2: Quad.set_y3(temp); break;
		case 3: Quad.set_y4(temp); break;
		}
	}

	char ask2;
	cout << "Start changing coordinates? 1/0: ";	//спрашиваем про изменение координат
	cin >> ask2;
	while (ask2 == '1'){
	cout << "Enter number if coordinate: ";
	char ask;
	cin >> ask;
		switch (ask) {								//если что = меняем
		case '1': {cout << "New x = "; cin >> temp; Quad.set_x1(temp);
				   cout << "New y = "; cin >> temp; Quad.set_y1(temp); break;}
		case '2': {cout << "New x = "; cin >> temp; Quad.set_x2(temp);
				   cout << "New y = "; cin >> temp; Quad.set_y2(temp); break;}
		case '3': {cout << "New x = "; cin >> temp; Quad.set_x3(temp);
				   cout << "New y = "; cin >> temp; Quad.set_y3(temp); break;}
		case '4': {cout << "New x = "; cin >> temp; Quad.set_x4(temp);
				   cout << "New y = "; cin >> temp; Quad.set_y4(temp); break;}
		}
	cout << "New coordinates:" << endl;				//выводим то что получилось
	cout << "x1 = " << Quad.get_x1() << " y1 = " << Quad.get_y1() << endl;
	cout << "x2 = " << Quad.get_x2() << " y2 = " << Quad.get_y2() << endl;
	cout << "x3 = " << Quad.get_x3() << " y3 = " << Quad.get_y3() << endl;
	cout << "x4 = " << Quad.get_x4() << " y4 = " << Quad.get_y4() << endl;

	cout << "Continue changing? 1/0: ";
	cin >> ask2;
	}

	cout << Quad.fin_to_string ();					//выводим одним методом все результаты
	cout << "Start again? 1/0: "; 
	cin >> stop;									//повторный запуск
}
}