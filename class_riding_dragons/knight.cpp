///Eargosha|Иванов Егор, ИВТ-22
///.cpp file for class KNIGHT

#include <exception>
#include <stdexcept>
#include <iostream>
#include <assert.h>
#include <cmath>
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

	/// Тест для меча
	void test_sword(){
		Sword test("Mech", 50.0, 50.0, Sword::Type_4::Long);

		assert(test.get_name() == "Mech");
		assert(test.get_sharpness() == 0.5);
		assert(test.get_damage() == 50.0);
		assert(test.get_type() == Sword::Type_4::Long);

		double temp44 = round(test.total_damage()*100)/100;
		assert(temp44 == 20);
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
	string Knight::dragon_attack (Riding_Dragon& enemy){
		enemy.set_health(enemy.get_health() - (power*weapon.total_damage()));
		return "Knight " + name + " attacks " + enemy.get_name() +", dealing " + std::to_string(power*weapon.total_damage()) + " HP damage!\n";
	}
    /// Метод лечения своего дракона
    string Knight::heal_dragon (Riding_Dragon& friend_){
   		friend_.set_health(friend_.get_health()+(150*relations));
   		return "Knight " + name + " heals " + friend_.get_name() +", restoring " +std::to_string(150*relations) + " HP points!\n";
    }

    /// Метод вывода рыцаря в строку
    string Knight::to_string(){
    	string s;
    	s = "Yeah, it is a knight, his name is " + name + ", it have " + std::to_string(relations) + " %" + " of relations and "+ std::to_string(power) + " points of power\n";
    	s = s + weapon.to_string();
    	return s;
    }

	/// Тест для рыцаря
    void test_knight(){
    	Knight test("Hooly", 50.0, 25.0, "Rud", 50.0, 50.0, Sword::Type_4::Short);

    	assert(test.get_name()=="Hooly");
    	assert(test.get_relations()==0.5);
    	assert(test.get_power()==25.0);

		Seadle *saed = new Seadle(7.0, Seadle::Color_4::Green, Seadle::Material_4::Leather);
		Hydra bolna_bl("Biba", Draconate::Element_4::Fire, 2000.0, 400.0, 10.0, 100.0, 10.0, saed, 2);

    	test.dragon_attack(bolna_bl);   //тестируем урон, хил
    	assert(bolna_bl.get_health()==1687.5);

    	test.heal_dragon(bolna_bl);
    	assert(bolna_bl.get_health()==1762.5);
    }