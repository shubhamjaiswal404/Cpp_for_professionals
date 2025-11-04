CC=g++
HADOOP_INSTALL=/usr/local/hadoop
JAVA_HOME=/usr/lib/jvm/java-21-openjdk-amd64

CFLAGS = -c -Wall -g -I$(HADOOP_INSTALL)/include  -I${JAVA_HOME}/include  -I${JAVA_HOME}/include/linux 
LDFLAGS = -L$(HADOOP_INSTALL)/lib/native -lhdfs -L${JAVA_HOME}/lib/server -ljvm

all: hadoop_upload  hadoop_copy

hadoop_upload:hadoop_upload.o
	$(CC) hadoop_upload.o $(LDFLAGS) -o hadoop_upload -std=c++11
hadoop_upload.o:hadoop_upload.cpp
	$(CC) $(CFLAGS) hadoop_upload.cpp -o hadoop_upload.o

hadoop_copy:hadoop_copy.o
	$(CC) hadoop_copy.o $(LDFLAGS) -o hadoop_copy -std=c++11
hadoop_copy.o:hadoop_copy.cpp
	$(CC) $(CFLAGS) hadoop_copy.cpp -o hadoop_copy.o



clean:
	rm -f *.o hadoop_upload  hadoop_copy
    



# sudo find /usr/lib/jvm -name "libjvm.so"  // to find libjvm.so 
# Same execution from to different methods :: execution is to upload file on hadoop  
#....>hdfs dfs -ls /user/data
#....>./hadoop_upload sample.txt /user/data/sample.txt
#....>hdfs dfs -ls /user/data
#....>hdfs dfs -cat /user/data/sample.txt
#....>hdfs dfs -rm /user/data/sample.txt
#
#
#....>hdfs dfs -ls /user/data
#....>./hadoop_copy sample.txt /user/data/sample.txt
#....>hdfs dfs -ls /user/data
#....>hdfs dfs -cat /user/data/sample.txt



