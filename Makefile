SOURCE_DIR = src
SOURCES = $(wildcard *.cpp) $(wildcard src/*/*.cpp)
BUILD_DIR = bin
TEST_FILE_NAME = test.txt

ifeq ($(OS),Windows_NT) 
GXX := cl /EHsc /std:c++17
BUILD_NAME := brain.exe
DELETE_OBJS := del *.obj
DELETE_FOLDER := call rmdir /S /Q
DELETE_FILE := call del /Q /F
CLEAR_SCREEN := cls
OUTPUT_FLAG := /Fe:
else
GXX := g++ -std=c++17
BUILD_NAME := brain.out
DELETE_FOLDER := rm -rf
DELETE_FILE := rm -f
CLEAR_SCREEN := clear
OUTPUT_FLAG := -o
endif

default: build
.PHONY: default

build: |buildDir
	$(GXX) $(SOURCES) ${OUTPUT_FLAG}$(BUILD_DIR)/$(BUILD_NAME)
	${DELETE_OBJS}
.PHONY: build


buildDir: |clean
	mkdir $(BUILD_DIR)
.PHONY: buildDir


clean:
	 ${DELETE_FOLDER} $(BUILD_DIR) | echo Done
.PHONY: clean


test: |build
	${CLEAR_SCREEN}
	$(BUILD_DIR)/$(BUILD_NAME) $(TEST_FILE_NAME)
.PHONY: test