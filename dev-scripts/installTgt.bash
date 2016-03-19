#! /bin/bash

TGT=$1
DST=$2

if [ "" != "$DST" ]; then
    cp $TGT $DST
fi
