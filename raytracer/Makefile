################################################################################
# Ben Baral, Matthew Calligaro, Julia Read, David Sobek
# Team D
# April 24, 2019
# Makefile for Ray Tracer project
#
# Usage: Copy this Makefile into your raytracer directory.  In bash (or an
# equivalent shell program), enter the command "make" to compile the
# "raytracer" executable.
#
# Note: As you add more functionality to your race tracer, you will likely
# need to create new targets to make the object (.o) files associated with your
# new classes.  You may also need to update the dependencies of certain targets
# if they #include your new class
#
# Disclaimer: We make no claims about the correctness of this Makefile and are
# not responsible for any issues it may cause
################################################################################

CXX = g++
CXXFLAGS = -g -std=c++1z -Wall -Wextra -pedantic -O3

# Used by Open MP for multi-threading
# Change to "OMPFLAGS =" if you do not multi-thread
OMPFLAGS = -fopenmp

all: raytracer

# Builds the executable
# Important: Change the first dependency to the build you are using
raytracer: obj/buildAntiAlias.o \
	obj/Parallel.o obj/Perspective.o \
	obj/Geometry.o obj/Plane.o obj/Sphere.o obj/Triangle.o obj/SmoothTriangle.o \
	obj/Light.o obj/Ambient.o obj/Directional.o obj/Point.o obj/Spotlight.o \
	obj/Cosine.o \
	obj/Sampler.o obj/Simple.o obj/RegularBox.o \
	obj/Image.o obj/Point3D.o obj/Ray.o	obj/RGBColor.o obj/ShadeInfo.o \
	obj/Vector3D.o \
	obj/ViewPlane.o obj/World.o \
	obj/raytracer.o
	$(CXX) $(OMPFLAGS) -o $@ $^

obj/raytracer.o: raytracer.cpp build/buildHelloWorld.cpp \
	materials/Material.hpp samplers/Sampler.hpp utilities/Image.hpp \
	utilities/ShadeInfo.hpp	world/World.hpp obj
	$(CXX) $(OMPFLAGS) -c $(CXXFLAGS) -o $@ raytracer.cpp

################################################################################
# Builds
################################################################################

obj/buildHelloWorld.o: build/buildHelloWorld.cpp cameras/Perspective.hpp \
	geometry/Plane.hpp geometry/Sphere.hpp geometry/Triangle.hpp \
	materials/Cosine.hpp samplers/Simple.hpp utilities/Constants.hpp \
	world/World.hpp obj
	$(CXX) -c $(CXXFLAGS) -o $@ build/buildHelloWorld.cpp

obj/buildChapter14.o: build/buildChapter14.cpp cameras/Parallel.hpp \
	geometry/Plane.hpp geometry/Sphere.hpp \
	materials/Cosine.hpp samplers/Simple.hpp utilities/Constants.hpp \
	world/World.hpp obj
	$(CXX) -c $(CXXFLAGS) -o $@ build/buildChapter14.cpp

# Add any addition builds you make here
obj/buildMVP.o: build/buildMVP.cpp cameras/Perspective.hpp \
	geometry/Plane.hpp geometry/Sphere.hpp geometry/Triangle.hpp \
	materials/Cosine.hpp samplers/Simple.hpp utilities/Constants.hpp \
	world/World.hpp obj
	$(CXX) -c $(CXXFLAGS) -o $@ build/buildMVP.cpp

obj/ply_testing.o: build/ply_testing.cpp cameras/Perspective.hpp \
	geometry/Plane.hpp materials/Cosine.hpp samplers/Simple.hpp \
	utilities/Constants.hpp world/World.hpp obj
	$(CXX) -c $(CXXFLAGS) -o $@ build/ply_testing.cpp

obj/buildChess.o: build/buildChess.cpp cameras/Perspective.hpp \
	geometry/Plane.hpp geometry/Triangle.hpp materials/Cosine.hpp \
	samplers/Simple.hpp	utilities/Constants.hpp world/World.hpp obj
	$(CXX) -c $(CXXFLAGS) -o $@ build/buildChess.cpp

