/*
******************************
**      2048 game           **
******************************
*/


#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include "allegro5/allegro_image.h"
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <cstdio>

using namespace std;


/*
**
** Game's configuration
**
*/

// Game's settings
int max_value = 11; // basically it's highest power of 2 = highest result

// Dimensions
int block_height = 106;
int block_width = 106;
int button_x = 361;
int button_y = 100;
int button_w = 129;
int button_h = 42;
int vertical_blocks = 4;
int horizontal_blocks = 4;
int gap_size = 15;
int top_offset = 186;
int display_width = block_width * horizontal_blocks + gap_size * ( horizontal_blocks + 1 );
int display_height = block_height * vertical_blocks + gap_size * ( vertical_blocks + 1 ) + top_offset;
// Blocks values
int values_number = vertical_blocks * horizontal_blocks;
int values[ 16 ];
// Allegro variables

ALLEGRO_DISPLAY *display = NULL;
ALLEGRO_EVENT_QUEUE *event_queue = NULL;
ALLEGRO_BITMAP* bitmap[ 12 ];
ALLEGRO_BITMAP* buttons[ 1 ];
ALLEGRO_BITMAP* items[ 3 ];
ALLEGRO_FONT * font20 = NULL;
ALLEGRO_MOUSE_STATE mice;


// Mechanics utils
int last_round[ 16 ];
int indexes[ 4 ][ 4 ];
int score;
int summed_blocks[ 3 ];
bool game_end;
const string button_files[ 1 ] =
{
    "blocks/new.png"
};
const string items_files[ 3 ] =
{
    "blocks/board.png",
    "blocks/lost.png",
    "blocks/won.png"
};
/*
**
** Initialization functions
**
*/

// load all graphics
bool prepare_bitmaps()
{
    stringstream ss;

    for( int i = 0; i <= max_value; ++i )
    {
        ss << "blocks/" << i << ".png";
        bitmap[ i ] = al_load_bitmap( ss.str().c_str() );
        if( !bitmap[ i ] )
        {
            cerr << "Prepare Bitmaps error." << endl;
            cerr << "Could not load: " << ss.str() << endl;
            return false;
        }
        ss.str( "" );
    }

    for( int i = 0; i < 1; ++i )
    {
        buttons[ i ] = al_load_bitmap( button_files[ i ].c_str() );
        if( !buttons[ i ] )
        {
            cerr << "Prepare Bitmaps error." << endl;
            cerr << "Could not load: " << button_files[ i ] << endl;
            return false;
        }

    }

    for( int i = 0; i < 3; ++i )
    {
        items[ i ] = al_load_bitmap( items_files[ i ].c_str() );
        if( !items[ i ] )
        {
            cerr << "Prepare Bitmaps error." << endl;
            cerr << "Could not load: " << items_files[ i ] << endl;
            return false;
        }

    }

    return true;
}

// clear game_board, empty all blocks
void prepare_values()
{
    for( int i = 0; i < values_number; ++i )
    {
        values[ i ] = 0;
    }
}

// initialize allegro
int init()
{
    if( !al_init() )
    {
        cerr << "Al Init error." << endl;
        return -1;
    }

    if( !al_init_primitives_addon() )
    {
        cerr << "Al Init Primitives Addon error." << endl;
        return -1;
    }

    if( !al_init_image_addon() )
    {
        cerr << "Al Init Image Addon error." << endl;
        return -1;
    }

    al_init_font_addon();

    if( !al_init_ttf_addon() )
    {
        cerr << "Al Init TTF Addon error." << endl;
        return -1;
    }
    font20 = al_load_ttf_font("blocks/courbd.ttf",20, 0);

    if( !font20 )
    {
        cerr << "Al Create Font error." << endl;
        return -1;
    }

    if( !al_install_keyboard() )
    {
        cerr << "Al Install Keyboard error." << endl;
        return -1;
    }


    if( !al_install_mouse() )
    {
        cerr << "Al Install Mouse error." << endl;
        return -1;
    }

    display = al_create_display( display_width, display_height );
    if( !display )
    {
        cerr << "Al Create Display error." << endl;
        return -1;
    }

    event_queue = al_create_event_queue();
    if( !event_queue )
    {
        cerr << "Al Create Event Queue error." << endl;
        al_destroy_display( display );
        return -1;
    }

    al_register_event_source( event_queue, al_get_display_event_source( display ) );
    al_register_event_source( event_queue, al_get_keyboard_event_source() );
    al_register_event_source( event_queue, al_get_mouse_event_source());
    al_clear_to_color( al_map_rgb( 0, 0, 0 ) );

    al_flip_display();

    return 0;
}


