my $i=98;
my $counter=1;
my @serial;
for ($i=98; $i<123; $i++) {
	$counter=1;
	system "smartctl.exe -a sd".chr($i)." -d sat >>temp.txt";
	if (open(temp, "temp.txt")) {
		while ( my $line = <temp> ) {
			if ($counter == 6) {
				@serial = split( / / , $line ); 
				chomp(@serial);
				print "Serial: ".$serial[5]."\n";
				last;
			}
			else {
				$counter++;
			}
		}
		if ($counter < 6) {
			print "No drive found.\n";
		}
		else {
			system "copy temp.txt ".$serial[5].".txt";;
		}
		close(temp);
		system "del temp.txt";
	}
	else {
		print "No drive found.\n"
	}
	
	
}