![](dwm.png)
###### patch set compatible with dwm-6.2 (20190203)

## Extra stuff added to vanilla dwm:

##### additional layouts
- [bottomstack (*without bstackhoriz*)](https://dwm.suckless.org/patches/bottomstack/) `super+T`
- [centeredmaster](https://dwm.suckless.org/patches/centeredmaster/) `super+c, super+C`
- [deck](https://dwm.suckless.org/patches/deck/) `super+D`
- [gaplessgrid](https://dwm.suckless.org/patches/gaplessgrid/) `super+v`
- [horizgrid](https://dwm.suckless.org/patches/horizgrid/) `super+V`

##### tag
- [alternativetags](https://dwm.suckless.org/patches/alternativetags/) `super+a`
- [hide_vacant_tags](https://dwm.suckless.org/patches/hide_vacant_tags/)
- [nametag-prepend](https://dwm.suckless.org/patches/nametag/) `super+A`
- [pertag-perseltag](https://dwm.suckless.org/patches/pertag/)

##### bar
- [extrabar](https://dwm.suckless.org/patches/extrabar/)
- [status2d(*extrabar, xresources, swap-save-restore*)](https://dwm.suckless.org/patches/status2d/)
- [statusallmons](https://dwm.suckless.org/patches/statusallmons/)
- [statuscmd-signal(*dwmblocks, status2d*)](https://dwm.suckless.org/patches/statuscmd/)
- [systray](https://dwm.suckless.org/patches/systray/)
- toggleextrabar

##### other
- [actualfullscreen](https://dwm.suckless.org/patches/actualfullscreen/) `super+f`
- [fixborders (*remove transparancy in window borders*)](https://dwm.suckless.org/patches/alpha/)
- [floatrules](https://dwm.suckless.org/patches/floatrules/)
- [namedscratchpads](https://dwm.suckless.org/patches/namedscratchpads/)
- [noborder_floatingfix](https://dwm.suckless.org/patches/noborder/)
- [restartsig](https://dwm.suckless.org/patches/restartsig/) `super+shift+esc, super+ctrl+shift+esc`
- [stacker](https://dwm.suckless.org/patches/stacker/)
- [sticky](https://dwm.suckless.org/patches/sticky/) `super+s`
- [warp](https://dwm.suckless.org/patches/warp/)
- [xresources](https://dwm.suckless.org/patches/xresources/)

###### this patch is the reason `libxft-bgra` is required!
dwm-fix_color_fonts-6.2.diff - support utf-8 colored emoji characters in fonts.

## Installation

After making any config changes that you want, but `make`, `sudo make install` it.

###### You must have `libxft-bgra` installed until the libxft upstream is fixed.

This build of dwm does not block color emoji in the status/info bar, so you must install [libxft-bgra](https://aur.archlinux.org/packages/libxft-bgra/) from the AUR, which fixes a libxft color emoji rendering problem, otherwise dwm will crash upon trying to render one. Hopefully this fix will be in all libxft soon enough.

## Configuration

After `make` command *config.h* file will be generated, based from *config.def.h*.\
You will definitely need to **remap the keys** because I'm using the colemak, not qwerty layout.\
Edit default variable values in *config.h*.

Make a backup of your *config.h* before `make clean`, as by default it removes *config.h* as well.\
`sudo make install` to apply config changes, and press (`super+shift+esc` to restart dwm)

#### About configuration structure

`patch/`-- all dirs except `patch/include/` dir, contain **.diff** files.\
`patch/include/`--  there is some patch specific **.[c|h]** files with recognizable patch name.\
`patch/include/config/`-- parts of config code. So, if you want to edit keyboard keys - edit them in **keys.h** etc.

**include.[c|h]** -- includes all separate patch specific files. Those files contain separate patch specific functions.
**include.c & include.h** -- the files themselves are the only files that is included inside **dwm.c**.

This makes **dwm.c** more readable, and **.diff** files contain only changes that directly affect the main code.

## About .diff patch files included inside patch/ dir

Almost all patches contain changes and are not original, many **.diff** files are merged because the same parts of the files were been affected.

That is why I have included links to the original patch pages to make it easier to find them.

If you keep the original patching order and apply the command `patch -p1 -f -R` in reverse order to each.\
The files will revert to their original state, without failed hunks.

Do not forget to remove from **include.c & include.h** patch specific files for patches that you are reversed,\
and update config files in `patch/include/config/`, as they are not affected by the **.diff** files.

##### [The order of applying a set of patches - from the first to the last.](https://github.com/WANDEX/dwm/blob/master/patch/active_patch_list)

###### For more details visit official dwm page [dwm.suckless.org](https://dwm.suckless.org/).

