///Eargosha|Иванов Егор, ИВТ-22
///.h file for class Riding_Dragon

#ifndef RIDING_DRAGON_H
#define RIDING_DRAGON_H

#include <string>
using namespace std;

/// Class Seadle: material, color, comfortable. Агрегация к классу Riding_Dragon
class Seadle {
public:
/// Материал, может быть - Серебро, Пух, Хлопок, Кожа
enum Material_4 {Silver, Poof, Cotton, Leather};
/// Цвет, может быть - синим, красным, зеленым, коричневым
enum Color_4 {Blue, Red, Green, Brown};
protected:
                    // Поля класса седло:
    /// Материал седла из перечисления выше
    Material_4 material;
    /// Цвет седла из перечисления выше
    Color_4 color_of;
    /// Значение комфортабельности от 0 до 1
    double comfortable; 

public:
                        /// Методы класса
    /// Пустой конструктор
    Seadle();
    /// Конструктор с параметрами
    Seadle(double comfortable, Color_4 _color_of, Material_4 material_);


            /// Геттеры
    //цвета
    Color_4 get_color_of() const;  
    //материала     
    Material_4 get_material() const;
    //комфортабельности
    double get_comfortable() const;


             /// Сеттеры
    //цвета
    void set_color_of(Color_4 _color_of);
    //материала  
    void set_material(Material_4 _material);
    //комфортабельности
    void set_comfortable(double _comfortable);


    /// Метод вычисления фактора удобности
    double convenience_factor();
    /// Метод вывода седла в строку
    string to_string();

};

///Тетсты класса Seadle
void test_seadle ();

///Class Riding_Dragon: имя, элемент, здоровье, выносливость, сила, скорость, размах крыльев, седло(класс Seadle)
class Riding_Dragon {
public:
    /// Элемент, может быть - огня, воды, земли, воздуха
    enum Element_4 {Fire, Water, Earth, Air};

protected:
                         // Поля класса драконов:
    /// Имя
    string name;
    /// Элемент дракона из перечисления выше
    Element_4 element;
    /// Кол-во здоровья
    double health;
    /// Кол-во выносливости
    double stamina;
    /// Кол-во силы
    double power;
    /// Кол-во скорости
    double speed;
    /// Размах крыльев
    double wingspan;
    /// Седло - агрегация
    Seadle *_seadle;

public:
                         /// Методы класса
    /// Пустой конструктор
    Riding_Dragon();
    /// Конструктор с параметрами
    Riding_Dragon(const string& name, Element_4 _element, double health, double stamina, double power, double speed, double wingspan, Seadle* seadle);


    /// Гетер для имени
    string get_name() const;
    /// Гетер для елемента
    Element_4 get_element() const;
    /// Гетер для здоровья
    double get_health() const;
    /// Гетер для стамины
    double get_stamina() const;
    /// Гетер для силы
    double get_power() const;
    /// Гетер для скорости
    double get_speed() const;
    /// Гетер для размаха крыльев
    double get_wingspan() const;


    /// Сетер для имени
    void set_name(const string& _name);
    /// Сетер для елемента
    void set_element(typeof element _element);
    /// Сетер для здоровья
    void set_health(double _health);
    /// Сетер для стамины
    void set_stamina(double _stamina);
    /// Сетер для силы
    void set_power(double _power);
    /// Сетер для скорости
    void set_speed(double _speed);
    /// Сетер для размаха крыльев
    void set_wingspan(double _wingspan);


    /// Метод увеличения силы
    void increase_stamina (double value);
    /// Метод увеличения скорости
    void increase_speed (double value);


    /// Метод атаки врага в ближнем бою
    virtual string dragon_melee_attack (Riding_Dragon& enemy) = 0;
    /// Метод атаки врага в дальнем бою
    virtual string dragon_ranged_attack (Riding_Dragon& enemy) = 0;


    /// Метод проверки дракона на летабельность
    bool flight_ability_check();
    /// Метод рыка дракона
    virtual string roar() = 0;
    /// Метод вывода дракона в строку
    virtual string to_string() = 0;


    ///Функция для создания рандомного числа от min до max, нужно для многих штук
    double Rand(int min, int max);

};


/// С помощью наследования получаем следующие классы, перенимая все поля и методы из Riding_Dragon

/// Class Draconate: речь, наследование от Riding_Dragons
class Draconate: public Riding_Dragon{
private:
                    // Поля класса
    /// Речь
    double speech;

public:
                    // Методы класса
    /// Пустой конструктор
    Draconate();
    /// Конструктор с параметрами
    Draconate(const string& name, Element_4 _element, double health, double stamina, double power, double speed, double wingspan, Seadle* seadle, double _speech);


    /// Гетер для речи
    double get_speech() const;
    /// Сетер для речи
    void set_speech(double _speech);


    /// Метод говорения сообщения рыцарю
    string speak_to_knight(const string& message);
    /// Метод атаки врага в ближнем бою
    string dragon_melee_attack (Riding_Dragon& enemy) override;
    /// Метод атаки врага в дальнем бою
    string dragon_ranged_attack (Riding_Dragon& enemy) override;
    /// Метод вывода Драконейта в строку
    string to_string() override;
    /// Метод рыка драконейта
    string roar() override;
}; 

///Тестирование класса Draconate
    void test_draconate();



/// Class Hydra: кол-во голов гидры, наследование от Riding_Dragons
class Hydra: public Riding_Dragon{
private:
    /// Кол-во голов гидры
    int count_of_heads;

public:
    /// Пустой конструктор
    Hydra();
    /// Конструктор с параметром
    Hydra(const string& name, Element_4 _element, double health, double stamina, double power, double speed, double wingspan, Seadle* seadle, int count_of_heads_);


    /// Геттер кол-ва голов
    int get_count_of_heads() const;
    /// Сеттер кол-ва голов
    void set_count_of_heads(int count);    


    /// Метод атаки врага в ближнем бою
    string dragon_melee_attack (Riding_Dragon& enemy) override;
    /// Метод атаки врага в дальнем бою
    string dragon_ranged_attack (Riding_Dragon& enemy) override;
    /// Метод переговоров между головами Гидры
    string conversation ();
    /// Метод рыка Гидры
    string roar() override;


    string to_string() override;
}; 

///Тестирование класса Hydra
    void test_hydra();



/// Получаем наследованием класс Виверны, наследование от Riding_Dragons
class Wyvern: public Riding_Dragon{
private:
    /// % агрессивности
    double aggressiveness;
    /// % размера от обычного дракона
    double size;

public:
    /// Пустой конструктор
    Wyvern();
    /// Конструктор с параметром
    Wyvern(const string& name, Element_4 _element, double health, double stamina, double power, double speed, double wingspan, Seadle* seadle, double aggressiveness, double size);


    /// Гетер для агрессивности
    double get_aggressiveness() const;
    /// Гетер для размера
    double get_size() const;
    /// Сетер для агрессивности
    void set_aggressiveness(double _aggressiveness);
    /// Сетер для раземера
    void set_size(double _size);


    /// Метод атаки врага в ближнем бою
    string dragon_melee_attack (Riding_Dragon& enemy) override;
    /// Метод атаки врага в дальнем бою
    string dragon_ranged_attack (Riding_Dragon& enemy) override;
    /// Метод рандомной атаки, зависит от агрессивности
    string random_attack (Riding_Dragon& enemy);
    /// Метод рыка Гидры
    string roar() override;


    string to_string() override;
}; 

///Тестирование класса Wyvern
void test_wyvern();


#endif //RIDING_DRAGON_H