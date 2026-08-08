#include "bsq.h"

int min3(int a, int b, int c) {
	int m = a;
	if (b < m)
		m = b;
	if (c < m)
		m = c;
	return (m);
}

void freemap(BSQ *b) {
	if (!b->map)
		return ;
	for (int i = 0; i < b->lines; i++)
		free(b->map[i]);
	free(b->map);
}

int parse(BSQ *b, FILE *f) {
	char nl;
	int ret = fscanf(f, "%d%c%c%c%c", &b->lines, &b->empt, &b->obst, &b->full, &nl);

	if (ret != 5 || nl != '\n' || b->lines <= 0)
		return (b->lines = 0, 0);
	if (b->empt == b->full || b->empt == b->obst || b->full == b->obst)
		return b->lines = 0, 0;
	
	b->map = calloc(b->lines, sizeof(char *));
	int n = 0;

	while (n < b->lines) {
		char *line = NULL;
		size_t cap = 0;
		ssize_t len = getline(&line, &cap, f);

		if (len <= 0)
			return free(line), 0;
		if (line[len - 1] == '\n')
			line[--len] = '\0';
		b->map[n++] = line;
		if (n == 1)
			b->width = len;
		if (len != b->width)
			return 0;
		for (int j = 0; j < b->width; j++)
			if (line[j] != b->obst && line[j] != b->empt)
				return (0);
	}
	return 1;
}

void solve(BSQ *b) {
	int **board = calloc(b->lines, sizeof(int *));
	int max = 0, bi = 0, bj = 0;

	for (int i = 0; i < b->lines; i++) {
		board[i] = calloc(b->width, sizeof(int));
		for(int j = 0; j < b->width; j++) {
			if (b->map[i][j] == b->obst)
				board[i][j] = 0;
			else if (i == 0 || j == 0)	
				board[i][j] = 1;
			else
				board[i][j] = 1 + min3(board[i - 1][j], board[i][j - 1], board[i - 1][j - 1]);
			if (board[i][j] > max) {
				max = board[i][j];
				bi = i;
				bj = j;
			}
		}
	}
	for (int i = bi - max + 1; i <= bi; i++)
		for (int j = bj - max + 1; j < bj; j++)
			b->map[i][j] = b->full;
	for (int i = 0; i < b->lines; i++)
		free(board[i]);
	free(board);
}

void run(FILE *f) {
	BSQ b = {0};

	if (parse(&b, f)) {
		solve (&b);
		for (int i = 0; i < b.lines; i++)
			printf("%s\n", b.map[i]);
	}
	else
		fprintf(stderr, "map error\n");
	freemap(&b);
}

int main(int ac, char **av) {
	if (ac < 2)
		return (run(stdin), 0);
	for (int i = 0; i < ac; i++) {
		FILE *f = fopen(av[i], "r");
		if (!f)
			fprintf(stderr, "maperror\n");
		else {
			run(f);
			fclose(f);
		}
		if (i != ac - 1)
			printf("\n");
	} 
	return (0);
}
