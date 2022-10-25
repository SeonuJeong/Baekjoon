#include<stdio.h>
#pragma warning (disable:4996)
int MAX = -999999;
int arr[100001];
int size;
int cache[100001];

int Sum(int pos);


int main() {

	for (int i = 0; i < 100001; i++)
		cache[i] = 0;

	scanf("%d", &size);

	for (int i = 1; i <= size; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = size; i > 0; i--) {
		int tmp = Sum(i);
		if (tmp > MAX) {
			MAX = tmp;
		}
	}

	printf("%d\n", MAX);

	return 0;

}

int Sum(int pos) {

	if (pos == size) {
		cache[pos] = arr[pos];
		return arr[pos];
	}
	
	if (true) {
		if (cache[pos+1] >= 0) {
			cache[pos] = arr[pos] + cache[pos + 1];
			return arr[pos] + cache[pos + 1];
		}
		else {
			cache[pos] = arr[pos];
			return arr[pos];
		}
	}
	else
	{
		printf("ERROR\n");

	}

}