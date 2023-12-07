///Eargosha|Иванов Егор, ИВТ-22
///.cpp file for class KNIGHT

#include <exception>
#include <stdexcept>
#include <iostream>
#include "knight.h"

using namespace std;




    								///Class Sword

    // Пустой конструктор
    Sword::Sword(){
    	set_name(" ");
    	set_sharpness(0);
    	set_damage(0);
    	set_type(Type_4::Short);
//базовый параметр - короткий
    }
    // Конструктор с праметрами
    Sword::Sword(const string _name, double _sharpness, double _damage, Type_4 _type){
    	set_name(_name);
    	set_sharpness(_sharpness);
    	set_damage(_damage);
    	set_type(_type);
    }


                   //Геттеры
    // название
    string Sword::get_name() const{return name;}
    // острота
    double Sword::get_sharpness() const{return sharpness;}
    // урон
    double Sword::get_damage() const{return damage;}
    // тип меча
    Sword::Type_4 Sword::get_type() const
    {return type;}


                    //Сеттеры
    // название
    void Sword::set_name (const string _name){name = _name;}
    // острота
    void Sword::set_sharpness (double _sharpness){
    if ((_sharpness < 0) || (_sharpness > 100))
		throw invalid_argument("Incorrect sharpness of Sword (0 < wingspan < 100)");
	sharpness = _sharpness/100;	
    }
    // урон
    void Sword::set_damage (double _damage){
    if ((_damage < 0) || (_damage > 100))
		throw invalid_argument("Incorrect damage of Sword (0 < wingspan < 100)");
	damage = _damage;	
    }
    // тип меча
    void Sword::set_type (Type_4 _type){type = _type;}

	// Дамаг от меча
	double Sword::total_damage(){
    double dmr;
    if (type==Type_4::Two_handed)
        dmr = 1;
    if (type==Type_4::Short)
        dmr = 0.5;
    if (type==Type_4::Long)
        dmr = 0.8;
    return damage*sharpness*dmr;
	}

	// выгон меча в строку
	string Sword::to_string(){
    string s, t;
    if (type==Type_4::Two_handed)
        t = "Two_handed";
    if (type==Type_4::Short)
        t = "Short";
    if (type==Type_4::Long)
        t = "Long";
    s = "This knight has "+t+" sword with name '"+name+"', sharpness = "+std::to_string(sharpness)+", total damage = "+std::to_string(total_damage())+"\n";
	return s;
	}




    								///Class Knight

	/// Конструктор
	Knight::Knight () {
	set_name("");
	set_power(0);
	set_relations(0);
	set_weapon(" ", 0, 0, Sword::Type_4::Short);
	}

	/// Конструктор
	Knight::Knight (const string name, double relations, double power, const string _name, double _sharpness, double _damage, Sword::Type_4 _type) {
	set_name(name);
	set_power(power);
	set_relations(relations);
	set_weapon(_name, _sharpness, _damage, _type);
	}


	/// Гетеры
	/// для имени
    string Knight::get_name() const {return name;}
    /// для силы
    double Knight::get_power() const {return power;}	
    /// для отношений
    double Knight::get_relations() const {return relations;}
    /// для меча
    Sword Knight::get_weapon() const {return weapon;};	


	/// Сетеры
	/// для имени
	void Knight::set_name(const string& _name){name = _name;}
	/// для силы
    void Knight::set_power(double _power){
		if ((_power < 0) || (_power > 50))
			throw invalid_argument("Incorrect power (0 < power < 50)");
		power = _power;
	}	
	/// для отношений
	void Knight::set_relations(double _relations) {
		if ((_relations < 0) || (_relations > 100))
			throw invalid_argument("Incorrect % relations (0 < power < 100)");
		relations = _relations/100;
	}	
	/// для меча
	void Knight::set_weapon(const string _name, double _sharpness, double _damage, Sword::Type_4 _type){
        Sword temp_weapon(_name, _sharpness, _damage, _type);
        weapon = temp_weapon;
	}


	/// Метод атаки дракона
	void Knight::dragon_attack (Riding_Dragon& enemy){
		cout << "Knight " << name << " attacks " << enemy.get_name() << ", dealing " << power*weapon.total_damage() << " HP damage!"<<endl;
		enemy.set_health(enemy.get_health() - (power*weapon.total_damage()));
	}
    /// Метод лечения своего дракона
    void Knight::heal_dragon (Riding_Dragon& friend_){
    	cout << "Knight " << name << " heals " << friend_.get_name() << ", restoring " << 150*relations << " HP points!"<<endl;
   		friend_.set_health(friend_.get_health()+(150*relations));
    }

    /// Метод вывода рыцаря в строку
    string Knight::to_string(){
    	string s;
    	s = "Yeah, it is a knight, his name is " + name + ", it have " + std::to_string(relations) + " %" + " of relations and "+ std::to_string(power) + " points of power\n";
    	s = s + weapon.to_string();
    	return s;
    }