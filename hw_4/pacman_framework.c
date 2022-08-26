#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define FOOD_SCORE 10
#define MAX_GHOSTS 30

typedef enum gameState
{
    losing,
    onGoing,
    winning
} GameState;
typedef enum direction
{
    up,
    down,
    left,
    right,
    idle
} Direction;

typedef struct game
{
    char **grid;
    int columns;
    int rows;
    int foodCount;
    int score;
    int pcm;
    int ghost;
    int pcm_x;
    int pcm_y;
    GameState state;
} Game;

typedef struct ghost
{
    int x;
    int y;
    int before;
    Direction direction;
} Ghost;

Ghost ghost[MAX_GHOSTS];

/* Creates a new game, with given rows and columns.
 * The left-upper corner is at row 0 and column 0.
 * Boundary is not included in either rows or columns.
 * You should dynamically allocate space for a Game pointer,
 * dynamically allocate a 2-dimensional char grid,
 * and initialize any other value in your Game structure.
 * Return that pointer to the game you created.
 */
Game *NewGame(int rows, int columns)
{
    Game *game = (Game *)malloc(sizeof(Game));
    game->rows = rows;
    game->columns = columns;
    game->foodCount = 0;
    game->score = 0;
    game->pcm = 0;
    game->ghost = 0;
    game->pcm_x = 0;
    game->pcm_y = 0;
    game->state = onGoing;
    game->grid = (char **)malloc(rows * sizeof(char *));
    game->grid[0] = (char *)malloc(rows * columns * sizeof(char));
    for (int i = 1; i < rows; i++)
    {
        game->grid[i] = game->grid[i - 1] + columns;
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            game->grid[i][j] = ' ';
        }
    }
    return game;
}

/* Ends your game by freeing any memory
 * you dynamically created.
 * After that, free the game pointer,
 * as it is also dynamically created.
 */
void EndGame(Game *game)
{
    free(game->grid[0]);
    free(game->grid);
    free(game);

    return;
}

/* Adds a wall to the game, at row = r, column = c.
 * Walls should be added only to an empty place.
 * After you successfully add a wall, 
 * you should modify the `grid' to represent
 * the wall by '#'. Then, return true.
 * Return false on failures.
 */
bool AddWall(Game *game, int r, int c)
{
    if (r * c < 0 || r >= game->rows || c >= game->columns || game->grid[r][c] != ' ')
    {
        return false;
    }
    else
    {
        game->grid[r][c] = '#';
        return true;
    }
    return false;
}

/* Adds a food to the game, at row = r, column = c.
 * Foods should be added only to an empty place.
 * After you successfully add a food, 
 * you should modify the `grid' to represent
 * the food by '.', also update the `foodCount'
 * correctly. Then, return true.
 * Return false on failures.
 *
 * FOR PART 2:
 * It's not allowed to add a food on a ghost.
 * It's allowed, however, conversely.
 */
bool AddFood(Game *game, int r, int c)
{
    if (r * c < 0 || r >= game->rows || c >= game->columns || game->grid[r][c] != ' ')
    {
        return false;
    }
    else
    {
        game->grid[r][c] = '.';
        game->foodCount += 1;
        return true;
    }
    return false;
}

/* Adds a Pacman to the game! At row = r, column = c.
 * If there is already a Pacman, return false.
 * Pacman should be added only to an empty place.
 * After you successfully add a Pacman,
 * you should modify the `grid' to represent
 * the Pacman by 'C'. Then, return true.
 * Return false on failures.
 */
bool AddPacman(Game *game, int r, int c)
{
    if (r * c < 0 || r >= game->rows || c >= game->columns)
    {
        return false;
    }
    else if (game->grid[r][c] == ' ' && game->pcm == 0)
    {
        game->grid[r][c] = 'C';
        game->pcm = 1;
        game->pcm_x = r;
        game->pcm_y = c;
        return true;
    }
    return false;
}

