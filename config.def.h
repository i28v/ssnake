#ifndef CONFIG_H
#define CONFIG_H

/* array size constants */

#define BOARD_WIDTH 32
#define BOARD_HEIGHT 16

#define FOOD_COUNT 1

/* any other constant */

static const int debug = 0;
static const int game_speed = 100000;

static const int wrap = 1;
static const int snake_starting_length = 4;

static const int snake_starting_pos_x = 16;
static const int snake_starting_pos_y = 8;

static const int food_score_increment = 1;

static const int food_snake_length_increment = 1;

static const char snake_head_char = '@';
static const char snake_tail_char = '*';

static const char food_char = '%';

static const char board_corner_char = '+';
static const char board_vertical_char = '|';
static const char board_horizontal_char = '-';
static const char board_blank_char = ' ';

/* constants that would otherwize be variables but the compiler complained about it */

#define DIRECTION_UP 'k'
#define DIRECTION_DOWN 'j'
#define DIRECTION_LEFT 'h'
#define DIRECTION_RIGHT 'l'

/* constants that wouldn't make any sense if they were a variable */

#define SNAKE_STARTING_DIRECTION DIRECTION_RIGHT

#endif /* CONFIG_H */
