//
// Define shapes for game pieces
// Will Orr 8/18/25
//


#define NUM_PIECES 40
#define MAX_DIM 5
typedef unsigned char piece_map_t[MAX_DIM][MAX_DIM];
typedef struct {
    unsigned char x_len;
    unsigned char y_len;
    unsigned char topl_botr;
    piece_map_t map;
} piece_struct;
extern const piece_struct piece_library[NUM_PIECES];
