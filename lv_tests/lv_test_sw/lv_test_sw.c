/**
 * @file lv_test_sw.c
 *
 */

/*********************
 *      INCLUDES
 *********************/
#include <stdio.h>  /*For printf in the action*/

#include "lv_test_sw.h"

#if USE_LV_SW != 0

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
static lv_res_t sw_action(lv_obj_t *sw);

/**********************
 *  STATIC VARIABLES
 **********************/

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/
/**
 * Create a default object and test the basic functions
 */
void lv_test_sw_1(void)
{
    /* Default object */
    lv_obj_t *sw1 = lv_sw_create(lv_scr_act(), NULL);
    lv_obj_set_pos_scale(sw1, 10, 10);
    lv_sw_set_action(sw1, sw_action);

    static lv_style_t bg;
    static lv_style_t indic;

    lv_style_copy(&bg, &lv_style_pretty);
    bg.body.padding.hor = -5 << LV_ANTIALIAS;
    bg.body.padding.ver = -5 << LV_ANTIALIAS;

    lv_style_copy(&indic, &lv_style_pretty_color);
    indic.body.padding.hor = 8 << LV_ANTIALIAS;
    indic.body.padding.ver = 8 << LV_ANTIALIAS;

    lv_obj_t *sw2 = lv_sw_create(lv_scr_act(), sw1);
    lv_sw_set_style(sw2, &bg, &indic, &lv_style_btn_pressed, &lv_style_btn_tgl_pressed);
    lv_sw_set_on(sw2);
    lv_obj_align_scale(sw2, sw1, LV_ALIGN_OUT_RIGHT_MID, 20, 0);

    lv_obj_t *sw3 = lv_sw_create(lv_scr_act(), sw2);
    lv_obj_align_scale(sw3, sw2, LV_ALIGN_OUT_RIGHT_MID, 20, 0);

}

/**********************
 *   STATIC FUNCTIONS
 **********************/

static lv_res_t sw_action(lv_obj_t *sw)
{
    printf("Switch state: %d\n", lv_sw_get_state(sw));
    return LV_RES_OK;
}


#endif /*USE_LV_SW*/