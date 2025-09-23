//
// Will 8/5
//

#include <string.h>
#include <tonc.h>
#include "block_sprite.h"
#include "pieces.h"

OBJ_ATTR obj_buffer[128];
OBJ_AFFINE *obj_aff_buffer= (OBJ_AFFINE*)obj_buffer;

#define CBB_0  0
#define SBB_0 28

#define FPID 6
#define WPID 7

#define BLOCK_WIDTH  16
#define BLOCK_HEIGHT 16

#define NUM_COLS 9
#define NUM_ROWS 9
#define MAX_BLOCKS 81 // FIXME
#define BLOCK_GAP_WIDTH 0

#define BLOCK_TILE_OFFSET 0

BG_POINT bg0_pt= { 0, 0 };
SCR_ENTRY *bg0_map= se_mem[SBB_0];

const SCR_ENTRY my_map[20][32] = {
    {WPID,WPID,WPID,WPID,WPID,WPID,WPID,WPID,WPID,WPID,WPID,WPID,WPID,WPID,WPID,WPID,WPID,WPID,WPID,WPID,WPID,WPID,WPID,WPID,WPID,WPID,WPID,WPID,WPID,WPID,WPID,WPID},
    {WPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,WPID,WPID,WPID},
    {WPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,WPID,WPID,WPID},
    {WPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,WPID,WPID,WPID},
    {WPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,WPID,WPID,WPID},
    {WPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,WPID,WPID,WPID},
    {WPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,WPID,WPID,WPID},
    {WPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,WPID,WPID,WPID},
    {WPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,WPID,WPID,WPID},
    {WPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,WPID,WPID,WPID},
    {WPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,WPID,WPID,WPID},
    {WPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,WPID,WPID,WPID},
    {WPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,WPID,WPID,WPID},
    {WPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,WPID,WPID,WPID},
    {WPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,WPID,WPID,WPID},
    {WPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,WPID,WPID,WPID},
    {WPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,WPID,WPID,WPID},
    {WPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,WPID,WPID,WPID},
    {WPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,FPID,WPID,WPID,WPID},
    {WPID,WPID,WPID,WPID,WPID,WPID,WPID,WPID,WPID,WPID,WPID,WPID,WPID,WPID,WPID,WPID,WPID,WPID,WPID,WPID,WPID,WPID,WPID,WPID,WPID,WPID,WPID,WPID,WPID,WPID,WPID,WPID},
};

volatile u8 board_state[NUM_COLS][NUM_ROWS] = {
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
};

// FIXME dummy for now
// TODO make it a struct to handle multiple pieces
//const piece_map_t* live_piece = &(piece_library[0]);
volatile u8 live_piece_idx = 0;
volatile u8 live_piece_x   = 0;
volatile u8 live_piece_y   = 0;

void wait_any_key(void) {
    while(1) {
        vid_vsync();
        key_poll();
        if(key_hit(KEY_ANY)) {
            break;
        }
    }
}

// TODO optimize to only run live piece shape, not n^2
// returns collision state
u8 copy_piece_to_board_state(u8 piece_idx, u8 block_idx_x, u8 block_idx_y, u8 pal_offset) {
    volatile u8 collision_found = 0;
    for (int i = 0; i < MAX_DIM; i++) {
        for (int j = 0; j < MAX_DIM; j++) {
            board_state[block_idx_y+i][block_idx_x+j] = board_state[block_idx_y+i][block_idx_x+j] + (piece_library[piece_idx].map[i][j] << pal_offset);
            if (board_state[block_idx_y+i][block_idx_x+j] > 2) {
                collision_found = 1;
            }
        }
    }
    return collision_found;
}

