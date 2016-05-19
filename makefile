CXX=g++
CPPFLAGS=-lfreeimage -lfreetype -I/usr/include/freetype2 

OBJS=main.o ImageReader.o ImageBuilder.o ImagePNG.o ImageJPEG.o

conv: $(OBJS)
	$(CXX) $^ -o $@

$(OBJS): %.o : %.cpp
	$(CXX) -c $(CPPFLAGS) $< -o $@ 



all: conv

clean:
	rm -f *.o
