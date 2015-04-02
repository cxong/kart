#include "map.h"
#include "powerup.h"
#include "renderer.h"
#include "shell.h"

// none doesnæt have an image
static SDL_Texture *textures[POWERUP_STAR+1] = {0};

extern int ren_offset_x, ren_offset_y;

void powerup_render(SDL_Renderer *ren, PowerUp type, ivec2 pos)
{
        SDL_Rect target;
        target.x = pos.x;
        target.y = pos.y;
        target.w = POWERUPS_WIDTH;
        target.h = POWERUPS_HEIGHT;
        SDL_RenderCopy(ren, textures[type], 0, &target);
}

int powerups_init()
{
    textures[POWERUP_NONE]          = ren_load_image("none_powerup.bmp");
    textures[POWERUP_BANANA]        = ren_load_image("banana.bmp");
    textures[POWERUP_GREEN_SHELL]   = ren_load_image("green_shell.bmp");
    textures[POWERUP_RED_SHELL]     = ren_load_image("red_shell.bmp");
    textures[POWERUP_BLUE_SHELL]    = ren_load_image("blue_shell.bmp");
    textures[POWERUP_OIL]           = ren_load_image("oil.bmp");
    textures[POWERUP_MUSHROOM]      = ren_load_image("mushroom.bmp");
    textures[POWERUP_BIG_MUSHROOM]  = ren_load_image("big_mushroom.bmp");
    textures[POWERUP_LIGHTNING]     = ren_load_image("lightning.bmp");
    textures[POWERUP_STAR]          = ren_load_image("star.bmp");

    for (int i=0; i<POWERUP_STAR; i++) {
        if (!textures[i]) {
            return 0;
        }
    }

    return 1;
}
