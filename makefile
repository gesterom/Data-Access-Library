TARGET_EXEC =$(shell basename "$(PWD)" )

SOURCE := $(shell ls ./src/*.cpp)
OBJ := ./$(addprefix obj/,$(notdir $(SOURCE:.cpp=.o)))
DATA=$(shell date)

CXX=g++-7
CXXFLAGS=-Wall -Wextra -Wunused-variable

CXXLIBS=$(shell cat ./libs)

.PHONY: all clean

all: post-build

pre-build:
	@echo "START"
	@echo " " > ./.build.log

post-build: main-build
	@echo "DONE"

main-build: pre-build
	@$(MAKE) --no-print-directory exec
	
exec: $(OBJ)
	@echo "$(SOURCE)\n$(OBJ)\nCompilation date : $(DATA)\nFlags list: $(CXXFLAGS)\nFile list: $(SOURCE)\nLib list: $(CXXLIBS)" > ./bin/info
	$(CXX) $(CXXFLAGS) -o ./bin/"$(TARGET_EXEC)" $^ $(CXXLIBS) >> ./.build.log 2>> ./.build.log

./obj/%.o: ./src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(CXXLIBS) >> ./.build.log 2>> ./.build.log
	
test:
	echo $(CXXLIBS)
	
rebuild:
	rm ./obj/* || true
	@$(MAKE) --no-print-directory post-build
