#ifndef CONFIG_H
#define CONFIG_H

#define BOARD_WIDTH 32
#define BOARD_HEIGHT 16

#define FOOD_COUNT 1

static const int debug = 0;
static const int game_speed = 100000;

static const int wrap = 1;
static const int snake_starting_length = 4;

static const int snake_starting_pos_x = 16;
static const int snake_starting_pos_y = 8;

static const int food_score_increment = 1;

static const int food_snake_length_increment = 1;

static const char snake_head_up_char = 'v';
static const char snake_head_down_char = '^';
static const char snake_head_left_char = '>';
static const char snake_head_right_char = '<';

static const char snake_tail_char = '*';

static const char food_char = '%';

static const char board_corner_char = '+';
static const char board_vertical_char = '|';
static const char board_horizontal_char = '-';
static const char board_blank_char = ' ';

static const char* color_black = "\033[30m";
static const char* color_red = "\033[31m";
static const char* color_green = "\033[32m";
static const char* color_yellow = "\033[33m";
static const char* color_blue = "\033[34m";
static const char* color_magenta = "\033[35m";
static const char* color_cyan = "\033[36m";
static const char* color_white = "\033[37m";

#define DEFAULT_CHAR_COLOR color_white

#define SNAKE_HEAD_CHAR_COLOR color_red
#define SNAKE_TAIL_CHAR_COLOR color_green

#define FOOD_CHAR_COLOR color_yellow

#define BOARD_CORNER_CHAR_COLOR color_cyan
#define BOARD_VERTICAL_CHAR_COLOR color_blue
#define BOARD_HORIZONTAL_CHAR_COLOR color_blue

#define DIRECTION_UP 'k'
#define DIRECTION_DOWN 'j'
#define DIRECTION_LEFT 'h'
#define DIRECTION_RIGHT 'l'

#define SNAKE_STARTING_DIRECTION DIRECTION_RIGHT

#endif /* CONFIG_H */
