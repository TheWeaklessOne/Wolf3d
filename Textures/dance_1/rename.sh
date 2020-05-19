#!/bin/bash

a=1
  for f in "$@"; do
    mv -- "$f" "flex_${a}.png"
    let "a += 1"
  done
