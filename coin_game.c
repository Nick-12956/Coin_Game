// Coin Game

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int fun() {
	srand(time(NULL));
	return ((rand() % 4)+1);
}
int main() {
	int c = 100,b,l,o,win=0,loss=0,r;             // Initial coins is 100
	while (c > 0) {
		r = fun();
		printf("Current Coins : %d\nEnter how much do you want to BET ('0' to leave) : ",c);
		do{
			scanf("%d",&b);
			if(b > c) printf("---< Bet can't be more than Coins >---\nEnter BET : ");
		}while(b > c);
		if (b == 0) break;
		do{
			printf("Enter Choice ( 1 - 4 ) : ");
			scanf("%d",&o);
			if((o < 1)||(o > 4)) printf("---< Choice must be between (1 - 4) >---\n");
		}while ((o < 1)||(o > 4));
		if (r == o) {
			printf("---< Correct Number is picked, Won BET (4X) >---");
			c = c + (b * 4);
			win++;
		}
		else {
			printf("---< Wrong Number is picked ( Your Pick = %d || Random pick = %d ), You lost the BET >---",o,r);
			c -= b;;
			loss++;
		}
		printf("\n-------------------------------------\n");
	}
	if(c < 0) c = 0;
	printf("-------------------------------------------\n\nCurrent Coins : %d\nWins          : %d\nLosses        : %d\n---< Game is Completed >---",c,win,loss);
	return 0;
}
/*
c = current coins
b = bet coins
l = leave game
r = random value (1 - 4)
o = option from (1 - 4)
*/