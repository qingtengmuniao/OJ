#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FACTOR 1000000
#define _DEBUG 0 
#define myabs(a) ((a) > 0 ? (a) : (-a))

typedef struct Arm{
	int arms[6];
	struct Arm *next;
}Arm;
Arm* hash_table[FACTOR];
int have_same = 0;

int is_same(Arm *a, Arm *b)
{

	int i, j;
	for (i = 0; i < 6; ++i) {
		if (a->arms[i] == b->arms[0]) {
			// clockwise 
			for (j = 0; j < 6; ++j) {
				if (a->arms[(i+j)%6] != b->arms[j])
					break;
			}
			if (j == 6) return 1;

			// anticlockwise
			for (j = 6; j > 0; --j) {
#if _DEBUG
				printf("a=%d;b=%d\n", (i+6-j)%6, j%6);
#endif
				if (a->arms[(i+6-j)%6] != b->arms[j%6])
					break;
			}
			if (j == 0) return 1;
		}
	}
	return 0;
}

void read_data(int n)
{
	int i, j;

	// init
	memset(hash_table, 0, sizeof(hash_table));
	have_same = 0;
	
	// read data 
	for (i = 0; i < n; ++i) {
		Arm *temp = (Arm *)malloc(sizeof(Arm));
		int sum = 0;
		for (j = 0; j < 6; ++j) {
			scanf("%d", &temp->arms[j]);
			if (!have_same) {
				sum += temp->arms[j];
				sum %= FACTOR;
			}
		}

		// just read data while we find the same;
		if (have_same) continue;

		temp->next = NULL;
		int loc = sum % FACTOR;
		Arm *start = hash_table[loc], *previous;
		if (start == NULL) 
			hash_table[loc] = temp;
		else {
			while (start != NULL) {
				if (is_same(temp, start)) {
					have_same = 1;	
					break;
				}
				previous = start;
				start = start->next;
			}
			if (!have_same)
				previous->next = temp;
		}
	}

	// release the space
	for (i = 0; i < FACTOR; ++i)
		if (hash_table[i] != NULL) 
			free(hash_table[i]);
}

int main()
{
	int n;
	while (scanf("%d", &n) != EOF) {
		read_data(n);
		if (have_same) {
			printf("Twin snowflakes found.\n");
		} else {
			printf("No two snowflakes are alike.\n");
		}
	}
	return 0;
}
