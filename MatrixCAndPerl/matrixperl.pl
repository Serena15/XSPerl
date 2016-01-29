use strict;
use warnings;

use DDP;
use Time::HiRes qw(gettimeofday tv_interval);


my @Amatr = ();
my @Bmatr = ();
my @Resmatr = ();
my $n = 5;

open(my $infile1, '<', "matr1.txt") or die $!;

while(<$infile1>) {
	my @lines = split(/:/, $_);
	push @Amatr, \@lines;
}
#p @Amatr;
close $infile1;

open(my $infile2, '<', "matr2.txt") or die $!;
while(<$infile2>) {
	my @lines = split(/:/, $_);
	push @Bmatr, \@lines;
}
#p @Bmatr;
close $infile2;

#p @{$Amatr[$n-1]}[$n-1];
my $start_time = [ gettimeofday ];
for my $i(0..($n-1)) {
        for my $j(0..($n-1)) {
		for my $k(0..($n-1)) {
			@{$Resmatr[$i]}[$j] += (@{$Amatr[$i]}[$k])*(@{$Bmatr[$k]}[$j]);
		}
        }
}
my $end_time = [ gettimeofday ];
print "Result matrix :\n";

for my $i(0..($n-1)) {
        for my $j(0..($n-1)) {
		print " @{$Resmatr[$i]}[$j] ";
	}
	print $/;
}

my $elapsed = tv_interval($start_time,$end_time);

print "Время исполнения кода в милисекундах:\n";
print $elapsed, $/;

#p $Resmatr[0];
#p @Resmatr;



