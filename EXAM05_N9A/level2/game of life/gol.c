#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int ac, char **av)
{
	if (ac != 4)
		return 0;
	int w = atoi(av[1]);
	int h = atoi(av[2]);
	int iter = atoi(av[3]);

	if (w <= 0 || h <= 0)
		return 0;
	char board[h][w];
	char newb[h][w];
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			board[i][j] = 0;
	char c;
	int x = 0;
	int y = 0;
	int pen = 0;
	while (read(0, &c, 1) > 0)
	{
		if (pen)
			board[y][x] = 1;
		if (c == 'w' && y > 0)
			y--;
		else if (c == 's' && y < h - 1)
			y++;
		else if (c == 'a' && x > 0)
			x--;
		else if (c == 'd' && x < w - 1)
			x++;
		else if (c == 'x')
			pen = !pen;
	}
	while (iter > 0)
	{
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				int ngbrs = 0;
				for (int dy = -1; dy <= 1; dy++)
				{
					for (int dx = -1; dx <= 1; dx++)
					{
						if (dy == 0 && dx == 0)
							continue;
						int ni = i + dy;
						int nj = j + dx;
						if (ni >= 0 && ni < h && nj >= 0 && nj < w)
							if (board[ni][nj] == 1)
								ngbrs++;
					}
				}
				if (board[i][j] == 1)
					newb[i][j] = (ngbrs == 2 || ngbrs == 3);
				else
					newb[i][j] = (ngbrs == 3);
			}
		}
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				board[i][j] = newb[i][j];
		iter--;
	}
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (board[i][j] == 1)
				putchar('0');
			else
				putchar(' ');
		}
		putchar('\n');
	}
}