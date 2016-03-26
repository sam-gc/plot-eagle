EAGLE=eagle
CC=gcc

emcalc: utils/necessary_evil.o arithmetic/*.egl core/*.egl utils/*.egl
	$(EAGLE) $^ -o $@ -lSDL -lSDL_ttf -lm --verbose

utils/necessary_evil.o: utils/necessary_evil.c
	$(CC) $^ -o $@ -c

clean:
	rm -f plot
	rm -f utils/necessary_evil.o

