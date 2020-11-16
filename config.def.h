/* See LICENSE file for copyright and license details. */

/* tray and bar */
static unsigned int systraypinning  = 2;    /* 0: follow monitor, >0: pin to monitor X */
static unsigned int systrayspacing  = 2;    /* systray spacing */
static int systraypinningfailfirst  = 1;    /* if fails display on: 1-first, 0-last monitor*/
static int showsystray              = 1;    /* 0 means no systray */
static char statussep               = ';';  /* separator between status bars */

/* appearance */
static unsigned int borderpx        = 2;    /* border pixel of windows */
static unsigned int snap            = 2;    /* snap pixel */
static int showbar                  = 1;    /* 0 means no bar */
static int topbar                   = 1;    /* 0 means bottom bar */
static const char *fonts[] = {
       "monospace:size=8",
       "JoyPixels:pixelsize=8:antialias=true:autohint=true",
       "FontAwesome:pixelsize=8",
};
static char dmenufont[]             = "monospace:size=8";
static char normbgcolor[]           = "#3E494C";
static char normfgcolor[]           = "#E0E5E6";
static char selfgcolor[]            = "#32393A";
static char selbgcolor[]            = "#97A6AA";
static char normbordercolor[]       = "#32393A";
static char selbordercolor[]        = "#97A6AA";
static char *colors[][3] = {
       /*               fg           bg           border   */
       [SchemeNorm] = { normfgcolor, normbgcolor, normbordercolor },
       [SchemeSel]  = { selfgcolor,  selbgcolor,  selbordercolor  },
};

/* tagging */
#define MAX_TAGNAME_LEN 14             /* excludes TAG_PREPEND */
#define TAG_PREPEND "%1i"              /* format */
#define MAX_TAGLEN 16                  /* altogether */
static char tags[][MAX_TAGLEN] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };
static const char *tagsalt[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

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
    { NULL,       "opaque",     "pomodoro",     0,      1, -1, -1,-1,1200,700,      2, 'p' },
    { NULL,       "opaque",     "drop",         0,      1, -1, 0,8,-1,888,          0, 'd' },
};

/* layout(s) */
static float mfact     = 0.5;   /* factor of master area size [0.05..0.95] */
static int nmaster     = 1;     /* number of clients in master area */
static int resizehints = 1;     /* 1 means respect size hints in tiled resizals */

#include "layout/bottomstack.c"
#include "layout/centeredmaster.c"
#include "layout/deck.c"
#include "layout/gaplessgrid.c"
#include "layout/horizgrid.c"
static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "TTT",      bstack },                 /* +bind setlayout key! */
	{ "[D]",      deck },                   /* +bind setlayout key! */
	{ "|M|",      centeredmaster },         /* +bind setlayout key! */
	{ "<M>",      centeredfloatingmaster }, /* +bind setlayout key! */
	{ "##V",      gaplessgrid },            /* +bind setlayout key! */
	{ "##H",      horizgrid },              /* +bind setlayout key! */
	{ "[M]",      monocle },
	{ "><>",      NULL },    /* no layout function means floating behavior */
};

