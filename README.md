# El Ramon Volador 

**Made with <3 by [stdmatt](http://stdmatt.com).**

## Description:

<p align="center">
    <img src="./res/el_ramon_volador.gif"/>
</p>

El Jamon Volador is parody of Flappy Bird to the original Nintendo's Game Boy.

It is my first Game Boy game!

You can play it online [here](http://stdmatt.com/games/el_ramon_volador) 
and download the ROM [here](http://stdmatt.com/games/el_ramon_volador).

<br>

As usual, you are **very welcomed** to **share** and **hack** it.

## Directory structure
- ```game/include``` - The game headers.
- ```game/src``` - The sources
- ```game/third_party``` - GBDK resources to build the game.
- ```html```- Resources / files need to build the game's website.
- ```res``` - Resources used to create the project.

## Building 

```bash 
git clone https://gitlab.com/stdmatt-games/flappy_gb.git
cd flappy_gb

./scripts/build.sh        ## Will generate the ROM on ./build dir.
./scripts/build.sh --html ## Will create the game's website.
./scripts/build.sh --dist ## Will create the games's release package.
```

## Dependencies:

- [GBDK](http://gbdk.sourceforge.net/)


## Thanks to:
I used a lot of free and open resources, for which I'm most grateful!

- [Kenney](https://www.kenney.nl/) - For the backgrounds elements of the website.
- [Raymond Larabie](https://about.me/raylarabie#) - For the __FOO__ font used on the logo.
- [bitnenfer](https://github.com/bitnenfer/FlappyBoy) - For the main inspiration and the background tileset.

## License:

This software is released under [GPLv3](https://www.gnu.org/licenses/gpl-3.0.en.html).


## Others:

There's more FLOSS things at [stdmatt.com](https://stdmatt.com) :)
