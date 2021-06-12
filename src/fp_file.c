#include <stdio.h>
#include "menu.h"
#include "settings.h"
#include "fp.h"
#include "commands.h"

static void save_slot_dec_proc(struct menu_item *item, void *data)
{
    pm_status.save_slot += 3;
    pm_status.save_slot %= 4;
}

static void save_slot_inc_proc(struct menu_item *item, void *data)
{
    pm_status.save_slot += 1;
    pm_status.save_slot %= 4;
}

static void save_proc() {
    command_save_game_proc();
}

static void load_proc() {
    command_load_game_proc();
}

static int byte_mod_proc(struct menu_item *item, enum menu_callback_reason reason, void *data) {
    int8_t *p = data;
    if (reason == MENU_CALLBACK_THINK_INACTIVE) {
        if (menu_intinput_get(item) != *p)
            menu_intinput_set(item, *p);
    }
    else if (reason == MENU_CALLBACK_CHANGED)
        *p = menu_intinput_get(item);
    return 0;
}

static int halfword_mod_proc(struct menu_item *item, enum menu_callback_reason reason, void *data) {
    int16_t *p = data;
    if (reason == MENU_CALLBACK_THINK_INACTIVE) {
        if (menu_intinput_get(item) != *p)
            menu_intinput_set(item, *p);
    }
    else if (reason == MENU_CALLBACK_CHANGED)
        *p = menu_intinput_get(item);
    return 0;
}

static int checkbox_mod_proc(struct menu_item *item, enum menu_callback_reason reason, void *data) {
    uint8_t *p = data;
    if (reason == MENU_CALLBACK_SWITCH_ON) {
        *p = 1;
    }
    else if (reason == MENU_CALLBACK_SWITCH_OFF) {
        *p = 0;
    }
    else if (reason == MENU_CALLBACK_THINK) {
        menu_checkbox_set(item, *p);
    }
    return 0;
}

static int story_progress_draw_proc(struct menu_item *item, struct menu_draw_params *draw_params) {
    gfx_mode_set(GFX_MODE_COLOR, GPACK_RGB24A8(draw_params->color, draw_params->alpha));
    struct gfx_font *font = draw_params->font;
    int x = draw_params->x;
    int y = draw_params->y;

    int8_t progress = pm_unk3.story_progress;
    int8_t chapter_starts[] = {
        -128,
        -98,
        -74,
        -51,
        -12,
        8,
        40,
        60,
        90,
        97
    };
    uint8_t chapter = 0;
    int8_t chapter_progress = 0;
    int8_t chapter_max = 0;
    for (int i = 1; i < 10; i++) {
        if (progress >= chapter_starts[i]) {
            chapter++;
        }
        else {
            chapter_progress = progress - chapter_starts[chapter];
            chapter_max = chapter_starts[chapter + 1] - chapter_starts[chapter];
            break;
        }
    }

    char buffer[24];
    if (chapter == 0) {
        sprintf(buffer, "- prologue (%d/%d)", chapter_progress, chapter_max);
    }
    else if (chapter > 8) {
        sprintf(buffer, "- invalid");
    }
    else {
        sprintf(buffer, "- chapter %d (%d/%d)", chapter, chapter_progress, chapter_max);
    }
    gfx_printf(font, x, y, buffer);
    return 1;
}

struct menu *create_file_menu(void)
{
    static struct menu menu;
    
    /* initialize menu */
    menu_init(&menu, MENU_NOVALUE, MENU_NOVALUE, MENU_NOVALUE);

    /*build menu*/
    int y = 0;
    int MENU_X = 17;

    menu.selector = menu_add_submenu(&menu, 0, y++, NULL, "return");
    menu_add_static(&menu, 0, y, "save slot", 0xC0C0C0);
    menu_add_button(&menu, 11, y, "-", save_slot_dec_proc, NULL);
    menu_add_watch(&menu, 13, y, (uint32_t)&pm_status.save_slot, WATCH_TYPE_U8);
    menu_add_button(&menu, 15, y++, "+", save_slot_inc_proc, NULL);
    menu_add_button(&menu, 0, y, "save", save_proc, NULL);
    menu_add_button(&menu, 5, y++, "load", load_proc, NULL);
    y++;
    menu_add_static(&menu, 0, y, "story progress", 0xC0C0C0);
    menu_add_intinput(&menu, MENU_X, y++, 16, 2, byte_mod_proc, &pm_unk3.story_progress);
    menu_add_static_custom(&menu, 1, y++, story_progress_draw_proc, NULL, 0xC0C0C0);
    y++;
    menu_add_static(&menu, 0, y, "music", 0xC0C0C0);
    menu_add_checkbox(&menu, MENU_X, y++, checkbox_mod_proc, &pm_status.music_enabled);
    menu_add_static(&menu, 0, y, "quizzes answered", 0xC0C0C0);
    menu_add_intinput(&menu, MENU_X, y, 10, 2, halfword_mod_proc, &pm_flags.global_bytes[0x161]);

    
    return &menu;
}
