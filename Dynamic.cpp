#include<iostream>

using namespace std;

int knapsack(int weight[], int profit[], int n, int cap) {

 int arr[n+1][cap+1];

 // Initialize the table

 for(int i = 0; i <= n; i++) {

 for(int w = 0; w <= cap; w++) {

 if(i == 0 || w == 0)

 arr[i][w] = 0;

 else if(weight[i-1] <= w)

 arr[i][w] = max(profit[i-1] + arr[i-1][w - weight[i-1]], arr[i-1][w]);

 else

 arr[i][w] = arr[i-1][w];

 }

 }

 return arr[n][cap];

}

int main() {

 int n, cap;

 cout << "Enter number of objects and knapsack capacity: ";

 cin >> n >> cap;

 int weight[n], profit[n];

 cout << "Enter weights: ";

 for(int i = 0; i < n; i++) cin >> weight[i];

 cout << "Enter profits: ";

 for(int i = 0; i < n; i++) cin >> profit[i];

 int maxProfit = knapsack(weight, profit, n, cap);

 cout << "Maximum profit: " << maxProfit << endl;

 return 0;

}
