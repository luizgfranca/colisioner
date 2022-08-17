CC = g++
CFLAGS = -Wall -g 
COMPILE = -c
OUTPUT = -o
OUTPATH = out
APPLICATION = colisioner
LIBS = -lSDL2 -lSDL2main
CMD_RUN = ./$(OUTPATH)/\$(APPLICATION)

define run_std_compilation
	$(CC) $(CFLAGS) $(COMPILE) $< $(OUTPUT) $(OUTPATH)/$@ $(LIBS)
endef

SRCS = $(wildcard */*/*.cpp) $(wildcard */*.cpp) $(wildcard *.cpp) 
OBJS = $(patsubst %.cpp,%.o,$(SRCS))
OBJS_FILES = $(patsubst %.o,$(OUTPATH)/%.o,$(OBJS))

all: compile link start

link: 
	$(CC) $(CFLAGS) $(OUTPUT) \
		$(OUTPATH)/$(APPLICATION) \
		$(OUTPATH)/main.o \
		$(OUTPATH)/app.o \
		$(OUTPATH)/lib/frameTimer.o \
		$(OUTPATH)/config.o \
		$(OUTPATH)/lib/geometry/point.o \
		$(OUTPATH)/lib/geometry/circle.o \
		$(OUTPATH)/lib/geometry/bounds.o \
		$(OUTPATH)/environment.o \
		$(OUTPATH)/physics/vector.o \
		$(OUTPATH)/physics/physicalObject.o \
		$(OUTPATH)/physics/circleObject.o \
		$(OUTPATH)/physics/physicsEngine.o \
		$(OUTPATH)/physics/colisionDetector.o \
		$(OUTPATH)/physics/interactionsResultEvaluator.o \
		$(OUTPATH)/render/shape/pixel.o \
		$(OUTPATH)/render/shape/circle.o \
		$(OUTPATH)/render/engine.o \
		$(LIBS)

start: 
	$(CMD_RUN)

compile: prepare $(OBJS)

%.o: %.cpp
	$(call run_std_compilation)

prepare:
	mkdir -p $(OUTPATH)/lib
	mkdir -p $(OUTPATH)/lib/geometry
	mkdir -p $(OUTPATH)/physics
	mkdir -p $(OUTPATH)/render
	mkdir -p $(OUTPATH)/render/shape

clear: 
	rm -rf out/*

