@echo off
color 0F
:Loop
#texconv data\textest.bmp
spasm -E data\textest.inc TEXTEST.8xv
pause