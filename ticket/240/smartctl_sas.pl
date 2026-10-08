my $i=98;
my $counter=1;
my @serial;
for ($i=98; $i<123; $i++) {
	$counter=1;
	system "smartctl.exe -a sd".chr($i)." >>temp.txt";
	if (open(temp, "temp.txt")) {
		while ( my $line = <temp> ) {
			if ($counter == 10) {
				@serial = split( / / , $line ); 
				chomp(@serial);
				print "Serial: ".$serial[9]."\n";
				last;
			}
			else {
				$counter++;
			}
		}
		if ($counter < 10) {
			print "No drive found.\n";
		}
		else {
			#print $serial[7]."/".$serial[8]."/".$serial[9]."/".$serial[10]."/".$serial[11]."/".$serial[12]."/".$serial[13]."/".$serial[14]."/".$serila[15]."\n";
			system "copy temp.txt ".$serial[9].".txt";;
		}
		close(temp);
		system "del temp.txt";
	}
	else {
		print "Invalid command.\n"
	}
	
	
}