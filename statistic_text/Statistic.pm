package Statistic;

use strict;
use warnings;


sub Statistic {
    my %stats;
    for my $sentence (split m/\n/, $_[0]) {
        if (index ($sentence, ',') > -1) {
            for my $word (split /\s+/, $sentence) {
                $stats{$word}++ if length($word) < 5;
            }
        }
    }
    return \%stats;
}


