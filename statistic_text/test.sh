cc -o statist main.c decodebase64.c `perl -MExtUtils::Embed -e ccopts -e ldopts` -std=c99 -ggdb
./statist  Statistic.pm ./
rm -r statist*

