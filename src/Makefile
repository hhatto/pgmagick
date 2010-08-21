FLAGS=-Wall
INCS=-I/usr/include/python2.6 -I/usr/include/GraphicsMagick
OBJS=_main.o _Blob.o _Color.o _CompositeOperator.o _Image.o _FilterTypes.o \
	 _Geometry.o _Montage.o _Pixels.o

all: $(OBJS)

_main.o: _main.cpp
	g++ $(FLAGS) $(INCS) \
		-o _main.o -c _main.cpp

_Blob.o: _Blob.cpp
	g++ $(FLAGS) $(INCS) \
		-o _Blob.o -c _Blob.cpp

_Color.o: _Color.cpp
	g++ $(FLAGS) $(INCS) \
		-o _Color.o -c _Color.cpp

_CompositeOperator.o: _CompositeOperator.cpp
	g++ $(FLAGS) $(INCS) \
		-o _CompositeOperator.o -c _CompositeOperator.cpp

_Image.o: _Image.cpp
	g++ $(FLAGS) $(INCS) \
		-o _Image.o -c _Image.cpp

_FilterTypes.o: _FilterTypes.cpp
	g++ $(FLAGS) $(INCS) \
		-o _FilterTypes.o -c _FilterTypes.cpp

_Geometry.o: _Geometry.cpp
	g++ $(FLAGS) $(INCS) \
		-o _Geometry.o -c _Geometry.cpp

_Montage.o: _Montage.cpp
	g++ $(FLAGS) $(INCS) \
		-o _Montage.o -c _Montage.cpp

_Pixels.o: _Pixels.cpp
	g++ $(FLAGS) $(INCS) \
		-o _Pixels.o -c _Pixels.cpp

clean:
	rm $(OBJS)
