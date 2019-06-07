#include "stdafx.h"
#pragma warning(disable:4996)

#include <cstdio>
#include <algorithm>

const int maxn = 260000;

char str1[maxn], str2[maxn];

int main()
{
	int h, w, len;
	int x, y;
	scanf("%d%d%d",&h, &w, &len);
	scanf("%d%d",&x, &y);
	scanf("%s", str1 + 1);
	scanf("%s", str2 + 1);

	int l1, r1, u1, d1;
	int l2, r2, u2, d2;
	l1 = r1 = u1 = d1 = l2 = r2 = u2 = d2 = 0;
	for (int i = 1;i <= len;i++){
		if (str1[i] == 'L') l1++;
		else if (str1[i] == 'R') r1++;
		else if (str1[i] == 'U') u1++;
		else d1++;
		if (y + r1 - l2 > w || y - l1 + r2 <= 0 || x + d1 - u2 > h || x - u1 + d2 <= 0){
			printf("NO\n");
			return 0;
		} 
		if (str2[i] == 'L') {
			if (y + r1 - l2 > 1) l2++;
		}
		else if (str2[i] == 'R') {
			if (y - l1 + r2 < w) r2++;
		}
		else if (str2[i] == 'U') {
			if (x + d1 - u2 > 1) u2++;
		}
		else {
			if (x - u1 + d2 < h) d2++;
		}
	}
	printf("YES\n");
    return 0;
}

