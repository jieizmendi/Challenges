<?php
$key = "SUVOJIT";
$s1 = 0;
$s2 = 0;
$c = 0;
fscanf(STDIN, "%d", $N);

for ($i = 0; $i < $N; $i++) {
    fscanf(STDIN, "%s\n", $line);
    echo "puta";
    $s1 = 0;
    $s2 = 0;
    $c = 0;
    for ($j = 0; $j < strlen($line); $j++) {
        if ($line[$j] == $key[$c]) $c++;
        else {
            if ($c > 6) $s2++;
            if ($c > 3 && $c < 7) $s1++;
            $c = 0;
            $j--;
        }
    }
    
}
?>