/* Moves Pacman in the given direction.
 * The direction will always be valid.
 * Pacman should stay still if this move
 * will let him hit a wall or boundaries.
 * No matter what move is performed, the
 * game score should decrease by 1.
 *
 * FOR PART 2:
 * Pacman is allowed to move onto a grid
 * with a ghost. In that case, Pacman loses,
 * and will not be able to eat the food
 * under that ghost, if any. Score should
 * still decrease by 1.
 */
void MovePacman(Game *game, Direction direction)
{
    game->score -= 1;
    int x = game->pcm_x;
    int y = game->pcm_y;
    switch (direction)
    {
    case up:
        if (x <= 0 || game->grid[x - 1][y] == '#')
        {
            return;
            break;
        }
        x -= 1;
        break;
    case down:
        if (x >= game->rows - 1 || game->grid[x + 1][y] == '#')
        {
            return;
            break;
        }
        x += 1;
        break;
    case left:
        if (y <= 0 || game->grid[x][y - 1] == '#')
        {
            return;
            break;
        }
        y -= 1;
        break;
    case right:
        if (y >= game->columns - 1 || game->grid[x][y + 1] == '#')
        {
            return;
            break;
        }
        y += 1;
        break;
    case idle:
        return;
        break;
    }
    if (game->grid[x][y] == '.')
    {
        game->grid[x][y] = 'C';
        game->grid[game->pcm_x][game->pcm_y] = ' ';
        game->pcm_x = x;
        game->pcm_y = y;
        game->foodCount -= 1;
        game->score += FOOD_SCORE;
        if (game->foodCount == 0)
        {
            game->state = winning;
        }
        return;
    }
    else if (game->grid[x][y] == ' ')
    {
        game->grid[x][y] = 'C';
        game->grid[game->pcm_x][game->pcm_y] = ' ';
        game->pcm_x = x;
        game->pcm_y = y;
        return;
    }
    else if (game->grid[x][y] == '@')
    {
        game->grid[game->pcm_x][game->pcm_y] = ' ';
        game->pcm = 0;
        game->state = losing;
        return;
    }

    return;
}

/* Adds a ghost to the game,
 * at row = r, column = c, with given initial direction.
 * you should modify the `grid' to represent the ghost by '@'.
 * Ghosts can be added to an empty place or on a food.
 * For the latter case, the ghost will cover that food on display,
 * represented also by an '@'. 
 * That food must still exist, and that grid should 
 * display '.' when the ghost leaves.
 */
bool AddGhost(Game *game, int r, int c, Direction direction)
{
    if (r * c < 0 || r >= game->rows || c >= game->columns || direction == idle)
    {
        return false;
    }
    else if (game->grid[r][c] == ' ' && game->ghost < MAX_GHOSTS)
    {
        game->ghost += 1;
        ghost[game->ghost].x = r;
        ghost[game->ghost].y = c;
        ghost[game->ghost].direction = direction;
        ghost[game->ghost].before = 0;
        game->grid[r][c] = '@';
        return true;
    }
    else if (game->grid[r][c] == '.' && game->ghost < MAX_GHOSTS)
    {
        game->ghost += 1;
        ghost[game->ghost].x = r;
        ghost[game->ghost].y = c;
        ghost[game->ghost].direction = direction;
        ghost[game->ghost].before = 1;
        game->grid[r][c] = '@';
        return true;
    }
    return false;
}

/* Moves all ghosts in their own directions.
 * Ghosts should be moved in the order they were added.
 * If a ghost will bump into a wall, another ghost, or a boundary,
 * Its direction will reverse, and it will try to move
 * in the new direction immediately this turn.
 * If it bumps into another wall/ghost/boundary,
 * it won't move for this turn.
 */
