#!/bin/sh

convert X.jpg -sharpen 1 -quality 100 Y.jpg
convert X.jpg -filter Sinc -resize 1000x1000 -sharpen 1 -quality 100 Y.jpg
convert X.jpg -filter Sinc -resize 100x100 -sharpen 1 -quality 100 Y.jpg
convert X.jpg -filter Sinc -resize 500x500 -sharpen 1 -quality 100 Y.jpg
