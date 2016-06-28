#include <iostream>
#include<algorithm>
using namespace std;

long long a[100001];

bool check(long long time, int &n, long long &m) {
	// 해당 시간 대에 처리할수 있는 사람의 수가 m 보다 작은지 비교
	int count = 0;
	for (int i = 1; i <= n; i++) {
		count = count + (time / a[i]);
	}
	return count < m;
}
int main() {
	int n;
	long long m;
	scanf_s("%d %lld", &n, &m);

	long long mx_time = 0;
	long long mn_time = 1000000000;
	for (int i = 1; i <= n; i++) {
		scanf_s("%lld", &a[i]);
		mx_time = max(mx_time, a[i]);
		mn_time = min(mn_time, a[i]);
	}
	long long l = (mn_time * m) / n, r = (mx_time * m) / n;
	long long ans = r;
	cout << l << endl;
	cout << r << endl;
	while (l <= r) {
		long long mid = (l + r) / 2;
		if (check(mid, n, m)) {
			l = mid + 1;
		}
		else {
			r = mid - 1;
			ans = min(ans, mid);
		}
	}
	printf_s("%lld\n", ans);
	return 0;
}
/*
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N;
int M;
vector <int>T;
int i;
int temp;


int main(){
	cin >> N >> M;
	for (i = 0; i < N; i++){
		cin >> temp;
		T.push_back(temp);
	}

}
*/