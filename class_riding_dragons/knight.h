///Eargosha|Иванов Егор, ИВТ-22
///.h file for class KNIGHT

#ifndef KNIGHT_H
#define KNIGHT_H


#include <string>
#include "riding_dragon.h"
using namespace std;

// Class Sword: name, sharpness, damage, type
class Sword {
public:
    // Тип: короткий, длинный, двуручный
    enum Type_4 {Short, Long, Two_handed};
    
protected:
                // Поля класса
    // название меча
    string name;
    // острота от 0 до 1
    double sharpness;
    // урон
    double damage;
    // тип меча, переменная перечисляемого выше
    Type_4 type;

public:
                // Методы класса
    // Пустой конструктор
    Sword();
    // Конструктор с праметрами
    Sword(const string _name, double _sharpness, double _damage, Type_4 _type);
    

                   //Геттеры
    // название
    string get_name() const;
    // острота
    double get_sharpness() const;
    // урон
    double get_damage() const;
    // тип меча
    Type_4 get_type() const;
    

                    //Сеттеры
    // название
    void set_name (const string _name);
    // острота
    void set_sharpness (double _sharpness);
    // урон
    void set_damage (double _damage);
    // тип меча
    void set_type (Type_4 _type);
    
                    //Методы
    // Дамаг от меча
    double total_damage();
    // выгон меча в строку
    string to_string();
};

///Тест для меча
void test_sword();

/// Class Knight: имя, уровень отношения с дрг, сила, меч
class Knight {
protected:
                         // Поля класса рыцарь:
    /// Имя
    string name;
    /// Уровень отношения с драконом
    double relations;
    /// Кол-во здоровья
    double power;
    /// Меч - композиция
    Sword weapon;

public:
                         /// Методы класса
    /// Пустой конструктор
    Knight();
    /// Конструктор с параметрами
    Knight(const string name, double relations, double power, const string _name, double _sharpness, double _damage, Sword::Type_4 _type);


            /// Геттеры
    /// для имени
    string get_name() const;
    /// для отношений
    double get_relations() const;
    /// для меча
    Sword get_weapon() const;
    /// для силы
    double get_power() const;


            /// Cеттеры
    /// для имени
    void set_name(const string& _name);
    /// для имени
    void set_relations(double _relation);   
    /// для меча
    void set_weapon(const string _name, double _sharpness, double _damage, Sword::Type_4 _type);
    /// для силы
    void set_power(double _power);
 

    /// Метод атаки врага в ближнем бою
    string dragon_attack (Riding_Dragon& enemy);
    /// Метод лечения своего дракона
    string heal_dragon (Riding_Dragon& friend_);

    /// Метод вывода рыцаря в строку
    string to_string();
};

    //Тест для рыцаря
    void test_knight();

#endif //KNIGHT_H