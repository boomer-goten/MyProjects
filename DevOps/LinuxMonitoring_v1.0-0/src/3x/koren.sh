#!/bin/bash
SPACE_ROOT=$(df -Th -k / | grep dev | xargs | cut -d " " -f 3 | cut -d "M" -f 1)
SPACE_ROOT_USED=$(df -Th -k / | grep dev | xargs | cut -d " " -f 4 | cut -d "M" -f 1)
SPACE_ROOT_FREE=$(df -Th -k / | grep dev | xargs | cut -d " " -f 5 | cut -d "M" -f 1)
if [ $SPACE_ROOT -ge 1024 ]
then
SPACE_ROOT=$(bc<<<"scale=2;$SPACE_ROOT/1024")
echo -e "${TEXT[$1]}${BACKGROUND[$2]}SPACE_ROOT${NORMAL[0]} = ${TEXT[$3]}${BACKGROUND[$4]}$SPACE_ROOT MB${NORMAL[0]}"
else
SPACE_ROOT=$(bc<<<"scale=3;$SPACE_ROOT/1024")
echo -e "${TEXT[$1]}${BACKGROUND[$2]}SPACE_ROOT${NORMAL[0]} = ${TEXT[$3]}${BACKGROUND[$4]}0$SPACE_ROOT MB${NORMAL[0]}"
fi
if [ $SPACE_ROOT_USED -ge 1024 ]
then
SPACE_ROOT_USED=$(bc<<<"scale=2;$SPACE_ROOT_USED/1024")
echo -e "${TEXT[$1]}${BACKGROUND[$2]}SPACE_ROOT_USED${NORMAL[0]} = ${TEXT[$3]}${BACKGROUND[$4]}$SPACE_ROOT_USED MB${NORMAL[0]}"
else
SPACE_ROOT_USED=$(bc<<<"scale=3;$SPACE_ROOT_USED/1024")
echo -e "${TEXT[$1]}${BACKGROUND[$2]}SPACE_ROOT_USED${NORMAL[0]} = ${TEXT[$3]}${BACKGROUND[$4]}0$SPACE_ROOT_USED MB${NORMAL[0]}"
fi
if [ $SPACE_ROOT_FREE -ge 1024 ]
then
SPACE_ROOT_FREE=$(bc<<<"scale=2;$SPACE_ROOT_FREE/1024")
echo -e "${TEXT[$1]}${BACKGROUND[$2]}SPACE_ROOT_FREE${NORMAL[0]} = ${TEXT[$3]}${BACKGROUND[$4]}$SPACE_ROOT_FREE MB${NORMAL[0]}"
else
SPACE_ROOT_FREE=$(bc<<<"scale=3;$SPACE_ROOT_FREE/1024")
echo -e "${TEXT[$1]}${BACKGROUND[$2]}SPACE_ROOT_FREE${NORMAL[0]} = ${TEXT[$3]}${BACKGROUND[$4]}0$SPACE_ROOT_FREE MB${NORMAL[0]}"
fi