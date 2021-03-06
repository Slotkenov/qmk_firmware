cbbrowne custom keyboard
==============================

Due to cbbrowne@acm.org
Christopher Browne

This was originally based on the default keyboard map, but I have been
doing sundry experimentation:

1. Useful Experiments
----------------------------------------

 * It made sense to mess around some with keyboard maps.
   - I added a keypad, originally based on keymaps/numpad.c, but
     mighty substantially revised, as that one seems to be rotated 90
     degrees from usual conventions for number pads
 * The keypad layer also includes some sample "hacks" of cool things,
   all using actions attached in using the function action_get_macro()
   - Key [1][2] aka "q" types out my name, cbbrowne, as a fun example
     of a key generating a bunch of keystrokes.  The keystroke is
     sufficiently inconvenient that it isn't terribly practical for me
     to use it, but hey, it shows how others might use this facility
     in a more useful context.
   - Key [2][2] aka "a" uses a random number generator to select a digit 0-9 at random
   - Key [3][2] aka "z" uses a random number generator to select a letter a-z at random
   - Key [1][3] aka "e" spits out the keymap version number
  * Trying out sgoodwin's "hold Enter down to get Shift"
    - Liking this Quite Well Enough...
    - Applied this to both Shift and Quote
    - It seems likely that Alt should get a right-hand-side, akin to this...
    - Alt needs to move, and get a RHS
      - Hence ALTRIGHT, and shifted ROT_LED over
      - Emacs likes this!!!  :-)
    - I'm suspicious that I'll want to shift ROT_LED another location over,
      so some modifier can replace the OS/KC_LGUI key
  * I have added an alternate ADJUST layer that is activated via update_tri_layer()
    - e.g. - LOWER+RAISE simultaneously
    - This seems entirely more useful for handling my "special keys"
      like the random numbers, user name, and such, than the keypad layer
  * The _ADJUST layer provides a good place to have RESET
    - But this isn't strictly enough; I want RESET somewhat accessible from
      main layer lest an error hide that layer
    - I never use the OS/KC_LGUI key (that's Command on MacOS, Windows
      Key on Windows), so that's a good place to have it as a chord of
      some sort
        

2. Some code structure ideas
---------------------------------------------------

   Each layer is given a name to aid in readability, which is then
   used in the keymap matrix below.  The underscores do not denote
   anything - you can have a layer called STUFF or any other name.

   Layer names don't all need to be of the same length, obviously, and
   you could also skip them entirely and just use numbers, though that
   means needing to manage the numbers.

   It is preferable to keep the symbols short so that a line worth of
   key mappings fits compactly onto a line of code.  It might be an
   interesting idea to express the maps rotated 90%, so that you
   only need to fit 4 symbols onto each line, rather than 12.

   I used enums to manage layer IDs and macro IDs so that I don't need
   to care (beyond "start at 0", and arguably even that's not needed)
   about their values.

3. Things I did not like about the default mapping
---------------------------------------------------------

   * I found control too hard to get to.  I use it more than Tab, so
     switched it there.
   * Having dash on [lower-j] is a bit nonintuitive, but may be OK
   * I switched ESC/TAB/M(0) around
   * I'm suspicious that I want to shift M(0) from [4][1] to [4][2],
     and shift ESC off the first column so KC_LCTL and KC_LALT can
     be on the first column.
   * I needed to swap ' and ENTER

4. Unuseful experiments
---------------------------------------------------------

I have tried some things out that didn't turn out particularly well.
I'll note some of these for posterity, hopefully helpful in not doing
unwise things again...

   * I tried added Workman alongside Dvorak and Colemak
     - Boy, oh boy, these don't help!!!
     - I have done 30 years of learning of Emacs key mappings, and
       these alternative keyboards massively mess me up

   * Space Cadet Shift; switching L_SHIFT to KC_LSP0, so that when I
     just hit SHIFT, I get a left parens.  In principle, this is great
     for Lisping.
     - Unfortunately, there are times when mouse interfaces use SHIFT
       to allow selecting multiple items, and this really interferes
        with that

5. TODO
---------------------------------------------------------

  * I use tmux quite a lot; the mollat keymap seems to have some
    interesting helpers.  It might be interesting to add a "tmux
    layer," or to have a few keys in a layer oriented towards that
  * The mollat tmux layer also suggests some thoughts about Emacs
    helpers.
  * I do not presently have anything that handles X11 screen
    switching, as with Control-Alt-various
  * I ought to probably look into KC_LEAD, to have some key combos
    that do not need to be concurrent
  * The jeebak keymap seems to have some neat ideas:
    - Number layer which is aggressive about having numbers in several places
    - Touch layer seems interesting
