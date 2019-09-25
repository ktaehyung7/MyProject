# MyProject

Starting of My Project

<the Game of Life>

1. Usage

Usage: game_of_life <filename> <generation_count>
	-filename: *.txt containing of board configuration and initial values
	-gerneration_count: number of generation by dumping result of "game_of_life" generation finally

example: game_of_life
	 game_of_life plus.txt
	 game_of_life plus.txt 20


you can execute by shell script, see "game_of_life.sh" provided.


2. Release note

version 0.1:
	-add elementary function of "Game of Life"
	-fixed board size (40*80)
	-initial value: plus

version 0.5:
	-add using arguments logic
	-add file reading logic: "plus.txt" 
	-add logic for randomizing board size
	-add "dump()" function to 2-arguments input logic

version 0.9:
	-refactoring: devide module(function)
	-rename function name

version 1.0:
	-add checking arguments exception(generation value is from 0 to 2 billions)
	-delete unused variable declarations
	-perform annotation complement
