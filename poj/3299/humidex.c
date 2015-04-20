#include <stdio.h>
#include <math.h>

#define EXP 2.718281828

void TD(double T, double D)
{
	double e = 6.11 * pow(EXP, (5417.7530 * ((1/273.16) - (1/(D+273.16))) ));    
	double h = (0.5555) * (e - 10.0);
	printf("T %.1lf D %.1lf H %.1lf\n", T, D, T+h);
}

void TH(double T, double H)
{
	double h = (H - T) / 0.5555 + 10; 
	double e = 1 / (1/273.16 - log(h/6.11) / 5417.7530) - 273.16;
	printf("T %.1lf D %.1lf H %.1lf\n", T, E, H);
}

void HD(double H, double D)
{
	double e = 6.11 * pow(EXP, (5417.7530 * ((1/273.16) - (1/(D+273.16))) ));    
	double h = (0.5555) * (e - 10.0);
	printf("T %.1lf D %.1lf H %.1lf\n", H-h, D, H);
}

int main()
{
	double x1, x2;
	char c1, c2;

	while (scanf("%c", &c1)) {
		if (c == 'E') break;	
		scanf("%lf", &x1);
		scanf("%c", &c2);
		scanf("%lf", &x2);

		switch (c1) {
			case 'T': 
				if (c2 == 'D') TD(x1, x2);
				else if (c2 == 'h') TH(x1, x2);
				break;
			case 'D': 
				if (c2 == 'T') TD(x2, x1);
				else if (c2 == 'h') HD(x2, x1);
				break;
			case 'H': 
				if (c2 == 'D') HD(x1, x2);
				else if (c2 == 'T') TH(x2, x1);
				break;
		}

		getchar();
	}

	return 0;
}
