CFLAGS = -std=c++17 -O2
LDFLAGS = -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi -Iinclude

vertShaders=$(shell find ./shaders -type f -name "*.vert")
vertObjFiles=$(patsubst %.vert, %.vert.spv, $(vertShaders))
fragShaders=$(shell find ./shaders -type f -name "*.frag")
fragObjFiles=$(patsubst %.frag, %.frag.spv, $(fragShaders))

TARGET= bin/VulkanTest
$(TARGET): $(vertObjFiles) $(fragObjFiles)
$(TARGET): */*.cpp */*.hpp
	g++ $(CFLAGS) -o $(TARGET) */*.cpp $(LDFLAGS)

%.spv: %
	glslc $< -o $@

all: test clean

test: bin/VulkanTest
	DRI_PRIME=1 ./bin/VulkanTest

clean:
	rm -f bin/VulkanTest
	rm -f shaders/*.spv
	