// TODO optimize to only run live piece shape, not n^2
void remove_piece_from_board_state(u8 piece_idx, u8 block_idx_x, u8 block_idx_y, u8 pal_offset) {
    for (int i = 0; i < MAX_DIM; i++) {
        for (int j = 0; j < MAX_DIM; j++) {
            if (board_state[block_idx_y+i][block_idx_x+j] > 0) {
                board_state[block_idx_y+i][block_idx_x+j] = board_state[block_idx_y+i][block_idx_x+j] - (piece_library[piece_idx].map[i][j] << pal_offset);
            }
        }
    }
}

void render_blocks(void) {
    OBJ_ATTR *block_obj;
    for (int col = 0; col < NUM_COLS; col++) {
        for (int row = 0; row < NUM_ROWS; row++) {
            block_obj = &obj_buffer[(col*NUM_COLS)+row];
            if (board_state[row][col]) {
                // Set sprite visibility
                block_obj->attr0 = block_obj->attr0 & 0xFCFF;

                // Set sprite palette
                u8 pal_bank;
                switch (board_state[row][col]) {
                    case 2:
                        pal_bank = 1;
                        break;
                    default:
                        pal_bank = 3;
                        break;
                }
                block_obj->attr2 = ATTR2_BUILD(BLOCK_TILE_OFFSET, pal_bank, 0);
            }
            else {
                // Set sprite visibility
                block_obj->attr0 = block_obj->attr0 | ATTR0_HIDE;
            }
        }
    }
}

void demo_animation(void) {
    u8 piece_idx = 0;
    u8 pal_bank  = 0;
    while(1) {
        vid_vsync();
        key_poll();
        if (key_hit(KEY_SELECT)) {
            break; // Break out of waiting loop and restart
        }

        remove_piece_from_board_state(piece_idx, 4, 4, 0);

        if (key_hit(KEY_RIGHT) && (piece_idx < NUM_PIECES-1)) {
            piece_idx++;
        }
        if (key_hit(KEY_LEFT) && (piece_idx > 0)) {
            piece_idx--;
        }
        if (key_hit(KEY_UP)) {
            pal_bank++;
            for (int i = 0; i < MAX_BLOCKS; i++) {
                obj_buffer[i].attr2 = ATTR2_BUILD(BLOCK_TILE_OFFSET, pal_bank, 0);
            }
        }
        if (key_hit(KEY_DOWN)) {
            pal_bank--;
            for (int i = 0; i < MAX_BLOCKS; i++) {
                obj_buffer[i].attr2 = ATTR2_BUILD(BLOCK_TILE_OFFSET, pal_bank, 0);
            }
        }
        
        copy_piece_to_board_state(piece_idx, 4, 4, 0);

        render_blocks();
        oam_copy(oam_mem, obj_buffer,  MAX_BLOCKS /* + other things??? TODO */);
    }
}

void init_bg() {
    int ii, jj;

    // initialize a background
    REG_BG0CNT= BG_CBB(CBB_0) | BG_SBB(SBB_0) | BG_REG_64x64;
    REG_BG0HOFS= 0;
    REG_BG0VOFS= 0;

    // create the tiles: basic tile and a cross FIXME understand and edit
    const TILE tiles[2]=
    {
        {{0x11111111, 0x01111111, 0x01111111, 0x01111111,
          0x01111111, 0x01111111, 0x01111111, 0x00000001}},
        {{0x00000000, 0x00100100, 0x01100110, 0x00011000,
          0x00011000, 0x01100110, 0x00100100, 0x00000000}},
    };
    tile_mem[CBB_0][0]= tiles[0];
    tile_mem[CBB_0][1]= tiles[1];

    // create a palette
    pal_bg_bank[0][1]= RGB15(31,  0,  0);
    pal_bg_bank[1][1]= RGB15( 0, 31,  0);
    pal_bg_bank[2][1]= RGB15( 0,  0, 31);
    pal_bg_bank[3][1]= RGB15(16, 16, 16);

    // FIXME Clean up
    SCR_ENTRY *pse= bg0_map;
    SCR_ENTRY my_scr = 0;
    for(jj=0; jj<32*20; jj++) {
        ii = jj;// - (2*(jj/30));
        my_scr = my_map[ii/32][ii%32];
        *pse++ = SE_PALBANK(my_scr);
        //vid_vsync();
    }
}

