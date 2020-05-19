# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define MAX 20

typedef struct c{
	// pike, heart, tile, clover
	char format[MAX];
	// 1~13
	int rank;
	struct c *next;
}CARD;

void CARD_ADD(CARD *card, char *format, int rank){
	// create new card
	CARD *newCard = (CARD*)malloc(sizeof(CARD));
	strcpy(newCard->format, format);
	newCard->rank = rank;
	newCard->next = NULL;
	// if no card
	if(card->next == NULL){
		card->next = newCard;
		return;
	}
	// insert to the side
	CARD *pre = card;
	while(card->next && card->rank<rank){
		pre = card;
		card = card->next;
	}
	// rank not the same
	if( card->rank != rank ){
		newCard->next = card;
		pre->next = newCard;
	}
	// have the same rank
	else{
		char templet[4][MAX]={"clover", "tile", "heart", "pike"};
		int newCardRank;
		int curCardRank;
		// get both card format rank
		for(int i=0;i<4;i++){
			if( strcmp(templet[i], card->format) == 0)
				curCardRank = i;
			if( strcmp(templet[i], format) == 0)
				newCardRank = i;
		}
		// new's format < cur
		if(curCardRank > newCardRank){
			newCard->next = card;
			pre->next = newCard;			
		}
		// new's format > cur
		else{
			newCard->next = card->next;
			card->next = newCard;
		}
	}
}

void CARD_PRINT(CARD *card){
	printf("\t[ Format ]\t[ Rank ]\n");
	while(card->next){
		printf("\t[ %s ]\t[ %d ]\n", card->next->format, card->next->rank);
		card = card->next;
	}
}

int main(void){
	CARD *card = (CARD*)malloc(sizeof(CARD));
	card->next = NULL;
	// loop (5)
	for(int i=0;i<5;i++){
		// input card infor
		int rank;
		char format[MAX];
		printf("請輸入第%d張牌資料(花色:pike, heart, tile, clover; 點數: 1~13\n花色 點數: ", i+1);
		scanf("%s %d", format, &rank);
		fflush(stdin);
		// add card to link (sorted)
		CARD_ADD(card, format, rank);
	}
	// print all 5 card
	CARD_PRINT(card);
	return 0;
}