/*
**
** Game mechanics
**
*/

// moving directions
enum directions { dir_up = 1001, dir_down = 1002, dir_left = 1003, dir_right = 1004 };
// verbose boolean enum
enum tests { test = true, not_a_test = false };

// get horizontal distance for given column
int get_block_x( int column )
{
    return block_width * column + gap_size * (column + 1);
}

// get vertical distance for given row
int get_block_y( int row )
{
    return block_height * row + gap_size * (row + 1) + top_offset;
}

// draw current state of game board
void draw_game_board()
{
    al_clear_to_color( al_map_rgb( 0, 0, 0 ) );
    al_draw_bitmap( items[ 0 ], 0, 0, 0 );
    al_draw_textf (font20,al_map_rgb(100,100,100),375,22,0, "%i" ,score );
    al_draw_bitmap( buttons[ 0 ], 361, 100, 0 );

    int value_index;
    for( int i = 0; i < horizontal_blocks; ++i )
    {
        for( int j = 0; j < vertical_blocks ; ++j )
        {
            value_index = i * horizontal_blocks + j; //basically increase from 0 to 15
            //{0,  1,  2,  3 }
            //{4,  5,  6,  7 }
            //{8,  9,  10, 11}
            //{12, 13, 14, 15}
            al_draw_bitmap( bitmap[ values[ value_index ] ],
                           get_block_x( j ),
                           get_block_y( i ),
                           0 );
            // bitmap[0] - keeps empty image
            // bitmap[1] - keeps image with number 2
            // bitmap[2] - keeps image with number 4 and so on
            // bitmap[ values[ value_index ] ] - keeps image with number for value_index block
        }
    }
}

