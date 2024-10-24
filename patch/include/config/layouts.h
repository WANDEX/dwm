#pragma once

#include "layout/bottomstack.h"
#include "layout/centeredmaster.h"
#include "layout/deck.h"
#include "layout/gaplessgrid.h"
#include "layout/horizgrid.h"


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
