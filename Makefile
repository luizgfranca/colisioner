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
		$(OUTPATH)/config.o \
		$(LIBS)

	$(CMD_RUN)


# GENERAL

main: app
	$(CC) $(CFLAGS) $(COMPILE) main.cpp $(OUTPUT) $(OUTPATH)/main.o $(LIBS)

app: config render_engine frameTimer
	$(CC) $(CFLAGS) $(COMPILE) app.cpp $(OUTPUT) $(OUTPATH)/app.o $(LIBS)


# RENDERING

render_engine: config pixel
	$(CC) $(CFLAGS) $(COMPILE) render/engine.cpp $(OUTPUT) $(OUTPATH)/render_engine.o $(LIBS)

pixel: 
	$(CC) $(CFLAGS) $(COMPILE) render/pixel.cpp $(OUTPUT) $(OUTPATH)/pixel.o $(LIBS)



# LIB

frameTimer:
	$(CC) $(CFLAGS) $(COMPILE) lib/frameTimer.cpp $(OUTPUT) $(OUTPATH)/frameTimer.o $(LIBS)



# SETTINGS

config:
	$(CC) $(CFLAGS) $(COMPILE) config.cpp $(OUTPUT) $(OUTPATH)/config.o $(LIBS)

clear: 
	rm -rf out/*