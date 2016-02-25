EAGLE=eagle

plot: arithmetic/*.egl core/*.egl utils/*.egl
	$(EAGLE) $^ -o $@ -lSDL
