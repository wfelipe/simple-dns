use Net::DNS;

my $res   = Net::DNS::Resolver->new (
	nameservers => [qw( 127.0.0.1 )],
	recurse => 0,
	debug => 1,
	port => 5555,
);
my $query = $res->search("host.example.com");

if ($query) {
	foreach my $rr ($query->answer) {
		next unless $rr->type eq "A";
			print $rr->address, "\n";
	}
} else {
   	warn "query failed: ", $res->errorstring, "\n";
}