obj/buildAntiAlias.o: build/buildAntiAlias.cpp cameras/Perspective.hpp \
	geometry/Plane.hpp geometry/Sphere.hpp geometry/Triangle.hpp \
	materials/Cosine.hpp samplers/RegularBox.hpp samplers/Simple.hpp \
	utilities/Constants.hpp	world/World.hpp obj
	$(CXX) -c $(CXXFLAGS) -o $@ build/buildAntiAlias.cpp

################################################################################
# Cameras
################################################################################

obj/Parallel.o: cameras/Parallel.cpp cameras/Parallel.hpp cameras/Camera.hpp \
	utilities/Vector3D.hpp obj
	$(CXX) -c $(CXXFLAGS) -o $@ cameras/Parallel.cpp

obj/Perspective.o: cameras/Perspective.cpp cameras/Perspective.hpp \
	cameras/Camera.hpp utilities/Point3D.hpp utilities/Vector3D.hpp obj
	$(CXX) -c $(CXXFLAGS) -o $@ cameras/Perspective.cpp

################################################################################
# Geometry
################################################################################

obj/Geometry.o: geometry/Geometry.cpp geometry/Geometry.hpp \
	materials/Material.hpp utilities/Ray.hpp utilities/ShadeInfo.hpp obj
	$(CXX) -c $(CXXFLAGS) -o $@ geometry/Geometry.cpp

obj/Plane.o: geometry/Plane.cpp geometry/Plane.hpp geometry/Geometry.hpp \
	materials/Material.hpp utilities/Constants.hpp utilities/Point3D.hpp \
	utilities/Ray.hpp utilities/ShadeInfo.hpp utilities/Vector3D.hpp obj
	$(CXX) -c $(CXXFLAGS) -o $@ geometry/Plane.cpp

obj/Sphere.o: geometry/Sphere.cpp geometry/Sphere.hpp geometry/Geometry.hpp \
	materials/Material.hpp utilities/Constants.hpp utilities/Point3D.hpp \
	utilities/Ray.hpp utilities/ShadeInfo.hpp utilities/Vector3D.hpp obj
	$(CXX) -c $(CXXFLAGS) -o $@ geometry/Sphere.cpp

obj/Triangle.o: geometry/Triangle.cpp geometry/Triangle.hpp \
	geometry/Geometry.hpp materials/Material.hpp utilities/Constants.hpp \
	utilities/Point3D.hpp utilities/Ray.hpp utilities/ShadeInfo.hpp \
	utilities/Vector3D.hpp obj
	$(CXX) -c $(CXXFLAGS) -o $@ geometry/Triangle.cpp

obj/SmoothTriangle.o: geometry/SmoothTriangle.cpp geometry/SmoothTriangle.hpp \
	geometry/Geometry.hpp materials/Material.hpp utilities/Constants.hpp \
	utilities/Point3D.hpp utilities/Ray.hpp utilities/ShadeInfo.hpp \
	utilities/Vector3D.hpp obj
	$(CXX) -c $(CXXFLAGS) -o $@ geometry/SmoothTriangle.cpp

################################################################################
# Lights
################################################################################

obj/Light.o: lights/Light.cpp lights/Light.hpp utilities/RGBColor.hpp obj
	$(CXX) -c $(CXXFLAGS) -o $@ lights/Light.cpp

obj/Ambient.o: lights/Ambient.cpp lights/Ambient.hpp lights/Light.hpp \
	utilities/RGBColor.hpp utilities/Vector3D.hpp obj
	$(CXX) -c $(CXXFLAGS) -o $@ lights/Ambient.cpp

obj/Directional.o: lights/Directional.cpp lights/Directional.hpp \
	lights/Light.hpp utilities/RGBColor.hpp utilities/Vector3D.hpp obj
	$(CXX) -c $(CXXFLAGS) -o $@ lights/Directional.cpp

obj/Point.o: lights/Point.cpp lights/Point.hpp lights/Light.hpp \
	utilities/Point3D.hpp utilities/RGBColor.hpp utilities/Vector3D.hpp obj
	$(CXX) -c $(CXXFLAGS) -o $@ lights/Point.cpp

