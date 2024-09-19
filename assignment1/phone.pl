#prompt the user to enter any portion of a person's name
print "Enter a portion of a name: ";
$name_to_search=<STDIN>;
print "\n";

#remove the line break caused by the user's input
chomp($name_to_search);

#read the file phones and append it to an array
$FILE="phones";
open (FILE);
@array=<FILE>;
close (FILE);

#initialize counter to keep track of matches
$name_found=0;

#iterate through the array, if a match is found print the line and increment the counter
foreach $line (@array) {
	if ($line =~ /$name_to_search/) {
		print "$line \n";
		$name_found=$name_found+1;
	}
}

# if the name is not found, print this to the user
if ($name_found==0) {
	print "$name_to_search NOT found in the phone directory file! \n";
}

