# Use a base image with both C and Python environments
FROM ubuntu:latest

# Update the package lists
RUN apt-get update -y && apt-get upgrade -y

# Install necessary packages for C and Python development
RUN apt-get install -y \
    build-essential \
    python3 \
    python3-pip

# Set the working directory
WORKDIR /

COPY . .

# Download Valgrind for C/C++
RUN apt-get install -y valgrind

# Update the package lists and install clang
RUN apt update 
RUN apt install clang

# Install Python dependencies
RUN pip3 install -r requirements.txt

# Command to run when the container starts
CMD ["bash"]