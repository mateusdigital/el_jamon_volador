# El Jamon Volador

**Made with <3 by [stdmatt](http://stdmatt.com).**

## Description:

<p align="center">
    <img style="border-radius: 10px;" src="./res/readme_game.gif"/>
</p>

El Jamon Volador is homage to Flappy Bird developed for the original Nintendo's Game Boy.

It is my first Game Boy game!

You can [play it online](http://stdmatt.com/games/el_ramon_volador)
and [download the ROM](http://stdmatt.com/games/el_ramon_volador).


The Game Boy frame was developed by me using pure CSS - [give a look](https://mateus.digital/projects/gameboy-css) :)
<br>

As usual, you are **very welcomed** to **share** and **hack** it.



## Directory structure

- ```game/include``` - The game headers.
- ```game/src``` - The sources
- ```game/third_party``` - GBDK resources to build the game.
- ```html```- Resources / files need to build the game's website.
- ```res``` - Resources used to create the project.
- ```scripts``` - Scripts to build the game and website.

## Building

```
    CAVEAT: It just builds on OSX for now - for some reason an invalid rom
    is generated with the gbdk-2020 and in non OSX hosts.
```

```bash
git clone https://github.com/mateus.digital/el_jamon_volador
cd el_jamon_volador

./scripts/build-game.sh   ## Builds the gameboy game, results: ./build/el_jamon_volador-x.y.z.gb
./scripts/build-static.sh ## Builds the landing page, results: ./out/*
```

## Dependencies:

- [GBDK](http://gbdk.sourceforge.net/)  - for building the gameboy game.
- [PollenBoy](https://nectarboy.github.io/gameboy/) - for the website emulator.


## Thanks to:

I used a lot of free and open resources, for which I'm most grateful!

- [Raymond Larabie](https://about.me/raylarabie#) - For the __FOO__ font used on the logo.
- [bitnenfer](https://github.com/bitnenfer/FlappyBoy) - For the main inspiration and the background tileset.

## License:

This software is released under [GPLv3](https://www.gnu.org/licenses/gpl-3.0.en.html).


## Others:

There's more FLOSS things at [mateus.digital](https://mateus.digital) :)
