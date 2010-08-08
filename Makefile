LIBS=-lboost_python -lGraphicsMagick++
SRC_DIR=src

all:
	cd $(SRC_DIR) && make
	g++ $(LIBS) \
		-fPIC -shared -o _pgmagick.so $(SRC_DIR)/*.o


TEST_DIR=test
.PHONY: test
test:
	python -c "import pgmagick"
	python -c "from pgmagick import *"
	python $(TEST_DIR)/test_pgmagick_blob.py
	python $(TEST_DIR)/test_pgmagick_color.py

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
	rm $(SRC_DIR)/*.o
