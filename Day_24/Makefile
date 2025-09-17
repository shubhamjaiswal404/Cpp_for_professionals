# Makefile 


CXX = g++
CXXFLAGS = --std=c++17 -Wall -Wextra
PKGCONFIG = pkg-config --cflags --libs libmongocxx
SRC = QueryMongodb.cpp
OUT = QueryMongod.out

all: $(OUT)

$(OUT): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(OUT) `$(PKGCONFIG)`

#run: $(OUT)
#	LD_LIBRARY_PATH=/usr/local/lib:$$LD_LIBRARY_PATH ./$(OUT)

clean:
	rm -f $(OUT)

# OR 
# (Direct Command ) ::  c++ --std=c++17 QueryMongodb.cpp $(pkg-config --cflags --libs libmongocxx) -o ./QueryMongodb.out
# (Run Binary) :: ./QueryMongodb.out


