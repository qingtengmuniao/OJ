#include <stdio.h>
#include <stdlib.h>

unsigned short now_status = 0;
unsigned short oprand[16] = {0}; 
int times = 33;

void get_input()
{
	int i = 0;
	char c;

	for (i = 15; i >= 0; --i){
		if ((c = getchar()) == '\n')
			c = getchar();
		
		if (c == 'w')
			now_status |= (1<<i);
		//printf("%c", c);
	}
	//printf("%u\n", now_status);
}

int judge_success()
{
	return !(now_status ^ 0x0000) || !(now_status ^ 0xffff);
}

void init_oprand()
{
	int i = 0;
	for (i = 0; i < 16; ++i){
		oprand[i] |= (1 << (15-i));	
		if (i % 4 != 0) oprand[i] |= (1 << (16-i));
		if (i % 4 != 3) oprand[i] |= (1 << (14-i));
		if (i > 3) oprand[i] |= (1 << (19-i));
		if (i < 12) oprand[i] |= (1 << (11-i));
		//printf ("%u\n", oprand[i]);
	}
}

/**
 * when steps
 */
void dfs(int now_grid, int steps)
{
	if (judge_success()){
		times = times > steps ? steps : times;
		return;
	}

	if (now_grid >= 16) {
		return;
	}

	dfs(now_grid+1, steps);
	now_status ^= oprand[now_grid];
	dfs(now_grid+1, steps+1);
	now_status ^= oprand[now_grid];
}

int main()
{
	get_input();	
	init_oprand();
	dfs(0, 0);
	if (times < 33) {
		printf("%d\n", times);
	} else {
		printf("Impossible\n");
	}
	//printf("%d\n", steps);
	//printf("%u\n", judge_success());
	return 0;
}

