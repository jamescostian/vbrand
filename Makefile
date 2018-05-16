OBJS=main.o eof_tools.o
EXEC=vbrand
CXXFLAGS=-D THE_BRAND='"$(brand)"'

all: $(OBJS) $(EXEC)

eof_tools.o: eof_tools.cc eof_tools.h
	$(CXX) $(CXXFLAGS) -c eof_tools.cc

main.o: main.cc eof_tools.h
	$(CXX) $(CXXFLAGS) -c main.cc

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o vbrand

clean:
	rm -f *.o $(EXEC)
