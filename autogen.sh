#! /bin/sh

SUBDIRS=

for dir in $SUBDIRS
do
    cd $dir
    ./autogen.sh bare
    cd ..
done

if [ $# == 0 ]
then
    mkdir -p m4
    set -e
    autoreconf --install --force
    rm -rf autom4te.cache
else
    if [ $1 == "bare" ]
    then
        mkdir -p m4
        rm -rf autom4te.cache
    else
        echo "Usage: $0 [bare]"
    fi
fi



