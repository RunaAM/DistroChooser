.PHONY: all
all: main

main: out/main.o out/quiz.o 
	g++ out/main.o out/quiz.o -o distrochooser

out/main.o: src/main.cpp
	g++ -c src/main.cpp -o out/main.o

out/quiz.o: src/quiz.cpp src/quiz.h /src/database.txt
	g++ -c src/quiz.cpp -o out/quiz.o

/src/database.txt:
	cp src/database.txt /etc/distrochooserdatabase
.PHONY: clean
clean:
	rm -f out/*.o main

.PHONY:gitpush
gitpush:
	git add . && git commit -m "testing features" && git push -u origin main