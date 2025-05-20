#include <windows.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

class Character {
public:
    string name;
    int health;
    int attack;
    
    Character(string n, int h, int a) : name(n), health(h), attack(a) {}
    
    void attackTarget(Character &target) {
        int damage = rand() % attack + 1;
        cout << name << " атакует " << target.name << " и наносит " << damage << " урона.\n";
        target.health -= damage;
    }
};

int getChoice() {
    string input;
    while (true) {
        cout << "Выберите действие (1 - Атаковать, 2 - Пропустить ход): ";
        cin >> input;
        if (input == "1" || input == "2") {
            return input[0] - '0';
        } else {
            cout << "Неверный ввод. Попробуйте снова.\n";
        }
    }
}

void playBattle() {
    Character hero("Герой", 30, 10);
    Character monster("Монстр", 25, 8);
    
    while (hero.health > 0 && monster.health > 0) {
        cout << "\n" << hero.name << " (Здоровье: " << hero.health << ")\n";
        cout << monster.name << " (Здоровье: " << monster.health << ")\n";
        
        int choice = getChoice();
        if (choice == 1) {
            hero.attackTarget(monster);
        } else {
            cout << hero.name << " пропускает ход.\n";
        }
        
        if (monster.health > 0) {
            monster.attackTarget(hero);
        }
    }
    
    if (hero.health > 0)
        cout << "\nГерой победил!\n";
    else
        cout << "\nМонстр победил!\n";
}

int main() {
	SetConsoleOutputCP(CP_UTF8);
    srand(time(0));
    string playAgain;
    do {
        playBattle();
        cout << "\nХотите сыграть ещё раз? (Y/N): ";
        cin >> playAgain;
    } while (playAgain == "Y" || playAgain == "y");
    
    return 0;
}

   
