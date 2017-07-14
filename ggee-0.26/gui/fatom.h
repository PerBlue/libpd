/* ------------------------ fatom ----------------------------- */

#ifndef _fatom_h_
#define _fatom_h_

#define x_val a_pos.a_w.w_float
#define DEBUG(x) 

#include <string.h>
#include <stdio.h>

typedef struct _fatom
{
     t_object x_obj;
     t_atom a_pos;  /* the value of the fatom */

     t_glist * x_glist; /* value of the current canvas, intialized in _new */
     int x_rect_width; /* width of the widget */
     int x_rect_height; /* height of the widget */
     t_symbol*  x_sym; /* symbol for receiving callbacks from GUI */
     t_symbol*  x_type; /* type of fatom (vslider, hslider, checkbutton) */

     t_symbol*  x_text; /* associated widget text */
     int x_max; /* maximum value of a_pos (x_val) */
     int x_min; /* minimum value of a_pos (x_val) */
     int x_width; /* width of widget (e.g x_rect_height + 15 for hslider, x_rect_width + 15 for slider) */
     t_symbol* x_color;
     t_symbol* x_bgcolor;
} t_fatom;

/* widget helper functions */




static void draw_inlets(t_fatom *x, t_glist *glist, int firsttime, int nin, int nout);

static void draw_handle(t_fatom *x, t_glist *glist, int firsttime);

static void create_widget(t_fatom *x, t_glist *glist);





static void fatom_drawme(t_fatom *x, t_glist *glist, int firsttime);


static void fatom_erase(t_fatom* x,t_glist* glist);
	


/* ------------------------ fatom widgetbehaviour----------------------------- */


static void fatom_getrect(t_gobj *z, t_glist *owner,
    int *xp1, int *yp1, int *xp2, int *yp2);

static void fatom_displace(t_gobj *z, t_glist *glist,
    int dx, int dy);

static void fatom_select(t_gobj *z, t_glist *glist, int state);


static void fatom_activate(t_gobj *z, t_glist *glist, int state);

static void fatom_delete(t_gobj *z, t_glist *glist);

       
static void fatom_vis(t_gobj *z, t_glist *glist, int vis);

static void fatom_save(t_gobj *z, t_binbuf *b);

t_widgetbehavior   fatom_widgetbehavior;

 


void fatom_size(t_fatom* x,t_floatarg w,t_floatarg h);

void fatom_color(t_fatom* x,t_symbol* col);

static void fatom_float(t_fatom* x,t_floatarg f);

static void fatom_bang(t_fatom* x,t_floatarg f);

static void fatom_f(t_fatom* x,t_floatarg f);


static void fatom_properties(t_gobj *z, t_glist *owner);


static void *fatom_new(t_fatom* x,t_floatarg max, t_floatarg min, t_floatarg h,t_symbol* text);

void fatom_setup_common(t_class* class);

#endif
