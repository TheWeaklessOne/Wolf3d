#!/bin/zsh

# function configure_make prevents double configure/make

function configure_make()
{
	if [ ! -f "Makefile" ]; then
		./configure --prefix="$DIR"
		make && make install
	fi
}

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

# upgrade timestamps for authoconfig

touch aclocal.m4 Makefile.am configure Makefile.in
export SDL_CONFIG=$DIR/sdl2-config

DIR=`pwd`
configure_make
cd ../..
