all: raytracer

raytracer: main.o vec3f.o renderer.o canvas.o pixel.o lightsource.o object.o scene.o
	g++ main.o vec3f.o renderer.o canvas.o pixel.o lightsource.o object.o scene.o -o raytracer

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

lightsource.o: lightsource.cpp
	g++ -c lightsource.cpp

object.o: object.cpp
	g++ -c object.cpp

scene.o: scene.cpp
	g++ -c scene.cpp

clean:
	rm -rf *.o raytracer
