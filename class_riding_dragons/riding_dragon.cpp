///Eargosha|Иванов Егор, ИВТ-22
///.cpp file for class Riding_Dragon

#include <exception>
#include <stdexcept>
#include <iostream>
#include <string>
#include <ctime>
#include <cmath>
#include "riding_dragon.h"
#include "knight.h"

using namespace std;




    								///Class Seadle

    /// Пустой конструктор
    Seadle::Seadle(){
    	set_color_of(Seadle::Color_4::Blue);      // по умолчанию все плохое
    	set_material(Seadle::Material_4::Silver);
    	set_comfortable(0);
    }
    /// Конструктор с параметрами
    Seadle::Seadle(double comfortable, Color_4 _color_of, Material_4 material_) {
    	set_color_of(_color_of);
    	set_material(material_);
    	set_comfortable(comfortable);
    }


    		/// Геттеры
    //цвета
    Seadle::Color_4 Seadle::get_color_of() const {return color_of;}
    //материала     
    Seadle::Material_4 Seadle::get_material() const {return material;}
    //комфортабельности
    double Seadle::get_comfortable() const {return comfortable;}


    		/// Сеттеры
    //цвета
    void Seadle::set_color_of(Color_4 _color_of) {color_of = _color_of;}
    //материала  
    void Seadle::set_material(Material_4 _material) {material = _material;}
    //комфортабельности
    void Seadle::set_comfortable(double _comfortable) {
    	if ((_comfortable < 0) || (_comfortable > 10))
			throw invalid_argument("Incorrect comfortable of Seadle (0 < wingspan < 10)");
		comfortable = _comfortable;	
    }

    /// Метод вычисленя удобства
    double Seadle::convenience_factor(){
    	double a,b;
    	if (material==Material_4::Silver)
 			a = 1.2;
 		if (material==Material_4::Poof)
 			a = 1.3;
 		if (material==Material_4::Cotton)
 			a = 1.4;
 		if (material==Material_4::Leather)
 			a = 1.5;
    	return comfortable*a;
    }

    /// Метод вывода кресла
    string Seadle::to_string () {
 		string m, c;
 		if (material==Material_4::Silver)
 			m = "Silver";
 		if (material==Material_4::Poof)
 			m = "Poof";
 		if (material==Material_4::Cotton)
 			m = "Cotton";
 		if (material==Material_4::Leather)
 			m = "Leather";

 		if (color_of==Color_4::Blue)
 			c = "Blue";
 		if (color_of==Color_4::Red)
 			c = "Red";
 		if (color_of==Color_4::Green)
 			c = "Green";
 		if (color_of==Color_4::Brown)
 			c = "Brown";

    	string s;
    	s = "Seadle made of " + m + " and colored in " + c 
    	+ ". Its comfortable is " + std::to_string(comfortable) 
    	+ " and convenience factor is " + std::to_string(convenience_factor());
    	return s;
    }




    								///Class Riding_Dragon

	/// Пустой конструктор
	Riding_Dragon::Riding_Dragon(){
	set_name("");
	set_element(Riding_Dragon::Element_4::Fire); //пусть дракон по базе плюёт огнем
	set_health(0);
	set_stamina(0);
	set_power(0);
	set_speed(0);
	set_wingspan(0);	}
	/// Конструктор с праметрами
	Riding_Dragon::Riding_Dragon(const string& name, Element_4 _element, 
	double health, double stamina, double power, double speed, double wingspan, Seadle* seadle = nullptr){
	set_name(name);
	set_element(_element);
	set_health(health);
	set_stamina(stamina);
	set_power(power);
	set_speed(speed);
	set_wingspan(wingspan);
	_seadle = seadle;		}


	/// Гетер для имени
    string Riding_Dragon::get_name() const {return name;}
    /// Гетер для елемента
    Riding_Dragon::Element_4 Riding_Dragon::get_element() const {return element;}	
    /// Гетер для здоровья
    double Riding_Dragon::get_health() const {return health;}
    /// Гетер для стамины		
    double Riding_Dragon::get_stamina() const {return stamina;}	
    /// Гетер для силы	
    double Riding_Dragon::get_power() const {return power;}
    /// Гетер для скорости	
    double Riding_Dragon::get_speed() const {return speed;}	
    /// Гетер для размаха крыльев				
    double Riding_Dragon::get_wingspan() const {return wingspan;}					


	/// Сетер для имени
	void Riding_Dragon::set_name(const string& _name){name = _name;}
	/// Сетер для елемента	
	void Riding_Dragon::set_element(Element_4 _element){element = _element;}
	/// Сетер для здоровья
	void Riding_Dragon::set_health(double _health){
		if ((_health < 0) || (_health > 50000))
			throw invalid_argument("Incorrect health (0 < health < 50000)");
		health = _health;	}		
	/// Сетер для стамины
	void Riding_Dragon::set_stamina(double _stamina){
		if ((_stamina < 0) || (_stamina > 5000))
			throw invalid_argument("Incorrect stamina (0 < stamina < 5000)");
		stamina = _stamina;
	}	
	/// Сетер для силы
	void Riding_Dragon::set_power(double _power){
		if ((_power < 0) || (_power > 50))
			throw invalid_argument("Incorrect power (0 < power < 50)");
		power = _power;		}
	/// Сетер для скорости
	void Riding_Dragon::set_speed(double _speed){
		if ((_speed < 0) || (_speed > 500))
			throw invalid_argument("Incorrect speed (0 < speed < 500)");
		speed = _speed;		}
	/// Сетер для размаха крыльев
	void Riding_Dragon::set_wingspan(double _wingspan){
		if ((_wingspan < 0) || (_wingspan > 50))
			throw invalid_argument("Incorrect wingspan (0 < wingspan < 50)");
		wingspan = _wingspan;	}
	

	/// Метод увеличения силы
    void Riding_Dragon::increase_stamina (double value){
    	if ((value < 0) || (value > 50))
			throw invalid_argument("Incorrect value (0 < value < 50)");
    	stamina = stamina+value;
    }
	/// Метод увеличения скорости
	void Riding_Dragon::increase_speed (double value){
		if ((value < 0) || (value > 50))
			throw invalid_argument("Incorrect value (0 < value < 50)");
		speed = speed+value;
	}


	///Метод атаки врага в ближнем бою
	void Riding_Dragon::dragon_melee_attack (Riding_Dragon& enemy){
	cout << "Dragon " << name << " melee attacks " << enemy.get_name() << " , dealing " << 5*power << " HP damage!"<<endl;
	enemy.set_health(enemy.get_health() - (5*power));
	}
	///Метод атаки врага в двльнем бою
	void Riding_Dragon::dragon_ranged_attack (Riding_Dragon& enemy){
	double dmr;
	if ((element == 0) || (element == 2))
		dmr = 2;
	else
		dmr = 1;	
	cout << "Dragon " << name << " ranged attacks " << enemy.get_name() << " , dealing " << 10*power*dmr << " HP damage!"<<endl;
	enemy.set_health(enemy.get_health() - (10*power*dmr));}


	///Метод проверки возможности полёта - зависит от размаха крыльев
	bool Riding_Dragon::flight_ability_check() {
		if (wingspan < 2.0)
			return false;
		else
			return true; }
	/// Метод рыка дракона
    void Riding_Dragon::roar() {
    	double xxx;
    	xxx = Rand(0,100);
    	cout << xxx;
    	if ((xxx > 0) && (xxx < 0.5)) 
    		cout << name << " made a long Rrr-roar~" << endl;
    	if ((xxx > 0.5) && (xxx < 0.7))
    		cout <<"Rrrrraaaaawwwwr!!! - screamed by" << name << endl;
    	else 
    		cout << name << ": 'Wuuurrrr...'" << endl;
    }
	/// Метод вывода дракона в строку
    string Riding_Dragon::to_string() {
		string s;
		s = "Name of the dragon is " + name + ". It has next stats:\n" + std::to_string(health) + " HP \n" 
		+ std::to_string(trunc(stamina)) + " points of stamina \n" + std::to_string(power) + " power of attack \n" 
		+ std::to_string(trunc(speed)) + " running speed \n" + std::to_string(wingspan) + " metrs of wingspan\n";
		return s;
    }


	///Функция для создания рандомного числа от min до max, нужно для многих штук
	double Riding_Dragon::Rand(int min, int max) { 
		int temp = (rand()) % (max-min) + min;
		return temp / 100.0; }




							// Наследование
							// Class Draconate

	/// Конструктор, пустой
    Draconate::Draconate() {set_speech(0);}
	/// Конструктор, с параметрами
    Draconate::Draconate(const string& name, Element_4 _element, double health, double stamina, double power, double speed, double wingspan,
    Seadle* seadle, double _speech): Riding_Dragon(name, _element, health, stamina, power, speed, wingspan, seadle)
    {
	set_speech(_speech);
	}


	/// Геттер для речи Драконейта
	double Draconate::get_speech() const {return speech;}
	/// Сеттер для речи Драконейта
	void Draconate::set_speech(double _speech){
		if ((_speech < 0) || (_speech > 50))
			throw invalid_argument("Incorrect speech (0 < health < 50)");
		speech = _speech;
	}	


    /// Метод говорения сообщения рыцарю
    string Draconate::speak_to_knight(const string& message){
    	if (speech > 25)
    		return "Draconate " + name + " said to Knights " + ": '" + message + "'\n";
    	else
    		return "Draconate " + name + " does not have enough communication skills\n";
    }
	///Метод атаки врага в ближнем бою
	void Draconate::dragon_melee_attack (Riding_Dragon& enemy){
	double damag;
	if (_seadle == nullptr)
		damag = 20*power;
	else
		damag = 20*power*_seadle->convenience_factor();
	cout << "Draconate " << name << " melee attacks " << enemy.get_name() << " , dealing " << damag << " HP damage!"<<endl;
	enemy.set_health(enemy.get_health() - (damag));
	}
	///Метод атаки врага в двльнем бою
	void Draconate::dragon_ranged_attack (Riding_Dragon& enemy){
	double dmr;					//Урон от элемента
	if ((element == 0) || (element == 2))
		dmr = 2;
	else
		dmr = 1,3;
	double damag;
	if (_seadle == nullptr)
		damag = 5*power*dmr;
	else
		damag = 5*power*dmr*_seadle->convenience_factor();		
	cout << "Draconate " << name << " ranged attacks " << enemy.get_name() << " , dealing " << damag << " HP damage!"<<endl;
	enemy.set_health(enemy.get_health() - (damag));
	}

	/// Метод вывода Драконейта в строку 
	string Draconate::to_string () {
		string s;
		s = ("Name of the draconate is " + name + ". It has next stats:\n" + std::to_string(health) + " HP \n" 
		+ std::to_string(trunc(stamina)) + " points of stamina \n" + std::to_string(power) + " power of attack \n" 
		+ std::to_string(trunc(speed)) + " running speed \n" + std::to_string(wingspan) + " metrs of wingspan \n" + std::to_string(speech) + " points of speech \n");
		return s;
	}  

	/// Метод рыка драконейта
    void Draconate::roar() {
    	srand((time(NULL)));
    	double xxx;
    	xxx = Rand(0,100);
    	if ((xxx > 0) && (xxx < 0.5)) 
    		cout << name << " made a long Rrr-roar~" << endl;
    	if ((xxx > 0.5) && (xxx < 0.7))
    		cout <<"'I can literaly speak...' - said sad Draconate " << name << endl;
    	else 
    		cout << name << ": 'Is everything alright?'" << endl;
    }




							// Наследование
							// Class Hydra

	/// Пустой конструктор
    Hydra::Hydra(){set_count_of_heads(1);}
	/// Конструктор с параметром
    Hydra::Hydra(const string& name, Element_4 _element, double health, double stamina, double power, double speed, double wingspan,
    Seadle* seadle, int count_of_heads_):
    Riding_Dragon(name, _element, health, stamina, power, speed, wingspan, seadle)
    {set_count_of_heads(count_of_heads_);}


	/// Геттер кол-ва голов
    int Hydra::get_count_of_heads() const {return count_of_heads;}
	/// Сеттер кол-ва голов
    void Hydra::set_count_of_heads(int count) {
    	if ((count < 0) || (count > 10))
			throw invalid_argument("Incorrect count_of_heads (0 < health < 10)");
		count_of_heads = count;
    }


	///Метод атаки врага в ближнем бою - defferent dmg
	void Hydra::dragon_melee_attack (Riding_Dragon& enemy){
	double damag;
	if (_seadle == nullptr)		//Урон от седла
		damag = 15*power;
	else
		damag = 15*power*_seadle->convenience_factor();	
	cout << "Hydra " << name << " melee attacks " << enemy.get_name() << " , dealing " << damag << " HP damage!"<<endl;
	enemy.set_health(enemy.get_health() - (damag));
	}
	///Метод атаки врага в двльнем бою - poison, burts
	void Hydra::dragon_ranged_attack (Riding_Dragon& enemy){
	double dmr; 			//Урон от елемента
	if ((element == 0) || (element == 2))
		dmr = 2;
	else
		dmr = 1.3;
	double poison_dmg; 		//Урон от яда
	poison_dmg = Rand(0,100) * 10;	
	double damag;
	if (_seadle == nullptr)  //Урон от седла
		damag = 20*power*dmr+poison_dmg*count_of_heads;
	else
		damag = 20*power*dmr+poison_dmg*count_of_heads*_seadle->convenience_factor();	
	cout << "Hydra " << name << " ranged attacks " << enemy.get_name() << " , dealing " << damag << " HP damage!"<<endl;
	enemy.set_health(enemy.get_health() - (damag)); }
	/// Метод переговора голов гидры
	void Hydra::conversation (){
		cout << "The hydra heads hiss noisily and growl at each other \nStamina decrease with 10 points" << endl;
		set_stamina(get_stamina()-10);
	}
	/// Метод рыка гидры
    void Hydra::roar() {
    	double xxx;
    	for (int i = 0; i<count_of_heads; i++){
    		xxx = Rand(0,100);
    		if ((xxx > 0) && (xxx < 0.5)) 
    			cout <<" Every head of Hydra "<< name <<" hisses" << endl;
    		if ((xxx > 0.5) && (xxx < 0.7))
    			cout <<"Rrrrraaaaawwwwr!!! - screamed by " << i+1 << "'s head" << name << endl;
    		else 
    			cout << i+1 << "'s head of " << name << " made a long Rrr-roar~" << endl;
    	}
    }    
	/// Метод вывода Гидры в строку
	string Hydra::to_string () {
		string s;
		s = ("Name of the hydra is " + name + ". It has next stats:\n" + std::to_string(health) + " HP \n" 
		+ std::to_string(trunc(stamina)) + " points of stamina \n" + std::to_string(power) + " power of attack \n" 
		+ std::to_string(trunc(speed)) + " running speed \n" + std::to_string(wingspan) + " metrs of wingspan \n" + std::to_string(count_of_heads) + " heads\n");
		return s;
	}




							// Наследование
							// Class Wyvern

	/// Пустой конструктор
    Wyvern::Wyvern(){set_aggressiveness(0); set_size(0.5);}
	/// Конструктор с параметром
    Wyvern::Wyvern(const string& name, Element_4 _element, double health, double stamina, double power, double speed, double wingspan,
    Seadle* seadle, double aggressiveness, double size):
    Riding_Dragon(name, _element, health, stamina, power, speed, wingspan, seadle)
    {set_aggressiveness(aggressiveness); set_size(size);}


	/// Геттер для агрессивности Виверны
	double Wyvern::get_aggressiveness() const {return aggressiveness;}
	/// Геттер для размера Виверны
	double Wyvern::get_size() const {return size;}
	/// Сеттер для речи Драконейта
	void Wyvern::set_aggressiveness(double _aggressiveness){
		if ((_aggressiveness < 0) || (_aggressiveness > 100))
			throw invalid_argument("Incorrect aggressiveness (0 < health < 100)");
		aggressiveness = _aggressiveness/100;
	}
	/// Сеттер для речи Драконейта
	void Wyvern::set_size(double _size){
		if ((_size < 0) || (_size > 100))
			throw invalid_argument("Incorrect size (0 < health < 100)");
		size = _size/100;
	}		


	/// Метод атаки врага в ближнем бою - defferent dmg
	void Wyvern::dragon_melee_attack (Riding_Dragon& enemy){
	double damag;
	if (_seadle == nullptr) //если есть седло - от него удобство
		damag = 10*power*size;
	else
		damag = 10*power*size*_seadle->convenience_factor(); 	
	cout << "Wyvern " << name << " melee attacks " << enemy.get_name() << " , dealing " << damag << " HP damage!"<<endl;
	enemy.set_health(enemy.get_health() - (damag));
	}
	/// Метод атаки врага в двльнем бою - poison, burts
	void Wyvern::dragon_ranged_attack (Riding_Dragon& enemy){
	double dmr, damag;					//урон от элемента
	if ((element == 0) || (element == 2))
		dmr = 2;
	else
		dmr = 1.3;
	if (_seadle == nullptr)  	//если есть седло - от него удобство
		damag = 10*power*dmr*size;
	else
		damag = 10*power*dmr*size*_seadle->convenience_factor();
	cout << "Wyvern " << name << " ranged attacks " << enemy.get_name() << " , dealing " << damag << " HP damage!"<<endl;
	enemy.set_health(enemy.get_health() - (damag)); }
	/// Метод рандомной атаки
	void Wyvern::random_attack (Riding_Dragon& enemy){
		if ((aggressiveness> 0) && (aggressiveness < 0.5))
			dragon_melee_attack(enemy);
		else
			dragon_ranged_attack(enemy);
	}
	/// Метод рыка виверна
    void Wyvern::roar() {
    	double xxx;
    	xxx = Rand(0,100);
    	if ((xxx > 0) && (xxx < 0.5)) 
    		cout <<"Murrr - grumbled "<< name << endl;
    	if ((xxx > 0.5) && (xxx < 0.7))
    		cout <<"Rrrrraaaaawwwwr!!! - screamed by " << name << endl;
    	else 
    		cout << name << " made a long Rrr-roar~" << endl;
    }  


	/// Метод вывода Виверны в строку
	string Wyvern::to_string () {
		string s;
		s = ("Name of the wyvern is " + name + ". It has next stats:\n" + std::to_string(health) + " HP \n" 
		+ std::to_string(trunc(stamina)) + " points of stamina \n" + std::to_string(power) + " power of attack \n" 
		+ std::to_string(trunc(speed)) + " running speed \n" + std::to_string(wingspan) + " metrs of wingspan \n" + std::to_string(aggressiveness) + " % "+" of aggressiveness\n" + std::to_string(size) + " size according to standard \n");
		return s;
	}
