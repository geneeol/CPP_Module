DIRS = $(wildcard module0*/ex*)

all:
	for dir in $(DIRS); do \
		make -j4 -C $$dir all; \
	done

clean:
	for dir in $(DIRS); do \
		make -j4 -C $$dir clean; \
	done

fclean:
	for dir in $(DIRS); do \
		make -j4 -C $$dir fclean; \
	done

re:
	make fclean
	make all

.PHONY: all clean fclean