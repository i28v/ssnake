simple snake game for the linux terminal that i made because every other snake game on github wasn't that good

use vim hjkl to move

settings are configured in config.h

if config.h does not exist yet, make will automaticlaly copy it from config.def.h

compile using make and install using make install (as root)

default installation path is /usr/local/bin but that can be changed in the makefile

no highscore saving but it might be implemented later

features i plan on implementing later:

food checking to make sure it doesn't respawn on the snake

highscore file which it's location can be configured in config.h

optionally multiple food pieces on the map

optionally a speed boost of movement key is held down for traversing a large map

