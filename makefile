make:
	gcc game.c game.h ai.c battle.c init.c misc.c typeeffect.c -o battlegame

clean:
	rm ./battlegame