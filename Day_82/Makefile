CC=g++
HADOOP_INSTALL=/usr/local/hadoop
JAVA_HOME=/usr/lib/jvm/java-21-openjdk-amd64

CFLAGS = -c -Wall -g -I$(HADOOP_INSTALL)/include  -I${JAVA_HOME}/include  -I${JAVA_HOME}/include/linux 
LDFLAGS = -L$(HADOOP_INSTALL)/lib/native -lhdfs -L${JAVA_HOME}/lib/server -ljvm

all: hadoop_read

hadoop_read:hadoop_read.o
	$(CC) hadoop_read.o $(LDFLAGS) -o hadoop_read -std=c++11
hadoop_read.o:hadoop_read.cpp
	$(CC) $(CFLAGS) hadoop_read.cpp -o hadoop_read.o
    
clean:
	rm -f *.o hadoop_read
    


# linux command 
# ....> g++ version
# ....> hadoop version 
# ..../lib/native> ls -l
# libhdfs.so 
#
#....> start-dfs.sh
#Starting namenodes on [localhost]
#Starting datanodes
#Starting secondary namenodes [shubham-Dell-G15-5511]
#
#....> start-yarn.sh
#Starting resourcemanager
#Starting nodemanagers

#
#hdfs dfs -mkdir /user
#hdfs dfs -mkdir -p /user/data 
#hdfs dfs -ls /user
#
#....> hadoop version > my_test.txt
#....> cat my_test.txt
#Hadoop 3.4.1 
#....>hdfs dfs -put my_test.txt /user/data
#....>hdfs dfs -ls  /user/data
#....>hdfs dfs -cat  /user/data/my_test.txt
#Hadoop 3.4.1
#....>./hadoop_read /user/data/my_test.txt
#Hadoop 3.4.1





# Direct linux commands for compilation head_read::
#
#....> export JAVA_HOME=/usr/lib/jvm/java-11-openjdk-amd64
#....> g++ -Wall -g -I/usr/local/hadoop/include -I$JAVA_HOME/include -I$JAVA_HOME/include/linux \
    hadoop_read.cpp -L/usr/local/hadoop/lib/native -lhdfs \
    -L$JAVA_HOME/lib/server -ljvm \
    -o hadoop_read

# Linux set up to solve run time error :: Dynamic linking 
# linux command 
#....> nano ~/.bashrc 
# add all below command in  ~/.bashrc file and save the file  ,

#export HADOOP_HOME=/usr/local/hadoop
#export JAVA_HOME=/usr/lib/jvm/java-21-openjdk-amd64
#export HADOOP_CONF_DIR=$HADOOP_HOME/etc/hadoop
#export CLASSPATH=$($HADOOP_HOME/bin/hadoop classpath --glob)
#export LD_LIBRARY_PATH=$JAVA_HOME/lib/server:$HADOOP_HOME/lib/native:$LD_LIBRARY_PATH
#....> source ~/.bashrc
#
#echo $CLASSPATH
#./hadoop_read /user/data/my_test.txt




