#include <iostream>
#include <utility>

using std::string;

class Animal {
private:
    int height;
    int width;
    int weight;
    string voice;
    int speed;
public:
    Animal(int _height, int _width, int _weight, string _voice, int _speed) {
        height = _height;
        width = _width;
        weight = _weight;
        voice = std::move(_voice);
        speed = _speed;
    }

    void printData() const {
        printf("Animal(height=%d, width=%d, weight=%d, speed=%d)", height, width, weight, speed);
    }

    void move() const {
        printf("Moved for %d km", speed);
    }

    void say() const {
        printf(voice.c_str());
    }
};

class Bird: public Animal {
private:
    int flying_speed;
public:
    Bird(int _height, int _width, int _weight, int _speed, int _flying_speed)
            : Animal(_height, _weight, _weight, "twi twi", _speed) {
        flying_speed = _flying_speed;
    };

    void fly() const {
        printf("Bird flown %d km", flying_speed);
    }

};
class Human: public Animal {
private:
    string fullname;
    string work;
    int money;
public:
    Human(int _height, int _width, int _weight, int _movement_speed, string _fullname, string _work, int _money)
            : Animal(_height, _weight, _weight, "blah blah", _movement_speed) {
        fullname = std::move(_fullname);
        work = std::move(_work);
        money = _money;
    };

    void printStats() {
        printf("[%s] work at '%s' and have %d$", fullname.c_str(), work.c_str(), money);
    }

    void earnMoney(int amount) {
        money += amount;
    }
};

int main() {
    return 0;
}
