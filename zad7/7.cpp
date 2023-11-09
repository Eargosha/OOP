//Иванов Егор
// Задача 7
// https://ivtipm.github.io/Programming/Glava01/index01.htm#z7


#include <math.h>		  //для работы математики
#include <iostream>       //библиотека cin cout
#include <cassert>		  //для assert
#include <string>
#include "module_for_7.h" //мой модуль


using namespace std;  //пространоство имен

const float EPS = 10e-2;  //константа для assert

int main(int argc, char *argv[])
{

	//проверки двух функций при помощи assert
	assert(all_v(10,20) == 30);
	assert(all_v(123,220) == 343);
	assert(all_v(100,200) == 300);
	assert(all_temp(15,10,15,-50) == -11);
	assert(abs(all_temp(25,30,10,-50) + 22.72)<EPS);
	assert(abs(all_temp(10,30,5,8) - 7.25)<EPS);


	/// Переменные, что используются в проге
	float v1, v2, t1, t2, nv, m1, m2, nt; 

	string carg;
	int n;
	n = argc;

	if (n > 1)
	{
		carg = argv [1];
		if (carg == "help")									// Если введут хельп
		{
		cout << "- You can use this program with the following first arguments: 'solve'" << endl;
		cout << "- If 'solve' then type <v1> <t1> <v2> <t2>" << endl;
		}	
		if (carg == "solve")
		{
		v1 = stof (argv[2]);
		t1 = stof (argv[3]);
		v2 = stof (argv[4]);
		t2 = stof (argv[5]);
		cout << "V of finile water = " << all_v(v1,v2) << " and T of finile water = " << all_temp(v1,v2,t1,t2) << endl;  //финальный вывод
		}
	}
	else
	{
	cout << "v1 = "; //Вводим данные обьем
	cin >> v1;

	cout << "t1 = "; //Вводим данные темп
	cin >> t1;

	cout << "v2 = "; //Вводим данные обьем 2
	cin >> v2;

	cout << "t2 = "; //Вводим данные темп 2
	cin >> t2;  

	//вывод результата
	cout << "V of finile water = " << all_v(v1,v2) << " and T of finile water = " << all_temp(v1,v2,t1,t2) << endl;  //финальный вывод
	}
}
