#include <stdio.h>
#include <stdlib.h>

typedef struct { int y, x, size; } square;

int min3(int a, int b, int c)
{
	if (a <= b && a <= c)
		return (a);
	else if (b <= a && b <= c)
		return (b);
	else
		return (c);
}

int slen(char *s)
{
	int i = 0;

	while (s[i])
		i++;
	return (i);
}

void free_map(char** map, int h)
{
	int i = 0;

	while (i < h)
		free(map[i++]);
	free(map);
}

void free_dp(int** dp, int h)
{
	int i = 0;

	while (i <= h)
		free(dp[i++]);
	free(dp);
}

int bsq(FILE* fi)
{
	// INIT
	int h, w, l;
	char e, o, f;
	char** map = NULL;
	int** dp = NULL;
	char* line;
	size_t len;
	square s;

	h = 0;
	w = 0;
	s.y = 0;
	s.x = 0;
	s.size = 0;
	// PARSE HEADER
	if (fscanf(fi, "%d %c %c %c\n", &h, &e, &o, &f) != 4)
		return (fprintf(stderr, "map error\n"), 1);
	if (h <= 0 || e == o || e == f || o == f)
		return (fprintf(stderr, "map error\n"), 1);
	// ALLOC MAP
	map = calloc(h, sizeof(char *));
	// READ LINES
	for (int i = 0; i < h; i++)
	{
		line = NULL;
		len = 0;
		if (getline(&line, &len, fi) < 0)
		{
			free_map(map, h);
			return (fprintf(stderr, "map error\n"), 1);
		}
		l = slen(line);
		if (l > 0 && line[l -1] == '\n')
			line[--l] = '\0';
		if (l == 0)
		{
			free(line);
			free_map(map, h);
			return (fprintf(stderr, "map error\n"), 1);
		}
		if (!w)
			w = l;
		else if (w != l)
		{
			free(line);
			free_map(map, h);
			return (fprintf(stderr, "map error\n"), 1);
		}
		map[i] = line;
	}
	// ALLOC DP
	dp = calloc(h + 1, sizeof(int *));
	for (int i = 0; i <= h; i++)
		dp[i] = calloc(w + 1, sizeof(int));
	// FILL DP
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (map[i][j] == e)
			{
				dp[i+1][j+1] = 1 + min3(dp[i][j], dp[i+1][j], dp[i][j+1]);
				if (s.size < dp[i+1][j+1])
				{
					s.y = i;
					s.x = j;
					s.size = dp[i+1][j+1];
				}
			}
			else if (map[i][j] != o && map[i][j] != f)
			{
				free_map(map, h);
				free_dp(dp, h);
				return (fprintf(stderr, "map error\n"), 1);
			}
		}
	}
	// PAINT SQUARE
	for (int i = s.y - s.size + 1; i <= s.y; i++)
		for (int j = s.x - s.size + 1; j <= s.x; j++)
			map[i][j] = f;
	// PRINT & FREE
	for (int i = 0; i < h; i++)
		fprintf(stdout, "%s\n", map[i]);
	free_map(map, h);
	free_dp(dp, h);
	return (0);
}

int main(int ac, char** av)
{
	FILE* fi;
	int i;

	if (ac == 1)
	{
		bsq(stdin);
		return (0);
	}
	for (i = 1; i < ac; i++)
	{
		fi = fopen(av[i], "r");
		if (!fi)
			fprintf(stderr, "map error\n");
		else
		{
			bsq(fi);
			fclose(fi);
		}
		if (i < ac - 1)
			fprintf(stdout, "\n");
	}
	return (0);
}