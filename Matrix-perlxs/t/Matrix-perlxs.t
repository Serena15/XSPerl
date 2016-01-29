# Before 'make install' is performed this script should be runnable with
# 'make test'. After 'make install' it should work as 'perl Matrix-perlxs.t'

#########################

# change 'tests => 1' to 'tests => last_test_to_print';

use strict;
use warnings;

use Test::More tests => 1;
BEGIN { use_ok('Matrix::perlxs') };

my @Amatr = ();
my @Bmatr = ();
my $n = 5;

open(my $infile1, '<', "matr1.txt") or die $!;

while(<$infile1>) {
	my @lines = split(/:/, $_);
	push @Amatr, \@lines;
}
close $infile1;

open(my $infile2, '<', "matr2.txt") or die $!;
while(<$infile2>) {
	my @lines = split(/:/, $_);
	push @Bmatr, \@lines;
}
close $infile2;
my $res = Matrix::perlxs::multiply_matrix(@Amatr,@Bmatr);
print "res = $res\n";
#########################

# Insert your test code below, the Test::More module is use()ed here so read
# its man page ( perldoc Test::More ) for help writing this test script.

