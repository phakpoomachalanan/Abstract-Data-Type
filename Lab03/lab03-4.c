#include <stdio.h>
#include <stdlib.h>

int traverseMaze(char **maze, int mazeSize, int y, int x);

int main(void) {
    char **maze;
    char trash;
    int  startPositionX;
    int  startPositionY;
    int  flag = 1;
    int  mazeSize;
    
    scanf("%d%c", &mazeSize, &trash);

    maze = (char **)malloc(sizeof(char *) * mazeSize);
    for (int k=0; k<mazeSize; k++)
    {
        maze[k] = (char *)malloc(sizeof(char) * mazeSize);
    }

    for (int i=0; i<mazeSize; i++)
    {
        for (int j=0; j<mazeSize; j++)
        {
            maze[i][j] = fgetc(stdin);
            if (flag == 1 && maze[i][j] == 'S')
            {
                startPositionX = j;
                startPositionY = i;
                flag = 0;
            }
        }
        scanf("%c", &trash);
    }
        
    traverseMaze(maze, mazeSize, startPositionY, startPositionX);

    maze[startPositionY][startPositionX] = 'S';

    for (int j=0; j<mazeSize; j++)
    {
        printf("%s\n", maze[j]);
    }

    return 0;
}

int traverseMaze(char **maze, int mazeSize, int y, int x)
{
    maze[y][x] = '#';

    if(x+1 < mazeSize && maze[y][x+1] == 'G')
    {
        maze[y][x] = '.';
        return 1;
    }
    else if (y+1 < mazeSize && maze[y+1][x] == 'G')
    {
        maze[y][x] = '.';
        return 1;
    }
    else if (x-1 >= 0 && maze[y][x-1] == 'G')
    {
        maze[y][x] = '.';
        return 1;
    }
    else if (y-1 >= 0 && maze[y-1][x] == 'G')
    {
        maze[y][x] = '.';
        return 1;
    }

    if (x+1 < mazeSize && maze[y][x+1] == ' ' && traverseMaze(maze, mazeSize, y, x+1))
    {
        maze[y][x] = '.';
    }
    else if (y+1 < mazeSize && maze[y+1][x] == ' ' && traverseMaze(maze, mazeSize, y+1, x))
    {
        maze[y][x] = '.';
    }
    else if (x-1 >= 0 && maze[y][x-1] == ' ' && traverseMaze(maze, mazeSize, y, x-1))
    {
        maze[y][x] = '.';
    }
    else if (y-1 >= 0 && maze[y-1][x] == ' ' && traverseMaze(maze, mazeSize, y-1, x))
    {
        maze[y][x] = '.';
    }
    else
    {
        maze[y][x] = ' ';
        return 0;
    }

    return 1;
}