void MoveGhosts(Game *game)
{
    for (int i = 1; i <= game->ghost; i++)
    {
        int x = ghost[i].x;
        int y = ghost[i].y;
        Direction direction = ghost[i].direction;
        int before = ghost[i].before;
        int change = 0;
        switch (direction)
        {
        case up:
            for (int j = 1; j <= game->ghost; j++)
            {
                if ((ghost[j].x == x - 1 && ghost[j].y == y) || x == 0 || game->grid[x - 1][y] == '#')
                {
                    ghost[i].direction = down;
                    change = 1;
                    break;
                }
            }
            if (change == 1)
            {
                for (int j = 1; j <= game->ghost; j++)
                {
                    if ((ghost[j].x == x + 1 && ghost[j].y == y) || x == game->rows - 1 || game->grid[x + 1][y] == '#')
                    {
                        ghost[i].direction = up;
                        change = 3;
                        break;
                    }
                }
            }
            if (change == 1)
            {
                x += 1;
                change = 0;
                break;
            }
            if (change == 0)
            {
                x -= 1;
                break;
            }
            if (change == 3)
            {
                change = 0;
                break;
            }
            break;
        case down:
            for (int j = 1; j <= game->ghost; j++)
            {
                if ((ghost[j].x == x + 1 && ghost[j].y == y) || x == game->rows - 1 || game->grid[x + 1][y] == '#')
                {
                    ghost[i].direction = up;
                    change = 1;
                    break;
                }
            }
            if (change == 1)
            {
                for (int j = 1; j <= game->ghost; j++)
                {
                    if ((ghost[j].x == x - 1 && ghost[j].y == y) || x == 0 || game->grid[x - 1][y] == '#')
                    {
                        ghost[i].direction = down;
                        change = 3;
                        break;
                    }
                }
            }
            if (change == 1)
            {
                x -= 1;
                change = 0;
                break;
            }
            if (change == 0)
            {
                x += 1;
                break;
            }
            if (change == 3)
            {
                change = 0;
                break;
            }
            break;
        case left:
            for (int j = 1; j <= game->ghost; j++)
            {
                if ((ghost[j].x == x && ghost[j].y == y - 1) || y == 0 || game->grid[x][y - 1] == '#')
                {
                    ghost[i].direction = right;
                    change = 1;
                    break;
                }
            }
            if (change == 1)
            {
                for (int j = 1; j <= game->ghost; j++)
                {
                    if ((ghost[j].x == x && ghost[j].y == y + 1) || y == game->columns - 1 || game->grid[x][y + 1] == '#')
                    {
                        ghost[i].direction = left;
                        change = 3;
                        break;
                    }
                }
            }
            if (change == 1)
            {
                y += 1;
                change = 0;
                break;
            }
            if (change == 0)
            {
                y -= 1;
                break;
            }
            if (change == 3)
            {
                change = 0;
                break;
            }
            break;
        case right:
            for (int j = 1; j <= game->ghost; j++)
            {
                if ((ghost[j].x == x && ghost[j].y == y + 1) || y == game->columns - 1 || game->grid[x][y + 1] == '#')
                {
                    ghost[i].direction = left;
                    change = 1;
                    break;
                }
            }
            if (change == 1)
            {
                for (int j = 1; j <= game->ghost; j++)
                {
                    if ((ghost[j].x == x && ghost[j].y == y - 1) || y == 0 || game->grid[x][y - 1] == '#')
                    {
                        ghost[i].direction = right;
                        change = 3;
                        break;
                    }
                }
            }
            if (change == 1)
            {
                y -= 1;
                change = 0;
                break;
            }
            if (change == 0)
            {
                y += 1;
                break;
            }
            if (change == 3)
            {
                change = 0;
                break;
            }
            break;
        }
        if (ghost[i].x != x || ghost[i].y != y)
        {
            if (before == 1)
            {
                game->grid[ghost[i].x][ghost[i].y] = '.';
            }
            else
            {
                game->grid[ghost[i].x][ghost[i].y] = ' ';
            }
            if(game->grid[x][y] == '.')
            {
                ghost[i].before = 1;
                game->grid[x][y] = '@';
                ghost[i].x = x;
                ghost[i].y = y;
            }
            else if(game->grid[x][y] == ' ')
            {
                ghost[i].before = 0;
                game->grid[x][y] = '@';
                ghost[i].x = x;
                ghost[i].y = y;
            }
            else if(game->grid[x][y] == 'C')
            {
                game->grid[x][y] = '@';
                ghost[i].x = x;
                ghost[i].y = y;
                game->state = losing;
            }
        }
    }
    return;
}

