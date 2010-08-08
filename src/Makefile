FLAGS=-Wall
INCS=-I/usr/include/python2.6 -I/usr/include/GraphicsMagick
OBJS=_main.o _Blob.o _Color.o _Image.o _FilterTypes.o _Geometry.o

all: $(OBJS)

_main.o:
	g++ $(FLAGS) $(INCS) \
		-o _main.o -c _main.cpp

_Blob.o:
	g++ $(FLAGS) $(INCS) \
		-o _Blob.o -c _Blob.cpp

_Color.o:
	g++ $(FLAGS) $(INCS) \
		-o _Color.o -c _Color.cpp

_Image.o:
	g++ $(FLAGS) $(INCS) \
		-o _Image.o -c _Image.cpp

_FilterTypes.o:
	g++ $(FLAGS) $(INCS) \
		-o _FilterTypes.o -c _FilterTypes.cpp

_Geometry.o:
	g++ $(FLAGS) $(INCS) \
		-o _Geometry.o -c _Geometry.cpp
