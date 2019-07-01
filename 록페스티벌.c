#include <stdio.h>

int main() {
	int n; 
	scanf("%d", &n);
	while (n) {
		int test, date;
		int dp[1001] = { 0, };
		int dat[1001];
		scanf("%d %d", &test, &date);
		for (int i = 0; i < test; i++) scanf("%d", &dat[i]);
		float least = 1000000.0;
		for (int i = 0; i <= test-date; i++) {
			for (int j = 0; i+j < test; j++) {
				if (least >( dp[i]+dat[i+j]) / (float)(j+1) &&j>=date-1) {
					least = (dp[i] + dat[i + j] )/ (float)(j+1);
				}
				else if (least <= (dp[i] + dat[i + j]) / (float)(j + 1) && j >= date - 1) {
					j = test; continue;
				}
				dp[i] += dat[i + j];
			}
		}
		printf("%.12f", least);
		n--;
	}
	return 0;
}
