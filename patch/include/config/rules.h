static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
    /* class        instance    title           tgmask isf mon float x,y,w,h   fbrdrpx skey*/
    { NULL, "telegram-desktop", NULL,           1 << 8, 0,  1, 0,0,0,0,             2,  0  },
    { NULL, "pulseeffects",     NULL,           1 << 7, 0,  1, 0,0,0,0,             2,  0  },
    { NULL, "google-chrome",    NULL,           1 << 6, 0, -1, 0,0,0,0,             2,  0  },
    { "mpv",    "MPVstream",    NULL,           1 << 5, 0,  1, 0,0,0,0,             2,  0  },
    { NULL,         NULL,       "scratchpad",   0,      1, -1, -1,-1,1200,700,      2, 't' },
    { NULL,         NULL,       "calc",         0,      1, -1, -1,-1,400,600,       4, 'c' },
    { NULL,         NULL,       "muse",         0,      1, -1, 0,8,-1,-1,           0, 'm' },
    { NULL,       "opaque",     "pomodoro",     0,      1, -1, -1,-1,1200,700,      2, 'p' },
    { NULL,       "opaque",     "drop",         0,      1, -1, 0,8,-1,888,          0, 'd' },
};

/*First arg only serves to match against key in rules*/
static const char *sp_term[] = {"t", "st", "-t", "scratchpad", NULL};
static const char *sp_calc[] = {"c", "st", "-t", "calc", "-f", "monospace:size=16", "-e", "bc", "-lq", NULL };
static const char *sp_muse[] = {"m", "st", "-t", "muse", "-e", "ncmpcpp", NULL };
static const char *sp_pmdr[] = {"p", "st", "-t", "pomodoro", "-n", "opaque", "-e", "pmdr", NULL };
static const char *sp_drop[] = {"d", "st", "-t", "drop", "-n", "opaque", NULL };
