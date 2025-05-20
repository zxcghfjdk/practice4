#include <iostream>
#include <vector>
#include <limits>
#include <windows.h>


using namespace std;

class TicTacToe {
private:
    vector<char> board;
    char currentPlayer;
public:
    TicTacToe() : board(9, ' '), currentPlayer('X') {
        for (int i = 0; i < 9; i++) {
            board[i] = '1' + i;
        }
    }
    
    void printBoard() {
        cout << "\n";
        for (int i = 0; i < 9; i++) {
            cout << board[i] << " ";
            if ((i + 1) % 3 == 0)
                cout << "\n";
        }
    }
    
    bool checkWin() {
        int wins[8][3] = {
            {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, // строки
            {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, // столбцы
            {0, 4, 8}, {2, 4, 6}             // диагонали
        };
        for (int i = 0; i < 8; i++) {
            if (board[wins[i][0]] == currentPlayer &&
                board[wins[i][1]] == currentPlayer &&
                board[wins[i][2]] == currentPlayer) {
                return true;
            }
        }
        return false;
    }
    
    void play() {
        int moves = 0;
        while (moves < 9) {
            printBoard();
			string input;
            int choice;
            cout << "Игрок " << currentPlayer << ", выберите ячейку (1-9): ";
            cin >> input;
            
            if (input.length() != 1 || input[0] < '1' || input[0] > '9') {
				cout << "Неверный ввод! Введите число от 1 до 9.\n";
				continue;
			} else {
				choice = input[0] - '0';
				cout << "Вы выбрали ячейку номер " << choice << "\n";
			}
            
            if (board[choice - 1] == 'X' || board[choice - 1] == 'O') {
                cout << "Эта ячейка уже занята. Попробуйте снова.\n";
                continue;
            }
            
            board[choice - 1] = currentPlayer;
            moves++;
            
            if (checkWin()) {
                printBoard();
                cout << "\nПоздравляем, игрок " << currentPlayer << " выиграл!\n";
                return;
            }
            
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
        printBoard();
        cout << "\nНичья!\n";
    }
};

int main() {
	SetConsoleOutputCP(CP_UTF8);
    char playAgain;
    do {
        TicTacToe game;
        game.play();
        cout << "\nХотите сыграть ещё раз? (Y/N): ";
        cin >> playAgain;
    } while (playAgain == 'Y' || playAgain == 'y');
    return 0;
}
