OBJS=main.o eof_tools.o
EXEC=vbrand
CXXFLAGS=-D THE_BRAND='"$(brand)"'

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
	rm -f *.o $(EXEC) video.test

video.test.original:
	wget $(TEST_VIDEO_FILE_SOURCE) -O video.test.original

video.test: video.test.original
	@cp video.test.original video.test

test: test_speed test_correctness
	@tput setaf 2
	@echo
	@echo Passed all tests!
	@tput sgr0

test_speed: $(EXEC)
	rm video.test && make video.test
	if ! timeout 1 ./$(EXEC) video.test; then \
		echo Took too long to actually brand; \
		exit 1; \
	fi
	if ! timeout 1 ./$(EXEC) video.test; then \
		echo Took too long to run vbrand on an already branded file; \
		exit 1; \
	fi

test_correctness: $(EXEC)
	rm video.test && make video.test
	if [[ "`$(EXEC) video.test`" != "Added brand to video.test" ]] ; then \
		echo vbrand did not brand an unbranded file; \
		exit 1; \
	fi
	if [[ "`$(EXEC) video.test`" != "Already branded video.test" ]] ; then \
		echo vbrand rebranded a branded file; \
		exit 1; \
	fi
