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

# Compile the C code
RUN gcc -o /app/c_code/main /app/c_code/main.c

# Install Python dependencies
RUN pip3 install -r

# Command to run when the container starts
CMD ["bash"]
