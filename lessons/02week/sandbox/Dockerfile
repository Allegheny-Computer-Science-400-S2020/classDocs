
# date: 21 Jan 2020
# gcc development

FROM ubuntu

RUN apt-get update

RUN \
      apt-get update &&\
      apt-get install -y git &&\
      apt-get install -y htop &&\
      apt-get install -y vim &&\
	  apt-get install -y strace &&\
      apt-get install -y gcc &&\
      apt-get install -y g++-8-i686-linux-gnu


RUN useradd gccdev
RUN mkdir /home/gccdev
RUN export HOME=/home/gccdev

WORKDIR /home/gccdev

# Define default command.
CMD ["bash"]


# Build the container : docker build -t gccdev .
# Run the container  : docker run -it gccdev
# Mount local drive and run container :
# docker run -it --mount type=bind,source=$PWD,target=/home/gccdev gccdev

# Alden Hall: running this docker at Alden must have a different source directory due to network configuration
# docker run -it --mount type=bind,source=/tmp/gccdev,target=/home/gccdev gccdev
