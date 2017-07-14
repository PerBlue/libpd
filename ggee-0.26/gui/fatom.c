#include <m_pd.h>
#include "g_canvas.h"
#include "fatom.h"

static t_class *fatom_class;

void fatom_setup() {
  post("fatom setup");
    fatom_class = class_new(gensym("fatom"), (t_newmethod)fatom_new, 0,
				sizeof(t_fatom),0,A_DEFSYM,0);

  fatom_setup_common(fatom_class);
}

void fatom_setup_common(t_class* class)
{

  fatom_widgetbehavior.w_getrectfn =  fatom_getrect;
  fatom_widgetbehavior.w_displacefn = fatom_displace;
  fatom_widgetbehavior.w_selectfn =   fatom_select;
  fatom_widgetbehavior.w_activatefn = fatom_activate;
  fatom_widgetbehavior.w_deletefn =  fatom_delete;
  fatom_widgetbehavior.w_visfn =     fatom_vis;
#if PD_MINOR_VERSION < 37
  fatom_widgetbehavior.w_savefn =    fatom_save;
  fatom_widgetbehavior.w_propertiesfn = NULL,
#endif
  fatom_widgetbehavior.w_clickfn =   NULL,

    class_addfloat(class, (t_method)fatom_float);
    class_addbang(class, (t_method)fatom_bang);
    class_addmethod(class, (t_method)fatom_f, gensym("f"),
    	A_FLOAT, 0);

/*
    class_addmethod(class, (t_method)fatom_size, gensym("size"),
    	A_FLOAT, A_FLOAT, 0);

    class_addmethod(class, (t_method)fatom_color, gensym("color"),
    	A_SYMBOL, 0);
*/
/*
    class_addmethod(class, (t_method)fatom_open, gensym("open"),
    	A_SYMBOL, 0);
*/
    class_setwidget(class,&fatom_widgetbehavior);
#if PD_MINOR_VERSION >= 37
    class_setsavefn(class,&fatom_save);
#endif
}

void fatom_size(t_fatom* x,t_floatarg w,t_floatarg h) {
     x->x_rect_width = w;
     x->x_rect_height = h;
}

void fatom_color(t_fatom* x,t_symbol* col)
{
/*     outlet_bang(x->x_obj.ob_outlet); only bang if there was a bang ..
       so color black does the same as bang, but doesn't forward the bang
*/
}
