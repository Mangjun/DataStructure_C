#include <stdio.h>

/* color */
#define WHITE 0
#define BLACK 1
#define YELLOW 2

/* variable */
#define WIDTH 10
#define HEIGHT 10

char read_pixel(int x, int y);
void write_pixel(int x, int y, int color);
void flood_fill(int x, int y);
void print();

int screen[WIDTH][HEIGHT];

int main() {
	for (int i = 0; i < WIDTH; i++) {
		for (int ii = 0; ii < HEIGHT; ii++) {
			write_pixel(i, ii, YELLOW);
		}
	}

	printf("Before\n");
	print();
	printf("\n");

	write_pixel(2, 3, WHITE);
	write_pixel(2, 4, WHITE);
	write_pixel(2, 5, WHITE);
	write_pixel(2, 6, WHITE);
	write_pixel(3, 4, WHITE);
	write_pixel(3, 5, WHITE);
	write_pixel(3, 6, WHITE);
	write_pixel(4, 4, WHITE);
	write_pixel(4, 5, WHITE);
	write_pixel(4, 6, WHITE);
	write_pixel(5, 4, WHITE);
	write_pixel(5, 5, WHITE);
	write_pixel(5, 6, WHITE);
	write_pixel(5, 7, WHITE);
	write_pixel(6, 4, WHITE);
	write_pixel(7, 4, WHITE);
	write_pixel(8, 4, WHITE);

	printf("Ing..\n");
	print();
	printf("\n");

	flood_fill(5, 4);

	printf("After\n");
	print();

	return 0;
}

char read_pixel(int x, int y) {
	return screen[x][y];
}

void write_pixel(int x, int y, int color) {
	screen[x][y] = color;
}

void flood_fill(int x, int y) {
	if (read_pixel(x, y) == WHITE) {
		write_pixel(x, y, BLACK);
		flood_fill(x + 1, y);
		flood_fill(x - 1, y);
		flood_fill(x, y + 1);
		flood_fill(x, y - 1);
	}
}

void print() {
	for (int i = 0; i < WIDTH; i++) {
		for (int ii = 0; ii < HEIGHT; ii++) {
			printf(" %d", screen[i][ii]);
		}
		printf("\n");
	}
}