obj/Spotlight.o: lights/Spotlight.cpp lights/Spotlight.hpp lights/Light.hpp \
	utilities/Point3D.hpp utilities/RGBColor.hpp utilities/Vector3D.hpp obj
	$(CXX) -c $(CXXFLAGS) -o $@ lights/Spotlight.cpp


################################################################################
# Materials
################################################################################

obj/Cosine.o: materials/Cosine.cpp materials/Cosine.hpp materials/Material.hpp \
	utilities/RGBColor.hpp utilities/ShadeInfo.hpp obj
	$(CXX) -c $(CXXFLAGS) -o $@ materials/Cosine.cpp

################################################################################
# Samplers
################################################################################

obj/Sampler.o: samplers/Sampler.cpp samplers/Sampler.hpp obj
	$(CXX) -c $(CXXFLAGS) -o $@ samplers/Sampler.cpp

obj/Simple.o: samplers/Simple.cpp samplers/Simple.hpp cameras/Camera.hpp \
	samplers/Sampler.hpp utilities/Ray.hpp obj
	$(CXX) -c $(CXXFLAGS) -o $@ samplers/Simple.cpp

# Add any additional samplers you make here
obj/RegularBox.o: samplers/RegularBox.cpp samplers/RegularBox.hpp cameras/Camera.hpp \
	samplers/Sampler.hpp utilities/Ray.hpp obj
	$(CXX) -c $(CXXFLAGS) -o $@ samplers/RegularBox.cpp

################################################################################
# Utilities
################################################################################

obj/Image.o: utilities/Image.cpp utilities/Image.hpp utilities/RGBColor.hpp \
	world/ViewPlane.hpp obj
	$(CXX) -c $(CXXFLAGS) -o $@ utilities/Image.cpp

obj/Point3D.o: utilities/Point3D.cpp utilities/Point3D.hpp \
	utilities/Vector3D.hpp obj
	$(CXX) -c $(CXXFLAGS) -o $@ utilities/Point3D.cpp

obj/Ray.o: utilities/Ray.cpp utilities/Ray.hpp utilities/Point3D.hpp \
	utilities/Vector3D.hpp obj
	$(CXX) -c $(CXXFLAGS) -o $@ utilities/Ray.cpp

obj/RGBColor.o: utilities/RGBColor.cpp utilities/RGBColor.hpp obj
	$(CXX) -c $(CXXFLAGS) -o $@ utilities/RGBColor.cpp

obj/ShadeInfo.o: utilities/ShadeInfo.cpp utilities/ShadeInfo.hpp \
	utilities/Constants.hpp utilities/Point3D.hpp utilities/Ray.hpp	\
	utilities/Vector3D.hpp obj
	$(CXX) -c $(CXXFLAGS) -o $@ utilities/ShadeInfo.cpp

obj/Vector3D.o: utilities/Vector3D.cpp utilities/Vector3D.hpp \
	utilities/Point3D.hpp obj
	$(CXX) -c $(CXXFLAGS) -o $@ utilities/Vector3D.cpp

################################################################################
# World
################################################################################

obj/ViewPlane.o: world/ViewPlane.cpp world/ViewPlane.hpp utilities/Point3D.hpp \
	utilities/Vector3D.hpp obj
	$(CXX) -c $(CXXFLAGS) -o $@ world/ViewPlane.cpp

obj/World.o: world/World.cpp world/World.hpp cameras/Camera.hpp \
	geometry/Geometry.hpp geometry/SmoothTriangle.hpp geometry/Triangle.hpp \
	happly/happly.h lights/Light.hpp materials/Material.hpp samplers/Sampler.hpp \
	utilities/Point3D.hpp utilities/RGBColor.hpp utilities/ShadeInfo.hpp obj
	$(CXX) -c $(CXXFLAGS) -o $@ world/World.cpp

################################################################################
# Other
################################################################################

# Removes executable and all object files
clean:
	rm -rf raytracer obj *.o

# Formats code and suggestions improvements according to cpplint
clean-code:
	clang-format --style=google -i **/*.*pp
	-cpplint **/*.cpp
	-cpplint **/*.hpp

# Creates obj folder for all object files
obj:
	mkdir obj
