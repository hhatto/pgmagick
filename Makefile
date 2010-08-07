all:
	g++ -Wall -lboost_python -lGraphicsMagick++ \
		-I/usr/include/python2.6 -I/usr/include/GraphicsMagick \
		-fPIC -shared -o _pgmagick.so \
		_main.cpp _Image.cpp _Geometry.cpp _Color.cpp _FilterTypes.cpp

test:
	python -c "import pgmagick"
	python -c "from pgmagick import *"

profile_pg:
	cd example && python -m cProfile -o test.cprof pgmagick_prof.py
	cd example && pyprof2html test.cprof && mv html html_pg && rm test.cprof

profile_im:
	cd example && python -m cProfile -o test.cprof pythonmagick_prof.py
	cd example && pyprof2html test.cprof && mv html html_im && rm test.cprof

profile_4:
	cd example && sh profile.sh

clean:
	rm _pgmagick.so
