all: cookbook blob color image geometry montage api

PYTHON?=python

cookbook:
	@${PYTHON} test_cookbook.py

blob:
	@${PYTHON} test_pgmagick_blob.py

color:
	@${PYTHON} test_pgmagick_color.py

image:
	@${PYTHON} test_pgmagick_image.py

geometry:
	@${PYTHON} test_pgmagick_geometry.py

montage:
	@${PYTHON} test_pgmagick_montage.py

api:
	@${PYTHON} test_pgmagick_api.py

clean:
	rm *.png *.jpg
