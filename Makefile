OBJS=main.o eof_tools.o
EXEC=vbrand
CXXFLAGS=-std=c++11 -D THE_BRAND='"$(brand)"'

brand?=I am lazy and did not see how to change the brand in the README, so I will use the default one

TEST_VIDEO_FILE_SOURCE=http://jell.yfish.us/media/jellyfish-400-mbps-4k-uhd-hevc-10bit.mkv


all: $(EXEC)

eof_tools.o: eof_tools.cc eof_tools.h
	$(CXX) $(CXXFLAGS) -c eof_tools.cc

main.o: main.cc eof_tools.h
	$(CXX) $(CXXFLAGS) -c main.cc

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o vbrand

clean:
	rm -f *.o $(EXEC) tests/video.test

tests/video.test.original:
	wget $(TEST_VIDEO_FILE_SOURCE) -O tests/video.test.original

tests/video.test: tests/video.test.original
	cp tests/video.test.original tests/video.test

test: $(EXEC) tests/video.test.original
	tests/run
