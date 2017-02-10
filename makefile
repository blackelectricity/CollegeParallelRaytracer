raytracer:
	g++ Main.cpp -lX11  /lib/libpthread.so.0 -o raytracer
clean:
	\rm -f raytracer
