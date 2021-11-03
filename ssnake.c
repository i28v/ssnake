#include "util.h"
#include "config.h"

#define SNAKE_MAX_LENGTH ((BOARD_WIDTH - 2) * (BOARD_HEIGHT - 2))

void initialize_game();
void finalize_game();
void game_input();
void game_update();
void game_draw();

static char board[BOARD_HEIGHT][BOARD_WIDTH];
static int running;
static int snake_body_x[SNAKE_MAX_LENGTH], snake_body_y[SNAKE_MAX_LENGTH];
static int snake_length;
static char snake_direction;
static int food_x;
static int food_y;
static int score;

void initialize_game()
{
    running = 1;
    score = 0;
    snake_direction = SNAKE_STARTING_DIRECTION;
    snake_length = snake_starting_length;
    for(int i = 0; i < snake_length; i++)
    {
        snake_body_x[i] = snake_starting_pos_x - i;
        snake_body_y[i] = snake_starting_pos_y;
    }
    food_x = randnum(1, BOARD_WIDTH - 2);
    food_y = randnum(1, BOARD_HEIGHT - 2);
}

void finalize_game()
{
    LOG("Quitting...\n");
}

void game_input()
{
    if(kbhit())
    {
        char ch = getchar();
        if(ch == 'q') running = 0;
        else
        {
            switch(ch)
            {
            case DIRECTION_UP:
                if(snake_direction != DIRECTION_DOWN) snake_direction = ch;
                break;
            case DIRECTION_DOWN:
                if(snake_direction != DIRECTION_UP) snake_direction = ch;
                break;
            case DIRECTION_LEFT:
                if(snake_direction != DIRECTION_RIGHT) snake_direction = ch;
                break;
            case DIRECTION_RIGHT:
                if(snake_direction != DIRECTION_LEFT) snake_direction = ch;
                break;
            case 'g':
                if(debug) snake_length++;
            default:
                break;
            }
        }
    }
}

void game_update()
{
    for(int i = snake_length; i > 0; i--)
    {
        snake_body_x[i] = snake_body_x[i-1];
        snake_body_y[i] = snake_body_y[i-1];
    }
    switch(snake_direction)
    {
    case DIRECTION_UP:
        snake_body_y[0]--;
        break;
    case DIRECTION_DOWN:
        snake_body_y[0]++;
        break;
    case DIRECTION_LEFT:
        snake_body_x[0]--;
        break;
    case DIRECTION_RIGHT:
        snake_body_x[0]++;
    default:
        break;
    }
    if((snake_body_x[0] == food_x) && (snake_body_y[0] == food_y))
    {
        score += food_score_increment;
        snake_length += food_snake_length_increment;
        food_x = randnum(1, BOARD_WIDTH - 2);
        food_y = randnum(1, BOARD_HEIGHT - 2);
    }
    for(int i = 1; i < snake_length; i++)
    {
        if((snake_body_x[0] == snake_body_x[i]) && (snake_body_y[0] == snake_body_y[i]))
        {
            running = 0;
        }
    }
    switch(snake_body_x[0])
    {
    case 0:
        if(wrap) snake_body_x[0] = BOARD_WIDTH - 2;
        else running = 0;
        break;
    case (BOARD_WIDTH - 1):
        if(wrap) snake_body_x[0] = 1;
        else running = 0;
    default:
        break;
    }
    switch(snake_body_y[0])
    {
    case 0:
        if(wrap) snake_body_y[0] = BOARD_HEIGHT - 2;
        else running = 0;
        break;
    case (BOARD_HEIGHT - 1):
        if(wrap) snake_body_y[0] = 1;
        else running = 0;
    default:
        break;
    }

}

void game_draw()
{
    for(int j = 0; j < BOARD_HEIGHT; j++) for(int i = 0; i < BOARD_WIDTH; i++) board[j][i] = board_blank_char;
    board[0][0] = board_corner_char;
    board[0][BOARD_WIDTH-1] = board_corner_char;
    board[BOARD_HEIGHT-1][BOARD_WIDTH-1] = board_corner_char;
    board[BOARD_HEIGHT-1][0] = board_corner_char;
    for(int i = 1; i < BOARD_WIDTH-1; i++)
    {
        board[0][i] = board_horizontal_char;
        board[BOARD_HEIGHT-1][i] = board_horizontal_char;
    }
    for(int i = 1; i < BOARD_HEIGHT-1; i++)
    {
        board[i][0] = board_vertical_char;
        board[i][BOARD_WIDTH-1] = board_vertical_char;
    }
    switch(snake_direction)
    {
    case DIRECTION_UP:
        board[snake_body_y[0]][snake_body_x[0]] = snake_head_up_char;
        break;
    case DIRECTION_DOWN:
        board[snake_body_y[0]][snake_body_x[0]] = snake_head_down_char;
        break;
    case DIRECTION_LEFT:
        board[snake_body_y[0]][snake_body_x[0]] = snake_head_left_char;
        break;
    case DIRECTION_RIGHT:
        board[snake_body_y[0]][snake_body_x[0]] = snake_head_right_char;
    default:
        break;
    }
    for(int i = 1; i < snake_length; i++)
    {
        board[snake_body_y[i]][snake_body_x[i]] = snake_tail_char;
    }
    board[food_y][food_x] = food_char;
    RESET_CURSOR_POSITION();
    for(int j = 0; j < BOARD_HEIGHT; j++)
    {
        for(int i = 0; i < BOARD_WIDTH; i++)
        {
            if(board[j][i] == snake_head_up_char || board[j][i] == snake_head_down_char || board[j][i] == snake_head_left_char || board[j][i] == snake_head_right_char) printf("%s%c", SNAKE_HEAD_CHAR_COLOR, board[j][i]);
            else if(board[j][i] == snake_tail_char) printf("%s%c", SNAKE_TAIL_CHAR_COLOR, board[j][i]);
            else if(board[j][i] == food_char) printf("%s%c", FOOD_CHAR_COLOR, board[j][i]);
            else if(board[j][i] == board_corner_char) printf("%s%c", BOARD_CORNER_CHAR_COLOR, board[j][i]);
            else if(board[j][i] == board_vertical_char) printf("%s%c", BOARD_VERTICAL_CHAR_COLOR, board[j][i]);
            else if(board[j][i] == board_horizontal_char) printf("%s%c", BOARD_HORIZONTAL_CHAR_COLOR, board[j][i]);
            else printf("%s%c", DEFAULT_CHAR_COLOR, board[j][i]);
        }
        printf("\n");
    }
    printf("\n");
    printf("%sScore: %d\n\n\n\n", DEFAULT_CHAR_COLOR, score);
}

int main(void)
{
    CLEAR_SCREEN();
    initialize_terminal();
    initialize_game();
    do
    {
        game_input();
        game_update();
        game_draw();
        if(running) usleep(game_speed);
    } while(running);
    finalize_game();
    finalize_terminal();
    return 0;
}
