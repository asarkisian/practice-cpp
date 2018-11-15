#---------------------------------------
# makefile

# options

# compiler
	CC = gcc

# compiler options
	COPS = -W -Wall -ansi -O3

# linker
	LINK = gcc

# libraries
	LIB = -lstdc++

# header files
	HS = poker.h blackjack.h game.h headers.h

# obj files
	OBJS = poker.o main.o domain.o showscreen.o quit.o displaygrid.o displaytitle.o clearscreen.o checkonepair.o checktwopair.o checkthreeofakind.o checkstraight.o checkflush.o checkfullhouse.o checkfourofakind.o checkstraightflush.o checkroyalflush.o checkpattern.o countvalues.o dealcards.o clearhands.o discardcards.o selectwinner.o calcplayermoney.o placewager.o getplayersname.o game.o blackjack.o displaymenu.o

# executable
casino: $(OBJS)
	$(LINK) $(OBJS) $(LIB) -o casino

# objs
poker.o: poker.cpp $(HS)
	$(CC) $(COPS) -c poker.cpp

main.o: main.cpp $(HS)
	$(CC) $(COPS) -c main.cpp

domain.o: domain.cpp $(HS)
	$(CC) $(COPS) -c domain.cpp

showscreen.o: showscreen.cpp $(HS)
	$(CC) $(COPS) -c showscreen.cpp

quit.o: quit.cpp $(HS)
	$(CC) $(COPS) -c quit.cpp

displaygrid.o: displaygrid.cpp $(HS)
	$(CC) $(COPS) -c displaygrid.cpp

displaytitle.o: displaytitle.cpp $(HS)
	$(CC) $(COPS) -c displaytitle.cpp

clearscreen.o: clearscreen.cpp $(HS)
	$(CC) $(COPS) -c clearscreen.cpp

checkonepair.o: checkonepair.cpp $(HS)
	$(CC) $(COPS) -c checkonepair.cpp

checktwopair.o: checktwopair.cpp $(HS)
	$(CC) $(COPS) -c checktwopair.cpp

checkthreeofakind.o: checkthreeofakind.cpp $(HS)
	$(CC) $(COPS) -c checkthreeofakind.cpp

checkstraight.o: checkstraight.cpp $(HS)
	$(CC) $(COPS) -c checkstraight.cpp

checkflush.o: checkflush.cpp $(HS)
	$(CC) $(COPS) -c checkflush.cpp

checkfullhouse.o: checkfullhouse.cpp $(HS)
	$(CC) $(COPS) -c checkfullhouse.cpp

checkfourofakind.o: checkfourofakind.cpp $(HS)
	$(CC) $(COPS) -c checkfourofakind.cpp

checkstraightflush.o: checkstraightflush.cpp $(HS)
	$(CC) $(COPS) -c checkstraightflush.cpp

checkroyalflush.o: checkroyalflush.cpp $(HS)
	$(CC) $(COPS) -c checkroyalflush.cpp

checkpattern.o: checkpattern.cpp $(HS)
	$(CC) $(COPS) -c checkpattern.cpp

countvalues.o: countvalues.cpp $(HS)
	$(CC) $(COPS) -c countvalues.cpp

dealcards.o: dealcards.cpp $(HS)
	$(CC) $(COPS) -c dealcards.cpp

clearhands.o: clearhands.cpp $(HS)
	$(CC) $(COPS) -c clearhands.cpp

discardcards.o: discardcards.cpp $(HS)
	$(CC) $(COPS) -c discardcards.cpp

selectwinner.o: selectwinner.cpp $(HS)
	$(CC) $(COPS) -c selectwinner.cpp

calcplayermoney.o: calcplayermoney.cpp $(HS)
	$(CC) $(COPS) -c calcplayermoney.cpp

placewager.o: placewager.cpp $(HS)
	$(CC) $(COPS) -c placewager.cpp

getplayersname.o: getplayersname.cpp $(HS)
	$(CC) $(COPS) -c getplayersname.cpp

blackjack.o: blackjack.cpp $(HS)
	$(CC) $(COPS) -c blackjack.cpp

game.o: game.cpp $(HS)
	$(CC) $(COPS) -c game.cpp

displaymenu.o: displaymenu.cpp $(HS)
	$(CC) $(COPS) -c displaymenu.cpp

clean:
	-rm *.o casino

e:
	./casino
