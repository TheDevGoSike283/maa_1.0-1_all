#!/bin/bash
echo "\033[33;34Type in anything and it will be said out loud."
speak=nothing
read speak
for i in 3 2 1; do echo "\033[33;33Installing \"espeak\" in $i second(s)"; sleep 1; done;
espeak "$speak"
