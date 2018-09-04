#!/bin/sh
SRC_DIR=./
DST_DIR=./

#C++
mkdir -p $DST_DIR
protoc -I=$SRC_DIR --cpp_out=$DST_DIR $SRC_DIR/IM*.proto

#JAVA
#mkdir -p $DST_DIR/java
#protoc -I=$SRC_DIR --java_out=$DST_DIR/java/ $SRC_DIR/IM*.proto

#PYTHON
#mkdir -p $DST_DIR/python
#protoc -I=$SRC_DIR --python_out=$DST_DIR/python/ $SRC_DIR/IM*.proto
