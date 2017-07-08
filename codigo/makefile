CC     = gcc
CFLAGS = -g -Wall
OBJS = ConvexHull.o InputOutput.o OpHull.o OpExtra.o Sort.o tp4.o 
TARGET = tp4

all: $(TARGET)

tp4: $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) -lm -o tp4 -lpthread
	
tp4.o: tp4.c ConvexHull.c ConvexHull.h InputOutput.c InputOutput.h OpHull.c OpHull.h Sort.c Sort.h OpExtra.c OpExtra.h
		$(CC) $(CFLAGS) -c tp4.c
	
ConvexHull.o: ConvexHull.c ConvexHull.h OpHull.c OpHull.h OpExtra.c OpExtra.h
	$(CC) $(CFLAGS) -lm -c ConvexHull.c
	
InputOutput.o: InputOutput.c InputOutput.h OpExtra.c OpExtra.h
	$(CC) $(CFLAGS) -c InputOutput.c
	
OpHull.o: OpHull.c OpHull.h OpExtra.c OpExtra.h
	$(CC) $(CFLAGS) -c OpHull.c
	
Sort.o:  Sort.c Sort.h OpExtra.c OpExtra.h
	$(CC) $(CFLAGS) -c Sort.c -lpthread
		
OpExtra.o: OpExtra.c OpExtra.h
	$(CC) $(CFLAGS) -c OpExtra.c
	
clean: 
	rm -rf *.o ./$(TARGET)
