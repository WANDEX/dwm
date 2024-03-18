/* See LICENSE file for copyright and license details. */

/* systray */
static unsigned int systraypinning  = 2;    /* 0: follows selected monitor, >0: pin systray to monitor X */
static unsigned int systrayonleft   = 0;    /* 0: systray in the right corner, >0: left of status text */
static unsigned int systrayspacing  = 0;    /* systray spacing */
static int systraypinningfailfirst  = 1;    /* if pinning fails, 1: display on first monitor, 0: last */
static int showsystray              = 1;    /* 0 means no systray */

/* bar */
static char statussep               = ';';  /* separator between status bars */
static int ebalign                  = 1;    /* extrabar alignment: 0 - left, 1 - right, 2 - center */
static int extrabarmon              = 0;    /* extrabar monitor number: -1 - all monitors */
static int showextrabar             = 1;    /* 0 means no bar */

/* appearance */
static unsigned int borderpx        = 2;    /* border pixel of windows */
static unsigned int snap            = 2;    /* snap pixel */
static int showbar                  = 1;    /* 0 means no bar */
static int topbar                   = 1;    /* 0 means bottom bar */
static char dmenufont[]             = "NotoMono Nerd Font:size=8";
static const char *fonts[] = {
       dmenufont,
       "monospace:size=8",
       "JoyPixels:pixelsize=8:antialias=true:autohint=true",
       "FontAwesome:pixelsize=8",
};
static char normbgcolor[]           = "#3E494C";
static char normfgcolor[]           = "#E0E5E6";
static char selfgcolor[]            = "#32393A";
static char selbgcolor[]            = "#97A6AA";
static char normbordercolor[]       = "#32393A";
static char selbordercolor[]        = "#97A6AA";
#include "patch/include/config/termcolors.h"
static char *colors[][ColCount] = {
       /*               fg           bg           border   */
       [SchemeNorm] = { normfgcolor, normbgcolor, normbordercolor },
       [SchemeSel]  = { selfgcolor,  selbgcolor,  selbordercolor  },
};

/* tagging */
#define MAX_TAGNAME_LEN 14             /* excludes TAG_PREPEND */
#define TAG_PREPEND "%1i:"             /* format */
#define MAX_TAGLEN 16                  /* altogether */
static char tags[][MAX_TAGLEN] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };
static char *tagsalt[] = { "1:", "2:", "3:", "4:", "5:", "6:", "7:", "8:", "9:" };

#include "patch/include/config/rules.h"

/* layout(s) */
static float mfact     = 0.5;   /* factor of master area size [0.05..0.95] */
static int nmaster     = 1;     /* number of clients in master area */
static int resizehints = 1;     /* 1 means respect size hints in tiled resizals */

#include "patch/include/config/layouts.h"

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbordercolor, "-sf", selfgcolor, NULL };
static const char *termcmd[]  = { "st", NULL };

/* Xresources preferences to load at startup */
#include "patch/include/config/xresources.h"

/* Keys */
#include "patch/include/config/keys.h"
