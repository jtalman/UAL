#!/usr/local/bin/perl

# Convert NikolayOut file to fort.8 file 
# by suppressing unused columns

# perl perl/IGtoFort.8.pl IG >! out/fort.8

$, = ' ';		# set output field separator
$\ = "\n";		# set output record separator

while (<>) {
    chop;	# strip record separator
    $LineTemp = $_;
    @Fld = split(' ', $LineTemp, 9999);
    print $Fld[1], $Fld[3], $Fld[4], $Fld[5], $Fld[6], $Fld[7], $Fld[8];
}

