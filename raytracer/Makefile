CXX = clang++
CXXFLAGS = -g -std=c++1z -Wall -Wextra -pedantic -Qunused-arguments

all: raytracer

################################################################################
# Build 
################################################################################

bulidHelloWorld.o: build/buildHelloWorld.cpp cameras/Perspective.hpp \
	geometry/Plane.hpp geometry/Sphere.hpp geometry/Triangle.hpp \
	samplers/Simple.hpp materials/Cosine.hpp utilites/Constants.hpp \
	world/World.hpp
	$(CXX) -c $(CXXFLAGS) build/buildHelloWorld.cpp

buildChapter14.o: build/buildChapter14.cpp cameras/Perspective.hpp \
	geometry/Plane.hpp geometry/Sphere.hpp \
	samplers/Simple.hpp materials/Cosine.hpp utilites/Constants.hpp \
	world/World.hpp
	$(CXX) -c $(CXXFLAGS) build/buildChapter14.cpp

################################################################################
# Cameras 
################################################################################

Parallel.o: cameras/Parallel.cpp cameras/Camera.hpp utilities/Vector3D.hpp \
	cameras/Parallel.hpp
	$(CXX) -c $(CXXFLAGS) cameras/Parallel.cpp

Perspective.o: cameras/Perspective.cpp cameras/Camera.hpp \
	utilities/Point3D.hpp utilities/Vector3D.hpp cameras/Perspective.hpp
	$(CXX) -c $(CXXFLAGS) cameras/Perspective.cpp

################################################################################
# Geometry 
################################################################################

Geometry.o: geometry/Geometry.cpp materials/Material.hpp geometry/Geometry.hpp
	$(CXX) -c $(CXXFLAGS) geometry/Geometry.cpp

Plane.o: geometry/Plane.cpp geometry/Geometry.hpp materials/Material.hpp \
	utilities/Point3D.hpp utilities/Vector3D.hpp geometry/Plane.hpp
	$(CXX) -c $(CXXFLAGS) geometry/Plane.cpp

Sphere.o: geometry/Sphere.cpp geometry/Geometry.hpp materials/Material.hpp \
	utilities/Point3D.hpp geometry/Sphere.hpp
	$(CXX) -c $(CXXFLAGS) geometry/Sphere.cpp

Triangle.o: geometry/Triangle.cpp geometry/Geometry.hpp materials/Material.hpp \
	utilities/Point3D.hpp geometry/Triangle.hpp
	$(CXX) -c $(CXXFLAGS) geometry/Triangle.cpp

################################################################################
# Lights 
################################################################################

Light.o: lights/Light.cpp utilities/RGBColor.hpp lights/Light.hpp \
	$(CXX) -c $(CXXFLAGS) lights/Ambient.cpp

Ambient.o: lights/Ambient.cpp lights/Light.hpp utilities/RGBColor.hpp \
	utilities/Vector3D.hpp lights/Ambient.hpp
	$(CXX) -c $(CXXFLAGS) lights/Ambient.cpp

Directional.o: lights/Directional.cpp lights/Light.hpp utilities/RGBColor.hpp \
	utilities/Vector3D.hpp lights/Directional.hpp
	$(CXX) -c $(CXXFLAGS) lights/Directional.cpp

Point.o: lights/Point.cpp lights/Light.hpp utilities/RGBColor.hpp \
	utilities/Point3D.hpp utilities/Vector3D.hpp lights/Point.hpp
	$(CXX) -c $(CXXFLAGS) lights/Point.cpp

Spotlight.o: lights/Spotlight.cpp lights/Light.hpp utilities/RGBColor.hpp \
	utilities/Point3D.hpp utilities/Vector3D.hpp lights/Spotlight.hpp
	$(CXX) -c $(CXXFLAGS) lights/Spotlight.cpp


################################################################################
# Materials 
################################################################################

Cosine.o: materials/Cosine.cpp materials/Material.hpp utilities/RGBColor.hpp \
	materials/Cosine.hpp
	$(CXX) -c $(CXXFLAGS) materials/Cosine.cpp

################################################################################
# Samplers 
################################################################################

Sampler.o: samplers/Sampler.cpp samplers/Sampler.hpp
	$(CXX) -c $(CXXFLAGS) samplers/Sampler.cpp

Simple.o: samplers/Simple.cpp samplers/Sampler.hpp samplers/Simple.hpp
	$(CXX) -c $(CXXFLAGS) samplers/Simple.cpp

################################################################################
# Utilities 
################################################################################

Image.o: utilities/Image.cpp utilities/RGBColor.hpp utilities/Impage.hpp
	$(CXX) -c $(CXXFLAGS) utilities/Image.cpp

Point3D.o: utilities/Point3d.cpp utilities/Vector3D.hpp utilities/Point3D.hpp
	$(CXX) -c $(CXXFLAGS) utilities/Point3D.cpp

Ray.o: utilities/Point3d.cpp utilites/Point3D.hpp utilities/Vector3D.hpp \
	utilities/Ray.hpp
	$(CXX) -c $(CXXFLAGS) utilities/Ray.cpp

RGBColor.o: utilites/RGBColor.cpp utilities/RGBColor.hpp
	$(CXX) -c $(CXXFLAGS) utilities/RGBColor.cpp

ShadeInfo.o: utilites/ShadeInfo.cpp utilities/Point3D.hpp \
	utilities/Vector3D.hpp utilities/Ray.hpp utilities/ShadeInfo.hpp
	$(CXX) -c $(CXXFLAGS) utilities/ShadeInfo.cpp

Vector3D.o: utilites/Vector3D.cpp utilities/Point3D.hpp utilities/Vector3D.hpp
	$(CXX) -c $(CXXFLAGS) utilities/Vector3D.cpp

################################################################################
# World 
################################################################################

ViewPlane.o: world/ViewPlane.cpp utilities/Point3D.hpp world/ViewPlane.hpp
	$(CXX) -c $(CXXFLAGS) world/ViewPlane.cpp

World.o: world/World.cpp utilities/Point3D.hpp utilities/RGBColor.hpp \
	utilities/ShadeInfo.hpp world/World.hpp
	$(CXX) -c $(CXXFLAGS) world/World.cpp

################################################################################
# Other 
################################################################################

clean: 
	rm -f raytracer *.o

clean-code:
	clang-format --style=google -i **/*.*pp
	cpplint **/*.cpp
	cpplint **/*.hpp