// updates two dimensional array needed for moving
// every row keeps sorted blocks indexes
// in row: indexes from last to first - it is how blocks will be moved
void updateIndexes( directions direction )
{
    //game board
    //{0,  1,  2,  3 }
    //{4,  5,  6,  7 }
    //{8,  9,  10, 11}
    //{12, 13, 14, 15}
    switch( direction )
    {
        case dir_up:
            //moving blocks up
            indexes[0][0] = 0;indexes[0][1] = 4;indexes[0][2] = 8;indexes[0][3] = 12;//     {0, 4, 8, 12}
            //first we move block on index 4 -> 0, then 8 -> 4 -> 0, then 12 -> 8 -> 4 -> 0
            indexes[1][0] = 1;indexes[1][1] = 5;indexes[1][2] = 9;indexes[1][3] = 13; //    {1, 5, 9, 13}
            //second we move 5 -> 1, then 9 -> 5 -> 1, then 13 -> 9 -> 5 -> 1, and so on
            indexes[2][0] = 2;indexes[2][1] = 6;indexes[2][2] = 10;indexes[2][3] = 14;//    {2, 6, 10, 14}
            indexes[3][0] = 3;indexes[3][1] = 7;indexes[3][2] = 11;indexes[3][3] = 15;//    {3, 7, 11, 15}
            break;
        case dir_down:
            indexes[0][0] = 12;indexes[0][1] = 8;indexes[0][2] = 4;indexes[0][3] = 0;//     {12, 8, 4, 0}
            indexes[1][0] = 13;indexes[1][1] = 9;indexes[1][2] = 5;indexes[1][3] = 1; //    {13, 9, 5, 1}
            indexes[2][0] = 14;indexes[2][1] = 10;indexes[2][2] = 6;indexes[2][3] = 2;//    {14, 10, 6, 2}
            indexes[3][0] = 15;indexes[3][1] = 11;indexes[3][2] = 7;indexes[3][3] = 3;//    {15, 11, 7, 3}
            break;
        case dir_left:
            indexes[0][0] = 0;indexes[0][1] = 1;indexes[0][2] = 2;indexes[0][3] = 3;//     {0, 1, 2, 3}
            indexes[1][0] = 4;indexes[1][1] = 5;indexes[1][2] = 6;indexes[1][3] = 7; //    {4, 5, 6, 7}
            indexes[2][0] = 8;indexes[2][1] = 9;indexes[2][2] = 10;indexes[2][3] = 11;//    {8, 9, 10, 11}
            indexes[3][0] = 12;indexes[3][1] = 13;indexes[3][2] = 14;indexes[3][3] = 15;//    {12, 13, 14, 15}
            break;
        case dir_right:
            indexes[0][0] = 3;indexes[0][1] = 2;indexes[0][2] = 1;indexes[0][3] = 0;//     {3, 2, 1, 0}
            indexes[1][0] = 7;indexes[1][1] = 6;indexes[1][2] = 5;indexes[1][3] = 4; //    {7, 6, 5, 4}
            indexes[2][0] = 11;indexes[2][1] = 10;indexes[2][2] = 9;indexes[2][3] = 8;//    {11, 10, 9, 8}
            indexes[3][0] = 15;indexes[3][1] = 14;indexes[3][2] = 13;indexes[3][3] = 12;//    {15, 14, 13, 12}
            break;
    }
}

void print_score()
{
    cout << "Your score: " << score << endl;
}

void clear_summed_blocks()
{
    summed_blocks[0] = -1;
    summed_blocks[1] = -1;
    summed_blocks[2] = -1;
}

void set_block_as_summed( int block_index )
{
    for( int i = 0; i < 3; ++i )
    {
        if( -1 == summed_blocks[ i ] )
        {
            summed_blocks[ i ] = block_index;
            break;
        }
    }
}

bool was_summed( int block_index )
{
    for( int i = 0; i < 3; ++i )
    {
        if( block_index == summed_blocks[ i ] )
        {
            return true;
        }
    }
    return false;
}

// moving blocks, or just testing if move possible
bool move_values( int current, int target, bool test )
{
    if( values[ target ] == 0 )
	{
	    //move possible
	    if( test )
        {
            return true;
        }
	    //move to empty block
	    //move value and leave empty block behind
		values[ target ] = values[ current ];
		values[ current ] = 0;
	}
	else if( values[ target ] == values[ current ] && !was_summed(target) && !was_summed(current))
	{
	    //move possible
	    if( test )
        {
            return true;
        }
	    //move to block with same value if target block has not been summed yet
	    //change value on next block (increase power of 2)
	    //and leave empty block behind
		values[ target ] = values[ target ] + 1;
		score += pow(2, values[ target ]);
		print_score();
		values[ current ] = 0;
		set_block_as_summed( target );
		set_block_as_summed( current );
	}
	//if move to block with different value, do not do anything
	return false;
}

// moving whole line (or just test if possible)
// if moving up/down it is column
// if moving right/left it is row
// function is using two dimensional array indexes to distinct between column/row
bool move_line( int i, bool test )
{
    clear_summed_blocks();
    //we are moving blocks 1 tile at a time
    //starting at 2nd block closes to direction we moving (if moving up, we start moving with 2nd block from top)
    //1st block obviously stays in place, but still can change value (if moving up, the top block does not move)
    for( int start_at = 1; start_at < 4; ++start_at )
    {
        for( int current_block = start_at; current_block > 0; --current_block )
        {
            int target_block = current_block - 1;
            // current block and target blocks will get following values:
            // current -> target
            // 1 -> 0
            // 2 -> 1
            // 1 -> 0
            // 3 -> 2
            // 2 -> 1
            // 1 -> 0
            // if we moving up - second (1) goes to the top block (0),
            // then third (2) goes to second(1) and again to the top (0),
            // then fourth (3, the one at the bottom) goes to third block (2) then to second (1) and then to the top one (0).
            bool test_result = move_values(indexes[i][current_block], indexes[i][target_block], test);
            // if just testing if move possible and test_result is true, return true = moving this line is possible
            if(test && test_result)
            {
                return true;
            }
        }
    }
    return false;
}

