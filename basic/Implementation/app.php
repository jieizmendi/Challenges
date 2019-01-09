<?php
/*****************************************
Title
	War 
Autor
	Juan Eizmendi
*****************************************/

fscanf(STDIN, "%d\n", $T);
while($T--)
{
	fscanf(STDIN, "%d\n", $N);
	$bob = 0;
	fscanf(STDIN, "%s\n", $temp);
	$temp = explode(' ', $temp);
	for ($i=0; $i < $N; $i++)
		if($temp[$i] > $bob) $bob = $temp[$i];
	fscanf(STDIN, "%s\n", $temp);
	$temp = explode(' ', $temp);
	$alice = 0;
	for ($i=0; $i < $N; $i++)
		if($temp[$i] > $alice) $alice = $temp[$i];
	echo "Alice: $alice\n";
	echo "Bob: $bob\n";
	if($bob < $alice) echo "Alice\n";
	if($bob > $alice) echo "Bob\n";
	if($bob == $alice) echo "Tie\n";
}
?>