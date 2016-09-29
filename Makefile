CC ?= gcc
CFLAGS_common ?= -Wall -std=gnu99
CFLAGS_orig = -O0
CFLAGS_opt  = -O0

EXEC = phonebook_orig phonebook_struct phonebook_hash
all: $(EXEC)

SRCS_common = main.c

phonebook_orig: $(SRCS_common) phonebook_orig.c phonebook_orig.h
	$(CC) $(CFLAGS_common) $(CFLAGS_orig) \
		-DIMPL="\"$@.h\"" -o $@ \
		$(SRCS_common) $@.c

phonebook_struct: $(SRCS_common) phonebook_struct.c phonebook_struct.h
	$(CC) $(CFLAGS_common) $(CFLAGS_opt) \
		-DIMPL="\"$@.h\"" -o $@ \
		-DSTRUCT="1" \
		$(SRCS_common) $@.c

phonebook_hash: $(SRCS_common) phonebook_hash.c phonebook_hash.h
	$(CC) $(CFLAGS_common) $(CFLAGS_opt) \
		-DIMPL="\"$@.h\"" -o $@ \
		-DHASH="1" \
		$(SRCS_common) $@.c

phonebook_smaz: $(SRCS_common)  smaz.c smaz.h phonebook_smaz.c phonebook_smaz.h
	$(CC) $(CFLAGS_common) $(CFLAGS_opt) \
		-DIMPL="\"$@.h\"" -o $@ \
		-DSMAZ="1" \
	$(SRCS_common) $@.c smaz.c


run: $(EXEC)
	echo 3 | sudo tee /proc/sys/vm/drop_caches
	watch -d -t "./phonebook_orig && echo 3 | sudo tee /proc/sys/vm/drop_caches"

cache-test: $(EXEC)
	perf stat --repeat 100 \
		-e cache-misses,cache-references,instructions,cycles \
		./phonebook_orig
	perf stat --repeat 100 \
		-e cache-misses,cache-references,instructions,cycles \
		./phonebook_struct
	perf stat --repeat 100 \
                -e cache-misses,cache-references,instructions,cycles \
                ./phonebook_hash
	perf stat --repeat 100 \
                -e cache-misses,cache-references,instructions,cycles \
                ./phonebook_smaz


output.txt: cache-test calculate
	./calculate

plot: output.txt
	gnuplot scripts/runtime.gp

calculate: calculate.c
	$(CC) $(CFLAGS_common) $^ -o $@

.PHONY: clean
clean:
	$(RM) $(EXEC) *.o perf.* \
	      	calculate orig.txt struct.txt output.txt runtime.png hash.txt smaz.txt