void sprite_loop() {
    OBJ_ATTR *block_obj;
    for (int i = 0; i < MAX_BLOCKS; i++) {
        block_obj = &obj_buffer[i];
        obj_set_attr(block_obj,
            ATTR0_SQUARE | ATTR0_HIDE,
            ATTR1_SIZE_16x16,
            ATTR2_PALBANK(0) | BLOCK_TILE_OFFSET);
        obj_set_pos(block_obj, (i/NUM_COLS)*BLOCK_HEIGHT, (i%NUM_ROWS)*BLOCK_WIDTH);
    }

    // TODO remove demo
    //demo_animation();
    
    // Copy initial piece to board
    copy_piece_to_board_state(live_piece_idx, live_piece_x, live_piece_y, 0);

    volatile int frame_counter = 0;
    volatile u8 collision = 0;
    while(1) {
        vid_vsync();
        key_poll();
        if (key_hit(KEY_SELECT)) {
            break; // Break out of waiting loop and restart
        }
        // Game Loop
        // move live piece or swap live piece
        // check collisons
        // Can place?
        // Does legal placement clear any blocks? (vertical, horizontal, square)


        // Check collision

        // Check for "place" command
        // Double copy on placement to leave blocks in the game state
        // Check for no collision
        // Generate new live piece
        if ((key_hit(KEY_A)) && (collision == 0)) {
            live_piece_idx = qran_range(0, NUM_PIECES-1);
            live_piece_x   = 0;
            live_piece_y   = 0;
        }
        else {
            remove_piece_from_board_state(live_piece_idx, live_piece_x, live_piece_y, 0);
        }
        
        // FIXME redo the bounds checking to account for different piece shapes
        if (key_hit(KEY_UP) && (live_piece_y > 0)) {
            live_piece_y--;
        }
        if (key_hit(KEY_DOWN) && (live_piece_y < (NUM_ROWS - piece_library[live_piece_idx].y_len))) {
            live_piece_y++;
        }
        if (key_hit(KEY_LEFT) && (live_piece_x > 0)) {
            live_piece_x--;
        }
        if (key_hit(KEY_RIGHT) && (live_piece_x < (NUM_ROWS - piece_library[live_piece_idx].x_len))) {
            live_piece_x++;
        }

        collision = copy_piece_to_board_state(live_piece_idx, live_piece_x, live_piece_y, 0);
        // TODO update colors of live piece placement
        // make collision 1 color and valid placement another


        // FIXME update all touched blocks
        //mr_env->attr2= ATTR2_BUILD(tid, pb, 0);
        //obj_set_pos(mr_env, x, y);


        render_blocks();
        oam_copy(oam_mem, obj_buffer,  MAX_BLOCKS /* + other things??? TODO */);
        frame_counter++;
    }
}

int main() {
    while(1) {
        //opening_sequence();

        // Setup for tiled mode
        // Places the glyphs of a 4bpp Mr. Envelope
        //   into LOW obj memory (cbb == 4)
        // TODO copy block
        memcpy32(&tile_mem[4][0], block_spriteTiles, block_spriteTilesLen / sizeof(u32));
        memcpy16(pal_obj_mem, block_spritePal, block_spritePalLen / sizeof(u16));
        oam_init(obj_buffer, 128);
        REG_DISPCNT= DCNT_MODE0 | DCNT_BG0 | DCNT_OBJ | DCNT_OBJ_1D;

        //init_bg(); // FIXME create basic BG
        sprite_loop();

        // Waiting for new commands
        while(1) {
            vid_vsync();
            key_poll();
            if (key_hit(KEY_SELECT)) {
                break; // Break out of waiting loop and restart
            }
        }
    }
    return 0;
}
