
  typedef struct  s_point
  {
    int           x;
    int           y;
  }               t_point;

void	fill(char **tab, t_point size, t_point begin, char to_fill, char c)
{
	if (begin.x < 0 || begin.x >= size.x || begin.y < 0 || begin.y >= size.y)
		return ;
	if (tab[begin.y][begin.x] != to_fill)
		return ;
	tab[begin.y][begin.x] = c;
	
	fill(tab, size, (t_point){begin.x, begin.y + 1}, to_fill, c);
	fill(tab, size, (t_point){begin.x, begin.y - 1}, to_fill, c);
	fill(tab, size, (t_point){begin.x + 1, begin.y}, to_fill, c);
	fill(tab, size, (t_point){begin.x - 1, begin.y}, to_fill, c);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	char	to_fill = tab[begin.y][begin.x];
	char	c = 'F';
	
	fill(tab, size, begin, to_fill, c);
}
