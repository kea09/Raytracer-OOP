all: raytracer

raytracer: main.o vec3f.o renderer.o canvas.o pixel.o
	g++ main.o vec3f.o renderer.o canvas.o pixel.o -o raytracer

main.o: main.cpp
	g++ -c main.cpp

vec3f.o: vec3f.cpp
	g++ -c vec3f.cpp

renderer.o: renderer.cpp
	g++ -c renderer.cpp

canvas.o: canvas.cpp
	g++ -c canvas.cpp

pixel.o: pixel.cpp
	g++ -c pixel.cpp

clean:
	rm -rf *.o raytracer
