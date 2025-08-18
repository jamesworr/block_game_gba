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

void wait_any_key(void) {
    while(1) {
        vid_vsync();
        key_poll();
        if(key_hit(KEY_ANY)) {
            break;
        }
    }
}

void demo_animation(int frame) {
    if ((frame & 0x0007) != 0x0007) {
        return;
    }
    for (int i = 0; i < MAX_BLOCKS; i++) {
        if (board_state[i/NUM_ROWS][i%NUM_COLS]) {
            board_state[(i-1)/NUM_ROWS][(i-1)%NUM_COLS] = 1;
            board_state[i/NUM_ROWS][i%NUM_COLS] = 0;
            if (i == 0) {
                board_state[NUM_ROWS-1][NUM_COLS-1] = 1;
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
                block_obj->attr0 = block_obj->attr0 & 0xFCFF;
            }
            else {
                block_obj->attr0 = block_obj->attr0 | ATTR0_HIDE;
            }
        }
    }
}

void opening_sequence(void) {
//    // Setup bmp background
//    memcpy32(vid_mem, me_fullBitmap, me_fullBitmapLen / sizeof(u32));
//    memcpy16(pal_bg_mem, me_fullPal, me_fullPalLen / sizeof(u16));
//
//    REG_DISPCNT= DCNT_MODE4 | DCNT_BG2;
//
//    // Text screen 1
//    tte_init_bmp_default(4);
//    tte_write("#{P:72,110}");
//    tte_write("Happy birthday, Avery!");
//    tte_write("#{P:72,140}");
//    tte_write("Press any key to continue");
//    vid_vsync();
//    wait_any_key();
//    vid_vsync();
//    // Clean up
//    tte_write("#{P:72,110}");
//    tte_erase_line();
//    vid_vsync();
//
//    // Text screen 2
//    vid_vsync();
//    tte_write("#{P:5,110}");
//    tte_write("We all know you can't mail things to other continents");
//    tte_write("#{P:72,120}");
//    tte_write("so this year I had to go digital!");
//    vid_vsync();
//    wait_any_key();
//
//    // Clean up
//    tte_write("#{P:5,110}");
//    tte_erase_line();
//    tte_write("#{P:72,120}");
//    tte_erase_line();
//    vid_vsync();
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
    // TODO init 81 block sprites
    OBJ_ATTR *block_obj;
    for (int i = 0; i < MAX_BLOCKS; i++) {
        block_obj = &obj_buffer[i];
        obj_set_attr(block_obj,
            ATTR0_SQUARE | ATTR0_HIDE,
            ATTR1_SIZE_16x16,
            ATTR2_PALBANK(0) | BLOCK_TILE_OFFSET);
        obj_set_pos(block_obj, (i/NUM_COLS)*BLOCK_HEIGHT, (i%NUM_ROWS)*BLOCK_WIDTH); // TODO fix XY per block location
    }

    // TODO remove demo
    board_state[NUM_ROWS-1][NUM_COLS-1] = 1;
    board_state[NUM_ROWS-3][NUM_COLS-3] = 1;
    board_state[NUM_ROWS-5][NUM_COLS-5] = 1;

    int frame_counter = 0;
    while(1) {
        vid_vsync();
        key_poll();
        if (key_hit(KEY_SELECT)) {
            break; // Break out of waiting loop and restart
        }

        // TODO move live piece
        // move left/right
        //x += 2*key_tri_horz();

        // move up/down
        //y += 2*key_tri_vert();

        // TODO update colors of live piece placement
        // make collision 1 color and valid placement another

        // TODO check for "place" command

        // FIXME update all touched blocks
        //mr_env->attr2= ATTR2_BUILD(tid, pb, 0);
        //obj_set_pos(mr_env, x, y);

        // TODO remove demo
        demo_animation(frame_counter);

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
