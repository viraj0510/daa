#include<iostream>

#include<algorithm>

using namespace std;

struct obj {

 double profit, weight, ratio;

};

bool cmp(obj a, obj b) {

 return a.ratio > b.ratio;

}

void input(obj arr[], int n) {

 for(int i = 0; i < n; i++) {

 cout << "Enter weight and profit: ";

 cin >> arr[i].weight >> arr[i].profit;

 arr[i].ratio = arr[i].profit / arr[i].weight;

 }

}

double knapsack(obj arr[], int n, int w) {

 sort(arr, arr + n, cmp);

 double totalProfit = 0.0;

 for(int i = 0; i < n && w > 0; i++) {

 if(arr[i].weight <= w) {

 totalProfit += arr[i].profit;

 w -= arr[i].weight;

 } else {

 totalProfit += arr[i].ratio * w;

 w = 0;

 }

 }

 return totalProfit;

}

int main() {

 int n, w;

 cout << "Enter number of objects and total capacity: ";

 cin >> n >> w;

 obj arr[n];

 input(arr, n);

 cout << "Maximum profit: " << knapsack(arr, n, w);

 return 0;

}
