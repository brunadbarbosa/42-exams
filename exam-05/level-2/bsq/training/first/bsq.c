#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int lines, width;
	char empt, obs, full;
	char** map;
} BSQ;

int min(int a, int b, int c) {
	int m = a;
	if (b < m)
		m = b;
	if (c < m)
		m = c;
	return (m);
}

void	solve_bsq(BSQ *b) {
	int **board = malloc(b->lines * sizeof(int*));
	int max = 0, mx = 0, my = 0;
	for (int i = 0; i < b->lines; i++) {
		board[i] = calloc(b->width, sizeof(int));
		for (int j = 0; j < b->width; j++) {
			if (b->map[i][j] == b->obs)
				board[i][j] = 0;
			else if (i == 0 || j == 0)
				board[i][j] = 1;
			else
				board[i][j] = min(board[i-1][j], board[i][j-1], board[i-1][j-1]) + 1;
			if(board[i][j] > max) {
				max = board[i][j];
				mx = j;
				my = i;
			}
		}
	}
	for (int i = my - max + 1; i <= my; i++)
		for (int j = mx - max + 1; j <= mx; j++)
			b->map[i][j] = b->full;
	for (int i = 0; i < b->lines; i++)
		free(board[i]);
	free(board);
}

int parse(BSQ *b, FILE *f) {
	int ret = fscanf(f, "%d%c%c%c\n", &b->lines, &b->empt, &b->obs, &b->full);
	if (ret != 4 || b->lines <= 0)
		return 0;
	if (b->empt == b->obs || b->empt == b->full || b->obs == b->full)
		return 0;
	b->map = malloc(b->lines *sizeof(char*));
	for (int i = 0;i < b->lines; i++) {
		char * line = NULL;
		size_t cap = 0;
		ssize_t	len = getline(&line, &cap, f);
		if (len <= 0) {
			free(line);
			b->lines = i;
			free_map(b);
			return 0;
		}
		if (line[len - 1] == '\n')
			line[--len] = '\0';
		if (i == 0)
			b->width = len;
		else if(len != b->width) {
			free(line);
			b->lines = i;
			free_map(b);
			return 0;
		}
		b->map[i] = line;
	}
	return 1;
}

void	start(FILE *f) {
	BSQ b = {0};
	if (!parse(&b, f))
		return (void)fprintf(stderr, "error: invalid map\n");
	solve_bsq(&b);
	for (int i = 0; i < b.lines; i++) {
		fputs(b.map[i], stdout);
		fputs("\n", stdout);
	}
	free_map(&b);
}

int main(int ac, char **av) {
	FILE *f;
	if (ac == 2)
		f = fopen(av[1], "r");
	else
		f = stdin;
	if (!f)
		return (fprintf(stderr, "Error opening the file\n"), 1);
	start(f);
	if (ac == 2)
		fclose(f);
	return 0;
}