// moving all line
// prepares two dimensional array indexes
// and invoke move_line for all (columns - up/down or rows - right/left).
void move_it( directions direction )
{
    updateIndexes(direction);
    for( int i = 0; i < 4; ++i )
    {
        move_line(i, not_a_test);
    }
}

// testing moving all lines
// does same thing as move_it
// but does NOT change any value on game board
bool test_it( directions direction )
{
    updateIndexes(direction);
    for( int i = 0; i < 4; ++i )
    {
        bool test_result = move_line(i, test);
        if( test_result )
        {
            return true;
        }
    }
    return false;
}

// nice name for testing if moving up is possible
bool can_move_up()
{
    return test_it(dir_up);
}

// nice name for moving up
void move_up()
{
    move_it(dir_up);
}

// so forth
bool can_move_down()
{
    return test_it(dir_down);
}

// and so on
void move_down()
{
    move_it(dir_down);
}

bool can_move_left()
{
    return test_it(dir_left);
}

void move_left()
{
    move_it(dir_left);
}

bool can_move_right()
{
    return test_it(dir_right);
}

void move_right()
{
    move_it(dir_right);
}

// nice name for checking if move in any direction is possible
bool check_move_available()
{
    return can_move_up() || can_move_down() || can_move_left() || can_move_right();
}

// checking if there is empty block on game board
// needed to place random number 2 at the begging of turn
bool can_add_one()
{
    for( int i = 0; i < values_number; ++i )
    {
        if( values[ i ] == 0 )
        {
            return true;
        }
    }
    return false;
}

// returns [from, to] - including both from and to
// not [from, to) as in basic rand
int getRandom( int from, int to )
{
    int range = to - from + 1;
    int randomed = rand() % range;
    return from + randomed;
}

// adding number 2 or 4 on random empty block
void add_one_at_random()
{
    int randomNumber;

    do
    {
        randomNumber = rand() % values_number;
    }
    while( values[ randomNumber ] != 0 );
    values[ randomNumber ] = getRandom(1, 2);
}

// starting game
void start_game()
{
    cout << "New game. Good Luck!" << endl;
    game_end = false;
    // clear game board
    prepare_values();
    for( int i = 0; i < 16; ++i )
    {
        last_round[ i ] = 0;
    }
    // set players score to 0
    score = 0;
    // add random 2
    add_one_at_random();
    // add random 2
    add_one_at_random();
    // dram game board
    draw_game_board();
    // show newly drawn board
    al_flip_display();
}

// checking if any block has maximum value (11 -> pow(2,11) = 2048)
bool check_if_won()
{
    for( int i = 0; i < values_number; ++i )
    {
        if( values[ i ] == max_value )
        {
            return true;
        }
    }
    return false;
}

bool check_if_button_hit(float x, float y)
{
   if( (x > button_x) & (x<button_x + button_w))
   {
       if( (y > button_y) & (y<button_y + button_h))
       {
            return true;
       }
   }
    return false;
}

// draws result on game board
void draw_result( string result )
{
    if( result == "lost")
    {
        al_draw_bitmap(items[ 1 ], 0, 0, 0);
    }
    else
    {
        al_draw_bitmap(items[ 2 ], 0, 0, 0);
    }
    al_flip_display();
}

