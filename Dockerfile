# Get the GCC preinstalled image from Docker Hub
FROM gcc:5.5

# Copy the current folder which contains C++ source code to the Docker image under /usr/src
COPY /exercise_1/source/task01 /task01

# Specify the working directory
WORKDIR /task01

# run Makefile
RUN make

# Run the program output from the previous step
CMD ["./printsizes"] 