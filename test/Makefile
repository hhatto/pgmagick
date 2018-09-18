all: cookbook blob color image geometry montage api

PYTHON?=python

cookbook:
	@${PYTHON} test_cookbook.py ${TEST_OPTIONS}

blob:
	@${PYTHON} test_pgmagick_blob.py ${TEST_OPTIONS}

color:
	@${PYTHON} test_pgmagick_color.py ${TEST_OPTIONS}

image:
	@${PYTHON} test_pgmagick_image.py ${TEST_OPTIONS}

geometry:
	@${PYTHON} test_pgmagick_geometry.py ${TEST_OPTIONS}

montage:
	@${PYTHON} test_pgmagick_montage.py ${TEST_OPTIONS}

api:
	@${PYTHON} test_pgmagick_api.py ${TEST_OPTIONS}

clean:
	rm *.png *.jpg
