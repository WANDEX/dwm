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
	{ MODKEY|ShiftMask,             XK_Escape, quit,           {1} },
	{ MODKEY|ShiftMask|ControlMask, XK_Escape, quit,           {0} },
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
	{ MODKEY,                       XK_F3,     togglescratch,  {.v = sp_calc } },
	{ MODKEY|ShiftMask,             XK_m,      togglescratch,  {.v = sp_muse } },
	{ MODKEY,                       XK_p,      togglescratch,  {.v = sp_pmdr } },
	{ MODKEY,                       XK_space,  togglescratch,  {.v = sp_drop } },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button1,        sigdwmblocks,   {.i = 1} },
	{ ClkStatusText,        0,              Button2,        sigdwmblocks,   {.i = 2} },
	{ ClkStatusText,        0,              Button3,        sigdwmblocks,   {.i = 3} },
	{ ClkStatusText,        0,              Button4,        sigdwmblocks,   {.i = 4} },
	{ ClkStatusText,        0,              Button5,        sigdwmblocks,   {.i = 5} },
	{ ClkStatusText,        ShiftMask,      Button1,        sigdwmblocks,   {.i = 6} },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
