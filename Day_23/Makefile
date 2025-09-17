# Makefile 


CXX = g++
CXXFLAGS = --std=c++17 -Wall -Wextra
PKGCONFIG = pkg-config --cflags --libs libmongocxx
SRC = ConnectMongodb.cpp
OUT = app.out

all: $(OUT)

$(OUT): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(OUT) `$(PKGCONFIG)`

run: $(OUT)
	LD_LIBRARY_PATH=/usr/local/lib:$$LD_LIBRARY_PATH ./$(OUT)

clean:
	rm -f $(OUT)

# OR 
# (Direct Command ) ::  c++ --std=c++17 ConnectMongodb.cpp $(pkg-config --cflags --libs libmongocxx) -o ./apps.out
# (Run Binary) :: ./apps.out


