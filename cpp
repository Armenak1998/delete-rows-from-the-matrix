#include<iostream>
#include<string>
using namespace std;
bool stugel(int a, int b) {
	if (a == 0 || b == 0)
		return false;
	while (true) {
		if (a == 1 || b == 1)
			return false;
		if (a == b)
			return true;
		if (a > b)
			a -= b;
		else
		    b -= a;
	}
}
int main() {
	
	int n;
	int m;
	cout << "input quantity array- ";
	cin >> n;
	cout << "input size of array- ";
	cin >> m;
	int **arry = new int*[n];
	register int j;
	for (j= 0; j < n; j++) {
		arry[j] = new int[m];
	}
	for (int i = 0; i < n ; i++) {
		for (j = 0; j < m; j++)
			cin >> arry[i][j];
	}
	int *a = new int[n];
	int l = 0;
	for ( int i = 0; i < n; i++) {
		for (j = 2; j < m; j++) {
			if (stugel(arry[i][j], i) || stugel(arry[i][j], j))
				goto aa;
		}
		a[l] = i;
		++l;
	aa: extern int klj;
	}
	for (int i = l - 1; i >= 0; i--) {
		delete[]arry[a[i]];
		for (j = a[i]; j < n-1; j++) {
			arry[j] = arry[j + 1];
		}
		--n;
	}
	cout << "\n";
	for (int i = 0; i < n; i++) {
		for (j = 0; j < m; j++)
			cout<<arry[i][j]<<" ";
		cout << '\n';
	}
	delete[]a;
	for (j = 0; j < n; j++)
		delete[]arry[j];
	delete[]arry;
	system("pause");
	return 0;
}
