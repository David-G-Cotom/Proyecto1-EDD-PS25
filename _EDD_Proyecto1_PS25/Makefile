TARGET=Ejecutable/Proyecto1

SRCS=main.cpp $(wildcard src/*.cpp) $(wildcard src/controllers/*.cpp) $(wildcard src/models/*.cpp) $(wildcard src/models/objects/*.cpp)

OBJS=$(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	 g++ -o $(TARGET) $(OBJS)

%.o: %.cpp
	 g++ -c $< -o $@

# Limpiar archivos generados
clean:
	 rm -f *.o src/*.o src/controllers/*.o src/models/*.o src/models/objects/*.o $(TARGET)