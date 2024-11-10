#include <iostream>
#include <cmath> 

using namespace std;
int board[20], count;
void print(int n) {
 cout << "\n\nSolution " << ++count << ":\n\n";
 for (int i = 1; i <= n; ++i)
 cout << "\t" << i;
 for (int i = 1; i <= n; ++i) {
 cout << "\n\n" << i; 
 for (int j = 1; j <= n; ++j) {
 if (board[i] == j) {
 cout << "\tQ"; 
 } else {
 cout << "\t-"; 
 }
 }
 }
}

bool place(int row, int column) {
 for (int i = 1; i < row; ++i) {
 if (board[i] == column || abs(board[i] - column) == abs(i - row))
 return false; 
 }
 return true; 
}
void queen(int row, int n) {
 for (int column = 1; column <= n; ++column) {
 if (place(row, column)) {
 board[row] = column; 
 if (row == n) {
 print(n); 
 } else {
 queen(row + 1, n); 
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
