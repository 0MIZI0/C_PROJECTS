#include<stdio.h>

typedef struct {
    char name[10];
    int info[5];
}Card;

void printCardInfo(char* cardOwner, Card* card) {
	printf("%s - %s\n", cardOwner, card->name);	// (char*)card[0]
	printf("|통솔|무력|지력|정치|매력|\n");
	for (int i = 0; i < 5; i++)
		printf("| %d ", card->info[i]);	// *((int*)card[1] + i)
	printf("|\n\n");
}

void swapCard(Card** c1, Card** c2){
    Card* temp = *c1;
    *c1 = *c2;
    *c2 = temp;
}
void cardBattle(void** myCard, void** comCard);

int main() {
	Card A = { "유비", { 75, 73, 74, 78, 99 } };
	Card B = { "조조", { 96, 72, 91, 94, 96 } };

    Card* myCard = &A;
    Card* comCard = &B;

	printCardInfo("플레이어 카드", myCard);
	printCardInfo("컴퓨터 카드", comCard);

	// cardBattle

	printf("\n****** Card trading ******\n\n");
	swapCard(&myCard, &comCard);

	printCardInfo("플레이어 카드", myCard);
	printCardInfo("컴퓨터 카드", comCard);

	// cardBattle

	return 0;
}

// cardBattle( ) 함수 정의