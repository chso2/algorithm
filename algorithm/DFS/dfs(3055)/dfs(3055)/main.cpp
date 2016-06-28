#include<iostream>
#include<algorithm>
using namespace std;

int R;
int C;
char map[51][51];
char water_check[51][51];
int check[51][51];
int i;
int j;
int val;
int start_x, start_y;
int cnt = 0;
int result = 1000000;

int water(){
	for (i = 0; i < R; i++){
		for (j = 0; j < C; j++){
			if (map[i][j] == '*'){
				check[i][j] = 1;
				if (i != 0){
					if (map[i - 1][j] == '.'){
						water_check[i - 1][j] = '*';
						check[i - 1][j] = 1;
					}
				}
				if (i != R - 1){
					if (map[i + 1][j] == '.'){
						water_check[i + 1][j] = '*';
						check[i + 1][j] = 1;
					}
				}
				if (j != 0){
					if (map[i][j - 1] == '.'){
						water_check[i][j - 1] = '*';
						check[i][j - 1] = 1;
					}
				}
				if (j != C - 1){
					if (map[i][j + 1] == '.'){
						water_check[i][j + 1] = '*';
						check[i][j + 1] = 1;
					}
				}
			}else if (map[i][j] == 'X'){
				check[i][j] = 1;
			}
		}
	}
	return 0;
}
int water_fill(){
	for (i = 0; i < R; i++){
		for (j = 0; j < C; j++){
			map[i][j] = water_check[i][j];
		}
	}
	return 0;
}
int dfs(int x, int y){
	if (map[x][y] == 'D'){
		if (result > cnt){
			result = cnt;
		}
		cnt--;
		return 0;
	}else{
		cnt++;
		if (check[x][y] == 1){
			cnt--;
			return 0;
		}else{
			//cout << "x = " << x << "y = " << y << endl;
			//cout << cnt << endl;
			check[x][y] = 1;
			water();
			water_fill();
			if (x > 0){
				dfs(x - 1, y);
			}
			if (x < R - 1){
				dfs(x + 1, y);
			}
			if (y > 0){
				dfs(x, y - 1);
			}
			if (y < C - 1){
				dfs(x, y + 1);
			}
		}
		cnt--;
	}
	return 0;
}

int main(){
	cin >> R >> C;
	for (i = 0; i < R; i++){
		for (j = 0; j < C; j++){
			cin >> map[i][j];
			check[i][j] = 0;
			water_check[i][j] = map[i][j];
			if (map[i][j] == 'S'){
				start_x = i;
				start_y = j;
			}
		}
	}
	dfs(start_x, start_y);
	if (result == 1000000){
		cout << "KAKTUS" << endl;
	}else{
		cout << result << endl;
	}
}
