CC = g++
CFLAGS = -Wall -g 
COMPILE = -c
OUTPUT = -o
OUTPATH = out
APPLICATION = colisioner
LIBS = -lSDL2 -lSDL2main
CMD_RUN = ./$(OUTPATH)/\$(APPLICATION)

all: main
	$(CC) $(CFLAGS) $(OUTPUT) \
		$(OUTPATH)/$(APPLICATION) \
		$(OUTPATH)/main.o \
		$(OUTPATH)/app.o \
		$(OUTPATH)/frameTimer.o \
		$(OUTPATH)/render_engine.o \
		$(OUTPATH)/pixel.o \
		$(OUTPATH)/circle.o \
		$(OUTPATH)/config.o \
		$(OUTPATH)/point.o \
		$(LIBS)

	$(CMD_RUN)


# GENERAL

main: app
	$(CC) $(CFLAGS) $(COMPILE) main.cpp $(OUTPUT) $(OUTPATH)/main.o $(LIBS)

app: config render_engine lib
	$(CC) $(CFLAGS) $(COMPILE) app.cpp $(OUTPUT) $(OUTPATH)/app.o $(LIBS)


# RENDERING

render_engine: config pixel circle
	$(CC) $(CFLAGS) $(COMPILE) render/engine.cpp $(OUTPUT) $(OUTPATH)/render_engine.o $(LIBS)

## SHAPE

pixel: 
	$(CC) $(CFLAGS) $(COMPILE) render/shape/pixel.cpp $(OUTPUT) $(OUTPATH)/pixel.o $(LIBS)

circle: 
	$(CC) $(CFLAGS) $(COMPILE) render/shape/circle.cpp $(OUTPUT) $(OUTPATH)/circle.o $(LIBS)


# LIB

lib: frameTimer point

frameTimer:
	$(CC) $(CFLAGS) $(COMPILE) lib/frameTimer.cpp $(OUTPUT) $(OUTPATH)/frameTimer.o $(LIBS)

## GEOMETRY

point:
	$(CC) $(CFLAGS) $(COMPILE) lib/geometry/point.cpp $(OUTPUT) $(OUTPATH)/point.o $(LIBS)	



# SETTINGS

config:
	$(CC) $(CFLAGS) $(COMPILE) config.cpp $(OUTPUT) $(OUTPATH)/config.o $(LIBS)

clear: 
	rm -rf out/*