#include<stdio.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<stdlib.h>
#include<memory.h>
#pragma warning(disable:4996)
using namespace std;

#define MAX 101
#define INF 999999
#define CAPACITY 100001

int cache[CAPACITY][MAX];
int w[MAX];
int v[MAX];

int len;

int dp(int K, int pos) {

	if (pos == len + 1)
		return 0;

	if (cache[K][pos] != -1)
		return cache[K][pos];

	int tmp = dp(K, pos + 1);

	if (K >= w[pos]) {
		tmp = max(tmp, dp(K - w[pos], pos + 1) + v[pos]);
	}

	cache[K][pos] = tmp;
	return tmp;
}

int main() {
	int k;
	scanf("%d %d", &len, &k);

	memset(cache, -1, sizeof(cache));
	

	for (int i = 1; i <= len; i++) {
		int wei, val;
		scanf("%d %d", &wei, &val);
		w[i] = wei;
		v[i] = val;
	}

	printf("%d\n",dp(k,0));
	return 0;
}