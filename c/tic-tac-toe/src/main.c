#include <stdio.h>

void displayBoard(char board[3][3]){
printf("\n    %c | %c | %c \n   ---+---+---\n    %c | %c | %c \n   ---+---+---\n    %c | %c | %c \n", board[0][0], board[0][1], board[0][2], board[1][0], board[1][1], board[1][2], board[2][0], board[2][1], board[2][2]);
}

void winCheck(char board[3][3] ,char player, int *end){
if((board[0][0] == board[0][1] && board[0][0] == board[0][2] && board[0][0] != ' ') ||
(board[1][0] == board[1][1] && board[1][0] == board[1][2] && board[1][0] != ' ') ||
(board[2][0] == board[2][1] && board[2][0] == board[2][2] && board[2][0] != ' ') ||
(board[0][0] == board[1][0] && board[0][0] == board[2][0] && board[0][0] != ' ') ||
(board[0][1] == board[1][1] && board[0][1] == board[2][1] && board[0][1] != ' ') ||
(board[0][2] == board[1][2] && board[0][2] == board[2][2] && board[0][2] != ' ') ||
(board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != ' ') ||
(board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[0][2] != ' ')){
printf("%c wins\n\n",player);
*end = 1;
}
}

void drawCheck(char board[3][3], int *end){
if(board[0][0] != ' ' && board[0][1] != ' ' && board[0][2] != ' ' &&
board[1][0] != ' ' && board[1][1] != ' ' && board[1][2] != ' ' &&
board[2][0] != ' ' && board[2][1] != ' ' && board[2][2] != ' '){
printf("DRAW.\n\n");
*end = 1;
}
}

int main(){
char replay;
int position, row, col;

while(1){	

  int end=0;  
	char board[3][3] = {  
		{' ',' ',' '},  
		{' ',' ',' '},  
		{' ',' ',' '}  
		}, player = 'X';  
	  
	printf("     TIC TAC TOE.\n");  
	printf("    Player 1 -> X\n    Player 2 -> O");  
	  
	displayBoard(board);  
	  
	while(1){  
		  
		printf("Player %c turn\n\n",player);  
		printf("Choose a position.\n");  
		scanf("%d",&position);  
		  
		position--;  
		row = position/3;  
		col = position % 3;  
		  
		if(board[row][col] == ' '){  
			board[row][col] = player;  
		}  
		else{  
			printf("The column is already occuppied.\nPlease try another column\n\n");  
			continue;  
		}  
		  
		displayBoard(board);  
			  
		winCheck(board, player, &end);  
		  
		if(end){  
			break;  
		}  
		  
		drawCheck(board, &end);  
		  
		if(end){  
			break;  
		}  
			  
		if(player == 'X'){  
			player = 'O';  
		}else{  
			player = 'X';  
		}  
	}  
	printf("Do You want to play again? (y/n) :");  
	scanf(" %c",&replay);  
	  
	if(replay != 'y'){  
		printf("\n\n");  
		break;  
	}  
	  
}

}