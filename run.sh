#!/bin/zsh

# function configure_make prevents double configure/make

function configure_make()
{
	if [ ! -f "Makefile" ]; then
		./configure --prefix="$DIR"
		make && make install
	fi
}

if [ ! -d SDL2_libs ]; then
	mkdir SDL2_libs
fi

# install SDL2 basic library

cd SDL2_libs
git clone https://github.com/spurious/SDL-mirror.git SDL2
cd SDL2 || exit
DIR=$(pwd)
configure_make

cd ..

# if not school's Mac, install freetype2 and authomake

if [[ "$OSTYPE" == "linux-gnu" ]]; then
  sudo apt install libfreetype6 libfreetype6-dev
  sudo apt-get install automake
fi

# install SDL_ttf

git clone https://github.com/Ecognize/SDL_ttf.git
cd SDL_ttf || exit

# upgrade timestamps for authoconfig

touch aclocal.m4 Makefile.am configure Makefile.in
export SDL_CONFIG=$DIR/sdl2-config

DIR=`pwd`
configure_make
cd ../..