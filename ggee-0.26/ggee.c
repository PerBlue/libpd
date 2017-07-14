#include "m_pd.h"

typedef struct _ggee
{
     t_object x_obj;
} t_ggee;

static t_class* ggee_class;

// objects
void constant_setup();
void getdir_setup();
void inv_tilde_setup();
void inv_setup();
void qread_setup();
void rl_setup();
void serial_bird_setup();
void serial_ms_setup();
void serial_mt_setup();
void serialize_setup();
void shell_setup();
void sinh_setup();
void sl_setup();
void stripdir_setup();
void unserialize_setup();
void unwonk_setup();
void fofsynth_tilde_setup();
void shuffle_setup();
void tabwrite4_tilde_setup();
void bandpass_setup();
void equalizer_setup();
void highpass_setup();
void highshelf_setup();
void hlshelf_setup();
void lowpass_setup();
void lowshelf_setup();
void moog_tilde_setup();
void notch_setup();
void button_setup();
void envgen_setup();
void fatom_setup();
void gcanvas_setup();
void image_setup();
void slider_setup();
void sliderh_setup();
void state_setup();
void ticker_setup();
void toddle_setup();
void atan2_tilde_setup();
void mixer_tilde_setup();
void sfwrite_tilde_setup();
void streamin_tilde_setup();
void streamout_tilde_setup();

static void* ggee_new(t_symbol* s) {
    t_ggee *x = (t_ggee *)pd_new(ggee_class);
    return (x);
}

void ggee_setup(void)
{
    ggee_class = class_new(gensym("ggee"), (t_newmethod)ggee_new, 0, sizeof(t_ggee), 0,0);

    constant_setup();
    getdir_setup();
    inv_tilde_setup();
    inv_setup();
    qread_setup();
    rl_setup();
    serial_bird_setup();
    serial_ms_setup();
    serial_mt_setup();
    serialize_setup();
    shell_setup();
    sinh_setup();
    sl_setup();
    stripdir_setup();
    unserialize_setup();
    unwonk_setup();
    fofsynth_tilde_setup();
    shuffle_setup();
    tabwrite4_tilde_setup();
    bandpass_setup();
    equalizer_setup();
    highpass_setup();
    highshelf_setup();
    hlshelf_setup();
    lowpass_setup();
    lowshelf_setup();
    moog_tilde_setup();
    notch_setup();
    button_setup();
    envgen_setup();
    fatom_setup();
    gcanvas_setup();
    image_setup();
    slider_setup();
    sliderh_setup();
    state_setup();
    ticker_setup();
    toddle_setup();
    atan2_tilde_setup();
    mixer_tilde_setup();
    sfwrite_tilde_setup();
    streamin_tilde_setup();
    streamout_tilde_setup();
}
