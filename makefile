SOURCE := $(shell ls ./example/*.cpp)
TARGET_EXEC :=./$(addprefix bin/,$(notdir $(SOURCE:.cpp=.out)))
ZZZ = ""

CXX=g++ -std=c++17
CXXFLAGS=-Wall -Wextra -Wunused-variable

CXXLIBS=-lpthread

.PHONY: all clean

all: post-build

pre-build:
	@echo "START"
	@echo " " > ./.build.log

post-build: main-build
	@echo "DONE"

main-build: pre-build
	$(MAKE) --no-print-directory bin
	@$(MAKE) --no-print-directory $(TARGET_EXEC)

$(TARGET_EXEC) : $(SOURCE)
	$(eval TMP := $(shell ls ./$(addprefix example/,$(notdir $(@:.out=.cpp)))))
	@echo $(TMP)
	@$(CXX) $(CXXFLAGS) $(TMP) -o $@ $(CXXLIBS)

rebuild:
	rm ./bin/* || true
	@$(MAKE) --no-print-directory all

bin: pre-build
	mkdir ./bin/ || true
	cp ./example/*.data ./bin/
