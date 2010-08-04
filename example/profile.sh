#!/bin/zsh


echo "==================================================="
echo "[pgmagick (libGraphicsMagick++ wrapper for Python)]"
for cnt in `seq 5`
do
    time python pgmagick_prof.py
done

echo "==================================================="
echo "[PythonMagick(libMagick++ wrapper for Python)]"
for cnt in `seq 5`
do
    time python pythonmagick_prof.py
done

echo "==================================================="
echo "[ImageMagick(convert command)]"
for cnt in `seq 5`
do
    time sh im.sh
done

echo "==================================================="
echo "[GraphicsMagick(gm convert command)]"
for cnt in `seq 5`
do
    time sh gm.sh
done
