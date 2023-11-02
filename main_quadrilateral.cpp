// Автор Eargosha, ИВТ-22
// Класс квадратов

#include "class_quadrilateral.h"
#include <iostream>
#include <cmath>

using namespace std;

int main () {
	// Quad - экземпляр класса Quadrilateral
	Quadrilateral Quad;

	//Производим тестирование кода
	test_code();

	char stop = '1';
	while (stop == '1')
	{
	cout << "========================================================================="<<endl; 
	cout << "Enter the coordinates of the points of your quadrilateral..." << endl; 
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
	cout << "Start changing coordinates? 1/0: ";
	cin >> ask2;
	while (ask2 == '1'){
	cout << "Enter number if coordinate: ";
	char ask;
	cin >> ask;
		switch (ask) {
		case '1': {cout << "New x = "; cin >> temp; Quad.set_x1(temp);
				   cout << "New y = "; cin >> temp; Quad.set_y1(temp); break;}
		case '2': {cout << "New x = "; cin >> temp; Quad.set_x2(temp);
				   cout << "New y = "; cin >> temp; Quad.set_y2(temp); break;}
		case '3': {cout << "New x = "; cin >> temp; Quad.set_x3(temp);
				   cout << "New y = "; cin >> temp; Quad.set_y3(temp); break;}
		case '4': {cout << "New x = "; cin >> temp; Quad.set_x4(temp);
				   cout << "New y = "; cin >> temp; Quad.set_y4(temp); break;}
		}
	cout << "New coordinates:" << endl;
	cout << "x1 = " << Quad.get_x1() << " y1 = " << Quad.get_y1() << endl;
	cout << "x2 = " << Quad.get_x2() << " y2 = " << Quad.get_y2() << endl;
	cout << "x3 = " << Quad.get_x3() << " y3 = " << Quad.get_y3() << endl;
	cout << "x4 = " << Quad.get_x4() << " y4 = " << Quad.get_y4() << endl;

	cout << "Continue changing? 1/0: ";
	cin >> ask2;
	}

	//Находим углы
	Quad.angle_a=Quad.find_angle(Quad.get_x1(), Quad.get_y1(), Quad.get_x2(), Quad.get_y2(), Quad.get_x3(), Quad.get_y3());
	Quad.angle_b=Quad.find_angle(Quad.get_x2(), Quad.get_y2(), Quad.get_x3(), Quad.get_y3(), Quad.get_x4(), Quad.get_y4());
	Quad.angle_c=Quad.find_angle(Quad.get_x3(), Quad.get_y3(), Quad.get_x4(), Quad.get_y4(), Quad.get_x1(), Quad.get_y1());
	Quad.angle_d=Quad.find_angle(Quad.get_x4(), Quad.get_y4(), Quad.get_x1(), Quad.get_y1(), Quad.get_x2(), Quad.get_y2());

	//Находим стороны
	Quad.a=Quad.find_length(Quad.get_x1(), Quad.get_y1(), Quad.get_x2(), Quad.get_y2());
	Quad.b=Quad.find_length(Quad.get_x2(), Quad.get_y2(), Quad.get_x3(), Quad.get_y3());
	Quad.c=Quad.find_length(Quad.get_x3(), Quad.get_y3(), Quad.get_x4(), Quad.get_y4());
	Quad.d=Quad.find_length(Quad.get_x4(), Quad.get_y4(), Quad.get_x1(), Quad.get_y1());

	Quad.find_type ();
	cout << Quad.fin_to_string ();
	cout << "Start again? 1/0: "; 
	cin >> stop;
}
}