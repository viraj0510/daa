#include <iostream>

#include <cmath> // for abs

using namespace std;

int board[20], count;

void print(int n) {

 cout << "\n\nSolution " << ++count << ":\n\n";

 // Print the column numbers

 for (int i = 1; i <= n; ++i)

 cout << "\t" << i;

 // Print the chessboard with queens and empty spaces

 for (int i = 1; i <= n; ++i) {

 cout << "\n\n" << i; // Print the row number

 for (int j = 1; j <= n; ++j) {

 if (board[i] == j) {

 cout << "\tQ"; // Print 'Q' for a queen

 } else {

 cout << "\t-"; // Print '-' for empty space

 }

 }

 }

}

bool place(int row, int column) {

 for (int i = 1; i < row; ++i) {

 if (board[i] == column || abs(board[i] - column) == abs(i - row))

 return false; // There is a conflict

 }

 return true; // No conflict

}

void queen(int row, int n) {

 for (int column = 1; column <= n; ++column) {

 if (place(row, column)) {

 board[row] = column; // Place queen

 if (row == n) {

 print(n); // Print the solution

 } else {

 queen(row + 1, n); // Place the next queen

 }

 }

 }

}

int main() {

 int n;

 cout << " - N Queens Problem Using Backtracking -";

 cout << "\n\nEnter number of Queens: ";

 cin >> n;

 queen(1, n);

 return 0;

}
