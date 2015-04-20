#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char month_name[12][10] = {"January", "February", "March", "April", "May", "June", 
	"July", "August", "September", "October", "November" , "December"};

int is_leap_year(int year)
{
	return (year % 4 == 0) && (year % 100) || (year % 400 == 0);
}

int get_month(char *month) 
{
	switch(month[0]) {
		case 'J':
			if (month[1] == 'a') return 1;
			else if (month[2] == 'n') return 6;
			else return 7;
		case 'F':
			return 2;
		case 'M':
			if (month[2] == 'y') return 5;
			return 3;
		case 'A':
			if (month[1] == 'p') return 4;
			return 8;
		case 'S':
			return 9;
		case 'O':
			return 10;
		case 'N':
			return 11;
		case 'D':
			return 12;
	}
}

int main()
{
	int i, n, j, len;
	char start[32], end[32];

	scanf("%d", &n);
	for (i = 0; i < n; ++i) {
		int count = 0;
		char s_month[10], e_month[10];
		int s_year, s_day, e_year, e_day;
		scanf("%s", s_month);
		scanf("%d,", &s_day);
		scanf("%d", &s_year);
		scanf("%s", e_month);
		scanf("%d,", &e_day);
		scanf("%d", &e_year);
		for (j = s_year+1; j <= e_year-1; j++) {
			count += is_leap_year(j);
		}
		if (is_leap_year(s_year)) {
			int m = get_month(s_month);
			if (m == 1 || m == 2 && s_day <= 29) count++;
		}
		if (is_leap_year(e_year)) {
			int m = get_month(e_month);
			if (m >= 3 || m == 2 && e_day == 29) count++;
		}
		if (s_year == e_year && count) count--;
		printf("Case #%d: %d\n", i+1, count);
	}

	return 0;
}

