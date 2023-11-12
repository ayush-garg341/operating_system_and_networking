FLAGS = -Wall -pthread -g

all: main_race main_deadlock main_deadlock_global main_signal main_signal_cv

clean: rm -f main_race main_deadlock main_deadlock_global main_signal main_signal_cv

main_race: main_race.c mythreads.h
	gcc -o main_race main_race.c ${FLAGS}


main_deadlock : main_deadlock.c mythreads.h
	gcc -o main_deadlock main_deadlock.c ${FLAGS}


main_deadlock_global: main_deadlock_global.c mythreads.h
	gcc -o main_deadlock_global main_deadlock_global.c ${FLAGS}


main_signal: main_signal.c mythreads.h
	gcc -o main_signal main_signal.c ${FLAGS}


main_signal_cv: main_signal_cv.c mythreads.h
	gcc -o main_signal_cv main_signal_cv.c ${FLAGS}

