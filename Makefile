CFLAGS = -std=c++17 -O2
LDFLAGS = -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi -Iinclude

VulkanTest: */*.cpp */*.hpp
	g++ $(CFLAGS) -o bin/VulkanTest */*.cpp $(LDFLAGS)

all: test clean

test: VulkanTest
	./bin/VulkanTest

clean:
	rm -f bin/VulkanTest