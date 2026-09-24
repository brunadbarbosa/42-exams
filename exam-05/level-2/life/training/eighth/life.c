#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int ac, char **av) {
	if (ac != 4)
		return 1;
	int width = atoi(av[1]);
	int height = atoi(av[2]);
	int iter = atoi(av[3]);

	int board[height][width];
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			board[i][j] = 0;
	
	int x = 0, y = 0, pen = 0;
	char c;
	while(read(0, &c, 1)) {
		if (c == 'w' && y > 0)
			y--;
		else if (c == 's' && y < height - 1)
			y++;
		else if (c == 'a' && x > 0)
			x--;
		else if (c == 'd' && x < width - 1)
			x++;
		else if (c == 'x')
			pen = !pen;
		if (pen)
			board[y][x] = 1;
	}

	int n = 0;
	int new[height][width];
	for (int it = 0; it < iter; it++) {
		for (int x = 0; x < height; x++) {
			for (int y = 0; y < width; y++) {
				n = 0;
				for (int xx = -1; xx <= 1; xx++)
					for (int yy = -1; yy <= 1; yy++)
						if ((xx || yy) && x + xx >= 0 && x + xx < height && y + yy >= 0 && y + yy < width)
							n+= board[x + xx][y + yy];
				if (board[x][y] && (n == 2 || n == 3))
					new[x][y] = 1;
				else if (!board[x][y] && n == 3)
					new[x][y] = 1;
				else 
					new[x][y] = 0;
			}
		}
		for (int i = 0; i < height; i++)
			for (int j = 0; j < width; j++)
				board[i][j] = new[i][j];
	}
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++)
			putchar(board[i][j] ? 'O' : ' ');
		putchar('\n');
	}
}