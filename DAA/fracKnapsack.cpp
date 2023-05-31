//1 . Write a program to implement Fractional knapsack using Greedy algorithm and also find the maximum profit 

#include <bits/stdc++.h>
using namespace std;

// Structure for an item which stores weight and corresponding value of Item
struct Item {
	int value, weight;
};

// Comparison function to sort Item according to val/weight ratio
bool cmp(struct Item a, struct Item b)
{
	double r1 = (double)a.value / (double)a.weight;
	double r2 = (double)b.value / (double)b.weight;
	return r1 > r2;
}

// Main greedy function to solve problem
double fractionalKnapsack(int W, struct Item arr[], int N)
{
	// Sorting Item on basis of ratio
	sort(arr, arr + N, cmp);

	double finalvalue = 0.0;

	// Looping through all items
	for (int i = 0; i < N; i++) {
		
		// If adding Item won't overflow,
		// add it completely
		if (arr[i].weight <= W) {
			W -= arr[i].weight;
			finalvalue += arr[i].value;
		}

		// If we can't add current Item,
		// add fractional part of it
		else {
			finalvalue += arr[i].value * ((double)W / (double)arr[i].weight);
			break;
		}
	}

	// Returning final value
	return finalvalue;
}

// Driver code
int main()
{
	int W ;
	cout<<"Enter weight of knapsack: "<<endl;
	cin>>W;
	int N ;
	cout<<"Enter number of items: "<<endl;
	cin>>N;

	Item arr[N];
	for(int i=0;i<N;i++)
	{
		cout<<"Enter value and weight of item "<<i+1<<endl;
		cin>>arr[i].value>>arr[i].weight;
	}
	cout << "Maximum value we can obtain = "<< fractionalKnapsack(W, arr, N);

	return 0;
}
