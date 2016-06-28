#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

/*
	4 7
	20 15 10 17
	높이의 최대값? -> 짤리는게 최소
*/
int N;
int M;
vector <int>tree;
int temp;
int i;
int mid;
int j;
int high;
int result;
int t_high;
int t_result;
int sign = 1;

int binary_search(int start, int end){
	mid = (start + end) / 2;
	if (tree[end] - tree[mid] > M){
		binary_search(mid + 1, end);
	}else{
		int c = 1;
		high = tree[mid + c - 1];
		while (true){
			t_high = 0;
			t_result = 0;
			if (high == tree[mid + c]){
				c++;
			}
			if (high == tree[mid - c + 1]){
				c--;
			}
			for (int j = mid + c; j <= end; j++){
				t_high = t_high + tree[j];
			}
			t_result = t_high - (high * (end - mid - c + 1));
			if (t_result == M){
				result = high;
				break;
			}else if (t_result < M){
				sign = 0;
				high--;
			}else if (t_result > M){
				if (sign == 0){
					result = high;
					break;
				}else{
					high++;
					sign = 1;
				}
			}
		}
		return 0;
	}
}

int main(){
	cin >> N >> M;
	for (i = 0; i < N; i++){
		cin >> temp;
		tree.push_back(temp);
	}
	sort(tree.begin(), tree.end());
	binary_search(0, N - 1);
	cout << result << endl;
}