void win()
{
    game_end = true;
    draw_result( "won" );
    cout << "You won" << endl;
    cout << "If you want to play again click S" << endl;
    cout << "To exit click ESC" << endl;
}

void lose()
{
    game_end = true;
    draw_result( "lost" );
    cout << "You lost" << endl;
    cout << "If you want to try again click S" << endl;
    cout << "To exit click ESC" << endl;
}


bool moved_since_last_round()
{
    for( int i = 0; i < 16; ++i )
    {
        /*cout << values[ i ] << " " << last_round[ i ];
        if( (i + 1) % 4 == 0 )
        {
            cout << endl;
        }*/
        if(values[ i ] != last_round[ i ] )
        {
           return true;
        }
    }
    return false;
}

void update_last_round()
{
    for( int i = 0; i < 16; ++i )
    {
        last_round[ i ] = values[ i ];
    }
}

/*
**
** Game itself
**
*/

int main( int argc, char ** argv )
{
    // initialize random salt for whole game
    srand( time( NULL ) );

    // initialize allegro
    if( init() != 0 )
    {
        cerr << "Init error." << endl;
        return -1;
    }

    // load images
    if( !prepare_bitmaps() )
    {
        return -1;
    }

    bool redraw = false;
    bool exit = false;
    bool print_menu = true;

    // main loop
    do
    {
        if( print_menu )
        {
            cout << "Welcome to 2048 game clone." << endl;
            cout << "To start click S" << endl;
            cout << "To leave (now or ever) press ESC" << endl;
            cout << endl << "You can use arrows to navigate, everything else is straight forward." << endl;
            cout << "Good luck at getting 2048!";
            if( max_value != 11 )
            {
                cout << " Or " << pow( 2, max_value )  << " this time.";
            }
            cout << endl;
            print_menu = false;
            start_game();
        }

        ALLEGRO_EVENT ev;

        al_get_mouse_state(&mice);
        al_wait_for_event( event_queue, &ev );
        // Player control - get clicked key
        if( ev.type == ALLEGRO_EVENT_KEY_UP )
        {
            // ESC
            if( ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE || ev.keyboard.keycode == ALLEGRO_KEY_Q )
            {
                //signal end of game
                exit = true;
            }

            // S
            if( ev.keyboard.keycode == ALLEGRO_KEY_S )
            {
                start_game();
            }

            // UP
            if( ev.keyboard.keycode == ALLEGRO_KEY_UP )
            {
                // check if it is possible to move up
                if( can_move_up() )
                {
                    // move up - update values on game board (player can not see it yet - game board is not redrawn)
                    move_up();
                    // signal need for redrawing game board
                    redraw = true;
                }
            }

            // DOWN
            if( ev.keyboard.keycode == ALLEGRO_KEY_DOWN )
            {
                if( can_move_down() )
                {
                    move_down();
                    redraw = true;
                }
            }

            // LEFT
            if( ev.keyboard.keycode == ALLEGRO_KEY_LEFT )
            {
                if( can_move_left() )
                {
                    move_left();
                    redraw = true;
                }
            }

            // RIGHT
            if( ev.keyboard.keycode == ALLEGRO_KEY_RIGHT )
            {
                if( can_move_right() )
                {
                    move_right();
                    redraw = true;
                }
            }
        }
        if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
        {
            if (check_if_button_hit(mice.x,mice.y))
            {
                start_game();
            }
        }
        // Game board control
        // player clicked up, down, left or right
        if( redraw && al_is_event_queue_empty( event_queue ) )
        {
            // game board will be redrawn, wait for another signal
            redraw = false;

            if( check_if_won() )
            {
                win();
            }
            else if( !can_add_one() )
            {
                lose();
            }

            if( !game_end )
            {
                if( moved_since_last_round() )
                {
                    // add number 2 or 4 at random empty block
                    add_one_at_random();
                    update_last_round();
                }

                draw_game_board();
                al_flip_display();

                if( !check_move_available() )
                {
                    lose();
                }
            }
        }
    }
    while( !exit );

    return 0;
}
