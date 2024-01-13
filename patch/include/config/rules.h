/* There are two options when it comes to per-client rules:
 *  - a typical struct table or
 *  - using the RULE macro
 *
 * A traditional struct table looks like this:
 *    // class      instance  title  wintype  tags mask  isfloating  monitor
 *    { "Gimp",     NULL,     NULL,  NULL,    1 << 4,    0,          -1 },
 *    { "Firefox",  NULL,     NULL,  NULL,    1 << 7,    0,          -1 },
 *
 * The RULE macro has the default values set for each field allowing you to only
 * specify the values that are relevant for your rule, e.g.
 *
 *    RULE(.class = "Gimp", .tags = 1 << 4)
 *    RULE(.class = "Firefox", .tags = 1 << 7)
 *
 * Refer to the Rule struct definition for the list of available fields.
 */
static const Rule rules[] = {
    /* xprop(1):
     *      WM_CLASS(STRING) = instance, class
     *      WM_NAME(STRING) = title
     */

    /* place window with substring in title on tag (useful with restartsig patch) */
    RULE(.title = "[.1]", .tags = 1 << 0)
    RULE(.title = "[.2]", .tags = 1 << 1)
    RULE(.title = "[.3]", .tags = 1 << 2)
    RULE(.title = "[.4]", .tags = 1 << 3)
    RULE(.title = "[.5]", .tags = 1 << 4)
    RULE(.title = "[.6]", .tags = 1 << 5)
    RULE(.title = "[.7]", .tags = 1 << 6)
    RULE(.title = "[.8]", .tags = 1 << 7)
    RULE(.title = "[.9]", .tags = 1 << 8)
    /* monitor */
    RULE(.title = "(.0)", .monitor = 0)
    RULE(.title = "(.1)", .monitor = 1)
    RULE(.title = "(.2)", .monitor = 2)

    RULE(.title = "The-Matrix-Shell", .isfullscreen = -1)

    RULE(.class = "steam",                   .tags = 1 << 7, .monitor = 0)
    RULE(.class = "steam_app_",              .tags = 1 << 7, .monitor = 0)
    RULE(.class = "easyeffects",             .tags = 1 << 7, .monitor = 1)

    RULE(.class = "google-chrome",           .tags = 1 << 6, .monitor = -1)
    RULE(.class = "firefox",                 .tags = 1 << 6, .monitor = -1)
    RULE(.class = "firefoxdeveloperedition", .tags = 1 << 6, .monitor = -1)

    RULE(.instance = "telegram-desktop",     .tags = 1 << 8, .monitor = 1)
    RULE(.instance = "telegram-desktop", .title = "Media viewer",
         .monitor = -1, .isfloating = 1, .fbpx = 1, .isfullscreen = 0,
         .floatx = -1, .floaty = -1, .floatw = -1, .floath = -1
    )

    /* class        instance    title           tgmask isf mon float x,y,w,h      fbpx isF skey*/
    { "mpv",    "MPVstream",    NULL,           1 << 5, 0,  1, 0,0,0,0,             2,  0,  0  },
    { NULL,     "rocksmith",    "Rocksmith",    1 << 7, 1,  0, 0,8,-1,-1,           0,  0, 'R' },
    { NULL,         NULL,       "scratchpad",   0,      1, -1, -1,-1,1200,700,      2,  0, 't' },
    { NULL,         NULL,       "calc",         0,      1, -1, -1,-1,400,600,       4,  0, 'c' },
    { NULL,         NULL,       "muse",         0,      1, -1, 0,8,-1,-1,           0,  0, 'm' },
    { NULL,         NULL,       "HTOP",         0,      1, -1, 0,8,-1,-1,           0,  0, 'h' },
    { NULL,       "opaque",     "pomodoro",     0,      1, -1, -1,-1,1200,700,      2,  0, 'p' },
    { NULL,       "opaque",     "drop",         0,      1, -1, 0,8,-1,888,          0,  0, 'd' },
    { NULL,      "twitchez",    "twitchez",     0,      1, -1, 0,8,-1,-1,           0,  0, 'e' },
};

/*First arg only serves to match against key in rules*/
static const char *sp_term[] = {"t", "st", "-t", "scratchpad", NULL};
static const char *sp_calc[] = {"c", "st", "-t", "calc", "-f", "monospace:size=16", "-e", "bc", "-lq", NULL };
static const char *sp_muse[] = {"m", "st", "-t", "muse", "-e", "ncmpcpp", NULL };
static const char *sp_htop[] = {"h", "st", "-t", "HTOP", "-e", "htop", NULL };
static const char *sp_pmdr[] = {"p", "st", "-t", "pomodoro", "-n", "opaque", "-e", "pmdr", NULL };
static const char *sp_drop[] = {"d", "st", "-t", "drop", "-n", "opaque", NULL };
static const char *sp_twitchez[] = {"e", "st", "-t", "twitchez", "-n", "twitchez", "-f", "VictorMono Nerd Font Mono:pixelsize=14", "twitchez", NULL };

