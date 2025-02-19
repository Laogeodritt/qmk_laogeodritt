# Laogeodritt's QMK Keymaps

This repository contains all of Laogeodritt's keymaps for the [QMK keyboard firmware](https://qmk.fm/).

This is an [external userspace repository](https://docs.qmk.fm/newbs_external_userspace)---that is, this repository is not a fork of the [qmk_firmware](https://github.com/qmk/qmk_firmware) repository, but the QMK CLI tool can compile keymaps contained here against the firmware sources.

For more information on the keymaps contained here, please refer to the README files of each keymap (and potentially its source code for more details), linked below.

## List of keymaps

* [Planck QWERTY layout](keyboards/planck/keymaps/arenthil): Based on the default OLKB layout. Optimised for programming, with easy access to punctuation/symbols, and for multilingual users, with AltGr and access to special deadkeys present on Laogeodritt's Polyglot keyboard layout for Windows (TODO: add link).
* [Planck Sibelius layout](keyboards/planck/keymaps/arenthil_sibelius): A dedicated macro layout intended for inputting music with Sibelius, a music notation application. It is intended for use with a full-size or TKL keyboard for text entry and keyboard shortcuts used for other parts of the Sibelius workflow (e.g. editing, formatting, playback).

## I just want to use your keymaps!

Good news! I provide prebuilt binaries over at [Releases](Laogeodritt/qmk_laogeodritt/releases). To flash your keyboard with a compatible keymap:

1. Go to [Releases](Laogeodritt/qmk_laogeodritt/releases), and find the latest release of the keymap you're interested in.
1. Download the `.bin` file corresponding to your keyboard and revision. *If such a corresponding file does not exist, you will probably need to compile it yourself (or even adapt the keymap to work with your keyboard)---sorry it's not quite as straightforward as flashing a binary! See the next section in this case.*
1. Follow the QMK instructions for [flashing your keyboard](https://docs.qmk.fm/newbs_flashing#stm32-arm). This page includes instructions for both Windows and Linux.


## I want to compile your keymaps myself

1. Make sure you've already [set up your QMK environment](https://docs.qmk.fm/newbs_getting_started).
1. Clone this repository to your computer, using the git command-line utility (on Windows, you can use git-bash): `git clone https://github.com/Laogeodritt/qmk_laogeodritt.git`
1. `cd` into the clone's directory: `cd qmk_laogeodritt/`
1. Run the command `qmk userspace-compile` to compile all my keymaps. You can also use `qmk compile -kb <keyboard> -km <keymap>` to compile one specific keymap for one specific keyboard, as normal with QMK. Refer to the [tutorial](https://docs.qmk.fm/newbs_building_firmware) or [command reference](https://docs.qmk.fm/cli_commands) for more information.


## I want to customize your keymap

Please feel free! These keymaps are released under the GNU Public Licence, just like QMK. I cannot promise any support with git or programming for QMK, but if you're familiar or willing to learn it, feel free to play with these keymaps!

QMK has [extensive documentation](https://docs.qmk.fm/newbs) on how to get set up and using it, as well as a Discord community and the /r/OLKB subreddit for community support.


## Resources

* How to use an [external userspace repository](https://docs.qmk.fm/newbs_external_userspace)
* [External userspace template](https://github.com/qmk/qmk_userspace) - You can fork this to make your own external userspace repository. Also includes instructions in its README.
