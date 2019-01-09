# Get the base Ubuntu image from Docker Hub
FROM ubuntu:latest

# Update apps on the base image
RUN apt-get -y update && apt-get install -y

# Install the Clang compiler
RUN apt-get -y install clang cmake

# Copy the current folder which contains C++ source code to the Docker image under /usr/src
COPY .. /usr/src/dockertest1

# Specify the working directory
WORKDIR /usr/src/dockertest1

# Use Clang to compile the Test.cpp source file
#RUN clang++ -o test test.cpp
RUN mkdir -p build && \
    cd build && \
    cmake .. && \
    make

# Run the output program from the previous step
CMD ["./test_docker"]
