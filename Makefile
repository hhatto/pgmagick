LIBS=-lboost_python -lGraphicsMagick++
SRC_DIR=src

all:
	cd $(SRC_DIR) && make
	g++ $(LIBS) \
		-fPIC -shared -o pgmagick/_pgmagick.so $(SRC_DIR)/*.o


TEST_DIR=test
.PHONY: test
test:
	python $(TEST_DIR)/test_pgmagick_blob.py
	python $(TEST_DIR)/test_pgmagick_color.py
	python $(TEST_DIR)/test_pgmagick_image.py
	python $(TEST_DIR)/test_pgmagick_geometry.py
	python $(TEST_DIR)/test_pgmagick_montage.py

profile_pg:
	cd example && python -m cProfile -o test.cprof pgmagick_prof.py
	cd example && pyprof2html test.cprof && mv html html_pg && rm test.cprof

profile_im:
	cd example && python -m cProfile -o test.cprof pythonmagick_prof.py
	cd example && pyprof2html test.cprof && mv html html_im && rm test.cprof

profile_4:
	cd example && sh profile.sh

pypireg:
	python setup.py register
	python setup.py sdist upload

clean:
	rm -rf pgmagick.* build dist
	rm pgmagick/_pgmagick.so
	rm pgmagick/*.pyc
	cd $(SRC_DIR) && make clean
