/*
 * 1. Продемонстрировать различные уровни инкапсуляции данных (указать комментарием):
a. Отсутствие инкапсуляции (public свойства)
b. Инкапсуляция с помощью set/get
c. Инкапсуляция с помощью специализированных протоколов/методов
d. Инкапсуляция за счёт абстракций

p.s. использовать механизмы исключений, если нарушается инвариант или не соблюдаются пост/пред-условия

2. Продемонстрировать различные варианты инкапсуляции поведения
a. За счёт позднего связывания
b. Замена поведения (тут тоже используется позднее связывание)
c. Расширения поведения (тут тоже используется позднее связывание)
 */
#include <iostream>


class Basketball{
private:
    unsigned short Points, Assist;
    std::string Player_name;

public:
    bool Match; //Отсутствие инкапсуляции (public свойства)
    Basketball(bool match){
        Match = match;
    }

    void setPoints(unsigned short points){ //Инкапсуляция с помощью set/get
        Points = points;
    }

    std::string getPlayerName() const{
        return Player_name;
    };

    virtual void HeGetAssist(unsigned short assist){ //За счёт позднего связывания
        Assist = assist;
        std::cout << Assist << std::endl;
    }

    void Assists(){ //расширение поведения
        std::cout << getPlayerName() << " gave away assists: ";
        HeGetAssist(Assist);
    }

    virtual void PlayerInfo(){
        std::cout << getPlayerName();
    }

};

class Player_Card: public Basketball{ //Инкапсуляция за счёт абстракций
private:
    unsigned short Age, Weight, Height, Points, Assists;
public:
    Player_Card(unsigned short age, unsigned short weight, unsigned short height,
            unsigned short points, unsigned short assists) : Basketball(Match){
        Age = age;
        Weight = weight;
        Height = height;
        Points = points;
        Assists = assists;
    }

    unsigned short getAge() const {
        return Age;
    }

    unsigned short getWeight() const {
        return Weight;
    }

    unsigned short getHeight() const {
        return Height;
    }

    void PlusPoint(){ // Не уверен, что я понял правильно, но подразумевалась "Инкапсуляция с помощью специализированных протоколов/методов"
        Points++;
    }

    void PlusAssist(){
        Assists++;
    }

    void PlayerInfo() override{ //Замена поведения
        std::cout << "Возраст:" << getAge() << " " << "Вес:" << getWeight() << " " << "Рост:" << getHeight() << " " <<
        "Очки:" << Points << " " << "Передачи:" << Assists << std::endl;
    }
};

//Добавил функцию, ожидающую на вход абстракцию
void getInfo(Basketball &Player_name) {
    Player_name.PlayerInfo();
}

int main(){
    Player_Card Matvey(18, 60, 180, 10, 12);
    Player_Card Slava(20, 70, 180, 15, 3);

    std::cout << "Матвей и слава проигрывают 4 очка, у них есть время лишь на одну атаку, что же они будут делать?\n" << std::endl;
    std::cout << "Давайте посмотрим на их статистику сейчас" << std::endl;
    std::cout << "Матвей: ";
    getInfo(Matvey);
    std::cout << "Слава: ";
    getInfo(Slava);

    std::cout << std::endl << "И вот они атакуют, Слава отдает изумительную передачу из за спины прямо на Матвея, который находится за трехочковой линией" <<std::endl;

    Slava.PlusAssist();
    Matvey.PlusPoint();
    Matvey.PlusPoint();
    Matvey.PlusPoint();

    std::cout << "И Матвей попадает великолепный трехочковый, который так им был нужен. Слава зарабатывает отличную результативную передачу" << std::endl;

    std::cout << "Какую защиту мы наблюдаем от этих двух игроков! Мяч опять у них, последний шанс на победу" << std::endl;
    std::cout << "Посмотрите! Матвей отдает передачу через всю площадку, где ее уже ожидает Слава. ОН ЗАБИВАЕТ! Казалось бы, на таймере осталась лишь пара секунд, но эти двое смогли выйграть игру!\n" << std::endl;

    Matvey.PlusAssist();
    Slava.PlusPoint();
    Slava.PlusPoint();

    std::cout << "Сейчас мы можем наблюдать карточки обоих игроков со статистикой за сегодняшний матч" << std::endl;
    std::cout << "Матвей: ";
    Matvey.PlayerInfo();
    std::cout << "Слава: ";
    Slava.PlayerInfo();

    return 0;
}