///////////////////////////////////////////////////////////////////////////////
/////////////////// Please submit all code above to OJ ////////////////////////
///////////////////////////////////////////////////////////////////////////////

// Declarations of provided functions
void PrintGame(Game *game);
void PlayGame(Game *game);

int main()
{
    Game *game = NewGame(8, 8);

    // Add walls, foods, and pacman here.
    AddWall(game, 6, 5);
    AddPacman(game, 2, 3);
    AddFood(game, 5, 2);
    AddGhost(game, 2, 3, down);
    AddGhost(game, 3, 3, up);
    AddGhost(game, 1, 5, right);
    AddGhost(game, 4, 7, left);


    PlayGame(game);

    EndGame(game);
}

///////////////////////////////////////////////////////////////////////////////
//////////////////////// DO NOT MODIFY ANY CODE BELOW! ////////////////////////
///////////////////////////////////////////////////////////////////////////////

/* This function prints the game grid with boundary,
 * and any message depending on game state.
 * Please make sure that, after any action is done,
 * game->state, game->score, and game->foodCount
 * are correctly updated.
 */
#ifdef _MSC_VER

#include <windows.h>

#endif // _MSC_VER

void PrintGame(Game *game)
{
    if (!game || !game->grid)
        return;

// If visual C++, clear console.
#ifdef _MSC_VER
    system("cls");
#else
// Clears terminal screen
#ifndef _ONLINE_JUDGE
    fflush(stdout);
    system("clear");
#endif

#endif

    // The game grid
    printf(" ");
    for (int i = 0; i < game->columns; i++)
        printf("_");
    printf(" \n");

    for (int i = 0; i < game->rows; i++)
    {
        printf("|");
        for (int j = 0; j < game->columns; j++)
            printf("%c", game->grid[i][j]);
        printf("|\n");
    }
    printf("\\");
    for (int i = 0; i < game->columns; i++)
        printf("-");
    printf("/\n\n");

    // Messages on different states
    switch (game->state)
    {
    case losing:
        printf("Pacman died! Your score: %d\n", game->score);
        break;
    case onGoing:
        printf("Score: %d\n", game->score);
        printf("There are %d foods remaining!\n", game->foodCount);
        printf("Pacman wants food! (control by w/a/s/d/i, confirm by Enter)\n\n");
        break;
    case winning:
        printf("Victory! Your score: %d\n", game->score);
        break;
    default:
        printf("ERROR: invalid game state!\n");
    }
}

void PlayGame(Game *game)
{
    if (!game)
        return;

    // Prints the initial grid
    PrintGame(game);

    // Main loop of game. Terminates when the game ends.
    while (true)
    {
        // We only care about one charater, but should eat the whole line of input.
        char input[127];
        scanf("%s", input);
        Direction direction;
        switch (input[0])
        {
        case 'w':
        case 'W':
            direction = up;
            break;
        case 'a':
        case 'A':
            direction = left;
            break;
        case 's':
        case 'S':
            direction = down;
            break;
        case 'd':
        case 'D':
            direction = right;
            break;
        case 'i':
        case 'I':
            direction = idle;
            break;
        default:
            PrintGame(game);
            continue;
        }

        // Pacman moves first
        MovePacman(game, direction);

        // Loses if Pacman bumps into a ghost
        if (game->state != onGoing)
        {
            break;
        }

        // If you haven't implemented ghosts, this does nothing.
        MoveGhosts(game);

        // Loses if a ghost kills Pacman
        if (game->state != onGoing)
        {
            break;
        }
        PrintGame(game);
    }

    // End game message
    PrintGame(game);
    printf("Press any key to exit.\n");
    getchar();
    getchar();
}