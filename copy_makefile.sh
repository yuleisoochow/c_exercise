#/bin/bash

dir=`ls -d */ | grep "^[0-9]\{1,\}_" | sed "s/\/$//"`

for i in $dir
do
    cp Makefile.common ./$i/Makefile
done

