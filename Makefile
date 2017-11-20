LIBS=-lboost_python -lGraphicsMagick++
SRC_DIR=src

all:
	cd $(SRC_DIR) && make
	cp -p src/*.so pgmagick/

fastbuild:
	cd $(SRC_DIR) && make CC="ccache g++"
	cp -p src/*.so pgmagick/

TEST_DIR=test
.PHONY: test
test:
	cd $(TEST_DIR) && make

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

build_bdist_wheel:
	# NOTE: only available in my environment
	workon py363
	python setup.py bdist_wheel
	workon py2714
	pip install --upgrade pip
	python setup.py bdist_wheel

clean:
	rm -rf pgmagick.* build dist temp
	cd $(SRC_DIR) && make clean
	rm -rf pgmagick/_pgmagick.so
	rm -rf pgmagick/*.pyc
	rm -rf test/*.png test/*.jpg
