#!/bin/bash
rainbowtext=nothing
echo "\033[33;34Type in something and it will be rainbow text."
read rainbowtext
for i in 3 2 1; do echo "\033[33;33Installing \"toilet\" (linux font command) in $i second(s)"; done;
sudo apt install toilet
toilet --gay -f future "$rainbowtext" 
