#include <bits/stdc++.h> 
using namespace std;
void solve(stack<int>&inputStack, int count, int size) {
    //base case
    if(count == size/2) {
        inputStack.pop();
        return ;
    }
    
    int num = inputStack.top();
    inputStack.pop();
    
	//RECURSIVE CALL
    solve(inputStack, count+1, size);
    
    inputStack.push(num);
    
}
void deleteMiddle(stack<int>&inputStack, int N){
	
   // Write your code here
   	int count = 0;
    solve(inputStack, count, N);
   
}



