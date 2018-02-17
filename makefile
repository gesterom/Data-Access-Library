SOURCE := $(shell ls ./example/*.cpp)
TARGET_EXEC :=./$(addprefix bin/,$(notdir $(SOURCE:.cpp=.out)))

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
	@$(MAKE) --no-print-directory $(TARGET_EXEC)

$(TARGET_EXEC): $(SOURCE)
	$(CXX) $(CXXFLAGS) $< -o $@ $(CXXLIBS)

rebuild:
	rm ./bin/* || true
	@$(MAKE) --no-print-directory all