/* key definitions */
#define MODKEY Mod4Mask
#define AltMask Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },
#define STACKKEYS(MOD,ACTION) \
	{ MOD, XK_n,                    ACTION##stack,            {.i = INC(+1) } }, \
	{ MOD, XK_e,                    ACTION##stack,            {.i = INC(-1) } }, \
	{ MOD, XK_backslash,            ACTION##stack,            {.i = PREVSEL } }, \
	{ MOD, XK_apostrophe,           ACTION##stack,            {.i = 0 } }, \
	{ MOD, XK_semicolon,            ACTION##stack,            {.i = 1 } }, \
	{ MOD, XK_bracketleft,          ACTION##stack,            {.i = 2 } }, \
	{ MOD, XK_bracketright,         ACTION##stack,            {.i = -1 } },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbordercolor, "-sf", selfgcolor, NULL };
static const char *termcmd[]  = { "st", NULL };

/*First arg only serves to match against key in rules*/
static const char *sp_term[] = {"t", "st", "-t", "scratchpad", NULL};
static const char *sp_calc[] = {"c", "st", "-t", "calc", "-f", "monospace:size=16", "-e", "bc", "-lq", NULL };
static const char *sp_pmdr[] = {"p", "st", "-t", "pomodoro", "-n", "opaque", "-e", "exit0.sh", "rlwrap", "pomodoro", NULL };
static const char *sp_drop[] = {"d", "st", "-t", "drop", "-n", "opaque", NULL };

/* Xresources preferences to load at startup */
ResourcePref resources[] = {
	{ "systraypinning",             INTEGER,   &systraypinning                  },
	{ "systrayspacing",             INTEGER,   &systrayspacing                  },
	{ "systraypinningfailfirst",    INTEGER,   &systraypinningfailfirst         },
	{ "showsystray",                INTEGER,   &showsystray                     },
	{ "statussep",                  STRING,    &statussep                       },
	{ "borderpx",                   INTEGER,   &borderpx                        },
	{ "snap",                       INTEGER,   &snap                            },
	{ "showbar",                    INTEGER,   &showbar                         },
	{ "topbar",                     INTEGER,   &topbar                          },
	{ "dmenufont",                  STRING,    &dmenufont                       },
	{ "normbgcolor",                STRING,    &normbgcolor                     },
	{ "normfgcolor",                STRING,    &normfgcolor                     },
	{ "selbgcolor",                 STRING,    &selbgcolor                      },
	{ "selfgcolor",                 STRING,    &selfgcolor                      },
	{ "normbordercolor",            STRING,    &normbordercolor                 },
	{ "selbordercolor",             STRING,    &selbordercolor                  },
	{ "mfact",                      FLOAT,     &mfact                           },
	{ "nmaster",                    INTEGER,   &nmaster                         },
	{ "resizehints",                INTEGER,   &resizehints                     },
};

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_d,      spawn,          {.v = dmenucmd } },
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY|ShiftMask,             XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_i,      setmfact,       {.f = +0.05} },
	{ MODKEY|AltMask,               XK_h,      setmfact,       {.f = -0.025} },
	{ MODKEY|AltMask,               XK_i,      setmfact,       {.f = +0.025} },
	{ MODKEY|ShiftMask,             XK_h,      incnmaster,     {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_i,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_q,      killclient,     {0} },
	{ MODKEY,                       XK_s,      togglesticky,   {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	{ MODKEY,                       XK_a,      togglealttag,   {0} },
	{ MODKEY|ShiftMask,             XK_a,      nametag,        {0} },
	{ MODKEY,                       XK_f,      togglefullscr,  {0} },
	{ MODKEY|ControlMask,           XK_f,      togglefloating, {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY|ShiftMask,             XK_t,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY|ShiftMask,             XK_d,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_c,      setlayout,      {.v = &layouts[3]} },
	{ MODKEY|ShiftMask,             XK_c,      setlayout,      {.v = &layouts[4]} },
	{ MODKEY,                       XK_v,      setlayout,      {.v = &layouts[5]} },
	{ MODKEY|ShiftMask,             XK_v,      setlayout,      {.v = &layouts[6]} },
	{ MODKEY|ShiftMask,             XK_f,      setlayout,      {.v = &layouts[7]} },
	{ MODKEY|ShiftMask|ControlMask, XK_f,      setlayout,      {.v = &layouts[8]} },
	STACKKEYS(MODKEY,                          focus)
	STACKKEYS(MODKEY|ShiftMask,                push)
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_Escape, quit,           {1} },
	{ MODKEY|ShiftMask|ControlMask, XK_Escape, quit,           {0} },
	{ MODKEY,                       XK_grave,  togglescratch,  {.v = sp_term } },
	{ MODKEY,                       XK_space,  togglescratch,  {.v = sp_drop } },
	{ MODKEY,                       XK_F3,     togglescratch,  {.v = sp_calc } },
	{ MODKEY,                       XK_p,      togglescratch,  {.v = sp_pmdr } },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkStatusText,        0,              Button1,        sigdwmblocks,   {.i = 1} },
	{ ClkStatusText,        0,              Button2,        sigdwmblocks,   {.i = 2} },
	{ ClkStatusText,        0,              Button3,        sigdwmblocks,   {.i = 3} },
	{ ClkStatusText,        0,              Button4,        sigdwmblocks,   {.i = 4} },
	{ ClkStatusText,        0,              Button5,        sigdwmblocks,   {.i = 5} },
	{ ClkStatusText,        ShiftMask,      Button1,        sigdwmblocks,   {.i = 6} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

