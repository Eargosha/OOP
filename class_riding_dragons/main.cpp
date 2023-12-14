///Eargosha|Иванов Егор, ИВТ-22
///Main file of class

#include <iostream>
#include <vector>
#include "riding_dragon.h"
#include "knight.h"
#include <cassert>
using namespace std;

int main()
{
	srand((time(NULL)));

		//Тесты
	test_seadle();
	test_draconate();
	test_hydra();
	test_wyvern();
	test_sword();
	test_knight();


	cout << "Welcome to riding dragon something like a console thing?.." << endl;
	cout << "Anyway let's get started..." << endl;

	Seadle *sed = new Seadle(5.0, Seadle::Color_4::Blue, Seadle::Material_4::Poof);  		   //создаём седло вне видимости других классов дракона

		//Всё эти создания обьектов можно реализовать через ввод с помощью switch case и cin, сейчас просто передача параметров для демонстрации
	{
	cout<<"========================================= First dragon ========================================="<< endl;
	string nume = "Snowfoot";
	Wyvern snowfoot(nume, Riding_Dragon::Element_4::Air, 10000.0, 500.0, 10.0, 500.0, 0,sed, 50, 50); //создаем обьект класса виверны
	cout<<snowfoot.roar();
	cout << snowfoot.to_string();

	cout<<"His knight"<< endl;
	Knight ric_1("George", 75, 25, "Torch", 75, 5, Sword::Type_4::Short);
	cout<<ric_1.to_string();

	cout<<"========================================= Second dragon ========================================="<< endl;
	nume = "Aevere";
	Hydra aevere(nume, Riding_Dragon::Element_4::Earth, 5000.0, 500.0, 25.0, 500.0, 5,sed, 3);	//создаем обьект класса гидры
	cout<<aevere.roar();
	cout << aevere.to_string();

	cout<<"His knight"<< endl;
	Knight ric_2("Peter", 25, 45, "Arrow Of The Fate", 32, 15, Sword::Type_4::Two_handed);
	cout<<ric_2.to_string();

	cout<<"========================================= Third dragon ========================================="<< endl;
	nume = "Kazyan";
	Draconate kazyan(nume, Riding_Dragon::Element_4::Fire, 8000.0, 500.0, 20.0, 500.0, 5,sed, 30);	//создаем обьект класса драконейт
	cout<<kazyan.roar();
	cout << kazyan.to_string();
					/// Да начнется бой
	cout<<"==================================== Let's start the battle! ==================================="<< endl;
		//Тут происходят баталии между драконами и рыцарями
	cout<<kazyan.speak_to_knight("I will smash u'll like a boiled potato!")<<endl;
	cout<<kazyan.dragon_melee_attack(snowfoot);
	cout<<kazyan.dragon_ranged_attack(aevere);

	cout<<ric_1.heal_dragon(snowfoot);

	cout<<snowfoot.roar();
	cout<<snowfoot.random_attack(kazyan);
	cout<<snowfoot.dragon_melee_attack(aevere);

	cout<<aevere.conversation();
	cout<<aevere.roar();
	cout<<aevere.dragon_ranged_attack(snowfoot);
	cout<<ric_2.dragon_attack(kazyan);
	cout<<aevere.dragon_melee_attack(kazyan);
		//В конце выведется статистика того, что они натворили
	cout<<"========================================= At the end... ========================================"<< endl;
	cout << "~~~~~~~~~~~ First dragon: ~~~~~~~~~~~" << endl;
	cout << snowfoot.to_string();
	cout << "~~~~~~~~~~~ Second dragon: ~~~~~~~~~~~" << endl;
	cout << aevere.to_string();
	cout << "~~~~~~~~~~~ Third dragon: ~~~~~~~~~~~" << endl;
	cout << kazyan.to_string();
	}

	//Другие классы ушли со своей зоной видимости, а вот седло такое вот такое вот крутое осталось
	cout << endl;
	cout << "All participants in today's battle used this saddle" << endl;
	cout<<sed->to_string();  
}