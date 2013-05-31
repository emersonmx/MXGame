#! /bin/sh

# Call sub-autogens
SUBDIRS=

for dir in $SUBDIRS
do
    cd $dir
    ./autogen.sh
    cd ..
done

# Generates project files autotools.
echo "===== $(pwd)/autogen.sh ====="
mkdir -p m4
set -e
autoreconf --install --force
rm -rf autom4te.cache

