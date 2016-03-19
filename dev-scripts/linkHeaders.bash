#! /bin/bash

EXPORTED_HEADERS=exported

if [ -e $EXPORTED_HEADERS ]; then
    while read file
    do
	FirstWord=`echo $file | cut -d" " -f 1`
	if [ "#" != "$FirstWord" ] && [ "" != "$FirstWord" ]; then
	    ln -sf `pwd`/$file $CAS_DIR/include/$file
	fi
    done < $EXPORTED_HEADERS
fi
