#include <iostream>
#include <stack>
using namespace std;
int n, a[1010101], b[1010101];
int num[1010101];
stack<int> stk;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n;
	for (int i = 1; i <= n; i++){
	    cin >> a[i];
	    num[a[i]]++;
	}

	for (int i = n; i >= 1; i--)
	{
		while (!stk.empty() && num[stk.top()] <= num[a[i]])stk.pop();
		b[i] = stk.empty() ? -1 : stk.top();
		stk.push(a[i]);
	}
	for (int i = 1; i <= n; i++)cout << b[i] << " ";
}
