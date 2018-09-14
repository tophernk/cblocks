#include <stdio.h>
#define STARTING_X 6
#define STARTING_Y 0
#define FIELD_WIDTH 14
#define FIELD_HEIGHT 18

enum Direction {
	UP, RIGHT, DOWN, LEFT
};

struct Block
{
	enum Direction direction;
	struct Block *next;	
};

struct Piece
{
	struct Block starting_block;	
};

struct Piece generate_piece(void);
void print_playing_field(void);
void copy_playing_field(void);

char playing_field[FIELD_HEIGHT][FIELD_WIDTH];
char temporary_field[FIELD_HEIGHT][FIELD_WIDTH];
int current_piece_x;
int current_piece_y;

int main() {
	struct Piece piece = generate_piece();
	print_playing_field();
	return 0;
}

struct Piece generate_piece() {
	struct Block first_block;
	struct Block second_block;
	struct Block third_block; 
	struct Block fourth_block;

	first_block.next = &second_block;
	second_block.next = &third_block;
	third_block.next = &fourth_block;

	struct Piece piece;
	piece.starting_block = first_block;

	current_piece_x = STARTING_X;
	current_piece_y = STARTING_Y;

	return piece; 
}

void print_playing_field() {
	copy_playing_field();
	for(int y = 0; y < FIELD_HEIGHT; ++y) {
		for(int x = 0; x < FIELD_WIDTH; ++x) {
		printf("%d", temporary_field[y][x]);
		}
		printf("\n");
	}		
}

void copy_playing_field() {
	for(int y = 0; y < FIELD_HEIGHT; ++y) {
		for(int x = 0; x < FIELD_WIDTH; ++x) {
			temporary_field[y][x] = playing_field[y][x];
		}	
	}
}
