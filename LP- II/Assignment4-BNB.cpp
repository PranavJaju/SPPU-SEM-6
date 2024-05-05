//Implement a solution for a Constraint Satisfaction Problem using Branch 
//and Bound

#include <bits/stdc++.h>
using namespace std;
int n,cnt;
void printsol(vector<vector<int>>& boards){
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			cout<<((boards[i][j]==1)?'Q':'.')<<" ";
		}
		cout<<endl;
	}
}
bool issafe(int row,int col,vector<int>&rows,vector<int>&left,vector<int>&right){
	cnt++;
	if(rows[row]==1 || left[row+col] ==1 || right[col-row+n-1] == 1){
		return false;
	}
	return true;
}
void solve(vector<vector<int>>& boards,int col,vector<int>&rows,vector<int>&left,vector<int>&right,int & count){
	if(col==n){
		count++;
		cout<<"\nSolution :"<<count<<endl;
		printsol(boards);
		return;
	}
	for(int i = 0;i<n;i++){
		if(issafe(i,col,rows,left,right)){
			rows[i] = 1;
			left[i+col] = 1;
			right[col-i+n-1] = 1;
			boards[i][col] = 1;
			
			solve(boards,col+1,rows,left,right,count);
			
			rows[i] = 0;
			left[i+col] = 0;
			right[col-i+n-1] = 0;
			boards[i][col] = 0;
		}
	}
}

int main(){
	cnt = 0;
	cout<<"Enter the value of n: ";
	cin>>n;
	int count = 0;
	vector<vector<int>>board(n,vector<int>(n,0));
	vector<int>rows(n,0);
	vector<int>left_diagonals(2*n-1,0);
	vector<int>right_diagonals(2*n-1,0);
	solve(board,0,rows,left_diagonals,right_diagonals,count);
	cout<<"\nTotal number of solutions: "<<count<<endl;
	
}
