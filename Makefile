TAG = Onegin
HEAD = Onegin
DEP1 = main
DEP2 = GetKeys
DEP3 = Help
DEP4 = GetFileNames
DEP5 = ReadStrings
DEP6 = PrintStrings
DEP7 = SortStrings
DEP8 = FreeStrings
DEPS = $(DEP1).o $(DEP2).o $(DEP3).o $(DEP4).o $(DEP5).o $(DEP6).o $(DEP7).o $(DEP8).o

$(TAG): $(DEPS)
	gcc -g -Wall $^ -o $@

%.o: %.c $(HEAD).h
	gcc -c $<

clean:
	rm -f $(DEPS)
