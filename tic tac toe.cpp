#include <iostream>
using namespace std;

char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};

void printBoard() {
    cout << "  0 1 2" << endl;
    for (int i = 0; i < 3; i++) {
        cout << i << " ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << "|";
        }
        cout << endl;
        if (i < 2) cout << "  -----" << endl;
    }
}

bool isMoveValid(int row, int col) {
    return row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ';
}

bool checkWin(char c) {
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == c && board[i][1] == c && board[i][2] == c) ||
            (board[0][i] == c && board[1][i] == c && board[2][i] == c)) {
            return true;
        }
    }
    if ((board[0][0] == c && board[1][1] == c && board[2][2] == c) ||
        (board[0][2] == c && board[1][1] == c && board[2][0] == c)) {
        return true;
    }
    return false;
}

bool isBoardFull() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ')
                return false;
        }
    }
    return true;
}

void computer_move(int arr[],int n){
for(int i=0;i<3;i++){
for(int j=0;j<3;j++){
if(board[i][j]==' '){

board[i][j]='O';
if(checkWin('O')){cout<<"hey!  ";arr[0]=i;arr[1]=j;board[i][j]=' ';return;}
else{board[i][j]=' ';
}
}
}
}

for(int i=0;i<3;i++){
for(int j=0;j<3;j++){
if(board[i][j]==' '){
board[i][j]='X';
if(checkWin('X')){arr[0]=i;arr[1]=j;board[i][j]=' ';return;}
else{board[i][j]=' ';}
}
}
}

if(board[1][1]==' '){
board[1][1]='O';
arr[0]=1;arr[1]=1;return;}

else if(board[0][0]==' '){board[0][0]='O';
arr[0]=0;arr[1]=0;return;}
else if(board[0][2]==' '){board[0][2]='O';
arr[0]=0;arr[1]=2;return;}

else if(board[2][0]==' '){board[2][0]='O';
arr[0]=2;arr[1]=0;return;}

else if(board[2][2]==' '){board[2][2]='O';
arr[0]=2;arr[1]=2;return;}

else if(board[0][1]==' '){board[0][1]='O';
arr[0]=0;arr[1]=1;return;}

else if(board[1][0]==' '){board[1][0]='O';
arr[0]=1;arr[1]=0;return;}

else if(board[1][2]==' '){board[1][2]='O';
arr[0]=1;arr[1]=2;return;}

else if(board[2][1]==' '){board[2][1]='O';
arr[0]=2;arr[1]=1;return;}

else{
return;}

}



int main() {
    char currentPlayer = 'X';
int k;

cout<<"Enter 1 if you want to play against computer else 0:";
cin>>k;

if(k==0){
    while (true) {
        printBoard();

        int row, col;
        cout << "Player " << currentPlayer << ", enter row (0-2) and column (0-2): ";
        cin >> row >> col;

        if (isMoveValid(row, col)) {
            board[row][col] = currentPlayer;

            if (checkWin(currentPlayer)) {
                printBoard();
                cout << "Player " << currentPlayer << " wins!" << endl;
                break;
            }

            if (isBoardFull()) {
                printBoard();
                cout << "It's a draw!" << endl;
                break;
            }

            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        } else {
            cout << "Invalid move. Try again." << endl;
        }
    }
}
else{
int l;
cout<<"Chose first player: 0 for computer , 1 for you:";
cin>>l;
if(l==1){
while (true) {
        printBoard();
        int row, col;
        cout << "Player " << currentPlayer << ", enter row (0-2) and column (0-2): ";
        cin >> row >> col;

        if (isMoveValid(row, col)) {
            board[row][col] = currentPlayer;

            if (checkWin(currentPlayer)) {
                printBoard();
                cout << "Player " << currentPlayer << " wins!" << endl;
                break;
            }

            if (isBoardFull()) {
                printBoard();
                cout << "It's a draw!" << endl;
                break;
            }


        }

int arr[2];
computer_move(arr,2);
printBoard();
row=arr[0];
col=arr[1];
cout<<"Player O(computer)'s move "<<row<<","<<col<<endl;
 if (isMoveValid(row, col)) {
            board[row][col] = 'O';

            if (checkWin('O')) {
                printBoard();
                cout << "Computer wins!" << endl;
                break;
            }

            if (isBoardFull()) {
                printBoard();
                cout << "It's a draw!" << endl;
                break;
            }

        }
}
}
else{
while(1){
int arr[2];
int row,col;
computer_move(arr,2);
printBoard();
row=arr[0];
col=arr[1];
cout<<"Player O(computer)'s move "<<row<<","<<col<<endl;

 if (isMoveValid(row, col)) {
            board[row][col] = 'O';

            if (checkWin('O')) {
                printBoard();
                cout << "Computer wins!" << endl;
                break;
            }

            if (isBoardFull()) {
                printBoard();
                cout << "It's a draw!" << endl;
                break;
            }


}
    printBoard();

        cout << "Player " << currentPlayer << ", enter row (0-2) and column (0-2): ";
        cin >> row >> col;

        if (isMoveValid(row, col)) {
            board[row][col] = currentPlayer;

            if (checkWin(currentPlayer)) {
                printBoard();
                cout << "Player " << currentPlayer << " wins!" << endl;
                break;
            }

            if (isBoardFull()) {
                printBoard();
                cout << "It's a draw!" << endl;
                break;
            }
        }

}
}}
return 0;
}
