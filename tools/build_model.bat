@echo off
color 0F
:Loop
mdlconv  data\test.obj -T -N -C
spasm data\test.inc Test.8xv -E -S
pause