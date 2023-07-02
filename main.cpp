#include <iostream>
#include <ctime>

void drawBoard(char *board);
void playerInput(char *board, char player);
void computerInput(char *board, char computer);
bool checkWinner(char *board);
bool canTakeInput(char *board);

int main(){
    
    char board[] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char player = 'X';
    char computer = 'O';
    bool playing = true;

    while (playing) {
        drawBoard(board);
        if (canTakeInput(board)) {
            playerInput(board, player);
        }
        if (checkWinner(board)) {
            drawBoard(board);
            playing = false;
            break;
        }
        if (canTakeInput(board)) {
            computerInput(board, computer);
        }
        if (checkWinner(board)) {
            drawBoard(board);
            playing = false;
            break;
        }
        if (!canTakeInput(board)) {
            std::cout << "\n\n\nIT'S A TIE" << std::endl;
            break;
        }
    }
    return 0;
}

void drawBoard(char *board){
    std::cout << "       |       |       " <<std::endl;
    std::cout << "  " << board[0] << "    |  " << board[1] << "    |  " << board[2] << "     " <<std::endl;
    std::cout << "_______|_______|_______" <<std::endl;
    std::cout << "       |       |       " <<std::endl;
    std::cout << "  " << board[3] << "    |  " << board[4] << "    |  " << board[5] << "     " <<std::endl;
    std::cout << "_______|_______|_______" <<std::endl;
    std::cout << "       |       |       " <<std::endl;
    std::cout << "  " << board[6] << "    |  " << board[7] << "    |  " << board[8] << "     " <<std::endl;
    std::cout << "       |       |       " <<std::endl;

}

void playerInput(char *board, char player){
    int number;
    do{
        std::cout << "Enter where in the board you want to mark(1-9)" << std::endl;
        std::cin >> number;
        number--;
        if ((number >= 0 && number < 9)&& (board[number] != ' ')) {
            std::cout << "Already Occupied" << std::endl;
        }
    }while((number < 0 || number > 9) || (board[number] != ' '));
    
    board[number] = player;
}

void computerInput(char *board, char computer){
    srand((int)time(0));
    int number;
    
    do{
        number = rand() % 9;
        if (board[number] == ' ') {
            board[number] = computer;
            break;
        }
    }while(board[number] != ' ');
}

bool checkWinner(char *board){
    if (board[0] == board[1] && board[1] == board[2] && board[0] != ' ') {
        board[0] == 'X' ? std::cout << "\nYOU WIN" << std::endl : std::cout << "\nYOU LOSS" << std::endl;
    }
    else if (board[3] == board[4] && board[4] == board[5] && board[3] != ' ') {
        board[3] == 'X' ? std::cout << "\nYOU WIN" << std::endl : std::cout << "\nYOU LOSS" << std::endl;
    }
    else if (board[6] == board[7] && board[7] == board[8] && board[6] != ' ') {
        board[6] == 'X' ? std::cout << "\nYOU WIN" << std::endl : std::cout << "\nYOU LOSS" << std::endl;
    }
    else if (board[0] == board[3] && board[3] == board[6] && board[0] != ' ') {
        board[0] == 'X' ? std::cout << "\nYOU WIN" << std::endl : std::cout << "\nYOU LOSS" << std::endl;
    }
    else if (board[1] == board[4] && board[4] == board[7] && board[1] != ' ') {
        board[1] == 'X' ? std::cout << "\nYOU WIN" << std::endl : std::cout << "\nYOU LOSS" << std::endl;
    }
    else if (board[2] == board[5] && board[7] == board[8] && board[2] != ' ') {
        board[2] == 'X' ? std::cout << "\nYOU WIN" << std::endl : std::cout << "\nYOU LOSS" << std::endl;
    }
    else if (board[0] == board[4] && board[4] == board[8] && board[0] != ' ') {
        board[0] == 'X' ? std::cout << "\nYOU WIN" << std::endl : std::cout << "\nYOU LOSS" << std::endl;
    }
    else if (board[2] == board[4] && board[4] == board[6] && board[2] != ' ') {
        board[2] == 'X' ? std::cout << "\nYOU WIN" << std::endl : std::cout << "\nYOU LOSS" << std::endl;
    }
    else {
        return false;
    }
    return true;
}

bool canTakeInput(char *board){
    int num = 0;
    for (int i = 0; i < 9; i++) {
        if (board[i] == ' ') {
            num++;
        }
    }
    if (num > 0) {
        return true;
    }
    else return false;
}
