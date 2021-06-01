#include "layout/bottomstack.c"
#include "layout/centeredmaster.c"
#include "layout/deck.c"
#include "layout/gaplessgrid.c"
#include "layout/horizgrid.c"

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "TTT",      bstack },
	{ "[D]",      deck },
	{ "|M|",      centeredmaster },
	{ "<M>",      centeredfloatingmaster },
	{ "##V",      gaplessgrid },
	{ "##H",      horizgrid },
	{ "[M]",      monocle },
	{ "><>",      NULL },    /* no layout function means floating behavior */
};
