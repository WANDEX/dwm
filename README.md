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
- [statusallmons](https://dwm.suckless.org/patches/statusallmons/)
- [statuscmd-signal](https://dwm.suckless.org/patches/statuscmd/)
- [systray](https://dwm.suckless.org/patches/systray/)

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

###### this patch is the reason libxft-bgra is required!
dwm-fix_color_fonts-6.2.diff - support utf-8 colored emoji characters in fonts.

## Installation

You must have `libxft-bgra` installed until the libxft upstream is fixed.\
After making any config changes that you want, but `make`, `sudo make install` it.

## Configuration

After `make` command *config.h* file will be generated, based from *config.def.h*.\
You will definitely need to **remap the keys** because I'm using the colemak, not qwerty layout.\
Edit keyboard keys or default variable values in *config.h*.\
Make a backup of your *config.h* before `make clean`, as by default it removes *config.h* as well.\
`sudo make install` to apply config changes, and press (`super+shift+esc` to restart dwm)

## about .diff patch files included inside patch/ dir

Almost all patches contain changes and are not original, many .diff files are merged because the same parts of the files are being edited.

That is why I have included links to the original patch pages to make it easier to find them.

If you keep the original patching order and apply the command `patch -p1 -f -R` in reverse order to each.\
The files will revert to their original state, without failed hunks.

##### [The order of applying a set of patches - from the first to the last.](https://github.com/WANDEX/dwm/blob/master/patch/active_patch_list)

###### For more details visit official dwm page [dwm.suckless.org](https://dwm.suckless.org/).

